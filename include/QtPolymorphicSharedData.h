/****************************************************************************
** QtPolymorphicSharedData.h
**
** Copyright (c) 2014, Korobov Sergiy.
** All rights reserved.
** Contact: Korobov Sergiy (tiamatenko@gmail.com)
**
** This file is part of the QtPolymorphicSharedData.
**
** The QtPolymorphicSharedData is free software:
** you can redistribute it and/or modify it under the terms of the
** Lesser GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** The QtPolymorphicSharedData is distributed in the hope
** that it will be useful, but WITHOUT ANY WARRANTY; without even the
** implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the Lesser GNU General Public License for more details.
**
** You should have received a copy of the Lesser GNU General Public License
** along with the QtPolymorphicSharedData.
** If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef QT_POLYMORPHIC_SHARED_DATA_H
#define QT_POLYMORPHIC_SHARED_DATA_H

#include <QtCore/QSharedData>
#include <QtCore/QVariant>
#include <QtCore/QDebug>

struct QtPolymorphicSharedDataHelper
{
    class NullType {};

    template <class T, class U>
    struct TypeList
    {
        typedef T Head;
        typedef U Tail;
    };

    template <class TList, int index> struct TypeAt;

    template <class Head, class Tail>
    struct TypeAt<TypeList<Head, Tail>, 0>
    {
        typedef Head Result;
    };

    template <class Head, class Tail, int index>
    struct TypeAt<TypeList<Head, Tail>, index>
    {
        typedef typename TypeAt<Tail, index-1>::Result Result;
    };
};

struct QtPolymorphicSharedMetaTypeIdGenerator
{
    QtPolymorphicSharedMetaTypeIdGenerator() {}
};

typedef const QtPolymorphicSharedMetaTypeIdGenerator *QtPolymorphicSharedMetaTypeId;

template <typename T>
struct QtPolymorphicSharedMetaType
{
    static const QtPolymorphicSharedMetaTypeIdGenerator metaTypeIdGenerator;

    static QtPolymorphicSharedMetaTypeId typeId() { return &metaTypeIdGenerator; }
};

template <typename T>
const QtPolymorphicSharedMetaTypeIdGenerator QtPolymorphicSharedMetaType<T>::metaTypeIdGenerator;

/**
 * @brief The QtPolymorphicSharedData class is a base class for polymorphic shared data objects.
 *        QtPolymorphicSharedData is designed to be used with QtPolymorphicSharedType to implement custom implicitly polymorphic shared or explicitly polymorphic shared classes.
 *        Inherits: QSharedData.
 */
class QtPolymorphicSharedData : public QSharedData
{
public:
    /**
     * @brief MetaTypeId
     * This is a typedef for an unique ID of every polymorphic shared data class
     */
    typedef QtPolymorphicSharedMetaTypeId MetaTypeId;
    /**
     * @brief ~QtPolymorphicSharedData
     *        Destructor
     */
    virtual ~QtPolymorphicSharedData() {}
    /**
     * @brief canCastTo Returns true if the data can be cast to the requested type ID.
     * @param metaTypeId - ID of requested type
     * @return result of possibility casting
     */
    virtual bool canCastTo(MetaTypeId metaTypeId) const { Q_UNUSED(metaTypeId) return false; }
    /**
     * @brief metaTypeId Returns type ID of data
     * @return type ID of data
     */
    virtual MetaTypeId metaTypeId() const = 0;
    /**
     * @brief metaTypeName Returns the type name associated with the instance derived from QtPolymorphicSharedType (not QtPolymorphicSharedData).
     *        The returned pointer must not be deleted.
     * @return the type name
     */
    virtual const char *metaTypeName() const = 0;
    /**
     * @brief clone Creates and returns a deep copy of the data.
     *        This function uses the operator new and calls the copy constructor of the current type.
     * @return Pointer of copy of data
     */
    virtual QtPolymorphicSharedData *clone() const = 0;

protected:
    typedef QtPolymorphicSharedDataHelper::TypeList<QtPolymorphicSharedData, QtPolymorphicSharedDataHelper::NullType> Types;
};

