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
        cout << "��ӭʹ��У԰������ϵͳ����ѡ��������ݣ�������ţ���" << endl;
        cout << "1��У԰������Ա" << endl;
        cout << "2: ѧ���û�" << endl;
        cout << "3: �˳�ϵͳ" << endl;
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
            cout << "��Ǹ���������Ч��" << endl;
            break;
        }

        
        cout << endl;
    } while (select!=3);

    cout << endl;
    cout << "���˳�ϵͳ��" << endl;

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
    cout << "����Ա���ã�";

    do
    {
        cout << endl;
        cout << "1: ����ѧ����Ϣ" << endl;
        cout << "2: ��������У԰��" << endl;
        cout << "3: У԰�����ת��" << endl;
        cout << "4: ע��У԰��" << endl;
        cout << "5: ɾ��ѧ����Ϣ" << endl;
        cout << "6: �˳�" << endl;
        cout << "��ѡ�������" << endl;
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
            cout << "��ѡ����Ч��" << endl;
            break;
        }

    } while (select != 6);
    return;
}
void CreateStudent()
{
    string name;
    int ID, department, major, grade, class_;

    cout << "\n������ѧ��ѧ�ţ�" << endl;
    cin >> ID;
    while (ID < 0 || ID >= MAX)
    {
        cout << "\nѧ�Ÿ�ʽ������������ȷ��ѧ�ţ�" << endl;
        cin >> ID;
    }
    if (students[ID] != NULL)
    {
        cout << "\n��ѧ����Ϣ�Ѵ��ڣ����������룺" << endl;
        return;
    }

    cout << endl;
    cout << "������ѧ��������" << endl;
    cin >> name;

    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << ": " << DEPARTMENT[i] << endl;
    }
    cout << "��ѡ��ѧ��Ժϵ��" << endl;
    cin >> department;

    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << ": " << MAJOR[i] << endl;
    }
    cout << "��ѡ��ѧ��רҵ��" << endl;
    cin >> major;

    cout << endl;
    cout << "������ѧ���꼶����ѧ��ݣ���" << endl;
    cin >> grade;

    cout << endl;
    cout << "������ѧ���༶��" << endl;
    cin >> class_;

    students[ID] = new Student(name, ID, department, major, grade, class_);

    return;
}
void CreateCard()
{

    int n = rand() % MAX, ID;
    while (cards[n] != NULL)
        n = rand() % MAX;

    cout << "\n������ѧ��ѧ�ţ�" << endl;
    cin >> ID;
        
    while (ID < 0 || ID >= MAX)
    {
        cout << "\nѧ�Ÿ�ʽ������������ȷ��ѧ�ţ�" << endl;
        cin >> ID;
    }
    if (students[ID] == NULL)
    {
        cout << "\nϵͳ�в����ڸ�ѧ����Ϣ��" << endl;
        return;
    }

    if (students[ID]->getCard() != NULL)
    {
        int select;
        cout << "��ѧ���Ѱ�У԰�� " << setfill('0') << setw(4) << students[ID]->getCard()->getNum() << " ���Ƿ����°�У԰����" << endl;
        cout << "1:��  2:��" << endl;
        cin >> select;
        if (select == 2)
            return;
    }

    cards[n] = new Card(n, students[ID]);       //�����¿�������Ϊ����ָ�������±�
    students[ID]->setCard(cards[n]);            //�����󶨸�ѧ��
    return;
}
void Transfer()
{
    int from, to;
    double amount;

    cout << "\n������ת���˻����ţ�" << endl;
    cin >> from;
    while (from < 0 || from >= MAX)
    {
        cout << "\n���Ÿ�ʽ�������������룺" << endl;
        cin >> from;
    }
    while (cards[from] == NULL)
    {
        cout << "\n���˻������ڣ����������룺" << endl;
        cin >> from;
    }

    cout << "\n������ת���˻����ţ�" << endl;
    cin >> to;
    while (to < 0 || to >= MAX)
    {
        cout << "\n���Ÿ�ʽ�������������룺" << endl;
        cin >> to;
    }
    while (cards[to] == NULL)
    {
        cout << "\n���˻������ڣ����������룺" << endl;
        cin >> to;
    }

    cout << "\n������ת�˽� 0 ~ " << cards[from]->getValue() << " ):" << endl;
    cin >> amount;
    while (amount < 0 && amount > cards[from]->getValue())
    {
        cout << "\nת�˽������ 0 ~ " << cards[from]->getValue() << " �ڣ�����������" << endl;
        cin >> amount;
    }

    cards[from]->minus(amount);
    cards[to]->add(amount);
    //������
    cout << "\nת�˳ɹ���\nת���˻�" << from << "��ʣ��" << cards[from]->getValue() << endl;
    cout << "ת���˻�" << to << "��ʣ��" << cards[to]->getValue() << endl;
    return;
}
void DeleteCard()
{
    int num;
    cout << "\n�����뿨�ţ�" << endl;
    cin >> num;
    while (num < 0 || num >= MAX)
    {
        cout << "\n���Ÿ�ʽ�������������룺" << endl;
        cin >> num;
    }
    if (cards[num] == NULL)
    {
        cout << "\n���˻������ڣ�" << endl;
        return;
    }
    delete cards[num];
    cards[num] = NULL;

    cout << endl;
    cout << "�ɹ�ע����У԰����" << endl;
    return;
}
void DeleteStudent()
{
    int ID;
    cout << "\n�����뽫Ҫɾ����ѧ��ѧ�ţ�" << endl;
    cin >> ID;

    while (ID < 0 || ID >= MAX)
    {
        cout << "\nѧ�Ÿ�ʽ������������ȷ��ѧ�ţ�" << endl;
        cin >> ID;
    }

    if (students[ID] == NULL)
    {
        cout << "\n��ѧ����Ϣ��ϵͳ�в����ڣ�" << endl;
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
    cout << "\nͬѧ���ã�";
    cout << "����������ѧ�ţ�" << endl;
    cin >> ID;
    while (ID < 0 || ID >= MAX)
    {
        cout << "\nѧ�Ÿ�ʽ������������ȷ��ѧ�ţ�" << endl;
        cin >> ID;
    }

    while (students[ID] == NULL)
    {
        cout << "\nѧ���������������룺" << endl;
        cin >> ID;
    }

    if (students[ID]->getCard()->getState() == OFF)
    {
        cout << "����У԰����δ����Ƿ񼤻�У԰����\n����1�������0�˳���" << endl;
        cin >> select;
        if (select)
            students[ID]->Activate();
        else
            return;
    }

    do
    {

        cout << endl;
        cout << "1: �鿴У԰����Ϣ" << endl;
        cout << "2: ��ֵУ԰��" << endl;
        cout << "3: ����" << endl;
        cout << "4: ��ʧ����" << endl;
        cout << "5: �˳�" << endl;
        cout << "��ѡ�������" << endl;
        cin >> select;

        switch (select)
        {
            case 1:students[ID]->Check();
                break;
            case 2:if(students[ID]->getCard()->getState()==LOST){
                    cout << endl;
                    cout << "�˿����ڹ�ʧ״̬�޷���ֵ��" << endl;
                    }
                    else
                    students[ID]->Charge();
                    break;
            case 3:if(students[ID]->getCard()->getState()==LOST){
                    cout << endl;
                    cout << "�˿����ڹ�ʧ״̬�޷��������ѣ�" << endl;
                    }                                                              //��У԰�����ڹ�ʧ״̬ʱ�޷����г�ֵ������
                    else
                    students[ID]->Consume();
                    break;
            case 4:if (students[ID]->getCard()->isChecked())
                    students[ID]->Loss();
                break;
            case 5:
                break;
            default:
            cout << "��ѡ����Ч��" << endl;
                break;
        }

    } while (select != 5);

    return;
}

