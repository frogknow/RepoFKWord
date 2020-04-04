#ifndef __STYLEMGR_H__
#define __STYLEMGR_H__

#include<algorithm>
#include <initializer_list>
#include "cppdbg11.h"

#include <types.h>

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

using MapIdStyle   = map<int, WdAttrStyle>;
using MapNameStype = map<string, WdAttrStyle>;


class StyleMgr{
//	MapIdStyle& GetAllStyle();

	StyleMgr(const string& path){}

	// Serlize
	int SyncFile();
	static int LoadStyleLib();

	string     mPath;
	MapIdStyle mIdStyleMap;
};





#endif
