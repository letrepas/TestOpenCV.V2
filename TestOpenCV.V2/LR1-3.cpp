#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

void mouseCallback(int event, int x, int y, int flags, void* param);
void combined();

Rect box;
bool drawingBox;
vector<Mat> selectedRegions;

void drawBox(Mat* pimg, Rect rect)
{
    rectangle(
        *pimg,
        rect,
        Scalar(0x00, 0x00, 0x00));
}

int main(int argc, char** argv)
{
    vector<string> imageFiles = {
        "C:/Users/danil/source/repos/TestOpenCV.V2/image/1.tiff",
        "C:/Users/danil/source/repos/TestOpenCV.V2/image/1.png"
    };

    Mat finalImage;

    for (int i = 0; i < imageFiles.size(); i++)
    {
        string& filePath = imageFiles[i];
        Mat image = imread(filePath);
        if (image.empty()) return -1;

        namedWindow("3");
        setMouseCallback("3", mouseCallback, (void*)&image);

        while (1)
        {
            Mat temp = image.clone();
            if (drawingBox) drawBox(&temp, box);
            imshow("3", temp);
            if (waitKey(15) == 27) break;
        }

        destroyWindow("3");
        
        combined();
    }
}


void mouseCallback(int event, int x, int y, int flags, void* param)
{
    Mat* pimg = (Mat*)param;

    switch (event)
    {

    case EVENT_MOUSEMOVE:
        if (drawingBox)
        {
            box.width = x - box.x;
            box.height = y - box.y;
        }
        break;

    case EVENT_LBUTTONDOWN:
        drawingBox = true;
        box = Rect(x, y, 0, 0);
        break;

    case EVENT_LBUTTONUP:
        drawingBox = false;
        if (box.width < 0)
        {
            box.x += box.width;
            box.width *= -1;
        }
        if (box.height < 0)
        {
            box.y += box.height;
            box.height *= -1;
        }
        drawBox(pimg, box);

        selectedRegions.push_back((*pimg)(box).clone());
        break;
    }
}

void combined()
{
    int newWidth = 0;
    int newHeight = 0;

    for (int i = 0; i < selectedRegions.size(); i++)
    {
        Mat& region = selectedRegions[i];
        newWidth += region.cols;
        newHeight = max(newHeight, region.rows);
    }

    Mat finalImage(newHeight, newWidth, CV_8UC3, Scalar(0xff, 0xff, 0xff));
    int currentX = 0;

    for (int i = 0; i < selectedRegions.size(); i++)
    {
        Mat& region = selectedRegions[i];
        Mat target = finalImage(Rect(currentX, 0, region.cols, region.rows));
        region.copyTo(target);
        currentX += region.cols;
    }

    imwrite("result1-3.png", finalImage);
}
