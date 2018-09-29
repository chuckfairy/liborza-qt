/****************************************************************************
** Meta object code from reading C++ file 'IOPortChanger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "IOPortChanger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IOPortChanger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Orza__App__LV2UI__IOPortChanger_t {
    QByteArrayData data[3];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Orza__App__LV2UI__IOPortChanger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Orza__App__LV2UI__IOPortChanger_t qt_meta_stringdata_Orza__App__LV2UI__IOPortChanger = {
    {
QT_MOC_LITERAL(0, 0, 31), // "Orza::App::LV2UI::IOPortChanger"
QT_MOC_LITERAL(1, 32, 22), // "handleSelectionChanged"
QT_MOC_LITERAL(2, 55, 0) // ""

    },
    "Orza::App::LV2UI::IOPortChanger\0"
    "handleSelectionChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Orza__App__LV2UI__IOPortChanger[] = {

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
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Orza::App::LV2UI::IOPortChanger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IOPortChanger *_t = static_cast<IOPortChanger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleSelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Orza::App::LV2UI::IOPortChanger::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Orza__App__LV2UI__IOPortChanger.data,
      qt_meta_data_Orza__App__LV2UI__IOPortChanger,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Orza::App::LV2UI::IOPortChanger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Orza::App::LV2UI::IOPortChanger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Orza__App__LV2UI__IOPortChanger.stringdata0))
        return static_cast<void*>(const_cast< IOPortChanger*>(this));
    return QWidget::qt_metacast(_clname);
}

int Orza::App::LV2UI::IOPortChanger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
