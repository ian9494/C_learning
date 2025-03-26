#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

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
                append(&head, wordBuffer, 1); // 最後一段 isEnd=1
                idx = 0;
            }
        } else {
            wordBuffer[idx++] = c;
            if (idx == MAX_LEN) {
                printf("max len\n");
                wordBuffer[idx] = '\0';
                printf("%s + %c + %d\n", wordBuffer, wordBuffer[idx], idx);

                if (wordBuffer[idx] == ' ' || wordBuffer[idx] == '\n') {
                    printf("is end\n");
                    append(&head, wordBuffer, 1); // 最後一段 isEnd=1
                } else {
                    printf("not end\n");
                    append(&head, wordBuffer, 0);
                }
                // append(&head, wordBuffer, (c == ' ' || c == '\n') ? 1 : 0); // 判斷是否為最後一段
                idx = 0;
            }
        }
    }

    // 結束前如果還有字
    if (idx > 0) {
        wordBuffer[idx] = '\0';
        append(&head, wordBuffer, 1);
    }

    // 輸出
    Node* curr = head;
    while (curr) {
        printf("%s", curr->text);
        if (curr->isEnd && curr->next!=NULL) printf("\n");
        curr = curr->next;
    }

    freeList(head);
    return 0;
}
