/* 
 * File:   main.cpp
 * Author: MdFarhadur
 *
 * Created on April 14, 2017, 9:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>


using namespace std;

/*
 * 
 */

template <typename T>
class Graph{
private:
    int vertices;
    vector<T> *adj;
    vector<T> vertex;
    
public:
    Graph(int v)
    {
        vertices=v;
       // adj= new list<T>[v];
        adj= new vector<T>[v];
        
    }
    
    void addVertex(T v)
    {
        if(find(vertex.begin(),vertex.end(),v)==vertex.end())
        {
            vertex.push_back(v);
        }
        else
        {
            cout<<"Vertex already exist in the graph\n";
            return;
        }
    }
    
    void addEdge(T v, T w)
    {
      //list<T>::iterator lit;
        
        addVertex(v);
        addVertex(w);
        
        if(adj->size()>1)
        {
            //check whether edge already exist in the graph
        if(find(adj[v].begin(),adj[v].end(),w)==adj[v].end())
        {
        // vertex.push_back(v);
         cout<<"Edge Inserted\n";
         adj[v].push_back(w);
        }
        else
            cout<<"\nEdge already exist in the graph\n";
        }
        else
        {
         //  vertex.push_back(v);
            cout<<"Edge Inserted\n";
           adj[v].push_back(w);
        }
    }
    
    void DFS_iterative(T s)
    {
        stack<T> sg;
        //list<int>::iterator lit;
       // list<int>::const_iterator lit;
        bool *discovered=new bool[vertices];
        for(int i=0;i<vertices;i++)
        {
            discovered[i]=false;
        }
        
        sg.push(s);
        
        cout<<"Visited Node:\n";
        
        while(!sg.empty())
        {
            s=sg.top();
            sg.pop();
            
            if(!discovered[s])
            {
                discovered[s]=true;
                cout<<s<<" ";
                
               // for(list<int>::iterator lit=adj[s].begin();lit!=adj[s].end();++lit)
                for(T lit :adj[s])
                {
                  //  sg.push(*lit);
                     sg.push(lit);
                }
            }
            
            
        }
    }
    
   void DFS_recursive(T s)
   {
       cout<<"Visited Node:\n";
       bool *discovered=new bool[vertices];
        for(int i=0;i<vertices;i++)
        {
            discovered[i]=false;
        }
       
       DFS_recursive_util(s,discovered);
   }  
   
    void DFS_recursive_util(T s, bool discovered[])
    {
        discovered[s]=true;
        cout<<s<<" ";
       // list<int>::iterator lit;
       // list<int>::const_iterator lit;
        
       // for(list<int>::iterator lit=adj[s].begin();lit!=adj[s].end();++lit)
        for(T lit :adj[s])
           {
              /* if(!discovered[*lit])
              {
                    DFS_recursive_util(*lit, discovered);
               }*/
            if(!discovered[lit])
              {
                    DFS_recursive_util(lit, discovered);
               }
           }
        
        
    }
    
    
    void BFS_iterative(T s)
    {
        queue<T> sg;
        
        bool *discovered=new bool[vertices];
        for(int i=0;i<vertices;i++)
        {
            discovered[i]=false;
        }
        
        sg.push(s);
        
        cout<<"Visited Node:\n";
        
        while(!sg.empty())
        {
            s=sg.front();
            sg.pop();
            
            if(!discovered[s])
            {
                discovered[s]=true;
                cout<<s<<" ";
                
              //  for(list<int>::iterator lit=adj[s].begin();lit!=adj[s].end();++lit)
                for(T lit :adj[s])
                {
                 //   cout<<*lit<<" ";
                  //  sg.push(*lit);
                     cout<<lit<<" ";
                    sg.push(lit);
                }
                cout<<"\n";
            }
            
            
        }
    }
    
    void printEdges()
    {        
        for(int i=0;i<vertices;i++)
        {
            cout<<"Edges adjacent to vertex:\t"<<i<<"\t are:\t";
           // for(list<int>::iterator lit=adj[i].begin();lit!=adj[i].end();++lit)
           for(T lit :adj[i])
           {
                   // cout<<*lit<<" ";
                    cout<<lit<<" ";
           }
          cout<<"\n";
        }
        
    }
    
    //no of vertices in the graph
     int getSize()
    {
        return vertex.size();
    }
    
    
    vector<T> getVertices()
    {
        return vertex;
    }
    
    int getEdgeSize()
    {
        int edge_count=0;
        for(int i=0;i<vertex.size();i++)
        {
            edge_count+=adj[vertex[i]].size();
            
        }
        
        return edge_count;
        
    }
    int getNeighborSize(T v)
    {
        return adj[v].size();
    }
    
    T getVertex(int index)
    {
        return vertex[index];
    }
    
     int getIndex(T v)
     {
         for(int i=0;i<vertex.size();i++)
         {
             if(vertex[i]==v)
             {
                 return i;
             }
         }
         return -1;
     }
     
     void clear()
     {      
           adj->clear();
           vertex.clear();
     }
    
};

int main() {

    Graph<char> g(7);
   
    /*g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);*/
    
 /*   g.addEdge(0, 1);
    g.addEdge(0, 2);
   // g.addEdge(2, 0);
    g.addEdge(0, 4);
    
     g.addEdge(1, 3);
    g.addEdge(1, 5);
    
    g.addEdge(5, 1);
    g.addEdge(5, 4);
    g.addEdge(4, 5);
    
    g.addEdge(2, 6);*/
    
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'E');
    
     g.addEdge('B', 'D');
    g.addEdge('B', 'F');
    
    g.addEdge('F', 'B');
    g.addEdge('F', 'E');
    g.addEdge('E', 'F');
    
     g.addEdge('C', 'G');
    
    cout << "Iterative Depth First Traversal:\n";
   // g.DFS_iterative(0);
     g.DFS_iterative('A');
    cout<<"\n";
    
    cout << "Recursive Depth First Traversal\n";
   // g.DFS_recursive(0);
    g.DFS_recursive('A');
    
    cout<<"\n";
    cout << "Iterative Breadth First Traversal:\n";
  //  g.BFS_iterative(0);
    g.BFS_iterative('A');
    
    cout << "Print the Edges of the Graph:\n";
    g.printEdges();
    
   
    cout << "Print vertices of the Graph:\n";
    
    vector<char> vertex_2=g.getVertices();
    
    for(int i=0;i<vertex_2.size();i++)
    {
        cout<<"Vertex:\t"<<vertex_2[i]<<" "<<"Vertex Index:\t"<<g.getIndex(vertex_2[i])<<" ";
        cout<<"Neighbor Size:\t"<<g.getNeighborSize(vertex_2[i])<<"\n";
    }
    
    cout<<"Total no. of Edges:\t"<<g.getEdgeSize()<<"\n";
    
    g.clear();
    return 0;
}

