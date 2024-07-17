/* 
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's. 

 Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(size, type) (type *)malloc(size * sizeof(type))

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int z = digitsSize - 1; z >= 0; z--) {
        if (digits[z] < 9) {
            digits[z]++;
            *returnSize = digitsSize;
            return digits;
        }

        digits[z] = 0;
    }
    // Covering for all digits being nine
    // int* arrayVal = MALLOC(digitsSize + 1, int);
    int *arrayVal = (int *)malloc((digitsSize + 1) * sizeof(int));

    if(arrayVal == NULL) {
        return NULL;
    }

    // Setting first digit to one and rest to zero
    arrayVal[0] = 1;
    for(int t = 1; t <= digitsSize; t++) {
        arrayVal[t] = 0;
    }

    *returnSize = digitsSize + 1;
    return arrayVal;


}

int main()
{
    int digits1[] = {4,3};
    int size1 = sizeof(digits1) / sizeof(digits1[0]);
    int newSize1;
    int *result1 = plusOne(digits1, size1, &newSize1);
    printf("Example 1 output: ");
    for (int i = 0; i < newSize1; i++) {
        printf("%d", result1[i]);
    }
    printf("\n");
}