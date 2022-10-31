#ifndef __ATARGET_HPP__
#define __ATARGET_HPP__

#include <string>
#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget {

    private:
        std::string _type;

        ATarget();
        ATarget(const ATarget&);
        ATarget& operator=(const ATarget&);

    public:
        ATarget(std::string type);

        const std::string& getType(void) const;

        void    getHitBySpell(const ASpell& spell) const;

        virtual ATarget* clone() const = 0;
};

#endif