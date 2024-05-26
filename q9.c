#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 32
#define STATIC_CAPACITY 64

typedef struct element{
    unsigned int *key;
    bool duplicated;
} element_t;

typedef struct hash_table{
    element_t *elements;
} hash_table_t;

unsigned int hash_function(unsigned int x);
hash_table_t* ht_init(void);
void ht_insert(hash_table_t *table, unsigned int key);

int main(void)
{
    int numbers[SIZE];

    //unique seed value
    srand(time(NULL));

    //initialize two hash tables
    hash_table_t *seen = ht_init();

    printf("Original Numbers:\n");
    for(int i = 0; i < SIZE; i++)
    {
        numbers[i] = (rand() % SIZE) + 1;
        printf("%d, ", numbers[i]);
    }

    for(int i = 0; i < SIZE; i++)
        ht_insert(seen, numbers[i]); //Check if seen, if not store new value

    printf("\n\nDuplicates:\n");
    for(int i = 0; i < STATIC_CAPACITY; i++)
    {
        if(seen->elements[i].duplicated)
            printf("%u, ", *seen->elements[i].key);
    }
    exit(0);
}

hash_table_t* ht_init(void)
{
    //allocate memory for table and spaces
    hash_table_t *table = malloc(sizeof (hash_table_t));
    if(table == NULL)
        exit(1);

    table->elements = calloc(STATIC_CAPACITY, sizeof(element_t));
    if(table->elements == NULL)
        exit(1);
    return table;
}

void ht_insert(hash_table_t *table, unsigned int key)
{
    unsigned int index = hash_function(key); //generate hash value

    //loop until key is found
    while (table->elements[index].key != NULL) {
        if (key == *(table->elements[index].key))
        {
            table->elements[index].duplicated = true; //Set duplicate marker to true
            return;
        }
        //Using linear probing
        index++;

        //reached end of table, loop to beginning
        if(index >= STATIC_CAPACITY)
            index = 0;
    }

    //set new entry
    unsigned int *seen_elm = malloc(sizeof(int));
    table->elements[index].key = seen_elm;
    *table->elements[index].key = key;
    table->elements[index].duplicated = false;
}

unsigned int hash_function(unsigned int x) //generate hash values
{
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) % STATIC_CAPACITY;
    return x;
}