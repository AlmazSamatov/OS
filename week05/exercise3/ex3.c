#include <stdio.h> 

void* producer(void *ptr) {
  int i;
  for (i = 1; i <= MAX; i++) {
    /* produce */
    // add your code here ...
  }
  pthread_exit(0);
}

void* consumer(void *ptr) {
/* consume */
// add your code here ...
}


int main(int argc, char **argv) {
  pthread_t pro, con;
  
  pthread_create(&con, NULL, consumer, NULL);
  pthread_create(&pro, NULL, producer, NULL);
  
  pthread_join(con, NULL);
  pthread_join(pro, NULL);
}