#include <stdio.h>
#include <math.h>

void map(int filter(int), int a[], int n);
 int abs(int x){if(x<0)x=-x; return x;}
 int prime(int x){if(x%2==0)x=1; else x=0;return x;}
int printarray(char name[],int a[],int n);
 int main(){

    double x=0.1 ,y;
    int numbers[]={-1,2,-3,4,-5,6};
    printarray("numbers\n",numbers,6);
    map(abs,numbers,6);
    printarray("abs(numbers)\n",numbers,6);
 }

void map(int filter(int),int a[],int n){

    int i;
    for(i=0;i<n;i++){
        a[i]=filter(a[i]);
    }
}
int printarray(char name[],int a[],int n){ 
int i;
printf("\n%s",name);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }}