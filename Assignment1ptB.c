#include <stdio.h>
#include <ctype.h>


int div_mapping(int n);  



int main( void ) {
    int n;
    int valid = scanf("%d", &n);
    if((n < 0) || valid == 0){
        printf("Invalid integer");
        return 0;
    }
    printf(" %d\n", div_mapping(n));
    return 0;
}


//GIVEN: an integer n > 0
//RETURNS: ceil(log base 2 of n), and prints the number backwards in binary with each digit separated by spaces
int div_mapping(int n) {
    if (n==0) {
        printf("end");
        return 0;
    } else if (n%2) {
        printf("1 ");
        return 1 + div_mapping(n/2);
    } else {
        printf("0 ");
        return 1 + div_mapping(n/2);
    }
}