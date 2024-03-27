#include <stdio.h>
#include <assert.h>

int f(int n, int m);

int main( void ) {
    int n, m;
    scanf("%d %d", &n, &m);
    assert(m >= 0);
    assert(n >= m);
    printf("%d", f(n, m));
}
//GIVEN: integers n and m, n >=m >= 0
//RETURNS: the value of f(n, m)
int f(int n, int m) {
    if ((m == 0) || (m == n)) {
        return 1;
    } else {
        return f(n-1, m) + f(n-1, m-1);
    }
}
