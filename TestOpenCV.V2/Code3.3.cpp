//#include <opencv2/opencv.hpp>
//using namespace cv;
//void my_mouse_callback(int event, int x, int y,
//    int flags, void* param);
//Rect box;
//bool drawing_box = false;
//void draw_box(Mat* pimg, Rect rect)
//{
//    rectangle(
//        *pimg,
//        Point(box.x, box.y),
//        Point(box.x + box.width, box.y + box.height),
//        Scalar(0x00, 0x00, 0x00));
//}
//int main(int argc, char* argv[])
//{
//    box = Rect(-1, -1, 0, 0);
//    Mat image = Mat(Size(400, 400), CV_8UC3,
//        Scalar(0xff, 0xff, 0xff));
//    Mat temp = image.clone();
//    namedWindow("Box Example");
//    setMouseCallback("Box Example", my_mouse_callback,
//        (void*)&image);
//    while (1)
//    {
//        image.copyTo(temp);
//        if (drawing_box) draw_box(&temp, box);
//        imshow("Box Example", temp);
//        if (waitKey(15) == 27) break;
//    }
//    destroyWindow("Box Example");
//}
//void my_mouse_callback(int event, int x, int y,
//    int flags, void* param)
//{
//    Mat* pimg = (Mat*)param;
//    switch (event)
//    {
//    case EVENT_MOUSEMOVE:
//        if (drawing_box)
//        {
//            box.width = x - box.x;
//            box.height = y - box.y;
//        }
//        break;
//    case EVENT_LBUTTONDOWN:
//        drawing_box = true;
//        box = Rect(x, y, 0, 0);
//        break;
//    case EVENT_LBUTTONUP:
//        drawing_box = false;
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
//        draw_box(pimg, box);
//        break;
//    }
//}
