#include<iostream>
#include<string.h>
using namespace std;
class CGoods{
private:
	long no;						//第一题
	char* p_name;				//第一题
	double price;			//第一题
	static int count;		//第二题
public:
	CGoods(long n,char* p,double pr){		//第一题
		no = n;
		p_name = new char[sizeof(p)];
		strcpy(p_name, p);
		price = pr;
		count++;		//第二题
	};
	CGoods(const CGoods &p){
		no = p.no;
		strcpy(p_name, p.p_name);
		price = p.price;
		count++;		//第二题
	};
	~CGoods(){ count--; delete(p_name); };
	void Print(){		//第一题
		printf("num:%d\tname:%s\tprice:%.2f\n", no, p_name, price);
	};
	int getCount(){ return count; };	//第二题
	friend char* getName(CGoods &p){ return p.p_name; };//第二题
	bool operator<(CGoods &p){	//第三题
		return price < p.price ? true : false;
	};
	bool operator >=(CGoods &p){	//第三题
		return price >= p.price ? true : false;
	};
	virtual void useFor(){ printf("This is Good\n"); };//第四题第五题
};
class CClothes :public CGoods{	//第四题
private:
	char* p_brand;
public:
	CClothes(long n, char* p, double pr, char* p_bra) :CGoods(n, p, pr){//第四题
		p_brand = new char[sizeof(p_bra)];
		strcpy(p_brand, p_bra);
	}
	~CClothes(){ delete(p_brand); };
	void useFor(){		//第四题第五题
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
	void useFor(){		//第四题第五题
		printf("This is food!\n");
	};
};
int CGoods::count = 0;
int main(){
	CGoods p1(1,"test",100);
	CGoods *p;		//对象指针
	p1.Print();
	printf("count:%d\tname:%s\n\n\n", p1.getCount(),getName(p1));

	CClothes p2(1, "test2", 99,"pin1");
	p = &p2;			
	p->useFor();		
	CFood p3(1, "test2", 99, "pin2");
	p = &p3;		
	p->useFor();	
}