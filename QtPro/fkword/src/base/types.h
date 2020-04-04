#ifndef __TYPES_H__
#define __TYPES_H__

#include <map>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>

#include <iomanip>
#include <sstream>
#include <ostream>

#include <locale>

#include <string.h>


#if defined(_MSC_VER) && (_MSC_VER >= 1600)
//#pragma execution_character_set("utf-8")
#endif


using std::ostream;
using std::endl;
using std::setw;

using std::map;
using std::list;
using std::vector;
using std::string;
using std::unordered_map;

using std::string;
using std::wstring;
using std::locale;

using u8t    = unsigned char;
using ushort = unsigned short;
using uint   = unsigned int;
using ulong  = unsigned long;
using ullong = unsigned long long;
//using sint = int;

using ConstStr = const string;
using ListStr = list<string>;

using cstring = ConstStr;

enum MoRet{
	MO_FAIL = -1,
	MO_OK = 0,
//	MO_
};



#endif
