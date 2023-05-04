#include "std_lib_facilities.h"

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print() const;
	void sort();
	const vector<string>& get_name() const { return names; };
	const vector<double>& get_age() const { return ages; };
private:
	vector<string> names;
	vector<double> ages;
};

void Name_pairs::read_names()
{
	cout << "Enter names, 'stop' to finish\n";
	string temp;
	while (cin >> temp && temp != "stop") {
		for (int i = 0; i < names.size(); ++i) {
			if (names[i] == temp) error("Name exists already: ", temp);
		}
		names.emplace_back(temp);
	}
}

void Name_pairs::read_ages()
{
	for (string i : names) {
		cout << i << "'s age: ";
		int j;
		cin >> j;
		ages.emplace_back(j);
	}
}

void Name_pairs::print() const
{
	if (names.size() != ages.size())
		error("print(): names and ages must be the same size");
	for (int i = 0; i < names.size(); ++i) {
		cout << names[i] << ": " << ages[i] << endl;
	}
}

void Name_pairs::sort()
{
	if (names.size() != ages.size())
		error("sort(): names and ages must be the same size");
	vector<string> tempNames = names;
	vector<double> tempAges = ages;
	std::sort(names.begin(), names.end());
	for (int i = 0; i < names.size(); ++i) {
		for (int j = 0; j < tempNames.size(); ++j) {
			if (names[i] == tempNames[j]) ages[i] = tempAges[j];
		}
	}
}

ostream& operator<<(ostream& os, const Name_pairs& np)
{
	if (np.get_name().size() != np.get_age().size()) error("<<: names and ages must be the same size");
	for (int i = 0; i < np.get_name().size(); ++i) {
		os << np.get_name()[i] << ": " << np.get_age()[i] << endl;
	}
	return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	if (a.get_name().size() != b.get_name().size() && a.get_age().size() != b.get_age().size())
		return false;
	for (int i = 0; i < a.get_name().size(); ++i) {
		if (a.get_name()[i] != b.get_name()[i])
			return false;
	}
	for (int i = 0; i < a.get_age().size(); ++i) {
		if (a.get_age()[i] != b.get_age()[i])
			return false;
	}
	return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b) {
	return !(a == b);
}

int main() 
	try {
		Name_pairs np1;
		np1.read_names();
		np1.read_ages();
		Name_pairs np2;
		np2.read_names();
		np2.read_ages();
		cout << "np1:\n" << np1;
		cout << "np2:\n" << np2;
		if (np1 == np2) cout << "Identical!\n";
		if (np1 != np2) cout << "Not identical!\n";
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
	}
	catch (...) {
		cerr << "exception\n";
	}
