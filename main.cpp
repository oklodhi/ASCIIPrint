#include <iostream>
#include <cstdlib>
#include <fstream>

#include "CImg-2.3.4_pre072618/CImg.h"

using namespace std;
using namespace cimg_library;

int main() {

    /* Open "asciidog.jpg" as image object */
    CImg <unsigned char> image("wwalczyszyn.png");

    /* Get image dimensions and color channels */
    int imageWidth = image.width();
    int imageHeight = image.height();
    int imageSpec = image.spectrum();

    /* Check for valid image & print dimensions */
    if (image != NULL) {
        cout << "Successfully loaded image!" << endl;
        cout << "Image Size: " << imageWidth << " x " << imageHeight << " \t" << imageSpec << " channels" << endl;
    } else {
        cout << "Error: invalid image!" << endl;
    }

    /* Load pixel RGB data into 2D array
     Convert RBG tuples into brightness numbers
     Convert brightness matrix to ASCII matrix */
    int pixel_matrix_red[imageWidth][imageHeight];
    int pixel_matrix_green[imageWidth][imageHeight];
    int pixel_matrix_blue[imageWidth][imageHeight];

    int brightness_matrix[imageWidth][imageHeight];

    char ascii_matrix[imageWidth][imageHeight];
    string ascii_string = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    float brightness_to_ascii_ratio = 4;

    cout << "Iterating through pixels... " << endl << endl;
    cout << "Brightness matrix size: " << imageWidth << " x " << imageHeight << endl;
    cout << "Iterating through pixel brightnesses... " << endl << endl;
    cout << "Size of ASCII string: " << ascii_string.size() << endl << endl;

    //for (int s = 0; s < ascii_string.size(); s++) {
        //cout << ascii_string[s] << endl;
    //}

    for (int w = 0; w < imageWidth; w++) {
        for (int h = 0; h < imageHeight; h++) {
            pixel_matrix_red[w][h] = image(w, h, 0, 0);
            pixel_matrix_green[w][h] = image(w, h, 0, 1);
            pixel_matrix_blue[w][h] = image(w, h, 2);
            //cout << "(" << pixel_matrix_red[w][h] << ", " << pixel_matrix_green[w][h] << ", " << pixel_matrix_blue[w][h] << ")" << endl;

            brightness_matrix[w][h] = (pixel_matrix_red[w][h] + pixel_matrix_green[w][h] + pixel_matrix_blue[w][h]) / 3;
            // cout << brightness_matrix[w][h] << endl;

            int current_ascii_num = round(brightness_matrix[w][h] / brightness_to_ascii_ratio);
            ascii_matrix[w][h] = ascii_string[round(brightness_matrix[w][h] / brightness_to_ascii_ratio)];
        }
    }

    cout << "Done!" << endl;

    /* TEST: find smallest & largest value in brightness matrix
    int brightness_smallest = 255;
    int brightness_largest = 0;
    for (int a = 0; a < imageWidth; a++) {
        for (int b = 0; b < imageHeight; b++) {
            if (brightness_matrix[a][b] < brightness_smallest) {
                brightness_smallest = brightness_matrix[a][b];
            }
        }
    }
    for (int a = 0; a < imageWidth; a++) {
        for (int b = 0; b < imageHeight; b++) {
            if (brightness_matrix[a][b] > brightness_largest) {
                brightness_largest = brightness_matrix[a][b];
            }
        }
    }
    cout << "The smallest value in brightness matrix is: " << brightness_smallest << endl;
    cout << "The largest value in brightness matrix is: " << brightness_largest << endl; */

    /* TEST: find smallest and largest value in ASCII matrix
    int ascii_smallest = 255;
    int ascii_largest = 0;
    for (int a = 0; a < imageWidth; a++) {
        for (int b = 0; b < imageHeight; b++) {
            if (ascii_matrix[a][b] < ascii_smallest) {
                ascii_smallest = ascii_matrix[a][b];
            }
        }
    }
    for (int a = 0; a < imageWidth; a++) {
        for (int b = 0; b < imageHeight; b++) {
            if (ascii_matrix[a][b] > ascii_largest) {
                ascii_largest = ascii_matrix[a][b];
            }
        }
    }
    cout << "The smallest value in ASCII matrix is: " << ascii_smallest << endl;
    cout << "The largest value in ASCII matrix is: " << ascii_largest << endl; */

    /* Print ASCII art to a text file */
    ofstream output;
    output.open("FINAL_ASCII_ART.txt");

    for (int h = 0; h < imageHeight; h++) {
        for (int w = 0; w < imageWidth; w++) {
            output << ascii_matrix[w][h] << ascii_matrix[w][h];
        }
        output << endl;
    }

    output.close();
    return 0;
}
