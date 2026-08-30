#include<stdio.h>
#define SIZE 10
int hashtable[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++) {
        hashtable[i] = -1;
    }
}

void insert(int key) {
    int index,i = 0;
    while(i < SIZE) {
        index = (key % SIZE + (i * i)) % SIZE;
        if(hashtable[index] == -1) {
            hashtable[index] = key;
            return;
        }
        i++;
    }
    printf("Hashtable is full\n");
}

void display() {
    for(int i = 0; i < SIZE; i++) {
        if(hashtable[i] == -1) {
            printf("%d : -1\n",i);
        } else {
            printf("%d : %d\n",i,hashtable[i]);
        }
    }
}

int main() {
    initialize();
    insert(24);
    insert(33);
    insert(34);
    insert(45);
    insert(29);
    insert(35);
    insert(22);
    insert(77);
    insert(96);
    insert(107);
    display();
    insert(98);

    return 0;
}


