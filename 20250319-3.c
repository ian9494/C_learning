#include <stdio.h>
#include <stdlib.h>

// 定義鏈結串列節點
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL; // 鏈結串列的起始點
int created = 0; // 是否已經創建過鏈結串列

// 列印鏈結串列
void printList() {
    Node* temp = head;
    if (temp == NULL) {
        printf("\n");
        return;
    }

    while (temp != NULL) {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 插入節點（保持排序）
void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // 如果已經有節點了則不添加
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printList(); // **每次插入後印出鏈結串列**
            return;
        }
        temp = temp->next;
    }
    if (head == NULL || head->data >= value) { // 插入到開頭
        newNode->next = head;
        head = newNode;
    } else { // 插入適當位置
        Node* temp = head;
        while (temp->next != NULL && temp->next->data < value) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printList(); // **每次插入後印出鏈結串列**
}

// 刪除節點
void delete(int value) {
    Node* temp = head, *prev = NULL;

    // 刪除第一個節點
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printList(); // **刪除後印出**
        return;
    }

    // 搜尋要刪除的節點
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // 沒找到，直接結束

    prev->next = temp->next;
    free(temp);
    printList(); // **刪除後印出**
}

// 搜尋元素
void search(int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Yes\n");
            return;
        }
        temp = temp->next;
    }
    printf("No\n");
}

int main() {
    int command, value;

    while (1) {
        scanf("%d", &command);
        if (command == 0) break;

        if (command == 1) { // 創建鏈結串列
            scanf("%d", &value);
            if (!created) {
                insert(value);
                created = 1;
            }
        } else if (command == 2) { // 插入
            scanf("%d", &value);
            insert(value);
        } else if (command == 3) { // 刪除
            scanf("%d", &value);
            delete(value);
        } else if (command == 4) { // 搜尋
            scanf("%d", &value);
            search(value);
        }
    }

    return 0;
}
