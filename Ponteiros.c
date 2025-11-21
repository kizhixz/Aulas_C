/*
ASSUNTO PRINCIPAL DETECTADO: Ponteiros em C
Resumo geral do assunto.
Ponteiros são variáveis que armazenam o endereço de memória de outras variáveis. Eles são fundamentais em C, permitindo a manipulação direta da memória, o que é essencial para tarefas como alocação dinâmica de memória, otimização de passagem de parâmetros (referência) e o entendimento de estruturas de dados como arrays e strings.

Explicação clara e didática.
Um ponteiro não armazena um valor de dado (como um 'int' ou 'char'), mas sim o local (endereço) onde esse valor está armazenado na memória RAM. Existem dois operadores principais: o operador de endereço '&' (referência), que retorna o endereço de uma variável, e o operador de desreferência '*' (indireção), que acessa o valor armazenado no endereço apontado pelo ponteiro. Esse conceito permite que diferentes partes do programa acessem e modifiquem a mesma informação na memória, proporcionando controle de baixo nível e eficiência.

Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
Ponteiros são o recurso mais poderoso e distintivo de C, sendo a base para grande parte da sua flexibilidade e desempenho. Eles estão intrinsecamente ligados a arrays (onde o nome do array é um ponteiro), strings (que são arrays de char) e, mais tarde, à alocação dinâmica de memória. O formato de impressão '%p' em printf() é usado para exibir endereços de memória. O uso correto de ponteiros é crucial para evitar erros de segmentação e vulnerabilidades de segurança, exigindo familiaridade com a organização dos dados na memória.
*/

#include <stdio.h> // Necessário para a função printf()

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Ponteiros)
// ------------------------------------------------------------
// Definição: Um **ponteiro** é o **endereço** de um bloco de memória que contém uma variável.
// Operadores de Ponteiro:
// 1. **Operador de Endereço/Referência (`&`)**:
//    - Usado para obter o **endereço de memória** de uma variável.
//    - Exemplo: `&age` retorna o endereço onde a variável `age` está armazenada.
//    - É impresso com o especificador de formato `%p` em `printf()`.
// 2. **Operador de Desreferência/Indireção (`*`)**:
//    - Usado em **declaração**: Indica que a variável é um ponteiro para um certo tipo.
//      - Exemplo: `int *address;` declara `address` como um ponteiro para um inteiro.
//    - Usado em **expressão**: Significa "o valor da variável para a qual este ponteiro está apontando".
//      - Exemplo: `*address` acessa o valor que está no endereço contido em `address`.
// Aplicações:
// - **Inicialização de Variável**: Um ponteiro pode ser usado para inicializar ou modificar o valor de uma variável.
// - **Arrays**: O nome de um array (`prices`) é um **ponteiro** para o seu primeiro elemento (`*prices`).
// - **Aritmética de Ponteiros**: Adicionar um número inteiro a um ponteiro (ex: `prices + 1`) move o ponteiro para o próximo elemento do array, respeitando o tamanho do tipo de dado.
//
// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// - Variáveis e Tipos de Dados: Menciona a declaração de um inteiro (`int age = 37;`).
// - Funções: Menciona a função `printf()` e o especificador de formato `%u` (para inteiros sem sinal) e `%p` (para ponteiros/endereços).
// - Arrays: Explica a relação direta entre arrays e ponteiros, onde o nome do array age como um ponteiro.
// - Strings: Menciona que a manipulação de strings (arrays de char) pode ser feita de forma eficiente usando aritmética de ponteiros.
// - Linguagens de Alto Nível: Menciona Python e JavaScript como contexto para comparação, onde o gerenciamento de memória é abstrato.
// - Otimização de Recursos: Ponteiros são usados para **passar referências** de objetos ou funções, evitando a cópia completa e economizando recursos.

