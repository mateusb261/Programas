#include <stdio.h>

void troca(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    float a = 1.0, b = 2.0;

    troca(&a, &b);
    return 0;
}
