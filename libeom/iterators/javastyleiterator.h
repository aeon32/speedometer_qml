// -*- coding:utf-8 -*-
// -*- кодировка:utf-8 -*-

#ifndef JAVASTYLEITERATOR_H
#define JAVASTYLEITERATOR_H

#include <boost/shared_ptr.hpp>
namespace eom {

/**
 * Итератор в java-стиле для коллекции из элементов Type *
 *
**/
template<class Type>
class JavaStyleIterator {
    public:
        /**
        * Умный указатель
        *
       **/
        typedef boost::shared_ptr<JavaStyleIterator> PJavaStyleIterator;

       /**
        * Возвращает указатель на текущий элемент, итератор передвигается на следующий.
        * Возвращает NULL по окончанию обхода коллекции
        *
       **/
        virtual Type * next() = 0;

};


/**
 * Производящая функция для java-style итератора, границы которого заданы std-итераторами
 *
**/
template <class iterator>
typename JavaStyleIterator<typename iterator::value>::PJavaStyleIterator createJavaIterator(const  iterator & begin, const  iterator & end) {

    struct AuxIterator : public JavaStyleIterator <typename iterator::value> {
        typedef typename iterator::value ValueType;

        iterator begin;
        iterator end;

        virtual ValueType * next() {
            ValueType * res = NULL;
            if (begin != end) {
                    res = &*begin;
                    ++begin;
            } else {

            };
            return res;

        };

        AuxIterator(const iterator & begin, const iterator & end) : begin(begin), end(end) {};

    };

    return JavaStyleIterator<typename iterator::value>::PJavaStyleIterator(new AuxIterator(begin, end));

};


/**
 * Производящая функция для java-style итератора, границы которого заданы указателями
 *
**/
template <class ValueType>
typename JavaStyleIterator<ValueType>::PJavaStyleIterator createJavaIterator(ValueType * begin, ValueType * end) {

    struct AuxIterator : public JavaStyleIterator <ValueType> {
        typedef ValueType ValueType_;

        ValueType_ * begin;
        ValueType_ * end;

        virtual ValueType * next() {
            ValueType * res = NULL;
            if (begin != end) {
                    res = begin;
                    ++begin;
            } else {

            };
            return res;

        };

        AuxIterator(ValueType * begin, ValueType * end) : begin(begin), end(end) {};

    };

    return typename JavaStyleIterator<ValueType>::PJavaStyleIterator(new AuxIterator(begin, end));

};



}; //namespace eom
#endif
