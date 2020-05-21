#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include<GL/glut.h>
#include<math.h>

#include"mcauds.h"
#include"mcau.h"
#include"lvau.h"

#include"lvauth.h"
#define cn 416

time_t t, begin, end;
char cards[cn];
short choice =0;
short bet=0;
void init();
//sends cards to the  choice header file
void showprob(char card[cn]);//shows probability from same header file
char win(short a,short b,short c,short d);//Calculates the winner in a round
short randCards();
void game();
//short value(short a);
int flag=0;
time_t t;
#define cn 416

int f=0;

  void BitmapText(char *string, float x, float y)
{
char c;
int j;
glColor3f(1.0,0.40,0.3);
glRasterPos2f(x,y);
for(j=0;string[j]!='\0'; j++)
{
c=string[j];
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
}
}
void mapText(char *string, float x, float y)
{
char c;
int j;
glColor3f(0,0,0);
glRasterPos2f(x,y);
for(j=0;string[j]!='\0'; j++)
{
c=string[j];
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
}
}
void Text(char *string, float x, float y)
{
char c;
int j;
glColor3f(1.0,1.0,1.0);
glRasterPos2f(x,y);
for(j=0;string[j]!='\0'; j++)
{
c=string[j];
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
}
}


 void betGUI()
 {

  Text("Place Bet on:",200,260);
  BitmapText("Cards:",160,170);
  Text("Result:",100,40);
  glBegin(GL_QUADS);

glColor3f(1.0,1.0,1.0);
if(f==1)
  {

  glColor3f(0.3,0.0,0.4);
  }
glVertex2i(50,220);
glVertex2i(175,220);
glVertex2i(175,250);
glVertex2i(50,250);
glEnd();
glFlush();
mapText("Banker",80,235);

glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
if(f==2)
  {

  glColor3f(0.3,0.0,0.4);
  }
glVertex2i(200,220);
glVertex2i(325,220);
glVertex2i(325,250);
glVertex2i(200,250);
glEnd();
mapText("Player",230,235);
glBegin(GL_QUADS);
 glColor3f(1.0,1.0,1.0);
  if(f==3)
  {

  glColor3f(0.3,0.0,0.4);
  }
glVertex2i(340,220);
glVertex2i(465,220);
glVertex2i(465,250);
glVertex2i(340,250);
glEnd();
mapText("Tie",380,235);
glFlush();
 }
void render()
{


if(flag==1)
{

glBegin(GL_QUADS);
glColor3f(0.6,0.0,0.0);
glVertex2i(50,320);
glVertex2i(175,320);
glVertex2i(175,400);
glVertex2i(50,400);
glEnd();
glColor3f(1.0,1.0,1.0);
mapText("1.Las Vegas",53,360);

betGUI();
}
if(flag==2)
{
glBegin(GL_QUADS);
glColor3f(0.6,0.0,0.0);
glVertex2i(200,320);
glVertex2i(325,320);
glVertex2i(325,400);
glVertex2i(200,400);
glEnd();
glFlush();
glColor3f(1.0,1.0,1.0);
mapText("2.Las Vegas",208,360);
mapText("with Threading",201,345);
betGUI();
}
if(flag==3)
{
glBegin(GL_QUADS);
glColor3f(0.6,0.0,0.0);
glVertex2i(340,320);
glVertex2i(465,320);
glVertex2i(465,400);
glVertex2i(340,400);
glEnd();
glFlush();
glColor3f(1.0,1.0,1.0);
mapText("3.Monte",360,360);
mapText("Carlo",370,345);
betGUI();
}
if(flag==4)
{
      glBegin(GL_QUADS);
glColor3f(0.6,0.0,0.0);
glVertex2i(480,320);
glVertex2i(610,320);
glVertex2i(610,400);
glVertex2i(480,400);
glEnd();
glFlush();
glColor3f(1.0,1.0,1.0);

mapText("4.Monte Carlo",490,360);
mapText("with DS",510,345);
glFlush();
betGUI();
}
glColor3f(0.0,1.0,0.0);
BitmapText("Welcome!", 300,440);

Text("Select the Algorithm:",200,420);
glFlush();



}

