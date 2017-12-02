#include "grille.h"

Grille::Grille(Navire &N1, Navire &N2,) : {
  /*  size_t k = 0;
  for(size_t i = 0; i < lignes; i++){
    for(size_t j = 0; j < colonnes; j++){
      tabCases[k].setX(i);
      tabCases[k].setY(j); */
    }

Grille::~Grille() { if(tabCases != NULL) delete[] tabCases; }

const Case* Grille::at(int i, int j) const {
  for (size_t k = 0 ; k < nbCases ; k++) {
    if ((tabCases[k].getX() == i) && (tabCases[k].getY() == j)) {
      return tabCases+k;
    }
  }
  return NULL;
}

Case* Grille::at(int i, int j)  {
  for (int k = 0 ; k < nbCases ; k++) {
    if ((tabCases[k].getX() == i) && (tabCases[k].getY() == j)) {
      return tabCases+k;
    }
  }
  return NULL;
}

// accesseur en lecture

const int Grille::getNbColonnes()const{
    return col;
}

const int Grille::getNbLignes()const{
    return lig;
}


Cases* Grille::Random_Cases(){
int i=0;
int j=0;
do{
    i=rand()% getLargeur;
    j=rand()% getHauteur;
}
while(caseValide(i,j)==false);
Cases* ptr=at(i,j);
if(ptr->getLibre==true){
ptr->setLibre(false);
}
if(ptr->getOccupee()==true){
ptr->setTouchee(true);
}
return ptr;
}




 
 bool Grille::caseValide(int x, int y){
   if((x>0 && x<= (getNbColonnes()) && (y>0 && y<=(getNbLignes()) )))
     {return true;}
     else{return false;}
     }

// accesseur en écriture
bool Grille::tireSurCase(int x, int y){
    if(caseValide(x,y)){
      Case* ptr=at(x,y);
      ptr->setTouchee(true);
        return true;
    }
    else{return false;}
    
}
