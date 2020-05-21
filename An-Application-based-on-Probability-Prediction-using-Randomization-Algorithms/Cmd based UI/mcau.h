//mcau w/o ds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define mcaucn 416

time_t mcaut;

char mcaucardsArr[mcaucn];
unsigned int mcauB, mcauP, mcauT;
unsigned long mcauitr;
unsigned int mcaui;
short mcauk, mcaul, mcaum, mcaun, mcauj;

void mcaucalcProb(); //display as well
short mcaurandCards();
char mcauwin(short mcaua, short mcaub, short mcaue, short mcaud);
short mcauvalue(short mcauds_a)
	{
		mcauds_a=mcauds_a%13;
    if(mcauds_a<10)
		{
			return mcauds_a;}
		else
			{return 0;}
		}
short mcaurandCards(){
  short mcaur;
  mcaur=rand()%mcaucn;
  //printf("Card randomly selected from deck: %mcaud\mcaun",mcaur );
  while(mcaucardsArr[mcaur]=='f'){ //trying to find mcaua card that we have in the deck as of now. Because if value is 'f' it means that we dont have that
                          // card in the deck
     mcaur=rand()%mcaucn;
     //printf("Card randomly selected from deck on second try: %mcaud\mcaun",mcaur );
  }
  return mcaur;
}

char mcauwin(short mcaua,short mcaub,short mcauc,short mcaud){
	mcaua=mcauvalue(mcaua);
	mcaub=mcauvalue(mcaub);
	mcauc=mcauvalue(mcauc);
	mcaud=mcauvalue(mcaud);
	short temp;
	if((((mcaua+mcauc)%10)>7)||(((mcaub+mcaud)%10)>7))
	{	if(((mcaua+mcauc)%10)==((mcaub+mcaud)%10))
		{return 't';}
		return ((mcaua+mcauc)%10)>((mcaub+mcaud)%10)?'p':'b';
		}
	else if((((mcaua+mcauc)%10)>5)&&(((mcaub+mcaud)%10)<6))
		{ 
			temp = mcauvalue(mcaurandCards());
			if(((mcaua+mcauc)%10)==((temp+mcaub+mcaud)%10))
		{return 't';}
		return ((mcaua+mcauc)%10)>((temp+mcaub+mcaud)%10)?'p':'b';
			
			}
	else if ((((mcaua+mcauc)%10)<6)&&(((mcaub+mcaud)%10)>5))
		{temp = mcauvalue(mcaurandCards());
			if(((temp+mcaua+mcauc)%10)==((mcaub+mcaud)%10))
		{return 't';}
		return ((temp+mcaua+mcauc)%10)>((mcaub+mcaud)%10)?'p':'b';}
		
		
	else 
		{ 
			//temp = mcauvalue(mcaurandCards());
			if(((mcaua+mcauc)%10)==((mcaub+mcaud)%10))
		{return 't';}
		return ((mcaua+mcauc)%10)>((mcaub+mcaud)%10)?'p':'b';
				
		}



}
void mcaucalcProb(){
  printf("Banker Sum= %d\n",mcauB);
  printf("Player Sum= %d\n",mcauP);
  printf("Tie Sum= %d\n",mcauT);
  double mcaub,mcaup,mcaut;
  mcaub=mcauB;
  mcaup=mcauP;
  mcaut=mcauT;
  mcaub=(mcaub/mcauitr)*100;
  mcaup=(mcaup/mcauitr)*100;
  mcaut=(mcaut/mcauitr)*100;
  printf("Probability of Banker= %lf\n",mcaub);
  printf("Probability of Player= %lf\n",mcaup);
  printf("Probability of Tie= %lf\n",mcaut);
}


void mcaushowProb(char mcaucardArr[mcaucn]){
	for(mcaui=0;mcaui<mcaucn;mcaui++)
{
mcaucardsArr[mcaui]=mcaucardArr[mcaui];}
  mcauB=0;
  mcauP=0;
  mcauT=0;
  mcauitr=200000;

  for(mcaui=0; mcaui<mcauitr; ++mcaui){//mcaucalcProb();
    srand((unsigned)time(&mcaut)+mcaui);
    //printf("Hand No.: %d\n", mcaui+1);
    //printf("Drawing Player and Banker hands....\n" );
    mcauk=0;
    mcaul=0;
    mcaum=0;
    mcaun=0;
    mcauk=mcaurandCards();
    mcaucardsArr[mcauk]= 'f';
    //printf("yoyo %s %mcaud \mcaun", &cardsArr[mcauk], &mcauk);
    mcaul=mcaurandCards();
    mcaucardsArr[mcaul]= 'f';
    mcaum=mcaurandCards();
    mcaucardsArr[mcaum]= 'f';
    mcaun=mcaurandCards();
    mcaucardsArr[mcaun]= 'f';
	char mcauw= mcauwin(mcauk,mcaul,mcaum,mcaun);
   switch(mcauw)
		{
			case 'p':
			mcauP++;
			//printf("\nplayer wins\n");
			break;
			
			case 'b':
			mcauB++;
			//printf("\nbanker wins\n");
			break;
			case 't':
			mcauT++;
			//printf("\ntie\n");
			break;
			default :
			//printf("error");
			break;
			} 

    mcaucardsArr[mcauk]= 't';
    mcaucardsArr[mcaul]= 't';
    mcaucardsArr[mcaum]= 't';
    mcaucardsArr[mcaun]= 't';
  }
  //printf("hello loop end\n" );
  mcaucalcProb();
  
}
