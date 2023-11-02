#include<iostream>
using namespace std;

// class Test{
// int a;
// public:
// void in(){
//     cin>>a;
// }
// void out(){
//     cout<<a;
// }
// };

class Marks{
int a,b,c;
public:
void in(){
    cout<<"Enter three marks : ";
    cin>>a>>b>>c;
}
int sum(){
return a+b+c;
}
float avg(){
    float avg = (a+b+c)/3;
    return avg;
}

};
int main(){

//  Test test1;
//  test1.in();
//  test1.out();

Marks obj1;
obj1.in();
float avg = obj1.avg();
int sum = obj1.sum();
cout<<"Sum is : "<<sum<<endl<<"Avg is : "<<avg;
    return 0;
}