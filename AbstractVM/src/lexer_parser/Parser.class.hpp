/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:59:58 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 17:35:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_CLASS_HPP
#define PARSER_CLASS_HPP

#include <vector>
#include "IToken.class.hpp"
#include "Instruction.class.hpp"

class Parser {
    public:
        Parser (std::vector<IToken *> tokens);
        Parser (Parser const &);
        virtual ~Parser ();

        Parser &operator=(Parser const &);

        bool run();

        std::vector<IToken *> getTokens() const;
        std::vector<Instruction> getInstructions() const;
    private:
        std::vector<IToken *> _tokens;
        std::vector<Instruction> _instructions;
};

#endif
