/*
ASSUNTO PRINCIPAL DETECTADO: Arquivos de Cabeçalho (.h) e a Diretiva #include
Resumo geral do assunto: Arquivos de cabeçalho (.h) são usados em C para modularizar programas grandes, separando as declarações (interfaces) das funções e estruturas de suas implementações. Eles contêm protótipos de funções, definições de tipos (structs, typedefs) e constantes, permitindo que diferentes arquivos de código-fonte (.c) compartilhem essas informações.

Explicação clara e didática: Quando um programa fica muito grande, dividi-lo em módulos (pares .h e .c) melhora a organização, manutenção e o tempo de compilação. O arquivo .h atua como um contrato, dizendo ao compilador o que esperar de uma função sem mostrar como ela faz o trabalho, que está no arquivo .c correspondente.

Contexto sobre o que esse tema significa na Linguagem C: Este é o método padrão de C para alcançar a modularização e reutilização de código. A diretiva '#include' é um comando do pré-processador que insere o conteúdo do arquivo de cabeçalho no arquivo-fonte durante a fase de pré-processamento. A forma de inclusão (<>) ou ("") sinaliza ao pré-processador onde procurar o arquivo.
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Arquivos de Cabeçalho e #include)
// ------------------------------------------------------------

// Modularização: É a prática de dividir um programa grande em arquivos menores e gerenciáveis.
// Arquivos de Cabeçalho (.h): Contêm as DECLARAÇÕES (protótipos) de funções, definições de
// estruturas (structs), enums e macros.
// Arquivos de Implementação (.c): Contêm as IMPLEMENTAÇÕES (o corpo) das funções e o código executável.

// Diretiva #include: É uma diretiva do PRÉ-PROCESSADOR, que, antes da compilação, substitui
// a linha '#include' pelo conteúdo do arquivo de cabeçalho especificado.

// Formas de Inclusão:
// 1. #include <arquivo.h>: Usado para arquivos de cabeçalho da **biblioteca padrão** (como stdio.h).
//    O pré-processador procura em locais predefinidos do sistema (bibliotecas).
// 2. #include "arquivo.h": Usado para arquivos de cabeçalho **próprios/do projeto**.
//    O pré-processador procura primeiro na pasta atual e depois, dependendo do compilador,
//    em caminhos especificados pelo usuário.
// 3. Estrutura de Pastas: Pode-se usar caminhos relativos para bibliotecas internas, como:
//    #include "minhaPasta/meuArquivo.h" 

// Protótipo de Função: É a declaração de uma função que informa ao compilador sobre:
// o tipo de retorno, o nome da função e o tipo dos parâmetros.
// Exemplo: 'int calcularIdade(int ano);' O ponto e vírgula final indica que é apenas uma declaração.

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------

// Função `printf()`: Uma função de entrada/saída (I/O) cuja declaração (protótipo) está
// contida no arquivo de cabeçalho padrão `<stdio.h>`.

// Compilação com Múltiplos Arquivos: Quando um programa é dividido em vários arquivos `.c`,
// todos eles devem ser listados no comando de compilação.
// Exemplo: `gcc -o main main.c calculate_age.c`
// - `gcc`: O compilador C.
// - `-o main`: Especifica que o arquivo de saída executável deve ser chamado 'main'.
// - `main.c` e `calculate_age.c`: Os arquivos de código-fonte a serem compilados e ligados.

// `Makefile`: Para projetos mais complexos com muitos arquivos, é usado um `Makefile` para
// automatizar o processo de compilação, definindo regras e dependências.

#include <stdio.h> // Biblioteca padrão (stdio.h)

// --- Simulação dos arquivos modularizados ---

// Conteúdo de "calcular_idade.h" (Apenas a Declaração/Protótipo)
int calcularIdade(int ano);

// Conteúdo de "calcular_idade.c" (A Implementação)
// int calcularIdade(int ano) {
//   const int ANO_ATUAL = 2022;
//   return ANO_ATUAL - ano;
// }

// Para fins de compilação em arquivo único, incluímos a implementação aqui,
// mas na modularização real, ela estaria em 'calcular_idade.c'.
int calcularIdade(int ano) {
  const int ANO_ATUAL = 2022; // Variável de contexto
  return ANO_ATUAL - ano;
}


int main(void) {
  // Chamamos a função 'calcularIdade', cujo protótipo foi incluído (simulado)
  // por '#include "calcular_idade.h"'
  printf("A idade (anos passados desde 1983) eh: %u\n", calcularIdade(1983));

  // Exemplo de inclusão de cabeçalho próprio (simulação de uso)
  // #include "calcular_idade.h"
  // int main(void) { ... }

  return 0;
}

// Explicação do meu código (dentro de main() e definições)
// `#include <stdio.h>`: Inclui as declarações de funções de I/O, como 'printf()', da biblioteca padrão.
// `int calcularIdade(int ano);`: O protótipo da função (o que estaria no arquivo .h).
// `int calcularIdade(int ano) { ... }`: A definição da função (o que estaria no arquivo .c).
// `const int ANO_ATUAL = 2022;`: Uma constante local dentro da função.
// `printf("%u", calcularIdade(1983));`: Chamada da função que foi declarada via cabeçalho (em um programa real) e cuja implementação está em outro arquivo.
// `%u`: Especificador de formato para imprimir um inteiro sem sinal, embora `%d` também seja comum para `int`.

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Modularização de programas
// - Arquivos de cabeçalho (.h)
// - Arquivos de código-fonte (.c)
// - Protótipo de função (Declaração)
// - Implementação de função (Definição/Corpo)
// - Diretiva do pré-processador '#include'
// - Inclusão de biblioteca padrão: #include <stdio.h>
// - Inclusão de arquivos próprios: #include "meuArquivo.h"
// - Caminhos de inclusão (estrutura de pastas)
// - Compilador 'gcc'
// - Opção de saída '-o' (gcc -o main ...)
// - Compilação com múltiplos arquivos (main.c calculate_age.c)
// - 'Makefile' (para compilação complexa)