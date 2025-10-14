import functions



def main():
    str1: str = input("Inserisci str1: ")
    str2:str = input("Inserisci str2: ")
    
    print("--- MENU ---")
    print("1) Controlla se la prima stringa contiene solo lettere")
    print("2) Conta una lettera nella prima stringa")
    print("3) Crea stringhe di lettere in posizioni pari/dispari")
    print("4) Verifica se la prima stringa contiene doppie")
    print("5) Quale delle due stringhe e' piu' lunga")
    print("6) Lettere comuni tra le due stringhe")
    print("7) Quale stringa ha piu' vocali")
    print("8) Quale stringa ha piu' consonanti")
    print("0) Esci\n");

    scelta_str: str = input("Scelta: ")

    if check_if_only_letters(str1): print("only letter")
    else: print("Not only letters")

    # viene preso solo il primo carattere inserito
    c = input("Inserisci un carattere da controllare: ")[0]

    str

    return


if __name__ == "__main__":
    main()