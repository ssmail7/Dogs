# Dogs

Version 1 (dogs.c):
- This program maintains records for canine patients at an animal hospital.
Each dog’s record has a name, a breed, a patient number, and owner’s last name.
It uses a dynamically allocated linked list to store the records.
- For a detailed description of this project, please refer to Project 9.pdf

Version 2 (dogs2.c, dogs2.h, readline2.c, readline2.h, records2.c, makefile):
- This version modifies the original program so that there are three source files and two header files.
- Compile: "gcc -o records2 readline2.c dogs2.c records2.c"
- For a detailed description of this project, please refer to Project 9.pdf

(Note: Despite the description in the PDF, this version does NOT contain a makefile
due to additional versions and the conflict with the "makefile" file name.)

Version 3 ():
- This version modifies the previous version by:
  1) Adding a delete_from_list function in dogs.c that deletes a dog from the list.
  2) Changing the Append function so the dog is inserted into an ordered list (by dog name and owner last name).
  3) Including a makefile.
- For a detailed description of this project, please refer to Project 11.pdf
