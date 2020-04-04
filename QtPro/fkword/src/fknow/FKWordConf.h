#ifndef __FKWordConf_H__
#define __FKWordConf_H__

#include <algorithm>
#include <initializer_list>
#include "cppdbg11.h"

#include "types.h"

class FKWordConf{
public:
	static MoRet load();
	static MoRet save();
	static MoRet backup();
};




#endif
