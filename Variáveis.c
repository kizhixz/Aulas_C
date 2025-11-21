/*
ASSUNTO PRINCIPAL DETECTADO: Variáveis e Tipos de Dados em C
Resumo geral do assunto.
Este documento detalha o conceito de tipagem estática em C, as regras de declaração de variáveis e os tipos de dados primitivos. Aborda as categorias de números inteiros (int, char, short, long) e números de ponto flutuante (float, double, long double), incluindo as variações sem sinal (unsigned).
Explicação clara e didática.
C é uma linguagem estaticamente tipada, o que significa que o tipo de toda variável deve ser declarado e é conhecido em tempo de compilação. Isso difere de linguagens interpretadas (Python, JavaScript). O texto explica as diferenças de tamanho e alcance (range) dos tipos inteiros e o risco de overflow (exceder o limite do tipo). Em seguida, introduz os tipos flutuantes para números decimais.
Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
A tipagem estática e o gerenciamento explícito dos tamanhos dos tipos são fundamentais para a performance e o controle de baixo nível do C. O texto demonstra a sintaxe correta para declaração/inicialização de variáveis, o risco de conversão implícita (implicit conversion) e o uso do operador `sizeof()` para determinar o tamanho de um tipo em bytes na arquitetura atual. O perigo de overflow, especialmente com tipos com ou sem sinal, é um conceito central de baixo nível que o programador deve gerenciar.
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL
// ------------------------------------------------------------
// TIPAGEM ESTÁTICA:
// C é uma **linguagem estaticamente tipada**.
// O tipo de uma variável é associado no momento da declaração e é **conhecido em tempo de compilação**.
// Isso contrasta com linguagens dinamicamente tipadas (ex: Python, JavaScript).
//
// DECLARAÇÃO E INICIALIZAÇÃO DE VARIÁVEIS:
// Sintaxe: `tipo nome_da_variavel;` ou `tipo nome_da_variavel = valor_inicial;`
// Exemplo: `int age = 37;`
//
// REGRAS DE NOMENCLATURA:
// - Pode conter letras (maiúsculas/minúsculas), algarismos e sublinha (`_`).
// - **Não pode começar por um algarismo.**
// - Exemplo válido: `AGE`, `Age10`
// - Exemplo inválido: `1age`
//
// ALTERAÇÃO DE VALOR:
// O valor de uma variável pode ser alterado a qualquer momento usando o **operador de atribuição** (`=`), desde que o novo valor seja do **mesmo tipo**.
//
// TIPOS DE DADOS INTEGRADOS (PRIMITIVOS):
// - Tipos de Números Inteiros: **`int`**, **`char`**, **`short`**, **`long`**
// - Tipos de Ponto Flutuante: **`float`**, **`double`**, **`long double`**
//
// NÚMEROS INTEIROS:
// - **`int`**: O tipo mais comum para números inteiros.
// - **`char`**: Tipicamente usado para armazenar caracteres **ASCII**, mas pode armazenar inteiros pequenos (ex: -128 a 127). Ocupa menos de 1 byte (mas, na prática, o `sizeof(char)` é 1 byte por definição).
// - **Tamanhos e Ranges (Garantias Mínimas):**
//   - **`int`**: Pelo menos 2 bytes.
//   - **`short`**: Pelo menos 2 bytes.
//   - **`long`**: Pelo menos 4 bytes.
// - A garantia padrão ANSI C é que: **`short` $\leq$ `int` $\leq$ `long`** (em termos de tamanho em bytes).
// - Os valores exatos dependem da **implementação** e **arquitetura** (ex: Arduino Uno vs. MKR 1010).
//
// NÚMEROS INTEIROS SEM SINAL (UNSIGNED):
// - O prefixo **`unsigned`** (sem sinal) move o intervalo para começar em **0**, dobrando o limite superior positivo.
// - Ex: `unsigned char` (0 a pelo menos 255), `unsigned int` (0 a pelo menos 65,535).
//
// PROBLEMA COM OVERFLOW:
// O C **não protege o programador** de exceder os limites do tipo (`overflow`).
// - Se o tipo é **`unsigned`**: O valor retorna ao início (comportamento de **módulo**). Ex: `unsigned char 255 + 1` resulta em `0`.
// - Se o tipo tem **sinal** (`signed` ou padrão): O comportamento é **indefinido** (pode resultar em um número inesperado). O programador é responsável por evitar isso.

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// CONVERSÃO IMPLÍCITA E AVISOS DO COMPILADOR:
// - Se um valor de um tipo maior (ex: `double`/ponto flutuante) é atribuído a um tipo menor (ex: `int`), o compilador (`gcc`) emitirá um **aviso** (`warning: implicit conversion`).
// - O valor decimal será convertido (truncado) para o valor inteiro.
// - Aviso também ocorre ao inicializar um `char` com um valor > 127 ou < -128 (ex: `char j = 1000;`).
// - O compilador **pode não avisar** em operações de atribuição composta (ex: `j += 1000;`) se a variável for inicializada primeiro.
//
// NÚMEROS DE PONTO FLUTUANTE:
// - Usados para representar números com casas decimais (frações).
// - Representam números como decimais na **potência de 10** (notação científica, ex: `1.29e-3`).
// - **Tipos:**
//   - **`float`**: Tipicamente 32 bits. Precisão de 24 bits significativos.
//   - **`double`**: Tipicamente 64 bits. Precisão de 53 bits significativos.
//   - **`long double`**: Tipicamente 80 bits ou mais.
// - Todos representam números positivos e negativos.
//
// O operador `sizeof()`:
// - Retorna o **tamanho em bytes** de um tipo ou de uma variável na arquitetura de execução.
// - Usado para determinar dinamicamente o tamanho alocado para cada tipo (`%lu` é o especificador de formato para `unsigned long`, o tipo de retorno de `sizeof`).

// ------------------------------------------------------------
// EXEMPLOS
// ------------------------------------------------------------

// Exemplo 1: Declaração, Inicialização e Atribuição
#include <stdio.h>

int main(void) {
    int age;          // Declaração da variável 'age' do tipo int
    int count = 10;   // Declaração e inicialização da variável 'count'
    age = 37;         // Atribuição de novo valor à variável 'age'

    printf("Idade inicial: %d\n", age); 
    
    age = 100;        // Alteração do valor
    printf("Nova idade: %d\n", age);

    // Tentativa de atribuição com tipo incorreto (o compilador pode avisar e converter)
    // int age = 0;
    // age = 37.2; // Isso resultará em conversão implícita para int (provavelmente 37 ou 0, dependendo da ordem)
    
    return 0;
}
// Explicação do exemplo: 
// Demonstra a sintaxe de declaração (`int age;`), inicialização (`int count = 10;`) 
// e reatribuição (`age = 100;`) para variáveis inteiras.

// Exemplo 2: Overflow com unsigned char
#include <stdio.h>

int main(void) {
  unsigned char j = 255; // 255 é o valor máximo para unsigned char (geralmente 1 byte)
  printf("J inicial: %u\n", j); 

  j = j + 10; // Soma 10. (255 + 10 = 265). O limite é 255, então ocorre overflow.
  
  // O valor final será (265 % 256), que é 9.
  printf("J após overflow: %u\n", j); // Output: 9
  
  return 0;
}
// Explicação do exemplo:
// Demonstra o comportamento de *wrap-around* (volta ao zero) quando ocorre overflow 
// em um tipo sem sinal (`unsigned char`).

// Exemplo 3: Uso do sizeof() para verificar tamanhos
#include <stdio.h>

int main(void) {
  printf("Tamanho de char: %lu bytes\n", sizeof(char));
  printf("Tamanho de int: %lu bytes\n", sizeof(int));
  printf("Tamanho de short: %lu bytes\n", sizeof(short));
  printf("Tamanho de long: %lu bytes\n", sizeof(long));
  printf("Tamanho de float: %lu bytes\n", sizeof(float));
  printf("Tamanho de double: %lu bytes\n", 
    sizeof(double));
  printf("Tamanho de long double: %lu bytes\n", 
    sizeof(long double));
  return 0;
}
// Explicação do exemplo:
// O operador `sizeof()` é usado para determinar quantos bytes cada tipo de dado 
// ocupa na arquitetura de execução atual. O especificador de formato `%lu` 
// é usado para imprimir o valor retornado por `sizeof()`.

// ------------------------------------------------------------
// EXPLICAÇÃO DO MEU CÓDIGO LINHA POR LINHA
// ------------------------------------------------------------

#include <stdio.h> // Inclui a biblioteca padrão de entrada/saída (necessária para printf)

int main(void) { // Início da função principal
  unsigned char j = 255; // Declara e inicializa a variável 'j' como unsigned char (sem sinal) com o valor máximo.
  j = j + 10; // Soma 10 a 'j'. Como 255 + 10 excede o limite (overflow), 'j' volta a 9 (265 % 256).
  printf("%u", j); /* 9 */ // Imprime o valor final de 'j' (9) usando o especificador %u para unsigned int.
} // Fim da função principal

