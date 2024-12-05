#include "SpotsDialog.h"
#include "ui_SpotsDialog.h"
#include <QPainter>
SpotsDialog::SpotsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpotsDialog)
{
    ui->setupUi(this);
    mScale = 32;
}

SpotsDialog::~SpotsDialog()
{
    delete ui;
}


void SpotsDialog::paintEvent(QPaintEvent* e){
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);


    p.setBrush(QBrush(QColor("black")));
    p.translate(0,height() - 50);
    for(auto& pos:mPosList){
        int x = pos.first * mScale;
        int y = pos.second * mScale;

        p.translate(x,y);
        p.drawEllipse(x,y,8,8);
        p.drawText(QPointF(x,y + 32),QString::number(x/mScale) + "," + QString::number(y/-mScale));
        p.translate(-x,-y);
    }
}
void SpotsDialog::setScale(int scale){
    mScale = scale;
}

void SpotsDialog::draw(std::vector<std::pair<int,int>>& posList){
    mPosList = posList;
    for(auto& pos:mPosList){
        pos.second *= -1;
    }
    update();
}
