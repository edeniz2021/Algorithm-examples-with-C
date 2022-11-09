#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"


int main() {

    /* Ask for the problem selection (1,2,3) .....  */

    /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
    /* Compare performances and print results */

    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    /* Compare performances and print results */

    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
    /* Compare performances and print results */
int problem;
   printf("Which problem do you want to solve from 1-2-3:");
   scanf("%d",&problem);
   float pl,pw,sl,sw;
   double x1,x2,x3,t,h;
   int x4,x5,l,type,continent;
   float w,n;
   char c;
   double temp,semp;
   char kemp,lemp;
     printf("\n");
   if(problem==1){
   printf("Enter the PL value:");
   scanf("%f",&pl);
   printf("Enter the PW value: ");
   scanf("%f",&pw);
   printf("Enter the SL value:");
   scanf("%f",&sl);
   printf("Enter the SW value: ");
   scanf("%f",&sw);
   kemp=dt1b(pl,pw,sl,sw);
   lemp=dt1a(pl,pw,sl,sw);
/*I have assigned different variables to define the p1 ave b functions and compared them.*/
   if(kemp==lemp){
        printf("Since PL value is %.3f and PW value is %.3f, in both trees:",pl,pw);
       if(kemp=='s'){
    printf("SETOSA");
   }else if(kemp=='v'){
   printf("VİRGİNİCA");
   }else if(kemp=='c'){
   printf("VERSİCOLOR");
   }}
   else{printf("Since PL is %.3f and PW is %.3f: \n",pl,pw);
   printf("1.Type of tree:");
     if(lemp=='s'){
    printf("SETOSA");
   }else if(lemp=='v'){
   printf("VİRGİNİCA");
   }else if(lemp=='c'){
   printf("VERSİCOLOR");
   }printf("\n");
   printf("2.Type of tree:"); if(kemp=='s'){
    printf("SETOSA");
   }else if(kemp=='v'){
   printf("VİRGİNİCA");
   }else if(kemp=='c'){
   printf("VERSİCOLOR");
   }}}
   if(problem==2){
    printf("Enter X1 value:");scanf("%lf",&x1);
    printf("Enter X2 value:");scanf("%lf",&x2);
    printf("Enter X3 value:");scanf("%lf",&x3);
    /*I asked the user for binary numbers in the form of 1 and 0. If the user does not enter the desired way, I have asked the user for a number again.*/
    do{
    printf("\nEnter a value such that X4 is either 1 or 0 as binary value:");scanf("%d",&x4);
    }while ((x4!=1) && (x4!=0));
    do{
    printf("Enter a value such that X5 is either 1 or 0 as binary value:");scanf("%d",&x5);
    }while ((x5!=1) && (x5!=0));
   temp=dt2a(x1,x2,x3,x4,x5);
   semp=dt2b(x1,x2,x3,x4,x5);
   printf("1. Result: %.4lf\n",temp);
   printf("2. Result:%.4lf\n",semp);
   if(semp<temp){
   if(CLOSE_ENOUGH>=(temp-semp)){
    double ort;
    ort=(temp+semp)/2;
    printf("Results : %lf\n",ort);}}else
     if(temp<semp){
   if(CLOSE_ENOUGH>=(semp-temp)){
    double ort;
    ort=(temp+semp)/2;
    printf("Results : %lf\n",ort);}}
    else {
   if(semp<temp){
    printf("2nd result (%.4lf) is less than 1st result(%lf)",semp,temp);
   }else if(temp<semp){
    printf("1st result (%.4lf) is less than 2nd result (%lf)",temp,semp);
   }else if(temp==semp){
   printf("Both results are the same");
   }}
   }
   if(problem==3){
   printf("PLANT SPECIES:\n");
   printf(" 1 - MORUS\n");
   printf(" 2 - MALUS DOMESTİCA\n");
   printf(" 3 - RUBUS\n");
   printf(" 4 - FRAGARİA\n");
   printf(" 5 - COTONEASTER\n");
   printf(" 6 - FİCUS CARİCA\n");
   do{
      printf("Enter the number of the plant whose values ​​you want to calculate:");scanf("%d",&type); 
   printf("\n");
    }while ((type!=1) && (type!=2) && (type!=3) && (type!=4) && (type!=5) &&(type!=6));
    /*Here I set the plant species as the categorical language and asked the user to choose it.*/
   printf("WHICH CONTINENT DOES HE LIVE:\n");
   printf(" 1 - AFRİCA\n");
   printf(" 2 - AMERİCA\n");
   printf(" 3 - ASİA\n");
   printf(" 4 - EUROPE\n");
   printf(" 5 - ANTARCTİCA\n");
   printf(" 6 - AUSTRALIA\n");
   do{
       printf("Enter the code letter of the continent you want to select:");scanf("%d",&continent); 
   printf("\n"); 
    }while ((continent!=1) && (continent!=2) && (continent!=3) && (continent!=4) && (continent!=5) &&(continent!=6));
   /*Here I set the continents as categorical languages ​​and asked the user to select them.*/
   printf("Enter the temperature value:");scanf("%lf",&t);
    printf("Enter the humidity value:");scanf("%lf",&h);
    printf("Enter the water value:");scanf("%f",&w);
    printf("Enter the nutritional value:");scanf("%f",&n);
     do{
     printf("Does it receive light? If yes, enter '1', if no, enter '0':");scanf("%d",&l);
    }while ((l!=1) && (l!=0));
    if(l==1){
     do{
    printf("Red light or purple light?If red, enter 'r', if purple'p':");scanf("%s",&c);
    }while ((c!='r') && (c!='p'));
   dt3a(t,h,w,n,l,c,type,continent);
   dt3b(t,h,w,n,l,c,type,continent);
    
}}
}
