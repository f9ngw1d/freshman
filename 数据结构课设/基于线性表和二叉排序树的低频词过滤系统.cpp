#include<iostream>
#include<time.h>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<ctype.h>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#define MAXSIZE 10000
#define N 5
using namespace std;
void mune()
{
	int linklist();
	int Tree();
	cout << "******************�˵�******************" << endl;
	cout << "*��ѡ����Ҫִ�еĲ���                  *" << endl;
	cout << "*1�����Ա�                             *" << endl;
	cout << "*2������������                         *" << endl;
	cout << "*3���˳�ϵͳ                           *" << endl;
	cout << "*���������Ҫ�ķ����������֣�1-3��   *" << endl;
	cout << "****************************************" << endl;
	int t;
	while (1)
	{
		cin >> t;
		switch (t)
		{
		case 1:linklist(); break;
		case 2:Tree(); break;
		case 3:return; break;
		default:cout << "���������������������" << endl; break;
		}
	}
}
string d[10000];
string print1[10000];
int print2[10000];
int n = 0;
int m = 0;
int z = 0;
typedef struct
{
	string c;
	int freq;
}word;
struct Source
{
	string b;
	int count;
}Bt[1000];
typedef struct LNode
{
	word data;
	struct LNode *next;
}LNode, *LinkList;
int InitList(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return 1;
}
typedef struct BSTNode {
	word elem;
	struct BSTNode *lChild, *rChild;
} BSTNode, *BSTree;
typedef struct
{
	word *elem;
	int length;
}SqList;
int InitListSqlist(SqList &L)
{
	L.elem = new word[MAXSIZE];
	if (!L.elem) exit(0);
	L.length = 0;
	return 1;
}
BSTree T; 
BSTree BT; 
void InOrderzhong(BSTree BT)    //������� 
{
	if (BT)
	{
		InOrderzhong(BT->lChild);
		cout << BT->elem.c << " " << BT->elem.freq << endl;
		InOrderzhong(BT->rChild);
	}
}
void InOrderhou(BSTree BT)      //������� 
{
	if (BT)
	{
		InOrderhou(BT->lChild);
		InOrderhou(BT->rChild);
		cout << BT->elem.c << " " << BT->elem.freq << endl;
	}
}
void InOrderxian(BSTree BT)      //������� 
{
	if (BT)
	{
		cout << BT->elem.c << " " << BT->elem.freq << endl;
		InOrderxian(BT->lChild);
		InOrderxian(BT->rChild);
	}
}
void Balance(BSTree &T)
{
	if (T)
	{
		Balance(T->lChild);
		Bt[z].b = T->elem.c;
		Bt[z].count = T->elem.freq;
		z++;
		Balance(T->rChild);
	}
}
int y=0;
int Depth(BSTree T)
{
	if (!T)
		return 0;
	else
	{
		int x = Depth(T->lChild);
		int y = Depth(T->rChild);
		if (x > y)
			return (x + 1);
		else
			return (y + 1);
	}
}
void Balanceinsert(BSTree &bT,struct Source t)      //ƽ����������� 
{
	if (!bT)
	{
		BSTree S;
		S = new BSTNode;
		S->elem.c = t.b;
		S->elem.freq = t.count;
		S->lChild = NULL;
		S->rChild = NULL;
		bT = S;
	}
	else if (t.b < bT->elem.c)
	{
		Balanceinsert(bT->rChild, t);
		if ((Depth(bT->lChild) - Depth(bT->rChild)) > 1 || (Depth(bT->lChild) - Depth(bT->rChild)) < -1)
		{
			if (t.b < bT->elem.c)
			{
				BSTree r1;
				BSTree r2=bT;
				r1=bT->rChild;
				bT->rChild=r1->lChild;
				r1->lChild=bT;
				bT=r1;
			}
		}
	}
	else if (t.b > bT->elem.c)
	{
		Balanceinsert(bT->lChild, t);
	}
}
void Balancetree()       
{
	BT=NULL;
	for (int i = 0; i < z; i++)
	{
		Balanceinsert(BT, Bt[i]);
	}
}

