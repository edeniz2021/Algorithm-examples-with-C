#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dice();
int startGame(int a,int b);
void printMap(int temp,int pemp);
int game(char map[15][30],int temp,int pemp);
int main()
{
    int temp=0,pemp=0,lemp=0;
    int a=0;
    int b=0;
    int k,m;

    char map[15][30];
    int count=0;
    printMap(temp,pemp);
    printf("To start game, players should dice and decide who is going to start first according to it...\n");

    while(count!=1)//I defined the 'count' variable so that if the dice come out the same, it will loop
    {
        printf("\033[0;33m");
        printf("PLAYER 1 ... press ENTER to dice");
        printf("\033[0m");
        temp= dice();
        printf("\033[0;33m");
        printf("DICE:  %d\n\n",temp);
        printf("\033[0m");
        printf("\033[0;34m");
        printf("PLAYER 2 ... press ENTER to dice");
        printf("\033[0m");
        pemp= dice();
        printf("\033[0;34m");
        printf("DICE:  %d\n",pemp);
        printf("\033[0m");
        lemp=startGame(temp,pemp);

        if(lemp==1)
        {
            count=1;
            printf("\n***PLAYER 1 will start to game...***\n");
            temp=0,pemp=0,lemp=0;
            do
            {
                printf("\033[0;33m");
                printf("PLAYER 1 ... press ENTER to dice");
                printf("\033[0m");
                a=dice();
                temp= temp+a;
                printf("\033[0;33m");
                printf("DICE:  %d\n\n",a);
                printf("\033[0m");
                k=game(map,temp,pemp);
                if(k==1)//I have defined the 'k' variable, when the game is over, it will exit the loop.
                {
                    printf("\033[0;33m");
                    printf("\n\n***PLAYER 1 WON THE GAME***\n\n");
                    printf("\033[0m");
                }
                if(k==0)
                {
                    printf("\033[0;33m");
                    printf("Penalty for player 1...\n");
                    printf("\033[0m");
                }
                printf("\033[0;34m");
                printf("PLAYER 2 ... press ENTER to dice");
                printf("\033[0m");
                b=dice();
                pemp= pemp+b;
                printf("\033[0;34m");
                printf("DICE:  %d\n",b);
                printf("\033[0m");
                
                k=game(map,temp,pemp);
                if(k==2)
                {
                    printf("\033[0;34m");
                    printf("\n\n***PLAYER 2 WON THE GAME***\n\n");
                    printf("\033[0m");
                }
                if(k==3)
                {
                    printf("\033[0;34m");
                    printf("Penalty for player 2...\n");
                    printf("\033[0m");
                }
                printMap(temp,pemp);

            }
            while(k !=1 && k!=2 );
        }
        else if(lemp==2)
        {
            count=1;
            temp=0,pemp=0,lemp=0;
            printf("\n***PLAYER 2 will start to game...***\n");

            do
            {
                printf("\033[0;34m");
                printf("PLAYER 2 ... press ENTER to dice");
                printf("\033[0m");
                b=dice();
                pemp= pemp+b;
                printf("\033[0;34m");
                printf("DICE:  %d\n",b);
                printf("\033[0m");
                m=game(map,temp,pemp);
                if(m==2)
                {
                    printf("\033[0;34m");
                    printf("\n\n***PLAYER 2 WON THE GAME***\n\n");
                    printf("\033[0m");
                }
                if(m==3)
                {
                    printf("\033[0;34m");
                    printf("Penalty for player 2...\n");
                    printf("\033[0m");
                }
                printf("\033[0;33m");
                printf("PLAYER 1 ... press ENTER to dice");
                printf("\033[0m");
                a=dice();
                temp= temp+a;
                printf("\033[0;33m");
                printf("DICE:  %d\n\n",a);
                printf("\033[0m");
               
                m=game(map,temp,pemp);
                if(m==1)
                {
                    printf("\033[0;33m");
                    printf("\n\n***PLAYER 1 WON THE GAME***\n\n");
                    printf("\033[0m");
                }
                if(m==0)
                {
                    printf("\033[0;33m");
                    printf("Penalty for player 1...\n");
                    printf("\033[0m");
                }

 printMap(temp,pemp);
            }
            while(m !=1 && m!=2);
        }
        else if(lemp==3)
        {
            printf("Same dice value.. Please try again...\n");
            count=0;
        }
    }

}

