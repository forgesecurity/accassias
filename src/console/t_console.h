#ifndef T_CONSOLE_H 
#define T_CONSOLE_H 

#include <string>
#include <fstream>
#include "virtual_machine/t_vm.h"
#include "console/t_time.h"

#define SIZE_LINES 20

class t_console 
{
  public:
    t_console();
    void read();
    void start();
    t_vm *get_vm();
    void print_stack();
    void print_space(std::string);
    void print_space(unsigned int);

  private:
    bool getfromstdin;
    t_vm *vm;
    std::vector<std::string> linesstring;
    unsigned int nb_lines;
    timestamp_t t0;
    timestamp_t t1;
};

#endif

