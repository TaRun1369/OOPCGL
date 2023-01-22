#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

map <string, int> m1 ;
m1["Maharashtra"] = 3000000;
m1["Gujrat"] = 25000000;
m1["Rajsthan"] = 20000000;
m1["Punjab"] = 12500000;
m1["Karnataka"] = 3000000;


string state ;
cout<<"Enter name of state you want to find population of : "<<endl;
cin>>state;
cout<<"Population of state "<<state<<" is "<<m1[state]<<endl;

return 0;
}