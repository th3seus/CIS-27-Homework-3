/**
 * Program Name: cis27Spring2018StephenMHw3Ex1.c
 * Discussion:   Homework #3
 * Written By:   Stephen M
 * Due Date:     2018/03/15
 */

#include <stdio.h>
#include <stdlib.h>
#include "FractionListUtilityStephenM.h"
#include "FractionListStephenM.h"


// menu utility function definitions
void runMainMenuStephenMHw3() {
    int menuOption;
    int tempNum;
    int tempDenom;
    int nodePos;
    FracNodeSMAddrT userFrList = NULL;
    
    showClassInfo();
    
    do {
        showMainMenuOptions();
        printf("\nSelect the option (1, 2, 3, or 4): ");
        scanf("%d", &menuOption);
        
        switch (menuOption) {
            case 1: // Display current Linked List
                printf("\n  You chose menu option 1 - Display Current Linked List");
                if (isEmptyStephenM(userFrList)) {
                    printf("\n\n  Your list is empty - please create a list to display");
                    break;
                } else {
                    displayListStephenM(userFrList);
                }
                break;
            case 2: // go to Insertion Menu
                printf("\n  You chose to insert data into the linked list");
                do {
                    showInsertionMenuOptions();
                    printf("\n  Select the option (1, 2, 3, 4, or 5): ");
                    scanf("%d", &menuOption);
                    
                    switch (menuOption) {
                        case 1: // insert new node at head of list
                            runInsertFirstUtility(&userFrList, tempNum, tempDenom);
                            break;
                        case 2: // insert new node after the n-th node
                            if (isEmptyStephenM(userFrList)) {
                                printf("\n  List is empty! Creating new list head instead\n");
                                
                                runInsertFirstUtility(&userFrList, tempNum, tempDenom);
                                
                                break;
                            } else {
                                runInsertAfterNthNodeUtility(&userFrList, tempNum, tempDenom, nodePos);
                            }
                            break;
                        case 3: // insert new node at end of list
                            if (isEmptyStephenM(userFrList)) {
                                printf("\n  List is empty! Creating new list head instead\n");
                                
                                runInsertFirstUtility(&userFrList, tempNum, tempDenom);
                                
                                break;
                            } else {
                                runInsertLastNodeUtility(&userFrList, tempNum, tempDenom);
                            }
                            break;
                        case 4: // Display current list
                            if (isEmptyStephenM(userFrList)) {
                                printf("\n\n  Your list is empty - please create a list to display");
                                break;
                            } else {
                                displayListStephenM(userFrList);
                            }
                            break;
                        case 5: // return to Main Menu
                            break;
                        default: // wrong option
                            break;
                    }
                } while (menuOption != 5);
                break;
            case 3: // go to Removal Menu
                printf("\n You chose menu option 3 - Remove a Node from List");
                if (isEmptyStephenM(userFrList)) {
                    printf("\n        Your list is empty - please create a list first");
                    break;
                }
                printf("\n  You chose to remove a node from the list");
                do {
                    showRemovalMenuOptions();
                    printf("\n  Select the option (1, 2, 3, 4, or 5): ");
                    scanf("%d", &menuOption);
                    
                    switch (menuOption) {
                        case 1: // remove node at head of list
                            runRemoveFirstNodeUtility(&userFrList);
                            break;
                        case 2: // remove node after the n-th node
                            runRemoveNthNodeUtility(&userFrList, nodePos);
                            break;
                        case 3: // remove node at end of list
                            runRemoveLastNodeUtility(&userFrList);
                            break;
                        case 4: // Display current list
                            printf("\n  Your current list is:");
                            displayListStephenM(userFrList);
                            break;
                        case 5: // return to Main Menu
                            break;
                        default: // wrong option
                            break;
                    }
                } while (menuOption != 5);
                break;
            case 4: // quit application
                printf("\n  Fractions and Linked Lists -- Fun!\n");
                break;
            default: // wrong option
                printf("\n  You must be kidding...\n");
                break;
        }
    } while (menuOption != 4);
}

void showMainMenuOptions() {
    printf("\n*******************************"
           "\n*         Menu HW #3          *"
           "\n* LINKED LIST MENU: Fractions *"
           "\n* 1. Display Current List     *"
           "\n* 2. Inserting                *"
           "\n* 3. Removing                 *"
           "\n* 4. Quit                     *"
           "\n*******************************");
}

