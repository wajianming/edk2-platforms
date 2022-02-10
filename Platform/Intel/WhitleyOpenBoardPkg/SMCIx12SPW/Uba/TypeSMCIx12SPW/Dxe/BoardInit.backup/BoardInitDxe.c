/** @file
  BOARD INIT DXE Driver.

  @copyright
  Copyright 2014 - 2021 Intel Corporation.
  Copyright (c) 2021, American Megatrends International LLC. <BR>
  Copyright 2021, Super Micro Computer, Inc. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "BoardInitDxe.h"
#include <PlatformInfoTypes.h>

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
BoardInitDxeDriverEntry (
  IN EFI_HANDLE                            ImageHandle,
  IN EFI_SYSTEM_TABLE                      *SystemTable
)
{
  EFI_STATUS                              Status = EFI_SUCCESS;
  UBA_CONFIG_DATABASE_PROTOCOL           *UbaConfigProtocol = NULL;
  UINT32                                  PlatformType = 0;
  EFI_HANDLE                              Handle = NULL;

  Status = gBS->LocateProtocol (
                  &gUbaConfigDatabaseProtocolGuid,
                  NULL,
                  &UbaConfigProtocol
                  );
  if (EFI_ERROR(Status)) {
    return Status;
  }

  DEBUG ((DEBUG_ERROR, "Uba init Dxe driver: SMCI gEfiPlatformTypeSMCIx12SPWProtocolGuid\n"));
  Status = gBS->InstallProtocolInterface (
    &Handle,
    &gEfiPlatformTypeSMCIx12SPWProtocolGuid,
    EFI_NATIVE_INTERFACE,
    NULL
    );
  ASSERT_EFI_ERROR (Status);
  return Status;
}
