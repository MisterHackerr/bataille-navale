#ifndef MESSAGE_H
#define MESSAGE_H
#include<string>
class message{
private:
 std::string msg;
 public:
//constructeur
message();
//Instruction en début de partie
std::string instruction();
 //Joueurs désigné par le tirage au sort (nb=0:le joueur commence, nb= autre: l'ordinateur (ou joueur 2) commence)
 std::string tirage_au_sort(int nb);
 //Message d'erreur lorsque 2 batiments ce chevauchent ou sortent de la grille
 std::string error_placement();
 //Erreure du choix de la case( case déjà utilisée )
std::string error_case();
// Résultat de la partie (nb=0:le joueur gagne la partie, nb=autre: l'ordinateur (ou joueur 2) gagne la partie)
std::string resultat(int nb);
//destructeur
// ~message();
 // suprimme message
 void supprime();
std::string  get_message();
};
#endif // MESSAGE_H
