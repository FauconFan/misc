/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserError.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:09:22 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 14:10:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParserError.class.hpp"

ParserError::ParserError(std::string reason, size_t index_instruction)
    : _reason(reason), _index_instruction(index_instruction) {}

ParserError::ParserError(ParserError const & pe) {
    *this = pe;
}

ParserError::~ParserError() {}

ParserError &ParserError::operator=(ParserError const & pe) {
    this->_reason = pe.getReason();
    this->_index_instruction = pe.getIndexInstruction();
    return *this;
}

std::string ParserError::getReason() const {
    return this->_reason;
}

size_t ParserError::getIndexInstruction() const {
    return this->_index_instruction;
}

std::ostream &operator<<(std::ostream &os, ParserError const & pe) {
    os << "\t.Index Instruction : " << pe.getIndexInstruction() << "'\n"
       << "\t\t-> " << pe.getReason()
       << '\n';
    return os;
}
