#include<iostream>
#include<ctime>
#include<string>
using namespace std;

	//cout << "hello world" << endl;
	/*int arr[5] = {};
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}*/
	
	/*����1
	ѧУ��������ҵ�����Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ���������£����ѧ������ʦ�Ľṹ�壬
	��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա��ѧ���ĳ�Ա�����������Է�����
	����������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ�����մ�ӡ����ʦ�����Լ���ʦ����ѧ������
	*/
	/*
	������
	�ȹ��������ṹ�壬Ƕ��
	�ٴ������鼰��ֵ����
	��󴴽���ӡ����
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
			cout << "��ʦ����:" << tecarry[i].tecname << endl
				<< "����ѧ������Ϣ:" << endl;
			for(int j=0;j<5;j++)
			{
				cout << "	ѧ������:" << tecarry[i].stuarry[j].stdname << "  ѧ������:" <<
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