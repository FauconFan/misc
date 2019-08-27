/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InvalidEntryException.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:48:19 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 14:52:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVALIDENTRY_CLASS_HPP
#define INVALIDENTRY_CLASS_HPP

#include "SuperException.class.hpp"

#define STDIN_BAD_MSG	"The stdin is not readable"
#define FILE_BAD_MSG	"The file is not readable"

enum InvalidEntryType {
	STDIN_BAD,
	FILE_BAD,
};

class InvalidEntryException : public SuperException {
	public:
		InvalidEntryException (InvalidEntryType);
		InvalidEntryException (InvalidEntryException const &);
		virtual ~InvalidEntryException ();

	private:
		InvalidEntryException ();
		InvalidEntryException &operator=(InvalidEntryException const &);
};

#endif
