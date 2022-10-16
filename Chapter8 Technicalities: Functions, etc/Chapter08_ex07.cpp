#include "std_lib_facilities.h"

using namespace std;

void read_values(vector<string>& name, vector<double>& age) {
	string temp;
	cout << "Enter list of names. 'stop' if you want to stop\n";
	while (cin >> temp && temp != "stop") {
		for (int i = 0; i < name.size(); ++i) {
			if (temp == name[i]) error("Duplicate name");
		}
		name.emplace_back(temp);
	}
	double num;
	for (int i = 0; i < name.size(); ++i) {
		cout << "Age of " << name[i] << " is ";
		cin >> num;
		age.emplace_back(num);
	}
}

void print(const vector<string>& name, const vector<double>& age) {
	if (name.size() != age.size()) error("print: vectors must be same size");
	for (int i = 0; i < name.size(); ++i) {
		cout << '(' << name[i] << ',' << age[i] << ")\n";
	}
}

void print(string label, const vector<string> vec) {
	cout << label << " (" << vec.size() << "): {";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i];
		if (i < vec.size() - 1) cout << ", ";
	}
	cout << "}\n";
}

int findIndex(const vector<string>& name, const string& s) {
	for (int i = 0; i < name.size(); ++i) {
		if (name[i] == s)
			return i;
	}
	error("name not found");
}


int main() 
try {
	vector<string> name;
	vector<double> age;
	read_values(name, age);
	print(name, age);
	vector<string> copyName = name;
	vector<double> copyAge = age;
	sort(name.begin(), name.end());
	for (int i = 0; i < name.size(); ++i) {
		age[i] = copyAge[findIndex(copyName, name[i])];
	}
	cout << "After sorting" << endl;
	print(name, age);

}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
