    #include <stdio.h>
    #include <string.h>

    // Definição da estrutura Aluno
    typedef struct {
    char nome[20];
    float nota;
    char status; // 'A' para ativo, 'C' para cancelado
    } Aluno;

    // Definição do tipo ListaChamada
    typedef struct {
    Aluno alunos[40];
    int totalAlunos;
    } ListaChamada;

        // Função para incluir um aluno na lista de chamada
        void incluirAluno(ListaChamada *lista, Aluno aluno) {
        if (lista->totalAlunos < 40) {
        lista->alunos[lista->totalAlunos] = aluno;
        lista->totalAlunos++;
        } else {
        printf("A lista de chamada está cheia, não é possível adicionar mais alunos.\n");  
         }
        }

// Função para excluir um aluno da lista de chamada
void excluirAluno(ListaChamada *lista, char nome[]) {
 int i, encontrado = 0;
 for (i = 0; i < lista->totalAlunos; i++) {
    if (strcmp(lista->alunos[i].nome, nome) == 0) {
     encontrado = 1;
 break;
}
}
    if (encontrado) {
    for (; i < lista->totalAlunos - 1; i++) {
        lista->alunos[i] = lista->alunos[i + 1];
}
     lista->totalAlunos--;
} else {
     printf("Aluno não encontrado na lista de chamada.\n");
}
}

// Função para ordenar a lista por nota decrescente
void ordenarPorNota(ListaChamada *lista) {
 int i, j;
 Aluno temp;
 for (i = 0; i < lista->totalAlunos - 1; i++) {
 for (j = i + 1; j < lista->totalAlunos; j++) {
 if (lista->alunos[i].nota < lista->alunos[j].nota) {
 temp = lista->alunos[i];
 lista->alunos[i] = lista->alunos[j];
 lista->alunos[j] = temp;
}
}
}
}

// Função para apresentar a relação total de alunos e de alunos com matrícula ativa
void mostrarLista(ListaChamada lista) {
 printf("Relação total de alunos:\n");
 for (int i = 0; i < lista.totalAlunos; i++) {
 printf("%s\t%.2f\t%c\n", lista.alunos[i].nome, lista.alunos[i].nota, lista.alunos[i].status);
}
 printf("\nAlunos com matrícula ativa:\n");
 for (int i = 0; i < lista.totalAlunos; i++) {
 if (lista.alunos[i].status == 'A') {
 printf("%s\t%.2f\n", lista.alunos[i].nome, lista.alunos[i].nota);
}
}

int main() {
 ListaChamada lista;
 lista.totalAlunos = 0;
 Aluno aluno1 = {"Joao", 8.5, 'A'};
 Aluno aluno2 = {"Maria", 7.8, 'A'};
 Aluno aluno3 = {"Pedro", 6.9, 'A'};

 incluirAluno(&lista, aluno1);
 incluirAluno(&lista, aluno2);
incluirAluno(&lista, aluno3);
    printf("Lista de chamada antes de ordenar por nota:\n");
 mostrarLista(lista);

ordenarPorNota(&lista);

printf("\nLista de chamada depois de ordenar por nota:\n");
 mostrarLista(lista);

 excluirAluno(&lista, "Maria");

 printf("\nLista de chamada após excluir Maria:\n");
 mostrarLista(lista);

 return 0;
}
