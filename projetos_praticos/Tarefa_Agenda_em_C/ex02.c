/*

Variáveis, tipos básicos e entrada/saída (printf/scanf)

Você vai precisar para:

receber dados do usuário (nome, telefone, email)

exibir o menu e listar contatos

*/

#include <stdio.h>

int main(void){

    char telefone[50];
    char nome[100];
    char email[100];

    printf("Telefone: ");
    scanf("%49s", telefone);   // lê string até espaço

    printf("Nome: ");
    scanf("%99s", nome);

    printf("Email: ");
    scanf("%99s", email);

    printf("\n--- Dados recebidos ---\n");
    printf("Telefone: %s\n", telefone);
    printf("Nome: %s\n", nome);
    printf("Email: %s\n", email);

    return 0;
};
