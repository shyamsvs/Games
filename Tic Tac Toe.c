#include <stdio.h>
void display();
int status1();
int status2();
int a[9] = {0,0,0,0,0,0,0,0,0};
int res;

int main()
{
    int i=0,flag=0;
    while(i<9)
    {
        printf("Board\n");
        display();
        printf("Player1 Turn\n");
        int pos=0;
        printf("Enter the Position\n");
        scanf("%d",&pos);
        while(a[pos]==1 || a[pos] == 2)
        {
            printf("You Entered wrong Postition\nRe-enter again\n");
            scanf("%d",&pos);
        }
        a[pos] = 1;
        res = status1();
        printf("%d\n",res);
        if(res==1)
        {
            printf("Player1 Wins\nThank You for Playing :)\n");
            display();
            flag=1;
            break;
        }
        display();
        printf("Player2 Turn\n");
        printf("Enter the Position\n");
        scanf("%d",&pos);
        while(a[pos]==1 || a[pos] == 2)
        {
            printf("You Entered wrong Postition\nRe-enter again\n");
            scanf("%d",&pos);
        }
        a[pos] = 2;
        res = status2();
        if(res==1)
        {
            printf("Player2 Wins\nThank You for Playing :)\n");
            display();
            flag=1;
            break;
        }
        display();
        i++;
    }
    if(flag==0)
    {
        printf("Match Draw\n");
        display();
    }

    return 0;
}
void display()
{
    for(int i=0;i<9;i++)
    {
        if(i%3==0)
        {
            printf("\n");
        }
        printf("%d ",a[i]);
    }
    printf("\n");
}
int status1()
{
    if((a[0]==1 && a[1]== 1 && a[2] == 1)||(a[2]==1 && a[4]== 1 && a[6] == 1)|| (a[0]==1 && a[4]== 1 && a[8] == 1)|| (a[3]==1 && a[4]== 1 && a[5] == 1)|| (a[6]==1 && a[7]== 1 && a[8] == 1)|| (a[0]==1 && a[3]== 1 && a[6] == 1)|| (a[1]==1 && a[4]== 1 && a[7] == 1)|| (a[2]==1 && a[5]== 1 && a[8] == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int status2()
{
     if((a[0]==2 && a[1]== 2 && a[2] == 2)||(a[2]==2 && a[4]== 2 && a[6] == 2)|| (a[0]==2 && a[4]== 2 && a[8] == 2)|| (a[3]==2 && a[4]== 2 && a[5] == 2)|| (a[6]==2 && a[7]== 2 && a[8] == 2)|| (a[0]==2 && a[3]== 2 && a[6] == 2)|| (a[1]==2 && a[4]== 2 && a[7] == 2)|| (a[2]==2 && a[5]== 2 && a[8] == 2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
