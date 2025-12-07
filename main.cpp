//COMSC-210|Ethan Aylard|Lab-37
//IDE used: Visual Studio Code
//This Program will use Hash Tables to sort and store data from an external file.

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

//universal variables:
bool debug = false, debug_precise  = false;  int ENTRY_AMOUNT = 100;

int gen_hash_index(string);

int main() {
    map<int, list<string>> hash_table; //hash table: the int is the ascii value of the string

    
    string temp_str;

    ifstream iFile("lab-37-data-2.txt");
    if(!iFile){
        cout << "Error opening file. Program ending...\n";
        return -1;

    }

    if(debug){

        cout << "File Opened\n";
    }

    while(!iFile.eof()){
        getline(iFile, temp_str);
        hash_table[gen_hash_index(temp_str)].push_back(temp_str);
        
    }
    iFile.close();
    if(debug){
        cout << "File Closed\n";
    }

    //displaying the first 100 entries in hash_table:
    int counter = 0;
    for (auto const& pair : hash_table){
        
        if( counter >= ENTRY_AMOUNT){
            break;
        }
        int i = 0;

        cout << "ACII Value: " << pair.first << " -> ";
        for (auto str : pair.second){
            

            cout << str; // displaying the current string

            //checking if there is more strings with the same ascii value to display:
            if( i != pair.second.size() - 1){ // if the current string is not the final string:
              cout << ", ";  
            }
            i++; //adding to the counter
        }
        cout << endl;
        i = 0;
        counter++;
    }
    cout << counter << " entriest displayed. \n ";

    cout << "\nProgram Ending...\n";
    //clearing hash_table:
    for(auto & pair : hash_table){
        pair.second.clear();
    }
    hash_table.clear();

    
    return 0;
}

//gen_hash_index() makes an sum of all ascii value in a given string
//requires:  a string variable
//returns: an integer value
int gen_hash_index(string str){
    int sum = 0;
    int count = 0; //for debug perposes
    if (debug){
        cout << "Calculating ascii sum for: " << str << endl;
    }
    //using a range based for loop to iterate through the string.
    for (char c : str){
        if(debug_precise){
            cout << " Char " << count++ << ": " << c << " Ascii: " << (int) c << endl;

        }
        sum += (int) c; //add the ascii value of the current character to the ascii sum
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
