#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
class USER
{
 char un[25];
 char pw[25];
 public:
 void login()
{
 int c=0; char temp;
 char chu[25];
 char chp[25];
 fstream obj;
 obj.open("ACCINFO.dat",ios::in|ios::out|ios::binary);
 cout<<"\nEnter the Username: ";
 gets(l.un);
 cout<<"\nEnter the Password: ";
 for(int i=0;i>=0;)
 {
  char temp=getch();
  if(((int)temp)!='\r' && ((int)temp)!='\b')
  {
   cout<<"*";
   l.pw[i]=temp;
   i++;
  }
  else if(((int)temp)=='\b')
  {
   cout<<"\b \b";
   i--;
  }
  else if(((int)temp)=='\r')
  {
   l.pw[i]='\0';
   i=-1;
  }
  break;
 }
 while(!obj.eof())
 {
  obj>>chu;
  if(strcmp(chu,l.un)==0)
  {
   c=1;
   obj>>chp;
   if(strcmp(chp,l.pw)==0)
    cout<<"\nWELCOME TO ORIENT CINEMAS!!";
   else
    cout<<"\nYou entered the wrong password..";
   break;
  }
 }
 if(c==0)
  cout<<"\nYou entered the wrong username..";
  obj.close();
}
 void signup()
{
 fstream obj;
 obj.open("ACCINFO.dat",ios::in|ios::out|ios::binary);
 cout<<"\nEnter a Username: ";
 gets(s.un);
 cout<<"\nEnter a Password: ";
 for(int i=0;i>=0;)
 {
 char temp=getch();
 if(((int)temp)!='\r' && ((int)temp)!='\b')
 {
  cout<<"*";
  s.pw[i]=temp;
  i++;
 }
 else if(((int)temp)=='\b')
 {
  cout<<"\b \b";
  i--;
 }
 else if(((int)temp)=='\r')
 {
  s.pw[i]='\0';
  i=-1;
 }
 break;
 }
 obj.seekg(0,ios::end);
 obj<<s.un<<" "<<s.pw<<endl;
 cout<<endl;
 cout<<"\nSuccessfully Registered!!";
 obj.close();
}

}l,s;


void main()
{
 clrscr();
 char ch;
 cout<<"Do you have an account?(y/n)";
 cin>>ch;
 switch(ch)
 {
  case 'y':
  case 'Y':login();
	   break;
  case 'n':
  case 'N':signup();
	   break;
  default:"\nInavlid Choice!!";
 }
 getch();
}

