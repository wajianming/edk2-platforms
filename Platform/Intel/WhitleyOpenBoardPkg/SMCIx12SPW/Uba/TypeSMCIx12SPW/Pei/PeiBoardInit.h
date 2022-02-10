/** @file
  PeiBoardInit.

  @copyright
  Copyright 2018 - 2021 Intel Corporation. <BR>
  Copyright (c) 2021, American Megatrends International LLC. <BR>
  Copyright 2021, Super Micro Computer, Inc. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _PEI_BOARD_INIT_PEIM_H_
#define _PEI_BOARD_INIT_PEIM_H_

#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Ppi/UbaCfgDb.h>
#include <Guid/PlatformInfo.h>
#include <Library/PeiServicesLib.h>
#include <Library/HobLib.h>
#include <Library/PeiServicesTablePointerLib.h>
#include <Library/GpioLib.h>
#include <GpioPinsSklH.h>
#include <Ppi/DynamicSiLibraryPpi.h>
#define TypeSMCIx12SPW 0xa0 

// TypeSMCIx12SPW
EFI_STATUS
TypeSMCIx12SPWPlatformUpdateUsbOcMappings (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeSMCIx12SPWPlatformUpdateAcpiTablePcds (
  VOID
);

EFI_STATUS
TypeSMCIx12SPWInstallClockgenData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeSMCIx12SPWInstallPcdData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeSMCIx12SPWPchEarlyUpdate (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeSMCIx12SPWIioPortBifurcationInit (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeSMCIx12SPWInstallSlotTableData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeSMCIx12SPWInstallKtiEparamData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

// TypeSMCIx12SPW
EFI_STATUS
TypeSMCIx12SPWInstallGpioData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
) ;

EFI_STATUS
TypeSMCIx12SPWInstallSoftStrapData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);
#endif // _PEI_BOARD_INIT_PEIM_H_
