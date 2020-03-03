#include "functions.h"

int main() {
  char *argv[MAX_ARGS], *cmd1[MAX_ARGS], *cmd2[MAX_ARGS];
  PipeRedirect pipe_redirect;
  int argc;

  while (true) {
    cout << "Shell> ";

    argc = read_args(argv);

    pipe_redirect = parse_command(argc, argv, cmd1, cmd2);

    if (pipe_redirect == PIPE)          // piping
      pipe_cmd(cmd1, cmd2);
    else if (pipe_redirect == REDIRECT) // redirecting
      redirect_cmd(cmd1, cmd2);
    else if (pipe_redirect == WRITE) // writing
      write_cmd(cmd1,cmd2);
    else
      run_cmd(argc, argv);              // neither

    for (int i=0; i<argc; i++)
      argv[i] = NULL;
  }

  return 0;
}
