#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
class moviez
{
public:
char mname[15];
int mcode;
char mdesc[100];
}M;
void movielist()
{
fstream m;
m.open("mvslst.txt",ios::in|ios::out|ios::binary);
cout<<"\n1.Add";
cout<<"\n2.Remove";
int c;
cin>>c;
char r;
int code;
fstream t;
t.open("temp.txt",ios::in|ios::out|ios::binary);
switch(c)
{
case 1:
do
{
cout<<"\nEnter The Name Of The Movie";
gets(M.mname);
cout<<"\nEnter The Movie Code Number";
cin>>M.mcode;
cout<<"\nEnter The Descrption Of The Movie";
gets(M.mdesc);
m.write((char *)&M, sizeof(M));
cout<<"\nDo You Want To Enter More Movies?..(y/n)";
cin>>r;
if(r=='n'||r=='N')
break;
}
while(r=='y'||r=='Y');
break;
case 2:
cout<<"Enter The Movie Code Number That You Want To Be Removed";
cin>>code;
while(!m.eof())
{
if(M.mcode!=code)
{
m.read((char *)&M,sizeof(M));
t.write((char *)&M,sizeof(M));
}
else{;}
}
remove("mvslst.txt");
rename("temp.txt","mvslst.txt");
break;
default:cout<<"\nInvalid Choice...";
}
}
void main()
{
clrscr();
int chances=1;
char c;
char pas[20];
cout<<"\nAre You An Administrator?..(y/n)";
cin>>c;
if(c=='y'||c=='Y')
{
cout<<"\nEnter The Password( You Have Got 3 Tries To Enter The Correct Password )";
while(chances<=3)
{
chances++;
gets(pas);
if(strcmp(pas,"Dhandam")==0)
{
cout<<"\nYou Got It Correct...Good for You";
movielist();
break;
}
else
cout<<"\nWrong... ";
}
if(strcmp(pas,"Dhandam")!=0)
cout<<"\nLiar...You Are Not Za Admin..Get Outta Ma Face";
}
else
cout<<"\nk bye";
getch();
}
