#include "define.h"
#include "node.h"


/* local function */
void initialize_node_single(Node *node, int cwmin, int cwmax){

  extern int uniform_int(int);

  node->cwmin = cwmin;
  node->cwmax = cwmax;
  node->cwnow = node->cwmin;

  node->bo = uniform_int(node->cwmin);
  node->retry_bit = 0;
  node->retry_count = 0;

  return;
}


/********************************/
/*       global function        */
/********************************/
void initialize_node_array(Node *node_array){

  int i;

  for(i=0; i < NODE_N; i++){
    initialize_node_single(&node_array[i], CWmin, CWmax);
  }

  return;
}
