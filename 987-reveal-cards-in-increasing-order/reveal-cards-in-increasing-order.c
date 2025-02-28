struct node {
    int data;
    struct node *next;
};

// Insert at the end of the linked list
void insertAtEnd(struct node** head, int newdata) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

// Move first node to last
void moveFirstToLast(struct node** head) {
    if (*head == NULL || (*head)->next == NULL) 
        return; // No change needed if 0 or 1 elements

    struct node* temp = *head;
    *head = (*head)->next; // Move head to the next node

    struct node* last = *head;
    while (last->next != NULL) {
        last = last->next; // Find last node
    }

    last->next = temp; // Attach first node to last
    temp->next = NULL; // Set old first node as the last node
}

// Deck reveal in increasing order
int* deckRevealedIncreasing(int* deck, int n, int* rsize) {
    int i, j, t;
    int* a = (int*)malloc(n * sizeof(int));

    // Step 1: Sort the deck in ascending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (deck[i] > deck[j]) {
                t = deck[i];
                deck[i] = deck[j];
                deck[j] = t;
            }
        }
    }

    // Step 2: Create a linked list of indices 0 to n-1
    struct node* head = NULL;
    for (i = 0; i < n; i++) {
        insertAtEnd(&head, i);
    }

    // Step 3: Assign the sorted deck elements to the correct positions
    struct node* temp = head;
    i = 0;
    while (temp != NULL) {
        a[temp->data] = deck[i]; // Assign the smallest available card
        struct node* toDelete = temp;
        temp = temp->next; // Move to the next node
        free(toDelete);    // Delete the used node
        if (temp != NULL) {
            moveFirstToLast(&temp); // Move the first node to the last
        }
        i++;
    }

    *rsize = n;
    return a;
}