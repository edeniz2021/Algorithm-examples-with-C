#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
    int xs;
    int currentlen=1;
    int *seq;
    int seqlen;
    int looplen;
    int digit=1;
    int i ;
    int h[9];
    printf("Please enter the sequence length: ");
    scanf("%d",&seqlen);
    looplen=seqlen/2;//looplen can be at most half of the array
    int *loop=(int *)calloc(seqlen/2,sizeof(int));//I also reserved memory for the loop.
    printf("Please enter the first element: ");
    scanf("%d",&xs);
    check_loop_iterative(&generate_sequence,xs,seqlen,loop,&looplen);

    if(looplen>=2)//I put the condition that the length can be at least 2. I told him to print it if he met the condition.
    {
        printf("Loop : {");
        for (int i=0; loop[i]!='\0'; i++)
        {
            printf("%d ",loop[i]);
            if(i+1!=looplen)
            {
                printf(",");
            }
        }
        printf("}\n");
    }

    hist_of_firstdigits(&generate_sequence,xs,seqlen,h,digit) ;
    printf("\n\nHistogram of the sequence : { ");//I printed the array I created in the function here.
    for (i = 1; i<10; i++)
    {
        printf(" %d ", h[i]);
        if(i+1!=10)
        {
            printf(",");
        }
    }
    printf(" }\n");

}

