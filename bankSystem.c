#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
 int i, j;
 int mainExit;
void menu();
struct date{
    int year,month,day;
};
struct{
    char name[50];
    int accountNo,age;
    int address[50];
    char accountType[10];
    char citizen[15];
    double mobile;
    float amount;
    struct date DOB;
    struct date withdraw;
    struct date deposit;
}
add,check,update,transaction,removeoveainingaining;

float interest(float amount, float time, int rate){
    float SI;
    SI=(amount*time*rate)/100.0;
    return SI;

}
void delay(int j){
    int i,k;
    for(i=0; i<j; i++){
        k=i;
    }
}

void newAccount(){
    int choice;
    FILE *ptr;
    ptr=fopen("record.data","a+");
    accountNumber:
 system("cls");
 //\xB2 is an escape sequence that represents a special character in the ASCII character set.
    printf("\t\t\t\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.accountNo);
     while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.accountNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.age,add.address,add.citizen,&add.mobile,add.accountType,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.accountNo==add.accountNo)
            {printf(" This Account no. already in use!");
            delay(1000000000);
                goto accountNumber;
            }
    } 
add.accountNo=check.accountNo;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.DOB.month,&add.DOB.day,&add.DOB.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizen number:");
    scanf("%s",add.citizen);
    printf("\nEnter the mobile number: ");
    scanf("%lf",&add.mobile);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amount);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.accountType);
     fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.citizen,add.mobile,add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
  
  
  fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&mainExit);
    system("cls");
    if (mainExit==1)
        menu();
    else if(mainExit==0)
      exit(0);
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}


void viewList(){
FILE *view;
view= fopen("record.data","r");
int test=0;
system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tmobile\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accountNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.age,add.address,add.citizen,&add.mobile,add.accountType,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.accountNo,add.name,add.address,add.mobile);
           test++;
       }
 fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&mainExit);
        system("cls");
        if (mainExit==1)
            menu();
        else if(mainExit==0)
            exit(0);
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
 void edit(void){
    
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&update.accountNo);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accountNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.age,add.address,add.citizen,&add.mobile,add.accountType,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.accountNo==update.accountNo)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.mobile\n\nEnter your choice(1 for address and 2 for mobile):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",update.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,update.address,add.citizen,add.mobile,add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new mobile number:");
                scanf("%lf",&update.mobile);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.citizen,update.mobile,add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.citizen,add.mobile,add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&mainExit);
              system("cls");
                 if (mainExit==1)

                    menu();
                else if (mainExit==2)
                    exit(0);
                else if(mainExit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&mainExit);
        system("cls");
        if (mainExit==1)
            menu();
        else
            exit(0);
        }
 }

 void transact(void) {
     int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.accountNo);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accountNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.age,add.address,add.citizen,&add.mobile,add.accountType,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.accountNo==transaction.accountNo)
            {   test=1;
                if(strcmpi(add.accountType,"fixed1")==0||strcmpi(add.accountType,"fixed2")==0||strcmpi(add.accountType,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    delay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amount);
                    add.amount+=transaction.amount;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.citizen,add.mobile,add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amount);
                    add.amount-=transaction.amount;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.citizen,add.mobile,add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.citizen,add.mobile,add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&mainExit);
      system("cls");
      if (mainExit==0)
        transact();
    else if (mainExit==1)
        menu();
    else if (mainExit==2)
        exit(0);
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&mainExit);
        system("cls");
        if (mainExit==1)
            menu();
        else
            exit(0);
   }
 }

 void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&add.accountNo);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accountNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.age,add.address,add.citizen,&add.mobile,add.accountType,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.accountNo!=add.accountNo)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.citizen,add.mobile,add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&mainExit);

                 if (mainExit==1)
                    menu();
                else if (mainExit==2)
                    exit(0);
                else if(mainExit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&mainExit);
        system("cls");
        if (mainExit==1)
            menu();
        else
            exit(0);
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.accountNo);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accountNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.age,add.address,add.citizen,&add.mobile,add.accountType,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.accountNo==check.accountNo)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \ncitizen No:%s \nmobile number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.citizen,add.mobile,
                add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.accountType,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.accountType,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.accountType,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.accountType,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.accountType,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accountNo,add.name,&add.DOB.month,&add.DOB.day,&add.DOB.year,&add.age,add.address,add.citizen,&add.mobile,add.accountType,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \ncitizen No:%s \nmobile number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.accountNo,add.name,add.DOB.month,add.DOB.day,add.DOB.year,add.age,add.address,add.citizen,add.mobile,
                add.accountType,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.accountType,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.accountType,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.accountType,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.accountType,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.accountType,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&mainExit);
              system("cls");
                 if (mainExit==1)
                    menu();
                else if (mainExit==2)
                    exit(0);
                else if(mainExit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&mainExit);}
        if (mainExit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            exit(0);
            }

}


void closeAcc(void)
{
    printf("\n\n\n\nThis C Mini Project is developed by Code With C team!");
    }



void new_acc(void);
void Edit(void);
void Transact(void);
void See(void);
void Erase(void);
void view_list(void);


void menu(void)
{    
     int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.removeoveainingoving existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:Edit();
        break;
        case 3:Transact();
        break;
        case 4:See();
        break;
        case 5:Erase();
        break;
        case 6:view_list();
        break;
        case 7:exit(0);
        break;
    }
    }

void new_acc(void) {
    printf("Creating a new account...\n");
    // Implementation for creating a new account
}

void Edit(void) {
    printf("Editing an existing account...\n");
    // Implementation for editing an existing account
}

void Transact(void) {
    printf("Performing transactions...\n");
    // Implementation for transactions
}

void See(void) {
    printf("Viewing account details...\n");
    // Implementation for viewing account details
}

void Erase(void) {
    printf("Deleting an account...\n");
    // Implementation for deleting an account
}

void view_list(void) {
    printf("Viewing the list of accounts...\n");
    // Implementation for viewing the list of accounts
}

int main()
{
    char pass[10],password[10]="codewithc";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            delay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&mainExit);
            if (mainExit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (mainExit==0)
                    {
                    system("cls");
                    exit(0);}
            else
                    {printf("\nInvalid!");
                    delay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}