/**
 */
#define QT_POLYMORPHIC_COMMON_DATA(TYPE)                                                            \
protected:                                                                                          \
    typedef QtPolymorphicSharedDataHelper::TypeList<TYPE::TData, Types> Types;                      \
    virtual MetaTypeId metaTypeId() const { return QtPolymorphicSharedMetaType<TYPE>::typeId(); }   \
    virtual const char* metaTypeName() const { return #TYPE; }

#define QT_POLYMORPHIC_ABSTRACT_DATA(TYPE)                                                          \
    QT_POLYMORPHIC_COMMON_DATA(TYPE)                                                                \
    virtual bool canCastTo(MetaTypeId metaTypeId) const                                             \
    {                                                                                               \
        typedef QtPolymorphicSharedDataHelper::TypeAt<Types, 1>::Result AncestorType;               \
        return QtPolymorphicSharedMetaType<TYPE>::typeId() == metaTypeId ||                         \
               AncestorType::canCastTo(metaTypeId);                                                 \
    }

#define QT_POLYMORPHIC_ABSTRACT_DATA_IFACE1(TYPE, INTERFACE)                                        \
    QT_POLYMORPHIC_COMMON_DATA(TYPE)                                                                \
    virtual bool canCastTo(MetaTypeId metaTypeId) const                                             \
    {                                                                                               \
        typedef QtPolymorphicSharedDataHelper::TypeAt<Types, 1>::Result AncestorType;               \
        return QtPolymorphicSharedMetaType<TYPE>::typeId() == metaTypeId ||                         \
               QtPolymorphicSharedMetaType<INTERFACE>::typeId() == metaTypeId ||                    \
               AncestorType::canCastTo(metaTypeId);                                                 \
    }

#define QT_POLYMORPHIC_ABSTRACT_DATA_IFACE2(TYPE, IFACE1, IFACE2)                                   \
    QT_POLYMORPHIC_COMMON_DATA(TYPE)                                                                \
    virtual bool canCastTo(MetaTypeId metaTypeId) const                                             \
    {                                                                                               \
        typedef QtPolymorphicSharedDataHelper::TypeAt<Types, 1>::Result AncestorType;               \
        return QtPolymorphicSharedMetaType<TYPE>::typeId() == metaTypeId ||                         \
               QtPolymorphicSharedMetaType<IFACE1>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE2>::typeId() == metaTypeId ||                       \
               AncestorType::canCastTo(metaTypeId);                                                 \
    }

#define QT_POLYMORPHIC_ABSTRACT_DATA_IFACE3(TYPE, IFACE1, IFACE2, IFACE3)                           \
    QT_POLYMORPHIC_COMMON_DATA(TYPE)                                                                \
    virtual bool canCastTo(MetaTypeId metaTypeId) const                                             \
    {                                                                                               \
        typedef QtPolymorphicSharedDataHelper::TypeAt<Types, 1>::Result AncestorType;               \
        return QtPolymorphicSharedMetaType<TYPE>::typeId() == metaTypeId ||                         \
               QtPolymorphicSharedMetaType<IFACE1>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE2>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE3>::typeId() == metaTypeId ||                       \
               AncestorType::canCastTo(metaTypeId);                                                 \
    }

#define QT_POLYMORPHIC_ABSTRACT_DATA_IFACE4(TYPE, IFACE1, IFACE2, IFACE3, IFACE4)                   \
    QT_POLYMORPHIC_COMMON_DATA(TYPE)                                                                \
    virtual bool canCastTo(MetaTypeId metaTypeId) const                                             \
    {                                                                                               \
        typedef QtPolymorphicSharedDataHelper::TypeAt<Types, 1>::Result AncestorType;               \
        return QtPolymorphicSharedMetaType<TYPE>::typeId() == metaTypeId ||                         \
               QtPolymorphicSharedMetaType<IFACE1>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE2>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE3>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE4>::typeId() == metaTypeId ||                       \
               AncestorType::canCastTo(metaTypeId);                                                 \
    }

#define QT_POLYMORPHIC_ABSTRACT_DATA_IFACE5(TYPE, IFACE1, IFACE2, IFACE3, IFACE4, IFACE5)           \
    QT_POLYMORPHIC_COMMON_DATA(TYPE)                                                                \
    virtual bool canCastTo(MetaTypeId metaTypeId) const                                             \
    {                                                                                               \
        typedef QtPolymorphicSharedDataHelper::TypeAt<Types, 1>::Result AncestorType;               \
        return QtPolymorphicSharedMetaType<TYPE>::typeId() == metaTypeId ||                         \
               QtPolymorphicSharedMetaType<IFACE1>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE2>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE3>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE4>::typeId() == metaTypeId ||                       \
               QtPolymorphicSharedMetaType<IFACE5>::typeId() == metaTypeId ||                       \
               AncestorType::canCastTo(metaTypeId);                                                 \
    }

/**
 */
#define QT_POLYMORPHIC_DATA(TYPE)       \
    QT_POLYMORPHIC_ABSTRACT_DATA(TYPE)  \
    virtual QtPolymorphicSharedData *clone() const { return new TYPE::TData(*this); }

#define QT_POLYMORPHIC_DATA_IFACE1(TYPE, INTERFACE)                                                 \
    QT_POLYMORPHIC_ABSTRACT_DATA_IFACE1(TYPE, INTERFACE)                                            \
    virtual QtPolymorphicSharedData *clone() const { return new TYPE::TData(*this); }

#define QT_POLYMORPHIC_DATA_IFACE2(TYPE, IFACE1, IFACE2)                                            \
    QT_POLYMORPHIC_ABSTRACT_DATA_IFACE2(TYPE, IFACE1, IFACE2)                                       \
    virtual QtPolymorphicSharedData *clone() const { return new TYPE::TData(*this); }

#define QT_POLYMORPHIC_DATA_IFACE3(TYPE, IFACE1, IFACE2, IFACE3)                                    \
    QT_POLYMORPHIC_ABSTRACT_DATA_IFACE3(TYPE, IFACE1, IFACE2, IFACE3)                               \
    virtual QtPolymorphicSharedData *clone() const { return new TYPE::TData(*this); }

#define QT_POLYMORPHIC_DATA_IFACE4(TYPE, IFACE1, IFACE2, IFACE3, IFACE4)                            \
    QT_POLYMORPHIC_ABSTRACT_DATA_IFACE4(TYPE, IFACE1, IFACE2, IFACE3, IFACE4)                       \
    virtual QtPolymorphicSharedData *clone() const { return new TYPE::TData(*this); }

#define QT_POLYMORPHIC_DATA_IFACE5(TYPE, IFACE1, IFACE2, IFACE3, IFACE4, IFACE5)                    \
    QT_POLYMORPHIC_ABSTRACT_DATA_IFACE5(TYPE, IFACE1, IFACE2, IFACE3, IFACE4, IFACE5)               \
    virtual QtPolymorphicSharedData *clone() const { return new TYPE::TData(*this); }

/**
 *
 */
template <>
inline QtPolymorphicSharedData *QSharedDataPointer<QtPolymorphicSharedData>::clone()
{
    return d->clone();
}

/**
 *
 */
template <>
inline QtPolymorphicSharedData *QExplicitlySharedDataPointer<QtPolymorphicSharedData>::clone()
{
    return d->clone();
}

/**
 *
 */
template <template <typename> class T>
class QtPolymorphicSharedType
{
public:
    /**
     * @brief QtPolymorphicSharedType
     */
    inline QtPolymorphicSharedType() {}
    /**
     * @brief QtPolymorphicSharedType
     * @param other
     */
    inline QtPolymorphicSharedType(const QtPolymorphicSharedType &other) : d(other.d) {}
    /**
     * @brief operator =
     * @param rhs
     * @return
     */
    inline QtPolymorphicSharedType& operator=(const QtPolymorphicSharedType &rhs)
    { if (this != &rhs) d.operator=(rhs.d); return *this; }

#ifdef Q_COMPILER_RVALUE_REFS
    /**
     * @brief QtPolymorphicSharedType
     * @param other
     */
    inline QtPolymorphicSharedType(QtPolymorphicSharedType &&other) : d(std::move(other.d)) {}
    /**
     * @brief operator =
     * @param other
     * @return
     */
    inline QtPolymorphicSharedType & operator=(QtPolymorphicSharedType &&other)
    { d.swap(other.d); return *this; }
#endif
    /**
     * @brief detach
     */
    inline void detach() { d.detach(); }
    /**
     * @brief clear
     */
    inline void clear() { *this = QtPolymorphicSharedType(); }
    /**
     * @brief metaTypeId
     * @return
     */
    inline QtPolymorphicSharedMetaTypeId metaTypeId() const { return d->metaTypeId(); }
    /**
     * @brief metaTypeName
     * @return
     */
    inline const char *metaTypeName() const { return d->metaTypeName(); }
    /**
     * @brief isValid
     * @return
     */
    inline bool isValid() const { return d.constData(); }
    /**
     * @brief isNull
     * @return
     */
    inline bool isNull() const { return !d; }
    /**
     * @brief operator !
     * @return
     */
    inline bool operator!() const { return !d; }
    /**
     *
     */
    template <typename X>
    inline bool is() const
    { return isValid() && metaTypeId() == QtPolymorphicSharedMetaType<X>::typeId(); }
    /**
     *
     */
    template <typename X>
    inline bool canCastTo() const
    { return isValid() && d->canCastTo(QtPolymorphicSharedMetaType<X>::typeId()); }
    /**
     *
     */
    template <typename X>
    inline const X &castTo() const
    { return reinterpret_cast<const X &>(*this); }
    /**
     *
     */
    template <typename X>
    inline X &castTo()
    { return reinterpret_cast<X &>(*this); }
    /**
     * @brief operator QVariant
     */
    inline operator QVariant() const
    { return QVariant::fromValue(*this); }
    /**
     * @brief swap
     * @param other
     */
    inline void swap(QtPolymorphicSharedType &other)
    { d.swap(other.d); }

protected:
    typedef QtPolymorphicSharedDataHelper::TypeList<QtPolymorphicSharedType, QtPolymorphicSharedDataHelper::NullType> Types;
    /**
     * @brief QtPolymorphicSharedType
     * @param data
     */
    QtPolymorphicSharedType(QtPolymorphicSharedData *data) : d(data) {}
    /**
     *
     */
    template <typename X>
    inline const X *data() const
    { return q_check_ptr(static_cast<const X*>(d.constData())); }
    /**
     *
     */
    template <typename X>
    inline X *data()
    { return q_check_ptr(static_cast<X*>(d.data())); }

protected:
    T<QtPolymorphicSharedData> d;
};

#ifdef Q_COMPILER_RVALUE_REFS
    #define QT_POLYMORPHIC_TYPE_RVALUE_REFS(TYPE)   \
    inline TYPE(TYPE &&other) : AncestorType(std::move(other)) {}   \
    inline TYPE &operator=(TYPE &&other)   \
    { d.swap(other.d); return *this; }
#else
    #define QT_POLYMORPHIC_TYPE_RVALUE_REFS(TYPE)
#endif

#define QT_POLYMORPHIC_TYPE_COMMON(TYPE, DATA)  \
protected:                               \
    friend class DATA;                   \
    typedef class DATA TData;            \
    typedef QtPolymorphicSharedDataHelper::TypeList<TYPE, Types> Types;             \
    typedef QtPolymorphicSharedDataHelper::TypeAt<Types, 1>::Result AncestorType;   \
    inline TYPE(QtPolymorphicSharedData *data) : AncestorType(data) {}              \
public:                                         \
    QT_POLYMORPHIC_TYPE_RVALUE_REFS(TYPE)       \
    inline TYPE() {}                            \
    inline TYPE& operator=(const TYPE &rhs)     \
    { if (this != &rhs) d.operator=(rhs.d); return *this; }

/**
*/
#define QT_POLYMORPHIC_TYPE(TYPE, DATA)     \
    QT_POLYMORPHIC_TYPE_COMMON(TYPE, DATA)  \
    inline TYPE(const TYPE &other) : AncestorType(other) {}

/*
*/
#define QT_POLYMORPHIC_TYPE_IFACE1(TYPE, DATA, INTERFACE)   \
    QT_POLYMORPHIC_TYPE_COMMON(TYPE, DATA)                  \
    inline TYPE(const TYPE &other) : AncestorType(other), INTERFACE(other) {}

/*
*/
#define QT_POLYMORPHIC_TYPE_IFACE2(TYPE, DATA, IFACE1, IFACE2)  \
    QT_POLYMORPHIC_TYPE_COMMON(TYPE, DATA)                      \
    inline TYPE(const TYPE &other) : AncestorType(other), IFACE1(other), IFACE2(other) {}

/*
*/
#define QT_POLYMORPHIC_TYPE_IFACE3(TYPE, DATA, IFACE1, IFACE2, IFACE3)  \
    QT_POLYMORPHIC_TYPE_COMMON(TYPE, DATA)                              \
    inline TYPE(const TYPE &other) : AncestorType(other), IFACE1(other), IFACE2(other), IFACE3(other) {}

/*
*/
#define QT_POLYMORPHIC_TYPE_IFACE4(TYPE, DATA, IFACE1, IFACE2, IFACE3, IFACE4)  \
    QT_POLYMORPHIC_TYPE_COMMON(TYPE, DATA)                                      \
    inline TYPE(const TYPE &other) : AncestorType(other), IFACE1(other), IFACE2(other), IFACE3(other), IFACE4(other) {}

/*
*/
#define QT_POLYMORPHIC_TYPE_IFACE5(TYPE, DATA, IFACE1, IFACE2, IFACE3, IFACE4, IFACE5)  \
    QT_POLYMORPHIC_TYPE_COMMON(TYPE, DATA)                                              \
    inline TYPE(const TYPE &other) : AncestorType(other), IFACE1(other), IFACE2(other), IFACE3(other), IFACE4(other), IFACE5(other) {}

/**
 */
#define QT_GET_D const TData *const d = data<TData>();
/**
 */
#define QT_SET_D TData *const d = data<TData>();

/**
 */
#define QT_DECLARE_POLYMORPHIC_SHARED(TYPE) \
Q_DECLARE_TYPEINFO(TYPE, Q_MOVABLE_TYPE); \
template <> inline void qSwap<TYPE>(TYPE &value1, TYPE &value2) \
{ value1.swap(value2); } \
namespace std { \
    template<> inline void swap<TYPE>(TYPE &value1, TYPE &value2) \
    { value1.swap(value2); } \
}

/**
 * @brief QtPolymorphicImplicitSharedType
 */
typedef QtPolymorphicSharedType<QSharedDataPointer> QtPolymorphicImplicitSharedType;
/**
 * @brief QtPolymorphicExplicitSharedType
 */
typedef QtPolymorphicSharedType<QExplicitlySharedDataPointer> QtPolymorphicExplicitSharedType;

QT_DECLARE_POLYMORPHIC_SHARED(QtPolymorphicImplicitSharedType)
QT_DECLARE_POLYMORPHIC_SHARED(QtPolymorphicExplicitSharedType)

Q_DECLARE_METATYPE(QtPolymorphicImplicitSharedType)
Q_DECLARE_METATYPE(QtPolymorphicExplicitSharedType)

#endif // QT_POLYMORPHIC_SHARED_DATA_H
