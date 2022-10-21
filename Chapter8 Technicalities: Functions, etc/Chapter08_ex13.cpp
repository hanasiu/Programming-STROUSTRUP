#include "std_lib_facilities.h"

using namespace std;

// print vector of integers
void print(const vector<int>& v)
{
	cout << "{ ";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << " }\n";
}

// print vector of strings
void print(const vector<string>& v)
{
	cout << "{ ";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << " }\n";
}

vector<int> numOfChar(const vector<string>& vec) {
	if (vec.size() == 0) error("argument is empty vector");
	vector<int> num;
	for (auto i : vec) {
		num.emplace_back(i.size());
	}
	return num;
}

void longAndShort(vector<string> vec, vector<string>& longest, vector<string>& shortest) {
	if (vec.size() == 0) error("argument is empty vector");
	sort(vec.begin(), vec.end(), [](string a, string b) { // ladbda function for predicate
		return a.size() < b.size();
		});
	shortest.emplace_back(vec[0]);
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i].size() == shortest[0].size()) shortest.emplace_back(vec[i]);
		else break;
	}
	longest.emplace_back(vec[vec.size() - 1]);
	for (int i = vec.size() - 2; i >= 0; --i) {
		if (vec[i].size() == longest[0].size()) longest.emplace_back(vec[i]);
		else break;
	}
}

void firstAndLast(const vector<string>& vec, string& first, string& last) {
	if (vec.size() == 0) error("argument is empty vector");
	first = vec[0];
	last = vec[0];
	for (auto i : vec) {
		if (i < first) first = i;
		if (i > last) last = i;
	}
}



int main() 
try {
	vector<string> example = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	vector<string> longest;
	vector<string> shortest;
	string first;
	string last;
	vector<int> result = numOfChar(example);
	cout << "the number of characters in each string: ";
	print(result);
	longAndShort(example, longest, shortest);
	cout << "the longest string: ";
	print(longest);
	cout << "the shortest string: ";
	print(shortest);
	firstAndLast(example, first, last);
	cout << "lexicographically first: " << first << endl
		<< "lexicographically last: " << last << endl;
	

}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
