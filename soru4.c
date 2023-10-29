#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

// Öðrenci yapýsý
struct Student {
    char name[50];
    int age;
    // Diðer öðrenci bilgilerini buraya ekleyebilirsiniz.
};

// Öðrenci listesi
struct Student students[] = {
    {"Ahmet", 20},
    {"Mehmet", 22},
    {"Ayþe", 21},
    {"Fatma", 19},
    // Daha fazla öðrenci eklemek için bu yapýyý kullanabilirsiniz.
};

int numberOfStudents = sizeof(students) / sizeof(students[0]);

// Öðrenci adýna göre arama yapacak fonksiyon
void searchStudentByName(const char *searchName) {
    int found = 0;
    int i;
    for (i = 0; i < numberOfStudents; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Öðrenci Bulundu: %s, Yaþý: %d\n", students[i].name, students[i].age);
            found = 1;
            break; // Öðrenci bulundu, döngüyü sonlandýr
        }
    }

    if (!found) {
        printf("Öðrenci bulunamadý: %s\n", searchName);
    }
}

int main() {
    char nameToSearch[50]; // Aranacak öðrencinin adýný saklamak için bir dizi oluþturun
    printf("Aranacak öðrencinin adýný girin: ");
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    nameToSearch[strcspn(nameToSearch, "\n")] = '\0'; // Yeni satýr karakterini kaldýr
    searchStudentByName(nameToSearch);

    return 0;
}

