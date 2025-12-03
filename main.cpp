//COMSC-210|Ethan Aylard|Lab-37
//IDE used: Visual Studio Code
//This Program will use Hash Tables to sort and store data from an external file.

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

bool debug = true;

int sum_ascii(string);

int main() {
    string test = "666D109AA22E";

    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = sum_ascii(test);
    cout << b << endl;
    cout << (char) b << endl;
    return 0;
}

//sum_ascii() makes an sum of all ascii value in a given string
//requires:  a string variable
//returns: an integer value
int sum_ascii(string str){
    int sum = 0;
    for (char c : str){
        sum += (int) c;
    }

    return sum;

}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF 
1DA9D64D02A0
666D109AA22E ascii sum = 
E1D2665B21EA
*/
