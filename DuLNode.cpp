#include <iostream>
using namespace std;
#define N 100
typedef struct DuLNode {
    int  data;
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode, * DuLinkList;
DuLNode * GetElem_L(DuLinkList &L, int i) {
    DuLNode *p = L->next; 
    int j = 1; //初始化
    while (p && j < i) {	//向后扫描，直到p指向第i个元素或p为空
        p = p->next; ++j;
    }
    if (!p || j > i)return NULL; //第i个元素不存在 
    return p;
}


void createlist(DuLinkList& L) {
    DuLNode* r = L;
    for (int i = 0; i < N; i++) {
        DuLNode* p = new DuLNode; //生成新结点 
        cin >> p->data; //输入元素值
        //cout << p->data;
        if (p->data == -1) {
            break;
        }

        p->next = NULL;	//插入到表尾
        r->next = p;
        p->prior = r;
        r = p;
    }
}
void showList(DuLinkList& L) {
    cout << "now the list is" << endl;
    DuLNode* p1 = L->next;
    cout << p1->data << endl;
    while (p1->next) {
        p1 = p1->next;
        cout << p1->data << endl;
    }

}
void exchangeDu(DuLNode* p){
    p->next->prior = p->prior;
    p->prior->next = p->next;
    p->prior = p->next;
    p->next = p->next->next;
    p->prior->next->prior = p;
    p->prior->next = p;
}
int main() {

    DuLNode* L = new DuLNode;
    L->next = NULL;
    createlist(L);
    showList(L);
    DuLNode* p = GetElem_L(L, 3);
    exchangeDu(p);

    showList(L);
}