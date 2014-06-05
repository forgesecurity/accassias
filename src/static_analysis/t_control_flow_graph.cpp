#include "t_control_flow_graph.h"

t_control_flow_graph::t_control_flow_graph(t_threeaddresscode *tac)
{
  this->tac = tac;
  this->cfg = new t_cfg;
  this->data_flow = new t_data_flow;
  this->data_flow_bb = new t_data_flow;	
}

t_cfg *t_control_flow_graph::getgraph()
{
  return this->cfg;
}

t_data_flow *t_control_flow_graph::get_data_flow()
{
  return this->data_flow;
}

void t_control_flow_graph::start(std::vector<t_threeaddress>::iterator it_start)
{
  t_basicblock *first_bb = new t_basicblock(
      it_start, this->tac->get_code()->end(), new t_node<t_threeaddresscode>(L_BB, new t_threeaddresscode));

  this->build(first_bb);

  this->cfg->addnode(first_bb->getnode());
  this->cfg->setroot(first_bb->getnode());
}

t_basicblock *t_control_flow_graph::build(t_basicblock *bb1)
{
  std::vector<t_threeaddress>::iterator it;
  for(it = bb1->get_it_start(); it < bb1->get_it_end(); it++)
  {
    bb1->getnode()->getvertex()->get_code()->push_back((*it));

    if((*it).gettacsymbol() == TAC_ASSIGN_IF ||
        (*it).gettacsymbol() == TAC_ASSIGN_ELSEIF)
    {	
      t_basicblock *iftrue_bb = new t_basicblock(it + 1, bb1->get_it_end(), 
          new t_node<t_threeaddresscode>(L_BB, new t_threeaddresscode));

      t_basicblock *it_ifend = this->build(iftrue_bb);


      t_basicblock *iffalse_bb = new t_basicblock(it_ifend->get_it_start() + 1, bb1->get_it_end(), 
          new t_node<t_threeaddresscode>(L_BB, new t_threeaddresscode));

      t_basicblock *it_iffalseend = this->build(iffalse_bb);


      this->cfg->addnode(iftrue_bb->getnode());
      this->cfg->addnode(iffalse_bb->getnode());

      this->data_flow->add_flow(bb1->getnode()->getid(), iftrue_bb->getnode()->getid());
      this->data_flow->add_flow(bb1->getnode()->getid(), iffalse_bb->getnode()->getid());

      this->data_flow->add_block(bb1);
      this->data_flow->add_block(iftrue_bb);
      this->data_flow->add_block(iffalse_bb);

      bb1->getnode()->addchild(iftrue_bb->getnode());
      bb1->getnode()->addchild(iffalse_bb->getnode());



      t_basicblock *afterif_bb = new t_basicblock(iffalse_bb->get_it_start() + 1, bb1->get_it_end(), 
          new t_node<t_threeaddresscode>(L_BB, new t_threeaddresscode));

      t_basicblock *it_end = this->build(afterif_bb);

      this->cfg->addnode(afterif_bb->getnode());


      this->data_flow->add_flow(it_ifend->getnode()->getid(), afterif_bb->getnode()->getid());
      this->data_flow->add_flow(it_iffalseend->getnode()->getid(), afterif_bb->getnode()->getid());
      this->data_flow->add_block(afterif_bb);

      it_ifend->getnode()->addchild(afterif_bb->getnode());
      it_iffalseend->getnode()->addchild(afterif_bb->getnode());

      return afterif_bb;
    }
    else if((*it).gettacsymbol() == TAC_ASSIGN_ENDELSEIF)
    {	
      bb1->set_it_end(it);			
      return bb1;
    }
    else if((*it).gettacsymbol() == TAC_ASSIGN_ENDELSE)
    {	
      bb1->set_it_end(it);			
      return bb1;
    }
    else if((*it).gettacsymbol() == TAC_ASSIGN_NOELSE)
    {
      bb1->set_it_end(it);			
      return bb1;
    }
    else if((*it).gettacsymbol() == TAC_ASSIGN_ENDIF)
    {
      bb1->set_it_end(it);			
      return bb1;
    }
    else
    {

    }
  }

  bb1->set_it_end(it);			
  return bb1;
}

