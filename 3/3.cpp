#include<iostream>
using namespace std;

class Worker{	//抽象类
protected:
	char name[10];
	int age;
	char sex;
	int pay_per_hour;
	double week_pay;
public:
	Worker(){};
	Worker(char* name, int age, char sex){
		int i;
		for (i = 0; name[i] != '\0'; ++i)
			this->name[i] = name[i];
		this->name[i] = '\0';
		this->age = age;
		this->sex = sex;
	}
	void Name() {
		cout << "name:"<<name <<"\tsex:"<<sex<<"\tage:"<<age<<"\tpay_per_hour:"<<pay_per_hour<< endl;
	};	
	//纯虚函数
	virtual void Computer_pay(double hours) = 0;
	friend ostream& operator<<(ostream& out, Worker& worker){
		worker.Name();
		out << "week_pay:" << worker.week_pay << endl;
		return out;
	};
};

class HourlyWorker :public Worker{
public:
	HourlyWorker(char* name, int age, char sex, int pay_per_hour) :Worker(name, age, sex){
		if (pay_per_hour == 1){
			this->pay_per_hour = 10;
		}
		else if(pay_per_hour == 2){
			this->pay_per_hour = 20;
		}
		else {
			pay_per_hour = 40;
		}
	}
	void Computer_pay(double hours){
		if (hours <= 40){
			week_pay = pay_per_hour*hours;
		}
		else {
			week_pay = pay_per_hour * 40 + 1.5*pay_per_hour*(hours - 40);
		}
	}

};
class SalariedWorker :public Worker{
public:
	SalariedWorker(char* name, int age, char sex, int pay_per_hour) : Worker(name, age, sex){
		if (pay_per_hour == 1){
			this->pay_per_hour = 30;
		}
		else {
			this->pay_per_hour = 50;
		}
	}
	void Computer_pay(double hours){
		if (hours >= 35){
			week_pay = pay_per_hour * 40;
		}
		else {
			week_pay = pay_per_hour*hours + 0.5*pay_per_hour*(35 - hours);
		}
	}
};

int main(){
	Worker* worker[5];
	int i;
	char name[10];
	char sex;
	int age;
	int type;
	int level;
	int flag;
	int hours;
	for (i = 0; i < 5; ++i){
		cout << "请输入第" << i << "个的姓名，年龄，性别(1男 0 女)，类别（1 计时，0 计薪）、薪金等级（计时3级，计薪2级）\n";
		cin >> name >> age >> sex >> type >> level;
		if (type == 0){
			worker[i] = new SalariedWorker(name, age, sex, level);
		}
		else if (type == 1){
			worker[i] = new HourlyWorker(name, age, sex, level);
		}
		else{
			cout << "type error\n";
		}
	}
	for (i = 0; i < 5; ++i){
		cout << i << ".";
		worker[i]->Name();
	}
	cout << "请选择一个，计算其工资：";
	cin >> flag;
	cout << "请输入工作时间:";
	cin >> hours;
	worker[flag]->Computer_pay(hours);
	cout << *worker[flag];
	for (i = 0; i < 5; ++i){
		delete worker[i];
	}
	system("pause");
	return 0;
}