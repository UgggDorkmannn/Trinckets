#ifndef MERGECOLUMNS_H
#define MERGECOLUMNS_H

#include <QWidget>

namespace Ui {
class MergeColumns;
}

class MergeColumns : public QWidget
{
    Q_OBJECT

public:
    explicit MergeColumns(QWidget *parent = nullptr);
    ~MergeColumns();

private:
    Ui::MergeColumns *ui;
};

#endif // MERGECOLUMNS_H
