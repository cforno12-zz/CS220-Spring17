#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct tnode {
   struct tnode * left;
   struct tnode * right;
   int value;
};

struct tnode * makeNode(int value);
void freeTree(struct tnode * t);

void insertVal(struct tnode * t, int value);
void prLVR(struct tnode * t);
void prRVL(struct tnode * t);
void printTree(struct tnode * t, char * prefix);

int main(int argc, char **argv) {
   int i;

   if (argc<2) {
		printf("You must specify at least one argument to %s\n",argv[0]);
		return 1;
	}
	struct tnode * root=makeNode(atoi(argv[1]));
   for(i=2; i<argc; i++) {
      int val=atoi(argv[i]);
      insertVal(root,val);
   }
   printf("In LVR order: ");
   prLVR(root);
   printf("\nIn RVL order: ");
   prRVL(root);
   printf("\nGraphic Representation...\n");
   printTree(root,"");
   freeTree(root);
   return 0;
}

struct tnode * makeNode(int value) {
   struct tnode * t = malloc(sizeof(struct tnode));
   t->value=value;
   t->left=NULL;
   t->right=NULL;
   return t;
}

void freeTree(struct tnode * t) {
   assert(t);
   if (t->left) freeTree(t->left);
   if (t->right) freeTree(t->right);
   free(t);
}

void insertVal(struct tnode * t, int value) {
	assert(t);
   if(value <= t->value){
      if(t->left == NULL){
         t->left = makeNode(value);
      } else {
         insertVal(t->left, value);
      }
   } else if (value > t->value){
      if(t->right == NULL){
         t->right = makeNode(value);
      } else {
         insertVal(t->right, value);
      }
   }
}

void prLVR(struct tnode * t) {
	assert(t);
    if(t->left != NULL){
        prLVR(t->left);
    }
    printf("%i ", t->value);
    if(t->right != NULL){
        prLVR(t->right);
    }
}


void prRVL(struct tnode * t) {
    assert(t);
    if(t->right != NULL){
        prRVL(t->right);
    }
    printf("%i ", t->value);
    if(t->left != NULL){
        prRVL(t->left);
    }
}

void printTree(struct tnode * t, char * prefix) {
	assert(t);
    if(t->right!=NULL){
        printf("%s", prefix);
        printTree(t->right,"   |");
    }
    if(t->right==NULL&&t->left==NULL){
        printf("%s%d\n", prefix, t->value);
    } else {
        printf("%s%d+\n",prefix, t->value);
    }
    if(t->left!=NULL){
        printf("%s", prefix);
        printTree(t->left, "   |");
    }

}
