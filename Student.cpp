#include <iostream>
#include "Student.hpp"
#include "Card.hpp"
using namespace std;
Student::Student(string Name_, int ID_,int Department_, int Major_, int Grade_, int Class_):Name(Name_), ID(ID_), Department(Department_), Major(Major_), Grade(Grade_), Class(Class_){
    card = NULL;
    cout << endl;
    cout << "�ɹ�����ѧ����Ϣ��" << endl;
    cout << "ѧ�ţ�" << setfill('0') << setw(4) << getID() << "        ������" << getName() << endl;
    cout << "Ժϵרҵ��" << DEPARTMENT[Department - 1] << MAJOR[Major - 1] << endl;
    cout << "�꼶�༶��" << getGrade() << "��" << getClass() << "��" << endl;
}

void Student::setCard(Card* newcard){
    card = newcard;
    return;
}

void Student::Check(){
    cout << "������������������������Ƭ��Ϣ����������������������" << endl;
    cout << "    ���ţ�" << setfill('0') << setw(4) << card->getNum() << endl;
    cout << "    ״̬: " << STATE[card->getState()] << endl;
    cout << endl;
    cout << "    ������" << getName() << "        ѧ�ţ�" << setfill('0') << setw(4) << getID() <<  endl;
    cout << "    Ժϵרҵ��" << DEPARTMENT[Department - 1] << MAJOR[Major - 1] <<  endl;
    cout << "    �꼶�༶��" << getGrade() << "��" << getClass() << "��" << endl;
    cout << "������������������������Ƭ��Ϣ����������������������" << endl;

    int select;
    do{
        cout << endl;
        cout << "1: ��ѯ���" << endl;
        cout << "2: ��ˮ�˻�" << endl;
        cout << "3: ��ֵ��¼" << endl;
        cout << "4: ���Ѽ�¼" << endl;
        cout << "5: ��ˮʹ�ü�¼" << endl;
        cout << "6: �˳�" << endl;
        cout << "��ѡ��" << endl;
        cin >> select;

            switch(select){
                case 1:
                    cout << "��" << card->getValue() << endl;
                    break;
                case 2:
                    cout << "��ˮ�˻���" << card->getWaterAccount() << endl;
                    break;
                case 3:
                    card->printCharge();
                    break;
                case 4:
                    card->printConsume();
                    break;
                case 5:
                    card->printWater();
                    break;
                case 6:
                    break;
                default:
                    cout << "��ѡ����Ч��" << endl;
                    break;
            }

    } while (select!=6);

    return;
}

void Student::Activate(){
    string newPassword;
    if(card->isChecked()){
        cout << "�����������루6λ���ɰ������֡���ĸ���»��ߣ���" << endl;
        cin >> newPassword;
        card->setPassword(newPassword);

        card->setState(ON);

        cout << endl;
        cout << "�ɹ�����У԰����" << endl;
        cout << "���ţ�" << setfill('0') << setw(4) << card->getNum() << endl;
        cout << "״̬: " << STATE[card->getState()] << endl;
    }
    else{
        cout << "����У԰��ʧ�ܣ�" << endl;
    }

    return;
}

void Student::Charge(){
    int select;
    do{
        cout << endl;
        cout << "1: ����ֵ" << endl;
        cout << "2: ��ˮ�˻���ֵ" << endl;
        cout << "3: �˳�" << endl;
        cout << "��ѡ��" << endl;

        cin >> select;

        switch (select)
        {
        case 1:
            ChargeCard();
            break;
        case 2:
            ChargeWater();
            break;
        case 3:
            break;
        default:
            break;
    }
    } while (select != 3);

    return;
}
void Student::ChargeCard(){
    double amount;
    cout << endl;

    cout << "�������ֵ��100~500����" << endl;
    cin >> amount;
    while(amount<100|amount>500){
        cout << endl;
        cout << "��ֵ�޶�Ϊ100~500�����������룺" << endl;
        cin >> amount;
    }
    card->add(amount);
    card->recordCharge(new ChargeRecord(amount));

    cout << "���ţ�" << setfill('0') << setw(4) << card->getNum() << endl;
    cout << "��" << card->getValue() << " Ԫ" << endl;
    return;
}

