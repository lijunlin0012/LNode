/*函数void mergeNode(LNode *p,LinkList &L1)为所需代码
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
        
        if (p->data == -1) break;
      
        p->next = NULL;	//插入到表尾
        r->next = p;
        r = p;
    }
}//生成链表
LNode* GetElem_L(LinkList& L, int x) {
    LNode* p = L->next;
 
    while (p && p->data!=x) {	//向后扫描，直到p指向x元素所在结点
        p = p->next; 
    }
    if(p&&p->data==x)return p;
    else { 
        cout << "没找到元素x" << endl; 
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
        cout << "合并成功" << endl;
    }
    else {
        cout << "合并失败" << endl;
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
    cout << "输入表A的元素，以-1结尾" << endl;
    LNode* L = new LNode;
    L->next = NULL; 
    createlist(L);
    cout << "now the list A is" << endl;
    showList(L);
    cout << "输入表B的元素，以-1结尾" << endl;
    LNode* L1 = new LNode;
    L1->next = NULL;
    createlist(L1);
    cout << "now the list B is" << endl;
    showList(L1);
    int x;
    cout << "请输入x元素的值" << endl;
    cin >> x;
    LNode* p = GetElem_L(L, x);
    mergeNode(p, L1);
    cout << "此时的表A为" << endl;
    showList(L);
}