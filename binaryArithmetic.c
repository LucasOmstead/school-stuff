//do binary arithmetic on 2 numbers, either + or -
#include <stdio.h>

void get2complement(char *num1);
void Add(char *num1, char *num2, char *result);
int parse(char *num1);


int main(int argc, char** argv) {
    //Print usage instructions if the user runs the program without arguments
    if (argc == 1) {
        printf("Usage: binaryArithmetic < Binary1 > < +/- > < Binary2 >\n");
        return 1;
    //Run the main program if the user properly enters arguments
    } else if (argc == 4) {
        char *num1 = *(argv + 1); 
        char *operation = *(argv + 2);
        char *num2 = *(argv + 3);
        char result[9];
        char *ptrresult = result;
       
        if (!parse(num1)) {
            return 0;
        }
        if (!parse(num2)) {
            return 0;
        }
        if (*operation=='-') {
            get2complement(num2);
        }
        Add(num1, num2, ptrresult);
        printf("%s %c %s = %s", num1, *operation, num2, ptrresult);
        return 1;
    //Tell the user how to use the program if the wrong number of arguments are entered
    } else {
        printf("Incorrect number of arguments!\nUsage: binaryArithmetic < Binary1 > < +/- > < Binary2 >");
        return 0;
    }
}


int parse(char *num1) {
    //Check if the string is 9 bytes / binary number is 1 byte
    if (num1[8] != '\0') {
        printf("Binary number must be one byte!");
        return 0;
    }
    //Check if all characters are 1s or 0s
    for (int i = 0; i < 8; i++) {
        if (!(num1[i] == '1' || num1[i]=='0')) {
            printf("Illegal character in binary string");
            return 0;
        }
    }
    return 1;
}
void get2complement(char *num1) {
    int firstIndex;
    //Use the heuristic: starting from the right, look for the first 1, then keep it the same and invert all remaining bits
    for (int i = 7; i >=0; i--) {
        if (num1[i]=='1') {
            firstIndex = i;
            break;
        }
    }
    for (int i = 0; i < firstIndex; i++) {
        if (num1[i]=='1') {
            num1[i]='0';
        } else {
            num1[i]='1';
        }
    }
}
void Add(char *num1, char *num2, char *result) {
    int carry = 0;
    int total = 0;
    //Carrying logic: 
    for (int i = 7; i >= 0; i--) {
        total = carry + (int)(num1[i]=='1') + (int)(num2[i]=='1');
        result[i] = (char)('0' + (total%2));
        carry = (total>1);
    }
    result[8] = '\0';
}


