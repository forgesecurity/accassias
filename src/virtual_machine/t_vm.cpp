#include "t_vm.h"
#include "multi_precision/t_mparray.h"
#include "multi_precision/t_mpinteger.h"
#include "multi_precision/t_string.h"
#include "multi_precision/t_mppolynomial.h"
#include "console/t_time.h"
#include <iostream>
#include <sstream>

t_vm::t_vm()
{
  this->co = 0;
  this->nbmpgenerics = 0;
  this->sp = SIZE_MEM - SIZE_SECTION_STACK;
  this->beg = SIZE_MEM - SIZE_SECTION_STACK - SIZE_SECTION_HEAP;
  this->bel = 0;

  this->mem.resize(SIZE_MEM);
  this->gencode = new t_gencode();
}

t_gencode *t_vm::get_gencode()
{
  return this->gencode;
}

std::vector<int> &t_vm::get_mem()
{
  return this->mem;
}

unsigned int t_vm::get_sp()
{
  return this->sp;
}

unsigned int t_vm::get_co()
{
  return this->co;
}

void t_vm::set_co(unsigned int co)
{
  this->co = co;
}

unsigned int t_vm::get_executed_co()
{
  return this->executed_co;
}

void t_vm::set_executed_co(unsigned int executed_co)
{
  this->executed_co = executed_co;
}

unsigned int t_vm::get_bel()
{
  return this->bel;
}

unsigned int t_vm::get_beg()
{
  return this->beg;
}

bool t_vm::get_endwhile()
{
  return this->endwhile;
}

void t_vm::set_endwhile(bool endwhile)
{
  this->endwhile = endwhile;
}

void t_vm::copy_code_to_mem(std::vector<int> &code)
{
  unsigned int i = 0;
  std::vector<int>::iterator it;

  for(it = code.begin(); it < code.end(); it++)
    this->mem[i ++] = *it;

  if(i > SIZE_SECTION_CODE)
    std::cout << "ALERT" << std::endl;
}

void t_vm::set_print_statevm(bool state)
{
  this->print_statevm = state;
}

bool t_vm::get_print_statevm()
{
  return this->print_statevm;
}

