/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:04:55 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 14:05:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_TEMPLATE_HPP
#define INSTRUCTION_TEMPLATE_HPP

#include <iostream>
#include <string>

enum InstructionType {
    PUSH,
    POP,
    DUMP,
    ASSERT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    PRINT,
    EXIT
};

class Instruction {
    protected:
        Instruction (InstructionType type, bool isUnary);
        Instruction &operator=(Instruction const &);

    public:
        Instruction (InstructionType type);
        Instruction (Instruction const &);
        virtual ~Instruction ();

        InstructionType getType() const;

        virtual bool isUnary() const;
    private:
        InstructionType _type;
        bool _isUnary;

        Instruction ();
};

std::ostream &operator<<(std::ostream &, Instruction const &);

#endif // ifndef INSTRUCTION_TEMPLATE_HPP
