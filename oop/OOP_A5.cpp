#include<iostream>
using namespace std;
template <class T>
class sort{
T *arr;
int size;
public:
    sort(int n){
    size=n;
    arr = new T[size];
    }
    void getdata(){
        cout<<"Enter values ";
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
    }
    void sorting(){
        cout<<"\n Array before sorting : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        int min;
        T temp;
        for(int i=0;i<size;i++){
            min=i;
            for(int j=i+1;j<size;j++){
                if(arr[j]<arr[min]){
                    min=j;
                }
            }
            if(min!=i){
                temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
            }
        }
        cout<<"\n Array after sorting : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n \n ";
    }
};

int main()
{ 
    int n; 
    int ch;
    do{
        cout<<"Selection sort : \n1.Integer \n2.Floating number \n3.Exit \n";
        cout<<"Enter your choice : ";
        cin>>ch;
        if(ch==1){
            cout<<"Enter size ";
            cin>>n;
            sort <int>s1(n); 
            s1.getdata();
            s1.sorting();
        }
        else if (ch==2){ 
            cout<<"Enter size ";
            cin>>n;
            sort <float>s1(n);
            s1.getdata();
            s1.sorting();
        }
    }
    while(ch==1 or ch==2);
    return 0;
}
