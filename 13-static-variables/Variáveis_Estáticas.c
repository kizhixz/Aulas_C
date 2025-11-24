/*
ASSUNTO PRINCIPAL DETECTADO: Variáveis Estáticas (static) em C
Resumo geral do assunto.
Variáveis estáticas são uma classe de armazenamento que confere a variáveis locais o tempo de vida de variáveis globais. Elas são inicializadas apenas na primeira vez que a função é chamada e retêm seu valor entre as invocações da função. Isso permite que funções mantenham um estado interno sem recorrer a variáveis globais.

Explicação clara e didática.
A palavra-chave 'static' altera o comportamento de uma variável local em termos de tempo de vida e inicialização. Enquanto variáveis locais normais são destruídas (e reinicializadas) a cada chamada da função, uma variável 'static' é criada uma única vez no início do programa (ou na primeira chamada da função) e reside na memória pelo tempo de vida do programa, mantendo seu valor. Variáveis estáticas, incluindo arrays, são inicializadas automaticamente com zero se nenhuma inicialização explícita for fornecida.

Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
Em C, variáveis estáticas não são alocadas na Stack (pilha), mas sim em uma área de dados da memória, semelhante às variáveis globais. Isso explica seu tempo de vida estendido. A palavra-chave 'static' em variáveis globais ou em funções globais tem um significado diferente (limitar a visibilidade ao arquivo), mas, dentro de uma função, seu papel é garantir a persistência de estado. Isso é um poderoso mecanismo de controle de estado e memória.
*/

#include <stdio.h> // Necessário para a função printf()

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Variáveis Estáticas)
// ------------------------------------------------------------
// Palavra-chave: `static`.
// Aplicação em Funções: Usada para variáveis declaradas **dentro** de uma função.
// Comportamento:
// - **Tempo de Vida Prolongado**: A variável estática é inicializada uma única vez e seu valor é **retido** em todas as chamadas subsequentes da função.
// - **Inicialização Automática**: Se nenhum valor inicial for especificado (`static int idade;`), a variável é automaticamente inicializada com **zero** (ou nulo, para ponteiros/arrays).
//
// Diferença em Relação a Variáveis Locais Normais:
// - Variáveis locais normais são recriadas e reinicializadas a cada chamada da função, perdendo o valor anterior.
// - Variáveis estáticas mantêm o estado ("memória") entre as chamadas.
//
// Variáveis Globais:
// - Variáveis globais são **estáticas por padrão** em seu tempo de vida (existem durante toda a execução), por isso a palavra-chave `static` não é necessária para elas nesse sentido (embora tenha outro significado em escopo de arquivo).
//
// Arrays Estáticos:
// - Podem ser declarados dentro de uma função. Cada item do array estático é inicializado com 0 por padrão.

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// - Funções: O conceito principal é manter o estado entre as chamadas de função.
// - Variáveis Locais: Usadas como contraste para explicar a diferença de tempo de vida.
// - Variáveis Globais: Mencionadas por terem o tempo de vida estático por natureza.
// - Arrays: Podem ser declarados como estáticos dentro de funções, com inicialização padrão em zero.
// - Tipos de Dados: Menciona o tipo `int`.

// Exemplo 1: Função com Variável Local Normal (Sem static)
int aumentarIdade_Normal() {
  int idade = 0; // Reinicializada em 0 em cada chamada
  idade++;
  return idade;
}
// Explicação do Exemplo 1:
// - O valor de `idade` é sempre 1 após a execução, pois ele é redefinido para 0 no início de cada chamada e destruído no fim.

// Exemplo 2: Função com Variável Estática
int aumentarIdade_Static() {
  // Inicializada apenas na PRIMEIRA chamada. Retém o valor nas chamadas subsequentes.
  static int idade = 0;
  idade++;
  return idade;
}
// Explicação do Exemplo 2 (Linha por linha):
// - `static int idade = 0;`: Declarada como estática. Na primeira execução, `idade` é 0.
// - `idade++;`: Incrementa o valor.
// - `return idade;`: Retorna o novo valor. Na próxima chamada, a linha de inicialização (`= 0;`) é ignorada, e o valor retido é incrementado.

// Exemplo 3: Array Estático (Inicialização Automática com 0)
int aumentarIdade_Array_Static() {
  // Array estático. idades[0] é 0 na primeira chamada e retém o valor depois.
  static int idades[3];
  idades[0]++;
  return idades[0];
}

int main(void) {
  printf("// Teste de Variavel Local Normal:\n");
  printf("Chamada 1 (Normal): %d\n", aumentarIdade_Normal()); // Resultado: 1
  printf("Chamada 2 (Normal): %d\n", aumentarIdade_Normal()); // Resultado: 1
  printf("-------------------------------------------\n");
  
  printf("// Teste de Variavel Estatica (static):\n");
  printf("Chamada 1 (Static): %d\n", aumentarIdade_Static()); // Resultado: 1
  printf("Chamada 2 (Static): %d\n", aumentarIdade_Static()); // Resultado: 2
  printf("Chamada 3 (Static): %d\n", aumentarIdade_Static()); // Resultado: 3
  printf("-------------------------------------------\n");
  
  printf("// Teste de Array Estatico:\n");
  printf("Chamada 1 (Array Static): %d\n", aumentarIdade_Array_Static()); // Resultado: 1
  printf("Chamada 2 (Array Static): %d\n", aumentarIdade_Array_Static()); // Resultado: 2
  
  return 0;
}

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Variáveis estáticas
// - Palavra-chave static
// - Variáveis globais (estáticas por padrão em tempo de vida)
// - Variáveis locais (como contraste)
// - Tempo de vida estendido/retenção de valor
// - Reinicialização de variáveis locais
// - Inicialização automática com 0
// - Omissão de inicialização
// - Funções (aumentarIdade())
// - Array estático
// - Item de array