#ifndef __WARLOCK_HPP__
#define __WARLOCK_HPP__

#include <string>
#include <iostream>
#include <map>
#include <utility>

#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock {

    private:
        std::string _name;
        std::string _title;
        SpellBook*  _book;

        Warlock(void);
        Warlock(const Warlock&);
        Warlock&  operator=(const Warlock&);

    public:
        Warlock(std::string name, std::string title) : _name(name), _title(title) {
            _book = new SpellBook();
            std::cout << _name << ": This looks like another boring day." << std::endl;
        }
        ~Warlock(void) {
            delete _book;
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
            _book->learnSpell(spell);
        }

        void    forgetSpell(std::string name) {
            _book->forgetSpell(name);
        }

        void    launchSpell(std::string name, const ATarget& target) {
            ASpell* sort = _book->createSpell(name);

            if (sort)
                sort->launch(target);
        }

};

#endif