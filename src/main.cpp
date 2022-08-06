#include <iostream>

#include "dev_class.h"
#include "remote_device.h"


extern std :: vector<remote_device> scan();

extern int parse_s_major_bitmask(std :: vector<remote_device> &devices);
extern int parse_minor_bitmask(std :: vector<remote_device> &devices);
extern std :: string cr_xml(std :: vector<remote_device> &devices);

int main() {
    std :: shared_ptr<std :: vector<remote_device>> devices = std :: make_shared<std :: vector<remote_device>>(scan());
    if(parse_s_major_bitmask(*devices) == PARSE_ERR){
        spdlog :: error("Parsing major device class\n");
    };
    parse_minor_bitmask(*devices);
    if(!devices->empty()){
        spdlog :: info("Creating xml info");
    }else{
        spdlog :: error("No devices has been founded,can't create xml info");
    }
    std :: string xml_vid = cr_xml(*devices);
    return 0;
}
