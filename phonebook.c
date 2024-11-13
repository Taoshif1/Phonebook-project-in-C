#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "phonebook.h"
#include "utilities.h"

#define MAX_SIZE 100

//array to hold contacts
Contact phonebook[MAX_SIZE];

//current size of the phonebook array
int currentsize = 0;



void addEntry()
{
     if (currentsize == MAX_SIZE){
     puts ("Error: phonebook is full!");
     return ;

}
    Contact c;
    printf("Enter First Name: ");
    gets(c.firstName);
    printf("Enter Last Name: ");
    gets(c.lastName);
    printf("Enter Mobile Number: ");
    gets(c.mobileNumber);

    phonebook[currentsize] = c;
    ++currentsize;

    printf("\nContact added.\n");
}
void display(int index)
{
    if (index < 0 || index >= currentsize){
        puts("Error: invalid index!");
        return;
    }

    Contact c = phonebook[index];

    printf("First Name: %s\n", c.firstName);
    printf("Last Name: %s\n", c.lastName);
    printf("Mobile Number: %s\n", c.mobileNumber);

}
void displayAll()
{
    if(currentsize == 0){
        puts("Phonebook is empty!");
        return;
    }
    int i;
    for(i=0; i<currentsize; i++){
        display(i);
        puts(""); //for new line
    }

}
void search(char *key, search_t type)
{
    int found = 0;
    int i;

    strtolower(key);
    char content[41];

    if (type == FIRST_NAME) {//search by first name
            for(i=0; i<currentsize; i++){

            strcpy(content, phonebook[i]. firstName);
            strtolower(content);

                if(strcmp(content, key) == 0){
                    display (i);
                    found = 1 ;
                }
            }

        }

    else if (type == LAST_NAME) {//search by last name
            for(i=0; i<currentsize; i++){

            strcpy(content, phonebook[i]. lastName);
            strtolower(content);

                if(strcmp(content, key) == 0){
                    display (i);
                    found =1 ;
                }
            }

        }

    else if (type == MOBILE_NUMBER) {//search by mobile number
            for(i=0; i<currentsize; i++){

            strcpy(content, phonebook[i]. mobileNumber);
            strtolower(content);

                if(strcmp(content, key) == 0){
                    display (i);
                    found =1 ;
                }
            }

        }

    else {
        puts("Error: invalid search type!");
        return;
    }
      if (!found){
        puts("Not found in phonebook");
    }

}

//currentsize -= 1;
//-------------------------------------
//0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
//-------------------------------------

void removeEntry(char *mobileNumber)
{
  if(currentsize == 0){
    puts("Phonebook is empty! Nothing to delete!");
    return;
  }


    int i, j;
    int count = 0;
    for(i=0; i<currentsize; i++){
        if(strcmp(phonebook[i].mobileNumber, mobileNumber) == 0) {
            for(j=i; j<currentsize-1; j++){
                phonebook[j] = phonebook [j+1];
            }

            strcpy(phonebook [j]. firstName, "");
            strcpy(phonebook [j]. lastName, "");
            strcpy(phonebook [j]. mobileNumber, "");

            currentsize -= 1;
            ++count;


        }
    }
    if(count == 0){
        puts("No entry deleted");
    }
    else {
        printf("%d enteries deleted\n", count);
    }

}


void readFromFile()
{
    FILE *fp;
    if((fp = fopen("phonebook.db", "rb")) == NULL) {
        puts("Error: can't load database file");
        return;
    }


    //read the size of phonebok
    if(fread(&currentsize, sizeof(currentsize), 1, fp) !=1){
        puts("Error: can't read data!");
        return;
    }

    //read the actual content of phonebook
    if(fread(phonebook, sizeof(phonebook), 1, fp)!=1){
        puts("Error: can't read data!");
        return;
    }

}


void saveToFile()
{
    FILE *fp;
    if((fp = fopen("phonebook.db", "wb")) == NULL){
        puts("Error: can't creat a database file!");
        return;
    }

    //save the current size of phonebook
    if (fwrite(&currentsize, sizeof(currentsize), 1, fp) !=1){
            puts("Error: can't save data!");
    return;

    }


    //save the phonebook contents
    if(fwrite(phonebook, sizeof(phonebook), 1, fp) != 1) {
        puts("Error: can't save data!");
        return;
    }

    puts("Phonebook saved to file successfully!");
}
