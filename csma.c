#include "define.h"
#include "csma.h"
#include "util.h"

void backoff_reset(Node *node){
  node->retry_count = 0;
  node->retry_bit = 0;
  node->cwnow = node->cwmin;
  node->bo = uniform_int(node->cwnow);
  return;
}

void backoff_double(Node *node){

  node->cwnow = (node->cwnow + 1) * 2 - 1 ;
  if(node->cwnow > node->cwmax){
    node->cwnow = node->cwmax;
  }
  node->bo = uniform_int(node->cwnow);
  
  return;
}

void backoff_collision(Node *node){

  if( ++node->retry_count >= RETRY_LIMIT){
    backoff_reset(node);
  }
  else{
    node->retry_bit = 1;
    backoff_double(node);
  }
  return;
}



/********************************/
/*     global functions         */
/********************************/

/* count the number of nodes with bo==0 */
int BackoffZeroNum(Node *node_array){

  int i, count=0;

  for(i=0; i<NODE_N; i++){
    if(node_array[i].bo == 0) count++;
  }

  return count;
}

/* if zero_n == 0 */
void AllBackoffDec(Node *node_array, Result *result_p){

  int i;

  for(i=0; i<NODE_N; i++){
    node_array[i].bo --;
  }
  if(result_p->time_total > RESULT_CUT) result_AllBackoffDec(result_p);

  return;
}

/* if zero_n == 1 */
void Success(Node *node_array, Result *result_p){

  int i;


  for(i=0; i<NODE_N; i++){
    if(node_array[i].bo ==0){

      backoff_reset(&node_array[i]);

      if(result_p -> time_total > RESULT_CUT) result_Success(result_p, i);
      break;
    }
  }

  return;
}

/* if zero_n >= 2 */
void Collision(Node *node_array, Result *result_p){

  int i, count=0;

  for(i=0; i<NODE_N; i++){

    if(node_array[i].bo == 0){
      backoff_collision(&node_array[i]);

      if(result_p -> time_total > RESULT_CUT) result_Collision(result_p, i, count++);
    }
  }

  return;
}
