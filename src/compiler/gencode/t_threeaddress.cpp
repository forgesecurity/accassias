#include "t_threeaddress.h"
#include <sstream>
#include <iostream>

t_threeaddress::t_threeaddress(t_tacsymbol tacsymbol, int addr_result, int addr_arg1)
{
  this->nbargs = 1;
  this->tacsymbol = tacsymbol;

  this->setaddrresult(addr_result);
  this->setaddrarg1(addr_arg1);
}

t_threeaddress::t_threeaddress(t_tacsymbol tacsymbol, int addr_result, int addr_arg1, int addr_arg2)
{
  this->nbargs = 2;
  this->tacsymbol = tacsymbol;

  this->setaddrresult(addr_result);
  this->setaddrarg1(addr_arg1);
  this->setaddrarg2(addr_arg2);
}

t_threeaddress::t_threeaddress(t_tacsymbol tacsymbol, int addr_result, int addr_arg1, std::string &const1)
{
  this->nbargs = 1;
  this->tacsymbol = tacsymbol;

  this->setaddrresult(addr_result);
  this->setaddrarg1(addr_arg1);
  this->setconst1(const1);
}

t_threeaddress::t_threeaddress(t_tacsymbol tacsymbol, int addr_result, std::string &const1)
{
  this->nbargs = 1;
  this->tacsymbol = tacsymbol;

  this->setaddrresult(addr_result);
  this->setconst1(const1);
}

t_threeaddress::t_threeaddress(t_threeaddress const &threeaddress)
{
  this->nbargs = threeaddress.nbargs;
  this->tacsymbol = threeaddress.tacsymbol;

  this->setaddrresult(threeaddress.addr_result);
  this->setaddrarg1(threeaddress.addr_arg1);
  this->setaddrarg2(threeaddress.addr_arg2);
  this->setconst1(threeaddress.const1);
}

std::string &t_threeaddress::getconst1()
{
  return this->const1;
}

int t_threeaddress::getaddrresult()
{
  return this->addr_result;
}

int t_threeaddress::getaddrarg1()
{
  return this->addr_arg1;
}

int t_threeaddress::getaddrarg2()
{
  return this->addr_arg2;
}

unsigned int t_threeaddress::getnbargs()
{
  return this->nbargs;
}

t_tacsymbol t_threeaddress::gettacsymbol()
{
  return this->tacsymbol;
}

void t_threeaddress::setconst1(const std::string &const1)
{
  this->const1 = const1;
}

void t_threeaddress::setaddrresult(int addr_result)
{
  this->addr_result = addr_result;
}

void t_threeaddress::setaddrarg1(int addr_arg1)
{
  this->addr_arg1 = addr_arg1;
}

void t_threeaddress::setaddrarg2(int addr_arg2)
{
  this->addr_arg2 = addr_arg2;
}

std::string printvar(int addr)
{
  std::stringstream streamtemp;
  std::string temp("temp");

  streamtemp << addr;
  temp += streamtemp.str();

  return temp;
}

