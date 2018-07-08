/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProgEnv.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:08:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/04 17:10:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProgEnv.class.hpp"

ProgEnv::ProgEnv() {}

ProgEnv::ProgEnv(ProgEnv const & copy) {
    *this = copy;
}

ProgEnv::~ProgEnv() {}

ProgEnv &ProgEnv::operator=(ProgEnv const & pe) {
    (void) pe;
    return *this;
}
