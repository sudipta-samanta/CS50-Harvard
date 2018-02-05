/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;
// create the hash table
node *hashtable[HASHTABLE_SIZE];
// hold dictionary size
unsigned int word_count = 0;
// load/unload condition check
bool loaded = false;
/**
 * Hash function via reddit user delipity:
 * https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
 */
int hash_it(char *needs_hashing)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(needs_hashing); i < n; i++)
    {
        hash = (hash << 2) ^ needs_hashing[i];
    }
    return hash % HASHTABLE_SIZE;
}
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int len = strlen(word);
    char wordLower[len + 1];
    for (int i = 0; i < len; i++)
    {
        wordLower[i] = tolower(word[i]);
    }
    wordLower[len] = '\0';
    int hashValue = hash_it(wordLower);
    node *cursor = hashtable[hashValue];
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, wordLower) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }
    FILE *fp = fopen(dictionary, "r");
    // check if it opens or not
    if (fp == NULL)
    {
        return false;
    }
    while (true)
    {
        // malloc a node for each new word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Could not malloc a new node.\n");
            return false;
        }
        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;
        if (feof(fp))
        {
            // hit end of file
            free(new_node);
            break;
        }
        word_count++;
        int h = hash_it(new_node->word);
        node *head = hashtable[h];
        // if bucket is empty, insert the first node
        if (head == NULL)
        {
            hashtable[h] = new_node;
        }
        // if bucket is not empty, attach node to front of list
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
    }
    // close dictionary
    fclose(fp);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *head = hashtable[i];
        while (head != NULL)
        {
            node *tmp = head;
            head = head->next;
            free(tmp);
        }
    }
    loaded = false;
    return true;
}
