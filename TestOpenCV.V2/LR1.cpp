#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void mouseCallback(int event, int x, int y, int flags, void* param);

Point trianglePoints[3];
int pointCount = 0;
bool startDraw = false;
bool triangleDraw = false;

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

        int key = waitKey(15);
        if (key == 27) break;
        if (key == 's' || key == 'S')
        {
            imwrite("result.png", image);
            cout << "Saved as triangle_result.png" << endl;
        }
    }

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
                drawTriangle(pimg);  // Draw triangle once all 3 points are set
            }
        }
        break;

    case EVENT_MBUTTONDOWN:
        pointCount = 0;  // Reset triangle drawing with middle mouse button
        //triangleDraw = false;
        break;
    }
}
