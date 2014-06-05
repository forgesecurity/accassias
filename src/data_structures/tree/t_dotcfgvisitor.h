#ifndef T_DOTCFGVISITOR_H
#define T_DOTCFGVISITOR_H

#include "data_structures/tree/t_treevisitor.h"
#include "data_structures/graph/t_node.h"
#include <sstream>

template <typename N>
class t_dotcfgvisitor : public t_treevisitor<N>
{

  public:
    t_dotcfgvisitor(){
    };

    void initialize(){

      this->clear_current_node();

      *(this->outfile) << "digraph cfg {\nordering=out;\n";
    };

    void add_current_node(N* node)
    {
      if(!check_first_node_id)
      {
        check_first_node_id = true;		
        first_node_id = node->getid();
      }

      if(!node->getlabel().empty())
      {
        std::stringstream ss;
        ss << node->getid();

        current_node_label = current_node_label + "\\n" + node->getlabel() + "_" + ss.str();
      }

    }

    void create_current_node()
    {
      *(this->outfile) 
        << first_node_id 
        << " [label=\"" 
        << current_node_label
        << "\"];\n";
    }

    void clear_current_node()
    {
      current_node_label = "";
      current_node_lexeme = "";
      first_node_id = 0;
      check_first_node_id = false;
    };


    void initialize_node(N* node){
      (void) node;

    };

    void examine_node(N *node){

      if(node->getlabel() == L_IF)
      {
        this->add_current_node(node);
        this->create_current_node();

        // IFTRUE
        *(this->outfile) 
          << first_node_id 
          << "->"
          << node->getchild(0)->getid()
          << " [label=\""
          << "if true"
          << "\"]"
          << ";\n";

        // ENDIF
        *(this->outfile) 
          << first_node_id 
          << "->"
          << node->getchild(1)->getid()
          << " [label=\""
          << "if false"
          << "\"]"
          << ";\n";

        this->clear_current_node();
      }
      else if(node->getlabel() == L_ENDIF)
      {
        this->create_current_node();

        this->clear_current_node();
        this->add_current_node(node);
      }
      else
        this->add_current_node(node);

    };


    void examine_node_target(N *node, N *targetnode){
      (void) node;
      (void) targetnode;

    };
    void finish_node(N *node){
      (void) node;
    };
    void finish(){

      this->create_current_node();

      *(this->outfile) << "\n\n}";
      this->outfile->close();
    };
    void openfile(const char *file){
      this->outfile = new std::ofstream(file, std::ios::out);
    };

  private:
    std::ofstream *outfile;
    std::string current_node_label;
    std::string current_node_lexeme;
    unsigned int first_node_id;
    bool check_first_node_id;

};

#endif


