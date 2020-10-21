/* 函数void insertList(LinkList& L)为所需代码
其他代码均供测试使用
默认表的所有元素为整数

在已创建好的链表中插入一个元素：
从键盘读入元素值和插入位置
调用插入函数完成插入操作。
然后将链表元素依次输出到屏幕上。
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
        //cout << p->data;
        if (p->data == -1) {
            break;
        }
        p->next = NULL;	//插入到表尾
        r->next = p;
        r = p;
    }
}
void insertList(LinkList& L,int val,int position) {
    LNode* p;
    p= L; 
    int j = 0;
    while (p && j < position-1) { p = p->next; ++j; }	//寻找第i−1个结点 
    if (!p || j > position - 1)
        cout << "插入的位置大于表长或小于1"<<endl;//i大于表长 + 1或者小于1  
    LNode *s = new LNode;			//生成新结点s 
    s->data = val;      		           //将结点s的数据域置为val 
    s->next = p->next;	   	          //将结点s插入L中 
    p->next = s;
    cout << "succeed!" << endl;
}//在第i个元素之前插入

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
    int position,val;
    LNode* L = new LNode;
    L->next = NULL; //先建立一个带头结点的单链表
    cout << "请输入链表的元素，以-1结尾" << endl;
    createlist(L);
    showList(L);
    cout << "请输入要插入的元素值" << endl;
    cin >> val;
    cout << "请输入要插入的位置" << endl;
    cin >> position;
    insertList(L, val, position);
    showList(L);
}