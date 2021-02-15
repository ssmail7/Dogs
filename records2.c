//**********************************************************************
// Written by Steven Smail for COP3514
//
// records.c (Project 10)
//
// This program maintains records for canine patients at an animal
// hospital - containing each dog’s name, breed, patient number, and
// owner’s last name.
//**********************************************************************

#include <stdio.h>
#include "dogs2.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct dog *dog_list = NULL;  
  printf("Operation Code: \n\ta - append the list\n\ts - search for a dog\n\tp - print the list\n\tq - quit\n");
  for(;;)
  {
    printf("Enter operation code:\n");
    scanf(" %c", &code);
    while(getchar() != '\n')   /* skips to end of line */
      ;
    switch(code)
    {
      case 'a': dog_list = append(dog_list);
                break;
      case 's': search(dog_list);
                break;
      case 'p': print(dog_list);
                break;
      case 'q': clear(dog_list);
		return 0;
      default:  printf("Illegal code.\n");
    }
    printf("\n");
  }
}
