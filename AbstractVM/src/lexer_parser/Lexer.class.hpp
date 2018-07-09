/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:48:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 16:45:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_CLASS_HPP
#define LEXER_CLASS_HPP

#include <iostream>
#include <string>
#include <vector>
#include "IToken.class.hpp"

#define PAR_COUPLE_MISSING "You need a couple of parenthesis..."
#define PAR_WRONG_ORDER "The ')' needs to be after '('..."
#define RPAR_LAST_CHARA "The ')' must be the last character..."
#define TYPE_NO_MATCH "The type isn't recognised..."
#define NO_INTEGER "The number given doesn't like to be a integer..."
#define NO_FLOTTANT "The number giver doesn't like to be a flottant..."

class Lexer {
    public:
        class LexerError {
            public:
                LexerError (
                        std::string word,
                        std::string reason,
                        size_t line,
                        size_t column);
                LexerError (LexerError const &);
                virtual ~LexerError ();

                LexerError &operator=(LexerError const &);

                size_t getLine() const;
                size_t getColumn() const;
                std::string getReason() const;
                std::string getWord() const;
            private:
                size_t _line;
                size_t _column;
                std::string _reason;
                std::string _word;
        };

        Lexer (std::string const & content);
        Lexer (Lexer const &);
        virtual ~Lexer ();

        Lexer &operator=(Lexer const &);

        std::vector<IToken *> getTokens() const;
        std::vector<LexerError> getErrors() const;

        bool run();

        bool validateN(std::string nu) const;
        bool validateZ(std::string nu) const;
    private:
        std::vector<LexerError> _list_errors;
        std::vector<IToken *> _tokens;
        std::string _content;
        size_t _line;
        size_t _column;

        bool is_blank(char c) const noexcept;
        bool is_nl(char c) const noexcept;
};

std::ostream &operator<<(std::ostream &, Lexer::LexerError const &);

#endif // ifndef LEXER_CLASS_HPP
