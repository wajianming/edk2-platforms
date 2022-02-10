/** @file
  Platform Hooks file

  @copyright
  Copyright 2021, Super Micro Computer, Inc. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

//
//ASPEED AST2600 register
//
#define ASPEED2600_SIO_INDEX_PORT  0x4E
#define ASPEED2600_SIO_DATA_PORT   (ASPEED2600_SIO_INDEX_PORT+1)

#define ASPEED2600_SIO_UART1       0x02
#define ASPEED2600_SIO_UART2       0x03
#define ASPEED2600_SIO_SMI         0x0D
#define ASPEED2600_SIO_MAILBOX     0x0E

#define ASPEED2600_SIO_UNLOCK      0xA5
#define ASPEED2600_SIO_LOCK        0xAA
