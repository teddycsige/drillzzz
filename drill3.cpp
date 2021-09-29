#include "std_lib_facilities.h"
int main(){
cout << "Enter the name of the person you want to write to" <<endl;
string first_name;
cin >> first_name;
cout << "Dear " << first_name << "," << endl;
cout <<"How are you? I'm fine. I miss you. Sorry for not writing, I've been quite busy lately. " << endl;
cout << "Enter your friend's name" <<endl;
string friend_name;
cin >> friend_name;
cout << "Have your seen "<< friend_name << " lately" <<endl;
char friend_sex='0';
cout << "Please enter your friend's gender (m or f)" << endl;
cin>>friend_sex;
if(friend_sex=='m')
cout << "If you see " << friend_name << " please ask him to call me." << endl;
if(friend_sex=='f')
cout << "I you see " << friend_name << " please ask her to call me." << endl;
int age=0;
cout<<"Please enter your friend's age"<< endl;
cin>>age;
cout<< "I heard you just had a birthday and you are " << age << " years old" << endl;
if(age<=0 || age>=110)
simple_error("you're kidding");
if(age<12)
cout << "Next year you will be " << age +1 << endl;
if (age ==17)
cout << "Next year you will be able to vote" << endl;
if(age>70)
cout << "I hope your are enjoying retirement" << endl;
cout << "Your sincerely" << endl;
cout << endl;
cout << endl;
cout << "Teddy" << endl;
return 0;
}
