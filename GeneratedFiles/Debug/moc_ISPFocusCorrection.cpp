/****************************************************************************
** Meta object code from reading C++ file 'ISPFocusCorrection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ISPFocusCorrection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ISPFocusCorrection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ISPFocusCorrection_t {
    QByteArrayData data[8];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ISPFocusCorrection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ISPFocusCorrection_t qt_meta_stringdata_ISPFocusCorrection = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ISPFocusCorrection"
QT_MOC_LITERAL(1, 19, 40), // "on_firstFocusWnPosLineEdit_re..."
QT_MOC_LITERAL(2, 60, 0), // ""
QT_MOC_LITERAL(3, 61, 37), // "on_FocusWnWidthLineEdit_retur..."
QT_MOC_LITERAL(4, 99, 42), // "on_displayFrameCountLineEdit_..."
QT_MOC_LITERAL(5, 142, 32), // "on_displayPlotPushButton_clicked"
QT_MOC_LITERAL(6, 175, 30), // "on_displayPlotCheckBox_clicked"
QT_MOC_LITERAL(7, 206, 8) // "autoPlot"

    },
    "ISPFocusCorrection\0"
    "on_firstFocusWnPosLineEdit_returnPressed\0"
    "\0on_FocusWnWidthLineEdit_returnPressed\0"
    "on_displayFrameCountLineEdit_returnPressed\0"
    "on_displayPlotPushButton_clicked\0"
    "on_displayPlotCheckBox_clicked\0autoPlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ISPFocusCorrection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void ISPFocusCorrection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ISPFocusCorrection *_t = static_cast<ISPFocusCorrection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_firstFocusWnPosLineEdit_returnPressed(); break;
        case 1: _t->on_FocusWnWidthLineEdit_returnPressed(); break;
        case 2: _t->on_displayFrameCountLineEdit_returnPressed(); break;
        case 3: _t->on_displayPlotPushButton_clicked(); break;
        case 4: _t->on_displayPlotCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->autoPlot(); break;
        default: ;
        }
    }
}

const QMetaObject ISPFocusCorrection::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ISPFocusCorrection.data,
      qt_meta_data_ISPFocusCorrection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ISPFocusCorrection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ISPFocusCorrection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ISPFocusCorrection.stringdata0))
        return static_cast<void*>(const_cast< ISPFocusCorrection*>(this));
    return QWidget::qt_metacast(_clname);
}

int ISPFocusCorrection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
