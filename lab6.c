#include <stdio.h>


int first_positive(const int A[], const int n);

int main(void) {
    int n;
    scanf("%d", &n);
    int A[1000] = {0};
    int i = 0;
    
    while (i<n) {
        scanf("%d", &A[i]);
        i++;
    }
    printf("%d", first_positive(A, n-1)); //subtract 1 from n, makes the calculations easier
}

int first_positive(const int A[], const int n) {
    if (n == 0 ) { //n == 0 comes from the second case which is an edge case, n == 1 comes from the first case in which case A[0] > 0
        if (A[0] > 0) {
            return A[0];
        } else {
            return 0;
        }
    }
    //n equals the length of the array. If n is even, A[n/2] = the middle element of the array to the right
    //if n is odd, A[n/2] = the middle element of the array 
    //If A[n/2] is greater than 0: return the same function called at 
    
    if (A[n/2] > 0) {
        return first_positive(A, n/2);
    } else if (A[n/2] < 0) {
        return first_positive(&A[n/2+1], n-(n/2)-1);
    }
    

}