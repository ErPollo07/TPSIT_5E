

def check_letters(s: str):
    return s.isalpha()


def count_char(s: str, c: str):
    return s.count(c)


def odd_even(s: str):
    odd, even = "", ""

    [odd.join([odd, s[i]]) for i in range(0, len(s), 2)]
    [even.join([even, s[i]]) for i in range(1, len(s), 2)]

    return odd, even


def check_doubles(s: str):
    return len(s) != len(set(s))


def saem_letters(s1: str, s2: str):
    same_letters: list[str] = []
    
    for c1 in s1:
        for c2 in s2:
            if same_letters.count(c1) == 0 and c1 == c2:
                same_letters.append(c1)

    return same_letters


def count_vowels(s: str):
    vowels: str = "aeiouAEIOU"
    count: int = 0

    [count.__add__(vowels.count(c)) for c in s]

    return count


def count_consonant(s: str):
    return len(s) - count_vowels(s)