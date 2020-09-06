#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct kitten {
    string name;
    string color;
    int score;

};

struct roster {
    kitten kittens[20];
    int size = 0;
};

void printMenu() {
    cout << "MENU" << endl;
    cout << "a - Add kitten" << endl;
    cout << "d - Delete kitten" << endl;
    cout << "u - Update kitten color and cuteness score" << endl;
    cout << "f - Find kitten" << endl;
    cout << "l - Load kitten info from file" << endl;
    cout << "s - Save kitten info to file" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;


}

int findKitten(string kitties, roster group) {
    for (int i = 0; i < group.size; i++) {
        if (group.kittens[i].name == kitties)
            return i;
    }
    return -1;

}

void addKitten(kitten newcat, roster& group) {
    if (group.size >= 10) {
        cout << "Impossible to add new kitten: roster is full." << endl;
        return;
    }
    else {
        group.size += 1;
        group.kittens[group.size - 1] = newcat;
        cout << "Successfully added new kitten to roster." << endl << endl;
    }
}

void add(roster& group) {
    kitten cat;
    cout << "Enter a new kitten's name:" << endl;
    cin >> cat.name;
    cout << "Enter the kittens's color:" << endl;
    cin >> cat.color;
    cout << "Enter the kittens's cuteness score:" << endl;
    cin >> cat.score;
    addKitten(cat, group);
}

bool deleteKitten(string kitties, roster& group) {
    int value = findKitten(kitties, group);
    if (value != -1)
    {
        for (int i = value; i < group.size; i++)
            group.kittens[i] = group.kittens[i + 1];
        group.size -= 1;
        return true;
    }
    else {
        return false;
    }

}

void getKittenFromFile(string file, roster& group)
{
    fstream f(file);
    if (!f.is_open())
    {
        cout << "Error! File not found." << endl;
        return;
    }
       kitten newKat;
       getline(f, newKat.name);
       getline(f, newKat.color);
       f >> newKat.score;
       addKitten(newKat, group);
       f.close();
}

bool updateKitten(kitten kitties, roster& group) {
    int value = findKitten(kitties.name, group);
    if (value == -1)
    {
        return false;
    }
    else
    {
        group.kittens[value].color = kitties.color;
        group.kittens[value].score = kitties.score;
        return true;
    }
}


void printToFile(string filename, roster group) {
    ofstream filecontroller;
    filecontroller.open (filename);
    filecontroller << "ROSTER:" << endl;
    for (int i = 0; i < group.size; i++)
        filecontroller << "Kitten " << i+1 << " -- Name: " << group.kittens[i].name << ", " << "Color: " << group.kittens[i].color << ", Score: " << group.kittens[i].score << endl;
    filecontroller.close();
}

void printRoster(roster group) {
    cout << "ROSTER:" << endl;
    for (int i = 0; i < group.size; i++)
        cout << "Kitten " << i+1 << " -- Name: " << group.kittens[i].name << ", Color: " << group.kittens[i].color << ", Score: " << group.kittens[i].score << endl;
    cout << endl;
}

void del(roster& group) {
    if (group.size <= 0)
    {
        cout << "Cannot delete from empty roster." << endl;
        return;
    }
    else {
        string catname;
        cout << "Enter kitten name to delete:" << endl;
        cin >> catname;
        bool check = deleteKitten(catname, group);
        if (check == false)
        {
            cout << "Error! Kitten not found." << endl;
        }
    }
}

void upd(roster &group) {
    kitten cat;
    cout << "Enter a kitten name:" << endl;
    cin >> cat.name;
    cout << "Enter a new color for the kitten:" << endl;
    cin >> cat.color;
    cout << "Enter a new cuteness score for the kitten:" << endl;
    cin >> cat.score;
    bool check = updateKitten(cat, group);
    if (check == false)
    {
        cout << "Cannot find kitten." << endl;
    }
    else
    {
        cout << "Successfully updated kitten info." << endl;
    }
}

void find(roster group) {
    string catname;
    cout << "Enter a kitten name: " << endl;
    cin >> catname;
    int value = findKitten(catname, group);
    if (value == -1)
    {
        cout << "Kitten not found." << endl << endl;
    }
    else
    {
        cout << catname << " info: " << group.kittens[value].color << ", " << group.kittens[value].score << endl << endl;
    }

}

void load(roster &group) {
    string nameofthefile;
    cout << "Enter file name:" << endl;
    cin >> nameofthefile;
    getKittenFromFile(nameofthefile, group);
}

void save(roster &group) {
    printToFile("output.txt", group);
}

int main()
{
    roster group;
    char option;
    while (true) {
        printMenu();
        cin >> option;
        switch (option) {
        case 'a': add(group); break;
        case 'd': del(group); break;
        case 'u': upd(group); break;
        case 'f': find(group); break;
        case 'l': load(group); break;
        case 's': save(group); exit(0);
        case 'o': printRoster(group); break;
        case 'q': exit(0);
        default: cout << "Invalid option. Please try again." << endl;
        }

    }
    return 0;
}