#include "NineButtons.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
QString flip(const QString& s){
    if(s == "0") return "1";
    return "0";
}
NineButtons::NineButtons(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(160,160);
    auto* edit = new QLineEdit("1,0,0,0,0,0,0,0,0");
    auto* set = new QPushButton("init");
    set->setFixedWidth(40);
    auto* topLayout = new QHBoxLayout;
    topLayout->setContentsMargins(0,0,0,0);
    topLayout->setSpacing(0);
    topLayout->addWidget(edit);
    topLayout->addWidget(set);


    auto* btn0 = new QPushButton("1");
    auto* btn1 = new QPushButton("0");
    auto* btn2 = new QPushButton("0");
    auto* btn10 = new QPushButton("0");
    auto* btn11 = new QPushButton("0");
    auto* btn12 = new QPushButton("0");
    auto* btn20 = new QPushButton("0");
    auto* btn21 = new QPushButton("0");
    auto* btn22 = new QPushButton("0");

    auto btnList = QList<QPushButton*>{btn0,btn1,btn2,btn10,btn11,btn12,btn20,btn21,btn22};
    for(auto* p:btnList){
        p->setFixedSize(40,40);
        p->setFont(QFont("Microsoft YaHei",24,2));
    }

    auto* gridLayout = new QGridLayout;
    gridLayout->setContentsMargins(0,0,0,0);
    gridLayout->setSpacing(0);
    gridLayout->addWidget(btn0,0,0);
    gridLayout->addWidget(btn1,0,1);
    gridLayout->addWidget(btn2,0,2);
    gridLayout->addWidget(btn10,1,0);
    gridLayout->addWidget(btn11,1,1);
    gridLayout->addWidget(btn12,1,2);
    gridLayout->addWidget(btn20,2,0);
    gridLayout->addWidget(btn21,2,1);
    gridLayout->addWidget(btn22,2,2);

    auto* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(gridLayout);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    setLayout(mainLayout);

    connect(set,&QPushButton::clicked,this,[=](){
        auto strList = edit->text().split(',');
        btn0->setText(strList[0]);
        btn1->setText(strList[1]);
        btn2->setText(strList[2]);
        btn10->setText(strList[3]);
        btn11->setText(strList[4]);
        btn12->setText(strList[5]);
        btn20->setText(strList[6]);
        btn21->setText(strList[7]);
        btn22->setText(strList[8]);
    });
    connect(btn0,&QPushButton::clicked,this,[=](){
        btn0->setText(flip(btn0->text()));
        btn1->setText(flip(btn1->text()));
        btn10->setText(flip(btn10->text()));
    });
    connect(btn1,&QPushButton::clicked,this,[=](){
        btn1->setText(flip(btn1->text()));
        btn0->setText(flip(btn0->text()));
        btn2->setText(flip(btn2->text()));
        btn11->setText(flip(btn11->text()));
    });
    connect(btn2,&QPushButton::clicked,this,[=](){
        btn2->setText(flip(btn2->text()));
        btn1->setText(flip(btn1->text()));
        btn12->setText(flip(btn12->text()));
    });
    connect(btn10,&QPushButton::clicked,this,[=](){
        btn10->setText(flip(btn10->text()));
        btn20->setText(flip(btn20->text()));
        btn0->setText(flip(btn0->text()));
        btn11->setText(flip(btn11->text()));
    });
    connect(btn11,&QPushButton::clicked,this,[=](){
        btn11->setText(flip(btn11->text()));
        btn1->setText(flip(btn1->text()));
        btn21->setText(flip(btn21->text()));
        btn10->setText(flip(btn10->text()));
        btn12->setText(flip(btn12->text()));
    });
    connect(btn12,&QPushButton::clicked,this,[=](){
        btn12->setText(flip(btn12->text()));
        btn11->setText(flip(btn11->text()));
        btn2->setText(flip(btn2->text()));
        btn22->setText(flip(btn22->text()));
    });
    connect(btn20,&QPushButton::clicked,this,[=](){
        btn20->setText(flip(btn20->text()));
        btn10->setText(flip(btn10->text()));
        btn21->setText(flip(btn21->text()));
    });
    connect(btn21,&QPushButton::clicked,this,[=](){
        btn21->setText(flip(btn21->text()));
        btn20->setText(flip(btn20->text()));
        btn22->setText(flip(btn22->text()));
        btn11->setText(flip(btn11->text()));
    });
    connect(btn22,&QPushButton::clicked,this,[=](){
        btn22->setText(flip(btn22->text()));
        btn21->setText(flip(btn21->text()));
        btn12->setText(flip(btn12->text()));
    });

}
