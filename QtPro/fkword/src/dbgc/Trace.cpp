
#include <iostream>
#include <sstream>

#include "cmnutil.h"
#include "Trace.h"



using std::ostringstream;
using std::setw;

namespace BaseSys
{

Trace gTrc("Global");

static const char* gTrcLvlName[TRC_MAX] = {
	"TRC_NO",
	"TRC_ERR",
	"TRC_ERR1",
	"TRC_ERR2",
	"TRC_ERR3",
	"TRC_WRN",
	"TRC_NTC",
	"TRC_INF",
	"TRC_NA",
	"TRC_DBG",
};

const char* Trace::GetTrcLvlName(uint lvl)
{
	switch(lvl){
	case TRC_NO:
	case TRC_ERR:
	case TRC_ERR1:
	case TRC_ERR2:
	case TRC_ERR3:
	case TRC_WRN:
	case TRC_NTC:
	case TRC_INF:
	case TRC_NA:
	case TRC_DBG:
		return gTrcLvlName[lvl];
		break;
	default:
		return gTrcLvlName[TRC_NA];
		break;
	}

	return nullptr;
}

TraceMap& Trace::GetTraceMap()
{
	static TraceMap* pTraceMap = nullptr;

	if(! pTraceMap){
		pTraceMap = new TraceMap();
	}

	return *pTraceMap;
}


Trace* Trace::FindTrace(const char* name)
{
	auto it = GetTraceMap().find(name);

	if(it != GetTraceMap().end()){
		return it->second;
	}

	return nullptr;
}



Trace::Trace(const char* name, uint lvl)
	: mName(name), mLevel(lvl)
{
	TraceMapVal v(name, this);
	GetTraceMap().insert(v);
}

Trace::~Trace()
{
	GetTraceMap().erase(mName);
}

int Trace::GetSysLogLvl(uint lvl)
{
#if 0
	int priority = LOG_INFO;

	switch(lvl){
	case TRC_ERR:
	case TRC_ERR1:
	case TRC_ERR2:
	case TRC_ERR3:
		priority = LOG_ERR;
		break;
	case TRC_WRN:
		priority = LOG_WARNING;
		break;
	case TRC_NTC:
		priority = LOG_NOTICE;
		break;
	case TRC_INF:
	case TRC_NA:
	case TRC_DBG:
	default:
		priority = LOG_DEBUG;
		break;
	}

	return priority;
#endif

return 0;

}

void Trace::Log(uint lvl, const string& str)
{
	if(lvl <= mLevel){
		int priority = GetSysLogLvl(lvl);
//		syslog(priority, "%s", str.c_str());
	}
}

void Trace::FmtLog(uint lvl, const string& str, const char* fmt, ...)
{
	if(lvl <= mLevel) {
		va_list ap;
		char format[512];
		char content[2048];

		int priority = GetSysLogLvl(lvl);
		snprintf(format, sizeof(format) - 1, "%s %s", str.c_str(), fmt);

		va_start(ap, fmt);
		vsnprintf(content, sizeof(content) - 1, format, ap);
//		syslog(priority, "%s", content);
		va_end(ap);
	}
}

void Trace::HexLog(uint lvl, const u8t* data, uint len)
{
	for(uint i = 0; i < len; i += 16){
		ostringstream oss;
		uint realLen = 16;

		if((i + realLen) > len){
			realLen = len - i;
		}
		DumpHex(oss, data + i, realLen, ' ');
		Log(lvl, oss.str());
	}
}

void Trace::ListAll(ostream& os)
{
	uint count = 0;
	auto trcMap = GetTraceMap();
	for(const auto& it : trcMap){
		if(it.second != nullptr){
			os << setw(15) << it.first << "(" << GetTrcLvlName(it.second->GetLevel());
		}

		if((++count) % 4 == 0){
			os << endl;
		}
	}
}

void Trace::DoSetLvl(const char* trcName, const char* strLvl, ostream& os)
{
	Trace* pTrace = FindTrace(trcName);
	if(pTrace == nullptr){
		os << "Error: trace " << trcName << "is invalid, use trc list to check " << endl;
		return;
	}

	uint lvl = (uint)atoi(strLvl);
	if(! strncasecmp(strLvl, "info", 3)){
		lvl = TRC_INF;
	}else if(! strncasecmp(strLvl, "warn", 3)){
		lvl = TRC_WRN;
	}else if(! strncasecmp(strLvl, "error", 3)){
		lvl = TRC_ERR;
	}else if(! strncasecmp(strLvl, "notice", 6)){
		lvl = TRC_NTC;
	}else if(! strncasecmp(strLvl, "debug", 3)){
		lvl = TRC_DBG;
	}else {
//		lvl = TRC_DBG;
	}

	os << "Setting trace level of " << trcName << " to " << lvl << endl;
	pTrace->SetLevel(lvl);

}



} // end of namespace



