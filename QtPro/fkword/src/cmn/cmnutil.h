#ifndef __COMMON_H__
#define __COMMON_H__

#include<algorithm>
#include <initializer_list>

#include <sstream>


#include "types.h"
#include "cppdbg11.h"

using std::ostream;


bool IsSame(const string str1, const string str2);

template<typename TypeCont, typename TypeElem>
bool IsContain(const TypeCont& cont, const TypeElem& elem);

template<typename TypeCont, typename TypeElem>
bool IsContainKey(const TypeCont& cont, const TypeElem& key);


void DumpHex(ostream& oss, const u8t* addr, uint len, char delim);

#endif
