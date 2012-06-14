#ifndef THREADLIBRARY_GLOBAL_H
#define THREADLIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QObject>

#if defined(THREADLIBRARY_LIBRARY)
#  define THREADLIBRARYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define THREADLIBRARYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // THREADLIBRARY_GLOBAL_H
