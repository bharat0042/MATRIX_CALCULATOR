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
    connect(ui->subBtn, SIGNAL(clicked()), this, SLOT(subs()));

    connect(ui->mulBtn, SIGNAL(clicked()), this, SLOT(mulAB()));

    connect(ui->mulBtn2, SIGNAL(clicked()), this, SLOT(accuA()));

    connect(ui->detABtn, SIGNAL(clicked()), this, SLOT(detA()));
    connect(ui->detBBtn, SIGNAL(clicked()), this, SLOT(detB()));

    connect(ui->invABtn, SIGNAL(clicked()), this, SLOT(invA()));
    connect(ui->invBBtn, SIGNAL(clicked()), this, SLOT(invB()));

    connect(ui->tposeABtn, SIGNAL(clicked()), this, SLOT(tposeA()));
    connect(ui->tposeBBtn, SIGNAL(clicked()), this, SLOT(tposeB()));

    connect(ui->sqABtn, SIGNAL(clicked()), this, SLOT(sqA()));
    connect(ui->sqBBtn, SIGNAL(clicked()), this, SLOT(sqB()));
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
        row = row.trimmed();
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
    matx.setA(noOfRows, noOfCols, temp);
}

void MainApp::setB()
{
    mx::Matrix temp;
    int noOfRows = 0;
    int noOfCols = 0;
    foreach(QString row, ui->textEdit_2->toPlainText().split("\n"))
    {
        std::vector<double> singleRow;
        row = row.trimmed();
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
    matx.setB(noOfRows, noOfCols, temp);
}

void MainApp::add()
{
    if(matx.getA().n_rows != matx.getB().n_rows || matx.getA().n_cols != matx.getB().n_cols)
    {
        setError("Matrix are not of same size");
    }
    setOutput("A+B = ", matx.addMat());
}

void MainApp::subs()
{
    if(matx.getA().n_rows != matx.getB().n_rows || matx.getA().n_cols != matx.getB().n_cols)
    {
        setError("Matrix are not of same size");
    }
    setOutput("A-B = ", matx.subMat());
}

void MainApp::mulAB()
{
    if(matx.getA().n_cols != matx.getB().n_rows)
    {
        setError("No of cols for matrix A is not equal to no of rows for matrix B");
        return;
    }
    setOutput("A * B = ", matx.mulMat());
}

void MainApp::accuA()
{
    setOutput("accuA = ", matx.accuA());
}

void MainApp::invA()
{
    arma::mat res;
    try
    {
        bool isCalculated = matx.invMat(true, res);
        if(isCalculated)
        {
            setOutput("Inv A = ", res);
        }
    }
    catch(...)
    {
        setError("Inv of A does not exist ");
    }
}

void MainApp::invB()
{
    arma::mat res;
    try
    {
        bool isCalculated = matx.invMat(false, res);
        if(isCalculated)
        {
            setOutput("Inv B = ", res);
        }
    }
    catch(...)
    {
        setError("Inv of B does not exist ");
    }
}

void MainApp::tposeA()
{
    setOutput("Transpose A = ", matx.tpose(true));
}

void MainApp::tposeB()
{
    setOutput("Transpose B = ", matx.tpose(false));
}

void MainApp::sqA()

{
    setOutput("Square A = ", matx.sq(true));
}

void MainApp::sqB()
{
    setOutput("Square B = ", matx.sq(false));
}

void MainApp::detA()
{
    setOutput("Determinant A = ", matx.matDet(true));
}

void MainApp::detB()
{
    setOutput("Determinant A = ", matx.matDet(false));
}

void MainApp::setOutput(std::string msg, arma::mat out)
{
    msg.append("\n");
    for(int i = 0; i < out.n_rows; i++)
    {
        for(int j = 0; j < out.n_cols; j++)
        {
            msg.append(std::to_string(out(i, j)));
            msg.append(" ");
        }
        msg.append("\n");
    }
    msg.append("\n");
    ui->textEdit_3->moveCursor(QTextCursor::End);
    ui->textEdit_3->insertPlainText(msg.c_str());
    ui->textEdit_3->moveCursor (QTextCursor::End);
}

void MainApp::setOutput(std::string msg, double out)
{
    msg.append(std::to_string(out));
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
