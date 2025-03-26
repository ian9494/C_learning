#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    char data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

typedef struct Node {
    char data;
    struct Node* next;
} Node;

// 建立雙向節點
DNode* createDNode(char c) {
    DNode* node = (DNode*)malloc(sizeof(DNode));
    node->data = c;
    node->prev = node->next = NULL;
    return node;
}

// 建立單向節點
Node* createNode(char c) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = c;
    node->next = NULL;
    return node;
}

// 新增到雙向串列尾端
void appendD(DNode** head, DNode** tail, char c) {
    DNode* node = createDNode(c);
    if (*head == NULL) {
        *head = *tail = node;
    } else {
        (*tail)->next = node;
        node->prev = *tail;
        *tail = node;
    }
}

// 在單向串列尾端加入
void append(Node** head, char c) {
    Node* node = createNode(c);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }
}

// 印出單向串列，兩兩空格
void printList(Node* head) {
    while (head) {
        printf("%c", head->data);
        if (head->next) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    char input[11];
    scanf("%s", input);

    // 建立雙向 linked list
    DNode* dhead = NULL;
    DNode* dtail = NULL;
    for (int i = 0; i < 10; i++) {
        appendD(&dhead, &dtail, input[i]);
    }

    // 從尾端反向複製到單向 linked list
    Node* newList = NULL;
    DNode* curr = dtail;
    while (curr) {
        append(&newList, curr->data);
        curr = curr->prev;
    }

    // 輸出
    printList(newList);

    return 0;
}
