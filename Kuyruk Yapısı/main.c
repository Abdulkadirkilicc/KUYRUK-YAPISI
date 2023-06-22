#include<stdio.h>
#include<stdlib.h>

// Kuyruk veri yap�s�n� tan�mlad�k
struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

// Yeni bir d���m olu�turmak  fonksiyon tan�mlad�k
struct Dugum* yeniDugum(int veri) {
    struct Dugum* gecici = (struct Dugum*)malloc(sizeof(struct Dugum));
    gecici->veri = veri;
    gecici->sonraki = NULL;
    return gecici;
}

// Kuyru�un ba��na eleman ekleme i�lemi i�in fonksiyon  tan�mlad�k
void kuyrugaEkle(struct Dugum** bas_ref, struct Dugum** son_ref, int veri) {
    struct Dugum* gecici = yeniDugum(veri);

    if (*bas_ref == NULL) {
        *bas_ref = *son_ref = gecici;
        return;
    }

    (*son_ref)->sonraki = gecici;
    *son_ref = gecici;
}

// Kuyruktan eleman ��karma i�lemi fonksiyon tan�mlad�k
void kuyruktanSil(struct Dugum** bas_ref, struct Dugum** son_ref) {
    if (*bas_ref == NULL) {
        printf("Kuyruk bos.\n");
        printf("\n");
        return;
    }

    struct Dugum* gecici = *bas_ref;
    *bas_ref = (*bas_ref)->sonraki;

    if (*bas_ref == NULL) {
        *son_ref = NULL;
    }

    free(gecici);
	printf("\n");
}

// Kuyruktaki t�m elemanlar� g�sterme i�lemi i�in fonksiyon tan�mlad�k
void Goruntuleme(struct Dugum* bas) {
    if (bas == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }

    printf("Kuyruktaki elemanlar: ");
    while (bas != NULL) {
        printf("%d ", bas->veri);
        bas = bas->sonraki;
    }
    printf("\n");
}

int main() {
    struct Dugum* bas = NULL;
    struct Dugum* son = NULL;

    int secim, veri;
    while (1) {
        printf("Lutfen asagidaki islemlerden birini seciniz:\n");
        printf("1. Ekle\n2. Silme\n3. Goruntuleme\n4. Cikis\n");
        printf("Seciminiz:");
        scanf("%d", &secim);

        switch(secim) {
            case 1:
                printf("Eklemek istediginiz degeri giriniz: ");
                scanf("%d", &veri);
                kuyrugaEkle(&bas, &son, veri);
                printf("\n");
                break;
            case 2:
                kuyruktanSil(&bas, &son);
                break;
            case 3:
                Goruntuleme(bas);
                printf("\n");
                break;
            case 4:
            	printf("Cikis Yaptiniz.");
                exit(0);
            default:
                printf("Gecersiz secenek.\n");
                printf("\n");
        }
    }

    return 0;
}

