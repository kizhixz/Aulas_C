/*
ASSUNTO PRINCIPAL DETECTADO: Introdução à Linguagem C e "Hello, World!"
Resumo geral do assunto.

Este documento apresenta a linguagem de programação C, destacando sua relevância 
histórica e contemporânea, seus recursos de baixo nível, 
a natureza compilada e a ausência de coletor de lixo. 
Explicação clara e didática.

A linguagem C é fundamental no ensino de Ciência da Computação e na indústria, 
sendo a base de sistemas operacionais como o Linux (e, por extensão, o Android) 
e amplamente utilizada em dispositivos embarcados e servidores. Seu ponto forte 
é o controle direto sobre o hardware (linguagem de "nível mais baixo") e a 
eficiência de seus programas compilados.

Contexto sobre o que esse tema significa na Linguagem C (por exemplo, 
uso de ponteiros, bibliotecas, compilação).
O texto introduz conceitos centrais em C, como o uso obrigatório 
de bibliotecas para funcionalidades (ex: stdio.h), o ponto de entrada 
do programa (função main()), e o processo essencial de compilação 
usando o compilador GCC. O programa "Hello, World!" é o exemplo canônico 
para demonstrar essa estrutura básica.
*/

// ------------------------------------------------------------
// TEORIA — ASSUNTO PRINCIPAL
// ------------------------------------------------------------
// O C é uma das linguagens mais conhecidas e serve como referência em cursos de ciência da computação.
// Ela é usada na indústria, não sendo apenas uma "linguagem acadêmica".
// A linguagem C é classificada como de "nível mais baixo" (low-level) em comparação com linguagens de alto nível (Python, Java).
// Isso significa que ela oferece mais controle sobre as operações do hardware e gerenciamento de memória.
// O C é amplamente utilizado em:
// - Dispositivos embarcados (como Arduino)
// - Servidores de Internet (muitos rodam Linux)
// - Desenvolvimento do kernel do Linux e, consequentemente, sistemas Android.
//
// HISTÓRIA E PORTABILIDADE:
// Quando foi criado, o C era considerado de "alto nível" por ser portável entre diferentes máquinas, algo que não era comum na época.
// A portabilidade era facilitada por um compilador simples de implementar em diversas arquiteturas.
//
// NATUREZA COMPILADA:
// C é uma **linguagem compilada**, assim como Go, Java, Swift e Rust.
// O processo de compilação traduz o código-fonte (.c) diretamente para um **arquivo binário executável** (.o ou .exe) que pode ser distribuído e executado pelo sistema operacional.
// Linguagens interpretadas (Python, JavaScript, Ruby) precisam de um "interpretador" em tempo de execução.
//
// GERENCIAMENTO DE MEMÓRIA:
// O C **não tem um coletor de lixo** (Garbage Collector).
// Isso impõe ao programador a responsabilidade de realizar o **gerenciamento manual da memória**, o que exige atenção, mas resulta em programas altamente otimizados e eficientes para ambientes com recursos limitados (como dispositivos embarcados).
//
// O PRIMEIRO PROGRAMA EM C - "HELLO, WORLD!"
// O programa utiliza a biblioteca padrão de entrada e saída (`stdio.h`) e a função principal (`main`).

