#ifndef _READ_ONLY_MAP_H
#define _READ_ONLY_MAP_H

#include <map>
#include <string>

template <class TKey, class TVal>
class ReadOnlyMap
{
	private:
		std::map<TKey, TVal> m_keyValues; 
			
	public:
		const TVal& operator[](TKey idx) const;
		
};
#endif