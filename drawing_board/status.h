#ifndef STATUS_H
#define STATUS_H

#include<QString>
class status
{
public:
    explicit status(
            int wide,
            int type,
            QString content,
            int draw_r,
            int draw_g,
            int draw_b,
            int brush_r,
            int brush_g,
            int brush_b);

    int wide;
     int type;
    QString content;
    int draw_r;
    int draw_g;
    int draw_b;
    int brush_r;
    int brush_g;
    int brush_b;
};

#endif // STATUS_H
