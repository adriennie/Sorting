#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

//merge two sorted lists
struct Node* merge(struct Node* left, struct Node* right) {
    struct Node* result = NULL;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Merge Sort function for linked list
void mergeSort(struct Node** head) {
    struct Node* current = *head;
    struct Node* left;
    struct Node* right;

    if (current == NULL || current->next == NULL)
        return;

    // Split the list into two halves
    split(current, &left, &right);

    // Recursively sort both halves
    mergeSort(&left);
    mergeSort(&right);

    // Merge the sorted halves
    *head = merge(left, right);
}

// Split the linked list into two halves
void split(struct Node* source, struct Node** left, struct Node** right) {
    struct Node* slow;
    struct Node* fast;

    if (source == NULL || source->next == NULL) {
        *left = source;
        *right = NULL;
        return;
    }

    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = source;
    *right = slow->next;
    slow->next = NULL;
}

// Print the list
void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of a linked list
void insert(struct Node** start_ref, int data) {
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}

int main() {
    int arr[] = { 78, 20, 10, 32, 1, 5 };
    int listsize, i;

    // Start with an empty linked list
    struct Node* start = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &listsize);

    if (listsize <= 0 || listsize > 100) {
        printf("Invalid input for the number of elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", listsize);
    for (i = 0; i < listsize; i++) {
        scanf("%d", &arr[i]);
        insert(&start, arr[i]);
    }

    // Print the list before sorting
    printf("Linked list before sorting\n");
    printList(start);

    // Sort the linked list using Merge Sort
    mergeSort(&start);

    // Print the sorted list
    printf("Linked list after sorting\n");
    printList(start);

    // Free the dynamically allocated memory for nodes
    struct Node* current = start;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
