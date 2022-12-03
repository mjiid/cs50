# TODO
from cs50 import get_string

text = get_string("Text: ")

letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)




def count_letters(text):
    count = 0
    for ch in text:
        if 