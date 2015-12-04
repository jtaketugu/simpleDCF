#ifndef _CSMA_H
#define _CSMA_H

#include "node.h"
#include "result.h"


int BackoffZeroNum(Node *node_array);

void AllBackoffDec(Node *node_array, Result *result_p);
void Success(Node *node_array, Result *result_p);
void Collision(Node *node_array, Result *result_p);


#endif

