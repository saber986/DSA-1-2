#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createHeap(int capacity) {
    MaxHeap *heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->data = (int*)malloc(capacity * sizeof(int));
    return heap;
}

int getParent(int i) {
    return (i - 1) / 2;
}

int getLeft(int i) {
    return 2 * i + 1;
}

int getRight(int i) {
    return 2 * i + 2;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void siftUp(MaxHeap *heap, int index) {
    while (index > 0 && heap->data[getParent(index)] < heap->data[index]) {
        swap(&heap->data[index], &heap->data[getParent(index)]);
        index = getParent(index);
    }
}

void insert(MaxHeap *heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        return;
    }

    heap->data[heap->size] = value;
    siftUp(heap, heap->size);
    heap->size++;
}

void siftDown(MaxHeap *heap, int index) {
    int largest = index;
    int left = getLeft(index);
    int right = getRight(index);

    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;

    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        siftDown(heap, largest);
    }
}

int extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int maxValue = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    siftDown(heap, 0);

    return maxValue;
}

void printHeap(MaxHeap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

void freeHeap(MaxHeap *heap) {
    free(heap->data);
    free(heap);
}

int main() {
    MaxHeap *heap = createHeap(10);

    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 40);
    insert(heap, 50);
    insert(heap, 100);

    printf("Heap after insertions: ");
    printHeap(heap);

    printf("Extracted Max: %d\n", extractMax(heap));

    printf("Heap after extraction: ");
    printHeap(heap);

    freeHeap(heap);
    return 0;
}
