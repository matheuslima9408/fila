/* TRABALHO PARA OBTEÇÃO DA NOTA PARCIAL 1, DISCIPLINA ESTRUTURA DE DADOS II
PROFESSOR: SERVULO JUNIOR 
FILA DINAMICA EM C
GRUPO: ARTHUR SILVA DO NASCIMENTO, MATHEUS LIMA DA SILVA,  CRISTIANO RODRIGUO CUNHA,  JOÃO PEDRO MONTELES DE SOUZA.
*/
#include <stdio.h> 
#include <stdlib.h> 
/*ESTRUTURA NO*/
typedef struct NO{
	 int data;
	 struct NO *nxt;
 }no;
 
int size;
no *tmp;

int empty(no *queue){
	if(queue->nxt == NULL) return 1;
	else return 0;
}
/*LIMPANDO A FILA*/
void showQueue(no *queue){
	if(empty(queue)){
		printf("\nFila vazia\n\n");/*Se a fila estiver vazia*/
	}else{
		tmp = queue->nxt;
		printf("\n");
		while(tmp != NULL){
			printf(" %d\n ", tmp->data);/*MOSTRA OS VALORES QUE FORMAM A FILA */
			tmp = tmp->nxt;
		}printf("\nTamanho da Fila: %d\n\n", size);/*MOSTRAR QUAL O TAMANHO DA FILA*/
	}
}

void enqueue(no *queue){
	no *new = (no*) malloc(sizeof(no));
	new->nxt = NULL;
	printf("\nAdicionar um Novo Valor: "); 
	scanf("%d", &new->data);
	printf("\n");
	if(empty(queue)){
		queue->nxt = new;
		size++;
	}else{
		tmp = queue->nxt;
		while(tmp->nxt != NULL){
			tmp = tmp->nxt; 
		}
		tmp->nxt = new;
		size++;
	}
}

no *dequeue(no *queue){
	if(empty(queue)){
		printf("\nfila vazia\n\n");
		return NULL;
	}else{
		tmp = queue->nxt;
		queue->nxt = tmp->nxt; 
		size--;
		return tmp;
	}
}

void freeQueue(no *queue){
	if(empty(queue)){
		printf("\nfila vazia\n\n");
	}else{
		no *nxtNode,
		   *actualNode;
		actualNode = queue->nxt;
		while(actualNode != NULL){
			nxtNode = actualNode->nxt;
			free(actualNode);
			actualNode = nxtNode;
		}
		printf("\nFila Limpa\n\n");
	}
}
	
int main(){
	no *queue = (no*) malloc(sizeof(no));
	if(!queue){
		printf("Nenhuma Memoria");
		exit(1);
	}else{
		queue->nxt = NULL;
		size = 0;
		int opt;
		do{	
		printf("--------FILA DINAMICA------------>\n");
			printf("<0> Sair\n");
			printf("<1> Mostrar Fila\n");
			printf("<2> Adicionar valor a Fila\n");
			printf("<3> Remover valor da Fila\n");
			printf("<4> Limpa Fila\n");
			printf("Escolha uma Opcao: "); scanf("%d", &opt);
		
			switch(opt){
				case 1:
					showQueue(queue);/**/
					break;
				case 2:
					enqueue(queue);/*Adicionar valor a fila*/
					break;
				case 3:
					tmp = dequeue(queue);
					if(tmp != NULL)
						printf("\nElemento Removido %d\n\n", tmp->data);
						break;
				case 4:
					freeQueue(queue);
					queue->nxt = NULL;
					size = 0;
					break;
				default:
					if(opt != 0) printf("\ninserir opcao valida!\n\n"); 
			 }	
		}while(opt != 0);
	}
	return 1;
}
	
