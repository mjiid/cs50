# TODO
from cs50 import get_string

text = get_string("Text: ")

letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)




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