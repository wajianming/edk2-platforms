/** @file
  LbgPchH Sx HSIO PTSS C File

  @copyright
  Copyright 2014 - 2021 Intel Corporation. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "PchLbgHsioPtssTablesSx.h"
#include <PlatformInfoTypes.h>

HSIO_PTSS_TABLES PchLbgHsioPtss_Sx[] = {
  {{0x0F, 12, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x04000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0x0F, 13, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x04000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0x0F, 14, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x04000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xD9, 18, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x04000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xD9, 19, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x04000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xD9, 20, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x04000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xD9, 21, V_PCH_PCR_FIA_LANE_OWN_SATA, 0x150, 0x04000000, (UINT32) ~0x3F000000}, PchSataTopoUnknown, TypeWilsonCityRP},
  {{0xEB, 0, V_PCH_PCR_FIA_LANE_OWN_PCIEDMI, 0x11c, 0x48000000, (UINT32) ~0xF8000000}, PchDmiTopoUnknown, TypeWilsonCityRP},
  {{0xEB, 0, V_PCH_PCR_FIA_LANE_OWN_PCIEDMI, 0x164, 0x00080000, (UINT32) ~0x1F0000}, PchDmiTopoUnknown, TypeWilsonCityRP},
  {{0xEB, 1, V_PCH_PCR_FIA_LANE_OWN_PCIEDMI, 0x11c, 0x48000000, (UINT32) ~0xF8000000}, PchDmiTopoUnknown, TypeWilsonCityRP},
  {{0xEB, 1, V_PCH_PCR_FIA_LANE_OWN_PCIEDMI, 0x164, 0x00080000, (UINT32) ~0x1F0000}, PchDmiTopoUnknown, TypeWilsonCityRP},
  {{0xEB, 2, V_PCH_PCR_FIA_LANE_OWN_PCIEDMI, 0x11c, 0x48000000, (UINT32) ~0xF8000000}, PchDmiTopoUnknown, TypeWilsonCityRP},
  {{0xEB, 2, V_PCH_PCR_FIA_LANE_OWN_PCIEDMI, 0x164, 0x00080000, (UINT32) ~0x1F0000}, PchDmiTopoUnknown, TypeWilsonCityRP},
  {{0xEB, 3, V_PCH_PCR_FIA_LANE_OWN_PCIEDMI, 0x11c, 0x48000000, (UINT32) ~0xF8000000}, PchDmiTopoUnknown, TypeWilsonCityRP},
  {{0xEB, 3, V_PCH_PCR_FIA_LANE_OWN_PCIEDMI, 0x164, 0x00080000, (UINT32) ~0x1F0000}, PchDmiTopoUnknown, TypeWilsonCityRP},
};

UINT32 PchLbgHsioPtss_Sx_Size = sizeof (PchLbgHsioPtss_Sx) / sizeof (PchLbgHsioPtss_Sx[0]);

