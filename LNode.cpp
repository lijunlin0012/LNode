// LNode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
using namespace std;
typedef struct LNode {
	int data;
	struct LNode* next;
}Node, * LinkList;

//CreateList_F 
/*
Status ListDelete_L(LinkList& L, int i, ElemType& e) {
    p = L; j = 0;
    while (p->next && j < i - 1) {//寻找第i个结点，并令p指向其前驱 
        p = p->next; ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR; //删除位置不合理 
    q = p->next; //临时保存被删结点的地址以备释放 
    p->next = q->next; 	//改变删除结点前驱结点的指针域 
    e = q->data; 	//保存删除结点的数据域 
    delete q; 	//释放删除结点的空间 
    return OK;
}//ListDelete_L 
*/
void createlist(LinkList& L) {
    
   for(int i=0;i<5;i++) {
        LNode* p = new Node; //生成新结点 
        cin >> p->data; //输入元素值
        //cout << p->data;
       
        p->next = L->next; L->next = p; 	//插入到表头 
    } 
}
void deleteSameNum(LinkList& L) {
    LNode* p2 = L->next;
    LNode* q;
    while (p2->next) {
        if (p2->data == p2->next->data)
        {
            q = p2->next;
            p2->next = q->next;
            p2 = p2->next;
        }
        else {
            p2 = p2->next;
        }
    }
}
void showList(LinkList &L) {
    cout << "now the list is" << endl;
    LNode* p1 = L->next;
    cout << p1->data << endl;
    while (p1->next) {
        p1 = p1->next;
        cout << p1->data << endl;
    }
}

int main() {
    LNode* L = new LNode;
    L->next = NULL; //先建立一个带头结点的单链表
    createlist(L);
    showList(L);
    deleteSameNum(L);
 showList(L);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
