/*
ASSUNTO PRINCIPAL DETECTADO: Funções em C (Estrutura e Invocação)
Resumo geral do assunto.
Funções são sub-rotinas que permitem estruturar o código em blocos nomeados, reutilizáveis e isolados. Cada função possui um nome, um valor de retorno (ou 'void'), argumentos opcionais e um corpo com as instruções a serem executadas. A função 'main()' é o ponto de entrada obrigatório de todo programa C.

Explicação clara e didática.
Funções são essenciais para a modularização, tornando o código mais legível e mantível. Um ponto crucial em C é que as funções devem ser declaradas (ou seu protótipo deve ser fornecido) antes de serem chamadas. A passagem de argumentos é, por padrão, "por valor" (por cópia), o que significa que modificações nos argumentos dentro da função são locais. Para modificar a variável original, é necessário usar ponteiros e a técnica de "passagem por referência".

Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
Em C, a função 'main()' é a única que o compilador e o sistema operacional reconhecem como início da execução. O uso de `void` para o tipo de retorno ou para indicar a ausência de argumentos é uma característica explícita da linguagem. A exigência de declarar funções antes do uso está relacionada à forma como o compilador C processa o código sequencialmente. O conceito de passagem por referência, viabilizado por ponteiros, é fundamental para a performance e manipulação de memória em C. A diretiva `#include <stdio.h>` é necessária para usar funções de I/O como `printf()`.
*/

#include <stdio.h> // Biblioteca necessária para usar printf()

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Funções)
// ------------------------------------------------------------
// Definição: Funções estruturam o código em sub-rotinas nomeadas e reutilizáveis.
// A função `main()`: É o ponto de entrada (início da execução) de todo programa C.
// Aspectos de uma função:
// 1. **Nome**: Usado para invocá-la (chamá-la).
// 2. **Valor de Retorno**: O tipo de dado que a função retorna.
//    - Se nenhum valor for retornado, usa-se a palavra-chave **`void`**.
//    - Tipos comuns: `int`, `float`, `const char *` (para string).
//    - **Restrição**: Uma função só pode retornar **um único** valor.
// 3. **Argumentos/Parâmetros**: Valores opcionais que a função recebe.
//    - Se não houver argumentos, deve-se usar a palavra-chave **`void`** nos parênteses (`fazerAlgo(void)`).
//    - Múltiplos parâmetros são separados por vírgula.
// 4. **Corpo**: O bloco de instruções entre chaves (`{}`) que é executado na invocação.
// Passagem de Parâmetros:
// - **Por Cópia (Por Valor)**: O padrão. O valor do argumento é copiado para o parâmetro local. Modificações internas são **locais** e não afetam a variável original.
// - **Por Referência**: Para modificar a variável original, um **ponteiro** deve ser passado como argumento.
// Regras de Definição:
// - **Ordem de Definição**: A função deve ser **definida ou declarada** (protótipo) **antes** de ser chamada para evitar erros e avisos de "declaração implícita".
// - **Valores Padrão**: C **não** permite definir valores padrão para parâmetros (diferente de C++ ou Arduino).
// Variáveis Locais:
// - Variáveis declaradas dentro do corpo da função são **locais** (visíveis apenas dentro da função).
// - São criadas na invocação e destruídas no encerramento da função.
// **Recursão**: É a capacidade de uma função chamar a si mesma, oferecendo "possibilidades bem peculiares" (útil para problemas recursivos como fatoriais ou travessia de árvores).

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// - Bibliotecas: Uso de `#include <stdio.h>` para `printf()`.
// - Tipos de Dados: Menciona `int`, `float`, `void`, `const char *` (para string).
// - Ponteiros: Menciona que passar um ponteiro como parâmetro permite modificar o valor da variável original (passagem por referência).
// - Variáveis: Menciona a criação e destruição de variáveis no escopo local da função.
// - Compilador: Menciona a necessidade de definir a função antes de usá-la para evitar *warnings* e *errors* de "declaração implícita" e "tipos conflitantes".
// - Protótipos de Função: Menciona a opção de usar protótipos em um arquivo de cabeçalho (header) para resolver problemas de ordenação.

// Protótipo de função para evitar warnings/erros (int fazerAlgo(int, int);)
void fazerAlgo(int valor1, int valor2);
void fazerAlgo_void(void);

