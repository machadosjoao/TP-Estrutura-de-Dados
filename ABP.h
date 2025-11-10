/*---------------- File: ABP.h  ------------------------+
|Arvore Binaria de Pesquisa (ABP)                       |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 12/10/2023      |
| E modificado por                                      |
| Andre Lourenconi Freitas                              |
|Joao Pedro Machado dos Santos                          |
|Yuri Codreanski Collinett Guimarães                    |
+-------------------------------------------------------+ */

#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO{
    int info;
    char palavra[50];
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* ABP;

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

ABP* criaABP(){
    ABP* raiz = (ABP*) malloc (sizeof(ABP));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}


int insereRec(NO** raiz, int elem, char palavra[50]){
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        novo->info = elem;
        strcpy(novo->palavra, palavra);
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo;
    }else{
        if(strcmp((*raiz)->palavra, palavra)==0){
            printf("Elemento Existente!\n"); 
            return 0;
        }
        if(strcmp((*raiz)->palavra, palavra)>0)
            return insereRec(&(*raiz)->esq, elem, palavra);
        else if(strcmp((*raiz)->palavra, palavra)<0)
            return insereRec(&(*raiz)->dir, elem, palavra);
    }
    return 1;
}



int insereElem(ABP* raiz, int elem, char palavra[50]){
    if(raiz == NULL) return 0;
    return insereRec(raiz, elem, palavra);
    //return insereIte(raiz, elem);
}

NO* pesquisaRec(NO** raiz, char* elem){
    if(*raiz == NULL) return NULL;
    if(strcmp((*raiz)->palavra, elem)==0) return *raiz;
    if(strcmp((*raiz)->palavra, elem)>0)
        return pesquisaRec(&(*raiz)->esq, elem);
    else 
        return pesquisaRec(&(*raiz)->dir, elem);
}




void em_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1);
        printf("[%s, %d] ", raiz->palavra,nivel);
        em_ordem(raiz->dir, nivel+1);
    }
}

void pre_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        printf("[%d, %d] ", raiz->info,nivel);
        pre_ordem(raiz->esq, nivel+1);
        pre_ordem(raiz->dir, nivel+1);
    }
}

void pos_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        pos_ordem(raiz->esq, nivel+1);
        pos_ordem(raiz->dir, nivel+1);
        printf("[%d, %d] ", raiz->info,nivel);
    }
}

void imprime(ABP* raiz){
    if(raiz == NULL) return;
    if(estaVazia(raiz)){
        printf("Arvore Vazia!\n");
        return;
    }
    printf("\nEm Ordem: "); em_ordem(*raiz, 0);
    printf("\n");
}


#endif