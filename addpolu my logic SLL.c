#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial node
struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

// Function to traverse and display a polynomial
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%dx^%d", ptr->coefficient, ptr->exponent);
        if (ptr->next != NULL) {
            printf(" + ");
        }
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL, *last = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        if (poly1->exponent > poly2->exponent) {
            newNode->coefficient = poly1->coefficient;
            newNode->exponent = poly1->exponent;
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            newNode->coefficient = poly2->coefficient;
            newNode->exponent = poly2->exponent;
            poly2 = poly2->next;
        } else {
            newNode->coefficient = poly1->coefficient + poly2->coefficient;
            newNode->exponent = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        newNode->next = NULL;
        if (result == NULL) {
            result = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    // Add remaining terms of poly1
    while (poly1 != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coefficient = poly1->coefficient;
        newNode->exponent = poly1->exponent;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }

        poly1 = poly1->next;
    }

    // Add remaining terms of poly2
    while (poly2 != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coefficient = poly2->coefficient;
        newNode->exponent = poly2->exponent;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }

        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node *poly1, *poly2, *result;

    // Allocate memory and manually create the first polynomial: 5x^3 + 4x^2 + 2x^1
    poly1 = (struct Node *)malloc(sizeof(struct Node));
    
    struct Node *poly1_second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *poly1_third = (struct Node *)malloc(sizeof(struct Node));

    poly1->coefficient = 5; 
    poly1->exponent = 3; 
    poly1->next = poly1_second;
    poly1_second->coefficient = 4; 
    poly1_second->exponent = 2; 
    poly1_second->next = poly1_third;
    poly1_third->coefficient = 2; 
    poly1_third->exponent = 1; 
    poly1_third->next = NULL;

    // Allocate memory and manually create the second polynomial: 5x^2 + 3x^1 + 6x^0
    poly2 = (struct Node *)malloc(sizeof(struct Node));
    
    struct Node *poly2_second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *poly2_third = (struct Node *)malloc(sizeof(struct Node));

    poly2->coefficient = 5; 
    poly2->exponent = 2; 
    poly2->next = poly2_second;
    poly2_second->coefficient = 3; 
    poly2_second->exponent = 1; 
    poly2_second->next = poly2_third;
    poly2_third->coefficient = 6; 
    poly2_third->exponent = 0; 
    poly2_third->next = NULL;

    // Display the polynomials
    printf("First Polynomial: ");
    linkedListTraversal(poly1);

    printf("Second Polynomial: ");
    linkedListTraversal(poly2);

    // Add the polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Resultant Polynomial: ");
    linkedListTraversal(result);

    return 0;
}
