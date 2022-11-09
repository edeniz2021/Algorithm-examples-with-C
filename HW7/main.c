#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void reverse_printing(char word[10],int n) //I reversed the words
{
    int i,d;
    char b[10];
    for (i = n - 1, d = 0; i>= 0; i--, d++)
    {
        b[d] = word[i];
    }

    for (i = 0; i < n; i++)
    {
        word[i] = b[i];
    }
}
void selection(int sec,int n,int x,int y,char table[][15],char word[][10])
{ int i,j; //I placed it according to the randomly chosen layout

for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(sec==1)
                table[x+i][y+i]=word[0][i];//I placed the word diagonally

            else if(sec==2)
                table[x][y+i]=word[0][i]; //I placed vertical

            else if(sec==3)
                table[x+i][y]=word[0][i];//I placed horizontal

            else if(sec==4)
            {
                reverse_printing(word[10],n);//I turned it upside down and placed the word diagonally
                table[x+i][y+i]=word[0][i];
            }

            else if(sec==5)
            {
                reverse_printing(word[10],n);//I turned it upside down and placed the word vertical
                table[x][y+i]=word[0][i];
            }

            else if(sec==6)
            {
                reverse_printing(word[10],n);//I turned it upside down and placed the word horizontal
                table[x+i][y]=word[0][i];
            }
            else if(sec==7)
            {
                table[x][y-i]=word[0][i];//I placed from left to right
            }

            else if(sec==8)
            {
                reverse_printing(word[10],n);//I turned it upside down and placed the word from left to right
                table[x][y-i]=word[0][i];
            }
        }
    }
    }
    void change(int n,int xa,int ya,int sec,char table[][15])
    { int i,j;
     for(i=0; i<n; i++) //printing X instead of word when known correctly
            {
                for(j=0; j<n; j++)
                {
                    if(sec==1 || sec==4)
                    {
                        table[xa+i][ya+i]='x';
                    }
                    else if(sec==2 || sec==5)
                    {
                        table[xa][ya+i]='x';
                    }
                    else if(sec==3 || sec==6)
                    {
                        table[xa+i][ya]='x';
                    }
                    else if(sec==7 || sec==8)
                    {
                        table[xa][ya-i]='x';
                    }
                }
            }
            }
      int  sayac(int h,int sec,int x,int y,int coun,char table[][15])
      { int j;
       for(j=0; j<h; j++) //I have it checked so that the words I will place do not overlap. If it is a space, I say place, if it is not a space, I give the place command.
        {
            if(sec==1 || sec==4)
            {
                if(table[x+j][y+j]==' ')
                    coun++;
                else
                    coun=0;
            }
            if(sec==2 || sec==5)
            {
                if(table[x][y+j]==' ')
                    coun++;
                else
                    coun=0;
            }
            if(sec==3 || sec==6)
            {
                if(table[x+j][y]==' ')
                    coun++;
                else
                    coun=0;
            }
            if(sec==7 || sec==8)
            {
                if(table[x][y-j]==' ')
                    coun++;
                else
                    coun=0;
            }


        } return coun;}
