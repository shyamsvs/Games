#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int a[100];
int pos=1;
int flag=1;



void display(int pos)
{ 
  int i;
  for(i=100;i>=1;i--)
  {
    a[pos]=1;
    if(i%10==0)
    {
      printf("\n\n");
    }
    printf("%d\t",a[i]);
  }
}



int roll()
{
int n;
  srand(time(NULL));
  n=rand()%6+1;
  /*printf("\nPlease enter the dice ");
  scanf("%d",&n);*/


  printf("\n\n***********************************\n\n");
  printf("\nDICE: %d\n\n",n);
  
  return n;
}



void play()
{ 
  int temp;
  temp=pos;
  
  if(temp==99 || temp==59 || temp==67 )
  { 
    a[temp]=555;
  }
  else if(temp==4 || temp==25 || temp==36 )
  { 
    a[temp]=55;
  }
  else if(temp==8 || temp==31 || temp==40 )
  { 
    a[temp]=777;
  }
  else if(temp==27 || temp==53 || temp==95 )
  { 
    a[temp]=77;
  }
  else
  {
   a[temp]=0;
  }
  pos = pos+roll();
  if(pos>100)
  {
    pos=temp;
  }
  if(pos==100)
  {
    flag=0;
    printf("\nYOU WON!!!!!!\n");
    printf("#######123456789########");
    exit(0);
  }
  else if(pos==99)
  {
      pos=4;
  }
  else if(pos==59)
  {
      pos=25;
  }
  else if(pos==67)
  {
      pos=36;
  }
  else if(pos==40)
  {
      pos=95;
  }
  else if(pos==8)
  {
      pos=27;
  }
  else if(pos==31)
  {
      pos=53;
  }
  display(pos);
}



  
int main() 
{
  printf("!!..WELCOME TO SNAKE AND LADDER...!!\n");
  int i;
  int flag=1;
  int snake_head[3];
  
  int player1;
  int board[100];
  int cho;
  /*for(i=100;i>0;i--)
  {
    if(i%10==0)
    {
      //printf("\n");
    }
    printf("%d ",i);
  }*/

  for(i=1;i<=100;i++)
  {
    a[i]=0;
    if(i==99 || i==67 || i==59 )
    {
      a[i]=555;          //snake top
    }
    if(i==8 || i==31 || i==40)
    {
      a[i]=777;         //ladder bottom
    }
    if(i==4 || i==25 || i==36)
    {
      a[i]=55;         //snake bottom
    }
    if(i==27 || i==53 || i==95)
    {
      a[i]=77;         //ladder top
    }

  }
  
  while(1)
  {
  printf("\n\n1.PLAY\n2.EXIT\n");
  scanf("%d",&cho); 
  switch(cho)
  {
    case 1:play();
           break;
    case 2:
           printf("Thankyou for playing");
           exit(0);
           break;
    default:printf("Enter valid response");
  }
}
  
  return 0;
}
