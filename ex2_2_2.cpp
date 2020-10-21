/* 函数void deleteOrInsret(LinkList& L, int val);为所需代码
其他代码均供测试使用
默认表的所有元素为整数

从键盘任意输入一个整数，在单链表中查询该数，
如果单链表中已经存在这个数，
就调用删除函数，删除该元素所在结点，
并将单链表在删除前后的数据元素依次输出到屏幕上；
   
如果单链表中不存在这个数，
就调用插入函数，将这个数插入到单链表尾，
并将单链表在插入前后的数据元素依次输出到屏幕上。
*/
#include <iostream>
using namespace std;
#define N 100

typedef struct LNode {
    int data;
    struct LNode* next;
}Node, * LinkList;

void deleteOrInsret(LinkList& L, int val);
int insertList(LinkList& L, int val);
int deletePoint(LinkList& L, int position);
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
void deleteOrInsret(LinkList& L, int val) {
    LNode* p = L->next;
    int j = 1;
    int flag = 0;//flag:调用过deletePoint的次数
    while (p) { 
        if (val == p->data) {
            deletePoint(L,j);
            flag++;
            j--;
        }
            p = p->next; j++;
    }
    cout << "共删除"<<flag<<"个元素" << endl;
    if (flag == 0) {
        insertList(L,val);
    }
    
}
int insertList(LinkList& L, int val) {
    LNode* p = L;
    while (p->next) { p = p->next; }
    LNode* s = new LNode;			//生成新结点s 
    s->data = val;      		           //将结点s的数据域置为val 
    s->next = NULL;	   	   
    p->next = s;
    cout << "Insert succeed!" << endl;
    return 0;
}//重写了insert函数，负责在链表末尾插入val
int deletePoint(LinkList& L, int position) {
    LNode* p = L;
    int j = 0;
    while (p && j < position - 1) { p = p->next; ++j; }	//寻找第i−1个结点 
    if (!p || j > position - 1) {
        cout << "删除的位置大于表长或小于1，删除失败" << endl;//i大于表长 + 1或者小于1  
        return -1;
    }
    p->next = p->next->next;
    cout << "Delete succeed!" << endl;
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
    L->next = NULL; //先建立一个带头结点的单链表
    cout << "请输入链表的元素，以-1结尾" << endl;
    createlist(L);
    showList(L);
    cout << "请输入一个整数" << endl;
    int val;
    cin >> val;
    deleteOrInsret(L, val);
    showList(L);
}