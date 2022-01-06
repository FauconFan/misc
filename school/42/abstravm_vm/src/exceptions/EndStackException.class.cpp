/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EndStackException.class.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:11:37 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 11:37:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EndStackException.class.hpp"

EndStackException::EndStackException(EndStackType zet) {
    std::string msg = "End Stack Exception : ";

    switch (zet) {
        case NO_END_STACK:
            msg += NO_END_STACK_MSG;
            break;
        case END_NO_STACK:
            msg += END_NO_STACK_MSG;
            break;
    }
    this->setMsg(msg);
}

EndStackException::EndStackException(EndStackException const & oe) {
    *this = oe;
}

EndStackException::~EndStackException() {}

EndStackException &EndStackException::operator=(EndStackException const & oe) {
    SuperException::operator=(oe);
    return *this;
}
