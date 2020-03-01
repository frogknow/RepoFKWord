#ifndef __DBMGR_H__
#define __DBMGR_H__

#include<algorithm>
#include <initializer_list>
#include "cppdbg11.h"

enum DbType{
	DB_SQ,
	DB_RF, // regular file
};

enum BookType{
	YouDao_XML,
	YouDao_txt,
	FK_,
};

class DbMgr{
	DbType GetDbType(cstring& suff);
	BookType GetBookType(cstring& suff);
	MoRet parse(cstring& path, FKWordBook& wbook);

};


#endif
