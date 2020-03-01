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


void ftool::fnames(uint type, ListString& names)
{
    names.clear();

    if(! S_ISDIR(mPath)){
        L_ERR(Trc(), mPath << " should be dir");
        return;
    }

    while(){
        stat(path, &sb);
        if (S_ISREG(sb.st_mode)){
            /* Handle regular file */
            names.insert(path);
        }
    }



}









