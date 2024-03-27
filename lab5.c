#include <stdio.h>
#include <limits.h>

int * select_ptr(int A[]);
void selection_sort(int A[]);

int main(void) {
    int i = 0;
    int A[10001];
    while (1) {
        scanf("%d", &A[i]);
        if (A[i] == 0) {
            break;
        }
        i++;
    }
    selection_sort(A);
    i = 0;
    while (A[i] != 0) {
        if (A[i+1] == 0) {
            printf("%d", A[i]);
            break;
        }
        printf("%d ", A[i]);
        i++;
    }
    printf("\n");
}


//Requires: int array
//Returns: a pointer to the smallest element in A
int * select_ptr(int A[]) {
    int i = 0;
    int min = INT_MAX;
    int minIndex = 0;
    while (A[i] != 0) {
        if (A[i] < min) {
            minIndex = i;
            min = A[i];
        }
        i++;
    } 
    return &A[minIndex];
}

//Requires: int array
//Returns: nothing
//Side effects: sorts array
void selection_sort(int A[]) {
    int i = 0;
    int * min;
    int temp;
    while (A[i] != 0) {
        min = select_ptr(&A[i]);
        temp = *min;
        *min = A[i];
        A[i] = temp;
        i++;
    }

}