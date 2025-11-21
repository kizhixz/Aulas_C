/*
ASSUNTO PRINCIPAL DETECTADO: Arrays (Vetores) em C
Resumo geral do assunto.
Um array é uma coleção de variáveis do mesmo tipo de dado, armazenadas em locais de memória contíguos. Eles permitem armazenar múltiplos valores sob um único nome de variável, acessados por um índice numérico que começa em 0. Em C, arrays têm um tamanho fixo que deve ser especificado no momento da declaração.

Explicação clara e didática.
Arrays são estruturas de dados sequenciais essenciais na Linguagem C para agrupar dados homogêneos (todos do mesmo tipo, como inteiros ou caracteres). A alocação contígua na memória é uma característica importante que permite acesso rápido aos elementos. A manipulação dos arrays é feita através de índices (offset a partir do início), e o nome do array funciona como um ponteiro para o seu primeiro elemento, conectando o conceito de arrays ao de ponteiros.

Contexto sobre o que esse tema significa na Linguagem C (por exemplo, uso de ponteiros, bibliotecas, compilação).
Em C, arrays são arrays estáticos por padrão (tamanho fixo), ao contrário de muitas linguagens de alto nível. Para simular arrays dinâmicos, é necessário usar outras estruturas ou técnicas de alocação de memória (como malloc/free) e ponteiros. O fato de os elementos serem armazenados em sequência (contiguamente) é crucial para otimizar o desempenho e é uma das razões pelas quais o nome do array é, na verdade, um ponteiro. A biblioteca <stdio.h> é usada aqui para fins de demonstração (printf), mas arrays não exigem bibliotecas específicas para sua definição e uso básico.
*/

#include <stdio.h> // Necessário para a função printf()

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL (Arrays)
// ------------------------------------------------------------
// Definição: Um array é uma variável que armazena múltiplos valores.
// Homogeneidade: Todos os valores em um array C devem ser do **mesmo tipo** (ex: int, double).
// Tamanho Fixo: O tamanho do array deve ser **sempre especificado** na definição.
// - C não fornece arrays dinâmicos nativamente (para isso, são necessárias estruturas como listas vinculadas ou alocação dinâmica).
// Inicialização:
// - Pode ser definida no momento da declaração: int nome[tamanho] = { v1, v2, v3, ... };
// - Pode ser atribuída elemento por elemento após a declaração.
// Acesso: É feito usando colchetes [] com o **índice** (número inteiro).
// Índices: Os arrays em C são **base 0**, ou seja, o primeiro elemento é o índice 0.
// - Um array com N itens tem índices de 0 a N-1.
// Armazenamento: Os elementos do array são armazenados em **sequência** (contiguamente) na memória.
// Ponteiros e Array: O **nome da variável do array** (ex: prices) é um **ponteiro** para o primeiro elemento do array (índice 0).
//
// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// - Tipos de Dados: Menciona tipos 'int' e 'double' como exemplos de tipos que podem ser usados em arrays.
// - Constantes: Uma variável constante (const int SIZE) pode ser usada para definir o tamanho do array, tornando o código mais legível e fácil de manter.
// - Laços (`for`): Arrays são frequentemente manipulados e inicializados usando laços, que automatizam o acesso sequencial aos índices.
// - Laços (`for`) e Índices: O laço 'for' (for (int i = 0; i < 5; i++)) é ideal para percorrer um array de 5 elementos (índices 0 a 4).
// - Listas Vinculadas (Estruturas de Dados): Mencionadas como uma alternativa para arrays dinâmicos.
// - Ponteiros: Menciona que o nome do array é um ponteiro para o primeiro elemento e que este assunto será detalhado posteriormente.

