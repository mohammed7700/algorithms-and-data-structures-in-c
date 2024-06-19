// TODO binden Sie die erforderlichen Headerdateien ein
#include "hashmap.h"
#include "arraylist.h"
#include "mergesort.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 255
#define RESULT_MSG "%s %d\n"

// Diese Methode ist schon fertig
char* get_next_word(FILE* f) {
    char c;
    int n_word_chars=0;
    char word_buffer[MAX_WORD_LENGTH+1];

    while(fscanf(f, "%c", &c) == 1 && n_word_chars < MAX_WORD_LENGTH) {
        if(!isalpha(c)) break;
        word_buffer[n_word_chars++] = c;
    }
    if(n_word_chars == 0) return NULL;

    word_buffer[n_word_chars++] = '\0';

    // TODO Der hier allokierte Speicher muss später wieder freigegeben werden.
    char* next_word = malloc(sizeof(char)*n_word_chars);
    strncpy(next_word, word_buffer, n_word_chars);
    return next_word;
}

void normalize(char* str) {
    // TODO Wandeln Sie str in Kleinbuchstaben um
    //      Sie duerfen 'char tolower(char c)' aus <string.h> benutzen.
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

int main(void) {
    HashFunction hash_func = {4789, 1789, INT_MAX};
    // TODO Sie brauchen eine Hashtabelle.
    //      Verwenden Sie hash_func als Hashfunktion.
    HashMap* h = malloc(sizeof(HashMap)); 
    hashmap_init(h, hash_func);


    // TODO Sie brauchen eine Arrayliste
    ArrayList* al = malloc(sizeof(ArrayList));
    al_init(al);

    FILE* infile = stdin;
    while(!feof(infile)) {
        char* next_word = get_next_word(infile);

        if(next_word == NULL) {
            continue;
        }

        // TODO Fuegen Sie next_word in die Hashtabelle ein.
        normalize(next_word);
        HashElement* wordCount = hashmap_get(h, next_word);

        if( wordCount != NULL) {

            hashmap_insert(h, next_word, wordCount->value+1);
        } else {

            hashmap_insert(h, next_word, 1);
            al_append(al, next_word);
        }
        
        // TODO Wann muessen Sie next_word in die Arrayliste einfuegen?
    }

    // TODO Sortieren Sie den Inhalt der Arrayliste
    merge_sort_bottom_up(al->arr, al->size);
    // TODO Gegeben Sie den Inhalt der Arrayliste aus
    for(int i = 0; i < al->size; i++) {

        printf("%i\n", hashmap_get(h, al_get(al, i))->value);
    }
    // TODO Geben Sie den Speicher wieder frei!
    al_destroy(al);
    hashmap_destroy(h);

    return 0;
}
