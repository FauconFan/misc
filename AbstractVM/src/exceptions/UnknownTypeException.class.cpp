/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnknownTypeException.class.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 09:45:34 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 09:53:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "UnknownTypeException.class.hpp"

UnknownTypeException::UnknownTypeException() {
    std::string msg = "UnknownTypeException...";

    this->setMsg(msg);
}

UnknownTypeException::UnknownTypeException(UnknownTypeException const & ute) {
    *this = ute;
}

UnknownTypeException::~UnknownTypeException() {}

UnknownTypeException &UnknownTypeException::operator=(UnknownTypeException const & ute) {
    SuperException::operator=(ute);
    return *this;
}
