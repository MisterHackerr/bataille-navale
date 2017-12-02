#ifndef GRILLE_H
#define GRILLE_H

#include "case.h"
#include "tableau-case.h"
#include "navire.h"

class Grille{


private:

  // On opte pour créer des grilles dynamiques pour en créer de différentes tailles
  // Par ex: Les deux grilles de jeu et la grille de la flotte en début de partie
  // Une grille est constituée d'un tableau dynamique de navires et d'un autre tableau dynamique de cases correspondant aux tirs qui n'ont pas atteint un navire
  
  int nbCases; // Le nombre de cases dans la grille au total, en comptant les cases des navires et les missiles
  Navire *tabNavires; 
  TableauCase tabCases;


public:

    Grille(int lignes, int colonnes); // constructeur
    ~Grille();  // destructeur
    
    const Case* at(int, int) const;
    Case* at(int, int);

    bool tireSurCase(int x, int y);  //tire sur la case
    
    // accesseurs en lecture
    
    const int getNbColonnes()const;  //retourne le nombre de colonnes de la grille

    const int getNbLignes()const;  //retourne le nombre de lignes de la grille
	
    bool caseValide(int x, int y);
    Cases* Random_Cases();

	
};

#endif
