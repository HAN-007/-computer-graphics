#include "resim.h"
#include <qmath.h>
#include <math.h>
#include <QApplication>
resim::resim(QWidget *parent) : QLabel(parent)
{
    renk = qRgb(255, 255, 0);
    QImage arkaplan(600, 600, QImage::Format_RGB32);
    YeniRenk = qRgb(255, 0, 0);
    setPixmap(QPixmap::fromImage(arkaplan));
    ortam = arkaplan;
    kontrol = 0;
}

void resim::cizDDA()
{
    double dx = ikinciNokta.x() - ilkNokta.x();
    double dy = ikinciNokta.y() - ilkNokta.y();
    double Xfark;
    double Yfark;
    double x;
    double y;
    double pixelSayisi;
    if (fabs(dx) > fabs(dy)) {
        pixelSayisi = fabs(dx);
    } else {
        pixelSayisi = fabs(dy);
    }
    Xfark = dx / pixelSayisi;
    Yfark = dy / pixelSayisi;
    x = ilkNokta.x();
    y = ilkNokta.y();
    for (int i = 0; i < pixelSayisi ;++i ) {
        x += Xfark;
        y += Yfark;
        ortam.setPixel(round(x), round(y), renk);
    }
    setPixmap(QPixmap::fromImage(ortam));
}

void resim::cizBresenham()
{
    int dx = ikinciNokta.x() - ilkNokta.x();
    int dy = ikinciNokta.y() - ilkNokta.y();
    if (abs(dx) - abs(dy) > 0) {
        if (dx > 0) {
            if (dy > 0) {
                xBolgesi(ilkNokta.x() - ikinciNokta.x(), 1, 1, abs(dx), 2 * abs(dx), 2 * abs(dy));
            } else {
                xBolgesi(ilkNokta.x() - ikinciNokta.x(), 1, -1, abs(dx), 2 * abs(dx), 2 * abs(dy));
            }
        } else {
            if (dy > 0) {
                xBolgesi(ikinciNokta.x() - ilkNokta.x(), -1, 1, abs(dx), 2 * abs(dx), 2 * abs(dy));
            } else {
                xBolgesi(ikinciNokta.x() - ilkNokta.x(), -1, -1, abs(dx), 2 * abs(dx), 2 * abs(dy));
            }
        }
    } else {
        if (dy > 0) {
            if (dx > 0) {
                yBolgesi(ilkNokta.y() - ikinciNokta.y(), 1, 1, abs(dy), 2 * abs(dx), 2 * abs(dy));
            } else {
                yBolgesi(ilkNokta.y() - ikinciNokta.y(), -1, 1, abs(dy), 2 * abs(dx), 2 * abs(dy));
            }
        } else {
            if (dx > 0) {
                yBolgesi(ikinciNokta.y() - ilkNokta.y(), 1, -1, abs(dy), 2 * abs(dx), 2 * abs(dy));
            } else {
                yBolgesi(ikinciNokta.y() - ilkNokta.y(), -1, -1, abs(dy), 2 * abs(dx), 2 * abs(dy));
            }
        }
    }
    setPixmap(QPixmap::fromImage(ortam));
}

void resim::cizCember(int r)
{
    double x, y;
    double aci = 0.0;
    while (aci < 360) {
        QApplication::processEvents();
        x = ilkNokta.x() + r * cos(qDegreesToRadians(aci));
        y = ilkNokta.y() + r * sin(qDegreesToRadians(aci));
        aci += 0.05;
        ortam.setPixel(round(x), round(y), renk);
        setPixmap(QPixmap::fromImage(ortam));
    }

}


void resim::cizCemberBresenham(int r)
{
    int x = r, y = 0, hata = 0;
    int hatax, hatax_1;
    simetri(x, y);
    while (x >= y) {
        QApplication::processEvents();
        hatax = hata + 2 * y + 1;
        hatax_1 = hata + (2 * y + 1) - (2 * x - 1);
        if (abs(hatax) < abs(hatax_1)) {
            y++;
            hata = hatax;
        } else {
            x--;
            y++;
            hata = hatax_1;
        }
        simetri(x, y);
        setPixmap(QPixmap::fromImage(ortam));
    }
}

void resim::Kaydet(QString yol)
{
    ortam.save(yol);
}

void resim::cizDaire(int r)
{
    int x, y;
    for (x = -r; x <= r; ++x) {
        int YeniY = sqrt(r * r - x * x);
        for (y = -YeniY; y <= YeniY; ++y) {
            QApplication::processEvents();
            ortam.setPixel(ilkNokta.x() + x, ilkNokta.y() +y, renk);
            setPixmap(QPixmap::fromImage(ortam));
        }
    }

}

void resim::cizCember(int x1, int y1, int r)
{
    double x, y;
    double aci = 0.0;
    while (aci < 360) {
        //QApplication::processEvents();
        x = x1 + r * cos(qDegreesToRadians(aci));
        y = y1 + r * sin(qDegreesToRadians(aci));
        aci += 0.005;
        ortam.setPixel(round(x), round(y), renk);
    }
    setPixmap(QPixmap::fromImage(ortam));
}

