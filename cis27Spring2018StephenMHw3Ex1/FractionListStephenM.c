/**
 * Program Name: cis27Spring2018StephenMHw3Ex1.c
 * Discussion:   Homework #3
 * Written By:   Stephen M
 * Due Date:     2018/03/15
 */

#include <stdio.h>
#include <stdlib.h>
#include "FractionListStephenM.h"

/* Function Definitions */

FractionSMAddrT createFractionStephenM(int num, int denom) {
    FractionSMPtrT tempFrac = NULL;
    
    if (tempFrac != NULL) {
        free(tempFrac);
        tempFrac = NULL;
    }
    
    tempFrac = (FractionSMPtrT)malloc(sizeof(FractionSMT));
 
    
    tempFrac->num = num / getGCD(num, denom);
    tempFrac->denom = denom / getGCD(num, denom);
    
    if (denom < 0) {
        tempFrac->num = -tempFrac->num;
        tempFrac->denom = -tempFrac->denom;
    }
    return tempFrac;
}

FracNodeSMPtrT createFractionNodeStephenM(FractionSMAddrT newFrac) {
    FracNodeSMPtrT tempFrNode = NULL;
    
    if (tempFrNode != NULL) {
        free(tempFrNode);
        tempFrNode = NULL;
    }
    
    tempFrNode = (FracNodeSMPtrT)malloc(sizeof(FracNodeSMT));
    
    tempFrNode->frAddr = newFrac;
    tempFrNode->next = NULL;
    
    return tempFrNode;
}

int getGCD(int n, int d) {
    return d == 0 ? n : getGCD(d, n % d);
}

// insertion function definitions

void insertFirstStephenM(FracNodeSMAddrT newNode, FracNodeSMAddrT* frList) {
    FracNodeSMPtrT tempFrNode = NULL;
    
    if (tempFrNode != NULL) {
        free(tempFrNode);
        tempFrNode = NULL;
    }
    
    if (frList == NULL) {
        *frList = newNode;
    } else {
        tempFrNode = newNode;
        
        tempFrNode->next = *frList;
        *frList = tempFrNode;
    }
}

