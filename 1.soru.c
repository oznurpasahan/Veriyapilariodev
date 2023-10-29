#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//SORU1: Klavyeden -1 girilinceye kadar , girilen t�m tek say�lar� listenin sonuna, �ift say�lar� ise listenin sonuna ekleyen fonksiyonu yaz�n�z:

struct Node {
	
	int data;
	struct Node* next;
};

// �IKI� YOLU: Klavyeden -1 tu�lanmas�

//Listeye eleman ekleme: 
void insertNode(struct Node **head, int value){
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->data = value;
	if(*head == NULL)
	{
		*head = newNode;
	}
	else if(newNode->data%2!=0)  //newNode'�n datas� tek say�d�r ---> ba�a eklenir
	{
		struct Node *current = newNode;
		current->data = value;
		current->next = *head;
		*head = current;
	}
	else   //newnode'�n datas� �ift say�d�r ---> sona eklenir
	{
		struct Node *current = *head;
		while(current->next!=NULL){   //Listenin sonuna kadar devam eder
			current=current->next;
		}
		current->next = newNode;
	}
}

int main(){
	struct Node *head = NULL;
	int value;
	printf("HATIRLATMA: Cikis yapmak icin -1 tuslamaniz gerekmektedir.\n");
	printf("Listeye eklemek istediginiz elemanlari giriniz: ");
	
	while(1){
		scanf("%d",&value);
		if(value ==-1)
		   break;
		insertNode(&head,value);
	}
	
	struct Node *current = head;
	printf("Listenin basi:  ");
	
	//L�STEY� EKRANA YAZDIRMAK �ST�YORUZ
	while(current!=NULL){
		printf("%d",current->data);
		current=current->next;
	}
	
	printf("   :Listenin sonuu");
}
