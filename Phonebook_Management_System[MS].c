/******************************************************************************************************
  Program Name: Phone Book Management System
  Description: This program has a login system that authenticates the user using a password.
  Once the user is authenticated, they are presented with a menu of options to choose from.
  The options include adding a new contact to the phone book, showing all the contacts,
  searching for a specific contact, removing a specific contact, modifying an existing contact,
  deleting all the contacts, and counting the number of contacts in the phone book.

*******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STORAGE 1024
#define PASSWD "khuljasemsem"

typedef struct person
{
  char name[100];
  long int phone;
  char address[100];
  char email[100];
  char gender[20];
}contact;


contact phonebook[STORAGE];

// Number of contacts in the phone book
int num_contacts = 0;
int size;

void add_contact();
void show_all_contacts();
void search_contact();
void remove_contact();
void modify_contact();
void delete_all();
void count_contacts();
int printline();
int printstar();

int main()
{
  char passwd[100];
  system("date");
  printline(size=42);
  printf("\n\t\t|\tPASSWORD AUTHENTICATION\t\t|\n");
  printline(size=42);
  printf("\n\t\t Enter Password: ");
  scanf("%s",passwd);
  printline(size=42);


  if (strcmp(passwd, PASSWD) != 0)
  {
    printf("\n\t\t Invalid Password!\n");
    printline(size=42);
    printf("\n\n");
    return 1;
  }

  // Phone book Menu
  while (1)
  {
    printf("\n\n\n");
    printstar(size=42);
    printf("\n\t\t\t     THE PHONE BOOK   \n");
    printstar(size=42);
    printf("\n\t\t (1) Add contact       \n");
    printf("\t\t (2) Show all contacts   \n");
    printf("\t\t (3) Search contact      \n");
    printf("\t\t (4) Remove contact      \n");
    printf("\t\t (5) Modify contact      \n");
    printf("\t\t (6) Delete all contacts \n");
    printf("\t\t (7) Count contacts      \n");
    printf("\t\t (0) Exit                \n");
    printline(size=42);
    printf("\n\t\t Enter your choice: ");

    int choice;
    scanf("%d",&choice);

    switch (choice)
    {
      case 1:
        add_contact();
        break;
      case 2:
        show_all_contacts();
        break;
      case 3:
        search_contact();
        break;
      case 4:
        remove_contact();
        break;
      case 5:
        modify_contact();
        break;
      case 6:
        delete_all();
        break;
      case 7:
        count_contacts();
        break;
      case 0:
          printf("\n");
          printstar(size=42);
          printf("\n\t\t   Thank You for using the Phone Book \n");
          printstar(size=42);
          printf("\n\n\n");
        return 0;
      default:
        printf("\n");
        printline(size=20);
        printf("\n\t\t  Invalid Choice\n");
        printline(size=20);
        break;
    }
  }
}


void add_contact()
{
  if (num_contacts == STORAGE)
  {
    printline(size=22);
    printf("\n\t\t PHONE BOOK is FULL\n");
    printline(size=22);
    return;
  }

   printstar(size=42);
   printf("\n\t\t\t Add Contact Number\n");
   printstar(size=42);
   printf("\n\t\t Enter name: ");
   scanf(" %[^\n]s", phonebook[num_contacts].name);

   printf("\t\t Enter phone number: ");
   scanf("%ld",&phonebook[num_contacts].phone);

   printf("\t\t Enter address: ");
   scanf(" %[^\n]s", phonebook[num_contacts].address);

   printf("\t\t Enter email: ");
   scanf(" %[^\n]s", phonebook[num_contacts].email);

   printf("\t\t Enter gender: ");
   scanf(" %[^\n]s", phonebook[num_contacts].gender);

   num_contacts++;
   printf("\n\n");
   printstar(size=30);
   printf("\n\t\t  Contact Added Successfully\n");
   printstar(size=30);
}

void show_all_contacts()
{
  if (num_contacts == 0)
  {
    printf("\n");
    printline(size=25);
    printf("\n\t\t Phone Book is Empty\n");
    printline(size=25);
    return;
  }
    printstar(size=42);
    printf("\n\t\t  Show All Contacts\n");
    printstar(size=42);

  for (int i = 0; i < num_contacts; i++)
  {
    printf("\n\t\t Name      : %s\n",phonebook[i].name);
    printf("\t\t Phone No. : 0%ld\n",phonebook[i].phone);
    printf("\t\t Address   : %s\n",phonebook[i].address);
    printf("\t\t Email     : %s\n",phonebook[i].email);
    printf("\t\t Gender    : %s\n",phonebook[i].gender);
    printline(size=42);
    printf("\n");
  }
}


void search_contact()
{
  printf("\n");
  printstar(size=42);
  printf("\n\t\t\t  Search Contact \n");
  printstar(size=42);
  char name[50];
  printf("\n\t\t  Enter name: ");
  scanf(" %[^\n]s", name);

  for (int i = 0; i < num_contacts; i++)
 {
    if (strcmp(phonebook[i].name, name) == 0)
    {
     printline(size=22);
     printf("\n\t\t Search result\n");
     printline(size=22);
     printf("\n\t\t Name      : %s\n",phonebook[i].name);
     printf("\t\t Phone No. : 0%ld\n",phonebook[i].phone);
     printf("\t\t Address   : %s\n",phonebook[i].address);
     printf("\t\t Email     : %s\n",phonebook[i].email);
     printf("\t\t Gender    : %s\n",phonebook[i].gender);
     printline(size=42);
     return;
   }
 }
  printline(size=25);
  printf("\n\t\t Contact Not Found!\n");
  printline(size=25);
}


void remove_contact()
{
  printf("\n\n");
  printstar(size=42);
  printf("\n\t\t\t Remove Contact\n");
  printstar(size=42);
  char name[50];
  printf("\n\t\t Enter name: ");
  scanf(" %[^\n]s", name);

  int found = 0;
  for (int i = 0; i < num_contacts; i++)
  {
    if (strcmp(phonebook[i].name, name) == 0)
    {
      found = 1;

      for (int j = i; j < num_contacts - 1; j++)
      {
        phonebook[j] = phonebook[j + 1];
      }

      num_contacts--;
      printf("\n");
      printline(size=30);
      printf("\n\t\t Contact Removed Successfully\n");
      printline(size=30);
      return;
    }
  }

  if (!found)
  {
    printf("\n");
    printline(size=25);
    printf("\n\t\t Contact Not Found!\n");
    printline(size=42);
  }
}


void modify_contact()
{
  printf("\n\n");
  printstar(size=42);
  printf("\n\t\t\t  Modify Contact\n");
  printstar(size=42);
  char name[50];
  printf("\n\t\t Enter name: ");
  scanf(" %[^\n]s", name);

  int found = 0;
  for (int i = 0; i < num_contacts; i++)
  {
    if (strcmp(phonebook[i].name, name) == 0)
    {
      found = 1;
      printf("\n");
      printline(size=42);
      printf("\n\t\t Enter new name       : ");
      scanf(" %[^\n]s", phonebook[i].name);

      printf("\n\t\t Enter new phone number : ");
      scanf("%ld", &phonebook[i].phone);

      printf("\t\t Enter new address      : ");
      scanf(" %[^\n]s", phonebook[i].address);

      printf("\t\t Enter new email        : ");
      scanf(" %[^\n]s", phonebook[i].email);

      printf("\t\t Enter new gender       : ");
      scanf(" %[^\n]s", phonebook[i].gender);
      printline(size=42);

      printf("\n\n\t\t Contact Modified Successfully\n");
      return;
    }
  }

  if (!found)
  {
    printf("\n");
    printline(size=22);
    printf("\n\t\t Contact Not Found\n");
    printline(size=22);
  }
}


void delete_all()
{
  num_contacts = 0;
  printf("\n");
  printstar(size=40);
  printf("\n\t\t All Contacts Deleted Successfully\n");
  printstar(size=40);
}


void count_contacts()
{
  printf("\n\n\t\t Number of Contacts: %d\n", num_contacts);
}

int printline(int size)
{
    int i;
    printf("\t\t");
    for(i=1;i<size;i++)
    {
        printf("-");
    }
    return;
}

int printstar(int size)
{
    int i;
    printf("\t\t");
    for(i=1;i<size;i++)
    {
        printf("*");
    }
    return;
}

