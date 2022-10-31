#ifndef __ASPELL_HPP__
#define __ASPELL_HPP__

#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell {

    private:
        std::string _name;
        std::string _effects;

        ASpell();
        ASpell(const ASpell&);
        ASpell& operator=(const ASpell&);

    public:
        ASpell(std::string name, std::string effects);

        const std::string& getName(void) const;
        const std::string& getEffects(void) const;

        void    launch(const ATarget& target);

        virtual ASpell* clone() const = 0;

};

#endif