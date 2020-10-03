/*����void deletePriorLNode(LinkList& p)Ϊ�������
 ���������������ʹ��
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
    r->next = L->next;
}//����ѭ������ r->next = L->next;
LNode* GetElem_L(LinkList& L, int i) {
    LNode* p = L->next;
    int j = 1; //��ʼ��
    while (p && j < i) {	//���ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
        p = p->next; ++j;
    }
    if (!p || j > i)return NULL; //��i��Ԫ�ز����� 
    return p;
}

void deletePriorLNode(LNode *p) {
    LNode* p1 = p->next;
    LNode* q=p;//qʼ��ָ��p1��ǰһ���ڵ�
    while (p1 ->next!= p) {
        q = p1;
        p1 = p1->next;
    }//��p1->next��������ȫ��ѭ����һ���p1ָ��ǰ���ڵ㣬qָ��ǰ���ڵ��ǰһ���ڵ�
    q->next = p;
    delete p1;//�ͷ�ǰ���ڵ���ڴ�
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
    int testNum;
    cout << "����ɾ���ڼ���Ԫ�ص�ǰ���ڵ㣿" << endl;
    cin >> testNum;
    LNode *p=GetElem_L(L, testNum);
   deletePriorLNode(p);
   showList(L);
}