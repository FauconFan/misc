/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:35:01 by jpriou            #+#    #+#             */
/*   Updated: 2018/12/03 11:12:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "OperandFactory.class.hpp"
#include "DefaultOperand.template.hpp"
#include "OverUnderFlowException.class.hpp"
#include "UnknownTypeException.class.hpp"

OperandFactory OperandFactory::factory = OperandFactory();

OperandFactory & OperandFactory::get() {
    return OperandFactory::factory;
}

OperandFactory::OperandFactory() {
    this->_fillLinker();
}

OperandFactory::~OperandFactory() {}

void OperandFactory::_fillLinker() noexcept {
    this->_linker = std::map<eOperandType,
        IOperand const * (OperandFactory::*) (std::string const &) const>();
    this->_linker[INT8]   = &OperandFactory::createInt8;
    this->_linker[INT16]  = &OperandFactory::createInt16;
    this->_linker[INT32]  = &OperandFactory::createInt32;
    this->_linker[INT64]  = &OperandFactory::createInt64;
    this->_linker[FLOAT]  = &OperandFactory::createFloat;
    this->_linker[DOUBLE] = &OperandFactory::createDouble;
}

IOperand const * OperandFactory::createOperand(eOperandType eo, std::string const & s) const {
    IOperand const * (OperandFactory::* method) (std::string const &) const;

    method = this->_linker.at(eo);
    if (method == NULL) {
        throw UnknownTypeException();
    }
    return (this->*method)(s);
}

template <typename T>
T OperandFactory::stoT(std::string s) const {
    T res      = 0;
    T tmp      = 0;
    short sign = 1;

    if (s[0] == '0' || (s[0] == '-' && s[1] == '0'))
        return res;

    if (s[0] == '-') {
        sign = -1;
        s    = s.substr(1);
    }
    for (char c : s) {
        if (c < '0' || c > '9')
            break;
        tmp = res * 10 + (c - '0') * sign;
        if (res != 0 && (
              (sign > 0 && tmp < res) ||
              (sign < 0 && tmp > res)))
        {
            throw OverUnderFlowException(OOR);
        }
        res = tmp;
    }
    return res;
}

IOperand const * OperandFactory::createInt8(std::string const & s) const {
    int8_t value = this->stoT<int8_t>(s);

    return new DefaultOperand<int8_t>(value, INT8);
}

IOperand const * OperandFactory::createInt16(std::string const & s) const {
    int16_t value = this->stoT<int16_t>(s);

    return new DefaultOperand<int16_t>(value, INT16);
}

IOperand const * OperandFactory::createInt32(std::string const & s) const {
    int32_t value = this->stoT<int32_t>(s);

    return new DefaultOperand<int32_t>(value, INT32);
}

IOperand const * OperandFactory::createInt64(std::string const & s) const {
    int64_t value = this->stoT<int64_t>(s);

    return new DefaultOperand<int64_t>(value, INT64);
}

IOperand const * OperandFactory::createFloat(std::string const & s) const {
    float value;

    try {
        value = static_cast<float>(std::stof(s));
    }
    catch (const std::out_of_range &e) {
        throw OverUnderFlowException(OOR);
    }
    return new DefaultOperand<float>(value, FLOAT);
}

IOperand const * OperandFactory::createDouble(std::string const & s) const {
    double value;

    try {
        value = static_cast<double>(std::stod(s));
    }
    catch (const std::out_of_range &e) {
        throw OverUnderFlowException(OOR);
    }
    return new DefaultOperand<double>(value, DOUBLE);
}
