#include <stdio.h>
#include "util.h"
#include <math.h>
/* Example decision tree - see the HW2 description 
int dt0(int t, double p, double h, int s, int w){
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}


/* Provide your implementations for all the requested functions here */
char dt1a(float x,float y,float z,float t){
  if(x<2.45){
   return 's';  } 
   else if(x>2.45 && y>1.75){
   return 'v';}
   else if(x>4.95 && y<1.75){
   return 'v';}
   else if(x<4.95 && y>1.65 && y<1.75){
   return 'v';}
   else if(x<4.95 && y<1.65){
   return 'c';}
   
}
char dt1b(float x,float y,float z,float t){
   if(x<2.55){
   return 's';}
   else if(x>2.55 && y>1.69){
   return 'v';}
   else if(x>4.85 && y<1.69){
   return 'v';}
   else if(x<4.85 && y<1.69){
   return 'c';}
   }
 
double dt2a(double x1,double x2,double x3,int x4,int x5){
 
  if(x1<31.5){
  if(x2>-2.5){ return 5.0;}
  else { if((x2-0.1)<=x1 && (x2+0.1)>=x1){
  return 2.1;} else return -1.1;}}
  else { if((-1<=x3) && (x3<=2)){
  return 1.4;} else {
  if(x4*x5==1){ return -2.23;}
  else return 11.0;}}
  
  }
  /*i multiplied the binary numbers x4 and x5 to check the 'and logic' operation, and the sound turns out to be 0 in the and operation, unless both get the value 1, it is similar to the multiplication operation.*/
double dt2b(double x1,double x2,double x3,int x4,int x5){
   
    if(x1<22 && 12<x1){
        if(x3>(5/3)){
            return -2.0;
        }else if((x1-(0.1)<=x3)&& (x1+(0.1)>=x3)){
        return 1.01;
        }else return -8;
    }else {
    if(x4*x5==1){
       return -1;
    }else {
    if((-1<=x2)&& (x2<=2)){
        return -1.0/7.0;
    }else return sqrt(2)/3;
    }
 }}

 void dt3a(double s,double n,float w,float b,int g,char c,int type,int con){
 /*i have considered suitable wards for growing a plant. Temperature. with terms such as humidity, water,nutritional value, light.  I have assigned threshold values to them and created my decision trees according to them.*/
   if(type==1){
   printf("\nFOR MORUS:\n");}
   if(type==2){
   printf("\nFOR MALUS DOMESTİCA:\n");}
   if(type==3){
   printf("\nFOR RUBUS:\n");}
   if(type==4){
   printf("\nFOR FRAGARİA:\n");}
   if(type==5){
   printf("\nFOR COTONEASTER:\n");}
   if(type==6){
   printf("\nFİCUS CARİCA:\n");}
   if(con==1){
   printf("on the Africa Continent\n");}
   if(con==2){
   printf("on the America Continent\n");}
   if(con==3){
   printf("on the Asia Continent\n");}
   if(con==4){
   printf("on the Europe Continent\n");}
   if(con==5){
   printf("on the Antarctica Continent\n");}
   if(con==6){
   printf("on the Australia Continent\n");}
   if(s>21 && s<28 && w>20 && w<30 && b>11.5 && g==1 && c=='r' && n<60 && n>40){
printf(" The plant is in the flowering period: Has not started blooming yet\n");}
else if(s>21 && s<28 && w>20 && w<30 && b>11.5 && g==1 && c=='p' && n<60 && n>40){
printf(" The plant is in the flowering period: The flowers are in bloom\n");}
else if(s>21 && s<28 && w>20 && w<30 && b>11.5 && g==1 && c=='r' && n>60){
 printf("The plant is in the developmental period: Has not yet borne fruit\n");}
else if(s>21 && s<28 && w>20 && w<30 && b>11.5 && g==1 && c=='r' && n>60){
 printf("The plant is in the developmental period: During the period when it bears fruit\n");}
 else {  printf(" The plant cannot live at these values\n"); }
  
}
/*i have determined such quantities as if the temperature is not between 21 and 28 degrees, if the humidity is not dec, if it does not receive enough water and nutrients and if it does not see light, the plant cannot live.*/
void dt3b(double s,double n,float w,float b,int g,char c,int type,int con){
/*I thought of different plant species as a and b, and that's why I took the threshold values differently.*/
 if(type==1){
   printf("\nFOR MORUS:\n");}
   if(type==2){
   printf("\nFOR MALUS DOMESTİCA:\n");}
   if(type==3){
   printf("\nFOR RUBUS:\n");}
   if(type==4){
   printf("\nFOR FRAGARİA:\n");}
   if(type==5){
   printf("\nFOR COTONEASTER:\n");}
   if(type==6){
   printf("\nFİCUS CARİCA:\n");}
   if(con==1){
   printf("on the Africa Continent\n");}
   if(con==2){
   printf("on the America Continent\n");}
   if(con==3){
   printf("on the Asia Continent\n");}
   if(con==4){
   printf("on the Europe Continent\n");}
   if(con==5){
   printf("on the Antarctica Continent\n");}
   if(con==6){
   printf("on the Australia Continent\n");}
   if(s>21 && s<28 && w>13.65 && w<21.7 && b>6.8 && g==1 && c=='r' && n<50 && n>35){
printf(" The plant is in the flowering period: Has not started blooming yet\n");}
else if(s>21 && s<28 && w>13.65 && w<21.7 && b>6.8 && g==1 && c=='p' && n<50 && n>35.5){
printf(" The plant is in the flowering period: The flowers are in bloom\n");}
else if(s>21 && s<28 && w>13.65 && w<21.7 && b>6.8 && g==1 && c=='r' && n>50){
 printf(" The plant is in the developmental period: Has not yet borne fruit\n");}
else if(s>21 && s<28 && w>13.65 && w<21.7 && b>6.8 && g==1 && c=='p' && n>50){
 printf(" The plant is in the developmental period: During the period when it bears fruit\n");}
 else {  printf(" The plant cannot live at these values\n"); }

}
