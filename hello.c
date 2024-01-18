#include <stdio.h>

int main() {
    int x = 12;
    float y = 3.14;
    char *s = "Hello, World!";

    printf("x is %d, y is %.2f \n%s\n", x, y, s);
    for (int i = 0; i <=4; i++) {
        printf("%d x 5 = %d\n", i, i * 5);
    }
    return 0;
}