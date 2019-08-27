/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgEnv.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:07:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 16:39:18 by jpriou           ###   ########.fr       */
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
        virtual ~ProgEnv ();

        std::vector<Instruction *> getInstructions() const;

        void run();
    private:
        std::vector<Instruction *> _instructions;
        std::vector<IOperand const *> _stack_prog;
        ProgEnv ();

        ProgEnv (ProgEnv const &);
        ProgEnv &operator=(ProgEnv const &);
};

#endif // ifndef PROGENV_CLASS_HPP
