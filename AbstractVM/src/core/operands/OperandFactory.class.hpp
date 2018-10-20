/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:24:28 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 16:37:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_STATIC_HPP
#define OPERANDFACTORY_STATIC_HPP

#include <string>
#include <map>
#include <cstdint>
#include "IOperand.class.hpp"

class OperandFactory {
    public:
        static OperandFactory & get();

        IOperand const * createOperand(eOperandType, std::string const &) const;
    private:
        static OperandFactory factory;

        OperandFactory ();
        OperandFactory (OperandFactory const &);
        virtual ~OperandFactory ();

        OperandFactory &operator=(OperandFactory const &);
        std::map<eOperandType,
          IOperand const * (OperandFactory::*) (std::string const &) const> _linker;

        void _fillLinker() noexcept;

        template <typename T>
        T stoT(std::string) const;

        IOperand const * createInt8(std::string const &) const;
        IOperand const * createInt16(std::string const &) const;
        IOperand const * createInt32(std::string const &) const;
        IOperand const * createFloat(std::string const &) const;
        IOperand const * createDouble(std::string const &) const;
};


#endif // ifndef OPERANDFACTORY_STATIC_HPP
