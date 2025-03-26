#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 建立新節點
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

// 加到尾端
void append(Node** head, int value) {
    Node* node = createNode(value);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* curr = *head;
        while (curr->next)
            curr = curr->next;
        curr->next = node;
    }
}

// 合併兩個已排序 linked list（回傳新串列頭）
Node* merge(Node* a, Node* b) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (a && b) {
        if (a->data < b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a != NULL) ? a : b;
    return dummy.next;
}

// 輸出串列（空格分隔，最後無空格）
void printList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" ");
        head = head->next;
    }
    printf("\n");
}

// 釋放記憶體
void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int num;

    // 讀取第一列
    while (scanf("%d", &num) == 1) {
        append(&list1, num);
        int c = getchar();
        if (c == '\n' || c == EOF) break;
    }
    printf("list1: ");
    printList(list1);

    // 讀取第二列
    while (scanf("%d", &num) == 1) {
        append(&list2, num);
        int c = getchar();
        if (c == '\n' || c == EOF) break;
    }
    printf("list2: ");
    printList(list2);

    // 合併並輸出
    Node* merged = merge(list1, list2);
    printList(merged);

    freeList(merged);
    return 0;
}
