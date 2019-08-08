#include "dvb_map/table.h"

Table::Table(int32_t width, int32_t length, int32_t width_resolution, int32_t length_resolution, bool debug_mode) :
    Map(debug_mode),
    width_(width),
    length_(length)
{
    Matrix temp(width_resolution, length_resolution);
    map_grid_ = &temp;

    map_grid_->displayMatrix();

    std::cout << std::endl << map_grid_->grid_[1][1];
}

Table::Table(int32_t width, int32_t length, int32_t** map, bool debug_mode) :
    Map(debug_mode)
{
    
}

Table::~Table(){}

void Table::add_Robot()
{
    //TO DO
}

void Table::add_Obstacle()
{
    //TO DO
}

bool Table::pose_Available(int32_t x, int32_t y)
{
    bool available = false;

    if( x > 1 ) return true;
}