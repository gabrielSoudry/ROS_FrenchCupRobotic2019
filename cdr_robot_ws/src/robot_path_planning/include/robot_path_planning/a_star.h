#ifndef DEF_A_STAR_H
#define DEF_A_STAR_H

#include "dvb_map/table.h"

#include <stack>

typedef geometry_msgs::Pose2D Pose;

class Node
{
    public:
        Node(Pose pos, Node* parent, Pose destination);

        bool isNodeValid();
        bool isNodeBlocked();
        bool isNodeDestination();

        float_t calculH();

    private:
        Pose pos_;
        float_t f_, g_, h_;

        Node* parent_;

        Pose destination_;
};

typedef std::vector<std::vector<Node>> A_Star_Map;

class A_Star
{
    public:
        A_Star(Table* map, Pose from, Pose destination);

        void findPath();

        void createAStarMap();
        void printPath();

        //to do getPath()
    private:
        Table* map_;
        A_Star_Map* a_star_map_;

        Pose from_;
        Pose destination_;

        std::stack<Pose> closedList_;
        std::stack<Pose> openList_;
};

#endif