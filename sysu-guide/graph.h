//
// Created by ken on 16-12-5.
//
#ifndef SYSUGUIDE_GRAPH_H
#define SYSUGUIDE_GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXNUM 10  // number of area in sysu
#define MAXINT 65535

class graph {
public:
    graph();

    ~graph();

	// create min path between two vertex
    void dijstra(int Start);

	// create path from start to end and visit areas user wants
    std::vector<int> createPath(int End, std::vector<int> toVisit);

	// in-class function, create a vector storages visit area's orders
    std::vector<int> createVisitList(int End);
    
    int edges[MAXNUM][MAXNUM] = {
            {0,     73,    220,   65535, 750,   65535, 65535, 65535, 500,   65535},
            {73,    0,     100,   400,   800,   65535, 65535, 65535, 65535, 65535},
            {220,   100,   0,     350,   65535, 65535, 450,   65535, 600,    65535},
            {65535, 400,   350,   0,     50,    220,   300,   400,   65535, 550},
            {65535, 65535, 65535, 550,   0,     450,   65535, 450,   65535, 65535},
            {65535, 65535, 65535, 220,   450,   0,     210,   450,   65535, 100},
            {65535, 65535, 450,   65535, 65535, 210,   0,     65535, 65535, 65535},
            {65535, 65535, 65535, 450,   450,   450,   65535, 0,     65535, 500},
            {500,   65535, 600,   65535, 65535, 65535, 65535, 65535, 0,     65535},
            {65535, 65535, 65535, 65535, 65535, 100,   65535, 65535, 65535, 0}};

private:
    int start, end;
    int distance[MAXNUM];
    int precursor[MAXNUM];
};

void decoder(int number);

void output(std::vector<int> &visitList);

#endif
