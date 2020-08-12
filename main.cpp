#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

FILE *ton,*moy,*LL;

///Initializing Functions
struct student
{
    char f_name[50],l_name[50],id[50],dpt[50],DOB[50],bld_Group[5],phn[50],eml[50],btch[50];
}st;

long int recordSZ=sizeof(st);

struct lock{
    char userName[50],passWord[50];
}L;
long int rcLock=sizeof(L);


///Function for Adding Data to the Database...
void addData(){
    char dif;
    fseek(ton,0,SEEK_END);
    dif='y';
    while(dif=='y'||dif=='Y')
    {
        system("cls");
        cout<<"\n\t\t\t\t     ====Add Data====\n\n\n\n";
        cout<<"Enter First Name\t\t::";
        cin>>st.f_name;
        cout<<"Enter Last Name\t\t\t::";
        cin>>st.l_name;
        cout<<"Enter ID-Number\t\t\t::";
        cin>>st.id;
        cout<<"Enter Department\t\t::";
        cin>>st.dpt;
        cout<<"Enter Date of Birth\t\t::";
        cin>>st.DOB;
        cout<<"Enter Blood Group\t\t::";
        cin>>st.bld_Group;
        cout<<"Enter Phone Number\t\t::";
        cin>>st.phn;
        cout<<"Enter E-mail Address\t\t::";
        cin>>st.eml;
        cout<<"Enter Batch Name\t\t::";
        cin>>st.btch;
        fwrite(&st,recordSZ,1,ton);
        cout<<"\n\nAdd more data(Y/N)::";
        fflush(stdin);
        dif=getchar();
    }
    fclose(ton);
}

///Function for Showing all Data from Database...
void viewData(){
    rewind(ton);
    int x=1;
    system("cls");
    cout<<"\n\t\t\t\t    ====View Data====\n\n\n\n";

    while(fread(&st,recordSZ,1,ton)==1)
    {
        cout<<"\n"<<x<<"..\n\t\tName\t\t\t:: "<<st.f_name<<" "<<st.l_name;
        cout<<"\n\t\tID-Number\t\t:: "<<st.id<<"\n\t\tDepartment\t\t:: "<<st.dpt;
        cout<<"\n\t\tDate of Birth\t\t:: "<<st.DOB<<"\n\t\tBlood Group\t\t:: "<<st.bld_Group;
        cout<<"\n\t\tPhone Number\t\t:: "<<st.phn<<"\n\t\tE-mail Address\t\t:: "<<st.eml<<"\n\t\tBatch Name\t\t:: "<<st.btch;
        x++;
    }
    cout<<"\n\n";
    getch();
}

///Function for Searching Individual Data from Database...
void searchData(){
    char dif,xid[10],n='n';
    dif='y';
    while(dif=='y'||dif=='Y')
    {
        system("cls");
        cout<<"\n\t\t\t\t    ====Search Data====\n\n\n\n";
        cout<<"\t\t\tEnter ID-Number to Search Data\n\t\t\t--->>>";
        cin>>xid;
        rewind(ton);
        while(fread(&st,recordSZ,1,ton)==1)
        {
            if(strcmp(st.id,xid)==0)
            {
                cout<<"\n\t\tName\t\t\t:: "<<st.f_name<<" "<<st.l_name;
                cout<<"\n\t\tID-Number\t\t:: "<<st.id<<"\n\t\tDepartment\t\t:: "<<st.dpt;
                cout<<"\n\t\tDate of Birth\t\t:: "<<st.DOB<<"\n\t\tBlood Group\t\t:: "<<st.bld_Group;
                cout<<"\n\t\tPhone Number\t\t:: "<<st.phn<<"\n\t\tE-mail Address\t\t:: "<<st.eml<<"\n\t\tBatch Name\t\t:: "<<st.btch;
                n='z';
            }
        }
        if(n!='z'){cout<<"\n\n\n\t\"Not Found in Database\"";}
        cout<<"\n\n";
        getch();
        cout<<"View more Data(Y/N)::";
        fflush(stdin);
        dif=getchar();
    }
}
///Function for Editing Data from Database...
void editData(){
    system("cls");
    char dif,xid[10],n='n';
    cout<<"\n\t\t\t\t    ====Edit Data====\n\n\n\n";
    dif='y';
    while(dif=='y'||dif=='Y')
    {
        cout<<"\t\tEnter ID-Number to edit data\n\n\t\t--->>>";
        cin>>xid;
        rewind(ton);
        while(fread(&st,recordSZ,1,ton)==1)
        {
            if(strcmp(st.id,xid)==0)
            {
                cout<<"Enter First Name\t\t::";
                cin>>st.f_name;
                cout<<"Enter Last Name\t\t\t::";
                cin>>st.l_name;
                cout<<"Enter ID-Number\t\t\t::";
                cin>>st.id;
                cout<<"Enter Department\t\t::";
                cin>>st.dpt;
                cout<<"Enter Date of Birth\t\t::";
                cin>>st.DOB;
                cout<<"Enter Blood Group\t\t::";
                cin>>st.bld_Group;
                cout<<"Enter Phone Number\t\t::";
                cin>>st.phn;
                cout<<"Enter E-mail Address\t\t::";
                cin>>st.eml;
                cout<<"Enter Batch Name\t\t::";
                cin>>st.btch;
                fseek(ton,-recordSZ,SEEK_CUR);
                fwrite(&st,recordSZ,1,ton);
                n='z';
                break;
            }
        }
        if(n!='z'){cout<<"\n\n\n\t\"Not Found in Database\"";}
        cout<<"Edit more data(Y/N)::";
        fflush(stdin);
        dif=getchar();
    }
}
///Function for Deleting Data from Database...
void deleteData(){
    char dif,xid[5];
    system("cls");
    cout<<"\n\t\t\t\t   ====Delete Data====\n\n\n\n";
    dif='y';
    while(dif=='y'||dif=='Y')
    {
        cout<<"\t\tEnter the ID-Number to delete data\n\n\t\t--->>>";
        cin>>xid;
        moy=fopen("Test.txt","w+");
        rewind(ton);
        while(fread(&st,recordSZ,1,ton)==1)
        {
            if(strcmp(st.id,xid)!=0)
            {
                fwrite(&st,recordSZ,1,moy);
            }
        }
        fclose(ton);
        fclose(moy);
        remove("Tonmoy.txt");
        rename("Test.txt","Tonmoy.txt");
        ton=fopen("Tonmoy.txt","r+");
        cout<<"Delete more data(Y/N)";
        fflush(stdin);
        dif=getchar();
    }
}
///Function for Showing Developers Information...
void aboutDevelopers(){
    system("cls");
    cout<<"\n\t\t\t      ====Developer Information====\n\n\n\n";
    cout<<"Developer::\n\tName\t\t::Md. Tahadur Rahman\n\tID-Number\t::CSE-11170320115\n\tDepartment\t::CSE\n\tPhone Number\t::01754-198218\n\tE-mail Address\t::trtanmoy1@gmail.com\n\tBatch Name\t::Fall 2017";
    getch();
}


