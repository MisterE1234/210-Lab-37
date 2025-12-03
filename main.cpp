//COMSC-210|Ethan Aylard|Lab-37
//IDE used: Visual Studio Code
//This Program will use Hash Tables to sort and store data from an external file.

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

bool debug = false, debug_precise  = false; int FILE_SIZE = 100000;

int sum_ascii(string);

int main() {
    int total_ascii = 0;
    string temp_str;

    ifstream iFile("lab-37-data-2.txt");
    if(!iFile){
        cout << "Error opening file. Program ending...\n";
        return -1;

    }

    if(debug){

        cout << "File Opened\n";
    }

    for (int i = 0; i < FILE_SIZE; i++){
        getline(iFile, temp_str);
        total_ascii += sum_ascii(temp_str);
    }
    iFile.close();
    cout << "Total Ascii Sum: " << total_ascii << endl;


    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 55;
    cout << b << endl;
    cout << (char) b << endl;
    return 0;
}

//sum_ascii() makes an sum of all ascii value in a given string
//requires:  a string variable
//returns: an integer value
int sum_ascii(string str){
    int sum = 0;
    int count = 0;
    if (debug){
        cout << "Calculating ascii sum for: " << str << endl;
    }
    for (char c : str){
        if(debug_precise){
            cout << " Char " << count++ << ": " << c << " Ascii: " << (int) c << endl;

        }
        sum += (int) c;
    }

    return sum;

}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF 
1DA9D64D02A0
666D109AA22E ascii sum = 683
E1D2665B21EA
*/
