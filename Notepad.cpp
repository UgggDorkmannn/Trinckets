#include "Notepad.h"
#include <QDebug>
Notepad::Notepad()
{
    mFind = new SearchPanel;
    mFind->hide();
    connect(mFind,&SearchPanel::searchRequest,this,[&](){
        QString target = mFind->target();
        qDebug() << "find " << target;
    });
}

void Notepad::keyPressEvent(QKeyEvent* e){
    if(e->key() == Qt::Key_F && (e->modifiers() & Qt::ControlModifier) ){
        mFind->show();
        return;
    }
    QTextEdit::keyPressEvent(e);
}
