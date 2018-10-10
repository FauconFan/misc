/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:21:50 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/10 09:08:11 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
void iter(T array[], size_t len, void (* f)(T)) {
    for (size_t i = 0; i < len; i++) {
        f(array[i]);
    }
}

template <typename T>
void apply(T array[], size_t len, T (* f)(T)) {
    for (size_t i = 0; i < len; i++) {
        array[i] = f(array[i]);
    }
}

template <typename T>
void display(T elem) {
    std::cout << elem << '\n';
}

int addTwo(int i) {return i + 2;}
std::string addPoint(std::string str) {return str + ".";}

int main() {
    std::string li[] = {"Hello", "World", "!"};
    int digits[]     = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // String manipulation

    iter(li, 3, display);
    std::cout << '\n';

    apply(li, 3, addPoint);

    iter(li, 3, display);
    std::cout << '\n';

    // Int manipulation

    iter(digits, 10, display);
    std::cout << '\n';

    apply(digits, 10, addTwo);

    iter(digits, 10, display);
    std::cout << '\n';

    return 0;
} // main
