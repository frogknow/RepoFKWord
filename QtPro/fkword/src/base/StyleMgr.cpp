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

#include "StyleMgr.h"
#include "cppdbg11.h"

#define PATH_DFT_STYLE "./etc/dftstyle.txt"

MapIdStyle& GetAllStyle()
{
	static MapIdStyle gAllStyle;

	return gAllStyle;
}

void ParseStyle(const string path, MapIdStyle& idStyleMap)
{

}


void LoadDefaultStyle()
{
	ParseStyle(PATH_DFT_STYLE, GetAllStyle());
}

