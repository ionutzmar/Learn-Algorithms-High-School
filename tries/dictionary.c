/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

typedef struct tries 
{
        char word[LENGTH];
        struct tries* array[27];
} structTries;

structTries* root, *sw;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
        char *s = (char *) malloc(sizeof(char) * (strlen(word) + 1));
        sw = root;
        strcpy(s, word);
        for(int i = 0; s[i] != '\0'; i++)
        {
                s[i] = (s[i] == '\'') ? '\'' : tolower(s[i]);
                int subscript = (s[i] == '\'') ?  26 : (s[i] - 'a');
                if(sw->array[subscript] == NULL)
                {
                        free(s);
			return false;
                }
                sw = sw->array[subscript];
        }
        if(!strcmp(sw->word, s))
        {
                free(s);
                return true;
        }
        free(s);
        return false;
}
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
int counter = 0;
bool load(const char* dictionary)
{
        FILE* f = fopen(dictionary, "r");
        if(f == NULL)
                return false;
        char s[LENGTH + 1];
        root = (structTries *) malloc(sizeof(structTries));
        while(fscanf(f, "%s", s) != EOF)
        {
                counter++;
                sw = root;
                for(int i = 0; s[i] != '\0'; i++)
                {
                        int subscript;
                        if(s[i] == '\'')
                                subscript = 26;
                        else
                                subscript = s[i] - 'a';
                        if(sw->array[subscript] == NULL)
                                sw->array[subscript] = (structTries *) malloc(sizeof(structTries));
                        sw = sw->array[subscript];
                }
                strcpy(sw->word, s);
        }

        fclose(f);
        return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
	if(root == NULL)
                return 0;
        else
                return counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

void unloadStruct(structTries* n)
{
        for(int i = 0; i < 27; i++)
        {
                if(n->array[i] != NULL)
                {
                        unloadStruct(n->array[i]);
                        free(n->array[i]);
                }
        }
}
bool unload(void)
{
        unloadStruct(root);
        free(root);
        return true;
}
