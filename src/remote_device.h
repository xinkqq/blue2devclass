//
// Created by xinkq on 04/08/22.
//

#ifndef BLUE2DEVCLASS_REMOTE_DEVICE_H
#define BLUE2DEVCLASS_REMOTE_DEVICE_H

#include <bitset>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include "dev_class.h"
#include "bit_ops.h"

class remote_device {
private:
    typedef struct services{           //Services that devices may offer
        bool discoverable_mode = false;
        bool le_audio          = false;
        bool positioning       = false;
        bool networking        = false;
        bool rendering         = false;
        bool capturing         = false;
        bool object_transfer   = false;
        bool audio             = false;
        bool telephony         = false;
        bool information       = false;
    }services;

    MAJOR_DEVICE major_class;          //Major class of device
    minor_cl minor_class;              //Sruct with minor classes,depends on major class
    services dev_services;             //Struct with all services that device can offer

    std :: bitset<24> dev_class;       //Received bitset from device
    std :: string     public_name;     //Public name of the device
    std :: string     public_addr;     //Public address of the device
public:
    explicit remote_device(inquiry_info *,int device);
    remote_device(const remote_device &dev);
    ~remote_device() = default;

    std :: vector<std :: string> str_services();
    void set_major_class(MAJOR_DEVICE);
    void set_service(MAJOR_SERVICE);
    void set_minor_class(minor_cl);
    std :: string major_class_str();
    std :: string minor_class_str();

    MAJOR_DEVICE get_major_dev(){
        return this->major_class;
    };
    std :: string get_name(){
        return this->public_name;
    };
    std :: string get_addr(){
        return this->public_addr;
    };
    std :: bitset<24> get_class(){
        return this->dev_class;
    };

};

#endif //BLUE2DEVCLASS_REMOTE_DEVICE_H
