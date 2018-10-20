/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgEnv.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:08:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 16:45:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ProgEnv.class.hpp"
#include "UnaryInstruction.class.hpp"
#include "AssertException.class.hpp"
#include "UnknownTypeException.class.hpp"

ProgEnv::ProgEnv(std::vector<Instruction *> v) : _instructions(v) {}

ProgEnv::ProgEnv(ProgEnv const & copy) {
    *this = copy;
}

ProgEnv::~ProgEnv() {
    for (IOperand const * io : this->_stack_prog) {
        delete io;
    }
}

ProgEnv &ProgEnv::operator=(ProgEnv const & pe) {
    this->_instructions = pe.getInstructions();
    return *this;
}

std::vector<Instruction *> ProgEnv::getInstructions() const {
    return this->_instructions;
}

void ProgEnv::run() {
    for (Instruction * it : this->_instructions) {
        if (it->isUnary()) {
            UnaryInstruction *ui = dynamic_cast<UnaryInstruction *>(it);
            IOperand const * op = OperandFactory::get().createOperand(ui->getOperandType(), ui->getStr());

            if (ui->getType() == PUSH) {
                this->_stack_prog.push_back(op);
            }
            else if (ui->getType() == ASSERT) {
                IOperand const * head = this->_stack_prog.back();
                double diff;
                
                diff = (std::stod(op->toString()) - std::stod(head->toString()));
                diff = (diff > 0) ? diff : -diff;
                delete op;
                if (diff >= 0.000001) {
                    throw AssertException(head->toString(), op->toString());
                }
            }
            else {
                throw UnknownTypeException();
            }
        }
        else {
            switch (it->getType()) {
                case POP: {
                    delete this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    break;
                }
                case DUMP: {
                    if (this->_stack_prog.size() != 0) {
                        for (size_t i = 0; i < this->_stack_prog.size(); i++) {
                            std::cout << this->_stack_prog[this->_stack_prog.size() - 1 - i]->toString() << '\n';
                        }
                    }
                    break;
                }
                case ADD: {
                    IOperand const * snd = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * fir = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * res = *fir + *snd;
                    this->_stack_prog.push_back(res);
                    delete fir;
                    delete snd;
                    break;
                }
                case SUB: {
                    IOperand const * snd = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * fir = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * res = *fir - *snd;
                    this->_stack_prog.push_back(res);
                    delete fir;
                    delete snd;
                    break;
                }
                case MUL: {
                    IOperand const * snd = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * fir = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * res = *fir * *snd;
                    this->_stack_prog.push_back(res);
                    delete fir;
                    delete snd;
                    break;
                }
                case DIV: {
                    IOperand const * snd = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * fir = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * res = *fir / *snd;
                    this->_stack_prog.push_back(res);
                    delete fir;
                    delete snd;
                    break;
                }
                case MOD: {
                    IOperand const * snd = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * fir = this->_stack_prog.back();
                    this->_stack_prog.pop_back();
                    IOperand const * res = *fir % *snd;
                    this->_stack_prog.push_back(res);
                    delete fir;
                    delete snd;
                    break;
                }
                case PRINT: {
                    IOperand const * last = this->_stack_prog.back();
                    if (last->getType() == INT8) {
                        int8_t v = static_cast<int8_t>(std::stoi(last->toString()));
                        std::cout << v << '\n';
                    }
                    else {
                        std::cout << "Non-ascii character" << '\n';
                    }
                    break;
                }
                case EXIT: {
                    break;
                }
                default: {
                    throw UnknownTypeException();
                }
            }
        }
    }
}
