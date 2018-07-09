/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZeroException.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:10:04 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/08 23:18:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEROEXCEPTION_CLASS_HPP
#define ZEROEXCEPTION_CLASS_HPP

#include "SuperException.class.hpp"

#define DIV_MSG "Cannot divide by zero..."
#define MOD_MSG "Cannot modulo by zero..."

enum ZeroExceptionType {
    DIV,
    MOD,
};

class ZeroException : public SuperException {
    public:
        ZeroException (ZeroExceptionType);
        ZeroException (ZeroException const &);
        virtual ~ZeroException ();

        ZeroException &operator=(ZeroException const &);
};


#endif // ifndef ZEROEXCEPTION_CLASS_HPP
