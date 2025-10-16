/*
Esercizio – Preparazione verifica
Scrivere un programma in C che dopo aver dichiarato una struttura denominata Persona con i
seguenti campi: Nome, Cognome, età, codice fiscale, reddito annuo, anno_nascita,residenza(città) ;
determini:
1) La persona con reddito annuo più alto e quella con reddito annuo più basso.Visualizzare
per entrambe: nome, cognome, città e reddito.
2) Ordinare la lista delle persone in base all’anno di nascita** (dal più anziano al più
giovane), e visualizzarla.
3) Consentire all’utente di cercare una persona inserendo il codice fiscale..
4) Visualizzare tutte le persone con reddito superiore o uguale a un valore scelto dall’utente.
5) Calcolare la media dei redditi delle persone registrate nel sistema.
6) Visualizzare tutte le persone nate in un anno specifico, scelto dall’utente;
7) Visualizzare l'elenco delle persone raggruppate per città di residenza, indicando per
ciascuna città: Quante persone vi risiedono, L’età media dei residenti
*/


#include <stdio.h>

typedef struct  {
    char *nome;
    char *cognome;
    int eta;
    char *codiceFiscale;
    int redditoAnnuo;
    int annoNascita;
    char *residenza;
} Persona;
const Persona EMPTY_PERSONA = {"", "", 0, "", 0, 0, ""};

void printPersona(Persona p) {
    printf("Nome: %s, Cognome: %s, Eta: %d, Codice Fiscale: %s, Reddito Annuo: %d, Anno di nascita: %d, Residenza: %s", 
        p.nome, p.cognome, p.eta, p.codiceFiscale, p.redditoAnnuo, p.annoNascita, p.residenza);
}

void printListPersona(Persona persone[], int l) {
    for (int i = 0; i < l; i++) {
        printPersona(persone[i]);
    }
}

Persona getRedditoMax(Persona persone[], int l)
{
    int pos = 0;
    for (int i = 0; i < l; i++) {
        if (persone[pos].redditoAnnuo < persone[i].redditoAnnuo) 
            pos = i;
    }

    return persone[pos];
}

Persona getRedditoMin(Persona persone[], int l)
{
    int pos = 0;
    for (int i = 0; i < l; i++) {
        if (persone[pos].redditoAnnuo > persone[i].redditoAnnuo) 
            pos = i;
    }

    return persone[pos];
}

void sortForYear(Persona persone[], int l)
{
    for (int i = l; i > 0; i++) {
        for (int j = 0; j < i; j++) {
            if (persone[j].annoNascita < persone[j + 1].annoNascita) {
                Persona temp = persone[j];
                persone[j] = persone[j + 1];
                persone[j + 1] = temp;
            }
        }
    }
}

Persona findByID(Persona persone[], int l, char ID[])
{
    for (int i = 0; i < l; i++) {
        if (persone[i].codiceFiscale == ID) {
            return persone[i];
        }
    }

    return EMPTY_PERSONA;
}

double avargeReddito(Persona persone[], int l) {
    int sum = 0;
    
    for (int i = 0; i < l; i++) {
        sum += persone[i].redditoAnnuo;
    }

    return (double)(sum / l);
}

Persona printByYear(Persona persone[], int l, int year)
{
    for (int i = 0; i < l; i++) {
        if (persone[i].codiceFiscale == year) {
            printPersona(persone[i]);
        }
    }

    return EMPTY_PERSONA;
}

int main(int argc, char *argv[]) {
    const int l = 9;
    Persona persone[] = {
        {"Mario", "Rossi", 25, "RSSMRA97A01H501U", 20000, 1997, "Milano"},
        {"Luigi", "Verdi", 30, "VRDLGU96A01H501U", 25000, 1996, "Torino"},
        {"Giovanni", "Bianchi", 35, "BNCGNN95A01H501U", 30000, 1995, "Napoli"},
        {"Francesca", "Neri", 28, "NRIFNC94A01H501U", 18000, 1994, "Firenze"},
        {"Anna", "Gialli", 22, "GLLANN93A01H501U", 22000, 1993, "Venezia"},
        {"Paolo", "Blu", 40, "BLUPAO92A01H501U", 35000, 1992, "Bologna"},
        {"Sara", "Rosa", 27, "RSSSRA91A01H501U", 27000, 1991, "Genova"},
        {"Luca", "Viola", 33, "VLLLCU90A01H501U", 32000, 1990, "Palermo"},
        {"Elena", "Arancio", 29, "RNCELN89A01H501U", 29000, 1989, "Catania"}
    };

    
    return 0;
}
