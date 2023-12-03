#include<iostream>
using namespace std;
int counter = 0;
struct user
{
    int accno;
    string accname;
};
user *arr[100];
void addStudent();
void display();

int main(){
    char ch;
do{
cout<<"1. Add Student";
cout<<"2. Display";
cout<<"0. exit";
cin>>ch;
if(ch=='1'){
    addStudent();
}
else if(ch =='2'){
    display();
}else{
    break;
}

}
while(ch !=0);

}

void addStudent()
{
user *us = new user;
cout << "enter name";
cin >> us->accname;
cout << "enter you account number";
cin >> us->accno;
arr[counter++] = us;
}
void display(){

for(int i =0; i<counter; i++){
cout<<arr[i]->accname;
cout<<arr[i]->accno<<endl;

}

}