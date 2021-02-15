//**********************************************************************
// Written by Steven Smail for COP3514
//
// dogs.c (Project 10)
//**********************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dogs2.h"
#include "readline2.h"

/**********************************************************
 * append: Prompts the user for information about a new   *
 *         dog and then inserts the dog into the end of   *
 *         the list. Prints an error message and returns  *
 *         prematurely if the dog's ID already exists or  *
 *         space could not be allocated for the dog.      *
 **********************************************************/
struct dog *append(struct dog *list)
{
  struct dog *cur, *new_node;

  new_node = malloc(sizeof(struct dog));
  if(new_node == NULL)
  {
    printf("Database is full; can't add more dogs.\n");
    return list;
  }

  printf("Enter patient number:\n");
  scanf("%d", &new_node->number);

  for(cur = list; cur != NULL; cur = cur->next)
    if(cur != NULL && new_node->number == cur->number)
    {
      printf("Patient already exists.\n");
      free(new_node);
      return list;
    }

  printf("Enter dog's name:\n");
  read_line(new_node->dog_name, NAME_LEN);
  printf("Enter dog's breed:\n");
  read_line(new_node->breed, NAME_LEN);
  printf("Enter owner's last name:\n");
  read_line(new_node->owner_last_name, NAME_LEN);

  if(list == NULL)
    return new_node;

  for(cur = list; cur->next != NULL; cur = cur->next)
    ;
  if(cur->next == NULL)
    cur->next = new_node;
  return list;
}

/**********************************************************
 * search: Prompts the user to enter a dog's name, then   *
 *         looks up the dog in the database. If the dog   *
 *         exists, it prints it's information; if not, it *
 *         prints an error message.                       *
 **********************************************************/
void search(struct dog *list)
{
  struct dog *p;
  char name[NAME_LEN + 1];
  int count = 0;

  printf("Enter patient name:\n");
  read_line(name, NAME_LEN);

  for(p = list; p != NULL; p = p->next)
  {
    if(strcmp(name, p->dog_name) == 0)
    {
      printf("%-8d%-16s%-16s        %-16s\n", p->number, p->dog_name,
             p->breed, p->owner_last_name);
      count++;
    }
  }
  if(count == 0)
    printf("Dog not found.\n");
}

/**********************************************************
 * print: Prints a listing of all dogs in the database,   *
 *        showing the dog's number, dog's name, breed,    *
 *        and the owner's last name.                      *
 **********************************************************/
void print(struct dog *list)
{
  struct dog *p;

  printf("Number  Name            "
         "Breed           Owner Last Name\n");
  for(p = list; p != NULL; p = p->next)
    printf("%-8d%-16s%-16s        %-16s\n", p->number, p->dog_name,
           p->breed, p->owner_last_name);
}

/**********************************************************
 * clear: Clears the entire linked list.                  *
 *        The function begins at the head of the list and *
 *        frees the memory allocated for each node of the *
 *        linked list.                                    *
 **********************************************************/
void clear(struct dog *list)
{
  struct dog *p;

  while(list != NULL)
  {
    p = list;
    list = list->next;
    if(p != NULL)
      free(p);
  }
}
