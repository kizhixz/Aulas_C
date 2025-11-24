/*
ASSUNTO PRINCIPAL DETECTADO: Estruturas (struct) em C
Resumo geral do assunto: A palavra-chave 'struct' em C é usada para criar um tipo de dado composto, chamado de estrutura. Uma estrutura é uma coleção de variáveis (membros) de diferentes tipos, agrupadas sob um único nome. Isso permite a criação de modelos complexos de dados, como o tipo 'pessoa' que agrupa 'idade' e 'nome'.

Explicação clara e didática: Estruturas resolvem a limitação dos arrays, que só podem armazenar dados de um único tipo. Com 'struct', você pode ter um campo inteiro, um campo de ponteiro de caractere, um campo flutuante, etc., todos parte da mesma entidade lógica. Isso facilita a manipulação e a passagem de dados relacionados.

Contexto sobre o que esse tema significa na Linguagem C: 'struct' é uma das principais ferramentas para a organização de dados em C. É a base para a criação de tipos de dados abstratos e é fundamental em bibliotecas e sistemas operacionais. A combinação com 'typedef' é uma prática padrão que simplifica a sintaxe de declaração. A maneira como as estruturas são passadas para funções (por cópia) e a alternativa de usar ponteiros (passagem por referência) são conceitos cruciais para a performance e modificação de dados.
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (A Palavra-chave struct)
// ------------------------------------------------------------

// Estruturas são coleções de valores de diferentes tipos, diferentemente dos arrays,
// que são limitados a um único tipo de dado.
// Sintaxe básica:
// struct <nome_da_estrutura> {
//   tipo_1 membro_1;
//   tipo_2 membro_2;
//   //...outras variáveis/membros
// };
// 

// Declaração de Variáveis de Estrutura:
// 1. Após a Definição: 'struct pessoa { ... } flavio, pessoas[20];'
//    Isso declara 'flavio' como uma única variável do tipo 'struct pessoa' e 'pessoas' como um array
//    de 20 variáveis do tipo 'struct pessoa'.
// 2. Posteriormente: 'struct pessoa flavio;'
//    Declara a variável após a estrutura ter sido definida no escopo.

// Acesso e Modificação de Membros (Operador Ponto):
// O operador de acesso de membro (o ponto '.') é usado para acessar ou modificar
// os valores internos de uma estrutura.
// Exemplo: 'flavio.idade' acessa o membro 'idade' da variável 'flavio'.

// Inicialização:
// Uma estrutura pode ser inicializada na declaração, listando os valores dos membros
// na ordem em que foram definidos, entre chaves:
// struct pessoa flavio = { 37, "Flavio" };

// Passagem para Funções:
// Por padrão, estruturas são passadas para funções POR CÓPIA (passagem por valor).
// Isso significa que a função recebe uma cópia da estrutura, e quaisquer modificações
// internas à função não afetam a estrutura original.

// Ponteiros e Passagem por Referência:
// Para passar uma estrutura POR REFERÊNCIA (permitir que a função modifique a original),
// deve-se passar um PONTEIRO para a estrutura. O acesso aos membros é feito
// usando o operador de seta '->' (ou desreferenciando o ponteiro e usando o ponto '(*p).membro').

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------

// Arrays: Coleções de elementos do *mesmo* tipo. Estruturas fornecem a coleção de tipos *diferentes*.
// `char *nome`: Este membro é um ponteiro de caractere, comumente usado em C para representar strings de texto.
// `printf()` e `"%s"` / `"%u"`: A função de saída padrão, usando especificadores de formato
// para strings (`%s`) e inteiros sem sinal (`%u` para evitar warnings, embora `%d` seja comum para `int`).

// Combinação com `typedef`:
// A prática recomendada é usar 'typedef' para criar um alias para a estrutura, eliminando a
// necessidade de usar a palavra-chave 'struct' toda vez que a variável é declarada.
// Sintaxe com typedef: 'typedef struct { ... } NOME_DO_TIPO;'
// Por convenção, o nome do tipo (`PESSOA`) é em maiúsculas.
// Exemplo de uso: 'PESSOA flavio = { 37, "Flavio" };'

#include <stdio.h>
#include <string.h> // Necessário para manipulação de strings (se fôssemos modificar 'nome')

// Definição da estrutura usando 'typedef' (prática recomendada)
// Isso define um novo tipo chamado 'PESSOA' que é um alias para a estrutura.
typedef struct {
  int idade;
  char *nome; // Ponteiro para uma string de caracteres
} PESSOA; // Alias em maiúsculas por convenção

// Exemplo da sintaxe original (sem typedef) para comparação
struct pessoa_original {
  int idade;
  char *nome;
};

// Função para demonstrar a passagem por cópia (Passagem por Valor)
void envelhecer_por_copia(PESSOA p) {
    printf("\n--- Dentro da funcao (Copia) ---\n");
    p.idade++; // Modifica apenas a CÓPIA local
    printf("Idade interna (copia) apos modificacao: %d\n", p.idade);
}

// Função para demonstrar a passagem por referência (usando ponteiro)
void envelhecer_por_referencia(PESSOA *p_ptr) {
    printf("\n--- Dentro da funcao (Referencia) ---\n");
    // O operador '->' (seta) é o atalho para (*p_ptr).idade
    p_ptr->idade++; // Modifica a estrutura ORIGINAL
    printf("Idade interna (original) apos modificacao: %d\n", p_ptr->idade);
}


int main() {
    // 1. Declaração e Inicialização com typedef
    PESSOA flavio = { 37, "Flavio" };

    printf("--- Exemplo 1: Acesso e Impressao ---\n");
    // Acesso aos valores usando o operador ponto '.'
    printf("Nome: %s, Idade: %d\n", flavio.nome, flavio.idade);

    // 2. Modificação de Valores
    printf("\n--- Exemplo 2: Modificacao ---\n");
    printf("Idade de Flavio antes: %d\n", flavio.idade);
    flavio.idade = 38; // Alterando o valor usando o operador ponto '.'
    printf("Idade de Flavio depois: %d\n", flavio.idade);

    // 3. Demonstração de array de structs (Conteúdo relacionado)
    struct pessoa_original pessoas[2]; // Declaração de um array de structs
    pessoas[0].idade = 40;
    // O ponteiro 'nome' precisa apontar para uma string válida, por exemplo, um literal.
    pessoas[0].nome = "Maria";
    printf("\nPrimeira pessoa do array: %s, %d\n", pessoas[0].nome, pessoas[0].idade);


    // 4. Passagem de Estruturas para Funções (Conteúdo principal, detalhado)
    printf("\n--- Exemplo 4: Passagem por Copia ---\n");
    printf("Idade original antes da copia: %d\n", flavio.idade);
    envelhecer_por_copia(flavio);
    printf("Idade original APOS copia: %d (Nao mudou, pois foi copiada)\n", flavio.idade);

    printf("\n--- Exemplo 5: Passagem por Referencia ---\n");
    printf("Idade original antes da referencia: %d\n", flavio.idade);
    // Passamos o endereço da estrutura (&flavio)
    envelhecer_por_referencia(&flavio);
    printf("Idade original APOS referencia: %d (Mudou, pois um ponteiro foi usado)\n", flavio.idade);

    return 0;
}

// Explicação do meu código (dentro de main() e definições)
// 'struct pessoa { int idade; char *nome; };': Define a estrutura 'pessoa' com dois membros.
// 'char *nome;': Define um ponteiro para char, usado para armazenar strings.
// 'struct pessoa flavio = { 37, "Flavio" };': Declara e inicializa a variável 'flavio'.
// 'flavio.idade = 38;': Acessa o membro 'idade' da variável 'flavio' usando o operador ponto (.), e atribui um novo valor.
// 'printf("%s, idade %d", flavio.nome, flavio.idade);': Imprime os valores dos membros da estrutura.
// 'typedef struct { ... } PESSOA;': Cria um alias de tipo 'PESSOA' para a estrutura.
// 'PESSOA flavio = { 37, "Flavio" };': Usa o novo alias 'PESSOA' para declarar a variável.

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Palavra-chave 'struct'
// - Tipos de dados complexos / Estruturas de dados
// - Membros de estrutura (variáveis internas: int, char *)
// - Sintaxe 'struct <nome> { ... }'
// - Arrays vs. Estruturas (tipos diferentes)
// - Declaração de variáveis de estrutura
// - Inicialização de estruturas
// - Acesso a membros (Operador Ponto '.')
// - Modificação de valores de membros
// - Função 'printf()' e especificadores de formato
// - Passagem por cópia (Passagem por Valor)
// - Ponteiros (implícito em 'char *nome' e explícito na passagem por referência)
// - Passagem por referência (usando ponteiro para struct)
// - Palavra-chave 'typedef' para estruturas
// - Convenção de nomenclatura em maiúsculas para o alias ('PESSOA')