/*����void exchangeDu(DuLNode* p)Ϊ�������
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

DuLNode *Get_p(DuLinkList &L, int i) {
    DuLNode *p = L->next; 
    int j = 1; 
    while (p && j < i) {	//���ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
        p = p->next; ++j;
    }
    if (!p || j > i)return NULL; //��i��Ԫ�ز����� 
    return p;
}

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
void exchangeDu(DuLNode* p){
    p->next->prior = p->prior;
    p->prior->next = p->next;
    p->prior = p->next;
    p->next = p->next->next;
    p->prior->next->prior = p;
    p->prior->next = p;
}//�ı�6��ָ���ָ�򼴿�
int main() {
    cout << "�����������Ԫ�أ���-1��β" << endl;
    DuLNode* L = new DuLNode;
    L->next = NULL;

    createlist(L);
    showList(L);
    cout << "������pָ��ڼ����ڵ㣿" << endl;
    int x;
    cin >> x;
    DuLNode* p = Get_p(L, x);
    exchangeDu(p);
    showList(L);
}