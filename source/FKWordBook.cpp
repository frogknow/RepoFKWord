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

MoRet WordBookMgr::load(cstring& path)
{
	FKWordBook wbook;
#if 1
	wbook.SetPath(path);
#else
	DbMgr::parse(path, wbook);
#endif
	mBooks.insert(wbook);
}

MoRet WordBookMgr::load(void)
{
	string path;
	FKWordConf::Get(path);

	ListString bookdbs;

	ftool(path).fnames(bookdbs);

	// load all db name
	for_each(bookdbs.begin(), bookdbs.end(), [](cstring& dbname){
		MoCallCheck(load(path), "Failed to load word book " << dbname);
	});
}














