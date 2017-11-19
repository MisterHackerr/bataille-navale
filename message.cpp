#include<iostream>
#include<string>
#include"message.h"
using namespace std;

// constructeur
message::message(){msg=" ";}
//Instruction en début de partie
string message::instcruction(){
msg=" Commencez par placez vos batiments dans la grille à l'aide des touches du clavier et de la touche entrée.";
return msg;
}
 //Joueurs désigné par le tirage au sort(nb=0:le joueur commence, nb= autre: l'ordinateur (ou joueur 2) commence)
  string message::tirage_au_sort(int nb){
 if(nb==0)
 msg="Vous avez gagné au tirage au sort, choisisez une case ennemie";
 else
 msg="Vous avez perdu au tirage au sort, veuilliez patienter s'ils vous plait";
 }
 //Message d'erreur lorsque 2 batiments se chevauchent ou sortent de la grille
string message::error_placement(){
 msg=" Vous ne pouvez pas placer ce batiment à cet endroit";
 }
 //Erreure du choix de la case( case déjà utilisée )
string message::error_case(){
 msg="Vous ne pouvez pas tirer sur cette case";
 }
// Résultat de la partie (nb=0:le joueur gagne la partie, nb=autre: l'ordinateur (ou joueur 2) gagne la partie)
string message::resultat(int nb){
if(nb==0)
 msg=" Félicitaion vous avez gagné la partie!! :)";
 else
 msg="La pertie est terminée, vous avez perdu :( ";
}



