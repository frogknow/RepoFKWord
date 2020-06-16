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

#include "baseinc.h"
#include "cmnutil.h"

#include "tinyxml.h"
#include "Youdao.h"


// We make an agreement that all words in youdao wordbook,
// it's key must a english word, be sure not to use chinese.




MapId2YdXmlWord YoudaoWb::mWdMap;
MapStr2Id YoudaoWb::mEnMap;
MapStr2Id YoudaoWb::mChnMap;

#if 1

bool findWord(const string& id, YoudaoXmlWord& word)
{

}

bool findTrans(const string& trans, YoudaoXmlWord& word)
{


}

ostream& YoudaoXmlWord::operator << (ostream& os) const
{
	super::operator << (os);
	os << "," << mTags
		<< "," << mProgress;

	return os;
}

ostream& operator << (ostream& os, const YoudaoXmlWord& ydxmlword)
{
	return ydxmlword.operator << (os);
}
#endif

bool YoudaoWb::LoadXml(ConstStr& fxml)
{
	TiXmlDocument doc(fxml.c_str());

	bool loadOkay = doc.LoadFile();
	if(! loadOkay) {
		oute("load", fxml, "failed");
		return false;
	}

	TiXmlNode* wbitem = doc.FirstChild( "wordbook" );
//outd(wbitem->Value());

	for(TiXmlNode* worditem = wbitem->FirstChild();
		worditem != nullptr;
		worditem = worditem->NextSiblingElement()){

//outd(worditem->Value());

		YoudaoXmlWord ydword;
		for(const TiXmlNode* wordattr = worditem->FirstChild();
			wordattr != nullptr;
			wordattr = wordattr->NextSibling()) {

			string text(wordattr->FirstChild()->Value());

			QDBG(wordattr->Value() << text.c_str());

			if(IsSame("word", wordattr->Value())) {
				ydword.mWord = text;
			} else if(IsSame("trans", wordattr->Value())){
				ydword.mTrans = text;
			} else if(IsSame("phonetic", wordattr->Value())){
				ydword.phonetic = text;
			} else if(IsSame("tags", wordattr->Value())){
				ydword.mTags = text;
			} else if(IsSame("progress", wordattr->Value())){
				ydword.mProgress = atoi(text.c_str());
			} else {
				outd("Unknown attr", wordattr->Value(), text);
			}
		}

		ydword.AssignId();
		outd(ydword);

//		mYdXmlList.push_back(ydword);

//		mEnMap[] = ;
//		mChnMap[] = ;
	}


}


void YoudaoWb::load(cstring& ydf)
{
//	string suffix = xxx;
	LoadXml(ydf);
}

bool YoudaoWb::load()
{
#if 1
	load("../fkword/wbfile/Youdao/001 .xml");
#else
	string yddir;
	WbCfg::GetYoudaoDir(yddir);
	while(lastfile){
		string ydf;
		load(ydf);
	}
#endif

	return true;
}

