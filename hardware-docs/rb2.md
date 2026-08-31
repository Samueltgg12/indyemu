# rb2

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
RAM Buffer (RB2)  Specification
Farhad Fouladi
Shyamoli Banerjee
Revision 2.3
Silicon Graphics Confidential
RB2 Specification	May 13, 2000	Page 1

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
Chapter 1
1.0 Device Introduction
1.1 Part Name and Number
Part Name: RAM Buffer2 (RB2)
SGI Part Number:
Vendor:LSI Logic
Vendor Part Number:
Process Design Technology: LCA 100K
Package: 100-pin PQFP
Number of gates:5K gates  (approx.)
1.2 General Description
The RB2 is a gate array located between the Raster Engine (REX3) and graphics memory. RB2
contains the read/write formatter and LogicOp  funtions of the pixel pipe. The front end of the pixel
pipe is in REX3. This document specifies the functionality, timing requirements and pinout of the
RB2. A block diagram of the RB2 is attached as Figure 1.
RB2 is designed with LCA 100K CMOS technology, operates at a maximum clock rate of 66MHz
and is housed in a 100-pin plastic quad flat pack. The chip has 11 input pins, 2 output pins, 64 bi-
directs and 23 power and ground pins which add up to a total of 100  pins.
1.3 Additional Documentation
Newport Graphics Subsystem Specification Rev. 1.0
REX3 specification. Rev 0.1
RB2 Specification	May 13, 2000	Page 2

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
Figure 1  RB2 BLOCK DIAGRAM
DP1
8
24
MASK/DRAW
REGISTER
TRISTATE
8 VRAM_DATA_A0[23:0]
O/P BUF
24
32	LOGICOP	WRITE
FORMAT
8
8
RB2_DATA_A0[7:0]
8
TRISTATE
O/P BUF 8
READ
32 READ
BUFFER 24
FORMAT
RB2_CLK
RB2SEL_A[2:0] DEC_CNTL
RB2_SELWMSK
SYS_RST RB2_CLK
SYS_CLK PLL
RCP1 RB2_CLK
RCP2
RB2_DATA_A1[7:0] VRAM_DATA_A1[23:0]
DP1
RB2 Specification	May 13, 2000	Page 3

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
Chapter 2
2.0 Device Interface
2.1 Pin Description
Refer to Figure 2.1 for a logical pin diagram of RB2. The table describes each pin, defined as type
Input or Output and specifies output drive in milliamps.Total pin count is 100 pins.
| Pin Name | Type | Function | Output Drive |
| --- | --- | --- | --- |
| RB2_DATA_A0[7:0] | I/O | Data bus between REX3 and RB2.The data on this bus is read from/written to BankA, VRAM0 of Frame Buffer. | 4mA |
| RB2_DATA_A1[7:0] | I/O | Data bus between REX3 and RB2.The data on this bus is read from/written to BankA, VRAM1 of Frame Buffer. | 4mA |
| RB2_SELWMSK_A | I | This signal selects whether data from write mask register or write data register gets driven on VRAM data bus. It is driven by the RAS_N signal from REX3. |  |
| RB2SEL_A[2:0] | I | These three bits specify the function that has to be executed by RB2 in the next cycle. The various functions are detailed in Chapter 4. |  |
| SYS_RST | I | On power-up reset, the state machines, etc. are reset. |  |
| SYS_CLK | I | 33MHz system clock. |  |
| VRAM_DATA_A0[23:0] | I/O | Data bus between Frame Buffer and RB2.The data on this bus is read from/written to BankA, VRAM0. | 4mA |
| VRAM_DATA_A1[23:0] | I/O | Data bus between Frame Buffer and RB2. The data on this bus is read from/written to BankA, VRAM1. | 4mA |
| RCP1 | O | Phase detector output. |  |
| RCP2 | I | PLL VCO input. TEST PINS: |  |
| TEI/ IDDTN | I | I/O pin tri-state enable/ PLL IDDTN pin. |  |
| PTREE/ PLLCTRO | O | Parametric NAND tree output/ PLL test mode counter out- put. |  |
| PLL_TSTMD | I | When asserted, this pin puts the PLL in test mode. |  |
| PLL_TSTCLK | I | PLL test mode clock input. |  |
| PLL_RESET_N | I | PLL reset signal. POWER AND GROUND PINS: VDD +5v supply pins. VSS 0v supply pins. PLLVDD PLL power pin. PLLVSS PLL ground pin. PLLAGND PLL analog ground. |  |
| RB2 Specification | May 13, 2000 | Page 4 |  |

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
Figure2.1 Logical pin diagram of RB2
10
VCC
RB2_DATA_A0[7:0] VRAM_DATA_A0[23:0]
VRAM_DATA_A1[23:0]
RB2_DATA_A1[7:0]
RCP1
RB2_SELWMSK
RB2
RCP2
RB2SEL_A[2:0]
SYS_CLK PTREE/ PLLCTRO
TEI/ IDDTN
SYS_RST
PLL_TSTMD
PLL_TSTCLK
PLL_RESET_N
PLLVDD
PLLVSS
PLLAGND
GND
10
RB2 Specification	May 13, 2000	Page 5

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
Chapter 3
3.0 System Interface
3.1 REX3 - RB2 Interface
The interface between RB2 and REX3 runs at 1/4 the page mode cycle or 15 ns(66 MHZ.). Every
clock 8-bits of data is tranferred between REX3 and RB2. For VRAM write, after 4 clocks the full
32 bits are latched into the RB2 and are then ready to be moved into the pixel pipe. For VRAM read,
24-bits of data are read from VRAM bus, re-formatted to RGBA format by READ Format Block
and sent out 8-bits at a time to REX3 via the RB2_DATA bus.
3.2 RB2 - VRAM Interface
This is the RB2 interface with the frame buffer(VRAM). Each bank of memory can perform a page
mode read or a page mode write of two adjacent pixels in 60 ns. When reading or writing pixels at
the maximum rate, each memory bank must receive a new 24-bit data every 60 ns.
3.3 Tester Interface
RB2 does not have ATPG or JTAG testing capability. The only test pins are for parametric and PLL
tests.
TEI/IDDTN disables the output drivers of the bi-directional buffers for parametric test and PTREE/
PLLCTRO  is the output of the parametric NAND tree.The on chip Phase Lock Loop requires 5 pins
for testing: PLL_RESET_N which resets the PLL, PLL_TSTMD which places the PLL into Test
Mode, PLL_TSTCLK is the PLL test mode clock input, PTREE/PLLCTRO is the PLL test mode
counter output and TEI/IDDTN, PLL IDD test enable which is used used for PLL testing at LSI.
RB2 Specification	May 13, 2000	Page 6

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
Figure 3.1 Block Diagram of RB2 System Interface
FRAME
RB2_DATA_A0[7:0] BUFFER
| REX3 | RB2_DATA_A1[7:0] | RB2 | VRAM_DATA_A0[23:0] RB2SEL_A[2:0] RB2_SELWMSK_A VRAM_DATA_A1[23:0] RB2_DATA_B0[7:0] |
| --- | --- | --- | --- |
| RB2_DATA_B1[7:0] | RB2 | VRAM_DATA_B0[23:0] RB2SEL_B[2:0] RB2_SELWMSK_B VRAM_DATA_B1[23:0] RB2_DATA_C0[7:0] |  |
| RB2_DATA_C1[7:0] | RB2 | VRAM_DATA_C0[23:0] RB2SEL_C[2:0] RB2_SELWMSK_C VRAM_DATA_C1[23:0] RB2_DATA_D0[7:0] |  |
| RB2_DATA_D1[7:0] | RB2 | VRAM_DATA_D0[23:0] RB2SEL_D[2:0] RB2_SELWMSK_D VRAM_DATA_D1[23:0] SYS_RST SYS_CLK |  |
| RB2 Specification | May 13, 2000 | Page 7 |  |

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
Chapter 4
4.0 Functional Description
The data (color and alpha) from REX3 is first  latched into the RB2, go down the pixel pipe and is
processed depending upon the function specified by RB2SEL[2:0]  and draw register and is finally
written into the memory.
The pixel pipe in RB2 consists of LogicOp function and read and write formatter.
Since there are 8 pixel ports (2 pixels per bank), four RB2s are required with two of these pixel ports
located in each RB2. The datapaths for the two pixel ports and the pixel processor pipes, inside the
RB2 chip, are identical. The four RB2 chips interface to BankA, BankB, BankC and BankD of the
frame buffer. Each RB2 requires 70 signal pins.
4.1 Function  Selection
The function select pins of the RB2 ( RB2SEL[2:0] ) are decoded by the Dec_Cntl block and control
signals are generated to execute the specified function. These bits are pipelined as shown on the
block diagram so that the value of RB2SEL[2:0] at the input of RB2 apply to data 1 clock later.
RB2SEL[2:0] Operation
000 none
001 WRITE pixel plane or low pixel of OLAY/CID/PUP plane.
010 WRITE high pixel of OLAY/CID/PUP plane.
011 LOAD write mask and draw register.
100 READ pixel plane or low pixel of OLAY/CID/PUP plane.
101 READ high pixel of OLAY/CID/PUP plane.
110 CID CHECK: READ low pixel of CID plane.
111 CID CHECK: READ high pixel of CID plane.
Table 1. RB2_BSEL[2:0] Definition
4.2 Draw Register / Write Mask Register
The RB2 has a 24-bit write mask register and a 12-bit draw register. The write mask register is in
the datapath corresponding to sub-bank0 and the draw register is in the datapath corresponding to
sub-bank1. These registers are written into simultaneously by REX3 (RB2_DATA_A0 and
RB2_DATA_A1) by asserting RB2SEL[2:0]= ’011’ and cannot be read. The data from write mask
register is sent out to the VRAMs during RAS pre-charge time.
The draw register bits are defined as follows:
| bit11    bit10 | bit9 | bit [8:6] | bit[5:4] | bit[3:0] |
| --- | --- | --- | --- | --- |
| fast | rgb | dblsrc | planes (2:0) | drawdepth(1:0)   logicop(3:0) clearmode • Fast Clear: Active HI signal.  When this signal is HI, column mask is passed through the write formatter without any change, to the VRAM bus. |
| RB2 Specification | May 13, 2000 | Page 8 |  |  |

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
• RGB mode: Active HI. Selects RGB (vs. Color Index) pixel format.
• DBLSRC: Pixels read from source buffer of VRAM, (0=buffer0, 1=buffer1) are in double buffer
mode.
• Planes(2:0):  Specifies which frame buffer planes are enabled for R/W.
Planes[2:0] Function
000 none
001 R/W RGB/CI planes.
010 R/W RGBA planes.
011 X
100 R/W OLAY planes.
101 R/W PUP planes
110 R/W CID planes.
111 X
• Drawdepth(1:0): This is the drawn depth of framebuffer planes, not including alpha.
drawdepth[1:0] Depth
00 4 bits.
01 8 bits.
10 12 bits.
11 24 bits.
• Logicop: This is discussed in the following section.
4.3 LogicOp
Draw_register[3:0] defines the logic operation to be performed between the the pixels being
iterated(source pixels) and the pixels from the frame buffer(destination pixels) to generate the
resultant destination pixels to be written into the frame buffer. Logical Operations are disabled when
LogicOp = "0011".
RB2 Specification	May 13, 2000	Page 9

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
LogicOp is defined defined by the following table:
| Value | Name | Operation |
| --- | --- | --- |
| 0000 | Clear | 0 |
| 0001 | And | src AND dst |
| 0010 | AndReverse | src AND (NOT dst) |
| 0011 | Copy | src |
| 0100 | AndInverted | (NOT src) AND dst |
| 0101 | Noop | dst |
| 0110 | Xor | src XOR dst |
| 0111 | Or | src OR dst |
| 1000 | Nor | NOT (src OR dst) |
| 1001 | Equiv | NOT (src XOR dst) |
| 1010 | Invert | NOT dst |
| 1011 | OrReverse | src OR (NOT dst) |
| 1100 | CopyInverted | NOT src |
| 1101 | OrInverted | (NOT src) OR dst |
| 1110 | Nand | NOT (src AND dst) |
| 1111 | Set Table 4.3. LOGICOP[3:0] Definition 4.4 Write Format Block The pixels coming out of the Logicop block are write formatted depending on the bits specified in the draw_register. The different write formats are specified in Table 4.4 at the end of the chapter. 4.5 Read Format Block Data read back from the frame buffer are formatted by this block. It is the reverse of write formatting in that it takes 24-bits in frame buffer format and converts it to 32-bits RGBA. The read format is specified by dblsrc, drawdepth bits of draw register and also whether it is CID check and whether access is to CID/PUP/OLAY planes of frame buffer. 4.6 RB2-VRAM bus source control The RB2_SELWMSK controls a 2 to 1 multiplexer that chooses between the writemask register and the write data register. Table 4.6 shows the encoding of this signal. The RAS signal will be connected to this pin , so that when RAS is high the write mask register is presented to the VRAMs and when RAS goes low the write data register will be sourced to the output pins. The RB2_SELWMSK is clocked before it is used internally. RB2_WRITE signal is driven by DEC_CNTL block by decoding RB2SEL_A[2:0]. | 1 |
| RB2_WRITE | RB2_SELWMSK | RB2-VRAM bus |
| 1 | 0 | write data register |
| 1 | 1 | write mask register |
| 0 | X | tristate Table 4.6. RB2_SELWMSK definition |
| RB2 Specification | May 13, 2000 | Page 10 |

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
4.7 Decode and Control block
The DEC_CNTL block decodes the reclocked versions of the RB2SEL_A[2:0], RB2_SELWMSK
input pins and draw register bits  and generates load enable signals for the pipeline registers, the
tristate enable for the bidirectional buses and control signals for Logicop, Read Format and Write
Format blocks. This block also includes the state machines needed to generate a number of the above
mentioned control signals.
4.8 RB2 clock
In order to minimize on-chip clock skew between REX3 and RB2, a 33MHz system clock (
SYS_CLK) is applied to the input of a PLL circuit in the RB2 and REX3 chips. The PLL, while
tracking the system clock to minimize skew, also multiplies the input frequency by a factor of 2 to
66MHz which is then used as the internal clock (RB2_CLK) at which the RB2 operates.
4.9 Chip Reset and Initialization
When SYS_RST signal is asserted, all state machines in RB2 are reset to IDLE state.
RB2 Specification	May 13, 2000	Page 11

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
D D D D D D D D D D D D D D D D D D D D D D D D
BIT
PIXEL TYPE	2	2	2	2	1	1	1	1	1	1	1	1	1	1	9	8	7	6	5	4	3	2	1	0
PLANES
3	2	1	0	9	8	7	6	5	4	3	2	1	0
RGB-SB B R G B R G B R G B R G B R G B R G B R G B R G
24	24BIT	0	0	0	1	1	1	2	2	2	3	3	3	4	4	4	5	5	5	6	6	6	7	7	7
RGB-DB B R G B R G B R G B R G B R G B R G B R G B R G
24	444+444	4	4	4	5	5	5	6	6	6	7	7	7	4	4	4	5	5	5	6	6	6	7	7	7
CI-SB	I	I	I	I	I	I	I	I	I	I	I	I
24	12BIT	------------1	1	9	8	7	6	5	4	3	2	1	0
1 0
CI-DB	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I	I
24	12+12	1	1	9	8	7	6	5	4	3	2	1	0	1	1	9	8	7	6	5	4	3	2	1	0
| 1 | 0 RGB-SB R G B R G B R G | 1 | 0 |
| --- | --- | --- | --- |
| 8/24 | 8BIT 332 | ----------------5 RGB-DB G B R G G B R G | 5 6 6 6 7 7 7 |
| 8/24 | 8BIT | ----------------6 121+121 | 7 7 7 6 7 7 7 |
| CI-SB | I | I | I I I I I I |
| 8/24 | 8BIT | ----------------7 | 6 5 4 3 2 1 0 |
| CI-DB | I | I | I I I I I I |
| 8/24 | 4+4 | ----------------3 | 2 1 0 3 2 1 0 |
| RGBa- DB | a | a | a a R G B R G B R G a a a a R G B R G B R G |
| 24 | 3324 + 3324 | 4 | 5 6 7 5 5 6 6 6 7 7 7 4 5 6 7 5 5 6 6 6 7 7 7 |
| RGBa- SB | a | a | a a a a a a B R G B R G B R G B R G |
| 24 | 444 8 | ----0 | 1 2 3 4 5 6 7 4 4 4 5 5 5 6 6 6 7 7 7 CID/AUX A A A A A A A A A A A A A A A A P P C C P P C C |
| 24 | 2BITS-CID | 8 | 8 8 8 0 0 0 0 8 8 8 8 0 0 0 0 8 8 8 8 0 0 0 0 |
| 2BITS-PUP | 7 | 6 | 5 4 7 6 5 4 3 2 1 0 3 2 1 0 1 0 1 0 1 0 1 0 8BIT AUX CID/AUX A A A A A A A A A A A A A A A A P P C C P P C C |
| 24 | 2BITS-CID | 8 | 8 8 8 0 0 0 0 8 8 8 8 0 0 0 0 8 8 8 8 0 0 0 0 |
| 2BITS-PUP | 1 | 1 | 1 1 1 1 1 1 0 0 0 0 0 0 0 0 1 0 1 0 1 0 1 0 |
| 4+4 AUX | 3 | 2 | 1 0 3 2 1 0 3 2 1 0 3 2 1 0 2BITS-CID P P C C P P C C |
| 8 | 2BITS-PUP | ----------------8 | 8 8 8 0 0 0 0 |
| 1 | 0 | 1 | 0 1 0 1 0 |
| NOTES: R - Red, G - Green, B - Blue, In - Color index, C | - CIDpixel, bit field, P p,n p,n A - OLAYpixel, (buffer), bit field,a - Alpha p,(b),n n Table 4.4. Frame Buffer pixel formats | - PUPpixel, bit field, |  |
| RB2 Specification | May 13, 2000 | Page 12 |  |

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
Chapter 5
5.0 Device Characteristics
5.1 Absolute Maximum Ratings
Stresses beyond those listed may cause permanent damage to the device.  These are stress ratings
only, and functional operation of the device at these or any other conditions beyond those listed in
the operating range section of this specification is not implied. Exposure to absolute maximum rated
conditions for extended periods may affect device reliability.
Ambient Operating Temperature with voltage applied  (Junction tempera- -40  ̊C to + 85  ̊C
ture not to exceed ambient temperature by more than 20  ̊ C.)
Storage Temperature -40  ̊C
Supply Voltage -0.50 V to +6.00V
Input Voltage -0.50 V to +5.50V
DC Input Current 20 mA
Lead Temperature 300  ̊C
Table 5.1 Absolute maximum ratings
5.2 Recommended Operating Range
Ambient Operating Temperature with voltage applied 0  ̊C to + 70  ̊C
(Junction temperature not to exceed ambient temperature by more than 20  ̊ C.)
VDD Supply Voltage  (VSS = 0.00 V) +4.75 V to +5.25
Table 5.2 Operating range
5.3 DC Characteristics
| Parameter | Description | Test Condition | Min | Max | Unit |
| --- | --- | --- | --- | --- | --- |
| VIL | Low Input Voltage | 0.3 VDD | V |  |  |
| VIH | High Input Voltage | 0.7 VDD | V |  |  |
| VOL | Low Output Voltage | IOL= 8.0 mA | 0.4 | V |  |
| VOH | High Output Voltage | IOH= -8.0mA | 2.4 | V |  |
| IIL | Input Leakage Current | VIN= VDDor VSS | -10 | 10 | mA |
| IOZ | Output Leakage Current   VOUT= VSSor VDD | -10 | 10 | mA |  |
| COUT | Output Capacitance Table 5.3 DC characteristics | 10 | pF |  |  |
| RB2 Specification | May 13, 2000 | Page 13 |  |  |  |

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
5.4 AC Characteristics
| Name | Description | Min | Max |
| --- | --- | --- | --- |
| tVOUT | Clock to output delay of RB2-VRAM bus | 3ns | 13ns |
| tVSU | Setup time with respect to clock for RB2-VRAM bus | 2ns |  |
| tVH | Hold time with respect to clock for RB2-VRAM bus | 1ns |  |
| tROUT | Clock to output delay of RB2-REX3 bus | 2ns | 13ns |
| tRSU | Setup time for signals latched by RB2_CLK | 1ns |  |
| tRH | Hold time for signals latched by RB2_CLK tRB2_CLK  Clock period of RB2_CLK (internal clock) 15ns Table 5.4 Timing Requirements Notes: Load on RB2-VRAM bus is 30pf.  Load on RB2-REX3 bus is 25pf. Worst case operating conditions are Vcc = 4.75V and Tj = 110 C. | 3ns |  |
| RB2 Specification | May 13, 2000 | Page 14 |  |

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
Chapter 6
6.0 Revision History
RB2 Specification	May 13, 2000	Page 15

SILICON GRAPHICS CONFIDENTIAL AND PROPRIETARY
APPENDIX 1
RB2 TIMING DIAGRAMS
RB2 Specification	May 13, 2000	Page 16
