#include <stdio.h>
#include <stdlib.h>
 
typedef int TIPO_IDENTIFICADOR;
 
typedef struct{
    TIPO_IDENTIFICADOR identificador;
    char *nome;
    char *matricula;
    int idade;
    int periodo;
    int curso;
}REGISTRO_ALUNO;
 
 
typedef struct {
    int dia;
    int mes;
    int ano;
    int qdtAlunos;
    int ppv;
    int posicaoInicial;
    REGISTRO_ALUNO *alunos;
}FILA_DO_DIA;
 
typedef struct{
    int qtdFilas;
    FILA_DO_DIA *filas;
}COLECAO_FILAS;
 
const char *cursos[] = {"informatica", "agroindutria", "agropecuaria", "engenharia de software", "musica"};
 
void iniciarFilaDoDia(FILA_DO_DIA *fd, int n){
    int dia, mes, ano;
    printf("Informe o dia\n");
    scanf("%i", &dia);
    printf("informe o mes\n");
    scanf("%i", &mes);
    printf("informe o ano\n");
    scanf("%i", &ano);
 
    fd->dia = dia;
    fd->mes = mes;
    fd->ano = ano;
    fd->ppv=0;
    fd->posicaoInicial = 0;
    fd->qdtAlunos = n;
}
 
void iniciarColecaoFilas(COLECAO_FILAS *cf){
    cf->qtdFilas = 1;
    //printf("iniciou");
}
 
 
REGISTRO_ALUNO criarAluno(){
    char *nome, *matricula;
    int idade, periodo, curso;
    REGISTRO_ALUNO aluno;
 
    printf("informe o nome do aluno\n");
    scanf("%s", nome);
    printf("informe o a matricula do aluno\n");
    scanf("%s", matricula);
    printf("informe a idade do aluno\n");
    scanf("%i", &idade);
    printf("Informe o periodo do aluno\n");
    scanf("%i", &periodo);
    printf("Informe o curso do aluno\n");
    scanf("%i", &curso);
 
    aluno.nome = nome;
    aluno.matricula = matricula;
    aluno.idade = idade;
    aluno.periodo = periodo;
    aluno.curso = curso;
 
    return aluno;
}
 
void adicionarNaFila(FILA_DO_DIA *fd){
    int qtdAlunos = fd->qdtAlunos;
    int i;
 
    for(i=0; i<qtdAlunos; i++){
        REGISTRO_ALUNO aluno = criarAluno();
        fd->alunos[i] = aluno;
        printf("%s\n", fd->alunos[i].nome);
        fd->ppv++;
    }
}
 
void removeAluno(FILA_DO_DIA *fd){
    fd->ppv = fd->ppv - 1;
}
 
void limparFilaDoDia(FILA_DO_DIA *fd){
    fd->ppv = 0;
}
 
void popColecaoFilas(COLECAO_FILAS *cf){
    cf->qtdFilas = cf->qtdFilas - 1;
}
 
void clearColecaoFilas(COLECAO_FILAS *cf){
    cf->qtdFilas = 0;
}
 
void serchFilaDoDia(COLECAO_FILAS *cf){
    int diaSearch, mesSearch, anoSearch;
    int i;

    printf("Informe o ano da fila que você deseja procurar na coleção de filas\n");
    scanf("%i", &anoSearch);
    
    printf("Agora informe o mes\n");
    scanf("%i", &mesSearch);
    
    printf("E agora o ano\n");
    scanf("%i", &diaSearch);

    for(i = 0; i < cf->qtdFilas; i++){
        if (cf->filas[i].ano == anoSearch) {
            if (cf->filas[i].mes == mesSearch) {
                if (cf->filas[i].dia == diaSearch) {
                    
                }
            }
        }
    }
}
 
 
int main(){
 
    int n = 5;
    FILA_DO_DIA fila;
    COLECAO_FILAS colecao;
 
 
    iniciarFilaDoDia(&fila, n);
    iniciarColecaoFilas(&colecao);
 
    adicionarNaFila(&fila);
 
 
    return 0;
}
 

