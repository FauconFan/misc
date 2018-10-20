/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnaryInstruction.class.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:04:15 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 14:03:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNARY_INSTRUCTION_CLASS_HPP
#define UNARY_INSTRUCTION_CLASS_HPP

#include "Instruction.class.hpp"
#include "IOperand.class.hpp"

class UnaryInstruction : public Instruction {
    public:
        UnaryInstruction (InstructionType, eOperandType, std::string const &);
        UnaryInstruction (UnaryInstruction const &);
        virtual ~UnaryInstruction ();

        eOperandType getOperandType() const;
        std::string getStr() const;
    private:
        eOperandType _type;
        std::string _str;

        UnaryInstruction ();

        UnaryInstruction &operator=(UnaryInstruction const &);
};

#endif // ifndef UNARY_INSTRUCTION_CLASS_HPP
