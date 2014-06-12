#include "t_data_flow.h"
#include "compiler/t_compiler.h"
#include "data_structures/graph/t_depth_first_search.h"
//class t_dotcfgtree;

t_data_flow::t_data_flow()
{
  this->flows = new std::vector<t_flow *>;
  this->blocks = new std::vector<t_basic_block *>;

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
  std::vector<t_node<t_threeaddresscode> *> b_blocks = this->control_flow_graph->getgraph()->getnodes();
  for(std::vector<t_node<t_threeaddresscode> *>::iterator it = b_blocks .begin(); it != b_blocks .end(); ++it)
  {
    std::cout << std::endl << std::endl;
    std::cout << "block id = " << (*it)->getid() << std::endl;
    std::cout << *((*it)->getvertex()) << std::endl;
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
  //  this->blocks->push_back(bb);
}

void t_data_flow::start(t_threeaddresscode *tac)
{
  /* CFG */
  this->control_flow_graph = new t_control_flow_graph(tac);

  this->control_flow_graph->start(tac->get_code()->begin());
  // itstart (pour colorer le nouveau tac)

  t_dotcfgtree *dotcfgtreevisitor = new t_dotcfgtree;
  dotcfgtreevisitor->openfile("cfg.dot");
  t_depth_first_search::visit<t_dotcfgtree, t_cfg, t_threeaddresscode>(dotcfgtreevisitor, this->control_flow_graph->getgraph());

  this->get_flows();
  this->get_blocks();

  /* END CFG */
}

void available_expressions()
{

}

