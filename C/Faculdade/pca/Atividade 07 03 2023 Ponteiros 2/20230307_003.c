#include <stdio.h>

int main() {
    int a = 1;
    double b = 2.0;
    char c = 'c';

    int *pont_a = &a;
    double *pont_b = &b;
    char *pont_c = &c;

    printf("Valores antes:\n");
    printf("%i\n", *pont_a);
    printf("%f\n", *pont_b);
    printf("%c\n", *pont_c);

    *pont_a = 2;
    *pont_b = 3.0;
    *pont_c = 'd';

    printf("Valores depois:\n");
    printf("%i\n", *pont_a);
    printf("%f\n", *pont_b);
    printf("%c\n", *pont_c);
    return 0;
}
