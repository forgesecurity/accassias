#ifndef T_DOTCFGTREEVISITOR_H
#define T_DOTCFGTREEVISITOR_H

#include "data_structures/tree/t_treevisitor.h"
#include "data_structures/graph/t_node.h"
#include <sstream>

template <typename N>
class t_dotcfgtreevisitor : public t_treevisitor<N>
{
  public:
    t_dotcfgtreevisitor(){
    };

    void initialize(){
      *(this->outfile) << "digraph cfg {\nordering=out;\n";	
    };

    void initialize_node(N* node){

      *(this->outfile) 
        << node->getlabel()
        << node->getid()
        << " [label=\"" 
        << node->getlabel() 
        << "_"
        << *(node->getvertex())
        << "\"];\n";
    };

    void examine_node(N *node){
      (void) node;
    };
    void examine_node_target(N *node, N *targetnode){
      *(this->outfile) 
        << node->getlabel()
        << node->getid()
        << "->"
        << targetnode->getlabel()
        << targetnode->getid()
        << ";\n";
    };
    void finish_node(N *node){
      (void) node;
    };
    void finish(){
      *(this->outfile) << "\n\n}";
      this->outfile->close();
    };
    void openfile(const char *file){
      this->outfile = new std::ofstream(file, std::ios::out);
    };

  private:
    std::ofstream *outfile;

};

#endif


