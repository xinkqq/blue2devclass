//
// Created by xinkq on 04/08/22.
//

#include "dev_class.h"
#include "remote_device.h"

std :: vector<remote_device> scan(){
    int local_device_id = hci_get_route(NULL);
    if(local_device_id < 0){
        spdlog :: error("No bluetooth device, turn on bluetooth or make sure that device is working properly\n");
        exit(HCI_DEVICE_NOT_FOUND);
    }
    spdlog::info("Scanning..");
    inquiry_info *devices_buffer = (inquiry_info*)malloc(255 * sizeof(inquiry_info));
    int devices_value = hci_inquiry(local_device_id,8,255,NULL,&devices_buffer,IREQ_CACHE_FLUSH);
    if(devices_value < 0){
        spdlog :: error("HCI inquiry failed\n");
        exit(HCI_INQUIRY_FAILED);
    }
    spdlog :: info("Found {} devices",devices_value);
    int local_device_socket = hci_open_dev(local_device_id);
    if(local_device_socket < 0){
        spdlog :: error("Can't use device");
        exit(HCI_SOCK_FAILED);
    }
    std :: vector<remote_device> remote_devices;
    remote_devices.reserve(devices_value + 2);
    for(int i = 0; i < devices_value;i++){
        inquiry_info *current_device_buff = devices_buffer + i;
        remote_device device(current_device_buff,local_device_socket);
        remote_devices.emplace_back(device);
    }
    close(local_device_socket);
    free(devices_buffer);
    return remote_devices;
}