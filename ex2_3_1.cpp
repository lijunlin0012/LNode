/*����void deleteSameNum(LinkList& L)Ϊ�������
 ���������������ʹ��
 Ĭ�ϱ������Ԫ��Ϊ����
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
        LNode* p = new Node; //�����½�� 
        cin >> p->data; //����Ԫ��ֵ
        
        if (p->data == -1) {
            break;
        }
        p->next = NULL;	//���뵽��β
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
    L->next = NULL; //�Ƚ���һ����ͷ���ĵ�����
    cout << "�����������Ԫ�أ���-1��β" << endl;
    createlist(L);
    showList(L);
    deleteNegativeNum(L);
    cout << "ɾ����" << endl;
    showList(L);
}
