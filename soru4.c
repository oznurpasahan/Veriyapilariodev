#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

// ��renci yap�s�
struct Student {
    char name[50];
    int age;
    // Di�er ��renci bilgilerini buraya ekleyebilirsiniz.
};

// ��renci listesi
struct Student students[] = {
    {"Ahmet", 20},
    {"Mehmet", 22},
    {"Ay�e", 21},
    {"Fatma", 19},
    // Daha fazla ��renci eklemek i�in bu yap�y� kullanabilirsiniz.
};

int numberOfStudents = sizeof(students) / sizeof(students[0]);

// ��renci ad�na g�re arama yapacak fonksiyon
void searchStudentByName(const char *searchName) {
    int found = 0;
    int i;
    for (i = 0; i < numberOfStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("��renci Bulundu: %s, Ya��: %d\n", students[i].name, students[i].age);
            found = 1;
            break; // ��renci bulundu, d�ng�y� sonland�r
        }
    }

    if (!found) {
        printf("��renci bulunamad�: %s\n", searchName);
    }
}

int main() {
    char nameToSearch[50]; // Aranacak ��rencinin ad�n� saklamak i�in bir dizi olu�turun
    printf("Aranacak ��rencinin ad�n� girin: ");
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    nameToSearch[strcspn(nameToSearch, "\n")] = '\0'; // Yeni sat�r karakterini kald�r
    searchStudentByName(nameToSearch);

    return 0;
}

