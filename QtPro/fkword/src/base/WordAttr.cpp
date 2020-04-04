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

#include "WordAttr.h"
#include "cppdbg11.h"


ostream& OneStdWord::operator << (ostream& os) const
{
	WordId mId;
	string mWord;		// the word
	string mTrans;		// translation
	string phonetic;	// for read and listen

	os << mId
		<< "," << mWord
		<< "," << mTrans
		<< "," << phonetic;

	return os;
}


ostream& operator << (ostream& os, const OneStdWord& stdword)
{
	return stdword.operator << (os);
}

