#include "MergeColumns.h"
#include "ui_MergeColumns.h"

MergeColumns::MergeColumns(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MergeColumns)
{
    ui->setupUi(this);
    connect(ui->merge,&QPushButton::clicked,this,[&](){
        QStringList strList = ui->textEditRes->toPlainText().split('\n');
        QStringList sufList = ui->textEditSuffix->toPlainText().split('\n');
        int N = std::min(strList.size() , sufList.size());
        for(int i = 0;i < N;i++){
            strList[i] += "    " + sufList[i];
        }
        QString res = strList.join('\n');
        ui->textEditRes->setText(res);
    });
}

MergeColumns::~MergeColumns()
{
    delete ui;
}
