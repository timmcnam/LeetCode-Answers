/*
* Given two strings needle and haystack, 
* return the index of the first occurrence of needle in haystack, 
* or -1 if needle is not part of haystack.
* 
* Example 1:
*
* Input: haystack = "sadbutsad", needle = "sad"
* Output: 0
* Explanation: "sad" occurs at index 0 and 6.
* The first occurrence is at index 0, so we return 0.
*
* Example 2:
* 
* Input: haystack = "leetcode", needle = "leeto"
* Output: -1
* Explanation: "leeto" did not occur in "leetcode", so we return -1.
*
* Constraints:
*
* 1 <= haystack.length, needle.length <= 104
* haystack and needle consist of only lowercase English characters.
* 
*/

int strStr(char* haystack, char* needle) {
    // if null, return 0
   if (*needle == '\0') {
        return 0;
    }

    int index = 0;

    while (*haystack) {
        // takes the current position of haystack
        char *z = haystack;
        // takes the beginning string character of needle
        char *t = needle;

        // while we are pointing to a character and the characters 
        // we are pointing to are equal to each other (potential match found code)
        while (*z && *t && (*z == *t)) {
            z++;
            t++;
        }

        // If we reached the end of needle, we found a match
        if (*t == '\0') {
            return index;
        }

        // if none of the conditions above are met, 
        // keep incrementing haystack till we find a letter
        // beginning with the same one as needle
        haystack++;
        // increment until we find where the needle starts
        index++;
    }

    // If no match is found, return -1
    return -1;
}


// Code using Code::Blocks to print the returned index from main
int main()
{
    char haystack[] = "nutterbutter";
    char needle[] = "butter";
    int result = strStr(haystack, needle);
    printf("%d\n", result);
    return 0;
}