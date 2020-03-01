#ifndef __FKWordBook_H__
#define __FKWordBook_H__

#include<algorithm>
#include <initializer_list>
#include "cppdbg11.h"

class FKWordBook{
//	FKWorkBook();
	FKWordBook(cstring& path);

	MoRet AddWord(OneWord& rhs);
	MoRet RemoveWord(cstring& w);
	MoRet RemoveWord(WordId id);
	MoRet ModifyWord(OneWord& rhs);
	MoRet GetWord(cstring& w, OneWord& w);
	MoRet GetWord(WordId id, OneWord& w);


private:
	string mPath;
	ListWordId mWordIdList;
};

using ListWordBook = list<FKWordBook>;

class WordBookMgr{
public:
	// load default managed word book
	void load();
	void load(cstring& path);


private:
	ListWordBook mBooks;
};


#endif
