/*����void bubbleList(LinkList& L)Ϊ�������
 ���������������ʹ��
 Ĭ�ϱ������Ԫ��Ϊ����
*/
#include <iostream>
using namespace std;
#define N 100
typedef struct DuLNode {
    int  data;
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode, * DuLinkList;//����˫������


void createlist(DuLinkList& L) {
    DuLNode* r = L;
    for (int i = 0; i < N; i++) {
        DuLNode* p = new DuLNode; //�����½�� 
        cin >> p->data; //����Ԫ��ֵ
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
    cout << "�����������Ԫ�أ���-1��β" << endl;
    DuLNode* L = new DuLNode;
    L->next = NULL;
    createlist(L);
    showList(L);
    bubbleList(L);
    showList(L);
}