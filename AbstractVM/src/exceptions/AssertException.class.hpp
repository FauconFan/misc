/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssertException.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:37:10 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 10:56:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERTEXCEPTION_CLASS_HPP
#define ASSERTEXCEPTION_CLASS_HPP

#include "SuperException.class.hpp"

class AssertException : public SuperException {
    public:
        AssertException (std::string const & head,
            std::string const              & cand);
        AssertException (AssertException const &);
        virtual ~AssertException ();

        AssertException &operator=(AssertException const &);
};

#endif // ifndef ASSERTEXCEPTION_CLASS_HPP
