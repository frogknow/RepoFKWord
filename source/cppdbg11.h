#ifndef CPPDBG_H
#define CPPDBG_H


#include <stdarg.h>
#include <stdio.h>
#include <iostream>

#include <pthread.h>

using std::to_string;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::forward;
// 尝试把COUTD宏定义为“//”或者#undef等，均失败
namespace dbg_macro{
	#define CDBG
	#define CPPDBG
	#define CDBGMARK
	#define CPPDBGMARK


	#define LINENO2STR(lineno) #lineno

	// Test in a function like this.
	// #if sizeof(__FUNCTION__) == sizeof(void*)
	// #define __FUNCTION_POINTER
	// #endif


	// Get a C string for trace

	#ifdef CDBGMARK
	#ifdef __FUNCTION_POINTER
		#define cdbg_mark(fun, line, str) ("[" fun "(): " LINENO2STR(line) str "]")
		#define CMARK1(mark) cdbg_mark(__FUNCTION__, __LINE__, " " mark)
		#define CMARK2 cdbg_mark(__FUNCTION__, __LINE__, "")
	#else
		#define cdbg_mark(file, line, str) ("[" file " " LINENO2STR(line) str "]")
		#define CMARK1(mark) cdbg_mark(__FILE__, __LINE__, " " mark)
		#define CMARK2 cdbg_mark(__FILE__, __LINE__, "")
	#endif

	#else
		#define cdbg_mark(file, line, str) (str)
		#define CMARK1(mark) (mark)
		#define CMARK2 ""

	#endif



	// Get a CPP string for trace
	#ifdef CPPDBGMARK
		#define cppdbg_mark(func, line, str) ("[" + string(fun) + "() " \
			+ LINENO2STR(line) + str + "]")
		#define CPPMARK1(mark) cppdbg_mark(__func__, __LINE__, " " mark)
		#define CPPMARK2 cppdbg_mark(__func__, __LINE__, "")
		#define CPPMARKSTR (string("[") + __FILE__ + ":" \
			+ to_string(__LINE__) + " " \
			+ __FUNCTION__ + "()]")
	#else
		#define cppdbg_mark(func, line, str) string(str)
		#define CPPMARK1(mark) cppdbg_mark("", "", mark)
		#define CPPMARK2 cppdbg_mark("", "", "")
		#define CPPMARKSTR ("")
	#endif


	#ifdef CDBG
		#define LOGD(a, b...) fprintf(stdout, "Dbg:[%s:%d][%s()] " a "\n", \
			__FILE__, __LINE__, __FUNCTION__, ##b)
		#define LOGE(a, b...) fprintf(stderr, "Err:[%s:%d][%s()] " a "\n", \
			__FILE__, __LINE__, __FUNCTION__, ##b)

		#define THLOGD(a, b...) fprintf(stdout, "THDbg:[%lu %s:%d][%s()] " a "\n", \
			pthread_self(), __FILE__, __LINE__, __FUNCTION__, ##b)
		#define THLOGE(a, b...) fprintf(stderr, "THErr:[%lu %s:%d][%s()] " a "\n", \
			pthread_self(), __FILE__, __LINE__, __FUNCTION__, ##b)
	#else
		#define LOGD(a, b...)
		#define LOGE(a, b...)
		#define THLOGD(a, b...)
		#define THLOGE(a, b...)
	#endif


	#ifdef CPPDBG
		#define COUTP(a) cout << a
		#define COUTD(a) cout << "Dbg:[" << __FILE__ << ":" << __LINE__ \
			<< " " << __func__ << "()] " << a << endl
		#define COUTE(a) cerr << "Err:[" << __FILE__ << ":" << __LINE__ \
			<< " " << __func__ << "()] " << a << endl


		#define THCOUTP(a) cout << pthread_self() << " " << a
		#define THCOUTD(a) cout << "THDbg:[" << pthread_self() << " " << __FILE__ << ":" << __LINE__ \
			<< " " << __func__ << "()] " << a << endl
		#define THCOUTE(a) cerr << "THErr:[" << pthread_self() << " " << __FILE__ << ":" << __LINE__ \
			<< " " << __func__ << "()] " << a << endl
	#else
		#define COUTP(a)
		#define COUTD(a)
		#define COUTE(a)
		#define THCOUTP(a)
		#define THCOUTD(a)
		#define THCOUTE(a)
	#endif

}

namespace out_obo{
	void inline outall(void){cout << endl;}

	template <typename T1, typename... T>
//	void outall(T1& t1, T... t) // ok, copy argument list
//	void outall(T1& t1, T...t)  // ok, copy argument list
	void outall(T1& t1, T&&... t)
	{
		cout << t1 << " ";
//		outall(t...); // ok, with no copy
		outall(forward<T&>(t)...); // ok, with no copy
	}

	#define outd(b...) outall("Dbg:", CPPMARKSTR, ##b)
	#define oute(b...) outall("Err:", CPPMARKSTR, ##b)
	#define markd()		outd("")
	#define marke()		oute("")
}

using out_obo::outall;

template <typename T>
void show_cont(const string& mark, const T& cont)
{
	outd(mark);
	for(const auto& elem: cont){
		cout << elem << " ";
	}
	cout << endl;
}

// show one by one
// Don't use this, it will output argument list by reverse order.
namespace show_obo{
	template <typename ... T>
	void dbgshow1(T... t){

	}

	template <typename T>
	T dbgshow2(T t)
	{
		cout << t << " ";
		return t;
	}

	template <typename...T>
	void dbgshow(T... t)
	{
		dbgshow1(dbgshow2(t)...);
		cout << endl;
	}

	#define OUTD(b...) dbgshow(__FILE__, __func__, __LINE__, ##b)
	#define OUTMARK() 	dbgshow(__FILE__, __func__, __LINE__)
}


using show_obo::dbgshow;



#endif
