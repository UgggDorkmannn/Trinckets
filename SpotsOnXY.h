#ifndef SPOTSONXY_H
#define SPOTSONXY_H

#include <QWidget>
#include <vector>
#include <QPaintEvent>
#include <QPainter>
class SpotsOnXY : public QWidget
{
    Q_OBJECT
public:
    explicit SpotsOnXY(QWidget *parent = nullptr);

    void draw(std::vector<std::pair<int,int>>& posList);
    void setScale(int scale);

    std::vector<std::pair<int,int>> mPosList;
    int mScale;
signals:

public slots:

protected:
    void paintEvent(QPaintEvent* e);
};

#endif // SPOTSONXY_H
