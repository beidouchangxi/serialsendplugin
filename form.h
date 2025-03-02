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
 * \file form.h
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QKeyEvent>

class SerialSendPlugin;

namespace SerialSend {
    namespace Ui {
        class Form;
        class MyComboBox;
    }

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(SerialSendPlugin *_plugin, QWidget *parent = 0);
    ~Form();

    void setConnections(QStringList list);
    void updateHistory();
    void storeHistory();
    void keyPressEvent(QKeyEvent *event);

public:
    Ui::Form *ui;
    SerialSendPlugin *plugin;

public slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
};
} // namespace SerialSend
#endif // FORM_H
