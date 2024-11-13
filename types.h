#ifndef TYPES_H
#define TYPES_H


typedef struct{

    char firstName[40];
    char lastName[40];
    char mobileNumber[20];

} Contact;

//enumerator for different search types
typedef enum {FIRST_NAME, LAST_NAME, MOBILE_NUMBER} search_t;

#endif //TYPES_H
