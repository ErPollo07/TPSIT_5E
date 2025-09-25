import functions as f


def main():
    # Inserimento della stringa
    string = input("Inserisci una stringa: ").split(" ")[0]

    if f.check_letters(string):
        print("La stringa ha solo lettere.")
    else:
        print("La stringa non ha solo lettere.")

    # Inserimento del carattere da cercare
    c = input("Inserisci un carattere da cercare: ")
    print(f"La stringa '{c}' e' presente '{f.search_char(c)}' volta/e nella stringa '{string}'.")

    # Divisione della stringa in caratteri in posizione pari e dispari
    odd, even = f.odd_even(string)
    print(f"Le lettere in posizione pari sono: [{even}].")
    print(f"Le lettere in posizione dispari sono [{odd}].")

    if f.check_doubles(string):
        print("La stringa contiene doppie.")
    else:
        print("La stringa non contiene doppie.")

    string2: str = input("Inserisci una seconda stringa: ")

    if len(string) > len(string2):
        print("La stringa 1 e' piu' lunga.")
    elif len(string) < len(string2):
        print("La stringa 2 e' piu' lunga.")
    else:
        print("Le due stringe hanno lughezza uguale.")

    print(f"Queste sono le lettere contenute all'interno di tutte e due le stringe: {f.check_string(string, string2)}")

    return


if __name__ == "__main__":
    main()