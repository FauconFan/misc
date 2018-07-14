/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgEnv.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:07:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 13:19:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGENV_CLASS_HPP
#define PROGENV_CLASS_HPP

#include <vector>
#include "IOperand.class.hpp"
#include "OperandFactory.class.hpp"
#include "Instruction.class.hpp"

class ProgEnv {
    public:
        ProgEnv (std::vector<Instruction *>);
        ProgEnv (ProgEnv const &);
        virtual ~ProgEnv ();

        ProgEnv &operator=(ProgEnv const &);

        std::vector<Instruction *> getInstructions() const;

        void run();
    private:
        std::vector<Instruction *> _instructions;
        std::vector<IOperand const *> _stack_prog;
        OperandFactory _operandFactory;
};

#endif // ifndef PROGENV_CLASS_HPP
