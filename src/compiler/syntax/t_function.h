#ifndef T_FUNCTION_H
#define T_FUNCTION_H

#include "t_identifier.h"

class t_function : public t_identifier
{
  public:
    t_function();
    t_function(unsigned int, unsigned int, s_symbol, int);
    t_function(unsigned int, unsigned int, s_symbol, std::string &);
    t_function(unsigned int, unsigned int, s_symbol, std::string &, int);
    t_function(unsigned int, unsigned int, s_symbol, std::string &, int, unsigned int);
    t_function(unsigned int, unsigned int, s_symbol, std::string &, int, unsigned int, unsigned int);

    bool ismethod();

    void addarg();
    virtual unsigned int getnbargs();
    virtual void setnbargs(unsigned int);

    virtual unsigned int getnblocalvariables();
    virtual void setnblocalvariables(unsigned int);

  private:
    unsigned int nbargs;
    unsigned int nblocalvariables;
};

#endif
