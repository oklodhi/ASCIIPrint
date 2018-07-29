#include <iostream>

#include "CImg-2.3.4_pre072618/CImg.h"

using namespace std;
using namespace cimg_library;

int main() {

    // open "asciidog.jpg" as image object
    CImg <unsigned char> image("asciidog.jpg");

    // get image dimensions
    int imageWidth = image.width();
    int imageHeight = image.height();
    int imageSpec = image.spectrum();

    // check for valid image and print dimensions
    if (image != NULL) {
        cout << "Successfully loaded image!" << endl;
        cout << "Image Size: " << imageWidth << " x " << imageHeight << " \t" << imageSpec << " channels" << endl << endl;
    } else {
        cout << "Error: invalid image!" << endl;
    }

    // load image pixel data into 2D array
    int pixel_matrix_red[imageWidth][imageHeight];
    int pixel_matrix_green[imageWidth][imageHeight];
    int pixel_matrix_blue[imageWidth][imageHeight];
    cout << "Iterating through pixels: " << endl;
    for (int w = 0; w < imageWidth; w++) {
        for (int h = 0; h < imageHeight; h++) {
            pixel_matrix_red[w][h] = (int)image(w, h, 0, 0);
            pixel_matrix_green[w][h] = (int)image(w, h, 0, 1);
            pixel_matrix_blue[w][h] = (int)image(w, h, 0, 2);
            cout << "(" << pixel_matrix_red[w][h] << ", " << pixel_matrix_green[w][h] << ", " << pixel_matrix_blue[w][h] << ")" << endl;
        }
    }



    return 0;
}
