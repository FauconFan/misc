/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexerError.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:48:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 14:37:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXERERROR_CLASS_HPP
#define LEXERERROR_CLASS_HPP

#include <fstream>
#include <string>

#define UNRECOGNISED_OPTION "This word is not recognised..."
#define PAR_COUPLE_MISSING  "You need a couple of parenthesis..."
#define PAR_WRONG_ORDER     "The ')' needs to be after '('..."
#define RPAR_LAST_CHARA     "The ')' must be the last character..."
#define TYPE_NO_MATCH       "The type isn't recognised..."
#define NO_INTEGER          "The number given doesn't like to be a integer..."
#define NO_FLOTTANT         "The number giver doesn't like to be a flottant..."

class LexerError {
    public:
        LexerError (
            std::string word,
            std::string reason,
            size_t      line,
            size_t      column);
        virtual ~LexerError ();
        LexerError (LexerError const &);

        size_t getLine() const;
        size_t getColumn() const;
        std::string getReason() const;
        std::string getWord() const;
    private:
        size_t _line;
        size_t _column;
        std::string _reason;
        std::string _word;

        LexerError ();

        LexerError &operator=(LexerError const &);
};

std::ostream &operator<<(std::ostream &, LexerError const &);

#endif // ifndef LEXER_CLASS_HPP
