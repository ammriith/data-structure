#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node *bst, int data);
void display(struct node *bst);
struct node* search(struct node *bst, int data);
struct node* delete(struct node *bst, int data);

void main() {
    struct node *root = NULL; // null bst
    int opt, data;

    do {
        printf("\n 1.Insert \n 2.Search \n 3.Delete \n 4.Display \n 5.Exit\n Enter your option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                if (search(root, data) == NULL)
                    printf("Not found\n");
                else
                    printf("Found\n");
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 4:
                display(root);
                break;
            case 5:
                exit(0);
        }
    } while (1);
}

// display bst contents-inorder
void display(struct node *bst) {
    if (bst != NULL) {
        display(bst->left);
        printf("%d\t", bst->data);
        display(bst->right);
    }
}

// to insert data in bst
struct node* insert(struct node *bst, int data) {
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->left = t->right = NULL;

    if (bst == NULL) { // case of null bst
        return t;
    } else {
        struct node *t1 = bst;
        while (1) {
            if (data < t1->data) {
                if (t1->left == NULL) {
                    t1->left = t;
                    break;
                }
                t1 = t1->left;
            } else if (data > t1->data) {
                if (t1->right == NULL) {
                    t1->right = t;
                    break;
                }
                t1 = t1->right;
            } else {
                printf("Duplicate \n");
                free(t);
                break;
            }
        }
        return bst;
    }
}

// to search an item
struct node* search(struct node *bst, int data) {
    while (bst != NULL && bst->data != data) {
        if (data < bst->data)
            bst = bst->left;
        else
            bst = bst->right;
    }
    return bst; // Returns NULL if not found
}

// to delete an item from bst
struct node* delete(struct node *bst, int data) {
    struct node *t1 = bst, *t2 = NULL, *sucpar = NULL, *suc = NULL;

    while (t1 != NULL && t1->data != data) {
        t2 = t1;
        if (data < t1->data)
            t1 = t1->left;
        else
            t1 = t1->right;
    }

    if (t1 == NULL) {
        printf("Item not found\n");
        return bst;
    }

    // Case 1: Node has no children (leaf node)
    if (t1->left == NULL && t1->right == NULL) {
        if (t2 != NULL) {
            if (t2->left == t1)
                t2->left = NULL;
            else
                t2->right = NULL;
        } else {
            bst = NULL; // Deleting the root node
        }
        free(t1);
    }
    // Case 2: Node has one child
    else if (t1->left == NULL || t1->right == NULL) {
        struct node *child = (t1->left != NULL) ? t1->left : t1->right;
        if (t2 != NULL) {
            if (t2->left == t1)
                t2->left = child;
            else
                t2->right = child;
        } else {
            bst = child; // Deleting the root node
        }
        free(t1);
    }
    // Case 3: Node has two children
    else {
        sucpar = t1;
        suc = t1->right;
        while (suc->left != NULL) {
            sucpar = suc;
            suc = suc->left;
        }

        // Copy the inorder successor's content to this node
        t1->data = suc->data;

        // Delete the inorder successor
        if (sucpar->left == suc)
            sucpar->left = suc->right;
        else
            sucpar->right = suc->right;

        free(suc);
    }

    return bst;
}

