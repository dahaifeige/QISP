/****************************************************************************
** Meta object code from reading C++ file 'ISPSpaceCorrection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ISPSpaceCorrection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ISPSpaceCorrection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ISPSpaceCorrection_t {
    QByteArrayData data[7];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ISPSpaceCorrection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ISPSpaceCorrection_t qt_meta_stringdata_ISPSpaceCorrection = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ISPSpaceCorrection"
QT_MOC_LITERAL(1, 19, 27), // "on_SCEnableCheckBox_clicked"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 9), // "isClicked"
QT_MOC_LITERAL(4, 58, 32), // "on_SCValueLineEdit_returnPressed"
QT_MOC_LITERAL(5, 91, 31), // "on_RGBDirectRadioButton_clicked"
QT_MOC_LITERAL(6, 123, 31) // "on_BGRDirectRadioButton_clicked"

    },
    "ISPSpaceCorrection\0on_SCEnableCheckBox_clicked\0"
    "\0isClicked\0on_SCValueLineEdit_returnPressed\0"
    "on_RGBDirectRadioButton_clicked\0"
    "on_BGRDirectRadioButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ISPSpaceCorrection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    0,   37,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       6,    1,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void ISPSpaceCorrection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ISPSpaceCorrection *_t = static_cast<ISPSpaceCorrection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_SCEnableCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_SCValueLineEdit_returnPressed(); break;
        case 2: _t->on_RGBDirectRadioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_BGRDirectRadioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ISPSpaceCorrection::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ISPSpaceCorrection.data,
      qt_meta_data_ISPSpaceCorrection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ISPSpaceCorrection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ISPSpaceCorrection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ISPSpaceCorrection.stringdata0))
        return static_cast<void*>(const_cast< ISPSpaceCorrection*>(this));
    return QWidget::qt_metacast(_clname);
}

int ISPSpaceCorrection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
