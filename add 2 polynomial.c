#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial in sorted order
struct Node* insertTerm(struct Node* head, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (head == NULL || head->exponent < exponent) {
        newNode->next = head;
        return newNode;
    }
    struct Node* ptr = head;
    while (ptr->next != NULL && ptr->next->exponent >= exponent) {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node* ptr = head;
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
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exponent > ptr2->exponent) {
            result = insertTerm(result, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        } else if (ptr1->exponent < ptr2->exponent) {
            result = insertTerm(result, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        } else {
            int sum = ptr1->coefficient + ptr2->coefficient;
            if (sum != 0) {
                result = insertTerm(result, sum, ptr1->exponent);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    // Add remaining terms of poly1
    while (ptr1 != NULL) {
        result = insertTerm(result, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }

    // Add remaining terms of poly2
    while (ptr2 != NULL) {
        result = insertTerm(result, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }

    return result;
}

// Main function to demonstrate polynomial addition
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Creating first polynomial: 3x^5 + 2x^3 + 1x^0
    poly1 = insertTerm(poly1, 3, 5);
    poly1 = insertTerm(poly1, 2, 3);
    poly1 = insertTerm(poly1, 1, 0);

    // Creating second polynomial: 4x^4 + 2x^3 + 5x^0
    poly2 = insertTerm(poly2, 4, 4);
    poly2 = insertTerm(poly2, 2, 3);
    poly2 = insertTerm(poly2, 5, 0);

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Adding the two polynomials
    struct Node* sum = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(sum);

    return 0;
}
