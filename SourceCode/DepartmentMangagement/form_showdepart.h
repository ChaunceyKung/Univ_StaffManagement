#ifndef FORM_SHOWDEPART_H
#define FORM_SHOWDEPART_H

#include <QWidget>

namespace Ui {
class Form_ShowDepart;
}

class Form_ShowDepart : public QWidget
{
    Q_OBJECT

public:
    explicit Form_ShowDepart(QWidget *parent = nullptr);
    ~Form_ShowDepart();

private:
    Ui::Form_ShowDepart *ui;
};

#endif // FORM_SHOWDEPART_H
