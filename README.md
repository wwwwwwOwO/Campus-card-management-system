#### 名称：校园卡管理系统

#### 功能：
##### 校园卡管理员功能

一、导入学生信息：向系统中导入学生信息（名字、学院、年级、班级、专业、学号）

1. 名字为字符串
2. 学院和专业根据提示信息选择
3. 年级即为学生的入学年份，班级为学生所在班级的序号
4. 学号需为0000~9999之间的数字


二、给在校生绑定校园卡（卡号，余额、充值记录、消费记录、校园卡状态、水控服务）

1. 校园卡卡号随机，生成时会确保卡号的唯一性
2. 初始使余额、热水账户为0，充值记录等为空，校园卡状态为未激活（OFF）
3. 校园卡的初始密码为000000



三、转移校园卡内的金额：学生本人申请办理新卡时，可将原账户的余额转移到新卡中

1. 具体操作为：办理新卡->绑定新卡->旧卡余额转移->删除旧卡
2. 转账时会确认转入账户和转出账户的有效性



四、注销校园卡：

1. 校园卡一经注销后无法使用。
2. 丢失校园卡后要重新办理的学生，需将原来绑定的校园卡注销后再办理新卡。


五、删除学生信息：

1. 当学生毕业或退学，管理员可将系统中的学生信息删除。
2. 删除的学生信息会连带他的校园卡一并从系统中清除。


##### 学生用户功能

该校园卡除了满足需求的功能外，还增加了热水卡的功能。

初次登录系统，若学生绑定的校园卡未激活将会提示完成校园卡的激活功能。

激活后校园卡可正常使用。


一、查看校园卡信息（卡号，余额、充值记录、消费记录、校园卡状态、水控服务）：

1. 选择此项功能时，会打印卡主信息，同时显示该校园卡的卡号和状态
2. 在选项中可选择查询余额、热水账户余额、充值记录等


二、激活校园卡：设置密码

1. 设置密码时需验证原始密码，原始密码为000000
2. 设置好的密码在挂失或解挂时需要验证


三、 充值校园卡：

1. 校园卡充值限额为100~500元，热水账户充值限额为1~20元
2. 充值超过或低于充值限额将会提示
3. 充值后需要输入充值的日期、时间、支付方式等以生成充值记录类


四、消费：

1. 学生可到食堂超市（第一饭堂、第二饭堂、第三饭堂、第四饭堂、行政楼餐厅、清真食堂、教育超市、快乐多超市）进行消费。可通过热水账户的金额使用热水（洗澡）。
2. 消费完成后会需输入相关信息以生成消费记录类


五、挂失与解挂：

1. 校园卡丢失后，学生可进行挂失，挂失后的校园卡无法充值或消费。
2. 若校园卡被找回，可进行解挂，解挂后校园卡可以继续使用。

