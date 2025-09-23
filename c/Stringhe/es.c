#include <stdio.h>
#include <string.h>
#include <ctype.h>

int solo_lettere(char *s) {
    for (int i = 0; s[i]; i++) {
        if (!isalpha(s[i])) return 0;
    }
    return 1;
}

int conta_lettera(char *s, char c) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == c) count++;
    }
    return count;
}

void stringhe_pari_dispari(char *s, char *pari, char *dispari) {
    int j = 0, k = 0;
    for (int i = 0; s[i]; i++) {
        if (i % 2 == 0) pari[j++] = s[i];
        else dispari[k++] = s[i];
    }
    pari[j] = '\0';
    dispari[k] = '\0';
}

int contiene_doppie(char *s) {
    for (int i = 0; s[i+1]; i++) {
        if (s[i] == s[i+1]) return 1;
    }
    return 0;
}

int conta_vocali(char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        char ch = tolower(s[i]);
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') count++;
    }
    return count;
}

int conta_consonanti(char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        char ch = tolower(s[i]);
        if (isalpha(ch) && !(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')) count++;
    }
    return count;
}

void lettere_comuni(char *s1, char *s2) {
    printf("Lettere comuni: ");
    for (int i = 0; s1[i]; i++) {
        for (int j = 0; s2[j]; j++) {
            if (s1[i] == s2[j]) {
                printf("%c ", s1[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    char str1[100], str2[100], pari[100], dispari[100], lettera;
    int scelta;

    printf("Inserisci la prima stringa: ");
    scanf("%s", str1);

    if (!solo_lettere(str1)) {
        printf("La stringa contiene caratteri non alfabetici.\n");
        return 0;
    }

    printf("Inserisci la seconda stringa: ");
    scanf("%s", str2);

    do {
        printf("\n--- MENU ---\n");
        printf("1) Controlla se la prima stringa contiene solo lettere\n");
        printf("2) Conta una lettera nella prima stringa\n");
        printf("3) Crea stringhe di lettere in posizioni pari/dispari\n");
        printf("4) Verifica se la prima stringa contiene doppie\n");
        printf("5) Quale delle due stringhe e' piu' lunga\n");
        printf("6) Lettere comuni tra le due stringhe\n");
        printf("7) Quale stringa ha piu' vocali\n");
        printf("8) Quale stringa ha piu' consonanti\n");
        printf("0) Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                if (solo_lettere(str1)) printf("La prima stringa contiene solo lettere\n");
                else printf("La prima stringa contiene caratteri non alfabetici\n");
                break;
            case 2:
                printf("Inserisci la lettera da contare: ");
                scanf(" %c", &lettera);
                printf("La lettera '%c' compare %d volte\n", lettera, conta_lettera(str1, lettera));
                break;
            case 3:
                stringhe_pari_dispari(str1, pari, dispari);
                printf("Lettere in posizione pari: %s\n", pari);
                printf("Lettere in posizione dispari: %s\n", dispari);
                break;
            case 4:
                if (contiene_doppie(str1)) printf("La stringa contiene doppie\n");
                else printf("La stringa non contiene doppie\n");
                break;
            case 5:
                if (strlen(str1) > strlen(str2)) printf("La prima stringa e' piu' lunga\n");
                else if (strlen(str2) > strlen(str1)) printf("La seconda stringa e' piu' lunga\n");
                else printf("Le due stringhe hanno la stessa lunghezza\n");
                break;
            case 6:
                lettere_comuni(str1, str2);
                break;
            case 7: {
                int v1 = conta_vocali(str1), v2 = conta_vocali(str2);
                if (v1 > v2) printf("La prima stringa ha piu' vocali\n");
                else if (v2 > v1) printf("La seconda stringa ha piu' vocali\n");
                else printf("Hanno lo stesso numero di vocali\n");
                break;
            }
            case 8: {
                int c1 = conta_consonanti(str1), c2 = conta_consonanti(str2);
                if (c1 > c2) printf("La prima stringa ha piu' consonanti\n");
                else if (c2 > c1) printf("La seconda stringa ha piu' consonanti\n");
                else printf("Hanno lo stesso numero di consonanti\n");
                break;
            }
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida\n");
        }
    } while (scelta != 0);

    return 0;
}