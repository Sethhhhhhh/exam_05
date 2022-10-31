#ifndef __FIREBALL_HPP__
#define __FIREBALL_HPP__

#include "ASpell.hpp"

class Fireball: public ASpell {
    public:
        Fireball() : ASpell("Fireball", "burnt to a crisp") {}

        virtual Fireball* clone() const { return new Fireball(); }

};

#endif