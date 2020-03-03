#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
using namespace std;

// Arreglo de comandos del usuario
const int MAX_ARGS = 256;

enum PipeRedirect {PIPE, PIPES, REDIRECT, WRITE, NEITHER};

// lee lo que escriba el usuario
int read_args(char**);

// split de comandos
PipeRedirect parse_command(int, char**, char**, char**);

// hace piping del primer comando al segundo
void pipe_cmd(char**, char**);

// redirige el output de un comando hacia un archivo
void redirect_cmd(char**, char**);

void write_cmd(char**, char**);

// corre los comandos
void run_cmd(int, char**);

