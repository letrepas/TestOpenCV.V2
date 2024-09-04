#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;int main() {
	Mat img(400, 500, CV_8UC3);//Создание изображения имеющее размер 500 в ширину на 400 в высоту. 

	//Для удобства, аргументы вызываемой функции: 
	string text = "Hello World!";//Целевая фраза. 
	Point textOrg(100, img.rows / 2);//Местоположение. 
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;//Фонт. 
	double fontScale = 2;//Его масштаб, размер. 
	Scalar color(200, 100, 50);//Цвет текста. 

	//Далее выполняется отрисовка фразы из переменной 
	//text в изображение img в положение textOrg. 
	//Фонт/гарнитура задается следующими переменными: 
	//fontFace, fontScale, thickness. 
	putText(img, text, textOrg, fontFace, fontScale,
		color);

	imshow("My World", img);
	waitKey(0);

	return 0;
}