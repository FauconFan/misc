/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:06:32 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 13:10:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.class.hpp"

Instruction::Instruction(InstructionType type, bool isUnary)
    : _type(type), _isUnary(isUnary) {}

Instruction::Instruction(InstructionType type)
    : _type(type), _isUnary(false) {}

Instruction::Instruction(Instruction const & is) {
    *this = is;
}

Instruction::~Instruction() {}

Instruction &Instruction::operator=(Instruction const & is) {
    this->_type = is.getType();
    this->_isUnary = is.isUnary();
    return *this;
}

InstructionType Instruction::getType() const {
    return this->_type;
}

bool Instruction::isUnary() const {
    return this->_isUnary;
}

std::ostream &operator<<(std::ostream & os, Instruction const & ist) {
    return os << "isUnary: " << ist.isUnary() << "\n"
            << "getType: " << ist.getType() << "\n";
}
