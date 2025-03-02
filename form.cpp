/**
 * @licence app begin@
 * Copyright (C) 2011-2012  BMW AG
 *
 * This file is part of GENIVI Project Dlt Viewer.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \file form.cpp
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#include "form.h"
#include "ui_form.h"
#include "serialsendplugin.h"
#include "qdltsettingsmanager.h"
#include <QKeyEvent>
#include <qfiledialog.h>

using namespace SerialSend;

Form::Form(SerialSendPlugin *_plugin,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    plugin = _plugin;
    this->updateHistory();
}

Form::~Form()
{
    delete ui;
}

void Form::setConnections(QStringList list)
{
    ui->comboBoxConnections->clear();
    ui->comboBoxConnections->insertItems(0,list);
}

void Form::updateHistory()
{
    QStringList list;
    list = QDltSettingsManager::getInstance()->value("injection/data").toStringList();
    ui->lineEditData->clear();
    foreach(QString text,list)
       ui->lineEditData->addItem(text);
}

void Form::storeHistory()
{
    QStringList list;

    list = QDltSettingsManager::getInstance()->value("injection/data").toStringList();
    list.removeAll(ui->lineEditData->currentText());
    list.insert(0, ui->lineEditData->currentText());
    while (list.size() > 10)
        list.removeLast();
    QDltSettingsManager::getInstance()->setValue("injection/data",list);
}

void Form::on_buttonBox_accepted()
{
    if(plugin->dltControl)
        plugin->dltControl->sendInjection(ui->comboBoxConnections->currentIndex(),"SER","CON",9999,ui->lineEditData->currentText().toLatin1());
        this->storeHistory();
        this->updateHistory();
}

void Form::on_buttonBox_rejected()
{
    ui->lineEditData->clearEditText();
}

void Form::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Enter:
    case Qt::Key_Return:
        this->on_buttonBox_accepted();
        break;
    default:
        ui->lineEditData->keyPressEvent(event);
        break;
    }
}
