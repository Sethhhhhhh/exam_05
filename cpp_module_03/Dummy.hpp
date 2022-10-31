#ifndef __DUMMY_HPP__
#define __DUMMY_HPP__

#include "ATarget.hpp"

class Dummy: public ATarget {
    public:
        Dummy() : ATarget("Target Practice Dummy") {}

        virtual Dummy* clone() const { return new Dummy(); }

};

#endif