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
#include "main.h"

void Usage()
{

}

// dbc



int main(void)
{
	DbgServer::start();

	// load config file
	FKWordConf::load();


	// load attribute lib
	// load style lib
	WordAttrMgr::LoadAttrLib();
	StyleMgr::LoadStyleLib();

	// load word note
	WordBookMgr::load();

//	// Load All App page
//	// Show main page


	return 0;
}
