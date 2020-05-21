#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define mcaudsc 416

time_t mcaudst;

char mcaudscardsArr[mcaudsc];
unsigned int mcaudsB, mcaudsP, mcaudsT;
unsigned long mcaudsitr;
unsigned int mcaudsi;
short mcaudsk, mcaudsl, mcaudsm, mcaudsn, mcaudsj;

struct node;
typedef struct node* nodeaf;


struct node* mcaudsgetnode(nodeaf tempRoot);
void mcaudscalcProb(); //display as well
short mcaudsrandCards();
char mcaudswin(short a, short b, short e, short d);


//nodeaf tempNode;
struct node{
  struct node* arr[mcaudsc];
};

nodeaf mcaudsarray[mcaudsc];


 struct node* mcaudsgetnode4(nodeaf tempRoot){
  if(tempRoot== NULL){
    /*tempRoot= (nodeaf)malloc(sizeof(struct node));
	for(mcaudsj=0;mcaudsj<mcaudsc;mcaudsj++)
	{
    tempRoot->arr[mcaudsj]=NULL;
	}*/
	 printf("null\n" );
    return tempRoot;
  }
	printf("not null\n" );
	return tempRoot;
}

struct node* mcaudsgetnode(nodeaf tempRoot){
  if(tempRoot== NULL){
    tempRoot= (nodeaf)malloc(sizeof(struct node));
	for(mcaudsj=0;mcaudsj<mcaudsc;mcaudsj++)
	{
    tempRoot->arr[mcaudsj]=NULL;
	}
	 //printf("null\mcaudsn" );
    return tempRoot;
  }
	//printf("not null\mcaudsn" );
	return tempRoot;
}

short mcaudsrandCards(){


  short r;
 r=rand()%mcaudsc;
   //printf("hello mcaudsrandCards %d\n",r );
  while(mcaudscardsArr[r]=='f'){
  r=rand()%mcaudsc;
  //printf("hello random loop %d\n",r );

  }
    return r;
}

short mcaudsvalue(short mcauds_a)
{

		mcauds_a=mcauds_a%13;
    if(mcauds_a<9)
		{
			return (mcauds_a+1);}
		else
			{return 0;}

}

char mcaudswin(short a, short b, short c, short d){
  //calculate face mcaudsvalue of card
a=mcaudsvalue(a);
b=mcaudsvalue(b);
c=mcaudsvalue(c);
d=mcaudsvalue(d);
short temp;

  if((((a+c)%10)>7)||(((b+d)%10)>7))
	{	if(((a+c)%10)==((b+d)%10))
		{return 't';}
		return ((a+c)%10)>((b+d)%10)?'p':'b';
		}
	else if((((a+c)%10)>5)&&(((b+d)%10)<6))
		{
			temp = mcaudsvalue(mcaudsrandCards());
			if(((a+c)%10)==((temp+b+d)%10))
		{return 't';}
		return ((a+c)%10)>((temp+b+d)%10)?'p':'b';

			}
	else if ((((a+c)%10)<6)&&(((b+d)%10)>5))
		{temp = mcaudsvalue(mcaudsrandCards());
			if(((temp+a+c)%10)==((b+d)%10))
		{return 't';}
		return ((temp+a+c)%10)>((b+d)%10)?'p':'b';}


	else
		{
			//temp = mcaudsvalue(mcaudsrandCards());
			if(((a+c)%10)==((b+d)%10))
		{return 't';}
		return ((a+c)%10)>((b+d)%10)?'p':'b';

		}


 //printf("%d %d %d %d\n",a,b,e,d );
}
void mcaudscalcProb(){
  printf("Banker= %d\n",mcaudsB);
  printf("Player= %d\n",mcaudsP);
  printf("Tie= %d\n",mcaudsT);
double b,p,mcaudst;
b=mcaudsB;
p=mcaudsP;
mcaudst=mcaudsT;
b=(b/mcaudsitr)*100;
p=(p/mcaudsitr)*100;
mcaudst=(mcaudst/mcaudsitr)*100;
 printf("Banker= %lf\n",b);
  printf("Player= %lf\n",p);
  printf("Tie= %lf\n",mcaudst);
}


void mcaudsshowProb(char mccards[416]){

for(int i=0;i<416;i++)
{
mcaudscardsArr[i]=mccards[i];
}
//  printf("hello\n" );
  //mcaudscalcProb();

  mcaudsB=0;
  mcaudsP=0;
  mcaudsT=0;
  mcaudsitr=300000;
  for(mcaudsj=0;mcaudsj<mcaudsc;mcaudsj++)

	{
		mcaudsarray[mcaudsj]=NULL;
	}	 //initializing the code

  for(mcaudsi=0; mcaudsi<mcaudsitr; ++mcaudsi){//mcaudscalcProb();
      srand((unsigned)time(&mcaudst)+mcaudsi);
    //printf("hello\n" );
 mcaudsk=0;
 mcaudsl=0;
 mcaudsm=0;
 mcaudsn=0;
    mcaudsk=mcaudsrandCards();
    mcaudscardsArr[mcaudsk]= 'f';
    mcaudsl=mcaudsrandCards();
    mcaudscardsArr[mcaudsl]= 'f';
    mcaudsm=mcaudsrandCards();
    mcaudscardsArr[mcaudsm]= 'f';
    mcaudsn=mcaudsrandCards();
    mcaudscardsArr[mcaudsn]= 'f';


     if((  mcaudsgetnode((mcaudsgetnode((  mcaudsgetnode(mcaudsarray[mcaudsk]))->arr[mcaudsl]))->arr[mcaudsm]))->arr[mcaudsn]!=NULL)
    {
      //break;
       //printf("full");
      continue;
    }
	else {
//printf("not full");

char mcaudsw= mcaudswin(mcaudsk,mcaudsl,mcaudsm,mcaudsn);
   switch(mcaudsw)
		{
			case 'p':
			mcaudsP++;
			//printf("\nplayer wins\n");
			break;

			case 'b':
			mcaudsB++;
			//printf("\nbanker wins\n");
			break;
			case 't':
			mcaudsT++;
			//printf("\ntie\n");
			break;
			default :
			//printf("error");
			break;
			}


}

    mcaudscardsArr[mcaudsk]= 't';

    mcaudscardsArr[mcaudsl]= 't';

    mcaudscardsArr[mcaudsm]= 't';

    mcaudscardsArr[mcaudsn]= 't';

  }

  //printf("hello loop end\n" );
 mcaudscalcProb();

}
