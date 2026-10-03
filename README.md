# Phonebook Project in C

A console-based phonebook application written in C for a term-final programming project.

## Features

- Add a new contact
- Display all contacts
- Search by first name
- Search by last name
- Search by mobile number
- Delete a contact by mobile number
- Save contacts to a local database file
- Load saved contacts when the program starts

## Structure

- `main.c` — menu and application flow
- `phonebook.c` / `phonebook.h` — phonebook operations
- `types.h` — shared data types
- `utilities.c` / `utilities.h` — utility functions

The application stores up to 100 contacts in memory and persists the phonebook to `phonebook.db` using binary file I/O.

## Build

Using GCC:

```bash
gcc main.c phonebook.c utilities.c -o phonebook
```

Run:

```bash
./phonebook
```

On Windows:

```powershell
phonebook.exe
```

## Learning focus

- C structures
- Arrays
- String handling
- Functions and headers
- Search/delete operations
- Binary file I/O
- Multi-file C programs

## Note

This is an educational project. Some legacy C input functions used in the original implementation are not suitable for production software and should be replaced with safer bounded input handling in future revisions.

## Author

**Gazi Taoshif**  
GitHub: https://github.com/Taoshif1
