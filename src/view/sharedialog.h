#ifndef SHAREDIALOG_H
#define SHAREDIALOG_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class ShareDialog;
}

class ShareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShareDialog(const QByteArray &Url,QWidget *parent = 0);
    ~ShareDialog();

private:
    Ui::ShareDialog *ui;
private slots:
    void onSaveButtonClicked();
};

#endif // SHAREDIALOG_H
