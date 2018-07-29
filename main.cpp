#include <iostream>

#include "CImg-2.3.4_pre072618/CImg.h"

using namespace std;
using namespace cimg_library;

int main() {

    // open "asciidog.jpg" as image object
    CImg <unsigned char> image("asciidog.jpg");

    // get image dimensions and color channels
    int imageWidth = image.width();
    int imageHeight = image.height();
    int imageSpec = image.spectrum();

    // check for valid image & print dimensions
    if (image != NULL) {
        cout << "Successfully loaded image!" << endl;
        cout << "Image Size: " << imageWidth << " x " << imageHeight << " \t" << imageSpec << " channels" << endl << endl;
    } else {
        cout << "Error: invalid image!" << endl;
    }

    // load pixel RGB data into 2D array
    int pixel_matrix_red[imageWidth][imageHeight];
    int pixel_matrix_green[imageWidth][imageHeight];
    int pixel_matrix_blue[imageWidth][imageHeight];

    //cout << "Iterating through pixels: " << endl;

    for (int w = 0; w < imageWidth; w++) {
        for (int h = 0; h < imageHeight; h++) {
            pixel_matrix_red[w][h] = image(w, h, 0, 0);
            pixel_matrix_green[w][h] = image(w, h, 0, 1);
            pixel_matrix_blue[w][h] = image(w, h, 2);

            //cout << "(" << pixel_matrix_red[w][h] << ", " << pixel_matrix_green[w][h] << ", " << pixel_matrix_blue[w][h] << ")" << endl;
        }
    }

    // convert RBG tuples to brightness numbers
    // -- using the average of RGB values
    int brightness_matrix[imageWidth][imageHeight];

    cout << "Brightness matrix size: " << imageWidth << " x " << imageHeight << endl;
    cout << "Iterating through pixel brightnesses: " << endl;

    for (int w = 0; w < imageWidth; w++) {
        for (int h = 0; h < imageHeight; h++) {
            brightness_matrix[w][h] = (pixel_matrix_red[w][h] + pixel_matrix_green[w][h] + pixel_matrix_blue[w][h]) / 3;

            // cout << brightness_matrix[w][h] << endl;
        }
    }

    // find smallest & largest value in brightness matrix
    int temp_smallest = 255;
    int temp_largest = 0;
    for (int a = 0; a < imageWidth; a++) {
        for (int b = 0; b < imageHeight; b++) {
            if (brightness_matrix[a][b] < temp_smallest) {
                temp_smallest = brightness_matrix[a][b];
            }
        }
    }
    for (int a = 0; a < imageWidth; a++) {
        for (int b = 0; b < imageHeight; b++) {
            if (brightness_matrix[a][b] > temp_largest) {
                temp_largest = brightness_matrix[a][b];
            }
        }
    }
    cout << "The smallest value in brightness matrix is: " << temp_smallest << endl;
    cout << "The largest value in brightness matrix is: " << temp_largest << endl;


    string ascii_string = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    int ascii_chars_iteration = 4;
    for (int s = 0; s < ascii_string.size(); s++) {
        //cout << ascii_string[s] << endl;
    }

    // convert brightness matrix to ASCII characters
    for (int w = 0; a < imageWidth; a++) {
        for (int h = 0; b < imageHeight; b++) {

        }
    }



    return 0;
}
