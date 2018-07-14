/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:06:32 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/13 15:53:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.class.hpp"

Instruction::Instruction(InstructionType type) : _type(type), _str(NULL) {
    if (type == PUSH || type == ASSERT) {
        throw std::exception();
    }
}

Instruction::Instruction(InstructionType type, std::string const & st)
    : _type(type), _str(new std::string(st)) {
    if (type != PUSH && type != ASSERT) {
        throw std::exception();
    }
}

Instruction::Instruction(Instruction const & is) {
    *this = is;
}

Instruction::~Instruction() {
    delete this->_str;
}

Instruction &Instruction::operator=(Instruction const & is) {
    this->_type = is.getType();
    this->_str  = NULL;
    if (is.getStr() != NULL) {
        this->_str = new std::string(*(is.getStr()));
    }
    return *this;
}

InstructionType Instruction::getType() const {
    return this->_type;
}

std::string * Instruction::getStr() const {
    return this->_str;
}