void resim::olusturArkaplan()
{
    for (int i = 0 ;i<=600 ;i+=100) {
        for (int j=0;j<=600 ;++j ) {
           ortam.setPixel(i,j,renk);
        }
    }
    setPixmap(QPixmap::fromImage(ortam));
}

void resim::imageYerlestirme()
{
    int X1,Y1;
    for (int x=0;x<200 ;++x ) {
        for (int y=0;y<400 ;++y ) {
            X1=0.5*x;
            Y1=2*y;
            ortam.setPixel(X1,Y1,renk);
        }
    }
    setPixmap(QPixmap::fromImage(ortam));
}

void resim::poligon()
{

    for (int i=0;i<600 ;i++ ) {
        for (int j=100;j<600 ;j+=100) {
            QApplication::processEvents();
            ortam.setPixel(j,i,renk);
            ortam.setPixel(i,j,renk);
            setPixmap(QPixmap::fromImage(ortam));
        }
    }

}

void resim::doldur(int x, int y, QRgb zeminRengi, QRgb yeniRenk)
{
    QApplication::processEvents();
        if (ortam.pixel(x, y) == zeminRengi) {
            ortam.setPixel(x, y, yeniRenk);
            setPixmap(QPixmap::fromImage(ortam));
            doldur(x + 1, y, zeminRengi, yeniRenk);
            doldur(x - 1, y, zeminRengi, yeniRenk);
            doldur(x, y + 1, zeminRengi, yeniRenk);
            doldur(x, y - 1, zeminRengi, yeniRenk);
        }
}

void resim::doldurAlan()
{
    doldur(ilkNokta.x(), ilkNokta.y(), ortam.pixel(ilkNokta.x(), ilkNokta.y()), YeniRenk);
}

void resim::icIceDaire()
{
    int x1=ortam.height();
    int y1=ortam.width();

    for (int i=50;i<=sqrt( pow(ortam.height(),2)+pow(ortam.width(),2))/2 ;i+=50 ) {
        cizCember(0,0,i);
        cizCember(0,x1,i);
        cizCember(y1,0,i);
        cizCember(x1,y1,i);
    }
}

void resim::koseliDaire()
{
    int x1=ortam.height();
    int y1=ortam.width();

    cizCember(0,0,200);
    cizCember(0,x1,200);
    cizCember(y1,0,200);
    cizCember(x1,y1,200);


}


void resim::sinavSorusu()
{
    int x;
    int y;
    int r = ortam.height()/6;

    for (int i=r;i<ortam.height() ;i+=(r*2)) {
        for (int j=r;j<ortam.width() ;j+=(r*2) ) {
           x=i;
           y=j;
          cizCember(x,y,r);
        }
    }

    cizCember(ortam.height()/2,ortam.width()/2,r*3);


}

void resim::sinavSorusu(int X1, int Y1, int X2, int Y2)
{
    for (int i= X1;i< X2 ;++i )
        ortam.setPixel(i,Y2,renk);

    for (int i= X1;i< X2 ;++i )
        ortam.setPixel(i,Y2+100,renk);
    setPixmap(QPixmap::fromImage(ortam));


}



void resim::yBolgesi(int hata, int Xartim, int Yartim, int pixelSayisi, int dx2, int dy2)
{
    int x1 = ilkNokta.x();
    int y1 = ilkNokta.y();
    int x = x1;
    for (int i = 0; i < pixelSayisi; ++i) {
        ortam.setPixel(x, y1, renk);
        hata += dx2;
        if (hata > 0) {
            x += Xartim;
            hata -= dy2;
        }
        y1 += Yartim;
    }
}

void resim::xBolgesi(int hata, int Xartim, int Yartim, int pixelSayisi, int dx2, int dy2)
{
    int x1 = ilkNokta.x();
    int y1 = ilkNokta.y();
    int y = y1;
    for (int i = 0; i < pixelSayisi; ++i) {
        ortam.setPixel(x1, y, renk);
        hata += dy2;
        if (hata > 0) {
            y += Yartim;
            hata -= dx2;
        }
        x1 += Xartim;
    }
}

void resim::simetri(int x, int y)
{
    ortam.setPixel(ilkNokta.x() + x, ilkNokta.y() + y, renk);
    ortam.setPixel(ilkNokta.x() - x, ilkNokta.y() + y, renk);
    ortam.setPixel(ilkNokta.x() + x, ilkNokta.y() - y, renk);
    ortam.setPixel(ilkNokta.x() - x, ilkNokta.y() - y, renk);
    ortam.setPixel(ilkNokta.x() + y, ilkNokta.y() + x, renk);
    ortam.setPixel(ilkNokta.x() - y, ilkNokta.y() + x, renk);
    ortam.setPixel(ilkNokta.x() + y, ilkNokta.y() - x, renk);
    ortam.setPixel(ilkNokta.x() - y, ilkNokta.y() - x, renk);
}

void resim::mousePressEvent(QMouseEvent *event)
{
    ilkNokta = event->pos();
/*
    if (kontrol % 2 == 0) {
        ilkNokta = event->pos();
        kontrol++;
    } else {
        ikinciNokta = event->pos();
        kontrol++;
        //cizDDA();
        cizBresenham();
    }
*/
}
