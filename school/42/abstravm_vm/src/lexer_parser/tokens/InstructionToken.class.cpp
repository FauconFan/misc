/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionToken.class.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:58:19 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 13:32:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstructionToken.class.hpp"

InstructionToken::InstructionToken(InstructionType it) {
    this->_type = it;
}

InstructionToken::InstructionToken(InstructionToken const & it) {
    *this = it;
}

InstructionToken::~InstructionToken() {}

InstructionToken &InstructionToken::operator=(InstructionToken const & it) {
    this->_type = it.getType();
    return *this;
}

TokenType InstructionToken::getTokenType() const noexcept {
    return INSTRUCTION;
}

InstructionType InstructionToken::getType() const {
    return this->_type;
}

std::map<std::string, InstructionType> const InstructionToken::list_assoc = {
    {"push",   PUSH  },
    {"pop",    POP   },
    {"dump",   DUMP  },
    {"assert", ASSERT},
    {"add",    ADD   },
    {"sub",    SUB   },
    {"mul",    MUL   },
    {"div",    DIV   },
    {"mod",    MOD   },
    {"print",  PRINT },
    {"exit",   EXIT  }
};
