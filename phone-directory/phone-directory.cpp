//https://repl.it/join/rkoxxmyf-orangenotebook
//For this challenge i re-used my 'interpreter' from the 'Data File Praser' challenge. After importing that code, i first
//worked on getting a user input and comparing it to data in a file, if the user input matched a field in the file then
//it would output the row name and telephone. After this i worked on creating a function that returns the amount of rows
//in the data file. This was to show the user how many records the program is searchign through. Finally, i worked on a
//not found message, in case the user searches for a record that is not present in the data file.

//importing
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//class to interpret CSV files and allow the user to access each row
class CSVRow{
  public:
    //defining variables to hold row string
    string m_line;
    vector<int> m_data;

    //operator overloading to allow to get a row via classInstance[rowNumber]
    string operator [] (int index) const{
      return string(&m_line[m_data[index] + 1], m_data[index + 1] -  (m_data[index] + 1));
    }

    //a method that returns the size of a field
    int size() const{
      return m_data.size() - 1;
    }

    

    //a method to get the next field in the column
    void readNextRow(istream& str){
      //defining var (this is for the position of ',' characters)
      int pos = 0;
      //gets the current row
      getline(str, m_line);

      //removes all elements from my data vector
      m_data.clear();
      m_data.emplace_back(-1);

      //looks for ',', if found returns the pos (index of where it is in the row)
      while((pos = m_line.find(',', pos)) != string::npos)
      {
        m_data.emplace_back(pos);
        ++pos;
      }
      // This checks for a trailing comma with no data after it.
      pos = m_line.size();
      m_data.emplace_back(pos);
    }
};

//extraction operator, takes in the file and CSVRow instance, used to move on to the next row in a file
istream& operator >> (istream& str, CSVRow& data){
  data.readNextRow(str);
  return str;
}

//checks how many lines are in the data.csv file and returns them
int fileSize(istream& str){
  string line;
  int count = 0;

  //itterates through each line and adds 1 to counter
  while(getline(str,line))
      {
        count++;
      }
    //clears bad state and resets to the first line, then returns the amount of lines
    str.clear();
    str.seekg(0);
    return count;
}

//main function
int main(){
  //initialising variables
  CSVRow row;
  string userInput;
  bool found = false;

  //getting file
  ifstream file("data.csv");

  //asking user for input
  cout << "Please enter a name or number to search: ";
  getline(cin, userInput);

  //checking how many records are present and telling the user
  cout << "Searching " << fileSize(file) << " records...\n\n";

  //while loop that iterates through each row in file and checks if the name or telephone matches user input
  while(file >> row){
    //checks if name or telephone matches uer input, if yes displays it, sets found to true and breaks out of loop
    if(row[0] == userInput || row[1] == userInput){
      cout << "Contact details:\n" << row[0] << ", T: " << row[1];
      found = true;
      break;
    }
  }
  //checks if the record was not found and outputs a message saying it wasn't
  if(!found){
    cout << "Sorry, no contact details found";
  }
  return 0;
}