// Exemplo 1: Função com Retorno void e Parâmetros
void fazerAlgo(int valor1, int valor2) {
  // Variável local, visível apenas aqui
  int valorEmDobro = valor1 * 2;
  printf("// Exemplo 1: Invocacao com 2 parametros\n");
  printf("Valores recebidos: %d e %d\n", valor1, valor2);
  printf("Valor 1 em dobro (variavel local): %d\n", valorEmDobro);
}
// Explicação do Exemplo 1 (Linha por linha):
// - `void fazerAlgo(int valor1, int valor2) {`: Declaração da função. `void` é o tipo de retorno; `fazerAlgo` é o nome; `int valor1, int valor2` são os parâmetros separados por vírgula.
// - `int valorEmDobro = valor1 * 2;`: Declaração e inicialização de uma **variável local**.
// - `printf(...)`: Executa a instrução no corpo da função.

// Exemplo 2: Função com Retorno void e sem Parâmetros
void fazerAlgo_void(void) {
  printf("// Exemplo 2: Invocacao sem parametros (uso de void)\n");
  printf("Funcao executada com sucesso.\n");
}
// Explicação do Exemplo 2:
// - `void fazerAlgo_void(void) {`: Uso de `void` no lugar dos parâmetros indica explicitamente que a função não recebe argumentos.

// Exemplo 3: Passagem por Cópia (Demonstração do escopo local)
void modificar_local(int a) {
  a = a * 10; // Modificacao local
  printf("Dentro da funcao (passagem por copia): %d\n", a);
}
// Explicação do Exemplo 3:
// - `a = a * 10;`: Altera apenas a cópia do valor, não a variável original.

// Exemplo 4: Passagem por Referência (Usando Ponteiros)
void modificar_referencia(int *ptr_a) {
  *ptr_a = *ptr_a * 10; // Modificacao no valor apontado pelo endereço
  printf("Dentro da funcao (passagem por referencia - novo valor): %d\n", *ptr_a);
}
// Explicação do Exemplo 4:
// - `int *ptr_a`: O parâmetro é um ponteiro para um inteiro.
// - `*ptr_a = ...`: O operador de desreferência modifica o valor na localização de memória original.

int main(void) {
  // Ponto de entrada do programa C
  printf("--- Teste de Funcoes ---\n");
  
  // Invocação do Exemplo 1
  fazerAlgo(3, 4); 
  
  // Invocação do Exemplo 2 (sem argumentos)
  fazerAlgo_void();
  
  // Invocação do Exemplo 3: Passagem por Cópia
  int valor_original = 5;
  printf("\nValor original antes da copia: %d\n", valor_original);
  modificar_local(valor_original); // Passa uma CÓPIA de 5
  printf("Valor original apos a copia: %d (Nao mudou)\n", valor_original);
  
  // Invocação do Exemplo 4: Passagem por Referência
  printf("\nValor original antes da referencia: %d\n", valor_original);
  modificar_referencia(&valor_original); // Passa o ENDEREÇO (&) da variável
  printf("Valor original apos a referencia: %d (Mudou)\n", valor_original); // O valor foi alterado!

  return 0;
}
// Explicação da função main:
// - `int main(void)`: Declaração da função principal. Retorna um inteiro (convencionalmente 0 para sucesso) e não recebe argumentos (`void`).
// - `return 0;`: Retorna o código de saída do programa para o sistema operacional.

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Funções (conceito)
// - Sub-rotinas
// - Nomenclatura
// - Invocação/Chamada
// - Função main()
// - Ponto de entrada
// - Valor de retorno
// - Tipo de retorno void
// - Tipos de retorno (int, float, const char *)
// - Argumentos/Parâmetros
// - Corpo da função (bloco de código, {})
// - Parênteses vazios ou com `void`
// - Múltiplos parâmetros (separados por vírgula)
// - Passagem de Parâmetros **por Cópia** (Por Valor)
// - Modificação de valor local
// - Passagem de **Ponteiro** (Por Referência)
// - Endereço de memória
// - Valor padrão (não permitido em C)
// - Declaração de função (antes da chamada)
// - Aviso/Erro de **declaração implícita**
// - Erro de **tipos conflitantes**
// - Protótipo de função
// - Arquivo de cabeçalho (header)
// - Variáveis locais (criadas e destruídas no escopo)
// - Recursão (função chamando a si mesma)
// - Bibliotecas (`stdio.h`)