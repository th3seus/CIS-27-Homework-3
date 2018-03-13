//
//  FractionListStephenM.c
//  cis27Spring2018StephenMHw3Ex1
//
//  Created by Stephen Miller on 3/12/18.
//  Copyright © 2018 Stephen Miller. All rights reserved.
//

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
    
    tempFrac->num = num / getGCD(num, denom);
    tempFrac->denom = denom / getGCD(num, denom);
    
    if (denom < 0) {
        num = -num;
        denom = -denom;
    }
    
    return tempFrac;
}

FracNodeSMAddrT createFractionNodeStephenM(FractionSMAddrT newFrac) {
    FracNodeSMPtrT tempFrNode = NULL;
    
    if (tempFrNode != NULL) {
        free(tempFrNode);
        tempFrNode = NULL;
    }
    
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

void insertAfterNodeStephenM(FracNodeSMAddrT* frList,
                             FracNodeSMAddrT newNode, int nodeFlag) {
    FracNodeSMPtrT prevNode = NULL;
    
    if (prevNode != NULL) {
        free(prevNode);
        prevNode = NULL;
    }
    
    prevNode = *frList;
    do {
        prevNode = prevNode->next;
        nodeFlag--;
    } while (nodeFlag >= 0);
    
    newNode->next = prevNode->next;
    prevNode->next = newNode;
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
    
    if (*frList == NULL) {
        printf("\n     List is empty");
        return;
    }
    
    tempFrNode = *frList;
    
    *frList = tempFrNode->next;
    free(tempFrNode);
}

void removeChosenNodeStephenM(FracNodeSMAddrT*, FractionSMT);

void removeLastNodeStephenM(FracNodeSMAddrT*);

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
    
    printf("\n     There are %d fractions in the list; they are:", listLength);
    
    while (temp != NULL) {
        tempFrPtr = temp->frAddr;
        printf("\n        (%d,%d)", tempFrPtr->num, tempFrPtr->denom);
        
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
    
    printf("\n     There are %d fractions in the list; they are:", listLength);
    
    while (temp != NULL) {
        tempFrPtr = temp->frAddr;
        printf("\n     Fraction %d: (%d,%d)", i, tempFrPtr->num, tempFrPtr->denom);
        
        temp = temp->next;
        i++;
    }
}
