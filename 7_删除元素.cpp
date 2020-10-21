/* 函数void insertList(LinkList& L,int val,int position)为所需代码
其他代码均供测试使用
默认表的所有元素为整数
插入到第position个元素之前

已创建好的链表中删除一个元素：
从键盘读入欲删除的元素位置（序号），
调用删除函数完成删除操作。
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
int deletePoint(LinkList& L, int position) {
    LNode* p=L;
    int j = 0;
    while (p && j < position - 1) { p = p->next; ++j; }	//寻找第i−1个结点 
    if (!p || j > position - 1) {
        cout << "删除的位置大于表长或小于1，删除失败" << endl;//i大于表长 + 1或者小于1  
        return -1;
    }
    p->next =p->next->next;
    cout << "succeed!" << endl;
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
    int position, val;
    LNode* L = new LNode;
    L->next = NULL; //先建立一个带头结点的单链表
    cout << "请输入链表的元素，以-1结尾" << endl;
    createlist(L);
    showList(L);
    cout << "请输入要删除元素的位置" << endl;
    cin >> position;
    deletePoint(L, position);
    showList(L);
}