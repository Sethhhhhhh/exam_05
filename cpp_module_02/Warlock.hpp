#ifndef __WARLOCK_HPP__
#define __WARLOCK_HPP__

#include <string>
#include <iostream>
#include <map>
#include <utility>

#include "ASpell.hpp"

class Warlock {

    private:
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell*>  _spells;

        Warlock(void);
        Warlock(const Warlock&);
        Warlock&  operator=(const Warlock&);

    public:
        Warlock(std::string name, std::string title) : _name(name), _title(title) {
            std::cout << _name << ": This looks like another boring day." << std::endl;
        }
        ~Warlock(void) {
            std::cout << _name << ": My job here is done!" << std::endl;
        }

        /* Set */
        void    setTitle(std::string title) { _title = title; }

        /* Get */
        std::string getName(void) const { return _name; }
        std::string getTitle(void) const { return _title; }

        void    introduce(void) const {
            std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
        }

        void    learnSpell(ASpell* spell) {
            if (_spells.find(spell->getName()) != _spells.end())
                return ;
            _spells.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
        }

        void    forgetSpell(std::string name) {
            if (_spells[name])
                _spells.erase(name);
        }

        void    launchSpell(std::string name, const ATarget& target) {
            ASpell* tmp = _spells[name];

            if (tmp)
                tmp->launch(target);
        }

};

#endif