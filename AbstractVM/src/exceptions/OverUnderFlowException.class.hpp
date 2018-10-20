/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverUnderFlowException.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:26:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 13:50:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVERUNDERFLOW_CLASS_HPP
#define OVERUNDERFLOW_CLASS_HPP

#include "SuperException.class.hpp"

#define OOR_MSG     "Out of range, this string is way too long."

#define ADD_SUS_MSG "Addition / Subtraction operation"
#define MULT_MSG    "Multiplication operation"

enum FlowExceptionNature {
    OVERFLOW,
    UNDERFLOW,
    NONE
};

enum FlowExceptionType {
    OOR,
    ADDSUS,
    MULT,
};

class OverUnderFlowException : public SuperException {
    public:
        OverUnderFlowException (FlowExceptionType, FlowExceptionNature = NONE);
        OverUnderFlowException (OverUnderFlowException const &);
        virtual ~OverUnderFlowException ();

    private:
        OverUnderFlowException();

        OverUnderFlowException &operator=(OverUnderFlowException const &);
};

#endif // ifndef OVERUNDERFLOW_CLASS_HPP
