#include "header.h"
#include <stdio.h>
#include <stdlib.h>

//pointer to the head of the linked list
student* head;

// a counter to use in functions
u8 counter;

/**The description of each fun is in header file**/


u8 SDB_GetUsedSize(void)
{
    //a pointer to pass on each student
    student* temp= head;

    // counter to count the students
    counter=0;

    //this loop is to count the students
    //using the struct pointer and counter
    while(temp != NULL)
    {
        counter++;
        temp=temp->next;
    }
    return counter;

}
////////////////////////////////////////////////////////////

bool SDB_IsFull(void)
{
    //Checking The Entries using
    //the get size fun.
    //max is defined in the header
    //file as the max number of
    //entries = 10.
    if(SDB_GetUsedSize() == max)
        return 1;
    else
        return 0;

}

/////////////////////////////////////////////////////////////

bool SDB_AddEntry(u8 id, u8 year, u8* Courses, u8* grades)
{
    //temp pointer to pass by the structs
    student* temp = head;

    //Using malloc fun to locate
    //a size of a struct in the heap
    //to use it to store new data
    student* s=(student*)malloc(sizeof(student));

    //Entering the Id of the student
    again: printf("Enter Student ID: ");
    id: scanf("%d",&id);

    //this checks if the Id
    //is already exist
    if(SDB_IsIdExist(id))
    {
        printf("This ID exists Please enter another one: \n");
        goto id;
    }
    s->id=id;

           ////////////////

    //Entering The Year
    label1: printf("Enter the Year (1st : 7th): ");
    scanf("%d",&year);
    //As the max Number of years
    //in college is 7 years
    if(year>7 || year==0)
    {
        printf("\t\tInvalid Year: Please enter from 1st to 7th Year\n");
        goto label1;//Re-Enter year
    }
    else
    s->year=year;

           ////////////////

    //This loop is to enter the
    //Courses with The grade
    //using arrays.
    for(int i=0; i<3;i++)
    {
        printf("Enter Course_%d (ID): ",i+1);
        scanf("%d",&Courses[i]);
        s->Courses[i] = Courses[i];
        printf("Enter Course_%d (grade): ",i+1);
        label2: scanf("%d",&grades[i]);
        if(grades[i]>100)
        {
            printf("Invalid grade Please enter a valid grade (0-100): ");
            goto label2;
        }
        else
        s->grades[i] = grades[i];
    }
        ///////////////////

    //to locate the new entry
    //in the linked list
    if(head == NULL)
    {
        head = s;
        s->next = NULL;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=s;
        s->next=NULL;
    }
    printf("\n\t Successfully Added :)\n\n");
    return 1;
}

/////////////////////////////////////////////////////////////

void SDB_DeleteEntry(u8 id)
{
    //pointer to prev student
    //and pointer to current student
    student* prev=head;
    student* curr=head;

    //loop to check every student
    //comparing IDs and delete
    //the wanted student then
    //assign the next address
    //to the prev student
    while(curr != NULL)
    {
        if(curr->id==id)
        {
            if(curr==prev)//if the wanted ID is the head
            {
                head=head->next;
                free(curr);
            }
            else
            {
                prev->next=curr->next;
                free(curr);
            }
            printf("\n\tDeleted Successfully :)\n\n");
            return;
        }
        prev=curr;
        curr=curr->next;
    }
    printf("\n\tThere is no such ID :(\n\n");
}

////////////////////////////////////////////////////////////////////

bool SDB_ReadEntry(u8 id, u8* year, u8* Courses, u8* grades)
{
    student* temp=head;//Pointer to pass on each student

    //checking every ID
    //Read the year, courses
    //and grades of the wanted student
    while(temp != NULL)
    {
        if(temp->id==id)
        {
            *year = temp->year;
            printf("\tStudent ID -> %d\n",id);
            if(*year==1)
                printf("\tYear-> %dst year\n",*year);
            else if(*year==2)
                printf("\tYear-> %dnd year\n",*year);
            else if(*year==3)
                printf("\tYear-> %drd year\n",*year);
            else
                printf("\tYear-> %dth year\n",*year);

                printf("\t\tCourses and Grades\n");
            for(int i;i<3;i++)
            {
                Courses[i]=temp->Courses[i];
                grades[i]=temp->grades[i];
                printf("\tCourse_%d ID:  %d\n\tGrade:  %d\n\t--..--..--..--..--..--..--\n"
                       ,i+1,Courses[i],grades[i]);
            }
            return 1;
        }
        temp=temp->next;
    }
    printf("\n\tThere is no such ID :(\n\n");
    return 0;
}

///////////////////////////////////////////////////////////////////////////
void SDB_GetIdList(u8* count, u8* list)
{
    student* temp= head;
    *count=0;
    printf("\t\t--The ID list--\n");

    //Creating an array
    //called list and a counter
    //to count the number
    //of entries
    while(temp != NULL)
    {
        list[(*count)]=temp->id;
        (*count)++;
        printf("Student_%d ID: %d\n----\t----\t----\n",*count,list[(*count)-1]);
        temp=temp->next;
    }
    printf("\t\tThere is %d ID in the list\n\n",*count);
}

////////////////////////////////////////////////////////////////////////////
bool SDB_IsIdExist(u8 id)
{
    student* temp=head;
    while(temp != NULL)
    {
        if(temp->id==id)
        return 1;
        temp=temp->next;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
void display(void)
{
    student* temp=head;
    counter=0;
    while (temp != NULL)
    {
        counter++;
        printf("\t\t(((  Student [%d]  )))\n",counter);
        printf("ID: %d\n",temp->id);
        if (temp->year == 1)
        printf("Year: %dst Year\n",temp->year);
        else if(temp->year == 2)
        printf("Year: %dnd Year\n",temp->year);
        else if(temp->year == 3)
        printf("Year: %drd Year\n",temp->year);
        else
        printf("Year: %dth Year\n",temp->year);
        printf("\tCourses and grades:\n....................\n");
        for(int i=0;i<3;i++)
        {
            printf("Course_%d ID:  %d\nGrade:  %d\n--..--..--..--..--..--..--\n",
                   i+1,temp->Courses[i],temp->grades[i]);
        }

        temp=temp->next;
    }

}
