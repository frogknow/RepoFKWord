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

#include "cppdbg11.h"

// the suffix in path marked the DB type
// double suffix like this:
//	book1.youdao.xml
//	book1.youdao.txt
//	book1.fk.db
//	book1.fk.txt
DbType GetDbType(cstring& suff)
{

}

BookType GetBookType(cstring& suff)
{

}

MoRet parse(cstring& path, FKWordBook& wbook)
{
	auto suff = ftool(path).GetSuffix();
	auto dbtype = GetDbType(suff);
	auto booktype = GetBookType(suff);







}


