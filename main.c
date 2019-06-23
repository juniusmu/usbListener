#include <stdlib.h>
#include <stdio.h>
#include <libusb-1.0/libusb.h>
int main(int argc, char *argv[])
{
	libusb_device **devices;
	libusb_context *context = NULL;

	size_t list;
	size_t i;
	int returnValue;

	returnValue = libusb_init(&context);

	if(returnValue < 0)
	{
		perror("libusb_init");
		exit(1);
	}

	list = libusb_get_device_list(context, &devices);
	if(list < 0)
	{
		fprintf(stderr, "Error in getting device list \n");
		libusb_free_device_list(devices, 1);
		libusb_exit(context);
		exit(1);
	}

	printf("There are %d devices found \n", list);
	for (i = 0; i < 0; i++)
	{
		/* print devices specs */
	}

	libusb_free_device_list(devices, 1);
	libusb_exit(context);
	return 0;
}
