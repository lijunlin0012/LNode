/*����void mergeNode(LNode *p,LinkList &L1)Ϊ�������
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
        
        if (p->data == -1) break;
      
        p->next = NULL;	//���뵽��β
        r->next = p;
        r = p;
    }
}//��������
LNode* GetElem_L(LinkList& L, int x) {
    LNode* p = L->next;
 
    while (p && p->data!=x) {	//���ɨ�裬ֱ��pָ��xԪ�����ڽ��
        p = p->next; 
    }
    if(p&&p->data==x)return p;
    else { 
        cout << "û�ҵ�Ԫ��x" << endl; 
        return NULL; 
    }
}

void mergeNode(LNode *p,LinkList &L1) {
    if(p!=NULL){
        LNode* q = p->next;
        p->next = L1->next;
        while (p->next) {	
             p = p->next;
        }
        p->next = q;
        cout << "�ϲ��ɹ�" << endl;
    }
    else {
        cout << "�ϲ�ʧ��" << endl;
    }
}
void showList(LinkList& L) {
   
    LNode* p1 = L->next;
    cout << p1->data <<" ";
    while (p1->next) {
        p1 = p1->next;
        cout << p1->data << " ";
    }
    cout << endl;
}

int main() {
    cout << "�����A��Ԫ�أ���-1��β" << endl;
    LNode* L = new LNode;
    L->next = NULL; 
    createlist(L);
    cout << "now the list A is" << endl;
    showList(L);
    cout << "�����B��Ԫ�أ���-1��β" << endl;
    LNode* L1 = new LNode;
    L1->next = NULL;
    createlist(L1);
    cout << "now the list B is" << endl;
    showList(L1);
    int x;
    cout << "������xԪ�ص�ֵ" << endl;
    cin >> x;
    LNode* p = GetElem_L(L, x);
    mergeNode(p, L1);
    cout << "��ʱ�ı�AΪ" << endl;
    showList(L);
}