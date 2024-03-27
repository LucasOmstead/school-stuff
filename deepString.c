#include <stdio.h>

int main() {
    int i  = 0;
    int currentDepth =  0;
    int highestDepth =  0;
    char deepestString[1004];
    int deepestLen = 0;
    int currentLen = 0;
    char fullString[1004];
    scanf("%s", &fullString);
    while (fullString[i] != '\0') {
        if (fullString[i] == '(') {
            currentDepth += 1;
            currentLen = 0;
            if (currentDepth > highestDepth) {
                deepestLen = 0;
            }
            //printf("Open bracket\n CurrentDepth: %d deepestLen: %d  currentLen: %d", currentDepth, deepestLen, currentLen);
            i++;
            continue;
        }
        if (fullString[i] == ')') {
            if (highestDepth < currentDepth) {
                highestDepth = currentDepth;
            }
            currentDepth -= 1;
            currentLen = 0;
            //printf("Close bracket\nHighest: %d CurrentDepth: %d   %d", highestDepth, currentDepth, currentLen);
            i++;
            continue;
        }
        if ((currentDepth > highestDepth) || (currentDepth == 0 && highestDepth == 0)) {
            deepestString[currentLen] = fullString[i];
            currentLen++;
            deepestLen = currentLen;
            //printf("he");
        }
        i++;
    }
    //printf("\n\n%d", deepestLen);
    deepestString[deepestLen] = '\0';
    printf("%s\n", deepestString);

}