#define MAINWINDOW_CPP
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Initial();
}

MainWindow::~MainWindow()
{
    Stock::Save_Data();
    delete ui;
}

void MainWindow::on_code_currentTextChanged(const QString &arg1)
{
    string code=arg1.toStdString();
    if(code.size()==6)
    {
        if(Stock::My_Stock.find(code)==Stock::My_Stock.end())
        {
            Stock::My_Stock[code].Initial();
        }
        Stock::My_Stock[code].Send_Code(code.c_str());
        bool error=Stock::My_Stock[code].Refresh_Real_Time_Data();
        Add_To_Menu(arg1,error);
        Refresh_Strategy_Information(code,error);
        Refresh_Stock_Information(code,error);
        ui->description->clear();
    }
    return;
}

void MainWindow::on_avaliable_strategy_itemDoubleClicked(QListWidgetItem *item)
{
    string code=ui->code->currentText().toStdString();
    Stock::My_Stock[code].Add_Strategy(Strategy::Name_To_Num[item->text()]);
    Refresh_Strategy_Information(code,false);
}

void MainWindow::on_selected_strategy_itemDoubleClicked(QListWidgetItem *item)
{
    string code=ui->code->currentText().toStdString();
    Stock::My_Stock[code].Delete_Strategy(Strategy::Name_To_Num[item->text()]);
    Refresh_Strategy_Information(code,false);
}

void MainWindow::on_select_button_clicked()
{
    string code=ui->code->currentText().toStdString();
    Stock::My_Stock[code].Add_Strategy(Strategy::Name_To_Num[ui->avaliable_strategy->currentItem()->text()]);
    Refresh_Strategy_Information(code,false);
}

void MainWindow::on_delete_button_clicked()
{
    string code=ui->code->currentText().toStdString();
    Stock::My_Stock[code].Delete_Strategy(Strategy::Name_To_Num[ui->selected_strategy->currentItem()->text()]);
    Refresh_Strategy_Information(code,false);
}

void MainWindow::on_selected_strategy_itemClicked(QListWidgetItem *item)
{
    ui->up_button->setEnabled(true);
    ui->down_button->setEnabled(true);
    ui->select_button->setEnabled(false);
    ui->delete_button->setEnabled(true);
    Refresh_Strategy_Description(Strategy::Name_To_Num[item->text()]);
    return;
}

void MainWindow::on_avaliable_strategy_itemClicked(QListWidgetItem *item)
{
    ui->up_button->setEnabled(false);
    ui->down_button->setEnabled(false);
    ui->select_button->setEnabled(true);
    ui->delete_button->setEnabled(false);
    Refresh_Strategy_Description(Strategy::Name_To_Num[item->text()]);
    return;
}

void MainWindow::on_up_button_clicked()
{
    int row=ui->selected_strategy->currentRow();
    if(row==0)
    {
        return;
    }
    string code=ui->code->currentText().toStdString();
    Stock::My_Stock[code].Swap_Strategy(row,row-1);
    Refresh_Strategy_Information(code,false);
    ui->selected_strategy->setCurrentRow(row-1);
    return;
}

void MainWindow::on_down_button_clicked()
{
    int row=ui->selected_strategy->currentRow();
    if(row==ui->selected_strategy->count()-1)
    {
        return;
    }
    string code=ui->code->currentText().toStdString();
    Stock::My_Stock[code].Swap_Strategy(row,row+1);
    Refresh_Strategy_Information(code,false);
    ui->selected_strategy->setCurrentRow(row+1);
    return;
}

void MainWindow::on_selected_strategy_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(current==0||Strategy::Name_To_Num.count(current->text())==0)
    {
        return;
    }
    Refresh_Strategy_Description(Strategy::Name_To_Num[current->text()]);
}

void MainWindow::on_avaliable_strategy_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(current==0||Strategy::Name_To_Num.count(current->text())==0)
    {
        return;
    }
    Refresh_Strategy_Description(Strategy::Name_To_Num[current->text()]);
}

void MainWindow::Initial()
{
    Strategy::Initial();
    std::map<std::string,Data>::iterator i;
    for(i=Stock::My_Stock.begin();i!=Stock::My_Stock.end();i++)
    {
        ui->code->addItem(QString::fromStdString(i->first));
    }
    QRegExp regx("[0-9]+$");
    QValidator *v=new QRegExpValidator(regx);
    ui->code->lineEdit()->setValidator(v);
    ui->code->lineEdit()->setMaxLength(6);
}

void MainWindow::Add_To_Menu(QString code,bool error)
{
    if(error||ui->code->findText(code)!=-1)
    {
        return;
    }
    ui->code->addItem(code);
    return;
}

void MainWindow::Refresh_Stock_Information(string code,bool error)
{
    if(error)
    {
        Stock::My_Stock.erase(Stock::My_Stock.find(code));
        ui->name->setText("不存在该股票");
        ui->current->setText("无");
        ui->holding->setText("无");
        ui->cost->setText("无");
        ui->profit->setText("无");
        return;
    }
    QString name=QString::fromWCharArray(Stock::My_Stock[code].R.name);
    ui->name->setText(name);
    ui->current->setText(QString::number(Stock::My_Stock[code].R.current,'f',2));
    ui->holding->setText(QString::number(Stock::My_Stock[code].D.hold_quantity,'f',2));
    ui->cost->setText(QString::number(Stock::My_Stock[code].D.cost_price,'f',2));
    float profit=(Stock::My_Stock[code].R.current-Stock::My_Stock[code].D.cost_price)*Stock::My_Stock[code].D.hold_quantity;
    ui->profit->setText(QString::number(profit,'f',2));
    return;
}

void MainWindow::Refresh_Strategy_Information(string code, bool error)
{
    Clear_Strategy_Information();
    if(error)
    {
        return;
    }
    bool S_Strategy[Num_Of_Strategy]={};
    int len=Stock::My_Stock[code].D.strategy.size();
    for(int i=0;i<len;i++)
    {
        int k=Stock::My_Stock[code].D.strategy[i];
        ui->selected_strategy->addItem(QString::fromWCharArray(Strategy::Strategy_Name[k]));
        S_Strategy[k]=true;
    }
    for(int i=0;i<Num_Of_Strategy;i++)
    {
        if(!S_Strategy[i])
        {
            ui->avaliable_strategy->addItem(QString::fromWCharArray(Strategy::Strategy_Name[i]));
        }
    }
    return;
}

void MainWindow::Clear_Strategy_Information()
{
    ui->selected_strategy->clear();
    ui->avaliable_strategy->clear();
}

void MainWindow::Refresh_Strategy_Description(int num)
{
    ui->description->clear();
    ui->description->setText(QString::fromWCharArray(Strategy::Strategy_Description[num]));
    return;
}

void MainWindow::on_pushButton_clicked()
{
    this->showMinimized();
    TdxWin::Soft_Initial();
    Stock::Get_Output_Data();
    Stock::Main_Operate();

}
