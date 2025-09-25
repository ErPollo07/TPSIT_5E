

def check_letters(s: str):
    return s.isalpha()


def search_char(s: str, c: str):
    return s.count(c)


def odd_even(s: str):
    odd: str = ""
    even: str = ""
    
    [odd.join([odd, s[i]]) for i in range(0, len(s), 2)]
    [even.join([even, s[i]]) for i in range(1, len(s), 2)]

    return odd, even

def check_doubles(s: str):
    return len(s) != len(set(s))