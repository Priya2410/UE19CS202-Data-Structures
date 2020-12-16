<h4>Graph :An ordered pair of vertices and edges.<br>
Directed Graph : When the pair of vertices representing an edge are ordered (u,v) not equal to (v,u)<br>
Undirected Graph: When the pair of vertices representing an edge are unordered (u,v) = (v,u)<br>
Weighted Graph : A graph in the edges have a numerical value associated with them.<br>
Incident: A vertex is said to be incident on an edge if it connects it to another node.<br>
Indegree : The number of edges incident from a vertex.<br>
Outdegree: The number of edges incident to a vertex.<br>
Adjacent Nodes : Two nodes are adjacent if an edge connects the two of them.<br>
Path:Sequence of vertices.<br>
Cyclic Graph : A path in which the starting and ending vertices are the same.<br>
Acyclic Graph : A graph with no cycles<br>
Directed Acycling Graph: DAG <br>
Connected Graph : If all nodes can be visited from a node its called connected (in directed and strongly connected in undirected)<br>
Disconnected Graph : If all the nodes can't be visited.<br>
Weakly connected : If all nodes can be visited only from a single node<br>
--------------------------------------------------------------------------------------------------------<br>
Properties:<br>
A directed graph has max of m(m-1) edges/<br>
An undirected graph has max of (m*(m-1))/2 edges<br>
--------------------------------------------------------------------------------------------------------<br>
Disadvantage of adjacency matrix : the number of vertices must be known <br>
Space Complexity : O(n^2)<br>
--------------------------------------------------------------------------------------------------------<br>
In case of weighted graph :<br>
struct Node<br>
{<br>
  int data;<br>
  int weight;<br>
  struct Node *link;<br>
}<br>
--------------------------------------------------------------------------------------------------------<br>
BFS - Level Order Traversal<br>
DFS - Pre Order Traversal<br>
--------------------------------------------------------------------------------------------------------<br>
Computer Topology :<br>
Used in networks <br>
1) Ring Topology : All the nodes have a degree=2<br>
2) Star Topology : Number of links= Number of nodes -1,Central vertex is connected to every other node<br>
3) Mesh Topology : Every node is connected to every node. ( strongly connected ) Degree of every node = Number of nodes-1<br>
4) Bus Topology: Every node except the first and the last node have a degree=2<br>
</h4>
