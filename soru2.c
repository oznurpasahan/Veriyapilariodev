#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//SORU2: L�STEYE RASTGELE �RET�LM�� 100 SAYI EKLENS�N,G�R�LEN T�M SAYILARI B�Y�KTEN K����E SIRALAYAN VE EKRANA BASAN C KODUNU YAZINIZ

// �ki say�n�n kar��la�t�rmas� yap�l�r:
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int sayilar[100];

    // 100 rastgele say�lar �retir:
    int i;
    for (i = 0; i < 100; i++) {
        sayilar[i] = rand() % 1000; // 0 ile 999 aras�nda rastgele say�lar �retir:
    }

    // Say�lar� b�y�kten k����e s�ralama
    qsort(sayilar, 100, sizeof(int), compare);

    // S�ralanm�� say�lar� ekrana yazd�r�r
    printf("S�ralanm�� Say�lar:\n");
    for (i = 0; i < 100; i++) {
        printf("%d -> ", sayilar[i]);
    }
    return 0;
}
