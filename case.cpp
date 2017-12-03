#include "case.h"
#include <iostream>

// Constructeurs

Case::Case() :  X(0), Y(0), libre(true), occupee(false), touchee(false) { }

Case::Case(int x, int y) :  X(x), Y(y), libre(true), occupee(false), touchee(false) { }

// Accesseurs en lecture

int Case::getX() const { return X; }
int Case::getY() const { return Y; }
bool Case::getLibre() const { return libre; }
bool Case::getOccupee() const { return occupee; }
bool Case::getTouchee() const { return touchee; }

// Acesseurs en écriture
 
void Case::setY(int y) { Y = y; }
void Case::setX(int x) { X = x; }
void Case::setLibre(bool B) { libre = B; }
void Case::setOccupee(bool B) { occupee = B; }
void Case::setTouchee(bool B) { touchee = B; }

void Case::afficher_case(Window& W, Color col) {
  if (getTouchee() == true)
    W.print(X, Y, "X", col);
  else
    W.print(X, Y, " ", col);
}
void Case::suprime_case(Window& W, Color col){
W.print(X, Y," ");
}
