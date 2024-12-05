#include "SortString.h"
#include "ui_SortString.h"

void f(QString& str){
    str = str.replace("\"","");
    str = str.replace("[","");
    str = str.replace("]","");
    QStringList strList = str.split(',');
    for(auto& s:strList){
        s = s.trimmed();
    }
    std::sort(strList.begin(),strList.end());
    str = strList.join('\n');
}
SortString::SortString(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortString)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QString str1 = ui->textEdit1->toPlainText();
        QString str2 = ui->textEdit2->toPlainText();
        f(str1);
        f(str2);
        ui->textEdit1->setText(str1);
        ui->textEdit2->setText(str2);
    });
}

SortString::~SortString()
{
    delete ui;
}
