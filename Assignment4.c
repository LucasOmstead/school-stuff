//Program to add or subtract two binary numbers using gate logic (full adder chain)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int parseBinary(char * bin);
void addZeros(char * bin, int len);
void complement(char * bin);
char FullAdder(char A, char B, char C, char *S);
int AddSub(char *N1, char *N2, char C, char *R);
void removeZeros(char * bin);

int main(int argc, char * argv[]) {
    char N1[100] =  {0};
    char N2[100] = {0};
    int N1size;
    int N2size;
    char operation;
    char R[100] = {0};
    if (argc == 1) {
        printf("Run the program by entering two binary integers (max 100 bits)\n \
                with an addition or subtraction sign in between. Example:\n \
                100001 - 100000");
    } else if (argc == 4) {
        //Get strings, ensure they're valid
        strcpy(N1, argv[1]);
        operation  = *argv[2];
        strcpy(N2, argv[3]);
        if (!parseBinary(N1) || !parseBinary(N2)) {
            printf("Please enter valid binary number!");
            return 0;
        }
        //Zero padding logic
        N1size = strlen(N1);
        N2size = strlen(N2);
        if (N1size > N2size) {
            addZeros(N2, N1size);
        } else if (N2size > N1size) {
            addZeros(N1, N2size);
        }
        if (operation == '+') {
            AddSub(N1, N2, '0', R);
            removeZeros(R);
            printf("Result: %s", R);
        } else if (operation == '-') {
            int isNegative = AddSub(N1, N2, '1', R);
            removeZeros(R);
            printf("Result: %c%s", isNegative ? '-' : ' ', R);
        }
    }
    return 0;
}





void removeZeros(char * bin) {
    int i, j = 0;
    for (i = 0; bin[i] != '1' && bin[i] != '\0'; i++) {
        
    } //i is the first 1, or the ending index
    if (bin[i] == '\0') {
        bin[0] = '0';
        bin[1] =  '\0';
        return;
    }
    for (; bin[i] != '\0'; i++) {
        bin[j] = bin[i];
        j++;
    }
    bin[j] = '\0';
}

//Given: string 
//Returns: 1, if the string contains only 0s and 1s
//         0, if the string contains any other character
int parseBinary(char * bin) {
    int i = 0;
    while (bin[i] != '\0') {
        if (bin[i] != '0' && bin[i] != '1') {
            return 0;
        }
        i++;
    }
    return 1;
}


//Given: binary string, target length
//Side effects: adds 0s to the left of the string to make it the target length
void addZeros(char * bin, int len) {
    int i = 0;
    int binLen =  0;
    while (bin[i] != '\0') {
        binLen++;
        i++;
    }
    
    int offset =  len-binLen;
    for (int i = binLen; i >= 0; i--) {
        bin[i+offset] = bin[i];
        //printf("%d %c %c\n", i+offset, bin[i], bin[i+offset]);
        
    }
    for (int i = 0; i < len-binLen; i++) {
        bin[i] = '0';
    }
    bin[binLen+offset+1] = '\0';
}

//Given: binary string
//Side effects: modifies binary string into its one's complement form
void complement(char * bin) {
    int i = 0;
    while (bin[i] != '\0') {
        if (bin[i] == '1') {
            bin[i] = '0';
        } else {
            bin[i] = '1';
        }
        i++;
    }
}


//Given: 3 chars, either 0 or 1
//Returns: carry bit
//Side effects: changes the sum bit
char FullAdder(char A, char B, char C, char * S) {
    int a = (A == '1');
    int b = (B == '1');
    int c = (C == '1');
    *S = ((a && (!b) && (!c)) || ((!a) && b && (!c)) || ((!a) && (!b) && c) || (a && b && c)) + '0';
    return ((a && b) || (b && c) || (c && a)) + '0';
    /*
    int sum = (A == '1') + (B == '1') + (C == '1');
    *S =  (sum%2) + '0';
    return sum/2 + '0';
    */
}


int AddSub(char *N1, char *N2, char C, char *R) {
    
    
    int len = 0;
    while (N1[len] != '\0') {
        len++;
    }
    
    char sum = '0';
    if (C == '0') {
        for (int i = len-1; i >= 0;  i--) {
            C = FullAdder(N1[i], N2[i], C, &sum);
            R[i+1] = sum;
        }
        R[0] = C;
        R[len+1] = '\0';
        return 1;
    } else if (C == '1') {
        complement(N2);
        for (int i = len-1; i >= 0; i--) {
            C = FullAdder(N1[i], N2[i], C, &sum);
            R[i] = sum;
        }
        if (C == '0') {
            complement(R);
            char one[100] = {0};
            one[len-1] = '1';
            one[len] = '\0';
            for (int i = 0; i < len-1; i++) {
                one[i] = '0';
            }
            char dupR[100] = {0};
            strcpy(dupR, R);
            //printf("%s\n%s\n", one, dupR);
            
            
            AddSub(dupR, one, '0', R); 
            //printf("%s + %s = %s", dupR, one, R);
            R[len+1] = '\0'; //check this
            return 1;
        } else {
            R[len] = '\0';
            return 0;
        }
    }
    //closest multiple to len-1
}