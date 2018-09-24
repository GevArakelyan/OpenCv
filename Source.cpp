#include <boost/gil.hpp>
#include <boost/gil/extension/dynamic_image/any_image.hpp>
#include <boost/gil/extension/io/jpeg.hpp>
#include <boost/gil/extension/io/png.hpp>
#include <boost/mpl/vector.hpp>
#include <iostream>
#include <algorithm>

int main()
{
	namespace bg = boost::gil;

	using my_images_t = boost::mpl::vector<bg::gray8_image_t, bg::rgb8_image_t, bg::gray16_image_t, bg::rgb16_image_t>;
	bg::any_image<my_images_t> dynamic_image;
	bg::rgb8_image_t image;
	bg::read_image("image.png", image, bg::png_tag());
	// Save the image upside down, preserving its native color space and channel depth
	bg::rgb8_pixel_t pixel;
	

	




	auto view = bg::flipped_up_down_view(bg::const_view(dynamic_image));
	bg::write_view("out-dynamic_image.jpg", view, bg::jpeg_tag());
}
