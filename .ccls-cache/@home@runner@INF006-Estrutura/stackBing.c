/*
Explicação
Um algoritmo de pilha sem usar lista encadeada é uma forma de implementar uma estrutura de dados que segue o princípio de LIFO (último a entrar, primeiro a sair). Uma pilha pode ser implementada usando um arranjo (vetor) ou uma estrutura encadeada, mas neste caso vamos usar um arranjo.

A ideia é ter um arranjo que armazene os elementos da pilha e uma variável que indique o índice do topo da pilha. Para inserir um elemento na pilha, usamos o método push, que adiciona o elemento no final do arranjo e incrementa o índice do topo. Para remover um elemento da pilha, usamos o método pop, que retorna o elemento no final do arranjo e decrementa o índice do topo. Para verificar se a pilha está vazia, usamos o método isEmpty, que compara o índice do topo com -1. Para verificar o tamanho da pilha, usamos o método size, que retorna o índice do topo mais um. Para ver o elemento no topo da pilha sem removê-lo, usamos o método peek, que retorna o elemento no final do arranjo.

A seguir, mostramos um exemplo de código em Java que implementa uma pilha usando um arranjo:

public class Pilha {
  private int[] arranjo; // arranjo que armazena os elementos da pilha
  private int topo; // índice do topo da pilha

  public Pilha(int capacidade) {
    // construtor da classe Pilha
    // recebe a capacidade máxima da pilha como parâmetro
    arranjo = new int[capacidade]; // cria um arranjo com a capacidade especificada
    topo = -1; // inicializa o topo com -1, indicando que a pilha está vazia
  }

  public boolean isEmpty() {
    // método que verifica se a pilha está vazia
    return topo == -1; // retorna verdadeiro se o topo for igual a -1
  }

  public int size() {
    // método que retorna o tamanho da pilha
    return topo + 1; // retorna o índice do topo mais um
  }

  public int peek() {
    // método que retorna o elemento no topo da pilha sem removê-lo
    if (isEmpty()) { // verifica se a pilha está vazia
      throw new RuntimeException("Pilha vazia!"); // lança uma exceção
    }
    return arranjo[topo]; // retorna o elemento no final do arranjo
  }

  public void push(int elemento) {
    // método que insere um elemento na pilha
    if (topo == arranjo.length - 1) { // verifica se a pilha está cheia
      throw new RuntimeException("Pilha cheia!"); // lança uma exceção
    }
    topo++; // incrementa o índice do topo
    arranjo[topo] = elemento; // adiciona o elemento no final do arranjo
  }

  public int pop() {
    // método que remove e retorna o elemento no topo da pilha
    if (isEmpty()) { // verifica se a pilha está vazia
      throw new RuntimeException("Pilha vazia!"); // lança uma exceção
    }
    int elemento = arranjo[topo]; // guarda o elemento no final do arranjo em uma variável
    topo--; // decrementa o índice do topo
    return elemento; // retorna o elemento removido
  }
}

Para implementar uma pilha em linguagem C usando um arranjo, você pode seguir os mesmos passos que mostramos no exemplo anterior em Java, mas adaptando a sintaxe para C. Por exemplo, você pode usar uma estrutura para representar a pilha, com um arranjo de inteiros e uma variável que indica o índice do topo. Você também pode definir constantes para a capacidade máxima da pilha e para indicar se ela está vazia ou cheia. As funções de serviço da pilha são semelhantes às de Java, mas você precisa passar o endereço da pilha como parâmetro, usando o operador &. Veja um possível código em C:
*/


#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 10 // capacidade máxima da pilha
#define VAZIA -1 // valor que indica que a pilha está vazia
#define CHEIA CAPACIDADE - 1 // valor que indica que a pilha está cheia

// estrutura que representa a pilha
typedef struct {
  int arranjo[CAPACIDADE]; // arranjo que armazena os elementos da pilha
  int topo; // índice do topo da pilha
} Pilha;

// função que inicializa a pilha
void inicializar_pilha(Pilha *p) {
  p->topo = VAZIA; // define o topo como -1, indicando que a pilha está vazia
}

// função que verifica se a pilha está vazia
int pilha_vazia(Pilha *p) {
  return p->topo == VAZIA; // retorna verdadeiro se o topo for igual a -1
}

// função que verifica se a pilha está cheia
int pilha_cheia(Pilha *p) {
  return p->topo == CHEIA; // retorna verdadeiro se o topo for igual a capacidade - 1
}

// função que retorna o tamanho da pilha
int tamanho_pilha(Pilha *p) {
  return p->topo + 1; // retorna o índice do topo mais um
}

// função que retorna o elemento no topo da pilha sem removê-lo
int consultar_topo(Pilha *p) {
  if (pilha_vazia(p)) { // verifica se a pilha está vazia
    printf("Pilha vazia!\n"); // imprime uma mensagem de erro
    exit(1); // encerra o programa
  }
  return p->arranjo[p->topo]; // retorna o elemento no final do arranjo
}

// função que insere um elemento na pilha
void empilhar(Pilha *p, int elemento) {
  if (pilha_cheia(p)) { // verifica se a pilha está cheia
    printf("Pilha cheia!\n"); // imprime uma mensagem de erro
    exit(1); // encerra o programa
  }
  p->topo++; // incrementa o índice do topo
  p->arranjo[p->topo] = elemento; // adiciona o elemento no final do arranjo
}

// função que remove e retorna o elemento no topo da pilha
int desempilhar(Pilha *p) {
  if (pilha_vazia(p)) { // verifica se a pilha está vazia
    printf("Pilha vazia!\n"); // imprime uma mensagem de erro
    exit(1); // encerra o programa
  }
  int elemento = p->arranjo[p->topo]; // guarda o elemento no final do arranjo em uma variável
  p->topo--; // decrementa o índice do topo
  return elemento; // retorna o elemento removido
}

// função principal para testar a implementação da pilha em C
int main() {
  Pilha p; // cria uma pilha chamada "p"
  inicializar_pilha(&p); // inicializa a pilha "p"

  empilhar(&p, 10); // insere o elemento 10 na pilha "p"
  empilhar(&p, 20); // insere o elemento 20 na pilha "p"

  printf("Tamanho da pilha: %d\n", tamanho_pilha(&p)); // imprime o tamanho da pilha "p"

  printf("Elemento no topo: %d\n", consultar_topo(&p)); // imprime o elemento no topo da pilha "p"

  printf("Elemento removido: %d\n", desempilhar(&p)); // imprime e remove o elemento no topo da pilha "p"

  printf("Elemento no topo: %d\n", consultar_topo(&p)); // imprime o elemento no topo da pilha "p"

  return 0; // encerra o programa com sucesso
}
