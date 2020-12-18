#ifndef RESIM_H
#define RESIM_H

#include <QLabel>
#include <QMouseEvent>

class resim : public QLabel
{
    Q_OBJECT
public:
    explicit resim(QWidget *parent = nullptr);
    void cizDDA();
    void cizBresenham();
    void cizCember(int r);
    void cizCemberBresenham(int r);
    void Kaydet(QString);
    void cizDaire(int r);
    void sinavSorusu();
    void sinavSorusu(int X1,int Y1,int X2, int Y2);
    void cizCember(int x1,int y1,int r);
    void olusturArkaplan();
    void imageYerlestirme();
    void poligon();
    void doldur(int x, int y, QRgb zeminRengi, QRgb yeniRenk);
    void doldurAlan();
    void icIceDaire();
    void koseliDaire();


private:
    QRgb renk;
    QPoint ilkNokta;
    QRgb YeniRenk;
    QPoint ikinciNokta;
    QImage ortam;
    void mousePressEvent(QMouseEvent*);
    void yBolgesi(int, int, int, int, int, int);
    void xBolgesi(int, int, int, int, int, int);
    int kontrol;
    void simetri(int x, int y);

signals:

};

#endif // RESIM_H