void displayCard(){

  short r;
  srand((unsigned)time(&t)); //+turns);
  for(int i=0; i<4; ++i){
    r=rand()%cn;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(50, 70);
    glVertex2i(150, 70);
    glVertex2i(150, 150);
    glVertex2i(50, 150);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 70);
    glVertex2i(300, 70);
    glVertex2i(300, 150);
    glVertex2i(200, 150);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(350, 70);
    glVertex2i(450, 70);
    glVertex2i(450, 150);
    glVertex2i(350, 150);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(500, 70);
    glVertex2i(600, 70);
    glVertex2i(600, 150);
    glVertex2i(500, 150);
    glEnd();

  }
}



void Display()
{

    glClearColor(0, 0, 0, 0);
    glColor3f(0.0, 0.4, 0.8);
    glClear(GL_COLOR_BUFFER_BIT);


    glFlush();
 glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex2i(50,320);
glVertex2i(175,320);
glVertex2i(175,400);
glVertex2i(50,400);
glEnd();
glFlush();
mapText("1.Las Vegas",53,360);
 glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex2i(200,320);
glVertex2i(325,320);
glVertex2i(325,400);
glVertex2i(200,400);
//gcvt(n2,3,ch);
glEnd();
glFlush();
mapText("2.Las Vegas",208,360);

mapText("with Threading",201,345);
glFlush();
 glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex2i(340,320);
glVertex2i(465,320);
glVertex2i(465,400);
glVertex2i(340,400);
glEnd();
glFlush();

mapText("3.Monte",360,360);
mapText("Carlo",370,345);
       glBegin(GL_QUADS);
glColor3f(1.0,1.0,1.0);
glVertex2i(480,320);
glVertex2i(610,320);
glVertex2i(610,400);
glVertex2i(480,400);
glEnd();
glFlush();


mapText("4.Monte Carlo",490,360);
mapText("with DS",510,345);
glFlush();


    render();
}



    void myin()
    {
    gluOrtho2D(0,640,0,480);
    }

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

          if(x>50&&x<175&&y<320)
          {
      printf("Lvau");
      if(flag==0)
     {
flag=1;
choice=3;

    render();
// game();
}

          //call lavau
 }
 if(x>250&&x<395&&y<320)
          {
          if(flag==0)

{

          flag=2;
choice=4;

          render();
// game();
      }
      printf("2");
          //call lavauth
 }
 if(x>420&&x<590&&y<320)
          {
        if(flag==0)
        {

          flag=3;
choice=1;

          render();


// game();
          }

          //call monte carlo
 }
 if(x>600&&x<720&&y<320)
          {
          if(flag==0)
          {

          flag=4;
choice=2;

          render();
// game();
          }

          //call monte carlo ds
 }
 if(x>50&&x<190&&y>320)
 {
 f=1;
 displayCard();
 betGUI();

bet=2;
game();
 //place bet on banker

 }
   if(x>200&&x<360&&y>320)
 {
 f=2;
bet=1;
displayCard();
betGUI();

game();
// betGUI();

//bet=1;
// game();
 //player
 }
   if(x>400&&x<545&&y>320)
 {
 f=3;
bet=3;
      displayCard();
 betGUI();
// bet=3;
game();
 //tie
 }
    }


    }

void init()
{
for (int i =0;i<cn;i++)
{
cards[i]='t';
}
printf("\nWelcome to our casino where we show you your winning probability beforehand!!!\n");
}
/*void showProb(char card[cn])
{

}*/
short value(short a)
{
a=a%13;
                if(a<10)
{
return a;}
else
{return 0;}
}