// AVISO DO COMPILADOR LINHA POR LINHA:
// Exemplo de código que gera warning:
// #include <stdio.h>
// int main(void) {
//   char j = 1000; // O compilador avisará que 1000 é muito grande para um 'char' e converterá para um valor incorreto (ex: -24).
// }

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Tipagem Estática
// - Variável
// - Declaração de Variável
// - Inicialização de Variável
// - Regras de Nomenclatura (letras, algarismos, sublinha, não pode começar com algarismo)
// - Operador de Atribuição (`=`)
// - Tempo de Compilação
// - Conversão Implícita (Implicit Conversion)
// - Tipos de Dados Primitivos
// - Tipos Inteiros: `int`, `char`, `short`, `long`
// - Tipos Flutuantes: `float`, `double`, `long double`
// - Modificador de Tipo: `unsigned`
// - Intervalo de Valores (Range)
// - Arquitetura (Hardware)
// - Implementação (Dependência da arquitetura)
// - Bytes (Tamanho em memória)
// - Tabela ASCII
// - Padrão ANSI C
// - Overflow (e wrap-around para unsigned)
// - Comportamento Indefinido (para overflow em signed)
// - Aviso do Compilador (Warning)
// - Operador `sizeof()`
// - Notação Científica (ex: `1.29e-3`)
// - Precisão (bits significativos)
// - Expoente (para flutuantes)
// - Especificador de Formato: `%u`, `%lu`
// - Operadores de Atribuição Composta (ex: `+=`)
// - Compilador `gcc`
// - `printf()`