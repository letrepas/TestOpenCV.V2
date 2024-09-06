//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//
//Mat averageSmoothing(Mat image, int kSize) {
//    Mat smoothedImage = image.clone();
//    int border = kSize / 2;
//
//    for (int i = border; i < image.rows - border; i++) {
//        for (int j = border; j < image.cols - border; j++) {
//            Scalar sum = Scalar(0, 0, 0);
//            int count = 0;
//
//            for (int k = 0; k < kSize * kSize; k++) {
//                int r = (k / kSize) - border;
//                int c = (k % kSize) - border;
//
//                sum += Scalar(image.at<Vec3b>(i + r, j + c));
//                count++;
//            }
//
//            smoothedImage.at<Vec3b>(i, j) = Vec3b(
//                (sum[0] / count),
//                (sum[1] / count),
//                (sum[2] / count)
//            );
//        }
//    }
//
//    return smoothedImage;
//}
//
//int main() {
//    Mat image = imread("C:/Users/danil/source/repos/TestOpenCV.V2/image/1.tiff");
//    if (image.empty()) return -1;
//
//    imshow("Source", image);
//
//    Mat smoothedImage = averageSmoothing(image, 4);
//    imshow("Blurred Image", smoothedImage);
//
//    Mat smoothedImageByCv;
//    blur(image, smoothedImageByCv, Size(4, 4));
//    imshow("Blurred Image by CV", smoothedImageByCv);
//
//    waitKey(0);
//    destroyAllWindows();
//
//}
