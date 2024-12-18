#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QWidget>
#include <QTextEdit>
#include <QKeyEvent>
#include "SearchPanel.h"
class Notepad : public QTextEdit
{
    Q_OBJECT
public:
    Notepad();
protected:
    void keyPressEvent(QKeyEvent*);
    //void keyReleaseEvent(QKeyEvent*);
private:
    SearchPanel* mFind;
};

#endif // NOTEPAD_H
