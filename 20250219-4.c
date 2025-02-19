    #include <stdio.h>
    #include <stdlib.h>

    #define MAX_SIZE 10000

    int leftHeap[MAX_SIZE], leftSize = 0;    
    int rightHeap[MAX_SIZE], rightSize = 0;  

    void maxHeapifyUp(int heap[], int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            int temp = heap[index];
            heap[index] = heap[(index - 1) / 2];
            heap[(index - 1) / 2] = temp;
            index = (index - 1) / 2;
        }
    }

    int maxHeapPop(int heap[], int *size) {
        int top = heap[0];
        heap[0] = heap[--(*size)];
        
        int index = 0;
        while (index * 2 + 1 < *size) {
            int largest = index;
            int left = index * 2 + 1, right = index * 2 + 2;

            if (heap[left] > heap[largest]) largest = left;
            if (right < *size && heap[right] > heap[largest]) largest = right;

            if (largest == index) break;

            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            index = largest;
        }
        return top;
    }

    void minHeapifyUp(int heap[], int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            int temp = heap[index];
            heap[index] = heap[(index - 1) / 2];
            heap[(index - 1) / 2] = temp;
            index = (index - 1) / 2;
        }
    }

    int minHeapPop(int heap[], int *size) {
        int top = heap[0];
        heap[0] = heap[--(*size)];

        int index = 0;
        while (index * 2 + 1 < *size) {
            int smallest = index;
            int left = index * 2 + 1, right = index * 2 + 2;

            if (heap[left] < heap[smallest]) smallest = left;
            if (right < *size && heap[right] < heap[smallest]) smallest = right;

            if (smallest == index) break;

            int temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;
            index = smallest;
        }
        return top;
    }

    void insertNumber(int num) {
        if (leftSize == 0 || num <= leftHeap[0]) {
            leftHeap[leftSize] = num;
            maxHeapifyUp(leftHeap, leftSize);
            leftSize++;
        } else {
            rightHeap[rightSize] = num;
            minHeapifyUp(rightHeap, rightSize);
            rightSize++;
        }

        if (leftSize > rightSize + 1) {
            rightHeap[rightSize] = maxHeapPop(leftHeap, &leftSize);
            minHeapifyUp(rightHeap, rightSize);
            rightSize++;
        } else if (rightSize > leftSize) {
            leftHeap[leftSize] = minHeapPop(rightHeap, &rightSize);
            maxHeapifyUp(leftHeap, leftSize);
            leftSize++;
        }
    }

    int getMedian() {
        if ((leftSize + rightSize) % 2 == 1) {
            return leftHeap[0];
        } else {
            return ( (long long) leftHeap[0] + rightHeap[0]) / 2;
        }
    }

    int main() {
        int num;
        while (scanf("%d", &num) != EOF) {
            insertNumber(num);
            printf("%d\n", getMedian());
        }
        return 0;
    }