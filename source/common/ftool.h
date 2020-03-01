#ifndef __FTOOL_H__
#define __FTOOL_H__

#include<algorithm>
#include <initializer_list>
#include "cppdbg11.h"

#if 0
   S_IFSOCK   0140000   socket
   S_IFLNK    0120000   symbolic link
   S_IFREG    0100000   regular file
   S_IFBLK    0060000   block device
   S_IFDIR    0040000   directory
   S_IFCHR    0020000   character device
   S_IFIFO    0010000   FIFO
#endif



class ftool{
public:
	ftool(cstring& path):
		mPath(path){}

	// get all names under dir 'mPath'
	// should not provide API like this with confusing
//	void fnames(ListString& names) const;

	void fnames(uint type, ListString& names) const;



private:
	string mPath;
};


#endif
