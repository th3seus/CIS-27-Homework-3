//
//  main.c
//  cis27Spring2018StephenMHw3Ex1
//
//  Created by Stephen Miller on 3/12/18.
//  Copyright © 2018 Stephen Miller. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "FractionListStephenM.h"

// menu utility function prototypes
void runMainMenuStephenMHw3(void);
void showMainMenuOptions(void);
void showInsertionMenuOptions(void);
void showRemovalMenuOptions(void);
void showClassInfo(void);

int main(int argc, const char * argv[]) {
    runMainMenuStephenMHw3();
    return 0;
} 

// menu utility function definitions
void runMainMenuStephenMHw3() {
    int menuOption;
    int tempNum;
    int tempDenom;
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
                menuOption = 0;
                do {
                    showInsertionMenuOptions();
                    printf("\n  Select the option (1, 2, 3, 4, or 5): ");
                    scanf("%d", &menuOption);
                 
                    switch (menuOption) {
                    case 1: // insert new node at head of list
                            printf("\n  Please enter an integer for the numerator: ");
                            scanf("%d", &tempNum);
                            
                            do {
                                printf("\n  Please enter a non-zero integer for the denominator: ");
                                scanf("%d", &tempDenom);
                                if (tempDenom == 0)
                                    printf("\n    DENOMINATOR CANNOT BE ZERO\n");
                            } while (tempDenom == 0);
                            
                            insertFirstStephenM(createFractionNodeStephenM(createFractionStephenM(tempNum, tempDenom)), &userFrList);
                        break;
                    case 2: // insert new node after the n-th node
                            if (isEmptyStephenM(userFrList)) {
                                printf("\n  List is empty! Creating new list head instead\n");
                                
                                printf("\n  Please enter an integer for the numerator: ");
                                scanf("%d", &tempNum);
                                
                                do {
                                    printf("\n  Please enter a non-zero integer for the denominator: ");
                                    scanf("%d", &tempDenom);
                                    if (tempDenom == 0)
                                        printf("\n    DENOMINATOR CANNOT BE ZERO\n");
                                } while (tempDenom == 0);
                                
                                insertFirstStephenM(createFractionNodeStephenM(createFractionStephenM(tempNum, tempDenom)), &userFrList);
                                break;
                            } else {
                                displayNumberedListStephenM(userFrList);
                                
                                
                            }
                        break;
                    case 3: // insert new node at end of list
                        break;
                    case 4: // Display current list
                        break;
                    case 5: // return to Main Menu
                        break;
                    default: // wrong option
                        break;
                    }
                } while (menuOption != 5);
                break;
            case 3: // go to Removal Menu
                
                printf("\n  You chose to remove a node from the list");
                menuOption = 0;
                /*do {
                 showRemovalMenu();
                 printf("\n  Select the option (1, 2, 3, 4, or 5): ");
                 scanf("%d", &menuOption);
                 
                 switch (menuOption) {
                    case 1: // remove node at head of list
                        break;
                    case 2: // remove node after the n-th node
                        break;
                    case 3: // remove node at end of list
                        break;
                    case 4: // Display current list
                        break;
                    case 5: // return to Main Menu
                        break;
                    default: // wrong option
                        break;
                 }
                 } while (menuOption != 5);*/
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
