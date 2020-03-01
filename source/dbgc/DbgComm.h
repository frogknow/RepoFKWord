#ifndef __DBGCOMM_H__
#define __DBGCOMM_H__



#if 1
void inline ASSERT(bool cond, cstring& mod, cstring& info)
{
	if(! cond){
		oute(mod, info);
		L_ERR(gDbgTrc, mod << ":" << info);
		abort();
	}
}

#else
#define ASSERT(cond, mod, info)
do{
	if(! cond){

	}

}while(0);
#endif

#define CallCheck(cond, err)
if(! cond){
	L_ERR(gDbgTrc, err);
}

#define MoCallCheck(call, err)
do{
	MoRet moRet = call;
	if(moRet != MO_OK){
		CallCheck(0, err);
		return moRet;
	}
}while(0);



class DbgComm : public CommThread
{



};


#endif
