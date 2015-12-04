#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "node.h"
#include "result.h"
#include "csma.h"
#include "util.h" //err_print, uniform_int, arg_set

int main(int argc, char *argv[]){

  int zero_n;
  Node *node_array; // [NODE_N]
  Result result;

  arg_set(argc,argv);

  /* initialize */
  node_array = (Node *)malloc(sizeof(Node)*NODE_N);
  if(node_array==NULL) error_print(__FILE__, __LINE__);

  initialize_node_array(node_array);
  initialize_result(&result);

  /* Main Loop */
  while(result.time_total < TIME_MAX){

    zero_n = BackoffZeroNum(node_array);

    if(zero_n == 0){
      result.time_total += I_TIME;
      AllBackoffDec(node_array, &result);
    }
    else if(zero_n == 1){
      result.time_total += S_TIME;
      Success(node_array, &result);
    }
    else{ //zero_n > 1
      result.time_total += C_TIME;
      Collision(node_array, &result);
    }
  }

  print_result_total(result);
  return 0;
}