double timeclock=0;
void AllLinkList()         //�����һ��ִ�� 
{
	clock_t start,finish;
   	double totaltime;
   	start=clock();
	int linklist();  
	FILE *fp;
	LinkList L;
	L = new LNode;
	L->next = NULL;
	LinkList q, p, r = L;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				int j = 0;
				q = L->next;
				while (q)
				{
					if (q->data.c == str)
					{
						q->data.freq++;
						break;
					}
					q = q->next;
				}
				if (q == NULL)
				{
					p = new LNode;
					p->next = NULL;
					p->data.c = str;
					p->data.freq = 1;
					r->next = p;
					r = p;
					j++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	q = L->next;
	q = L;
	while (q->next != NULL)
	{
		if (q->next->data.freq < 5)
		{
			LinkList f = q->next;
			q->next = f->next;
			delete f;
		}
		else
		{
			q = q->next;
		}
	}
	for (LinkList i = L->next; i->next != NULL; i = i->next)
		for (LinkList j = i->next; j != NULL; j = j->next)
			if (j->data.freq>i->data.freq)
			{
				word t = i->data;
				i->data = j->data;
				j->data = t;
			}
	fstream fin1;
	fin1.open("OutFile.txt", ios::out);
	if (fin1.fail())
	{
		return;
	}
	q = L->next;
	double sum=0;
	double ASL=0;
	while (q)
	{
		fin1 << q->data.c << " " << q->data.freq << endl;
		sum+=q->data.freq;
		q = q->next;
	}
	int k=1;
	q = L->next;
	while(q)
	{
		ASL+=(q->data.freq/sum)*k;
		k++;
		q=q->next;
	}
	printf("ASLֵΪ��%.8lf\n",ASL);
 	finish=clock();
   	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   	timeclock=totaltime;
   	fin1<<"�˳��������ʱ��Ϊ"<<totaltime<<"�룡"<<endl;	
	fin1.close();
	linklist();      
}
void Time()         //��������ʱ�� 
{
	int linklist();
	clock_t start,finish;
   	double totaltime;
   	start=clock();
	FILE *fp;
	LinkList L;
	L = new LNode;
	L->next = NULL;
	LinkList q, p, r = L;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				int j = 0;
				q = L->next;
				while (q)
				{
					if (q->data.c == str)
					{
						q->data.freq++;
						break;
					}
					q = q->next;
				}
				if (q == NULL)
				{
					p = new LNode;
					p->next = NULL;
					p->data.c = str;
					p->data.freq = 1;
					r->next = p;
					r = p;
					j++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	q = L->next;
	q = L;
	while (q->next != NULL)
	{
		if (q->next->data.freq < 5)
		{
			LinkList f = q->next;
			q->next = f->next;
			delete f;
		}
		else
		{
			q = q->next;
		}
	}
	for (LinkList i = L->next; i->next != NULL; i = i->next)
		for (LinkList j = i->next; j != NULL; j = j->next)
			if (j->data.freq>i->data.freq)
			{
				word t = i->data;
				i->data = j->data;
				j->data = t;
			}
	fstream fin1;
	fin1.open("OutFile.txt", ios::out);
	if (fin1.fail())
	{
		return;
	}
	q = L->next;
	double sum=0;
	double ASL=0;
	while (q)
	{
		fin1 << q->data.c << " " << q->data.freq << endl;
		sum+=q->data.freq;
		q = q->next;
	}
	int k=1;
	q = L->next;
	while(q)
	{
		ASL+=(q->data.freq/sum)*k;
		k++;
		q=q->next;
	}
//	printf("ASLֵΪ��%.8lf\n",ASL);
 	finish=clock();
   	totaltime=(double)(finish-start);//CLOCKS_PER_SEC;
   	timeclock=totaltime;
	printf("�˳��������ʱ��Ϊ:%lf��\n",timeclock);
	linklist();
}
void count()  //�������������� 
{
	int countotal=0;
	int linklist();
	FILE *fp;
	LinkList L;
	L = new LNode;
	L->next = NULL;
	LinkList q, p, r = L;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				int j = 0;
				q = L->next;
				while (q)
				{
					if (q->data.c == str)
					{
						q->data.freq++;
						break;
					}
					q = q->next;
				}
				if (q == NULL)
				{
					p = new LNode;
					p->next = NULL;
					p->data.c = str;
					p->data.freq = 1;
					r->next = p;
					r = p;
					j++;
				}	
			cout<<"��ʶ�𵥴ʣ�"<<str<<endl;
			countotal++; 
			}
			i=flag=0;
		
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	cout<<"�ܵĵ��ʸ���Ϊ��"<<countotal<<endl;
	fclose(fp);
	linklist();
}
void Delete()   //����Ƶ��С��5�ĵ��ʽ���ɾ�� 
{
	int linklist();
	FILE *fp;
	LinkList L;
	L = new LNode;
	L->next = NULL;
	LinkList q, p, r = L;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				int j = 0;
				q = L->next;
				while (q)
				{
					if (q->data.c == str)
					{
						q->data.freq++;
						break;
					}
					q = q->next;
				}
				if (q == NULL)
				{
					p = new LNode;
					p->next = NULL;
					p->data.c = str;
					p->data.freq = 1;
					r->next = p;
					r = p;
					j++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	q = L->next;
	q = L;
	while (q->next != NULL)
	{
		if (q->next->data.freq < 5)
		{
			cout<<"ɾ���ĵ���Ϊ:"<<q->next->data.c;printf(" Ƶ��Ϊ��%d\n",q->next->data.freq);
			LinkList f = q->next;
			q->next = f->next;
			delete f;
			printf("ɾ���ɹ�\n"); 
		}
		else
		{
			q = q->next;
		}
	}
	linklist();
}
void coutprint() //���ʣ�൥�� 
{
	int linklist();
		FILE *fp;
	LinkList L;
	L = new LNode;
	L->next = NULL;
	LinkList q, p, r = L;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				int j = 0;
				q = L->next;
				while (q)
				{
					if (q->data.c == str)
					{
						q->data.freq++;
						break;
					}
					q = q->next;
				}
				if (q == NULL)
				{
					p = new LNode;
					p->next = NULL;
					p->data.c = str;
					p->data.freq = 1;
					r->next = p;
					r = p;
					j++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	q = L->next;
	q = L;
	while (q->next != NULL)
	{
		if (q->next->data.freq < 5)
		{
			LinkList f = q->next;
			q->next = f->next;
			delete f;
		}
		else
		{
			q = q->next;
		}
	}
	for (LinkList i = L->next; i->next != NULL; i = i->next)
		for (LinkList j = i->next; j != NULL; j = j->next)
			if (j->data.freq>i->data.freq)
			{
				word t = i->data;
				i->data = j->data;
				j->data = t;
			}
	q = L->next;
	while (q)
	{	
		cout<<"ʣ�൥��Ϊ��"<<q->data.c<<endl;
		printf("��Ƶ��Ϊ��%2d\n",q->data.freq);
		q = q->next;
	}
	linklist();
}
void calculate() //����ɾ����ASL��ֵ 
{
	int linklist();
		FILE *fp;
	LinkList L;
	L = new LNode;
	L->next = NULL;
	LinkList q, p, r = L;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				int j = 0;
				q = L->next;
				while (q)
				{
					if (q->data.c == str)
					{
						q->data.freq++;
						break;
					}
					q = q->next;
				}
				if (q == NULL)
				{
					p = new LNode;
					p->next = NULL;
					p->data.c = str;
					p->data.freq = 1;
					r->next = p;
					r = p;
					j++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	q = L->next;
	q = L;
	while (q->next != NULL)
	{
		if (q->next->data.freq < 5)
		{
			LinkList f = q->next;
			q->next = f->next;
			delete f;
		}
		else
		{
			q = q->next;
		}
	}
	for (LinkList i = L->next; i->next != NULL; i = i->next)
		for (LinkList j = i->next; j != NULL; j = j->next)
			if (j->data.freq>i->data.freq)
			{
				word t = i->data;
				i->data = j->data;
				j->data = t;
			}
	fstream fin1;
	fin1.open("OutFile.txt", ios::out);
	if (fin1.fail())
	{
		return;
	}
	q = L->next;
	double sum=0;
	double ASL=0;
	while (q)
	{
		fin1 << q->data.c << " " << q->data.freq << endl;
		sum+=q->data.freq;
		q = q->next;
	}
	int k=1;
	q = L->next;
	while(q)
	{
		ASL+=(q->data.freq/sum)*k;
		k++;
		q=q->next;
	}
	printf("ASLֵΪ��%.8lf\n",ASL);
	linklist();
}
void linklist()
{
	int b;
	cout << "****************************************" << endl;
	cout << "*1������ִ�в����                     *" << endl;
	cout << "*2����ʾִ��ʱ��                       *" << endl;
	cout << "*3������ִ�У�ʶ��ͳ�Ƶ��ʸ���       *" << endl;
	cout << "*4������ִ�У�ɾ������ʾ����Ƶ�ʵ͵��� *" << endl;
	cout << "*5������ִ�У�����������ʼ���Ƶ��     *" << endl;
	cout << "*6������ִ�У����㲢���ASLֵ          *" << endl;
	cout << "*7���������˵�                         *" << endl;
	cout << "****************************************" << endl;
	while (1)
	{
		cin >> b;
		switch (b)
		{
		case 1:AllLinkList(); break;
		case 2:Time(); break;
		case 3:count(); break;
		case 4:Delete(); break;
		case 5:coutprint(); break;
		case 6:calculate(); break;
		case 7:mune();break;
		default:cout << "���������������������" << endl; break;
		} 
	}
}
void InsertBST(BSTree &T, word e)
{
	if (!T)
	{
		BSTree S = new BSTNode;
		S->elem = e;
		S->lChild = NULL;
		S->rChild = NULL;
		T = S;
	}
	else if (T->elem.c > e.c)
		InsertBST(T->lChild, e);
	else
		InsertBST(T->rChild, e);
}
void CreatBST(BSTree &T, SqList &L)
{
	T = NULL;
	for (int i = 0; i < L.length; i++)
	{
		InsertBST(T, L.elem[i]);
	}
}
int u=0;
int SearchBST(BSTree T,string key)
{
	u++;
	if(!T||T->elem.c==key) return u;
	else if(key<T->elem.c) return SearchBST(T->lChild,key);
	else return SearchBST(T->rChild,key);
}
void DeleteBST(BSTree &T, string key)  //������ָ��Ԫ�ص�ɾ�� 
{
	BSTree p = T, q=NULL,s=NULL,f = NULL;
	while (p)
	{
		if (p->elem.c == key) break;
		f = p;
		if (p->elem.c>key) p = p->lChild;
		else p = p->rChild;
	}
	if (!p) return;
	q = p;
	if ((p->lChild) && (p->rChild))
	{
		s = p->lChild;
		while (s->rChild)
		{
			q = s;
			s = s->rChild;
		}
		p->elem = s->elem;
		if (q != p) q->rChild = s->lChild;
		else q->lChild = s->lChild;
		delete s;
		return;
	}
	else if (!p->rChild)
	{
		p = p->lChild;
	}
	else if (!p->lChild)
	{
		p = p->rChild;
	}
	if (!f) T = p;
	else if (q == f->lChild) f->lChild = p;
	else f->rChild = p;
	delete q;
}
double clocktime=0;
void printcout() 
{
	fstream fin1;
	fin1.open("OutFile1.txt", ios::out);
	if (fin1.fail())
	{
		return;
	}
	int t;
	string str1;
	for(int j=0;j<n-1;j++)
		for(int i=0;i<n-1-j;i++)
			if (print2[i] < print2[i + 1])
			{
				t = print2[i];
				print2[i] = print2[i + 1];
				print2[i + 1] = t;
				str1 = print1[i];
				print1[i] = print1[i + 1];
				print1[i + 1] = str1;
			}
	for (int i = 0; i<n; i++)
	{
		cout << print1[i] << "       ʣ�൥��Ƶ��Ϊ     " << print2[i] << endl;
		fin1 << print1[i] << "       ʣ�൥��Ƶ��Ϊ     " << print2[i] << endl;
	}
	fin1<<"����ʱ��Ϊ"<<setiosflags(ios::fixed)<<setprecision(8)<<clocktime<<"��"<<endl;
	fin1.close();
}
void pre_traverset(BSTree T)  //�������������ҳ�С��5�ĵ��� 
{
	if (T)
	{
		//cout << T->elem.c << "     " << T->elem.freq << endl;
		if (T->lChild)
			pre_traverset(T->lChild);
		if (T->elem.freq<5)
		{
			cout << T->elem.c << "     ����ɾ���Ľڵ�Ƶ��Ϊ��     " << T->elem.freq << endl;
			d[m] = T->elem.c;
			m++;
		}
		if (T->rChild)
			pre_traverset(T->rChild);
	}
}
void pre_traversetr(BSTree T)   //��Ƶ��С��5�ĵ������ 
{
	if (T)
	{
		//cout << T->elem.c << "     " << T->elem.freq << endl;
		if (T->lChild)
			pre_traversetr(T->lChild);
		if (T->elem.freq<5)
		{
			//cout << T->elem.c << "     ����ɾ���Ľڵ�Ƶ��Ϊ��     " << T->elem.freq << endl;
			d[m] = T->elem.c;
			m++;
		}
		if (T->rChild)
			pre_traversetr(T->rChild);
	}
}
void pre_traverse(BSTree T)
{
	if (T)
	{
		print1[n] = T->elem.c;
		print2[n] = T->elem.freq;
		n++;
		if (T->lChild)
			pre_traverse(T->lChild);	
		if (T->rChild)
			pre_traverse(T->rChild);
	}
}
void TreeAllLinkList() //��������һ��ȫִ�� 
{
	int Tree();
	clock_t start,finish;
   double totaltime;
   start=clock();
	SqList L;
	InitListSqlist(L);
	FILE *fp;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				for (j = 0; j<L.length; j++)
				{
					if (str == L.elem[j].c)
					{
						L.elem[j].freq++;
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					L.elem[L.length].c = str;
					L.elem[L.length].freq = 1;
					L.length++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	BSTree F;
	CreatBST(T, L);
	pre_traverset(T);
	double sum=0;
	double ASL=0;
	for(int i=0;i<L.length;i++)
	{
		sum+=L.elem[i].freq;
	}
	for(int i=0;i<L.length;i++)
	{
		ASL=(L.elem[i].freq/sum)*SearchBST(T,L.elem[i].c);
		u=0;
	}
	printf("ASLֵΪ��%lf\n",ASL);
	for (int i=0; i<m; i++)
	{
		DeleteBST(T, d[i]);
	}
	n=0;
	pre_traverse(T);
	finish=clock();
   	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   	clocktime=totaltime;
    printf("�˳��������ʱ��Ϊ:%lf��\n",clocktime);
	printcout();
    Tree();
}
void TreeTime()   //����������ʱ�� 
{
	int Tree();
	clock_t start,finish;
   	double totaltime;
  	start=clock();
	SqList L;
	InitListSqlist(L);
	FILE *fp;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				for (j = 0; j<L.length; j++)
				{
					if (str == L.elem[j].c)
					{
						L.elem[j].freq++;
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					L.elem[L.length].c = str;
					L.elem[L.length].freq = 1;
					L.length++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	BSTree F;
	pre_traversetr(T);
	
	double sum=0;
	double ASL=0;
	for(int i=0;i<L.length;i++)
	{
		sum+=L.elem[i].freq;
	}
	for(int i=0;i<L.length;i++)
	{
		ASL=(L.elem[i].freq/sum)*SearchBST(T,L.elem[i].c);
		u=0;
	}
	
	//printf("ASLֵΪ��%lf\n",ASL);
	for (int i=0; i<m; i++)
	{
		DeleteBST(T, d[i]);
	} 
	pre_traverse(T);
	finish=clock();
   	totaltime=(double)(finish-start);//CLOCKS_PER_SEC;
   	clocktime=totaltime;
	printf("�˳��������ʱ��Ϊ:%lf��\n",clocktime);
	Tree();
}
void Treecount()   //���������ʼ��� 
{
	int Tree();
	SqList L;
	InitListSqlist(L);
	FILE *fp;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	int number3=0;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				for (j = 0; j<L.length; j++)
				{
					if (str == L.elem[j].c)
					{
						L.elem[j].freq++;
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					L.elem[L.length].c = str;
					L.elem[L.length].freq = 1;
					L.length++;
				}
				cout<<"��ʶ�𵥴�"<<str<<endl; 
				number3++;
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	cout<<"���ʸ���Ϊ��"<<number3<<endl; 
	fclose(fp);
	Tree();
}
void TreeDelete()  //����������ɾ�� 
{
	int Tree();
	SqList L;
	InitListSqlist(L);
	FILE *fp;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				for (j = 0; j<L.length; j++)
				{
					if (str == L.elem[j].c)
					{
						L.elem[j].freq++;
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					L.elem[L.length].c = str;
					L.elem[L.length].freq = 1;
					L.length++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	BSTree F;
	CreatBST(T, L);
	pre_traverset(T);
	double sum=0;
	for (int i=0; i<m; i++)
	{
		DeleteBST(T, d[i]);
	}	
	for(int i=0;i<1000;i++)
	{
		Bt[i].b="";
		Bt[i].count=0;
	}
	pre_traverse(T);
	z=0;
	Balance(T);
	Balancetree();
	cout<<"ƽ�����������������:"<<endl;
	InOrderzhong(BT);
	cout<<"ƽ�����������������:"<<endl;
	InOrderhou(BT);
	cout<<"ƽ�������ǰ��������:"<<endl;
	InOrderxian(BT);
	Tree();
}
void Treecalculate()  //������ʣ�൥�ʵ���� 
{
	int Tree();
	SqList L;
	InitListSqlist(L);
	FILE *fp;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				for (j = 0; j<L.length; j++)
				{
					if (str == L.elem[j].c)
					{
						L.elem[j].freq++;
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					L.elem[L.length].c = str;
					L.elem[L.length].freq = 1;
					L.length++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	BSTree F;
	CreatBST(T, L);
	pre_traversetr(T);
	for (int i=0; i<m; i++)
	{
		DeleteBST(T, d[i]);
	}
	n=0;
	pre_traverse(T);
	printcout();
	Tree();
}
void Treeprintcout()     //������ASL���� 
{
	int Tree();
	SqList L;
	InitListSqlist(L);
	FILE *fp;
	if ((fp = fopen("InFile.txt", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	char ch, a[100],t;
	string str;
	int i = 0;
	int j = 0,flag;
	a[i]=fgetc(fp);
	while(!isalpha(a[i]))
	{
		a[i]=fgetc(fp);
	}
	i++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (!isalpha(ch))
		{
			str=a;
			if(str!="\0")
			{
				for (j = 0; j<L.length; j++)
				{
					if (str == L.elem[j].c)
					{
						L.elem[j].freq++;
						flag=1;
						break;
					}
				}
				if (flag==0)
				{
					L.elem[L.length].c = str;
					L.elem[L.length].freq = 1;
					L.length++;
				}
			}
			i=flag=0;
			memset(a, '\0', sizeof(a));
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
	fclose(fp);
	BSTree F;
	CreatBST(T, L);
	pre_traversetr(T);
	double sum=0;
	double ASL=0;
	for(int i=0;i<L.length;i++)
	{
		sum+=L.elem[i].freq;
	}
	for(int i=0;i<L.length;i++)
	{
		ASL=(L.elem[i].freq/sum)*SearchBST(T,L.elem[i].c);
		u=0;
	}
	printf("ASLֵΪ��%lf\n",ASL);
	/*for (int i=0; i<m; i++)
	{
		DeleteBST(T, d[i]);
	}
	pre_traverse(T);
	printcout();*/
	Tree();
}
int Tree()
{
	int b;
	cout << "****************************************" << endl;
	cout << "*1������ִ�в����                     *" << endl;
	cout << "*2����ʾִ��ʱ��                       *" << endl;
	cout << "*3������ִ�У�ʶ��ͳ�Ƶ��ʸ���       *" << endl;
	cout << "*4������ִ�У�ɾ������ʾ����Ƶ�ʵ͵��� *" << endl;
	cout << "*5������ִ�У�����������ʼ���Ƶ��     *" << endl;
	cout << "*6������ִ�У����㲢���ASLֵ          *" << endl;
	cout << "*7���������˵�                         *" << endl;
	cout << "****************************************" << endl;
	while (1)
	{
		cin >> b;
		switch (b)
		{
		case 1:TreeAllLinkList(); break;
		case 2:TreeTime(); break;
		case 3:Treecount(); break;
		case 4:TreeDelete(); break;
		case 5:Treecalculate();break;
		case 6:Treeprintcout();  break;
		case 7:mune(); break;
		default:cout << "���������������������" << endl; break;
		}
	}
}
int main()
{
	mune();
	return 0;
}
