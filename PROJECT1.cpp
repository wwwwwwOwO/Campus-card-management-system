#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
//#include "Student.cpp"
#include "Student.hpp"
//#include "Card.cpp"
#include "Card.hpp"

#define MAX 10000
using namespace std;

void ManagerFunction();
void StudentFunction();

Student *students[MAX] = {NULL};
Card *cards[MAX] = {NULL};

int main()
{
    int select;
    do
    {
        cout << "欢迎使用校园卡管理系统！请选择您的身份（输入序号）：" << endl;
        cout << "1：校园卡管理员" << endl;
        cout << "2: 学生用户" << endl;
        cout << "3: 退出系统" << endl;
        cin >> select;

        switch (select)
        {
        case 1:
            ManagerFunction();
            break;
        case 2:
            StudentFunction();
            break;
        case 3:
            break;
        default:
            cout << "抱歉，该身份无效！" << endl;
            break;
        }

        
        cout << endl;
    } while (select!=3);

    cout << endl;
    cout << "已退出系统！" << endl;

    for (int i = 0; i < MAX;i++){
        if(students[i]!=NULL)
            delete students[i];
        if(cards[i]!=NULL)
            delete cards[i];
    }
    //system("pause");
    return 0;
}

void ManagerFunction()
{
    void CreateStudent();
    void CreateCard();
    void Transfer();
    void DeleteCard();
    void DeleteStudent();
    int select;
    cout << endl;
    cout << "管理员您好！";

    do
    {
        cout << endl;
        cout << "1: 导入学生信息" << endl;
        cout << "2: 创建并绑定校园卡" << endl;
        cout << "3: 校园卡余额转账" << endl;
        cout << "4: 注销校园卡" << endl;
        cout << "5: 删除学生信息" << endl;
        cout << "6: 退出" << endl;
        cout << "请选择操作：" << endl;
        cin >> select;

        switch (select)
        {
        case 1:
            CreateStudent();
            break;
        case 2:
            CreateCard();
            break;
        case 3:
            Transfer();
            break;
        case 4:
            DeleteCard();
            break;
        case 5:
            DeleteStudent();
            break;
        case 6:
            break;
        default:
            cout << endl;
            cout << "该选项无效！" << endl;
            break;
        }

    } while (select != 6);
    return;
}
void CreateStudent()
{
    string name;
    int ID, department, major, grade, class_;

    cout << "\n请输入学生学号：" << endl;
    cin >> ID;
    while (ID < 0 || ID >= MAX)
    {
        cout << "\n学号格式错误！请输入正确的学号：" << endl;
        cin >> ID;
    }
    if (students[ID] != NULL)
    {
        cout << "\n该学生信息已存在！请重新输入：" << endl;
        return;
    }

    cout << endl;
    cout << "请输入学生姓名：" << endl;
    cin >> name;

    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << ": " << DEPARTMENT[i] << endl;
    }
    cout << "请选择学生院系：" << endl;
    cin >> department;

    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << ": " << MAJOR[i] << endl;
    }
    cout << "请选择学生专业：" << endl;
    cin >> major;

    cout << endl;
    cout << "请输入学生年级（入学年份）：" << endl;
    cin >> grade;

    cout << endl;
    cout << "请输入学生班级：" << endl;
    cin >> class_;

    students[ID] = new Student(name, ID, department, major, grade, class_);

    return;
}
void CreateCard()
{

    int n = rand() % MAX, ID;
    while (cards[n] != NULL)
        n = rand() % MAX;

    cout << "\n请输入学生学号：" << endl;
    cin >> ID;
        
    while (ID < 0 || ID >= MAX)
    {
        cout << "\n学号格式错误！请输入正确的学号：" << endl;
        cin >> ID;
    }
    if (students[ID] == NULL)
    {
        cout << "\n系统中不存在该学生信息！" << endl;
        return;
    }

    if (students[ID]->getCard() != NULL)
    {
        int select;
        cout << "该学生已绑定校园卡 " << setfill('0') << setw(4) << students[ID]->getCard()->getNum() << " ，是否重新绑定校园卡？" << endl;
        cout << "1:是  2:否" << endl;
        cin >> select;
        if (select == 2)
            return;
    }

    cards[n] = new Card(n, students[ID]);       //创建新卡，卡号为卡的指针数组下标
    students[ID]->setCard(cards[n]);            //将卡绑定给学生
    return;
}
void Transfer()
{
    int from, to;
    double amount;

    cout << "\n请输入转出账户卡号：" << endl;
    cin >> from;
    while (from < 0 || from >= MAX)
    {
        cout << "\n卡号格式有误！请重新输入：" << endl;
        cin >> from;
    }
    while (cards[from] == NULL)
    {
        cout << "\n该账户不存在！请重新输入：" << endl;
        cin >> from;
    }

    cout << "\n请输入转出账户卡号：" << endl;
    cin >> to;
    while (to < 0 || to >= MAX)
    {
        cout << "\n卡号格式有误！请重新输入：" << endl;
        cin >> to;
    }
    while (cards[to] == NULL)
    {
        cout << "\n该账户不存在！请重新输入：" << endl;
        cin >> to;
    }

    cout << "\n请输入转账金额（ 0 ~ " << cards[from]->getValue() << " ):" << endl;
    cin >> amount;
    while (amount < 0 && amount > cards[from]->getValue())
    {
        cout << "\n转账金额需在 0 ~ " << cards[from]->getValue() << " 内：请重新输入" << endl;
        cin >> amount;
    }

    cards[from]->minus(amount);
    cards[to]->add(amount);
    //输出结果
    cout << "\n转账成功！\n转出账户" << from << "所剩余额：" << cards[from]->getValue() << endl;
    cout << "转入账户" << to << "所剩余额：" << cards[to]->getValue() << endl;
    return;
}
void DeleteCard()
{
    int num;
    cout << "\n请输入卡号：" << endl;
    cin >> num;
    while (num < 0 || num >= MAX)
    {
        cout << "\n卡号格式有误！请重新输入：" << endl;
        cin >> num;
    }
    if (cards[num] == NULL)
    {
        cout << "\n该账户不存在！" << endl;
        return;
    }
    delete cards[num];
    cards[num] = NULL;

    cout << endl;
    cout << "成功注销该校园卡！" << endl;
    return;
}
void DeleteStudent()
{
    int ID;
    cout << "\n请输入将要删除的学生学号：" << endl;
    cin >> ID;

    while (ID < 0 || ID >= MAX)
    {
        cout << "\n学号格式错误！请输入正确的学号：" << endl;
        cin >> ID;
    }

    if (students[ID] == NULL)
    {
        cout << "\n该学生信息在系统中不存在！" << endl;
        return;
    }

    if (students[ID]->getCard() != NULL)
    {
        cards[students[ID]->getCard()->getNum()] = NULL;
        delete students[ID]->getCard();
    }
    delete students[ID];
    students[ID] = NULL;
    return;
}
void StudentFunction()
{
    int select, ID;
    cout << "\n同学您好！";
    cout << "请输入您的学号：" << endl;
    cin >> ID;
    while (ID < 0 || ID >= MAX)
    {
        cout << "\n学号格式错误！请输入正确的学号：" << endl;
        cin >> ID;
    }

    while (students[ID] == NULL)
    {
        cout << "\n学号有误！请重新输入：" << endl;
        cin >> ID;
    }

    if (students[ID]->getCard()->getState() == OFF)
    {
        cout << "您的校园卡尚未激活，是否激活校园卡？\n输入1激活，输入0退出：" << endl;
        cin >> select;
        if (select)
            students[ID]->Activate();
        else
            return;
    }

    do
    {

        cout << endl;
        cout << "1: 查看校园卡信息" << endl;
        cout << "2: 充值校园卡" << endl;
        cout << "3: 消费" << endl;
        cout << "4: 挂失与解挂" << endl;
        cout << "5: 退出" << endl;
        cout << "请选择操作：" << endl;
        cin >> select;

        switch (select)
        {
            case 1:students[ID]->Check();
                break;
            case 2:if(students[ID]->getCard()->getState()==LOST){
                    cout << endl;
                    cout << "此卡处于挂失状态无法充值！" << endl;
                    }
                    else
                    students[ID]->Charge();
                    break;
            case 3:if(students[ID]->getCard()->getState()==LOST){
                    cout << endl;
                    cout << "此卡处于挂失状态无法进行消费！" << endl;
                    }                                                              //当校园卡处于挂失状态时无法进行充值和消费
                    else
                    students[ID]->Consume();
                    break;
            case 4:if (students[ID]->getCard()->isChecked())
                    students[ID]->Loss();
                break;
            case 5:
                break;
            default:
            cout << "该选项无效！" << endl;
                break;
        }

    } while (select != 5);

    return;
}

