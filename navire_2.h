#ifndef NAVIRE_H
#define NAVIRE_H

#include "cases.h"
#include "window.h"

class Navire{
 public:
  /* enum Couleur {
    NOIR,
    BLEU,
    VERT,
    ROUGE,
    JAUNE
    };*/

 private:
  Color couleurNavire;
  int nbCases;
  bool etat;
  Case *tabCases; // Un navire est un tableau de cases

 public:
  // Constructeur/Destructeur
  Navire(int, int, int, Color); // Par défaut, un navire est initialisé par un tableau dynamique de n cases occupées et non touchées.
  Navire(const Navire&); // Constructeur par copie
  Navire& operator=(const Navire&); // Par affectation
  ~Navire(); // Le destructeur désalloue le tableau dynamique des cases du navire.

  //Methode pour recuprer la case la cases i,j du navire
// const Case* at(int, int) const;
  //  Case* at(int, int);




  bool getEtat() const; // Si toutes les cases du navire sont touchées, alors le navire coule. Renvoie true si il est coulé.
  int getNbCases() const;
  Color getCouleur() const;
  int Y_min_case_navire();// on recupére l'ordonné de la first case
  int Y_max_case_navire();
  int X_min_case_navire();
  int X_max_case_navire();

  void setEtat(bool); // Permet d'affecter une valeur à l'attribut "estCoule". True = Coulé, False = Pas encore coulé
  void suprime_navire(Window& W, Color col);

  void deplacerNavireHaut(); // Méthode pour déplacer chaque case du navire
  // Servira lorsqu'il faudra placer les navires en début de partie.
  void deplacerNavireBas();
  void deplacerNavireDroite();
  void deplacerNavireGauche();
  // accesseurs en interrogation
  int nb_cases_touchees()    const;
  void couler(); // Si nb_cases_touchees == nbCases alors setEtat(True);

  // permet d'afficher toutes les cases du navire suivant leur position dans la grille.
  void afficher_navire(Window&, Color);

};

#endif
