#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//SORU6: Listede en uzun ismin olduðu kaydý yazdýran fonksiyonu yazýnýz.

// Öðrenci bilgileri tanýmlamalarý:
struct Student {
    int studentNumber;
    char name[50];
    int age;
    struct Student *next;
};

// Baðlý liste üzerinde dolaþarak en uzun ismi bulan fonksiyon
void findLongestName(struct Student *head) {
    struct Student *current = head;
    int maxLength = 0;
    char *longestName;

    while (current != NULL) {
        if (strlen(current->name) > maxLength) {
            maxLength = strlen(current->name);
            longestName = current->name;
        }
        current = current->next;
    }

    // En uzun isme sahip kaydý yazdýr
    printf("En uzun isme sahip kayýt: %s\n", longestName);
}

// Örnek bir baðlý liste oluþtur
struct Student* createSampleLinkedList() {
    struct Student *head = NULL;
    struct Student *second = NULL;
    struct Student *third = NULL;

    // Bellekte yer ayýr
    head = (struct Student *)malloc(sizeof(struct Student));
    second = (struct Student *)malloc(sizeof(struct Student));
    third = (struct Student *)malloc(sizeof(struct Student));

    // Veri atamasý yap
    head->studentNumber = 1;
    strcpy(head->name, "Ahmet");
    head->age = 20;
    head->next = second;

    second->studentNumber = 2;
    strcpy(second->name, "Mehmet");
    second->age = 21;
    second->next = third;

    third->studentNumber = 3;
    strcpy(third->name, "Abdullah");
    third->age = 22;
    third->next = NULL;

    // En uzun ismi bulan fonksiyonu çaðýr
    findLongestName(head);

    return head;
}

// Ana fonksiyon
int main() {
    // Örnek baðlý listeyi oluþtur
    struct Student *list = createSampleLinkedList();

    // Belleði serbest býrak
    free(list);
    
    return 0;
}
