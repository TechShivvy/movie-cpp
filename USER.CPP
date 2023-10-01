#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
class USER
{
public:
char USERNAME[25];
char PASSWORD[25];
static int i;
}u[20];
int USER::i=0;
void createacc(fstream obj)
{
char rep;
cout<<"\nDO YOU HAVE AN ACCOUNT?...(y/n)";
gets(rep);
if(rep=='y')
{
cout<<"\nOK... BYE";
}
if(rep=='n')
{
cout<<"\nOK THEN... LETS GET STARTED...";
cout<<"\nENTER A USERNAME :";
for(;i<20;)
{
gets(u[i].USERNAME);
cout<<"\nENTER A PASSWORD :";
gets(u[i].PASSWORD);
obj.open("USERID.txt",ios::in|ios::out|ios::binary);
obj.write((char*)&u[i], sizeof(u[i]));
cout<<endl;
}
}
}
void main()
{
fstream obj;
createacc(obj);
getch();
}