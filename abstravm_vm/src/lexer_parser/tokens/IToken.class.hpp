/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IToken.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 00:13:39 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/09 00:18:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOKEN_CLASS_HPP
#define ITOKEN_CLASS_HPP

enum TokenType {
    INSTRUCTION,
    VALUE,
};

class IToken {
    public:
        virtual TokenType getTokenType() const noexcept = 0;

        virtual ~IToken () {}
};

#endif // ifndef ITOKEN_CLASS_HPP
