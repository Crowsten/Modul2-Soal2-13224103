/** 
 * EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025 
 * Modul : Dynamic Structures 
 * Hari dan Tanggal : Rabu 11 November 2026 
 * Nama (NIM) : Jonathan Chandra (13224103) 
 * Nama File : Soal2.c 
 * Deskripsi : Peternak Bunga Matahari 
 * */ 

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int tinggi;
    struct Node *next;
    struct Node *prev;
} Node;

Node* CreateNode(int tinggi) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->tinggi = tinggi;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

void insertTail(Node **head, Node **tail, int tinggi) {
    Node* NewNode = CreateNode(tinggi);
    if (*head == NULL) {
        *head = NewNode;
        *tail = NewNode;
        return;
    }
    (*tail)->next = NewNode;
    NewNode->prev = *tail;
    *tail = NewNode;
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
    Node *tail = NULL;
    int n, tinggi, count;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &tinggi);
        insertTail(&head, &tail, tinggi);
    }

    if (head != NULL) {
        Node *curr = head;
        while (curr != NULL) {
            int a = (curr->prev == NULL) || (curr->tinggi < curr->prev->tinggi);
            int b = (curr->next == NULL) || (curr->tinggi < curr->next->tinggi);
            
            if (a && b) {
                printf("%d", curr->tinggi);
                count++;
            }
            curr = curr->next;
        }

    freeList(head);
    return 0;
    }
    if (count == 0){
        printf("NONE");
    }
}

