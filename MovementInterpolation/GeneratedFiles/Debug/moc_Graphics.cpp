/****************************************************************************
** Meta object code from reading C++ file 'Graphics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Graphics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Graphics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Graphics_t {
    QByteArrayData data[6];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Graphics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Graphics_t qt_meta_stringdata_Graphics = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Graphics"
QT_MOC_LITERAL(1, 9, 16), // "initializeBuffer"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "meshId"
QT_MOC_LITERAL(4, 34, 27), // "QOpenGLBuffer::UsagePattern"
QT_MOC_LITERAL(5, 62, 11) // "bufferUsage"

    },
    "Graphics\0initializeBuffer\0\0meshId\0"
    "QOpenGLBuffer::UsagePattern\0bufferUsage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graphics[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

       0        // eod
};

void Graphics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Graphics *_t = static_cast<Graphics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initializeBuffer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QOpenGLBuffer::UsagePattern(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Graphics::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Graphics.data,
      qt_meta_data_Graphics,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Graphics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graphics::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Graphics.stringdata0))
        return static_cast<void*>(const_cast< Graphics*>(this));
    return QObject::qt_metacast(_clname);
}

int Graphics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
