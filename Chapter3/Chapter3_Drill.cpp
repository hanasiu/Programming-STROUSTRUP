#include "std_lib_facilities.h" // header provided by the authour. 
//https://www.stroustrup.com/Programming/std_lib_facilities.h
#include <iostream>

using namespace std;

int main() {
	cout << " How are you? I am fine. I miss you.\n";
	cout << "Enter the name of the person you want to write to\n";
	string first_name;
	cin >> first_name;
	cout << "Dear " << first_name << ",\n";
	string friend_name;
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?\n";
	char friend_sex = 0;
	cout << "if the frined is male enter an m and if the frined is female enter an f.\n";
	cin >> friend_sex;
	if (friend_sex == 'm' || friend_sex == 'M')
	{
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	}
	else if (friend_sex == 'f' || friend_sex == 'F')
	{
		cout << "If you see " << friend_name << " please ask her to call me.\n";
	}
	int age;
	cout << "Enter the age of the recipeint";
	
	while(cin >> age){
	if (age <= 0 || age >= 110)
	{
		simple_error("you're kidding!");
	} else {
		cout << "I hear you just had a birthday and you are " << age <<
			" years old.\n";
		break;
	}
	}
	if (age <= 12)
	{
		cout << "Next year you will be " << age + 1 << ".\n";
	}
	else if (age == 17)
	{
		cout << "Next year you will be able to vote.\n";
	}
    else if (age >= 70)
	{
		cout << "I hope you are enjoying retirement.\n";
	}
	cout << "Yours sincerely, \n\n\n" << "Kim You\n";

}
