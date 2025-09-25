import functions as f


def main():
    # Inserimento della stringa
    string = input("Inserisci una stringa: ").split(" ")[0]

    print(set(string))

    return

    if f.check_letters(string):
        print("La stringa ha solo lettere.")
    else:
        print("La stringa non ha solo lettere.")

    # Inserimento del carattere da cercare
    c = input("Inserisci un carattere da cercare: ")
    print(f"La stringa '{c}' e' presente '{f.search_char(c)}' nella stringa '{string}'.")

    # Divisione della stringa in caratteri in posizione pari e dispari
    odd, even = f.odd_even(string)
    print(f"Le lettere in posizione pari sono: [{even}].")
    print(f"Le lettere in posizione dispari sono [{odd}].")




    return


if __name__ == "__main__":
    main()