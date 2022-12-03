# TODO
from cs50 import get_string


def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = int(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index + 1}")
    return 0




def count_letters(text):
    count = 0
    for ch in text:
        if ch.isalpha():
            count += 1
    return count


def count_words(text):
    count = 1
    for ch in text:
        if ch == ' ':
            count += 1
    return count


def count_sentences(text):
    count = 0
    for ch in text:
        if ch == '.' or ch == '?' or ch == '!':
            count += 1
    return count


main()