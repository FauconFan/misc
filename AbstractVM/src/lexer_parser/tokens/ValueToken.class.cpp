/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValueToken.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 00:06:19 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 13:49:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ValueToken.class.hpp"

ValueToken::ValueToken(eOperandType eot, std::string const & str)
    : _type(eot), _str(str) {}

ValueToken::ValueToken(ValueToken const & vt) {
    *this = vt;
}

ValueToken::~ValueToken() {}

ValueToken &ValueToken::operator=(ValueToken const & vt) {
    this->_type = vt.getType();
    this->_str  = vt.getStr();
    return *this;
}

TokenType ValueToken::getTokenType() const noexcept {
    return VALUE;
}

eOperandType ValueToken::getType() const {
    return this->_type;
}

std::string ValueToken::getStr() const {
    return this->_str;
}

const std::map<std::string, eOperandType> ValueToken::list_assoc = {
    {"int8",   INT8  },
    {"int16",  INT16 },
    {"int32",  INT32 },
    {"float",  FLOAT },
    {"double", DOUBLE}
};
