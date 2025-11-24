/*
ASSUNTO PRINCIPAL DETECTADO: Parâmetros da Linha de Comando em C
Resumo geral do assunto: A função 'main()' em C pode ser configurada para receber argumentos passados ao programa durante sua execução na linha de comando. Isso é feito alterando a assinatura da função para incluir dois parâmetros padrão: 'argc' (argument count) e 'argv' (argument vector).

Explicação clara e didática: 'argc' é um inteiro que conta quantos argumentos foram fornecidos. 'argv' é um array de strings (ponteiros para caracteres) que armazena os argumentos propriamente ditos. O primeiro argumento (argv[0]) é sempre o nome do próprio programa (ou seu caminho de execução).

Contexto sobre o que esse tema significa na Linguagem C: Receber argumentos de linha de comando é fundamental para criar ferramentas e utilitários que interagem com o sistema operacional. Essa é a maneira padrão de C para lidar com a entrada de dados não interativa, permitindo que o comportamento do programa seja dinamicamente configurado no momento da execução (por exemplo, passar nomes de arquivos, flags de opções, etc.). Para manipulação de opções complexas, a biblioteca 'getopt' é frequentemente usada.
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Parâmetros argc e argv)
// ------------------------------------------------------------

// Para aceitar parâmetros de linha de comando, a assinatura da função 'main()' deve ser alterada de:
// 'int main(void)'
// para:
// 'int main (int argc, char *argv[])'
// ']

// 1. argc (Argument Count):
// É uma variável inteira que armazena o NÚMERO TOTAL de argumentos passados.
// O valor de 'argc' é sempre **pelo menos 1**, pois o nome do próprio programa conta como o primeiro argumento.

// 2. argv (Argument Vector):
// É um array de strings. Em C, uma string é representada por um ponteiro para char ('char *').
// Assim, 'char *argv[]' é um array de ponteiros para caracteres (strings).
// - 'argv[0]' sempre contém o nome (ou caminho) do programa executado.
// - 'argv[1]' é o primeiro argumento passado pelo usuário, 'argv[2]' o segundo, e assim por diante,
// até 'argv[argc - 1]'.

// Exemplo da Linha de Comando: 'gcc hello.c -o hello'
// Se esta linha fosse a execução de um programa, teríamos:
// - argc: 4
// - argv[0]: "gcc"
// - argv[1]: "hello.c"
// - argv[2]: "-o"
// - argv[3]: "hello"

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------

// Função main(): O ponto de entrada obrigatório de qualquer programa C. O valor de retorno 'int'
// é geralmente usado para sinalizar o status de saída (0 para sucesso, diferente de 0 para erro).

// Tipo 'int': O tipo de dado inteiro usado para armazenar a contagem de argumentos ('argc') e o
// índice do loop.

// Array de Strings ('char *argv[]'): O conceito de um array de strings, onde cada elemento
// é um ponteiro para o primeiro caractere de uma string.

// Estrutura de Repetição ('for' loop): Usada no código de exemplo para iterar sobre o array 'argv',
// começando do índice 0 e continuando até 'argc - 1'. Sintaxe: 'for (int i = 0; i < argc; i++)'.

// Função 'printf()': Usada com o especificador de formato '%s' para imprimir strings (os argumentos)
// e '\n' para nova linha.

// Bibliotecas ('#include <stdio.h>'): A diretiva que inclui a biblioteca de entrada/saída padrão,
// essencial para usar a função 'printf()'.

// Pacote 'getopt': Mencionado como uma ferramenta mais avançada (biblioteca padrão do Unix)
// para tratar e analisar argumentos de linha de comando mais complexos (como flags e opções).

#include <stdio.h>

/*
A função main recebe dois parâmetros:
argc: O número de argumentos.
argv: O array de strings que contém os argumentos.
*/
int main (int argc, char *argv[]) {
  printf("----------------------------------------\n");
  printf("Numero total de argumentos (argc): %d\n", argc);
  printf("----------------------------------------\n");

  // O loop percorre o array de strings 'argv' do índice 0 (nome do programa)
  // até o último argumento (índice argc - 1).
  for (int i = 0; i < argc; i++) {
    // Imprime o argumento atual (que é uma string) seguido de uma nova linha.
    printf("Argumento %d: %s\n", i, argv[i]);
  }

  printf("----------------------------------------\n");

  // Simulação de execução:
  // Se executado como: ./meuprograma
  // Saída:
  // Argumento 0: ./meuprograma (argc = 1)

  // Se executado como: ./meuprograma a b c
  // Saída:
  // Argumento 0: ./meuprograma
  // Argumento 1: a
  // Argumento 2: b
  // Argumento 3: c (argc = 4)


  return 0; // Retorna 0 para indicar execução bem-sucedida
}

// Explicação do meu código (dentro de main)
// 'int main (int argc, char *argv[])': A nova assinatura da função main para aceitar argumentos.
// 'for (int i = 0; i < argc; i++)': Inicia um loop que itera através de todos os argumentos.
// 'printf("Argumento %d: %s\n", i, argv[i]);': Imprime o índice (i) e a string (argv[i]) do argumento atual.
// 'argv[i]': Acessa o i-ésimo argumento, que é uma string.
// 'argc': A condição de parada do loop, garantindo que todos os 'argc' argumentos sejam processados.

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Função 'main()'
// - Argumentos de linha de comando
// - Parâmetro 'argc' (argument count, tipo 'int')
// - Parâmetro 'argv' (argument vector, tipo 'char *argv[]')
// - Assinatura da 'main()'
// - O primeiro argumento 'argv[0]' (nome do programa)
// - Array de strings ('char *[]')
// - Estrutura de repetição 'for' loop
// - Função 'printf()'
// - Biblioteca '#include <stdio.h>'
// - Pacote 'getopt' (para argumentos complexos)