/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnknownTypeException.class.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:45:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 13:48:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNKNOWNTYPEEXCEPTION_CLASS_HPP
#define UNKNOWNTYPEEXCEPTION_CLASS_HPP

#include "SuperException.class.hpp"

class UnknownTypeException : public SuperException {
    public:
        UnknownTypeException ();
        UnknownTypeException (UnknownTypeException const &);
        virtual ~UnknownTypeException ();

    private:
        UnknownTypeException &operator=(UnknownTypeException const &);
};

#endif // ifndef UNKNOWNTYPEEXCEPTION_CLASS_HPP
