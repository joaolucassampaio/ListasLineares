#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	//Em C, uma estrutura (struct) é uma coleção de variáveis referenciadas por um nome, fornecendo uma maneira conveniente de se ter
	//informações relacionadas agrupadas.
	
	//no é o identificador (tag) da struct
	//struct é um tipo de dado. Ou seja, nesse ponto do código nenhuma variável foi declarada. Apenas a forma do dos dados foi definida.
	struct no{
		int dado; //Este membro armazena o dado que o nó contém. Neste caso, é um número inteiro (int).
		struct no *prox; //Este membro é um ponteiro para outro nó da lista. Ele aponta para o próximo nó na sequência.
	};
	//Declarando três ponteiros para a struct no
	struct no *lista, *p, *q;
	//Declarando três variáveis inteiras que serão usadas para diferentes propósitos dentro do programa.
	int sn, cont, pos;
	//Define o ponteiro lista como NULL. Isso geralmente é feito para indicar que a lista encadeada está vazia.
	lista = NULL;
	cont = 0;
	
	//Função que contém o menu de capturar a escolha do usuário
	int menu() {
		int escolha;
	    printf("\nBem-vindo(a) ao Sistema de Lista Lineares!\n\n");
	    printf("Em que posso ajudar hoje?\n");
	    printf("1. Fazer uma insercao a esquerda;\n");
	    printf("2. Fazer uma insercao a direita;\n");
	    printf("3. Fazer uma insercao intermediaria;\n");
	    printf("4. Encerrar programa;\n");
	    printf("Escolha uma opcao: ");
	    scanf("%d", &escolha); // Captura a escolha do usuário
	    return escolha;
	}
	
	void limparConsole() {
		system("cls");
	}
	
	//Função para inserção à esquerda
	void inserirEsquerda(int valor){
		struct no *novoNo = (struct no *)malloc(sizeof(struct no));
        novoNo->dado = valor;
        novoNo->prox = lista;
        lista = novoNo;
        printf("\nInsercao a esquerda realizada com sucesso.\n");
        
        // Exibir a lista atualizada
	    printf("Lista atual: ");
	    struct no *temp = lista;
	    while (temp != NULL) {
	        printf("%d ", temp->dado);
	        temp = temp->prox;
	    }
	    printf("\n");
	    
	}
	
	// Função para inserção à direita
	void inserirDireita(int valor) {
	    struct no *novoNo = (struct no *)malloc(sizeof(struct no));
	    novoNo->dado = valor;
	    novoNo->prox = NULL;
	
	    if (lista == NULL) {
	        // Se a lista estiver vazia, o novo nó se torna o primeiro nó da lista
	        lista = novoNo;
	    } else {
	        // Caso contrário, encontramos o último nó e o conectamos ao novo nó
	        struct no *temp = lista;
	        while (temp->prox != NULL) {
	            temp = temp->prox;
	        }
	        temp->prox = novoNo;
	    }
	
	    printf("\nInsercao a direita realizada com sucesso.\n");
	
	    // Exibir a lista atualizada
	    printf("Lista atual: ");
	    struct no *temp = lista;
	    while (temp != NULL) {
	        printf("%d ", temp->dado);
	        temp = temp->prox;
	    }
	    printf("\n");
	}
	
	//Função para exibir o menu e tratar a escolha do usuário
	int exibirMenu() {
		int opcao;
		int valor;
		
		do{
			opcao = menu(); //Chama o menu e captura a escolha do usuário
			
			switch(opcao) {
				case 1:
                    printf("Digite o valor a ser inserido a esquerda: ");
                    scanf("%d", &valor);
                    inserirEsquerda(valor);
					break;
					
				case 2:
					printf("Digite o valor a ser inserido a direita: ");
	                scanf("%d", &valor);
	                inserirDireita(valor);
					break;
				
				case 3:
					printf("Posicao a ser inserida: ");
                    scanf("%d", &pos);
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &valor);
                    inserirIntermediario(valor, pos);
					break;
				
				case 4:
					printf("\nVoce escolheu sair. Obrigado por utilizar o Sistema de Lista Lineares!\n");
					break;
					
				default:
					printf("\nOpcao invalida. Por favor, escolha uma opcao valida.\n");
					break;
			}
		}while(opcao != 4);
		
		return 0;
	}
	
	exibirMenu();

	return 0;
}
