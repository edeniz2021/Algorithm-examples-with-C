#include <stdio.h>
int main(){
    int num,a,b,c,i,j;
do{
    printf("Select an operation...\n");
    printf("1 -> Enter the coefficients.\n");
    printf("2 -> Draw the graph.\n");
    printf("3 -> Print the graph into a.txt file.\n");
    printf("4 -> Exit.\n");
    printf("\n");
    printf("Choice: "); scanf("%d",&num);
    printf("\n");
    FILE *fp;
        fp=fopen("coefficients.txt","w");
    switch(num){
    case 1:
        printf("Please enter the coefficient for the following equation x= a*(y*y)+b*y+c \n\n" );
        printf("a: ");scanf("%d",&a);
        printf("b: ");scanf("%d",&b);
        printf("c: ");scanf("%d",&c); printf("\n");
        fprintf(fp,"%d\n",a);
        fprintf(fp,"%d\n",b);
        fprintf(fp,"%d\n",c);
        fclose(fp);
        printf("coefficients.txt file has been created.\n\n");

    break;
    case 2:
        fp=fopen("coefficients.txt","r");
        fscanf(fp,"%d",&a);
        fscanf(fp,"\n %d",&b);
        fscanf(fp,"\n\n %d",&c);
        fclose(fp);
        printf("Coefficients file has been read from the coefficients.txt file.\n");
        printf("Printting the graph of x=%d*(y*y)+%d*y+%d\n",a,b,c);
             for(i=17;i>=-18;i--){
            for(j=-53;j<=56;j++){
                    if(j==a*i*i+b*i+c+2){
                        if(b==0){

                          if(i>5 && i%5==0){
                          printf("\033[0;34m");
       printf("\b#");
        printf("\033[0m");
                             
                         }if(i==-1){
                         printf("\033[0;34m");
        printf("  #");
        printf("\033[0m");
                           
                            
                         }
                        }else
                        if(i>5 && i%5==0){
                         printf("\033[0;34m");
        printf("\b\b#");
        printf("\033[0m");
                            
                         }
                         if(i==-1){
                         printf("\033[0;34m");
      printf("\b\b\b\b\b\b\b\b\b#");
        printf("\033[0m");
                             
                         }
                          if( i==-5){
                          printf("\033[0;34m");
       printf("\b\b#");
        printf("\033[0m");
                             
                            if(b==0){
                            printf("\033[0;34m");
        printf("\b #");
        printf("\033[0m");                                                        
                            }
                          }
                          printf("\033[0;34m");
      printf("\b#");
        printf("\033[0m"); 
                           
                }

                if(j==-1 && i%5==0 && i!=0){
                printf("\033[0;33m");
            printf("\b%d",i);
        printf("\033[0m");

           
                }
                if(i==-1 && j%10==0){
                    if(j<0){
                             printf("\033[0;33m");
          printf("\b\b%d",j);
        printf("\033[0m");
                        
                    }else if(j>0){ printf("\033[0;33m");
          printf("\b%d",j);
        printf("\033[0m");
                    }
                }
                if(i==0){
                        if(j==1){
                            printf("|");
                        }else
                  printf("-");
                  if(j==56){
                    printf("\b>");}
                    if(j==-53){
                        printf("\b<");
                    }
                }else if(i==5 && j==1){
                    printf("|");}else printf(" ");
                if(j==1 && i!=-1 && i%5!=0){
                        printf("\b|");}
                        if(j==0 && i%5==0 && i>5 ){
                            printf("\b|");
                        }else if(j==0 && i%5==0 && i<-5){
                        printf("\b\b|");
                        }else if(j==0 && i==-5 && b==0 ){
                        printf("\b|");
                        }else if(b!=0 && j==-6 && i==-1){
                        printf("\033[0;33m");
          printf("0");
        printf("\033[0m");
                        printf("|");
                        }else if(j==0 && i==-1){
                        printf("\033[0;33m");
          printf("\b0");
        printf("\033[0m");
                        printf("|");
                        }


             }
              printf("\n");
             } 


    break;
    case 3:
        fp=fopen("coefficients.txt","r");
        fscanf(fp,"%d",&a);
        fscanf(fp,"\n %d",&b);
        fscanf(fp,"\n\n %d",&c);
        fclose(fp);
        printf("Coefficients has been read from the coefficients.txt file.\n");
        printf("The graph of x=%d*(y*y)+%d*y+%d  has been written to graph.txt file\n",a,b,c);
     FILE *fp2;
     fp2=fopen("graph.txt","w");
     
      for(i=17;i>=-18;i--){
            for(j=-52;j<=55;j++){
                 if(j==a*i*i+b*i+c){
                       fprintf(fp2,"#");}else 
                       if(i==0){
                       if(i==0 && j==-55){
                       fprintf(fp2,"<");} else if(i==0 && j==55){
                       fprintf(fp2,">");} else fprintf(fp2,"-");}
                       else if(j==0){
                       fprintf(fp2,"|");}
                       else fprintf(fp2," ");
                       }
                       
           fprintf(fp2,"\n");
             }
            
             fclose(fp2);
           
    break;
 }   
}while(num != 4);

}
