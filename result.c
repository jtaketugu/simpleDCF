#include <stdlib.h>
#include "node.h"
#include "result.h"
#include "util.h"

/***************************/
/*        initialize       */
/***************************/
/*local*/
void initialize_result_element(ResultElement *k){

  k->suc = 0;
  k->col = 0;
  return;
}

/*global*/
void initialize_result(Result *r){

  int i;

  r->ch_suc = 0;
  r->ch_col = 0;
  r->ch_idle = 0;
  
  r->time_total = 0.0;

  r->node_total = (ResultElement *)malloc(sizeof(ResultElement)*NODE_N);
  if(r->node_total==NULL) error_print(__FILE__, __LINE__);

  for(i=0;i<NODE_N;i++){
    initialize_result_element(&r->node_total[i]);
  }

  return;
}

/***************************/
/*   results from CSMA/CA  */
/***************************/
void result_AllBackoffDec(Result *result_p){
  result_p -> ch_idle ++;
  return;
}

void result_Success(Result *result_p, int n){
  result_p -> ch_suc ++;
  result_p -> node_total[n].suc ++;
  return;
}

void result_Collision(Result *result_p, int n, int count){
  if(count==0) result_p -> ch_col ++;
  result_p -> node_total[n].col ++;
}



/**********************/
/*--- final result ---*/
/**********************/
void print_result_total(Result r){

  int i;
  //double p,th;
  int suc=0, col=0;

  for(i=0;i<NODE_N;i++){
    suc += r.node_total[i].suc;
    col += r.node_total[i].col;
  }

  //p = (double)col/(suc + col);
  //th = (double)suc/r.ch_idle;

  /* print */

  return;
}
