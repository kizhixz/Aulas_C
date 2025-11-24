/*
ASSUNTO PRINCIPAL DETECTADO: Instruções Condicionais (if/else e switch) em C
Resumo geral do assunto.
Este documento descreve as duas principais estruturas que C oferece para controle de fluxo e tomada de decisão: a instrução 'if' (com 'else' e 'else if') e a instrução 'switch'.
Explicação clara e didática.
Instruções condicionais permitem que o programa execute blocos de código diferentes dependendo se uma determinada condição é avaliada como verdadeira (não-zero) ou falsa (zero). O 'if' é usado para avaliar expressões booleanas complexas, enquanto o 'switch' é ideal para comparar uma única variável com múltiplos valores discretos ('case'). É crucial entender a diferença entre o operador de comparação (==) e o operador de atribuição (=) no contexto dos condicionais, pois o último é uma fonte comum de bugs.
Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
As estruturas de controle de fluxo são elementos fundamentais de qualquer linguagem imperativa. Em C, os condicionais avaliam expressões onde 0 é FALSO e qualquer valor diferente de zero (incluindo negativos) é VERDADEIRO. O uso correto de palavras-chave como 'break' no 'switch' e a prevenção de erros de atribuição no 'if' são habilidades essenciais para a programação segura e eficiente em C.
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL
// ------------------------------------------------------------
// CONDICIONAIS:
// Estruturas que permitem ao programa tomar decisões e executar diferentes blocos de código
// com base no estado dos dados.
//
// 1. INSTRUÇÃO `if` (SE)
// - Avalia uma **condição booleana** (verdadeiro/falso).
// - **Estrutura básica:**
//   `if (condição) { /* bloco se verdadeiro */ }`
// - **`else` (SENÃO):** Executa um bloco de código se a condição do `if` for **falsa**.
//   `if (condição) { /* ... */ } else { /* bloco se falso */ }`
// - **`else if` (SENÃO SE):** Permite encadear múltiplas condições sequenciais. O primeiro bloco cuja condição for verdadeira será executado, e os demais serão ignorados.
//
// CONDIÇÃO EM C (BOOLEANOS):
// - O resultado da condição é um valor inteiro:
//   - **0** é sempre avaliado como **FALSO** (`false`).
//   - **Qualquer valor diferente de 0** (positivo ou negativo) é avaliado como **VERDADEIRO** (`true`).
//
// FONTE COMUM DE ERRO: ATRIBUIÇÃO vs. COMPARAÇÃO
// - **Comparação:** Use o operador **`==`** (Operador de Igual).
// - **Atribuição:** Use o operador **`=`** (Operador de Atribuição).
// - Se você usar acidentalmente `if (a = 1)`, a expressão é avaliada como 1 (que é VERDADEIRO), e o bloco será executado, além de alterar o valor de `a`.
// - Se você usar `if (a = 0)`, a expressão é avaliada como 0 (que é FALSO), e o bloco NUNCA será chamado.
//
// 2. INSTRUÇÃO `switch` (CHAVE)
// - Usada para realizar verificações contra múltiplos **valores exatos** de uma única variável.
// - **Estrutura:** Recebe uma variável como condição e usa `case` para cada valor esperado.
// - **`case` (CASO):** Define um ponto de entrada para um valor específico da variável.
// - **`break`:** Palavra-chave **necessária** ao final de cada `case` para sair do bloco `switch`. Se omitido, o código continua executando o próximo `case` (efeito "cascata").
// - **`default` (PADRÃO):** Ponto de entrada opcional que é executado se nenhum dos `case`s anteriores corresponder ao valor da variável. Deve ser colocado por último.

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// LINGUAGENS DE PROGRAMAÇÃO: Todas fornecem capacidade de escolhas.
// OPERADORES: Requer o uso correto dos operadores de comparação (`==`) e atribuição (`=`).

// ------------------------------------------------------------
// EXEMPLOS
// ------------------------------------------------------------

// Exemplo 1: Uso básico de if/else e else if
#include <stdio.h>

int main(void) {
    int score = 85;

    if (score >= 90) {
        printf("Conceito A\n");
    } else if (score >= 80) {
        printf("Conceito B\n");
    } else {
        printf("Ainda precisa melhorar\n");
    }
    // Output para score = 85: Conceito B
    
    return 0;
}
// Explicação do exemplo:
// Demonstra o encadeamento de condições com 'else if'. A condição `score >= 80` só é verificada
// se a primeira (`score >= 90`) for falsa.

// Exemplo 2: Uso do switch com break e default
#include <stdio.h>

int main(void) {
    int choice = 3;

    switch (choice) {
        case 1:
            printf("Opção 1 selecionada\n");
            break;
        case 2:
            printf("Opção 2 selecionada\n");
            break;
        default:
            printf("Opção inválida\n");
            break; // O 'break' aqui é opcional, mas boa prática.
    }
    // Output para choice = 3: Opção inválida

    return 0;
}
// Explicação do exemplo:
// Mostra como o `switch` direciona o fluxo para um valor específico (`case`) e usa o `default` 
// para tratar todos os outros casos. O `break` impede a execução do código do `case` seguinte.

// ------------------------------------------------------------
// EXPLICAÇÃO DO MEU CÓDIGO LINHA POR LINHA
// ------------------------------------------------------------

int a = 0; // Declara e inicializa a variável 'a' como 0.
if (a = 0) { // AQUI ESTÁ O ERRO: Isso é uma ATRIBUIÇÃO (a = 0), não uma comparação. 
  /* O que estiver aqui nunca será chamado */ // A atribuição retorna o valor 0. Como 0 é FALSO em C, o bloco 'if' nunca é executado.
}

int a = 1; // Declara e inicializa 'a' como 1.
if (a == 1) { // COMPARAÇÃO CORRETA: Verifica se 'a' é igual a 1. Verdadeiro.
  /* Realizar uma ação */ // O bloco de código será executado.
}

int a = 1; // Declara e inicializa 'a' como 1.
switch (a) { // Inicia o switch, verificando o valor da variável 'a' (1).
  case 0: // Caso 'a' seja 0. Não é o caso.
    /* Realizar uma ação */
    break;
  case 1: // Caso 'a' seja 1. É o caso.
    /* Realizar outra ação */ // Este bloco é executado.
    break; // Sai do switch.
  case 2: // Caso 'a' seja 2. (Ignorado devido ao 'break' acima).
    /* Realizar outra ação */
    break;
  default: // Para todos os outros casos. (Ignorado).
    /* Para todos os outros casos */
    break;
}

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Condicionais
// - Instrução `if`
// - Instrução `else`
// - Instrução `else if`
// - Instrução `switch`
// - Bloco de Código (entre chaves `{}`)
// - Condição Booleana (`true`/`false`)
// - Valor 0 (Falso em C)
// - Valor Diferente de 0 (Verdadeiro em C)
// - Operador de Comparação (`==`)
// - Operador de Atribuição (`=`)
// - Palavra-chave `case`
// - Palavra-chave `default`
// - Palavra-chave `break`
// - Efeito "Cascata" (Fall-through)
// - Variáveis (`int`)