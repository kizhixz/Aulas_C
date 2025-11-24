/*
ASSUNTO PRINCIPAL DETECTADO: Strings em C (Arrays de char)
Resumo geral do assunto.
Em C, strings não são um tipo de dado nativo, mas sim uma convenção: são arrays de caracteres ('char') que devem ser terminados pelo caractere nulo (null terminator), representado pelo valor 0 (zero) ou '\0'. Essa terminação é fundamental para que funções da biblioteca padrão, como 'printf()' ou 'string.h', saibam onde a string termina.

Explicação clara e didática.
Uma string é essencialmente uma sequência contígua de bytes (caracteres ASCII) na memória, onde o último byte é o terminador nulo. Isso impõe uma regra crucial: o array de 'char' deve ter sempre um tamanho maior do que a sequência de caracteres visíveis para acomodar esse byte final. A biblioteca padrão <string.h> fornece um conjunto de funções essenciais para manipular strings (copiar, concatenar, comparar, calcular tamanho), abstraindo a necessidade de manipular diretamente os ponteiros e índices de baixo nível.

Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
O conceito de string como array de 'char' nulo-terminado é o cerne da manipulação de texto em C e se baseia fortemente no conhecimento de arrays e ponteiros (já que o nome do array de char é um ponteiro para o primeiro char). A biblioteca <string.h> é uma das mais importantes no desenvolvimento em C, pois é o padrão para o trabalho com cadeias de caracteres. A compilação lida com strings literais (entre aspas duplas) automaticamente, garantindo que o terminador nulo seja adicionado.
*/

#include <stdio.h>  // Necessário para printf()
#include <string.h> // Essencial para as funções de manipulação de strings

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Strings como Arrays de char)
// ------------------------------------------------------------
// Definição: Uma string em C é um **array de valores do tipo char**.
// Tipo char: Usado para armazenar letras da tabela **ASCII**.
// Inicialização de String:
// - Similar a um array normal: char name[7] = { 'F', 'l', 'a', 'v', 'i', 'o' };
// - Mais comum: usando uma **string literal** (sequência entre aspas duplas): char name[7] = "Flavio";
// Caractere Nulo (Terminador de String):
// - Strings C **devem** ser terminadas por um valor 0, o **finalizador da string** (também escrito como '\0').
// - O array precisa de um espaço extra para este terminador. Exemplo: "Flavio" (6 caracteres) exige um array de tamanho 7.
// Impressão: A função `printf()` usa o especificador de formato `%s` para imprimir strings.
//
// Biblioteca <string.h>:
// - É a biblioteca padrão que fornece funções de alto nível para manipular strings.
// - Abstrai os detalhes de baixo nível (manipulação direta de índices e ponteiros).
// Funções essenciais:
// - `strcpy()`: Copia uma string para outra.
// - `strcat()`: Anexa uma string ao final de outra (concatena).
// - `strcmp()`: Compara duas strings (retorna 0 se forem iguais).
// - `strncmp()`: Compara os primeiros *n* caracteres de duas strings.
// - `strlen()`: Calcula o **tamanho** de uma string (excluindo o terminador nulo).
//
// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// - Arrays: Strings são um tipo especial de array (de char). O conceito de tamanho fixo e acesso por índice se aplica.
// - Tipos de Dados: Menciona o tipo `char` e a necessidade de que todos os elementos do array sejam do mesmo tipo.
// - Ponteiros: Implicitamente relacionado, pois strings são manipuladas internamente usando ponteiros de 'char'.
// - Bibliotecas: Uso da diretiva `#include` para carregar bibliotecas (`string.h`, `stdio.h`).
// - Funções: Menciona a função `printf()` e seu especificador de formato `%s`.

// Exemplo 1: Definição, Inicialização e Impressão de Strings
// Demonstra a sintaxe de inicialização com string literal e o uso de printf.
void exemplo_string_basica() {
  printf("// Exemplo 1: Inicializacao e Impressao de String\n");
  
  // O tamanho 7 é necessário para "Flavio" (6 chars) + '\0' (1 char)
  char name[7] = "Flavio"; 
  
  // Impressão usando %s. A função printf lê até encontrar o '\0'.
  printf("O nome e: %s\n", name);
  printf("\n");
}
// Explicação do exemplo 1:
// - char name[7] = "Flavio";: Declara um array de 7 caracteres e inicializa com a string literal "Flavio". O compilador adiciona o '\0' automaticamente.
// - printf("...%s...", name);: Utiliza o especificador `%s` para imprimir a string armazenada no array `name`.

// Exemplo 2: Usando a biblioteca string.h (strcpy e strlen)
// Demonstra o uso de duas funções úteis da biblioteca string.h.
void exemplo_string_h() {
  printf("// Exemplo 2: Funcoes da biblioteca string.h (strcpy e strlen)\n");
  
  char source[] = "C Lindo";   // O compilador calcula o tamanho (7 chars + '\0' = 8)
  char destination[20]; // Array de destino com espaco suficiente (tamanho 20)
  
  // 1. Copia a string de source para destination
  strcpy(destination, source);
  printf("String copiada (destination): %s\n", destination); 
  
  // 2. Calcula o tamanho da string (exclui o '\0')
  size_t length = strlen(destination); // size_t é o tipo retornado por strlen
  printf("Tamanho da string (strlen): %zu caracteres\n", length); 
  // O resultado deve ser 7 (contagem de 'C Lindo'), nao 8 (tamanho do array).
  printf("\n");
}
// Explicação do exemplo 2:
// - char source[] = "C Lindo";: O tamanho do array é inferido pelo compilador.
// - strcpy(destination, source);: Copia a sequência de caracteres de `source` para `destination`, incluindo o terminador nulo.
// - strlen(destination);: Retorna o número de caracteres ANTES do terminador nulo, ou seja, o comprimento visível da string.

int main() {
  exemplo_string_basica();
  exemplo_string_h();
  
  // Nota: Para usar outras funcoes como strcat ou strcmp em um programa completo,
  // elas seriam chamadas de forma similar a strcpy e strlen.

  return 0;
}

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Strings (conceito)
// - Array de char
// - Tipo de dado char
// - Tabela ASCII
// - Inicialização de string
// - String literal / String constante
// - Aspas duplas ("")
// - Função printf()
// - Especificador de formato %s
// - Caractere finalizador da string (valor 0 / '\0')
// - Tamanho de array para strings (N + 1)
// - Manipulação de strings
// - Biblioteca string.h
// - Diretiva #include
// - Função strcpy()
// - Função strcat()
// - Função strcmp()
// - Função strncmp()
// - Função strlen()