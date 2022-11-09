#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int has_loop(int *arr, int n, int looplen, int *ls, int *le);
void generate_sequence (int xs, int currentlen, int seqlen, int *seq);
void check_loop_iterative(void (*f)(), int xs, int seqlen, int *loop,int *looplen)
{
    int *seq;
    int ls[1],le[1];
    seq= (int *)malloc(seqlen*sizeof(int));
    int currentlen=0;
    int sayac=0;
    int temp;
    f(xs,currentlen,seqlen,seq);
    int i;

    if(*(looplen)>=2)//For the recursive function, I set the condition that the looplen should be greater than two.
    {
        static int flag=0;//i used 'static int' to print it once
        flag++;
        if(flag==1)
        {
            printf("\nSequence= {");
            for(i=0; i<seqlen; i++)
            {
                printf("%d ",*(seq+i));
                if(i+1!=seqlen)
                {
                    printf(",");
                }
            }
            printf("}\n\n");
        }

        *(looplen);

        temp=has_loop(seq,seqlen,*(looplen),ls,le);

        if(temp==0)
        {
            printf("Checking if there is a loop of length %d... \n",*(looplen));
            (*looplen)-=1;//I reduced the loop and called the function again, I used recursive.
            check_loop_iterative(&generate_sequence,xs,seqlen,loop,looplen);

            for (int i=0; i<*(looplen); i++)
            {
                loop[i]=seq[seqlen-*looplen+i];//if loop exists i wanted it to equate to loop array.

            }

        }

    }
    else
    {

        printf("\nNo loop found \n");

    }

    if(*(looplen)>=2)
    {
        static int fin=0;
        fin++;
        if(fin==1)
        {
            printf("\nLoop detected with a length of %d. \n",*(looplen));
            printf("The indexes of the loop's first occurance : %d (first digit) ,  %d (last digit) \n",ls[0],le[0]);
        }
    }

}



int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
    int sum=0;
    for(int i=0; i<looplen; i++)
    {
        if(arr[n-2*looplen+i]!=arr[n-looplen+i])//I had it checked for any equality, loop.
        {
            sum++;
        }
    }
    if(sum==0)
    { //I found the first and last elements of the array
        *ls=n-2*looplen;
        *le=n-2*looplen+looplen-1;
        return 1;
    }
    else return 0;
}
void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit)
{
    int *(seq);
    int currentlen=0;
    int i,j;
    seq= (int *)malloc(seqlen*sizeof(int));
    f(xs,currentlen,seqlen,seq);

    if(digit<10)
   { 
         h[digit]=0;
        for(i=0; i<seqlen; i++)
        {
            if(*(seq+i)>=10)//I wanted it to find the first digits of the numbers in the seq array.
            {
                do
                {
                    *(seq+i)=*(seq+i)/10;
                }
                while(*(seq+i)>10);
                *(seq+i)=*(seq+i)%10;
            }
            else *(seq+i)=*(seq+i);
        }

        for(j = 0; j < seqlen; j++)
        {
            if ( seq[j] == digit)
            {
                h[digit]++;//how many there are will increase the number here
            }
        }

        hist_of_firstdigits(&generate_sequence,xs,seqlen,h,digit+1) ;
    //I made it recursive by increasing the digit by one. I put this condition because the number will be less than 10.
    }


}
void generate_sequence (int xs, int currentlen, int seqlen, int *seq)
{
    *(seq)=xs;
    if(currentlen==seqlen-1)//I created an array according to the collatz assumption.
    {
        return;
    }
    if(currentlen!=seqlen)//The loop will continue until currentlen syncs with seqlen
    {
        if(seq[currentlen]%2==0)//I set separate conditions for odd and even numbers.
        {
            seq[currentlen+1]=seq[currentlen]/2;
        }
        else if(seq[currentlen]%2!=0)
        {
            seq[currentlen+1]=(seq[currentlen]*3)+1;
        }
        generate_sequence (xs,currentlen+1,seqlen,seq);//I made it a recursive function by increasing the currentlen.
    }
}

