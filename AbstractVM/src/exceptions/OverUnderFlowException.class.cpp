/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverUnderFlowException.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:31:11 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/08 23:11:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OverUnderFlowException.class.hpp"

OverUnderFlowException::OverUnderFlowException (
  FlowExceptionType fet, FlowExceptionNature fen) {
    std::string msg = "";

    switch (fen) {
        case OVERFLOW:
            msg += "OverflowException : ";
            break;
        case UNDERFLOW:
            msg += "UnderflowException : ";
            break;
        default:
            break;
    }
    switch (fet) {
        case OOR:
            msg += OOR_MSG;
            break;
        case ADDSUS:
            msg += ADD_SUS_MSG;
            break;
        case MULT:
            msg += MULT_MSG;
            break;
    }
    this->setMsg(msg);
}

OverUnderFlowException::OverUnderFlowException(OverUnderFlowException const & oe) {
    *this = oe;
}

OverUnderFlowException::~OverUnderFlowException() {}

OverUnderFlowException &OverUnderFlowException::operator=(OverUnderFlowException const & oe) {
    SuperException::operator=(oe);
    return *this;
}
