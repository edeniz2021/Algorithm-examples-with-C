#include <stdio.h>
#include <math.h>
void temp_txt_file(int v1, int v2, int v3, int length);
void print_file();
void write_file (int number);
void sort_file ();
void write_file(int number){
   FILE *fp;
fp=fopen("results.txt","a++");
    fprintf(fp,"%d ",number);

}
void temp_txt_file(int v1, int v2, int v3, int length){
    FILE *fp;
    fp = fopen("temporary.txt","a");
    if(length == 3) fprintf(fp,"%d %d %d ", v1,v2,v3);
    else if(length == 2) fprintf(fp,"%d %d ", v1,v2);
    else if(length == 1) fprintf(fp,"%d ", v1);
    fclose(fp);
    /*here i opened additional function to print to temporary file*/
}

void sort_file(){
    int temp,min1 = 0,min2 = 0,min3 = 0,maximum = 0;
    int length = 0;
    int value;
    int counter = 0,counterTo = 0;
    FILE *fp;
    fp = fopen("results.txt","r");

    while(!feof(fp)){
       fscanf(fp,"%d ", &value);
       if(value > maximum)maximum = value;
       length++;
    }
    fclose(fp);
    min1 = maximum;
    min2 = maximum;
    min3 = maximum;
    fp = fopen("results.txt","r");

    while(!feof(fp)){
       fscanf(fp,"%d ", &value);
       if(value < min1){
          min3 = min2;
          min2 = min1;
          min1 = value;
       }else if(value < min2){
          min3 = min2;
          min2 = value;
       }else if(value < min3){
          min3 = value;
       }
    }
    fclose(fp);

    if(length>=3){
       temp_txt_file(min1,min2,min3,3);
       length-=3;
       counter=counter+3;
    }
    else if(length == 2){
       temp_txt_file(min1,min2,min3,2);
       length-=2;
    }
    else if(length == 1){
       temp_txt_file(min1,min2,min3,1);
       length-=1;
       /*I reduced the total length by three by three*/
    }

    fp = fopen("results.txt","r");
    FILE *fp1;
    fp1 = fopen("temporary.txt","a");
    int a = 0,b = 0,c = 0;
    while(!feof(fp)){
       fscanf(fp,"%d ",&value);
       if(value == min1 && a == 0) a++;
       else if(value == min2 && b == 0) b++;
       else if(value == min3 && c == 0) c++;
       else{
          fprintf(fp1,"%d ",value);
       }
    }
    fclose(fp1);
    fclose(fp);

    fp1 = fopen("temporary.txt","r");
    fp = fopen("results.txt","w");
    while(!feof(fp1)){
       fscanf(fp1,"%d ",&value);
       fprintf(fp,"%d ",value);
    }
    fclose(fp1);
    fclose(fp);

    while(length > 0 ){
    counterTo = 0;
    min1 = maximum;
    min2 = maximum;
    min3 = maximum;

    fp = fopen("results.txt","r");
    while(counterTo < counter) {
    fscanf(fp,"%d ",&value);
    counterTo++;
    }

    while(!feof(fp)){
       fscanf(fp,"%d ", &value);
       if(value < min1){
          min3 = min2;
          min2 = min1;
          min1 = value;
       }else if(value < min2){
          min3 = min2;
          min2 = value;
       }else if(value < min3){
          min3 = value;
       }
    }

    fclose(fp);

    fp1 = fopen("temporary.txt","w");
    fp = fopen("results.txt","r");
    counterTo = 0;
    while(counterTo < counter){
       fscanf(fp,"%d ", &value);
       fprintf(fp1,"%d ", value);
       counterTo++;
    }
    fclose(fp);
    fclose(fp1);
    if(length>=3){
       temp_txt_file(min1,min2,min3,3);
       length-=3;
    }
    else if(length == 2){
       temp_txt_file(min1,min2,min3,2);
       length-=2;
    }
    else if(length == 1){
       temp_txt_file(min1,min2,min3,1);
       length-=1;
    }


    fp = fopen("results.txt","r");
    FILE *fp1;
    fp1 = fopen("temporary.txt","a");
    counterTo = 0;
    while(counterTo < counter){
       fscanf(fp,"%d ",&value);
       counterTo++;
    }
    a = 0;
    b = 0;
    c = 0;
    while(!feof(fp)){
       fscanf(fp,"%d ",&value);
       if(value == min1 && a == 0) a++;
       else if(value == min2 && b == 0) b++;
       else if(value == min3 && c == 0) c++;
       else{
          fprintf(fp1,"%d ",value);
       }
    }
    fclose(fp1);
    fclose(fp);

    fp1 = fopen("temporary.txt","r");
    fp = fopen("results.txt","w");
    while(!feof(fp1)){
       fscanf(fp1,"%d ",&value);
       fprintf(fp,"%d ",value);
    }
    fclose(fp1);
    fclose(fp);
    counter=counter+3;
    }

    printf("Sorting is complete.\n");
    printf("Result :\n");

    print_file();
}


void print_file (){
FILE *fp;
fp=fopen("results.txt","r");
int value;

while(!feof(fp)) {
    fscanf(fp,"%d ",&value);
    printf("%d ",value);
}
}
int isprime (int a){
   int b,c;

   int say=0;
    b=sqrt(a);
    for(int i=2;i<=b;i++){
        if(a%i==0){
            say++;
        }
        }if(say==1){
                return 0;
            }else if(say < 1){
            return 1;
            }
            /*I returned 1 and 0 if the number satisfies or does not meet the sqrt requirement*/

   }
