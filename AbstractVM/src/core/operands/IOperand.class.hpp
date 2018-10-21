/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:17:40 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 10:12:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_CLASS_HPP
#define IOPERAND_CLASS_HPP

#include <string>

enum eOperandType {
    // Default Namespace
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
};

class IOperand {
    public:
        virtual size_t getPrecision() const  = 0;
        virtual eOperandType getType() const = 0;

        virtual IOperand const * operator+(IOperand const & rhs) const = 0;
        virtual IOperand const * operator-(IOperand const & rhs) const = 0;
        virtual IOperand const * operator*(IOperand const & rhs) const = 0;
        virtual IOperand const * operator/(IOperand const & rhs) const = 0;
        virtual IOperand const * operator%(IOperand const & rhs) const = 0;

        virtual std::string const & toString() const = 0;

        virtual ~IOperand () {};
};

#endif // ifndef IOPERAND_CLASS_HPP
