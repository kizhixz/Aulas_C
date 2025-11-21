/*
ASSUNTO PRINCIPAL DETECTADO: Constantes em C
Resumo geral do assunto.
Este documento explica duas maneiras principais de definir constantes em C: usando a palavra-chave 'const' (variáveis somente leitura) e a diretiva de pré-processador '#define' (constantes simbólicas).
Explicação clara e didática.
Constantes são valores fixos que não podem ser alterados durante a execução do programa. A maneira mais comum e moderna de declará-las é adicionando 'const' antes da declaração de tipo. Alternativamente, '#define' é usado como uma instrução do pré-processador para substituir um símbolo pelo seu valor em todo o código-fonte antes da compilação.
Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
A utilização de constantes é crucial para a legibilidade, manutenção e segurança do código. O padrão de nomenclatura em letras maiúsculas para constantes (`const int MAX_VALUE = 10;` ou `#define MAX_VALUE 10`) é uma convenção fundamental em C para diferenciar valores fixos de variáveis normais. O '#define' é um conceito de pré-processamento que é executado antes do compilador principal.
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL
// ------------------------------------------------------------
// DEFINIÇÃO DE CONSTANTES:
// Constantes são valores fixos que não podem ser alterados após a inicialização.
//
// MÉTODO 1: USANDO A PALAVRA-CHAVE `const`
// - É a maneira mais recomendada para criar variáveis somente leitura.
// - A palavra-chave **`const`** é adicionada **antes da declaração do tipo**.
// - **Obrigatório:** O valor deve ser especificado (inicializado) na declaração.
// - Exemplo: `const int age = 37;`
//
// CONVENÇÃO DE NOMENCLATURA:
// - É uma **convenção** de codificação em C (melhorando a legibilidade) definir constantes com **letras maiúsculas**.
// - Exemplo: `const int AGE = 37;`
// - Ajuda a distinguir constantes (MAIÚSCULAS) de variáveis (minúsculas).
// - Regras de Nomenclatura: As mesmas das variáveis (letras, algarismos, `_`, não pode começar com algarismo).
//
// MÉTODO 2: USANDO A DIRETIVA `#define`
// - É uma **diretiva de pré-processador**, executada antes da compilação.
// - Sintaxe: **`#define NOME_CONSTANTE VALOR`**
// - **Não** requer o tipo de dado.
// - **Não** requer o sinal de atribuição (`=`).
// - **Não** requer ponto e vírgula (`;`) no final.
// - O compilador infere o tipo a partir do valor em tempo de compilação.
// - Exemplo: `#define AGE 37`

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// PRÉ-PROCESSADOR:
// A diretiva `#define` pertence ao pré-processador, uma etapa que processa o código antes do compilador principal.
//
// LEGIBILIDADE E CONVENÇÃO:
// O uso de letras maiúsculas para constantes é um exemplo de convenção de codificação que aumenta a legibilidade.
//
// VARIÁVEIS VS. CONSTANTES:
// Variáveis são nomes em minúsculas (por convenção) e seus valores podem mudar. Constantes são nomes em maiúsculas (por convenção) e seus valores são fixos.

// ------------------------------------------------------------
// EXEMPLOS
// ------------------------------------------------------------

// Exemplo 1: Constante usando 'const' (variável somente leitura)
#include <stdio.h>

const int MAX_TRIES = 5; // Declaração de constante usando a convenção de maiúsculas

int main() {
    // MAX_TRIES = 6; // Se descomentado, o compilador emitirá um erro por tentar alterar uma constante.
    
    printf("O número máximo de tentativas é: %d\n", MAX_TRIES);
    
    return 0;
}
// Explicação do exemplo:
// A palavra-chave 'const' garante que o valor de MAX_TRIES não possa ser alterado. O 'int' define o tipo.

// Exemplo 2: Constante usando '#define' (constante simbólica)
#include <stdio.h>

#define PI 3.14159 // Constante definida via pré-processador
#define YEAR_OF_BIRTH 1988

int main() {
    printf("O valor de PI é aproximadamente: %f\n", PI);
    printf("Ano de nascimento definido: %d\n", YEAR_OF_BIRTH);
    
    return 0;
}
// Explicação do exemplo:
// O pré-processador substitui todas as ocorrências de 'PI' por '3.14159' e 'YEAR_OF_BIRTH' por '1988' 
// no código-fonte antes da compilação.

// ------------------------------------------------------------
// EXPLICAÇÃO DO MEU CÓDIGO LINHA POR LINHA
// ------------------------------------------------------------

#define AGE 37 // Diretiva de pré-processador para definir a constante simbólica AGE com o valor 37.

/*
Se fosse com 'const':
const int AGE = 37; // Declara a constante AGE do tipo int com valor 37.

int main() {
    const int age = 37; // Declara uma variável 'age' somente leitura, com o tipo int e valor 37.
    // ...
}
*/

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Constantes
// - Palavra-chave `const`
// - Declaração de Constante
// - Inicialização de Constante
// - Regras de Nomenclatura (letras, algarismos, sublinha, não pode começar com algarismo)
// - Convenção de Letras Maiúsculas (para legibilidade)
// - Diretiva `#define`
// - Pré-processador
// - Tipo de dado
// - Sinal de Igual (`=`)
// - Ponto e Vírgula (`;`)
// - Compilador
// - Inferência de Tipo
// - Tempo de Compilação 