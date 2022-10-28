#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdbool.h>

//maximum size of the database is 10 entries
#define max 10

//Standard Types:
typedef unsigned char         u8   ;
typedef unsigned short int    u16  ;
typedef unsigned long int     u32  ;

//The Data base Module:
typedef struct SimpleDb
{
    u8 id;
    u8 year;
    u8 Courses[3];
    u8 grades[3];
    struct SimpleDb* next;

}student;

// a pointer to the head of the linked list
student *head;

//Check if the database is full
bool SDB_IsFull(void);

//Get the number of entries in the database
u8 SDB_GetUsedSize(void);

//Add new entry to the database
bool SDB_AddEntry(u8 id, u8 year, u8* Courses, u8* grades);

//Delete the entry with the given ID
void SDB_DeleteEntry(u8 id);

//Read an entry matching the provided ID
bool SDB_ReadEntry(u8 id, u8* year, u8* Courses, u8* grades);

//Get the list of IDs of the students
void SDB_GetIdList(u8* count, u8* list);

//Checks if the the provided student ID exists
bool SDB_IsIdExist(u8 id);

//EXTRA: To display all the data base
void display(void);


#endif // HEADER_H_INCLUDED
