#ifndef __TYPES_H__
#define __TYPES_H__

#include <list>
#include <string>

using std::list;
using std::string;



using u8t    = unsigned char;
using ushort = unsigned short;
using uint   = unsigned int;
using ulong  = unsigned long;
using ullong = unsigned long long;
//using sint = int;

using cstring = const string;
using ListString = list<string>;


enum MoRet{
	MO_FAIL = -1,
	MO_OK = 0,
//	MO_
};



#endif
