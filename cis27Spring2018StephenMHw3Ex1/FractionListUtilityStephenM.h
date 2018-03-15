/**
 * Program Name: cis27Spring2018StephenMHw3Ex1.c
 * Discussion:   Homework #3
 * Written By:   Stephen M
 * Due Date:     2018/03/15
 */

#ifndef FractionListUtilityStephenM_h
#define FractionListUtilityStephenM_h
#include "FractionListStephenM.h"

// menu utility function prototypes
void runMainMenuStephenMHw3(void);
void showMainMenuOptions(void);
void showInsertionMenuOptions(void);
void runInsertFirstUtility(FracNodeSMAddrT*, int, int);
void runInsertAfterNthNodeUtility(FracNodeSMAddrT*, int, int, int);
void runInsertLastNodeUtility(FracNodeSMAddrT*, int, int);
void showRemovalMenuOptions(void);
void runRemoveFirstNodeUtility(FracNodeSMAddrT*);
void runRemoveNthNodeUtility(FracNodeSMAddrT*, int);
void runRemoveLastNodeUtility(FracNodeSMAddrT*);
void showClassInfo(void);

#endif /* FractionListUtilityStephenM_h */
