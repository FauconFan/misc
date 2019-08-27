/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperException.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:17:14 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/06 11:24:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperException.class.hpp"

SuperException::SuperException() {}

SuperException::SuperException(std::string msg) : _msg(msg) {}

SuperException::SuperException(SuperException const & se) {
    *this = se;
}

SuperException::~SuperException() {}

SuperException &SuperException::operator=(SuperException const & se) {
    this->setMsg(se.getMsg());
    return *this;
}

void SuperException::setMsg(std::string msg) noexcept {
    this->_msg = msg;
}

std::string SuperException::getMsg() const noexcept {
    return this->_msg;
}

std::string SuperException::what() const noexcept {
    return this->getMsg();
}
