/**
   Program Name: Student Record Management System
   Description: The program allows users to add student information,
   search for a student record,view all student records,
   delete a student record,modify a student record,delete all student record,
   and exit the program.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 1000

struct student
{
  char first_name[100];
  char last_name[100];
  int id;
  char department[50];
  char address[100];
  char batch[30];
  char gender[10];
};

struct student student_records[MAX_STUDENTS];
int num_students = 0;

void add_student();
void search_student();
void show_all_students();
void remove_student();
void modify_student();
void delete_all_students();

int main()
{
  int choice;
  do
    {
    printf("\n");
    printf("\t |-------STUDENTS' RECORD MANAGEMENT SYSTEM-------|\n");
    printf("\t |\t   Green University of Bangladesh         |\n");
    printf("\t |\t                                          |\n");
    printf("\t |\t 1. Add a student                         |\n");
    printf("\t |\t 2. Search for a student                  |\n");
    printf("\t |\t 3. Show all students                     |\n");
    printf("\t |\t 4. Remove a student                      |\n");
    printf("\t |\t 5. Modify a student                      |\n");
    printf("\t |\t 6. Delete all students                   |\n");
    printf("\t |\t 7. Exit                                  |\n");
    printf("\t |------------------------------------------------|\n");
    printf("\n\t\t>>Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        add_student();
        break;
      case 2:
        search_student();
        break;
      case 3:
        show_all_students();
        break;
      case 4:
        remove_student();
        break;
      case 5:
        modify_student();
        break;
      case 6:
        delete_all_students();
        break;
      case 7:
          printf("\n\t\t|=====================================|");
          printf("\n\t\t| Thank You for using this Software   |\n");
          printf("\t\t|=====================================|\n\n\n");
        printf("\n\tCopyright|Green University of Bangladesh||All Rights Reserved\n\n");
        break;
      default:
        printf("\n\t\tInvalid Choice!\n\n");
        printf("\n\tCopyright|Green University of Bangladesh||All Rights Reserved\n\n");
    }
  } while (choice != 7);

  return 0;
}

void add_student()
{
  if (num_students == MAX_STUDENTS)
  {
    printf("\n\t\t|=====================================|");
    printf("\n\t\t|      STUDENT RECORD IS FULL!        |\n");
    printf("\t\t|=====================================|\n\n\n");
  }
  printf("\n\t\t|===============================|");
  printf("\n\n\t\t     Add Student Information \n\n");
  printf("\t\t|===============================|\n\n\n");
  printf("\t\t Enter first name : ");
  scanf("%s", student_records[num_students].first_name);
  printf("\t\t Enter last name  : ");
  scanf("%s", student_records[num_students].last_name);
  printf("\t\t Enter ID         : ");
  scanf("%d",&student_records[num_students].id);
  printf("\t\t Enter department : ");
  scanf("%s", student_records[num_students].department);
  printf("\t\t Enter address    : ");
  scanf("%s", student_records[num_students].address);
  printf("\t\t Enter batch      : ");
  scanf("%s", student_records[num_students].batch);
  printf("\t\t Enter gender     : ");
  scanf("%s", student_records[num_students].gender);
  printf("\n\t\t---------------------------------------\n");

  printf("\n\t\t|===============================|\n");
  printf("\n\t\t|  Record stored successfully   |\n\n");
  printf("\t\t|===============================|\n\n\n");

  num_students++;
}


void search_student()
{
  int id;
  printf("\n\t\t|===============================|\n");
  printf("\n\t\t    SEARCH STUDENTS RECORD     \n\n");
  printf("\t\t|===============================|\n\n\n");
  printf("\n\t\t>>Enter ID: ");
  scanf("%d",&id);
  int i;
  for (i = 0; i < MAX_STUDENTS; i++)
  {
    if (student_records[i].id == id)
    {
      printf("\t\t First name : %s\n", student_records[i].first_name);
      printf("\t\t Last name  : %s\n", student_records[i].last_name);
      printf("\t\t ID         : %d\n", student_records[i].id);
      printf("\t\t Department : %s\n", student_records[i].department);
      printf("\t\t Address    : %s\n", student_records[i].address);
      printf("\t\t Batch      : %s\n", student_records[i].batch);
      printf("\t\t Gender     : %s\n", student_records[i].gender);
      printf("\n\t\t______________________________________\n\n");
      return;
    }

  }
    printf("\n\t\t|===============================|\n");
    printf("\t\t       Student not found!          \n");
    printf("\t\t|===============================|\n\n\n");
}

void show_all_students()
{
  int i;
  printf("\n\t\t|===============================|\n");
  printf("\n\t\t        STUDENTS'  RECORD    \n\n");
  printf("\t\t|===============================|\n\n\n");
  for (i = 0; i < MAX_STUDENTS; i++)
  {
    if (strlen(student_records[i].first_name) > 0)
    {
      printf("\t\t First name : %s\n", student_records[i].first_name);
      printf("\t\t Last name  : %s\n", student_records[i].last_name);
      printf("\t\t ID         : %d\n", student_records[i].id);
      printf("\t\t Department : %s\n", student_records[i].department);
      printf("\t\t Address    : %s\n", student_records[i].address);
      printf("\t\t Batch      : %s\n", student_records[i].batch);
      printf("\t\t Gender     : %s\n", student_records[i].gender);
      printf("\n\t\t---------------------------------\n\n");
      printf("\n");
    }
  }
}

void remove_student()
{
  int id;
  printf("\n\t\t|===============================|\n");
  printf("\n\t\t     DELETE STUDENTS RECORD \n\n");
  printf("\t\t|===============================|\n\n\n");
  printf("\t\t >>Enter ID: ");
  scanf("%d",&id);
  int i;
  for (i = 0; i < MAX_STUDENTS; i++)
  {
    if (student_records[i].id == id)
    {
        strcpy(student_records[i].first_name, "");
        strcpy(student_records[i].last_name, "");
        student_records[i].id = 0;
        strcpy(student_records[i].department, "");
        strcpy(student_records[i].address, "");
        strcpy(student_records[i].batch, "");

     printf("\n\t\t|====================================|\n");
     printf("\n\t\t    Record is Deleted Successfully\n\n");
     printf("\t\t|====================================|\n\n\n");
     return;
    }
  }
  printf("\n\t\t STUDENT NOT FOUND!\n\n");
}

void modify_student()
{
  int id;
  printf("\n\t\t|===============================|\n");
  printf("\n\t\t     MODIFY STUDENTS' RECORD   \n\n");
  printf("\t\t|===============================|\n\n\n");
  printf("\t\t >>Enter ID: ");
  scanf("%d",&id);
  int i;
  for (i = 0; i < MAX_STUDENTS; i++)
  {
    if (student_records[i].id == id)
    {
    printf("\n\t\t Enter new first name : ");
      scanf("%s", student_records[i].first_name);
      printf("\t\t Enter new last name  : ");
      scanf("%s", student_records[i].last_name);
      printf("\t\t Enter new ID         : ");
      scanf("%d",&student_records[i].id);
      printf("\t\t Enter new department : ");
      scanf("%s", student_records[i].department);
      printf("\t\t Enter new address    : ");
      scanf("%s", student_records[i].address);
      printf("\t\t Enter new batch      : ");
      scanf("%s", student_records[i].batch);
      printf("\t\t Enter new gender     : ");
      scanf("%s", student_records[i].gender);
      return;
    }
  }
     printf("\n\t\t STUDENT NOT FOUND!\n");
}

void delete_all_students()
{
  int i;
  printf("\n\t\t|===============================|\n");
  printf("\n\t\t    DELETE ALL STUDENTS RECORD \n\n");
  printf("\t\t|===============================|\n\n\n");
  for (i = 0; i < MAX_STUDENTS; i++)
  {
    strcpy(student_records[i].first_name, "");
    strcpy(student_records[i].last_name, "");
    student_records[i].id = 0;
    strcpy(student_records[i].department, "");
    strcpy(student_records[i].address, "");
    strcpy(student_records[i].batch, "");
  }
  num_students = 0;
  printf("\t\t ALL STUDENTS RECORD DELETED!\n\n\n");
}


