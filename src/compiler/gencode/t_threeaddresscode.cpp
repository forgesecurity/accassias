#include "t_threeaddresscode.h"
#include <iostream>

std::vector<t_threeaddress> *t_threeaddresscode::get_code()
{
  return code;
}

t_threeaddresscode::t_threeaddresscode()
{
  this->code = new std::vector<t_threeaddress>;
  this->set_print_tac(true);
}

t_threeaddresscode::t_threeaddresscode(std::vector<t_threeaddress>::iterator it1, std::vector<t_threeaddress>::iterator it2)
{
  this->code = new std::vector<t_threeaddress>(it1, it2);
  this->set_print_tac(true);
}

bool t_threeaddresscode::print_tac()
{
  return this->p_tac;
}

void t_threeaddresscode::set_print_tac(bool state)
{
  this->p_tac = state;
}

std::ostream &operator<<(std::ostream &out, t_threeaddresscode &tac)
{
  std::vector<t_threeaddress>::iterator it;
  for(it = tac.get_code()->begin(); it < tac.get_code()->end(); it++)
    out << *it << "\n";

  return out;
}

void t_threeaddresscode::print_console()
{
  std::vector<t_threeaddress>::iterator it;

  if(this->print_tac())
  {	  
    std::cout << " : THREEADDRESSCODE : \033[1;35mthree address code here\033[0m" << std::endl << std::endl;

    for(it = this->code->begin(); it < this->code->end(); it++)
      std::cout << *it << std::endl;
  }
}