int main()
{
    srand(time(NULL));
char kelime1[7],kelime2[7],kelime3[7],kelime4[7],kelime5[7],kelime6[7],kelime7[7];
    int sec1,sec2,sec3,sec4,sec5,sec6,sec7;
    char table[15][15];
    int i,j;
    int x,y;
    for(i=0; i<15; i++)
    {
        for(j=0; j<15; j++)
        {
            table[i][j]=' ';
        }
    }

    FILE *fp;
    fp=fopen("wordlist.txt","r");
    char veri[5000][20];
    if (fp == NULL)
    {
        printf("\nYour file could not be opened!\n");

    }
    else
    {
        while (!feof(fp))
        {
            for (i = 0; i < 50; i++ )
            {
                fscanf(fp, "%s", veri[i]);//I am reading data line by line from the file and throwing it into the array.
            }
        }
        fclose(fp);
    }
    int rast,rast1,rast2,rast3,rast4,rast5,rast6;



    rast=rand()%50;
    strcpy(kelime1,veri[rast]);//I equated the array where I hold the data I got from the file to the word array.
    rast1=rand()%50;//I pick random number and call that index in array.

    while(rast==rast1)
    {
        rast1=rand()%50;//I checked the case of randomly selected numbers not being the same.
    }
    strcpy(kelime2,veri[rast1]);

    rast2=rand()%50;

    while(rast==rast2 || rast1==rast2)
    {
        rast2=rand()%50;//I checked the case of randomly selected numbers not being the same.
    }
    strcpy(kelime3,veri[rast2]);
    rast3=rand()%50;
    while(rast==rast3 || rast1==rast3 || rast2==rast3)
    {
        rast3=rand()%50;//I checked the case of randomly selected numbers not being the same.
    }
    strcpy(kelime4,veri[rast3]);

    rast4=rand()%50;
    while(rast==rast4 || rast1==rast4 || rast2==rast4 || rast3==rast4)
    {
        rast4=rand()%50;//I checked the case of randomly selected numbers not being the same.
    }
    strcpy(kelime5,veri[rast4]);

    rast5=rand()%50;
    while(rast==rast5 || rast1==rast5 || rast2==rast5 || rast3==rast5 || rast4==rast5)
    {
        rast5=rand()%50;//I checked the case of randomly selected numbers not being the same.
    }
    strcpy(kelime6,veri[rast5]);//I equated the array where I hold the data I got from the file to the word array.

    rast6=rand()%50;
    while(rast==rast6 || rast1==rast6 || rast2==rast6 || rast3==rast6 || rast4==rast6 || rast5==rast6)
    {
        rast6=rand()%50;//I checked the case of randomly selected numbers not being the same.
    }
    strcpy(kelime7,veri[rast6]);


    char word1[10][10],word2[10][10],word3[10][10],word4[10][10],word5[10][10],word6[10][10],word7[10][10];
    int n;
    n=strlen(kelime1);
    memcpy(word1,kelime1,n);
    sec7=rand()%8;
    int w;
    if(sec7==1 || sec7==2 || sec7==3 || sec7==4 || sec7==5 || sec7==6)
    {
        w=15-n;//I subtracted the word length from the number of columns so that it doesn't overflow the row.
        x=rand()%w;
        y=rand()%w;
    }
    else if(sec7==7 || sec7==8)
    {
        while(n<15-y)
        {
            x=rand()%15;
            y=rand()%15;
        }
    }
selection(sec7,n,x,y,table,word1);
 printf("1. coordinates and word : %d , %d , %s\n", x,y,kelime1);
    int c,x1,y1,coun;
    c=strlen(kelime2);
    memcpy(word2,kelime2,c);
    coun=0;
    int control=0;
    while(control!=c)
    {
        coun=0;
        int m;
        sec6=rand()%8;
        if(sec6==1 || sec6==2 || sec6==3 || sec6==4 || sec6==5 || sec6==6)
        {
            m=15-c;//I subtracted the word length from the number of columns so that it doesn't overflow the row.
            x1=rand()%m;
            y1=rand()%m;
        }
        else if(sec6==7 || sec6==8)
        {

            while(c<15-y1)
            {
                x1=rand()%15;
                y1=rand()%15;
            }
        }
        control=sayac(c,sec6,x1,y1,coun,table);

    }
    selection(sec6,c,x1,y1,table,word2);
 printf("2. coordinates and word  : %d , %d , %s\n", x1,y1,kelime2);
    int d,x2,y2,count;
    d=strlen(kelime3);
    memcpy(word3,kelime3,d);
    count=0;
    int control2=0;
    while(control2!=d)
    {
        count=0;
        int k;
        sec5=rand()%8;
        if(sec5==1 || sec5==2 || sec5==3 || sec5==4 || sec5==5 || sec5==6)
        {
            k=15-c;
            x2=rand()%k;
            y2=rand()%k;
        }
        else if(sec5==7 || sec5==8)
        {
            while(d<15-y2)
            {
                x2=rand()%15;
                y2=rand()%15;
            }
        }
control2=sayac(d,sec5,x2,y2,count,table);

    }
selection(sec5,d,x2,y2,table,word3);
 printf("3.coordinates and word  : %d , %d , %s\n", x2,y2,kelime3);
    int e,x3,y3,coun1;
    e=strlen(kelime4);
    memcpy(word4,kelime4,e);

    coun1=0;
    int control3=0;
    while(control3!=e)
    {
        coun1=0;
        int z;
        sec4=rand()%8;
        if(sec4==1 || sec4==2 || sec4==3 || sec4==4 || sec4==5 || sec4==6)
        {
            z=15-e;//I subtracted the word length from the number of columns so that it doesn't overflow the row.
            x3=rand()%z;
            y3=rand()%z;
        }
        else if(sec4==7 || sec4==8)
        {

            while(e<15-y3)
            {
                x3=rand()%15;
                y3=rand()%15;
            }
        }
control3=sayac(e,sec4,x3,y3,coun1,table);

    }
    selection(sec4,e,x3,y3,table,word4);
 printf("4. coordinates and word  : %d , %d , %s\n", x3,y3,kelime4);
    int f,x4,y4,coun2;
    f=strlen(kelime5);
    memcpy(word5,kelime5,f);
    coun2=0;
    int control4=0;
    while(control4!=f)
    {
        coun2=0;
        int p;
        sec3=rand()%8;
        if(sec3==1 || sec3==2 || sec3==3 || sec3==4 || sec3==5 || sec3==6)
        {
            p=15-f;//I subtracted the word length from the number of columns so that it doesn't overflow the row.
            x4=rand()%p;
            y4=rand()%p;
        }
        else if(sec3==7 || sec3==8)
        {
            while(f<15-y4)
            {
                x4=rand()%15;
                y4=rand()%15;
            }
        }

control4=sayac(f,sec3,x4,y4,coun2,table);

    }
    selection(sec3,f,x4,y4,table,word5);
 printf("5. coordinates and word  : %d , %d , %s\n", x4,y4,kelime5);
    int g,x5,y5,coun3;
    g=strlen(kelime6);
    memcpy(word6,kelime6,g);
    coun3=0;
    int control5=0;
    while(control5!=g)
    {
        coun3=0;
        int t;
        sec2=rand()%8;
        if(sec2==1 || sec2==2 || sec2==3 || sec2==4 || sec2==5 || sec2==6)
        {
            t=15-g;//I subtracted the word length from the number of columns so that it doesn't overflow the row.
            x5=rand()%t;
            y5=rand()%t;
        }
        else if(sec2==7 || sec2==8)
        {
            while(g<15-y5)
            {
                x5=rand()%15;
                y5=rand()%15;
            }
        }
control5=sayac(g,sec2,x5,y5,coun3,table);
    }
 selection(sec2,g,x5,y5,table,word6);
 printf("6. coordinates and word  : %d , %d , %s\n", x5,y5,kelime6);
    int h,x6,y6,coun4;
    h=strlen(kelime7);
    memcpy(word7,kelime7,h);
    coun4=0;
   int  control1=0;
    while(control1!=h)
    {
        coun4=0;
        int s;
        sec1=rand()%8;
        if(sec1==1 || sec1==2 || sec1==3 || sec1==4 || sec1==5 || sec1==6)
        {
            s=15-h;//I subtracted the word length from the number of columns so that it doesn't overflow the row.
            x6=rand()%s;
            y6=rand()%s;
        }
        else if(sec1==7 || sec1==8)
        {
            while(h<15-y6)
            {
                x6=rand()%15;
                y6=rand()%15;
            }
        }
  control1=sayac(h,sec1,x6,y6,coun4,table);
    }
   selection(sec1,h,x6,y6,table,word7);
 printf("7. coordinates and word : %d , %d , %s\n", x6,y6,kelime7);
    int ya;
    char worda[10][10];
    int sayac=3;
    int true=0;
    int toplam=0;
    int kontrol=0;
    int bitti=0;
    do
    { printf("\n");
        kontrol =0;
        for(i=0; i<15; i++)//I printed the map.
        {
            for(j=0; j<15; j++)
            {
                if(table[i][j]==' ')
                {
                  table[i][j]='a'+rand()%26;//I wanted it to give random letters to places with spaces
                }
                printf("%2c",table[i][j]);
            }
            printf("\n");
        }
        char str[10];
        int xa;
        printf("\n Enter coordinates and word:");
        scanf("%s",str);

        if(strcmp(str,":q")==0)//I tell it to terminate the program when the ':q' command is entered.
        {
        bitti=1;  printf("\nYour total points:  %d\n",toplam); return 0; }  else

        bitti=0;xa=atoi(str);//I convert the numbers I get as 'char' to integer
        scanf("%d %s",&ya,worda[10]);

        int ret,ret1,ret2,ret3,ret4,ret5,ret6;
        ret=strncmp(worda[10],veri[rast],n);//I'm checking with strncmp
        ret1=strncmp(worda[10],veri[rast1],c);
        ret2=strncmp(worda[10],veri[rast2],d);
        ret3=strncmp(worda[10],veri[rast3],e);
        ret4=strncmp(worda[10],veri[rast4],f);
        ret5=strncmp(worda[10],veri[rast5],g);
        ret6=strncmp(worda[10],veri[rast6],h);
        if(xa==x && y==ya && ret==0)//It compares the coordinates and words for each word, and gives points if correct.
        {
            true++;
            toplam=toplam+2;
            printf("Founded! You got 2 points. Your total points: %d\n",toplam);
            kontrol=0;
           change(n,xa,ya,sec7,table);//command replace with 'x' if true
        }
        else if(xa==x1 && y1==ya && ret1==0)
        {
            true++;
            toplam=toplam+2;
            printf("Founded! You got 2 points. Your total points: %d\n",toplam);
            kontrol=0;
            change(c,xa,ya,sec6,table);//command replace with 'x' if true
        }
        else if(xa==x2 && y2==ya && ret2==0)
        {
            true++;
            toplam=toplam+2;
            printf("Founded! You got 2 points. Your total points: %d\n",toplam);
            kontrol=0;
            change(d,xa,ya,sec5,table); //command replace with 'x' if true
        }
        else if(xa==x3 && y3==ya && ret3==0)
        {
            true++;
            toplam=toplam+2;
            printf("Founded! You got 2 points. Your total points: %d\n",toplam);
            kontrol=0;
            change(e,xa,ya,sec4,table);  //command replace with 'x' if true
        }
        else if(xa==x4 && y4==ya && ret4==0)
        {
            true++;
            toplam=toplam+2;
            printf("Founded! You got 2 points. Your total points: %d\n",toplam);
            kontrol=0;
            change(f,xa,ya,sec3,table); //command replace with 'x' if true
        }
        else if(xa==x5 && y5==ya && ret5==0)
        {
            true++;
            toplam=toplam+2;
            printf("Founded! You got 2 points. Your total points:%d\n",toplam);
            kontrol=0;
            change(g,xa,ya,sec2,table); //command replace with 'x' if true
        }
        else if(xa==x6 && y6==ya && ret6==0)
        {
            true++;
            toplam=toplam+2;
            printf("Founded! You got 2 points. Your total points:%d\n",toplam);
            kontrol=0;
           change(h,xa,ya,sec1,table); //command replace with 'x' if true
        }
        else
        {
            sayac--;//It gives 3 wrongs and decreases for every wrong.
            kontrol=1;
        }
        if(true==7)
        {
            printf("Congrulations. Your total points:  %d",toplam);
        }
        if(sayac!=3 && kontrol==1 && bitti==0)
        {
            printf("Wrong choice! You have only %d lefts.\n",sayac);
            if(sayac==0)
            {
            printf("\nYour total points:  %d\n",toplam);}
        }
    }
    while(sayac!=0 && true!=7 && bitti!=1);
}






