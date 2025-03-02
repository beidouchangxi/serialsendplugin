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
 * \file serialsendplugin.cpp
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#include <QtGui>

#include "serialsendplugin.h"

SerialSendPlugin::SerialSendPlugin()
{
    form = NULL;
    counterMessages = 0;
    counterNonVerboseMessages = 0;
    counterVerboseMessages = 0;
    dltFile = 0;
    dltControl = 0;
    ecuList = 0;
}

SerialSendPlugin::~SerialSendPlugin()
{

}

QString SerialSendPlugin::name()
{
    return QString("Serial Send Plugin");
}

QString SerialSendPlugin::pluginVersion(){
    return SERIAL_SEND_PLUGIN_VERSION;
}

QString SerialSendPlugin::pluginInterfaceVersion(){
    return PLUGIN_INTERFACE_VERSION;
}

QString SerialSendPlugin::description()
{
    return QString();
}

QString SerialSendPlugin::error()
{
    return QString();
}

bool SerialSendPlugin::loadConfig(QString /* filename */)
{
    return true;
}

bool SerialSendPlugin::saveConfig(QString /* filename */)
{
    return true;
}

QStringList SerialSendPlugin::infoConfig()
{
    return QStringList();
}

QWidget* SerialSendPlugin::initViewer()
{
    form = new SerialSend::Form(this);
    return form;
}

bool SerialSendPlugin::initControl(QDltControl *control)
{
    dltControl = control;

    return true;
}

bool SerialSendPlugin::initConnections(QStringList list)
{
    ecuList = new QStringList(list);
    form->setConnections(list);

    return false;
}

bool SerialSendPlugin::controlMsg(int , QDltMsg &)
{
    return false;
}

void SerialSendPlugin::updateCounters(int ,int )
{

}

bool SerialSendPlugin::stateChanged(int index, QDltConnection::QDltConnectionState connectionState,QString hostname){

    qDebug() << ecuList->at(index) << "ConnectionState:" << connectionState << "Hostname:" << hostname << endl;

    return true;
}

bool SerialSendPlugin::autoscrollStateChanged(bool enabled)
{
    return true;
}

void SerialSendPlugin::initMessageDecoder(QDltMessageDecoder* pMessageDecoder)
{
    Q_UNUSED(pMessageDecoder);
}

void SerialSendPlugin::initMainTableView(QTableView* pTableView)
{
    Q_UNUSED(pTableView);
}

void SerialSendPlugin::configurationChanged()
{}

void SerialSendPlugin::selectedIdxMsg(int , QDltMsg &) {

}

void SerialSendPlugin::selectedIdxMsgDecoded(int , QDltMsg &){

}

void SerialSendPlugin::initFileStart(QDltFile *file){
    dltFile = file;
}

void SerialSendPlugin::initMsg(int , QDltMsg &){

}
void SerialSendPlugin::initMsgDecoded(int , QDltMsg &){

}

void SerialSendPlugin::initFileFinish(){

}

void SerialSendPlugin::updateFileStart(){

}

void SerialSendPlugin::updateMsg(int , QDltMsg &){

}

void SerialSendPlugin::updateMsgDecoded(int , QDltMsg &){

}
void SerialSendPlugin::updateFileFinish(){

}

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
Q_EXPORT_PLUGIN2(serialsendplugin, SerialSendPlugin);
#endif
