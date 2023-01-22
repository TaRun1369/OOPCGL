#include <iostream>
using namespace std;

int count=0;

class complex 
{
private:
    float real,imag;
public:
    complex()
    {
        if (count==0)
        {
            real=0;
            count=count+1;
            imag=0;
            cout<<real<<"+"<<imag<<"i"<<endl;
        }
    }
 
    complex operator +(complex c)
    {
        complex temp;
        temp.real=real+c.real;
        temp.imag=imag+c.imag;
        return temp;
    }

    complex operator *(complex c)
    {
        complex temp;
        temp.real=(real*c.real)-(imag*c.imag);
        temp.imag=(real*c.imag)+(imag*c.real);
        return temp;
    }

    friend complex operator << (ostream&out,complex&c)
    {
        cout<<c.real<<"+"<<c.imag<<"i "<<endl;
    }

    friend complex operator >> (istream&in,complex&c)
    {
        cout<<"Enter real part"<<endl;
        cin>>c.real;
        cout<<"Enter imaginary part"<<endl;
        cin>>c.imag;
    }
};

int main()
{
    complex c1,c2,c3,c4;
    cout<<"Enter value of c1"<<endl;
    cin>>c1;
    cout<<"Enter value of c2"<<endl;
    cin>>c2;

    c3=c1+c2;
    c4=c1*c2;

    cout<<"Sum is: "<<c3;
    cout<<"Product is: "<<c4;
}