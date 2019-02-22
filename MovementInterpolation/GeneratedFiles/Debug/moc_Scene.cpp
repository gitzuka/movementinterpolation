/****************************************************************************
** Meta object code from reading C++ file 'Scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Scene_t {
    QByteArrayData data[19];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scene_t qt_meta_stringdata_Scene = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Scene"
QT_MOC_LITERAL(1, 6, 7), // "updated"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 17), // "animationFinished"
QT_MOC_LITERAL(4, 33, 17), // "initializeProgram"
QT_MOC_LITERAL(5, 51, 21), // "QOpenGLShaderProgram*"
QT_MOC_LITERAL(6, 73, 7), // "program"
QT_MOC_LITERAL(7, 81, 10), // "ShaderData"
QT_MOC_LITERAL(8, 92, 10), // "shaderData"
QT_MOC_LITERAL(9, 103, 8), // "drawLeft"
QT_MOC_LITERAL(10, 112, 9), // "drawRight"
QT_MOC_LITERAL(11, 122, 19), // "changeAnimationTime"
QT_MOC_LITERAL(12, 142, 5), // "value"
QT_MOC_LITERAL(13, 148, 14), // "stopSimulation"
QT_MOC_LITERAL(14, 163, 6), // "update"
QT_MOC_LITERAL(15, 170, 4), // "draw"
QT_MOC_LITERAL(16, 175, 20), // "changeDrawStepsState"
QT_MOC_LITERAL(17, 196, 5), // "state"
QT_MOC_LITERAL(18, 202, 5) // "reset"

    },
    "Scene\0updated\0\0animationFinished\0"
    "initializeProgram\0QOpenGLShaderProgram*\0"
    "program\0ShaderData\0shaderData\0drawLeft\0"
    "drawRight\0changeAnimationTime\0value\0"
    "stopSimulation\0update\0draw\0"
    "changeDrawStepsState\0state\0reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   71,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    0,   82,    2, 0x08 /* Private */,
      15,    0,   83,    2, 0x08 /* Private */,
      16,    1,   84,    2, 0x08 /* Private */,
      18,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,

       0        // eod
};

void Scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scene *_t = static_cast<Scene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updated(); break;
        case 1: _t->animationFinished(); break;
        case 2: _t->initializeProgram((*reinterpret_cast< QOpenGLShaderProgram*(*)>(_a[1])),(*reinterpret_cast< const ShaderData(*)>(_a[2]))); break;
        case 3: _t->drawLeft(); break;
        case 4: _t->drawRight(); break;
        case 5: _t->changeAnimationTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->stopSimulation(); break;
        case 7: _t->update(); break;
        case 8: _t->draw(); break;
        case 9: _t->changeDrawStepsState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QOpenGLShaderProgram* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Scene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scene::updated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Scene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Scene::animationFinished)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Scene::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Scene.data,
      qt_meta_data_Scene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Scene.stringdata0))
        return static_cast<void*>(const_cast< Scene*>(this));
    return QObject::qt_metacast(_clname);
}

int Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Scene::updated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Scene::animationFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
