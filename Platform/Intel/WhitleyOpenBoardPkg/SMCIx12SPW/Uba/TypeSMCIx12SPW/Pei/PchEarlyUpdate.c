/** @file
  Pch Early update.

  @copyright
  Copyright 2019 - 2021 Intel Corporation. <BR>
  Copyright (c) 2021, American Megatrends International LLC. <BR>
  Copyright 2021, Super Micro Computer, Inc. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "PeiBoardInit.h"

#include <Library/UbaPchEarlyUpdateLib.h>

#include <PchAccess.h>
#include <GpioPinsSklH.h>
#include <Library/GpioLib.h>
#include <Ppi/DynamicSiLibraryPpi.h>

EFI_STATUS
TypeSMCIx12SPWPchLanConfig (
  IN SYSTEM_CONFIGURATION         *SystemConfig
)
{
  DYNAMIC_SI_LIBARY_PPI  *DynamicSiLibraryPpi = NULL;
  EFI_STATUS              Status;

  Status = PeiServicesLocatePpi (&gDynamicSiLibraryPpiGuid, 0, NULL, &DynamicSiLibraryPpi);
  if (EFI_ERROR (Status)) {
    ASSERT_EFI_ERROR (Status);
    return Status;
  }

  DynamicSiLibraryPpi->GpioSetOutputValue (GPIO_SKL_H_GPP_I9, (UINT32)SystemConfig->LomDisableByGpio);
  DynamicSiLibraryPpi->PchDisableGbe ();

  return EFI_SUCCESS;
}

EFI_STATUS
TypeSMCIx12SPWOemInitLateHook (
  IN SYSTEM_CONFIGURATION         *SystemConfig
)
{
  return EFI_SUCCESS;
}


PLATFORM_PCH_EARLY_UPDATE_TABLE  TypeSMCIx12SPWPchEarlyUpdateTable =
{
  PLATFORM_PCH_EARLY_UPDATE_SIGNATURE,
  PLATFORM_PCH_EARLY_UPDATE_VERSION,
  TypeSMCIx12SPWPchLanConfig,
  TypeSMCIx12SPWOemInitLateHook
};


/**
  Entry point function for the PEIM

  @param FileHandle      Handle of the file being invoked.
  @param PeiServices     Describes the list of possible PEI Services.

  @return EFI_SUCCESS    If we installed our PPI

**/
EFI_STATUS
EFIAPI
TypeSMCIx12SPWPchEarlyUpdate(
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
  )
{
  EFI_STATUS                            Status;

  Status = PeiServicesLocatePpi (
            &gUbaConfigDatabasePpiGuid,
            0,
            NULL,
            &UbaConfigPpi
            );
  if (EFI_ERROR(Status)) {
    return Status;
  }

  Status = UbaConfigPpi->AddData (
                               UbaConfigPpi,
                               &gPlatformPchEarlyConfigDataGuid,
                               &TypeSMCIx12SPWPchEarlyUpdateTable,
                               sizeof(TypeSMCIx12SPWPchEarlyUpdateTable)
                               );

  return Status;
}
