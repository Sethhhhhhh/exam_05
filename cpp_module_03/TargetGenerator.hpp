#ifndef __TARGET_GENERATOR_HPP__
#define __TARGET_GENERATOR_HPP__

#include <string>
#include <iostream>
#include <map>
#include <utility>

#include "ATarget.hpp"

class TargetGenerator {
    private:
        std::map<std::string, ATarget*>  _targets;

        TargetGenerator(const TargetGenerator&);
        TargetGenerator&  operator=(const TargetGenerator&);

    public:
        TargetGenerator(void) {}
        ~TargetGenerator(void) {}

        void    learnTargetType(ATarget* target) {
            if (_targets.find(target->getType()) == _targets.end())
                _targets.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
        }

        void    forgetTargetType(std::string name) {
            std::map<std::string, ATarget*>::iterator    it = _targets.find(name);

            if (it != _targets.end()) {
                delete it->second;
                _targets.erase(it);
            }
        }

        ATarget* createTarget(std::string name) {
            std::map<std::string, ATarget*>::iterator    it = _targets.find(name);
    
            if (it != _targets.end())
                return it->second;
            return NULL;
        }

};

#endif