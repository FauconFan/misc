/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:24:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 17:40:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.class.hpp"

Parser::Parser(std::vector<IToken *> tokens) : _tokens(tokens) {}

Parser::Parser(Parser const & pa) {
    *this = pa;
}

Parser::~Parser() {}

Parser &Parser::operator=(Parser const & pa) {
    this->_tokens = pa.getTokens();
    this->_instructions = pa.getInstructions();
    return *this;
}

std::vector<IToken *> Parser::getTokens() const {
    return this->_tokens;
}

std::vector<Instruction> Parser::getInstructions() const {
    return this->_instructions;
}

bool Parser::run() {
    return false;
}
