/*---------------- File: HashABP.h  ------------------------+
|Arvore Binaria de Pesquisa (ABP)                       |
|					      		                        |
|					      		                        |
| Implementado por Guilherme C. Pena em 12/10/2023      |
| E modificado por                                      |
| Andre Lourenconi Freitas                              |
|Joao Pedro Machado dos Santos                          |
|Yuri Codreanski Collinett Guimarães                    |
+-------------------------------------------------------+ */

#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABP.h"

typedef struct{
    ABP *tabela[26];
    int tam, qtd;
}Hash;


Hash* criaHash(){
    Hash* h;
    h = (Hash*) malloc (sizeof(Hash));
    if(h != NULL){
        h->tam = 26; h->qtd = 0;
        if(h->tabela == NULL) return NULL;
        int i;
        for(i = 0; i<26; i++)
            h->tabela[i] = criaABP();
    }
    return h;
}


void destroiHash(Hash *h){
    if(h != NULL){
        int i;
        for(i = 0; i<h->tam; i++)
            if(h->tabela[i] != NULL)
                destroiABP(h->tabela[i]);
        free(h->tabela);
        free(h);
    }
}


int chaveMultiplicacao(int chave, int tam){
    float A = 0.6180339887; //constante: 0 < A < 1
    float val = chave * A;
    val = val - (int) val;
    return (int) (tam * val);
}

int chaveDobra(int chave, int tam){
    int pos, n_bits = 30;
    
    int p = 1;
    int r = p << n_bits;
    while((chave & r) != r){ n_bits--; r = p << n_bits; }

    n_bits++;
    pos = chave;
    while(pos > tam){
        int metade_bits = n_bits/2;
        int parte1 = pos >> metade_bits;
        parte1 = parte1 << metade_bits;
        int parte2 = pos ^ parte1;
        parte1 = pos >> metade_bits;
        pos = parte1 ^ parte2;
        n_bits = n_bits/2;
    }
    return pos;
}

int valorString(char *str){
    int i, valor = 1;
    int tam = strlen(str);
    for(i=0; i<tam; i++)
        valor = 31*valor + (i+1)*((int) str[i]);
    return valor;
}


void imprimeHash(Hash *h){
    if(h == NULL) return;
    int i;
    for(i=0; i<h->tam; i++){
        printf("%d: ", i);
        if(h->tabela[i] == NULL) printf("NULL\n");
        else imprime(h->tabela[i]);
    }
}

#endif