void insertAfterNodeStephenM(FracNodeSMAddrT newNode,
                             FracNodeSMAddrT* frList, int nodeFlag) {
    FracNodeSMPtrT prevNode = NULL;
    
    if (prevNode != NULL) {
        free(prevNode);
        prevNode = NULL;
    }
    
    prevNode = *frList;
    if (prevNode->next == NULL) {
        prevNode->next = newNode;
    }
    else if (nodeFlag == 0) {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    else {
        do {
            prevNode = prevNode->next;
            nodeFlag--;
        } while (nodeFlag > 0);
    
            newNode->next = prevNode->next;
            prevNode->next = newNode;
    }
}

void appendFracNodeStephenM(FracNodeSMAddrT newNode, FracNodeSMAddrT* frList) {
    FracNodeSMPtrT tempFrNode = NULL;
     
    if (*frList != NULL) {
        tempFrNode = *frList;
        while (tempFrNode->next != NULL) {
            tempFrNode = tempFrNode->next;
        }
    } else {
        *frList = newNode;
        return;
    }
    
    tempFrNode->next = newNode;
}

// removal function definitions

void removeFirstNodeStephenM(FracNodeSMAddrT* frList) {
    FracNodeSMPtrT tempFrNode = NULL;
    FractionSMPtrT tempFrac = NULL;
    
    if (*frList == NULL) {
        printf("\n     List is empty");
        return;
    }
    
    if((*frList)->next == NULL) {
        free((*frList)->frAddr);
        (*frList)->frAddr = NULL;
        
        free(*frList);
        *frList = NULL;
        return;
    }
    
    tempFrNode = *frList;
    
    *frList = tempFrNode->next;
    
    tempFrac = tempFrNode->frAddr;
    
    printf("\n     Removing (%d/%d) from the list --\n", tempFrac->num, tempFrac->denom);
    
    free(tempFrac);
    tempFrac = NULL;
    free(tempFrNode);
    tempFrNode = NULL;
    
}

void removeChosenNodeStephenM(FracNodeSMAddrT* frList, int nodeFlag) {
    FracNodeSMPtrT prevNode = NULL;
    FracNodeSMPtrT tempNode = NULL;
    
    prevNode = *frList;
    if (prevNode == NULL) {
        printf("\n     List is empty");
        return;
    }
    if (nodeFlag == getLengthStephenM(prevNode) - 1) {
        removeLastNodeStephenM(&prevNode);
        return;
    }
    if (nodeFlag == 0) {
        tempNode = *frList;
        
        *frList = tempNode->next;
        
        free(tempNode->frAddr);
        tempNode->frAddr = NULL;
        free(tempNode);
        tempNode = NULL;
        return;
    }
    
    if(prevNode->next == NULL) {
        free(prevNode->frAddr);
        prevNode->frAddr = NULL;
        
        free(prevNode);
        prevNode = NULL;
        return;
    }
    nodeFlag--; // find node before node to be removed
    do {
        prevNode = prevNode->next;
        nodeFlag--;
    } while (nodeFlag > 0);
    
    tempNode = prevNode->next;
    
    prevNode->next = tempNode->next;
    
    printf("\n     Removing (%d/%d) from the list --\n", tempNode->frAddr->num, tempNode->frAddr->denom);
    
    free(tempNode->frAddr);
    tempNode->frAddr = NULL;
    free(tempNode);
    tempNode = NULL;
}

void removeLastNodeStephenM(FracNodeSMAddrT* frList) {
    FracNodeSMPtrT prevNode = NULL;
    FracNodeSMPtrT tempNode = NULL;
    FractionSMPtrT tempFrac = NULL;
    
    prevNode = *frList;
    
    if (prevNode->next == NULL) {
        tempFrac = prevNode->frAddr;
        
        free(tempFrac);
        tempFrac = NULL;
        free(prevNode);
        prevNode = NULL;
        return;
    } else {
        while (prevNode->next != NULL) {
            if (prevNode->next->next == NULL) {
                tempNode = prevNode->next;
                tempFrac = tempNode->frAddr;
                prevNode->next = NULL;
                
                printf("\n     Removing (%d/%d) from the list --\n", tempFrac->num, tempFrac->denom);
                
                free(tempFrac);
                tempFrac = NULL;
                free(tempNode);
                tempNode = NULL;
                
                return;
            }
            prevNode = prevNode->next;        }
    }
}

// utility function definitions

int isEmptyStephenM(FracNodeSMAddrT frList) {
    /* Returns 1 if list is empty, 0 if list is not */
    int emptyFlag;
    
    if (frList == NULL) {
        emptyFlag = 1;
    } else
        emptyFlag = 0;
    
    return emptyFlag;
} 

int getLengthStephenM(FracNodeSMAddrT frList) {
    FracNodeSMPtrT current = NULL;
    int count = 0;
    
    current = frList;
    
    if (current == NULL)
        return 0;
    if (current->next == NULL)
        return 1;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    
    return count;
}

void displayListStephenM(FracNodeSMAddrT frList) {
    FracNodeSMPtrT temp = NULL;
    FractionSMPtrT tempFrPtr = NULL;
    int listLength = 0;
    
    temp = frList;
    listLength = getLengthStephenM(frList);
    
    if (listLength == 1)
        printf("\n     There is 1 fraction in the list; it is:");
    else
        printf("\n     There are %d fractions in the list: they are:", listLength);
    
    while (temp != NULL) {
        tempFrPtr = temp->frAddr;
        printf("\n        (%d/%d)", tempFrPtr->num, tempFrPtr->denom);
        
        temp = temp->next;
    }
}

void displayNumberedListStephenM(FracNodeSMAddrT frList) {
    FracNodeSMPtrT temp = NULL;
    FractionSMPtrT tempFrPtr = NULL;
    int listLength = 0;
    int i = 0;
    
    temp = frList;
    listLength = getLengthStephenM(frList);
    
    if (listLength == 1)
        printf("\n     There is 1 fraction in the list; it is:");
    else
        printf("\n     There are %d fractions in the list: they are:", listLength);
    
    while (temp != NULL) {
        tempFrPtr = temp->frAddr;
        printf("\n        (%d/%d) at position %d", tempFrPtr->num, tempFrPtr->denom, i);
        
        temp = temp->next;
        i++;
    }
}

void freeFractionListStephenM(FracNodeSMAddrT* frList) {
    FracNodeSMPtrT temp = NULL;
    FracNodeSMPtrT next = NULL;
    
    temp = *frList;
    
    while (temp != NULL) {
        next = temp->next;
        
        free(temp->frAddr);
        free(temp);
        
        temp = next;
    }
    
    *frList = NULL;
}
