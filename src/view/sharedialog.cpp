/*
 * Copyright (C) 2014-2016 Symeon Huang <hzwhuang@gmail.com>
 *
 * shadowsocks-qt5 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * shadowsocks-qt5 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libQtShadowsocks; see the file LICENSE. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include "sharedialog.h"
#include "ui_sharedialog.h"
#include "src/utils/qrwidget.h"



ShareDialog::ShareDialog(const QByteArray &Url,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShareDialog)
{
    ui->setupUi(this);
    ui->QrWidget->setQRData(Url);
    ui->UrlEdit->setText(QString(Url));
    ui->UrlEdit->setCursorPosition(0);
    connect(ui->SaveButton, &QPushButton::clicked, this, &ShareDialog::onSaveButtonClicked);
    //this->adjustSize();
}

ShareDialog::~ShareDialog()
{
    delete ui;
}

void ShareDialog::onSaveButtonClicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save QR Code"), QString(), "PNG (*.png)");
    if (!filename.isEmpty()) {
        ui->QrWidget->getQRImage().save(filename);
    }
}

