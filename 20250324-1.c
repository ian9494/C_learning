#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data; // 節點的資料
    struct Node *next; // 指向下一個節點的指標
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // 分配記憶體給新節點
    newNode->data = data; // 設定新節點的資料
    newNode->next = NULL; // 設定新節點的指標為 NULL
    return newNode;
}

void insertSorted(Node **head, int data) { // Node **head 是指向指標的指標
    Node *newNode = createNode(data); // 建立要插入的新節點
    // 如果鏈表是空的或是新節點的資料比第一個節點的資料小
    if (*head == NULL || (*head)->data >= data) {
        // 這裡可以達成新節點插到第一個節點的前面，並且把原本的第一個節點接在新節點後面
        newNode->next = *head; // 新節點的指標指向第一個節點
        *head = newNode; // head 指標指向新節點

    // 如果新節點的資料比第一個節點的資料大
    } else {
        Node *current = *head;
        // 一路往下找，直到找到新節點要插入的位置
        while (current->next != NULL && current->next->data < data) { // 找到新節點要插入的位置
            current = current->next; // 將正在比較的節點指標往下移
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int calculateSum(Node *head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    int sum = 0;
    float average = 0.0;


    srand(time(NULL));
    
    for (int i = 0; i < 25; i++) {
        int randomValue = rand() % 101;
        insertSorted(&head, randomValue);
    }

    sum = calculateSum(head);
    average = (float)sum / 25.0;

    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        freeList(head);
        return 1;
    }

    fprintf(file, "elements in the list: ");
    Node *current = head;
    while (current != NULL) {
        fprintf(file, "%d ", current->data);
        current = current->next;
    }
    fprintf(file, "\nsum of the elements: %d\n", sum);
    fprintf(file, "average of the elements: %.2f\n", average);

    fclose(file);
    printf("File written successfully\n");

    freeList(head);
    return 0;
}