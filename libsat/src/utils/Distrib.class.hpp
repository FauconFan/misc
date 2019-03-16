#ifndef DISTRIB_CLASS_HPP
#define DISTRIB_CLASS_HPP

#include "libsat.hpp"

class Distrib
{
    public:
        Distrib();
        virtual ~Distrib();

        const std::unordered_map<unsigned int, bool> * getDistrib() const;

        void        set(unsigned int, bool);

    private:
        std::unordered_map<unsigned int, bool> _distrib;

        Distrib(const Distrib &); // Not implemented
        Distrib &operator=(const Distrib &); // Not implemented
};

std::ostream & operator<< (std::ostream & os, const Distrib & d);

#endif