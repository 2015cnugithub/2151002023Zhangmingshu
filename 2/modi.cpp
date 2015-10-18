#include<iostream>
#include<string.h>
using namespace std;
class CGoods{
private:
	long no;						//��һ��
	char* p_name;				//��һ��
	double price;			//��һ��
	static int count;		//�ڶ���
public:
	CGoods(long n,char* p,double pr){		//��һ��
		no = n;
		p_name = new char[sizeof(p)];
		strcpy(p_name, p);
		price = pr;
		count++;		//�ڶ���
	};
	CGoods(const CGoods &p){
		no = p.no;
		strcpy(p_name, p.p_name);
		price = p.price;
		count++;		//�ڶ���
	};
	~CGoods(){ count--; delete(p_name); };
	void Print(){		//��һ��
		printf("num:%d\tname:%s\tprice:%.2f\n", no, p_name, price);
	};
	int getCount(){ return count; };	//�ڶ���
	friend char* getName(CGoods &p){ return p.p_name; };//�ڶ���
	bool operator<(CGoods &p){	//������
		return price < p.price ? true : false;
	};
	bool operator >=(CGoods &p){	//������
		return price >= p.price ? true : false;
	};
	virtual void useFor(){ printf("This is Good\n"); };//�����������
};
class CClothes :public CGoods{	//������
private:
	char* p_brand;
public:
	CClothes(long n, char* p, double pr, char* p_bra) :CGoods(n, p, pr){//������
		p_brand = new char[sizeof(p_bra)];
		strcpy(p_brand, p_bra);
	}
	~CClothes(){ delete(p_brand); };
	void useFor(){		//�����������
		printf("This is clothes!\n");
	};
};
class CFood :public CGoods{
private:
	char* p_brand;
public:
	CFood(long n, char* p, double pr, char* p_bra) :CGoods(n, p, pr){
		p_brand = new char[sizeof(p_bra)];
		strcpy(p_brand, p_bra);
	}
	~CFood(){ delete(p_brand); };
	void useFor(){		//�����������
		printf("This is food!\n");
	};
};
int CGoods::count = 0;
int main(){
	CGoods p1(1,"test",100);
	CGoods *p;		//����ָ��
	p1.Print();
	printf("count:%d\tname:%s\n\n\n", p1.getCount(),getName(p1));

	CClothes p2(1, "test2", 99,"pin1");
	p = &p2;			
	p->useFor();		
	CFood p3(1, "test2", 99, "pin2");
	p = &p3;		
	p->useFor();	
}