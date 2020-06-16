#ifndef __FKWordBook_H__
#define __FKWordBook_H__

#include <algorithm>
#include <initializer_list>
#include "cppdbg11.h"

#include "WordAttr.h"
#include "types.h"

class FKWordBook{
public:
//	FKWorkBook();
	FKWordBook(cstring& path) : mPath(path) {}

	MoRet AddWord(OneWord& rhs);
	MoRet RemoveWord(cstring& w);
	MoRet RemoveWord(WordId id);
	MoRet ModifyWord(OneWord& rhs);

	MoRet GetWord(ConstStr& key, OneWord& w);
	MoRet GetWord(WordId id,  OneWord& w);


private:
	string mPath;
	ListWordId mWordIdList;
};

using ListWordBook = list<FKWordBook>;

class WordBookMgr{
public:
	// load default managed word book
	MoRet load();
	MoRet load(ConstStr& path);


private:
	ListWordBook mBooks;
};


#endif
