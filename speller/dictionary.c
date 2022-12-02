// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Initializes word count in dictionary
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash word -> hash value
    int hash_value = hash(word);

    // Table (hash value) -> access linked list
    node *n = table[hash_value];

    // Traverse linked list (word) vs word
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        // Compare the next subsequence traverse linked list
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Function : Take a string and return an index
    // Hash function: Adds ASCII values of all characters in the word all together
    long sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file and check if the file is null
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Scans dictionary word by word
    // Every single dictionary word -> hash table -> linked node (store)
    // Initialise word array
    char next_word[LENGTH + 1];

    // Read strings from file one at a time
    while (fscanf(file, "%s", next_word) != EOF)
    {
        // Create new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        // Copy word -> node (strcopy)
        strcpy(new_node->word, next_word);

        // Hash word -> hash value (Hash function)
        int hash_value = hash(next_word);

        // Target: table[hash_value] -> new_node -> closest linked list
        //
        // Note: table[hash_value] point to -> closest linked list address
        // 1. new_node copied table[hash_value] address = closest linked list address
        // table[hash_value] & new_node are pointing to -> closest linked list now
        new_node->next = table[hash_value];
        // 2. table[hash_value] copied new_node address
        // table[hash_value] -> new_node -> closest linked list
        table[hash_value] = new_node;
        word_count++;
    }
    // Close file
    fclose(file);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count++;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Iterate over hash table to free nodes on each linked list
    for (int i = 0; i < N; i++)
    {
        // Assign node pointer
        // Note: Note: table[hash_value] point to -> closest linked list address
        // n -> closest linked list
        node *n = table[i];
        // n & temp -> closest linked list
        node *temp = n;

        //Loop through linked list
        while (n != NULL)
        {
            // n -> 2nd closest linked list
            n = n-> next;
            // temp -> closest linked list(free)
            free(temp);
            // n & temp -> 2nd closest linked list
            temp = n;
        }
    }
    return true;
}