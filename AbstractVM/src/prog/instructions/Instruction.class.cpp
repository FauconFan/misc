/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:06:32 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 17:23:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.class.hpp"

template <InstructionType IT>
Instruction::Instruction() : _type(IT), _str(NULL) {
    static_assert(IT != PUSH && IT != ASSERT, "");
}

template <InstructionType IT>
Instruction::Instruction(std::string const & st)
        : _type(IT), _str(new std::string(st)) {
    static_assert(IT == PUSH || IT == ASSERT, "");
}

Instruction::Instruction(Instruction const & is) {
    *this = is;
}

Instruction::~Instruction() {
    delete this->_str;
}

Instruction &Instruction::operator=(Instruction const & is) {
    this->_type = is.getType();
    this->_str = NULL;
    if (is.getStr() != NULL) {
        this->_str = new std::string(*(is.getStr()));
    }
    return *this;
}

InstructionType Instruction::getType() const {
    return this->_type;
}

std::string *Instruction::getStr() const {
    return this->_str;
}
