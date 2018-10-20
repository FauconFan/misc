/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerError.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:33:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 14:34:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LexerError.class.hpp"

LexerError::LexerError(std::string word, std::string reason,
  size_t line, size_t column) :
    _line(line), _column(column), _reason(reason), _word(word) {}

LexerError::LexerError(LexerError const & le) {
    *this = le;
}

LexerError::~LexerError() {}

LexerError &LexerError::operator=(LexerError const & le) {
    this->_line   = le._line;
    this->_column = le._column;
    this->_reason = le._reason;
    this->_word   = le._word;
    return *this;
}

size_t LexerError::getLine() const {
    return this->_line;
}

size_t LexerError::getColumn() const {
    return this->_column;
}

std::string LexerError::getReason() const {
    return this->_reason;
}

std::string LexerError::getWord() const {
    return this->_word;
}

std::ostream &operator<<(std::ostream & os, LexerError const & le) {
    os << "\t.(" << le.getLine() << ", " << le.getColumn() << ")"
       << " in word '" << le.getWord() << "'\n"
       << "\t\t-> " << le.getReason()
       << '\n';
    return os;
}
