/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstructionToken.class.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:55:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 17:23:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_CLASS_HPP
#define INSTRUCTION_CLASS_HPP

#include <string>
#include <map>
#include "IToken.class.hpp"
#include "Instruction.class.hpp"

class InstructionToken : public IToken {
    public:
        InstructionToken (InstructionType);
        InstructionToken (InstructionToken const &);
        virtual ~InstructionToken ();

        InstructionToken &operator=(InstructionToken const &);

        TokenType getTokenType() const noexcept;
        InstructionType getType() const;

        static const std::map<std::string, InstructionType> list_assoc;
    private:
        InstructionType _type;
};

#endif // ifndef INSTRUCTION_CLASS_HPP
