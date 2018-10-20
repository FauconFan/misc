/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:52:17 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 15:26:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <algorithm>
#include <iostream>
#include "Lexer.class.hpp"
#include "ValueToken.class.hpp"
#include "InstructionToken.class.hpp"

Lexer::Lexer(std::string const & content) : _content(content) {}

Lexer::Lexer(Lexer const & lex) {
    *this = lex;
}

Lexer::~Lexer() {
    for (IToken * tok : this->_tokens) {
        delete tok;
    }
}

Lexer &Lexer::operator=(Lexer const & lex) {
    (void) lex;
    return *this;
}

std::vector<IToken *> Lexer::getTokens() const {
    return this->_tokens;
}

std::vector<LexerError> Lexer::getErrors() const {
    return this->_list_errors;
}

bool Lexer::run() {
    this->_line   = 0;
    this->_column = 0;
    std::string::iterator it = this->_content.begin();
    std::string::iterator et = this->_content.end();

    while (it != et) {
        while (is_blank(*it)) {
            ++it;
            this->_column++;
        }
        if (it == et) {
            break;
        }
        if (is_nl(*it)) {
            this->_column = 0;
            this->_line++;
            ++it;
        }
        else {
            std::string word   = "";
            bool is_error      = false;
            std::string reason = "";

            while (is_blank(*it) == false && is_nl(*it) == false && it != et) {
                word.push_back(*it);
                ++it;
                this->_column++;
            }
            // std::cout << word << '\n';
            if (InstructionToken::list_assoc.find(word) !=
              InstructionToken::list_assoc.end())
            {
                InstructionType iType = InstructionToken::list_assoc.at(word);
                IToken * n = static_cast<IToken *>(new InstructionToken(iType));
                this->_tokens.push_back(n);
            }
            else {
                size_t poslpar = word.find('(');
                size_t posrpar = word.find(')');
                size_t nb_par  = std::count_if(word.begin(), word.end(),
                        [](char c) {
                    return c == '(' || c == ')';
                });

                if (poslpar == std::string::npos ||
                  posrpar == std::string::npos)
                {
                    is_error = true;
                    reason   = UNRECOGNISED_OPTION;
                }
                else if (nb_par != 2) {
                    is_error = true;
                    reason   = PAR_COUPLE_MISSING;
                }
                else if (poslpar > posrpar) {
                    is_error = true;
                    reason   = PAR_WRONG_ORDER;
                }
                else if (posrpar != word.size() - 1) {
                    is_error = true;
                    reason   = RPAR_LAST_CHARA;
                }
                else if (ValueToken::list_assoc.find(word.substr(0, poslpar))
                  == ValueToken::list_assoc.end())
                {
                    is_error = true;
                    reason   = TYPE_NO_MATCH;
                }
                else {
                    eOperandType eot = ValueToken::list_assoc.at(word.substr(0, poslpar));

                    std::string numeric_str = word.substr(poslpar + 1, posrpar - poslpar - 1);
                    if (eot <= INT32 && this->validateN(numeric_str) == false) {
                        is_error = true;
                        reason   = NO_INTEGER;
                    }
                    else if (eot > INT32 && this->validateZ(numeric_str) == false) {
                        is_error = true;
                        reason   = NO_FLOTTANT;
                    }

                    if (is_error == false) {
                        IToken * n = new ValueToken(eot, numeric_str);
                        this->_tokens.push_back(n);
                    }
                }
            }

            if (is_error) {
                this->_list_errors.push_back(LexerError(word, reason,
                        this->_line, this->_column - word.size()));
            }
        }
    }
    return (this->_list_errors.size() == 0);
} // Lexer::run

bool Lexer::validateN(std::string nu) const {
    std::string::iterator it = nu.begin();
    std::string::iterator et = nu.end();
    size_t number = 0;

    if (*it == '-')
        ++it;
    while (it != et) {
        if (*it < '0' || *it > '9') {
            return false;
        }
        number++;
        ++it;
    }
    return (number >= 1);
}

bool Lexer::validateZ(std::string nu) const {
    std::string::iterator it = nu.begin();
    std::string::iterator et = nu.end();
    size_t number = 0;

    if (*it == '-')
        ++it;
    while (it != et && *it != '.') {
        if (*it < '0' || *it > '9') {
            return false;
        }
        number++;
        ++it;
    }
    if (number < 1) {
        return false;
    }
    if (it == et)
        return true;

    if (*it != '.')
        return false;

    ++it;
    number = 0;
    while (it != et) {
        if (*it < '0' || *it > '9') {
            return false;
        }
        number++;
        ++it;
    }
    return (number >= 1);
} // Lexer::validateZ

bool Lexer::is_blank(char c) const noexcept {
    return (c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

bool Lexer::is_nl(char c) const noexcept {
    return (c == '\n' || c == '\r');
}
