//https://repl.it/join/uhjekxin-orangenotebook
//First i read through the stat documentation and looked at a lot of examples using stat, following this i created 2 functions
//one of the functions took a document name input and returned the size, and the other one returned the last modified time.
//After i took user input and called the functiosn within a cout. Finally, my code looked verry messy so i removed the
//functions and created it all within the main, this shortened the code substantially and made it much more readable.

//importing
#include <iostream>
#include <sys/stat.h>
#include <string>

using namespace std;

//main function
int main(){
  //initialising variables and creating stat structure
  string userInput;
  struct stat st;

  //getting user input
  cout << "Filename to check: ";
  cin >> userInput;

  //checks if stat failed (should only happen if incorrect file name is provided)
  if(stat(userInput.c_str(), &st) != 0) {
     cout << userInput << " does not exist";
  }else{
  //outputs the size and last modified tiem of the file provided
  cout << userInput << ", " << st.st_size << " bytes, last modified: " << ctime(&st.st_mtime);
  }
  
  return 0;
}
