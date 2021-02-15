//**********************************************************************
// Written by Steven Smail for COP3514
//
// readline.c (Project 11)
//**********************************************************************

#include <stdio.h>
#include <ctype.h>
#include "readline3.h"

int read_line(char str[], int n)
{
  int ch, i = 0;

  while(isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while((ch = getchar()) != '\n')
  {
    if(i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}
