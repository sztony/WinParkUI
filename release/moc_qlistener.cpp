/****************************************************************************
** Meta object code from reading C++ file 'qlistener.h'
**
** Created: Mon Jul 29 16:48:38 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PlateDilivery/qlistener.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlistener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QListener[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   11,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QListener[] = {
    "QListener\0\0socketDescriptor\0Accept(int)\0"
    "HandleAccept(int)\0"
};

const QMetaObject QListener::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QListener,
      qt_meta_data_QListener, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QListener::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QListener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QListener))
        return static_cast<void*>(const_cast< QListener*>(this));
    return QThread::qt_metacast(_clname);
}

int QListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Accept((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: HandleAccept((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QListener::Accept(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
