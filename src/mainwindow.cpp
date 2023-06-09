#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "qcustomplot.h"

double calcVal = 0.0;
QString xmin = "0";
QString xmax = "10";
QString ymin = "0";
QString ymax = "10";

double xBegin = 0;
double xEnd = 10;
double h = 0.1;
double X;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->Display->setText(QString::number(calcVal));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::draw_Graph(double *mass, int flag_x) {
  QVector<double> x, y;
  ui->Graph->addGraph();
  ui->Graph->graph(0)->setPen(QPen(QColor::fromRgb(245, 0, 167), 4));
  // ui->Graph->graph(0)->setLineStyle(QCPGraph::lsNone);
  // ui->Graph->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,
  // 4));

  xBegin = xmin.toDouble();
  xEnd = xmax.toDouble();
  ui->Graph->xAxis->setRange(xmin.toFloat(), xmax.toFloat());
  ui->Graph->yAxis->setRange(ymin.toFloat(), ymax.toFloat());
  int i = 0;

  for (X = xBegin; X <= xEnd; X += h) {
    x.push_back(X);
    printf("~~ X = %f\n", X);
    i++;
  }

  int rav = 1;

  if (flag_x == 0) {
    for (int k = 0; k < i; k++) {
      y.push_back(mass[k]);
      printf("~~ Y = %f\n", mass[k]);
      if (k != i - 1) {
        if (mass[k] == mass[k + 1]) {
          rav = rav * 1;
        } else {
          rav = 0;
        }
      }
    }

  } else {
    for (int k = 0; k < i; k++) {
      y.push_back(mass[0]);
      printf("~~ Y = %f\n", mass[k]);
      if (k != i - 1) {
        if (mass[k] == mass[k + 1]) {
          rav = rav * 1;
        } else {
          rav = 0;
        }
      }
    }
  }

  QString answer;
  if (rav == 1) {
    std::string str;
    double a = mass[0];
    int int_a = mass[0];
    if (a == int_a) {
      str = std::to_string(int_a);
    } else {
      str = std::to_string(a);
    }
    answer = QString::fromStdString(str);
    ui->Display->setText(answer);
  }

  printf("Length x: %lli\n", x.length());
  printf("Length y: %lli\n", y.length());
  ui->Graph->graph(0)->setData(x, y);
  ui->Display_result->clear();
  ui->Graph->xAxis->setLabel("x");
  ui->Graph->yAxis->setLabel("y");
  ui->Graph->replot();
  free(mass);
}

void MainWindow::on_Button_equal_clicked() {
  if ((xmin == '0' && xmax == '0' && ymin == '0' && ymax == '0') ||
      (xmin >= xmax) || (ymin >= ymax)) {
    ui->Display_result->setText("Введите область определения");
  } else {
    ui->Display_result->clear();
    QString resultString = ui->Display->text();
    QString x_znach = ui->Display_x->text();
    std::string str = resultString.toStdString();
    const char *formula_const = str.c_str();
    double *mass = (double *)calloc(abs(xmax.toInt() - xmin.toInt()) * 10 + 1,
                                    sizeof(double));
    int flag_x = 0;
    if (x_znach == "") {
      mass = mainpn(formula_const, xmin.toInt(), xmax.toInt());
      draw_Graph(mass, flag_x);
    } else {
      xmin = x_znach;
      flag_x = 1;
      mass = mainpn(formula_const, xmin.toInt(), xmax.toInt());
      draw_Graph(mass, flag_x);
    }
  }
}

void MainWindow::on_Display_ymax_editingFinished() {
  ymax = ui->Display_ymax->text();
  on_Button_equal_clicked();
}

void MainWindow::on_Display_ymin_editingFinished() {
  ymin = ui->Display_ymin->text();
  on_Button_equal_clicked();
}

void MainWindow::on_Display_xmin_editingFinished() {
  xmin = ui->Display_xmin->text();
  on_Button_equal_clicked();
}

void MainWindow::on_Display_xmax_editingFinished() {
  xmax = ui->Display_xmax->text();
  on_Button_equal_clicked();
}

void MainWindow::on_Button1_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("1");
}

void MainWindow::on_Button2_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("2");
}

void MainWindow::on_Button3_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("3");
}

void MainWindow::on_Button4_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("4");
}

void MainWindow::on_Button5_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("5");
}

void MainWindow::on_Button6_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("6");
}

void MainWindow::on_Button7_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("7");
}

void MainWindow::on_Button8_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("8");
}

void MainWindow::on_Button9_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("9");
}

void MainWindow::on_Button0_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("0");
}

void MainWindow::on_Button_left_scob_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("(");
}

void MainWindow::on_Button_right_scob_clicked() {
  if (if_can_write_operator()) {
    ui->Display->insert(")");
  }
}

void MainWindow::on_Button_pow_clicked() {
  if (if_can_write_operator()) {
    ui->Display->insert("^");
  }
}

void MainWindow::on_Button_mult_clicked() {
  if (if_can_write_operator()) {
    ui->Display->insert("*");
  }
}

void MainWindow::on_Button_div_clicked() {
  if (if_can_write_operator()) {
    ui->Display->insert("/");
  }
}

void MainWindow::on_Button_mod_clicked() {
  if (if_can_write_operator()) {
    ui->Display->insert("%");
  }
}

void MainWindow::on_Button_sum_clicked() {
  if (if_can_write_operator()) {
    ui->Display->insert("+");
  }
}

void MainWindow::on_Button_sub_clicked() { ui->Display->insert("-"); }

void MainWindow::on_Button_dot_clicked() {
  if (if_can_write_operator() && if_last_is_digit()) {
    ui->Display->insert(".");
  }
}

void MainWindow::on_Button_sin_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("sin(");
}

void MainWindow::on_Button_cos_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("cos(");
}

void MainWindow::on_Button_tan_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("tan(");
}

void MainWindow::on_ButtonAC_clicked() {
  ui->Display->clear();
  ui->Display_x->clear();
  ui->Display_result->clear();
  ui->Display->insert("0");
}

int MainWindow::if_can_write_operator() {
  if (ui->Display->text() == "" || ui->Display->text().endsWith("(") ||
      ui->Display->text().endsWith("/") || ui->Display->text().endsWith("+") ||
      ui->Display->text().endsWith("-") || ui->Display->text().endsWith("*") ||
      ui->Display->text().endsWith("%")) {
    return 0;
  } else {
    return 1;
  }
}

int MainWindow::if_last_is_digit() {
  if (ui->Display->text().endsWith("0") || ui->Display->text().endsWith("1") ||
      ui->Display->text().endsWith("2") || ui->Display->text().endsWith("3") ||
      ui->Display->text().endsWith("4") || ui->Display->text().endsWith("5") ||
      ui->Display->text().endsWith("6") || ui->Display->text().endsWith("7") ||
      ui->Display->text().endsWith("8") || ui->Display->text().endsWith("9")) {
    return 1;
  } else {
    return 0;
  }
}

void MainWindow::on_Button_sqrt_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("sqrt(");
}

void MainWindow::on_Button_log_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("log(");
}

void MainWindow::on_Button_ln_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("ln(");
}

void MainWindow::on_Button_acos_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("acos(");
}

void MainWindow::on_Button_asin_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("asin(");
}

void MainWindow::on_Button_atan_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("atan(");
}

void MainWindow::on_Button_del_clicked() { ui->Display->backspace(); }

void MainWindow::on_Button_x_clicked() {
  if (ui->Display->text() == "0") {
    ui->Display->backspace();
  }
  ui->Display->insert("x");
}
