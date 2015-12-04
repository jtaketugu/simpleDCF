#ifndef _NODE_H
#define _NODE_H


int NODE_N;

// N
//#define AP_N 1
//#define NORMAL_N 1 // define <-> global
//#define SELFISH_N 0
//#define UNSATU_N 0  // define <-> global
//#define NODE_N (AP_N + NORMAL_N + SELFISH_N + UNSATU_N)

//KIND_NODE
//#define KIND_N 4
//#define NORMAL 0
//#define AP 1
//#define SELFISH 2
//#define UNSATU 3


typedef struct _node{

  int cwmin;
  int cwmax;
  int cwnow;
  
  int bo; /* redisual backoff */
  int retry_bit; /* 0:FirstAttempt, 1:Retransmission */
  int retry_count; /* short retry count */
  
}Node;



extern void initialize_node_array(Node *node_array);

#endif
