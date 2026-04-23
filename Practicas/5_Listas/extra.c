#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"

void insLast(Nodo** PrimerNodo, int new_data) {
    Nodo* newNodo = createNodo(new_data);
    if (*PrimerNodo == NULL) {
        *PrimerNodo = newNodo;
        return;
    }
    Nodo* current = *PrimerNodo;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNodo;
}

void delFirst(Nodo** PrimerNodo) {
    if (*PrimerNodo == NULL) {
        printf("List is empty. No Nodo to delete.\n");
        return;
    }
    Nodo* old_PrimerNodo = *PrimerNodo;
    *PrimerNodo = old_PrimerNodo->next;
    free(old_PrimerNodo);
}

void delValue(Nodo** PrimerNodo, int new_data) {
    if (*PrimerNodo == NULL) {
        printf("List is empty. No Nodo to delete.\n");
        return;
    }
    Nodo *current, *prev;
    current = *PrimerNodo;

    while (current->dato != new_data) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
}

void showFirst(Nodo* PrimerNodo) {
    Nodo* current = PrimerNodo;
    if (current == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d  \n", current->dato);
}

void showLast(Nodo* PrimerNodo) {
    Nodo* current = PrimerNodo;
    if (current == NULL) {
        printf("NULL\n");
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    printf("%d  \n", current->dato);
}
