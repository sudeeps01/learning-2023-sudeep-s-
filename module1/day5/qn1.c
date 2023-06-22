#include <stdio.h>

struct Box {
    float length;
    float width;
    float height;
};

float calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

float calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
}

int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox; // Pointer to the structure

    printf("Enter the length of the box: ");
    scanf("%f", &(boxPtr->length));

    printf("Enter the width of the box: ");
    scanf("%f", &(boxPtr->width));

    printf("Enter the height of the box: ");
    scanf("%f", &(boxPtr->height));

    // Calculate the volume and surface area using structure pointers and operators
    float volume = calculateVolume(boxPtr);
    float surfaceArea = calculateSurfaceArea(boxPtr);

    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
