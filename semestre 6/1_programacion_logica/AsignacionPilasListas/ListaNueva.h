/* 
 * File:   ListaNueva.h
 * Author: luis13711
 *
 * Created on 26 de marzo de 2015, 08:08 PM
 */

#ifndef LISTANUEVA_H
#define	LISTANUEVA_H



#include <stdio.h>   /* for printf */
#include <stdlib.h>  /* for malloc */
template<class T>
class ListaSimple{
    private:
        T data;
        ListaSimple<T> *next;
    public:
        ListaSimple(void){
            this->next=NULL;
        }
        ~ListaSimple(void){
        }
        ListaSimple<T>* list_add(T i);
};
ListaSimple<T>* ListaSimple<T>::list_add(T i) {
    /* algunos compiladores no requieren un casting del valor del retorno para malloc  */
    ListaSimple<T> *n = new ListaSimple<T>();
    if (next == NULL){
        this->data=i;
        return this;
    }
    else{
    n->next = this;                                                                            
    this = n;
    n->data = i;
    return n;
    }
}
typedef struct ns {
	int data;
	struct ns *next;
} node;
 
node *list_add(node **p, int i) {
    /* algunos compiladores no requieren un casting del valor del retorno para malloc  */
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
        return NULL;
    n->next = *p;                                                                            
    *p = n;
    n->data = i;
    return n;
}
 
void list_remove(node **p) { /* borrar cabeza*/
    if (*p != NULL) {
        node *n = *p;
	*p = (*p)->next;
	free(n);
    }
}
 
node **list_search(node **n, int i) {
    while (*n != NULL) {
        if ((*n)->data == i) {
            return n;
        }
        n = &(*n)->next;
    }
    return NULL;
}
 
void list_print(node *n) {
    if (n == NULL) {
        printf("lista esta vacía\n");
    }
    while (n != NULL) {
        printf("print %p %p %d\n", n, n->next, n->data);
        n = n->next;
    }
}

#endif	/* LISTANUEVA_H */

