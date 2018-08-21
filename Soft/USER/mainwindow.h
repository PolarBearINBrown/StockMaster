#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#if defined MAINWINDOW_CPP

#include "STOCK/stock.h"
#include "iostream"
#include "QLineEdit"
#include "QRegExp"
using namespace std;

#endif

#include "QListWidgetItem"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:

    void on_code_currentTextChanged(const QString &arg1);

    void on_avaliable_strategy_itemDoubleClicked(QListWidgetItem *item);

    void on_selected_strategy_itemDoubleClicked(QListWidgetItem *item);

    void on_avaliable_strategy_itemClicked(QListWidgetItem *item);

    void on_selected_strategy_itemClicked(QListWidgetItem *item);

    void on_select_button_clicked();

    void on_delete_button_clicked();

    void on_up_button_clicked();

    void on_down_button_clicked();

    void on_selected_strategy_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_avaliable_strategy_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:

    Ui::MainWindow *ui;

    bool running;

    void Initial();

    void Add_To_Menu(QString code,bool error);

    void Refresh_Stock_Information(std::string code,bool error);

    void Refresh_Strategy_Information(std::string code,bool error);

    void Clear_Strategy_Information();

    void Refresh_Strategy_Description(int num);

};

#endif // MAINWINDOW_H
