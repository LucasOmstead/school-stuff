#include <stdio.h>

int main() {
    int i  = 0;
    int currentDepth =  0;
    int highestDepth =  0;
    char deepestString[1000];
    int deepestLen = 0;
    int currentLen = 0;
    char fullString[1000];
    scanf("%s", fullString);
    while (fullString[i] != '\0') {
        if (fullString[i] == '(') {
            currentDepth += 1;
            currentLen = 0;
            i++;
            continue;
        }
        if (fullString[i] == ')') {
            highestDepth = currentDepth;
            currentDepth -= 1;
            currentLen = 0;
            i++;
            continue;
        }
        if (currentDepth == highestDepth) {
            deepestString[currentLen] = fullString[i];
            currentLen++;
            deepestLen = currentLen;
        }
        i++;
    }
    deepestString[deepestLen] = '\0';
    printf("%s\n", deepestString);

    return 0;
}