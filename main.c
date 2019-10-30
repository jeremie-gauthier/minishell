#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv, char **envp) {
   char *foo[] = { "/bin/ls", "-l", NULL };


 // int ret = execve(foo[0], foo, envp);
  int ret = execve(argv[1], &argv[1], envp);
 // int ret = execve("/bin/ls", argv, envp);


  if (ret == -1 )
      perror("Plantated" );


  return 0;
}
