#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int data;
    int height;
};
int NodeHeight(struct Node *p)
{
    int hl = 0, hr = 0;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}
int BalanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl, *plr;
    pl = p->lchild;
    plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    // if(root==p) root=pl;
    return pl;
}
struct Node *LRRotation(struct Node *p)
{
    struct Node *pl, *plr;
    pl = p->lchild;
    plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    // if(root==p) root=plr;
    return plr;
}
struct Node *RRRotation(struct Node *p)
{
    struct Node *pr, *prl;
    pr = p->rchild;
    prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    // if(root==p) root=pr;
    return pr;
}
struct Node *RLRotation(struct Node *p)
{
    struct Node *pr, *prl;
    pr = p->rchild;
    prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);
    // if(root==p) root=prl;
    return prl;
}
struct Node *InsertRecusriveAVl(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = InsertRecusriveAVl(p->lchild, key);
    else if (key > p->data)
        p->rchild = InsertRecusriveAVl(p->rchild, key);
    else
        return p;
    p->height = NodeHeight(p);
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RRRotation(p);
    if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RLRotation(p);
    return p;
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
struct Node *BSTSearch(struct Node *root, int data)
{
    struct Node *p = root;
    while (p != NULL)
    {
        if (p->data == data)
            return p;
        else if (data < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}
struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}
struct Node *InSuc(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}
int Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
struct Node *AVLDelete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->lchild = AVLDelete(p->lchild, key);
    else if (key > p->data)
        p->rchild = AVLDelete(p->rchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = AVLDelete(p->lchild, q->data);
        }
        else
        {
            q = InSuc(p->rchild);
            p->data = q->data;
            p->rchild = AVLDelete(p->rchild, q->data);
        }
    }
    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    { // L1 Rotation
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    { // L-1 Rotation
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    { // R-1 Rotation
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    { // R1 Rotation
        return RLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0)
    { // L0 Rotation
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0)
    { // R0 Rotation
        return RRRotation(p);
    }

    return p;
}
int main()
{
    struct Node *root = NULL;
    root = InsertRecusriveAVl(root, 50);
    root = InsertRecusriveAVl(root, 40);
    root = InsertRecusriveAVl(root, 20);
    root = InsertRecusriveAVl(root, 10);
    root = InsertRecusriveAVl(root, 42);
    root = InsertRecusriveAVl(root, 46);
    Inorder(root);
    printf("\n");
    Preorder(root);
    AVLDelete(root, 20);
    printf("\n");
    Inorder(root);
    AVLDelete(root, 42);
    printf("\n");
    Inorder(root);
    AVLDelete(root, 40);
    printf("\n");
    Inorder(root);
    printf("\n%d", root->height);
    return 0;
}
