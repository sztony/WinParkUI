/****************************************************************************
** Meta object code from reading C++ file 'monthlycarddialog.h'
**
** Created: Fri Sep 7 15:26:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dialog/monthlycarddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monthlycarddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CMonthlyCardDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   20,   19,   19, 0x08,
      62,   19,   19,   19, 0x08,
      83,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CMonthlyCardDialog[] = {
    "CMonthlyCardDialog\0\0strText\0"
    "on_edtNumber_textChanged(QString)\0"
    "on_btnSave_clicked()\0on_btnExit_clicked()\0"
};

const QMetaObject CMonthlyCardDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CMonthlyCardDialog,
      qt_meta_data_CMonthlyCardDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CMonthlyCardDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CMonthlyCardDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CMonthlyCardDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMonthlyCardDialog))
        return static_cast<void*>(const_cast< CMonthlyCardDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CMonthlyCardDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_edtNumber_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_btnSave_clicked(); break;
        case 2: on_btnExit_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
