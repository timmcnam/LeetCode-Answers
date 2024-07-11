#include <stdio.h>

#define IV(x) (*(x) == 'I' && *((x) + 1) == 'V')
#define IX(x) (*(x) == 'I' && *((x) + 1) == 'X')
#define XL(x) (*(x) == 'X' && *((x) + 1) == 'L')
#define XC(x) (*(x) == 'X' && *((x) + 1) == 'C')
#define CD(x) (*(x) == 'C' && *((x) + 1) == 'D')
#define CM(x) (*(x) == 'C' && *((x) + 1) == 'M')

int romanToInt(char* s) {
    int result = 0;     
    while(*s) {
        if (IV(s)) {
            result += 4;
            s += 2;
        }
        else if (IX(s)) {
            result += 9;
            s += 2;
        }
        else if (XL(s)) {
            result += 40;
            s += 2;
        }
        else if (XC(s)) {
            result += 90;
            s += 2;
        }
        else if (CD(s)) {
            result += 400;
            s += 2;
        }
        else if (CM(s)) {
            result += 900;
            s += 2;
        }
        else {
            switch (*s) {
                case 'I': 
                    result += 1;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    result += 10;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    result += 100;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
                default:
                    return -1; // Invalid input character
            }
            s++; // Move pointer to the next character
        }
    }
    return result;
}