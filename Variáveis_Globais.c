/*
ASSUNTO PRINCIPAL DETECTADO: Variáveis Globais vs. Locais (Diferença de Escopo e Tempo de Vida)
Resumo geral do assunto.
Esta seção detalha a distinção entre variáveis locais e globais em C, focando em sua visibilidade (escopo), acessibilidade (leitura e escrita) e tempo de vida. Variáveis locais existem apenas dentro da função onde são declaradas e têm memória liberada ao seu término. Variáveis globais são declaradas fora de qualquer função e são acessíveis e modificáveis por todas as funções, existindo durante toda a execução do programa.

Explicação clara e didática.
A principal diferença reside na localização da declaração e no gerenciamento de memória. Variáveis globais servem como um mecanismo centralizado para compartilhar dados entre diferentes partes do código. No entanto, o seu tempo de vida estendido (do início ao fim do programa) e a ampla acessibilidade exigem cautela para evitar efeitos colaterais indesejados e bugs complexos, diferentemente das variáveis locais, cujo escopo limitado e tempo de vida curto garantem um isolamento de dados mais seguro.

Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
Em C, o escopo e o tempo de vida estão diretamente ligados à área de memória utilizada. Variáveis locais são tipicamente alocadas na Stack (Pilha) e desalocadas automaticamente. Variáveis globais são alocadas em uma área de dados estáticos (Data Segment ou BSS), e sua memória só é liberada quando o processo do programa termina. O conhecimento dessa diferença é crucial para o design de código modular e para evitar problemas de concorrência ou modificação inesperada de dados compartilhados.
*/

#include <stdio.h> // Necessário para a função printf()

// Variável Global
char i = 0; // Declarada fora de qualquer função

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Variáveis Globais vs. Locais)
// ------------------------------------------------------------
// 1. Variáveis Locais:
// - Definição: Declaradas **dentro** de uma função (ex: `char j = 0;` dentro de `main()`).
// - Escopo/Acessibilidade: Disponíveis **apenas** dentro da função onde foram definidas.
// - Tempo de Vida: A memória é **liberada** assim que a função se encerra.
//
// 2. Variáveis Globais:
// - Definição: Declaradas **fora** de qualquer função (ex: `char i = 0;` no topo do arquivo).
// - Escopo/Acessibilidade: Podem ser **acessadas** e **atualizadas/modificadas** a partir de **qualquer função** do programa.
// - Compartilhamento de Dados: São o mecanismo padrão para **compartilhar os mesmos dados** entre diferentes funções.
// - Tempo de Vida: A memória é **liberada apenas quando o programa se encerra** (tempo de vida total do programa).
//
// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// - Funções: O ponto de definição (dentro ou fora de uma função) é o que estabelece a diferença de escopo. A função `main()` é o exemplo de função local.
// - Memória: Menciona a alocação e liberação de memória em diferentes momentos para cada tipo de variável.
// - Tipos de Dados: Menciona o tipo `char` e `int` (retorno de `main`).
// - Operadores: Uso do operador de atribuição e soma `+=` e operador de incremento e atribuição `++` (implícito no `+= 10`).

// Função para demonstrar o acesso e modificação da variável global
void modificarGlobal() {
  // Acesso e modificação da variável global 'i'
  i += 5;
  printf("Dentro de modificarGlobal: i agora é %u\n", i);
}

// Exemplo da Estrutura
int main(void) {
  // --- Variável Local (j) ---
  char j = 0; // Variável local: existe apenas aqui.
  j += 10;
  printf("// Exemplo de Variavel Local:\n");
  printf("Valor de j (local): %u\n", j); // 10
  
  printf("-----------------------------------\n");
  
  // --- Variável Global (i) ---
  printf("// Exemplo de Variavel Global:\n");
  printf("Valor inicial de i (global): %u\n", i); // 0 (definido no topo)
  
  i += 10; // Acesso e atualização da variável global a partir de main()
  printf("Valor de i apos i += 10 em main(): %u\n", i); // 10
  
  // Chamada de outra função que modifica a variável global
  modificarGlobal();
  
  printf("Valor de i apos modificacao por outra funcao (main): %u\n", i); // 15
  
  // A variável local 'j' não existe mais após o fim de main.
  // A variável global 'i' existirá até o final do programa.
  
  return 0;
}
// Explicação do meu código:
// - `char i = 0;`: Variável global, acessível em `main()` e `modificarGlobal()`.
// - `char j = 0;`: Variável local de `main()`. Não é acessível em `modificarGlobal()`.
// - O código demonstra que a modificação de `i` em `main()` e em `modificarGlobal()` afeta o mesmo valor, provando o compartilhamento de dados.