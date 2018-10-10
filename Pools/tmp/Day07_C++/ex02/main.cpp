/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:43:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/10 09:14:19 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <functional>

#include "Array.template.hpp"

void displayString(std::string str)
{
	std::cout << str;
}

std::string addCommaNL(std::string str, bool not_last)
{
	if (not_last)
		return str + ",";
	return str;
}

int main() {

    Array<std::string> i1 = Array<std::string>(2);

    i1[0] = "Hello";
    i1[1] = " World";

    i1.iter(displayString);
    std::cout << '\n';

    i1.applyNotLast(addCommaNL);

    i1.iter(displayString);
    std::cout << '\n';

	int *a = new int();
	std::cout << *a << '\n';
    return 0;
}
