/*
ASSUNTO PRINCIPAL DETECTADO: Entrada e Saída (I/O) Padrão em C
Resumo geral do assunto.
A funcionalidade de Entrada/Saída (I/O) não faz parte do núcleo da Linguagem C, mas é fornecida pela **Biblioteca Padrão C** (`standard library`) através de um conjunto de funções de manipulação de fluxos (streams) definidas no arquivo de cabeçalho **<stdio.h>**. Essas funções permitem que o programa interaja com o mundo exterior (usuário, arquivos, dispositivos).

Explicação clara e didática.
A comunicação em C é baseada em três **streams** de I/O padrão: `stdin` (entrada, geralmente o teclado), `stdout` (saída, geralmente a tela) e `stderr` (saída de erros, geralmente a tela). Funções como `printf()` são especializadas em escrever no `stdout`, enquanto `scanf()` é usada para ler do `stdin`. Ambas utilizam **especificadores de formato** (placeholders como %d, %s) para determinar o tipo de dado a ser manipulado e, no caso de `scanf()`, requerem o **endereço** de memória da variável (usando o operador `&`) para armazenar o valor lido.

Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
O uso da biblioteca `<stdio.h>` através de `#include` é obrigatório para I/O básico. O conceito de **stream** de I/O permite que o C trate diferentes fontes de dados (teclado, arquivo) de maneira uniforme. A função `scanf()` reforça a importância dos **ponteiros** em C, pois ela precisa do endereço de memória da variável (`&idade`) para poder modificar seu valor, implementando efetivamente uma "passagem por referência" para o dado de entrada. A única exceção é o nome de um array (string), que já é um ponteiro.
*/

#include <stdio.h> // Importa a biblioteca padrão de I/O

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Entrada e Saída)
// ------------------------------------------------------------
// Biblioteca Padrão C: O I/O é fornecido pela `standard library` C, não pelo núcleo da linguagem.
// Arquivo de Cabeçalho: As funções de I/O são definidas em `<stdio.h>`, que deve ser incluído via `#include <stdio.h>`.
// Streams de I/O: São interfaces de alto nível que unificam o tratamento de dispositivos/arquivos.
// Três Streams Padrão:
// - **`stdin`** (Standard Input / Entrada Padrão): Usado para leitura (ex: teclado).
// - **`stdout`** (Standard Output / Saída Padrão): Usado para escrita normal (ex: tela).
// - **`stderr`** (Standard Error / Erro Padrão): Usado para escrita de mensagens de erro (ex: tela).
//
// Funções de I/O Mencionadas: `printf()`, `scanf()`, `sscanf()`, `fgets()`, `fprintf()`.
//
// 1. Função `printf()` (Saída):
// - Imprime dados no **`stdout`**.
// - Forma mais simples: recebe uma string literal (ex: `printf("Olá!")`).
// - Impressão de Variáveis: Usa **especificadores de formato (placeholders)**, que mudam conforme o tipo da variável.
// - Múltiplas Variáveis: São passadas separadas por vírgulas.
//
// 2. Função `scanf()` (Entrada):
// - Obtém dados de entrada, geralmente do **`stdin`** (linha de comando).
// - Requer 2 argumentos principais: o formato (tipo) e o **endereço** da variável.
// - **Ponteiros**: O endereço da variável é obtido usando o **operador de endereço `&`** (ex: `&idade`).
// - Exceção: Para strings (arrays de char), o nome do array (`nome`) já é um ponteiro para o primeiro caractere, dispensando o uso do `&`.
//
// 3. Funções Relacionadas:
// - `fprintf()`: Equivalente mais geral do `printf()`, permite especificar em qual **stream** (não apenas `stdout`) se deseja escrever.
//
// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// - Bibliotecas: `standard library` C.
// - Diretiva `#include`: Usada para importar arquivos de cabeçalho.
// - Arquivo de Cabeçalho: `stdio.h`.
// - Ponteiros: Essenciais para `scanf()` (uso de `&`) e para strings (nome do array já é um ponteiro).
// - Arrays/Strings: Strings são arrays de `char` (mencionada a exceção na `scanf`).
// - Caracteres de Escape: Menciona `\n` para adicionar uma nova linha na saída.
// - Tipos de Dados e Especificadores de Formato:
//     - `%d`: algarismo inteiro decimal com sinal
//     - `%c`: caractere
//     - `%s`: string (array de caractere)
//     - `%f`: números de ponto flutuante
//     - `%p`: ponteiros