int dice()
{
    char zarat;
    char zar;
    srand(time(NULL));
    scanf("%c",&zarat);
    if(zarat==10)//I equated 'zarat' as 'enter' corresponds to value 10 in ascii code
    {
        zar=1+rand()%6;//I got the mod with 6 so that the random values are between 1-6
    }
    return zar;
}
int startGame(int a,int b)
{
    if(a>b)
    {
        return 1;
    }
    else if(b>a)
    {
        return 2;
    }
    else if(a==b)
    {
        return 3;
    }
}
int game(char map[15][30],int temp,int pemp)
{
//i played players in this function
    int penalty=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int k=0;
    int m=0;

    char y,t;
    b=1+temp;
    if(b<28)
    {
        if(b==14)
        { //I got him reduced by 2 when he was punished
            b=b-2;
            t= map[1][b] ='1';
            return 0;
        }
        else
            t= map[1][b] ='1';

    }
    else d=1+temp-27;//I subtract 27 from the total value so that it moves 27 digits and then goes down so that the new values are cleared.I applied the subtraction method in the next steps.
    if(d<13)
    {
        if(d==7)
        {
            d=d-2;

            t= map[d][28]='1';
            map[0][28]='.';

            return 0;

        }

        else
            t= map[d][28]='1';
        map[0][28]='.';

    }
    else f=1+temp-27-13;
    if(b>=27 && d>=13 && (28-f)>=1)

    {
        if((28-f)==14)
        {
            f=f-2;
            t= map[13][28-f]='1';
            return 0;
        }
        else t= map[13][28-f]='1';


    }
    else m=1+temp-27-13-27;
    if(b>=27 && d>=13 && (28-f)<1 && (13-m)>2)
    {

        t=map[13-m][1]='1';

    }
    else if((13-m)<=2)

    {
        return 1;


    }



    a=3+pemp;
    if(a<26)
    {

        if(a==10 || a==18)
        {
            a=a-2;
            y= map[3][a] ='2';

            return 3;

        }
        else
            y= map[3][a] ='2';

    }

    else c=3+pemp-23;
    if(c<11)
    {

        if(c==5 || c==10)
        {
            c=c-2;
            y= map[c][26]='2';
            map[0][26]='.';

            return 3;
        }

        else
            y= map[c][26]='2';
        map[0][26]='.';

    }

    else e=3+pemp-23-11;
    if(a>=25 && c>=11 && (26-e)>=3)
    {

        if((26-e)==10 || (26-e)==18)
        {
            e=e-2;
            y= map[11][26-e]='2';

            return 3;
        }

        else
            y= map[11][26-e]='2';

    }
    k=3+pemp-23-11-23;

    if(a>=25 && c>=11 && (26-e)<3 && (11-k)>3)
    {
        y= map[11-k][3]='2';//I kept my column equal and changed my row count.


    }
    else if((11-k)<=3)
    {
        return 2;


    }
}

