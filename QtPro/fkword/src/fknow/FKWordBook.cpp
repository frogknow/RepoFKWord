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

#include "FKWordBook.h"
#include "cppdbg11.h"



MoRet WordBookMgr::load(cstring& path)
{
	FKWordBook wbook(path);
#if 0

#if 1
	wbook.SetPath(path);
#else
	DbMgr::parse(path, wbook);
#endif
	mBooks.insert(wbook);
#endif

	return MO_OK;
}

MoRet WordBookMgr::load(void)
{
#if 0
	string path;
	FKWordConf::Get(path);

	ListStr bookdbs;

	ftool(path).fnames(bookdbs);

	// load all db name
	for_each(bookdbs.begin(), bookdbs.end(), [](cstring& dbname){
		MoCallCheck(load(path), "Failed to load word book " << dbname);
	});
#endif

	return MO_OK;
}














