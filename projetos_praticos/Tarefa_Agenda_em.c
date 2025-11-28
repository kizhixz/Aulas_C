/*

**Resumo da Tarefa (Agenda em C)**
Criar uma mini agenda utilizando:

* `struct` (nome, telefone, email)
* Vetor dinâmico com `malloc/realloc`
* Funções separadas
* Arquivo texto para salvar/carregar

**Ações obrigatórias do programa:**

1. Adicionar contato
2. Listar contatos
3. Buscar contato por nome
4. Remover contato (por índice ou nome)
5. Salvar em arquivo
6. Carregar do arquivo
7. Sair e liberar memória

**Estrutura necessária:**

* `struct Contato`
* `contato *agenda` (vetor dinâmico)
* `int qtd` (quantidade)
* `int cap` (capacidade, começa em 10)

**Funções que devem existir:**

* adicionarContato(...)
* listarContatos(...)
* buscarContatos(...)
* removerContatoPorIndice(...)
* salvarEmArquivo(...)
* carregarDeArquivo(...)

**Regras gerais:**

* Realocar quando encher
* Verificar erros (malloc, realloc, fopen)
* Validar opções do menu
* Remoção puxa elementos para trás

**Extras opcionais:**

* Ordenar por nome
* Bloquear duplicados
* Versão binária do arquivo

*/