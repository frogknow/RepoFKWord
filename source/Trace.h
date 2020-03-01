#ifndef __TRACE_H__
#define __TRACE_H__

namespace BaseSys {

class Trace;

extern Trace gTrc;

using TraceMap     = map<string, Trace*, StrICmp>;
using TraceMapIter = TraceMap::iterator;
using TraceMapVal  = TraceMap::value_type;

class Trace{
public:
	enum TRACE_LEVEL {
		TRC_NO    = 0,  // Disabled
		TRC_ERR   = 1,
		TRC_ERR1,
		TRC_ERR2,
		TRC_ERR3,
		TRC_WRN,
		TRC_NTC,
		TRC_INF,
		TRC_NA,
		TRC_DBG,
//			TRC_DBG1,
//			TRC_DBG2,
//			TRC_DBG3,
		TRC_MAX,
	};

	Trace(const char* name, uint lvl = TRC_INF);
	virtual ~Trace();

	string& GetName()	{return mName; }
	uint    GetLevel()  {return mLevel; }

	void SetLevel(uint lvl)  {mLevel = lvl;}
	void Log(uint lvl, const string& str);
	void FmtLog(uint lvl, const string& str, const char* fmt, ...);
	void HexLog(uint lvl, const char* data, uint len);

	static void ListAll(ostream &os);
	static Trace* FindTrace(const char* name);

	static const char* GetTrcLvlName(uint lvl);
	static TraceMap* GetTraceMap();
	static void DoSetLvl(const char* trcName, const char* lvl, ostream& os);

private:
	string mName;
	uint   mLevel;

};

#define LOG(tc, lvl, msg) {
	if (tc.GetLevel() > lvl){
		ostringstream __oss;
		__oss << __FUNCTION__ << "(";
		__oss << __FILE__ << ":" << __LINE__ << "): ";
		__oss << msg;
		tc.Log(lvl, __oss.str());
	}
}

#define LOG_RAW(tc, lvl, msg) {
	if (tc.GetLevel() > lvl){
		ostringstream __oss;
		__oss << msg;
		tc.Log(lvl, __oss.str());
	}
}

#define LOG_HEX(tc, lvl, data, len) {
	if(tc.GetLevel() >= lvl){
		tc.HexLog(lvl, data, len);
	}
}

#define LOG_FMT(tc, lvl, fmt, oth...) {
	if(tc.GetLevel() >= lvl){
		ostringstream __oss;
		__oss << __FUNCTION__ << "(";
		__oss << __FILE__ << ":" << __LINE__ << "): ";
		tc.FmtLog(lvl, __oss.str(), fmt, ##oth);
	}

}

#define L_ERR(tc, msg)   LOG(tc, Trace::TRC_ERR,  msg)
#define L_ERR1(tc, msg)  LOG(tc, Trace::TRC_ERR1, msg)
#define L_ERR2(tc, msg)  LOG(tc, Trace::TRC_ERR2, msg)
#define L_ERR3(tc, msg)  LOG(tc, Trace::TRC_ERR3, msg)
#define L_WRN(tc, msg)   LOG(tc, Trace::TRC_WRN,  msg)
#define L_NTC(tc, msg)   LOG(tc, Trace::TRC_NTC,  msg)
#define L_INF(tc, msg)   LOG(tc, Trace::TRC_INF,  msg)
#define L_DBG(tc, msg)   LOG(tc, Trace::TRC_DBG,  msg)

#define F_ERR(tc, fmt, oth...)   LOG_FMT(tc, Trace::TRC_ERR,  fmt, ##oth)
#define F_ERR1(tc, fmt, oth...)  LOG_FMT(tc, Trace::TRC_ERR1, fmt, ##oth)
#define F_ERR2(tc, fmt, oth...)  LOG_FMT(tc, Trace::TRC_ERR2, fmt, ##oth)
#define F_ERR3(tc, fmt, oth...)  LOG_FMT(tc, Trace::TRC_ERR3, fmt, ##oth)
#define F_WRN(tc, fmt, oth...)   LOG_FMT(tc, Trace::TRC_WRN,  fmt, ##oth)
#define F_NTC(tc, fmt, oth...)   LOG_FMT(tc, Trace::TRC_NTC,  fmt, ##oth)
#define F_INF(tc, fmt, oth...)   LOG_FMT(tc, Trace::TRC_INF,  fmt, ##oth)
#define F_DBG(tc, fmt, oth...)   LOG_FMT(tc, Trace::TRC_DBG,  fmt, ##othmsg)

#define R_ERR(tc, msg)        LOG_RAW(tc, Trace::TRC_ERR,  msg)
#define R_WRN(tc, msg)        LOG_RAW(tc, Trace::TRC_WRN,  msg)
#define R_NTC(tc, msg)        LOG_RAW(tc, Trace::TRC_NTC,  msg)
#define R_INF(tc, msg)        LOG_RAW(tc, Trace::TRC_INF,  msg)
#define R_DBG(tc, msg)        LOG_RAW(tc, Trace::TRC_DBG,  msg)

#define H_ERR(tc, dat, len)   LOG_HEX(tc, Trace::TRC_ERR,  dat, len)
#define H_WRN(tc, dat, len)   LOG_HEX(tc, Trace::TRC_WRN,  dat, len)
#define H_NTC(tc, dat, len)   LOG_HEX(tc, Trace::TRC_NTC,  dat, len)
#define H_INF(tc, dat, len)   LOG_HEX(tc, Trace::TRC_INF,  dat, len)
#define H_DBG(tc, dat, len)   LOG_HEX(tc, Trace::TRC_DBG,  dat, len)






}



#endif
