#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "util.h"

void arg_set(int argc, char *argv[]){

  /* argc == 2 , argv[1]: NODE_N  */
  if(argc !=2) {
    fprintf(stderr, "usage:./a.out NODE_N\n");
    error_print(__FILE__,__LINE__);
  }

  NODE_N = atoi(argv[1]);

  return;
}

void error_print(char *file, int line){

  char err_place[128];

  sprintf(err_place, "%s:%d", file, line);
  perror(err_place);

  exit(1);
}


int uniform_int(int max){

  static long seed = -1234;
  extern double ran2(long *);

  return (int)(ran2(&seed)*(max+1));
}
