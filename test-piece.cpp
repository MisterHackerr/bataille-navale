#include "window.h"
#include"message.h"
#include<string>

void myprogram(){
  // teste message
  message m1;
  std::string msg;
  msg=m1.instcruction();

  // fin teste
  int ch;
  int h=10,w=10;
  Window menu(3,55,25,0);
  Window plateau(h,w,1,6);

  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);


  int x=w/2,y=h/2;
  char p='X';
  Color col=WBLUE;
  plateau.print(x,y,p,col);
menu.print(1,1, msg,WRED);

  while((ch = getch()) != 'q')
    {


      switch (ch) {
      case '1':
	col=BMAGENTA;
	break;
      case '2':
	col=WCYAN;
	break;
      case 'c':
	plateau.clear();
	break;
      case KEY_UP:
	plateau.print(x,y,' ');
	plateau.print(x,--y,p,col);
	if(y<0){
	msg=m1.error_placement();
	menu.print(1,1, msg,WCYAN);
	}

	break;
      case KEY_DOWN:
	plateau.print(x,y,' ');
	plateau.print(x,++y,p,col);
	if(y>10){
	msg=m1.error_placement();
	menu.print(1,1, msg,WCYAN);
	}

	break;
      case KEY_LEFT:
	plateau.print(x,y,' ');
	plateau.print(--x,y,p,col);
	if(x<1){
	msg=m1.error_placement();
	menu.print(1,1, msg,WCYAN);
	}

	break;
      case KEY_RIGHT:
	plateau.print(x,y,' ');
	plateau.print(++x,y,p,col);
	if(y>10){
	msg=m1.error_placement();
	menu.print(1,1, msg,WCYAN);
	}
	break;
      case '\n':
	x=w/2,y=h/2;
	plateau.print(x,y,p,col);
	break;
      case '\t':
	Color tmp= menu.getCouleurBordure();
	menu.setCouleurBordure(plateau.getCouleurBordure());
	plateau.setCouleurBordure(tmp);
	break;
      }
    }

}

int main(int argc, char** argv){
  startProgramX();
  myprogram();
  stopProgramX();
  return 0;
}
