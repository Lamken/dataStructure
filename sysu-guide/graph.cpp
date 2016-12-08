//
// Created by ken on 16-12-5.
//
#include "graph.h"

graph::graph() {}

graph::~graph() {}

void graph::dijstra(int Start) {
    start = Start;
    bool isVisited[MAXNUM] = {0};
    for (int i = 0; i < MAXNUM; ++i) {
        distance[i] = edges[start][i];
        precursor[i] = (distance[i] == MAXINT ? -1 : start);
    }
    isVisited[start] = 1;

    for (int i = 0; i < MAXNUM - 1; ++i) {
        int closestVertexPosition, minDistance = MAXINT;
        for (int j = 0; j < MAXNUM; ++j) {
            if (!isVisited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                closestVertexPosition = j;
            }
        }
        if (minDistance == 65535) break;
        isVisited[closestVertexPosition] = 1;

        for (int j = 0; j < MAXNUM; ++j) {
            if (!isVisited[j] && \
                    edges[closestVertexPosition][j] + distance[closestVertexPosition] < distance[j]) {
                distance[j] = edges[closestVertexPosition][j] + distance[closestVertexPosition];
                precursor[j] = closestVertexPosition;
            }
        }
    }
}

std::vector<int> graph::createPath(int End, std::vector<int> toVisit) {
    end = End;
    std::vector<int> visitList = this->createVisitList(End);
    if (start == End) {
        visitList.clear();
        visitList.push_back(start);
        visitList.push_back(start);
    }
    if (toVisit.size() == 0)
        return visitList;
    bool isVisited[toVisit.size()] = {0};
    for (int i = 0; i < visitList.size(); ++i) {
        for (int j = 0; j < toVisit.size(); ++j) {
            if (visitList[i] == toVisit[j])
                isVisited[j] = 1;
        }
    }

    for (int i = 0; i < toVisit.size(); ++i) {
        if (isVisited[i]) continue;
        int minLength = MAXINT;
        std::vector<int>::iterator insertPosition = visitList.end();
        graph tempGraph;
        tempGraph.dijstra(toVisit[i]);
        for (std::vector<int>::iterator it = visitList.begin(); it != visitList.end() - 1; ++it) {
            if (tempGraph.distance[*it] + tempGraph.distance[*(it + 1)] < minLength) {
                minLength = tempGraph.distance[*it] + tempGraph.distance[*(it + 1)];
                insertPosition = it;
            }
        }
        std::vector<int> insertList = tempGraph.createVisitList(*insertPosition);
        std::vector<int> insertList1 = tempGraph.createVisitList(*(insertPosition + 1));
        insertList.erase(insertList.end() - 1);
        insertList1.erase(insertList1.begin());
        insertList1.erase(insertList1.end() - 1);
        std::reverse(insertList.begin(), insertList.end());
        insertList.insert(insertList.end(), insertList1.begin(), insertList1.end());
        for (int j = 0; j < insertList.size(); ++j) {
            for (int k = 0; k < toVisit.size(); ++k) {
                if (insertList[j] == toVisit[k])
                    isVisited[k] = 1;
            }
        }


        visitList.insert(insertPosition + 1, insertList.begin(), insertList.end());
    }
    return visitList;
}

std::vector<int> graph::createVisitList(int End) {
    int tempVertex = End;
    std::vector<int> visitList;
    visitList.push_back(End);
    while (tempVertex != start) {
        visitList.push_back(precursor[tempVertex]);
        tempVertex = precursor[tempVertex];
    }
    std::reverse(visitList.begin(), visitList.end());
    return visitList;
}

void decoder(int number) {
    switch (number) {
        case 0:
            std::cout << "正门";
            break;
        case 1:
            std::cout << "铜像";
            break;
        case 2:
            std::cout << "公教楼";
            break;
        case 3:
            std::cout << "图书馆";
            break;
        case 4:
            std::cout << "实验楼";
            break;
        case 5:
            std::cout << "体育馆";
            break;
        case 6:
            std::cout << "真草";
            break;
        case 7:
            std::cout << "假草";
            break;
        case 8:
            std::cout << "软件学院楼";
            break;
        case 9:
            std::cout << "新天地";
            break;
    }
}

void output(std::vector<int>& visitList) {
    for (int i = 0; i < visitList.size()-1; ++i) {
        decoder(visitList[i]);
        std::cout << "->";
    }
    decoder(visitList[visitList.size()-1]);
    std::cout << std::endl;
}

