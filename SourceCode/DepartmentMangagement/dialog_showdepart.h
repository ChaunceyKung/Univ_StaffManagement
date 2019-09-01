#ifndef DIALOG_SHOWDEPART_H
#define DIALOG_SHOWDEPART_H

#include <QDialog>



namespace Ui {
class Dialog_ShowDepart;
}

class Dialog_ShowDepart : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ShowDepart(QWidget *parent = nullptr);
    ~Dialog_ShowDepart();

private:
    Ui::Dialog_ShowDepart *ui;
};

#endif // DIALOG_SHOWDEPART_H
