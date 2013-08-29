using System; 
using System.Runtime.InteropServices; 

namespace pcDuino.Net 
{
    public class GpioFile : IDisposable
    {
		/// <summary>
		/// The currently assigned GPIO pin. Used for class methods.
		/// </summary>
		protected readonly GpioPins _pin;
		/// <summary>
		/// Variable to track the disposed state
		/// </summary>
		private bool _disposed = false;
		private GpioDirection _direction;

        private const char High = '1';
        private const char Low = '0';
        private const char ModeInput = '0';
        private const char ModeOutput = '1';
        private const char ModePullup = '8';

		[DllImport("libgpio.so")]
		private static extern void gpio_open();

		[DllImport("libgpio.so")]
		private static extern void gpio_close();

		[DllImport("libgpio.so")]
		private static extern void setPinMode(int pin, byte mode);

		[DllImport("libgpio.so")]
		private static extern void setPinValue(int pin, byte value);

		[DllImport("libgpio.so")]
		private static extern byte getPinValue(int pin);

        public GpioFile(GpioPins pin, GpioDirection direction, bool initialValue)
        {
			if (pin == GpioPins.GpioNone) throw new ArgumentException("Invalid pin");
			
			gpio_open();

			_pin = pin;
			try {
				PinDirection = direction;
				Write(initialValue);
			}
			catch {
				Dispose();
				throw;
			}			
        }
		
		/// <summary>
		/// Finalizer to make sure we cleanup after ourselves.
		/// </summary>
		~GpioFile() 
		{
			if (!_disposed)
				Dispose();
		}		
		
		/// <summary>
		/// Sets a pin to output the give value.
		///
		/// Creates (exports) the pin if needed, and sets it to Out direction.
		/// </summary>
		/// <param name="pin">The pin who's value to set</param>
		/// <param name="value">The value to set</param>
		public static void Write(GpioPins pin, bool value) {
			using(var file = CreatePinFile(pin, GpioDirection.Out))
			{ 
				file.Write(value);
			}
		}
		
		/// <summary>
		/// Creates a pin if it has not already been created (exported), creates a GPIOMem if possible, otherwise falls back to GPIOFile.
		/// </summary>
		/// <param name="pin">The pin to create or export</param>
		/// <param name="dir">The direction the pin is to have</param>
		/// <returns>The GPIO instance representing the pin</returns>
		public static GpioFile CreatePinFile(GpioPins pin, GpioDirection dir) {
			try {
				return new GpioFile(pin, dir, false);
			}
			catch (Exception e) {
				System.Diagnostics.Debug.WriteLine("Unable to create pin " + (uint)pin + " as GPIOFile because: " + e.ToString());
			}
		    return null;
		}		

		/// <summary>
		/// Gets the value of a given pin.
		///
		/// Creates (exports) the pin if needed, and sets it to In direction.
		/// </summary>
		/// <param name="pin">The pin who's value to get</param>
		/// <returns>The value of the pin</returns>
		public static bool Read(GpioPins pin) {
			using(var file = CreatePinFile(pin, GpioDirection.In))
			{
				return file.Read();
			}
		}
		
		public void Write(bool value)
        {
			if (IsDisposed)
				throw new ObjectDisposedException(string.Empty);
			if (_direction != GpioDirection.Out)
				PinDirection = GpioDirection.Out;
				
			setPinValue(value ? High : Low);
        }
	
		public bool Read() 
		{
			if (IsDisposed)
				throw new ObjectDisposedException(string.Empty);
				
			if (_direction != GpioDirection.In)
				PinDirection = GpioDirection.In;

			return getPinValue((int)_pin) == High;
		}
		
		protected char getPinValue() 
		{
			return Convert.ToChar(getPinValue((int)_pin));
		}
		
		protected void setPinValue(char value) 
		{
			setPinValue((int)_pin, Convert.ToByte(value));
		}
		
		protected void setPinMode(char mode) 
		{
			setPinMode((int)_pin, Convert.ToByte(mode));
		}
        
		/// <summary>
		/// Gets the pin that this GPIO instance represents
		/// </summary>
		public GpioPins Pin 
		{
			get 
			{
				if (_disposed)
					throw new ObjectDisposedException(string.Empty);
				return _pin;
			}
		}
		
		public GpioDirection PinDirection
        {
            get
            {
				if (_disposed)
					throw new ObjectDisposedException(string.Empty);
					
				return _direction;
            }
            set
            {
				if (_disposed)
					throw new ObjectDisposedException(string.Empty);

                if (_direction == value) return;

				_direction = value;
				setPinMode(_direction == GpioDirection.In ? ModeInput : ModeOutput);
            }
        }
		
		/// <summary>
		/// Gets the disposal state of this GPIO instance
		/// </summary>
		public bool IsDisposed 
		{
			get 
			{
				return _disposed;
			}
		}
		
		public void Dispose()
		{
			gpio_close();
			if (_disposed)
				throw new ObjectDisposedException(string.Empty);
			_disposed = true;
		}
    }
}