// ------------------------------------------------------------
// TEORIA — CONTEÚDO RELACIONADO PRESENTE NO TEXTO
// ------------------------------------------------------------
// Linguagens Mencionadas: Pascal, Python, Java, Node.js, Ruby, JavaScript, Go, Swift, Rust.
// Sistemas Operacionais Mencionados: Linux, Windows, macOS, Android.
//
// BIBLIOTECAS:
// O C é pequeno em seu núcleo, e a maior parte da funcionalidade é fornecida por meio de **bibliotecas**.
// Algumas bibliotecas são padrão (como a `stdio`), integradas ao compilador. Outras são criadas por terceiros.
//
// STDIN / STDOUT (stdio):
// Significa **ST**an**D**ard **I**nput/**O**utput (Entrada e Saída Padrão).
// É a biblioteca padrão que fornece funções essenciais de entrada e saída de dados, como a `printf()`.
//
// FUNÇÕES:
// Uma função é uma rotina de código que **recebe argumentos** (zero ou mais) e **retorna um único valor** (ou `void` se não retornar nada).
// - **`main()`:** É o **ponto de entrada obrigatório** de qualquer programa C. O sistema operacional começa a execução a partir dela.
// - **Estrutura de uma função:** `tipo_retorno nome_funcao(argumentos) { corpo_da_funcao }`
// - **`int main(void)`:** Indica que a função `main` retorna um inteiro (`int`) e não recebe argumentos (`void`).
// - **Corpo da função:** O código entre chaves (`{...}`).
// - **`printf()`:** É uma função de saída fornecida pela `stdio.h` que envia dados para a tela (saída padrão).
// - **Invocação de função:** O ato de chamar a função, como `printf("Hello, World!");`. O ponto e vírgula (`;`) é um terminador de instrução.
// - **Definição de `printf`:** `int printf(const char *format, ...);` (Não é essencial entender sua estrutura completa agora, mas mostra que ela retorna um `int`, recebe uma string de formato e argumentos variáveis (`...`)).
//
// COMPILAÇÃO E EXECUÇÃO (GCC):
// **GCC** (GNU Compiler Collection) é um compilador comum para C e C++.
// **Comando de Compilação:** `gcc hello.c -o hello`
// - `hello.c`: Arquivo fonte de entrada.
// - `-o hello`: Opção que especifica o nome do arquivo de saída (o executável).
// **Comando de Execução:** `./hello`
// - O `./` (diretório atual) é necessário para que o terminal saiba onde procurar o executável.
// **Otimização:** Programas C são pequenos (o exemplo tem 12KB) devido à sua alta otimização.

// ------------------------------------------------------------
// EXEMPLOS
// ------------------------------------------------------------

// O programa canônico "Hello, World!"
#include <stdio.h> // Diretiva de pré-processador para incluir a biblioteca de entrada/saída padrão

int main(void) { // Definição da função principal
    printf("Hello, World!\n"); // Instrução para imprimir a string na tela, \n adiciona uma nova linha
    return 0; // Retorna 0 (sucesso) ao sistema operacional, pois main é definida para retornar um 'int'
}

// Explicação do exemplo:
// - A linha `#include <stdio.h>` torna a função `printf` disponível para uso.
// - `int main(void)` é a assinatura da função principal que será executada. O `void` indica que ela não espera argumentos.
// - `printf("Hello, World!\n");` é a chamada de função que realiza a saída de texto.
// - `return 0;` indica que o programa terminou com sucesso.

// ------------------------------------------------------------
// EXPLICAÇÃO DO MEU CÓDIGO LINHA POR LINHA
// ------------------------------------------------------------

#include <stdio.h> // Diretiva de pré-processador para incluir a biblioteca "stdio.h" (Standard Input Output)
int main(void) { // Início da definição da função principal "main". Retorna um inteiro (int) e não recebe argumentos (void).
    printf("Hello, World!"); // Chamada da função printf(), que pertence à biblioteca stdio, para imprimir a string "Hello, World!".
} // Fim da definição da função main().

// ------------------------------------------------------------
// RESUMO TÉCNICO (TUDO QUE APARECEU NO TEXTO)
// ------------------------------------------------------------
// - Linguagem C
// - Linguagem de programação compilada (Go, Java, Swift, Rust)
// - Linguagem de programação interpretada (Python, Ruby, JavaScript)
// - Linguagem de nível mais baixo (low-level)
// - Linguagem de nível mais alto (high-level)
// - Gerenciamento de memória
// - Coletor de Lixo (Garbage Collector)
// - Dispositivos embarcados (Arduino)
// - Servidores de Internet / Kernel do Linux / Android
// - Compilador (GCC)
// - Arquivo binário
// - Código-fonte
// - Portabilidade
// - Biblioteca (stdio - Standard Input Output)
// - Diretiva `#include`
// - Função (`main()`, `printf()`)
// - Argumentos de função
// - Tipo de retorno (`int`, `void`)
// - Palavras-chave (`int`, `void`, `const char *`, `...`)
// - `const char *format, ...` (Definição da função printf)
// - Ponto de entrada do programa
// - String (envolvida por aspas duplas)
// - Terminal (linha de comando)
// - Editor de texto (nano)
// - Comando `gcc`
// - Comando `./hello`
// - Comando `ls -al hello`
// - Extensão de arquivo `.c`