/** @file
  IIO Config Update.

  @copyright
  Copyright 2018 - 2021 Intel Corporation. <BR>
  Copyright (c) 2021, American Megatrends International LLC. <BR>
  Copyright 2021, Super Micro Computer, Inc. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "IioCfgUpdateDxe.h"

EFI_STATUS
UpdateSMCIx12SPWIioConfig (
  IN  IIO_GLOBALS             *IioGlobalData
  )
{
  return EFI_SUCCESS;
}

PLATFORM_IIO_CONFIG_UPDATE_TABLE  TypeSMCIx12SPWIioConfigTable =
{
  PLATFORM_IIO_CONFIG_UPDATE_SIGNATURE,
  PLATFORM_IIO_CONFIG_UPDATE_VERSION,

  IioBifurcationTable,
  sizeof(IioBifurcationTable),
  UpdateSMCIx12SPWIioConfig,
  IioSlotTable,
  sizeof(IioSlotTable)

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
IioCfgUpdateEntry (
  IN EFI_HANDLE                            ImageHandle,
  IN EFI_SYSTEM_TABLE                      *SystemTable
)
{
  EFI_STATUS                               Status;
  UBA_CONFIG_DATABASE_PROTOCOL             *UbaConfigProtocol = NULL;

  DEBUG((DEBUG_INFO, "UBA:IioCfgUpdate-TypeSMCIx12SPW\n"));
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
                                     &gPlatformIioConfigDataDxeGuid,
                                     &TypeSMCIx12SPWIioConfigTable,
                                     sizeof(TypeSMCIx12SPWIioConfigTable)
                                     );

  Status = UbaConfigProtocol->AddData (
                                     UbaConfigProtocol,
                                     &gPlatformIioConfigDataDxeGuid_1,
                                     &TypeSMCIx12SPWIioConfigTable,
                                     sizeof(TypeSMCIx12SPWIioConfigTable)
                                     );

  Status = UbaConfigProtocol->AddData (
                                     UbaConfigProtocol,
                                     &gPlatformIioConfigDataDxeGuid_2,
                                     &TypeSMCIx12SPWIioConfigTable,
                                     sizeof(TypeSMCIx12SPWIioConfigTable)
                                     );

  Status = UbaConfigProtocol->AddData (
                                     UbaConfigProtocol,
                                     &gPlatformIioConfigDataDxeGuid_3,
                                     &TypeSMCIx12SPWIioConfigTable,
                                     sizeof(TypeSMCIx12SPWIioConfigTable)
                                     );

  if (EFI_ERROR(Status)) {
    return Status;
  }

  return Status;
}
