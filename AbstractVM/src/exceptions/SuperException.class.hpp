/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperException.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 10:15:08 by jpriou            #+#    #+#             */
/*   Updated: 2018/07/06 11:24:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPEREXCEPTION_CLASS_HPP
#define SUPEREXCEPTION_CLASS_HPP

#include <string>

class SuperException {
    protected:
        SuperException ();
        SuperException (std::string msg);
        SuperException (SuperException const &);
        virtual ~SuperException ();

        SuperException &operator=(SuperException const &);

        void setMsg(std::string msg) noexcept;

        std::string getMsg() const noexcept;
    private:
        std::string _msg;

    public:
        std::string what() const noexcept;
};

#endif // ifndef SUPEREXCEPTION_CLASS_HPP
