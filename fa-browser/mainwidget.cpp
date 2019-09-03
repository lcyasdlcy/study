#include "mainwidget.h"
#include <QFontDatabase>
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    label = new QLabel("字体代码：");
    lineEdit = new QLineEdit;
    tblWidget = new QTableWidget();
    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(label);
    layout1->addWidget(lineEdit);
    QVBoxLayout *layout2 = new QVBoxLayout;
    layout2->addLayout(layout1);
    layout2->addWidget(tblWidget);
    setLayout(layout2);
    resize(640, 480);
    //font-awesome-4.7.0的675个字体代码
    QString s = "f000,f001,f002,f003,f004,f005,f006,f007,f008,f009,f00a,f00b,f00c,f00d,f00e,f010,f011,f012,f013,f014,f015,f016,f017,f018,f019,f01a,f01b,f01c,f01d,f01e,f021,f022,f023,f024,f025,f026,f027,f028,f029,f02a,f02b,f02c,f02d,f02e,f02f,f030,f031,f032,f033,f034,f035,f036,f037,f038,f039,f03a,f03b,f03c,f03d,f03e,f040,f041,f042,f043,f044,f045,f046,f047,f048,f049,f04a,f04b,f04c,f04d,f04e,f050,f051,f052,f053,f054,f055,f056,f057,f058,f059,f05a,f05b,f05c,f05d,f05e,f060,f061,f062,f063,f064,f065,f066,f067,f068,f069,f06a,f06b,f06c,f06d,f06e,f070,f071,f072,f073,f074,f075,f076,f077,f078,f079,f07a,f07b,f07c,f07d,f07e,f080,f081,f082,f083,f084,f085,f086,f087,f088,f089,f08a,f08b,f08c,f08d,f08e,f090,f091,f092,f093,f094,f095,f096,f097,f098,f099,f09a,f09b,f09c,f09d,f09e,f0a0,f0a1,f0f3,f0a3,f0a4,f0a5,f0a6,f0a7,f0a8,f0a9,f0aa,f0ab,f0ac,f0ad,f0ae,f0b0,f0b1,f0b2,f0c0,f0c1,f0c2,f0c3,f0c4,f0c5,f0c6,f0c7,f0c8,f0c9,f0ca,f0cb,f0cc,f0cd,f0ce,f0d0,f0d1,f0d2,f0d3,f0d4,f0d5,f0d6,f0d7,f0d8,f0d9,f0da,f0db,f0dc,f0dd,f0de,f0e0,f0e1,f0e2,f0e3,f0e4,f0e5,f0e6,f0e7,f0e8,f0e9,f0ea,f0eb,f0ec,f0ed,f0ee,f0f0,f0f1,f0f2,f0a2,f0f4,f0f5,f0f6,f0f7,f0f8,f0f9,f0fa,f0fb,f0fc,f0fd,f0fe,f100,f101,f102,f103,f104,f105,f106,f107,f108,f109,f10a,f10b,f10c,f10d,f10e,f110,f111,f112,f113,f114,f115,f118,f119,f11a,f11b,f11c,f11d,f11e,f120,f121,f122,f123,f124,f125,f126,f127,f128,f129,f12a,f12b,f12c,f12d,f12e,f130,f131,f132,f133,f134,f135,f136,f137,f138,f139,f13a,f13b,f13c,f13d,f13e,f140,f141,f142,f143,f144,f145,f146,f147,f148,f149,f14a,f14b,f14c,f14d,f14e,f150,f151,f152,f153,f154,f155,f156,f157,f158,f159,f15a,f15b,f15c,f15d,f15e,f160,f161,f162,f163,f164,f165,f166,f167,f168,f169,f16a,f16b,f16c,f16d,f16e,f170,f171,f172,f173,f174,f175,f176,f177,f178,f179,f17a,f17b,f17c,f17d,f17e,f180,f181,f182,f183,f184,f185,f186,f187,f188,f189,f18a,f18b,f18c,f18d,f18e,f190,f191,f192,f193,f194,f195,f196,f197,f198,f199,f19a,f19b,f19c,f19d,f19e,f1a0,f1a1,f1a2,f1a3,f1a4,f1a5,f1a6,f1a7,f1a8,f1a9,f1aa,f1ab,f1ac,f1ad,f1ae,f1b0,f1b1,f1b2,f1b3,f1b4,f1b5,f1b6,f1b7,f1b8,f1b9,f1ba,f1bb,f1bc,f1bd,f1be,f1c0,f1c1,f1c2,f1c3,f1c4,f1c5,f1c6,f1c7,f1c8,f1c9,f1ca,f1cb,f1cc,f1cd,f1ce,f1d0,f1d1,f1d2,f1d3,f1d4,f1d5,f1d6,f1d7,f1d8,f1d9,f1da,f1db,f1dc,f1dd,f1de,f1e0,f1e1,f1e2,f1e3,f1e4,f1e5,f1e6,f1e7,f1e8,f1e9,f1ea,f1eb,f1ec,f1ed,f1ee,f1f0,f1f1,f1f2,f1f3,f1f4,f1f5,f1f6,f1f7,f1f8,f1f9,f1fa,f1fb,f1fc,f1fd,f1fe,f200,f201,f202,f203,f204,f205,f206,f207,f208,f209,f20a,f20b,f20c,f20d,f20e,f210,f211,f212,f213,f214,f215,f216,f217,f218,f219,f21a,f21b,f21c,f21d,f21e,f221,f222,f223,f224,f225,f226,f227,f228,f229,f22a,f22b,f22c,f22d,f230,f231,f232,f233,f234,f235,f236,f237,f238,f239,f23a,f23b,f23c,f23d,f23e,f240,f241,f242,f243,f244,f245,f246,f247,f248,f249,f24a,f24b,f24c,f24d,f24e,f250,f251,f252,f253,f254,f255,f256,f257,f258,f259,f25a,f25b,f25c,f25d,f25e,f260,f261,f262,f263,f264,f265,f266,f267,f268,f269,f26a,f26b,f26c,f26d,f26e,f270,f271,f272,f273,f274,f275,f276,f277,f278,f279,f27a,f27b,f27c,f27d,f27e,f280,f281,f282,f283,f284,f285,f286,f287,f288,f289,f28a,f28b,f28c,f28d,f28e,f290,f291,f292,f293,f294,f295,f296,f297,f298,f299,f29a,f29b,f29c,f29d,f29e,f2a0,f2a1,f2a2,f2a3,f2a4,f2a5,f2a6,f2a7,f2a8,f2a9,f2aa,f2ab,f2ac,f2ad,f2ae,f2b0,f2b1,f2b2,f2b3,f2b4,f2b5,f2b6,f2b7,f2b8,f2b9,f2ba,f2bb,f2bc,f2bd,f2be,f2c0,f2c1,f2c2,f2c3,f2c4,f2c5,f2c6,f2c7,f2c8,f2c9,f2ca,f2cb,f2cc,f2cd,f2ce,f2d0,f2d1,f2d2,f2d3,f2d4,f2d5,f2d6,f2d7,f2d8,f2d9,f2da,f2db,f2dc,f2dd,f2de,f2e0";
    QList<QString> lst = s.split(",");
    int itemCnt = lst.length();
    int colCnt = 10;
    int rowCnt = itemCnt/colCnt+1;
    //设置列数、行数
    tblWidget->setColumnCount(colCnt);
    tblWidget->setRowCount(rowCnt);
    //设置不可编辑
    tblWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置font-awesome字体
    int fontId = QFontDatabase::addApplicationFont(":/font/fontawesome-webfont.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    Q_ASSERT_X(fontFamilies.size()==1, "font", "font not exist.");
    QFont font;
    font.setFamily(fontFamilies.at(0));
    font.setPointSize(20);//字体大小
    int n = 0;
    for (int i=0; i<rowCnt; i++) {
        for (int j=0; j<colCnt; j++,n++) {
            if (n == itemCnt) break;
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setFont(font);
            item->setText(QString(QChar(lst.at(n).toUShort(0,16))));
            item->setTextColor(QColor::fromHsl(rand()%360,rand()%256,rand()%200));
            tblWidget->setItem(i, j, item);
        }
    }
    //设置单元格适应内容大小
    tblWidget->resizeColumnsToContents();
    tblWidget->resizeRowsToContents();
    //连接单元格单击信号
    connect(tblWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(getItem(QTableWidgetItem*)));
}

MainWidget::~MainWidget()
{

}

void MainWidget::getItem(QTableWidgetItem *item)
{
    lineEdit->setText(QString("0x%1").arg(QString::number(item->text().at(0).unicode(),16)));
}
