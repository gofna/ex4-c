#ifndef _TRIE_H
#define _TRIE_H
#include <stdbool.h> 
  

#define NUM_LETTERS (26) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
#define INDEX_TO_CHAR(i) ((int)i + (int)'a') 
#define LINE 256

// trie node 
typedef struct node 
{ 
    struct node *children[NUM_LETTERS]; 
	
	int count;

    bool isEndOfWord; 
}node;

node *getNode(void);
void insert(node *root, const char *key);
void print(node *root, char temp[], int pos , bool reverse); 
void deleteTrie(node *root);

#endif