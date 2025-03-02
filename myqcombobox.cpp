#include "myqcombobox.h"
#include <QLineEdit>
#include "form.h"

MyQComboBox::MyQComboBox(QWidget *parent)
    : QComboBox(parent)
{
    ;
}

void MyQComboBox::keyPressEvent(QKeyEvent *event)
{
    QComboBox::keyPressEvent(event);
}
