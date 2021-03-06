/**
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef CHIP_ZCL_ZPRO_CODEC_H
#define CHIP_ZCL_ZPRO_CODEC_H

#include <stdbool.h>
#include <stdint.h>

typedef uint16_t EmberApsOption;

/** @brief An in-memory representation of a ZigBee APS frame
 * of an incoming or outgoing message. Copy pasted here so that we can compile this unit of code independently.
 */
typedef struct
{
    /** The application profile ID that describes the format of the message. */
    uint16_t profileId;
    /** The cluster ID for this message. */
    uint16_t clusterId;
    /** The source endpoint. */
    uint8_t sourceEndpoint;
    /** The destination endpoint. */
    uint8_t destinationEndpoint;
    /** A bitmask of options from the enumeration above. */
    EmberApsOption options;
    /** The group ID for this message, if it is multicast mode. */
    uint16_t groupId;
    /** The sequence number. */
    uint8_t sequence;
    uint8_t radius;
} EmberApsFrame;

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Encode an on command for on-off server into buffer including the APS frame
 */
uint32_t encodeOnCommand(uint8_t * buffer, uint32_t buf_length, uint8_t destination_endpoint);

/** @brief Encode an off command for on-off server into buffer including the APS frame
 */

uint32_t encodeOffCommand(uint8_t * buffer, uint32_t buf_length, uint8_t destination_endpoint);

/** @brief Encode a toggle command for on-off server into buffer including the APS frame
 */

uint32_t encodeToggleCommand(uint8_t * buffer, uint32_t buf_length, uint8_t destination_endpoint);

/** @brief Extracts an aps frame from buffer into outApsFrame
 */
bool extractApsFrame(void * buffer, uint32_t buf_length, EmberApsFrame * outApsFrame);

/** @brief Populates msg with address of the zcl message within buffer.
 * @return Returns the length of msg buffer. Returns 0 on error e.g. if buffer is too short.
 */
uint16_t extractMessage(uint8_t * buffer, uint16_t buffer_length, uint8_t ** msg);

/** @brief Prints an aps frame struct
 */
void printApsFrame(EmberApsFrame * frame);

#ifdef __cplusplus
}
#endif

#endif // CHIP_ZCL_ZPRO_CODEC_H
