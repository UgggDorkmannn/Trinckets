#include "SpotsOnXY.h"

SpotsOnXY::SpotsOnXY(QWidget *parent) : QWidget(parent)
{
    mScale = 32;
}


void SpotsOnXY::paintEvent(QPaintEvent* e){
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int w = width();
    int h = height();
    p.translate(w/2,h/2);
    for(auto& pos:mPosList){
        int x = pos.first * mScale;
        int y = pos.second * mScale;

        p.translate(x,y);
        p.drawEllipse(x,y,8,8);
        p.translate(-x,-y);
    }
}
void SpotsOnXY::setScale(int scale){
    mScale = scale;
}

void SpotsOnXY::draw(std::vector<std::pair<int,int>>& posList){
    mPosList = posList;
    update();
}
