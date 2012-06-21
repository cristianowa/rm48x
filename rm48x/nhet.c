/** @file nhet.c 
*   @brief NHET Driver Inmplmentation File
*   @date 04.October.2011
*   @version 1.02.000
*
*/

/* (c) Texas Instruments 2009-2011, All rights reserved. */


#include "nhet.h"
/* USER CODE BEGIN (0) */
/* USER CODE END */

/*----------------------------------------------------------------------------*/
/* Global variables                                                           */

static const uint32_t s_nhet1pwmPolarity[] =
{
    3U,
    3U,
    3U,
    3U,
    3U,
    3U,
    3U,
    3U,
};

static const uint32_t s_nhet2pwmPolarity[] =
{
    3U,
    3U,
    3U,
    3U,
    3U,
    3U,
    3U,
    3U,
};


/*----------------------------------------------------------------------------*/
/* Default Program                                                            */

/** @var const nhetINSTRUCTION_t nhet1PROGRAM[]
*   @brief Default Program
*
*   Het program running after initialization.
*/

const nhetINSTRUCTION_t nhet1PROGRAM[] =
{
    /* CNT: Timebase
    *       - Instruction                  = 0
    *       - Next instruction             = 1
    *       - Conditional next instruction = na
    *       - Interrupt                    = na
    *       - Pin                          = na
    *       - Reg                          = T
    */
    {
        /* Program */
        0x00002C80U,
        /* Control */
        0x01FFFFFFU,
        /* Data */
        0xFFFFFF80U,
    },
    /* PWCNT: PWM 0 -> Duty Cycle
    *         - Instruction                  = 1
    *         - Next instruction             = 2
    *         - Conditional next instruction = 2
    *         - Interrupt                    = 1
    *         - Pin                          = 8
    */
    {
        /* Program */
        0x000055C0U,
        /* Control */
        (0x00004006U | (8U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 0 -> Period
    *         - Instruction                  = 2
    *         - Next instruction             = 3
    *         - Conditional next instruction = 41
    *         - Interrupt                    = 2
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00007480U,
        /* Control */
        0x00052006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 1 -> Duty Cycle
    *         - Instruction                  = 3
    *         - Next instruction             = 4
    *         - Conditional next instruction = 4
    *         - Interrupt                    = 3
    *         - Pin                          = 10
    */
    {
        /* Program */
        0x000095C0U,
        /* Control */
        (0x00008006U | (10U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 1 -> Period
    *         - Instruction                  = 4
    *         - Next instruction             = 5
    *         - Conditional next instruction = 43
    *         - Interrupt                    = 4
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0000B480U,
        /* Control */
        0x00056006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 2 -> Duty Cycle
    *         - Instruction                  = 5
    *         - Next instruction             = 6
    *         - Conditional next instruction = 6
    *         - Interrupt                    = 5
    *         - Pin                          = 12
    */
    {
        /* Program */
        0x0000D5C0U,
        /* Control */
        (0x0000C006U | (12U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 2 -> Period
    *         - Instruction                  = 6
    *         - Next instruction             = 7
    *         - Conditional next instruction = 45
    *         - Interrupt                    = 6
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0000F480U,
        /* Control */
        0x0005A006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 3 -> Duty Cycle
    *         - Instruction                  = 7
    *         - Next instruction             = 8
    *         - Conditional next instruction = 8
    *         - Interrupt                    = 7
    *         - Pin                          = 14
    */
    {
        /* Program */
        0x000115C0U,
        /* Control */
        (0x00010006U | (14U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 3 -> Period
    *         - Instruction                  = 8
    *         - Next instruction             = 9
    *         - Conditional next instruction = 47
    *         - Interrupt                    = 8
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00013480U,
        /* Control */
        0x0005E006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 4 -> Duty Cycle
    *         - Instruction                  = 9
    *         - Next instruction             = 10
    *         - Conditional next instruction = 10
    *         - Interrupt                    = 9
    *         - Pin                          = 16
    */
    {
        /* Program */
        0x000155C0U,
        /* Control */
        (0x00014006U | (16U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 4 -> Period
    *         - Instruction                  = 10
    *         - Next instruction             = 11
    *         - Conditional next instruction = 49
    *         - Interrupt                    = 10
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00017480U,
        /* Control */
        0x00062006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 5 -> Duty Cycle
    *         - Instruction                  = 11
    *         - Next instruction             = 12
    *         - Conditional next instruction = 12
    *         - Interrupt                    = 11
    *         - Pin                          = 17
    */
    {
        /* Program */
        0x000195C0U,
        /* Control */
        (0x00018006U | (17U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 5 -> Period
    *         - Instruction                  = 12
    *         - Next instruction             = 13
    *         - Conditional next instruction = 51
    *         - Interrupt                    = 12
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001B480U,
        /* Control */
        0x00066006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 6 -> Duty Cycle
    *         - Instruction                  = 13
    *         - Next instruction             = 14
    *         - Conditional next instruction = 14
    *         - Interrupt                    = 13
    *         - Pin                          = 18
    */
    {
        /* Program */
        0x0001D5C0U,
        /* Control */
        (0x0001C006U | (18U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 6 -> Period
    *         - Instruction                  = 14
    *         - Next instruction             = 15
    *         - Conditional next instruction = 53
    *         - Interrupt                    = 14
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001F480U,
        /* Control */
        0x0006A006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 7 -> Duty Cycle
    *         - Instruction                  = 15
    *         - Next instruction             = 16
    *         - Conditional next instruction = 16
    *         - Interrupt                    = 15
    *         - Pin                          = 19
    */
    {
        /* Program */
        0x000215C0U,
        /* Control */
        (0x00020006U | (19U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 7 -> Period
    *         - Instruction                  = 16
    *         - Next instruction             = 17
    *         - Conditional next instruction = 55
    *         - Interrupt                    = 16
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00023480U,
        /* Control */
        0x0006E006U,
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 0
    *         - Instruction                  = 17
    *         - Next instruction             = 18
    *         - Conditional next instruction = 18
    *         - Interrupt                    = 17
    *         - Pin                          = 9
    */
    {
        /* Program */
        0x00025440U,
        /* Control */
        (0x00024007U | (9U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 1
    *         - Instruction                  = 18
    *         - Next instruction             = 19
    *         - Conditional next instruction = 19
    *         - Interrupt                    = 18
    *         - Pin                          = 11
    */
    {
        /* Program */
        0x00027440U,
        /* Control */
        (0x00026007U | (11U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 2
    *         - Instruction                  = 19
    *         - Next instruction             = 20
    *         - Conditional next instruction = 20
    *         - Interrupt                    = 19
    *         - Pin                          = 13
    */
    {
        /* Program */
        0x00029440U,
        /* Control */
        (0x00028007U | (13U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 3
    *         - Instruction                  = 20
    *         - Next instruction             = 21
    *         - Conditional next instruction = 21
    *         - Interrupt                    = 20
    *         - Pin                          = 15
    */
    {
        /* Program */
        0x0002B440U,
        /* Control */
        (0x0002A007U | (15U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 4
    *         - Instruction                  = 21
    *         - Next instruction             = 22
    *         - Conditional next instruction = 22
    *         - Interrupt                    = 21
    *         - Pin                          = 20
    */
    {
        /* Program */
        0x0002D440U,
        /* Control */
        (0x0002C007U | (20U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 5
    *         - Instruction                  = 22
    *         - Next instruction             = 23
    *         - Conditional next instruction = 23
    *         - Interrupt                    = 22
    *         - Pin                          = 21
    */
    {
        /* Program */
        0x0002F440U,
        /* Control */
        (0x0002E007U | (21U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 6
    *         - Instruction                  = 23
    *         - Next instruction             = 24
    *         - Conditional next instruction = 24
    *         - Interrupt                    = 23
    *         - Pin                          = 22
    */
    {
        /* Program */
        0x00031440U,
        /* Control */
        (0x00030007U | (22U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 7
    *         - Instruction                  = 24
    *         - Next instruction             = 25
    *         - Conditional next instruction = 25
    *         - Interrupt                    = 24
    *         - Pin                          = 23
    */
    {
        /* Program */
        0x00033440U,
        /* Control */
        (0x00032007U | (23U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 0
    *         - Instruction                  = 25
    *         - Next instruction             = 26
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 0
    */
    {
        /* Program */
        0x00034E00U | (0U << 6U)  | (0U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 0
    *         - Instruction                  = 26
    *         - Next instruction             = 27
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 0  + 1
    */
    {
        /* Program */
        0x00036E80U | (0U << 6U)  | ((0U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 1
    *         - Instruction                  = 27
    *         - Next instruction             = 28
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 2
    */
    {
        /* Program */
        0x00038E00U | (0U << 6U)  | (2U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 1
    *         - Instruction                  = 28
    *         - Next instruction             = 29
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 2  + 1
    */
    {
        /* Program */
        0x0003AE80U | (0U << 6U)  | ((2U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 2
    *         - Instruction                  = 29
    *         - Next instruction             = 30
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 4
    */
    {
        /* Program */
        0x0003CE00U | (0U << 6U)  | (4U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 2
    *         - Instruction                  = 30
    *         - Next instruction             = 31
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 4  + 1
    */
    {
        /* Program */
        0x0003EE80U | (0U << 6U)  | ((4U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 3
    *         - Instruction                  = 31
    *         - Next instruction             = 32
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 6
    */
    {
        /* Program */
        0x00040E00U | (0U << 6U)  | (6U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 3
    *         - Instruction                  = 32
    *         - Next instruction             = 33
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 6  + 1
    */
    {
        /* Program */
        0x00042E80U | (0U << 6U)  | ((6U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 4
    *         - Instruction                  = 33
    *         - Next instruction             = 34
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 24
    */
    {
        /* Program */
        0x00044E00U | (0U << 6U)  | (24U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 4
    *         - Instruction                  = 34
    *         - Next instruction             = 35
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 24  + 1
    */
    {
        /* Program */
        0x00046E80U | (0U << 6U)  | ((24U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 5
    *         - Instruction                  = 35
    *         - Next instruction             = 36
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 26
    */
    {
        /* Program */
        0x00048E00U | (0U << 6U)  | (26U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 5
    *         - Instruction                  = 36
    *         - Next instruction             = 37
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 26  + 1
    */
    {
        /* Program */
        0x0004AE80U | (0U << 6U)  | ((26U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 6
    *         - Instruction                  = 37
    *         - Next instruction             = 38
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 28
    */
    {
        /* Program */
        0x0004CE00U | (0U << 6U)  | (28U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 6
    *         - Instruction                  = 38
    *         - Next instruction             = 39
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 28  + 1
    */
    {
        /* Program */
        0x0004EE80U | (0U << 6U)  | ((28U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 7
    *         - Instruction                  = 39
    *         - Next instruction             = 40
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 30
    */
    {
        /* Program */
        0x00050E00U | (0U << 6U)  | (30U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 7
    *         - Instruction                  = 40
    *         - Next instruction             = 57
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 30  + 1
    */
    {
        /* Program */
        0x00072E80U | (0U << 6U)  | ((30U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* MOV64: PWM 0 -> Duty Cycle Update
    *         - Instruction                  = 41
    *         - Next instruction             = 42
    *         - Conditional next instruction = 2
    *         - Interrupt                    = 1
    *         - Pin                          = 8
    */
    {
        /* Program */
        0x00054201U,
        /* Control */
        (0x00004007U | (0U << 22U) | (8U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 0 -> Period Update
    *         - Instruction                  = 42
    *         - Next instruction             = 3
    *         - Conditional next instruction = 41
    *         - Interrupt                    = 2
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00006202U,
        /* Control */
        (0x00052007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 1 -> Duty Cycle Update
    *         - Instruction                  = 43
    *         - Next instruction             = 44
    *         - Conditional next instruction = 4
    *         - Interrupt                    = 3
    *         - Pin                          = 10
    */
    {
        /* Program */
        0x00058203U,
        /* Control */
        (0x00008007U | (0U << 22U) | (10U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 1 -> Period Update
    *         - Instruction                  = 44
    *         - Next instruction             = 5
    *         - Conditional next instruction = 43
    *         - Interrupt                    = 4
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0000A204U,
        /* Control */
        (0x00056007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 2 -> Duty Cycle Update
    *         - Instruction                  = 45
    *         - Next instruction             = 46
    *         - Conditional next instruction = 6
    *         - Interrupt                    = 5
    *         - Pin                          = 12
    */
    {
        /* Program */
        0x0005C205U,
        /* Control */
        (0x0000C007U | (0U << 22U) | (12U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 2 -> Period Update
    *         - Instruction                  = 46
    *         - Next instruction             = 7
    *         - Conditional next instruction = 45
    *         - Interrupt                    = 6
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0000E206U,
        /* Control */
        (0x0005A007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 3 -> Duty Cycle Update
    *         - Instruction                  = 47
    *         - Next instruction             = 48
    *         - Conditional next instruction = 8
    *         - Interrupt                    = 7
    *         - Pin                          = 14
    */
    {
        /* Program */
        0x00060207U,
        /* Control */
        (0x00010007U | (0U << 22U) | (14U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 3 -> Period Update
    *         - Instruction                  = 48
    *         - Next instruction             = 9
    *         - Conditional next instruction = 47
    *         - Interrupt                    = 8
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00012208U,
        /* Control */
        (0x0005E007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 4 -> Duty Cycle Update
    *         - Instruction                  = 49
    *         - Next instruction             = 50
    *         - Conditional next instruction = 10
    *         - Interrupt                    = 9
    *         - Pin                          = 16
    */
    {
        /* Program */
        0x00064209U,
        /* Control */
        (0x00014007U | (0U << 22U) | (16U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 4 -> Period Update
    *         - Instruction                  = 50
    *         - Next instruction             = 11
    *         - Conditional next instruction = 49
    *         - Interrupt                    = 10
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001620AU,
        /* Control */
        (0x00062007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 5 -> Duty Cycle Update
    *         - Instruction                  = 51
    *         - Next instruction             = 52
    *         - Conditional next instruction = 12
    *         - Interrupt                    = 11
    *         - Pin                          = 17
    */
    {
        /* Program */
        0x0006820BU,
        /* Control */
        (0x00018007U | (0U << 22U) | (17U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 5 -> Period Update
    *         - Instruction                  = 52
    *         - Next instruction             = 13
    *         - Conditional next instruction = 51
    *         - Interrupt                    = 12
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001A20CU,
        /* Control */
        (0x00066007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 6 -> Duty Cycle Update
    *         - Instruction                  = 53
    *         - Next instruction             = 54
    *         - Conditional next instruction = 14
    *         - Interrupt                    = 13
    *         - Pin                          = 18
    */
    {
        /* Program */
        0x0006C20DU,
        /* Control */
        (0x0001C007U | (0U << 22U) | (18U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 6 -> Period Update
    *         - Instruction                  = 54
    *         - Next instruction             = 15
    *         - Conditional next instruction = 53
    *         - Interrupt                    = 14
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001E20EU,
        /* Control */
        (0x0006A007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 7 -> Duty Cycle Update
    *         - Instruction                  = 55
    *         - Next instruction             = 56
    *         - Conditional next instruction = 16
    *         - Interrupt                    = 15
    *         - Pin                          = 19
    */
    {
        /* Program */
        0x0007020FU,
        /* Control */
        (0x00020007U | (0U << 22U) | (19U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 7 -> Period Update
    *         - Instruction                  = 56
    *         - Next instruction             = 17
    *         - Conditional next instruction = 55
    *         - Interrupt                    = 16
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00022210U,
        /* Control */
        (0x0006E007U),
        /* Data */
        159872U,
    },
    /* WCAP: Capture timestamp
    *         - Instruction                  = 57
    *         - Next instruction             = 0
    *         - Conditional next instruction = 0
    *         - Interrupt                    = na
    *         - Pin                          = na
    *         - Reg                          = T
    */
    {
        /* Program */
        0x00001600U,
        /* Control */
        (0x00000004U),
        /* Data */
        0x00000000U,
    },
};


/*----------------------------------------------------------------------------*/
/* Default Program                                                            */

/** @var const nhetINSTRUCTION_t nhet2PROGRAM[]
*   @brief Default Program
*
*   Het program running after initialization.
*/

const nhetINSTRUCTION_t nhet2PROGRAM[] =
{
    /* CNT: Timebase
    *       - Instruction                  = 0
    *       - Next instruction             = 1
    *       - Conditional next instruction = na
    *       - Interrupt                    = na
    *       - Pin                          = na
    *       - Reg                          = T
    */
    {
        /* Program */
        0x00002C80U,
        /* Control */
        0x01FFFFFFU,
        /* Data */
        0xFFFFFF80U,
    },
    /* PWCNT: PWM 0 -> Duty Cycle
    *         - Instruction                  = 1
    *         - Next instruction             = 2
    *         - Conditional next instruction = 2
    *         - Interrupt                    = 1
    *         - Pin                          = 8
    */
    {
        /* Program */
        0x000055C0U,
        /* Control */
        (0x00004006U | (8U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 0 -> Period
    *         - Instruction                  = 2
    *         - Next instruction             = 3
    *         - Conditional next instruction = 41
    *         - Interrupt                    = 2
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00007480U,
        /* Control */
        0x00052006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 1 -> Duty Cycle
    *         - Instruction                  = 3
    *         - Next instruction             = 4
    *         - Conditional next instruction = 4
    *         - Interrupt                    = 3
    *         - Pin                          = 10
    */
    {
        /* Program */
        0x000095C0U,
        /* Control */
        (0x00008006U | (10U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 1 -> Period
    *         - Instruction                  = 4
    *         - Next instruction             = 5
    *         - Conditional next instruction = 43
    *         - Interrupt                    = 4
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0000B480U,
        /* Control */
        0x00056006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 2 -> Duty Cycle
    *         - Instruction                  = 5
    *         - Next instruction             = 6
    *         - Conditional next instruction = 6
    *         - Interrupt                    = 5
    *         - Pin                          = 12
    */
    {
        /* Program */
        0x0000D5C0U,
        /* Control */
        (0x0000C006U | (12U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 2 -> Period
    *         - Instruction                  = 6
    *         - Next instruction             = 7
    *         - Conditional next instruction = 45
    *         - Interrupt                    = 6
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0000F480U,
        /* Control */
        0x0005A006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 3 -> Duty Cycle
    *         - Instruction                  = 7
    *         - Next instruction             = 8
    *         - Conditional next instruction = 8
    *         - Interrupt                    = 7
    *         - Pin                          = 14
    */
    {
        /* Program */
        0x000115C0U,
        /* Control */
        (0x00010006U | (14U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 3 -> Period
    *         - Instruction                  = 8
    *         - Next instruction             = 9
    *         - Conditional next instruction = 47
    *         - Interrupt                    = 8
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00013480U,
        /* Control */
        0x0005E006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 4 -> Duty Cycle
    *         - Instruction                  = 9
    *         - Next instruction             = 10
    *         - Conditional next instruction = 10
    *         - Interrupt                    = 9
    *         - Pin                          = 16
    */
    {
        /* Program */
        0x000155C0U,
        /* Control */
        (0x00014006U | (16U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 4 -> Period
    *         - Instruction                  = 10
    *         - Next instruction             = 11
    *         - Conditional next instruction = 49
    *         - Interrupt                    = 10
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00017480U,
        /* Control */
        0x00062006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 5 -> Duty Cycle
    *         - Instruction                  = 11
    *         - Next instruction             = 12
    *         - Conditional next instruction = 12
    *         - Interrupt                    = 11
    *         - Pin                          = 17
    */
    {
        /* Program */
        0x000195C0U,
        /* Control */
        (0x00018006U | (17U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 5 -> Period
    *         - Instruction                  = 12
    *         - Next instruction             = 13
    *         - Conditional next instruction = 51
    *         - Interrupt                    = 12
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001B480U,
        /* Control */
        0x00066006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 6 -> Duty Cycle
    *         - Instruction                  = 13
    *         - Next instruction             = 14
    *         - Conditional next instruction = 14
    *         - Interrupt                    = 13
    *         - Pin                          = 18
    */
    {
        /* Program */
        0x0001D5C0U,
        /* Control */
        (0x0001C006U | (18U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 6 -> Period
    *         - Instruction                  = 14
    *         - Next instruction             = 15
    *         - Conditional next instruction = 53
    *         - Interrupt                    = 14
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001F480U,
        /* Control */
        0x0006A006U,
        /* Data */
        0x00000000U,
    },
    /* PWCNT: PWM 7 -> Duty Cycle
    *         - Instruction                  = 15
    *         - Next instruction             = 16
    *         - Conditional next instruction = 16
    *         - Interrupt                    = 15
    *         - Pin                          = 19
    */
    {
        /* Program */
        0x000215C0U,
        /* Control */
        (0x00020006U | (19U << 8U) | (3U << 3U)),
        /* Data */
        0x00000000U,
    },
    /* DJZ: PWM 7 -> Period
    *         - Instruction                  = 16
    *         - Next instruction             = 17
    *         - Conditional next instruction = 55
    *         - Interrupt                    = 16
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00023480U,
        /* Control */
        0x0006E006U,
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 0
    *         - Instruction                  = 17
    *         - Next instruction             = 18
    *         - Conditional next instruction = 18
    *         - Interrupt                    = 17
    *         - Pin                          = 9
    */
    {
        /* Program */
        0x00025440U,
        /* Control */
        (0x00024007U | (9U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 1
    *         - Instruction                  = 18
    *         - Next instruction             = 19
    *         - Conditional next instruction = 19
    *         - Interrupt                    = 18
    *         - Pin                          = 11
    */
    {
        /* Program */
        0x00027440U,
        /* Control */
        (0x00026007U | (11U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 2
    *         - Instruction                  = 19
    *         - Next instruction             = 20
    *         - Conditional next instruction = 20
    *         - Interrupt                    = 19
    *         - Pin                          = 13
    */
    {
        /* Program */
        0x00029440U,
        /* Control */
        (0x00028007U | (13U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 3
    *         - Instruction                  = 20
    *         - Next instruction             = 21
    *         - Conditional next instruction = 21
    *         - Interrupt                    = 20
    *         - Pin                          = 15
    */
    {
        /* Program */
        0x0002B440U,
        /* Control */
        (0x0002A007U | (15U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 4
    *         - Instruction                  = 21
    *         - Next instruction             = 22
    *         - Conditional next instruction = 22
    *         - Interrupt                    = 21
    *         - Pin                          = 20
    */
    {
        /* Program */
        0x0002D440U,
        /* Control */
        (0x0002C007U | (20U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 5
    *         - Instruction                  = 22
    *         - Next instruction             = 23
    *         - Conditional next instruction = 23
    *         - Interrupt                    = 22
    *         - Pin                          = 21
    */
    {
        /* Program */
        0x0002F440U,
        /* Control */
        (0x0002E007U | (21U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 6
    *         - Instruction                  = 23
    *         - Next instruction             = 24
    *         - Conditional next instruction = 24
    *         - Interrupt                    = 23
    *         - Pin                          = 22
    */
    {
        /* Program */
        0x00031440U,
        /* Control */
        (0x00030007U | (22U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* ECNT: CCU Edge 7
    *         - Instruction                  = 24
    *         - Next instruction             = 25
    *         - Conditional next instruction = 25
    *         - Interrupt                    = 24
    *         - Pin                          = 23
    */
    {
        /* Program */
        0x00033440U,
        /* Control */
        (0x00032007U | (23U << 8U) | (1U << 4U)),
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 0
    *         - Instruction                  = 25
    *         - Next instruction             = 26
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 0
    */
    {
        /* Program */
        0x00034E00U | (0U << 6U)  | (0U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 0
    *         - Instruction                  = 26
    *         - Next instruction             = 27
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 0  + 1
    */
    {
        /* Program */
        0x00036E80U | (0U << 6U)  | ((0U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 1
    *         - Instruction                  = 27
    *         - Next instruction             = 28
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 2
    */
    {
        /* Program */
        0x00038E00U | (0U << 6U)  | (2U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 1
    *         - Instruction                  = 28
    *         - Next instruction             = 29
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 2  + 1
    */
    {
        /* Program */
        0x0003AE80U | (0U << 6U)  | ((2U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 2
    *         - Instruction                  = 29
    *         - Next instruction             = 30
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 4
    */
    {
        /* Program */
        0x0003CE00U | (0U << 6U)  | (4U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 2
    *         - Instruction                  = 30
    *         - Next instruction             = 31
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 4  + 1
    */
    {
        /* Program */
        0x0003EE80U | (0U << 6U)  | ((4U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 3
    *         - Instruction                  = 31
    *         - Next instruction             = 32
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 6
    */
    {
        /* Program */
        0x00040E00U | (0U << 6U)  | (6U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 3
    *         - Instruction                  = 32
    *         - Next instruction             = 33
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 6  + 1
    */
    {
        /* Program */
        0x00042E80U | (0U << 6U)  | ((6U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 4
    *         - Instruction                  = 33
    *         - Next instruction             = 34
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 24
    */
    {
        /* Program */
        0x00044E00U | (0U << 6U)  | (24U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 4
    *         - Instruction                  = 34
    *         - Next instruction             = 35
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 24  + 1
    */
    {
        /* Program */
        0x00046E80U | (0U << 6U)  | ((24U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 5
    *         - Instruction                  = 35
    *         - Next instruction             = 36
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 26
    */
    {
        /* Program */
        0x00048E00U | (0U << 6U)  | (26U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 5
    *         - Instruction                  = 36
    *         - Next instruction             = 37
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 26  + 1
    */
    {
        /* Program */
        0x0004AE80U | (0U << 6U)  | ((26U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 6
    *         - Instruction                  = 37
    *         - Next instruction             = 38
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 28
    */
    {
        /* Program */
        0x0004CE00U | (0U << 6U)  | (28U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 6
    *         - Instruction                  = 38
    *         - Next instruction             = 39
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 28  + 1
    */
    {
        /* Program */
        0x0004EE80U | (0U << 6U)  | ((28U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Duty 7
    *         - Instruction                  = 39
    *         - Next instruction             = 40
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 30
    */
    {
        /* Program */
        0x00050E00U | (0U << 6U)  | (30U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* PCNT: Capture Period 7
    *         - Instruction                  = 40
    *         - Next instruction             = 57
    *         - Conditional next instruction = na
    *         - Interrupt                    = na
    *         - Pin                          = 30  + 1
    */
    {
        /* Program */
        0x00072E80U | (0U << 6U)  | ((30U) + 1U),
        /* Control */
        0x00000000U,
        /* Data */
        0x00000000U,
    },
    /* MOV64: PWM 0 -> Duty Cycle Update
    *         - Instruction                  = 41
    *         - Next instruction             = 42
    *         - Conditional next instruction = 2
    *         - Interrupt                    = 1
    *         - Pin                          = 8
    */
    {
        /* Program */
        0x00054201U,
        /* Control */
        (0x00004007U | (0U << 22U) | (8U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 0 -> Period Update
    *         - Instruction                  = 42
    *         - Next instruction             = 3
    *         - Conditional next instruction = 41
    *         - Interrupt                    = 2
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00006202U,
        /* Control */
        (0x00052007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 1 -> Duty Cycle Update
    *         - Instruction                  = 43
    *         - Next instruction             = 44
    *         - Conditional next instruction = 4
    *         - Interrupt                    = 3
    *         - Pin                          = 10
    */
    {
        /* Program */
        0x00058203U,
        /* Control */
        (0x00008007U | (0U << 22U) | (10U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 1 -> Period Update
    *         - Instruction                  = 44
    *         - Next instruction             = 5
    *         - Conditional next instruction = 43
    *         - Interrupt                    = 4
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0000A204U,
        /* Control */
        (0x00056007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 2 -> Duty Cycle Update
    *         - Instruction                  = 45
    *         - Next instruction             = 46
    *         - Conditional next instruction = 6
    *         - Interrupt                    = 5
    *         - Pin                          = 12
    */
    {
        /* Program */
        0x0005C205U,
        /* Control */
        (0x0000C007U | (0U << 22U) | (12U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 2 -> Period Update
    *         - Instruction                  = 46
    *         - Next instruction             = 7
    *         - Conditional next instruction = 45
    *         - Interrupt                    = 6
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0000E206U,
        /* Control */
        (0x0005A007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 3 -> Duty Cycle Update
    *         - Instruction                  = 47
    *         - Next instruction             = 48
    *         - Conditional next instruction = 8
    *         - Interrupt                    = 7
    *         - Pin                          = 14
    */
    {
        /* Program */
        0x00060207U,
        /* Control */
        (0x00010007U | (0U << 22U) | (14U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 3 -> Period Update
    *         - Instruction                  = 48
    *         - Next instruction             = 9
    *         - Conditional next instruction = 47
    *         - Interrupt                    = 8
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00012208U,
        /* Control */
        (0x0005E007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 4 -> Duty Cycle Update
    *         - Instruction                  = 49
    *         - Next instruction             = 50
    *         - Conditional next instruction = 10
    *         - Interrupt                    = 9
    *         - Pin                          = 16
    */
    {
        /* Program */
        0x00064209U,
        /* Control */
        (0x00014007U | (0U << 22U) | (16U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 4 -> Period Update
    *         - Instruction                  = 50
    *         - Next instruction             = 11
    *         - Conditional next instruction = 49
    *         - Interrupt                    = 10
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001620AU,
        /* Control */
        (0x00062007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 5 -> Duty Cycle Update
    *         - Instruction                  = 51
    *         - Next instruction             = 52
    *         - Conditional next instruction = 12
    *         - Interrupt                    = 11
    *         - Pin                          = 17
    */
    {
        /* Program */
        0x0006820BU,
        /* Control */
        (0x00018007U | (0U << 22U) | (17U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 5 -> Period Update
    *         - Instruction                  = 52
    *         - Next instruction             = 13
    *         - Conditional next instruction = 51
    *         - Interrupt                    = 12
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001A20CU,
        /* Control */
        (0x00066007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 6 -> Duty Cycle Update
    *         - Instruction                  = 53
    *         - Next instruction             = 54
    *         - Conditional next instruction = 14
    *         - Interrupt                    = 13
    *         - Pin                          = 18
    */
    {
        /* Program */
        0x0006C20DU,
        /* Control */
        (0x0001C007U | (0U << 22U) | (18U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 6 -> Period Update
    *         - Instruction                  = 54
    *         - Next instruction             = 15
    *         - Conditional next instruction = 53
    *         - Interrupt                    = 14
    *         - Pin                          = na
    */
    {
        /* Program */
        0x0001E20EU,
        /* Control */
        (0x0006A007U),
        /* Data */
        159872U,
    },
    /* MOV64: PWM 7 -> Duty Cycle Update
    *         - Instruction                  = 55
    *         - Next instruction             = 56
    *         - Conditional next instruction = 16
    *         - Interrupt                    = 15
    *         - Pin                          = 19
    */
    {
        /* Program */
        0x0007020FU,
        /* Control */
        (0x00020007U | (0U << 22U) | (19U << 8U) | (3U << 3U)),
        /* Data */
        80128U,
    },
    /* MOV64: PWM 7 -> Period Update
    *         - Instruction                  = 56
    *         - Next instruction             = 17
    *         - Conditional next instruction = 55
    *         - Interrupt                    = 16
    *         - Pin                          = na
    */
    {
        /* Program */
        0x00022210U,
        /* Control */
        (0x0006E007U),
        /* Data */
        159872U,
    },
    /* WCAP: Capture timestamp
    *         - Instruction                  = 57
    *         - Next instruction             = 0
    *         - Conditional next instruction = 0
    *         - Interrupt                    = na
    *         - Pin                          = na
    *         - Reg                          = T
    */
    {
        /* Program */
        0x00001600U,
        /* Control */
        (0x00000004U),
        /* Data */
        0x00000000U,
    },
};



/** @fn void nhetInit(void)
*   @brief Initializes the nhet Driver
*
*   This function initializes the nhet 1 module.
*/



void nhetInit(void)
{
    /** @b intalise @b NHET */

    /** - Set NHET pins default output value */
    nhetREG1->DOUT = (0U << 31U)
                 | (0U << 30U)
                 | (0U << 29U)
                 | (0U << 28U) 
                 | (0U << 27U)  
                 | (0U << 26U)  
                 | (0U << 25U)  
                 | (0U << 24U)  
                 | (0U << 23U)  
                 | (0U << 22U)  
                 | (0U << 21U)  
                 | (0U << 20U)  
                 | (0U << 19U)  
                 | (0U << 18U) 
                 | (0U << 17U) 
                 | (0U << 16U) 
                 | (0U << 15U) 
                 | (0U << 14U) 
                 | (0U << 13U) 
                 | (0U << 12U) 
                 | (0U << 11U) 
                 | (0U << 10U) 
                 | (0U << 9U)
                 | (0U << 8U)
                 | (0U << 7U)
                 | (0U << 6U)
                 | (0U << 5U)
                 | (0U << 4U)
                 | (0U << 3U)
                 | (0U << 2U)
                 | (0U << 1U)
                 | (0U);

    /** - Set NHET pins direction */
    nhetREG1->DIR = 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00080000U 
                | 0x00040000U 
                | 0x00020000U 
                | 0x00010000U 
                | 0x00000000U 
                | 0x00004000U 
                | 0x00000000U 
                | 0x00001000U 
                | 0x00000000U 
                | 0x00000400U 
                | 0x00000000U
                | 0x00000100U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U;

    /** - Set NHET pins open drain enable */
    nhetREG1->PDR = 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U;

    /** - Set NHET pins pullup/down enable */
    nhetREG1->PULDIS = 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U;

    /** - Set NHET pins pullup/down select */
    nhetREG1->PSL = 0x80000000U 
                | 0x40000000U 
                | 0x20000000U 
                | 0x10000000U 
                | 0x08000000U 
                | 0x04000000U 
                | 0x02000000U 
                | 0x01000000U 
                | 0x00800000U 
                | 0x00400000U 
                | 0x00200000U 
                | 0x00100000U 
                | 0x00080000U 
                | 0x00040000U 
                | 0x00020000U 
                | 0x00010000U 
                | 0x00008000U 
                | 0x00004000U 
                | 0x00002000U 
                | 0x00001000U 
                | 0x00000800U 
                | 0x00000400U 
                | 0x00000200U
                | 0x00000100U
                | 0x00000080U
                | 0x00000040U
                | 0x00000020U
                | 0x00000010U
                | 0x00000008U
                | 0x00000004U
                | 0x00000002U
                | 0x00000001U;

    /** - Set NHET pins high resolution share */
    nhetREG1->HRSH = 0x00008000U 
                 | 0x00004000U 
                 | 0x00002000U 
                 | 0x00001000U 
                 | 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U
                 | 0x00000008U
                 | 0x00000004U
                 | 0x00000002U
                 | 0x00000001U;

/* USER CODE BEGIN (1) */
/* USER CODE END */

				/** - Release from reset */
    memcpy((void *)nhetRAM1, (const void *)nhet1PROGRAM, sizeof(nhet1PROGRAM));

    /** - Setup prescaler values
	*     - Loop resolution prescaler
	*     - High resolution prescaler
	*/
    nhetREG1->PFR = (6U << 8U)
                | (0U);
 
    /** - Setup interrupt priority level 
    *     - PWM 0 end of duty  level
    *     - PWM 0 end of period level
    *     - PWM 1 end of duty  level
    *     - PWM 1 end of period level
    *     - PWM 2 end of duty  level
    *     - PWM 2 end of period level
    *     - PWM 3 end of duty  level
    *     - PWM 3 end of period level
    *     - PWM 4 end of duty  level
    *     - PWM 4 end of period level
    *     - PWM 5 end of duty  level
    *     - PWM 5 end of period level
    *     - PWM 6 end of duty  level
    *     - PWM 6 end of period level
    *     - PWM 7 end of duty  level
    *     - PWM 7 end of period level

    *     - CCU Edge Detection 0 level
    *     - CCU Edge Detection 1 level
    *     - CCU Edge Detection 2 level
    *     - CCU Edge Detection 3 level
    *     - CCU Edge Detection 4 level
    *     - CCU Edge Detection 5 level
    *     - CCU Edge Detection 6 level
    *     - CCU Edge Detection 7 level
    */
    nhetREG1->PRY = 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U;
 
    /** - Enable interrupts 
    *     - PWM 0 end of duty
    *     - PWM 0 end of period
    *     - PWM 1 end of duty
    *     - PWM 1 end of period
    *     - PWM 2 end of duty
    *     - PWM 2 end of period
    *     - PWM 3 end of duty
    *     - PWM 3 end of period
    *     - PWM 4 end of duty
    *     - PWM 4 end of period
    *     - PWM 5 end of duty
    *     - PWM 5 end of period
    *     - PWM 6 end of duty
    *     - PWM 6 end of period
    *     - PWM 7 end of duty
    *     - PWM 7 end of period
    *     - CCU Edge Detection 0
    *     - CCU Edge Detection 1
    *     - CCU Edge Detection 2
    *     - CCU Edge Detection 3
    *     - CCU Edge Detection 4
    *     - CCU Edge Detection 5
    *     - CCU Edge Detection 6
    *     - CCU Edge Detection 7
    */
    nhetREG1->INTENAC = 0xFFFFFFFFU;
    nhetREG1->INTENAS = 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U;

   
   /** - Setup control register 
    *     - Enable output buffers
    *     - Ignore software breakpoints
    *     - Master mode
    *     - Enable NHET
    */
    nhetREG1->GCR = 0x01030001U;
    /**   @note This function has to be called before the driver can be used.\n
    *           This function has to be executed in priviledged mode.\n
    */




  /** @b intalise @b NHET 2 */

    /** - Set NHET pins default output value */
    nhetREG2->DOUT = (0U << 19U)  
                 | (0U << 18U) 
                 | (0U << 17U) 
                 | (0U << 16U) 
                 | (0U << 15U) 
                 | (0U << 14U) 
                 | (0U << 13U) 
                 | (0U << 12U) 
                 | (0U << 11U) 
                 | (0U << 10U) 
                 | (0U << 9U)
                 | (0U << 8U)
                 | (0U << 7U)
                 | (0U << 6U)
                 | (0U << 5U)
                 | (0U << 4U)
                 | (0U << 3U)
                 | (0U << 2U)
                 | (0U << 1U)
                 | (0U);

    /** - Set NHET pins direction */
    nhetREG2->DIR = 0x00080000U 
                | 0x00040000U 
                | 0x00020000U 
                | 0x00010000U 
                | 0x00000000U 
                | 0x00004000U 
                | 0x00000000U 
                | 0x00001000U 
                | 0x00000000U 
                | 0x00000400U 
                | 0x00000000U
                | 0x00000100U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U;

    /** - Set NHET pins open drain enable */
    nhetREG2->PDR = 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U 
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U;

    /** - Set NHET pins pullup/down enable */
    nhetREG2->PULDIS = 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U 
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U
                   | 0x00000000U;

    /** - Set NHET pins pullup/down select */
    nhetREG2->PSL = 0x00080000U 
                | 0x00040000U 
                | 0x00020000U 
                | 0x00010000U 
                | 0x00008000U 
                | 0x00004000U 
                | 0x00002000U 
                | 0x00001000U 
                | 0x00000800U 
                | 0x00000400U 
                | 0x00000200U
                | 0x00000100U
                | 0x00000080U
                | 0x00000040U
                | 0x00000020U
                | 0x00000010U
                | 0x00000008U
                | 0x00000004U
                | 0x00000002U
                | 0x00000001U;

    /** - Set NHET pins high resolution share */
    nhetREG2->HRSH = 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U 
                 | 0x00000000U
                 | 0x00000008U
                 | 0x00000004U
                 | 0x00000002U
                 | 0x00000001U;

/* USER CODE BEGIN (2) */
/* USER CODE END */
				
				/** - Release from reset */
    memcpy((void *)nhetRAM2, (const void *)nhet2PROGRAM, sizeof(nhet2PROGRAM));

    /** - Setup prescaler values
	*     - Loop resolution prescaler
	*     - High resolution prescaler
	*/
    nhetREG2->PFR = (6U << 8U)
                | (0U);
 
    /** - Setup interrupt priority level 
    *     - PWM 0 end of duty  level
    *     - PWM 0 end of period level
    *     - PWM 1 end of duty  level
    *     - PWM 1 end of period level
    *     - PWM 2 end of duty  level
    *     - PWM 2 end of period level
    *     - PWM 3 end of duty  level
    *     - PWM 3 end of period level
    *     - PWM 4 end of duty  level
    *     - PWM 4 end of period level
    *     - PWM 5 end of duty  level
    *     - PWM 5 end of period level
    *     - PWM 6 end of duty  level
    *     - PWM 6 end of period level
    *     - PWM 7 end of duty  level
    *     - PWM 7 end of period level

    *     - CCU Edge Detection 0 level
    *     - CCU Edge Detection 1 level
    *     - CCU Edge Detection 2 level
    *     - CCU Edge Detection 3 level
    *     - CCU Edge Detection 4 level
    *     - CCU Edge Detection 5 level
    *     - CCU Edge Detection 6 level
    *     - CCU Edge Detection 7 level
    */
    nhetREG2->PRY = 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U
                | 0x00000000U;
 
    /** - Enable interrupts 
    *     - PWM 0 end of duty
    *     - PWM 0 end of period
    *     - PWM 1 end of duty
    *     - PWM 1 end of period
    *     - PWM 2 end of duty
    *     - PWM 2 end of period
    *     - PWM 3 end of duty
    *     - PWM 3 end of period
    *     - PWM 4 end of duty
    *     - PWM 4 end of period
    *     - PWM 5 end of duty
    *     - PWM 5 end of period
    *     - PWM 6 end of duty
    *     - PWM 6 end of period
    *     - PWM 7 end of duty
    *     - PWM 7 end of period
    *     - CCU Edge Detection 0
    *     - CCU Edge Detection 1
    *     - CCU Edge Detection 2
    *     - CCU Edge Detection 3
    *     - CCU Edge Detection 4
    *     - CCU Edge Detection 5
    *     - CCU Edge Detection 6
    *     - CCU Edge Detection 7
    */
    nhetREG2->INTENAC = 0xFFFFFFFFU;
    nhetREG2->INTENAS = 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U
                    | 0x00000000U;

   
   /** - Setup control register 
    *     - Enable output buffers
    *     - Ignore software breakpoints
    *     - Master mode
    *     - Enable NHET
    */
    nhetREG2->GCR = 0x01030001U;

    /**   @note This function has to be called before the driver can be used.\n
    *           This function has to be executed in priviledged mode.\n
    */


}


/** @fn void pwmStart(uint32_t pwm)
*   @brief Start pwm signal
*   @param[in] pwm Pwm signal:
*              - pwm0: Pwm 0
*              - pwm1: Pwm 1
*              - pwm2: Pwm 2
*              - pwm3: Pwm 3
*              - pwm4: Pwm 4
*              - pwm5: Pwm 5
*              - pwm6: Pwm 6
*              - pwm7: Pwm 7
*
*   Start the given pwm signal
*/

void pwmStart( nhetRAMBASE_t * nhetRAM, uint32_t pwm)    //spiBASE_t *spi
{
 
   nhetRAM->Instruction[(pwm << 1U) + 41U].Control  |= 0x00400000U;
}


/** @fn void pwmStop(uint32_t pwm)
*   @brief Stop pwm signal
*   @param[in] pwm Pwm signal:
*              - pwm0: Pwm 0
*              - pwm1: Pwm 1
*              - pwm2: Pwm 2
*              - pwm3: Pwm 3
*              - pwm4: Pwm 4
*              - pwm5: Pwm 5
*              - pwm6: Pwm 6
*              - pwm7: Pwm 7
*
*   Stop the given pwm signal
*/

void pwmStop( nhetRAMBASE_t * nhetRAM, uint32_t pwm)
{
    nhetRAM->Instruction[(pwm << 1U) + 41U].Control  &= ~0x00400000U;
}


/** @fn void pwmSetDuty(uint32_t pwm, uint32_t duty)
*   @brief Set duty cycle
*   @param[in] pwm Pwm signal:
*              - pwm0: Pwm 0
*              - pwm1: Pwm 1
*              - pwm2: Pwm 2
*              - pwm3: Pwm 3
*              - pwm4: Pwm 4
*              - pwm5: Pwm 5
*              - pwm6: Pwm 6
*              - pwm7: Pwm 7
*   @param[in] duty duty cycle in %.
*
*   Sets a new duty cycle on the given pwm signal
*/

void pwmSetDuty(nhetRAMBASE_t * nhetRAM, uint32_t pwm, uint32_t duty)
{
    uint32_t action;
    uint32_t pwmPolarity;
    double   period = nhetRAM->Instruction[(pwm << 1U) + 42U].Data + 128U;
    if(nhetRAM == nhetRAM1)
    {
        pwmPolarity = s_nhet1pwmPolarity[pwm];
    }
    else
    {
        pwmPolarity = s_nhet2pwmPolarity[pwm];
    }
    if (duty == 0U)
    {
        action = (pwmPolarity == 3U) ? 0U : 2U;
    }
    else if (duty >= 100U)
    {
        action = (pwmPolarity == 3U) ? 2U : 0U;
    }
    else
    {
        action = pwmPolarity;
    }
        
    nhetRAM->Instruction[(pwm << 1U) + 41U].Control = (nhetRAM->Instruction[(pwm << 1U) + 41U].Control & ~0x18U) | (action << 3U);
    nhetRAM->Instruction[(pwm << 1U) + 41U].Data = (uint32_t)(period * duty / 100.0) + 128U;
}


/** @fn void pwmSetSignal(uint32_t pwm, nhetSIGNAL_t signal)
*   @brief Set period
*   @param[in] pwm Pwm signal:
*              - pwm0: Pwm 0
*              - pwm1: Pwm 1
*              - pwm2: Pwm 2
*              - pwm3: Pwm 3
*              - pwm4: Pwm 4
*              - pwm5: Pwm 5
*              - pwm6: Pwm 6
*              - pwm7: Pwm 7
*   @param[in] signal signal 
               - duty cycle in %.
*              - period period in us.
*
*   Sets a new pwm signal
*/

void pwmSetSignal(nhetRAMBASE_t * nhetRAM, uint32_t pwm, nhetSIGNAL_t signal)
{
    uint32_t action;
    uint32_t period;
    uint32_t pwmPolarity;
    
    if(nhetRAM == nhetRAM1)
    {
        period = (uint32_t)(signal.period * 1000.0 / 800.000) << 7U;
        pwmPolarity = s_nhet1pwmPolarity[pwm];
    }
    else
    {
        period = (uint32_t)(signal.period * 1000.0 / 800.000) << 7U;
        pwmPolarity = s_nhet2pwmPolarity[pwm];
    }
    if (signal.duty == 0U)
    {
        action = (pwmPolarity == 3U) ? 0U : 2U;
    }
    else if (signal.duty >= 100U)
    {
        action = (pwmPolarity == 3U) ? 2U : 0U;
    }
    else
    {
        action = pwmPolarity;
    }
        
    nhetRAM->Instruction[(pwm << 1U) + 41U].Control = (nhetRAM->Instruction[(pwm << 1U) + 41U].Control & ~0x18U) | (action << 3U);
    nhetRAM->Instruction[(pwm << 1U) + 41U].Data = (uint32_t)(period * signal.duty / 100.0) + 128U;
    nhetRAM->Instruction[(pwm << 1U) + 42U].Data = period - 128U;
}


/** @fn nhetSIGNAL_t pwmGetSignal(uint32_t pwm)
*   @brief Get duty cycle
*   @param[in] pwm Pwm signal:
*              - pwm0: Pwm 0
*              - pwm1: Pwm 1
*              - pwm2: Pwm 2
*              - pwm3: Pwm 3
*              - pwm4: Pwm 4
*              - pwm5: Pwm 5
*              - pwm6: Pwm 6
*              - pwm7: Pwm 7
*
*   Gets current signal of the given pwm signal.
*/

nhetSIGNAL_t pwmGetSignal(nhetRAMBASE_t * nhetRAM, uint32_t pwm)
{
    nhetSIGNAL_t signal;   
    uint32_t    duty   = nhetRAM->Instruction[(pwm << 1U) + 41U].Data - 128;
    uint32_t    period = nhetRAM->Instruction[(pwm << 1U) + 42U].Data + 128;
    
    signal.duty   = (uint32_t)(100.0 * duty / period);

    if(nhetRAM == nhetRAM1)
	signal.period = (period >> 7U) * 800.000 / 1000.0;
    else
	signal.period = (period >> 7U) * 800.000 / 1000.0;

    return signal;
}


/** @fn void pwmEnableNotification(uint32_t pwm, uint32_t notification)
*   @brief Enable pwm notification
*   @param[in] pwm Pwm signal:
*              - pwm0: Pwm 0
*              - pwm1: Pwm 1
*              - pwm2: Pwm 2
*              - pwm3: Pwm 3
*              - pwm4: Pwm 4
*              - pwm5: Pwm 5
*              - pwm6: Pwm 6
*              - pwm7: Pwm 7
*   @param[in] notification Pwm notification:
*              - pwmEND_OF_DUTY:   Notification on end of duty
*              - pwmEND_OF_PERIOD: Notification on end of end period
*              - pwmEND_OF_BOTH:   Notification on end of both duty and period
*/

void pwmEnableNotification(nhetBASE_t * nhetREG, uint32_t pwm, uint32_t notification)
{
    nhetREG->FLG     = notification << (pwm << 1U);
    nhetREG->INTENAS = notification << (pwm << 1U);
}


/** @fn void pwmDisableNotification(uint32_t pwm, uint32_t notification)
*   @brief Enable pwm notification
*   @param[in] pwm Pwm signal:
*              - pwm0: Pwm 0
*              - pwm1: Pwm 1
*              - pwm2: Pwm 2
*              - pwm3: Pwm 3
*              - pwm4: Pwm 4
*              - pwm5: Pwm 5
*              - pwm6: Pwm 6
*              - pwm7: Pwm 7
*   @param[in] notification Pwm notification:
*              - pwmEND_OF_DUTY:   Notification on end of duty
*              - pwmEND_OF_PERIOD: Notification on end of end period
*              - pwmEND_OF_BOTH:   Notification on end of both duty and period
*/

void pwmDisableNotification(nhetBASE_t * nhetREG, uint32_t pwm, uint32_t notification)
{
    nhetREG->INTENAC = notification << (pwm << 1U);
}


/** @fn void edgeResetCounter(uint32_t edge)
*   @brief Resets edge counter to 0
*   @param[in] edge Edge signal:
*              - edge0: Edge 0
*              - edge1: Edge 1
*              - edge2: Edge 2
*              - edge3: Edge 3
*              - edge4: Edge 4
*              - edge5: Edge 5
*              - edge6: Edge 6
*              - edge7: Edge 7
*
*   Reset edge counter to 0.
*/

void edgeResetCounter(nhetRAMBASE_t * nhetRAM, uint32_t edge)
{
    nhetRAM->Instruction[edge + 17U].Data = 0U;
}


/** @fn uint32_t edgeGetCounter(uint32_t edge)
*   @brief Get current edge counter value
*   @param[in] edge Edge signal:
*              - edge0: Edge 0
*              - edge1: Edge 1
*              - edge2: Edge 2
*              - edge3: Edge 3
*              - edge4: Edge 4
*              - edge5: Edge 5
*              - edge6: Edge 6
*              - edge7: Edge 7
*
*   Gets current edge counter value.
*/

uint32_t edgeGetCounter(nhetRAMBASE_t * nhetRAM, uint32_t edge)
{
    return nhetRAM->Instruction[edge + 17U].Data >> 7U;
}


/** @fn void edgeEnableNotification(uint32_t edge)
*   @brief Enable edge notification
*   @param[in] edge Edge signal:
*              - edge0: Edge 0
*              - edge1: Edge 1
*              - edge2: Edge 2
*              - edge3: Edge 3
*              - edge4: Edge 4
*              - edge5: Edge 5
*              - edge6: Edge 6
*              - edge7: Edge 7
*/

/** @fn void nhetSetDirection(nhetBASE_t *nhet , uint32_t dir)
*   @brief Set Port Direction
*   @param[in] dir value to write to PCDIR register
*   @param[in] nhet   - nhet module base address
*   Set the direction of NHET pins at runtime.
*/
void nhetSetDirection(nhetBASE_t *nhet , uint32_t dir)
{
    nhet->DIR = dir; 
}

/** @fn void nhetSetBit( nhetBASE_t *nhet ,uint32_t bit, uint32_t value)
*   @brief Write Bit
*   @param[in] bit number 0-18 that specifies the bit to be written to.
*   @param[in] value binrary value to write to bit
*
*   Writes a value to the specified pin of the NHET port
*/
void nhetSetBit( nhetBASE_t *nhet ,uint32_t bit, uint32_t value)
{
    if (value != 0)
    {
        nhet->DSET = 1 << bit;
    }
    else
    {
        nhet->DCLR = 1 << bit; 
    }
}


/** @fn uint32_t nhetGetBit( nhetBASE_t *nhet ,uint32_t bit)
*   @brief Read Bit
*   @param[in] bit number 0-18 that specifies the bit to be written to.
*
*   Reads a the current value from the specified pin of the NHET port
*/
uint32_t nhetGetBit( nhetBASE_t *nhet ,uint32_t bit)
{
    return (nhet->DIN >> bit) & 1U;
}

void edgeEnableNotification(nhetBASE_t * nhetREG, uint32_t edge)
{
    nhetREG->FLG     = 0x20000U << edge;
    nhetREG->INTENAS = 0x20000U << edge;
}


/** @fn void edgeDisableNotification(uint32_t edge)
*   @brief Enable edge notification
*   @param[in] edge Edge signal:
*              - edge0: Edge 0
*              - edge1: Edge 1
*              - edge2: Edge 2
*              - edge3: Edge 3
*              - edge4: Edge 4
*              - edge5: Edge 5
*              - edge6: Edge 6
*              - edge7: Edge 7
*/

void edgeDisableNotification(nhetBASE_t * nhetREG, uint32_t edge)
{
    nhetREG->INTENAC = 0x20000U << edge;
}


/** @fn nhetSIGNAL_t capGetSignal(uint32_t cap)
*   @brief Get capture signal
*   @param[in] cap captured signal:
*              - cap0: Captured signal 0
*              - cap1: Captured signal 1
*              - cap2: Captured signal 2
*              - cap3: Captured signal 3
*              - cap4: Captured signal 4
*              - cap5: Captured signal 5
*              - cap6: Captured signal 6
*              - cap7: Captured signal 7
*
*   Gets current signal of the given capture signal.
*/

nhetSIGNAL_t capGetSignal(nhetRAMBASE_t * nhetRAM, uint32_t cap)
{
    uint32_t    duty   = nhetRAM->Instruction[(cap << 1U) + 25U].Data;
    uint32_t    period = nhetRAM->Instruction[(cap << 1U) + 26U].Data;
	nhetSIGNAL_t signal;   
    
    signal.duty   = (uint32_t)(100.0 * duty / period);
    
    if( nhetRAM == nhetRAM1)
    	signal.period = (period >> 7U) * 800.000 / 1000.0;
    else
	signal.period = (period >> 7U) * 800.000 / 1000.0;
    return signal;
}


/** @fn void nhetResetTimestamp(void)
*   @brief Resets timestamp
*
*   Resets loop count based timstamp.
*/

void nhetResetTimestamp(nhetRAMBASE_t * nhetRAM)
{
    nhetRAM->Instruction[0U].Data = 0;
}


/** @fn uint32_t nhetGetTimestamp(void)
*   @brief Returns timestamp
*
*   Returns loop count based timstamp.
*/

uint32_t nhetGetTimestamp(nhetRAMBASE_t * nhetRAM)
{
    return nhetRAM->Instruction[57U].Data;
}

/* USER CODE BEGIN (3) */
/* USER CODE END */

/** @fn void nhet1HighLevelInterrupt(void)
*   @brief Level 0 Interrupt for NHET1
*/
#pragma INTERRUPT(nhet1HighLevelInterrupt, IRQ)

void nhet1HighLevelInterrupt(void)
{
    uint32_t vec = nhetREG1->OFF1;

    if (vec < 18U)
    {
        if ((vec & 1U) != 0)
        {
            pwmNotification(nhetREG1,(vec >> 1U) - 1U, pwmEND_OF_PERIOD);
        }
        else
        {
            pwmNotification(nhetREG1,(vec >> 1U) - 1U, pwmEND_OF_DUTY);
        }
    }
    else
    {
        edgeNotification(nhetREG1,vec - 18U);
    }
}


/** @fn void nhet1LowLevelInterrupt(void)
*   @brief Level 1 Interrupt for NHET1
*/
#pragma INTERRUPT(nhet1LowLevelInterrupt, IRQ)

void nhet1LowLevelInterrupt(void)
{
    uint32_t vec = nhetREG1->OFF2;

    if (vec < 18U)
    {
        if ((vec & 1U) != 0)
        {
            pwmNotification(nhetREG1,(vec >> 1U) - 1U, pwmEND_OF_PERIOD);
        }
        else
        {
            pwmNotification(nhetREG1,(vec >> 1U) - 1U, pwmEND_OF_DUTY);
        }
    }
    else
    {
        edgeNotification(nhetREG1,vec - 18U);
    }
}


/** @fn void nhet2HighLevelInterrupt(void)
*   @brief Level 0 Interrupt for NHET2
*/
#pragma INTERRUPT(nhet2HighLevelInterrupt, IRQ)

void nhet2HighLevelInterrupt(void)
{
    uint32_t vec = nhetREG2->OFF1;

    if (vec < 18U)
    {
        if ((vec & 1U) != 0)
        {
            pwmNotification(nhetREG2,(vec >> 1U) - 1U, pwmEND_OF_PERIOD);
        }
        else
        {
            pwmNotification(nhetREG2,(vec >> 1U) - 1U, pwmEND_OF_DUTY);
        }
    }
    else
    {
        edgeNotification(nhetREG2,vec - 18U);
    }
}


/** @fn void nhet2LowLevelInterrupt(void)
*   @brief Level 1 Interrupt for NHET2
*/
#pragma INTERRUPT(nhet2LowLevelInterrupt, IRQ)

void nhet2LowLevelInterrupt(void)
{
    uint32_t vec = nhetREG2->OFF2;

    if (vec < 18U)
    {
        if ((vec & 1U) != 0)
        {
            pwmNotification(nhetREG2,(vec >> 1U) - 1U, pwmEND_OF_PERIOD);
        }
        else
        {
            pwmNotification(nhetREG2,(vec >> 1U) - 1U, pwmEND_OF_DUTY);
        }
    }
    else
    {
        edgeNotification(nhetREG2, vec - 18U);
    }
}

