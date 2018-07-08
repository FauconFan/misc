/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DefaultOperand.template.tpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13:12:09 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/08 23:27:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEFAULTOPERAND_TEMPLATE_HPP

#include <limits>
#include "OverUnderFlowException.class.hpp"
#include "ZeroException.class.hpp"
#include "OperandFactory.class.hpp"

#define ABS(x) (((x) > 0) ? (x) : (-x))
#define PREC_DIV_ZERO 0.0000001

template <typename T>
DefaultOperand<T>::DefaultOperand(T value, eOperandType type)
        : _value(value), _type(type) {
    this->_stringvalue = std::to_string(value);
}

template <typename T>
DefaultOperand<T>::DefaultOperand(DefaultOperand const & dp) {
    *this = dp;
}

template <typename T>
DefaultOperand<T>::~DefaultOperand() {}

template <typename T>
DefaultOperand<T> &DefaultOperand<T>::operator=(DefaultOperand<T> const &dp) {
    this->_value       = dp._value;
    this->_stringvalue = dp.toString();
    this->_type        = dp.getType();
    return *this;
}

template <typename T>
size_t DefaultOperand<T>::getPrecision() const {
    return static_cast<size_t>(this->_type);
}

template <typename T>
eOperandType DefaultOperand<T>::getType() const {
    return this->_type;
}

template <typename T>
std::string const & DefaultOperand<T>::toString() const {
    return this->_stringvalue;
}

template <typename T>
IOperand const * DefaultOperand<T>::operator+(IOperand const & rhs) const {
    if (this->getPrecision() < rhs.getPrecision()) {
        return rhs + *this;
    }
    T a = this->_value;
    T b = static_cast<T>(std::stod(rhs.toString()));
    T res = a + b;

    if ((a > 0) && (b > 0)) {
        if (res < b) {
            throw OverUnderFlowException(ADDSUS, OVERFLOW);
        }
    }
    else if ((a < 0) && (b < 0)) {
        if (a < 0 && res > b) {
            throw OverUnderFlowException(ADDSUS, OVERFLOW);
        }
        else if (res < b) {
            throw OverUnderFlowException(ADDSUS, UNDERFLOW);
        }
    }
    return OperandFactory().createOperand(this->getType(),
            std::to_string(res));
}

template <typename T>
IOperand const * DefaultOperand<T>::operator-(IOperand const & rhs) const {
    (void)rhs;
    return NULL;
}

template <typename T>
IOperand const * DefaultOperand<T>::operator*(IOperand const & rhs) const {
    if (this->getPrecision() < rhs.getPrecision()) {
        return rhs * *this;
    }
    T a = this->_value;
    T b = static_cast<T>(std::stod(rhs.toString()));

    if (ABS(a) > std::numeric_limits<T>::max() / ABS(b)) {
        if ((a < 0) && (b < 0)) {
            throw OverUnderFlowException(MULT, OVERFLOW);
        }
		else if ((a > 0) && (b > 0)) {
            throw OverUnderFlowException(MULT, OVERFLOW);
        }
		else {
            throw OverUnderFlowException(MULT, UNDERFLOW);
        }
    }
    return OperandFactory().createOperand(this->getType(),
            std::to_string(a * b));
}

template <typename T>
IOperand const * DefaultOperand<T>::operator/(IOperand const & rhs) const {
    double value_rhs = std::stold(rhs.toString());

    if (value_rhs > - PREC_DIV_ZERO && value_rhs < PREC_DIV_ZERO) {
        throw ZeroException(DIV);
    }
    return OperandFactory().createOperand(
        (this->getType() > rhs.getType()) ? this->getType() : rhs.getType(),
        std::to_string(this->_value / value_rhs));
}

template <typename T>
IOperand const * DefaultOperand<T>::operator%(IOperand const & rhs) const {
    double value_rhs = std::stold(rhs.toString());
    double res;

    value_rhs = ABS(value_rhs);
    if (value_rhs < PREC_DIV_ZERO) {
        throw ZeroException(MOD);
    }
    if (this->_value > 0) {
        res = this->_value;
        while (res >= value_rhs) {
            res -= value_rhs;
        }
    }
    else {
        res = this->_value;
        while (-res >= value_rhs) {
            res += value_rhs;
        }
    }
    return OperandFactory().createOperand(
        (this->getType() > rhs.getType()) ? this->getType() : rhs.getType(),
        std::to_string(res));
}

#endif // ifdef DEFAULTOPERAND_TEMPLATE_HPP
