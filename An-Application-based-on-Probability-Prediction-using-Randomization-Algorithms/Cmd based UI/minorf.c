#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include"mcau.h"
#include"lvau.h"
#include"mcauds.h"
#include"lvauth.h"
#define cn 416

time_t t;
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
		printf("\nWelcome to our casino where we show you your winning probability beforehand!!!\n");
		}
void showProb(char card[cn])
	{
		switch (choice)
		{case 1:
                  mcaushowProb(card);
									break;
		case 2:
                  mcaudsshowProb(card);
									break;
		case 3:
                 lvauShowProb(card);
								 break;
		case 4:
                 lvauthshowProb(card);
								 break;
		default:
		break;
			}
		}
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

while(choice!=1&&choice!=2&&choice!=3&&choice!=4){
	printf("\nEnter your choice of algorithm to calculate probability\n1.Monte Carlo\n2.Monte Carlo with Forest\n3.Las Vegas\n4.Las Vegas with threading\n");
	fflush(stdin);
	scanf("%hd",&choice);
		}

	showProb(cards);
	do {
	printf("\nEnter your choice \n1.Banker\n2.Player\n3.Tie\n");
	scanf("%hu",&bet);}while(bet!=1&&bet!=2&&bet!=3);
	w=win(randCards(),randCards(),randCards(),randCards());
		switch(w)
		{
			case 'p':
			printf("\nplayer wins\n");
			break;
			case 'b':
			printf("\nbanker wins\n");
			break;
			case 't':
			printf("\nThere was a TIE\n");
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
