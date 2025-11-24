/*
ASSUNTO PRINCIPAL DETECTADO: Tipos Enumerados (Enumerações) combinados com typedef
Resumo geral do assunto: A combinação das palavras-chave 'typedef' e 'enum' em C permite ao programador definir um novo tipo que pode assumir um de um conjunto de valores nomeados (constantes inteiras). Isso melhora drasticamente a legibilidade do código, permitindo o uso de nomes significativos em vez de números mágicos.

Explicação clara e didática: Um tipo enumerado cria um conjunto de identificadores, onde cada identificador (ou 'membro') representa um valor inteiro. Usar 'typedef' em conjunto com 'enum' elimina a necessidade de escrever a palavra-chave 'enum' toda vez que uma variável desse tipo é declarada, simplificando a sintaxe para 'NOME_DO_TIPO variavel;'.

Contexto sobre o que esse tema significa na Linguagem C: Tipos enumerados são usados para definir constantes simbólicas de forma organizada. Por baixo dos panos, são inteiros. Sua principal utilidade é restringir uma variável a um conjunto finito e bem definido de valores. O uso de 'typedef' é um dos mais importantes para 'enum', pois transforma uma sintaxe potencialmente longa (ex: 'enum nome_tag { ... }') em um nome de tipo limpo e direto (ex: 'DIA_DA_SEMANA').
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (typedef e enum)
// ------------------------------------------------------------

// O tipo enumerado é definido usando a palavra-chave 'enum'.
// A sintaxe que combina 'typedef' e 'enum' é amplamente utilizada para criar um novo tipo:
// typedef enum { /* ... valores ... */ } NOME_DO_TIPO;
// 

// Essa combinação é considerada um dos usos mais importantes da palavra-chave 'typedef',
// pois facilita a declaração de variáveis de enumeração.

// Convenção de Nomenclatura: Por convenção, o 'NOME_DO_TIPO' criado (o alias) é escrito
// em letras MAIÚSCULAS para ser facilmente reconhecido como um tipo definido pelo usuário.

// Mapeamento Interno: Internamente, cada membro da enumeração é mapeado para um valor inteiro,
// começando por 0 e incrementando em 1 para cada membro subsequente, a menos que seja explicitamente
// inicializado com outro valor.
// Exemplo: 'segunda' é mapeado para 0, 'terca' para 1, 'quarta' para 2, e assim por diante.
// Embora tecnicamente seja possível usar o número (ex: 'if (dia == 0)'), o uso do nome
// (ex: 'if (dia == segunda)') é muito mais legível e recomendado para humanos.

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------

// Tipos Integrados e 'bool': O texto menciona que C já possui um tipo 'bool' (booleano),
// que é definido na biblioteca <stdbool.h> e usa os valores 'true' e 'false'.
// Embora o exemplo de 'BOOLEANO' demonstre a sintaxe, ele é menos prático devido à existência
// do tipo 'bool' nativo no C moderno (C99 em diante).

// Biblioteca <stdio.h>: Necessária para usar a função 'printf()', que é utilizada para
// exibir mensagens no console (saída padrão).

// Condicionais ('if', 'else'): Estruturas de controle de fluxo usadas para executar diferentes
// blocos de código dependendo de uma condição (aqui, a comparação se 'dia' é igual a 'segunda').

// 'main(void)': A função principal, o ponto de entrada de todo programa C.

// Declaração de Variável: 'DIA_DA_SEMANA dia = segunda;' é a declaração de uma variável 'dia'
// do tipo enumerado 'DIA_DA_SEMANA', inicializando-a com o valor simbólico 'segunda'.

#include <stdio.h> // Diretiva necessária para o uso da função printf()
#include <stdbool.h> // Opcional, mas fornece o tipo 'bool' nativo (mencionado no texto)

// Exemplo 1: Tipos Booleano (Conceitual)
// Demonstração da sintaxe (embora 'bool' seja preferido na prática)
typedef enum {
  falso, // Mapeado para 0 (por padrão)
  verdadeiro // Mapeado para 1 (por padrão)
} BOOLEANO;

// Exemplo 2: Dias da Semana (Exemplo prático do conteúdo)
typedef enum {
  segunda,  // Mapeado para 0
  terca,    // Mapeado para 1
  quarta,   // Mapeado para 2
  quinta,   // Mapeado para 3
  sexta,    // Mapeado para 4
  sabado,   // Mapeado para 5
  domingo   // Mapeado para 6
} DIA_DA_SEMANA;

// Exemplo 3: Nova variável para demonstração de outro valor
void demonstracao_outros_valores() {
    DIA_DA_SEMANA hoje = sabado;
    printf("\n--- Exemplo Adicional ---\n");
    printf("Hoje eh sabado. O valor inteiro interno de 'sabado' eh: %d\n", hoje);

    if (hoje == sexta) {
        printf("Ainda eh sexta-feira.\n");
    } else if (hoje == 5) { // Usando o valor inteiro interno para demonstrar o mapeamento
        printf("Sabado eh o dia 5 (indice zero).\n");
    }
}


int main(void) {
  // O tipo é 'DIA_DA_SEMANA' e o valor é 'segunda' (que internamente é 0)
  DIA_DA_SEMANA dia = segunda;

  printf("--- Exemplo Principal ---\n");

  // O condicional usa o nome simbólico, melhorando a legibilidade.
  if (dia == segunda) {
    printf("Hoje e segunda! (Valor interno: %d)\n", dia);
  } else {
    printf("Hoje nao e segunda (Valor interno: %d)\n", dia);
  }

  // Explicação do condicional:
  // if (dia == segunda) { ... }: A condição verifica se o valor da variável 'dia' é igual ao
  // valor inteiro associado ao identificador 'segunda' (que é 0).
  // if (dia == 0) teria o mesmo efeito, mas o uso do nome simbólico ('segunda')
  // é muito mais claro para o programador.

  demonstracao_outros_valores();

  return 0;
}

// Explicação do meu código (dentro de main() e definições)
// 'typedef enum { ... } DIA_DA_SEMANA;': Define um novo tipo chamado DIA_DA_SEMANA que só pode
// assumir os valores listados dentro das chaves, mapeados para inteiros (0 a 6).
// '#include <stdio.h>': Inclui a biblioteca de entrada/saída padrão para usar printf.
// 'DIA_DA_SEMANA dia = segunda;': Declara uma variável 'dia' do tipo recém-criado e a inicializa
// com o primeiro valor enumerado.
// 'if (dia == segunda)': Compara o valor da variável 'dia' com a constante simbólica 'segunda'.
// 'printf(...)': Exibe a string de texto no console.

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Palavra-chave 'typedef'
// - Palavra-chave 'enum'
// - Tipos enumerados
// - Sintaxe 'typedef enum { ... } NOME_DO_TIPO;'
// - Convenção de nomenclatura em maiúsculas (NOME_DO_TIPO)
// - Definição de constantes nomeadas (membros da enumeração: segunda, terca, etc.)
// - Mapeamento para números inteiros (segunda = 0, terca = 1, etc.)
// - Tipo 'bool' integrado em C (mencionado)
// - Função 'printf()'
// - Condicionais 'if' / 'else'
// - Função 'main(void)'
// - Biblioteca '#include <stdio.h>'