#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


using namespace sf;

struct point
{ int x,y;};

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(400, 533), "Doodle Game!");// name windo = doodle jump  ; resolution 44**533 
    app.setFramerateLimit(60);  //  set the frame 60 

    Texture t1,t2,t3; 
    t1.loadFromFile("images/background.png");///////////////////////
    t2.loadFromFile("images/platform.png");/////////////////////////////
    t3.loadFromFile("images/doodle.png");////////////////////////

    Sprite sBackground(t1), sPlat(t2), sPers(t3);

    point plat[20];
     int j,j1 ; 
    //  posiont des plateformes 

  
    for (int i=0;i<10;i++)

     {
          //  separation de plateform paraport a y  par distance de 50  
        int temp = rand() % 515;  //  515 = 533-hauteur  de plateform=14 
        for( j = 0; j < i; j++) {
            if(abs(plat[j].y - temp) < 50  ) {
                break;
            }
        }
        if(j == i) {
            plat[i].y = temp;
            i++;}
            // separation de plateformes paraport a x par une distance de 100
int temp1 = rand() % 342;  // 342 = 400 -68
        for(int  j1 = 0; j1 < i; j1++) {
            if(abs(plat[j].x - temp1) <100 ) {         break;
            }
        }
        if(j == i) {
            plat[i].x = temp;
            i++;}
        

        

       plat[i].x=rand()%342;
       plat[i].y=rand()%515;
      }

        int x=100,y=100,h=300;
    float dx=0,dy=0;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }
   // controles 

    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;

    dy+=0.2;
    y+=dy;
 
   //  reglage de position de  plateform 
    if (y>500)  dy=-10;  //  gravitee    (perso tombe si y >500 ) 

        if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>514) {plat[i].y=0; plat[i].x=rand()%350;}
    }
  //  reglage de position de personage  

        for (int i=0;i<10;i++)
    if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
    && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))  dy=-10;

        sPers.setPosition(x,y);

    app.draw(sBackground);
    app.draw(sPers);

    for (int i=0;i<10;i++)
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    app.draw(sPlat);
    }

    app.display();
}

    return 0;
}

