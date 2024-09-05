//#include <opencv2/opencv.hpp>
//using namespace cv;
//void mouseCallback (int event, int x, int y,
//    int flags, void* param);
//
//Point pointLineStart;
//Point pointLineFinish;
//bool startDraw;
//bool lineDraw;
//double lineBlack;
//
//void drawLine(Mat* pimg)
//{
//    line(
//        *pimg,
//        pointLineStart,
//        pointLineFinish,
//        Scalar(lineBlack, lineBlack, lineBlack));
//}
//
//int ain(int argc, char* argv[])
//{
//    Mat image = Mat(Size(500, 500), CV_8UC3,
//        Scalar(0xff, 0xff, 0xff));
//
//    Mat temp = image.clone();
//    namedWindow("Line Example");
//    setMouseCallback("Line Example", mouseCallback,
//        (void*)&image);
//    while (1)
//    {
//        image.copyTo(temp);
//        if (lineDraw) drawLine(&temp);
//        imshow("Line Example", temp);
//        if (waitKey(15) == 27) break;
//    }
//    destroyWindow("Line Example");
//}
//
//void mouseCallback (int event, int x, int y,
//    int flags, void* param)
//{
//    Mat* pimg = (Mat*)param;
//    switch (event)
//    {
//    case EVENT_MOUSEMOVE:
//        if (startDraw)
//        {
//            pointLineFinish.x = x;
//            pointLineFinish.y = y;
//        }
//        break;
//    case EVENT_LBUTTONDOWN:
//        if (!startDraw)
//        {
//            pointLineStart.x =
//                pointLineFinish.x = x;
//            pointLineStart.y =
//                pointLineFinish.y = y;
//            startDraw = true;
//        }
//        lineDraw = true;
//        break;
//    case EVENT_LBUTTONUP:
//        lineDraw = false;
//        drawLine(pimg);
//        pointLineStart.x = pointLineFinish.x;
//        pointLineStart.y = pointLineFinish.y;
//        break;
//    case EVENT_MBUTTONUP:
//        startDraw = lineDraw = false;
//        break;
//    }
//}
