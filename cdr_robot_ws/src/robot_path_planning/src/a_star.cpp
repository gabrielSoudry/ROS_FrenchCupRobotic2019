#include "robot_path_planning/a_star.h"

Node::Node(Pose pos, Node* parent, Pose destination) :
    pos_(pos),
    parent_(parent),
    destination_(destination)
{
    f_ = g_ = h_ = 0;
}

A_Star::A_Star(Table* map, Pose from, Pose destination) :
    map_(map),
    from_(from),
    destination_(destination)
{
    createAStarMap();
}

void A_Star::findPath()
{

}

void A_Star::createAStarMap()
{
    for (int i = 0; i < map_->map_grid_->rows_; i++)
    {
        for (int j = 0; j < map_->map_grid_->col_; j++)
        {
            Pose pose_tmp;
            pose_tmp.x = i;
            pose_tmp.y = j;

            Node node_tmp(pose_tmp, nullptr, destination_);

            //a_star_map_[i][j] = node_tmp;
        }
    }
}

void A_Star::printPath()
{

}

int main(int argc, char** argv){
    return 0;
}