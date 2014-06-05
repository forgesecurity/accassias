#ifndef T_STDLIB_H
#define T_STDLIB_H

#include "data_structures/graph/t_node.h"
#include "compiler/syntax/t_identifiervertex.h"
#include "compiler/syntax/t_function.h"
#include <map>

class t_stdlib
{
  public:
    static void importfunctions(std::map<std::string, t_function *> &);
    static void importfunctionscode(std::vector<int> &);
};

#endif


