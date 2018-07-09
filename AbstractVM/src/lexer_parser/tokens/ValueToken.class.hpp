/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValueToken.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 00:02:44 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 13:47:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_CLASS_HPP
#define VALUE_CLASS_HPP

#include <map>
#include <string>
#include "IToken.class.hpp"
#include "IOperand.class.hpp"

class ValueToken : public IToken {
    public:
        ValueToken (eOperandType, std::string const & str);
        ValueToken (ValueToken const &);
        virtual ~ValueToken ();

        ValueToken &operator=(ValueToken const &);

        TokenType getTokenType() const noexcept;
        eOperandType getType() const;
        std::string getStr() const;

        static const std::map<std::string, eOperandType> list_assoc;
    private:
        eOperandType _type;
        std::string _str;
};

#endif // ifndef VALUE_CLASS_HPP
