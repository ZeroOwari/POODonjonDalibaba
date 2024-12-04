#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Monstre.hpp"
class Monstre;

class Observer {
public:
    virtual ~Observer() {}
    virtual void update(Monstre* monstre) = 0;
};