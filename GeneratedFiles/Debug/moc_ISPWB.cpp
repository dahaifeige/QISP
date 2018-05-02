/****************************************************************************
** Meta object code from reading C++ file 'ISPWB.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ISPWB.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ISPWB.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ISPWB_t {
    QByteArrayData data[15];
    char stringdata0[429];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ISPWB_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ISPWB_t qt_meta_stringdata_ISPWB = {
    {
QT_MOC_LITERAL(0, 0, 5), // "ISPWB"
QT_MOC_LITERAL(1, 6, 28), // "on_AWBEnableCheckBox_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 35), // "on_AWBStaticModeRadioButton_c..."
QT_MOC_LITERAL(4, 72, 34), // "on_AWBSmartModeRadioButton_cl..."
QT_MOC_LITERAL(5, 107, 38), // "on_SampleLineNumLineEdit_retu..."
QT_MOC_LITERAL(6, 146, 34), // "on_startXPosLineEdit_returnPr..."
QT_MOC_LITERAL(7, 181, 34), // "on_startYPosLineEdit_returnPr..."
QT_MOC_LITERAL(8, 216, 30), // "on_rGainLineEdit_returnPressed"
QT_MOC_LITERAL(9, 247, 30), // "on_gGainLineEdit_returnPressed"
QT_MOC_LITERAL(10, 278, 30), // "on_bGainLineEdit_returnPressed"
QT_MOC_LITERAL(11, 309, 38), // "on_gainCalOnceEnablePushButto..."
QT_MOC_LITERAL(12, 348, 26), // "on_rReadPushButton_clicked"
QT_MOC_LITERAL(13, 375, 26), // "on_gReadPushButton_clicked"
QT_MOC_LITERAL(14, 402, 26) // "on_bReadPushButton_clicked"

    },
    "ISPWB\0on_AWBEnableCheckBox_clicked\0\0"
    "on_AWBStaticModeRadioButton_clicked\0"
    "on_AWBSmartModeRadioButton_clicked\0"
    "on_SampleLineNumLineEdit_returnPressed\0"
    "on_startXPosLineEdit_returnPressed\0"
    "on_startYPosLineEdit_returnPressed\0"
    "on_rGainLineEdit_returnPressed\0"
    "on_gGainLineEdit_returnPressed\0"
    "on_bGainLineEdit_returnPressed\0"
    "on_gainCalOnceEnablePushButton_clicked\0"
    "on_rReadPushButton_clicked\0"
    "on_gReadPushButton_clicked\0"
    "on_bReadPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ISPWB[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       3,    1,   82,    2, 0x08 /* Private */,
       4,    1,   85,    2, 0x08 /* Private */,
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
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

void ISPWB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ISPWB *_t = static_cast<ISPWB *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_AWBEnableCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_AWBStaticModeRadioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_AWBSmartModeRadioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_SampleLineNumLineEdit_returnPressed(); break;
        case 4: _t->on_startXPosLineEdit_returnPressed(); break;
        case 5: _t->on_startYPosLineEdit_returnPressed(); break;
        case 6: _t->on_rGainLineEdit_returnPressed(); break;
        case 7: _t->on_gGainLineEdit_returnPressed(); break;
        case 8: _t->on_bGainLineEdit_returnPressed(); break;
        case 9: _t->on_gainCalOnceEnablePushButton_clicked(); break;
        case 10: _t->on_rReadPushButton_clicked(); break;
        case 11: _t->on_gReadPushButton_clicked(); break;
        case 12: _t->on_bReadPushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ISPWB::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ISPWB.data,
      qt_meta_data_ISPWB,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ISPWB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ISPWB::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ISPWB.stringdata0))
        return static_cast<void*>(const_cast< ISPWB*>(this));
    return QWidget::qt_metacast(_clname);
}

int ISPWB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
