/* linked list based implementation */
#include<iostream>
using namespace std;
/* graph  class to creat graph */
class graph{
    int v;          // no of vertics to initializ the vertex list
    int vertices;   //  to add vertex on list as a index
    /* node to cerat a node */
    struct node
    {
    int data;
    node* link;
    };
    node* adj[];    // adj list (vertex list)
public:
    graph(int v){
        vertices=0;      // to nitializ vertices , the v and the array 
        this->v=v;
        adj[v];
        for (int i = 0; i < v; i++)
        {
            adj[i]=nullptr;          // each element == null
        }
        
    }
    void add_vertex(int data){    // add the vertex
              
            node*temp=new node();
            temp->data=data;
            temp->link=nullptr;
            adj[vertices];
        vertices++;
    }
    void add_edge(int u,int v){     // to add and edge
        node*ptr=new node;
        ptr->data=v;
        ptr->link=adj[u];
        adj[u]=ptr;

    }
    void print_graph(){              // to print the graph
        for (int i = 0; i <v; i++)
        {     cout<<i<<" :";

            node*curr=adj[i];
            while (curr!=nullptr)
            {
                cout<<curr->data;
                curr=curr->link;
            }
            cout<<endl;
        }
        
    }
     
    bool is_edge(int u,int v){      // to check that there is an edge or not
        node*ptr=adj[u];
        while (ptr!=nullptr)
        {   
            if(ptr->data==v)return true;
           ptr=ptr->link;
        }
        return false;
    }
};
int main(){
    
    graph g1(4);
   g1.add_vertex(0);
   g1.add_vertex(1);
   g1.add_vertex(2);
   g1.add_vertex(3);
   
   g1.add_edge(0,1);
   g1.add_edge(0,2);         /* we would have used the doubly linked-list to reduce the size to make undirected graph  */
   g1.add_edge(1,0);
   g1.add_edge(1,2);
   g1.add_edge(2,0);
   g1.add_edge(2,1);
   g1.add_edge(2,3);
   g1.add_edge(3,2);

g1.print_graph();
cout<<g1.is_edge(3,2);
    return 0;
}
