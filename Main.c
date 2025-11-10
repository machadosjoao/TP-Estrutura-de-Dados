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

#include <stdio.h>
#include "HashAbp.h"



int main(){
    Hash *H;
    H = criaHash();
    int i, n, k, j, u;
    char c;
    char pal[50];
    scanf("%d", &n);
    c= getchar();
    for(int j=0; j<n; j++){
        scanf("%s %d",pal, &u);
        k=pal[0]-'a';
        insereElem(H->tabela[k],u,pal);
    }
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        NO* aux;
        scanf("%s", pal);
        k=pal[0]-'a';
        aux = pesquisaRec(H->tabela[k], pal);
        if(aux!=NULL){
            printf("Palavra %s encontrada, valor:%d\n", pal, aux->info);
        }else{
            printf("Palavra nao encontrada!\n");
        }
    }
    // imprimeHash(H);
    return 0;
}
