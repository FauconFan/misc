/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnaryInstruction.class.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:07:26 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 12:42:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UnaryInstruction.class.hpp"

UnaryInstruction::UnaryInstruction(InstructionType it, eOperandType type,
  std::string const & str) : Instruction(it, true), _type(type), _str(str) {}

UnaryInstruction::UnaryInstruction(UnaryInstruction const & ui)
    : Instruction(ui) {}

UnaryInstruction::~UnaryInstruction() {}

UnaryInstruction &UnaryInstruction::operator=(UnaryInstruction const & ui) {
    Instruction::operator=(ui);
    this->_type = ui.getOperandType();
    this->_str  = ui.getStr();
    return *this;
}

eOperandType UnaryInstruction::getOperandType() const {
    return this->_type;
}

std::string UnaryInstruction::getStr() const {
    return this->_str;
}
