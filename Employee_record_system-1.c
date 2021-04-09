#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int,int);
void intro();
void work();
void pass(int);
void AdminMenu();
void add();
void modify(int);
void deleterecord();
void modify_password(int);
void employeeMenu(int);
void view_1(int);
void view(int);
void search_1(int);
void view_emp(int);


typedef struct
{
    int Id;
    int Age;
    char Name[50];
    char Address[200];
    char DOB[10];
    char Qualification[20];
    char Designation[20];
    char Password[50];
    double Salary;
    double Phone;

}EMPLOYEE;

//COORD coord = {0,0};
FILE *f;
EMPLOYEE emp[200];
long int size=sizeof(emp);

void gotoxy(int x,int y)
{
//    coord.X = x;
  //  coord.Y = y;
    //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void intro()
{
    system("cls");
    gotoxy(30,8);
    printf("PROJECT: EMPLOYEE RECORD SYSTEM");
    gotoxy(30,10);
    printf("MADE BY: ANKAN NATH AND PRAYASH KUMAR SAHA");
    gotoxy(30,12);
    printf("COLLEGE: TECHNO MAIN SALT LAKE");
    gotoxy(30,14);
    printf("DEPARTMENT: ELECTRONICS AND COMMUNICATION ENGINEERING");
    int ans= getche();
}

void main()
{   intro();
    work();
}

void work()
{
    char ch,choice;


    do
    {
         system("cls");
         gotoxy(30,8);
         printf("MAIN MENU");
         gotoxy(30,10);
         printf("1. ADD RECORD");
         gotoxy(30,12);
         printf("2. VIEW RECORD");
         gotoxy(30,14);
         printf("3. ADMIN");
         gotoxy(30,16);
         printf("4. EMPLOYEE PERSONAL");
         gotoxy(30,18);
         printf("5. EXIT");
         gotoxy(30,20);
         printf("ENTER YOUR CHOICE: ");
         fflush(stdin);
        choice = getche();
         switch(choice)
         {
         case '1':add();break;
         case '2':view_1(1);break;
         case '3':pass(0);break;
         case '4':gotoxy(30,22);
         printf("\nENTER ID: ");
         int id;
         scanf("%d",&id);
         if(id==0){gotoxy(30,24);printf("NOT VALID");}
         else
         {pass(id);}
         break;
         case '5':exit(0);break;
         default: printf("\nWRONG CHOICE\n");break;

         }
         printf("DO YOU WANT TO CONTINUE (y/n)? : ");
         fflush(stdin);
         ch=getche();

    }while(ch=='Y' || ch=='y');

work();
}

void pass(int n)
{char p[50];int ch;
system("cls");
printf("ENTER YOUR PASSWORD: ");
fflush(stdin);
fgets(p,50,stdin);
f=fopen("Employee.dat","rb");
if(n==0){
if(strcmp(p,emp[0].Password)==0)
{
    fclose(f);
    AdminMenu();
}
else{
        printf("WRONG PASSWORD");
        fclose(f);
        ch=getche();
        work();
}}
else{if(strcmp(p,emp[n].Password)==0)
{
    fclose(f);
    employeeMenu(n);
}
else{
        printf("WRONG PASSWORD");
        fclose(f);
        ch=getche();
        work();
}}

}

void AdminMenu()
{
    char ch,choice;
    do{
    system("cls");
    gotoxy(30,8);
    printf("ADMIN MENU");
    gotoxy(30,10);
    printf("1. MODIFY RECORD");
    gotoxy(30,12);
    printf("2. VIEW RECORD");
    gotoxy(30,14);
    printf("3. DELETE RECORD");
    gotoxy(30,16);
    printf("4. RETURN TO MAIN MENU");
    gotoxy(30,18);
    printf("ENTER YOUR CHOICE: ");
    gotoxy(30,20);
    choice=getche();
    switch(choice)
    {
        case '1': modify(0);break;
        case '2': view_1(0);break;
        case '3': deleterecord();break;
        case '4': work();break;
        default: printf("WRONG CHOICE\n");break;
    }
    printf("DO YOU WANT TO CONTINUE (y/n)?: ");
    fflush(stdin);
    ch=getche();
    }while(ch=='y' || ch=='Y');
AdminMenu();
}

void add()
{   system("cls");
    char ch;int j=0,i;
    f=fopen("Employee.dat","rb+");
    if(f==NULL)
    {
        f=fopen("Employee.dat","wb+");
        if(f==NULL)
        {
            printf("FILE DOESN'T EXISTS");
            exit(1);
        }
        else
        {
            i=0;
        }

    }
    else{
            while(fread(&emp[j],size,1,f))
               j++;
            i=j;
    }

           fseek(f,0,SEEK_END);
            do{
            fflush(stdin);
            system("cls");
            printf("\nENTER YOUR NAME: ");
            fflush(stdin);
            fgets(emp[i].Name,50,stdin);
            printf("\nENTER YOUR AGE: ");
            fflush(stdin);
            scanf("%d",&emp[i].Age);
            printf("\nENTER YOUR ADDRESS: ");
            fflush(stdin);
            fgets(emp[i].Address,200,stdin);
            printf("\nENTER YOUR PHONE NUMBER: ");
            fflush(stdin);
            scanf("%lf",&emp[i].Phone);
             printf("\nENTER THE DOB: ");
             fflush(stdin);
             fgets(emp[i].DOB,10,stdin);
             printf("\nENTER THE QUALIFICATION: ");
             fflush(stdin);
             fgets(emp[i].Qualification,20,stdin);
             fflush(stdin);
             emp[i].Salary=0.00;
             fflush(stdin);
             emp[i].Id=i;
             fflush(stdin);
             strcpy(emp[i].Password,emp[i].Name);
             fflush(stdin);
             strcpy(emp[i].Designation,"DEFAULT");
             fflush(stdin);

            fwrite(&emp[i], size,1, f);
            printf("\nThe record is sucessfully added\nWith your ID: %d\nPASSWORD: %s\n",i,emp[i].Password);
            if(i==0)
            {
                printf("YOU ARE THE ADMIN NOW");
                strcpy(emp[0].Designation,"ADMIN");
                }
            printf("\nDO YOU WANT TO CONTINUE(y/n)?: ");
            fflush(stdin);
            ch=getch();
            i++;
            }while(ch=='y' || ch=='Y');
            work();
}

void modify(int n)
{
    int id,choice;char ch;

    f=fopen("Employee.dat","rb+");
         system("cls");

         if(n==0)
         {
            printf("1. NAME\n");
            printf("2. AGE\n");
            printf("3. ADDRESS\n");
            printf("4. DOB\n");
            printf("5. PHONE\n");
             printf("6. SALARY\n");
             printf("7. DESIGNATION\n");
             printf("8. QUALIFICATION\n");
             printf("9. PASSWORD\n");
             printf("10. ALL\n");
             printf("11. RETURN TO ADMIN MENU\n");
             printf("12. RETURN TO MAIN MENU\n");
             printf("ENTER YOUR CHOICE: ");
             fflush(stdin);
             scanf("%d",&choice);
             switch(choice)
             {
             case 1:printf("ENTER ID: ");
             fflush(stdin);
             scanf("%d",&id);
             printf("\nENTER THE NEW NAME: ");
             fflush(stdin);
             fgets(emp[id].Name,50,stdin);
             fwrite(&emp[id].Name,size,1,f);
             break;

             case 2:printf("ENTER ID: ");
             fflush(stdin);
             scanf("%d",&id);
             printf("\nENTER THE NEW AGE: ");
             fflush(stdin);
             scanf("%d",emp[id].Age);
             fwrite(&emp[id].Age,size,1,f);
             break;

             case 3:printf("ENTER ID: ");
             fflush(stdin);
             scanf("%d",&id);
             printf("\nENTER THE NEW ADDRESS: ");
             fflush(stdin);
             fgets(emp[id].Address,200,stdin);
             fwrite(&emp[id].Address,size,1,f);
             break;

             case 4:printf("ENTER ID: ");
             fflush(stdin);
             scanf("%d",&id);
             printf("\nENTER THE NEW DOB: ");
             fflush(stdin);
             fgets(emp[id].DOB,10,stdin);
             fwrite(&emp[id].DOB,size,1,f);
             break;

             case 5:printf("ENTER ID: ");
             fflush(stdin);
             scanf("%d",&id);
             printf("\nENTER THE NEW PHONE NUMBER: ");
             fflush(stdin);
             scanf("%lf",&emp[id].Phone);
             fwrite(&emp[id].Phone,size,1,f);
             break;

            case 6:printf("ENTER ID: ");
            fflush(stdin);
             scanf("%d",&id);
             printf("\nENTER THE NEW SALARY: ");
             fflush(stdin);
             scanf("%lf",&emp[id].Salary);
             fwrite(&emp[id].Salary,size,1,f);
             break;

            case 7:printf("ENTER ID: ");
            fflush(stdin);
             scanf("%d",&id);
             printf("\nENTER THE NEW DESIGNATION: ");
             fflush(stdin);
             fgets(emp[id].Designation,20,stdin);
             fwrite(&emp[id].Designation,size,1,f);
             break;

            case 8:printf("ENTER ID: ");
            fflush(stdin);
             scanf("%d",&id);
             printf("\nENTER THE NEW QUALIFICATION: ");
             fflush(stdin);
             fgets(emp[id].Qualification,20,stdin);
             fwrite(&emp[id].Qualification,size,1,f);
             break;

             case 9:printf("ENTER ID: ");
             fflush(stdin);
             scanf("%d",&id);
             modify_password(0);
             break;

            case 10: printf("ENTER ID: ");
            fflush(stdin);
             scanf("%d",&id);
              printf("\nENTER THE NEW NAME: ");
              fflush(stdin);
             fgets(emp[id].Name,50,stdin);
              printf("\nENTER THE NEW AGE: ");
              fflush(stdin);
             scanf("%d",emp[id].Age);
             printf("\nENTER THE NEW ADDRESS: ");
             fflush(stdin);
             fgets(emp[id].Address,200,stdin);
             printf("\nENTER THE NEW DOB: ");
             fflush(stdin);
             fgets(emp[id].DOB,10,stdin);
              printf("\nENTER THE NEW PHONE NUMBER: ");
              fflush(stdin);
             scanf("%lf",&emp[id].Phone);
              printf("\nENTER THE NEW SALARY: ");
              fflush(stdin);
             scanf("%lf",&emp[id].Salary);
              printf("\nENTER THE NEW DESIGNATION: ");
              fflush(stdin);
             fgets(emp[id].Designation,20,stdin);
             printf("\nENTER THE NEW QUALIFICATION: ");
             fflush(stdin);
             fgets(emp[id].Qualification,20,stdin);
             fwrite(&emp[id],size,1,f);
             break;

            case 11:AdminMenu();break;

            case 12:work();break;
            default: printf("WRONG CHOICE\n");break;

             }fclose(f);
             printf("\nDO YOU WAANT TO CONTINUE(y/n)? :");
             ch=getche();
             if(ch=='y' || ch=='Y')modify(n);
             else AdminMenu();

         }
         else
         {
              printf("1. NAME\n");
              printf("2. AGE\n");
              printf("3. ADDRESS\n");
             printf("4. DOB\n");
             printf("5. PHONE\n");
             printf("6. PASSWORD\n");
             printf("7. ALL\n");
             printf("8. RETURN TO EMPLOYEE MENU\n");
             printf("9. RETURN TO MAIN MENU\n");
              printf("ENTER YOUR CHOICE: ");
              fflush(stdin);
             scanf("%d",&choice);
             switch(choice)
             {
             case 1:
             printf("\nENTER THE NEW NAME: ");
             fflush(stdin);
             fgets(emp[n].Name,50,stdin);
             fwrite(&emp[n].Name,size,1,f);
             break;

             case 2:
             printf("\nENTER THE NEW AGE: ");
             fflush(stdin);
             scanf("%d",emp[n].Age);
             fwrite(&emp[n].Age,size,1,f);
             break;

             case 3:
             printf("\nENTER THE NEW ADDRESS: ");
             fflush(stdin);
             fgets(emp[n].Address,200,stdin);
             fwrite(&emp[n].Address,size,1,f);
             break;

             case 4:
             printf("\nENTER THE NEW DOB: ");
             fflush(stdin);
             fgets(emp[n].DOB,10,stdin);
             fwrite(&emp[n].DOB,size,1,f);
             break;

             case 5:
             printf("\nENTER THE NEW PHONE NUMBER: ");
             fflush(stdin);
             scanf("%lf",&emp[n].Phone);
             fwrite(&emp[n].Phone,size,1,f);
             break;

             case 6:
             modify_password(n);break;

             case 7:
              printf("\nENTER THE NEW NAME: ");
              fflush(stdin);
             fgets(emp[n].Name,50,stdin);
              printf("\nENTER THE NEW AGE: ");
              fflush(stdin);
             scanf("%d",emp[n].Age);
             printf("\nENTER THE NEW ADDRESS: ");
             fflush(stdin);
             fgets(emp[n].Address,200,stdin);
             printf("\nENTER THE NEW DOB: ");
             fflush(stdin);
             fgets(emp[n].DOB,10,stdin);
              printf("\nENTER THE NEW PHONE NUMBER: ");
              fflush(stdin);
             scanf("%lf",&emp[n].Phone);
             fflush(stdin);
             fwrite(&emp[n],size,1,f);
             break;

             case 8: employeeMenu(n);break;
             case 9: work();break;
             default:  printf("WRONG CHOICE\n");break;

         }fclose(f);
         printf("\nDO YOU WAANT TO CONTINUE(y/n)? :");
             ch=getche();
             if(ch=='y' || ch=='Y')modify(n);
             else employeeMenu(n);}



}

void deleterecord()
{
    system("cls");
    int id, i=0;
    int isFound = 0;
    printf("Enter ID to Delete: ");
    fflush(stdin);
    scanf("%d",&id);
    FILE  *temp;
    f = fopen("Employee.dat","rb+");
    temp = fopen("temp.dat", "wb+");
    while(fread(&emp[i], size,1,f))
    {
        if(emp[id].Id==emp[i].Id)
        {
            i++;
            continue;
        }
        else
        {
            fwrite(&emp[i],size,1,temp);i++;
        }
    }
    fclose(f);
    fclose(temp);
    remove("Employee.dat");
    rename("temp.dat","Employee.dat");
    printf("The record is sucessfully deleted");
    int ch=getche();
    AdminMenu();
}

void modify_password(int n)
{
    char p[50];int ch;
    system("cls");
    f=fopen("Employee.dat","rb+");
    if(n==0)
    {
        printf("ENTER PREVIOUS PASSWORD: ");
        fflush(stdin);
        fgets(p,50,stdin);
        if(strcmp(emp[0].Password,p)==0)
        {
            printf("\nENTER THE NEW PASSWORD: ");
            fflush(stdin);
            fgets(emp[0].Password,50,stdin);
            fflush(stdin);
            fwrite(&emp[0].Password,size,1,f);
            printf("\nThe password is changed sucessfully");
            fclose(f);
            ch=getche();
            AdminMenu();

        }
        else{printf("WRONG PASSWORD");
        fclose(f);
        ch=getche();
        AdminMenu();}
    }
    else
    {
      printf("ENTER PREVIOUS PASSWORD: ");
      fflush(stdin);
        fgets(p,50,stdin);
        if(strcmp(emp[n].Password,p)==0)
        {
            printf("\nENTER THE NEW PASSWORD: ");
            fflush(stdin);
            fgets(emp[n].Password,50,stdin);
            fflush(stdin);
            fwrite(&emp[n].Password,size,1,f);
            printf("\nThe password is changed sucessfully");
            fclose(f);
            ch=getche();
            employeeMenu(n);

        }
        else{printf("WRONG PASSWORD");
        fclose(f);
        ch=getche();employeeMenu(n);}
    }

}

void employeeMenu(int n)
{
    char ch,choice;
    system("cls");
    do
    {
    system("cls");
    gotoxy(30,8);
    printf("EMPLOYEE MENU");
    gotoxy(30,10);
    printf("1. MODIFY RECORD");
    gotoxy(30,12);
    printf("2. VIEW RECORD");
    gotoxy(30,14);
    printf("3. RETURN TO MAIN MENU");
    gotoxy(30,16);
    printf("ENTER YOUR CHOICE: ");
    fflush(stdin);
    choice=getche();
    switch(choice)
    {
        case '1':modify(n);break;
        case '2':view_emp(n);break;
        case '3':work();break;
        default: printf("WRONG CHOICE\n");break;
    }
    printf("DO YOU WANT TO CONTINUE (y/n)? : ");
    fflush(stdin);
    ch=getche();

    }while(ch=='y' || ch=='Y');
    work();
}

void view_1(int n)
{
    system("cls");
    char ch,choice;
        gotoxy(30,14);
        printf("1. VIEW SPECIFIC");
        gotoxy(30,16);
        printf("2. VIEW ALL");
        gotoxy(30,18);
        printf("ENTER YOUR CHOICE: ");
        fflush(stdin);
        choice=getche();
        switch(choice)
        {
            case '1':if(n==0)
            {
                search_1(0);
            }
            else{

            search_1(1);
            }break;

            case '2':if(n==0)
            {
                view(0);
            }
            else{
            view(1);
            }break;
        default: printf("\nWRONG CHOICE");break;}
    work();
}

void view(int n)
{
    system("cls");
    int i=0,ans;
    f = fopen("Employee.dat","rb+");
        while(fread(&emp, size,1,f))
        {
            printf("ID: %d\n",emp[i].Id);
            printf("Name: %s\n",emp[i].Name);
            printf("Address: %s\n",emp[i].Address);
            printf("Age: %d\n",emp[i].Age);
            printf("DOB: %s\n",emp[i].DOB);
            fflush(stdin);
            if(n==0)
            {
                printf("Designation: %s\n",emp[i].Designation);
                fflush(stdin);
                printf("Qualifications: %s\n",emp[i].Qualification);
                fflush(stdin);
                printf("Salary: %lf\n",emp[i].Salary);
                fflush(stdin);
                printf("Phone no,: %lf\n",emp[i].Phone);
                fflush(stdin);
            }
            i++;
        }
    fclose(f);
    ans=getche();
}

void search_1(int n)
{
    system("cls");
    printf("Search Record\n");
    int id,i=0;
    int isFound = 0;
    printf("Enter ID to Search: ");
    fflush(stdin);
    scanf("%d",&id);
    f = fopen("Employee.dat","rb+");
    while(fread(&emp,size,1,f))
    {
        if(emp[id].Id==emp[i].Id)
        {
            isFound = 1;
            break;
        }
        i++;
    }
    if(isFound == 1)
    {
        printf("\nThe record is Found");
        fflush(stdin);
        printf("\nID: %d",emp[i].Id);
        fflush(stdin);
        printf("\nName: %s",emp[i].Name);
        fflush(stdin);
        printf("\nAddress: %s",emp[i].Address);
        fflush(stdin);
        printf("\nAge: %d",emp[i].Age);
        fflush(stdin);
        printf("\nDOB: %s",emp[i].DOB);
        fflush(stdin);
        if(n==0 || n==2)
        {
            printf("\nDesignation: %s",emp[i].Designation);
            fflush(stdin);
            printf("\nQualification: %s",emp[i].Qualification);
            fflush(stdin);
            printf("\nSalary: %lf",emp[i].Salary);
            fflush(stdin);
            printf("\nPhone no,: %lf",emp[i].Phone);
            fflush(stdin);

        }
    }
    else
    {
        printf("\nSorry, No record found in the database");
    }
    fclose(f);
    int ans=getche();
}

void view_emp(int id)
{
 system("cls");
    int i=0;
    int isFound = 0;
    f = fopen("Employee.dat","rb+");
        printf("\nID: %d",emp[id].Id);
        fflush(stdin);
        printf("\nName: %s",emp[id].Name);
        fflush(stdin);
        printf("\nAddress: %s",emp[id].Address);
        fflush(stdin);
        printf("\nAge: %d",emp[id].Age);
        fflush(stdin);
        printf("\nDOB(dd.mm.yyyy): %s",emp[id].DOB);
        fflush(stdin);
        printf("\nDesignation: %s",emp[id].Designation);
        fflush(stdin);
        printf("\nQualification: %s",emp[id].Qualification);
        fflush(stdin);
        printf("\nSalary: %lf",emp[id].Salary);
        fflush(stdin);
        printf("\nPhone no,: %lf",emp[id].Phone);
        fflush(stdin);

    fclose(f);
    int ans=getche();
}






