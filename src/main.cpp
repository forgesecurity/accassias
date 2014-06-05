#include "console/t_console.h"

int main(int argc, char **argv)
{

  t_console *console = new t_console;  
  console->read();

  std::string str1 ="./stdlib.aca";
  console->get_vm()->get_gencode()->get_syntax()->get_lexical()->set_file_source(str1.c_str());
  console->start();

  std::string str2 ="./poly.aca";
  console->get_vm()->get_gencode()->get_syntax()->get_lexical()->set_file_source(str2.c_str());
  console->start();

  if(argc > 0)
    console->get_vm()->get_gencode()->get_syntax()->get_lexical()->set_file_source(argv[1]);

  while(true)
    console->start();

  return 0;
}


