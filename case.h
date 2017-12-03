#ifndef CASE_H
#define CASE_H

#include "window.h"

class Case{

private:
        bool libre;
        bool touchee;
        bool occupee;

	int X,Y;

public:

	Case();     //Constructeur
    
	Case(int X, int Y);

	// Accesseurs en lecture

        int getX() const;
        int getY() const;
	bool getLibre() const;
	bool getOccupee() const;
	bool getTouchee() const;

	// Accesseurs en écriture

	void setY(int);
	void setX(int);
	void setLibre(bool B);
	void setOccupee(bool B);
	void setTouchee(bool B);
        void suprime_case(Window&, Color);
	void afficher_case(Window&, Color);
};

#endif
