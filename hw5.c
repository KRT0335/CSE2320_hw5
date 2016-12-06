#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_p{
  char* key;
  char* spanish;
  struct node_p *left;
  struct node_p *right;
}node;

node *root = NULL;

node* insertBST(node *cnode, char *strinput, char *desp);
void searchBST(node **cnode, char *strinput, int count);
//node *rotR(node **cnode);
//node *rotL(node **cnode);

int main(){
    FILE *pfile;


    pfile = fopen("Spanish.txt", "r");
    char buf[1000];
    char *eng;
    char *span;
    char buf2[1000];
    char bduf[1000];
    //node* tree = (node *) malloc(sizeof(node));
    //tree->left = NULL;
    //tree->right = NULL;
    //node *root;
    int counter = 0, count = 0;

    if(!pfile)
        return 1;

        while(fgets(buf, sizeof(buf), pfile)!=NULL){
            if(buf[0] != '#')
            {

                //printf("%s", buf);
                eng = strtok(buf, " \t");
                //printf("%s\n", eng);

                if(eng != NULL){
                    span = strtok(NULL, "\n");
                    //printf("%s\n", span);
                }

                root = (node*)insertBST(root, eng, span);
                //scanf("%s", bduf);
                counter++;
            }
        }

        scanf("%s", buf2);
        searchBST(&root, buf2, count);


    printf("%d", counter);
    fclose(pfile);

    return 0;
}


node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}


node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}
/*
node *rotR(node **cnode){
    node **x = (*cnode)->left;
    (*cnode)->left = (*x)->right;
    (*x)->right = (*cnode);
    return (*x);
}

node *rotL(node **cnode){
    node **x = (*cnode)->right;
    (*cnode)->right = (*x)->left;
    (*x)->left = (*cnode);
    return (*x);
}
*/
node* insertBST(node *cnode, char *strinput, char *desp){
    if(cnode == NULL){
        (cnode) = (node*)malloc(sizeof(node));
        (cnode)->key = strdup(strinput);
        (cnode)->spanish = strdup(desp);
        (cnode)->left = NULL;
        (cnode)->right = NULL;
        //printf("%s\n", (*cnode)->key);
    }
    else{
        if(strcmp((char*)(cnode)->key, (char*)strinput) < 0){
            //printf("%s\t%s\n", (*cnode)->key, strinput);
            (cnode)->left = insertBST(((cnode)->left), strinput, desp);
            //cnode->right = rightRotate(cnode->right);
        }
        else if(strcmp((char*)(cnode)->key, (char*)strinput) > 0){
            //printf("%s\t%s\n", (*cnode)->key, strinput);
            (cnode)->right = insertBST(((cnode)->right), strinput, desp);
            //cnode->left = leftRotate(cnode->left);
        }
        else{
            //printf("%s\tnada\n", (char*)((*cnode)->right));
        }
    }
    return cnode;
}

void searchBST(node **cnode, char *strinput, int count){
    if(*cnode == NULL){
        printf("No\n");
    }
    else {
        count++;
        if(strcmp((char*)(*cnode)->key, (char*)strinput) == 0){
            printf("%s\t%s\n", strinput, (*cnode)->spanish);
            printf("%s\t%s\n", (*cnode)->key, (*cnode)->spanish);
            printf("%d\n", count);
        }
        else if(strcmp((char*)(*cnode)->key, (char*)strinput) < 0){
            //printf("%d\n", count);
            searchBST(&((*cnode)->left), strinput, count);
        }
        else if(strcmp((char*)(*cnode)->key, (char*)strinput) > 0){
            //printf("%d\n", count);
            searchBST(&((*cnode)->right), strinput, count);
        }
    }
}
