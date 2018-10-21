/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:48:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 15:58:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_CLASS_HPP
#define LEXER_CLASS_HPP

#include <string>
#include <vector>
#include "IToken.class.hpp"
#include "LexerError.class.hpp"

#define COMMENT_CHAR ';'

class Lexer {
    public:
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

        Lexer();

        bool is_blank(char c) const noexcept;
        bool is_nl(char c) const noexcept;
};

#endif // ifndef LEXER_CLASS_HPP
