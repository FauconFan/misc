/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssertException.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 10:57:03 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/14 11:09:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssertException.class.hpp"

AssertException::AssertException(std::string const & head,
  std::string const                                & cand) {
    std::string msg = "The assert command went wrong:\n";

    msg += "Head Operand : " + head + "\n";
    msg += "Cand Operand : " + cand + "\n";
    this->setMsg(msg);
}

AssertException::AssertException(AssertException const & ae) {
    *this = ae;
}

AssertException::~AssertException() {}

AssertException &AssertException::operator=(AssertException const & ae) {
    SuperException::operator=(ae);
    return *this;
}
