/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZeroException.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 23:11:37 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/08 23:18:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZeroException.class.hpp"

ZeroException::ZeroException(ZeroExceptionType zet) {
    std::string msg = "Zero Exception : ";

    switch (zet) {
        case DIV:
            msg += DIV_MSG;
            break;
        case MOD:
            msg += MOD_MSG;
            break;
    }
    this->setMsg(msg);
}

ZeroException::ZeroException(ZeroException const & oe) {
    *this = oe;
}

ZeroException::~ZeroException() {}

ZeroException &ZeroException::operator=(ZeroException const & oe) {
    SuperException::operator=(oe);
    return *this;
}
