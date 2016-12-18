#include "UI.cpp"
#define STUDENT_NUMBER 80


int main() {
// 80 student's id in "ids"
    int ids[] = {
            15331186, 15331187, 15331188, 15331189, 15331190, 15331191, 15331192, 15331193,
            15331194, 15331195, 15331196, 15331197, 15331198, 15331199, 15331200, 15331201,
            15331202, 15331203, 15331204, 15331205, 15331206, 15331207, 15331208, 15331209,
            15331210, 15331211, 15331212, 15331213, 15331214, 15331215, 15331216, 15331217,
            15331218, 15331219, 15331220, 15331221, 15331222, 15331223, 15331224, 15331225,
            15331226, 15331227, 15331228, 15331229, 15331230, 15331231, 15331232, 15331233,
            15331234, 15331235, 15331236, 15331237, 15331238, 15331239, 15331240, 15331241,
            15331242, 15331243, 15331244, 15331245, 15331246, 15331247, 15331248, 15331249,
            15331250, 15331251, 15331252, 15331253, 15331254, 15331255, 15331256, 15331257,
            15331258, 15331259, 15331260, 15331261, 15331262, 15331263, 15331264, 15331265
    };

    std::string names[] = {
            "liangyidong", "liangzhihao", "liaoqiongxiang", "liaowenjun", "liaoyinghong", "liaozelin", "liaozexiang",
            "linhongyu", "linjian", "linjiequn", "linjinxia", "linjinghua", "linjingyang", "linkun", "linmiao",
            "linrunqing", "linweihong", "linweihan", "linyiqi", "linzeyun", "linziheng", "linziqi", "linziqin",
            "liubingyun", "liubo", "liufang", "liujunjun", "liujunliang", "liupeidong", "liuyanan", "liuyang",
            "liuyangqi", "liuruanhao", "liuzhaorui", "liuzhongtao", "luhaorong", "lujiaxi", "lujianbin", "lutongjie",
            "luweiyuan", "luguanxing", "luojianjie", "luolijing", "luomiao", "luowenlu", "luoxianzhuo", "luoxiaofeng",
            "mazhaolu", "majianrong", "maxiaohe", "mayiling", "maiweijun", "maozihao", "mingyoufeng", "mohuakun",
            "moyi", "nongyuxin", "oubaichuan", "ouyangjingchao", "panchengyuan", "panyaoxin", "pangjinglong",
            "pengcaiying", "pengchen", "penggao", "pengyifeng", "pusiyu", "qianhang", "qiuxiaofneg", "qiuxushuan",
            "quliaofei", "raoyuxin", "renhaoen", "renhongkun", "renjiaxin", "renlei", "renshijie", "shaobaiqin",
            "shaojiaxu", "sheying"
    };

    bool gender[] = {
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1,
            1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1,
            1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0
    };

    table students;
    for (int i = 0; i < STUDENT_NUMBER; ++i) {
        Person *person = new Person(names[i], gender[i], ids[i]);
        students.insert(person);
    }

    UI ui(&students);
    ui.hint();

    int order;
    while (std::cin >> order) {
        switch (order) {
            case 1:
                ui.insert();
                break;

            case 2:
                ui.erase();
                break;

            case 3:
                ui.search();
                break;

            case 4:
                ui.showTable();
                break;

            case 5:
                ui.getSize();
                break;

            case 0:
                std::cout << "谢谢您的使用!\n";
                exit(1);

            default:
                std::cout << "命令无效,请输入命令表中的命令!\n";
                break;
        }
    }
    return 0;
}

/*
 int main() {
        int nameSize = 0;
        while (names[nameSize] != "sheying") {
                ++nameSize;
        }
        std::cout << "name size is " << nameSize + 1 << ' ' << names[nameSize] << std::endl;
        std::cout << "ids size is " << sizeof(ids) / sizeof(ids[0]) << std::endl;
        table students;
        int peopleSize;
        std::cin >> peopleSize;
        for (int i = 0; i < peopleSize; ++i) {
                std::string name;
                bool male;
                int id;
                std::cin >> name >> male >> id;
                Person* person = new Person(name, male, id);
                students.insert(person);
        }
        std::cout << "-------------------------------\n\n";
        students.showTable();
        std::string name;
        while (std::cin >> name) {
                std::cout << students.search(name) << std::endl;
        }
        return 0;
}
*/