short randCards(){


  short r;
  do{
  r=rand()%cn;


  }while(cards[r]=='f');
   cards[r]='f';
    return r;
}
void game()
{
char w='n';
//for(int turns =1; turns<=40;turns++){
// srand((unsigned)time(&t)+turns);

// while(choice!=1&&choice!=2&&choice!=3&&choice!=4){
// //printf("n//Enter your choice of algorithm to calculate probability\n1.Monte Carlo\n2.Monte Carlo with Forest\n3.Las Vegas\n4.Las Vegas with threading\n");
// //fflush(stdin);
// //scanf("%hu",&choice);
// }

//showProb(cards);
switch (choice)
{case 1: begin= time(NULL);
                  mcaushowProb(cards);
end= time(NULL);
printf("Time elapsed is %f seconds\n", (double)(end-begin));
break;
case 2: begin= time(NULL);
mcaudsshowProb(cards);
end= time(NULL);
printf("Time elapsed is %f seconds\n", (double)(end-begin));

break;
case 3: begin= time(NULL);
                  lvaushowProb(cards);
end= time(NULL);
printf("Time elapsed is %f seconds\n", (double)(end-begin));
break;
case 4: begin= time(NULL);
                  lvauthshowProb(cards);
end= time(NULL);
printf("Time elapsed is %f seconds\n",(double) (end-begin));
break;
default: printf("Wrong Choice");
break;
}

// do {
// printf("\nEnter your choice \n1.Banker\n2.Player\n3.Tie\n");
// fflush(stdin);
// scanf("%hu",&bet);
// }
while(bet!=1&&bet!=2&&bet!=3);
w=win(randCards(),randCards(),randCards(),randCards());
switch(w)
{
case 'p':
//printf("\nplayer wins\n");
glBegin(GL_QUADS);
glColor3f(1,1,1);
glVertex2i(300, 35);
glVertex2i(170, 35);
glVertex2i(170, 55);
glVertex2i(300, 55);
glEnd();
BitmapText("Player wins",170,40);
break;
case 'b':
glBegin(GL_QUADS);
glColor3f(1,1,1);
glVertex2i(300, 35);
glVertex2i(170, 35);
glVertex2i(170, 55);
glVertex2i(300, 55);
glEnd();
//printf("\nbanker wins\n");
BitmapText("Banker wins",170,40);
break;
case 't':
glBegin(GL_QUADS);
glColor3f(1,1,1);
glVertex2i(300, 35);
glVertex2i(170, 35);
glVertex2i(170, 55);
glVertex2i(300, 55);
glEnd();
//printf("\ntie\n");
BitmapText("Tie",170,40);
break;
default :
//printf("error");
break;
}

}
 char win(short a,short b,short c,short d){
int a1,b1,c1,d1;
a1=a;b1=b;
c1=c;
d1=d;
a=value(a);
b=value(b);
c=value(c);
d=value(d);
char ch[10];


glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2i(50, 70);
glVertex2i(150, 70);
glVertex2i(150, 150);
glVertex2i(50, 150);
glEnd();


glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2i(200, 70);
glVertex2i(300, 70);
glVertex2i(300, 150);
glVertex2i(200, 150);
glEnd();

glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2i(350, 70);
glVertex2i(450, 70);
glVertex2i(450, 150);
glVertex2i(350, 150);
glEnd();

glColor3f(1.0, 1.0, 1.0);
glBegin(GL_QUADS);
glVertex2i(500, 70);
glVertex2i(600, 70);
glVertex2i(600, 150);
glVertex2i(500, 150);
glEnd();

gcvt(a1,4,ch);
BitmapText(ch, 100,100);
char ch1[10],ch2[10],ch3[10];
gcvt(c1,4,ch1);
gcvt(b1,4,ch2);
gcvt(d1,4,ch3);
BitmapText(ch1, 250,100);
BitmapText(ch2, 400,100);
BitmapText(ch3, 550,100);
//mapText("caah", 250, 300);

short temp;
if((((a+c)%10)>7)||(((b+d)%10)>7))
{ if(((a+c)%10)==((b+d)%10))
{return 't';}
return ((a+c)%10)>((b+d)%10)?'p':'b';
}
else if((((a+c)%10)>5)&&(((b+d)%10)<6))
{
temp = value(randCards());
if(((a+c)%10)==((temp+b+d)%10))
{return 't';}
return ((a+c)%10)>((temp+b+d)%10)?'p':'b';

}
else if ((((a+c)%10)<6)&&(((b+d)%10)>5))
{temp = value(randCards());
if(((temp+a+c)%10)==((b+d)%10))
{return 't';}
return ((temp+a+c)%10)>((b+d)%10)?'p':'b';}


else
{
temp = value(randCards());
if(((a+c)%10)==((temp+b+d)%10))
{return 't';}
return ((a+c)%10)>((temp+b+d)%10)?'p':'b';

}



}
int main(int argc, char** argv)
{
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(600,0);
    glutInit(&argc, argv);
    glutCreateWindow("Baccarat:");
    myin();
    glutDisplayFunc(Display);
    glutMouseFunc(mouse);
   //glutMouseFunc(mouse);
glutPostRedisplay();
   glutMainLoop();
// init();
// game();
return 0;
}
