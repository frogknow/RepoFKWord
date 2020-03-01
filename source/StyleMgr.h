#ifndef __STYLEMGR_H__
#define __STYLEMGR_H__

#include<algorithm>
#include <initializer_list>
#include "cppdbg11.h"

using StyleId = int;
using StyleGrpId = int;

class WdAttrStyle{
public:
	struct StyleVal{
		enum Type{
			BOLD,
			HIGHLIGHT,
			SIZE,
			COLOR,
		};

		Type type;
		uint val;
	};


private:
	string   mName;
	int      mId;
	StyleVal mVal;
};


class StyleMgr{
//	MapIdStyle& GetAllStyle();

	void StyleMgr(const string& path);

	// Serlize
	int SyncFile();
	static int LoadStyleLib();

	string     mPath;
	MapIdStyle mIdStyleMap;
};


using MapIdStyle   = map<int, WdAttrStyle>;
using MapNameStype = map<string, WdAttrStyle>;


#endif
