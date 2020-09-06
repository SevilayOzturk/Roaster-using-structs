# Roaster-using-structs
#//programmed for 1430 introduction to programming class in 2020



This program will store a roster of most popular videos with kittens. The roster can include at most 10 kittens.You will implement structures to handle kitten information. You will also use functions to manipulate the structure.
(1) Create a structure kitten. The structure should contain the following attributes:
	• name; string
	• color; string
	• score; integer
Important! The name of the structure and each of its field must match exactly for the program to work and be graded correctly.
(2) Create a struct roster. This struct should contain the following attributes:
	• kittens: an array of struct kitten, with size 10
	• size; int. This variable will be updated based on the current number of kittens in the roster.
In main(), create a roster called kittenRoster. This will store your kitten roster.
(3) Implement function printMenu(). This function prints out a menu of options for the user to modify the roster. Each option is represented by a single character.

Ex:
MENU
a - Add kitten
d - Delete kitten
u - Update kitten color and cuteness score
f - Find kitten
l - Load kitten info from file
s - Save kitten info to file
o - Output roster
q - Quit
Choose an option:
After creating a roster from file, the program outputs the menu. The program will continue to output the menu, until the user chooses the option Quit. If user chooses an option that doesn't exist, display error message
Invalid option. Please try again.
You can safely assume that user will only enter lower-case letters for option.
(4) Implement a function findKitten(). This function takes two arguments: a string name, and a roster struct. If the kitten's name is in the roster, return the position of the kitten in roster. Otherwise, return -1.
(5) Implement a function addKitten(). This function takes two arguments: a kitten struct and a roster struct. If the roster is full, display error message
Impossible to add new kitten: roster is full.
Otherwise, it will add the new kitten to the end of the roster and display the message. The size of the roster will be updated accordingly.
Successfully added new kitten to roster.
(6) Implement function deleteKitten(). This function takes string name and a roster struct as arguments. It deletes kitten with the same name in roster (i.e., remove the kitten from the roster). You can use findKitten() to check if the kitten exists in the roster. If kitten is not found, return false. Otherwise, delete the kitten, and return true. Remember to update the size of the roster accordingly and pay attention not to leave unused spaces in the roster array.
(7) Implement function getKittenFromFile(). This function takes two arguments: the name of a file that stores kitten info, and a struct roster. The function reads the file, and stores kittens info into roster.
The format of the file is as follows (a sample text file is provided as an example):
<kitten's name>
<kitten's color>
<kitten's cuteness>
...
If the file is not opened successfully, print
Error! File not found.
You can assume that the number of kittens in the file will not exceed the size of the array.
This function will be tested using unit testing.
(8) Implement updateKitten() function. This function takes 2 arguments: a kitten struct, and a roster struct. First, it needs to look up the kitten name in the roster (You can use findKitten() to look up kitten's name). If not found, return false. If found, update the corresponding kitten's color and cuteness score, and return true.
(9) Implement printToFile() function. This function takes a string filename, and a roster as arguments, saves the roster into a text file with the following format:
ROSTER
Kitten 1 -- Name: Peanut Butter, Color: light brown, Score: 10
Kitten 2 -- Name: Addie, Color: grey, Score: 42
...
(10) Implement a function printRoster(). This function takes as argument a roster and prints all the kittens info to standard output, each one on a new line.

Ex:
ROSTER
Kitten 1 -- Name: Willow, Color: white, Score: 10
Kitten 2 -- Name: Addie, Color: grey, Score: 42
...
This function will be called when the user selects option 'o'.
(11) Implement the "Add kitten" menu option. Prompt the user for a new kitten's name, color and score.

Ex:
Enter a new kitten's name:
Rocky Balboa
Enter the kittens's color:
white
Enter the kittens's cuteness score:
82
Store the user input into a kitten struct, then use addKitten() function to add the new kitten to roster. Note that the kitten's name may contain spaces.
(12) Implement option "Delete kitten". If the user chooses the option when the roster is empty, immediately print the message:
Cannot delete from empty roster.
If the roster is not empty, prompt the user for a kitten's name. Remove the kitten with the specified name from the roster using deleteKitten()
Enter kitten name to delete:
Rocky Balboa
If deleteKitten() returns false (i.e. kitten is not in the roster), inform the user:
Error! Kitten not found.
(13) Implement the "Update kitten color and cuteness score" menu option, Prompt the user for a kitten's name, color and score.

Ex:
Enter a kitten name:
Jingle Bell
Enter a new color for the kitten:
Pink
Enter a new cuteness score for the kitten:
98
Call updateKitten(). If update unsuccessful, print the following error message:
Cannot find kitten.
Otherwise, display message:
Successfully updated kitten info.
(14) Implement "Find kitten" menu option. Prompt the user for kitten's name.

Ex:
Enter a kitten name:
Grump Kit
Use findKitten(). If kitten is not found, print the following error message:
Kitten not found.
Otherwise, print out kitten info in the following format:
kittenName info: color, cuteness score
(15) Implement option "Load kitten info from file". Prompt the user for input file name.
Enter file name:
Use getKittenFromFile().
(16) Implement option "Save kitten info to file". Prompt the user for output file name.
Enter file name:
Use printToFile().
