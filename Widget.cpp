#include "Widget.h"
#include "ui_Widget.h"
#include <QClipboard>
#include <QApplication>
#include "NineButtons.h"
#include "SortString.h"
#include "SpotsDialog.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        auto str = ui->textEdit->toPlainText();
        str = str.replace("[" , "{");
        str = str.replace("]" , "}");
        str = str.replace("\'" , "\"");
        ui->textEdit->setText(str);
        QApplication::clipboard()->setText(str);
    });
    ui->lineEditCmd->setText("SpotsOnXY");
    connect(ui->lineEditCmd,&QLineEdit::returnPressed,this,[=](){
        QString cmd = ui->lineEditCmd->text().trimmed();
        if(cmd == "help"){
            ui->textEdit->setText("9buttons");
            ui->textEdit->append("sortString");
            ui->textEdit->append("SpotsOnXY");
        }
        else if(cmd == "9buttons"){
            auto* w = new NineButtons;
            w->show();
        }
        else if(cmd == "sortString"){
            auto* w = new SortString;
            w->exec();
        }
        else if(cmd == "SpotsOnXY"){
            auto* w = new SpotsDialog;
            w->setScale(50);
            std::vector<std::pair<int,int>> posList{{3,0},{4,0},{5,0},{6,1},{7,2},{7,3},{7,4},{6,5},{5,5},{4,5},{3,5},{2,5},{1,4},{1,3},{1,2},{2,1},{4,2},{0,3}};
            w->draw(posList);
            w->show();

        }
    });
}

Widget::~Widget()
{
    delete ui;
}