// Exemplo 1: Uso básico de printf(), scanf() e especificadores de formato
// O programa solicita um nome do usuário e o imprime.
#include <stdio.h> // Duplicado propositalmente para exemplificar, já que a estrutura requer incluir a biblioteca aqui

int main(void) {
  // Declara uma variável inteira para o exemplo de %d
  int idade = 37; 
  
  // Declara uma string (array de 20 caracteres) para a entrada do usuário
  char nome[20];
  
  // Exemplo de printf() com múltiplas variáveis e especificadores
  int idade_ontem = 36;
  int idade_hoje = 37;
  printf("Ontem, eu tinha %d anos e hoje eu tenho %d. (Demonstracao de %%d)\n", idade_ontem, idade_hoje);
  
  // Exemplo de printf() com caractere de escape
  printf("Exemplo de nova linha usando \\n.\n");
  
  // Exemplo de scanf() - Entrada de String
  printf("Digite seu nome: ");
  // scanf usa %s e o nome do array 'nome' (que é um ponteiro), dispensando o &
  scanf("%s", nome); 
  
  // Exemplo de printf() imprimindo o valor obtido pela scanf()
  printf("Foi digitado o nome %s. (Demonstracao de %%s)\n", nome);
  
  // Exemplo de scanf() - Entrada de Inteiro
  int valor_int;
  printf("Digite um numero inteiro: ");
  // scanf usa %d e o endereço da variavel (&valor_int)
  scanf("%d", &valor_int); 
  printf("O numero digitado (%d) foi armazenado corretamente.\n", valor_int);
  
  return 0;
}
// Explicação do meu código:
// - `#include <stdio.h>`: Importa as funções de I/O.
// - `int main(void) { ... }`: A função principal do programa.
// - `char nome[20];`: Declaração de um array de 20 chars para armazenar o nome.
// - `printf("Digite seu nome: ");`: Usa `printf` (escrita no `stdout`) para solicitar a entrada.
// - `scanf("%s", nome);`: Usa `scanf` (leitura do `stdin`) para obter uma string. `%s` indica que o dado é uma string, e `nome` é o ponteiro para onde o dado será armazenado.
// - `scanf("%d", &valor_int);`: Obtém um inteiro. `%d` indica o tipo, e `&valor_int` fornece o endereço de memória para o armazenamento.
// - `return 0;`: Finaliza o programa.

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Entrada/Saída (I/O)
// - Núcleo da linguagem C (sem I/O nativo)
// - Biblioteca Padrão C (standard library)
// - Arquivo de cabeçalho stdio.h
// - Diretiva #include
// - Funções de I/O: printf(), scanf(), sscanf(), fgets(), fprintf()
// - Streams de I/O
// - stdin (standard input / Entrada Padrão)
// - stdout (standard output / Saída Padrão)
// - stderr (standard error / Erro Padrão)
// - Streams (interface de alto nível)
// - Strings literal
// - Variáveis
// - Especificadores de formato (Placeholders)
// - %d (inteiro decimal com sinal)
// - %c (caractere)
// - %s (string/array de char)
// - %f (ponto flutuante)
// - %p (ponteiros)
// - Operador de endereço &
// - Endereço de memória
// - Caracteres de escape (\n)
// - Arrays de char (strings)
// - Nome do array como ponteiro