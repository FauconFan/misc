/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InvalidEntryException.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:52:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 15:23:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InvalidEntryException.class.hpp"

InvalidEntryException::InvalidEntryException(InvalidEntryType iet) {
	std::string msg = "Invalid Entry Exception : ";

	switch (iet) {
		case STDIN_BAD:
			msg += STDIN_BAD_MSG;
			break;
		case FILE_BAD:
			msg += FILE_BAD_MSG;
			break;
	}
	this->setMsg(msg);
}

InvalidEntryException::InvalidEntryException(InvalidEntryException const & iee) {
    *this = iee;
}

InvalidEntryException::~InvalidEntryException() {}

InvalidEntryException &InvalidEntryException::operator=(InvalidEntryException const & iee) {
    SuperException::operator=(iee);
    return *this;
}
