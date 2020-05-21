//macau with ds
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define mcauds_co 416
char mcauds_cardsArr[mcauds_co];
unsigned int mcauds_i;
time_t mcauds_tt;
struct root1;
struct node1;
struct node2;
struct nodef;
int mcauds_pl;
int mcauds_ba;
int mcauds_t;
unsigned int mcauds_iter;

struct root1
{
  struct node1* arr [mcauds_co];
};
struct node1
{
  short place;
  struct node2* arr [mcauds_co];
};

struct node2
{
  short place;
  struct nodef* arr [mcauds_co];
};

struct nodef
{
  short place;
  short card;
};
short mcauds_value(short mcauds_a)
	{
		mcauds_a=mcauds_a%13;
    if(mcauds_a<10)
		{
			return mcauds_a;}
		else
			{return 0;}
		}
short mcauds_randCards(){


  short mcauds_r;
  do{
  mcauds_r=rand()%mcauds_co;


  }while(mcauds_cardsArr[mcauds_r]=='f');
   //mcauds_cards[mcauds_r]='f';
    return mcauds_r;
}
char mcauds_win(short mcauds_a,short mcauds_b,short mcauds_c,short mcauds_d){
	mcauds_a=mcauds_value(mcauds_a);
	mcauds_b=mcauds_value(mcauds_b);
	mcauds_c=mcauds_value(mcauds_c);
	mcauds_d=mcauds_value(mcauds_d);
	short mcauds_temp;
	if((((mcauds_a+mcauds_c)%10)>7)||(((mcauds_b+mcauds_d)%10)>7))
	{	if(((mcauds_a+mcauds_c)%10)==((mcauds_b+mcauds_d)%10))
		{return 't';}
		return ((mcauds_a+mcauds_c)%10)>((mcauds_b+mcauds_d)%10)?'p':'b';
		}
	else if((((mcauds_a+mcauds_c)%10)>5)&&(((mcauds_b+mcauds_d)%10)<6))
		{
			mcauds_temp = mcauds_value(mcauds_randCards());
			if(((mcauds_a+mcauds_c)%10)==((mcauds_temp+mcauds_b+mcauds_d)%10))
		{return 't';}
		return ((mcauds_a+mcauds_c)%10)>((mcauds_temp+mcauds_b+mcauds_d)%10)?'p':'b';

			}
	else if ((((mcauds_a+mcauds_c)%10)<6)&&(((mcauds_b+mcauds_d)%10)>5))
		{mcauds_temp = mcauds_value(mcauds_randCards());
			if(((mcauds_temp+mcauds_a+mcauds_c)%10)==((mcauds_b+mcauds_d)%10))
		{return 't';}
		return ((mcauds_temp+mcauds_a+mcauds_c)%10)>((mcauds_b+mcauds_d)%10)?'p':'b';}


	else
		{
			mcauds_temp = mcauds_value(mcauds_randCards());
			if(((mcauds_a+mcauds_c)%10)==((mcauds_temp+mcauds_b+mcauds_d)%10))
		{return 't';}
		return ((mcauds_a+mcauds_c)%10)>((mcauds_temp+mcauds_b+mcauds_d)%10)?'p':'b';

		}
}
void calcProb(){
  printf("Banker Sum= %d\n",mcauds_ba);
  printf("Player Sum= %d\n",mcauds_pl);
  printf("Tie Sum= %d\n",mcauds_t);
  double mcauds_B,mcauds_P,mcauds_T;
  mcauds_B=mcauds_ba;
  mcauds_P=mcauds_pl;
  mcauds_T=mcauds_t;
  mcauds_B=(mcauds_B/mcauds_iter)*100;
  mcauds_P=(mcauds_P/mcauds_iter)*100;
  mcauds_T=(mcauds_T/mcauds_iter)*100;
  printf("Probability of Banker= %lf\n",mcauds_B);
  printf("Probability of Player= %lf\n",mcauds_P);
  printf("Probability of Tie= %lf\n",mcauds_T);
}


void mcaudsshowProb(char cards[416]){
  printf("mcau ds\n");
for (int i=0;i<416;i++)
{
mcauds_cardsArr[i]=cards[i];

}
  struct root1* array[mcauds_co];
  for(mcauds_i=0;mcauds_i<mcauds_co;mcauds_i++)
  {
    array[mcauds_i] =NULL ;
  }
  struct root1* temproot;
  struct node1* tempnode1;
  struct node2* tempnode2;
  struct nodef* tempnodef;
  srand((unsigned)time(&mcauds_tt));
  int mcauds_k;
  int mcauds_l;
  int mcauds_m;
  int mcauds_n;
  float mcauds_mem = sizeof(struct root1)+sizeof(struct node1)+sizeof(struct node2)+sizeof(struct nodef);
  float mcauds_meb = sizeof(struct root1)+sizeof(struct node1)+sizeof(struct node2)+sizeof(struct nodef);

  mcauds_iter=300;

  for(mcauds_i=0; mcauds_i<mcauds_iter; mcauds_i++)
  {
    printf("mcau ds for\n");

    srand((unsigned)time(&mcauds_tt)+mcauds_iter);
  	mcauds_k=rand()%mcauds_co;
  	if(array[mcauds_k]==NULL)
  	{
  		array[mcauds_k]=(struct root1*)malloc(sizeof(struct root1));
  	}
  	temproot=array[mcauds_k];
  	mcauds_l=rand()%mcauds_co;
  	if(temproot->arr[mcauds_l]==NULL)
    {
      temproot->arr[mcauds_l]=(struct node1*)malloc(sizeof(struct node1));
    }
    tempnode1=temproot->arr[mcauds_l];
    mcauds_m=rand()%mcauds_co;
    if(tempnode1->arr[mcauds_m]==NULL)
    {
      tempnode1->arr[mcauds_m]=(struct node2*)malloc(sizeof(struct node2));
    }
    tempnode2=tempnode1->arr[mcauds_m];
    mcauds_n=rand()%mcauds_co;
    if (tempnode2->arr[mcauds_n]!=NULL)
    { mcauds_i--;
      continue;
    }
    if(tempnode2->arr[mcauds_n]==NULL)
    {
      tempnode2->arr[mcauds_n]=(struct nodef*)malloc(sizeof(struct nodef));
      char mcaudswin =mcauds_win(mcauds_k,mcauds_l,mcauds_m,mcauds_n);
	switch(mcaudswin)
		{
			case 'p':
			mcauds_pl++;
			//printf("\nplayer wins\n");
			break;

			case 'b':
			mcauds_ba++;
			//printf("\nbanker wins\n");
			break;
			case 't':
			mcauds_t++;
			//printf("\ntie\n");
			break;
			default :
			//printf("error");
			break;
			}
      mcauds_mem=mcauds_mem+mcauds_meb;
    }
}
printf("tree mcauds_mem allocated= %lf Kilo Bytes\n",mcauds_mem/1024);
calcProb();

}
