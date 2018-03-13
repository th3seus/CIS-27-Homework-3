//
//  FractionStephenM.h
//  cis27Spring2018StephenMHw3Ex1
//
//  Created by Stephen Miller on 3/12/18.
//  Copyright © 2018 Stephen Miller. All rights reserved.
//

#ifndef FractionListStephenM_h
#define FractionListStephenM_h

/* Basic Fraction data structure
 and typedefs */

struct FractionStephenM {
    int num;
    int denom;
};

typedef struct FractionStephenM FractionSMT;
typedef FractionSMT* FractionSMAddrT;
typedef FractionSMT* FractionSMPtrT;

/* Node structure for linked list of
    Fractions and typedefs */

struct FractionNodeStephenM {
    FractionSMAddrT frAddr;
    struct FractionNodeStephenM* next;
};

typedef struct FractionNodeStephenM FracNodeSMT;
typedef FracNodeSMT* FracNodeSMAddrT;
typedef FracNodeSMT* FracNodeSMPtrT;

/* Function Prototypes */

FractionSMAddrT createFractionStephenM(int, int);

FracNodeSMPtrT createFractionNodeStephenM(FractionSMAddrT);

int getGCD(int, int); 

// insertion function prototypes

void insertFirstStephenM(FracNodeSMAddrT, FracNodeSMAddrT* /* address of linked list */);

void insertAfterNodeStephenM(FracNodeSMAddrT*, FracNodeSMAddrT, int);

void appendFracNodeStephenM(FracNodeSMAddrT, FracNodeSMAddrT*);

// removeal function prototypes

void removeFirstNodeStephenM(FracNodeSMAddrT*);

void removeChosenNodeStephenM(FracNodeSMAddrT*, int);

void removeLastNodeStephenM(FracNodeSMAddrT*);

// utility prototypes

int isEmptyStephenM(FracNodeSMAddrT);

int getLengthStephenM(FracNodeSMAddrT);

void displayListStephenM(FracNodeSMAddrT);

void displayNumberedListStephenM(FracNodeSMAddrT);

void freeFractionListStephenM(FracNodeSMAddrT*);

#endif /* FractionStephenM_h */
