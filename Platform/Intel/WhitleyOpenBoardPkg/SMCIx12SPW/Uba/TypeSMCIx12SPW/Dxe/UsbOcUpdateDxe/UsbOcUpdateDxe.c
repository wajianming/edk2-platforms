/** @file

  @copyright
  Copyright 2018 - 2021 Intel Corporation. <BR>
  Copyright (c) 2021, American Megatrends International LLC. <BR>
  Copyright 2021, Super Micro Computer, Inc. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "UsbOcUpdateDxe.h"

#include <Library/UbaUsbOcUpdateLib.h>
#include <PchLimits.h>
#include <ConfigBlock/UsbConfig.h>
#include <ConfigBlock/Usb2PhyConfig.h>

USB_OVERCURRENT_PIN TypeSMCIx12SPWUsb20OverCurrentMappings[PCH_MAX_USB2_PORTS] = {
                          UsbOverCurrentPinSkip,   //Port00:
                          UsbOverCurrentPinSkip,   //Port01:
                          UsbOverCurrentPinSkip,   //Port02:
                          UsbOverCurrentPinSkip,   //Port03:
                          UsbOverCurrentPinSkip,   //Port04:
                          UsbOverCurrentPinSkip,   //Port05:
                          UsbOverCurrentPinSkip,
                          UsbOverCurrentPinSkip,
                          UsbOverCurrentPinSkip,
                          UsbOverCurrentPinSkip,
                          UsbOverCurrentPinSkip,
                          UsbOverCurrentPinSkip,
                          UsbOverCurrentPinSkip,
                          UsbOverCurrentPinSkip,
                          UsbOverCurrentPinSkip,
                          UsbOverCurrentPinSkip
                      };

USB_OVERCURRENT_PIN TypeSMCIx12SPWUsb30OverCurrentMappings[PCH_MAX_USB3_PORTS] = {
                          UsbOverCurrentPinSkip, //Port01:
                          UsbOverCurrentPinSkip, //Port02:
                          UsbOverCurrentPinSkip, //Port03:
                          UsbOverCurrentPinSkip, //Port04:
                          UsbOverCurrentPinSkip, //Port05:
                          UsbOverCurrentPinSkip, //Port06:
                          UsbOverCurrentPinSkip, //Port07:
                          UsbOverCurrentPinSkip, //Port08:
                          UsbOverCurrentPinSkip, //Port09:
                          UsbOverCurrentPinSkip  //Port10:
                       };

USB2_PHY_PARAMETERS         TypeSMCIx12SPWUsb20AfeParams[PCH_H_XHCI_MAX_USB2_PHYSICAL_PORTS] = {
                        {3, 0, 3, 1},   // PP0
                        {5, 0, 3, 1},   // PP1
                        {3, 0, 3, 1},   // PP2
                        {0, 5, 1, 1},   // PP3
                        {3, 0, 3, 1},   // PP4
                        {3, 0, 3, 1},   // PP5
                        {3, 0, 3, 1},   // PP6
                        {3, 0, 3, 1},   // PP7
                        {2, 2, 1, 0},   // PP8
                        {6, 0, 2, 1},   // PP9
                        {2, 2, 1, 0},   // PP10
                        {6, 0, 2, 1},   // PP11
                        {0, 5, 1, 1},   // PP12
                        {7, 0, 2, 1},   // PP13
                      };

EFI_STATUS
TypeSMCIx12SPWPlatformUsbOcUpdateCallback (
  IN OUT   USB_OVERCURRENT_PIN   **Usb20OverCurrentMappings,
  IN OUT   USB_OVERCURRENT_PIN   **Usb30OverCurrentMappings,
  IN OUT   USB2_PHY_PARAMETERS        **Usb20AfeParams
)
{
  *Usb20OverCurrentMappings   = &TypeSMCIx12SPWUsb20OverCurrentMappings[0];
  *Usb30OverCurrentMappings   = &TypeSMCIx12SPWUsb30OverCurrentMappings[0];

  *Usb20AfeParams   = TypeSMCIx12SPWUsb20AfeParams;
  return EFI_SUCCESS;
}

PLATFORM_USBOC_UPDATE_TABLE  TypeSMCIx12SPWUsbOcUpdate =
{
   PLATFORM_USBOC_UPDATE_SIGNATURE,
   PLATFORM_USBOC_UPDATE_VERSION,
   TypeSMCIx12SPWPlatformUsbOcUpdateCallback
};

/**
  The Driver Entry Point.

  The function is the driver Entry point.

  @param ImageHandle   A handle for the image that is initializing this driver
  @param SystemTable   A pointer to the EFI system table

  @retval EFI_SUCCESS:              Driver initialized successfully
  @retval EFI_LOAD_ERROR:           Failed to Initialize or has been loaded
  @retval EFI_OUT_OF_RESOURCES      Could not allocate needed resources

**/
EFI_STATUS
EFIAPI
UsbOcUpdateEntry (
  IN EFI_HANDLE                            ImageHandle,
  IN EFI_SYSTEM_TABLE                      *SystemTable
)
{
  EFI_STATUS                          Status;
  UBA_CONFIG_DATABASE_PROTOCOL        *UbaConfigProtocol = NULL;

  DEBUG((DEBUG_INFO, "UBA:UsbOcUpdate-TypeSMCIx12SPW\n"));
  Status = gBS->LocateProtocol (
                  &gUbaConfigDatabaseProtocolGuid,
                  NULL,
                  &UbaConfigProtocol
                  );
  if (EFI_ERROR(Status)) {
    return Status;
  }

  Status = UbaConfigProtocol->AddData (
                                     UbaConfigProtocol,
                                     &gDxePlatformUbaOcConfigDataGuid,
                                     &TypeSMCIx12SPWUsbOcUpdate,
                                     sizeof(TypeSMCIx12SPWUsbOcUpdate)
                                     );

  return Status;
}
