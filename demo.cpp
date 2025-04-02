#include "aistd/aistd.h"



int main()
{
    std::string imagePath = "test.jpg";
    std::string configPath = "config.json";
    std::string modelPath = "model.rknn";

    // 读取配置参数
    Aistd::Config config = Aistd::ReadConfig(configPath);

    // 初始化
    Aistd::Init(config, modelPath);
    Aistd::SetScoreThresh(0.3);

    // 读取测试图像并执行检测
    cv::Mat image = cv::imread(imagePath);
    float preTime, forwardTime, postTime;
    std::vector<Aistd::Instance> instances = Aistd::Run(image, &preTime, &forwardTime, &postTime);
    printf("detect %d targets, pre time: %.2fms, forward time: %.2fms, post time: %.2fms\n",
           (int)instances.size(), preTime, forwardTime, postTime);

    // 绘制结果并保存
    cv::Mat result = Aistd::PlotInstance(image, instances, config.classNames);
    cv::imwrite("result.jpg", result);

    // 释放
    Aistd::Release();
    return 0;

}