///Security Functions...
void signUp(){
    system("cls");
    LL=fopen("Lock.o","w+");
    char choice;
    cout<<"\n\t\t\t\t    ==== Welcome ====\n\n\n\n";
    cout<<"\n\t\t\t\t==========================\n";
    cout<<"\t\t\t\t1.SIGN UP\n\t\t\t\t2.EXIT";
    cout<<"\n\t\t\t\t==========================\n";
    cout<<"\n\t\t\t\t--->>>";
    fflush(stdin);
    choice=getche();

    switch (choice)
    {
        case '1':
            system("cls");
            cout<<"\n\t\t\t\t    ==== SignUp ====\n\n\n\n";
            cout<<"Enter a New Username\t\t::";
            cin>>L.userName;
            cout<<"Enter a New Password\t\t::";
            cin>>L.passWord;
            fwrite(&L,rcLock,1,LL);
            fclose(LL);
            break;
        case '2':
            exitPrograms();
            break;
    }
}

void changePassword(){
    LL=fopen("Lock.o","r+");
    fread(&L,rcLock,1,LL)==1;
    char user[20],pass[20];
    system("cls");
    cout<<"\n\t\t\t\t    ==== Change Password ====\n\n\n\n";
    cout<<"Enter Current Username\t\t::";
    cin>>user;
    cout<<"Enter Current Password\t\t::";
    cin>>pass;
    if((strcmp(L.userName,user)==0)&&(strcmp(L.passWord,pass)==0)){
        cout<<"Enter New Username\t\t::";
        cin>>L.userName;
        cout<<"Enter New Password\t\t::";
        cin>>L.passWord;
        fseek(LL,-rcLock,SEEK_CUR);
        fwrite(&L,rcLock,1,LL);
        fclose(LL);
        cout<<"Your Password has been changed Successfully.....";
        getch();
    }
    else{
        cout<<"\n\nYou Entered wrong username or password, So, You are an unauthorized person to change the password, Good Bye.....";
        getch();
        exitPrograms();
    }
}


void logIn(){
    LL=fopen("Lock.o","r+");
    fread(&L,rcLock,1,LL)==1;
    char choice;
    int i=1;
    cout<<"\n\t\t\t\t    ==== Welcome ====\n\n\n\n";
    cout<<"\n\t\t\t\t==========================\n";
    cout<<"\t\t\t\t1.LOG IN\n\t\t\t\t2.CHANGE PASSWORD\n\t\t\t\t3.EXIT";
    cout<<"\n\t\t\t\t==========================\n";
    cout<<"\n\t\t\t\t--->>>";
    fflush(stdin);
    choice=getche();
    switch (choice)
    {
        case '1':
            system("cls");
            cout<<"\n\t\t\t\t    ==== LogIn ====\n\n\n\n";
            char user[20],pass[20];
            cout<<"Enter the Username\t\t::";
            cin>>user;
            cout<<"Enter the Password\t\t::";
            cin>>pass;
            while((strcmp(L.userName,user)!=0)&&(strcmp(L.passWord,pass)!=0)){
                i++;
                system("cls");
                cout<<"\n\t\t\t\t    ==== LogIn ====\n\n\n\n";
                cout<<"Enter the Username\t\t::";
                cin>>user;
                cout<<"Enter the Password\t\t::";
                cin>>pass;
                if(i==3){getch();cout<<"You entered Either wrong username or wrong password for three times. \nGood Bye...";getch();exitPrograms();}
            }
            break;
        case '2':
            changePassword();
            break;
        case '3':
            exitPrograms();
            break;
    }
}


///Head Security Panel.
void Security(){
    LL=fopen("Lock.o","r+");
    if(LL==NULL){
        signUp();
    }
    else{
        logIn();
    }
}

int main(void){
    system("color 1A");
    Security();
    DisplayMainMenu();
}
