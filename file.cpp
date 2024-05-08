#include<iostream>
#include<fstream>
using namespace std;
class student
{
 int rollno;
 char name[10];
 public:
 void getdata();
 void readdata();
};
void student::getdata()
{
 cout<<"enter the roll no of the student:\n";
 cin>>rollno;
 cout<<"\nenter the name of the student:\n";
 cin>>name;
}
void student::readdata()
{
 cout<<"the roll no of the student::"<<rollno<<endl;
 cout<<"the name of the student::"<<name<<endl;
}
int main()
{
 student s[10];
 fstream f;
 int i,n;
 f.open("t1.txt",ios::out);
 cout<<"how many records do you want to print: "<<endl;
 cin>>n;
 for (i=0;i<n;i++)
 {
 s[i].getdata();
 f.write((char*) &s[i], sizeof(s[i]));
 }
 f.close();
 f.open("t1.txt",ios::in);
 for(i=0;i<n;i++)
 {
 s[i].readdata();
 f.read((char*) &s[i], sizeof(s[i]));
 }
 f.close();
}

/*output;
how many records do you want to print: 
1
enter the roll no of the student:
1
enter the name of the student:
ram
the roll no of the student::1
the name of the student::ram*/