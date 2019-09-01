#ifndef DIALOG_SHOWSTAFF_H
#define DIALOG_SHOWSTAFF_H

#include <QDialog>

namespace Ui {
class Dialog_ShowStaff;
}

class Dialog_ShowStaff : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ShowStaff(QWidget *parent = nullptr);
    ~Dialog_ShowStaff();

private:
    Ui::Dialog_ShowStaff *ui;
};

#endif // DIALOG_SHOWSTAFF_H
