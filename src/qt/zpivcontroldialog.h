// Copyright (c) 2017-2018 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZPIVCONTROLDIALOG_H
#define ZPIVCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "primitives/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;

class WalletModel;

namespace Ui {
    class ZWspControlDialog;
}

class ZWspControlDialog : public QDialog {
    Q_OBJECT

public:
    explicit ZWspControlDialog(QWidget *parent);

    ~ZWspControlDialog();

    void setModel(WalletModel *model);

    static std::set <std::string> setSelectedMints;
    static std::set <CMintMeta> setMints;

    static std::vector <CMintMeta> GetSelectedMints();

private:
    Ui::ZWspControlDialog *ui;
    WalletModel *model;
    PrivacyDialog *privacyDialog;

    void updateList();

    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };

private
    slots:
            void
    updateSelection(QTreeWidgetItem
    * item,
    int column
    );

    void ButtonAllClicked();
};

#endif // ZPIVCONTROLDIALOG_H
