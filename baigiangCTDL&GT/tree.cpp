/*Nhap vao 1 cay nhi phan cac so/tao cay. Hiển thị cây cây nhị phân */
#include <iostream>
using namespace std;
struct node {
    int data;
    node *pleft;
    node *pright;
};
typedef struct node NODE;
typedef NODE* TREE;
void KhoiTaoCay( TREE &t)
{
    t=NULL;
}
void ThemNodeVaoCay(TREE &t, int x)
{
    if(t==NULL)// Cây rỗng
    {
        NODE *p = new NODE;//tạo 1 nút mới để thêm vào cây
        p->data= x;
        p->pleft = NULL;
        p->pright = NULL;
        t=p;//node p chính là node gốc
    }
    else // cây có phần tử
    {
        //Nhỏ bên trái, lớn bên phải
        if(t->data>x)
        {
            ThemNodeVaoCay(t->pleft,x);
        }
        else if(t->data<x)
        {
            ThemNodeVaoCay(t->pright,x);
        }
    }
}
// NLR, NRL, LNR, RNL,LRN,RLN
void Duyet_NLR(TREE t)
{

    if(t != NULL)
    {
        cout << t->data << " ";
        Duyet_NLR(t->pleft); // duyet ben trai
        Duyet_NLR(t->pright);// duyet ben phai
    }
}

int Menu(TREE &t)
{
    while(true)
    {
        cout << "\n===Menu===" << endl;
        cout << "=== 1. Nhap du lieu===" << endl;
        cout << "=== 2. Xuat dư lieu theo NLR===" << endl;
        cout << "=== 0. Ket thuc===" << endl;
        int luachon;
        cout <<"Nhap lua chon: ";
        cin >>luachon;
        if(luachon <0 || luachon >2)
        {
            cout << "Lua chon khong hop le";
        }
        else if(luachon ==1)
        {
            int x;
            cout << "Nhap so nguyen x= ";
            cin >>x;
            ThemNodeVaoCay(t,x);
        }
        else if(luachon==2)
        {
            cout << "Duyet theo NLR" << endl;
            Duyet_NLR(t);
        }
        else
        {
            break;
        }

    }
}
int main(void)
{
    TREE t;
    KhoiTaoCay(t);
    Menu(t);
    return 0;

}