t_opcode t_vm::start()
{
  this->endwhile = false;

  t_mpinteger *mpint1;
  t_mpinteger *mpint2;
  t_mparray *mparr;
  t_mpgeneric *mpgen1;
  t_mpgeneric *mpgen2;
  t_string *str1;
  unsigned int i;
  unsigned int v;

  t_opcode opcode;

  std::ostringstream out;

  opcode = (t_opcode) this->mem[this->co];

  switch(opcode)
  {
    case JUMP:
      {
        this->co = this->mem[this->co + 1]; 
        break;
      }

    case EMPTIME:
      {
        out << get_timestamp();

        mpint1 = t_mpinteger::fromstring(out.str());
        this->mpgenerics.push_back(mpint1);

        this->mem[this->sp ++] = nbmpgenerics ++;
        this->co ++; 

        break;
      }

    case EMPT:
      {
        i = this->mem[-- this->sp];

        mparr = (t_mparray *) this->mpgenerics[this->mem[this->co + 1]];
        mpgen1 = mparr->getcase(this->mpgenerics[i]->toint());

        this->mpgenerics.push_back(mpgen1);

        this->mem[this->sp ++] = nbmpgenerics ++;
        this->co += 2; 

        break;
      }

    case DEPT:
      {
        v = this->mem[-- this->sp];
        i = this->mem[-- this->sp];

        mparr = (t_mparray *) this->mpgenerics[this->mem[this->co + 1]];
        mparr->setcase(this->mpgenerics[i]->toint(), this->mpgenerics[v]);
        this->co += 2;

        break;
      }

    case DEPL:
      {
        this->mem[this->bel + this->mem[this->co + 1]] = this->mem[-- this->sp];
        this->co += 2;
        break;
      }

    case EMPL: 
      {
        this->mem[this->sp ++] = this->mem[this->bel + this->mem[this->co + 1]];
        this->co += 2;
        break;
      }

    case EMPG:
      {
        this->mem[this->sp ++] = this->mem[this->beg + this->mem[this->co + 1]];
        this->co += 2;
        break;
      }

    case EMPC:
      {
        mpint1 = t_mpinteger::fromcode(this->mem, this->co + 1);
        this->mpgenerics.push_back(mpint1);

        this->mem[this->sp ++] = nbmpgenerics ++;
        this->co = this->co + 3 + mpint1->getsize(); 

        break;
      }

    case EMPS:
      {
        str1 = t_string::fromcode(this->mem, this->co);
        this->mpgenerics.push_back(str1);

        this->mem[this->sp ++] = nbmpgenerics ++;
        this->co = this->co + 2 + str1->getsize(); 

        break;
      }

    case PILE: 
      {
        this->sp = this->sp + this->mem[co + 1];	
        this->co += 2;
        break;
      }

    case CALL:
      {
        this->mem[this->sp ++] = this->co + 2;
        this->co = this->mem[this->co + 1];
        break;
      }

    case FUNCTION:
      {
        this->mem[this->sp ++] = this->bel;
        this->bel = this->sp;
        this->co += 2;
        break;
      }

    case CLASS:
      {
        this->mem[this->sp ++] = this->bel;
        this->bel = this->sp;
        this->co += 2;
        break;
      }

      /*
         case ENDCLASS:
         { 
         this->mem[this->bel - (this->mem[this->co + 1] + 3)] = this->mem[-- this->sp];
         this->sp = this->bel;
         this->bel = this->mem[-- this->sp];
         this->co = this->mem[-- this->sp]; 
         break;
         }
       */

    case INSTRUCTIONS:
      {
        this->mem[this->sp ++] = this->bel;
        this->bel = this->sp;
        this->co ++;
        break;
      }

    case INF:
      {
        mpint1 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 2]];
        mpint2 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 1]];

        this->mem[this->sp ++] = t_mpinteger::inf(mpint1, mpint2);
        this->co ++;
        break;
      }

    case INFEQUAL:
      {
        mpint1 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 2]];
        mpint2 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 1]];

        this->mem[this->sp ++] = t_mpinteger::infequal(mpint1, mpint2);
        this->co ++;
        break;
      }

    case SUP:
      {
        mpint1 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 2]];
        mpint2 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 1]];

        this->mem[this->sp ++] = t_mpinteger::sup(mpint1, mpint2);
        this->co ++;
        break;
      }

    case SUPEQUAL:
      {
        mpint1 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 2]];
        mpint2 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 1]];

        this->mem[this->sp ++] = t_mpinteger::supequal(mpint1, mpint2);
        this->co ++;
        break;
      }

    case ADD:
      {
        mpint1 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 2]];
        mpint2 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 1]];
        mpint2 = t_mpinteger::add(mpint1, mpint2);

        this->mpgenerics[this->mem[sp - 1]] = (t_mpgeneric *) mpint2;
        this->co ++;
        break;
      }

    case SUB:
      {
        mpint1 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 2]];
        mpint2 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 1]];
        mpint2 = t_mpinteger::sub(mpint1, mpint2);

        this->mpgenerics[this->mem[sp - 1]] = (t_mpgeneric *) mpint2;
        this->co ++;
        break;
      }

    case MUL: 
      {
        mpint1 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 2]];
        mpint2 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 1]];
        mpint2 = t_mpinteger::mul(mpint1, mpint2);

        this->mpgenerics[this->mem[sp - 1]] = (t_mpgeneric *) mpint2;
        this->co ++;
        break;
      }

    case DIV: 
      {
        mpint1 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 2]];
        mpint2 = (t_mpinteger *) this->mpgenerics[this->mem[sp - 1]];
        mpint2 = t_mpinteger::div(mpint1, mpint2);

        this->mpgenerics[this->mem[sp - 1]] = (t_mpgeneric *) mpint2;
        this->co ++;
        break;
      }

    case RETURN:
      { 
        this->mem[this->bel - (this->mem[this->co + 1] + 3)] = this->mem[-- this->sp];
        this->sp = this->bel;
        this->bel = this->mem[-- this->sp];
        this->co = this->mem[-- this->sp]; 
        break;
      }

    case EXIT:
      {
        this->endwhile = true;
        break;
      }

    case SHOWTAC:
      {
        this->co ++;
        this->get_gencode()->get_gentac()->get_tac()->set_print_tac(true);

        break;
      }

    case HIDETAC:
      {
        this->co ++;
        this->get_gencode()->get_gentac()->get_tac()->set_print_tac(false);

        break;
      }

    case SHOWCODE:
      {
        this->co ++;
        this->get_gencode()->set_print_code(true);

        break;
      }

    case HIDECODE:
      {
        this->co ++;
        this->get_gencode()->set_print_code(false);

        break;
      }

    case SHOWSTATEVM:
      {
        this->co ++;
        this->set_print_statevm(true);

        break;
      }

    case HIDESTATEVM:
      {
        this->co ++;
        this->set_print_statevm(false);

        break;
      }

    case IFFALSE:
      {
        if(!this->mem[sp - 1])
        {
          this->co = this->mem[this->co + 1];
          break;
        }

        this->co += 2;
        break;
      }

    case PRINT:
      {
        unsigned int test = this->mem[this->bel + this->mem[this->co + 1]];
        std::cout << *mpgenerics[this->mem[this->bel + this->mem[this->co + 1]]] << std::endl;

        this->co += 2;
        break;
      }

    case READPOL:
      {
        unsigned int test = this->bel + this->mem[this->co + 1];
        std::cout << *mpgenerics[this->mem[this->bel + this->mem[this->co + 1]]] << std::endl;
        t_string *tstr = (t_string *) mpgenerics[this->mem[this->bel + this->mem[this->co + 1]]];
        t_mppolynomial *mppol1 = (t_mppolynomial *) t_mppolynomial::read('X', tstr);

        this->co ++;
        break;
      }

    case END:
      {
        this->endwhile = true;
        break;
      }

    default: 
      {
        this->co ++;
        break;
      }
  }



  return opcode;
}



