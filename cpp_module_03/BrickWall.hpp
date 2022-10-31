#ifndef __BRICKWALL_HPP__
#define __BRICKWALL_HPP__

#include "ATarget.hpp"

class BrickWall: public ATarget {
    public:
        BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

        virtual BrickWall* clone() const { return new BrickWall(); }

};

#endif