#include <stdlib.h> //malloc realloc free
#include <stdio.h> //printf

struct IntArray
{
    int* container;
    int size;
    int maxSize;
};

void InitIntArray (struct IntArray* arr, int startSize)
{
    arr->container = malloc (startSize * sizeof(int));
    arr->maxSize = startSize;
    arr->size =0;
};

void FreeIntArray (struct IntArray* arr) 
{
    free (arr->container);
}

void Resize (struct IntArray* arr, int newSize)
{
    printf ("new size is: %d\n", newSize);
    arr->container = realloc (arr->container, newSize * sizeof(int));
    arr->maxSize = newSize;
}

void InsertItem (struct IntArray* arr,int elem)
{
    if (arr->size == arr->maxSize) {
        Resize (arr, arr->maxSize * 2);
    }
    arr->container[arr->size] = elem;
    arr->size++;
}

int GetItem (struct IntArray* arr,int index)
{
    if (index < 0 || index >= arr->size) {
        printf ("out of range\n");
        exit (1);
    }
    return arr->container[index];
}

void EraseElement (struct IntArray* arr,int index)
{
    if (arr->size == 0) {
        printf ("out of range\n");
        exit (1);
    }
    //arr->container[index] = arr->container[arr->size-1];
    //arr->size--;

    for (size_t i = index; i < arr->size-1; i++)
    {
        arr->container[i] = arr->container[i+1];
    }
    arr->size--;
}

int main(int argc, char const *argv[])
{
    struct IntArray myArray;
    InitIntArray (&myArray, 4);

    for (size_t i = 0; i < 10; i++)
       InsertItem (&myArray,i);
    
    EraseElement (&myArray,4);

    for (size_t i = 0; i < myArray.size; i++)
       printf("%d\n", GetItem (&myArray, i));
    
    printf ("size of the array: %d\n",myArray.size);
    
   
    FreeIntArray (&myArray);
    return 0;
}
