/*****
@author: Nilay Chandra Barman (https://github.com/Nilaycb)
Copyright (c) 2020, All rights reserved.
Copyrights licensed under the GNU GPLv3 License.
******/


#include<stdio.h>
#include<stdlib.h>

#define ID_LENGTH 11
#define NAME_LENGTH 25
#define TOTAL_SUBJECTS 3


typedef struct Student
{
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
    float marks[TOTAL_SUBJECTS];
} student;


int main()
{
    int i, n;
    char temp;
    int max_mark = -1;
    int max_mark_st_arr = -1;

    printf("Enter no of student: ");
    scanf("%d", &n);

    student st[n];

    printf("\n\n ------------ Input Students Information: ------------\n");
    for(i=0; i<n; i++)
    {
        scanf("%c", &temp); //clear buffer after int input
        printf("\nStudent %d: \nName: ", i+1);
        scanf("%[^\n]", st[i].name);
        printf("ID: ");
        scanf("%s", st[i].id);
        printf("Exam Marks: ");
        scanf("%f", &st[i].marks[0]);
        scanf("%f", &st[i].marks[1]);
        scanf("%f", &st[i].marks[2]);
    }

    printf("\n\n -------- Stored data: -------------\n");
    for(i=0; i<n; i++)
    {
        printf("\nStudent %d: \n", i+1);
        printf("Name: %s\n", st[i].name);
        printf("ID: %s\n", st[i].id);
        printf("Exam Marks: %.0f %.0f %.0f\n", st[i].marks[0], st[i].marks[1], st[i].marks[2]);
    }

    printf("\n\n ---------- Average marks of each student: ----------\n");
    for(i=0; i<n; i++)
    {
        float total_marks = st[i].marks[0]+st[i].marks[1]+st[i].marks[2];

        if(total_marks > max_mark)
        {
            max_mark = total_marks;
            max_mark_st_arr = i;
        }

        printf("\nStudent %d: %.2f\n", i+1, (float)total_marks/TOTAL_SUBJECTS);
    }

    printf("\n\n ----------- Student with maximum total marks: -------------- \n");
    printf("\nName: %s\n", st[max_mark_st_arr].name);
    printf("ID: %s\n", st[max_mark_st_arr].id);

    printf("\n");
    return 0;
}
