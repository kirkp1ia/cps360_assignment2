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

/*
Struct for set.

data:
  The array of bytes. Each bit in each byte corresponds to a number and
  whether or not that integer is in this set. Each byte at index i contains bits
  corresponding to those integers >= i * 8 and < (i + 1) * 8. Then, each bit j in
  byte i corresponds to the actual value. j is the remainder of the given number
  divided by 8.

count:
  The number of elements in the set.
*/
struct set{
  char data[SIZE];
  int count; /* count of elements/members */
};
typedef struct set set;

/*
Sets all elements in s1 to 0 and set the count to 0.
*/
void initaset(set *s1) {
  int i;
  s1->count = 0;

  for(i = 0; i < SIZE; i++)
    s1->data[i] = 0;
}


/*
Determin weather x is contained in st. This function looks at the byte
  corresponding to x / 8. It then looks at the bit in that byte that is at the
  bit corresponding to elm % 8. If that bit is on, then x is in the set and 1 is
  returned. Otherwise, 0 is returned.

Limitations: none.
*/
int isinset(int x, set st) {
  int i, j;
  int mod(int num, int mod);
  
  i = elm >> 3;
  j = mod(elm, 8);

  if (st.data[i] & (1<<j)) return 1;
  return 0;
}

/*
Adds given element elm to set. elm can be found in the byte that corresponds
to elm / 8. It then sets the bit at elm % 8 in that byte to on.

Limitations: none.
*/
void addtoset(int elm, set *sl) {
  int i, j;
  int mod(int num, int mod);
  
  i = elm >> 3;
  j = mod(elm, 8);

  s1->data[i] = s1->data[i] | (1<<j);
  s1->count += 1;
}

/*
sets the value of s3 to the union of sets s1 and s2
*/
void setunion(set s1, set s2, set *s3);

/*
sets the value of s3 to the intersection of sets s1 and s2
*/
void setintersection(set s1, set s2, set *s3);

/*
sets the value of s3 to the intersection of sets s1 and s2
*/
void setdiff(set s1, set s2, set *s3);

/*
perform the set operations and print results as needed.
  result sets will have to cleared after each operation
*/
void dosetops(set sea, set setb);

/*
Writes the label followed by members of s1 to stderr
*/
void printaset(char *label, set s1);

/*
populates the set using values read stdin,
  updates the count of elements, checks for bad input,
  returns 1 on success 0 otherwise
 */
int buildaset(set *s1);

/*
Wrapper for initaset() call. All this function does is calls initaset. This
  acts like a refresh function for a given set.
*/
void clearaset(set *s1) {
  initaset(&s1);
}

/*
Frees the memory allocated to a set by calling free(s1). s1 is also set
  to NULL.
*/
void freeaset(set *s1) {
  free(s1);
  s1 = NULL;
}

/*
Perform a modulo operation on num based on mod.
  This is the same as if num % mod were called. The difference here is that we are
  only using bitwise operations.

To perform this, we extract the bits from num that would be dropped if we were
  to divide num by mod. These bits represent the remainder. To get these bits,
  use the & operator to extract any bits that are less than mod (mod-1).

Limitations: none
*/
int mod(int num, int mod) {
  return num & (mod-1);
}

int main(void) {
  set seta, setb;
  int i;

  int initaset(set *s1);
  int isinset(int x, set st);
  void addtoset(int elm, set *sl);
  void freeaset(set *s1);
  
  initaset(&seta); initaset(&setb);

  addtoset(4, &seta);
  
  clearaset(&seta);
  clearaset(&setb);
  // for(i= 0; i < 3; i++) {
  //   if(!buildaset(&seta) || !buildaset(&setb)) {
  //     fprintf(stderr, "Set build failure. \n");
  //     clearaset(&seta); clearaset(&setb); continue;
  //   }
  // 
  //   printaset("Set A: ", seta); printaset("Set B: ", setb);
  //   dosetops(seta, setb);
  //   clearaset(&seta); clearaset(&setb);
  // }
  exit(0);
}
