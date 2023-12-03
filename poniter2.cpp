#include<iostream>
using namespace std;
struct book{
    string name;
    int price;
};

int main(){

// int arr[5];
// for(int i=0;i<5;i++){
//     cout<<"enter 5 number";
//     cin>>arr[i];
// }
// int *p=arr;
// for (int i = 0; i <5; i++)
// {
//     cout<<*p++<<endl;
// }
book rec,*ptr;
ptr=&rec;
ptr->name="physics";
ptr->price=100;
cout<<rec.name;
cout<<rec.price;
cout<<ptr->name;
cout<<ptr->price;



    return 0;
}