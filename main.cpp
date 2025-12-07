//COMSC-210|Ethan Aylard|Lab-38
//IDE used: Visual Studio Code
//This Program will use Hash Tables to sort and store data from an external file. Now with an interactive menu!

#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

//universal variables:
bool debug = false, debug_precise  = false;  int ENTRY_AMOUNT = 100;

int gen_hash_index(string);
void display_hash_table(map<int, list<string>>&);
void key_search(map<int, list<string>>&);
int menu();

int main() {
    map<int, list<string>> hash_table; //hash table: the int is the ascii value of the string

    
    string temp_str;
    bool exit = false;

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


    while(!exit){
        switch(menu()){

            case 0: //exit program:
                exit = true;
                break;
            case 1: // display 100 entries:
                //displaying the first 100 entries in hash_table:
                
                display_hash_table(hash_table);
                break;
            case 2: //search for a key:

                break;
            case 3: //add a key:
                break;
            case 4: //delete a key:
                break;
            case 5: // modify a key:
                break;
            
            default:
                cout << "Error! wrong switch case. Program stopping...\n";
                exit = true;
                break;
            
        }
    }

    

    
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

//menu() displays the user menu and validates their input
//requires: nothing
//returns: an integer value
int menu(){
    int choice = 0;
    bool valid = false;

    cout << "Menu:\n"
    << "[1] Display First 100 Entries\n"
    << "[2] Search for a Key\n"
    << "[3] Add a Key\n"
    << "[4] Delete a Key\n"
    << "[5] Modify a Key\n"
    << "[0] Exit Program\n"
    << "Enter your choice: ";

    //using a while loop to validate the user's response:
    while(!valid){
        cout << "Which would you like (0-5)?: ";
        cin >> choice;

        if(cin.fail()){ //if not an integer:
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Invalid Entry. Not an Integer. Try again\n";
        }
        else if(choice > 5 || choice < 0){ // if not an option in the menu:
            cout << "Invalid Entry. Not within range. Try again\n";
        }
        else{// if correct:
            valid = true;
        }
    }

    cin.ignore(10000, '\n');// clearing the input buffer for futer getline()

    return choice;
}


//display_hash_table() displays the first 100 entries in the hash_table
//requires: a map<int, list<string>> passed by reference
//returns: nothing
void display_hash_table(map<int, list<string>>& hash_table){
    int counter = 0;
    for (auto const& pair : hash_table){
        
        if( counter >= ENTRY_AMOUNT){// checking if 100 map entries have been displayed
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
        cout << endl << endl;
        i = 0;
        counter++;
    }
    if(debug){
        cout << counter << " entries displayed. \n ";
    }
}

void search_key(map<int, list<string>>& hash_table){
    string target;
    cout << "Enter the key to search for: ";
    getline(cin, target);

    int target_index = gen_hash_index(target);

    auto search = hash_table.find(target_index);

    }
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF 
1DA9D64D02A0
666D109AA22E ascii sum = 683
E1D2665B21EA
*/
