#include <stdio.h>
#include <string.h>



int evalTerm(int A, int B, int C, char *term);


int main(int argc, char** argv) {
    if (argc == 1) {
        printf("Truth table generator for 3-variable Boolean functions\n"
                "Usage: enter a Boolean function as a sum of products\n"
                "E.g.: ./a.out \"AB'\" + \"BC'\" + \"A'BC\"");
        return 1;
    } else {
        int num_terms = ((argc-1)/2)+1; //number of terms in the expression
        printf("F is the sum of %d product terms\n", num_terms);
        printf("F = ");
        for (int i = 1; i < argc; i += 2) {
            printf("%s ", argv[i]);
            if (i < (argc-2)) {
                printf(" + ");
            }
        }
        printf("\n\nTruth table of F\n");
        printf("A B C | F\n");
        printf("_________\n");
        int currentF = 0; //Stores the result of the function evaluated with each input

        for (int i = 0; i < 8; i++) {
            //Nested loop to print the table
            if (i < 4) {
                printf("0 ");
            } else {
                printf("1 ");
            }
            if ((i % 4) < 2) {
                printf("0 ");
            } else {
                printf("1 ");
            }
            if (i % 2) {
                printf("1 | ");
            } else {
                printf("0 | ");
            }
            //If any of the terms is 1, the function = 1
            for (int j = 1; j < argc; j += 2) {
                if (evalTerm((i>3), ((i%4)>1), (i%2), argv[j])) {
                    currentF = 1;
                }
            }
            printf("%d\n", currentF);
            currentF = 0;
        }
    }
}
int evalTerm(int A, int B, int C, char *term) {
    //Go through each literal, if any of them are false then the function returns false
    int i = 0;
    //Check to see if any of the characters are invalid. If they are, return 1 for error handling
    while (term[i] != '\0') {
        if (term[i] != 'A' && term[i] != 'B' && term[i] != 'C' && term[i] != '\'') {
            
            return 1;
        }
        i++;
    }
    
    i = 0;
    while (term[i] != '\0') {
        if (term[i] != 'A' && term[i] != 'B' && term[i] != 'C' && term[i] != '\'') {
           
            return 1;
        }
        if (term[i+1]=='\'') {
            if ((term[i]=='A' && A) || (term[i]=='B' && B) || (term[i]=='C' && C)) {
                return 0;
            }
            i++;
        } else {
            if ((term[i]=='A' && !A) || (term[i]=='B' && !B) || (term[i]=='C' && !C)) {
                return 0;
            }
        }
        i++;
    }
    
    return !!(i);
}