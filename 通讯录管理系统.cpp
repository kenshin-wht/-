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
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通信录 *****" << endl;
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
		case 1: //添加联系人
			addMenu(abs);
			break;
		case 2://显示联系人
			printMenu(abs);
			break;
		case 3://删除联系人
		/*
		*{
			cout << "请先输入要删除的联系人姓名" << endl;
			if (isExist(abs) == -1)
				cout << "查无此人！" << endl;
			else
				cout << "查到此人！" << endl;
			system("pause");
			system("cls");
			showMenu();
		}
		*/
			deleteMenu(abs);
			break;
		case 4://查找联系人
			findperson(abs);
			break;
		case 5://修改联系人
			modifyMenu(abs);
			break;
		case 6://清空联系人
			clearMenu(abs);
			break;
		case 0://退出通讯录
			signout();
			select_true = 0;
			break;
		default:
			cout << "您的输入有误！请重新输入！" << endl;
			break;
		}
	}
}
 
void signout()
{
	cout << "欢迎下次使用！" << endl;
	//system("pause");
}

void addMenu(addressBooks *abs)
{
	if (abs->size < MAX)
	{
		//添加联系人姓名
		cout << "请输入联系人姓名" << endl;
		string abs_name;
		cin >> abs_name;
		int ret;
		ret = isExist(abs, abs_name);
		if (ret == -1)
		{
			abs->personArray[abs->size].name = abs_name;
			//添加联系人性别
			cout << "请输入联系人性别（1--男，2--女）" << endl;
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
					cout << "输入有误！请重新输入！" << endl;
				}
			}
			//添加联系人年龄
			cout << "请输入联系人年龄" << endl;
			int abs_age;
			cin >> abs_age;
			abs->personArray[abs->size].age = abs_age;
			//添加联系人电话号码
			cout << "请输入联系人电话" << endl;
			string abs_phone;
			cin >> abs_phone;
			abs->personArray[abs->size].phone = abs_phone;
			//添加联系人地址
			cout << "请输入联系人地址" << endl;
			string abs_address;
			cin >> abs_address;
			abs->personArray[abs->size].address = abs_address;
			//更新通讯录人数
			abs->size++;
			cout << "添加成功！" << endl;
		}
		else
		{
			cout << "已存在同名联系人，添加无效！" << endl;	
		}
		system("pause");
		system("cls");
		showMenu();
	}
	else
	{
		cout << "通讯录已满，不允许添加！" << endl;
	}
}

void printMenu(addressBooks *abs)
{
	if (abs->size > 0)
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "联系人姓名：" << abs->personArray[i].name << "\t";
			/*if (abs->personArray[i].sex == 1)
				cout << "联系人性别：男"<< endl;
			else
				cout << "联系人性别：女" << endl;
				*/
			//cout << "联系人性别：" << abs->personArray[i].sex << endl;
			cout << "联系人性别：" << (abs->personArray[i].sex==1?"男":"女") << "\t";
			cout << "联系人年龄：" << abs->personArray[i].age << "\t";
			cout << "联系人电话：" << abs->personArray[i].phone << "\t";
			cout << "联系人地址：" << abs->personArray[i].address << endl;
		}
	}
	else
	{
		cout << "通讯录为空，请先添加联系人！" << endl;
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
	cout << "请输入要删除的联系人姓名" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
		cout << "查无此人！" << endl;
	else
	{
		for (int i = isExist(abs, name); i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
	showMenu();
}

void findperson(addressBooks* abs)
{
	cout << "请输入要查找联系人的姓名" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) != -1)
	{
		cout << "性别：" << abs->personArray[isExist(abs, name)].sex << "\t";
		cout << "年龄：" << abs->personArray[isExist(abs, name)].age << "\t";
		cout << "电话：" << abs->personArray[isExist(abs, name)].phone << "\t";
		cout << "地址：" << abs->personArray[isExist(abs, name)].address << endl;
	}
	else
		cout << "查无此人！" << endl;
	system("pause");
	system("cls");
	showMenu();
}

void modifyMenu(addressBooks* abs)
{
	cout << "请输入要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret;
	ret = isExist(abs, name);
	if (ret != -1)
	{
		int judge = 1;
		while (judge)
		{
			cout << "您要修改该联系人的信息是：" << endl;
			string infor;
			cin >> infor;
			if (infor == "性别")
			{
				cout << "填写提示：1--男/2--女" << endl;
				cout << name << "的性别需要改为：" << endl;
				int change_one;
				cin >> change_one;
				abs->personArray[ret].sex = change_one;
				cout << "修改完毕！是否继续修改？" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "是")
					judge = 1;
				else
					judge = 0;
			}
			else if (infor == "年龄")
			{
				cout << name << "的年龄需要改为：" << endl;
				int change_two;
				cin >> change_two;
				abs->personArray[ret].age = change_two;
				cout << "修改完毕！是否继续修改？" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "是")
					judge = 1;
				else
					judge = 0;
			}
			else if (infor == "电话")
			{
				cout << name << "的电话需要改为：" << endl;
				string change_three;
				cin >> change_three;
				abs->personArray[ret].phone = change_three;
				cout << "修改完毕！是否继续修改？" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "是")
					judge = 1;
				else
					judge = 0;
			}
			else if (infor == "地址")
			{
				cout << name << "的地址需要改为：" << endl;
				string change_four;
				cin >> change_four;
				abs->personArray[ret].address = change_four;
				cout << "修改完毕！是否继续修改？" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "是")
					judge = 1;
				else
					judge = 0;
			}
			else if (infor == "姓名")
			{
				cout << "此功能不能修改联系人的姓名!" << endl;
				cout << "是否继续修改？" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "是")
					judge = 1;
				else
					judge = 0;
			}
			else
			{
				cout << "修改无效" << endl;
				cout << "是否继续修改？" << endl;
				string answer_one;
				cin >> answer_one;
				if (answer_one == "是")
					judge = 1;
				else
					judge = 0;
			}
		}
	}
	else
		cout << "查无此人！" << endl;
	system("pause");
	system("cls");
	showMenu();
}

void clearMenu(addressBooks* abs)
{
	abs->size = 0;
	cout << "通讯录已清空！" << endl;
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