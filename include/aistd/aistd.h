#ifndef _AISTD_H_
#define _AISTD_H_

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
namespace Aistd {


struct Instance {
    int x;                                                      //目标左上角x坐标
    int y;                                                      //目标左上角y坐标
    int w;                                                      //目标框宽度
    int h;                                                      //目标框高度
    float score;                                                //目标置信度
    int classId;                                                //目标类别ID
    cv::Mat mask;                                               //目标分割mask(与目标尺寸相同),检测任务该值为空
};


struct Config {
    int taskType;
    int modelType;
    int modelWidth;
    int modelHeight;
    std::vector<int> strides;
    std::vector<std::string> classNames;
};

// 用于读取设置相关检测参数, 也可手动设置
Config ReadConfig(std::string configFilePath);  //configFilePath: 模型导出时生成的config.json文件


// 初始化接口，用于加载模型和设置相关检测参数
int Init(Config config, std::string modelPath);



// 执行检测的接口，输入图像，返回检测得到的目标
std::vector<Instance> Run(const cv::Mat& image,
                          float* preTime,          //非空时统计预处理时间
                          float* forwardTime,      //非空时统计推理时间
                          float* postTime);        //非空时统计后处理时间


// 设置置信度阈值
void SetScoreThresh(float scoreThresh); // default 0.5


// 设置nms的iou阈值
void SetNmsIouThresh(float iouThresh);  // default 0.7


// 释放检测器
int Release();


cv::Mat PlotInstance(const cv::Mat& image,
                     std::vector<Instance> &instances,
                     std::vector<std::string> classNames);


}
#endif  // _AISTD_H_