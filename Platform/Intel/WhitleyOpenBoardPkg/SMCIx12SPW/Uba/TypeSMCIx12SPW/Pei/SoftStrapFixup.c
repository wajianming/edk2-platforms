/** @file
  Soft Strap update.

  @copyright
  Copyright 2018 - 2021 Intel Corporation. <BR>
  Copyright (c) 2021, American Megatrends International LLC. <BR>
  Copyright 2021, Super Micro Computer, Inc. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "PeiBoardInit.h"
#include <Library/UbaSoftStrapUpdateLib.h>

PLATFORM_PCH_SOFTSTRAP_FIXUP_ENTRY  TypeSMCIx12SPWSoftStrapTable[] =
{
// SoftStrapNumber, LowBit, BitLength, Value
  {2,    6, 1, 0x1 },    // Enable/Disable sSATA
  {15,   0, 2, 0x0 },    // sSATA / PCIe Select for Port 0 (SATA_PCIE_SP0)
  {15,   2, 2, 0x0 },    // sSATA / PCIe Select for Port 1 (SATA_PCIE_SP1)
  {15,   4, 2, 0x0 },    // sSATA / PCIe Select for Port 2 (SATA_PCIE_SP2)
  {15,   6, 2, 0x0 },    // sSATA / PCIe Select for Port 3 (SATA_PCIE_SP3)
  {15,   8, 2, 0x0 },    // sSATA / PCIe Select for Port 4 (SATA_PCIE_SP3)
  {15,  10, 2, 0x0 },    // sSATA / PCIe Select for Port 5 (SATA_PCIE_SP3)
//  {15,  18, 1, 0x1 },    // Polarity of GPP_H20 (GPIO polarity of Select between sSATA Port 2 and PCIe Port 8)
  {16,   0, 2, 0x0 },    // sSATA / PCIe GP Select for Port 0 (SATA_PCIE_GP0)
  {16,   2, 2, 0x0 },    // sSATA / PCIe GP Select for Port 1 (SATA_PCIE_GP1)
  {16,   4, 2, 0x0 },    // sSATA / PCIe GP Select for Port 2 (SATA_PCIE_GP2)
  {16,   6, 2, 0x0 },    // sSATA / PCIe GP Select for Port 3 (SATA_PCIE_GP3)
  {16,   8, 2, 0x0 },    // sSATA / PCIe GP Select for Port 4 (SATA_PCIE_GP3)
  {16,  10, 2, 0x0 },    // sSATA / PCIe GP Select for Port 5 (SATA_PCIE_GP3)
  {17,   6, 1, 0x0 },    // Intel (R) GbE Legacy PHY over PCIe Enabled

  {17,   8, 2, 0x0 },    // sSATA / PCIe Combo Port 0 
  {17,  10, 2, 0x0 },    // sSATA / PCIe Combo Port 1
  {17,  12, 2, 0x0 },    // sSATA / PCIe Combo Port 2
  {18,   0, 2, 0x0 },    // sSATA / PCIe Combo Port 3
  {18,   2, 2, 0x0 },    // sSATA / PCIe Combo Port 4
  {18,   4, 2, 0x0 },    // sSATA / PCIe Combo Port 5

  {18,   6, 2, 0x0 },    // SATA / PCIe Combo Port 0
  {18,   8, 2, 0x0 },    // SATA / PCIe Combo Port 1
  {18,  10, 2, 0x0 },    // SATA / PCIe Combo Port 2
  {18,  12, 2, 0x0 },    // SATA / PCIe Combo Port 3
  {18,  14, 2, 0x0 },    // SATA / PCIe Combo Port 4

  {19,   2, 1, 0x1 },    // Polarity Select sSATA / PCIe Combo Port 2

  {19,  16, 2, 0x0 },    // SATA / PCIe Combo Port 5
  {19,  18, 2, 0x0 },    // SATA / PCIe Combo Port 6
  {19,  20, 2, 0x0 },    // SATA / PCIe Combo Port 7

  {19,  26, 1, 0x1 },    // Statically assign PCH PCIe NP8 Uplink to act as Downlink or Uplink(PCIEUDS)
  {33,  24, 7, 0x17},    // IE SMLink1 I2C Target Address
  {64,  24, 7, 0x17},    // ME SMLink1 I2C Target Address
  {84,  24, 1, 0x0 },    // SMS1 Gbe Legacy MAC SMBus Address Enable
  {85,   8, 3, 0x0 },    // SMS1 PMC SMBus Connect
  {88,   8, 2, 0x3 },    // Root Port Configuration 0
  {93,   0, 2, 0x0 },    // Flex IO Port 18 AUXILLARY Mux Select between SATA Port 0 and PCIe Port 12
  {93,   2, 2, 0x0 },    // Flex IO Port 19 AUXILLARY Mux Select between SATA Port 1 and PCIe Port 13
  {93,   4, 2, 0x0 },    // Flex IO Port 20 AUXILLARY Mux Select between SATA Port 2 and PCIe Port 14
  {94,   0, 2, 0x0 },    // Flex IO Port 21 AUXILLARY Mux Select between SATA Port 3 and PCIe Port 15
  {94,   2, 2, 0x0 },    // Flex IO Port 22 AUXILLARY Mux Select between SATA Port 4 and PCIe Port 16
  {94,   4, 2, 0x0 },    // Flex IO Port 23 AUXILLARY Mux Select between SATA Port 5 and PCIe Port 17
  {94,   6, 2, 0x0 },    // Flex IO Port 24 AUXILLARY Mux Select between SATA Port 6 and PCIe Port 18
  {94,   8, 2, 0x0 },    // Flex IO Port 25 AUXILLARY Mux Select between SATA Port 7 and PCIe Port 19
  {102,  0, 2, 0x0 },    // Flex IO Port 18 Mux Select between SATA Port 0 and PCIe Port 12
  {102,  2, 2, 0x0 },    // Flex IO Port 18 Mux Select between SATA Port 1 and PCIe Port 13
  {102,  4, 2, 0x0 },    // Flex IO Port 18 Mux Select between SATA Port 2 and PCIe Port 14
  {102,  6, 2, 0x0 },    // Flex IO Port 18 Mux Select between SATA Port 3 and PCIe Port 15
  {102,  8, 2, 0x0 },    // Flex IO Port 18 Mux Select between SATA Port 4 and PCIe Port 16
  {102, 10, 2, 0x0 },    // Flex IO Port 18 Mux Select between SATA Port 5 and PCIe Port 17
  {102, 12, 2, 0x0 },    // Flex IO Port 18 Mux Select between SATA Port 6 and PCIe Port 18
  {102, 14, 2, 0x0 },    // Flex IO Port 18 Mux Select between SATA Port 7 and PCIe Port 19
  {103, 16, 3, 0x0 },    // GbE Legacy PHY Smbus Connection
  {103, 26, 1, 0x0 },    // GbE Legacy LCD SMBus PHY Address Enabled
  {103, 27, 1, 0x0 },    // GbE Legacy LC SMBus Address Enabled
  {120, 15, 1, 0x0 },    // SATA Disable (0 = is not disabled)
  {121, 11, 1, 0x0 },    // sSATA Disable (0 = is not disabled)

//
// END OF LIST
//
  {0, 0, 0, 0}
};

UINT32
TypeSMCIx12SPWSystemBoardRevIdValue (VOID)
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
TypeSMCIx12SPWPlatformSpecificUpdate (
  IN OUT  UINT8                 *FlashDescriptorCopy
  )
{
}

PLATFORM_PCH_SOFTSTRAP_UPDATE  TypeSMCIx12SPWSoftStrapUpdate =
{
  PLATFORM_SOFT_STRAP_UPDATE_SIGNATURE,
  PLATFORM_SOFT_STRAP_UPDATE_VERSION,
  TypeSMCIx12SPWSoftStrapTable,
  TypeSMCIx12SPWPlatformSpecificUpdate
};

EFI_STATUS
TypeSMCIx12SPWInstallSoftStrapData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
  )
{
  EFI_STATUS                            Status;

  Status = UbaConfigPpi->AddData (
                                 UbaConfigPpi,
                                 &gPlatformPchSoftStrapConfigDataGuid,
                                 &TypeSMCIx12SPWSoftStrapUpdate,
                                 sizeof(TypeSMCIx12SPWSoftStrapUpdate)
                                 );

  return Status;
}

