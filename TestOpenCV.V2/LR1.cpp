#include <opencv2/opencv.hpp>
using namespace cv;

void mouseCallback(int event, int x, int y, int flags, void* param);

Point trianglePoints[3];
int pointCount;
bool startDraw;
bool triangleDraw;

void drawTriangle(Mat* pimg)
{
    if (pointCount == 3)
    {
        const Point* pts[1] = { trianglePoints };
        int npts[] = { 3 };

        polylines(*pimg, pts, npts, 1, true, Scalar(0, 0, 255), 2);  
    }
}

int main(int argc, char* argv[])
{
    Mat image = Mat(Size(500, 500), CV_8UC3, Scalar(0xff, 0xff, 0xff)); 
    Mat temp = image.clone();

    namedWindow("Triangle Example");
    setMouseCallback("Triangle Example", mouseCallback, (void*)&image);

    while (1)
    {
        image.copyTo(temp);
        if (triangleDraw) drawTriangle(&temp);
        imshow("Triangle Example", temp);

        if (waitKey(15) == 27) break;
    }

    imwrite("result.png", image);
    destroyWindow("Triangle Example");
}

void mouseCallback(int event, int x, int y, int flags, void* param)
{
    Mat* pimg = (Mat*)param;

    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        if (pointCount < 3)  // Store up to 3 points
        {
            trianglePoints[pointCount] = Point(x, y);
            pointCount++;
            if (pointCount == 3)
            {
                triangleDraw = true;
                drawTriangle(pimg);  // Draw triangle
            }
        }
        break;

    case EVENT_MBUTTONDOWN:
        pointCount = 0;  // Reset 
        break;
    }
}
