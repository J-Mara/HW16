#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  printf("pre-fork\n");
  fork();
  printf("PID: %d\n", getpid());
  int rand_num = rand()%4;
  sleep(rand_num);
  printf("I have finished\n");
  int child_status;
  waitpid(getpid(), &child_status, 0);
  WEXITSTATUS(child_status);
  printf("child pid: %d\n", getpid());
  printf("sleep time: %d\n", rand_num);
  printf("done\n");
  return 0;
}
