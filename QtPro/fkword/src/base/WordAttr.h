#ifndef __WORDATTR_H__
#define __WORDATTR_H__

#include<algorithm>
#include <initializer_list>
#include "cppdbg11.h"

#include "StyleMgr.h"
#include "types.h"

using AttrId = int;
using WordId = int;
using ListWordId = list<WordId>;

// Don't really remove wordAttr.
// Don't really remove wordStyle;


class WordAttr{
	AttrId    mId;
	string mName;
	string mComments;

	StyleGrpId mStyGrpId;
};

class WordAttrMgr{

	static MoRet LoadAttrLib();
};

// All OneWord in a container, just use id in wordbook.
// Ok?

struct OneStdWord{
public:
	WordId mId;
	string mWord;		// the word
	string mTrans;		// translation
	string phonetic;	// for read and listen


	WordId AssignId() { return 0; }

	virtual ostream& operator << (ostream& os) const;
};

ostream& operator << (ostream& os, const OneStdWord& stdword);

class OneWord{
	WordId mId;
	string kwordForein;		// main key
	string kwordCN;

	string Phonetic;
	string Paraphrase;

	string mNote;
	// resource, such as pronunce.mp3

#if 1
	const WordAttr& wattr;
#else
	AttrId mAttrId;
#endif

};

using ListOneWord = list<OneWord>;
using MapWordId2Key = unordered_map<WordId, string>;
using MapWordKey2Id = unordered_map<string, WordId>;
using MapWordCN2Id  = unordered_map<string, WordId>;
using MapWordCN2Key = unordered_map<string, string>;
using MapId2Word    = unordered_map<WordId, OneWord&>;


class WordPool{
public:
	WordPool(cstring& path): mPath(path){}

	// single instance


	MoRet AddWord(OneWord& rhs);
	MoRet RemoveWord(cstring& w);
	MoRet RemoveWord(WordId id);
	MoRet ModifyWord(OneWord& rhs);
	MoRet GetWord(cstring& w);
	MoRet GetWord(WordId id);

protected:
	void load();

private:
	string mPath;
	ListOneWord mAllWords;


	MapWordId2Key mMapId2Key;
	MapWordKey2Id mMapKey2Id;
	MapWordCN2Id  mMapCN2Id;
	MapWordCN2Key mMapCN2Key;
	MapId2Word    mMapId2Word;

};
#endif
