/*
ASSUNTO PRINCIPAL DETECTADO: Operadores em C
Resumo geral do assunto.
Este documento lista e detalha os principais grupos de operadores em C: aritméticos (binários e unários), de comparação, lógicos, de atribuição composta, o operador ternário e o operador 'sizeof'. 
Explicação clara e didática.
Os operadores são símbolos que instruem o compilador a realizar manipulações específicas nas variáveis e valores. O texto foca na sintaxe, funcionalidade e, crucialmente, na precedência e associatividade dos operadores, elementos essenciais para garantir que as expressões complexas sejam avaliadas corretamente em C. É dada atenção especial à diferença entre os operadores de incremento e decremento prefixados (ex: ++a) e posfixados (ex: a++).
Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
A compreensão dos operadores é a base para a escrita de qualquer lógica de programação em C, especialmente na manipulação de dados e controle de fluxo. A precedência e a associatividade são regras que governam a ordem de avaliação em tempo de compilação, e o uso de parênteses é recomendado para sobrescrever essas regras e aumentar a legibilidade. O operador 'sizeof' é de particular importância para o gerenciamento de memória de baixo nível em C, permitindo descobrir o tamanho em bytes de tipos e variáveis.
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL
// ------------------------------------------------------------
// OPERADORES:
// Símbolos usados para realizar operações com os dados (operandos).
//
// CLASSIFICAÇÃO DOS OPERADORES MENCIONADOS:
// - Aritméticos
// - De Comparação
// - Lógicos
// - De Atribuição Compostos
// - Ternário
// - Diversos (`sizeof`)
// (Os operadores bitwise, de ponteiro e de estrutura foram excluídos para simplificação).
//
// OPERADORES ARITMÉTICOS BINÁRIOS (2 operandos: a e b):
// | OPERADOR | NOME | EXEMPLO |
// | :---: | :---: | :---: |
// | `=` | Atribuição | `a = b` |
// | `+` | Adição | `a + b` |
// | `-` | Subtração | `a - b` |
// | `*` | Multiplicação | `a * b` |
// | `/` | Divisão | `a / b` |
// | `%` | Módulo (Resto da Divisão) | `a % b` |
//
// OPERADORES ARITMÉTICOS UNÁRIOS (1 operando: a):
// | OPERADOR | NOME | EXEMPLO |
// | :---: | :---: | :---: |
// | `+` | Unário de soma | `+a` |
// | `-` | Unário de subtração | `-a` |
// | `++` | Incremento | `a++` ou `++a` |
// | `--` | Decremento | `a--` ou `a` |
//
// Incremento/Decremento Pré-fixado vs. Pós-fixado:
// - **Pós-fixado (`a++`, `a--`):** O valor da variável é usado na expressão **antes** de ser incrementado/decrementado.
// - **Pré-fixado (`++a`, `--a`):** O valor da variável é incrementado/decrementado **antes** de ser usado na expressão.
//
// OPERADORES DE COMPARAÇÃO (Retornam valor Booleano/Inteiro):
// | OPERADOR | NOME | EXEMPLO |
// | :---: | :---: | :---: |
// | `==` | Igual | `a == b` |
// | `!=` | Diferente | `a != b` |
// | `>` | Maior que | `a > b` |
// | `<` | Menor que | `a < b` |
// | `>=` | Maior ou igual | `a >= b` |
// | `<=` | Menor ou igual | `a <= b` |
//
// OPERADORES LÓGICOS (Usados com valores booleanos/inteiros):
// - `!` : NOT (Negação Lógica - Unário)
// - `&&` : AND (E Lógico - Binário)
// - `||` : OR (Ou Lógico - Binário)
//
// OPERADORES DE ATRIBUIÇÃO COMPOSTOS:
// São atalhos para realizar uma operação e atribuição na mesma instrução (ex: `a = a + b` é o mesmo que `a += b`).
// | OPERADOR | NOME | EXEMPLO | EQUIVALE A |
// | :---: | :---: | :---: | :---: |
// | `+=` | Atribuição e adição | `a += b` | `a = a + b` |
// | `-=` | Atribuição e subtração | `a -= b` | `a = a - b` |
// | `*=` | Atribuição e multiplicação | `a *= b` | `a = a * b` |
// | `/=` | Atribuição e divisão | `a /= b` | `a = a / b` |
// | `%=` | Atribuição e módulo | `a %= b` | `a = a % b` |
//
// OPERADOR TERNÁRIO:
// - O único operador em C que usa **3 operandos**.
// - Forma abreviada do condicional `if/else`.
// - Sintaxe: `<condição> ? <expressão_se_true> : <expressão_se_false>`
// - Exemplo: `a ? b : c` (Se `a` é avaliado como verdadeiro/não-zero, retorna `b`; caso contrário, retorna `c`).
//
// OPERADORES DIVERSOS (`sizeof`):
// - **`sizeof`**: Retorna o **tamanho em bytes** do seu operando (variável ou tipo).

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// PRECEDÊNCIA DOS OPERADORES:
// Regras que determinam a ordem de avaliação em expressões com múltiplos operadores.
// Ordem (da menor precedência para a maior, dentro dos grupos):
// 1. Operador de atribuição (`=`)
// 2. Operadores binários de adição/subtração (`+`, `-`)
// 3. Operadores de multiplicação/divisão (`*`, `/`)
// 4. Operadores unários (`+`, `-`, `++`, `--`)
//
// ASSOCIATIVIDADE:
// Regra para desempate entre operadores de mesma precedência.
// - Padrão: **Da esquerda para a direita** (ex: `*`, `/`, `+`, `-`).
// - Exceção: **Da direita para a esquerda** (Operadores unários e de atribuição, ex: `=`, `++`, `!`).
//
// PARÊNTESES (`()`):
// - Têm a **maior prioridade** sobre todos os operadores.
// - Devem ser usados para aumentar a legibilidade ou para forçar uma ordem de avaliação diferente da padrão.
//
// VARIÁVEIS IMAGINÁRIAS:
// As variáveis `a` e `b` são usadas apenas para exemplificar a sintaxe dos operadores.

// ------------------------------------------------------------
// EXEMPLOS
// ------------------------------------------------------------

// Exemplo 1: Diferença entre Incremento Pré e Pós-fixado
#include <stdio.h>

int main(void) {
    int a = 2;
    int b;
    
    // a++ (Pós-fixado): Atribui o valor de 'a' (2) a 'b' e DEPOIS incrementa 'a' para 3.
    b = a++; 
    printf("Pos-fixado: b = %d, a = %d\n", b, a); // Output: b = 2, a = 3
    
    // ++a (Pré-fixado): Incrementa 'a' para 4 e DEPOIS atribui o novo valor (4) a 'b'.
    b = ++a; 
    printf("Pre-fixado: b = %d, a = %d\n", b, a); // Output: b = 4, a = 4
    
    return 0;
}
// Explicação do exemplo: 
// Demonstra como a posição do operador de incremento (`++`) afeta o momento em que a variável é atualizada em uma expressão de atribuição.

// Exemplo 2: Operador Ternário
#include <stdio.h>

int main(void) {
    int x = 10;
    int y = 5;
    int max_val;
    
    // Se (x > y) for verdadeiro, atribui x a max_val; caso contrário, atribui y.
    max_val = (x > y) ? x : y; 
    
    printf("O valor máximo é: %d\n", max_val); // Output: 10
    
    return 0;
}
// Explicação do exemplo:
// O operador ternário atua como um 'if/else' compacto para retornar um valor baseado em uma condição.

// ------------------------------------------------------------
// EXPLICAÇÃO DO MEU CÓDIGO LINHA POR LINHA
// ------------------------------------------------------------

#include <stdio.h> // Inclui a biblioteca padrão de entrada/saída (para printf)

int main(void) { // Início da função principal
  int age = 37; // Declara a variável 'age' do tipo int e inicializa com 37.
  printf("%ld\n", sizeof(age)); // Imprime o tamanho em bytes da variável 'age'. (%ld é usado para unsigned long, o tipo retornado por sizeof).
  printf("%ld", sizeof(int)); // Imprime o tamanho em bytes do tipo 'int' na arquitetura atual.
} // Fim da função principal

// TRECHO DE PRECEDÊNCIA EXPLICADO:
// int a = 2; int b = 4;
// int c = b + a * a / b - a; 
// 1. Precedência * e / (da esquerda para a direita):
//    a * a = 2 * 2 = 4
//    4 / b = 4 / 4 = 1
//    Expressão se torna: c = b + 1 - a
// 2. Precedência + e - (da esquerda para a direita):
//    b + 1 = 4 + 1 = 5
//    5 - a = 5 - 2 = 3
// 3. Resultado final: c = 3
//
// Versão com parênteses (mais legível):
// int c = b + ((a * a) / b) - a;

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Operadores (Geral)
// - Operandos
// - Operadores Aritméticos
// - Operadores Binários (`=`, `+`, `-`, `*`, `/`, `%`)
// - Operadores Unários (`+`, `-`, `++`, `--`, `!`)
// - Atribuição
// - Adição, Subtração, Multiplicação, Divisão, Módulo
// - Incremento (`++a`, `a++`)
// - Decremento (`--a`, `a--`)
// - Precedência de Incremento/Decremento (Pré-fixado vs. Pós-fixado)
// - Operadores de Comparação (`==`, `!=`, `>`, `<`, `>=`, `<=`)
// - Operadores Lógicos (`!`, `&&`, `||`)
// - Valores Booleanos (true/false)
// - Operadores de Atribuição Compostos (`+=`, `-=`, `*=`, `/=`, `%=`)
// - Operador Ternário (`? :`)
// - Condicionais (`if/else`)
// - Operador `sizeof`
// - Precedência dos Operadores
// - Associatividade (Esquerda para Direita, Direita para Esquerda)
// - Parênteses (`()`, maior prioridade)
// - Variável
// - Tipo (`int`)
// - Função `printf()`
// - Especificador de Formato (`%ld`)