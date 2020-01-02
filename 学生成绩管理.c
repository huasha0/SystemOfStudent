#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct stu
{
	int num;
	char name[20];
	char sex[5];
	float score1, score2, score3, score4, score5, sum, aver;
	struct stu *next;
}Student;

void menu()
{
	printf("\n");
	printf("\t\t********************************\n");
	printf("\t\t\t学生成绩管理系统\n");
	printf("\t\t********************************\n");
	printf("\t\t\t1.学生输入\n");
	printf("\t\t\t2.学生插入\n");
	printf("\t\t\t3.学生删除\n");
	printf("\t\t\t4.修改信息\n");
	printf("\t\t\t5.学生查询\n");
	printf("\t\t\t6.学生输出\n");
	printf("\t\t\t7.按总分排序\n");
	printf("\t\t\t8.按学号排序\n");
	printf("\t\t\t9.计算每科的平均分并输出低于平均分的学生\n");
	printf("\t\t\t10.显示90分以上的同学及不及格同学\n");
	printf("\t\t\t0.退出系统\n");
}

void input() //录入和插入学生成绩信息并写入文件中（存在问题，无法结束学生信息输入循环，无法写入文件） 
{
	FILE *fp;
	Student *person, *p, *head = NULL, *temp;
	int num, flag, count = 0;
	char c;
	
	if ((fp=fopen("data.txt", "a"))== NULL) //开文件 
	{
		printf("ERROR...");
		exit ;
	}
//	p = (Student *)malloc(sizeof(Student));
	p = NULL;
	do //循环输入学生信息到链表中 
	{
//		num = 0;
		person = (Student *)malloc(sizeof(Student)); //开辟两个空间，p与person的初始位置相同 
		count++; //添加的学生的个数随着循环的增加而增加 
		flag = 1; //判断学生是否已经存在的临时变量 
		printf("\t\t请输入要加入的学生的学号：\n\t\t");
		scanf("%d", &num);
		while(fscanf(fp, "%d %s %s %f %f %f %f %f %f %f", &head->num, head->name, head->sex, &head->score1, &head->score2,
			&head->score3, &head->score4, &head->score5, &head->sum, &head->aver) == 10) //判断文件中是否已经存在该学生的信息 
		{
			if (temp->num == num)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			printf("该学生信息已存在...请重新输入...");
			printf("\t\t是否继续输入?(Y/N): ");
		    scanf("%*c%c", &c);
		    if(c == 'N' || c == 'n')
				break;
		}
		person->num = num; //将num的值给person->num
		printf("\t\t请输入学生的姓名:               \n\t\t");
	    scanf("%s", person->name); 
	    printf("\t\t请输入学生的性别:               \n\t\t");
	    scanf("%s", person->sex); 
	    printf("\t\t请输入学生的成绩1:             \n\t\t"); 
	    scanf("%f", &person->score1); 
	    printf("\t\t请输入学生的成绩2:               \n\t\t"); 
	    scanf("%f", &person->score2); 
	    printf("\t\t请输入学生的成绩3:               \n\t\t"); 
	    scanf("%f", &person->score3); 
	    printf("\t\t请输入学生的成绩4:               \n\t\t"); 
	    scanf("%f", &person->score4); 
	    printf("\t\t请输入学生的成绩5:               \n\t\t"); 
	    scanf("%f", &person->score5);
	    person->sum = person->score1 + person->score2 + person->score3 + person->score4 + person->score5; //计算五门课的总成绩 
	    person->aver = person->sum / 5; //求平均成绩 
	    if (count == 1) //当count=1的时候，head指向person，head也就成为了一个头结点（此时person是第一个节点） 
	    {
	    	head = person;
		}
		else //count!=1时，p->next指向person
		{
			p->next = person;
		}
		p = person; //将p的位置移到person，以上几行内容形成了一个链表 
	    printf("\t\t是否继续输入?(Y/N): ");
	    scanf("%*c%c", &c);
	}while(c == 'y' || c == 'Y');
	person->next = NULL; //结束循环之后p->next=NULL 
	while (head != NULL) //将链表中的内容依次写入文件中，其中head是整个链表的头 
	{
		fprintf(fp, "%d %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
			head->score3, head->score4, head->score5, head->sum, head->aver);
		head = head->next;
	}
	fclose(fp);
}

