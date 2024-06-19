#include "bintree.h"
#include "dlinkedlist.h"

#include <stdio.h>
#include <stdlib.h>

BinTree* read_tree(FILE* f);
void printNodesOnLevel(BinTreeNode* node, int lvl);

int treeDepth(BinTreeNode* node) {

    if (node == NULL) {

        return 0;
    } else {

        int left = treeDepth(node->left);
        int right = treeDepth(node->right);

        if(left >= right) {

            return left + 1;
        }
        else {

            return right + 1;
        }
    }
}

void printNodesOnLevel(BinTreeNode* node, int lvl) {

    if(node == NULL){
        return;
    }

    if(lvl == 0) {

        printf("%i\n", node->key);
    } else {
        
        printNodesOnLevel(node->left, lvl-1);
        printNodesOnLevel(node->right, lvl-1);
    }
}


void printByLevel(BinTreeNode* root) {

    int maxDepth = treeDepth(root);

    for(int i = 0; i < maxDepth; i++) {

        printNodesOnLevel(root, i);
    }
}




int main(void) {
    BinTree* t = read_tree(stdin);
    if(!t) {
        fprintf(stderr, "Fehler beim Lesen der Eingabe.\n");
        return 1;
    }

    /* TODO Geben Sie t ebenenweise aus.
     *
     * Genauer:
     *
     * - Geben Sie zunächst alle Knoten auf Ebene 0 aus (das ist nur die Wurzel)
     * - Geben Sie dann alle Knoten auf Ebene 1 aus (die Kinder der Wurzel)
     * - Geben Sie dann alle Knoten auf Ebene 2 aus
     *
     * ...usw...
     *
     * - Die Ebenen sollen jeweils von links nach rechts ausgegeben werden, mit
     * einem Knoten pro Zeile (s. Beispiel auf dem Übungsblatt)
     *
     * Sie dürfen zur Lösung alle Datenstrukturen aus dem Repository verwenden.
     * Wählen Sie einen Datenstruktur, die zu einer optimalen asymptotischen
     * Worst-Case-Laufzeit führt und passen Sie die Datenstruktur ggf. an Ihre
     * Bedürfnisse an.
     *
     * Passen Sie ggf. das Makefile an!
     *
     * Markieren Sie außerdem in Frage.md, welche Datenstruktur Sie als
     * Grundlage gewählt haben.
     */


    printByLevel(t->root);


    bt_destroy(t);
    free(t);

    return 0;
}

BinTree* read_tree(FILE* f) {
    BinTree* t = create_bintree();

    while(!feof(f)) {
        int key;

        if(fscanf(f, "%d\n", &key) != 1) {
            fprintf(stderr, "Fehlerhafte Zeile.\n");
            bt_destroy(t);
            free(t);
            return NULL;
        }

        bt_add(t, key);
    }



    return t;
}
