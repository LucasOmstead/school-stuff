#include <stdio.h>
#include <stdbool.h>


int num_factors_of_n(int n, int k);
bool is_prime(int n);

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", num_factors_of_n(n, k));
    if (is_prime(n)) {
        printf("prime");
    } else {
        printf("not prime");
    }
}

//GIVEN: an integer > 0
//RETURNS: true if the integer is prime, otherwise false
bool is_prime(int n) {
    if (num_factors_of_n(n, n) == 2) {
        return true;
    } else {
        return false;
    }
}
//GIVEN: an integer n and upper bound k
//RETURNS: the number of factors of that integer between 1 and the upper bound
int num_factors_of_n(int n, int k) {
    if (k == 1) {
        
        return 1;
    } else if (n % k == 0) {
       
        return 1 + num_factors_of_n(n, k-1);
    } else {
        
        return num_factors_of_n(n, k-1);
    }
}