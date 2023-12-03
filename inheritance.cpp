#include<iostream>
using namespace std;

class Human{
protected : 
int walkTime,sleepTime,eatTime;

public :
void walk(){
    cout<<"My walk time is :"<<walkTime<<endl;
}
void sleep()
{
    cout<<"My Sleep time is :"<<sleepTime<<endl;
}
void eat(){
    cout<<"My eat time is :"<<eatTime<<endl;
}
void input(){
    cout<<"Enter Walk Time :";
    cin>>walkTime;
    cout<<"Enter sleep Time :";
    cin>>sleepTime;
    cout<<"Enter eat Time :";
    cin>>eatTime;
}


};

class Numan : public Human{
    private:
    string name;
    int age;
    public:
    void getInput(){
        cout<<"Enter Your Name : ";
        cin>> name;
        cout<<"Enter Your Age :";
        cin>> age;
    }
    void display(){
        cout<<"My name is "<<name<<endl;
        cout<<"My age is "<<age<<endl;

    }
};


int main (){

Numan person;
person.input();
person.sleep();
person.getInput();
person.display();


    return 0;
}