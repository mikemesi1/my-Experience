#ifndef QUESTION5_H
#define QUESTION5_H
#include <vector>   //allows the use of stl vectors.
#include <list>     //allows the use of stl list functions.
#include<locale>    //to allow the use of isdigit()
#include<iterator>  //to allow the use of iterators.


using namespace std;


vector<int> visitedIndex;

class graph
{
    private:
        int size;
        std::vector< std::list<int> > adj_list; //stores the values of the adjacency matrix.
        std::vector< char > labels;             //stores the labels for the adjacency matrix.
        void depth_first(int v) const;      //depth first traversal of a vertex.
    public:
        graph( const char* filename );  //construcor builds adj_list and labels by reading in the adjacency matrix from the input file.
        ~graph();                   //destructor
        int get_size() const;       //gets the size
        void traverse( ) const;     //Traverses the graph with the depth first search method.
        void print ( ) const;       //Prints out the adjacency matrix.


};

#endif
