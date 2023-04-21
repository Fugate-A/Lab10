
//------------------------------------------------------------

//

//------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    struct Trie *temp = *ppTrie;

    if( temp == NULL )
    {
        temp = calloc( 1, sizeof( struct Trie ) );
        *ppTrie = temp;
    }
 
    for( int alpha = 0; word[alpha] != '\0'; alpha++ )
    {
        char spot = word[alpha];

        if( spot >= 'a' && spot <= 'z' )
        {
            spot = spot - 'a';

            if( temp -> children[spot] == NULL )
            {
                temp -> children[spot] = calloc( 1, sizeof( struct Trie ) );
            }

            temp = temp -> children[spot];
        }
    }

    temp -> count++;

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

    for( int alpha = 0; word[alpha] != '\0'; alpha++ )
    {
        char spot = word[alpha];

        if( spot >= 'a' && spot <= 'z' )
        {
            spot = spot - 'a';

            pTrie = pTrie -> children[spot];

            if( pTrie == NULL )
            {
                return 0;
            }
        }
    }
    return pTrie -> count;
}
//------------------------------------------------------------

//

//------------------------------------------------------------
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    if( pTrie != NULL )
    {
        for( int i = 0; i < 26; i++ )
        {
            pTrie -> children[i] = deallocateTrie( pTrie -> children[i] );
        }

        free(pTrie);
    }

    free(pTrie);

    return NULL;
}
//------------------------------------------------------------

//

//------------------------------------------------------------
int main(void)
{
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

    struct Trie *trie = NULL;

    //read the number of the words in the dictionary
    //int size = sizeof(pWords) / sizeof(char);
    int size = 5;

    // parse line  by line, and insert each word to the trie data structure
    for( int i = 0; i < size; i++ )
    {
        insert( &trie, pWords[i] );
    }
    //

    for( int i = 0 ; i < size; i++ )
    {
        printf("\t%s : %d\n",pWords[i], numberOfOccurances(trie, pWords[i]));
    }
    
    trie = deallocateTrie(trie);
    
    if( trie != NULL )
    {
        printf("There is an error in this program\n");
    }

    return 0;
}
//------------------------------------------------------------

//

//------------------------------------------------------------
