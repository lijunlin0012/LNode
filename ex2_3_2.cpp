/*函数void bubbleList(LinkList& L)为所需代码
 其他代码均供测试使用
 默认表的所有元素为整数
*/
#include <iostream>
using namespace std;
#define N 100
typedef struct DuLNode {
    int  data;
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode, * DuLinkList;//建立双向链表


void createlist(DuLinkList& L) {
    DuLNode* r = L;
    for (int i = 0; i < N; i++) {
        DuLNode* p = new DuLNode; //生成新结点 
        cin >> p->data; //输入元素值
        if (p->data == -1)  break;
        p->next = NULL;
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
void bubbleList(DuLinkList& L) {
    DuLNode* p2 = L;
    DuLNode* p = L;
    DuLNode* p3 = p2->next;

    DuLNode* p4 = p3->next;
    DuLNode* p5 = p4->next;
    int j = 0; int len = -1;
    while (p) {
        p = p->next;
        len++;
    }
    for (j = 0; j < len-1;j++) {
        p2 = L;
        for (int i = 0; i < len-j-1;i++) {
            if (p2->next->data > p2->next->next->data) {
                p3 = p2->next;
                p4 = p3->next;
                p5 = p4->next;
                p2->next = p4;
                p4->next = p3;
                p4->prior = p2;
                p3->next = p5;
                p3->prior = p4;
                if (p5) {
                    p5->prior = p3;
                }
            }
            p2 = p2->next;
        }   
    }
}
int main() {
    cout << "请输入链表的元素，以-1结尾" << endl;
    DuLNode* L = new DuLNode;
    L->next = NULL;
    createlist(L);
    showList(L);
    bubbleList(L);
    showList(L);
}