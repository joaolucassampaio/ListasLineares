#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	//Em C, uma estrutura (struct) � uma cole��o de vari�veis referenciadas por um nome, fornecendo uma maneira conveniente de se ter
	//informa��es relacionadas agrupadas.
	
	//no � o identificador (tag) da struct
	//struct � um tipo de dado. Ou seja, nesse ponto do c�digo nenhuma vari�vel foi declarada. Apenas a forma do dos dados foi definida.
	struct no{
		int dado; //Este membro armazena o dado que o n� cont�m. Neste caso, � um n�mero inteiro (int).
		struct no *prox; //Este membro � um ponteiro para outro n� da lista. Ele aponta para o pr�ximo n� na sequ�ncia.
	};
	//Declarando tr�s ponteiros para a struct no
	struct no *lista, *p, *q;
	//Declarando tr�s vari�veis inteiras que ser�o usadas para diferentes prop�sitos dentro do programa.
	int sn, cont, pos;
	//Define o ponteiro lista como NULL. Isso geralmente � feito para indicar que a lista encadeada est� vazia.
	lista = NULL;
	cont = 0;
	
	//Fun��o que cont�m o menu de capturar a escolha do usu�rio
	int menu() {
		int escolha;
	    printf("\nBem-vindo(a) ao Sistema de Lista Lineares!\n\n");
	    printf("Em que posso ajudar hoje?\n");
	    printf("1. Fazer uma insercao a esquerda;\n");
	    printf("2. Fazer uma insercao a direita;\n");
	    printf("3. Fazer uma insercao intermediaria;\n");
	    printf("4. Encerrar programa;\n");
	    printf("Escolha uma opcao: ");
	    scanf("%d", &escolha); // Captura a escolha do usu�rio
	    return escolha;
	}
	
	void limparConsole() {
		system("cls");
	}
	
	//Fun��o para inser��o � esquerda
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
	
	// Fun��o para inser��o � direita
	void inserirDireita(int valor) {
	    struct no *novoNo = (struct no *)malloc(sizeof(struct no));
	    novoNo->dado = valor;
	    novoNo->prox = NULL;
	
	    if (lista == NULL) {
	        // Se a lista estiver vazia, o novo n� se torna o primeiro n� da lista
	        lista = novoNo;
	    } else {
	        // Caso contr�rio, encontramos o �ltimo n� e o conectamos ao novo n�
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
	
	//Fun��o para exibir o menu e tratar a escolha do usu�rio
	int exibirMenu() {
		int opcao;
		int valor;
		
		do{
			opcao = menu(); //Chama o menu e captura a escolha do usu�rio
			
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
