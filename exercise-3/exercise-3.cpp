//https://repl.it/join/ycwgwfyy-orangenotebook
//For this exercise i looked at my file writer and the recource provided for it, there i found ifstream, which allows
//file reading. I looked into this further, and started by writing a program that simply reads the first line. Following this
//i created a counter and a while loop to get all of the lines. Once i had all of the lines, i got user input and used that
//as a file-name instead of hard-coding it in. Finally i worked on an if statement that checks if the file exists or not.

//importing
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//main function
int main () {
  //initialising variables
  int count = 0;
  string fileName, line;

  //while loop in case user enters incorrect file name
  while(true){
    //getting file name from user
    cout << "Please enter a valid filename: ";
    cin >> fileName;

    //getting the file via the input
    ifstream myFile (fileName);
    //checking if the file has been opened or not, if not file does not exist and returns error
    if (myFile.is_open())
    {
      //while loop to read each line of the file
      while ( getline (myFile,line) )
      {
        cout << ++count << ": " << line << '\n';
      }
      //closing file so OS' recourses become available again
      myFile.close();
      //outputting the total number of lines read and ending application
      cout << "\nTotal number of lines read: " << count;
      return 0;
    }
    //else statement if file could not be opened or does not exist, this then rerunst the loop
    else{
      cout << "Sorry, '" << fileName << "' does not exist.\n\n" ; 
    }
  }
}
