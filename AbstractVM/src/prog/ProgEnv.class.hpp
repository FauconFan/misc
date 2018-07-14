/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgEnv.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:07:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 09:43:11 by jpriou           ###   ########.fr       */
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

        
};

#endif // ifndef PROGENV_CLASS_HPP
