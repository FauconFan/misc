/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:47:09 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/10 09:16:23 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TEMPLATE_HPP
#define ARRAY_TEMPLATE_HPP

#include <stdexcept>

template <typename T>
class Array {
    public:
        Array () {
            this->_data = new T[0];
            this->_len  = 0;
        }

        Array (size_t size) {
            this->_data = new T[size];
            this->_len  = size;
			for (size_t i = 0; i < size; i++) {
				this->_data[i] = T();
			}
        }

        Array (Array const & copy) {
            *this = copy;
        }

        virtual ~Array () {
            delete [] this->_data;
        }

        Array &operator=(Array const &copy) {
            this->_data = new T[copy.size()];
            this->_len  = copy.size();
            for (size_t i = 0; i < copy.size(); i++) {
                this->_data[i] = copy[i];
            }
            return *this;
        }

        size_t size() const {
            return this->_len;
        }

        T &operator[](size_t idx) {
            if (idx >= this->_len) {
                throw std::exception();
            }
            return this->_data[idx];
        }

        const T &operator[](size_t idx) const {
            if (idx >= this->_len) {
                throw std::exception();
            }
            return this->_data[idx];
        }

        void iter(void (* f)(T)) const {
            for (size_t i = 0; i < this->_len; i++) {
                f(this->_data[i]);
            }
        }

        void applyNotLast(T (* f)(T, bool)) const {
            for (size_t i = 0; i < this->_len - 1; i++) {
                this->_data[i] = f(this->_data[i], true);
            }
            if (this->_len != 0) {
                size_t lastIndex = this->_len - 1;
                this->_data[lastIndex] = f(this->_data[lastIndex], false);
            }
        }

    private:
        T * _data;
        size_t _len;
};

#endif // ifndef ARRAY_TEMPLATE_HPP
