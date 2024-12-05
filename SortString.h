#ifndef SORTSTRING_H
#define SORTSTRING_H

#include <QDialog>

namespace Ui {
class SortString;
}

class SortString : public QDialog
{
    Q_OBJECT

public:
    explicit SortString(QWidget *parent = nullptr);
    ~SortString();

private:
    Ui::SortString *ui;
};

#endif // SORTSTRING_H
