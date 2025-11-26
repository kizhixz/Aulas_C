/*
Uma boa questão complexa em C que usa “todo o básico” é implementar uma mini agenda (lista de contatos) usando structs, ponteiros, arrays, funções e arquivos.
Enunciado da questão

Implemente em C um programa de “Agenda de Contatos” com menu interativo, usando:

    struct para representar um contato (nome, telefone, e-mail).

​

Um array dinâmico de contatos (alocado com malloc/realloc).

​

Funções separadas para: adicionar, listar, buscar por nome, remover contato e salvar/carregar em arquivo.

​

Manipulação de arquivos em modo texto para persistir a agenda em disco.

    ​

Regras:

    Defina a struct:

    Campos sugeridos:

        char nome;

        char telefone;

        ​

        char email;

    Use um ponteiro para struct:

    contato *agenda; // vetor dinâmico de contatos.

​

Um int qtd para quantidade atual de contatos.

Um int cap para capacidade atual do vetor (comece, por exemplo, em 10 e use realloc quando precisar aumentar).

    ​

    Implemente um menu em loop:

    1 – Adicionar contato

    2 – Listar contatos

    3 – Buscar contato por nome (exibir todos que contenham o texto buscado)

    4 – Remover contato por índice ou nome

    5 – Salvar agenda em arquivo (ex: “agenda.txt”)

    6 – Carregar agenda do arquivo (substituindo a atual)

    0 – Sair (liberando memória com free).

    ​

    Requisitos de funções (cada uma em função separada):

    void adicionarContato(contato **agenda, int *qtd, int *cap);

        Lê dados com scanf, aumenta o vetor com realloc se *qtd == *cap.

    ​

void listarContatos(contato *agenda, int qtd);

int buscarContatos(contato *agenda, int qtd, const char *texto);

    Percorre o vetor e mostra contatos cujo nome contém o texto (use strstr).

    ​

int removerContatoPorIndice(contato *agenda, int *qtd, int indice);

    Para remover, “puxa” os elementos à frente uma posição para trás.

    ​

void salvarEmArquivo(contato *agenda, int qtd, const char *nomeArquivo);

    Usa fopen, fprintf, fclose.

    ​

int carregarDeArquivo(contato **agenda, int *qtd, int *cap, const char *nomeArquivo);

    Usa fopen, fscanf/fgets, e realoca o vetor conforme lê.

        ​

    Tratamento de erros:

    Verificar se fopen retornou NULL.

​

Verificar se malloc/realloc retornou NULL.

​

Validar opção do menu e índice na remoção.

    ​

    Desafios extras (se quiser deixar ainda mais complexa):

    Ordenar a agenda por nome usando qsort e uma função de comparação.

​

Impedir inserção de contatos com mesmo nome e telefone (verificar antes de adicionar).

​

Salvar em arquivo binário além do texto (ex: “agenda.dat”) usando fwrite/fread.

    ​

Se quiser, na próxima mensagem posso escrever o esqueleto do código em C (assinaturas das funções e main com o menu) para você preencher.




*/