Student *readfile() //将文件中的信息读出并放到链表中（感觉是无法将文件中的数据块存到链表中） 
{
	FILE *fp;
	Student *head, *p1, *p2;
	int count = 0;
	
	if ((fp = fopen("data.txt", "r")) == NULL)
	{
		printf("ERROR...");
		exit ;
	}
//	head = (Student *)malloc(sizeof(Student));
	if (fgetc(fp)==EOF)//feof
	{
		return NULL;
	}
	else
	{
		fp = fopen("data.txt", "r");
	}
	p1 = (Student *)malloc(sizeof(Student)); //开辟结构体空间
//	p1 = NULL;
	head = p2 = p1;
	while (fscanf(fp, "%d %s %s %f %f %f %f %f %f %f", &p1->num, p1->name, p1->sex, &p1->score1, &p1->score2,
			&p1->score3, &p1->score4, &p1->score5, &p1->sum, &p1->aver) == 10) //从文件中读出内容到p1的时候循环 
	{	
		count++; //读出的学生信息的条数 
		if (count == 1) //当读出学生信息条数为1时，head移动到p1 
		{
			head = p1;
		}
		else //当读出学生信息条数不为1的时候，p2->next指向p1 
		{
			p2->next = p1;
		}
		p2 = p1; //将p2指针移动到p1的位置 

//		p2->next = p1;
//		p2 = p1;
		p1 = (Student *)malloc(sizeof(Student)); //为p1开辟结构体空间 
	}
	p2 ->next = NULL; //最后p2->next指向NULL
	
	fclose(fp);
	return head; //返回链表头head
}

void del() //删除学生信息操作 
{
	FILE *fp;
	Student *head, *p1, *p2, *p, *temp; //head是第一个节点(含值) 
	int num, count = 0;
	
	head = readfile(); //读出文件内容
	if ((fp=fopen("data.txt", "w")) == NULL)
	{
		printf("ERROR...");
		exit ;
	}
	p = p1 = p2 = head; //将p1、p2移动到head的位置
	p1 = p1->next; //p2始终在p1的后一位，p2是跟班指针
	printf("请输入要删除的学生的学号：");
	scanf("%d", &num);
	while (p2 != NULL) //当p2不为NULL的时候循环
	{
		count++;
		if (count == 1) //第一个节点时 
		{
			if (p2->num == num) //如果第一个节点就是要删除的，就直接删除 
			{
				temp = p2;
				head = p2->next;
				free(temp);
				break;
			}
			else //否则继续循环 
			{
				continue;
			}
		}
		else //不是第一个节点时 
		{
			if (p1->num == num) //如果找到要删除的节点，直接删除 
			{
				temp = p1;
				p2->next = p1->next;
				free(temp);
				break;
			}
			else //否则p1和p2向前移动 
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}
	}
	while (head != NULL)
	{
		fprintf(fp, "%d %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
			head->score3, head->score4, head->score5, head->sum, head->aver);
		head = head->next;
	}
	fclose(fp);
}

void mod() //修改学生信息操作 
{
	FILE *fp;
	char name[20], message[20];
	Student *head, *p;
	int num, snum;
	float grade;
	
	p = head = readfile(); //将文件中的数据块读入链表
	if ((fp=fopen("data.txt", "w")) == NULL)
	{
		printf("ERROR...");
		exit ;
	}
	printf("\t\t请输入需要修改信息的学生的姓名："); 
	scanf("%s", name);
	while (head != NULL)
	{
		if(strcmp(head->name, name) == 0) //找到需要修改信息的同学之后进行的操作 
		{
			printf("\t\t1.姓名\n");
			printf("\t\t2.性别\n");
			printf("\t\t3.学号\n");
			printf("\t\t4.score1\n");
			printf("\t\t5.score2\n");
			printf("\t\t6.score3\n");
			printf("\t\t7.score4\n");
			printf("\t\t8.score5\n");
			printf("\t\t请输入要修该的信息的序号(1-8)：");
			scanf("%d", &num);
			if (num < 1 || num > 8) //当num不再指令范围内的时候报错
			{
				printf("\t\tERROR...");
				break;
			}
			if (num >= 1 && num <= 2) //当num为1或2时，进行操作 
			{
				printf("\t\t请输入修改后的学生姓名或性别：");
				scanf("%s", message);
				switch (num)
				{
					case 1: strcpy(head->name, message); break;
					case 2: strcpy(head->sex, message); break;
				}
			}
			if(num == 3)
			{
				printf("\t\t请输入修改后的学生的学号：");
				scanf("%d", &snum);
				head->num = snum;
			}
			if(num >= 4 && num <= 8)
			{
				printf("\t\t请输入修改之后的学生的成绩：");
				scanf("%f", &grade);
				switch(num)
				{
					case 4: head->score1 = grade; break;
					case 5: head->score2 = grade; break;
					case 6: head->score3 = grade; break;
					case 7: head->score4 = grade; break;
					case 8: head->score5 = grade; break;
				}
			}
			printf("修改成功...");
			break;
		}
		else
		{
			printf("不存在该学生...");
			return ;
		}
		head = head->next;
	}
	while (p != NULL)
	{
		fprintf(fp, "%d %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", p->num, p->name, p->sex, p->score1, p->score2,
			p->score3, p->score4, p->score5, p->sum, p->aver);
		p = p->next;
	}
	fclose(fp);
}

