/****************************************************************************
** Meta object code from reading C++ file 'MovementInterpolation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MovementInterpolation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MovementInterpolation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MovementInterpolation_t {
    QByteArrayData data[12];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MovementInterpolation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MovementInterpolation_t qt_meta_stringdata_MovementInterpolation = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MovementInterpolation"
QT_MOC_LITERAL(1, 22, 14), // "initializeLeft"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 15), // "initializeRight"
QT_MOC_LITERAL(4, 54, 16), // "changeStartEuler"
QT_MOC_LITERAL(5, 71, 14), // "changeStartPos"
QT_MOC_LITERAL(6, 86, 15), // "changeStartQuat"
QT_MOC_LITERAL(7, 102, 14), // "changeEndEuler"
QT_MOC_LITERAL(8, 117, 12), // "changeEndPos"
QT_MOC_LITERAL(9, 130, 13), // "changeEndQuat"
QT_MOC_LITERAL(10, 144, 15), // "startSimulation"
QT_MOC_LITERAL(11, 160, 15) // "resetSimulation"

    },
    "MovementInterpolation\0initializeLeft\0"
    "\0initializeRight\0changeStartEuler\0"
    "changeStartPos\0changeStartQuat\0"
    "changeEndEuler\0changeEndPos\0changeEndQuat\0"
    "startSimulation\0resetSimulation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MovementInterpolation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MovementInterpolation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MovementInterpolation *_t = static_cast<MovementInterpolation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initializeLeft(); break;
        case 1: _t->initializeRight(); break;
        case 2: _t->changeStartEuler(); break;
        case 3: _t->changeStartPos(); break;
        case 4: _t->changeStartQuat(); break;
        case 5: _t->changeEndEuler(); break;
        case 6: _t->changeEndPos(); break;
        case 7: _t->changeEndQuat(); break;
        case 8: _t->startSimulation(); break;
        case 9: _t->resetSimulation(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MovementInterpolation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MovementInterpolation.data,
      qt_meta_data_MovementInterpolation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MovementInterpolation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MovementInterpolation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MovementInterpolation.stringdata0))
        return static_cast<void*>(const_cast< MovementInterpolation*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MovementInterpolation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
