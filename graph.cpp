#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

//Graph 
    // -> creating and printing UNWEIGHTED graph
    // -> creating and printing WEIGHTED graph
    // -> BFS traversal
    // -> DFS traversal

class Graph{
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction){
        // direction -> 0 = undirected
        // direction -> 1 = directed
        if(direction == 1){
            // u -> v
            adjList[u].push_back(v);
        }
        else{
            // u-> v
            // v-> v
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        cout<<endl<<"Printing Adjacent List: "<<endl;
        printAdjList();
        cout<<endl;

    }

    void printAdjList() {
        for(auto i: adjList){
            cout<< i.first<<"-> {";
            for(auto neighbour : i.second){
                cout<<neighbour<<", ";
            }
            cout<<"}"<<endl;
        }
    }
};

template<typename T>
class Graph1{
    public:
    unordered_map<T, list<pair<T,int>>> adjList;

    void addEdge(T u, T v,int wt, bool direction){
        // direction -> 0 = undirected
        // direction -> 1 = directed
        if(direction == 1){
            // u -> v
            adjList[u].push_back(make_pair(v,wt));
        }
        else{
            // u-> v
            // v-> v
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        cout<<endl<<"Printing Adjacent List: "<<endl;
        printAdjList();
        cout<<endl;

    }

    void printAdjList() {
        for(auto i: adjList){
            cout<< i.first<<"-> {";
            for(pair<int,int> p : i.second){
                cout<<"{ "<<p.first<<" ,"<<p.second<<" }";
            }
            cout<<" }";
            cout<<endl;
        }
    }

    void bfsTraversal(T src, unordered_map<T, bool> &vis){
        //adj List already data memeber m hai
        //visited
        // unordered_map<T, bool> vis;
        //queue
        queue<T> q;
        
        //initial state
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            T frontNode = q.front();
            cout<<frontNode<<" ";
            q.pop();

            //go to nbr
            for(auto nbr: adjList){
                T nbrData = nbr.first;

                if(!vis[nbrData]){
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T ,bool> & vis){
        vis[src]= true;
        cout<< src << " ";

        for(auto nbr : adjList[src]){
            T nbrData = nbr.first;
            if(!vis[nbrData]){
                dfs(nbrData, vis);
            }
        }
    }
};

int main() {

    // Graph g;
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,1);
    // g.addEdge(2,3,1);

    //  Graph1<int> g;
    // g.addEdge(0,1,5,1);
    // g.addEdge(1,2,6,1);
    // g.addEdge(1,3,3,1);
    // g.addEdge(2,3,8,1);

    //  Graph1<char> g;
    // g.addEdge('a','b',5,0);
    // g.addEdge('b','c',10,0);
    // g.addEdge('d','e',20,0);
    // g.addEdge('f','f',50,0);
   


    // // g.bfsTraversal('a');
    // unordered_map<char, bool> vis;
    // for(char node = 'a'; node <='f'; node++){
    //     if(!vis[node]){
    //         g.bfsTraversal(node, vis);
    //     }
    // }

     Graph1<char> g;
    g.addEdge('a','b',5,0);
    g.addEdge('a','c',10,0);
    g.addEdge('c','d',20,0);
    g.addEdge('c','e',50,0);
    g.addEdge('e', 'f', 70,0);

    unordered_map<char, bool>vis;

    g.dfs('a', vis);

    return 0;
}