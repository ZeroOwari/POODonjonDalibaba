#pragma once

#include "Item.h"


class Consommable : public item {
public:
    Consommable(int p) : item(p) {}
};

class Equipement : public item {
public:
    Equipement(int p) : item(p) {}
};

class Armement : public item {
public:
    Armement(int p) : item(p) {}
};


