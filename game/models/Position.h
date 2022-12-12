//
// Created by duarte on 10-11-2022.
//

#ifndef POO_NATURAL_RESERVE_POSITION_H
#define POO_NATURAL_RESERVE_POSITION_H

class Position {
public:
    int column;
    int row;
    Position(int col, int row);
    void setX(int col); // set column
    int getX();
    void setY(int row); // set row
    int getY();
};


#endif //POO_NATURAL_RESERVE_POSITION_H
