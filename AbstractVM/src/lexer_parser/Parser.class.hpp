/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:59:58 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 13:13:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_CLASS_HPP
#define PARSER_CLASS_HPP

#include <iostream>
#include <vector>
#include "IToken.class.hpp"
#include "Instruction.class.hpp"
#include "UnaryInstruction.class.hpp"

#define UNEXPECTED_VALUE   "Unexpected value, expected instruction here..."
#define EXPECTED_VALUE_EOF "Expected value, found EOF..."
#define EXPECTED_VALUE     "Expected value, found an instruction..."
#define POP_EMPTY_STACK    "Trying to pop on a empty stack..."
#define ASSERT_EMPTY_STACK "Trying to assert on a empty stack..."
#define TOO_FEW_ELEM       "Too few elements, can't apply operations..."

class Parser {
    public:
        class ParserError {
            public:
                ParserError (std::string reason,
                    size_t               index_instruction);
                ParserError (ParserError const &);
                virtual ~ParserError ();

                ParserError &operator=(ParserError const &);

                std::string getReason() const;
                size_t getIndexInstruction() const;
            private:
                std::string _reason;
                size_t _index_instruction;
        };
        Parser (std::vector<IToken *> tokens);
        Parser (Parser const &);
        virtual ~Parser ();

        Parser &operator=(Parser const &);

        bool run();

        std::vector<IToken *> getTokens() const;
        std::vector<Instruction *> getInstructions() const;
        std::vector<ParserError> getErrors() const;
    private:
        std::vector<IToken *> _tokens;
        std::vector<Instruction *> _instructions;
        std::vector<ParserError> _errors;
};

std::ostream &operator<<(std::ostream &, Parser::ParserError const &);

#endif // ifndef PARSER_CLASS_HPP
