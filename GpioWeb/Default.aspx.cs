using System;
using System.Web;
using System.Web.UI;

namespace GpioWeb
{
	public partial class Default : System.Web.UI.Page
	{
		
		public virtual void button1Clicked (object sender, EventArgs args)
		{
			button1.Text = "You clicked me";
			pcDuino.Net.GpioFile.Write(pcDuino.Net.GpioPins.Gpio03, ledCheckBox.Checked);
		}
	}
}

