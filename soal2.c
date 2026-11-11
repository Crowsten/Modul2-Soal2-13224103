/**
 * EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 * Modul : Dynamic Structures
 * Hari dan Tanggal : Rabu 11 November 2026
 * Nama (NIM) : Jonathan Chandra (13224103)
 * Nama File : Soal2.c
 * Deskripsi : Peternak Bunga Matahari
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int tinggi;
    struct Node *next;
    struct Node *prev;
} Node;

Node* CreateNode(int tinggi) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode != NULL) {
        NewNode->tinggi = tinggi;
        NewNode->next = NULL;
        NewNode->prev = NULL;
    }
    return NewNode;
}

void insertTail(Node **head, Node **tail, int tinggi) {
    Node* NewNode = CreateNode(tinggi);
    if (NewNode == NULL) return;

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
    int tinggi;
    int count = 0;
    int lokasi = 0;

    while (scanf("%d", &tinggi) == 1) {
        insertTail(&head, &tail, tinggi);
    }

    Node *curr = head;
    while (curr != NULL) {
        lokasi++;
        if (curr->prev != NULL && curr->next != NULL) {
            if (curr->tinggi < curr->prev->tinggi && curr->tinggi < curr->next->tinggi) {
                if (count > 0) {
                    printf(" ");
                }
                printf("%d", lokasi);
                count++;
            }
        }
        curr = curr->next;
    }

    if (count == 0) {
        printf("NONE");
    }
    printf("\n");

    freeList(head);
    head = NULL;
    tail = NULL;

    return 0;
}
