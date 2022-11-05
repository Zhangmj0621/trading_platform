/****************************************************************************
** Meta object code from reading C++ file 'refresh.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../trading_platform/refresh.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'refresh.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Refresh_t {
    QByteArrayData data[8];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Refresh_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Refresh_t qt_meta_stringdata_Refresh = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Refresh"
QT_MOC_LITERAL(1, 8, 13), // "refreshsignal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "string"
QT_MOC_LITERAL(4, 30, 2), // "id"
QT_MOC_LITERAL(5, 33, 14), // "refreshsignal2"
QT_MOC_LITERAL(6, 48, 14), // "refreshsignal3"
QT_MOC_LITERAL(7, 63, 14) // "refreshsignal4"

    },
    "Refresh\0refreshsignal\0\0string\0id\0"
    "refreshsignal2\0refreshsignal3\0"
    "refreshsignal4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Refresh[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       7,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void Refresh::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Refresh *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshsignal((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->refreshsignal2((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->refreshsignal3((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 3: _t->refreshsignal4((*reinterpret_cast< string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Refresh::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Refresh::refreshsignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Refresh::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Refresh::refreshsignal2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Refresh::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Refresh::refreshsignal3)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Refresh::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Refresh::refreshsignal4)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Refresh::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Refresh.data,
    qt_meta_data_Refresh,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Refresh::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Refresh::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Refresh.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Refresh::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Refresh::refreshsignal(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Refresh::refreshsignal2(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Refresh::refreshsignal3(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Refresh::refreshsignal4(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
