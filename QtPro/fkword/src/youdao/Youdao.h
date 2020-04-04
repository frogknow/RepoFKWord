#ifndef __YOUDAO_H__
#define __YOUDAO_H__

#include<algorithm>
#include <initializer_list>
#include "cppdbg11.h"

#include <WordAttr.h>

#include <map>

using std::map;


class YoudaoXmlWord : public OneStdWord {
	using super = OneStdWord;
public:
	string mTags;
	int    mProgress;

public:
	virtual ostream& operator << (ostream& os) const;

};

ostream& operator << (ostream& os, const YoudaoXmlWord& ydxmlword);


//using ListYdXml = list<YoudaoXmlWord>;
using MapId2YdXmlWord = map<WordId, YoudaoXmlWord>;
using MapStr2Id = map<string, WordId>;

class YoudaoWb{
public:
	static bool load();


protected:
	static bool LoadXml(ConstStr& fxml);

	static void load(cstring& ydf);

private:
//	ListYdXml mYdXmlList;
	static MapId2YdXmlWord  mWdMap; // key by id

	static MapStr2Id mEnMap;   // key by english
	static MapStr2Id mChnMap;  // key by chinese
};


#endif
