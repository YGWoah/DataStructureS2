#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
    int val;
    struct noeud *fg;
    struct noeud *fd;
} noeud;

noeud *creer_noeud()
{
    noeud *n = (noeud *)malloc(sizeof(noeud));
    n->val = 0; // or any other value
    return n;
}

noeud *ajouter(int val, noeud *fg, noeud *fd)
{
    noeud *n = (noeud *)malloc(sizeof(noeud));
    n->val = val;
    n->fg = fg;
    n->fd = fd;
    return n;
}

void aficher(noeud *n)
{
    if (n != NULL) // this is the stop condition
    {
        printf("%d ", n->val);
        aficher(n->fg);
        aficher(n->fd);
    }
}

int getNb(noeud *n)
{
    if (n == NULL)
        return 0;
    else
        return 1 + getNb(n->fg) + getNb(n->fd);
}

int getFeille(noeud *n)
{
    if (n == NULL) // if the tree is empty
        return 0;
    else if (n->fg == NULL && n->fd == NULL) // if the tree is a leaf
        return 1;
    else
        return getFeille(n->fg) + getFeille(n->fd); // if the tree is not a leaf
}

int main()
{
    noeud *n = creer_noeud();
    n = ajouter(1, ajouter(2, NULL, NULL), ajouter(3, NULL, NULL));
    n = ajouter(4, n, ajouter(5, NULL, NULL));

    aficher(n);

    printf("les nomber de noeud est %d et les nomber de feille est %d", getNb(n), getFeille(n));
    return 0;
}