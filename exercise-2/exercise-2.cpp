//https://repl.it/join/bjgykuxm-orangenotebook
//First i looked at the provided recourse about IO streams, along with doing some extra reaserch on stackoverflow
//I then got input from a user and used ofstream to assess a file (or create one) called list.csv in write mode
//I used ofstream:app to append instead of replace data in the file, following this i wrote the users input into file
//and closed the file. To allow the user to enter multiple names i created a while loop that loops until the user chooses to stop

//importing
#include <iostream>
#include <fstream>
using namespace std;

//main function
int main () {
  //initialising variables
  string restart;
  string userInput;

  //while loop to allow for multiple names being entered
  while(true){
  
    //getting user input
    cout << "Enter name: ";
    getline(cin, userInput);
    
    //accessing 'list.csv' in append mode
    ofstream myfile ("list.csv", ofstream::app);
    //checking if the file has been accessed (if not throw error)
    if (myfile.is_open()){
      //telling user file is being updated and updating file then closing it
      cout << "Updating file...\n\n";
      myfile << userInput << "\n";
      myfile.close();
    }else{
      cout << "Unable to open file"; //error if file can't be accessed
    } 

    //asking user if they want to add another name and getting their input
    cout << "Add another (y/n)? ";
    getline(cin, restart);

    //checking if user wants to add more, if yes let loop restart if no say 'Goodbye' and end loop by returning 0
    if(restart == "y" || restart == "Y"){
        cout << "\n";
    }else{
      cout << "Goodbye";
      return 0;
    }
  }
}