void query() //查询学生信息
{
	Student *head;
	int num;
	
	head = readfile();
	printf("请输入需要查询的学生的学号：");
	scanf("%d", &num);
	if (head == NULL)
	{
		printf("没有找到学生成绩...");
		return ;
	}
	while (head != NULL)
	{
		if (head->num == num)
		{
			printf("%d %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f", head->num, head->name, head->sex, head->score1, head->score2,
				head->score3, head->score4, head->score5, head->sum, head->aver);
			break;
		}
		head = head->next;
	}
}

void allquery() //查询所有学生信息
{
	Student *head;
	int num;
	
	head = readfile();
	if (head == NULL)
	{
		printf("没有找到学生信息...");
		return ;
	}
	else
	{
		printf("学生信息如下：\n");
		printf("学号\t姓名\t性别\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5\t总成绩\t平均分\n");
		do
		{
			printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
				head->score3, head->score4, head->score5, head->sum, head->aver);
			head = head->next;
		}while(head != NULL);
	}
}

void sortoftotal() //按总分排序（判断节点数是否多于两个，如果少于两个的话，直接输出链表中的内容） 
{
	Student *head, *p1, *p2, temp;
	
	head = readfile();
	p1 = head;
	if (head == NULL)
	{
		printf("没有学生信息...");
		 return ;
	}
	if (p1->next == NULL)
	{
		printf("只有一个学生信息，不需排序...");
		return ;
	}
	while (p1->next != NULL)
	{
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (p1->sum > p2->sum)
			{
				temp = *p1;
				*p1 = *p2;
				*p2 = temp;
				temp.next = p1->next;
				p1->next = p2->next;
				p2->next = temp.next;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	printf("学生信息如下：\n");
	printf("学号\t姓名\t性别\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5\t总成绩\t平均分\n");
	while(head != NULL)
	{
		printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
			head->score3, head->score4, head->score5, head->sum, head->aver);
		head = head->next;
	}
}

void sortofnum() //按学号排序
{
	Student *head, *p1, *p2, temp;
	
	head = readfile();
	p1 = head;
	if (head == NULL)
	{
		printf("没有学生信息...");
		 return ;
	}
	if (p1->next == NULL)
	{
		printf("只有一个学生信息，不需排序...");
		return ;
	}
	while (p1->next != NULL)
	{
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (p1->num > p2->num)
			{
				temp = *p1;
				*p1 = *p2;
				*p2 = temp;
				temp.next = p1->next;
				p1->next = p2->next;
				p2->next = temp.next;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	printf("学生信息如下：\n");
	printf("学号\t姓名\t性别\t成绩1\t成绩2\t成绩3\t成绩4\t成绩5\t总成绩\t平均分\n");
	while(head != NULL)
	{
		printf("%d  %s  %s  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f  %.2f\n", head->num, head->name, head->sex, head->score1, head->score2,
			head->score3, head->score4, head->score5, head->sum, head->aver);
		head = head->next;
	}
}

void average() //计算各科平均分并输出低于平均分的同学 
{
	Student *head, *p1, *p2, *p3, *p4, *p5;
	float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	float aver1 = 0, aver2 = 0, aver3 = 0, aver4 = 0, aver5 = 0;
	int count = 0;
	
	head = p1 = p2 = p3 = p4 = p5 = readfile();
	while (head != NULL) //求各科平均分以及总分 
	{
		count++;
		sum1 += head->score1;
		sum2 += head->score2;
		sum3 += head->score3;
		sum4 += head->score4;
		sum5 += head->score5;
		head = head->next;
	}
	aver1 = sum1 / count;
	aver2 = sum2 / count;
	aver3 = sum3 / count;
	aver4 = sum4 / count;
	aver5 = sum5 / count;
	
	printf("\t\tscore1成绩低于平均分的同学有：\n");
	while (p1 != NULL)
	{
		if (p1->score1 < aver1)
		{
			printf("\t\t%d %s %s %f\n", p1->num, p1->name, p1->sex, p1->score1);
		}
		p1 = p1->next;
	}
	printf("\t\tscore2成绩低于平均分的同学有：\n");
	while (p2 != NULL)
	{
		if (p2->score2 < aver2)
		{
			printf("\t\t%d %s %s %f\n", p2->num, p2->name, p2->sex, p2->score1);
		}
		p2 = p2->next;
	}
	printf("\t\tscore3成绩低于平均分的同学有：\n");
	while (p3 != NULL)
	{
		if (p3->score3 < aver3)
		{
			printf("\t\t%d %s %s %f\n", p3->num, p3->name, p3->sex, p3->score1);
		}
		p3 = p3->next;
	}
	printf("\t\tscore4成绩低于平均分的同学有：\n");
	while (p4 != NULL)
	{
		if (p4->score4 < aver4)
		{
			printf("\t\t%d %s %s %f\n", p4->num, p4->name, p4->sex, p4->score1);
		}
		p4 = p4->next;
	}
	printf("\t\tscore5成绩低于平均分的同学有：\n");
	while (p5 != NULL)
	{
		if (p5->score5 < aver5)
		{
			printf("\t\t%d %s %s %f\n", p5->num, p5->name, p5->sex, p5->score1);
		}
		p5 = p5->next;
	}
}

void qua() //显示各科成绩低于60分以及高于90分的同学的成绩 
{
	Student *head, *p1, *p2, *p3, *p4, *p5;
	
	head = p1 = p2 = p3 = p4 = p5 = readfile();
	printf("\t\tscore1成绩低于60、高于90的同学有：\n");
	while (p1 != NULL)
	{
		if (p1->score1 < 60 || p1->score1 > 90)
		{
			printf("\t\t%d %s %s %f\n", p1->num, p1->name, p1->sex, p1->score1);
		}
		p1 = p1->next;
	}
	printf("\t\tscore2成绩低于60、高于90的同学有：\n");
	while (p2 != NULL)
	{
		if (p2->score2 < 60 || p2->score2 > 90)
		{
			printf("\t\t%d %s %s %f\n", p2->num, p2->name, p2->sex, p2->score1);
		}
		p2 = p2->next;
	}
	printf("\t\tscore3成绩低于60、高于90的同学有：\n");
	while (p3 != NULL)
	{
		if (p3->score3 < 60 || p3->score3 > 90)
		{
			printf("\t\t%d %s %s %f\n", p3->num, p3->name, p3->sex, p3->score1);
		}
		p3 = p3->next;
	}
	printf("\t\tscore4成绩低于60、高于90的同学有：\n");
	while (p4 != NULL)
	{
		if (p4->score4 < 60 || p4->score4 > 90)
		{
			printf("\t\t%d %s %s %f\n", p4->num, p4->name, p4->sex, p4->score1);
		}
		p4 = p4->next;
	}
	printf("\t\tscore5成绩低于60、高于90的同学有：\n");
	while (p5 != NULL)
	{
		if (p5->score5 < 60 || p5->score5 > 90)
		{
			printf("\t\t%d %s %s %f\n", p5->num, p5->name, p5->sex, p5->score1);
		}
		p5 = p5->next;
	}
}

int main()
{
	int num;
	
	while (1)
	{
		menu(); 
		printf("\t\t请输入正确的指令（0-10）：");
		scanf("%d", &num);
		system("cls");
		switch (num)
		{
			case 1:
			case 2: input(); break;
			case 3: del(); break;
			case 4: mod(); break;
			case 5: query(); break;
			case 6: allquery(); break;
			case 7: sortoftotal(); break;
			case 8: sortofnum(); break;
			case 9: average(); break;
			case 10: qua(); break;
			case 0: printf("\t\t谢谢使用..."); return 0;
			default: printf("\t\t无效指令..."); break;
		}
		printf("操作成功...");
//		sleep(3);
//		system("cls");
	}
	return 0;
}
