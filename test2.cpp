#include<iostream>
#include<string>
using namespace std;
/*

����2��
���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�;�����ṹ�����飬�����д��5��Ӣ�ۡ�ͨ��ð��������㷨
�������е�Ӣ�۰���������������������մ�ӡ�����Ľ����
Ӣ����Ϣ���£�
{"����",23,"��"},
{"����",22,"��"},
{"�ŷ�",20,"��"},
{"����",21,"��"},
{"����",19,"Ů"},
*/


 //ָ�뷽��
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
		cout << "������" << arry[i].name << " ���䣺" 
			<< arry[i].age << " �Ա�" << arry[i].sex << endl;
	}
}

int main1() {
	hero heroarry[9] = {
	{ "����",22,"��" },
	{ "����",23,"��" },
	{ "�ŷ�",20,"��" },
	{ "����",21,"��" },
	{ "����",19,"Ů" },
	{ "����1",28,"��" },
	{ "�ŷ�1",27,"��" },
	{ "����1",21,"��" },
	{ "����1",19,"Ů" },
	};
	//hero hsingle = { "����",23,"��" } ;
	hero* h1 = heroarry;
	//hero* p = &hsingle;
	//cout << h1->age;
	int length = sizeof(heroarry) / sizeof(heroarry[0]);
	bubblesort(h1,length);
	heroprint(heroarry,length);
	system("pause");
	return 0;
}

//��ָ�뷽��
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
		cout << "������" << arry[i].name << " ���䣺"
			<< arry[i].age << " �Ա�" << arry[i].sex << endl;
	}
}

int main() {
	hero heroarry[5] = {
	{ "����",23,"��" },
	{ "����",22,"��" },
	{ "�ŷ�",20,"��" },
	{ "����",21,"��" },
	{ "����",19,"Ů" }, };
	int length = sizeof(heroarry) / sizeof(heroarry[0]);
	bubblesort(heroarry, length);
	heroprint(heroarry);
	system("pause");
	return 0;
}
*/