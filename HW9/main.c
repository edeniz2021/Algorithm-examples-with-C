#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i=0;
int total=0;
void listCustomers();
void addCustomer ();
void newLoan ();
double calculateLoan(float amount, int period, float interestRate);
void getReport();
void combine();
void print();
void detay();
int per[50][50][3];
double tut[500][50][3];
char veri[5000][500];

union Person
{
    char name[50];
    char address[50];
    int phone;
};
union Loan
{
    float amount;
    float interestRate;
    int period;
};
struct BankAccount
{
    union Person Customer;
    union Loan Loans[3];
};
void addCustomer (struct BankAccount *a)//I am sending union structure to function with pointer.
{
    if(total>49)//I defined the total as global, if it is more than 50, it will return and give a warning.
    {
     printf("The maximum number of people is 50. Please choose another action. \n");
        return;      
    }
    total++;// The total is incremented by 1 each line the addcustomer function is called.
     FILE *fp;
    fp=fopen("customer.txt","a");
    fprintf(fp,"Customer ID =  %d\n",total);
    printf("Please Enter Customer Phone = ");
    scanf(" %d",&a->Customer.phone);//I send the data I get from the user to the customer.txt file.
    fprintf(fp,"Customer Phone = %d\n",a->Customer.phone);
    printf("Please Enter Customer Adress = ");
    scanf(" %[^\n]%*c",a->Customer.address);
    fprintf(fp,"Customer Adress = %s\n",a->Customer.address);
    printf("Please Enter Customer Name = ");
    scanf(" %[^\n]%*c",a->Customer.name);
    fprintf(fp,"Customer Name =  %s\n",a->Customer.name);    
    fclose(fp);
}
void listCustomers(struct BankAccount *b)
{
  //In the struct list the names I keep in the union structure.
    printf("%s\n",b->Customer.name);

}

void newLoan (struct BankAccount *c,int sayi)
{   int perd;
    float ir;
    double temp;
    if(c->Loans[0].amount=='\0')
    {
        printf("Please Enter Period: ");
        scanf("%d",&c->Loans[0].period);
        perd=c->Loans[0].period;
        *per[sayi][0]=perd;
        //I kept the entered period there by creating an array. So i made connection between client and period.
        printf("Please Enter Interestrate: ");
        scanf("%f",&c->Loans[0].interestRate);
        ir=c->Loans[0].interestRate;  
         printf("Please Enter Amount : ");
        scanf("%f",&c->Loans[0].amount);
        temp=calculateLoan(c->Loans[0].amount,perd,ir);//I send the entered information to the function, let the loan be calculated.
        printf("New Loan : %f \n",temp);
        *tut[sayi][0]=temp;//I kept the calculated loan in an array by associating it with the customer.
    }
    else if(c->Loans[0].amount!='\0' && c->Loans[1].amount=='\0')// if the loan is full,enter the next loan
    {
        printf("Pleasse Enter Period: ");
        scanf("%d",&c->Loans[1].period);
         perd=c->Loans[1].period;
        *per[sayi][1]=perd;
        printf("Please Enter Interestrate: ");
        scanf("%f",&c->Loans[1].interestRate);
         ir=c->Loans[1].interestRate;
         printf("Please Enter amount : ");
        scanf("%f",&c->Loans[1].amount);  
        temp=calculateLoan(c->Loans[1].amount,perd,ir);
        printf("New Loan : %f \n",temp);
        *tut[sayi][1]=temp;
    }
    else if(c->Loans[0].amount!='\0' && c->Loans[1].amount!='\0' && c->Loans[2].amount=='\0')
    {
        printf("enter period: ");
        scanf("%d",&c->Loans[2].period);
         perd=c->Loans[2].period;
        *per[sayi][2]=perd;
        printf("enter interestrate: ");
        scanf("%f",&c->Loans[2].interestRate);
        ir=c->Loans[2].interestRate;
        printf("enter amount : ");
        scanf("%f",&c->Loans[2].amount);
        temp=calculateLoan(c->Loans[2].amount,perd,ir);
        printf("new loan : %f \n",temp);
        *tut[sayi][2]=temp;
    }
    else if(c->Loans[0].amount!='\0' && c->Loans[1].amount!='\0' && c->Loans[2].amount!='\0')
    {
        printf("You have reached the maximum number of credits you can take.\n");
    }
}
double calculateLoan(float amount, int period, float interestRate)
{

    double sonuc;
    sonuc=1;

    if(period!=0)
    {//I used a recursive function by reducing the period from calculate loan.
        sonuc= (1+interestRate)*calculateLoan(amount,period-1,interestRate);
    }
    else
        sonuc=sonuc*amount;

    return sonuc;
}
void combine(int num)
{ //I opened a function like this to combine loan,period,customer information.
    int j=0;
    int n;
    int ten;
    double sum=0;
    ten=num;
    FILE *fp;
    fp=fopen("customer.txt","r");
    if (fp == NULL)
    {
        printf("\nYour file could not be opened!\n");
    }
    else
    {
        while (!feof(fp))
        {
            for (i = 0; i < total*4; i++ )
            {
                fscanf(fp, "%[^\n]%*c", veri[i]);
            }//I kept data read line by line from file in veri array.
        }
    }
    fclose(fp);
    FILE *tp;
    tp=fopen("loan.txt","w");
    num=(num-1)*4;//Calculates the index of desired customer and pulls the data from there.
    for (j = num; j < num+4; j++ )
    {
        fprintf(tp,"%s\n", veri[j]);
    }
    int k=0;
    for(i=0; *tut[ten][i]!=0; i++)
    {
        sum = sum +(*tut[ten][i]);
        k++;//I defined the counter to calculate how many loans the customer has.
    }

    fprintf(tp,"Loans = [");
    for(n=0; n<k; n++)
    {
        fprintf(tp," %f ",*tut[ten][n]);
        if((n+1)!=k)
        {
            fprintf(tp,"+");
        }
    }
    fprintf(tp,"] => %f \n",sum);
    fclose(tp);
}

