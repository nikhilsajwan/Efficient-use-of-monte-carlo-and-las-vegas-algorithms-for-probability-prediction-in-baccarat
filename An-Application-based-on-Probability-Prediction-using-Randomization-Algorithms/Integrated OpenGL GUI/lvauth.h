#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>
#include<unistd.h>
#include<errno.h>

#define cn 104
time_t start,end;
char cardsArr[cn];
unsigned long int P=0,B=0,T=0;
unsigned long int count = 0;
struct winstruct;
struct winstruct{
		unsigned long int PL;
		unsigned long int BA;
		unsigned long int TI;
		unsigned long int CO;
		};
void* lvauThread(void *ttid);
//short lvauthvalue(short a);
//struct winstruct win(short a,short b,short c,short d);
//void init();
/*void init(){printf("10");
	for(short i=0;i<cn;i++)
		{cardsArr[i]='t';

			}}*/
short lvauthvalue(short a)
	{
		a=a%13;
                if(a<9)
		{
			return (a+1);}
		else
			{return 0;}
		}

void* lvauThread(void *ttid){
	short* tid = (short*)ttid;
	short id = *tid;
	//id = id*2;
	//printf("\nthreading\n");
		//struct winstruct threadstruct;
		struct winstruct counter;
	counter.PL=0;
	counter.BA=0;
	counter.TI=0;
	counter.CO=0;
	//printf("\nthreading cont..\n");
	//for(int i=0;i<2;i++){printf("\nthreading cont..\n");
		if(cardsArr[id]=='f')
			{return(NULL);}
		for(int j=0;j<cn;j++){
			if(cardsArr[j]=='f'||(id)==j)
				continue;
				for(int k=0;k<cn;k++){
			if(cardsArr[k]=='f'||(id)==k||j==k)
				continue;
				for(int l=0;l<cn;l++){
			if(cardsArr[l]=='f'||(id)==l||j==l||k==l)
				continue;

short a,b,c,d;
a=id;
b=j;
c=k;
d=l;
short c1,c2,c3,c4;
	c1=a;
	c2=b;
	c3=c;
	c4=d;
	//printf("\n %hu %hu %hu %hu\n",a,b,c,d);
	a=lvauthvalue(a);
	b=lvauthvalue(b);
	c=lvauthvalue(c);
	d=lvauthvalue(d);
	//printf("\n %hu %hu %hu %hu\n",a,b,c,d);
	short temp=0;



	if((((a+c)%10)>7)||(((b+d)%10)>7))
	{
		if(((a+c)%10)==((b+d)%10))
		{counter.TI+=1;
		counter.CO+=1;
		//printf("\ntie\n");
		}

		else if((a+c)%10>(b+d)%10)
		{counter.PL+=1;counter.CO+=1;
		//printf("\nplayer\n");
		}
		else {counter.BA+=1;
		counter.CO+=1;
		//printf("\nBanker\n");
		}
		}
	else if((((a+c)%10)>5)&&(((b+d)%10)<6))
		{ for(short i=0;i<cn;i++)
		{    if(cardsArr[i]=='f'||i==c1||i==c2||i==c3||i==c4)
			{continue;}
			temp = lvauthvalue(i);
			if(((a+c)%10)==((temp+b+d)%10))
			{counter.TI+=1;
		counter.CO+=1;
		//printf("\ntie\n");
		}
		else if((a+c)%10>(temp+b+d)%10)
		{counter.PL+=1;counter.CO+=1;
		//printf("\nplayer\n");
		}
			else {counter.BA+=1;
			counter.CO+=1;}	}
			}
	else if((((a+c)%10)<6)&&(((b+d)%10)>5))
		{
			for(short i=0;i<cn;i++)
			{    if(cardsArr[i]=='f'||i==c1||i==c2||i==c3||i==c4)
				{continue;}
				temp = lvauthvalue(i);
			if(((temp+a+c)%10)==((b+d)%10))
		{counter.TI+=1;
		counter.CO+=1;
		//printf("\ntie\n");
		}
		 else if((temp+a+c)%10>(b+d)%10)
		   {counter.PL+=1;
		counter.CO+=1;
		//printf("\nplayer\n");
		}
		else {counter.BA+=1;
		counter.CO+=1;
		//printf("\nBanker\n");
		}}

}
 else{
if(((a+c)%10)==((b+d)%10))
		{counter.TI+=1;
		counter.CO+=1;
		//printf("\ntie\n");
		}

		else if((a+c)%10>(b+d)%10)
		{counter.PL+=1;counter.CO+=1;
		//printf("\nplayer\n");
		}
		else {counter.BA+=1;
		counter.CO+=1;
		//printf("\nBanker\n");
		}
		}


			}
			}
			}//}
		P+=counter.PL;
		B+=counter.BA;
		T+=counter.TI;
		count+=counter.CO;
		//printf("\n%ld %ld %ld %ld \n",P,B,T,count);



		}

void lvauthshowProb(char card[cn]){
//printf("start");
time(&start);
for (short i =0;i<cn;i++){
  cardsArr[i] = card[i];}
	short i =0;

	//printf("\n main");
	short id[416];
	pthread_t tid[416];
        for(i=0;i<416;i++){
    tid[i]=i;
    id[i]=i;
	//printf("\n initialise\n");
  }
	for(i=0;i<416;i++){
	//printf("\nthread");
	 pthread_create(&(tid[i]),NULL,lvauThread, (void *)&id[i]);
	//printf("\n");
}
	for(i=0;i<416;i++)
{
  pthread_join(tid[i], NULL);
	//printf("\njoin\n");
}
long double banker_percentage= ((long double)B/(long double)count)*100;
  long double player_percentage= ((long double)P/(long double)count)*100;
  long double tie_percentage= ((long double)T/(long double)count)*100;
  printf("\nProbability of banker's win= %Lf \n",banker_percentage);
  printf("Probability of player's win= %Lf \n",player_percentage);
  printf("Probability of tie= %Lf \n",tie_percentage);
time(&end);
double timeTaken = (double)(end - start);
//printf("time taken = %lf \n",timeTaken);
	}
