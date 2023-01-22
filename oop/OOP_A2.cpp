#include <iostream>
#include <string.h>

using namespace std;
class studdata;

class student{
    string name;
    int roll_no;
    string cls;
    char* division;
    string dob;
    char* bloodgroup;
    static int count;

    public:

    student()
    {
        name="";
        roll_no=0;
        cls="";
        division=new char;
        dob="dd/mm/yyyy";
        bloodgroup=new char[4];
    }

    ~student()
    {
        delete division;
        delete bloodgroup;

    }

    static int getcount()
    {
        return count;
    }

    void getdata(studdata*);
    void dispdata(studdata*);
};

class studdata
{
    string caddress;
    long int* telno;
    long int* dlno;
    friend class student;

    public:

    studdata()
    {
        caddress="";
        telno=new long;
        dlno=new long;
    }
    ~studdata()
    {
        delete telno;
        delete dlno;
    }

    void getstuddata()
    {
        cout<<"Enter contact address: ";
        cin.get();
        getline(cin,caddress);
        cout<<"Enter telephone number: ";
        cin>>*telno;
        cout<<"Enter driving license number: ";
        cin>>*dlno;
    }

    void dispstuddata()
    {
        cout<<"Contact address: "<<caddress<<endl;
        cout<<"Telephone number: "<<*telno<<endl;
        cout<<"Driving license number: "<<*dlno<<endl;
    }
};

inline void student::getdata(studdata* st)
{
    cout<<"Enter student name: ";
    getline(cin,name);
    cout<<"Enter roll number: ";
    cin>>roll_no;
    cout<<"Enter class: ";
    cin.get();
    getline(cin,cls);
    cout<<"Enter division: ";
    cin>>division;
    cout<<"Enter date of birth: ";
    cin.get();
    getline(cin,dob);
    cout<<"Enter blood group: ";
    cin>>bloodgroup;
    st->getstuddata();
    count++;
}

inline void student::dispdata(studdata* st1)
{
    cout<<"Student name : "<<name<<endl;    
    cout<<"roll no. : "<<roll_no<<endl;    
    cout<<"class : "<<cls<<endl;    
    cout<<"division : "<<division<<endl;    
    cout<<"date of birth : "<<dob<<endl;    
    cout<<"blood group : "<<bloodgroup<<endl;    
    st1->dispstuddata();

}

int student::count;

int main()
{
    student* stud1[100];
    studdata* stud2[100];
    int n=0;
    char ch;
    do 
    {
        stud1[n]=new student;
        stud2[n]=new studdata;
        stud1[n]->getdata(stud2[n]);
        n++;
        cout<<"Do you want to add another student (y/n) : ";
        cin>>ch;
        cin.get();
    }
    while(ch=='y'|| ch=='Y');
    for(int i=0;i<n;i++)
    {
        cout<<"---------------------------------------"<<endl;
        stud1[i]->dispdata(stud2[i]);

    }
    cout<<"-------------------------------------------"<<endl;
    cout<<"Total students: "<<student::getcount();
    cout<<endl<<"--------------------------------------"<<endl;

    for (int i=0;i<n;i++)
    {
        delete stud1[i];
        delete stud2[i];

    }
    return 0;
}