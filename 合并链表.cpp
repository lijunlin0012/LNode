/*����void mergeNode(LinkList &L,LinkList &L1)Ϊ�������
 ���������������ʹ��
 Ĭ�ϱ������Ԫ��Ϊ����
 ����д���е�sb�����ģ�Ӧ����L3����һ����ָ��ģ�û���ĸ�sb��ֱ����L������
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

        if (p->data == -1) break;

        p->next = NULL;	//���뵽��β
        r->next = p;
        r = p;
    }
}//��������

void showList(LinkList& L) {

    LNode* p1 = L->next;
    cout << p1->data << " ";
    while (p1->next) {
        p1 = p1->next;
        cout << p1->data << " ";
    }
    cout << endl;
}

void mergeNode(LinkList L, LinkList L1) {
    LNode* p0 = L->next->next;
    LNode* p1 = L1->next;
    LNode* temp;
    LNode* tail_0= L->next;
    while (p0||p1) {
        if (p0 != NULL&&p1!=NULL) {
            if (p0->data >= p1->data) {
                temp= L->next;
                L->next = p1;
                p1 = p1->next;
                L->next->next = temp; 
            cout << "��ʱ�ı�AΪ" << endl;
            showList(L);
           continue;
            }
           
        }
        else if(p0 == NULL) {
            temp = L->next;
            L->next = p1;
            p1 = p1->next;
            L->next->next = temp;
            cout << "��ʱ�ı�AΪ" << endl;
            showList(L);
            continue;
        }
        
        if (p1 != NULL&&p0!=NULL) {
            if (p0->data < p1->data) {
                tail_0->next = p0->next;
                p0->next=L->next;
                L->next = p0;
                p0 = tail_0->next;
                cout << "��ʱ�ı�AΪ" << endl;
                showList(L);
                continue;
            }
        }
        else if (p1 == NULL) {
            tail_0->next = p0->next;
            p0->next = L->next;
            L->next = p0;
            p0 = tail_0->next;
            cout << "��ʱ�ı�AΪ" << endl;
            showList(L);
            continue;
        }
    
    }
}


int main() {
    cout << "�����L��Ԫ�أ���-1��β" << endl;
    LNode* L = new LNode;
    L->next = NULL;
    createlist(L);
    cout << "now the list L is" << endl;
    showList(L);
    cout << "�����L1��Ԫ�أ���-1��β" << endl;
    LNode* L1 = new LNode;
    L1->next = NULL;
    createlist(L1);
    cout << "now the list L1 is" << endl;
    showList(L1);
   
    mergeNode(L, L1);

    cout << "��ʱ�ı�AΪ" << endl;
    showList(L);
}