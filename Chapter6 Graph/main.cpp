#include <iostream>
using namespace std;
#define MaxVertexNum 100
typedef struct {
    char Var[MaxVertexNum];//顶点表
    int Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表
    int verNum;//当前顶点数目
    int archNum;//当前弧的数目
}MGraph;
/*邻接矩阵法
 * 空间复杂度O(|V|^2)只和顶点数有关与实际边数无关
 * 适合用于存储稠密图，不适于稀疏图
 * 可以用压缩矩阵
 * 表示方式唯一
 * 要找相邻的边必须遍历对应行或列
 */
#define VertexType int
typedef struct ArchNode{
    int adjoinVex;//指向哪个节点
    struct ArchNode *next;//指向下一条弧的指针
};
typedef struct VNode{
    VertexType data;
    ArchNode *first;
}VNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;
    int vexNum;
    int archNum;
}ALGraph;
/*邻接表法
 * 空间复杂度（有向图） O(|V|+|E|) 无向图O(|v|+2|E|)
 * 表示方式不唯一
 * 存储稀疏图
 * 找有向图的入边很不方便要遍历整个表
 */


/*十字链表法
 * 只能用于存储有向图
 * 空间复杂度O(|V|+|E|)
 */


/*临界多重表
 *用于存储无向图
 *顶点结点：data + firstEdge（与该顶点相连的第一条边）
 *边结点： i + j + info + iLink（依附于顶点i的下一条边） + jLink(依附于顶点j的下一条边)
 *空间复杂度O（|V|+|E|）
 *删除边、删除节点等操作很方便
 */
int main() {
    return 0;
}
