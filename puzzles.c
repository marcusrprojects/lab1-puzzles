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
 *
 * To set the third bits using only these operators and no loops, one must initially choose a number that's first few bits follow the pattern. This then must be shifted as new
 * bits are added to complete the trend until the number is fully composed. This number would be 00100100...1001.
 */
int setThirdBits(void) {

int x = 0x249;
x = x | (x<<9);
x = x | (x<<15);
return x;
}

/* 
 * byteExtract - Extract byte n from x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: byteExtract(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 * 
 * To do this, use masking and shift the mask based on which areas of code should be illuminated. In this case, it is split into 4 even parts.
 * 
 */
int byteExtract(int x, int n) {

return (x >> (8*n)) & 0xFF;
}

/* 
 * bitFit - return 1 if x can be represented as an 
 *  n-bit, two's complement integer or 0 otherwise.
 *   1 <= n <= 32
 *   Examples: bitFit(5,3) = 0, bitFit(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 *
 * Given that we are dealing with 32-bit numbers, to retain the bits followed by 0, the amount of distance necessary to shift out all of the extra bits in one direction would be
 * be 32 - n. To negate a number, one must follow the rule for 2's complement, which involves flipping it and adding one. After shifting in this direction, one can recieve an n-bit
 * number by shifting the same number of spaces in the other direction. In theory, if x was an n-bit number, this generated value would equal x. An exclusive or would consequently
 * result in 0, since the values would not be exclusive. The logical not then would turn this 0 into a value of 1 to show that these values can be represented with n bits.
 */
int bitFit(int x, int n) {
int shiftDistance = 32 + (~n + 1);
  return !(((x << shiftDistance) >> shiftDistance) ^ x);
}

/* 
 * byteSwitch - swaps the nth byte and the mth byte
 *  Examples: byteSwitch(0x12345678, 1, 3) = 0x56341278
 *            byteSwitch(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 *
 * To swap bytes, first save each byte separately. Next, shift each isolated byte to its new location. Finally, replace former bits in bytes that will be swapped with 0 and add in
 * the necessary one bits to represent the new byte locations.
 */
int byteSwitch(int x, int n, int m) {

//isolate n
int nAlone = (x >> (8 * n)) & 0xFF;
//isolate m
int mAlone = (x >> (8 * m)) & 0xFF;

//properly shifted nAlone values. Moves n to m's place and vice versa.
nAlone = nAlone << (m * 8); //nAlone shifts to n's new spot
mAlone = mAlone << (n * 8); //mAlone shifts to m's new spot

//places all 1's where n/m were before
int nOnes = 0xFF << (8 * m); //nOnes shifts 1's to n's new spot
int mOnes = 0xFF << (8 * n); //mOnes shifts 1's to m's new spot

//Zero's out places so that they can be replaced with a new byte
x = (x & ~nOnes) | nAlone; //flip nAlone
x = (x & ~mOnes) | mAlone; //flip mAlone

return x;
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

//if both negative, the result must be negative or else it is wrong. Check sign digit. FALSE!

//if both positive, the result must be positive or else it is wrong. Check sign digit. FALSE!

//Otherwise, true

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