void showInsertionMenuOptions() {
    printf("\n     **********************"
           "\n     *   Insertion Menu   *"
           "\n     * 1. As First Node   *"
           "\n     * 2. After n-th Node *"
           "\n     * 3. As Last Node    *"
           "\n     * 4. Display List    *"
           "\n     * 5. Return To Main  *"
           "\n     **********************");
}

void showRemovalMenuOptions() {
    printf("\n     **********************"
           "\n     *    Removal Menu    *"
           "\n     * 1. First Node      *"
           "\n     * 2. n-th Node       *"
           "\n     * 3. Last Node       *"
           "\n     * 4. Display List    *"
           "\n     * 5. Return to Main  *"
           "\n     **********************");
}

void showClassInfo() {
    printf("CIS 27 - Data Structures"
           "\nLaney College"
           "\nStephen Miller \n"
           "\nAssignment Information -- "
           "\n  Assignment Number:    Homework 03,"
           "\n                        Coding Assignment -- Exercise #1"
           "\n  Written By:           Stephen M"
           "\n  Submitted Date:       2018/03/12\n");
}

void runInsertFirstUtility(FracNodeSMAddrT* frList, int num, int denom) {
    printf("\n  Please enter an integer for the numerator: ");
    scanf("%d", &num);
    
    do {
        printf("\n  Please enter a non-zero integer for the denominator: ");
        scanf("%d", &denom);
        if (denom == 0)
            printf("\n    DENOMINATOR CANNOT BE ZERO\n");
    } while (denom == 0);
    
    insertFirstStephenM(createFractionNodeStephenM(createFractionStephenM(num, denom)), frList);
}

void runInsertAfterNthNodeUtility(FracNodeSMAddrT* frList, int num, int denom, int nodePos) {
    displayNumberedListStephenM(*frList);
    printf("\n  Please enter the node after which you'd like to insert a new node: ");
    scanf("%d", &nodePos);
    
    if (nodePos < 0 || nodePos > getLengthStephenM(*frList) - 1)
        printf("\n    Not a valid option");
    else{
        printf("\n  Please enter an integer for the numerator: ");
        scanf("%d", &num);
        
        do {
            printf("\n  Please enter a non-zero integer for the denominator: ");
            scanf("%d", &denom);
            if (denom == 0)
                printf("\n    DENOMINATOR CANNOT BE ZERO\n");
        } while (denom == 0);
        if (nodePos == getLengthStephenM(*frList) - 1)
            appendFracNodeStephenM(createFractionNodeStephenM(createFractionStephenM(num, denom)), frList);
        else
            insertAfterNodeStephenM(createFractionNodeStephenM(createFractionStephenM(num, denom)), frList, nodePos);
    }
}
void runInsertLastNodeUtility(FracNodeSMAddrT* frList, int num, int denom) {
    printf("\n  Appending new node to current list --");
    printf("\n  Please enter an integer for the numerator: ");
    scanf("%d", &num);
    
    do {
        printf("\n  Please enter a non-zero integer for the denominator: ");
        scanf("%d", &denom);
        if (denom == 0)
            printf("\n    DENOMINATOR CANNOT BE ZERO\n");
    } while (denom == 0);
    
    appendFracNodeStephenM(createFractionNodeStephenM(createFractionStephenM(num, denom)), frList);
}

void runRemoveFirstNodeUtility(FracNodeSMAddrT* frList) {
    printf("\n  You chose to remove the head of the list --");
    removeFirstNodeStephenM(frList);
}

void runRemoveNthNodeUtility(FracNodeSMAddrT* frList, int nodePos) {
    displayNumberedListStephenM(*frList);
    printf("\n  Please enter the node that you'd like to remove: ");
    scanf("%d", &nodePos);
    
    if (nodePos < 0 || nodePos >= getLengthStephenM(*frList))
        printf("\n    Not a valid option");
    else{
        printf("\n  You chose to remove the node at position %d"
               "\n  ..."
               "\n  ... removing node %d"
               "\n  ... node %d is now removed -- you're welcome", nodePos, nodePos, nodePos);
        
        removeChosenNodeStephenM(frList, nodePos);
    }
}

void runRemoveLastNodeUtility(FracNodeSMAddrT* frList) {
    printf("\n  You chose to remove the last node in the list --");
    removeLastNodeStephenM(frList);
}
