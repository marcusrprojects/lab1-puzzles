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
 *
 * First, we determine the sign of each integer. If each integer has different signs, then our addition must work, since it cannot possibly overflow. Next, to cover the case in which
 * both numbers have the same sign but still do not overflow, we also determine what the sign would be when added. If the sign bit would be the same as the sign of one of the numbers,
 * then this problem will also not overflow. For the ones that do not overflow, we product a value 1 of 1 using not operators and for the ones that do overflow, we produce a value of
 * 0.
 */
int addOverflow(int x, int y) {

int xSign = (x>>31);
int ySign = (y>>31);

int addedSign = (x+y)>>31; //sign digit after adding them.

return (!(!(xSign ^ ySign))) | (!(addedSign ^ xSign));
}

/* 
 * shiftLogical - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: shiftLogical(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 *
 * To avoid doing an arithmetic shift, we need to set the MSB to 0. We do this by shifting the int to the right by 31 digits and masking out extraneous values to distill its sign
 * bit. Then, we shift the number, in which case it now must use zero fill. Finally, if the integer initially started with a 1, we replace the 0 that we initially set it to by 1.
 */
int shiftLogical(int x, int n) {

int signDigit = ((x >> 31) & (1)); //save the sign digit value
x = x & (~(1<<31)); //put a 0 for the sign digit for now
x = x >> n; //shift right by n spaces
x = x | (signDigit << (31-n));
 return x;
}

/* 
 * not - Compute !x without using !
 *   Examples: not(3) = 0, not(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 *
 * First, we utilize a special property of 0 in which negating it results in 0, but negating anything else results in a nonzero number that would then be orred with x. Then, we shift 
 * the sign digit downwards, either resulting in all 1's or 0's, due to the arithmetic righting shifting protocol. We add 1 to this since all 0's + 1 = 1 (for x = 0) and all 1's + 1
 * = 0 (for x=/=0).
 */
int not(int x) {
x = (~x + 1) | x; //make x negative to cancel out values.
x = x >> 31; //will be all 1's if it is negative. Will be all 0's if originally 0.
return x + 1;
}

/* 
 * signMagnitude - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: signMagnitude(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 *
 * To convert to sign-magnitude, we must first shift the first bit entirely downwards to either get all 1's or all 0's. Then we xor this with the initial argument value to find out
 * the absolute value of the data as positive numbers will not change, but negative numbers will flip. Finally, we or this with the initial signbit and add in an extra sign bit
 * to make up for the case when the negative value was flipped but we did not add one to it to complete its negation.
 */
int signMagnitude(int x) {

int y = x>>31; //arithmetic right shift: if positive, it adds 0 and if negative, it adds 11111...
int signBit = y & 1; //mask out only the sign bit
x = y ^ x; //gets absolute value
return ((x | (signBit << 31)) + (signBit));
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
 *
 * This function first converts its assigned value into one with a sign digit of 0. It does this so that it can then see if the value needs to be changed to get its absolute value.
 * The function's argument value will need to be changed if the exponent digits are all 1's and the decimal is nonzero (NaN case). Otherwise, the value would stay the same.
 */
unsigned fp_abs(unsigned uf) {

unsigned comparisonUf = (uf & (~(1<<31)));//make first digit = 0

if (comparisonUf > 0x7f800000) { //nonzero fractions along with 0 sign bit and all 1's for exp activate this condition.
	return uf;
}

else {
return comparisonUf;
}

}

/* 
 * fp_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *  When argument is NaN, return argument
 *  Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 *
 * For this problem, one has to consider the many scenarios that can complicate things. For one, we will not change the value if all of the exponent values are all 1's or all of the
 * 32 bits are 0's. Additionally, for values that are only fractional, we can left shift them by one and maintain their signage. Lastly, for all other values, to double them, one must
 * add 1 to their first exponent bit.
 */
unsigned fp_twice(unsigned uf) {

unsigned signDigit = uf & (1 << 31);

if ((((uf>>23) & 0xff) == 0xff) || (uf == 0) || (uf == (1<<31))) { //takes care of cases where exp is all 1's or the whole number is just 0.
}

else if (((uf>>23) & 0xff) == 0) { //some fractional value exists
uf = (uf << 1); //left shift by 1 to multiply by 2
uf = signDigit | uf; //keeps sign digit intact
}

else {
uf = uf + 0x800000;
}

return uf;
}
