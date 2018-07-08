/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:51:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/08 22:54:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ProgEnv.class.hpp"
#include "SuperException.class.hpp"
#include "DefaultOperand.template.hpp"
#include "OperandFactory.class.hpp"

int main(void) {
    OperandFactory of;
    IOperand const * I8_1  = of.createOperand(INT8, "-128");
    IOperand const * I8_2  = of.createOperand(INT8, "127");
    IOperand const * I16_1 = of.createOperand(INT16, "-32768");
    IOperand const * I16_2 = of.createOperand(INT16, "32767");
    IOperand const * I32_1 = of.createOperand(INT32, "2147483647");
    IOperand const * I32_2 = of.createOperand(INT32, "-2147483648");
    IOperand const * F     = of.createOperand(FLOAT, "4.42");
    IOperand const * D     = of.createOperand(DOUBLE, "5.52");

    IOperand const * oui = of.createOperand(INT32, "-1024");
    IOperand const * oui2 = of.createOperand(INT32, "-1024");

    std::cout << I8_1->toString() << '\n';
    std::cout << I8_2->toString() << '\n';
    std::cout << I16_1->toString() << '\n';
    std::cout << I16_2->toString() << '\n';
    std::cout << I32_1->toString() << '\n';
    std::cout << I32_2->toString() << '\n';
    std::cout << F->toString() << '\n';
    std::cout << D->toString() << '\n';

    IOperand const * add1 = (*I8_2 + *I16_1);
    IOperand const * mult1 = (*oui * *oui2);

    std::cout << add1->toString() << '\n';
    std::cout << mult1->toString() << '\n';

    return 0;
}
