#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "SmartDevice.h"
#include <functional>

using Predicate = std:: function< bool (const SmartDevice*)> ;
void CreateObjects(SmartDevice** devices, unsigned int size);

void Deallocate(const SmartDevice** devices, const unsigned int size);

void FindIthIndexValue(const SmartDevice* device, unsigned int idx);

void FindMaxGSTDeviceId(const SmartDevice** devices, unsigned int idx);

/*

                                                [  10.21  | 9.21  | 11.22 ]
                                                ^
                                                |
    [d101 |Mobile  | 9000.0f    |BLUETOOTH   |0x100H]
    24      24           4           4         8
*/

void FilterDevices(Predicate fn , const SmartDevice* ,const  unsigned int );

#endif // FUNCTIONALITIES_H
