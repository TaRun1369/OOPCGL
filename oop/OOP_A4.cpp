#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream fo;
    fo.open("assignment.txt",ios::out);
    string name;
    string roll;
    cout<<"File opearations \n";
    cout<<"Enter name ";
    cin>>name;
    fo<<name<<endl;
    cout<<"Enter roll no. ";
    cin>>roll;
    fo<<roll<<endl;
    cout<<"File created successfully \n";
    fo.close();
    string temp1;
    string temp2;
    ifstream fi;
    fi.open("assignment.txt",ios::in);
    fi>>temp1;
    fi>>temp2;
    cout<<"Name is "<<temp1<<endl;
    cout<<"Roll no. is "<<temp2<<endl;
    fi.close();
}


