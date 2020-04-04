#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <typeinfo>
#include <exception>
#include <memory>
#include <thread>

#include <memory>

#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
//#include <priority_queue> // no such header file.

#include "cmnutil.h"
#include "cppdbg11.h"


bool IsSame(const string str1, const string str2)
{
	return str1.compare(str2) == 0;
}

template<typename TypeCont, typename TypeElem>
bool IsContain(const TypeCont& cont, const TypeElem& elem)
{
	for(auto& memb : cont) {
		if(memb == elem) {
			return true;
		}
	}

	return false;
}

template<typename TypeCont, typename TypeElem>
bool IsContainKey(const TypeCont& cont, const TypeElem& key)
{
	for(auto& memb : cont) {
		if(memb.first == key) {
			return true;
		}
	}

	return false;
}


void DumpHex(ostream& oss, const u8t* addr, uint len, char delim)
{
	return;
}

