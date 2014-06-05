#include "t_data_flow.h"

t_data_flow::t_data_flow()
{
  this->flows = new std::vector<t_flow *>;
  this->blocks = new std::vector<t_basicblock *>;

}

t_label t_data_flow::init(t_statement *st)
{
  t_label label_init;
  return label_init;
}

t_label *t_data_flow::final(t_statement *st)
{
  t_label *label_final;
  return label_final;
}

void t_data_flow::get_blocks()
{
  for(std::vector<t_basicblock *>::iterator it = blocks->begin(); it != blocks->end(); ++it)
  {
    std::cout << std::endl << std::endl;
    std::cout << "block id = " << (**it).getnode()->getid() << std::endl;
    std::cout << (**it) << std::endl;
  }
}

void t_data_flow::get_flows()
{
  for(std::vector<t_flow *>::iterator it = flows->begin(); it != flows->end(); ++it)
    std::cout << "flow " << (**it) << std::endl;
}

void t_data_flow::add_flow(t_label lb1, t_label lb2)
{
  t_flow *flow = new t_flow(lb1, lb2);
  this->flows->push_back(flow);
}

void t_data_flow::add_block(t_basicblock *bb)
{
  this->blocks->push_back(bb);
}

void available_expressions()
{

}

