#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 1024
#define STATIC_CAPACITY 2024

typedef struct element{
    unsigned int *key;
} element_t;

typedef struct hash_table{
    element_t *elements;
} hash_table_t;

unsigned int hash_function(unsigned int x);
hash_table_t* ht_init(void);
bool ht_look_up(hash_table_t *table, unsigned int key);

int main(void)
{
    int numbers[SIZE];

    //unique seed value
    srand(time(NULL));

    hash_table_t *seen = ht_init();
    hash_table_t *dups = ht_init();

    for(int i = 0; i < SIZE; i++)
    {
        numbers[i] = rand() % 1024 + 1;
    }

    for(int i = 0; i < SIZE; i++)
    {
        if(ht_look_up(seen, numbers[i]))
            ht_look_up(dups, numbers[i]);
    }

    exit(0);
}

hash_table_t* ht_init(void)
{
    hash_table_t *table = malloc(sizeof (hash_table_t));
    if(table == NULL)
        return NULL;

    table->elements = calloc(STATIC_CAPACITY, sizeof(element_t));
    if(table->elements == NULL)
    {
        free(table);
        return NULL;
    }
    return table;
}

bool ht_look_up(hash_table_t *table, unsigned int key)
{
    unsigned int index = hash_function(key);

    //loop until key is found
    while (table->elements[index].key != NULL) {
        if(key == *(table->elements[index].key))
        {
            return true;
        }
        //Using linear probing
        index++;

        //reached end of table, loop to beginning
        if(index >= STATIC_CAPACITY)
        {
            index = 0;
        }
    }

    unsigned int *seen_elm = malloc(sizeof(int));
    table->elements[index].key = seen_elm;
    *table->elements[index].key = key;

    return false;
}

unsigned int hash_function(unsigned int x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) % STATIC_CAPACITY;
    return x;
}