void print()//I opened a function to print the combined information.
{

    char musteri[5000][500];
    FILE *cp;
    cp=fopen("loan.txt","r");
    if (cp == NULL)
    {
        printf("\nYour file could not be opened!\n");
    }
    else
    {
        i=0;
        while (!feof(cp))
        {
            i++;
            fscanf(cp, "%[^\n]%*c", musteri[i]);
        }
        fclose(cp);

    }
    printf("\nCustomer information you entered :\n");
    for (i = 0; i<8; i++ )//ı print data in the loan file.
    {
        printf( "%s \n",*(musteri+i));
    }

}
void detay(int say)
{
    double sum=0;
    double insta=0;
    int kac;
    printf("Let's calculate which loan: ");
    scanf("%d",&kac);
    kac=kac-1;
    if(*tut[say][kac]!=0)
    {
        sum=*tut[say][kac];//Iam using the period and loan that I associated earlier here.
        printf("\nTotalll : %f\n",sum);
        insta=sum/(*per[say][kac]);
        for(i=0; i<(*per[say][kac]); i++)
        {
            printf("%d. Month Installement:%f \n",i+1,insta);
        }
    }
    else printf("The loan you entered cannot be found.\n");

}
void getReport(int say)
{
    int sec;
    printf(" 1-Customer Detail \n 2-Loan Detail \n");
    printf("Choose selection: ");
    scanf("%d",&sec);
    printf("\n");
    int j=0;
    switch(sec)
    {
    case 1:
       print();
        break;
    case 2:
        detay(say);//I called a function for the loan period relationship.
        break;
    }
}

int main()
{
    struct BankAccount b[2];  
    int select;
    int sayi;
    int j;
    int num;
    do
    {

        printf("===========================================\n");
        printf("Welcome to the Bank Management Systems\n");
        printf("===========================================\n");
        printf("\t1.List All Customers\n");
        printf("\t2.Add New Customer\n");
        printf("\t3.New Loan Application\n");
        printf("\t4.Report Menu\n");
        printf("\t5.Exit System\n");
        printf("Choose: ");
        scanf("%d",&select);
        printf("\n");
        switch(select)
        {

        case 1:
            for(j=0; j<total; j++)
            {
                printf("%d. Customer Name:",j+1);
                listCustomers(&b[j]);//I sent the struct into the function with the address.
            }
            break;

        case 2:

            addCustomer (&b[total]);

            break;

        case 3:
            printf("Enter Customer's ID number: ");
            scanf("%d",&sayi);
            newLoan (&b[sayi],sayi);
            break;

        case 4:
            printf("Enter the ID number of the customer you want to view:  ");
            scanf("%d",&num);
            combine(num);
            getReport(num);

            break;
        }
    }
    while(select!=5);//Unless 5 is selected, the program flow will continue.
}

