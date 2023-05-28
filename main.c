#include <stdio.h>

//Bulan�k k�me analizi i�in veri yap�s�n�n olu�turulmas�.
typedef struct {
    float kumeDeger;
    float kumeBulaniklik;
} Veri;

//Verilerin bulan�kl�k de�erine g�re s�ralanmas� i�in fonskiyon.
void siralamaFonk(Veri veriler[], int n) {
    int k,t;
    k = 0;
    Veri temp;
    
    while( k < n-1) {
        for (t = 0; t < n-k-1; t++) {
            if (veriler[t].kumeBulaniklik > veriler[t+1].kumeBulaniklik) {
                temp = veriler[t];
                veriler[t] = veriler[t+1];
                veriler[t+1] = temp;
            }
        }
       k++; 
    }
}

//Bulan�k k�me analizi i�lemi i�in yaz�lan fonksiyon.
void bulanikKumeAnalizi(Veri veriler[], int n) {
    int i = 0;
    
    siralamaFonk(veriler, n);
    
    //S�ralanm�� verileri ekrana yazd�r�yoruz.
    printf("Siralama:\n");
    while (i < n) {
        printf("%.2f (Bulaniklik degeri = %.2f)\n", veriler[i].kumeDeger, veriler[i].kumeBulaniklik);
		i++;
    }
    
}

int main() {
    int n, o;
    printf("Veri sayisini giriniz = ");
    scanf("%d", &n);
    
    //Verileri kullan�c�dan al�yoruz.
    Veri veriler[n];
    for (o = 0; o < n; o++) {
        printf("Veri %d degerini girin: ", o+1);
        scanf("%f", &veriler[o].kumeDeger);
        printf("Veri %d bulaniklik degerini girin: ", o+1);
        scanf("%f", &veriler[o].kumeBulaniklik);
    }
    
    //Bulan�k k�me analizi i�lemini �a��r�yoruz.
    bulanikKumeAnalizi(veriler, n);
    
    return 0;
}

