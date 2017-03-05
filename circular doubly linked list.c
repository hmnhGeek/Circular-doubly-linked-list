#include<stdio.h>
#include<stdlib.h>

// Define a structure for the circular linked list. //
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}cdll;

// Initialise and instance head. //
cdll *head = NULL;

void insert( int item ){
    // First check if the item being inserted forms the first node. //
    if( head == NULL ){
        head = ( cdll * )malloc( sizeof( cdll ) );
        head -> prev = head;
        head -> data = item;
        head -> next = head;
    }
    else{
        // Initialise a pointer temp to traverse the list. //
        cdll *temp = head;
        while( temp -> next != head ){
            temp = temp -> next;
        }
        // now temp contains last node. //
        // Now take the element. //
        cdll *var = ( cdll * )malloc( sizeof( cdll ) );
        temp -> next = var;
        var -> prev = temp;
        var -> data = item;
        var -> next = head;
        head -> prev = var;
    }
    printf("Element inserted.\n");
} // End of insert() function. //

void delete( int item ){
    // Check if the list is empty or not. //
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        // To traverse the list, initialise the temp pointer. //
        cdll *temp = head;
        
        while( temp -> next != head ){
            if( temp -> data == item ){
                if( temp == head ){
                    cdll *prev_node = temp -> prev;
                    cdll *next_node = temp -> next;
                    prev_node -> next = next_node;
                    next_node -> prev = prev_node;
                    head = next_node;
                    cdll *temp1 = temp;
                    temp = head;
                }
                else{
                    cdll *prev_node = temp -> prev;
                    cdll *next_node = temp -> next;
                    prev_node -> next = next_node;
                    next_node -> prev = prev_node;
                    cdll *temp1 = temp;
                    temp = head;
                    free( temp1 );
                }
            }
            else{
                temp = temp -> next;
            }
        }
        if( temp -> data == item ){ // Since above while loop will not work for the last node. //
            if( temp -> prev == temp -> next ){
                head = NULL;
                free( temp );
            }
            else{
                cdll *prev_node = temp -> prev;
                cdll *next_node = temp -> next;
                prev_node -> next = next_node;
                next_node -> prev = prev_node;
                cdll *temp1 = temp;
                temp = head;
                free( temp1 );
            }
        }
    }
} // End of delete() function. //

void search( int item ){
    // Check if the list is empty or not. //
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        // To traverse the list, initialise the temp pointer. //
        cdll *temp = head;
        int index = -1;
        while( temp -> next != head ){
            index += 1;
            if( temp -> data == item ){
                printf("Element found at index %d. \n", index);
            }
            temp = temp -> next;
        }
        index += 1;
        if( temp -> data == item ){
            printf("Element found at index %d. \n", index);
        }
    }
} // End of search() function. //

void display(){
    // Check if the list is empty or not. //
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        // To traverse the list, initialise the temp pointer. //
        cdll *temp = head;

        while( temp -> next != head ){
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
        printf("%d\n", temp -> data);
    }
} // End of display() function. //

void main(){
    int ch = 1;
    while( ch == 1 ){
        printf("1. Insert.\n");
        printf("2. Delete.\n");
        printf("3. Search.\n");
        printf("4. Display.\n");
        printf("5. Exit.\n");
        
        int x;
        printf("Enter choice: ");
        scanf("%d", &x);
        
        if( x == 1 ){
            int elem;
            printf("Enter item: ");
            scanf("%d", &elem);
            insert( elem );
        }
        else if( x == 2 ){
            int elem;
            printf("Enter item: ");
            scanf("%d", &elem);
            delete( elem );
        }
        else if( x == 3 ){
            int elem;
            printf("Enter item: ");
            scanf("%d", &elem);
            search( elem );
        }
        else if( x == 4 ){
            display();
        }
        else if( x == 5 ){
            ch = 0;
        }
        else{
            printf("Invalid choice.\n");
        }
    }
} // End of main() function. //