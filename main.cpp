#include <iostream>
#include <stdlib.h>

#include "CImg-2.3.4_pre072618/CImg.h"

using namespace std;
using namespace cimg_library;

int main() {

    /* Open "asciidog.jpg" as image object */
    CImg <unsigned char> image("asciidog.jpg");

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

    /* Load pixel RGB data into 2D array */
    int pixel_matrix_red[imageWidth][imageHeight];
    int pixel_matrix_green[imageWidth][imageHeight];
    int pixel_matrix_blue[imageWidth][imageHeight];

    cout << "Iterating through pixels... ";

    for (int w = 0; w < imageWidth; w++) {
        for (int h = 0; h < imageHeight; h++) {
            pixel_matrix_red[w][h] = image(w, h, 0, 0);
            pixel_matrix_green[w][h] = image(w, h, 0, 1);
            pixel_matrix_blue[w][h] = image(w, h, 2);

            //cout << "(" << pixel_matrix_red[w][h] << ", " << pixel_matrix_green[w][h] << ", " << pixel_matrix_blue[w][h] << ")" << endl;
        }
    }

    cout << "Done!" << endl << endl;

    /* Convert RBG tuples to brightness numbers
    -- using the average of RGB values */
    int brightness_matrix[imageWidth][imageHeight];

    cout << "Brightness matrix size: " << imageWidth << " x " << imageHeight << endl;
    cout << "Iterating through pixel brightnesses... ";

    for (int w = 0; w < imageWidth; w++) {
        for (int h = 0; h < imageHeight; h++) {
            brightness_matrix[w][h] = (pixel_matrix_red[w][h] + pixel_matrix_green[w][h] + pixel_matrix_blue[w][h]) / 3;

            // cout << brightness_matrix[w][h] << endl;
        }
    }

    cout << "Done!" << endl << endl;

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

    /* Convert brightness_matrix to ASCII matrix */
    char ascii_matrix[imageWidth][imageHeight];
    string ascii_string = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    float brightness_to_ascii_ratio = 4;

    cout << "Size of ASCII string: " << ascii_string.size() << endl;

    //for (int s = 0; s < ascii_string.size(); s++) {
        //cout << ascii_string[s] << endl;
    //}

    for (int w = 0; w < imageWidth; w++) {
        for (int h = 0; h < imageHeight; h++) {
            int current_ascii_num = round(brightness_matrix[w][h] / brightness_to_ascii_ratio);
            ascii_matrix[w][h] = ascii_string[round(brightness_matrix[w][h] / brightness_to_ascii_ratio)];
        }
    }

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

    /* Print ASCII art */
    for (int w = 0; w < imageWidth; w++) {
        for (int h = 0; h < imageHeight; h++) {
            cout << ascii_matrix[w][h] << ascii_matrix[w][h] << ascii_matrix[w][h];
        }
    }
    return 0;
}
