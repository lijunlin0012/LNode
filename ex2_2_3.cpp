/*int insertOrderNum(LinkList& L,int val)为所需代码
 其他代码均供测试使用
 默认表的所有元素为整数

 用链表实现下面的算法:
 设线性表存放在向量A[1……MAXNUM]的前elenum个分量中，
 且递增有序，
 要求将x插入到线性表的适当位置上，
 以保持线性表的有序性。
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
}
int insertOrderNum(LinkList& L,int val) {
    LNode *s = new LNode;//构建新节点
    s->data = val;
    s->next = NULL;
    LNode* p = L;
    
    while (p->next) {
        if (val < p->next->data) {
            s->next = p->next;
            p->next = s;
            cout << "Insert secceed!" << endl;
            return 0;
        }
        p = p->next;
    }
    s->next = p->next;
    p->next = s;
    cout << "secceed!" << endl;
    return 0;
}
void showList(LinkList& L) {
    cout << "now the list is" << endl;
    LNode* p1 = L->next;
    cout << p1->data << " ";
    while (p1->next) {
        p1 = p1->next;
        cout << p1->data << " ";
    }cout << endl;
}

int main() {
    LNode* L = new LNode;
    L->next = NULL; //先建立一个带头结点的单链表
    cout << "请输入链表的元素，以-1结尾" << endl;
    createlist(L);
    showList(L);
    cout << "请输入一个整数" << endl;
    int val;
    cin >> val;
    insertOrderNum(L, val);
    showList(L);
}