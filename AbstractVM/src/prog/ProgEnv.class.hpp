/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgEnv.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:07:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/08 00:01:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGENV_CLASS_HPP
#define PROGENV_CLASS_HPP

class ProgEnv {
    public:
        ProgEnv ();
        ProgEnv (ProgEnv const &);
        virtual ~ProgEnv ();

        ProgEnv &operator=(ProgEnv const &);

        /**
         * In this class, we need :
         * - ProgNameSpace
         * - FactoryMethod
         */
};

#endif // ifndef PROGENV_CLASS_HPP
