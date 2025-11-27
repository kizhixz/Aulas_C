/*
Exercício 9: O Retorno de main A função main em C tem o tipo de retorno int. 
O que o valor numérico (geralmente 0) 
retornado por main indica ao sistema operacional?

*/

#include <stdio.h>

int main(void){
    printf("O valor numérico retornado por main indica ao sistema operacional o status de término do programa. \n");
    printf("Um valor de 0 geralmente indica que o programa foi executado com sucesso, \n");
    printf("enquanto valores diferentes de 0 indicam que ocorreram erros ou condições especiais durante a execução.\n");
    return 0;
}