// Exemplo 1: Definição, Inicialização e Acesso a um Array
// Demonstra a sintaxe básica de definição e acesso.
void exemplo_basico_array() {
  printf("// Exemplo 1: Definição e Acesso Direto\n");
  
  // Definição e inicialização na mesma linha
  int prices[5] = { 10, 20, 30, 40, 50 }; // Array de 5 inteiros
  
  // Atribuição individual
  prices[0] = 1;
  prices[4] = 5; // O último elemento de um array de 5 é o índice 4
  
  printf("prices[0] tem o valor: %d\n", prices[0]); 
  printf("prices[4] tem o valor: %d\n", prices[4]);
  printf("\n");
}
// Explicação do exemplo 1:
// - int prices[5];: Declara um array chamado 'prices' com capacidade para 5 valores inteiros.
// - prices[0] = 1;: Atribui o valor 1 ao primeiro elemento (índice 0).
// - prices[4] = 5;: Atribui o valor 5 ao último elemento (índice 4).

// Exemplo 2: Usando uma Constante e Inicializando com Laço
// Demonstra a prática de usar constantes e o uso de laço para popular o array.
void exemplo_array_com_laco() {
  printf("// Exemplo 2: Usando Constante e Inicialização com Laço for\n");
  
  const int SIZE = 5; // Definindo o tamanho como uma constante
  int prices[SIZE];   // Usando a constante para o tamanho do array
  
  // Inicialização usando um laço for
  for (int i = 0; i < SIZE; i++) {
    prices[i] = i + 1; // Atribui valores de 1 a 5 (i+1)
  }
  
  // Acesso e exibição de todos os elementos usando um laço for
  printf("Valores do array prices:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("prices[%d] = %d\n", i, prices[i]);
  }
  printf("\n");
}
// Explicação do exemplo 2:
// - const int SIZE = 5;: Define uma constante para o tamanho.
// - for (int i = 0; i < SIZE; i++): O laço itera de 0 até 4 (SIZE-1), cobrindo todos os índices.
// - prices[i] = i + 1;: Acessa o elemento na posição 'i' e atribui o valor de 'i + 1' a ele.

// Exemplo 3: O Nome do Array como Ponteiro (Conceito)
// Demonstra que o nome do array aponta para o endereço do primeiro elemento.
void exemplo_nome_como_ponteiro() {
  printf("// Exemplo 3: O Nome do Array como Ponteiro\n");
  int data[3] = {100, 200, 300};
  
  // O nome do array 'data' é um ponteiro para o primeiro elemento.
  // data == &data[0]
  printf("O valor do primeiro elemento (data[0]): %d\n", data[0]);
  // Para fins de demonstração do conceito: o valor que o nome do array guarda
  // (que é o endereço do primeiro elemento)
  printf("O endereco de memoria de data[0] (%%p): %p\n", (void *)&data[0]);
  printf("O valor do nome do array 'data' (%%p): %p\n", (void *)data);
  // O nome do array e o endereco do primeiro elemento sao os mesmos.
  printf("\n");
}
// Explicação do exemplo 3:
// - int data[3] = {100, 200, 300};: Declara e inicializa o array.
// - (void *)&data[0]: Obtém o endereço de memória do primeiro elemento.
// - (void *)data: O nome do array 'data' (sem colchetes) é implicitamente convertido para o endereço de seu primeiro elemento. Ambos os endereços são idênticos, reforçando o conceito de que o nome do array é um ponteiro para o início da sequência de memória.

int main() {
  exemplo_basico_array();
  exemplo_array_com_laco();
  exemplo_nome_como_ponteiro();
  return 0;
}

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Array (conceito)
// - Tipos de dados (int, double)
// - Homogeneidade de tipos em arrays
// - Definição de array (int prices[5];)
// - Especificação de tamanho
// - Arrays estáticos
// - Arrays dinâmicos (não nativos em C)
// - Estruturas de dados (listas vinculadas)
// - Constantes (const int SIZE)
// - Inicialização na definição ({})
// - Atribuição de valor após definição (prices[0] = 1;)
// - Índices de array (prices[0])
// - Base 0 para índices (0 a N-1)
// - Laços for (para inicialização/manipulação)
// - Variável de laço 'i'
// - Armazenamento sequencial/contíguo
// - Variável array nomeada (prices)
// - Nome do array como ponteiro
// - Ponteiros (conceito relacionado)