#ifndef DEF_TABLE_H
#define DEF_TABLE_H

#include "dvb_map/map.h"

class Matrix
{
    public:
        Matrix(int32_t nbRow, int32_t nbCol) :
                rows_(nbRow),
                col_(nbCol)
        {
                std::vector<std::vector<int32_t>> temp(nbRow, std::vector<int32_t>(nbCol, 0));
                grid_ = temp;
                initMatrix();
        }

        void initMatrix()
        {
            for(int i = 0; i < rows_; i++){
                for(int j = 0; j < col_; j++){
                    grid_[i][j] = 0;
                }
            }
        }

        void displayMatrix()
        {
            for(int i = 0; i < rows_; i++){
                for(int j = 0; j < col_; j++){
                    std::cout << grid_[i][j] << "   ";
                }
                std::cout << std::endl;
            }
        }

        std::vector<std::vector<int32_t>> grid_;

        int32_t rows_, col_;
};

class Table: public Map
{
    public:
        Table(int32_t width, int32_t length, int32_t width_resolution, int32_t length_resolution, bool debug_mode);
        Table(int32_t width, int32_t length, int32_t** map_grid, bool debug_mode);
        virtual ~Table();

        void add_Robot();
        void add_Obstacle();
        
        bool pose_Available(int32_t x, int32_t y);

        Matrix* map_grid_;

    private:
        bool debug_mode_;
        //Robot* robot;

        int32_t width_;
        int32_t length_;
        
        
};

#endif