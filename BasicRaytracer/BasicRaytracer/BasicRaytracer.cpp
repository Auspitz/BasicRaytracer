// HelloRaytracingWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "Vector3.h"
#include "Ray.h"

/* Line equation: p(t) = A + t*B
	Taking normalized(0..1) vector,
	t - linear interpolation value, if x - left to right, y - from bottom to top
	returns gradient that fills screen according to t
*/
Vector3 color_ray(const Ray &r) {
	Vector3 unit_direction = unit_vector(r.direction());
	double t = 0.5*(unit_direction.y() + 1.0);
	return (1.0 - t) * Vector3(1.0, 1.0, 1.0) + t * Vector3(0.5, 0.7, 1);
}

// create .ppm file
void create_image(int width, int height, std::string name) {
	std::ofstream output_file;

	// Header
	// "P3" means this is a RGB color image in ASCII
	std::cout << "P3" << "\n";
	//"width height" is the width and height of the image in pixels
	std::cout << width << " " << height << "\n";
	//"255" is the maximum value for each color
	std::cout << "255" << "\n";

	output_file.open(name);

	output_file << "P3" << "\n" << width << " " << height << "\n" << "255" << "\n";

	// Create plane with "camera" that sits in origin
	Vector3 lower_left_corner(-2.0, -1.0, -1.0);
	Vector3 horizontal(4.0, 0.0, 0.0);
	Vector3 vertical(0.0, 2.0, 0.0);
	Vector3 origin(0.0, 0.0, 0.0);

	for (int i = height; i > 0; i--) {
		for (int j = 0; j < width; j++) {

			double u = static_cast<double>(j) / static_cast<double>(width);
			double v = static_cast<double>(i) / static_cast<double>(height);

			// Setup raycast, basically a line that hit some plane and produces color result at point
			Ray r(origin, lower_left_corner + u * horizontal + v * vertical);

			// RGB triplets
			Vector3 color = color_ray(r);
			int i_red = static_cast<int>(255.99*color.r());
			int i_green = static_cast<int>(255.99*color.g());
			int i_blue = static_cast<int>(255.99*color.b());

			output_file << i_red
				<< " "
				<< i_green
				<< " "
				<< i_blue
				<< "\n";
		}
	}

	output_file.close();
}

int main()
{
	create_image(640, 480, "image_out/RayTest.ppm");
}

