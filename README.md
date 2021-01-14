# AP-Module-Cpp-Wednesday-Exercises
This repo is part of my 'Advanced Programming' module. It contains all of my Wednesday tasks / challenges.

## Exercise 1: File Exists
A simple C++ program that allows the user to enter a filename. The program should display the file’s status, if the file exists include the file size and last modified date.

Example output:
```
Filename to check: data.csv
data.csv does not exist

--OR--

Filename to check: data.csv
data.csv, 25 bytes, last modified: Tue Jan 12 14:41:00 2021
```
## Exercise 2: File Writer
A simple C++ program that allows the user to enter a name. The program should append (or create in the first instance) a plain text file called “list.csv” with the name entered. Once updated, the user should be prompted to enter another name, if no additional names are expected the program should finish with a goodbye message.

Example output:
```
Enter name: Jaelynn Stuart
Updating file...

Add another (y/n)? Y

Enter name: John Smith
Updating file...

Add another (y/n)? N
Goodbye
```
## Exercise 3: File Reader
A simple C++ program that prompts the user to enter a filename. If the file exists, the program should display and add a count to each line and display the total number of lines at the end; an appropriate indication should be given if the file specified does not exist.

Example output:
```
Please enter a valid filename: list.cvs
Sorry, ‘list.cvs’ does not exist.

Please enter a valid filename: list.csv
1: Jaelynn Stuart
2: John Smith

Total number of lines read: 2
```

## Data File Parser
A C++ program that reads the following data from a file:
```
Noak,Jaylinn,21500
Apollinaire,Venkata,29250
Faith,Mara,30000
Yasamin,Shukriyya,44500
Zahir,Marcel,31200
Maia,Ela,45600
Liam,Oliver,43300
Luka,Jones,45600
Alexander,Smith,20500
```
Processes the records and display them as a formatted, aligned and evenly spaced table as shown

Example output:
```
Initial  Last       Salary
-------  ---------  ------
N.       Jaylinn    £21500
A.       Venkata    £29250
F.       Mara       £30000
Y.       Shukriyya  £44500
Z.       Marcel     £31200
M.       Ela        £45600
L.       Oliver     £43300
L.       Jones      £45600
A.       Smith      £20500
```
