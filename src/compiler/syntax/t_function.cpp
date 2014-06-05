#include "t_function.h"

  t_function::t_function() 
: t_identifier()
{
  this->nbargs = 0;
  this->nblocalvariables = 0;
}

  t_function::t_function(unsigned int line, unsigned int column, s_symbol symbol, int addr) 
: t_identifier(line, column, symbol)
{
  this->addr = addr;
  this->nbargs = 0;
  this->nblocalvariables = 0;
}

  t_function::t_function(unsigned int line, unsigned int column, s_symbol symbol, std::string &lexeme) 
: t_identifier(line, column, symbol, lexeme)
{
  this->nbargs = 0;
  this->nblocalvariables = 0;
}

  t_function::t_function(unsigned int line, unsigned int column, s_symbol symbol, std::string &lexeme, int addr) 
: t_identifier(line, column, symbol, lexeme, addr)
{
  this->nbargs = 0;
  this->nblocalvariables = 0;
}

  t_function::t_function(unsigned int line, unsigned int column, s_symbol symbol, std::string &lexeme, int addr, unsigned int nbargs) 
: t_identifier(line, column, symbol, lexeme, addr)
{
  this->nbargs = nbargs;
  this->nblocalvariables = 0;
}

  t_function::t_function(unsigned int line, unsigned int column, s_symbol symbol, std::string &lexeme, int addr, unsigned int nbargs, unsigned int nblocalvariables) 
: t_identifier(line, column, symbol, lexeme, addr)
{
  this->nbargs = nbargs;
  this->nblocalvariables = nblocalvariables;
}

void t_function::addarg()
{

}

unsigned int t_function::getnbargs()
{
  return this->nbargs;
}

void t_function::setnbargs(unsigned int nbargs)
{
  this->nbargs = nbargs;
}

unsigned int t_function::getnblocalvariables()
{
  return this->nblocalvariables;
}

void t_function::setnblocalvariables(unsigned int nblocalvariables)
{
  this->nblocalvariables = nblocalvariables;
}



