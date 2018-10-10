/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:43:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/12 11:33:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <functional>

#include "Array.template.hpp"

int main() {
    std::function<void (std::string)> displayString =
      [](std::string s) {
          std::cout << s;
      };

    std::function<std::string(std::string, bool)> addCommaWN =
      [](std::string s, bool isntLast) {
          if (isntLast) {
              return s + ",";
          }
          return s;
      };

    Array<std::string> i1 = Array<std::string>(2);

    i1[0] = "Hello";
    i1[1] = " World";

    i1.iter(displayString);
    std::cout << '\n';

    i1.applyNotLast(addCommaWN);

    i1.iter(displayString);
    std::cout << '\n';
    return 0;
}
