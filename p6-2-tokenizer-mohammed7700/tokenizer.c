#include "tokenizer.h"

#include <stdio.h>
#include <stdlib.h>

/* Liefert den Teilstring str[l,...,r] als Kopie in einem neuen Array der
 * Länge r-l+1 zurück.
 *
 * Der Aufrufer ist dafür verantwortlich, die Kopie zu löschen.
 */
char* substring(char* str, int l, int r) {
  // TODO hier Code einfügen
}

/* Zerteilt einen String an jedem Vorkommen des Separators sep in Teilstrings,
 * die wir Tokens nennen. Liefert die Tokens/Teilstrings in einem Array und
 * die Länge dieses Arrays in *n_tokens zurück.
 *
 * Ein Separator am Anfang oder Ende des Eingabestrings führt dazu, dass das
 * erste bzw. letzte Token der leere String ist. Wenn der Eingabestring
 * n Vorkommen von sep enthält, ist *n_tokens daher genau n+1.
 *
 * Die zurückgelieferten Tokens sind Kopien des ursprünglichen Strings.
 *
 * Der Aufrufer ist dafür verantwortlich, das zurückgelieferte Array und alle
 * Teilstrings zu löschen.
 */
char** tokenize(char* str, char sep, int* n_tokens) {
  // TODO hier Code einfügen
}

/* Löscht alle in tokens enthaltenen Teilstrings und das Array tokens selbst */
void free_tokens(char** tokens, int n) {
  // TODO hier Code einfügen
}

