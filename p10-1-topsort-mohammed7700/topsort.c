/* ************************************************************************** *
 * Ändern Sie in dieser Datei nur die markierten Methoden, welche Sie ganz    *
 * unten in dieser Datei finden.                                              *
 * ***************************************************************************/

#include "topsort.h"
#include "stack.h"
#include "dlinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define KREIS "Der Graph ist nicht kreisfrei.\n"

#ifdef LISTE
#include "adjacencyList.h"
#endif
#ifdef MATRIX
#include "adjacencyMatrix.h"
#endif

int read_size(FILE *in);

int main(void){
    int size = read_size(stdin);
    if (size <= 0){
        return 1;
    }
    Graph *g = graph_create(size);
    g = read_graph(g, stdin);
    // Sie können diese Zeile zu Debuggingzwecken einkommentieren.
    print_graph(g, stdout); 
    top_sort(g);
    graph_destroy(g);
    g = NULL;
}

DFSData* create_dfsdata(int size){
    DFSData *data = malloc(sizeof(DFSData));
    dfsdata_init(data, size);
    return data;
}


void dfsdata_init(DFSData *data, int size){
    data->size = size;
    data->time = 0;
    data->color = malloc(size*sizeof(Color));
    data->discovery = malloc(size*sizeof(int));
    data->finish = malloc(size*sizeof(int));
    for(int i = 0; i < size; i++){
        data->color[i] = WHITE;
        data->discovery[i] = -1;
        data->finish[i] = -1;
    }
}


void dfsdata_destroy(DFSData *data){
    free(data->color);
    free(data->discovery);
    free(data->finish);
    free(data);
}


int read_size(FILE *in){
    int size;
    if(fscanf(in, "%d", &size)!= 1){
        fprintf(stderr, "[FEHLER] Graphgröße konnte nicht gelesen werden.\n");
        return -1;
    } else if (size <= 0){
        fprintf(stderr, "[FEHLER] Graphgröße ist ungültig (<= 0).\n");
    }
    return size;
}


void top_sort(Graph *g){
    // TODO implementieren Sie diese Methode
    DFSData* d = create_dfsdata(g->size);

    DList* stack = create_dlist();

    bool nKreisfrei = true;

    for ( int i = 0; i < g->size; i++ ) {

        if(d->color[i] == WHITE) {

            if(top_sort_dfs(g, i, d, stack)) {
                nKreisfrei &= false;
                break;
            }
        }
    }

    while(!is_empty(stack)) {
        if(nKreisfrei) {
            printf("%i\n",pop(stack));
        } else {
            pop(stack);
        }
    }

    dfsdata_destroy(d);
    dlist_destroy(stack, true);
}


bool top_sort_dfs(Graph *g, int v, DFSData* dfs_data, DList *s){
    // TODO implementieren Sie diese Methode
    // Den Rückgabetypen dürfen Sie ändern.

    dfs_data->discovery[v] =  dfs_data->time++;
    dfs_data->color[v] = GRAY;

    DList* e = g->nodes[v].edges;

    for ( DListElement* node = e->head; node != e->tail; node = node->_next ) {

        if(dfs_data->color[node->key] == GRAY) {

            printf(KREIS);
            return false;
        } else if(dfs_data->color[node->key] == WHITE) {

            top_sort_dfs(g, node->key, dfs_data, s);
        }
    }

    dfs_data->color[v] = BLACK;
    push(s, v);
    dfs_data->finish[v] = dfs_data->time;
    dfs_data->time++;

    return true;
}
