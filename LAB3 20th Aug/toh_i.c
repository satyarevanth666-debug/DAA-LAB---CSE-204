#include <stdio.h>

#define MAX 100

// Three arrays representing the three poles
int src_arr[MAX], aux_arr[MAX], dest_arr[MAX];
int src_top = -1, aux_top = -1, dest_top = -1;

// Push function
void push(int arr[], int *top, int disk)
{
    if (*top == MAX - 1)
        return;

    arr[++(*top)] = disk;
}

// Pop function
int pop(int arr[], int *top)
{
    if (*top == -1)
        return -1;

    return arr[(*top)--];
}

// Print the move
void printMove(char fromPole, char toPole, int disk)
{
    printf("Move disk %d from pole %c to pole %c\n",
           disk, fromPole, toPole);
}

// Move disks between two poles
void moveDisksBetweenTwoPoles(
    int arr1[], int *top1,
    int arr2[], int *top2,
    char pole1, char pole2)
{
    int topDisk1 = pop(arr1, top1);
    int topDisk2 = pop(arr2, top2);

    // Pole 1 is empty
    if (topDisk1 == -1)
    {
        push(arr1, top1, topDisk2);
        printMove(pole2, pole1, topDisk2);
    }

    // Pole 2 is empty
    else if (topDisk2 == -1)
    {
        push(arr2, top2, topDisk1);
        printMove(pole1, pole2, topDisk1);
    }

    // Disk 2 is smaller
    else if (topDisk1 > topDisk2)
    {
        push(arr1, top1, topDisk1);
        push(arr1, top1, topDisk2);

        printMove(pole2, pole1, topDisk2);
    }

    // Disk 1 is smaller
    else
    {
        push(arr2, top2, topDisk2);
        push(arr2, top2, topDisk1);

        printMove(pole1, pole2, topDisk1);
    }
}

int main()
{
    int num_of_disks = 3;

    char s = 'A';
    char a = 'B';
    char d = 'C';

    // For even number of disks, swap auxiliary and destination
    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }

    // Put disks onto source pole
    for (int i = num_of_disks; i >= 1; i--)
    {
        push(src_arr, &src_top, i);
    }

    // Total number of moves = 2^n - 1
    int total_moves = (1 << num_of_disks) - 1;

    // Perform all moves
    for (int i = 1; i <= total_moves; i++)
    {
        if (i % 3 == 1)
        {
            moveDisksBetweenTwoPoles(
                src_arr, &src_top,
                dest_arr, &dest_top,
                s, d);
        }
        else if (i % 3 == 2)
        {
            moveDisksBetweenTwoPoles(
                src_arr, &src_top,
                aux_arr, &aux_top,
                s, a);
        }
        else
        {
            moveDisksBetweenTwoPoles(
                aux_arr, &aux_top,
                dest_arr, &dest_top,
                a, d);
        }
    }

    return 0;
}