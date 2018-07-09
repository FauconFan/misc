/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 17:04:55 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 17:37:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_TEMPLATE_HPP
#define INSTRUCTION_TEMPLATE_HPP

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
    public:
        template <InstructionType T>
        Instruction ();

        template <InstructionType T>
        Instruction (std::string const &);
        
        Instruction (Instruction const &);
        virtual ~Instruction ();

        Instruction &operator=(Instruction const &);

        InstructionType getType() const;
        std::string *getStr() const;
    private:
        InstructionType _type;
        std::string *_str;
};

#endif
