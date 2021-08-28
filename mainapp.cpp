#include "mainapp.h"
#include "./ui_mainapp.h"

MainApp::MainApp(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainApp)
{
    ui->setupUi(this);
    connect(ui->setABtn, SIGNAL(clicked()), this, SLOT(setA()));
    connect(ui->setBBtn, SIGNAL(clicked()), this, SLOT(setB()));
    connect(ui->addBtn, SIGNAL(clicked()), this, SLOT(add()));
}

MainApp::~MainApp()
{
    delete ui;
}

void MainApp::setA()
{
    mx::Matrix temp;
    int noOfRows = 0;
    int noOfCols = 0;
    foreach(QString row, ui->textEdit->toPlainText().split("\n"))
    {
        std::vector<double> singleRow;
        foreach(QString val, row.split(" "))
        {
            singleRow.push_back(val.toDouble());
        }
        if(noOfCols == 0)
        {
            noOfCols = singleRow.size();
        }
        if(noOfCols != 0 && noOfCols != singleRow.size())
        {
            setError("No of cols is not consistent");
            return;
        }
        temp.push_back((singleRow));
    }
    noOfRows = temp.size();
    mx::MatrixNd tmat(noOfRows, noOfCols, temp);
    m_A = tmat;
}

void MainApp::setB()
{
    mx::Matrix temp;
    int noOfRows = 0;
    int noOfCols = 0;
    foreach(QString row, ui->textEdit_2->toPlainText().split("\n"))
    {
        std::vector<double> singleRow;
        foreach(QString val, row.split(" "))
        {
            singleRow.push_back(val.toDouble());
        }
        if(noOfCols == 0)
        {
            noOfCols = singleRow.size();
        }
        if(noOfCols != 0 && noOfCols != singleRow.size())
        {
            setError("No of cols is not consistent");
            return;
        }
        temp.push_back((singleRow));
    }
    noOfRows = temp.size();
    mx::MatrixNd tmat(noOfRows, noOfCols, temp);
    m_B = tmat;
}

void MainApp::add()
{
    mx::MatrixNd res = mx::add(m_A, m_B);
    setOutput("A+B = ", res);
}

void MainApp::setOutput(std::string msg, const mx::MatrixNd& out)
{
    msg.append("\n");
    for(int i = 0; i < out.getRows(); i++)
    {
        for(int j = 0; j < out.getCols(); j++)
        {
            msg.append(std::to_string(out[i][j]));
            msg.append(" ");
        }
        msg.append("\n");
    }
    msg.append("\n");
    ui->textEdit_3->moveCursor(QTextCursor::End);
    ui->textEdit_3->insertPlainText(msg.c_str());
    ui->textEdit_3->moveCursor (QTextCursor::End);
}

void MainApp::setError(std::string msg)
{
    msg.append("\n");
    ui->textEdit_3->moveCursor(QTextCursor::End);
    ui->textEdit_3->insertPlainText(msg.c_str());
    ui->textEdit_3->moveCursor (QTextCursor::End);
}

void MainApp::log(std::string msg)
{
    msg.append("\n");
    ui->textEdit_3->moveCursor(QTextCursor::End);
    ui->textEdit_3->insertPlainText(msg.c_str());
    ui->textEdit_3->moveCursor (QTextCursor::End);
}
