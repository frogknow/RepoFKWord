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

#include <QFile>
#include <QTextStream>
#include <QApplication>

#include "cppdbg11.h"
#include "main.h"


#include "types.h"
#include "FKWordConf.h"
#include "Youdao.h"

#include "mainwindow.h"



QFile g_dbgFile("debug.log");
QTextStream g_dbgts(&g_dbgFile);


// Note: it's a tool for learn word, but not
// a tool for search word.
// Seem YoudaoWB as a library.


void Usage()
{

}

// dbc



int start(void)
{
//	DbgServer::start();

	do {
		char cwd[128];
		getcwd(cwd, sizeof(cwd) - 1);
		outd("cwd", cwd);
	}while(0);


	// load config file
	FKWordConf::load();

	// load youdao wordbook
	YoudaoWb::load();


	// load attribute lib
	// load style lib
//	WordAttrMgr::LoadAttrLib();
//	StyleMgr::LoadStyleLib();

	// load word note
//	WordBookMgr::load();

//	// Load All App page
//	// Show main page


	return 0;
}

#include <Windows.h>
#include <QLocale>
#include <QTextCodec>

//locale::global(locale(""));

void test_locale()
{
	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForLocale(codec);

//	_wsetlocale(LC_ALL, L"zh");
	do {
//		locale langLocale("zh");
//		wcout.imbue(langLocale);
//		cout << langLocale.name() << endl;
//		return true;
	}while(0);

	string  str1  = "你不好";
	wstring wstr2 = L"你好";
//	outd(wstr);

//	cout.imbue(locale("zh_CN"));
	cout << "你不好" << endl;
//	wcout.imbue(locale("zh_CN.utf8"));
	wcout << "123" << wstr2.c_str()
	<< "456" << wstr2
	<< "789" << L"你好" << endl;

//	qDebug() << "你好啊" << endl;

    QString qstr("qt啥子");
    qDebug() <<qstr;

	QLocale qloc;
	qDebug() << QLocale::languageToString(qloc.language()) << endl;

}


void test_env()
{

	test_locale();
}

void DbgMsgHandler(QtMsgType type, const QMessageLogContext &, const QString & str)
{
    g_dbgts << str << endl;
//    cout << str.toStdString() <<endl;
}

void set_debug_mode()
{
    if(g_dbgFile.exists()){
	    g_dbgFile.open(QIODevice::ReadWrite | QIODevice::Append);
	    g_dbgFile.resize(0);
	    qInstallMessageHandler(DbgMsgHandler);
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

	test_env();

//	return 0;

	start();

    w.show();

//	extern int xmltest_main();
//	xmltest_main();

    return a.exec();
}
