/*int insertOrderNum(LinkList& L,int val)Ϊ�������
 ���������������ʹ��
 Ĭ�ϱ������Ԫ��Ϊ����

 ������ʵ��������㷨:
 �����Ա���������A[1����MAXNUM]��ǰelenum�������У�
 �ҵ�������
 Ҫ��x���뵽���Ա���ʵ�λ���ϣ�
 �Ա������Ա�������ԡ�
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
int insertOrderNum(LinkList& L,int val) {
    LNode *s = new LNode;//�����½ڵ�
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
    L->next = NULL; //�Ƚ���һ����ͷ���ĵ�����
    cout << "�����������Ԫ�أ���-1��β" << endl;
    createlist(L);
    showList(L);
    cout << "������һ������" << endl;
    int val;
    cin >> val;
    insertOrderNum(L, val);
    showList(L);
}