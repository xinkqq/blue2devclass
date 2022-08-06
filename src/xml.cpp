//
// Created by xinkq on 05/08/22.
//

#include "remote_device.h"


std :: string cr_xml(std :: vector<remote_device> &devices){
    std :: string xml_str {"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"};
    xml_str.append("<devices>\n");
    for(auto &i : devices){
        xml_str.append(" <device>\n");
        xml_str.append("  <name>");
        xml_str.append(i.get_name());
        xml_str.append("</name>\n");
        xml_str.append("  <address>");
        xml_str.append(i.get_addr());
        xml_str.append("</address>\n");
        xml_str.append("  <services>\n");
        std :: vector<std :: string> str_services = i.str_services();
        for(auto &j : str_services){
            xml_str.append("   <service>");
            xml_str.append(j);
            xml_str.append("</service>\n");
        }
        xml_str.append("  </services>\n");
        xml_str.append("  <major_class>");
        xml_str.append(i.major_class_str());
        xml_str.append("</major_class>\n");
        xml_str.append("  <minor_class>");
        xml_str.append(i.minor_class_str());
        xml_str.append("</minor_class>\n");
        xml_str.append(" </device>\n");
    }
    xml_str.append("</devices>");
    return xml_str;
}