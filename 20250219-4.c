#include <stdio.h>  // 引入標準輸入輸出庫
#include <stdlib.h> // 引入標準庫

 #define MAX_SIZE 10000 // 定義最大堆積大小

int leftHeap[MAX_SIZE], leftSize = 0;    // 最大堆積，用於存放較小的一半數字
int rightHeap[MAX_SIZE], rightSize = 0;  // 最小堆積，用於存放較大的一半數字

// 函數：將元素插入最大堆積並維持堆積性質
void maxHeapifyUp(int heap[], int index) {
    // 當前元素比父節點大時，交換它們的位置
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        int temp = heap[index]; // 暫存當前元素
        heap[index] = heap[(index - 1) / 2]; // 將父節點移到當前位置
        heap[(index - 1) / 2] = temp; // 將暫存的當前元素移到父節點位置
        index = (index - 1) / 2; // 更新當前元素索引為父節點索引
    }
}

// 函數：從最大堆積中取出最大元素並維持堆積性質
int maxHeapPop(int heap[], int *size) {
    int top = heap[0]; // 取出堆頂元素
    heap[0] = heap[--(*size)]; // 將最後一個元素移到堆頂，並減少堆積大小
    
    int index = 0; // 初始化索引為堆頂
    // 維持最大堆積性質
    while (index * 2 + 1 < *size) { // 當左子節點存在時
        int largest = index; // 初始化最大值索引為當前索引
        int left = index * 2 + 1, right = index * 2 + 2; // 左右子節點索引

        if (heap[left] > heap[largest]) largest = left; // 如果左子節點大於當前節點，更新最大值索引
        if (right < *size && heap[right] > heap[largest]) largest = right; // 如果右子節點存在且大於當前最大值，更新最大值索引

        if (largest == index) break; // 如果最大值索引未變，跳出迴圈

        int temp = heap[index]; // 暫存當前元素
        heap[index] = heap[largest]; // 將最大值元素移到當前位置
        heap[largest] = temp; // 將暫存的當前元素移到最大值位置
        index = largest; // 更新當前索引為最大值索引
    }
    return top; // 返回堆頂元素
}

// 函數：將元素插入最小堆積並維持堆積性質
void minHeapifyUp(int heap[], int index) {
    // 當前元素比父節點小時，交換它們的位置
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        int temp = heap[index]; // 暫存當前元素
        heap[index] = heap[(index - 1) / 2]; // 將父節點移到當前位置
        heap[(index - 1) / 2] = temp; // 將暫存的當前元素移到父節點位置
        index = (index - 1) / 2; // 更新當前元素索引為父節點索引
    }
}

// 函數：從最小堆積中取出最小元素並維持堆積性質
int minHeapPop(int heap[], int *size) {
    int top = heap[0]; // 取出堆頂元素
    heap[0] = heap[--(*size)]; // 將最後一個元素移到堆頂，並減少堆積大小

    int index = 0; // 初始化索引為堆頂
    // 維持最小堆積性質
    while (index * 2 + 1 < *size) { // 當左子節點存在時
        int smallest = index; // 初始化最小值索引為當前索引
        int left = index * 2 + 1, right = index * 2 + 2; // 左右子節點索引

        if (heap[left] < heap[smallest]) smallest = left; // 如果左子節點小於當前節點，更新最小值索引
        if (right < *size && heap[right] < heap[smallest]) smallest = right; // 如果右子節點存在且小於當前最小值，更新最小值索引

        if (smallest == index) break; // 如果最小值索引未變，跳出迴圈

        int temp = heap[index]; // 暫存當前元素
        heap[index] = heap[smallest]; // 將最小值元素移到當前位置
        heap[smallest] = temp; // 將暫存的當前元素移到最小值位置
        index = smallest; // 更新當前索引為最小值索引
    }
    return top; // 返回堆頂元素
}

// 函數：插入數字並維持兩個堆積的平衡
void insertNumber(int num) {
    // 插入數字到最大堆積或最小堆積
    if (leftSize == 0 || num <= leftHeap[0]) { // 如果最大堆積為空或數字小於等於最大堆積的堆頂
        leftHeap[leftSize] = num; // 將數字插入最大堆積
        maxHeapifyUp(leftHeap, leftSize); // 維持最大堆積性質
        leftSize++; // 增加最大堆積大小
    } else { // 否則
        rightHeap[rightSize] = num; // 將數字插入最小堆積
        minHeapifyUp(rightHeap, rightSize); // 維持最小堆積性質
        rightSize++; // 增加最小堆積大小
    }

    // 維持兩個堆積的平衡
    if (leftSize > rightSize + 1) { // 如果最大堆積的大小比最小堆積大超過1
        rightHeap[rightSize] = maxHeapPop(leftHeap, &leftSize); // 將最大堆積的堆頂移到最小堆積
        minHeapifyUp(rightHeap, rightSize); // 維持最小堆積性質
        rightSize++; // 增加最小堆積大小
    } else if (rightSize > leftSize) { // 如果最小堆積的大小比最大堆積大
        leftHeap[leftSize] = minHeapPop(rightHeap, &rightSize); // 將最小堆積的堆頂移到最大堆積
        maxHeapifyUp(leftHeap, leftSize); // 維持最大堆積性質
        leftSize++; // 增加最大堆積大小
    }
}

// 函數：取得目前所有數字的中位數
int getMedian() {
    // 如果總數是奇數，中位數是最大堆積的堆頂
    if ((leftSize + rightSize) % 2 == 1) {
        return leftHeap[0];
    } else {
        // 如果總數是偶數，中位數是兩個堆頂的平均值
        return ( (long long) leftHeap[0] + rightHeap[0]) / 2;
    }
}

int main() {
    int num;
    // 持續從使用者輸入數字，直到輸入結束
    while (scanf("%d", &num) != EOF) {
        insertNumber(num); // 插入數字並維持堆積平衡
        printf("%d\n", getMedian()); // 列印目前的中位數
    }
    return 0;
}