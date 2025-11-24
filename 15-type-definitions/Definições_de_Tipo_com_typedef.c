/*
ASSUNTO PRINCIPAL DETECTADO: Definições de Tipo com typedef
Resumo geral do assunto: A palavra-chave typedef em C é usada para criar um novo nome (um alias) para um tipo de dado existente, seja ele um tipo fundamental (como int), um tipo enumerado, ou uma estrutura. Isso aumenta a legibilidade e a portabilidade do código.

Explicação clara e didática: typedef permite dar um nome mais descritivo, mais curto ou mais fácil de manusear a tipos já definidos. A prática comum é usar letras maiúsculas para o novo nome de tipo para que ele se destaque no código.

Contexto sobre o que esse tema significa na Linguagem C: typedef é uma ferramenta de abstração de tipos. Embora possa ser usada para tipos simples como 'int', seu poder real é revelado quando usada com tipos complexos (structs e unions) e tipos enumerados (enum), facilitando a declaração de variáveis desses tipos e melhorando a organização do código.
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (A Palavra-chave typedef)
// ------------------------------------------------------------

// A palavra-chave 'typedef' (de 'type definition') é uma facilidade da linguagem C.
// Ela permite que o programador crie um 'pseudônimo' ou um 'alias' para um tipo existente.
// A sintaxe para usá-la é:
// 'typedef tipoExistente NOVOTIPO;'
// O 'tipoExistente' é o tipo de dado original que está sendo renomeado (ex: int, float, struct, etc.).
// O 'NOVOTIPO' é o novo nome (alias) que o programador está definindo para esse tipo.
// Por convenção, o novo nome de tipo é escrito em letras MAIÚSCULAS.
// Isso ajuda a distinguir o novo tipo (criado pelo usuário) dos tipos integrados do C (ex: int, char).

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------

// Tipos Integrados em C: São os tipos de dados fundamentais e nativos da linguagem, como 'int' (inteiro),
// 'char' (caractere), 'float' (ponto flutuante de precisão simples) e 'double' (ponto flutuante de precisão dupla).
// O 'typedef' parte desses tipos para criar as novas definições.

// Variáveis: São nomes simbólicos para locais de armazenamento. O exemplo usa a declaração de variável:
// 'NUMBER um = 1;' onde 'NUMBER' é o tipo (o novo alias), 'um' é o nome da variável e '1' é o valor inicial.

// Tipos Enumerados (enum): Um dos conceitos onde 'typedef' se torna muito útil. Tipos enumerados
// permitem definir um conjunto de constantes inteiras nomeadas. Usar 'typedef' simplifica a sintaxe de
// declaração de variáveis de um 'enum'.

// Estruturas (struct): O outro conceito onde 'typedef' é essencial. Estruturas permitem agrupar
// diferentes tipos de dados sob um único nome. 'typedef' é frequentemente usado para evitar a
// necessidade de usar a palavra-chave 'struct' toda vez que uma variável desse tipo é declarada.

#include <stdio.h> // Necessário para a função printf()

// Definição de tipo usando typedef
// O tipo 'int' (tipoExistente) é renomeado para 'NUMBER' (NOVOTIPO).
typedef int NUMBER;

// Exemplo de como usar typedef com um tipo simples (int)
// O propósito é principalmente demonstrar a sintaxe.
void exemplo_basico_typedef() {
    // Declaramos a variável 'um' usando o novo tipo 'NUMBER'.
    NUMBER um = 1;
    NUMBER outro_numero = 100;

    printf("--- Exemplo 1: Uso Basico do typedef ---\n");
    printf("O valor da variavel 'um' (tipo NUMBER) eh: %d\n", um);
    printf("O valor de 'outro_numero' eh: %d\n", outro_numero);

    // Na prática, 'NUMBER' é tratado pelo compilador exatamente como 'int'.
}

// Exemplo 2: Ilustrando o poder com uma estrutura (struct) (Conteúdo Relacionado)
// Embora struct não estivesse no texto, este exemplo demonstra o PORQUÊ do typedef ser útil.
// 
typedef struct {
    int x;
    int y;
} PONTO; // Aqui, PONTO é o novo nome para a estrutura anônima acima.

void exemplo_uso_com_struct() {
    printf("\n--- Exemplo 2: Uso do typedef com struct ---\n");
    // Sem typedef, precisaríamos escrever 'struct PONTO ponto1 = {10, 20};' (se a struct tivesse nome).
    // Com o typedef, podemos usar o nome 'PONTO' diretamente, simplificando:
    PONTO ponto1 = {10, 20};
    printf("Coordenada x do ponto1: %d\n", ponto1.x);
    printf("Coordenada y do ponto1: %d\n", ponto1.y);
}


// A função main é o ponto de entrada do programa C
int main() {
    // Código de exemplo original:
    // typedef int NUMBER
    // NUMBER um = 1;

    exemplo_basico_typedef();
    exemplo_uso_com_struct();

    return 0;
}

// Explicação do meu código (dentro de main() e exemplo_basico_typedef)
// 'typedef int NUMBER;': Esta linha define um novo nome de tipo 'NUMBER' que é um sinônimo exato para o tipo 'int'.
// 'NUMBER um = 1;': Declara uma variável inteira chamada 'um' e a inicializa com o valor 1, utilizando o alias 'NUMBER' no lugar de 'int'.
// 'printf(...)': Função padrão da biblioteca <stdio.h> usada para imprimir a saída formatada no console.

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Palavra-chave 'typedef'
// - Definições de tipo
// - Tipos integrados em C (int)
// - Sintaxe 'typedef tipoExistente NOVOTIPO'
// - Convenção de nomenclatura em maiúsculas (NOVOTIPO)
// - Declaração de variável (ex: NUMBER um = 1)
// - Tipos enumerados (enum)
// - Estruturas (struct)
// - Uso de 'int'
// - Uso de 'main()' (implícito, necessário para exemplos funcionais)
// - Uso de '#include' (implícito, necessário para exemplos funcionais com printf)