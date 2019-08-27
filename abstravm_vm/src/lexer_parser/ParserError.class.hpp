/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserError.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:08:11 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/20 14:30:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERERROR_CLASS_HPP
#define PARSERERROR_CLASS_HPP

#include <iostream>

#define UNEXPECTED_VALUE   "Unexpected value, expected instruction here..."
#define EXPECTED_VALUE_EOF "Expected value, found EOF..."
#define EXPECTED_VALUE     "Expected value, found an instruction..."
#define POP_EMPTY_STACK    "Trying to pop on a empty stack..."
#define ASSERT_EMPTY_STACK "Trying to assert on a empty stack..."
#define TOO_FEW_ELEM       "Too few elements, can't apply operations..."

class ParserError {
	public:
		ParserError (std::string reason,
			size_t               index_instruction);
		ParserError (ParserError const &);
		virtual ~ParserError ();

		std::string getReason() const;
		size_t getIndexInstruction() const;
	private:
		std::string _reason;
		size_t _index_instruction;

		ParserError();

		ParserError &operator=(ParserError const &);
};

std::ostream &operator<<(std::ostream &, ParserError const &);

#endif
