/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DefaultOperand.template.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13:06:47 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 14:02:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULTOPERAND_TEMPLATE_HPP
#define DEFAULTOPERAND_TEMPLATE_HPP

#include "IOperand.class.hpp"

template <typename T>
class DefaultOperand : public IOperand {
    public:
        DefaultOperand (T value, eOperandType type);
        virtual ~DefaultOperand ();


        size_t getPrecision() const;
        eOperandType getType() const;
        std::string const & toString() const;

        IOperand const * operator+(IOperand const & rhs) const;
        IOperand const * operator-(IOperand const & rhs) const;
        IOperand const * operator*(IOperand const & rhs) const;
        IOperand const * operator/(IOperand const & rhs) const;
        IOperand const * operator%(IOperand const & rhs) const;

    private:
        T _value;
        std::string _stringvalue;
        eOperandType _type;

        DefaultOperand ();
        DefaultOperand (DefaultOperand const &);
        DefaultOperand &operator=(DefaultOperand const &);
};

#include "DefaultOperand.template.tpp"

#endif // ifndef DEFAULTOPERAND_TEMPLATE_HPP
