
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
    while (p->next && j < i - 1) {//Ѱ�ҵ�i����㣬����pָ����ǰ��
        p = p->next; ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR; //ɾ��λ�ò�����
    q = p->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
    p->next = q->next; 	//�ı�ɾ�����ǰ������ָ����
    e = q->data; 	//����ɾ������������
    delete q; 	//�ͷ�ɾ�����Ŀռ�
    return OK;
}//ListDelete_L
*/
void createlist(LinkList& L) {
    LNode* r = L;
    for (int i = 0; i < N; i++) {
        LNode* p = new Node; //�����½�� 
        cin >> p->data; //����Ԫ��ֵ
        //cout << p->data;
        if (p->data == -1) {

            break;
        }

        p->next = NULL;	//���뵽��β
        r->next = p;
        r = p;
    }
    r->next = L->next;
}
LNode* GetElem_L(LinkList& L, int i) {
    LNode* p = L->next;
    int j = 1; //��ʼ��
    while (p && j < i) {	//���ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
        p = p->next; ++j;
    }
    if (!p || j > i)return NULL; //��i��Ԫ�ز����� 
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
    L->next = NULL; //�Ƚ���һ����ͷ���ĵ�����
    createlist(L);
    showList(L);
    LNode *p=GetElem_L(L, 3);
   deletePriorLNode(p);
   showList(L);
}