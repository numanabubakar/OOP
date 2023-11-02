#include<iostream>
using namespace std;

class Test{
int a;
public:
void in(){
    cin>>a;
}
void out(){
    cout<<a;
}
};
int main(){

 Test test1;
 test1.out();
 test1.in();
 test1.out();

    return 0;
}