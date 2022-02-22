#include<iostream>
using namespace std;
#define MAX 1000

struct person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};
struct addressBooks
{
	struct person personArray[MAX];
	int size;
};

void signout();
void addMenu(addressBooks* abs);
void printMenu(addressBooks* abs);
int isExist(addressBooks* abs,string name);
void deleteMenu(addressBooks* abs);
void findperson(addressBooks* abs);
void modifyMenu(addressBooks* abs);
void clearMenu(addressBooks* abs);

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨ��¼ *****" << endl;
	cout << "*************************" << endl;
}


void menuResponse(addressBooks *abs)
{
	int select_true=1;
	while (select_true)
	{
		int select;
		cin >> select;
		switch (select)
		{
		case 1: //�����ϵ��
			addMenu(abs);
			break;
		case 2://��ʾ��ϵ��
			printMenu(abs);
			break;
		case 3://ɾ����ϵ��
		/*
		*{
			cout << "��������Ҫɾ������ϵ������" << endl;
			if (isExist(abs) == -1)
				cout << "���޴��ˣ�" << endl;
			else
				cout << "�鵽���ˣ�" << endl;
			system("pause");
			system("cls");
			showMenu();
		}
		*/
			deleteMenu(abs);
			break;
		case 4://������ϵ��
			findperson(abs);
			break;
		case 5://�޸���ϵ��
			modifyMenu(abs);
			break;
		case 6://�����ϵ��
			clearMenu(abs);
			break;
		case 0://�˳�ͨѶ¼
			signout();
			select_true = 0;
			break;
		default:
			cout << "���������������������룡" << endl;
			break;
		}
	}
}
 
void signout()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	//system("pause");
}

void addMenu(addressBooks *abs)
{
	if (abs->size < MAX)
	{
		//�����ϵ������
		cout << "��������ϵ������" << endl;
		string abs_name;
		cin >> abs_name;
		int ret;
		ret = isExist(abs, abs_name);
		if (ret == -1)
		{
			abs->personArray[abs->size].name = abs_name;
			//�����ϵ���Ա�
			cout << "��������ϵ���Ա�1--�У�2--Ů��" << endl;
			while (true)
			{
				int abs_sex;
				cin >> abs_sex;
				if (abs_sex == 1 || abs_sex == 2)
				{
					abs->personArray[abs->size].sex = abs_sex;
					break;
				}
				else
				{
					cout << "�����������������룡" << endl;
				}
			}
			//�����ϵ������
			cout << "��������ϵ������" << endl;
			int abs_age;
			cin >> abs_age;
			abs->personArray[abs->size].age = abs_age;
			//�����ϵ�˵绰����
			cout << "��������ϵ�˵绰" << endl;
			string abs_phone;
			cin >> abs_phone;
			abs->personArray[abs->size].phone = abs_phone;
			//�����ϵ�˵�ַ
			cout << "��������ϵ�˵�ַ" << endl;
			string abs_address;
			cin >> abs_address;
			abs->personArray[abs->size].address = abs_address;
			//����ͨѶ¼����
			abs->size++;
			cout << "��ӳɹ���" << endl;
		}
		else
		{
			cout << "�Ѵ���ͬ����ϵ�ˣ������Ч��" << endl;	
		}
		system("pause");
		system("cls");
		showMenu();
	}
	else
	{
		cout << "ͨѶ¼��������������ӣ�" << endl;
	}
}

void printMenu(addressBooks *abs)
{
	if (abs->size > 0)
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "��ϵ��������" << abs->personArray[i].name << "\t";
			/*if (abs->personArray[i].sex == 1)
				cout << "��ϵ���Ա���"<< endl;
			else
				cout << "��ϵ���Ա�Ů" << endl;
				*/
			//cout << "��ϵ���Ա�" << abs->personArray[i].sex << endl;
			cout << "��ϵ���Ա�" << (abs->personArray[i].sex==1?"��":"Ů") << "\t";
			cout << "��ϵ�����䣺" << abs->personArray[i].age << "\t";
			cout << "��ϵ�˵绰��" << abs->personArray[i].phone << "\t";
			cout << "��ϵ�˵�ַ��" << abs->personArray[i].address << endl;
		}
	}
	else
	{
		cout << "ͨѶ¼Ϊ�գ����������ϵ�ˣ�" << endl;
	}
	system("pause");
	system("cls");
	showMenu();
}

