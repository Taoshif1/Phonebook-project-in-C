#ifndef PHONEBOOK_H
#define PHONEBOOK_H

void addEntry (); //function prototype
void display(int index);
void displayAll();
void search(char *key, search_t type);
void removeEntry(char *mobileNumber);
void readFromFile();
void saveToFile();

#endif // PHONEBOOK_H
