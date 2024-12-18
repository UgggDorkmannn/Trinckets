#include "SearchPanel.h"
#include "ui_SearchPanel.h"

SearchPanel::SearchPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchPanel)
{
    ui->setupUi(this);
    connect(ui->lineEdit,&QLineEdit::returnPressed,this,[&](){
        emit searchRequest();
        this->hide();
    });
}
QString SearchPanel::target()const{
    return ui->lineEdit->text().trimmed();
}
SearchPanel::~SearchPanel()
{
    delete ui;
}
