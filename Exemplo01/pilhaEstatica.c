#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int* vetor; //representa a pilha propriamente
    int capacidade; //capacidade da pilha
    int topo; //ultimo elemento da fila
} Pilha;

Pilha* criar(int capacidade){ //assinatura da pilha
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha -> vetor = malloc(sizeof(int) * capacidade);
    pilha -> topo = 0;
    pilha -> capacidade = capacidade;

    return pilha;
}

int vazia(Pilha* pilha){
    return pilha -> topo == 0;
}

int cheia(Pilha* pilha){
    return pilha -> topo == pilha -> capacidade;
}

void empilhar(Pilha* pilha, int valor){
    if(!(cheia(pilha))){
        pilha -> vetor[pilha -> topo] = valor;
        pilha -> topo++;
    } else {
        printf("Pilha cheia!");
        exit(0);
    }
}

int desempilhar(Pilha* pilha){
    if(!vazia(pilha)){
        return pilha -> vetor[--pilha -> topo]; //remove o ultimo elemento e decrementa o topo

    } else {
        printf("Pilha vazia!");
        exit(0);
    }
}

int espiar(Pilha* pilha){
    if(!vazia(pilha)){
        return pilha -> vetor[pilha->topo -1];
    } else {
        printf("Pilha vazia!");
        exit(0);
    }
}

int main(){
    int n = 10;

    Pilha *pilha = criar(n);

    printf("Empilhando: ");

    for(int i = 1; i <= n; i++){
        empilhar(pilha, i);
        printf("%d", espiar(pilha));
    }

    printf("Desempilhando: ");

    while (!vazia(pilha)){
        printf("%d", desempilhar(pilha));
    }
    
}