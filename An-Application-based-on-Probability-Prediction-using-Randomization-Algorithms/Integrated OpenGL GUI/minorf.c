#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include"mcauds.h"
#include"mcau.h"
#include"lvau.h"

#include"lvauth.h"
#define cn 416

time_t t;
clock_t begin, end;
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
void init()
	{
		for (int i =0;i<cn;i++)
		{
			cards[i]='t';
		}
		printf("\n*****Welcome to our casino where we show you your winning probability beforehand!!!*****\n");
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
for(int turns =1; turns<=40;turns++){
	srand((unsigned)time(&t)+turns);

do{
	printf("\n\t\tEnter your choice of algorithm to calculate probability \n\n1.Monte Carlo\n2.Monte Carlo with Forest\n3.Las Vegas\n4.Las Vegas with threading\n \n");
	//fflush(stdin);
	scanf("%hu",&choice);
}while(choice!=1&&choice!=2&&choice!=3&&choice!=4);

	//showProb(cards);
	switch (choice)
		{case 1:			begin= time(NULL);
                  mcaushowProb(cards);
									end= time(NULL);
									printf("Time elapsed is %lf seconds\n", (double)(end-begin));
									break;
		case 2:				begin= time(NULL);
									mcaudsshowProb(cards);
									end= time(NULL);
									printf("Time elapsed is %lf seconds\n", (double)(end-begin));

									break;
		case 3:				begin= time(NULL);
                  lvaushowProb(cards);
									end= time(NULL);
									printf("Time elapsed is %lf seconds\n", (double)(end-begin));
									break;
		case 4:				begin= time(NULL);
                  lvauthshowProb(cards);
									end= time(NULL);
									printf("Time elapsed is %lf seconds\n", (double)(end-begin));
									break;
		default:			printf("Wrong Choice");
									break;
			}

	do {
	printf("\n \nEnter your choice \n1.Banker\n2.Player\n3.Tie\n\n");
	fflush(stdin);
	scanf("%hu",&bet);}while(bet!=1&&bet!=2&&bet!=3);
	short a1,a2,a3,a4;
	a1=randCards();
	a2=randCards();
	a3=randCards();
	a4=randCards();
	w=win(a1,a2,a3,a4);
	printf("\nThe cards are p1=%hu b1=%hu p2=%hu b2=%hu\n",a1,a2,a3,a4);
	printf("\nThe value are are p1=%hu b1=%hu p2=%hu b2=%hu\n",value(a1),value(a2),value(a3),value(a4));
		switch(w)
		{
			case 'p':
			printf("\nplayer wins\n");
			break;
			case 'b':
			printf("\nbanker wins\n");
			break;
			case 't':
			printf("\ntie\n");
			break;
			default :
			printf("error");
			break;
			}
			}
		}
 char win(short a,short b,short c,short d){
	a=value(a);
	b=value(b);
	c=value(c);
	d=value(d);
	short temp;
	if((((a+c)%10)>7)||(((b+d)%10)>7))
	{	if(((a+c)%10)==((b+d)%10))
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
int main()
	{
	init();
	game();
	return 0;
}
