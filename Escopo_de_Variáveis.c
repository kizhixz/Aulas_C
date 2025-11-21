/*
ASSUNTO PRINCIPAL DETECTADO: Escopo de Variáveis (Global vs. Local) em C
Resumo geral do assunto.
O escopo de uma variável em C determina a sua visibilidade e o seu tempo de vida dentro de um programa. Existem dois tipos principais de escopo baseados no local da declaração: variáveis locais (declaradas dentro de funções) e variáveis globais (declaradas fora de qualquer função).

Explicação clara e didática.
Variáveis locais existem apenas dentro do bloco ou função onde foram declaradas; elas são tipicamente armazenadas na 'stack' (pilha) e são destruídas quando a execução da função termina. Variáveis globais, por outro lado, são declaradas fora de todas as funções e podem ser acessadas e modificadas por qualquer função do programa, existindo durante toda a execução do programa. O local de declaração, portanto, afeta diretamente a acessibilidade e o gerenciamento de memória da variável.

Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
Em C, o escopo está intimamente ligado ao gerenciamento de memória. Variáveis locais na 'stack' são alocadas e desalocadas automaticamente pelo sistema. A menção de exceções e a 'heap' (montanha) introduz o conceito de alocação dinâmica, onde o programador deve usar ponteiros para gerenciar a memória explicitamente. O uso de variáveis globais deve ser feito com cautela, pois pode dificultar a modularidade e rastreabilidade do código.
*/

#include <stdio.h> // Biblioteca necessária para usar printf()

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Escopo de Variáveis: Global vs. Local)
// ------------------------------------------------------------
// Escopo de Variáveis: Define a **visibilidade** e o **tempo de vida** de uma variável.
//
// 1. Variáveis Locais:
// - Declaração: Dentro de uma **função** ou bloco de código (ex: dentro de `main()`).
// - Acessibilidade: Estão disponíveis **apenas** dentro da função/bloco em que foram declaradas.
// - Tempo de Vida: Deixam de existir (são destruídas) quando a função se encerra.
// - Memória: Por padrão, são declaradas na **stack (pilha)**.
// - Exceção: Podem ser alocadas na **heap (montanha)** se forem usados ponteiros para alocação dinâmica, exigindo gerenciamento manual da memória.
//
// 2. Variáveis Globais:
// - Declaração: **Fora** de qualquer função.
// - Acessibilidade: Estão disponíveis para **qualquer função** do programa.
// - Tempo de Vida: Existem durante **toda a execução** do programa, do início ao fim.
//
// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// - Funções: O local de declaração (dentro ou fora de uma função) é o que define o escopo. A função `main()` é mencionada como exemplo.
// - Gerenciamento de Memória: Menciona os dois principais tipos de alocação:
//   - **Stack (Pilha)**: Usada para variáveis locais (alocação e desalocação automáticas).
//   - **Heap (Montanha)**: Usada para alocação dinâmica de memória (alocação e desalocação manuais via ponteiros).
// - Ponteiros: Mencionados como o mecanismo para alocar variáveis explicitamente na heap.
// - Tipos de Dados: Menciona `int` (inteiro) e `void` (retorno de função).

// Variável Global
int idade_global = 40; // Declarada fora de qualquer função.

// Função que demonstra o acesso e escopo local
void demonstrarEscopo(int valor_parametro) {
  // Variável local
  int valor_local = 10;
  
  printf("// Dentro da funcao demonstrarEscopo:\n");
  printf(" - Variavel Local (valor_local): %d\n", valor_local);
  // Acessa a variável global (idade_global)
  printf(" - Variavel Global (idade_global): %d\n", idade_global);
  
  // O parametro 'valor_parametro' também é tratado como uma variável local
  // Ele é destruído ao fim da função.
}
// Explicação do exemplo:
// - `idade_global` é visível e acessível aqui.
// - `valor_local` só existe durante a execução de `demonstrarEscopo()`.

// Exemplo da Estrutura
int main(void) {
  printf("// Exemplo de Escopo de Variaveis:\n");
  
  // Variável local da função main()
  int idade_local_main = 37; 
  
  printf("// Dentro da funcao main():\n");
  printf(" - Variavel Local de main (idade_local_main): %d\n", idade_local_main);
  printf(" - Variavel Global (idade_global): %d\n", idade_global);
  
  printf("-------------------------------------------\n");
  demonstrarEscopo(5);
  printf("-------------------------------------------\n");
  
  // Tentativa de acessar uma variável que não existe aqui
  // printf("Acesso fora do escopo: %d\n", valor_local); // ISSO CAUSARIA UM ERRO DE COMPILACAO
  
  return 0;
}
// Explicação do meu código:
// - `int idade_global = 40;`: Variável global, acessível em `main()` e `demonstrarEscopo()`.
// - `int idade_local_main = 37;`: Variável local de `main()`. Não é acessível em `demonstrarEscopo()`.
// - `int valor_local = 10;`: Variável local de `demonstrarEscopo()`.
// - As funções usam `printf()` para demonstrar a visibilidade de ambas as variáveis. A variável local `idade_local_main` só existe no escopo de `main()`.

// Observação de Memória:
/*
A variável 'idade_local_main' é alocada na stack quando main() começa e desalocada quando main() termina.
A variável 'idade_global' é alocada em uma seção de dados e permanece na memória durante toda a execução.
*/