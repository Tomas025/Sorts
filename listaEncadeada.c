#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *nome;
}ALUNO;

typedef struct {
    ALUNO aluno;
    struct NODE *prox;
}NODE;

typedef struct {
    int numElementos;
    NODE *inicial;
}FILA_ENCADEADA;

typedef 

void init(FILA_ENCADEADA *fila) {
    fila->numElementos = 0;
    fila->inicial = NULL;
}

ALUNO buscarNaLista(FILA_ENCADEADA *fila, int queroEncontrar) {
    ALUNO *copia;
    copia = fila->inicial;
    while (copia != NULL) {
        if(copia->id == queroEncontrar-1) {
            return *copia;
        }
        copia = copia->prox;
    }
    
}

void adicionaAlunoNaLista(LISTA_ENCADEADA *lista, int idAluno, char *nomeAluno) {
    ALUNO_INICIAL *temp;
    temp->id = idAluno;
    temp->nome = nomeAluno;
    temp->prox = NULL;
    if(lista->numElementos == 0) {
        lista->listaAlunos = temp;
        lista->numElementos++;
    }
    while (lista->listaAlunos->prox != NULL) {
        lista->listaAlunos = lista->listaAlunos->prox;
        if(lista->listaAlunos->prox == NULL) {
            lista->listaAlunos->prox = temp;
            lista->numElementos++;
        }   
    } 
}

void removeAlunoPorId(LISTA_ENCADEADA *lista, int idAluno) {
    lista->numElementos--;
}

void imprimirLista(LISTA_ENCADEADA *lista) {
    if(lista->numElementos == 0) {
        printf("\nLista Vazia");
    } else {
        printf("\nId: %i    ", lista->listaAlunos->id);
        printf("Nome: %s", lista->listaAlunos->nome);
        while (lista->listaAlunos->prox != NULL) {
            lista->listaAlunos = lista->listaAlunos->prox;
            printf("\nId: %i", lista->listaAlunos->id);
            printf("%s", lista->listaAlunos->nome);
        }
    }
}

int main() {

    LISTA_ENCADEADA teste;

    init(&teste);
    imprimirLista(&teste);
    adicionaAlunoNaLista(&teste, 0, "Tomas");
    imprimirLista(&teste);
    adicionaAlunoNaLista(&teste, 1, "David");
    imprimirLista(&teste);
    buscarNaLista(&teste, 0);

    return 0;
}