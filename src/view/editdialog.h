#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>

class VmessConfigModel;

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = 0);
    ~EditDialog();

private:
    Ui::EditDialog *ui;
private slots:
    void save();
signals:
    void signalAddServer(VmessConfigModel* server);
};

#endif // EDITDIALOG_H
