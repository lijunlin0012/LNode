
#include <iostream>
using namespace std;
#define N 100
typedef struct LNode {
    int data;
    struct LNode* next;
}Node, * LinkList;


/*
Status ListDelete_L(LinkList& L, int i, ElemType& e) {
    p = L; j = 0;
    while (p->next && j < i - 1) {//寻找第i个结点，并令p指向其前驱
        p = p->next; ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR; //删除位置不合理
    q = p->next; //临时保存被删结点的地址以备释放
    p->next = q->next; 	//改变删除结点前驱结点的指针域
    e = q->data; 	//保存删除结点的数据域
    delete q; 	//释放删除结点的空间
    return OK;
}//ListDelete_L
*/
void createlist(LinkList& L) {
    LNode* r = L;
    for (int i = 0; i < N; i++) {
        LNode* p = new Node; //生成新结点 
        cin >> p->data; //输入元素值
        //cout << p->data;
        if (p->data == -1) {

            break;
        }

        p->next = NULL;	//插入到表尾
        r->next = p;
        r = p;
    }
    r->next = L->next;
}
LNode* GetElem_L(LinkList& L, int i) {
    LNode* p = L->next;
    int j = 1; //初始化
    while (p && j < i) {	//向后扫描，直到p指向第i个元素或p为空
        p = p->next; ++j;
    }
    if (!p || j > i)return NULL; //第i个元素不存在 
    return p;
}

void deletePriorLNode(LinkList& p) {
    LNode* p1 = p->next;
    LNode* q=p;
    while (p1 ->next!= p) {
        q = p1;
        p1 = p1->next;
    }
    q->next = p;
    delete p1;
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
    LNode *p=GetElem_L(L, 3);
   deletePriorLNode(p);
   showList(L);
}