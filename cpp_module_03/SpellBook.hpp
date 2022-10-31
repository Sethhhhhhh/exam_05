#ifndef __SPELLBOOK_HPP__
#define __SPELLBOOK_HPP__

#include <string>
#include <iostream>
#include <map>
#include <utility>

#include "ASpell.hpp"

class SpellBook {
    private:
        std::map<std::string, ASpell*>  _spells;

        SpellBook(const SpellBook&);
        SpellBook&  operator=(const SpellBook&);

    public:
        SpellBook(void) {}
        ~SpellBook(void) {}

        void    learnSpell(ASpell* spell) {
            if (_spells.find(spell->getName()) == _spells.end())
                _spells.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
        }

        void    forgetSpell(std::string name) {
            std::map<std::string, ASpell*>::iterator    it = _spells.find(name);

            if (it != _spells.end()) {
                delete it->second;
                _spells.erase(it);
            }
        }

        ASpell* createSpell(std::string name) {
            std::map<std::string, ASpell*>::iterator    it = _spells.find(name);
    
            if (it != _spells.end())
                return it->second;
            return NULL;
        }

};

#endif