#include <stdio.h>

int max_min_vet(int vet[], int *min, int *max){
    int v_min = *min, v_max = *max;
    if(v_min != v_max)
        return 0;
    else
        return 1;
}

int main() {
    int vet[5] = {0, 1, 2, 3, 4};
    int min = vet[0], max = vet[4];

    max_min_vet(vet, &min, &max);
    return 0;
}
