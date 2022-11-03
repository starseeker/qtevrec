/****************************************************************************
** Meta object code from reading C++ file 'qinputeventrecorder.h'
**
** Created: Sun Mar 6 13:49:30 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qinputeventrecorder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qinputeventrecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QInputEventRecorder[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   20,   20,   20, 0x0a,
      55,   43,   20,   20, 0x0a,
      69,   20,   20,   20, 0x0a,
      76,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QInputEventRecorder[] = {
    "QInputEventRecorder\0\0replayDone()\0"
    "record()\0speedFactor\0replay(float)\0"
    "stop()\0replay()\0"
};

const QMetaObject QInputEventRecorder::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QInputEventRecorder,
      qt_meta_data_QInputEventRecorder, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QInputEventRecorder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QInputEventRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QInputEventRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QInputEventRecorder))
        return static_cast<void*>(const_cast< QInputEventRecorder*>(this));
    return QObject::qt_metacast(_clname);
}

int QInputEventRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: replayDone(); break;
        case 1: record(); break;
        case 2: replay((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: stop(); break;
        case 4: replay(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QInputEventRecorder::replayDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
