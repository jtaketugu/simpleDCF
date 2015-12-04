#ifndef _RESULT_H
#define _RESULT_H

#define RESULT_CUT 10e6 //[microsec]

typedef struct _result_kind{

  int suc;
  int col;

}ResultElement;

typedef struct _result{

  int ch_suc;
  int ch_col;
  int ch_idle;

  double time_total;

  ResultElement *node_total; //[NODE_N]

}Result;


// result.c
extern void initialize_result(Result *r);

extern void result_AllBackoffDec(Result *);
extern void result_Success(Result *,int);
extern void result_Collision(Result *, int, int);

extern void print_result_total(Result);

#endif
