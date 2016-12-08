#include "graph.cpp"

void hint() {
    std::cout << "----------------------------------\n"
              << "欢迎使用中大导游系统，地点与其代号如下所示:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << i << ':';
        decoder(i);
        std::cout << std::endl;
    }
    std::cout << "----------------------------------\n";
}

int main() {
    int start, end;
    hint();
    std::cout << "\n请输入您的起点: ";
    std::cin >> start;
    std::cout << "添加起点 ";
    decoder(start);
    std::cout << " 成功！\n";
    std::cout << "\n请输入您的终点: ";
    std::cin >> end;
    std::cout << "添加终点 ";
    decoder(end);
    std::cout << " 成功！\n\n";
    graph sysu;
    sysu.dijstra(start);
    std::vector<int> toVisit;
    int tempVisitPosition;
    std::cout << "以下请您分别输入您想要游览的地点,输入-1开始定制路线\n\n";
    while (1) {
        std::cout << "您想要游览的地点是: ";
        std::cin >> tempVisitPosition;
        if (tempVisitPosition > 9 || tempVisitPosition < -1) {
            std::cout << "您输入的序号 " << tempVisitPosition << "不存在\n";
            continue;
        } else if (tempVisitPosition == -1) break;
        bool repeat = false;
        for (int i = 0; i < toVisit.size(); ++i) {
            if (toVisit[i] == tempVisitPosition) {
                repeat = true;
                break;
            }
        }
        if (!repeat) {
            toVisit.push_back(tempVisitPosition);
            std::cout << "添加目的地点 ";
            decoder(tempVisitPosition);
            std::cout << " 成功！\n\n";
        } else {
            std::cout << "您添加目的地点 ";
            decoder(tempVisitPosition);
            std::cout << " 已存在！\n\n";
        }
    }

    std::cout << "----------------------------------\n";
    std::cout << "以下是为您定制的路线:\n";
    std::cout << "步行路线:\n";
    std::vector<int> result = sysu.createPath(end, toVisit);
    output(result);
    std::cout << std::endl;
    std::cout << "驾车路线:\n";
    sysu.edges[1][3] = sysu.edges[3][1] = MAXINT;
    sysu.edges[8][9] = sysu.edges[9][8] = 300;
    result = sysu.createPath(end, toVisit);
    output(result);
    std::cout << "----------------------------------\n";
    return 0;

