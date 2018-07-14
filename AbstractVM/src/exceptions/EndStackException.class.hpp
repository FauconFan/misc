/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EndStackException.class.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:10:04 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 11:35:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZEROEXCEPTION_CLASS_HPP
#define ZEROEXCEPTION_CLASS_HPP

#include "SuperException.class.hpp"

#define END_NO_STACK_MSG "The last instruction must be a exit instruction"
#define NO_END_STACK_MSG "Found an exit instruction, before the last one"

enum EndStackType {
    END_NO_STACK,
    NO_END_STACK,
};

class EndStackException : public SuperException {
    public:
        EndStackException (EndStackType);
        EndStackException (EndStackException const &);
        virtual ~EndStackException ();

        EndStackException &operator=(EndStackException const &);
};


#endif // ifndef ZEROEXCEPTION_CLASS_HPP