int sum (int n1, int n2, int flag){
     int sum=0;
     int kucuk;
     int n3;

     if(n2<n1){
        kucuk=n2;
        n2=n1;
        n1=kucuk;
     }n3= n1+1;
     /*I defined a value as n3 to not include the number we started with*/
   switch(flag){
   case 0:
       for(n3;n3<n2;n3++){
        if(n3%2==0){
            sum+=n3;
            }
            }
            return sum;
   case 1:
       for(n3;n3<n2;n3++){
        if(n3%2!=0){
            sum+=n3;
            }
            }
            return sum;
        default:
        break;


   }}

  int    multi (int n1, int n2, int flag){
int multi;
multi=1;
int n3;
     int kucuk;
     if(n2<n1){
        kucuk=n2;
        n2=n1;
        n1=kucuk;
     } n3=n1+1;
   switch(flag){
   case 0:
      for(n3;n3<n2;n3++){
        if(n3%2==0){
            multi*=n3;
            }
            }
            return multi;
        break;

   case 1:
       for(n3;n3<n2;n3++){
        if(n3%2!=0){
            multi*=n3;
            }
            }
            return multi;
            break;
     default:
     break;

   }
   }

int main()
{  FILE *fp;
      int N;
        int say=0;
   fp=fopen("results.txt","a++");
    printf("Select operation\n");
   int select,operation,flag,result,n1,n2,n3;
   printf("1- Calculate sum/multiplication between two numbers\n");
   printf("2-Calculate prime numbers\n");
   printf("3-Show number sequence file\n");
   printf("4-Short number sequence file\n");
   printf("-----------------------------\n");
   scanf("%d",&select);
   printf("\n");
   switch(select){
       case 1:
       printf("Select operation\n");
       printf("Please operation '0' sum,'1' for multiplication.");scanf("%d",&operation);


   switch(operation){
       case 0:
           printf("Please number enter '0' to work even numbers, '1' to work on odd numbers.");
       scanf("%d",&flag);
       switch(flag){
           case 0:
            printf("please enter two different number\n");
        printf("1.sayiyi gir: ");scanf("%d",&n1);printf("\n");
   printf("2.sayiyi gir: ");scanf("%d",&n2);
   n3=n1+1;
           result=sum(n1,n2,flag);
           for(n3;n3<(n2-2);n3++){
               if(n3%2==0){
           if(n3!=(n2-1)){
                printf(" %d +",n3);
            }}}if((n2-1)%2==0){
            printf(" %d = %d\n",n2-1,result);}
            else printf(" %d = %d\n",n2-2,result);
             write_file(result);
             printf("The results is written to the results.text file.\n");
           break;
           case 1:
          printf("please enter two different number\n");
        printf("1.sayiyi gir: ");scanf("%d",&n1);printf("\n");
   printf("2.sayiyi gir: ");scanf("%d",&n2);
   n3=n1+1;
           result=sum(n1,n2,flag);
           for(n3;n3<(n2-2);n3++){
               if(n3%2!=0){
           if(n3!=(n2-1)){
                printf(" %d +",n3);
            }}}if((n2-1)%2!=0){
            printf(" %d = %d\n",n2-1,result);}
            else printf(" %d = %d\n",n2-2,result);
            printf("The results is written to the results.text file.\n");
               write_file(result);
           break;
           default:
               printf("You entered incorrectly.");
           break;
       }
       break;
       case 1:
           printf("Please number enter '0' to work even numbers, '1' to work on odd numbers.");
       scanf("%d",&flag);
        switch(flag){
           case 0:
           printf("please enter two different number\n");
        printf("1.sayiyi gir: ");scanf("%d",&n1);printf("\n");
   printf("2.sayiyi gir: ");scanf("%d",&n2);
   n3=n1+1;
           result=multi(n1,n2,flag);
           for(n3;n3<(n2-2);n3++){
               if(n3%2==0){
           if(n3!=(n2-1)){
                printf(" %d *",n3);
            }}}if((n2-1)%2==0){
            printf(" %d = %d\n",n2-1,result);}
            else printf(" %d = %d\n",n2-2,result);
            printf("The results is written to the results.text file.\n");
              write_file(result);
           break;
           case 1:
          printf("please enter two different number\n");
        printf("1.sayiyi gir: ");scanf("%d",&n1);printf("\n");
   printf("2.sayiyi gir: ");scanf("%d",&n2);
   n3=n1+1;
           result=multi(n1,n2,flag);

           for(n3;n3<(n2-2);n3++){
               if(n3%2!=0){
           if(n3!=(n2-1)){
                printf(" %d *",n3);
            }}}if((n2-1)%2!=0){
            printf(" %d = %d\n",n2-1,result);}
            else printf(" %d = %d\n",n2-2,result);
            printf("The results is written to the results.text file.\n");
               write_file(result);
           break;
           default:
               printf("You entered incorrectly.");
       break;

   }       default: printf("You entered incorrectly.");
break;

   }break;

    case 2:

        printf("Please enter an integer: "); scanf("%d",&N);
        for(int i=2;i<=N;i++){
            result=isprime(i);
            if(result==1){
                printf("%d is a prime number.\n",i);
            }else if(result==0){
                for(int j=2;j<=N;j++){
                    if(i%j==0){
                        say++;
                        if(say==1){
                            printf("%d is not a prime number,it is dividible by %d. \n",i,j);
                        }
                    }
                }
            }say=0;
        }
    break;
    case 3:
       print_file();
    break;
    case 4:
   sort_file();

    break;
    default:

    break;

   }
}
