/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:24:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 14:31:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.class.hpp"
#include "InstructionToken.class.hpp"
#include "ValueToken.class.hpp"
#include "EndStackException.class.hpp"

Parser::Parser(std::vector<IToken *> tokens) : _tokens(tokens) {}

Parser::Parser(Parser const & pa) {
    *this = pa;
}

Parser::~Parser() {
    for (Instruction * in : this->_instructions) {
        delete in;
    }
}

Parser &Parser::operator=(Parser const & pa) {
    this->_tokens       = pa.getTokens();
    this->_instructions = pa.getInstructions();
    return *this;
}

std::vector<IToken *> Parser::getTokens() const {
    return this->_tokens;
}

std::vector<Instruction *> Parser::getInstructions() const {
    return this->_instructions;
}

std::vector<ParserError> Parser::getErrors() const {
    return this->_errors;
}

bool Parser::run() {
    std::vector<IToken *>::iterator it = this->_tokens.begin();
    std::vector<IToken *>::iterator et = this->_tokens.end();
    size_t nb_instruction = 0;
    size_t stack_size     = 0;

    while (it != et) {
        IToken * actu = *it;
        switch (actu->getTokenType()) {
            case VALUE: {
                this->_errors.push_back(ParserError(UNEXPECTED_VALUE, nb_instruction));
                ++it;
                ++nb_instruction;
                break;
            }
            case INSTRUCTION: {
                InstructionToken i_tok = *(dynamic_cast<InstructionToken *>(*it));

                if (i_tok.getType() == PUSH || i_tok.getType() == ASSERT) {
                    ++it;
                    if (it == et) {
                        this->_errors.push_back(ParserError(EXPECTED_VALUE_EOF, nb_instruction));
                    }
                    else {
                        IToken * value = *it;

                        switch (value->getTokenType()) {
                            case VALUE: {
                                ValueToken * v_tok = dynamic_cast<ValueToken *>(value);
                                UnaryInstruction * in     = new UnaryInstruction(
                                        i_tok.getType(), v_tok->getType(), v_tok->getStr());
                                this->_instructions.push_back(in);
                                ++it;
                                if (i_tok.getType() == PUSH) {
                                    stack_size++;
                                }
                                else if (i_tok.getType() == ASSERT && stack_size == 0) {
                                    this->_errors.push_back(ParserError(ASSERT_EMPTY_STACK,
                                            nb_instruction));
                                }
                                break;
                            }
                            case INSTRUCTION: {
                                this->_errors.push_back(ParserError(EXPECTED_VALUE,
                                        nb_instruction));
                                break;
                            }
                        }
                    }
                }
                else {
                    this->_instructions.push_back(new Instruction(i_tok.getType()));
                    if (i_tok.getType() == POP) {
                        if (stack_size == 0) {
                            this->_errors.push_back(ParserError(POP_EMPTY_STACK, nb_instruction));
                        }
                        else {
                            stack_size--;
                        }
                    }
                    else if (i_tok.getType() == ADD || i_tok.getType() == SUB ||
                      i_tok.getType() == MUL || i_tok.getType() == DIV ||
                      i_tok.getType() == MOD)
                    {
                        if (stack_size < 2) {
                            this->_errors.push_back(ParserError(TOO_FEW_ELEM, nb_instruction));
                        }
                        else {
                            stack_size--;
                        }
                    }
                    ++it;
                }
                ++nb_instruction;
            }
        }
    }

    if (this->_instructions.size() != 0) {
        for (size_t i = 0; i < this->_instructions.size() - 1; i++) {
            if (this->_instructions[i]->getType() == EXIT) {
                throw EndStackException(NO_END_STACK);
            }
        }
    }
    if (this->_instructions.size() == 0 ||
        this->_instructions.back()->getType() != EXIT) {
        throw EndStackException(END_NO_STACK);
    }

    return this->_errors.size() == 0;
} // Parser::run
