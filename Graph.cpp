#include <iostream>
#include <queue>
using namespace std;

const int MaxSize = 5;
struct ArcNode //边表节点
{
    int adjvex;
    ArcNode *next;
};

template <class T>
struct VertexNode //定义顶点表节点
{
    T vertex;
    ArcNode *firstedge;
};

template <class T>
class AdjGraph
{
  public:
    AdjGraph(T a[], int n, int e); //构造函数，建立具有n个顶点e条边的图
    void dfsTraverse(int v);       //深度优先遍历图
    void bfsTraverse(int v);       //广度优先遍历图
    void Insert(int a, int b);     //插入边表
    void Show();                   //显示邻接表
  private:
    VertexNode<int> adjlist[MaxSize]; //存放顶点表的数组
    int vertexNum, arcNum;            //图的顶点数和边数
    int visited[MaxSize];             //有没访问数组
    queue<int> que;
};

template <class T>
AdjGraph<T>::AdjGraph(T a[], int n, int e)
{
    vertexNum = n;
    arcNum = e;
    for (int i = 0; i < vertexNum; i++) //初始化头节点表
    {
        visited[i] = 0;
        adjlist[i].vertex = a[i];
        adjlist[i].firstedge = NULL;
    }
}

template <class T>
void AdjGraph<T>::Insert(int vertex, int arcNode)
{
    ArcNode *pArc = new ArcNode();
    pArc->adjvex = arcNode;
    if (adjlist[vertex].firstedge == NULL)
        adjlist[vertex].firstedge = pArc;
    else
    {
        ArcNode *p = adjlist[vertex].firstedge;
        while (p->next != NULL)
            p = p->next;
        p->next = pArc;
    }
}

template <class T>
void AdjGraph<T>::Show()
{
    cout << "邻接表为：" << endl;
    for (int i = 0; i < vertexNum; i++)
    {
        cout << adjlist[i].vertex;
        ArcNode *p = adjlist[i].firstedge;
        while (p != NULL)
        {
            cout << "->" << p->adjvex;
            p = p->next;
        }
        cout << "->NULL" << endl;
    }
}

template <class T>
void AdjGraph<T>::dfsTraverse(int v) //深度优先
{
    cout << adjlist[v].vertex << " ";
    visited[v] = 1;
    ArcNode *p = adjlist[v].firstedge; //指向顶点v的边表
    while (p != NULL)
    {
        int j = p->adjvex;
        if (visited[j] == 0)
            dfsTraverse(j);
        p = p->next;
    }
}

template <class T>
void AdjGraph<T>::bfsTraverse(int v) //广度优先
{
    for (int i = 0; i < vertexNum; i++) //被访问节点初始化
    {
        visited[i] = 0;
    }
    cout << adjlist[v].vertex << " ";
    visited[v] = 1;
    que.push(v);             //先把第一个元素放入队列
    while (que.empty() != 1) //队列非空时
    {
        v = que.front(); //获取队头元素并弹出
        que.pop();
        ArcNode *p = adjlist[v].firstedge; //指向顶点v的边表
        while (p != NULL)
        {
            int j = p->adjvex;
            if (visited[j] == 0) //若没被访问
            {
                cout << adjlist[j].vertex << " ";
                visited[j] = 1;
                que.push(j);
            }
            p = p->next;
        }
    }
}

void main()
{
    int a[5] = {0, 1, 2, 3, 4};
    AdjGraph<int> myGraph(a, 5, 6);
    myGraph.Insert(0, 1);
    myGraph.Insert(0, 3);
    myGraph.Insert(1, 0);
    myGraph.Insert(1, 2);
    myGraph.Insert(1, 4);
    myGraph.Insert(2, 1);
    myGraph.Insert(2, 3);
    myGraph.Insert(2, 4);
    myGraph.Insert(3, 0);
    myGraph.Insert(3, 2);
    myGraph.Insert(4, 2);
    myGraph.Insert(4, 1);
    myGraph.Show();

    cout << endl
         << "深度优先遍历:" << endl;
    myGraph.dfsTraverse(0);
    cout << endl;

    cout << endl
         << "广度优先遍历:" << endl;
    myGraph.bfsTraverse(0);
    cout << endl;
}