//https://repl.it/join/njrbkfdy-orangenotebook
//Prior to starting development and during development, a lot of reaserch went into this application, this is because
//i wanted to create somewhat of an interpreter to interpret CSV files and let me access each row/column of it. To start
//i looked into existing interpreters for CSV files and learnt about operator overloading, string_view structures (although
//i resulted in using ints instead), vectors and more. I then started hacking together my own interpreter class.
//Once i completed the class i moved on to displaying the information from data.csv in the console. Here i used setw() to
//define how large i want the gaps. I got lazy and tired so instead of calculating the size automatically, i counted the 
//characters of the longest word in each column and added 1.

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
      pos   = m_line.size();
      m_data.emplace_back(pos);
    }
};

//extraction operator, takes in the file and CSVRow instance, used to move on to the next row in a file
istream& operator >> (istream& str, CSVRow& data){
  data.readNextRow(str);
  return str;
}   

//main function
int main(){
  //initialising class
  CSVRow row;

  //getting file
  ifstream file("data.csv");

  //outputting headings
  cout << setw(9) << left << "Initial" << setw(11) << left << "Last" << setw(7) << left << "Salary\n";
  cout << setw(9) << left << "-------" << setw(11) << left << "---------" << setw(7) << left << "------\n";

  //while loop that iterates through each row and prints it out with the correct spacing and formatting
  while(file >> row)
  {
    cout << row[0][0] << setw(8) << left << "." << setw(10) << left << row[1] << " £" << row[2] << "\n";
  }
  return 0;
}