void printMap(int temp,int pemp)
{
    char map[15][30];
    int i,j;
    //I have looped the symbols to be printed to the function.
    for(i=0; i<15; i++)
    {
        for(j=0; j<30; j++)
        {
            map[i][j]=' ';
        }
    }
    for(i=0; i<15; i++)
    {
        for(j=0; j<30; j++)
        {
            if(j==0 || j==29)
            {
                if(i>0 && i<14)
                {
                    map[i][j]=':';
                }

            }
            if(i==0 || i==14 )
            {
                map[i][j]='.';
            }
            if(j==2 || j==27)
            {
                if(i>2 && i<12)
                {
                    map[i][j]=':';
                }

            }
            if(j>1 && j<28)
            {
                if(i==2 || i==12)
                {
                    map[i][j]='.';
                }
            }
            if(j==4 || j==25)
            {
                if(i>4 && i<10)
                {
                    map[i][j]=':';
                }

            }
            if(j>3 && j<26)
            {
                if(i==4 || i==10)
                {
                    map[i][j]='.';
                }
            }

        }
    }

    char y,t;
    int x=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int k=0;
    int m=0;
//I had defined and placed the array in the previous function. The purpose of my repeat here is because the players recognize their colors.

    b=1+temp;
    if(b<28)
    {
        if(b==14)
        {
            b=b-2;
            t= map[1][b] ='1';

        }
        else
            t= map[1][b] ='1';
    }
    else d=1+temp-27;
    if(d<13)
    {
        if(d==7)
        {
            d=d-2;
            t= map[d][28]='1';
            map[0][28]='.';


        }
        else
            t= map[d][28]='1';
        map[0][28]='.';
    }
    else f=1+temp-27-13;
    if(b>=27 && d>=13 && (28-f)>=1)
    {
        if((28-f)==14)
        {
            f=f-2;
            t= map[13][28-f]='1';

        }
        else t= map[13][28-f]='1';
    }
    else m=1+temp-27-13-27;
    if(b>=27 && d>=13 && (28-f)<1 && (13-m)>=2)
    {
        t=map[13-m][1]='1';
    }



    a=3+pemp;
    if(a<26)
    {
        if(a==10 || a==18)
        {
            a=a-2;
            y= map[3][a] ='2';

        }
        else
            y= map[3][a] ='2';
    }
    else c=3+pemp-23;
    if(c<11)
    {
        if(c==5 || c==10)
        {
            c=c-2;
            y= map[c][26]='2';
            map[0][26]='.';

        }
        else
            y= map[c][26]='2';
        map[0][26]='.';
    }
    else e=3+pemp-23-11;
    if(a>=25 && c>=11 && (26-e)>=3)
    {
        if((26-e)==10 || (26-e)==18)
        {
            e=e-2;
            y= map[11][26-e]='2';

        }
        else
            y= map[11][26-e]='2';

    }
    k=3+pemp-23-11-23;

    if(a>=25 && c>=11 && (26-e)<3 && (11-k)>=3)
    {
        y= map[11-k][3]='2';
    }
    game(map,temp,pemp);
    x=game(map,temp,pemp);
    map[1][14]='X';
    map[7][28]='X';
    map[13][14]='X';
    map[3][10]='X';
    map[3][18]='X';
    map[5][26]='X';
    map[10][26]='X';
    map[11][10]='X';
    map[11][18]='X';
    map[2][1]='_';
    map[4][3]='_';

    for(i=0; i<15; i++)
    {
        for(j=0; j<30; j++)
        {
            if(i==2 && j==1 )
            {
                printf("\033[0;32m");
                printf("%c",map[i][j]);
                printf("\033[0m");
            }
            else if(i==4 && j==3 )
            {
                printf("\033[0;32m");
                printf("%c",map[i][j]);
                printf("\033[0m");
            }
            else if(map[i][j]==y)
            {
                printf("\033[0;34m");
                printf("%c",map[i][j]);
                printf("\033[0m");
            }
            else if(map[i][j]==t)
            {
                printf("\033[0;33m");
                printf("%c",map[i][j]);
                printf("\033[0m");
            }
            else if((i==1 && j==14)||(i==7 && j==28)||(i==13 && j==14)||(i==3 && j==10)||(i==3 && j==18)||(i==5 && j==26)||(i==11 && j==10)||(i==11 && j==18)||(i==10 && j==26))
            {
                printf("\033[0;31m");
                printf("%c",map[i][j]);
                printf("\033[0m");
            }
            else printf("%c",map[i][j] );


        }
        printf("\n");
    }

}

