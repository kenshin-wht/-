#include<iostream>
#include<ctime>
#include<string>
using namespace std;

	//cout << "hello world" << endl;
	/*int arr[5] = {};
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}*/
	
	/*案例1
	学校正在做毕业设计项目，每名老师带领5个学生，总共有3名老师，需求如下：设计学生和老师的结构体，
	其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员，学生的成员有姓名，考试分数，
	创建数组存放3名老师，通过函数给每个老师及所带的学生赋值，最终打印出老师数据以及老师所带学生数据
	*/
	/*
	分析：
	先构建两个结构体，嵌套
	再创建数组及赋值函数
	最后创建打印函数
	*/
	struct student {
		string stdname;
		int score;
	};

	struct teacher {
		string tecname;
		struct student stuarry[5];
	};

	void name(teacher tecarry[], int length)
	{
		string name_seed = { "ABCDEF" };
		for (int i = 0; i < length; i++)
		{
			//tecarry[i].tecname = "teacher_" + name_seed[i];
			tecarry[i].tecname = "teacher_";
			tecarry[i].tecname += name_seed[i];
			for (int j = 0; j < 5; j++)
			{
				//tecarry[i].stuarry[j].stdname = "student_" + name_seed[j];
				tecarry[i].stuarry[j].stdname = "student_";
				tecarry[i].stuarry[j].stdname+= name_seed[j];
				//	srand((unsigned int)time(NULL));
				int num =rand() % 61+40;
				tecarry[i].stuarry[j].score = num;
			}
		}
		
	}

	void stprint(teacher tecarry[], int length)
	{
		for (int i = 0; i < length; i++)
		{
			cout << "老师姓名:" << tecarry[i].tecname << endl
				<< "所带学生的信息:" << endl;
			for(int j=0;j<5;j++)
			{
				cout << "	学生姓名:" << tecarry[i].stuarry[j].stdname << "  学生分数:" <<
					tecarry[i].stuarry[j].score << endl;
			}

		}
		
	}

	int main2()
	{
		teacher tecarry1[3];
		srand((unsigned int)time(NULL));
		int length = sizeof(tecarry1) / sizeof(tecarry1[0]);
		name(tecarry1, length);
		stprint(tecarry1, length);
	system("pause");
	return 0;
}