std::ostream &operator<<(std::ostream &out, t_threeaddress &threeaddress)
{
  switch(threeaddress.gettacsymbol())
  {
    case TAC_ASSIGN_TIMER:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = timer"; 

        break;
      }

    case TAC_ASSIGN_IF:
      {
        out << "if ";
        break;
      }

    case TAC_ASSIGN_IFTRUE:
      {
        out << "if true";
        break;
      }

    case TAC_ASSIGN_ELSEIF:
      {
        out << "elseif ";
        break;
      }

    case TAC_ASSIGN_ELSE:
      {
        out << "else ";
        break;
      }

    case TAC_ASSIGN_ENDIF:
      {
        out << "end if ";
        break;
      }

    case TAC_ASSIGN_ENDELSEIF:
      {
        out << "end elseif ";
        break;
      }

    case TAC_ASSIGN_ENDELSE:
      {
        out << "end else ";
        break;
      }

    case TAC_ASSIGN_NOELSE:
      {
        out << "no else ";
        break;
      }

    case TAC_ASSIGN_STARTFOR:
      {
        out << "start for ";
        break;
      }

    case TAC_ASSIGN_FOR:
      {
        out << "for ";
        break;
      }

    case TAC_ASSIGN_ENDFOR:
      {
        out << "end for ";
        break;
      }

    case TAC_ASSIGN_SHOWTAC:
      {
        out << "showtac ";
        break;
      }

    case TAC_ASSIGN_HIDETAC:
      {
        out << "hidetac ";
        break;
      }

    case TAC_ASSIGN_SHOWCODE:
      {
        out << "showcode ";
        break;
      }

    case TAC_ASSIGN_HIDECODE:
      {
        out << "hidecode ";
        break;
      }

    case TAC_ASSIGN_SHOWSTATEVM:
      {
        out << "showstatevm ";
        break;
      }

    case TAC_ASSIGN_HIDESTATEVM:
      {
        out << "hidestatevm ";
        break;
      }

    case TAC_ASSIGN_READPOL:
      {
        out << "readpol ";
        break;
      }

    case TAC_ASSIGN_SUBINSTRUCTIONS:
      {
        out << "subinstructions " << threeaddress.getaddrarg1();
        break;
      }

    case TAC_ASSIGN_INSTRUCTIONS:
      {
        out << "instructions ";
        break;
      }

    case TAC_ASSIGN_PROG_JUMP:
      {
        out << "jump " << threeaddress.getaddrresult();
        break;
      }

    case TAC_ASSIGN_STARTCALL:
      {
        out << "start call ";
        break;
      }

    case TAC_ASSIGN_CALL:
      {
        out << "call " << threeaddress.getconst1();
        break;
      }

    case TAC_ASSIGN_METHOD:
      {
        out << "method " << threeaddress.getconst1();
        break;
      }

    case TAC_ASSIGN_FUNCTION:
      {
        out << "function " << threeaddress.getaddrresult();
        break;
      }

    case TAC_ASSIGN_CLASS:
      {
        out << "class " << threeaddress.getaddrresult();
        break;
      }

    case TAC_ASSIGN_ENDCLASS:
      {
        out << "endclass ";
        break;
      }

    case TAC_ASSIGN_RETURN_WITHOUT_VALUE:
      {
        out << "return";
        break;
      }

    case TAC_ASSIGN_RETURN:
      {
        out << "return " << threeaddress.getaddrresult() << " " << threeaddress.getaddrarg1();
        break;
      }

    case TAC_ASSIGN_PARAM:
      {
        out << "param " << threeaddress.getaddrresult();
        break;
      }

    case TAC_ASSIGN_DECLR:
      { 
        out << printvar(threeaddress.getaddrresult())
          << " ; "; 
        break;
      }

    case TAC_ASSIGN_DECLR_ARRAY:
      { 
        out << printvar(threeaddress.getaddrresult())
          << "[" << threeaddress.getaddrarg1() << "] ; "; 
        break;
      }

    case TAC_ASSIGN_PRINT:
      { 
        out << "print " << threeaddress.getaddrarg1();
        break;
      }

    case TAC_ASSIGN_EXIT:
      { 
        out << "exit " << threeaddress.getaddrarg1();
        break;
      }

    case TAC_ASSIGN_FACTOR_ARRAY:
      { 
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()) << "[" << printvar(threeaddress.getaddrarg2()) << "]"; 
        break;
      }

    case TAC_ASSIGN_ARRAY:
      { 
        out << printvar(threeaddress.getaddrresult()) << "[" << printvar(threeaddress.getaddrarg1()) << "]"
          << " = " << printvar(threeaddress.getaddrarg2()); 
        break;
      }

    case TAC_ASSIGNCA:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = call " << threeaddress.getconst1(); 
        break;
      }

    case TAC_ASSIGNL:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()); 
        break;
      }

    case TAC_ASSIGNV:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()); 
        break;
      }

    case TAC_ASSIGNC:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << threeaddress.getconst1(); 
        break;
      }

    case TAC_ASSIGNS:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << threeaddress.getconst1(); 
        break;
      }

    case TAC_ASSIGN_INF:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()) 
          << " < " << printvar(threeaddress.getaddrarg2()); 
        break;
      }

    case TAC_ASSIGN_INFEQUAL:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()) 
          << " <= " << printvar(threeaddress.getaddrarg2()); 
        break;
      }

    case TAC_ASSIGN_SUP:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()) 
          << " > " << printvar(threeaddress.getaddrarg2()); 
        break;
      }

    case TAC_ASSIGN_SUPEQUAL:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()) 
          << " >= " << printvar(threeaddress.getaddrarg2()); 
        break;
      }

    case TAC_ASSIGN_ADD:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()) 
          << " + " << printvar(threeaddress.getaddrarg2()); 
        break;
      }

    case TAC_ASSIGN_SUB:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1())
          << " - " << printvar(threeaddress.getaddrarg2()); 
        break;
      }

    case TAC_ASSIGN_DIV:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()) 
          << " / " << printvar(threeaddress.getaddrarg2()); 
        break;
      }

    case TAC_ASSIGN_MUL:
      {
        out << printvar(threeaddress.getaddrresult())
          << " = " << printvar(threeaddress.getaddrarg1()) 
          << " * " << printvar(threeaddress.getaddrarg2()); 
        break;
      }

    case TAC_ASSIGN_NULL:
      {
        out << "null";
        break;
      }

  }

  return out;
}