int isExist(addressBooks* abs,string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name ==name)
		{
			return i;
		}
	}
	return -1;
}

void deleteMenu(addressBooks* abs)
{
	cout << "������Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
		cout << "���޴��ˣ�" << endl;
	else
	{
		for (int i = isExist(abs, name); i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
	showMenu();
}

void findperson(addressBooks* abs)
{
	cout << "������Ҫ������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) != -1)
	{
		cout << "�Ա�" << abs->personArray[isExist(abs, name)].sex << "\t";
		cout << "���䣺" << abs->personArray[isExist(abs, name)].age << "\t";
		cout << "�绰��" << abs->personArray[isExist(abs, name)].phone << "\t";
		cout << "��ַ��" << abs->personArray[isExist(abs, name)].address << endl;
	}
	else
		cout << "���޴��ˣ�" << endl;
	system("pause");
	system("cls");
	showMenu();
}

void modifyMenu(addressBooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int ret;
	ret = isExist(abs, name);
	if (ret != -1)
	{
		int judge = 1;
		while (judge)
		{
			cout << "��Ҫ�޸ĸ���ϵ�˵���Ϣ�ǣ�" << endl;
			string infor;
			cin >> infor;
			if (infor == "�Ա�")
			{
				cout << "��д��ʾ��1--��/2--Ů" << endl;
				cout << name << "���Ա���Ҫ��Ϊ��" << endl;
				int change_one;
				cin >> change_one;
				abs->personArray[ret].sex = change_one;
				cout << "�޸���ϣ��Ƿ�����޸ģ�" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "��")
					judge = 1;
				else
					judge = 0;
			}
			else if (infor == "����")
			{
				cout << name << "��������Ҫ��Ϊ��" << endl;
				int change_two;
				cin >> change_two;
				abs->personArray[ret].age = change_two;
				cout << "�޸���ϣ��Ƿ�����޸ģ�" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "��")
					judge = 1;
				else
					judge = 0;
			}
			else if (infor == "�绰")
			{
				cout << name << "�ĵ绰��Ҫ��Ϊ��" << endl;
				string change_three;
				cin >> change_three;
				abs->personArray[ret].phone = change_three;
				cout << "�޸���ϣ��Ƿ�����޸ģ�" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "��")
					judge = 1;
				else
					judge = 0;
			}
			else if (infor == "��ַ")
			{
				cout << name << "�ĵ�ַ��Ҫ��Ϊ��" << endl;
				string change_four;
				cin >> change_four;
				abs->personArray[ret].address = change_four;
				cout << "�޸���ϣ��Ƿ�����޸ģ�" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "��")
					judge = 1;
				else
					judge = 0;
			}
			else if (infor == "����")
			{
				cout << "�˹��ܲ����޸���ϵ�˵�����!" << endl;
				cout << "�Ƿ�����޸ģ�" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "��")
					judge = 1;
				else
					judge = 0;
			}
			else
			{
				cout << "�޸���Ч" << endl;
				cout << "�Ƿ�����޸ģ�" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "��")
					judge = 1;
				else
					judge = 0;
			}
		}
	}
	else
		cout << "���޴��ˣ�" << endl;
	system("pause");
	system("cls");
	showMenu();
}

void clearMenu(addressBooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
	showMenu();
}

int main()
{
	struct addressBooks abook1;
	abook1.size = 0;
	showMenu();
	menuResponse(&abook1);
	system("pause");
	return 0;
}