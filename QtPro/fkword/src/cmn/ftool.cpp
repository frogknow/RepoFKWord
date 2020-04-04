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

#include "cppdbg11.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "ftool.h"
#include "Trace.h"

void ftool::fnames(uint type, ListStr& names) const
{
    names.clear();

#if 0
    if(! S_ISDIR(mPath.c_str())){
//        L_ERR(Trc(), mPath << " should be dir");
        return;
    }

    while(1){
    	struct stat sb;
        stat(path, &sb);
        if (S_ISREG(sb.st_mode)){
            /* Handle regular file */
            names.insert(path);
        }
    }
#endif


}

string ftool::GetSuffix()
{
	return "";
}







