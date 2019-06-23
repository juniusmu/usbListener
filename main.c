#include <stdlib.h>
#include <stdio.h>
#include <libusb-1.0/libusb.h>

void printDevices(libusb_device *device)
{
	struct libusb_device_descriptor deviceDescriptor;
	struct libusb_config_descriptor *configDescriptor;
	const struct libusb_interface *interface;
	const struct libusb_interface_descriptor *interfaceDescriptor;
	const struct libusb_endpoint_descriptor *endpointDescriptor;

	int returnValue;
	int i,j,k;

	returnValue = libusb_get_device_descriptor(device, &deviceDescriptor);

	if( returnValue < 0)
	{
		fprintf(stderr, "error in getting device descriptor");
		return;
	}

	printf("Number of pos configs is %d\n", deviceDescriptor.bNumConfigurations);
	printf("Device class: %d\n", deviceDescriptor.idVendor);
	printf("Product ID: %d\n", deviceDescriptor.idProduct);

	libusb_get_config_descriptor(device, 0, &configDescriptor);
	printf("Interface: %d\n", configDescriptor->bNumInterfaces);

	printf("\n\n");
}

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

	printf("There are %zu devices found \n\n", list);
	for (i = 0; i < list; i++)
	{
		/* print devices specs */
		printDevices(devices[i]);
	}

	libusb_free_device_list(devices, 1);
	libusb_exit(context);
	return 0;
}
