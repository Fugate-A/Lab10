
//------------------------------------------------------------

//

//------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------------

//

//------------------------------------------------------------
struct Trie
{
    int count;
    struct Trie *children[26];
};
//------------------------------------------------------------

//

//------------------------------------------------------------
void insert(struct Trie **ppTrie, char *word);
int numberOfOccurances(struct Trie *pTrie, char *word);
struct Trie *deallocateTrie(struct Trie *pTrie);
//------------------------------------------------------------

//

//------------------------------------------------------------
void insert(struct Trie **ppTrie, char *word)
{
    //
}
//------------------------------------------------------------

//

//------------------------------------------------------------
int numberOfOccurances(struct Trie *pTrie, char *word)
{
    if( pTrie == NULL )
    {
        return 0;
    }

    for( int i = 0; word[i] != NULL; i++ )
    {
        int temp = word[i] - 'a';

        pTrie = pTrie -> children[temp];

        if( pTrie == NULL )
        {
            return 0;
        }
    }

    return pTrie -> count;
}
//------------------------------------------------------------

//

//------------------------------------------------------------
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    //
}
//------------------------------------------------------------

//

//------------------------------------------------------------



//------------------------------------------------------------

//

//------------------------------------------------------------
int main(void)
{
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

    struct Trie *trie = NULL;

    //read the number of the words in the dictionary
    int size = sizeof(pWords) / sizeof(char);

    // parse line  by line, and insert each word to the trie data structure
    for( int i = 0; i < size; i++ )
    {
        insert( &trie, pWords[i] );
    }
    //
    
    for( int i = 0 ; i < size; i++ )
    {
        printf("\t%s : %d\n",pWords[i], numberOfOccurances(&trie, pWords[i]));
    }
    
    trie = deallocateTree(&trie);
    
    if( trie != NULL )
    {
        printf("There is an error in this program\n");
    }

    return 0;
}
//------------------------------------------------------------

//

//------------------------------------------------------------
