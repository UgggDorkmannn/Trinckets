#ifndef SPOTSDIALOG_H
#define SPOTSDIALOG_H

#include <QDialog>

namespace Ui {
class SpotsDialog;
}

class SpotsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpotsDialog(QWidget *parent = nullptr);
    ~SpotsDialog();

private:
    Ui::SpotsDialog *ui;
public:
    void draw(std::vector<std::pair<int,int>>& posList);
    void setScale(int scale);

    std::vector<std::pair<int,int>> mPosList;
    int mScale;
signals:

public slots:

protected:
    void paintEvent(QPaintEvent* e);
};

#endif // SPOTSDIALOG_H
