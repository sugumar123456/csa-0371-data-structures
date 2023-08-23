#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct HashTable {
    int keys[SIZE];
    int values[SIZE];
};

void initHashTable(struct HashTable *hashTable) {
    for (int i = 0; i < SIZE; i++) {
        hashTable->keys[i] = -1; // -1 indicates an empty slot
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(struct HashTable *hashTable, int key, int value) {
    int index = hashFunction(key);

    while (hashTable->keys[index] != -1) {
        index = (index + 1) % SIZE; // Linear probing
    }

    hashTable->keys[index] = key;
    hashTable->values[index] = value;
}

int search(struct HashTable *hashTable, int key) {
    int index = hashFunction(key);

    while (hashTable->keys[index] != -1) {
        if (hashTable->keys[index] == key) {
            return hashTable->values[index];
        }
        index = (index + 1) % SIZE; // Linear probing
    }

    return -1; // Key not found
}

int main() {
    struct HashTable hashTable;
    initHashTable(&hashTable);

    insert(&hashTable, 5, 25);
    insert(&hashTable, 15, 225);
    insert(&hashTable, 25, 625);

    int value = search(&hashTable, 15);
    if (value != -1) {
        printf("Value for key 15: %d\n", value);
    } else {
        printf("Key 15 not found.\n");
    }

    return 0;
}
