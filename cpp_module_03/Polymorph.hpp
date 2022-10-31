#ifndef __POLYMORPH_HPP__
#define __POLYMORPH_HPP__

#include "ASpell.hpp"

class Polymorph: public ASpell {
    public:
        Polymorph() : ASpell("Polymorph", "turned into a critter") {}

        virtual Polymorph* clone() const { return new Polymorph(); }

};

#endif