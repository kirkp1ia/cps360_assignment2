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
#define OUTPUT stdout

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

int main(void) {
  set seta, setb;

  void initaset(set *s1);
  int isinset(int x, set st);
  void addtoset(int elm, set *sl);
  void freeaset(set *s1);

  initaset(&seta); initaset(&setb);

  addtoset(7, &seta);
  addtoset(5, &seta);
  addtoset(26, &seta);
  addtoset(8, &seta);

  char labela[] = "Set A";
  char labelb[] = "Set B";
  printaset(labela, seta);
  printaset(labelb, setb);

  clearaset(&seta);
  clearaset(&setb);

  // int i;
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

  i = x >> 3;
  j = mod(x, 8);

  if (st.data[i] & (1<<j)) return 1;
  return 0;
}

/*
Adds given element elm to set. elm can be found in the byte that corresponds
to elm / 8. It then sets the bit at elm % 8 in that byte to on.

Limitations: none.
*/
void addtoset(int elm, set *s1) {
  int i, j;
  int mod(int num, int mod);

  i = elm >> 3;
  j = mod(elm, 8);

  s1->data[i] = s1->data[i] | (1<<j);
  s1->count += 1;
}

/*
Sets the value of s3 to the union of sets s1 and s2. Do this by extracting all
  bits in s1 and s2 into s3 using the | (OR) operator with s1 and s2. s3 will
  contain the union of s1 and s2.
*/
void setunion(set s1, set s2, set *s3) {
  s3->data = s1.data | s2.data;
  s3->count = s1.count + s2.count;
}

/*
Sets the value of s3 to the intersection of sets s1 and s2. Do this by
  extracting all bits that are in both s1 and s2 into s3 using the & (AND)
  operator with s1 and s2. s3 will contain the intersection of s1 and s2.

Limitations: count in s3 is Unknown because we don't know how many bits were
  extracted from both sets into s3.
*/
void setintersection(set s1, set s2, set *s3) {
  s3->data = s1.data & s2.data;
}

/*
Sets the value of s3 to the intersection of sets s1 and s2. Do this by
  extracting all bits that are in both s1 and s2 into s3 using the & (AND)
  operator with s1 and s2. s3 will contain the intersection of s1 and s2.

Limitations: count in s3 is Unknown because we don't know how many bits were
  extracted from both sets into s3.
*/
void setdiff(set s1, set s2, set *s3) {
  s3->data = s1.data ^ s2.data;
}

/*
perform the set operations and print results as needed.
  result sets will have to cleared after each operation
*/
void dosetops(set sea, set setb);

/*
Prints every element in set s1 prepended by label. The print is in the format

  label: s1[0] s1[1] s1[2] etc...

For example, if label is "Set A:" and s1 has elements 3, 6, 2, 8 and 4, then
  printaset will print

  "Set A: 2 3 4 6 8".

The printed elements will be in order because of the way the set stores it's
  elements.

This function loops through each bit in the set and adds the corresponding
  number to the printed output. In order to get the indevidual values from
  each byte, we loop through 0 to 8. each iteration, we bit shift the byte
  that many places and extract the first bit. If the bit is 1, then we know that
  the number associated with that bit is in the set. The index in the byte that
  the bit is at is the remainder that will be added on to the base
  (or 8 * byte_number). Then print it out.
*/
void printaset(char *label, set s1) {
  fprintf(OUTPUT, "%s:", label);
  if (s1.count > 0) {
    int i;

    for (i = 0; i < SIZE; i++) {
      int base = i << 3;
      char byte = s1.data[i];

      for (int j = 0; j < 8; j++) {
        int rem = byte >> j;
        if (rem & 0x01) {
          int val = base + j;
          fprintf(OUTPUT, " %d", val);
        }
      }
    }
  } else {
    fprintf(OUTPUT, " empty");
  }
  fprintf(OUTPUT, "\n");
}

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
  initaset(s1);
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
