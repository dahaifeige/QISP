/****************************************************************************
** Meta object code from reading C++ file 'ISPFFC2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ISPFFC2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ISPFFC2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ISPFFC2_t {
    QByteArrayData data[13];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ISPFFC2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ISPFFC2_t qt_meta_stringdata_ISPFFC2 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ISPFFC2"
QT_MOC_LITERAL(1, 8, 29), // "on_FFC2EnableCheckBox_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 32), // "on_MannerModeRadioButton_clicked"
QT_MOC_LITERAL(4, 72, 32), // "on_OneKeyModeRadioButton_clicked"
QT_MOC_LITERAL(5, 105, 35), // "on_SampleLineLineEdit_returnP..."
QT_MOC_LITERAL(6, 141, 34), // "on_StartXPosLineEdit_returnPr..."
QT_MOC_LITERAL(7, 176, 34), // "on_StartYPosLineEdit_returnPr..."
QT_MOC_LITERAL(8, 211, 28), // "on_FT2EnableCheckBox_clicked"
QT_MOC_LITERAL(9, 240, 32), // "on_VWindowLineEdit_returnPressed"
QT_MOC_LITERAL(10, 273, 31), // "on_FPN2EnablePushButton_clicked"
QT_MOC_LITERAL(11, 305, 32), // "on_PRNU2EnablePushButton_clicked"
QT_MOC_LITERAL(12, 338, 35) // "on_FFC2ParaReturnPushButton_c..."

    },
    "ISPFFC2\0on_FFC2EnableCheckBox_clicked\0"
    "\0on_MannerModeRadioButton_clicked\0"
    "on_OneKeyModeRadioButton_clicked\0"
    "on_SampleLineLineEdit_returnPressed\0"
    "on_StartXPosLineEdit_returnPressed\0"
    "on_StartYPosLineEdit_returnPressed\0"
    "on_FT2EnableCheckBox_clicked\0"
    "on_VWindowLineEdit_returnPressed\0"
    "on_FPN2EnablePushButton_clicked\0"
    "on_PRNU2EnablePushButton_clicked\0"
    "on_FFC2ParaReturnPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ISPFFC2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       3,    1,   72,    2, 0x08 /* Private */,
       4,    1,   75,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ISPFFC2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ISPFFC2 *_t = static_cast<ISPFFC2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_FFC2EnableCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_MannerModeRadioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_OneKeyModeRadioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_SampleLineLineEdit_returnPressed(); break;
        case 4: _t->on_StartXPosLineEdit_returnPressed(); break;
        case 5: _t->on_StartYPosLineEdit_returnPressed(); break;
        case 6: _t->on_FT2EnableCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_VWindowLineEdit_returnPressed(); break;
        case 8: _t->on_FPN2EnablePushButton_clicked(); break;
        case 9: _t->on_PRNU2EnablePushButton_clicked(); break;
        case 10: _t->on_FFC2ParaReturnPushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ISPFFC2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ISPFFC2.data,
      qt_meta_data_ISPFFC2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ISPFFC2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ISPFFC2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ISPFFC2.stringdata0))
        return static_cast<void*>(const_cast< ISPFFC2*>(this));
    return QWidget::qt_metacast(_clname);
}

int ISPFFC2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
