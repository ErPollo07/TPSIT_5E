/*
Esercizio - Strutture
Scrivere un programma in C che dopo aver dichiarato una struttura denominata Auto con i seguenti
campi: ModelloAuto, marca, cilindrata, prezzo, anno_immatricolazione, targa; determini:
1) Il prezzo + alto e quello + basso visualizzando anche il modello dell'auto;
2) Ordinare la lista delle auto in base all'anno d'immatricolazione;
3) Visualizzare il nome delle auto a partire da un prezzo scelto dall'utente.
4) Ricerchi un Auto scelta dall’utente (utilizzare il campo targa): visualizzando tutti i campi;
5) La media dei prezzi delle auto inserite;
6) Visualizzare le Auto con anno di immatricolazione scelto dall’utente;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Auto
{
    char *modello;
    char *marca;
    char *targa;
    int cilindrata;
    int prezzo;
    int anno_immatricolazione;
};

const struct Auto EMPTY_AUTO = {"empty", "empty", "empty", 0, 0, 0};

void printAuto(struct Auto *a)
{
    printf("Modello: %s, Marca: %s, Targa: %s, Cilindrata: %d, Prezzo: %d, Anno di immatricolazione: %d\n",
           a->modello, a->marca, a->targa, a->cilindrata, a->prezzo, a->anno_immatricolazione);
}

void printListAuto(struct Auto *list, int l) {
    for (int i = 0; i < l; i++) {
        printAuto(&list[i]);
    }
}

struct Auto getMinPrice(struct Auto *garage, int l)
{
    if (l == 0)
        return EMPTY_AUTO;

    int minPrice = garage[0].prezzo;
    int pos = 0;

    for (int i = 0; i < l; i++)
    {
        if (garage[0].prezzo < minPrice)
        {
            pos = i;
        }
    }

    return garage[pos];
}

struct Auto getMaxPrice(struct Auto *garage, int l)
{
    if (l == 0)
        return EMPTY_AUTO;

    int maxPrice = garage[0].prezzo;
    int pos = 0;

    for (int i = 0; i < l; i++)
    {
        if (garage[0].prezzo > maxPrice)
        {
            pos = i;
        }
    }

    return garage[pos];
}

/// @brief Sort base on year of registration
/// @param garage the array of cars
/// @param l lenght of the garage
void sort(struct Auto *garage, int l)
{
    for (int i = l; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (garage[j].anno_immatricolazione > garage[j + 1].anno_immatricolazione)
            {
                struct Auto temp = garage[j];
                garage[j] = garage[j + 1];
                garage[j + 1] = temp;
            }
        }
    }
}

struct Auto find(struct Auto *garage, int l, char *targa)
{
    for (int i = 0; i < l; i++)
    {
        if (garage[0].targa == targa)
        {
            return garage[0];
        }
    }

    return EMPTY_AUTO;
}

int avaragePrice(struct Auto *garage, int l)
{
    int sum = 0;

    for (int i = 0; i < l; i++)
    {
        sum += garage[i].prezzo;
    }

    return sum / l;
}

struct Auto findYear(struct Auto *garage, int l, int anno_immatricolazione)
{
    if (l == 0)
        return EMPTY_AUTO;

    for (int i = 0; i < l; i++)
    {
        if (garage[i].anno_immatricolazione == anno_immatricolazione)
        {
            printAuto(&garage[i]);
        }
    }
}

int main()
{
    struct Auto garage[] = {
        {"Panda", "Fiat", "AB123CD", 1200, 8000, 2018},
        {"Golf", "Volkswagen", "EF456GH", 1600, 15000, 2018},
        {"Model 3", "Tesla", "IJ789KL", 0, 40000, 2022},
        {"Clio", "Renault", "MN012OP", 1300, 10000, 2017},
        {"A3", "Audi", "QR345ST", 2000, 25000, 2020}};

    int l_garage = sizeof(garage) / sizeof(garage[0]);

    // Max and min prices
    struct Auto maxPriceAuto = getMaxPrice(garage, l_garage);
    printf("The most expensive auto is: ");
    printAuto(&maxPriceAuto);
    struct Auto minPriceAuto = getMinPrice(garage, l_garage);
    printf("The least expensive auto is: ");
    printAuto(&minPriceAuto);

    // Sort the list
    printf("Garage before sorting: ");
    printListAuto(garage, l_garage);
    sort(garage, l_garage);
    printf("Garage after sorting: ");
    printListAuto(garage, l_garage);

    // Find car by targa
    printf("The car with targa 'AB123CD' is: \n\t");
    struct Auto a = find(garage, l_garage, "AB123CD");
    printAuto(&a);

    // Find by anno_immatricolazione
    printf("The cars with anno_immatricolazione of '2018' are: \n");
    findYear(garage, l_garage, 2018);

    // Avarage price
    printf("The avarage price of the cars is: %d", avaragePrice(garage, l_garage));

    
    printf("\n\n");
    return 0;
}
