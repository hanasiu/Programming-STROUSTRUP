#include "std_lib_facilities.h"


int main()
try {
    int birth_year = 1992;
    cout << showbase 
        << birth_year << "\t(decimal)\n"
        << hex << birth_year << "\t(hexadecimal)\n"
        << oct << birth_year << "\t(octal)\n";
    int age = 31;
    cout << dec << "age: " << age << endl;

//    int a, b, c, d;
//    cin >> a >> oct >> b >> hex >> c >> d;
//    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
  
    cout << defaultfloat << 1234567.89 << "\t(defaultfloat)\n" 
        << fixed << 1234567.89 << "\t(fixed)\n" 
        << scientific << 1234567.89 << "\t(scientific)\n";

    cout << setw(10) << "Wuethrich" << " | " << "Benjamin" << " | "
        << setw(16) << "+1345 326 5181" << " | " << setw(29) << "benjamin.wuethrich@gmail.com" << endl
        << setw(10) << "Forrest" << " | " << setw(8) << "Kara" << " | "
        << setw(16) << "+1345 516 1920" << " | " << setw(29) << "kara_forrest@hotmail.com" << endl
        << setw(10) << "Aarnau" << " | " << setw(8) << "Mayra" << " | "
        << "+34 66 696 55 63" << " | " << setw(29) << "mayraaachen@hotmail.com" << endl
        << setw(10) << "Michel" << " | " << setw(8) << "Tanael" << " | "
        << "+41 79 374 48 62" << " | " << setw(29) << "tanael@gmail.com" << endl
        << setw(10) << "Widler" << " | " << setw(8) << "Andrea" << " | "
        << "+41 79 293 29 38" << " | " << setw(29) << "andreawidler@bluewin.ch" << endl
        << "Amanatidou" << " | " << "Elisabet" << " | "
        << "+41 76 701 61 28" << " | " << "elisabet.amanatidou@gmail.com" << endl;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
