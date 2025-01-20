/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../model.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSModelENDCLASS = QtMocHelpers::stringData(
    "Model",
    "updateFrame",
    "",
    "canvas",
    "horizontalSignal",
    "verticalSignal",
    "updateCurrentFrameText",
    "newText",
    "updateTotalFrameText",
    "sendColor",
    "color",
    "updatePreviewImage",
    "image",
    "sendFrameSize",
    "size",
    "unCheckVertical",
    "unCheckHorizontal",
    "mousePressed",
    "QMouseEvent*",
    "event",
    "mouseMoved",
    "mouseReleased",
    "addFrame",
    "subFrame",
    "duplicateFrame",
    "clearFrame",
    "moveLeft",
    "moveRight",
    "editFrameSize",
    "editPenSize",
    "setColor",
    "changeErasing",
    "undo",
    "redo",
    "saveFrame",
    "loadFrame",
    "changePreviewImage",
    "startTimeout",
    "fps",
    "updatePause",
    "changeHorizontal",
    "changeVertical",
    "shift",
    "i"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  212,    2, 0x06,    1 /* Public */,
       4,    0,  215,    2, 0x06,    3 /* Public */,
       5,    0,  216,    2, 0x06,    4 /* Public */,
       6,    1,  217,    2, 0x06,    5 /* Public */,
       8,    1,  220,    2, 0x06,    7 /* Public */,
       9,    1,  223,    2, 0x06,    9 /* Public */,
      11,    1,  226,    2, 0x06,   11 /* Public */,
      13,    1,  229,    2, 0x06,   13 /* Public */,
      15,    0,  232,    2, 0x06,   15 /* Public */,
      16,    0,  233,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    1,  234,    2, 0x0a,   17 /* Public */,
      20,    1,  237,    2, 0x0a,   19 /* Public */,
      21,    1,  240,    2, 0x0a,   21 /* Public */,
      22,    0,  243,    2, 0x0a,   23 /* Public */,
      23,    0,  244,    2, 0x0a,   24 /* Public */,
      24,    0,  245,    2, 0x0a,   25 /* Public */,
      25,    0,  246,    2, 0x0a,   26 /* Public */,
      26,    0,  247,    2, 0x0a,   27 /* Public */,
      27,    0,  248,    2, 0x0a,   28 /* Public */,
      28,    1,  249,    2, 0x0a,   29 /* Public */,
      29,    1,  252,    2, 0x0a,   31 /* Public */,
      30,    0,  255,    2, 0x0a,   33 /* Public */,
      31,    0,  256,    2, 0x0a,   34 /* Public */,
      32,    0,  257,    2, 0x0a,   35 /* Public */,
      33,    0,  258,    2, 0x0a,   36 /* Public */,
      34,    0,  259,    2, 0x0a,   37 /* Public */,
      35,    0,  260,    2, 0x0a,   38 /* Public */,
      36,    0,  261,    2, 0x0a,   39 /* Public */,
      37,    1,  262,    2, 0x0a,   40 /* Public */,
      39,    0,  265,    2, 0x0a,   42 /* Public */,
      40,    0,  266,    2, 0x0a,   43 /* Public */,
      41,    0,  267,    2, 0x0a,   44 /* Public */,
      42,    1,  268,    2, 0x0a,   45 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QColor,   10,
    QMetaType::Void, QMetaType::QImage,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,

       0        // eod
};

Q_CONSTINIT const QMetaObject Model::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Model, std::true_type>,
        // method 'updateFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'horizontalSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'verticalSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateCurrentFrameText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateTotalFrameText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>,
        // method 'updatePreviewImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QImage, std::false_type>,
        // method 'sendFrameSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'unCheckVertical'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'unCheckHorizontal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mousePressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'mouseMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'mouseReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'addFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'subFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'duplicateFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveLeft'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveRight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editFrameSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'editPenSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeErasing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'undo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'redo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changePreviewImage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updatePause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeHorizontal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeVertical'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'shift'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Model *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateFrame((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->horizontalSignal(); break;
        case 2: _t->verticalSignal(); break;
        case 3: _t->updateCurrentFrameText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->updateTotalFrameText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->sendColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 6: _t->updatePreviewImage((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 7: _t->sendFrameSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->unCheckVertical(); break;
        case 9: _t->unCheckHorizontal(); break;
        case 10: _t->mousePressed((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 11: _t->mouseMoved((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 12: _t->mouseReleased((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 13: _t->addFrame(); break;
        case 14: _t->subFrame(); break;
        case 15: _t->duplicateFrame(); break;
        case 16: _t->clearFrame(); break;
        case 17: _t->moveLeft(); break;
        case 18: _t->moveRight(); break;
        case 19: _t->editFrameSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->editPenSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->setColor(); break;
        case 22: _t->changeErasing(); break;
        case 23: _t->undo(); break;
        case 24: _t->redo(); break;
        case 25: _t->saveFrame(); break;
        case 26: _t->loadFrame(); break;
        case 27: _t->changePreviewImage(); break;
        case 28: _t->startTimeout((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->updatePause(); break;
        case 30: _t->changeHorizontal(); break;
        case 31: _t->changeVertical(); break;
        case 32: _t->shift((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(QImage );
            if (_t _q_method = &Model::updateFrame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (_t _q_method = &Model::horizontalSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (_t _q_method = &Model::verticalSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Model::*)(QString );
            if (_t _q_method = &Model::updateCurrentFrameText; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Model::*)(QString );
            if (_t _q_method = &Model::updateTotalFrameText; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Model::*)(QColor );
            if (_t _q_method = &Model::sendColor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Model::*)(QImage );
            if (_t _q_method = &Model::updatePreviewImage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Model::*)(int );
            if (_t _q_method = &Model::sendFrameSize; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (_t _q_method = &Model::unCheckVertical; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Model::*)();
            if (_t _q_method = &Model::unCheckHorizontal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void Model::updateFrame(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::horizontalSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Model::verticalSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Model::updateCurrentFrameText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Model::updateTotalFrameText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Model::sendColor(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Model::updatePreviewImage(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Model::sendFrameSize(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Model::unCheckVertical()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Model::unCheckHorizontal()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
