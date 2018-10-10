/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:15:51 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/10 08:57:06 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b) {
    T c = a;

    a = b;
    b = c;
}

template <typename T>
T const &min(T const &a, T const &b) {
    if (a < b) {
        return a;
    }
    return b;
}

template <typename T>
T const &max(T const &a, T const &b) {
    if (a > b) {
        return a;
    }
    return b;
}

int     main(void) {
    int a = 2;
    int b = 3;
    std::string c = "chaine1";
    std::string d = "chaine2";
	double e = 21.21;
	double f = 42.42;

	std::cout << "Before swap" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    ::swap(a, b);
	std::cout << "After swap" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::cout << "Before swap" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
	std::cout << "After swap" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << "Before swap" << std::endl;
    std::cout << "e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
	std::cout << "After swap" << std::endl;
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
    return 0;
}
