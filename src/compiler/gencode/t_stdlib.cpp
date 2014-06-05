#include "t_stdlib.h"
#include "compiler/syntax/t_function.h"
#include "t_opcode.h"

void t_stdlib::importfunctions(std::map<std::string, t_function *> &functions)
{
  std::string str1("exit");
  std::string str2("print");

  functions.insert(std::pair<std::string, t_function *>(str1, new t_function(0, 0, S_IDENTIFIER, str1, 0, 0)));
  functions.insert(std::pair<std::string, t_function *>(str2, new t_function(0, 0, S_IDENTIFIER, str2, 1, 1)));
}

void t_stdlib::importfunctionscode(std::vector<int> &code)
{
  // exit
  code.push_back(EXIT);

  // print
  code.push_back(PRINT);
}

