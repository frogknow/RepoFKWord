#ifndef __QDBG_H__
#define __QDBG_H__

#include <QDebug>

#define QDBG(b) qDebug() << "D " << __FILE__ << ":" << __LINE__ << "," << __FUNCTION__ << "()" << b << endl
#define QERR(b) qError() << "E " << __FILE__ << ":" << __LINE__ << "," << __FUNCTION__ << "()" << b << endl


#endif
