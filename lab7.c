#include <stdio.h>

int extract_digits(const char in[], char out[]);


int main(void) {
    char in[1000], out[1000];
    scanf("%s", in);
    int sum = extract_digits(in, out);
    printf("%s %d\n", out, sum);
}

int extract_digits(const char in[], char out[]) {
    int i = 0;
    int outIndex = 0;
    int sum = 0;
    while (in[i] != '\0') {
        if (in[i] <= '9' && in[i] >= '0') {
            sum += in[i] - '0';
            out[outIndex] = in[i];
            outIndex++;
        } 
        i++;
    }
    out[outIndex] = '\0';
    return sum;
}