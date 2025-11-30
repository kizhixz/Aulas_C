/*
Exercício 1 — Entrada e saída simples

Peça nome e idade do usuário e imprima de volta.

*/

#include <stdio.h>

int main(void){

    char nome[100];  
    int idade;

    printf("Digite seu nome: ");
    scanf("%99s", nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Nome: %s\n", nome);
    printf("idade: %d\n", idade);
}


