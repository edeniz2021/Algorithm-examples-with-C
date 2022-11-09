#include <stdio.h>
#include "util.h"

int find_divisible(int x, int y, int z){
    int num=0;
    int f=0;
  for(int i=x;i<y+1;i++){
    if(i%z==0){
        num++;
        if(num==1){
            f=i;
            }
    }
    /* I put a counter to find the first integer divided. Once divided, the counter will increase. And it will prevent him from finding any more divisible numbers.*/
  }if(num!=0){
      return f;
  }else return -1;
}
int find_nth_divisible(int n, int f_I, int z){
    int nth;
    nth=(z*n)+f_I;
    return nth;
    /*To find the nth number, I multiply the divisor with the desired order and add it to the first integer we find.*/
}

int validate_identity_number(char identity_number [ ]){
     int counter=0;
     int singletotal=0;
     int doubletotal=0;
     int total=0;
  int check=0;
   if(identity_number [0]!=0){
    check++;
     }
     int size=0;
    for(int i=0;identity_number [i]!='\0';i++){
        size++;
    }
      /*I counted the string characters one by one to find the function length.*/
    if(size==11){
    check++;
    }for(int i=0;i<11;i++){
        if(identity_number[i]-48<10 && identity_number[i]-48>=0){
            counter++;
        }if(counter==11){
        check++;
    }/*since the index starts from 0, I need to find 1,3,5,7,9, 0,2,4,6,8 instead of the numbers.*/
    }for(int i=0;i<9;i++){
        if(i%2==0){
       singletotal=singletotal + (identity_number [i]-48);}
    }for(int i=1;i<9;i++){
        if(i%2!=0){
        doubletotal=doubletotal + (identity_number [i]-48);
    }}
   if(((singletotal*7 - doubletotal)%10) == (identity_number [9]-48)){
    check++;
   }
    for(int i=0;i<10;i++){
        total= total + (identity_number [i]-48);
    }if((total%10)==(identity_number [10]-48)){
    check++;
    }
   if(check==5){
   /* I put control for 5 steps. At the end of each step, the control increases by one. If the control equals 5 as a result of 5 steps, the algorithm is completed.*/
    return 1;
   }else {
   return 0;
 }
 }
 int create_customer(char identity_number [ ], int password){
      FILE *file;
    file=fopen("customeraccount.txt","w");
    fprintf(file,"%s,%d",identity_number ,password);
    fclose(file);
  return 2;
 }
 int check_login(char identity_number [ ], int password){
 int pass2;
 char idno2[11];
 int say=0;
   FILE *file;
    file=fopen("customeraccount.txt","r");
    fscanf(file,"%[^,],%d",idno2,&pass2);
    fclose(file);
   /* In this step, we retrieved the ID number and password that we wrote to the file in the previous step, from the file again.I entered this expression '[^,]' because when I didn't enter it, it didn't detect what was requested after the comma, however, it will treat the part up to the comma as a string and take the rest as an integer.*/
    for(int i=0; i<11;i++){
    if(idno2[i]==identity_number [i]){
    say++;
    }}if(pass2==password){
    say++;
    }if(say==12){
    
    return 5;
    }}
    int drawable_amount (float cash_amount){
    int remainder;
    remainder=(((int)cash_amount)%10);
    cash_amount=cash_amount-remainder;
     /*I changed the variable type from cash_amount to integer because it did not detect the expression '%' when I entered it as float.*/
    return cash_amount;
 }
