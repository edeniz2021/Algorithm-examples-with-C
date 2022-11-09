#include <stdio.h>
#include "util.h"


int main() {
   
    int num1,num2,divisor,firstnum,next;
    int pemp,temp,semp,lemp,femp;
    char idno1[11];
    int pass2,pass1;
    float amount;
    printf("Enter the 1st number: ");
    scanf("%d",&num1);
    printf("Enter the 2nd number: ");
    scanf("%d",&num2);
     printf("Enter the divisor number: ");
    scanf("%d",&divisor);
    pemp= find_divisible(num1,num2,divisor);
    if(pemp==-1){
    printf("There is not any integer between %d and %d can be divided by %d”\n",num1,num2,divisor);
    }else {
    firstnum=pemp;
    printf("The first number divisible by %d between %d and %d is %d.\n",divisor,num1,num2,firstnum);
    }if(pemp==-1){
    temp=(-999);
    }else {
       printf("Enter the number how many next: ");
    scanf("%d",&next);
    }

    temp=find_nth_divisible(next,firstnum,divisor);
    if(temp<num2 && temp>num1){
       temp=temp;
    }else {
    temp=(-999);
    }
    if(temp==-999){
        printf("No possible to find Nth divisible between %d and %d divided by %d”\n\n",num1,num2,divisor);
    }else {
    printf("The %d . integer between %d and %d divided by %d is %d\n\n",next+1,num1,num2,divisor,temp);
    }
   
    char idno[11];
    int kemp;
    printf("Enter your identity number: ");
    scanf("%s",idno);
    kemp = validate_identity_number(idno);
    if(kemp==0){
   printf("You entered incorrectly\n");
    }  else {printf("Enter password: ");
    scanf("%d",&pass1);}
    semp= create_customer(idno,pass1);
    printf("Please Enter your identity number: ");
    scanf("%s",idno1);
    printf("Please Enter password:");
    scanf("%d",&pass2);
    lemp=check_login(idno1,pass2);
    
    if(lemp==5){
    printf("Login Successful\n");
    printf("Enter your withdraw amount:");
    scanf("%f",&amount);
}else { printf("“Invalid identity number or password”");}
femp=drawable_amount (amount);
if(lemp==5){
printf("Withdrawable amount is: %d",femp);
}
}
