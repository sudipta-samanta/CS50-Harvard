// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
/*
from https://github.com/davidventuri/harvard-cs50/blob/master/pset5/dictionary.h
*/
// number of buckets in the hash table
#define HASHTABLE_SIZE 6553
// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

#endif // DICTIONARY_H
