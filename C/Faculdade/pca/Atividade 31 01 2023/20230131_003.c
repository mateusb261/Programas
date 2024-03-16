#include <stdio.h>

int main(){
    char data[11];
    do{
        printf("Digite uma data no formato 'DD/MM/AAAA': ");
        gets(data);
        printf("\n");
        if((data[2] != '/') || (data[5] != '/') || (data[0] < '0' || data[0] > '9')  || (data[1] < '0' || data[1] > '9') || (data[3] < '0' || data[3] > '9') || (data[4] < '0' || data[4] > '9') || (data[6] < '0' || data[6] > '9') || (data[7] < '0' || data[7] > '9') || (data[8] < '0' || data[8] > '9') || (data[9] < '0' || data[9] > '9'))
            printf("Entrada invalida. ");
    } while ((data[2] != '/') || (data[5] != '/') || (data[0] < '0' || data[0] > '9') || (data[1] < '0' || data[1] > '9') || (data[3] < '0' || data[3] > '9') || (data[4] < '0' || data[4] > '9') || (data[6] < '0' || data[6] > '9') || (data[7] < '0' || data[7] > '9') || (data[8] < '0' || data[8] > '9') || (data[9] < '0' || data[9] > '9'));
    return 0;
}
