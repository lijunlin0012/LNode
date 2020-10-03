/*函数void deletePriorLNode(LinkList& p)为所需代码
 其他代码均供测试使用
*/
#include <iostream>
using namespace std;
#define N 100
typedef struct LNode {
    int data;
    struct LNode* next;
}Node, * LinkList;

void createlist(LinkList& L) {
    LNode* r = L;
    for (int i = 0; i < N; i++) {
        LNode* p = new Node; //生成新结点 
        cin >> p->data; //输入元素值
        if (p->data == -1) {

            break;
        }

        p->next = NULL;	//插入到表尾
        r->next = p;
        r = p;
    }
    r->next = L->next;
}//生成循环链表 r->next = L->next;
LNode* GetElem_L(LinkList& L, int i) {
    LNode* p = L->next;
    int j = 1; //初始化
    while (p && j < i) {	//向后扫描，直到p指向第i个元素或p为空
        p = p->next; ++j;
    }
    if (!p || j > i)return NULL; //第i个元素不存在 
    return p;
}

void deletePriorLNode(LNode *p) {
    LNode* p1 = p->next;
    LNode* q=p;//q始终指向p1的前一个节点
    while (p1 ->next!= p) {
        q = p1;
        p1 = p1->next;
    }//当p1->next发现链表全部循环了一遍后，p1指向前驱节点，q指向前驱节点的前一个节点
    q->next = p;
    delete p1;//释放前驱节点的内存
}
void showList(LinkList& L) {
    cout << "now the list is" << endl;
    LNode* p1 = L->next;
    cout << p1->data << endl;
    while (p1->next) {
        if (p1 -> next == L->next) {
            break;
        }
        p1 = p1->next;
        cout << p1->data << endl;
    }
}

int main() {
    LNode* L = new LNode;
    L->next = NULL; //先建立一个带头结点的单链表
    createlist(L);
    showList(L);
    int testNum;
    cout << "你想删除第几个元素的前驱节点？" << endl;
    cin >> testNum;
    LNode *p=GetElem_L(L, testNum);
   deletePriorLNode(p);
   showList(L);
}