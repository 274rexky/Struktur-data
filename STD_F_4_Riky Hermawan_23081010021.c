#include <stdio.h>
#include <stdlib.h>

#define MAX 15

struct stack{
	int count;
	struct node *top;
};typedef struct stack stack;


struct node{
	int data;
	struct node *next;
};typedef struct node node;


void push(stack *s);
void pop(stack *s);
void display(stack *s);
int full(stack *s);
int empty(stack *s);
void jumlahData(stack *s);
void top(stack *s);
void destroy(stack *s);


int main(){
	stack s;
	s.count = 0;
	s.top = NULL;
	
	int pilihan;
	
	do{
		system("cls");
		printf("1. Push Stack\n");
		printf("2. Pop Stack\n");
		printf("3. Display Stack\n");
		printf("4. Jumlah data dalam stack\n");
		printf("5. Stack TOP\n");
		printf("6. Destroy Stack\n");
		printf("7. Keluar Program\n");
		printf("Masukkan pilihan: ");
		scanf("%d", &pilihan);
		printf("\n");
		
		switch(pilihan) {
			case 1:
				push(&s);
				getchar();
				getchar();
				break;
			case 2:
				pop(&s);
				getchar();
				getchar();
				break;
			case 3:
				display(&s);
				getchar();
				getchar();
				break;
			case 4:	
				jumlahData(&s);
				getchar();
				getchar();
				break;			
			case 5:
				top(&s);
				getchar();
				getchar();
				break;
			case 6:
				destroy(&s);
				getchar();
				getchar();
				break;			
			case 7:
				printf("Keluar dari program...");
				break;	
			default:
				printf("Pilihan tidak valid, coba lagi...");
				getchar();
				getchar();
		}
		
	}while(pilihan != 7);
	
	return 0;
}


void push(stack *s){
	system("cls");
	if(full(s)){
		printf("Stack Penuh!!!");
		return;
	}
	
	node *newNode = (node *)malloc(sizeof(node));
	int bil;
	printf("Masukkan bilangan: ");
	scanf("%d", &bil);
	
	newNode->data = bil;
	newNode->next = s->top;
	s->top = newNode;
	s->count++;
	printf("%d telah ditambahkan ke dalam Stack...", bil);	
}

void pop(stack *s){
	system("cls");
	if(empty(s) ){
		printf("Stack Kosong!!!");
		return;
	}
	
	node *del = s->top;
	printf("%d telah dihapus dari Stack...", del->data);
	s->top = s->top->next;
	free(del);
	s->count--;
}

void display(stack *s){
	system("cls");
	if(empty(s)){
		printf("Stack Kosong!!!");
		return;
	}
	
	node *display = s->top;
	while(display != NULL){
		printf("%d\n", display->data);
		display = display->next;
	} 
}

int full(stack *s){
	if(s->count == MAX){
	//	printf("TRUE");
		return 1;
	}else {
	//	printf("FALSE");
		return 0;
	}
}

int empty(stack *s){
	if(s->top == NULL){
	//	printf("TRUE");
		return 1;
	}else {
	//	printf("FALSE");
		return 0;
	}
}

void jumlahData(stack *s){
	system("cls");
	printf("Jumlah data dalam Stack: %d", s->count);
}

void top(stack *s){
	if ( s->top == NULL ){
		printf("Stack Kosong");
		return;
	}
	
	node *atas = s->top;
	printf("%d adalah data teratas dari Stack", atas->data);

}

void destroy(stack *s){
	if(s->top == NULL){
		printf("Stack Kosong");
		return;
	}
	
	while(s->top != NULL){
		node *del = s->top;
		s->top = s->top->next;
		printf("%d Berhasil dihapus\n", del->data);
		free(del);	
	}
	printf("Destroy Stack berhasil dijalankan~~~");
	s->count = 0;
return;
}
