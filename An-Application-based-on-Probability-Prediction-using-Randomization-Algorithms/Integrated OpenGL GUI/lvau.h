#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>

char lvaucardsArr[416];
long double lvauB=0.0, lvauP=0.0, lvauT=0.0, lvauC=0.0;


short lvauvalue(short a)
{
	a=a%13;
	if(a<9)
	{
		return (a+1);
	}
	else
	{
		return 0;
	}
}

void lvauWinCalc(short a, short b, short c, short d)
{       short c1,c2,c3,c4;
	c1=a;
	c2=b;
	c3=c;
	c4=d;
	a=lvauvalue(a);
	b=lvauvalue(b);
	c=lvauvalue(c);
	d=lvauvalue(d);
	short temp;
	if((((a+c)%10)>7)||(((b+d)%10)>7))
	{	
		if(((a+c)%10)==((b+d)%10))
		{
			lvauT+=1;
			lvauC+=1;
			//printf("\ntie\n");
		}
		else if((a+c)%10>(b+d)%10)
		{
			lvauP+=1;
			lvauC+=1;
			//printf("\nplayer\n");
		}
		else 
		{	
			lvauB+=1;
			lvauC+=1;
			//printf("\nBanker\n");
		}	
	}
	else if((((a+c)%10)>5)&&(((b+d)%10)<6))
	{ 
		for(short i=0;i<416;i++)
		{    
			if(lvaucardsArr[i]=='f'||i==c1||i==c2||i==c3||i==c4)
				continue;
			temp = lvauvalue(i);
			if(((a+c)%10)==((temp+b+d)%10))
			{
				lvauT+=1;
				lvauC+=1;
				//printf("\ntie\n");
			}
			else if((a+c)%10>(temp+b+d)%10)
			{
				lvauP+=1;
				lvauC+=1;
				//printf("\nplayer\n");
			}
			else 
			{
				lvauB+=1;
				lvauC+=1;
			}	
		}
	}
	else if ((((a+c)%10)<6)&&(((b+d)%10)>5))
	{
		for(short i=0;i<416;i++)
		{    
			if(lvaucardsArr[i]=='f'||i==c1||i==c2||i==c3||i==c4)
				continue;	
			temp = lvauvalue(i);
			if(((temp+a+c)%10)==((b+d)%10))
			{
				lvauT+=1;
				lvauC+=1;
			//printf("\ntie\n");
			}
		 	else if((temp+a+c)%10>(b+d)%10)
		   	{
				lvauP+=1;
				lvauC+=1;
				//printf("\nplayer\n");
			}
			else 
			{
				lvauB+=1;
				lvauC+=1;
				//printf("\nBanker\n");
			}
		}
	}
	else
	{
		if(((a+c)%10)==((b+d)%10))
		{
			lvauT+=1;
			lvauC+=1;
			//printf("\ntie\n");
		}		
		else if((a+c)%10>(b+d)%10)
		{
			lvauP+=1;
			lvauC+=1;
			//printf("\nplayer\n");
		}
		else 
		{
			lvauB+=1;
			lvauC+=1;
			//printf("\nBanker\n");
		}	
	}
}

void lvaushowProb(char cards[416])
{ time_t begin = time(NULL);
 for(int i =0; i<416;i++)
{lvaucardsArr[i]=cards[i];}
  printf("In lvau func \n");
  short k,l,m,n;
  for(k=0;k<416;k++)
  {
    //printf("IN first loop \n");
    if(lvaucardsArr[k]==false)
      continue;
    for(l=0;l<416;l++)
    {
      //printf("In second loop\n");
      if(lvaucardsArr[l]==false)
        continue;
      for(m=0;m<416;m++)
      {
        //printf("In 3rd loop\n");
        if(lvaucardsArr[m]==false)
          continue;
        for(n=0;n<416;n++)
        {
	  if(lvaucardsArr[m]==false)
            continue;
	  lvauWinCalc(k,l,m,n);
        }
      }
    }
  }
  double banker_percentage= (lvauB/lvauC)*100;
  double player_percentage= (lvauP/lvauC)*100;
  double tie_percentage= (lvauT/lvauC)*100;
  printf("banker, player, tie, counter %Lf %Lf %Lf %Lf \n",lvauB, lvauP, lvauT, lvauC);
  printf("Probability of banker's win= %lf \n",banker_percentage);
  printf("Probability of player's win= %lf \n",player_percentage);
  printf("Probability of tie= %lf \n",tie_percentage);
time_t end = time(NULL);

	// calculate elapsed time by finding difference (end - begin)
  printf("Time elpased is %ld seconds\n", (end - begin));
}


