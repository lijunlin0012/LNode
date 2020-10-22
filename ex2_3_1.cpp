/*函数void deleteSameNum(LinkList& L)为所需代码
 其他代码均供测试使用
 默认表的所有元素为整数
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
void deleteNegativeNum(LinkList& L) {
    LNode* p = L->next;
    LNode* q=L;
    while (p) {
        if (p->data < 0) {
            q->next = p->next;
            p = p->next;
        }
        else {
            p = p->next;
            q = q->next;
        }
    }
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
    deleteNegativeNum(L);
    cout << "删除后" << endl;
    showList(L);
}
