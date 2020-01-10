#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
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
  
// Returns new trie node (initialized to NULLs) 
node *getNode(void) 
{ 
    node *root = NULL; 
  
    root  = (node *)malloc(sizeof(node)); 
  
    if (root ) 
    { 
        int i; 
		
		root -> count = 0;
		
        root ->isEndOfWord = false; 
  
        for (i = 0; i < NUM_LETTERS; i++) 
            root ->children[i] = NULL; 
    } 
  
    return root; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just marks leaf node 
void insert(node *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
	char letter;
	
    node *temp = root; 
	
    for (level = 0; level < length; level++) 
    { 
		letter = key[level];
		if (key[level] >= 'A' && key[level] <= 'Z'){
			letter = key[level]-'A'+'a'; // to short case 
		}
        index = CHAR_TO_INDEX(letter); 
        if (!temp->children[index]) 
            temp->children[index] = getNode(); 
  
        temp = temp->children[index]; 
    } 
  
    // mark last node as leaf 
    temp->isEndOfWord = true; 
	temp->count++;
} 

  

//print the trie from a-z 
void print(node *root, char temp[], int pos , bool reverse) 
{ 
    if (root->isEndOfWord)  
    { 
        temp[pos] = '\0'; 
        printf("%s	%d\n" , temp, root->count); 
    } 
  
    int i; 
    if (reverse){
		for (i = NUM_LETTERS-1; i >= 0; i--)  
		{  
			if (root->children[i])  
			{ 
				temp[pos] = INDEX_TO_CHAR(i); 
				print(root->children[i], temp, pos + 1 , reverse); 
			} 
		} 
    }
	
	else{
		for (i = 0; i < NUM_LETTERS; i++)  
		{  	
			if (root->children[i])  
			{	 
				temp[pos] = INDEX_TO_CHAR(i); 
				print(root->children[i], temp, pos + 1 , reverse); 
			} 
		} 
	}
} 

void deleteTrie(node *root){
	if(!root) return;
	for (int i = 0; i < NUM_LETTERS; i++)  
	{  	
		if (root->children[i])  
		{	  
			deleteTrie(root->children[i]); 
		} 
	}
    free(root);	
}



 
