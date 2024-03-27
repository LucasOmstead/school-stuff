#include <stdio.h>
#include <stdbool.h>

bool matrix_mirrored(const int n, const int A[][5]);

int main(void) {
    int n;
    scanf("%d", &n);
    int matrix[10][5];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2], &matrix[i][3], &matrix[i][4]); 
    }
    printf("%c", (matrix_mirrored(n, matrix) ? 'Y' : 'N'));
}
//Requires: 2d array representing an nx5 matrix, n<=10
//Returns: true if matrix is symmetrical, else false 
bool matrix_mirrored(const int n, const int A[][5]) {
    for (int i = 0; i < n; i++) {
        if ((A[i][0]!=A[i][4])||(A[i][1]!=A[i][3])) {
            return false;
        }
    }
    return true;
    
}