// Exemplo 1: Obtenção de Endereço e Desreferência Básica
// Demonstra como obter o endereço de uma variável e como acessar seu valor através do ponteiro.
void exemplo_ponteiro_basico() {
  printf("// Exemplo 1: Obtencao de Endereco (Operador &) e Acesso a Valor (Operador *)\n");
  
  int age = 37;
  
  // Imprime o endereço de memória de 'age' (usa %p)
  printf("Endereco de age (&age): %p\n", (void *)&age); 
  
  // Declara 'address' como um ponteiro para um inteiro e armazena o endereço de 'age'
  int *address = &age; 
  
  // Imprime o valor do ponteiro (o endereço)
  printf("Valor armazenado no ponteiro address: %p\n", (void *)address);
  
  // Imprime o valor contido no endereço apontado por 'address' (usa *)
  printf("Valor da variavel apontada (*address): %u\n", *address);
  
  printf("\n");
}
// Explicação do exemplo 1:
// - int *address = &age;: A variável `address` agora contém o endereço de memória de `age`. O `*` indica que ela é um ponteiro.
// - *address: O `*` aqui age como desreferência, obtendo o valor (37) armazenado no endereço.

// Exemplo 2: Modificando o Valor através do Ponteiro
// Demonstra como um ponteiro pode ser usado para alterar o valor da variável original.
void exemplo_modificacao_via_ponteiro() {
  printf("// Exemplo 2: Modificacao do Valor via Ponteiro\n");
  
  int age;
  int *address = &age; // address aponta para age
  
  *address = 37; // Atribui 37 ao valor para o qual address aponta (ou seja, age)
  
  printf("Valor de age apos atribuicao via ponteiro: %u\n", age);
  printf("Valor de *address (o mesmo valor): %u\n", *address);
  
  printf("\n");
}
// Explicação do exemplo 2:
// - *address = 37;: Como o ponteiro está desreferenciado, a atribuição afeta a variável original (`age`).

// Exemplo 3: Arrays e Aritmética de Ponteiros
// Demonstra como o nome do array funciona como um ponteiro e como a aritmética de ponteiros acessa elementos.
void exemplo_array_aritmetica() {
  printf("// Exemplo 3: Arrays e Aritmetica de Ponteiros\n");
  
  int prices[3] = { 5, 4, 3 };
  
  // O nome do array 'prices' é um ponteiro para o primeiro elemento
  printf("Primeiro item usando ponteiro (*prices): %u\n", *prices); // Resultado: 5
  
  // Obtendo o segundo item (índice 1) usando aritmética de ponteiros
  // O compilador sabe que deve pular 1 * (tamanho de um int) bytes.
  printf("Segundo item usando aritmetica (*(prices + 1)): %u\n", *(prices + 1)); // Resultado: 4
  
  // Obtendo o terceiro item (índice 2)
  printf("Terceiro item usando aritmetica (*(prices + 2)): %u\n", *(prices + 2)); // Resultado: 3
  
  printf("\n");
}
// Explicação do exemplo 3:
// - *prices: Desreferencia o ponteiro para o início do array, resultando no primeiro valor.
// - *(prices + 1): Move o ponteiro para a frente por um elemento (`int`) e, em seguida, desreferencia para obter o valor. Isso é equivalente a `prices[1]`.

int main() {
  exemplo_ponteiro_basico();
  exemplo_modificacao_via_ponteiro();
  exemplo_array_aritmetica();
  return 0;
}

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Ponteiros (definição)
// - Endereço de memória
// - Variável
// - Tipos de dados (int)
// - Declaração de variável (int age = 37;)
// - Operador de Endereço/Referência (&)
// - Formato de impressão %p (para endereço)
// - Declaração de ponteiro (int *address;)
// - Operador de Desreferência/Indireção (*)
// - Formato de impressão %u (para inteiro sem sinal)
// - Aritmética de ponteiros (prices + 1)
// - Arrays
// - Nome do array como ponteiro
// - Manipulação de strings
// - Passagem por referência (evitar cópia de objetos/funções)
// - Otimização de recursos/memória