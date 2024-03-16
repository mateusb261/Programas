#include <stdio.h>
#include <string.h>

int main(){
    char frase[100];
    printf("Digite uma frase: ");
    gets(frase);
    int i, temp;
    int len = strlen(frase);
    for(i = 0; i <= len; i++){
        temp = frase[i];
        if(temp != 32 && i < len)
            frase[i] = temp + 3;
        else {
            if(i == len)
                frase[i] = '\0';
        }
    }
    printf("%s", frase);
    return 0;
}
