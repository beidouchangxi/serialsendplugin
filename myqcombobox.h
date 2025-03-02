#ifndef MYQCOMBOBOX_H
#define MYQCOMBOBOX_H
#include <QComboBox>

class MyQComboBox : public QComboBox
{
    Q_OBJECT
public:
    MyQComboBox(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYQCOMBOBOX_H
