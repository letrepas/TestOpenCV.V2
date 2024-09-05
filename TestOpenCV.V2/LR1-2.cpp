//#include <opencv2/opencv.hpp>
//using namespace cv;
//void mouseCallback(int event, int x, int y, int flags, void* param);
//
//Rect box;
//bool drawingBox;
//
//void drawBox(Mat* pimg, Rect rect)
//{
//    rectangle(
//        *pimg,
//        rect,
//        Scalar(0x00, 0x00, 0x00));
//}
//
//int main(int argc, char** argv)
//{
//    Mat image = imread("C:/Users/danil/source/repos/TestOpenCV.V2/image/1.tiff"); 
//    if (image.empty()) return -1;
//
//    namedWindow("2");
//    setMouseCallback("2", mouseCallback, (void*)&image);
//
//    while (1)
//    {
//        Mat temp = image.clone(); 
//        if (drawingBox) drawBox(&temp, box);
//        imshow("2", temp);
//        if (waitKey(15) == 27) break;
//    }
//
//    destroyWindow("2");
//}
//
//void mouseCallback(int event, int x, int y, int flags, void* param)
//{
//    Mat* pimg = (Mat*)param;
//
//    switch (event)
//    {
//
//    case EVENT_MOUSEMOVE:
//        if (drawingBox)
//        {
//            box.width = x - box.x;
//            box.height = y - box.y;
//        }
//        break;
//
//    case EVENT_LBUTTONDOWN:
//        drawingBox = true;
//        box = Rect(x, y, 0, 0);
//        break;
//
//    case EVENT_LBUTTONUP:
//        drawingBox = false;
//        if (box.width < 0)
//        {
//            box.x += box.width;
//            box.width *= -1;
//        }
//        if (box.height < 0)
//        {
//            box.y += box.height;
//            box.height *= -1;
//        }
//        drawBox(pimg, box);        
//
//        Mat selectedRegion = (*pimg)(box).clone(); 
//        imwrite("result1-2.png", selectedRegion); 
//        break;
//    }
//}
