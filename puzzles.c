/* 
 * Lab 1 - A Bit Puzzling 
 * 
 *Marcus Ribeiro
 * 
 * puzzles.c - Source file with your puzzle solutions.
 *
 * NOTE: Do not include the <stdio.h> header; it confuses the blc
 * compiler. You can still use printf for debugging, although you
 * might get a compiler warning (this is an exception to the
 * 'never accept compiler warnings' rule!).
 */

/* 
 * maxVal - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 * 
 * In order to get the biggest number, represented by bit containing a 0 followed by 31 1's, flip the reverse value. Therefore, this involves producing a number that starts with 
 * a 1 and continues with 0's using left shift. Then, this binary value should be flipped to get the desired number.
 *
 */
int maxVal(void) {
int x = 1<<31;  
return ~x;
}

/* 
 * negCheck - return 1 if x < 0, return 0 otherwise 
 *   Example: negCheck(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 1
 * 
 * To see if a number is negative, its first digit must be equal to 1. Therefore, we isolate the first digit by flipping it and then determine whether it receives a 0 or 1 based on
 * this flipped value. This utilizes the idea that  negative numbers normally do not operate properly with shifts.
 */
int negCheck(int x) {
int y = x>>31;  
return !(~(y));
}

/* 
 * lsbCopy - set all bits of result to least significant bit of x
 *   Example: lsbCopy(5) = 0xFFFFFFFF, lsbCopy(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 1
 * 
 * To set all bits to either 1 or 0 based on the LSB, the LSB should be isolated by moving it to the first position and determining whether it is a 1 or 0. Given this distinction,
 * true or false distinctions help generate a number that when negated, is either all 1's or 0's, as desired.
 */
int lsbCopy(int x) {
int y = x<<31;
y = !!y;
return ~y+1;
}

/* 
 * andBits - x&y using only ~ and | 
 *   Example: andBits(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 * 
 * To find out what is shared, you use and. To find out what is not shared, examine what both bits do not have and see which places they do not share 1's. Then, negate this to find
 * out which values are shared.
 */
int andBits(int x, int y) {
  
return ~(~x|~y);
}

/* 
 * xorBits - x^y using only ~ and & 
 *   Example: xorBits(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 * 
 * To do an exclusive or, we must first compare the flipped version of one variable to the normal version of the other, figuring out which digits follow the rule, and vice versa.
 * Then, we flip these digits and & them to find the digits that do not follow the rule. This allows us to find the digits that follow the rule by flipping this number.
 */
int xorBits(int x, int y) {
  return ~((~(~x&y))&(~(x&~y)));
}

/* 
 * setThirdBits - return value with every third bit (starting with the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int setThirdBits(void) {
  return 2;
}

/* 
 * byteExtract - Extract byte n from x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: byteExtract(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int byteExtract(int x, int n) {
  return 2;
}

/* 
 * bitFit - return 1 if x can be represented as an 
 *  n-bit, two's complement integer or 0 otherwise.
 *   1 <= n <= 32
 *   Examples: bitFit(5,3) = 0, bitFit(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int bitFit(int x, int n) {
  return 2;
}

/* 
 * byteSwitch - swaps the nth byte and the mth byte
 *  Examples: byteSwitch(0x12345678, 1, 3) = 0x56341278
 *            byteSwitch(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwitch(int x, int n, int m) {
    return 2;
}

/* 
 * addOverflow - Determine if can compute x+y without overflow
 *   Example: addOverflow(0x80000000,0x80000000) = 0,
 *            addOverflow(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOverflow(int x, int y) {
  return 2;
}

/* 
 * shiftLogical - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: shiftLogical(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int shiftLogical(int x, int n) {
  return 2;
}

/* 
 * not - Compute !x without using !
 *   Examples: not(3) = 0, not(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int not(int x) {
  return 2;
}

/* 
 * signMagnitude - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: signMagnitude(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int signMagnitude(int x) {
  return 2;
}

/* 
 * fp_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned fp_abs(unsigned uf) {
  return 2;
}

/* 
 * fp_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
unsigned fp_twice(unsigned uf) {
  return 2;
}

