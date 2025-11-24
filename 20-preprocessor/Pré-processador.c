/*
ASSUNTO PRINCIPAL DETECTADO: O Pré-processador C e Suas Diretivas
Resumo geral do assunto: O pré-processador é a primeira fase de compilação de um programa C. Ele atua como uma ferramenta de substituição de texto, processando diretivas que começam com o símbolo '#'. Suas funções incluem a inclusão de arquivos, a substituição de constantes simbólicas e a compilação condicional de blocos de código.

Explicação clara e didática: O pré-processador prepara o código-fonte para o compilador. Ele resolve todas as diretivas (#include, #define, #if, etc.) antes que o código principal em C seja efetivamente compilado. Isso permite modularização (incluir headers), definir constantes globais (constantes simbólicas) e incluir ou excluir código com base em condições (compilação condicional).

Contexto sobre o que esse tema significa na Linguagem C: As diretivas do pré-processador são essenciais para a estrutura e portabilidade de programas C. Elas permitem que o código seja adaptado a diferentes ambientes ou configurações de compilação sem alterar o código C principal, e fornecem um mecanismo para definir constantes e macros que otimizam o desempenho em comparação com a definição de variáveis em tempo de execução.

*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Diretivas do Pré-processador)
// ------------------------------------------------------------

// O Pré-processador: É uma ferramenta que faz parte do padrão C. Ele executa ANTES do compilador.
// Sua função é processar o código-fonte e garantir que o compilador receba todos os dados necessários.

// Diretivas: Qualquer linha que começa com o símbolo '#' é uma diretiva tratada pelo pré-processador.

// 1. #include (Inclusão de Arquivos):
// Procura e insere o conteúdo dos arquivos de cabeçalho (`.h`) no local da diretiva.
// Exemplo: `#include <stdio.h>` ou `#include "meuArquivo.h"`

// 2. Constantes Simbólicas (#define):
// Permite definir um identificador (constante simbólica) que será substituído pelo seu valor real
// em todo o código antes da compilação. Isso não cria variáveis em tempo de compilação.
// Exemplo: `#define PI 3.14`

// 3. Macros (#define com Argumentos):
// São semelhantes às constantes simbólicas, mas podem aceitar argumentos e tipicamente contêm código.
// Elas são limitadas a definições de uma linha.
// Exemplo: `#define POTENCIA(x) ((x) * (x))`
// A prática recomendada é usar parênteses adicionais para garantir a precedência correta das operações.
// Diferença chave: Macros não especificam tipos de argumentos ou valores de retorno, diferente de funções.

// 4. Compilação Condicional (#if, #ifdef, #ifndef, #else, #endif):
// Permite incluir ou excluir blocos de código do processo de compilação, dependendo de uma condição.
// - `#if expressão`: Inclui o bloco se a expressão for verdadeira (não zero).
// - `#ifdef IDENTIFICADOR`: Inclui o bloco se o identificador foi definido (via #define).
// - `#ifndef IDENTIFICADOR`: Inclui o bloco se o identificador NÃO foi definido.
// - `#if defined(IDENTIFICADOR)` / `#if !defined(IDENTIFICADOR)`: Alternativas para `#ifdef` e `#ifndef`.
// O uso de `#if 0` e `#endif` é uma técnica comum para comentar temporariamente grandes blocos de código.

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------

// Constantes Simbólicas Predefinidas: O pré-processador define automaticamente algumas constantes
// úteis que podem ser acessadas pelo programa, todas começando e terminando com sublinhas duplas:
// - `__LINE__`: Linha atual no código-fonte (tipo inteiro).
// - `__FILE__`: Nome do arquivo-fonte (tipo string).
// - `__DATE__`: Data da compilação (formato `Mmm dd aaaa`).
// - `__TIME__`: Hora da compilação (formato `hh:mm:ss`).

// Tipo de dado `const int`: Embora o texto use `#define VALOR 1`, o exemplo de condicional usa
// `const int DEBUG = 0;`. Embora ambas definam valores constantes, o `#if` atua em diretivas
// de pré-processador. O exemplo `const int DEBUG = 0;` não seria o ideal para o `#if`, que atua
// antes do compilador lidar com variáveis `const`.

// Função `printf()`: Usada para exibir strings (`%s`) e inteiros (`%u` para unsigned ou `%d`).

#include <stdio.h>

// Definindo constantes simbólicas
#define VALOR 1
#define PI 3.14
#define NOME "Flavio"
// Definindo uma macro
#define POTENCIA(x) ((x) * (x))

// Definindo a constante DEBUG para compilação condicional
#define DEBUG 0 // 0 = false/desativado, qualquer outro valor = true/ativado

void exemplo_constantes_simbolicas() {
    printf("\n--- Constantes Simbolicas ---\n");
    // O pré-processador substitui VALOR, PI e NOME pelos seus valores
    printf("Valor da constante: %d\n", VALOR);
    printf("Valor de PI: %.2f\n", PI);
    printf("Nome definido: %s\n", NOME);
}

void exemplo_macros() {
    printf("\n--- Macro ---\n");
    // O pré-processador substitui POTENCIA(4) por ((4) * (4)) = 16
    printf("Potencia de 4: %u\n", POTENCIA(4));
    // Exemplo de uso de macro onde o tipo é inferido/ignorado:
    printf("Potencia de 3.5: %.2f\n", POTENCIA(3.5)); // ((3.5) * (3.5)) = 12.25
}

void exemplo_ifdef() {
    printf("\n--- Exemplo #ifdef e Constantes Predefinidas ---\n");
    #ifdef VALOR // Verifica se VALOR está definido
      printf("O identificador VALOR esta definido.\n");
    #else
      printf("O identificador VALOR nao esta definido.\n");
    #endif

    // Exemplo de uso de constantes simbólicas predefinidas
    printf("Compilado em: %s\n", __FILE__);
    printf("Data: %s, Hora: %s\n", __DATE__, __TIME__);
    printf("Esta linha esta na linha: %d\n", __LINE__); // Imprime o número da linha

    #ifndef NAO_EXISTE // Verifica se NAO_EXISTE não está definido
        printf("A constante NAO_EXISTE nao esta definida. (OK)\n");
    #endif
}


int main(void) {
    // -----------------------------------------------------------
    // Exemplo de Compilação Condicional (do Conteúdo)
    // -----------------------------------------------------------

    #if DEBUG == 0 // Verifica se o valor da constante definida pelo pré-processador é 0
      printf("Eu NAO estou fazendo debugging.\n");
    #else
      printf("Eu estou fazendo debugging.\n");
    #endif
    // NOTA: No texto original, const int DEBUG = 0; é usado, mas a checagem com #if
    // deve ser feita em uma constante definida por #define, como acima.

    exemplo_constantes_simbolicas();
    exemplo_macros();
    exemplo_ifdef();


    return 0;
}

// Explicação do meu código (dentro de main() e definições)
// `#define DEBUG 0`: Define a constante simbólica DEBUG com valor 0 para o pré-processador.
// `#if DEBUG == 0`: Verifica se o valor de DEBUG é 0. O código neste bloco será incluído.
// `#define POTENCIA(x) ((x) * (x))`: Define uma macro chamada POTENCIA que aceita um argumento 'x'.
// `printf("%u\n", POTENCIA(4));`: O pré-processador substitui 'POTENCIA(4)' pelo código '((4) * (4))'.
// `#ifdef VALOR`: Verifica a existência da constante simbólica 'VALOR'.
// `__FILE__`: Constante predefinida que é substituída pelo nome do arquivo atual.
// `__LINE__`: Constante predefinida que é substituída pelo número da linha atual.

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - O Pré-processador C
// - Diretivas do pré-processador (linhas que começam com '#')
// - Diretiva '#include' (inclusão de arquivos)
// - Diretiva '#define' (constantes simbólicas)
// - Macros (com argumentos)
// - Compilação condicional ('#if', '#else', '#endif')
// - Diretiva '#ifdef'
// - Diretiva '#ifndef'
// - Uso de '#if defined' e '#if !defined'
// - Constantes simbólicas predefinidas (`__LINE__`, `__FILE__`, `__DATE__`, `__TIME__`)
// - Função `printf()` e especificadores de formato
// - Funções vs. Macros (diferença de tipagem e limites de uma linha)