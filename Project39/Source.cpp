#include <iostream>
#include <vector>
using namespace std;
class employee {
protected:
	string name;
	int salary;
	int salarysaver=0;
	string job;
public:
	employee() = default;
	employee(string n, int s, string j):name(n),salary(s),job(j){}
	virtual void work() = 0;
	virtual void paysalary() {
		cout << "paid " << salarysaver << endl;
		salarysaver = 0;
	}
	string getname() {
		return name;
	}
	int getsalary() {
		return salary;
	}
	int getsalarysaver() {
		return salarysaver;
	}
	string getjob() {
		return job;
	}
	void setname(string n) {
		name = n;
	}
	void setjob(string n) {
		job = n;
	}
	void setsalary(int n) {
		salary = n;
	}
	void setsalarysaver(int n) {
		salarysaver = n;
	}
};
class programmer :public employee {
public:
	programmer() = default;
	programmer(string n, int s, string j) :employee(n, s, j) {}
	virtual void work() {
		salarysaver += salary;
		cout << "programming" << endl;
	}
};

class tester :public employee {
public:
	tester(string n, int s, string j) :employee(n, s, j) {}
	void work() {
		salarysaver += salary;
		cout << "testing" << endl;
	}
};

class manager :public employee {
public:
	manager(string n, int s, string j) :employee(n, s, j) {}
	void work() {
		salarysaver += salary;
		cout << "managing" << endl;
	}
};
class teamlead :public programmer {
	vector<employee*> arr;
public:
	teamlead(string n, int s, string j) :programmer(n, s, j) {
	}
	void work() {
		salarysaver += salary;
		cout << "programming and leading" << endl;
	}
	void add(employee* obj) {
		arr.push_back(obj);
	}
	void Delete(int j) {
		arr.erase(arr.begin() + j);
	}
	void print() {
		for (auto i = arr.begin(); i < arr.end();i++) {
			cout << (*i)->getname() << endl;
		}
	}
};
class project {
	string name;
	int budget;
	vector<employee*> arr;
public:
	project(string n, int b):name(n),budget(b) {
	}
	void add(employee* obj) {
		arr.push_back(obj);
	}
	void Delete(int j) {
		arr.erase(arr.begin() + j);
	}
	void print() {
		for (auto i = arr.begin(); i < arr.end(); i++) {
			cout << (*i)->getname() << endl;
		}
	}
	void salary() {
		int sum=0;
		for (auto i = arr.begin(); i < arr.end(); i++) {
			sum += (*i)->getsalary();
		}
		cout << sum << endl;
	}
	void work() {
		for (auto i = arr.begin(); i < arr.end(); i++) {
			(*i)->work();
		}
	}
	void maxsalary() {
		int max = arr[0]->getsalary();
		for (auto i = arr.begin(); i < arr.end(); i++) {
			if (max < (*i)->getsalary())
			{
				max = (*i)->getsalary();
			}
		}
		cout << max << endl;
	}
	void paysalary() {
		for (auto i = arr.begin(); i < arr.end(); i++) {
			(*i)->paysalary();
		}
	}
};
int main(){
	employee* foo = new programmer("name", 1000, "junior");
	employee* foo1 = new programmer("name1", 1000, "junior");
	employee* foo2 = new programmer("name2", 1000, "junior");
	employee* foo3 = new teamlead("name3", 1500, "senior");
	teamlead human("lead", 1500, "senior");
	human.add(foo);
	human.add(foo1);
	human.add(foo2);
	human.print();
	human.Delete(1);
	human.print();
	project first("plan", 100000);
	first.add(foo);
	first.add(foo1);
	first.add(foo2);
	first.add(foo3);
	first.Delete(0);
	first.print();
	first.maxsalary();
	first.salary();
	first.work();
	first.paysalary();
	first.work();
	first.work();
	first.work();
	first.paysalary();
	project second("plan", 1000000);
	second.add(foo);
	second.add(foo1);
	second.add(foo2);
}
