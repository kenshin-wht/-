#include<iostream>
#include<string>
using namespace std;
/*

案例2：
设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。通过冒泡排序的算法
将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
英雄信息如下：
{"刘备",23,"男"},
{"关羽",22,"男"},
{"张飞",20,"男"},
{"赵云",21,"男"},
{"貂蝉",19,"女"},
*/


 //指针方法
struct hero {
	string name;
	int age;
	string sex;

};

void bubblesort(struct hero *he,int length)
{
	int retnum = 0;
	struct hero temp;
	//temp = *(he + 1);
		//*(he + 1) = *he;
		//*he = temp;
		/*
		if (he->age > (he + 1)->age)
		{
			temp = *(he + 1);
			*(he + 1) = *he;
			*he = temp;
			he++;
		}
		*/
		//cout << temp.age;
		//cout << he->age;
		//cout << (he+1)->age;
	for (int i = 0; i < length-1; i++)
	{
		retnum = 0;
		for (int j = 0; j < length -i- 1; j++)
		{
			if (he->age > (he + 1)->age)
			{
				cout << he->age<<endl;
		        cout << (he+1)->age<<endl;
				temp = *(he+1);
				*(he + 1) = *he;
				*he = temp;
				
			}
			he++;
			retnum++;
		}
		he -= retnum;
	}
}

void heroprint(struct hero arry[],int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "姓名：" << arry[i].name << " 年龄：" 
			<< arry[i].age << " 性别：" << arry[i].sex << endl;
	}
}

int main1() {
	hero heroarry[9] = {
	{ "关羽",22,"男" },
	{ "刘备",23,"男" },
	{ "张飞",20,"男" },
	{ "赵云",21,"男" },
	{ "貂蝉",19,"女" },
	{ "关羽1",28,"男" },
	{ "张飞1",27,"男" },
	{ "赵云1",21,"男" },
	{ "貂蝉1",19,"女" },
	};
	//hero hsingle = { "刘备",23,"男" } ;
	hero* h1 = heroarry;
	//hero* p = &hsingle;
	//cout << h1->age;
	int length = sizeof(heroarry) / sizeof(heroarry[0]);
	bubblesort(h1,length);
	heroprint(heroarry,length);
	system("pause");
	return 0;
}

//非指针方法
/*
struct hero {
	string name;
	int age;
	string sex;

};

void bubblesort(struct hero heroarry[], int length)
{
	struct hero temp;
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (heroarry[j].age > heroarry[j + 1].age)
			{
				temp = heroarry[j+1];
				heroarry[j + 1]= heroarry[j];
				heroarry[j] = temp;
			}
		}
	}
}

void heroprint(struct hero arry[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "姓名：" << arry[i].name << " 年龄："
			<< arry[i].age << " 性别：" << arry[i].sex << endl;
	}
}

int main() {
	hero heroarry[5] = {
	{ "刘备",23,"男" },
	{ "关羽",22,"男" },
	{ "张飞",20,"男" },
	{ "赵云",21,"男" },
	{ "貂蝉",19,"女" }, };
	int length = sizeof(heroarry) / sizeof(heroarry[0]);
	bubblesort(heroarry, length);
	heroprint(heroarry);
	system("pause");
	return 0;
}
*/