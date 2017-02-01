/*
 * Names: Ian Kirkpatrick, Benjamin Groseclose, Nathan Johnson,
 * Class: CPS 360,                            Section: Spring 2017
 * Times: Tuesday, Thursday 9:30 - 11:00      Assignment: 02
 * Due: February 7, 2017                      Started: January 31, 2017
 * Credit: 15 points.
 *
 * Problem: Write a program that uses a set structure to store integers supplied
 * by a file passed through stdin. The input will be in the following syntax:
 *  3 15 12 51
 * where the first number (3 in this case) is the length of the set and each
 * subsequent number is a value that is to be stored in the set. There may be
 * less numbers in the input than are allowed by the first number. The file may
 * have several lines of input. Each line read in will cause the program to
 * create a seperate set. It will then print out the sets information in the
 * following format:
 *
 *  Set A: ## ## ## ## ... [or empty]
 *  Set B: ## ## ## ## ... [or empty]
 *  A union B: ## ## ## ## ## ## ## ## ... [or empty]
 *  A intersection B: ## ## ... [or empty]
 *  A difference B: ## ## ## ... [or empty]
 *
 * Solution: Unknown at the time.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

/* Clears the bits in the set s1 and also resets the set count
to 0 */
void initaset(set *s1) {
  int i;
  s1->count = 0;

  for(i = 0; i < SIZE; i++)
    s1->data[i] = 0;
}

/* Returns 1 if x is in set st, 0 otherwise */
int isinset(int x, set st) {
  int i, j;
  i = x & 0x1f;
  j = x >> 3;

  if (st.data[i] & (1<<j)) return 1;
  return 0;
}

/* Adds given element elm to set */
void addtoset(int elm, set *sl) {
  int i, j;

  i = elm & 0x1f;
  j = elm >> 3;

  s1->data[i] = s1->data[i] | (l<<j);
  s1->count += 1;
}

/* sets the value of s3 to the union of sets s1 and s2 */
void setunion(set s1, set s2, set *s3);

/* sets the value of s3 to the intersection of sets s1 and s2 */
void setintersection(set s1, set s2, set *s3);

/* sets the value of s3 to the intersection of sets s1 and s2 */
void setdiff(set s1, set s2, set *s3);

/* perform the set operations and print results as needed.
 result sets will have to cleared after each operation */
void dosetops(set sea, set setb);

/* Writes the label followed by members of s1 to stderr */
void printaset(char *label, set s1);

/* populates the set using values read stdin,
 updates the count of elements, checks for bad input,
 returns 1 on success 0 otherwise */
int buildaset(set *s1);

/* wrapper for initaset() call */
void clearaset(set *s1);

int main(void) {
  set seta, setb;
  int i;

  /* prototypes for the functions called by main go here */
  initaset(&seta); initaset(&setb);
  for(i= 0; i < 3; i++) {
    if(!buildaset(&seta) || !buildaset(&setb)) {
      fprintf(stderr, "Set build failure. \n");
      clearaset(&seta); clearaset(&setb); continue;
    }

    printaset("Set A: ", seta); printaset("Set B: ", setb);
    dosetops(seta, setb);
    clearaset(&seta); clearaset(&setb);
  }
exit(0);
}
