#include "graph.cpp"

void hint() {
    std::cout << "----------------------------------\n"
              << "��ӭʹ���д���ϵͳ���ص��������������ʾ:\n";
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
    std::cout << "\n�������������: ";
    std::cin >> start;
    std::cout << "������ ";
    decoder(start);
    std::cout << " �ɹ���\n";
    std::cout << "\n�����������յ�: ";
    std::cin >> end;
    std::cout << "����յ� ";
    decoder(end);
    std::cout << " �ɹ���\n\n";
    graph sysu;
    sysu.dijstra(start);
    std::vector<int> toVisit;
    int tempVisitPosition;
    std::cout << "���������ֱ���������Ҫ�����ĵص�,����-1��ʼ����·��\n\n";
    while (1) {
        std::cout << "����Ҫ�����ĵص���: ";
        std::cin >> tempVisitPosition;
        if (tempVisitPosition > 9 || tempVisitPosition < -1) {
            std::cout << "���������� " << tempVisitPosition << "������\n";
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
            std::cout << "���Ŀ�ĵص� ";
            decoder(tempVisitPosition);
            std::cout << " �ɹ���\n\n";
        } else {
            std::cout << "�����Ŀ�ĵص� ";
            decoder(tempVisitPosition);
            std::cout << " �Ѵ��ڣ�\n\n";
        }
    }

    std::cout << "----------------------------------\n";
    std::cout << "������Ϊ�����Ƶ�·��:\n";
    std::cout << "����·��:\n";
    std::vector<int> result = sysu.createPath(end, toVisit);
    output(result);
    std::cout << std::endl;
    std::cout << "�ݳ�·��:\n";
    sysu.edges[1][3] = sysu.edges[3][1] = MAXINT;
    sysu.edges[8][9] = sysu.edges[9][8] = 300;
    result = sysu.createPath(end, toVisit);
    output(result);
    std::cout << "----------------------------------\n";
    return 0;

