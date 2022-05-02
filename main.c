#include <stdio.h>
#include <stdlib.h>

int binarySearch(int tablica[], int leftVal, int rightVal, int val) {
 if (rightVal >= leftVal) {
    int pivot = leftVal + (rightVal - leftVal) / 2; // ustawienie pivotu
    if (tablica[pivot] == val) // jesli wartosc na indexie pivotu jest rowna naszej szukanej wartosci, zwracamy index szukanej wartosci
        return pivot;
    if (tablica[pivot]>val) // jesli wartosc jest wieksza od szukanej wartosci,
        return binarySearch(tablica,leftVal,pivot-1, val); // wykonujemy funkcje rekurencyjnie z ustawieniem indexu o jednego mniejszym niz nasz pivot na wartosci rightVal
    return binarySearch(tablica,pivot+1, rightVal, val);  // w przeciwnym wypadku ustawiamy pod leftVal wartosc pivotu i dodajemy do niego jeden

    }
  return -1;
}

void selectionSort(int tablica[]){
     int min, temp, i, j;
     for(i = 0; i < 10 ; i++){ // przechodzimy przez wszystkie elementy tablicy 11 elementowej,
                               //ostatni element zostanie ju¿ posortowany, dlatego nie jest potrzeba kolejna iteracja
            min = i;

            for(j=i+1;j<11;j++){ // petla przechodzi przez nasze elementy tablicy
                if (tablica[min] > tablica[j]){
                    min = j;
                }
            }
            temp = tablica[i]; // zapamietanie elementu o indexie i w zmiennej temp
            tablica[i] = tablica[min]; // zamiana elementu tablicy o indexie i elementem kolejnym
            tablica[min] = temp; // zamiana elementu o indexie min elementem zapamiêtanym w zmiennej temp
        }
}

int main() {
    int szukana;
    int tablica[] = {5,1,7,8,4,11,2,6,9,3};
    selectionSort(tablica);
    for(int i=0; i<10; i++){
        printf("%d ", tablica[i]);      // pokazanie posortowanej tablicy
    }

    printf("\n wpisz element który chcesz znaleŸæ: \n");
    scanf("%d",&szukana);

    int wynik = binarySearch(tablica, 0, 9, szukana);
    if(wynik == -1){
        printf("Elementu nie ma w tablicy");
    } else {
        printf("Element znajduje sie na pozycji %d", wynik);
    }
  return 0;
}
