/** @file
  Soft Strap update.

  @copyright
  Copyright 2018 - 2021 Intel Corporation. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "PeiBoardInit.h"
#include <Library/UbaSoftStrapUpdateLib.h>

PLATFORM_PCH_SOFTSTRAP_FIXUP_ENTRY  TypeWilsonCityRPSoftStrapTable[] =
{
// SoftStrapNumber, LowBit, BitLength, Value
  {0, 0, 0, 0}
};

UINT32
TypeWilsonCityRPSystemBoardRevIdValue (VOID)
{
  EFI_HOB_GUID_TYPE       *GuidHob;
  EFI_PLATFORM_INFO       *PlatformInfo;

  GuidHob       = GetFirstGuidHob (&gEfiPlatformInfoGuid);
  ASSERT(GuidHob != NULL);
  if (GuidHob == NULL) {
    return 0xFF;
  }
  PlatformInfo  = GET_GUID_HOB_DATA(GuidHob);
  return PlatformInfo->TypeRevisionId;
}

VOID
TypeWilsonCityRPPlatformSpecificUpdate (
  IN OUT  UINT8                 *FlashDescriptorCopy
  )
{
}

PLATFORM_PCH_SOFTSTRAP_UPDATE  TypeWilsonCityRPSoftStrapUpdate =
{
  PLATFORM_SOFT_STRAP_UPDATE_SIGNATURE,
  PLATFORM_SOFT_STRAP_UPDATE_VERSION,
  TypeWilsonCityRPSoftStrapTable,
  TypeWilsonCityRPPlatformSpecificUpdate
};

EFI_STATUS
TypeWilsonCityRPInstallSoftStrapData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
  )
{
  EFI_STATUS                            Status;

  Status = UbaConfigPpi->AddData (
                                 UbaConfigPpi,
                                 &gPlatformPchSoftStrapConfigDataGuid,
                                 &TypeWilsonCityRPSoftStrapUpdate,
                                 sizeof(TypeWilsonCityRPSoftStrapUpdate)
                                 );

  return Status;
}

