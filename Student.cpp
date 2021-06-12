#include <iostream>
#include "Student.hpp"
#include "Card.hpp"
using namespace std;
Student::Student(string Name_, int ID_,int Department_, int Major_, int Grade_, int Class_):Name(Name_), ID(ID_), Department(Department_), Major(Major_), Grade(Grade_), Class(Class_){
    card = NULL;
    cout << endl;
    cout << "成功导入学生信息！" << endl;
    cout << "学号：" << setfill('0') << setw(4) << getID() << "        姓名：" << getName() << endl;
    cout << "院系专业：" << DEPARTMENT[Department - 1] << MAJOR[Major - 1] << endl;
    cout << "年级班级：" << getGrade() << "级" << getClass() << "班" << endl;
}

void Student::setCard(Card* newcard){
    card = newcard;
    return;
}

void Student::Check(){
    cout << "———————————卡片信息———————————" << endl;
    cout << "    卡号：" << setfill('0') << setw(4) << card->getNum() << endl;
    cout << "    状态: " << STATE[card->getState()] << endl;
    cout << endl;
    cout << "    姓名：" << getName() << "        学号：" << setfill('0') << setw(4) << getID() <<  endl;
    cout << "    院系专业：" << DEPARTMENT[Department - 1] << MAJOR[Major - 1] <<  endl;
    cout << "    年级班级：" << getGrade() << "级" << getClass() << "班" << endl;
    cout << "———————————卡片信息———————————" << endl;

    int select;
    do{
        cout << endl;
        cout << "1: 查询余额" << endl;
        cout << "2: 热水账户" << endl;
        cout << "3: 充值记录" << endl;
        cout << "4: 消费记录" << endl;
        cout << "5: 热水使用记录" << endl;
        cout << "6: 退出" << endl;
        cout << "请选择：" << endl;
        cin >> select;

            switch(select){
                case 1:
                    cout << "余额：" << card->getValue() << endl;
                    break;
                case 2:
                    cout << "热水账户余额：" << card->getWaterAccount() << endl;
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
                    cout << "该选项无效！" << endl;
                    break;
            }

    } while (select!=6);

    return;
}

void Student::Activate(){
    string newPassword;
    if(card->isChecked()){
        cout << "请输入新密码（6位数可包含数字、字母、下划线）：" << endl;
        cin >> newPassword;
        card->setPassword(newPassword);

        card->setState(ON);

        cout << endl;
        cout << "成功激活校园卡！" << endl;
        cout << "卡号：" << setfill('0') << setw(4) << card->getNum() << endl;
        cout << "状态: " << STATE[card->getState()] << endl;
    }
    else{
        cout << "激活校园卡失败！" << endl;
    }

    return;
}

void Student::Charge(){
    int select;
    do{
        cout << endl;
        cout << "1: 余额充值" << endl;
        cout << "2: 热水账户充值" << endl;
        cout << "3: 退出" << endl;
        cout << "请选择：" << endl;

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

    cout << "请输入充值金额（100~500）：" << endl;
    cin >> amount;
    while(amount<100|amount>500){
        cout << endl;
        cout << "充值限额为100~500，请重新输入：" << endl;
        cin >> amount;
    }
    card->add(amount);
    card->recordCharge(new ChargeRecord(amount));

    cout << "卡号：" << setfill('0') << setw(4) << card->getNum() << endl;
    cout << "余额：" << card->getValue() << " 元" << endl;
    return;
}

void Student::ChargeWater(){
    double amount;
    cout << endl;

    cout << "请输入充值金额（1~20）：" << endl;
    cin >> amount;
    while(amount<1|amount>20){
        cout << endl;
        cout << "充值限额为1~20，请重新输入：" << endl;
        cin >> amount;
    }
    card->addWater(amount);
    card->recordCharge(new ChargeRecord(amount));

    cout << "卡号：" << setfill('0') << setw(4) << card->getNum() << endl;
    cout << "热水账户余额：" << card->getWaterAccount() << " 元" << endl;
    return;
}


void Student::Consume(){

    int select, time;
    double amount;
    
    do{
        cout << endl;
        cout << "1：饭堂超市消费" << endl;
        cout << "2：热水消费" << endl;
        cout << "3：退出" << endl;
        cout << "请选择：" << endl;
        cin >> select;
            switch(select){
                case 1:
                    cout << endl;
                    cout << "当前余额为：" << card->getValue() << " 元" << endl;
                    cout << "请输入消费金额：(限额为500元）" << endl;
                    cin >> amount;
                    if(amount > card->getValue())
                        cout << "校园卡余额不足！" << endl;
                    else if(amount<0||amount>500)
                        cout << "超出消费限额，消费失败!" << endl;
                    else{
                        card->minus(amount);
                        card->recordConsume(new ConsumeRecord(amount));
                        
                        cout << endl;
                        cout << "成功消费 " << amount << " 元！" << endl;
                        cout << "当前余额：" << card->getValue() << " 元" << endl;
                    }      
                    break;
                case 2:
                    cout << endl;
                    cout << "当前热水账户余额：" << card->getWaterAccount() << " 元" << endl;
                    cout << "水价：" << Rate << "元/分钟" << endl;
                    cout << "请输入使用热水时长（单位：分钟）：" << endl;
                    cin >> time;

                    if(time*Rate >card->getWaterAccount())
                        cout << "热水账户余额不足！" << endl;
                    else{
                        card->minusWater(time * Rate);
                        card->recordWater(new WaterRecord(time));
                        
                        cout << endl;
                        cout << "成功消费 " << time * Rate << " 元！" << endl;
                        cout << "当前热水账户余额：" << card->getWaterAccount() << " 元" << endl;
                    }   
                    break;
                case 3:
                    break;
                default:
                    cout << "该选项无效！" << endl;
                    break;
            }

    } while (select!=3);

    return;
}

void Student::Loss(){

    int select;
    do{
            cout<< endl;
            cout << "1：挂失校园卡" << endl;
            cout << "2：解挂校园卡" << endl;
            cout << "3：退出" << endl;
            cout << "请选择：" << endl;

            cin >> select;
            switch (select){

            case 1: if(card->getState() == LOST)
                    cout << "该卡已处于挂失状态，请勿重复操作！" << endl;
                    else{
                        card->setState(LOST);
                        cout << "挂失成功！" << endl;
                        cout << "校园卡：" << setfill('0') << setw(4) << card->getNum() << endl;
                        cout << "状态：" << STATE[card->getState()] << endl;
                    }
                    
                break;
            case 2: if(card->getState() !=LOST)
                        cout << "无法解挂！" << endl;
                    else{
                        card->setState(ON);
                        cout << "解挂成功！" << endl;
                        cout << "校园卡：" << setfill('0') << setw(4) << card->getNum() << endl;
                        cout << "状态：" << STATE[card->getState()] << endl;
                    }
                        
                break;
            case 3:
                break;
            default:
                cout << "该选项无效！" << endl;
                break;

            };
    } while (select != 3);


    return;
}
