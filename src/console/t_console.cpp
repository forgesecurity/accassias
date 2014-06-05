#include "t_console.h"

t_console::t_console()
{
  this->nb_lines = 0;
  this->vm = new t_vm;

  this->get_vm()->get_gencode()->get_gentac()->get_tac()->set_print_tac(false);
  this->get_vm()->get_gencode()->set_print_code(false);
  this->get_vm()->set_print_statevm(false);
  this->linesstring.resize(SIZE_LINES);

  this->t0 = 0;
  this->t1 = 0;
}


void t_console::print_stack()
{
  unsigned int j = 0;
  unsigned int i;

  for(i = this->get_vm()->get_sp(); i >= SIZE_MEM - SIZE_SECTION_STACK; i --)
  {
    std::cout << " " << this->get_vm()->get_mem()[i];
    if(j++ > 20)
      break;
  }
}

void t_console::print_space(std::string str)
{
  unsigned int size = 30 - str.size();
  unsigned int i;

  std::cout << str;	

  for(i = 0; i < size; i ++)
    std::cout << " ";
}

void t_console::print_space(unsigned int var)
{
  if(var < 10)
    std::cout << "         ";
  else if(var >= 10 && var < 100)
    std::cout << "        ";
  else if(var >= 100 && var < 1000)
    std::cout << "       ";
  else if(var >= 1000 && var < 10000)
    std::cout << "      ";
  else if(var >= 10000 && var < 100000)
    std::cout << "     ";
  else if(var >= 100000 && var < 1000000)
    std::cout << "    ";
  else if(var >= 1000000 && var < 10000000)
    std::cout << "   ";
  else if(var >= 10000000 && var < 100000000)
    std::cout << "  ";
  else if(var >= 100000000 && var < 1000000000)
    std::cout << " ";

  std::cout << var;
}

void t_console::start()
{		 
  if(!this->get_vm()->get_gencode()->start())
    return;

  if(this->get_vm()->get_gencode()->get_syntax()->get_lexical()->get_current_token() == T_TAB)
  {
    unsigned int nb_comp = 0;
    std::map<std::string, t_function *> *functions = this->get_vm()->get_gencode()->get_syntax()->get_functions();
    std::map<std::string, t_function *>::iterator it;
    unsigned int nb_char = this->get_vm()->get_gencode()->get_syntax()->get_lexical()->get_current_line_string().length();
    std::string str =  this->get_vm()->get_gencode()->get_syntax()->get_lexical()->get_current_line_string();
    std::string str_found;

    std::cout << std::endl;

    for(it = functions->begin(); it != functions->end(); it ++)
    {
      if((*it).first.substr(0, nb_char).compare(str) == 0)
      {
        str_found = (*it).first;
        nb_comp ++;
      }
    }

    if(nb_comp)
      std::cout << str_found << std::endl;
  }
  else
  {
    this->get_vm()->copy_code_to_mem(this->get_vm()->get_gencode()->get_code());

    timestamp_t t0_gen = get_timestamp();		
    unsigned int temp_co;

    this->get_vm()->set_endwhile(false);

    if(this->get_vm()->get_print_statevm())
    { 
      std::cout << " : VM : \033[1;35mstate and stack here\033[0m" << std::endl << std::endl;
      std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;
      std::cout << "|         co |        bel  |         sp | instruction                    |  stack                        " << std::endl;
      std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;		
    }

    while(this->get_vm()->get_co() < SIZE_SECTION_CODE && !this->get_vm()->get_endwhile())
    {	
      if(this->get_vm()->get_print_statevm())
      {
        temp_co = this->get_vm()->get_co();
        std::cout << "| "; this->print_space(this->get_vm()->get_co());
        std::cout << " | "; this->print_space(this->get_vm()->get_bel());
        std::cout << "  | "; this->print_space(this->get_vm()->get_sp());
        std::cout << " | "; this->print_space(this->get_vm()->get_gencode()->show_code_of_nextintruction(temp_co));
        std::cout << " | "; this->print_stack(); 
        std::cout << std::endl;
      }

      this->get_vm()->start();
    }

    if(this->get_vm()->get_print_statevm())	
      std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;		

    timestamp_t t1_gen = get_timestamp();
    t1_gen = t1_gen - t0_gen;

    std::cout << "time = " << t1_gen << " ms" << std::endl;

    this->linesstring[this->nb_lines % SIZE_LINES] = this->get_vm()->get_gencode()->get_syntax()->get_lexical()->get_current_line_string();
    this->nb_lines ++;
  }

  std::cout << "\033[1;34maca\033[0m\033[1;36m$\033[0m ";	
}

t_vm *t_console::get_vm()
{
  return this->vm;
}

void t_console::read()
{
  std::string contenu;
  std::ifstream is;

  std::string test = std::string(getenv("HOME")) + "/.accassias";
  is.open(test.c_str(), std::ifstream::in);

  std::cout << std::endl;

  if(is.good())
  {
    while(is.good())
    {
      getline(is, contenu);
      if(contenu == "printthreeaddresscode=yes")
      {
        this->vm->get_gencode()->get_gentac()->get_tac()->set_print_tac(true);
        std::cout << "     CONSOLE : \033[1;32mthree address code will be printed\033[0m" << std::endl;
      }

      if(contenu == "printcode=yes")
      {
        this->vm->get_gencode()->set_print_code(true);
        std::cout << "     CONSOLE : \033[1;32mcode will be printed\033[0m" << std::endl;
      }

      if(contenu == "printstatevm=yes")
      {
        this->vm->set_print_statevm(true);
        std::cout << "     CONSOLE : \033[1;32mstate vm + stack will be printed\033[0m" << std::endl;
      }
    }

    is.close(); 
  }

  std::cout << std::endl;
  std::cout << std::endl;
}

