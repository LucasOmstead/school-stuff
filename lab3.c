#include <stdio.h>


void char_caesar(char *character, int shift);

int main(void) {
    int shift;
    char character;
    scanf("%c %d", &character, &shift);
    char_caesar(&character, shift);
    printf("%c\n", character);
}

//GIVEN: character to be shifted (a-z, A-Z), number it should be shifted by (0-25)
//RETURNS: the shifted character
void char_caesar(char *character, int shift) {
    int lowercase = 0;
    if (('a' <= *character) && (*character <= 'z')) {
        *character -= 'a'-'A';
        
        lowercase = 1;
    }
    
    *character -= 'A';
    
    *character += shift;
    
    *character = *character % 26;
     
    *character += 'A';
    if (lowercase) {
        *character += 'a' - 'A';
    }
    
}
