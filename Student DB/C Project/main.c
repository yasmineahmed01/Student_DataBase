#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    head=NULL;
    u8 id;
    u8 year;
    u8 Courses[3];
    u8 grades[3];
    u8 count;
    u8 list[max];//as the max number of entries is 10
    u8 choice;

    printf("\t\t\t NOTE: all the values is unit 8 so the max is 255 unless stated otherwise\n\n");

    start:
    printf("\t\t\t--Please Enter an Option--\n");
    printf("\t\t\t1) Add Student\n\t\t\t2) Delete Student\n");
    printf("\t\t\t3) Used Size\n\t\t\t4) Check If Full\n");
    printf("\t\t\t5) Read ID Info\n\t\t\t6) Check ID Existence\n");
    printf("\t\t\t7) Get IDs list\n\t\t\t8) Display all students\n");
    printf("\t\t\t9) exit\n\t\tOption: ");
    scanf("%d",&choice);

    switch(choice)
    {

    case 1:
        if(SDB_IsFull())
            printf("\n\tCan't Add..The data base is full :(\n\n");
        else
            SDB_AddEntry(id, year, Courses, grades);
            goto start;
        break;

    case 2:
        printf("Enter The ID you want to delete: \n");
        scanf("%d", &id);
        SDB_DeleteEntry(id);
        goto start;
        break;

    case 3:
        printf("\n\tThe Used Size is %d \n\n",SDB_GetUsedSize());
        goto start;
        break;

    case 4:
        if(SDB_IsFull())
            printf("\n\tThe Data Base is FULL \n\n");
        else
            printf("\n\tThe Data Base is NOT FULL \n\n");
        goto start;
        break;

    case 5:
         printf("Enter The ID you want to Read: \n");
        scanf("%d", &id);
        SDB_ReadEntry(id,&year,Courses,grades);
        goto start;
        break;

    case 6:
        printf("Enter The ID you want to check: \n");
        scanf("%d",&id);
        if(SDB_IsIdExist(id))
            printf("\tThis ID Exists\n\n");
        else
            printf("\tThis ID Does Not Exist\n\n");
        goto start;
        break;

    case 7:
        if(SDB_GetUsedSize()==0)
            printf("\n\tThere is no IDs to display\n\n");
        else
            SDB_GetIdList(&count,list);
        goto start;
        break;

    case 8:
        if(SDB_GetUsedSize()==0)
            printf("\n\tThere is no data to display\n\n");
        else
            display();
        goto start;
        break;

    case 9:
        break;

    default:
        printf("\n\tINVALID CHOICE\n\n");
        goto start;
        break;

    }

    return 0;
}
