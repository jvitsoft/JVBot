/****************************************************************************
** Meta object code from reading C++ file 'JVBot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "JVBot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JVBot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_JVBot_t {
    QByteArrayData data[14];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_JVBot_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_JVBot_t qt_meta_stringdata_JVBot = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 8),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 11),
QT_MOC_LITERAL(4, 28, 12),
QT_MOC_LITERAL(5, 41, 4),
QT_MOC_LITERAL(6, 46, 7),
QT_MOC_LITERAL(7, 54, 18),
QT_MOC_LITERAL(8, 73, 18),
QT_MOC_LITERAL(9, 92, 12),
QT_MOC_LITERAL(10, 105, 21),
QT_MOC_LITERAL(11, 127, 8),
QT_MOC_LITERAL(12, 136, 8),
QT_MOC_LITERAL(13, 145, 6)
    },
    "JVBot\0onUpdate\0\0strFilePath\0onBotChanged\0"
    "tick\0predict\0JVTrainingSetData*\0"
    "pJVTrainingSetData\0processImage\0"
    "QList<JVDataDetected>\0strBotId\0JVImage*\0"
    "pImage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JVBot[] = {

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
       1,    1,   44,    2, 0x0a,
       4,    0,   47,    2, 0x0a,
       5,    0,   48,    2, 0x0a,
       6,    1,   49,    2, 0x0a,
       9,    1,   52,    2, 0x0a,
       9,    1,   55,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 7,    8,
    0x80000000 | 10, QMetaType::QString,   11,
    0x80000000 | 10, 0x80000000 | 12,   13,

       0        // eod
};

void JVBot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        JVBot *_t = static_cast<JVBot *>(_o);
        switch (_id) {
        case 0: _t->onUpdate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onBotChanged(); break;
        case 2: _t->tick(); break;
        case 3: { qint32 _r = _t->predict((*reinterpret_cast< JVTrainingSetData*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 4: { QList<JVDataDetected> _r = _t->processImage((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<JVDataDetected>*>(_a[0]) = _r; }  break;
        case 5: { QList<JVDataDetected> _r = _t->processImage((*reinterpret_cast< JVImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<JVDataDetected>*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject JVBot::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JVBot.data,
      qt_meta_data_JVBot,  qt_static_metacall, 0, 0}
};


const QMetaObject *JVBot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JVBot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JVBot.stringdata))
        return static_cast<void*>(const_cast< JVBot*>(this));
    return QObject::qt_metacast(_clname);
}

int JVBot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
