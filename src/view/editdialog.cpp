#include "editdialog.h"
#include "ui_editdialog.h"
#include "src/model/vmessconfigmodel.h"
#include "src/controller/configcontroller.h"
#include <QMessageBox>

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox,&QDialogButtonBox::accepted,this,&EditDialog::save);

}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::save(){
    VmessConfigModel* server = new VmessConfigModel();
    server->Address = ui->ServerAddressEdit->text();
    server->Port = ui->ServerPortEdit->text().toInt();
    server->UserId = ui->UserIdEdit->text();
    server->UserAlterId = ui->UserAlterIdEdit->text().toInt();
    server->UserSecurity = ui->UserSecurityComboBox->currentText();
    server->LocalPort = ui->LocalPortEdit->text().toInt();
    server->LastUseTime = QDateTime::fromTime_t(8964);
    server->Remarks = ui->ProfileNameEdit->text();
    server->RequestHost = "";
    ConfigController::getInstance().addServerConfig(server);
    this->accept();
}





