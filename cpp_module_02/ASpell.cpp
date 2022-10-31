#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}

const std::string& ASpell::getName(void) const { return _name; }

const std::string& ASpell::getEffects(void) const { return _effects; }

void    ASpell::launch(const ATarget& target) {
    target.getHitBySpell(*this);
}