void Student::ChargeWater(){
    double amount;
    cout << endl;

    cout << "�������ֵ��1~20����" << endl;
    cin >> amount;
    while(amount<1|amount>20){
        cout << endl;
        cout << "��ֵ�޶�Ϊ1~20�����������룺" << endl;
        cin >> amount;
    }
    card->addWater(amount);
    card->recordCharge(new ChargeRecord(amount));

    cout << "���ţ�" << setfill('0') << setw(4) << card->getNum() << endl;
    cout << "��ˮ�˻���" << card->getWaterAccount() << " Ԫ" << endl;
    return;
}


void Student::Consume(){

    int select, time;
    double amount;
    
    do{
        cout << endl;
        cout << "1�����ó�������" << endl;
        cout << "2����ˮ����" << endl;
        cout << "3���˳�" << endl;
        cout << "��ѡ��" << endl;
        cin >> select;
            switch(select){
                case 1:
                    cout << endl;
                    cout << "��ǰ���Ϊ��" << card->getValue() << " Ԫ" << endl;
                    cout << "���������ѽ�(�޶�Ϊ500Ԫ��" << endl;
                    cin >> amount;
                    if(amount > card->getValue())
                        cout << "У԰�����㣡" << endl;
                    else if(amount<0||amount>500)
                        cout << "���������޶����ʧ��!" << endl;
                    else{
                        card->minus(amount);
                        card->recordConsume(new ConsumeRecord(amount));
                        
                        cout << endl;
                        cout << "�ɹ����� " << amount << " Ԫ��" << endl;
                        cout << "��ǰ��" << card->getValue() << " Ԫ" << endl;
                    }      
                    break;
                case 2:
                    cout << endl;
                    cout << "��ǰ��ˮ�˻���" << card->getWaterAccount() << " Ԫ" << endl;
                    cout << "ˮ�ۣ�" << Rate << "Ԫ/����" << endl;
                    cout << "������ʹ����ˮʱ������λ�����ӣ���" << endl;
                    cin >> time;

                    if(time*Rate >card->getWaterAccount())
                        cout << "��ˮ�˻����㣡" << endl;
                    else{
                        card->minusWater(time * Rate);
                        card->recordWater(new WaterRecord(time));
                        
                        cout << endl;
                        cout << "�ɹ����� " << time * Rate << " Ԫ��" << endl;
                        cout << "��ǰ��ˮ�˻���" << card->getWaterAccount() << " Ԫ" << endl;
                    }   
                    break;
                case 3:
                    break;
                default:
                    cout << "��ѡ����Ч��" << endl;
                    break;
            }

    } while (select!=3);

    return;
}

void Student::Loss(){

    int select;
    do{
            cout<< endl;
            cout << "1����ʧУ԰��" << endl;
            cout << "2�����У԰��" << endl;
            cout << "3���˳�" << endl;
            cout << "��ѡ��" << endl;

            cin >> select;
            switch (select){

            case 1: if(card->getState() == LOST)
                    cout << "�ÿ��Ѵ��ڹ�ʧ״̬�������ظ�������" << endl;
                    else{
                        card->setState(LOST);
                        cout << "��ʧ�ɹ���" << endl;
                        cout << "У԰����" << setfill('0') << setw(4) << card->getNum() << endl;
                        cout << "״̬��" << STATE[card->getState()] << endl;
                    }
                    
                break;
            case 2: if(card->getState() !=LOST)
                        cout << "�޷���ң�" << endl;
                    else{
                        card->setState(ON);
                        cout << "��ҳɹ���" << endl;
                        cout << "У԰����" << setfill('0') << setw(4) << card->getNum() << endl;
                        cout << "״̬��" << STATE[card->getState()] << endl;
                    }
                        
                break;
            case 3:
                break;
            default:
                cout << "��ѡ����Ч��" << endl;
                break;

            };
    } while (select != 3);


    return;
}
