#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode dup;
    struct ListNode* temp = &dup;
    dup.next = NULL;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    temp->next = (list1 != NULL) ? list1 : list2;
    return dup.next;
}

// Helper to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper to build a linked list from an array
struct ListNode* buildList(int arr[], int size) {
    if (size == 0) return NULL;

    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper to print a linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Optional: Free linked list memory
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to test the merge
int main() {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    struct ListNode* list1 = buildList(arr1, 3);
    struct ListNode* list2 = buildList(arr2, 3);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("Merged List: ");
    printList(merged);

    // Free memory
    freeList(merged);

    return 0;
}
