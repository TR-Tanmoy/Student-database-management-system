#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

FILE *ton,*moy,*LL;

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
