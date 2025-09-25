import function as f


def main():
    ### Inserimento nella stringa ###
    string = input("Inserisci una stringa: ").split(" ")[0]

    ### Controlla se la stringaf ha solo lettere ###
    if f.check_letters(string):
        print("La stringa ha solo lettere.")
    else:
        print("La stringa non ha solo lettere.")

    ### Cerca carattere ###
    c = input("Inserisci un carattere da cercare: ")
    print(f"La stringa '{c}' e' presente '{(string.count(c))}' volta/e nella stringa '{string}'.")

    ### Divisione dei caratteri della stringa in pozioni diverse ###
    odd, even = f.odd_even(string)
    print(f"Le lettere in posizione pari sono: [{even}].")
    print(f"Le lettere in posizione dispari sono [{odd}].")

    ### Controllo doppie ###
    if f.check_doubles(string):
        print("La stringa contiene doppie.")
    else:
        print("La stringa non contiene doppie.")

    string2: str = input("Inserisci una seconda stringa: ")

    ### Comparazione della lunghezza ###
    if len(string) > len(string2):
        print("La stringa 1 e' piu' lunga.")
    elif len(string) < len(string2):
        print("La stringa 2 e' piu' lunga.")
    else:
        print("Le due stringe hanno lughezza uguale.")

    print(f"Queste sono le lettere contenute all'interno di tutte e due le stringe: {f.same_letters(string, string2)}")

    ### Conto vocali ###
    v1 = f.count_vowels(string)
    v2 = f.count_vowels(string2)
    if v1 > v2:
        print("La string 1 ha piu' vocali.")
    elif v1 < v2:
        print("La string 1 ha piu' vocali.")
    else:
        print("Il numero di vocali e' uguale")

    ### Conto consonanti ###
    c1: int = f.count_consonant(string)
    c2: int = f.count_consonant(string2)
    if c1 > c2:
        print("La string 1 ha un numero di consonanti maggiore.")
    elif v1 < v2:
        print("La string 2 ha un numero di consonanti maggiore.")
    else:
        print("IL numero di consonanti e' uguale.")

    return 0


if __name__ == "__main__":
    main()