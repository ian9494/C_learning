#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10

typedef struct Node {
    char text[MAX_LEN + 1];
    int isEnd; // 是否為一個單字的最後一段
    struct Node* next;
} Node;

Node* createNode(char* content, int isEnd) {
    Node* node = (Node*)malloc(sizeof(Node));
    strncpy(node->text, content, MAX_LEN);
    node->text[MAX_LEN] = '\0';
    node->isEnd = isEnd;
    node->next = NULL;
    return node;
}

void append(Node** head, char* content, int isEnd) {
    Node* newNode = createNode(content, isEnd);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
}

void freeList(Node* head) {
    Node* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node* head = NULL;
    char wordBuffer[MAX_LEN + 1];
    int idx = 0;
    char c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            if (idx > 0) {
                wordBuffer[idx] = '\0';
                append(&head, wordBuffer, 1); // 完整單字，標為結尾
                idx = 0;
            }
            if (c == '\n') break;
        } else {
            wordBuffer[idx++] = c;
            if (idx == MAX_LEN) {
                wordBuffer[idx] = '\0';
                append(&head, wordBuffer, 0); // 先切出去一段，不知道是不是結尾
                idx = 0;
            }
        }
    }

    // 如果最後還有未送出的字元
    if (idx > 0) {
        wordBuffer[idx] = '\0';
        append(&head, wordBuffer, 1);
    }

    // 輸出，每個單字換行，但最後一行不能多換行
    Node* curr = head;
    while (curr) {
        printf("%s", curr->text);
        if (curr->isEnd && curr->next != NULL)
            printf("\n");
        curr = curr->next;
    }

    freeList(head);
    return 0;
}
