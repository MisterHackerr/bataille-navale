#include "navire.h"

// où x et y sont les pos de la première case du navire
Navire::Navire(int n, int x, int y, Color c) : nbCases(n), tabCases(new Case[n]), couleurNavire(c) {
  // On attribue des valeurs à chaque case du navire, car il a été construit avec le constructeur par défaut de la classe Case :
  for(int i=0;i<nbCases;i++){
    tabCases[i].setLibre(false);
    tabCases[i].setOccupee(true);
    // Pas besoin de redéfinir "touchee", il est déjà à false par défaut
    tabCases[i].setX(x);
    tabCases[i].setY(y+i);
  }
};

Navire::Navire(const Navire& N) {
  {
    for(int i=0;i<nbCases;i++){
      tabCases[i]=N.tabCases[i];
    }
  }
}

Navire& Navire::operator=(const Navire& N) {
  if (this!=&N){
    delete[] tabCases;
    couleurNavire=N.couleurNavire;
    etat=N.etat;
    tabCases=new Case[N.nbCases];
    nbCases=N.nbCases;
    
    for(int i=0;i<nbCases;i++){
      tabCases[i]=N.tabCases[i];
    }    
  }
  return *this;
}

Navire::~Navire() { if(tabCases != NULL) delete[] tabCases; }

bool Navire::getEtat() const { return etat; }
int Navire::getNbCases() const { return nbCases; }
Color Navire::getCouleur() const { return couleurNavire; }
  
void Navire::setEtat(bool c) { etat = c; }

void Navire::suprime_navire(Window& W, Color col){
for(int i=0;i< this->nbCases;i++)
    tabCases[i].suprime_case(W,col);
}

int Navire::Y_min_case_navire(){
int minY=0;
minY= tabCases[0].getY();
for(int i=1;i< this->nbCases;i++)
if(tabCases[i].getY()<= minY){
minY=tabCases[i].getY();}

return minY;
}

int Navire::Y_max_case_navire(){
int maxY=0;
maxY= tabCases[0].getY();
for(int i=1;i< this->nbCases;i++)
if(tabCases[i].getY()>= maxY){
maxY=tabCases[i].getY();}

return maxY;
}


int Navire::X_min_case_navire(){
int minX=0;
minX= tabCases[0].getX();
for(int i=1;i< this->nbCases;i++)
if(tabCases[i].getX()<= minX){
minX=tabCases[i].getX();}

return minX;
}

int Navire::X_max_case_navire(){
int maxX=0;
maxX= tabCases[0].getY();
for(int i=1;i< this->nbCases;i++)
if(tabCases[i].getX()>= maxX){
maxX=tabCases[i].getX();}

return maxX;
}







void Navire::deplacerNavireHaut(void) {
    for(int i=0;i< this->nbCases;i++)
    tabCases[i].setY( tabCases[i].getY()-1);
}
void Navire::deplacerNavireBas(void) {
    for(int i=0;i< this->nbCases;i++)
    tabCases[i].setY( tabCases[i].getY()+1);
}
void Navire::deplacerNavireDroite(void) {
    for(int i=0;i< this->nbCases;i++)
    tabCases[i].setX( tabCases[i].getX()+1);
}

void Navire::deplacerNavireGauche(void) {
    for(int i=0;i< this->nbCases;i++)
    tabCases[i].setX( tabCases[i].getX()-1);
}

  void Navire::PivoterNavireGauche(){
  int sauv=0;
  for(int i=0;i< this->nbCases;i++){
    sauv=tabCases[i].getX();
    tabCases[i].setX( tabCases[i].getY());
    tabCases[i].setY( sauv);
    }
  }


  void Navire::PivoterNavireDroite(){
   int sauv=0;
  for(int i=0;i< this->nbCases;i++){
    sauv=tabCases[i].getX();
    tabCases[i].setX( tabCases[i].getY());
    tabCases[i].setY( sauv);
    }
  }






// accesseurs en interrogation
int Navire::nb_cases_touchees() const {int k = 0; for(int i = 0; i < nbCases; i++) { if (tabCases[i].getTouchee() == true) k ++; } return k; }

void Navire::couler() { if (nb_cases_touchees() == nbCases) setEtat(true); }

// permet d'afficher toutes les cases du navire suivant leur position dans la grille.
void Navire::afficher_navire(Window& W, Color col) {
  for(int i=0;i<nbCases;i++)
    tabCases[i].afficher_case(W, col);
}
