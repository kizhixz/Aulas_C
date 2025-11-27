/*

Exercício 10: Gerenciamento de Memória Qual é a principal 
característica do gerenciamento de memória em C que o diferencia 
de linguagens como Java ou Python, e por que essa característica torna 
a linguagem tão poderosa (e perigosa)?

*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("Em C, o gerenciamento de memória é manual, o que significa que o programador é responsável por alocar e liberar memória usando funções como malloc() e free().\n");
    printf("Essa característica torna C poderosa porque oferece controle total sobre o uso da memória, permitindo otimizações específicas para desempenho e eficiência.\n");
    printf("No entanto, também torna a linguagem perigosa, pois erros no gerenciamento de memória, como vazamentos de memória ou acessos inválidos, podem levar a falhas no programa ou vulnerabilidades de segurança.\n");
    return 0;
}