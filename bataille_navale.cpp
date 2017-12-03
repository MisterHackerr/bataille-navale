#include "window.h"
#include"message.h"
#include"cases.h"
#include"navire.h"
#include<string>






void deplacement(Window &grille, Navire &porteAvions){
    int ch;

    porteAvions.afficher_navire(grille, porteAvions.getCouleur());

  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case '1':
	//col=BMAGENTA;

	break;
      case '2':
	//col=WCYAN;
	break;
      case 'c':
	grille.clear();
	break;
      case KEY_UP:
    if( porteAvions.Y_min_case_navire()>( grille.getHauteur()- grille.getHauteur())){
        porteAvions.suprime_navire(grille, porteAvions.getCouleur());
        porteAvions.deplacerNavireHaut();
        porteAvions.afficher_navire(grille, porteAvions.getCouleur());


	break;
      case KEY_DOWN:
      if( ((grille.getHauteur()-1)-  porteAvions.Y_max_case_navire()  )!=0  ) {
        porteAvions.suprime_navire(grille, porteAvions.getCouleur());
        porteAvions.deplacerNavireBas();
        porteAvions.afficher_navire(grille, porteAvions.getCouleur());
        }
	break;
      case KEY_LEFT:
    if( porteAvions.X_min_case_navire()>( grille.getLargeur()- grille.getLargeur())){
        porteAvions.suprime_navire(grille, porteAvions.getCouleur());
        porteAvions.deplacerNavireGauche();
        porteAvions.afficher_navire(grille, porteAvions.getCouleur());
	}
	break;
      case KEY_RIGHT:
      if( (grille.getHauteur() - porteAvions.X_max_case_navire())-1 !=0 ) {
	     porteAvions.suprime_navire(grille, porteAvions.getCouleur());
         porteAvions.deplacerNavireDroite();
         porteAvions.afficher_navire(grille, porteAvions.getCouleur());
	}
	break;
	/*case '\n':
	x=w/2,y=h/2;
	grille.print(x,y,p);
	break;*/
      }
    }
}
}


void batailleNavale(){


  int h=20,w=20;
  Window menu(3,30,1,0);
  Window joueur(h,w,2,6);
  Window IA(h,w,29,6);
  Window flotte(10,15,5,30);

  menu.setCouleurBordure(BRED);
  joueur.setCouleurBordure(BBLUE);
  IA.setCouleurBordure(BBLUE);
  flotte.setCouleurBordure(BBLUE);

  menu.print(1,1,"Tapez q pour quitter !!!", WRED);

  Navire porteAvions(5, 2, 2, BBLUE);
  porteAvions.afficher_navire(flotte, porteAvions.getCouleur());

  Navire croiseur(4, 4, 2, BGREEN);
  croiseur.afficher_navire(flotte, croiseur.getCouleur());

  Navire contreTorpilleur(3, 6, 2, BYELLOW);
  contreTorpilleur.afficher_navire(flotte, contreTorpilleur.getCouleur());

  Navire sousMarin(3, 8, 2, BMAGENTA);
  sousMarin.afficher_navire(flotte, sousMarin.getCouleur());

  Navire torpilleur(2, 10, 2, BRED);
  torpilleur.afficher_navire(flotte, torpilleur.getCouleur());

  // Fonction pour que le joueur se déplace dans une grille donnée en paramètre
  deplacement(joueur, porteAvions); // Au début on a besoin de se déplacer dans la flotte pour accéder aux bateaux et les transférer vers la grille du joueur

}







int main(int argc, char** argv){
  startProgramX();
  batailleNavale();
  stopProgramX();
  return 0;
}
