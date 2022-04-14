#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "question5.h"
using namespace std;


int main(int argc, char** argv)
{
    if ( argc < 2 )
	{
        cerr << "args: input-file-name\n";
        return 1;
    }
    graph g(argv[1]);
    g.print();
    g.traverse();
    return 0;
}


        graph::graph( const char* filename )
        {
            locale loc;     //locale variableto use isdigit()
            int i =1;       //to keep track of the first and second lines.
            int j=0;        //to keep track of the index of the adj_list
            ifstream is;    //to read in file.
            is.open(filename);
            if(is.fail())   //if fails to open, abort.
            {
                cout << "couldn't open filem, aborting.\n";
                exit(3);
            }
            while(!is.eof()){       //until the end of file, read in the size, the letters, or the adjacency matrix values.
                if(i==1)
                    {
                    is>>size;   //first number in file reads in size of adjacency matrix.
                    adj_list.resize(get_size());      //sets list size.
                    i++;    //incriments i so it does not try to read in size again.
                    }
                else if(i==2)
                {               //if on line two, read in the letters.
                    for(int i=0; i<size;i++)
                    {
                        char c;
                        is>>c;
                        labels.push_back(c);//push letters into vector<char> labels.

                    }
                    i++;
                }
                else    //else if past those lines start reading in the values.
                {
                    char c;
                    int index;
                    is>>c;

                    if(isdigit(c,loc))  //checks if what was read in was a digit.
                    {
                        string a;       //string to store the char to use stoi().
                        a.push_back(c);
                        index = stoi(a);   //converts char numbers to integers
                        a.clear();          //clears string of characters.
                        adj_list[j].push_back(index);   //push the number (either a zero or a one) unto the list in adj_list

                        for(int counter=1;counter<size;counter++)   //reads the rest of the numbers on that line into the list as well.
                        {
                        is>>c;
                        a.push_back(c);
                        index = stoi(a);
                        a.clear();
                        adj_list[j].push_back(index);

                        }

                        j++;    // Incriments the vector to store the next line

                        if(j==size) //if end of line break loop.
                            break;
                    }

                }
            }
            is.close(); //close file since its done being used.
            for(int i=0; i<size;i++)      //initializes the list of visited vertices to zero.
                visitedIndex.push_back(0);


        }

       graph:: ~graph(){}

        int graph::get_size() const     //returns size of list.
        {
            return size;
        }

        void graph ::depth_first(int v) const   //preforms depth-first traversal on a vertice passed in.
        {
            list<int>:: iterator it;    //iterator to move through each list.
            list<int> l;                //list to be set to each list in adj_list so an iterator can be set to it.
            int row=0;                  //int to keep track of which row the iterator is on.
            l =adj_list[v];
            it =l.begin();
            while(it!= l.end()) //until the end of list.
            {
                if(*it==1)      //if the iterator points the the address of a 1, then the letter in that row is considered adjacent.
                {
                    if(visitedIndex[row]!=1)    //if it hasn't been visited mark as visited, print the letter and proceed with depth-first traversal.
                    {
                        visitedIndex[row]=1;
                        cout << labels[row] << "  ";
                        depth_first(row);
                    }
                    else    //otherwise continue moving through the list.
                    {
                        it++;
                        row++;
                    }
                }
                else    //otherwise move through the list.
                {
                    it++;
                    row++;
                }
            }
        }

        void graph::traverse( ) const   //traverses the graph with the depth-first traversal method, printing vertices along the way.
        {
            cout << "\n\nTraversing the graph by the depth-first traversal method\n--------------------------------------------------------\n\t";

            for(int i =0; i< size; i++)
            {
                if(visitedIndex[i]==0)  //if the vertex has not been visited.
                {
                    visitedIndex[i]=1;  // mark as visited and print.
                    cout << labels[i] << "  ";
                }
                depth_first(i);     //call depth first to preform depth first traversal of each vertice.
            }

        }


        void graph::print ( ) const         //moves through adj_list and prints all vertices and the vertices adjacent to them.
        {
            cout << "\n\nPrinting vertices and vertices adjecent to them\n-----------------------------------------------\n";

            std ::list<int>::iterator it;

            list<int> l;
            for(int index=0; index<size; index++)   //move through the adj_list.
            {
                int row=0;

                cout <<"\t" << labels[index] << ": ";   //print out each vertice.
                l=adj_list[index];
                it = l.begin();
                while(it!=l.end())      //print out each adjacent vertice by moving through each list and keeping track of the row.
                {

                    if(*it==1)
                        {
                            cout<< labels[row] << " ";
                        }
                    row++;
                    it++;
                }
                cout << endl;
            }

        }
