# VR5000 User Manual

User’s Manual
VR5000™,VR5000A™
64-/32-bit Microprocessor
μPD30500
μPD30500A
Document No.  U11761EJ6V0UM00 (6th edition)
Date Published  April 2001 N  CP(K)
© 1997, 1999
© MIPS Technologies, Inc. 1995
Printed in Japan
1

[MEMO]
2 User’s Manual   U11761EJ6V0UM

NOTES FOR CMOS DEVICES
1 PRECAUTION AGAINST ESD FOR SEMICONDUCTORS
Note:
Strong electric field, when exposed to a MOS device, can cause destruction of the gate oxide and
ultimately degrade the device operation.  Steps must be taken to stop generation of static electricity
as much as possible, and quickly dissipate it once, when it has occurred.  Environmental control
must be adequate.  When it is dry, humidifier should be used.  It is recommended to avoid using
insulators that easily build static electricity.  Semiconductor devices must be stored and transported
in an anti-static container, static shielding bag or conductive material.  All test and measurement
tools including work bench and floor should be grounded.  The operator should be grounded using
wrist strap.  Semiconductor devices must not be touched with bare hands.  Similar precautions need
to be taken for PW boards with semiconductor devices on it.
2 HANDLING OF UNUSED INPUT PINS FOR CMOS
Note:
No connection for CMOS device inputs can be cause of malfunction.  If no connection is provided
to the input pins, it is possible that an internal input level may be generated due to noise, etc., hence
causing malfunction.  CMOS devices behave differently than Bipolar or NMOS devices.  Input levels
of CMOS devices must be fixed high or low by using a pull-up or pull-down circuitry.  Each unused
pin should be connected to VDDor GND with a resistor, if it is considered to have a possibility of
being an output pin.  All handling related to the unused pins must be judged device by device and
related specifications governing the devices.
3 STATUS BEFORE INITIALIZATION OF MOS DEVICES
Note:
Power-on does not necessarily define initial status of MOS device.  Production process of MOS
does not define the initial operation status of the device.  Immediately after the power source is
turned ON, the devices with reset function have not yet been initialized.  Hence, power-on does
not guarantee out-pin levels, I/O settings or contents of registers.  Device is not initialized until the
reset signal is received.  Reset operation must be executed immediately after power-on for devices
having reset function.
VR4000, VR4100, VR4200, VR4300, VR4305, VR4310, VR4400, VR5000, VR5000A, VR10000, VR12000, VRSeries,
VR3000 Series, VR4000 Series, and VR10000 Series are trademarks of NEC Corporation.
MIPS is a registered trademark of MIPS Technologies, Inc. in the United States.
MC68000 is a trademark of Motorola Inc.
IBM370 is a trademark of IBM Corp.
iAPX is a trademark of Intel Corp.
VAX is a trademark of Digital Equipment Corp.
UNIX is a registered trademark in the United States and other countries, licensed exclusively through
X/Open Company, Ltd.
User’s Manual   U11761EJ6V0UM 3

Exporting this product or equipment that includes this product may require a governmental license from theU.S.A. for some
countries because this product utilizes technologies limited by the export controlregulations of the U.S.A.
• The information in this document is current as of March, 2001. Theinformation is subject to change
without  notice.    For  actual  design-in,  refer  to  the  latest  publications  of  NEC's  data  sheets  or  data
books, etc., for the most up-to-date specifications of NEC semiconductor products.  Not all products
and/or  types  are  available  in  every  country.    Please  check  with  an  NEC  sales  representative  for
availability and additional information.
• No  part  of  this  document  may  be  copied  or  reproduced  in  any  form  or  by  any  means  without  prior
written consent of NEC.  NEC assumes no responsibility for any errors that may appear inthisdocument.
• NEC  does  not  assume  any  liability  for  infringement  of  patents,  copyrights  or  other  intellectualpropertyrights  of
third parties by or arising from the use of NEC semiconductor products listed in this document or any other
liability arisingfrom the use ofsuch products.  No license, express, implied or otherwise, is granted under any
patents,copyrights or otherintellectual property rights of NEC or others.
• Descriptions of circuits, software and other related information in this document are provided for illustrative
purposes  in  semiconductor  product  operation  and  application  examples.  The  incorporation  of  these
circuits,software  and  information  in  the  design  of  customer's  equipment  shall  be  done  under  the  full
responsibility  ofcustomer.NEC  assumes  no  responsibility  for  any  losses  incurred  by  customers  or  third
parties arising fromthe use of these circuits, software and information.
• While NEC endeavours to enhance the quality, reliability and safety of NEC semiconductor products, customers
agree  and  acknowledge  that  thepossibility  of  defects  thereof  cannot  be  eliminated  entirely.    To  minimize
risks  of  damage  to  property  or  injury  (including  death)  to  persons  arising  from  defects  in  NEC
semiconductor  products,  customers  must  incorporate  sufficient  safety  measures  in  their  design,  such  as
redundancy, fire-containment, and anti-failure features.
• NEC semiconductor products are classified into the following three quality grades:
"Standard",  "Special"  and  "Specific".    The  "Specific"  quality  grade  applies  only  to  semiconductor  products
developed  based  on  a  customer-designated  "quality  assurance  program"  for  a  specific  application.    The
recommended  applications  of  a  semiconductor  product  depend  on  its  quality  grade,  as  indicated  below.
Customers  must  check  the  quality  grade  of  each  semiconductor  productbefore  using  it  in  a  particular
application.
"Standard":Computers, office equipment, communications equipment, test and measurement equipment, audio
and visual equipment, home electronic appliances, machine tools, personal electronic equipment
and industrial robots
"Special": Transportation equipment (automobiles, trains, ships, etc.), traffic control systems, anti-disaster
systems, anti-crime systems, safety equipment and medical equipment (not specifically designed
for life support)
"Specific":  Aircraft, aerospace equipment, submersible repeaters, nuclear reactor control systems, life
support systems and medical equipment for life support, etc.
The quality grade of NEC semiconductor products is "Standard" unless otherwise expressly specified in NEC's
data  sheets  or  data  books,  etc.    Ifcustomers  wish  to  use  NEC  semiconductor  products  in  applications  not
intended by NEC, they must contact an NEC sales representative in advance to determine NEC's willingness
to support a given application.
(Note)
(1) "NEC" as used in this statement means NEC Corporation and also includes its majority-owned subsidiaries.
(2) "NEC semiconductor products" means any semiconductor product developed or manufactured by or for
NEC (as defined above).
M8E  00. 4
4 User’s Manual   U11761EJ6V0UM

Regional Information
Some information contained in this document may vary from country to country.  Before using any NEC
product in your application, pIease contact the NEC office in your country to obtain a list of authorized
representatives and distributors.  They will verify:
•Device availability
•Ordering information
•Product release schedule
•Availability of related technical literature
•Development environment specifications (for example, specifications for third-party tools and
components, host computers, power plugs, AC supply voltages, and so forth)
•Network requirements
In addition, trademarks, registered trademarks, export restrictions, and other legal issues may also vary
from country to country.
| NEC Electronics Inc. (U.S.) | NEC Electronics (Germany) GmbH | NEC Electronics Hong Kong Ltd. |
| --- | --- | --- |
| Santa Clara, California | Benelux Office | Hong Kong |
| Tel: 408-588-6000 | Eindhoven, The Netherlands | Tel: 2886-9318 |
| 800-366-9782 | Tel: 040-2445845 | Fax: 2886-9022/9044 Fax: 408-588-6130 Fax: 040-2444580 800-729-9288 NEC Electronics Hong Kong Ltd. NEC Electronics (France) S.A. Seoul Branch |
| NEC Electronics (Germany) GmbH | Velizy-Villacoublay, France | Seoul, Korea |
| Duesseldorf, Germany | Tel: 01-3067-5800 | Tel: 02-528-0303 |
| Tel: 0211-65 03 02 | Fax: 01-3067-5899 Fax: 0211-65 03 490 NEC Electronics Singapore Pte. Ltd. NEC Electronics (France) S.A. | Fax: 02-528-4411 |
| NEC Electronics (UK) Ltd. | Madrid Office | Novena Square, Singapore |
| Milton Keynes, UK | Madrid, Spain | Tel: 253-8311 |
| Tel: 01908-691-133 | Tel: 091-504-2787 Fax: 01908-670-290 Fax: 091-504-2860 NEC Electronics Taiwan Ltd. NEC Electronics Italiana s.r.l. Taipei, Taiwan NEC Electronics (Germany) GmbH Milano, Italy Tel: 02-2719-2377 Scandinavia Office Tel: 02-66 75 41 Fax: 02-2719-5951 Taeby, Sweden Fax: 02-66 75 42 99 Tel: 08-63 80 820 Fax: 08-63 80 388 NEC do Brasil S.A. Electron Devices Division Guarulhos-SP, Brasil Tel: 11-6462-6810 Fax: 11-6462-6829 J01.2 User’s Manual   U11761EJ6V0UM 5 | Fax: 250-3583 |

MAJOR REVISIONS IN THIS EDITION
Page Description
p. 143 Correction of description in7.2.5 (1) Status Register Format
p. 212 Modification of description in9.4.6 Unimplemented Instruction Exception (E)
The mark shows major revised points.
6 User’s Manual   U11761EJ6V0UM

PREFACE
Readers This  manual  targets  users  who  wish  to  understand  the  functions  of  the  V 5000
R
(μPD30500),  V 5000A(μPD30500A)and  design  application  systems  using  this
R
microprocessor.
Purpose This manual introduces the architecture and hardware functions of the V 5000 and
R
V 5000A to users, following the organization described below.
R
Organization This manual consists of the following contents:
•  Introduction
•  Pipeline operation
•  Memory management system and cache organization
•  Exception processing
•  Floating-point operation
•  System interface operation
How to read this manual It is assumed that the reader of this manual has general knowledge in the fields of
electric engineering, logic circuits, and microcomputers.
Unless otherwise specified, V 5000 is described as a representative product in this
R
manual. When using this manual as that for V 5000A, read as follows.
R
V 5000→V 5000Α
R R
The V 4400™in this manual represents the V 4000™.
R R
The   V 4000   Series™ in   this   manual   represents   the   V 4100™,   V 4200™,
R	R	R
VR4300™, V 4305™, V 4310™, and V 4400.
R	R	R
To learn about detailed function of a specific instruction,
-> Refer toChapter 3 CPU Instruction Set Summary,Chapter 8 Floating
Point Unit, orV 5000,V 10000™ User’s Manual Instructionwhich is
R R
separately available.
To learn about the overall functions of the V 5000,
R
-> Read this manual in sequential order.
To learn about electrical specifications,
-> Refer toData Sheetwhich is separately available.
User’s Manual   U11761EJ6V0UM 7

Legend	Data significance:	Higher on left and lower on right
Active low: XXX*
Numeric representation: binary ... XXXX or XXXX
2
decimal ... XXXX
hexadecimal ... 0xXXXX
Prefixes representing an exponent of 2 (for address space or memory capacity) :
10
K (kilo) 2 = 1024
20 2
M (mega) 2 = 1024
30 3
G (giga) 2 = 1024
40 4
T (tera) 2 = 1024
50 5
P (peta) 2 = 1024
60 6
E (exa) 2 = 1024
Related Documents See also the following documents.
The  related  documents  indicated  here  may  include  preliminary  version.  However,
preliminary versions are not marked as such.
Documents Related to Devices
Document Name Document No.
μPD30500, 30500A (V5000, V5000A) Data Sheet U12031E
R R
V5000, V5000A User’s Manual This Manual
R R
μPD30700, 30700L, 30710 (V10000, V12000™) Data Sheet U12703E
R R
V10000 Series™User’s Manual U10278E
R
V5000, V10000INSTRUCTION User’s Manual U12754E
R R
Application Note
Document Name Document No.
VSeries™Application Note Programming Guide U10710E
R
8 User’s Manual   U11761EJ6V0UM

Table of Contents
Chapter 1 Introduction.................................................................................................25
1.1 Processor Characteristics....................................................................................26
1.2 Ordering Information..........................................................................................27
1.3 64-Bit Architecture...............................................................................................27
1.4 V 5000 Processor..................................................................................................27
R
1.4.1 Internal Block Configuration ....................................................................29
1.4.2 CPU Registers ...........................................................................................30
1.4.3 CPU Instruction Set Overview..................................................................32
1.4.4 Data Formats and Addressing ...................................................................34
1.4.5 System Control Coprocessor (CP0) ..........................................................37
1.4.6 Floating-Point Unit (FPU).........................................................................40
1.4.7 Internal Cache ...........................................................................................40
1.5 Memory Management System (MMU)............................................................41
1.5.1 Translation Lookaside Buffer (TLB) ........................................................41
1.5.2 Operating Modes .......................................................................................42
1.6 Instruction Pipeline...............................................................................................42
Chapter 2 V 5000 Processor Signal Descriptions..............................................43
R
2.1 System Interface Signals......................................................................................44
2.2 Clock Interface Signals........................................................................................46
2.3 Secondary Cache Interface Signals...................................................................46
2.4 Interrupt Interface Signals.................................................................................48
2.5 Initialization Interface Signals...........................................................................48
2.6 Power Supply..........................................................................................................50
2.7 Pin Configuration..................................................................................................51
Chapter 3 CPU Instruction Set Summary............................................................58
3.1 Load and Store Instructions...............................................................................59
3.1.1 Scheduling a Load Delay Slot...................................................................60
3.1.2 Defining Access Types .............................................................................60
3.2 Computational Instructions................................................................................62
3.2.1 64-bit Operations.......................................................................................62
3.2.2 Cycle Timing for Multiply and Divide Instructions .................................62
3.2.3 Jump and Branch Instructions ...................................................................63
3.2.4 Special Instructions ...................................................................................64
3.2.5 Coprocessor Instructions ...........................................................................64
User’s Manual  U11761EJ6V0UM 9

3.3 MIPS IV Instruction Set Additions..................................................................64
3.3.1 Summary of Instruction Set Additions......................................................67
3.3.2 Cycle Timing for Floating Point Instrucitons ...........................................71
3.4 The Cache Instruction..........................................................................................72
3.5 Implementation Specific Instructions..............................................................75
3.5.1 Implementation Specific CP0 Instructions................................................76
Chapter 4 V 5000 Processor Pipeline.....................................................................85
R
4.1 Instruction Pipeline Stages..................................................................................86
4.2 Branch Delay..........................................................................................................90
4.3 Load Delay..............................................................................................................90
4.4 Interlock and Exception Handling....................................................................91
4.4.1 Exception Conditions ................................................................................94
4.4.2 Stall Conditions .........................................................................................95
4.4.3 Slip Conditions..........................................................................................96
4.5 Write Buffer............................................................................................................97
Chapter 5 Superscalar Issue Mechanism..............................................................98
Chapter 6 Memory Management Unit.................................................................101
6.1 Translation Lookaside Buffer (TLB).............................................................102
6.1.1 Hits and Misses .......................................................................................102
6.1.2 Multiple Matches ....................................................................................102
6.2 Processor Modes..................................................................................................102
6.2.1 Processor Operating Modes ....................................................................103
6.2.2 Instruction Set Mode ...............................................................................104
6.2.3 Addressing Modes...................................................................................104
6.3 Address Spaces.....................................................................................................104
6.3.1 Virtual Address Space.............................................................................104
6.3.2 Physical Address Space...........................................................................105
6.3.3 Virtual-to-Physical Address Translation.................................................105
6.3.4 32-bit Mode Virtual Address Translation ...............................................106
6.3.5 64-bit Mode Virtual Address Translation ...............................................107
6.3.6 Address Spaces........................................................................................108
6.3.7 User Address Space................................................................................108
6.3.8 Supervisor Space ....................................................................................110
6.3.9 Kernel Space ..........................................................................................113
10 User’s Manual  U11761EJ6V0UM

6.4 System Control Coprocessor............................................................................118
6.4.1 Format of a TLB Entry............................................................................119
6.5 CP0 Registers.......................................................................................................123
6.5.1 Index Register (0)....................................................................................124
6.5.2 Random Register (1) ...............................................................................125
6.5.3 EntryLo0 (2), and EntryLo1 (3) Registers ..............................................126
6.5.4 PageMask Register (5) ............................................................................126
6.5.5 Wired Register (6)...................................................................................127
6.5.6 EntryHi Register (10) ..............................................................................128
6.5.7 Processor Revision Identifier (PRId) Register (15) ................................128
6.5.8 Config Register (16)................................................................................129
6.5.9 Load Linked Address (LLAddr) Register (17) .......................................132
6.5.10 Cache Tag Registers [TagLo (28) and TagHi (29)] ................................132
6.6 Virtual-to-Physical Address Translation Process.......................................135
6.7 TLB Exceptions....................................................................................................137
6.8 TLB Instructions.................................................................................................137
Chapter 7 CPU Exception Processing...................................................................138
7.1 Overview of Exception Processing..................................................................138
7.2 Exception Processing Registers........................................................................139
7.2.1 Context Register (4) ................................................................................140
7.2.2 Bad Virtual Address Register (BadVAddr) (8).......................................141
7.2.3 Count Register (9) ...................................................................................141
7.2.4 Compare Register (11) ............................................................................142
7.2.5 Status Register (12) .................................................................................142
7.2.6 Cause Register (13) .................................................................................147
7.2.7 Exception Program Counter (EPC) Register (14) ...................................149
7.2.8 XContext Register (20) ...........................................................................150
7.2.9 Error Checking and Correcting (ECC) Register (26)..............................151
7.2.10 Cache Error (CacheErr) Register (27).....................................................152
7.2.11 Error Exception Program Counter (Error EPC) Register (30) ................154
7.3 Processor Exceptions..........................................................................................154
7.3.1 Exception Types......................................................................................155
7.3.2 Exception Vector Locations ....................................................................157
7.3.3 Priority of Exceptions .............................................................................160
7.3.4 Reset Exception.......................................................................................161
7.3.5 Soft Reset Exception ...............................................................................161
7.3.6 Non Maskable Interrupt (NMI) Exception..............................................162
User’s Manual  U11761EJ6V0UM 11

7.3.7 Address Error Exception .........................................................................163
7.3.8 TLB Exceptions ......................................................................................164
7.3.9 Cache Error Exception ............................................................................167
7.3.10 Bus Error Exception ................................................................................168
7.3.11 Integer Overflow Exception ....................................................................169
7.3.12 Trap Exception ........................................................................................169
7.3.13 System Call Exception ............................................................................170
7.3.14 Breakpoint Exception..............................................................................170
7.3.15 Reserved Instruction Exception ..............................................................171
7.3.16 Coprocessor Unusable Exception ...........................................................172
7.3.17 Floating-Point Exception ........................................................................173
7.3.18 Interrupt Exception..................................................................................173
7.4 Exception Handling and Servicing Flowcharts...........................................174
Chapter 8 Floating Point Unit..................................................................................181
8.1 Overview................................................................................................................182
8.2 FPU Features........................................................................................................183
8.3 FPU Programming Model.................................................................................183
8.4 Floating-Point General Registers (FGRs).....................................................183
8.5 Floating-Point Registers....................................................................................185
8.6 Floating-Point Control Registers.....................................................................186
8.6.1 Implementation and Revision Register (FCR0) ......................................187
8.6.2 Control/Status Register (FCR31) ............................................................188
8.7 Floating-Point Formats......................................................................................192
8.8 Binary Fixed-Point Format...............................................................................194
8.9 Floating-Point Instruction Set Overview.......................................................195
8.9.1 Floating-Point Load, Store, and Move Instructions ................................197
8.9.2 Floating-Point Conversion Instructions ..................................................199
8.9.3 Floating-Point Computational Instructions .............................................199
8.10 FPU Instruction Pipeline Overview................................................................200
8.10.1 Instruction Execution ..............................................................................200
8.10.2 Instruction Execution Cycle Time ..........................................................201
8.10.3 Instruction Scheduling Constraints .........................................................203
Chapter 9 Floating Point Exceptions.....................................................................204
9.1 Exception Types...................................................................................................204
9.2 Exception Trap Processing...............................................................................206
12 User’s Manual  U11761EJ6V0UM

9.3 Flags........................................................................................................................206
9.4 FPU Exceptions....................................................................................................208
9.4.1 Inexact Exception (I)...............................................................................208
9.4.2 Invalid Operation Exception (V).............................................................209
9.4.3 Division-by-Zero Exception (Z) .............................................................210
9.4.4 Overflow Exception (O)..........................................................................210
9.4.5 Underflow Exception (U)........................................................................210
9.4.6 Unimplemented Instruction Exception (E) .............................................211
9.5 Saving and Restoring State...............................................................................212
9.6 Trap Handlers for IEEE Standard 754 Exceptions....................................213
Chapter 10 Initialization Interface..........................................................................214
10.1 Processor Reset Signals......................................................................................214
10.1.1 Power-on Reset .......................................................................................215
10.1.2 Cold Reset ...............................................................................................216
10.1.3 Warm Reset .............................................................................................217
10.1.4 Processor Reset State ..............................................................................218
10.2 Initialization Sequence.......................................................................................218
10.3 Boot-Mode Settings.............................................................................................219
Chapter 11 Clock Interface........................................................................................222
11.1 Basic System Clocks............................................................................................222
11.1.1 SysClock .................................................................................................222
11.1.2 PClock .....................................................................................................222
11.1.3 Alignment to SysClock ...........................................................................223
11.1.4 Phase-Locked Loop (PLL) ......................................................................223
11.2 Connecting Clocks to a Phase-Locked System.............................................224
Chapter 12 Cache Organization and Operation.................................................225
12.1 Memory Organization........................................................................................226
12.2 Primary Cache Organization...........................................................................227
12.2.1 Cache Line Lengths.................................................................................227
12.2.2 Cache Sizes .............................................................................................227
12.2.3 Organization of the Instruction Cache (I-Cache) ....................................228
12.2.4 Organization of the Data Cache (D-Cache) ............................................229
12.3 Secondary Cache Organization.......................................................................230
User’s Manual  U11761EJ6V0UM 13

Chapter 13 V 5000 Processor Bus Interface......................................................231
R
13.1 Terms Used...........................................................................................................232
13.2 Interface Buses.....................................................................................................232
Chapter 14 System Interface Transactions...........................................................234
14.1 Processor Requests..............................................................................................234
14.1.1 Rules for Processor Requests ..................................................................235
14.1.2 Processor Read Request ..........................................................................236
14.1.3 Processor Write Request .........................................................................237
14.2 External Requests................................................................................................237
14.2.1 External Write Request ...........................................................................239
14.2.2 Read Response ........................................................................................239
14.3 Handling Requests..............................................................................................240
14.3.1 Load Miss................................................................................................240
14.3.2 Store Miss................................................................................................241
14.3.3 Store Hit ..................................................................................................243
14.3.4 Uncached Loads or Stores.......................................................................243
14.3.5 Uncached Instruction Fetch.....................................................................243
14.3.6 Load Linked Store Conditional Operation ..............................................243
Chapter 15 System Interface Protocols.................................................................244
15.1 Address and Data Cycles...................................................................................244
15.2 Issue Cycles...........................................................................................................245
15.3 Handshake Signals..............................................................................................246
15.4 System Interface Operation..............................................................................247
15.4.1 Master and Slave States ..........................................................................248
15.4.2 External Arbitration ................................................................................248
15.4.3 Uncompelled Change to Slave State .......................................................248
15.5 Processor Request Protocols.............................................................................249
15.5.1 Processor Read Request Protocol............................................................250
15.5.2 Processor Write Request Protocol...........................................................251
15.5.3 Processor Request Flow Control .............................................................254
15.6 External Request Protocols...............................................................................258
15.6.1 External Arbitration Protocol ..................................................................259
15.6.2 External Null Request Protocol...............................................................260
15.6.3 External Write Request Protocol.............................................................261
15.6.4 Read Response Protocol..........................................................................262
14 User’s Manual  U11761EJ6V0UM

15.7 SysADC[7:0] Protocol........................................................................................264
15.8 Data Rate Control...............................................................................................265
15.9 Data Transfer Patterns......................................................................................266
15.10 Independent Transmissions on the SysAD Bus...........................................267
15.11 System Interface Endianness............................................................................267
15.12 System Interface Cycle Time............................................................................268
15.13 Release Latency....................................................................................................268
15.14 System Interface Commands/Data Identifiers.............................................269
15.14.1 Command and Data Identifier Syntax.....................................................269
15.14.2 System Interface Command Syntax ........................................................270
15.14.3 System Interface Data Identifier Syntax .................................................273
15.15 System Interface Addresses..............................................................................275
15.15.1 Addressing Conventions .........................................................................275
15.15.2 Subblock Ordering ..................................................................................276
15.15.3 Processor Internal Address Map .............................................................278
15.16 Error Checking....................................................................................................278
15.16.1 Parity Error Checking .............................................................................278
15.16.2 Error Checking Operation .......................................................................279
Chapter 16 Secondary Cache Interface..................................................................283
16.1 Secondary Cache Transactions........................................................................283
16.1.1 Secondary Cache Probe, Invalidate, and Clear .......................................284
16.1.2 Secondary Cache Write...........................................................................285
16.1.3 Secondary Cache Read............................................................................286
16.2 Secondary Cache Read Protocol.....................................................................287
16.2.1 Secondary Cache Read Hit......................................................................288
16.2.2 Secondary Cache Read Miss ...................................................................289
16.2.3 Secondary Cache Read Miss with Bus Error ..........................................291
16.3 Secondary Cache Write.....................................................................................292
16.4 Secondary Cache Line Invalidate....................................................................294
16.5 Secondary Cache Probe Protocol....................................................................295
16.6 Secondary Cache Flash Clear Protocol.........................................................296
16.7 Secondary Cache Mode Configuration..........................................................296
Chapter 17 Interrupts....................................................................................................298
17.1 Hardware Interrupts..........................................................................................298
17.2 Nonmaskable Interrupt (NMI).......................................................................299
User’s Manual  U11761EJ6V0UM 15

17.3 Asserting Interrupts............................................................................................299
Chapter 18 Standby Mode Operation.....................................................................303
18.1 Entering Standby Mode.....................................................................................303
Chapter 19 PLL Analog Power Filtering...............................................................305
Chapter 20 V 5000 Instruction Hazards...............................................................307
R
20.1 Introduction..........................................................................................................307
20.2 List of Instruction Hazards...............................................................................308
Appendix A Cycle Counts for V 5000 Cache Operations................................309
R
A.1 Cycle Counts for V 5000 Cache Misses........................................................309
R
A.1.1 Mnemonics ..............................................................................................309
A.1.2 DCache Misses........................................................................................310
A.1.3 ICache Misses .........................................................................................311
A.2 Cycle Counts for V 5000 Cache Operations................................................311
R
Appendix B Subblock Order........................................................................................314
Appendix C Driver Strength Control........................................................................317
Appendix D Differences between V 5000 and V 5000A..................................318
R R
Appendix E Differences between V 5000 and V 4310.....................................319
R R
Appendix F V 5000 Restrictions................................................................................321
R
Appendix G Index..............................................................................................................323
16 User’s Manual  U11761EJ6V0UM

List of Figures (1/5)
Fig. No.	Title	Page
1-1 V 5000 Processor Internal Block Diagram ...............................................................28
R
1-2 V 5000 Processor Registers.......................................................................................31
R
1-3 CPU Instruction Formats ............................................................................................32
1-4 Big-Endian Byte Ordering..........................................................................................34
1-5 Little-Endian Byte Ordering.......................................................................................34
1-6 Big-Endian Data in a Doubleword .............................................................................35
1-7 Little-Endian Data in a Doubleword ..........................................................................35
1-8 Misaligned Word Addressing.....................................................................................36
1-9 CP0 Registers .............................................................................................................38
2-1 V 5000 Processor Signals..........................................................................................44
R
3-1 CPU Instruction Formats ............................................................................................59
3-2 V 5000 CACHE Instruction Format..........................................................................72
R
4-1 Instruction Pipeline Stages .........................................................................................86
4-2 CPU Pipeline Activities..............................................................................................89
4-3 CPU Pipeline Branch Delay .......................................................................................90
4-4 CPU Pipeline Load Delay ..........................................................................................91
4-5 Exception Detection Mechanism................................................................................94
4-6 Servicing a Data Cache Miss......................................................................................95
4-7 Slips During an Instruction Cache Miss .....................................................................96
5-1 Dual Issue Mechanism ...............................................................................................99
6-1 Overview of a Virtual-to-Physical Address Translation ..........................................105
6-2 32-bit Mode Virtual Address Translation.................................................................106
6-3 64-bit Mode Virtual Address Translation.................................................................107
6-4 UserVirtual Address Space as Viewed from User Mode .........................................108
6-5 User and Supervisor Address Spaces as Viewed from Supervisor Mode ................111
6-6 User, Supervisor, and Kernel Address Spaces as Viewed from Kernel Mode.........114
6-7 CP0 Registers and the TLB ......................................................................................119
6-8 Format of a TLB Entry .............................................................................................120
6-9 Fields of the PageMask and EntryHi Registers ........................................................121
6-10 Fields of the EntryLo0 and EntryLo1 Registers.......................................................122
User’s Manual  U11761EJ6V0UM 17

List of Figures (2/5)
Fig. No.	Title	Page
6-11 Index Register...........................................................................................................124
6-12 Random Register ......................................................................................................125
6-13 Wired Register Boundary .........................................................................................127
6-14 Wired Register..........................................................................................................127
6-15 Processor Revision Identifier Register Format.........................................................128
6-16 Config Register Format ............................................................................................130
6-17 LLAddr Register Format ..........................................................................................132
6-18 TagLo and TagHi Register (P-cache) Formats.........................................................133
6-19 TagLo and TagHi Register (S-cache) Formats.........................................................133
6-20 TLB Address Translation .........................................................................................136
7-1 Context Register Format ..........................................................................................140
7-2 BadVAddr Register Format......................................................................................141
7-3 Count Register Format .............................................................................................141
7-4 Compare Register Format.........................................................................................142
7-5 Status Register ..........................................................................................................143
7-6 Status Register DS Field...........................................................................................146
7-7 Cause Register Format .............................................................................................149
7-8 EPC Register Format ................................................................................................150
7-9 XContext Register Format........................................................................................151
7-10 ECC Register Format ...............................................................................................152
7-11 CacheErr Register Format ........................................................................................153
7-12 ErrorEPC Register Format .......................................................................................154
7-13 Reset Exception Processing......................................................................................155
7-14 Cache Error Exception Processing ...........................................................................156
7-15 Soft Reset and NMI Exception Processing ..............................................................156
7-16 General Exception Processing ..................................................................................157
7-17 General Exception Handler (HW) ............................................................................175
7-18 General Exception Servicing Guidelines (SW) ........................................................176
7-19 TLB/XTLB Miss Exception Handler (HW).............................................................177
7-20 TLB/XTLB Exception Servicing Guidelines (SW) .................................................178
7-21 Cache Error Exception Handling (HW) and Servicing Guidelines..........................179
7-22 Reset, Soft Reset & NMI Exception Handling.........................................................180
18 User’s Manual  U11761EJ6V0UM

List of Figures (3/5)
Fig. No.	Title	Page
8-1 FPU Functional Block Diagram ...............................................................................182
8-2 FPU Registers ...........................................................................................................184
8-3 Implementation/Revision Register ...........................................................................187
8-4 FP Control/Status Register Bit Assignments............................................................188
8-5 Control/Status Register Cause, Flag, and Enable Fields ..........................................189
8-6 Single-Precision Floating-Point Format ...................................................................192
8-7 Double-Precision Floating-Point Format .................................................................193
8-8 Binary Fixed-Point Format.......................................................................................195
8-9 FPU Instruction Pipeline ..........................................................................................201
9-1 Control/Status Register Exception/Flag/Trap/Enable Bits .......................................205
10-1 Power-on Reset Timing Diagram .............................................................................216
10-2 Cold Reset Timing Diagram.....................................................................................217
10-3 Warm Reset Timing Diagram ..................................................................................218
11-1 SysClock Timing ......................................................................................................223
11-2 Phase-Locked System...............................................................................................224
12-1 Logical Hierarchy of Memory..................................................................................226
12-2 V 5000 Cache Support ............................................................................................227
R
12-3 Primary Instruction Cache Line Format ...................................................................228
12-4 Primary Data Cache Line Format.............................................................................229
12-5 Secondary Cache Line Format .................................................................................230
13-1 System Interface Buses.............................................................................................233
13-2 Secondary Cache Interface .......................................................................................233
14-1 Requests and System Events ....................................................................................235
14-2 Processor Requests to External Agent......................................................................235
14-3 Processor Request Flow Control ..............................................................................236
14-4 External Requests to Processor ................................................................................237
14-5 External Request Arbitration ....................................................................................238
14-6 External Agent Read Response to Processor............................................................240
15-1 State of RdRdy* Signal for Read Requests ..............................................................245
User’s Manual  U11761EJ6V0UM 19

List of Figures (4/5)
Fig. No.	Title	Page
15-2 State of WrRdy* Signal for Write Requests.............................................................246
15-3 System Interface Register-to-Register Operation.....................................................247
15-4 Symbol for Undocumented Cycles...........................................................................250
15-5 Processor Read Request Protocol .............................................................................251
15-6 Processor Non-Coherent Non-Block Write Request Protocol .................................252
15-7 Processor Non-Coherent, Non-Secondary Cache Block Write Request ..................253
15-8 Processor Request Flow Control ..............................................................................254
15-9 Two Processor Write Requests with Second Write Delayed ...................................255
15-10 V 4000-Compatible Back-to-Back Write Cycle Timing.........................................256
R
15-11 Write Reissue ...........................................................................................................257
15-12 Pipelined Writes .......................................................................................................258
15-13 Arbitration Protocol for External Requests ..............................................................260
15-14 System Interface Release External Null Request .....................................................261
15-15 External Write Request, with System Interface Initially a Bus Master....................262
15-16 Processor Word Read Request, Followed by a Word Read Response.....................263
15-17 Block Read Response, System Interface already in Slave State ..............................264
15-18 Read Response, Reduced Data Rate, System Interface in Slave State.....................265
15-19 System Interface Command Syntax Bit Definition ..................................................270
15-20 Read Request SysCmd Bus Bit Definition ...............................................................270
15-21 Write Request SysCmd Bus Bit Definition ..............................................................271
15-22 Null Request SysCmd Bus Bit Definition ................................................................272
15-23 Data Identifier SysCmd Bus Bit Definition..............................................................273
16-1 Processor Requests to Secondary Cache and External Agent ..................................284
16-2 Secondary Cache Invalidate and Clear.....................................................................284
16-3 Secondary Cache Tag Probe.....................................................................................285
16-4 Secondary Cache Write Through .............................................................................285
16-5 Secondary Cache Read Hit .......................................................................................286
16-6 Secondary Cache Read Miss ....................................................................................287
16-7 Secondary Cache Read Hit .......................................................................................289
16-8 Secondary Cache Read Miss ....................................................................................291
16-9 Secondary Cache Read Miss with Bus Error ...........................................................292
16-10 Secondary Cache Write Operation ...........................................................................293
20 User’s Manual  U11761EJ6V0UM

List of Figures (5/5)
Fig. No.	Title	Page
16-11 Secondary Cache Line Invalidate .............................................................................294
16-12 Secondary Cache Probe (Tag RAM Read)...............................................................295
16-13 Secondary Cache Flash Clear ...................................................................................296
17-1 Interrupt Register Bits and Enables ..........................................................................299
17-2 V 5000 Interrupt Signals .........................................................................................300
R
17-3 V 5000 Nonmaskable Interrupt Signal ....................................................................301
R
17-4 Masking of the V 5000 Interrupt .............................................................................302
R
18-1 Standby Mode Operation..........................................................................................304
19-1 PLL Filter Circuit (1)................................................................................................305
19-2 PLL Filter Circuit (2)................................................................................................306
B-1 Retrieving a Data Block in Sequential Order ...........................................................314
B-2 Retrieving a Data in a Subblock Order.....................................................................315
User’s Manual  U11761EJ6V0UM 21

List of  Tables (1/3)
Table No.	Title	Page
1-1 System Control Coprocessor (CP0) Register Definitions ..........................................39
2-1 System Interface Signals ............................................................................................45
2-2 Clock Interface Signals...............................................................................................46
2-3 Secondary Cache Interface Signals ............................................................................47
2-4 Interrupt Interface Signals ..........................................................................................48
2-5 Initialization Interface Signals....................................................................................49
2-6 Power Supply .............................................................................................................50
3-1 Byte Access within a Doubleword .............................................................................61
3-2 Multiply/Divide Instruction Latency and Repeat Rates .............................................63
3-3 MIPS IV Instruction Set Additions and Extensions ...................................................65
3-4 V 5000 COP0 Instrucitons ........................................................................................66
R
3-5 Floating Point Operations...........................................................................................71
4-1 Relationship of Pipeline Stage to Interlock Condition ...............................................92
4-2 Pipeline Exceptions ....................................................................................................93
4-3 Pipeline Interlocks ......................................................................................................93
6-1 Processor Modes  .....................................................................................................103
6-2 32-bit and 64-bit User Address Space Segments .....................................................109
6-3 Supervisor Mode Addressing ...................................................................................111
6-4 Kernel Mode Addressing..........................................................................................115
6-5 Cacheability and Coherency Attributes....................................................................117
6-6 TLB Page Coherency (C) Bit Values .......................................................................123
6-7 Index Register Field Descriptions ............................................................................124
6-8 Random Register Field Descriptions........................................................................125
6-9 Mask Field Values for Page Sizes ............................................................................126
6-10 Wired Register Field Descriptions ...........................................................................127
6-11 PRId Register Fields.................................................................................................128
6-12 Config Register Fields ..............................................................................................130
6-13 Cache Tag Register Fields........................................................................................134
6-14 TLB Instructions.......................................................................................................137
7-1 CP0 Exception Processing Registers........................................................................139
7-2 Context Register Fields ............................................................................................140
22 User’s Manual   U11761EJ6V0UM

List of  Tables (2/3)
Table No.	Title	Page
7-3 Status Register Fields ...............................................................................................144
7-4 Status Register Diagnostic Status Bits .....................................................................146
7-5 Cause Register Fields ...............................................................................................148
7-6 Cause Register ExcCode Field .................................................................................149
7-7 XContext Register Fields .........................................................................................151
7-8 ECC Register Fields .................................................................................................152
7-9 CacheErr Register Fields ..........................................................................................153
7-10 Exception Vector Base Addresses............................................................................157
7-11 Exception Vector Offsets .........................................................................................158
7-12 TLB Refill Vectors ...................................................................................................159
7-13 Exception Priority Order ..........................................................................................160
8-1 Floating-Point Control Register Assignments..........................................................186
8-2 FCR0 Fields..............................................................................................................187
8-3 Control/Status Register Fields ..................................................................................188
8-4 Flush Values of Denormalized Number Results ......................................................190
8-5 Rounding Mode Bit Decoding .................................................................................192
8-6 Calculating Values in Single and Double-Precision Formats ..................................193
8-7 Floating-Point Format Parameter Values .................................................................194
8-8 Minimum and Maximum Floating-Point Values .....................................................194
8-9 Binary Fixed-Point Format Fields ............................................................................195
8-10 FPU Instruction Summary: Load, Move and Store Instructions ..............................196
8-11 FPU Instruction Summary: Conversion Instructions ...............................................196
8-12 FPU Instruction Summary: Computational Instructions ..........................................197
8-13 FPU Instruction Summary: Compare and Branch Instructions ................................197
8-14 Mnemonics and Definitions of Compare Instruction Conditions.............................200
8-15 Floating-Point Operation Latencies..........................................................................202
9-1 Default FPU Exception Actions ...............................................................................207
9-2 FPU Exception-Causing Conditions ........................................................................208
10-1 Boot Mode Settings ..................................................................................................220
14-1 Load Miss to Primary Caches...................................................................................241
14-2 Store Miss to Primary and Secondary Caches..........................................................242
User’s Manual   U11761EJ6V0UM 23

List of  Tables (3/3)
Table No.	Title	Page
15-1 System Interface Requests........................................................................................249
15-2 Transmit Data Rates and Patterns.............................................................................266
15-3 Release Latency for External Requests ....................................................................269
15-4 Encoding of SysCmd(7:5) for System Interface Commands ...................................270
15-5 Encoding of SysCmd(4:3) for Read Requests..........................................................271
15-6 Encoding of SysCmd(1:0) for Block Read Request.................................................271
15-7 Read Request Data Size Encoding of SysCmd(2:0).................................................271
15-8 Write Request Encoding of SysCmd(4:3) ................................................................272
15-9 Block Write Request Encoding of SysCmd(2:0)......................................................272
15-10 Write Request Data Size Encoding of SysCmd(2:0) ...............................................272
15-11 External Null Request Encoding of SysCmd(4:3)....................................................273
15-12 Processor Data Identifier Encoding of SysCmd(7:3) ...............................................274
15-13 External Data Identifier Encoding of SysCmd(7:3) .................................................275
15-14 Partial Word Transfer Byte Lane Usage ..................................................................277
15-15 Error Checking Operation for Internal Transactions................................................281
15-16 Error Checking Operation for External Transactions...............................................282
A-1 Primary Data Cache Operations ...............................................................................312
A-2 Primary Instruction Cache Operations .....................................................................313
A-3 Secondary Cache Operations....................................................................................313
B-1 Subblock Ordering Sequence: Address 10 .............................................................316
2
B-2 Subblock Ordering Sequence: Address 11 .............................................................316
2
B-3 Subblock Ordering Sequence: Address 01 .............................................................316
2
C-1 Output Driver Strength .............................................................................................317
24 User’s Manual   U11761EJ6V0UM

Chapter 1  Introduction
The V 5000 and V 5000A are members of the NEC V -Series RISC (Reduced
R	R	R
Instruction Set Computer) microprocessors and are high-performance 64-/32-bit
microprocessors employing the RISC architecture developed by MIPS™.
Their instructions are upward-compatible with those of the V 3000 Series™ and
R
V 4000 Series and are completely compatible with those of the V 10000. Therefore,
R R
existing applications can be used with the V 5000 and V 5000A.
R R
User’s Manual   U11761EJ6V0UM 25

Chapter 1  Introduction
1.1 Processor Characteristics
The V 5000 and V 5000A have the following fetaures:
R R
• Maximum internal operating frequency:
150MHz (μPD30500-150) /180MHz (μPD30500-180) /
200MHz (μPD30500-200) /250MHz (μPD30500A-250)/
266MHz (μPD30500A-266)
• 64-bit architecture supporting 64-bit data processing
• Dual-issue instruction mechanism
• High-speed translation lookaside buffer (TLB) supporting virtual addresses (of
48 double entires)
| • | Address space: Virtual 40 bits (64-bit mode) 31 bits (32-bit mode) • Supports single-precision and double-precision floating-point operations | Physical | 36 bits |
| --- | --- | --- | --- |
| • | On-chip primary cache: Data 32KB • Up to 2MB optional Secondary cache • Employs writeback system -> store operation via system bus decreased Note | Instruction | 32KB |
| • | Up to 100 MHz external bus with frequency of /2, /2.5 of internal operation • Write buffer • Upward-compatible with V 3000 Series and V 4000 Series and completely R R compatible with V 10000 | , /3, /4, /5, /6, /7, /8 |  |
R
•	Supply voltage:	Vcc=3.3V±5% (V 5000)
R
Core : Vcc=2.4V±0.1V (V 5000A, 100 to 235MHz),
R
Vcc=2.5V+5% (V 5000A, 236 to 250MHz),
R
Vcc=2.6V±0.1V(V5000A, 251 to 266MHz)
R
I/O :   VccIO=3.3V±5%(V 5000A)
R
Note Selectable only when external operating frequency=100MHz
26 User’s Manual   U11761EJ6V0UM

Chapter 1  Introduction
1.2 Ordering Information
Maximum operating
| Part Number | Package | frequency (MHz) |
| --- | --- | --- |
| μPD30500RJ-150 | 223-pin ceramic PGA (48×48) | 150 |
| μPD30500RJ-180 | 223-pin ceramic PGA (48×48) | 180 |
| μPD30500RJ-200 | 223-pin ceramic PGA (48×48) | 200 |
| μPD30500S2-150 | 272-pin plastic BGA (cavity down advanced type) (29×29) | 150 |
| μPD30500S2-180 | 272-pin plastic BGA (cavity down advanced type) (29×29) | 180 |
| μPD30500S2-200 | 272-pin plastic BGA (cavity down advanced type) (29×29) | 200 |
| μPD30500AS2-250 | 272-pin plastic BGA (cavity down advanced type) (29×29) | 250 |
| μPD30500AS2-266 | 272-pin plastic BGA (cavity down advanced type) (29×29) 1.3 64-Bit Architecture The V 5000 is a 64-bit high-performance microprocessor. It can also execute 32-bit | 266 |
R
applications.
1.4	V	5000 Processor
R
Figure 1-1 shows the internal block diagram of the V 5000.
R
The V 5000 is equipped with a full-associative high-speed translation lookaside
R
buffer (TLB) that has 48 entries with two pages corresponding to each entry; data
cache and instruction cache; external secondary cache interface, in addition to dual-
issue mechanism ALU.
User’s Manual   U11761EJ6V0UM 27

Chapter 1  Introduction
Data/Address Control SysClock
Clock Generator
System
Interface
Instruction Cache Data Cache
CP0
TLB
Integer Operating Floating Point
Instruction Address
Unit Unit
Pipeline Control
Figure  1-1   V5000 Processor Internal Block Diagram
R
28 User’s Manual   U11761EJ6V0UM

Chapter 1  Introduction
1.4.1 Internal Block Configuration
System Interfaceallows the processor to access external resources such as memories
and secondary cache. It contains a 64-bit multiplexed address/data bus, with per-byte
parity, interrupt request signals, and various control signals included for secondary
cache.
Clock Generatorgenerates a pipeline clock (PClock) based on an externally input
clock (SysClock). The ratio of frequency of SysClock to that of PClock can be set to
Note
1:2, 1:2.5 , 1:3, 1:4, 1:5, 1:6, 1:7, or 1:8.
Note V 5000A only (Selectable only when SysClock=100MHz)
R
Instruction Cacheis 2-way set associative, virtually-indexed, and physically-
tagged. The capacity is 32KB.
Integer Operating Unithas the hardware resources to execute integer instruction. It
has a 64-bit register file and 64-bit integer datapath. It is provided with a dedicated
multiplier in order to process multiply instruction at a high speed.
Floating Point Unithas the hardware resources to execute floating point instruction.
It has a 64-bit register file, 64-bit mantissa datapath, and 12-bit exponent datapath. It
is provided with a dedicated multiplier and a dedicated div./sqrt. in order to process
multiply/multiplyadd and div./sqrt. instructions at a high speed.
Coprocessor 0 (CP0)has the memory management unit (MMU) and handles
exception processing. The MMU handles address translation and checks memory
accesses that occur between different memory segments (user, supervisor, or kernel).
The translation lookaside buffer (TLB) is used to translate virtual to physical
addresses.
Data Cacheis a 2-way set associative, virtually indexed and physically-tagged
writeback cache. The capacity is 32KB.
Instruction Addresscalculates the effective address of the next instruction to be
fetched. It contains the incrementer for the Program Counter (PC), the branch address
adder, and the conditional branch selector.
Pipeline Controlensures the instruction pipeline operates properly causing either of
pipeline stall or exception.
User’s Manual   U11761EJ6V0UM 29

Chapter 1  Introduction
1.4.2 CPU Registers
The processor provides the following registers:
• 32 64-bit general purpose registers,GPRs
• 32 64-bit floating-point purpose registers,FPRs
In addition, the processor provides the following special registers:
• 64-bit Program Counter, thePCregister
• 64-bitHIregister, containing the integer multiply and divide high-order
doubleword result
• 64-bitLOregister, containing the integer multiply and divide low-order
doubleword result
• 1-bit Load/LinkLLBitregister
• 32-bit floating-pointImplementation/Revisionregister, FCR0
• 32-bit floating-pointControl/Statusregister, FCR31
Two of the CPU general purpose registers have assigned functions:
• r0is hardwired to a value of zero, and can be used as the target register
for any instruction whose result is to be discarded.r0can also be used as
a source when a zero value is needed.
• r31is the link register used by JAL and JALR instructions.  It can be used
by other instructions.  Make sure that other data used in calculations does
not overlap with the register used by the JAL/JALR instruction.
Further more, the processor contains registers in the system control processor (CP0)
which perform the exception processing and address management.  CPU registers can
operate as either 32-bit or 64-bit registers, depending on the V 5000 processor mode
R
of operation.
Figure 1-2 shows the V 5000 processor registers.
R
30 User’s Manual   U11761EJ6V0UM

Chapter 1  Introduction
General Purpose Registers
63 0
Multiply and Divide Registers
r0 = 0
63 0
r1
HI
r2
63 0
•
LO
•
•
•
Program Counter
r29	63	0
PC
r30
r31 = Link address
Load/Link Register
0
LLbit
Floating-Point Registers
63 0
r0
r1
r2
Floating-Point Control Registers
•
31 0
•
r0 = Implementation/Revision
•
•
31 0
r31 = Control/Status
r29
r30
r31
Figure  1-2   V5000 Processor Registers
R
The V 5000 processor has noProgram Status Word(PSW) register as such; this is
R
covered by theStatusandCauseregisters incorporated within the System Control
Coprocessor (CP0).  CP0 registers are described later in this chapter.
User’s Manual   U11761EJ6V0UM 31

Chapter 1  Introduction
1.4.3 CPU Instruction Set Overview
Each CPU instruction is 32 bits long.  As shown in Figure 1-3, there are three
instruction formats:
• immediate (I-type)
• jump (J-type)
• register (R-type)
| 31 | 2625 | 2120 | 1615 | 0 |
| --- | --- | --- | --- | --- |
| I-Type (Immediate) | op | rs | rt | immediate |
| 31 | 2625 | 0 |  |  |
| J-Type (Jump) | op | target |  |  |
| 31 | 2625 | 2120 | 1615 | 11  10 65 0 |
| R-Type (Register) | op | rs | rt | rd sa funct Figure  1-3   CPU Instruction Formats The instruction set can be further divided into the following groupings: • Load and Storeinstructions move data between memory and general purpose registers.  They are all immediate (I-type) instructions, since the only addressing mode supported is base register plus 16-bit, signed immediate offset. • Computationalinstructions perform arithmetic, logical, shift, multiply, and divide operations on values in registers.  They include register (R- type, in which both the operands and the result are stored in registers) and immediate (I-type, in which one operand is a 16-bit signed immediate value) formats. • Jump and Branchinstructions change the control flow of a program. Jumps are always made to an address formed by combining a 26-bit target address with the high-order bits of the Program Counter (J-type format) or register address (R-type format).  Branch instructions are performed to the 16-bit offset address relative to the program counter (I-type).  Jump And Link instructions save their return address in register 31. • Coprocessorinstructions (CPz) perform operations in the coprocessors. Coprocessor load and store instructions are I-type.  As opposed to CP0 instructions, CPz instructions are not specific to any coprocessor.  (Refer toChapter 8 Floating Point Unit.) 32 User’s Manual   U11761EJ6V0UM |

Chapter 1  Introduction
• Coprocessor 0(system coprocessor, CP0) instructions perform operations
on CP0 registers to control the memory-management and exception-
handling facilities of the processor.
• Specialinstructions perform system call exception and breakpoint
exception operations, or cause a branch to the general exception-handling
vector based upon the result of a comparison.  These instructions occur in
both R-type (both the operands and the result are registers) and I-type
(one operand is a 16-bit immediate value) formats.
For each instruction, refer toChapter 3 CPU Instruction Set Summaryand
V 5000, V 10000 User’s Manual Instruction.
R R
User’s Manual   U11761EJ6V0UM 33

Chapter 1  Introduction
1.4.4 Data Formats and Addressing
The V 5000 processor uses four data formats: a 64-bit doubleword, a 32-bit word, a
R
16-bit halfword, and an 8-bit byte.  Byte ordering within all of the larger data
formats—halfword, word, doubleword—can be configured in either big-endian or
little-endian.  When the V 5000 processor is configured as a big-endian system, byte
R
0 is the most-significant (leftmost) byte, thereby providing compatibility with MC
68000™ and IBM 370™ conventions.  Figure 1-4 shows this configuration.
Higher Word
| Address | Address | 31 | 24 23 | 16 15 | 8 7 | 0 |
| --- | --- | --- | --- | --- | --- | --- |
| 12 | 12 | 13 | 14 | 15 |  |  |
| 8 | 8910 4 4567 Lower 0 0123 Address Figure  1-4   Big-Endian Byte Ordering Remarks   1. The most-significant byte is the lowest address. 2. A word is addressed by the address of the most-significant byte. When configured as alittle-endian system, byte 0 is always the least-significant (rightmost) byte, which is compatible with iAPX™ x86 and DEC VAX™ conventions.  Figure 1-5 shows this configuration. Unless otherwise specified, the little endian is used throughout this manual. Higher Word | 11 |  |  |  |  |
| Address | Address | 31 | 24 23 | 16 15 | 8 7 | 0 |
| 12 | 15 | 14 | 13 | 12 |  |  |
| 8 | 11 | 10 | 9 | 8 |  |  |
| 4 | 765 Lower 0 3210 Address Figure  1-5   Little-Endian Byte Ordering Remarks   1. The least-significant byte is the lowest address. 2. A word is addressed by the address of the least-significant byte. 34 User’s Manual   U11761EJ6V0UM | 4 |  |  |  |  |

Chapter 1  Introduction
| Word | Halfword Higher Doubleword Address Address | Byte |
| --- | --- | --- |
| 63 | 3231 | 1615 870 |
| 16 | 16 | 17 18 19 20 21 22 23 |
| 8 | 891011 | 12 13 14 15 |
| Lower | 0 | 0123 4567 Address Figure  1-6   Big-Endian Data in a Doubleword Remarks   1. The most-significant byte is the lowest address. 2. A word is addressed by the address of the most-significant byte. |
| Word | Halfword Higher Doubleword Address Address | Byte |
| 63 | 3231 | 1615 870 |
| 16 | 23 | 22 21 20 19 18 17 16 |
| 8 | 15 | 14 13 12 11 10 9 8 |
| Lower | 0 | 765 4 3 2 1 0 Address Figure  1-7   Little-Endian Data in a Doubleword Remarks   1. The least-significant byte is the lowest address. 2. A word is addressed by the address of the least-significant byte. User’s Manual   U11761EJ6V0UM 35 |

Chapter 1  Introduction
The CPU uses byte addressing for halfword, word, and doubleword accesses with the
following alignment constraints:
• Halfword accesses must be aligned on an even byte boundary (0, 2, 4...).
• Word accesses must be aligned on a byte boundary divisible by four (0, 4,
8...).
• Doubleword accesses must be aligned on a byte boundary divisible by
eight (0, 8, 16...).
The following special instructions load and store words that are not aligned on 4-byte
(word) or 8-word (doubleword) boundaries:
| LWL | LWR | SWL | SWR |
| --- | --- | --- | --- |
| LDL | LDR These instructions are always used in pairs to access data not aligned at an boundary. To access data not aligned at a boundary, additional 1P cycle is necessary as compared when accessing data aligned at a boundary. Figure 1-8 illustrates how a word misaligned and having byte address 3 is accessed in big and little endian. Higher Address | SDL | SDR |
| 31 | 24  23 | 16 15 | 8   7 0 4 56 Big-Endian |
3
Lower
Address
Higher
Address
31	24  23	16 15	8   7	0
6	5	4
Little-Endian
3
Lower
Address
Figure  1-8   Misaligned Word Addressing
36 User’s Manual   U11761EJ6V0UM

Chapter 1  Introduction
1.4.5 System Control Coprocessor (CP0)
The CPU can operate with up to four coprocessors (CP0 through CP3) closely coupled.
Coprocessors 1 and 2 are reserved for future use. Coprocessor 3 is assigned for MIPS
IV instruction set. Coprocessor 0 (CP0) is an internal system control coprocessor and
supports the virtual memory system and exception processing. The virtual memory
system is executed by the on-chip TLB and CP0 register.
CP0 converts virtual addresses into physical addresses, selects an operating mode
(Kernel, supervisor, or user mode), and control exceptions. It also controls the cache
subsystem to analyze causes and return execution from error processing. The CP0
register of the V 5000 is the same as that of the V 4000.
R R
Figure 1-9 shows the CP0 register. Table 1-1 briefly explains each register. For the
details of the registers related to the virtual memory system, refer toChapter 6
Memory Management Unit, and for the details of the registers used for exception
processing, refer toChapter 7 CPU Exception Processing.
User’s Manual   U11761EJ6V0UM 37

Chapter 1  Introduction
| Register Name | Reg. # | Register Name | Reg. # |
| --- | --- | --- | --- |
| Index* | 0 | Config* | 16 |
| Random* | 1 | LLAddr* | 17 |
| EntryLo0* | 2 | RFU | 18 |
| EntryLo1* | 3 | RFU | 19 |
| Context** | 4 | XContext** | 20 |
| PageMask* | 5 | RFU | 21 |
| Wired* | 6 | RFU | 22 |
| RFU | 7 | RFU | 23 |
| BadVAddr** | 8 | RFU | 24 |
| Count** | 9 | RFU | 25 |
| EntryHi* | 10 | Parity Error** | 26 |
| Compare** | 11 | Cache Error** | 27 |
| Status** | 12 | TagLo* | 28 |
| Cause** | 13 | TagHi* | 29 |
| EPC** | 14 | ErrorEPC** | 30 |
| PRId* | 15 | RFU * For Memory Management ** For Exception Processing RFU  Reserved for Future Use Figure  1-9   CP0 Registers 38 User’s Manual   U11761EJ6V0UM | 31 |

Chapter 1  Introduction
Table 1-1    System Control Coprocessor (CP0) Register Definitions
| Number | Register | Description |
| --- | --- | --- |
| 0 | Index | Programmable pointer into TLB array |
| 1 | Random | Pseudorandom pointer into TLB array(read only) |
| 2 | EntryLo0 | Low half of TLB entry for even virtual address (VPN) |
| 3 | EntryLo1 | Low half of TLB entry for odd virtual address (VPN) |
| 4 | Context | Pointer to kernel virtual page table entry (PTE) in 32-bit mode |
| 5 | PageMask | Page size specification |
| 6 | Wired | Number of wired TLB entries |
| 7 | — | Reserved for future use |
| 8 | BadVAddr | Display of virtual address that occurred an error last |
| 9 | Count | Timer Count |
| 10 | EntryHi | High half of TLB entry (including ASID) |
| 11 | Compare | Timer Compare Value |
| 12 | Status | Operation status setting |
| 13 | Cause | Display of cause of last exception |
| 14 | EPC | Exception Program Counter |
| 15 | PRId | Processor Revision Identifier |
| 16 | Config | Memory system mode setting |
| 17 | LLAddr | Load Linked instruction address display |
| 18, 19 | — | Reserved for future use |
| 20 | XContext | Pointer to Kernel virtual PTE table in 64-bit mode |
| 21–25 | — | Reserved for future use |
| 26 | Parity Error | Cache parity bits |
| 27 | Cache Error | Cache Error and Status register |
| 28 | TagLo | Cache Tag register low |
| 29 | TagHi | Cache Tag register high |
| 30 | ErrorEPC | Error Exception Program Counter |
| 31 | — | Reserved for future use User’s Manual   U11761EJ6V0UM 39 |

Chapter 1  Introduction
1.4.6 Floating-Point Unit (FPU)
The floating-point unit (FPU) performs arithmetic operations on floating-point values.
The FPU, with associated system software, fully conforms to the requirements of
ANSI/IEEE Standard 754–1985,IEEE Standard for Binary Floating-Point
Arithmetic.
The FPU includes:
• Full 64-bit Operation. The FPU can contain either 16 64-bit registers to
hold single-precision or double-precision values.  Another sixteen
floating-point registers can be used by setting the FR bit of theStatus
register to 1.  Moreover, a 32-bitControl/Statusregister is provided,
conforming to the IEEE exception processing standard.
• Load and Store Instruction Set.  Like the CPU, the FPU uses a load-
and store-based instruction set.  Floating-point operations are started in a
single cycle.
1.4.7 Internal Cache
The V 5000 has an instruction cache and a data cache to enhance the efficiency of
R
pipelining.  Each cache has a data width of 64 bits and can be accessed in 1 clock.  The
instruction cache and data cache can be accessed in parallel.  Both of the instruction
cache and data cache have a capacity of 32KB.
For the details of the cache, refer toChapter 12 Cache Organization and
Operation.
40 User’s Manual   U11761EJ6V0UM

Chapter 1  Introduction
1.5 Memory Management System (MMU)
The V 5000 processor has a 36-bit physical addressing range of 64 GB.  However,
R
since it is rare for systems to implement a physical memory space this large, the CPU
provides a logical expansion of memory space to the programmer by translating
addresses into the large virtual address space.  The V 5000 processor supports the
R
following two addressing modes:
• 32-bit mode, in which the virtual address space is divided into 2 GB per
user process and 2 GB for the kernel.
• 64-bit mode, in which the virtual address is expanded to
40
1 TB (2 bytes) of user virtual address space.
A detailed description of these address spaces is given inChapter 6 Memory
Management Unit.
1.5.1 Translation Lookaside Buffer (TLB)
Virtual memory mapping is assisted by a translation lookaside buffer, which holds
virtual-to-physical address translations.  This fully-associative, on-chip TLB contains
48 entries, each of which maps a pair of variable-sized pages of either 4 KB or 16 MB.
Joint TLB (JTLB)
The TLB can hold both instruction and data addresses, and is thus also referred to as a
joint TLB (JTLB).
An address translation value is tagged with the most-significant bits of its virtual
address (the number of these bits depends upon the size of the page) and a per-process
identifier.  If there is no matching entry in the TLB, an exception occurs and software
writes the entry contents to the on-chip TLB from a page table in memory.  The JTLB
entry to be rewritten is selected by a value in either theRandomorIndexregister.
User’s Manual   U11761EJ6V0UM 41

Chapter 1  Introduction
1.5.2 Operating Modes
The V 5000 processor has three operating modes:
R
• Usermode
• Supervisor mode
• Kernelmode
The manner in which memory addresses are translated ormappeddepends on the
operating mode of the CPU; this is described inChapter 6 Memory Management
Unit.
1.6 Instruction Pipeline
The V 5000 incorporates a simple dual-issue mechanism which allows a floating-
R
point ALU instruction to be issued simultaneously with any other instruction type and
has a five-stage instruction pipeline. For details, refer toChapter 4 V 5000
R
Processor PipelineandChapter 5 Superscalar Issue Mechanism.
42 User’s Manual   U11761EJ6V0UM

Chapter 2  V 5000 Processor Signal Descriptions
R
This chapter describes the signals used by and in conjunction with the V 5000
R
processor.  The signals include the System interface, the Clock interface, the
Secondary Cache interface, the Interrupt interface, and the Initialization interface.
Signals are listed in bold, and low active signals have a trailing asterisk—for instance,
the low-active Read Ready signal isRdRdy*.  The arrows used in each signal for each
signals  tells if the signal is an input (the processor receives it), an output (the processor
sends it out), or bidirectional.
Figure 2-1 illustrates the functional groupings of the processor signals.
User’s Manual   U11761EJ6V0UM 43

Chapter 2  V5000 Processor Signal Descriptions
R
64 16
SysAD[63:0] ScLine[15:0]
8
2
SysADC[7:0] ScWord[1:0)]
9
SysCmd[8:0]
ScCWE*[1:0]
SysCmdP ScDCE*[1:0]
ValidIn* ScDOE*
ValidOut* ScTCE*
ExtRqst*
ScTDE*
Release*
ScTOE*
System Interface
RdRdy*
ScCLR*
Secondary Cache Interface
WrRdy* ScValid
ScMatch
V 5000
R
Logic 6
SysClock
Int*[5:0]
Symbol
VccP
NMI*
InterruptInterface
VssP
Clock Interface
ModeClock
ModeIn
BigEndian
VccOk
ColdReset* Interface
Initialization
Reset*
Figure  2-1   V5000 Processor Signals
R
2.1 System Interface Signals
System interface signals provide the connection between the V 5000 processor and
R
the other components in the system. Table 2-1 lists the system interface signals.
44 User’s Manual   U11761EJ6V0UM

Chapter 2  V5000 Processor Signal Descriptions
R
Table 2-1   System Interface Signals
| Name | Definition | Direction | Description An external agent assertsExtRqst* to request use of the System interface. The |
| --- | --- | --- | --- |
| ExtRqst* | External request processor grants the request by asserting Release*. In response to the assertion ofExtRqst*, the processor assertsRelease*, signalling to the | Input |  |
| Release* | Release interface requesting device that the System interface is available. The external agent assertsRdRdy* to indicate that it can accept processor read | Output |  |
| RdRdy* | Read ready requests in either secondary or no-secondary cache mode. A 64-bit address and data bus for System address/ Input/ SysAD(63:0) communication between the processor, the data bus Output secondary cache, and an external agent. | Input |  |
| System address/ | Input/ | An 8-bit bus containing parity for theSysAD SysADC(7:0) |  |
| data check bus | Output | bus.SysADCis valid on data cycles only. A 9-bit bus for command and data identifier System command/ Input/ SysCmd(8:0) transmission between the processor and an data identifier Output external agent. System command/ Always zero when driven by the processor. Input/ |  |
| SysCmdP | data identifier bus | Never checked by the processor.  This signal Output parity is defined to maintain V 4000 compatiblility. |  |
R
The external agent assertsValidIn* when it is
driving a valid address or data on theSysAD
| ValidIn* | Valid input bus and a valid command or data identifier on theSysCmdbus. The processor assertsValidOut* when it is driving a valid address or data on theSysAD | Input |
| --- | --- | --- |
| ValidOut* | Valid output bus and a valid command or data identifier on theSysCmdbus to the external agent. The external agent assertsWrRdy* when it | Output |
| WrRdy* | Write ready can accept a processor write request. User’s Manual   U11761EJ6V0UM 45 | Input |

Chapter 2  V5000 Processor Signal Descriptions
R
2.2 Clock Interface Signals
The Clock interface signals make up the interface for clocking.  Table 2-2 lists the
Clock interface signals.
Table 2-2   Clock Interface Signals
| Name | Definition | Direction | Description System clock input that establishes |
| --- | --- | --- | --- |
| SysClock | System Clock | Input | the system interface operating frequency and phase. Quiet Vcc for the internal phase |
| VccP | Quiet Vcc for PLL locked loop. Quiet Vss for the internal phase | Input |  |
| VssP | Quiet Vss for PLL locked loop. 2.3 Secondary Cache Interface Signals Secondary Cache interface signals constitute the interface between the V 5000 | Input |  |
R
processor and secondary cache. Table 2-3 lists the Secondary Cache interface signals
in alphabetical order.
46 User’s Manual   U11761EJ6V0UM

Chapter 2  V5000 Processor Signal Descriptions
R
Table 2-3   Secondary Cache Interface Signals
| Name | Definition | Direction | Description Secondary Cache Clears all valid bits in those Tag ScCLR* Output Flash Clear RAMs which support this function. Asserted during writes to the Secondary Cache secondary cache. Two signals are ScCWE*(1:0) Output Write Enable provided to minimize loading from the cache RAMs. Chip Enable for Secondary Cache Data RAM Chip Data RAM. Two signals are provided ScDCE*(1:0) Output Enable to minimize loading from the cache RAMs. Data RAM Output Asserted by the external agent to ScDOE* Input Enable enable data onto theSysADbus Secondary Cache |
| --- | --- | --- | --- |
| ScLine (15:0) | Output | Cache line index for secondary cache Line Index Secondary cache Asserted by Tag RAM on Secondary ScMatch Input Tag Match cache tag match Secondary cache Chip enable for secondary cache tag |  |
| ScTCE* | Tag RAM Chip RAM. Enable Secondary cache Data Enable for Secondary Cache Tag | Output |  |
| ScTDE* | Tag RAM Data RAM. Enable Secondary cache Tag RAM Output enable for | Output |  |
| ScTOE* | Tag RAM Output Secondary Cache Tag RAM Enable Secondary cache Determines the double-word within ScWord (1:0) Input/Output Word Index the indexed secondary cache Index Always driven by the CPU except Secondary cache | Output |  |
| ScValid | Input/Output | during a CACHE Probe operation, Valid where it is driven by the Tag RAM. User’s Manual   U11761EJ6V0UM 47 |  |

Chapter 2  V5000 Processor Signal Descriptions
R
2.4 Interrupt Interface Signals
The Interrupt interface signals make up the interface used by external agents to
interrupt the V 5000 processor.Table 2-4 lists the Interrupt interface signals.
R
Table 2-4   Interrupt Interface Signals
| Name | Definition | Direction | Description General processor interrupts, bit-wise ORed with |
| --- | --- | --- | --- |
| Int*(5:0) | Interrupt bits 5:0 of the interrupt register. Nonmaskable Nonmaskable interrupt, ORed with bit 6 of the NMI* Input interrupt interrupt register. 2.5 Initialization Interface Signals The Initialization interface signals make up the interface by which an external agent initializes the processor operating parameters.  Table 2-5 lists the Initialization interface signals. 48 User’s Manual   U11761EJ6V0UM | Input |  |

Chapter 2  V5000 Processor Signal Descriptions
R
Table 2-5   Initialization Interface Signals
| Name | Definition | Direction | Description Allows the system to change the processor addressing mode without rewriting the mode ROM. If endianness is to be |
| --- | --- | --- | --- |
| BigEndian | Endian Mode Select | Input | specified via theBigEndianpin, program mode ROM bit 8 to zero. If endianness is to be specified by the mode ROM, ground theBigEndianpin. This signal must be asserted for a power on |
| ColdReset* | Cold reset | Input | reset or a cold reset.ColdReset* must be deasserted synchronously withSysClock. Serial boot-mode data clock output; runs at |
| ModeClock | Boot mode clock | Output | the system clock frequency divided by 256: (SysClock/256). |
| ModeIn | Boot mode data in | Input | Serial boot-mode data input. This signal must be asserted for any reset sequence.  It can be asserted synchronously or asynchronously for a |
| Reset* | Reset cold reset, or synchronously to initiate a warm reset.Reset* must be deasserted synchronously withSysClock. When asserted, this signal indicates to the processor that the +3.3 volt power supply Note Vcc and VccIO has been above 3.135 volts for more than VccOk Input are valid 100 milliseconds and will remain stable. The assertion ofVccOkinitiates the initialization sequence. Note VccIO is only for V 5000A. | Input |  |
R
User’s Manual   U11761EJ6V0UM 49

Chapter 2  V5000 Processor Signal Descriptions
R
2.6 Power Supply
Table 2-6   Power Supply
| Name | Definition | Direction | Description Vss for Processor Ground for the internal core logic and |
| --- | --- | --- | --- |
| Vss | Core and Processor processor I/O interface. I/O V 5000 : Power | – |  |
R
Positive power supply pin (3.3V)
supply
Vcc –
V 5000A : Power supply pin for core
R
Power supply for (100 to 235MHz: 2.4V, 236 to 250MHz: 2.5V,
Processor Core 251 to 266MHz: 2.6V)
Note Power supply for
VccIO	–	Power supply pin for I/O (3.3V)
Processor I/O
Note V 5000A only
R
Caution     Two kind of power sources are provided with the V 5000A. The sequence of
R
the power application order is not fixed. However, make sure that either of
the power supplies does not remain turned on for 1 second or more while the
other remains off.
50 User’s Manual   U11761EJ6V0UM

Chapter 2  V5000 Processor Signal Descriptions
R
2.7 Pin Configuration
• 223-pin ceramic PGA (48×48)
μPD30500RJ-150
μPD30500RJ-180
μPD30500RJ-200
Bottom View Top View
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
VUTRPNMLKJHGFEDCBA ABCDEFGHJKLMNPRTUV
Index mark
User’s Manual   U11761EJ6V0UM 51

Chapter 2  V5000 Processor Signal Descriptions
R
| Location .......Name | Location .......Name | Location ...... Name | Location....... Name | Location....... Name | Location ...... Name |
| --- | --- | --- | --- | --- | --- |
| A2 ...................Vcc | C5 ...... SysADC[6] | E18 ................. Vcc | K17 ............... VssP | R6 ....... SysAD[51] | U9........SysAD[63] |
| A3 ................... Vss | C6 ....... SysAD[16] | F1 ................... Vcc | K18 ..................Vss | R7 ....... SysAD[55] | U10......SysAD[13] |
| A4 ...................Vcc | C7 ....... SysAD[50] | F2 ........... Reserved | L1 ....................Vss | R8 ....... SysAD[27] | U11......SysAD[11] |
| A5 ................... Vss | C8 ....... SysAD[22] | F3 ............. ScValid | L2 ....... SysCmd[8] | R9 ....... SysAD[31] | U12........SysAD[9] |
| A6 ................... Vss | C9 ....... SysAD[24] | F4 .............INT[1]* | L3 ....... SysCmd[7] | R10 ..... SysAD[43] | U13......SysAD[37] |
| A7 ...................Vcc | C10 ..... SysAD[28] | F15 ..... ScDCE[0]* | L4 ....... SysCmd[5] | R11 ..... SysAD[39] | U14........SysAD[3] |
| A8 ................... Vss | C11 ..... SysAD[62] | F16 .... ScCWE[0]* | L15 ......ScLine[12] | R12 ..... SysAD[35] | U15...... ScWord[0] |
| A9 ...................Vcc | C12 ..... SysAD[44] | F17 .......... ScTDE* | L16 ......ScLine[14] | R13 ....... SysAD[1] | U16................. Vcc |
| A10 ................. Vss | C13 ..... SysAD[10] | F18 .................. Vss | L17 ......ScLine[15] | R14 ...... ScWord[1] | U17..................Vss |
| A11 .................Vcc | C14 ..... SysAD[38] | G1.................... Vss | L18 ................. Vcc | R15 ........ScLine[0] | U18..................Vss |
| A12 ................. Vss | C15 ....... SysAD[4] | G2........... Reserved | M1 .................. Vcc | R16 ........ScLine[3] | V1....................Vss |
| A13 .................Vcc | C16 ..... SysAD[34] | G3........... Reserved | M2 ...... SysCmd[6] | R17 ........ScLine[6] | V2....................Vss |
| A14 ................. Vss | C17 ....... SysAD[2] | G4........... Reserved | M3 ...... SysCmd[4] | R18 ..................Vss | V3................... Vcc |
| A15 ................. Vss | C18 ................. Vss | G15.......... ScCLR* | M4 ...... SysCmd[1] | T1 ....................Vss | V4....................Vss |
| A16 .................Vcc | D1 ................... Vss | G16.......... ScTCE* | M15 .......ScLine[8] | T2 ....... SysAD[15] | V5....................Vss |
| A17 ................. Vss | D2 ...............INT3* | G17........... ModeIn | M16 .....ScLine[10] | T3 ....... SysAD[47] | V6................... Vcc |
| A18 ................. Vss | D3 ...............INT5* | G18................. Vcc | M17 .....ScLine[13] | T4 ....... SysAD[17] | V7....................Vss |
| B1 ................... Vss | D4 ........... Release* | H1................... Vcc | M18 .................Vss | T5 ....... SysAD[19] | V8................... Vcc |
| B2 ................... Vss | D5 ................... Vcc | H2........... Reserved | N1 ....................Vss | T6 ....... SysAD[23] | V9....................Vss |
| B3 ...................Vcc | D6 ...... SysADC[2] | H3........... Reserved | N2 ....... SysCmd[3] | T7 ....... SysAD[57] | V10................. Vcc |
| B4 ...... SysADC[4] | D7 ....... SysAD[48] | H4........... Reserved | N3 ....... SysCmd[2] | T8 ....... SysAD[29] | V11..................Vss |
| B5 ...... SysADC[0] | D8 ....... SysAD[52] | H15............VccOK | N4 .......SysADC[7] | T9 ................... Vcc | V12................. Vcc |
| B6 ....... SysAD[18] | D9 ....... SysAD[56] | H16..... ModeClock | N15 ........ScLine[5] | T10 ..... SysAD[45] | V13..................Vss |
| B7 ....... SysAD[20] | D10 ..... SysAD[60] | H17.........SysClock | N16 ........ScLine[7] | T11 ..... SysAD[41] | V14................. Vcc |
| B8 ....... SysAD[54] | D11 ..... SysAD[14] | H18.................. Vss | N17 ......ScLine[11] | T12 ....... SysAD[7] | V15..................Vss |
| B9 ....... SysAD[26] | D12 ..... SysAD[42] | J1 ..................... Vss | N18 ................. Vcc | T13 ....... SysAD[5] | V16..................Vss |
| B10 ..... SysAD[58] | D13 ....... SysAD[8] | J2 ............. WrRdy* | P1.................... Vcc | T14 ..... SysAD[33] | V17................. Vcc |
| B11 ..... SysAD[30] | D14 ..... SysAD[36] | J3 ............. ValidIn* | P2........ SysCmd[0] | T15 .............Reset* | V18..................Vss |
| B12 ..... SysAD[46] | D15 .....ColdReset* | J4 ............. ExtReq* | P3...........SysCmdP | T16 ........ScLine[1] |  |
| B13 ..... SysAD[12] | D16 ....... SysAD[0] | J15 .......... Reserved | P4........SysADC[1] | T17 ................. Vcc |  |
| B14 ..... SysAD[40] | D17 ..........ScTOE* | J16 .......... Reserved | P15.........ScLine[2] | T18 ................. Vcc |  |
| B15 ....... SysAD[6] | D18 ................. Vcc | J17 .......... Reserved | P16.........ScLine[4] | U1 ................... Vcc |  |
| B16 ................. Vss | E1.................... Vss | J18 .................. Vcc | P17.........ScLine[9] | U2 ................... Vcc |  |
| B17 .................Vcc | E2............. INT[0]* | K1................... Vcc | P18...................Vss | U3 ....................Vss |  |
| B18 .................Vcc | E3............. INT[2]* | K2............ScMatch | R1 ................... Vcc | U4 ....... SysAD[21] |  |
| C1 ...................Vcc | E4............. INT[4]* | K3.............RdRdy* | R2 .......SysADC[5] | U5 ....... SysAD[53] |  |
| C2 ...................Vcc | E15...... SysAD[32] | K4............ScDOE* | R3 .......SysADC[3] | U6 ....... SysAD[25] |  |
| C3 .........ValidOut* | E16......ScDCE[1]* | K15......... Reserved | R4 ........ BigEndian | U7 ....... SysAD[59] |  |
| C4 ............... NMI* | E17.....ScCWE[1]* | K16............... VccP 52 User’s Manual   U11761EJ6V0UM | R5 ....... SysAD[49] | U8 ....... SysAD[61] |  |

Chapter 2  V5000 Processor Signal Descriptions
R
• 272-pin plastic BGA (cavity down advanced type) (29×29)
μPD30500S2-150
μPD30500S2-180
μPD30500S2-200
μPD30500AS2-250
μPD30500AS2-266
Bottom View Top View
21
20
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
AAYWVUTRPNMLK JHGFEDCBA ABCDEFGHJ KLMNPRTUVWYAA
User’s Manual   U11761EJ6V0UM 53

Chapter 2  V5000 Processor Signal Descriptions
R
(1) μPD30500
| Location .......Name | Location .......Name | Location ...... Name | Location....... Name | Location....... Name | Location ...... Name |
| --- | --- | --- | --- | --- | --- |
| A1 ................... Vss | C1 ................... Vss | E1 .................... Vss | K3 ....... SysAD[62] | R18 ................. Vcc | W2.................. Vcc |
| A2 ...................Vcc | C2 ................... Vcc | E2 ........SysAD[36] | K4 ................... Vcc | R19 ..... SysAD[53] | W3.................. Vcc |
| A3 ................... Vss | C3 .......ColdReset* | E3 ..........SysAD[4] | K18 ................. Vcc | R20 ..... SysAD[23] | W4.................. Vcc |
| A4 ....... SysAD[32] | C4 ....... SysAD[34] | E4 ................... Vcc | K19 ..... SysAD[11] | R21 ..................Vss | W5..............Int*[5] |
| A5 ................... Vss | C5 .......ScDCE*[1] | E18 ................. Vcc | K20 ..... SysAD[43] | T1 ....... SysAD[16] | W6..............Int*[4] |
| A6 ......ScCWE*[1] | C6 .......ScDCE*[0] | E19 ...... ScWord[1] | K21 ..... SysAD[13] | T2 .......SysADC[0] | W7..............Int*[1] |
| A7 ................... Vss | C7 ......ScCWE*[0] | E20 ...... ScWord[0] | L1 ....................Vss | T3 .......SysADC[2] | W8.......... Reserved |
| A8 ............. VccOK | C8 ............ScTCE* | E21 .................. Vss | L2 ....... SysAD[58] | T4 ....................Vss | W9.......... Reserved |
| A9 ................... Vss | C9 .............ModeIn | F1 ..........SysAD[8] | L3 ....... SysAD[28] | T18 ..................Vss | W10........ Reserved |
| A10 ........ SysClock | C10 ........ Reserved | F2 ........SysAD[38] | L4 ................... Vcc | T19 ..... SysAD[19] | W11......... ValidIn* |
| A11 ................. Vss | C11 ............... VssP | F3 ..........SysAD[6] | L18 ................. Vcc | T20 ..... SysAD[51] | W12.........ScDOE* |
| A12 ..... ScLine[15] | C12 ........ Reserved | F4 .................... Vss | L19 ..... SysAD[45] | T21 ..... SysAD[21] | W13.....SysCmd[7] |
| A13 ................. Vss | C13 ..... ScLine[13] | F18 .................. Vss | L120 ... SysAD[63] | U1 ....................Vss | W14.....SysCmd[4] |
| A14 ..... ScLine[12] | C14 ..... ScLine[11] | F19 ........SysAD[1] | L21 ..................Vss | U2 .......SysADC[4] | W15.....SysCmd[1] |
| A15 ................. Vss | C15 ....... ScLine[8] | F20 ......SysAD[33] | M1 ...... SysAD[26] | U3 .......SysADC[6] | W16.... SysADC[7] |
| A16 ....... ScLine[7] | C16 ....... ScLine[5] | F21 ........SysAD[3] | M2 ...... SysAD[56] | U4 ................... Vcc | W17.... SysADC[5] |
| A17 ................. Vss | C17 ....... ScLine[4] | G1.................... Vss | M3 ...... SysAD[24] | U18 ................. Vcc | W18.....SysAD[47] |
| A18 ....... ScLine[2] | C18 ....... ScLine[0] | G2........SysAD[10] | M4 .................. Vcc | U19 ..... SysAD[17] | W19......BigEndian |
| A19 ................. Vss | C19 ............ Reset* | G3........SysAD[40] | M18 ................ Vcc | U20 ..... SysAD[49] | W20................ Vcc |
| A20 .................Vcc | C20 ................. Vcc | G4................... Vcc | M19 .... SysAD[29] | U21 ..................Vss | W21.................Vss |
| A21 ................. Vss | C21 ................. Vss | G18................. Vcc | M20 .... SysAD[61] | V1 ................... Vcc | Y1................... Vcc |
| B1 ...................Vcc | D1 ................... Vcc | G19......SysAD[35] | M21 .... SysAD[31] | V2 ................... Vcc | Y2...................Vcc |
| B2 ...................Vcc | D2 ................... Vcc | G20........SysAD[5] | N1 ....................Vss | V3 ................... Vcc | Y3................... Vcc |
| B3 ...................Vcc | D3 ................... Vcc | G21.................. Vss | N2 ....... SysAD[54] | V4 ....................Vss | Y4........... Release* |
| B4 ......... SysAD[2] | D4 ................... Vss | H1........SysAD[42] | N3 ....... SysAD[22] | V5 ................NMI* | Y5...............Int*[3] |
| B5 ......... SysAD[0] | D5 .................. .Vcc | H2........SysAD[44] | N4 ....................Vss | V6 ....................Vss | Y6...............Int*[2] |
| B6 ............ScTOE* | D6 ................... Vss | H3........SysAD[12] | N18 ..................Vss | V7 ................... Vcc | Y7............. ScValid |
| B7 ........... ScCLR* | D7 ................... Vcc | H4................... Vcc | N19 ..... SysAD[27] | V8 ................... Vcc | Y8........... Reserved |
| B8 ........... ScTDE* | D8 ................... Vcc | H18................. Vcc | N20 ..... SysAD[59] | V9 ....................Vss | Y9........... Reserved |
| B9 ...... ModeClock | D9 ................... Vss | H19........SysAD[7] | N21 ..................Vss | V10 ................. Vcc | Y10......... Reserved |
| B10 ........ Reserved | D10 ................. Vcc | H20......SysAD[39] | P1........ SysAD[50] | V11 ................. Vcc | Y11..........ExtReq* |
| B11 ........ Reserved | D11 ...............VccP | H21......SysAD[37] | P2........ SysAD[52] | V12 ................. Vcc | Y12.......... RdRdy* |
| B12 ..................NC | D12 ................. Vcc | J1 ..................... Vss | P3........ SysAD[20] | V13 ..................Vss | Y13......SysCmd[8] |
| B13 ..... ScLine[14] | D13 ................. Vss | J2 .........SysAD[46] | P4.................... Vcc | V14 ................. Vcc | Y14......SysCmd[5] |
| B14 ..... ScLine[10] | D14 ................. Vcc | J3 .........SysAD[14] | P18.................. Vcc | V15 ................. Vcc | Y15......SysCmd[3] |
| B15 ....... ScLine[9] | D15 ................. Vcc | J4 ..................... Vss | P19...... SysAD[25] | V16 ..................Vss | Y16......SysCmd[0] |
| B16 ....... ScLine[6] | D16 ................. Vss | J18 ................... Vss | P20...... SysAD[57] | V17 ................. Vcc | Y17........ SysCmdP |
| B17 ....... ScLine[3] | D17 ................. Vcc | J19 .........SysAD[9] | P21...... SysAD[55] | V18 ..................Vss | Y18..... SysADC[1] |
| B18 ....... ScLine[1] | D18 ................. Vss | J20 .......SysAD[41] | R1 ....................Vss | V19 ................. Vcc | Y19......SysAD[15] |
| B19 .................Vcc | D19 ................. Vcc | J21 ................... Vss | R2 ....... SysAD[18] | V20 ................. Vcc | Y20................. Vcc |
| B20 .................Vcc | D20 ................. Vcc | K1........SysAD[60] | R3 ....... SysAD[48] | V21 ................. Vcc | Y21................. Vcc |
| B21 .................Vcc | D21 ................. Vcc | K2........SysAD[30] | R4 ................... Vcc Continued on next page 54 User’s Manual   U11761EJ6V0UM | W1 ...................Vss | AA1.................Vss |

Chapter 2  V5000 Processor Signal Descriptions
R
| Location .......Name | Location .......Name | Location ...... Name | Location....... Name | Location....... Name | Location ...... Name |
| --- | --- | --- | --- | --- | --- |
| AA2 ................Vcc | AA7 ................ Vss | AA12.......ScMatch | AA17 ...............Vss |  |  |
| AA3 ................ Vss | AA8 ....... Reserved | AA13............... Vss | AA18 ..SysADC[3] |  |  |
| AA4 ......ValidOut* | AA9 ................ Vss | AA14...SysCmd[6] | AA19 ...............Vss |  |  |
| AA5.................Vss | AA10..........WrRdy* | AA15................Vss | AA20..............Vcc |  |  |
| AA6............Int*[0] | AA11.................Vss User’s Manual   U11761EJ6V0UM 55 | AA16...SysCmd[2] | AA21..............Vss |  |  |

Chapter 2  V5000 Processor Signal Descriptions
R
(2) μPD30500A
| Location .......Name | Location .......Name | Location ...... Name | Location....... Name | Location....... Name | Location ...... Name |
| --- | --- | --- | --- | --- | --- |
| A1 ................... Vss | C1 ................... Vss | E1 .................... Vss | K3 ....... SysAD[62] | R18 ............. VccIO | W2.............. VccIO |
| A2 ...............VccIO | C2 ...............VccIO | E2 ........SysAD[36] | K4 ............... VccIO | R19 ..... SysAD[53] | W3.............. VccIO |
| A3 ................... Vss | C3 .......ColdReset* | E3 ..........SysAD[4] | K18 ............. VccIO | R20 ..... SysAD[23] | W4.............. VccIO |
| A4 ....... SysAD[32] | C4 ....... SysAD[34] | E4 ................... Vcc | K19 ..... SysAD[11] | R21 ..................Vss | W5..............Int*[5] |
| A5 ................... Vss | C5 .......ScDCE*[1] | E18 ................. Vcc | K20 ..... SysAD[43] | T1 ....... SysAD[16] | W6..............Int*[4] |
| A6 ......ScCWE*[1] | C6 .......ScDCE*[0] | E19 ...... ScWord[1] | K21 ..... SysAD[13] | T2 .......SysADC[0] | W7..............Int*[1] |
| A7 ................... Vss | C7 ......ScCWE*[0] | E20 ...... ScWord[0] | L1 ....................Vss | T3 .......SysADC[2] | W8...................Vss |
| A8 ............. VccOK | C8 ............ScTCE* | E21 .................. Vss | L2 ....... SysAD[58] | T4 ....................Vss | W9...................Vss |
| A9 ................... Vss | C9 .............ModeIn | F1 ..........SysAD[8] | L3 ....... SysAD[28] | T18 ..................Vss | W10................ Vcc |
| A10 ........ SysClock | C10 ..................NC | F2 ........SysAD[38] | L4 ................... Vcc | T19 ..... SysAD[19] | W11......... ValidIn* |
| A11 ................. Vss | C11 ............... VssP | F3 ..........SysAD[6] | L18 ................. Vcc | T20 ..... SysAD[51] | W12.........ScDOE* |
| A12 ..... ScLine[15] | C12 ................. Vss | F4 .................... Vss | L19 ..... SysAD[45] | T21 ..... SysAD[21] | W13.....SysCmd[7] |
| A13 ................. Vss | C13 ..... ScLine[13] | F18 .................. Vss | L120 ... SysAD[63] | U1 ....................Vss | W14.....SysCmd[4] |
| A14 ..... ScLine[12] | C14 ..... ScLine[11] | F19 ........SysAD[1] | L21 ..................Vss | U2 .......SysADC[4] | W15.....SysCmd[1] |
| A15 ................. Vss | C15 ....... ScLine[8] | F20 ......SysAD[33] | M1 ...... SysAD[26] | U3 .......SysADC[6] | W16.... SysADC[7] |
| A16 ....... ScLine[7] | C16 ....... ScLine[5] | F21 ........SysAD[3] | M2 ...... SysAD[56] | U4 ................... Vcc | W17.... SysADC[5] |
| A17 ................. Vss | C17 ....... ScLine[4] | G1.................... Vss | M3 ...... SysAD[24] | U18 ................. Vcc | W18.....SysAD[47] |
| A18 ....... ScLine[2] | C18 ....... ScLine[0] | G2........SysAD[10] | M4 .............. VccIO | U19 ..... SysAD[17] | W19......BigEndian |
| A19 ................. Vss | C19 ............ Reset* | G3........SysAD[40] | M18 ............ VccIO | U20 ..... SysAD[49] | W20............ VccIO |
| A20 .............VccIO | C20 .............VccIO | G4............... VccIO | M19 .... SysAD[29] | U21 ..................Vss | W21.................Vss |
| A21 ................. Vss | C21 ................. Vss | G18............. VccIO | M20 .... SysAD[61] | V1 ................... Vcc | Y1............... VccIO |
| B1 ...............VccIO | D1 ................... Vcc | G19......SysAD[35] | M21 .... SysAD[31] | V2 ................... Vcc | Y2............... VccIO |
| B2 ...............VccIO | D2 ................... Vcc | G20........SysAD[5] | N1 ....................Vss | V3 ................... Vcc | Y3............... VccIO |
| B3 ...............VccIO | D3 ................... Vcc | G21.................. Vss | N2 ....... SysAD[54] | V4 ....................Vss | Y4........... Release* |
| B4 ......... SysAD[2] | D4 ................... Vss | H1........SysAD[42] | N3 ....... SysAD[22] | V5 ................NMI* | Y5...............Int*[3] |
| B5 ......... SysAD[0] | D5 .................. .Vcc | H2........SysAD[44] | N4 ....................Vss | V6 ....................Vss | Y6...............Int*[2] |
| B6 ............ScTOE* | D6 ................... Vss | H3........SysAD[12] | N18 ..................Vss | V7 ................... Vcc | Y7............. ScValid |
| B7 ........... ScCLR* | D7 ...............VccIO | H4................... Vcc | N19 ..... SysAD[27] | V8 ............... VccIO | Y8....................Vss |
| B8 ........... ScTDE* | D8 ................... Vcc | H18................. Vcc | N20 ..... SysAD[59] | V9 ....................Vss | Y9....................Vss |
| B9 ...... ModeClock | D9 ................... Vss | H19........SysAD[7] | N21 ..................Vss | V10 ................. Vcc | Y10..................Vss |
| B10 ................. Vss | D10 .............VccIO | H20......SysAD[39] | P1........ SysAD[50] | V11 ............. VccIO | Y11..........ExtReq* |
| B11 ................. Vss | D11 ...............VccP | H21......SysAD[37] | P2........ SysAD[52] | V12 ................. Vcc | Y12.......... RdRdy* |
| B12 ................. Vss | D12 ................. Vcc | J1 ..................... Vss | P3........ SysAD[20] | V13 ..................Vss | Y13......SysCmd[8] |
| B13 ..... ScLine[14] | D13 ................. Vss | J2 .........SysAD[46] | P4.................... Vcc | V14 ............. VccIO | Y14......SysCmd[5] |
| B14 ..... ScLine[10] | D14 .............VccIO | J3 .........SysAD[14] | P18.................. Vcc | V15 ................. Vcc | Y15......SysCmd[3] |
| B15 ....... ScLine[9] | D15 ................. Vcc | J4 ..................... Vss | P19...... SysAD[25] | V16 ..................Vss | Y16......SysCmd[0] |
| B16 ....... ScLine[6] | D16 ................. Vss | J18 ................... Vss | P20...... SysAD[57] | V17 ............. VccIO | Y17........ SysCmdP |
| B17 ....... ScLine[3] | D17 .............VccIO | J19 .........SysAD[9] | P21...... SysAD[55] | V18 ..................Vss | Y18..... SysADC[1] |
| B18 ....... ScLine[1] | D18 ................. Vss | J20 .......SysAD[41] | R1 ....................Vss | V19 ................. Vcc | Y19......SysAD[15] |
| B19 .............VccIO | D19 ................. Vcc | J21 ................... Vss | R2 ....... SysAD[18] | V20 ................. Vcc | Y20............. VccIO |
| B20 .............VccIO | D20 ................. Vcc | K1........SysAD[60] | R3 ....... SysAD[48] | V21 ................. Vcc | Y21............. VccIO |
| B21 .............VccIO | D21 ................. Vcc Continued on next page 56 User’s Manual   U11761EJ6V0UM | K2........SysAD[30] | R4 ............... VccIO | W1 ...................Vss | AA1.................Vss |

Chapter 2  V5000 Processor Signal Descriptions
R
| Location .......Name | Location .......Name | Location ...... Name | Location....... Name | Location....... Name | Location ...... Name |
| --- | --- | --- | --- | --- | --- |
| AA2 ............VccIO | AA7 ................ Vss | AA12.......ScMatch | AA17 ...............Vss |  |  |
| AA3 ................ Vss | AA8 ................ Vss | AA13............... Vss | AA18 ..SysADC[3] |  |  |
| AA4 ......ValidOut* | AA9 ................ Vss | AA14...SysCmd[6] | AA19 ...............Vss |  |  |
| AA5.................Vss | AA10..........WrRdy* | AA15................Vss | AA20 .......... VccIO |  |  |
| AA6............Int*[0] | AA11.................Vss User’s Manual   U11761EJ6V0UM 57 | AA16...SysCmd[2] | AA21..............Vss |  |  |

Chapter 3  CPU Instruction Set Summary
The V 5000 processor executes the MIPS IV instruction set, which is a superset of the
R
MIPS III instruction set and is backward compatible. Each CPU instruction consists of
a single 32-bit word, aligned on a word boundary.  There are three instruction
formats—immediate (I-type), jump (J-type), and register (R-type).  The use of a small
number of instruction formats simplifies instruction decoding, allowing the compiler
to synthesize more complicated (and less frequently used) operations and addressing
modes from these three formats as needed.
A summary of the MIPS IV instruction set additions is listed along with a brief
explanation of each instruction. For more information on the MIPS IV instruction set,
refer toV 5000, V 10000 User’s Manual Instruction.
R R
58 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
There are three types of instruction types as shown in Figure 3-1.
I-Type (Immediate)
| 31 | 2625 | 2120 | 1615 | 0 |
| --- | --- | --- | --- | --- |
| op | rs | rt | immediate J-Type (Jump) |  |
| 31 | 2625 op target R-Type (Register) | 0 |  |  |
| 31 | 2625 | 2120 | 1615 | 11 10 6  5 0 |
| op | rs | rt | rd | sa funct op 6-bit operation code rs 5-bit source register specifier 5-bit target (source/destination) register or branch rt condition immediate 16-bit immediate value, branch displacement or address displacement target 26-bit jump target address rd 5-bit destination register specifier sa 5-bit shift amount funct 6-bit function field Figure  3-1   CPU Instruction Formats In the MIPS architecture, coprocessor instructions are implementation-dependent. 3.1 Load and Store Instructions Loadand store are immediate (I-type) instructions that move data between memory and the general registers.  The only addressing mode that integer load and store instructions directly support isbase register plus 16-bit signed immediate offset. Floating point load and store instructions also support an indexed addressing, register+ register, addressing mode. User’s Manual  U11761EJ6V0UM 59 |

Chapter 3  CPU Instruction Set Summary
3.1.1 Scheduling a Load Delay Slot
In the V 5000 processor, the instruction immediately following a load instruction can
R
use the contents of the loaded register, however in such cases hardware interlocks
insert additional real cycles.  Consequently, scheduling load delay slots can be
desirable, both for performance and V -Series processor compatibility.  However, the
R
scheduling of load delay slots is not absolutely required.
3.1.2 Defining Access Types
Access typeindicates the size of a V 5000 processor data item to be loaded or stored,
R
set by the load or store instruction opcode.
Regardless of access type or byte ordering (endianness), the address given specifies the
low-order byte in the addressed field.  For a big-endian configuration, the low-order
byte is the most-significant byte; for a little-endian configuration, the low-order byte
is the least-significant byte.
The access type, together with the three low-order bits of the address, define the bytes
accessed within the addressed doubleword (shown in Table 3-1).  Only the
combinations shown in Table 3-1 are permissible; other combinations cause address
error exceptions.
60 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
Table 3-1    Byte Access within a Doubleword
Low Order Bytes Accessed
Access Type Address Bits
Mnemonic	Big endian	Little endian
(Value) (63-----------31------------0) (63-----------31------------0)
210
Byte Byte
Doubleword (7)   0  0  0 0123456776543210
0  0  0 0123456 6543210
Septibyte (6)
0  0  1 12345677654321
0  0  0 012345 543210
Sextibyte (5)
0  1  0 234567765432
0  0  0 01234 43210
Quintibyte (4)
0  1  1 3456776543
0  0  0 0123 3210
Word (3)
1  0  0 45677654
0  0  0 012 210
| 0  0  1 | 123 Triplebyte (2) | 321 |
| --- | --- | --- |
| 1  0  0 | 456 1  0  1 567765 0  0  0 01 10 | 654 |
| 0  1  0 | 23 Halfword (1) | 32 |
| 1  0  0 | 45 1  1  0 6776 0000 0 | 54 |
| 001 | 1 | 1 |
| 010 | 2 | 2 |
| 011 | 3 Byte (0) | 3 |
| 100 | 4 | 4 |
| 101 | 5 | 5 |
| 110 | 6 111 77 User’s Manual  U11761EJ6V0UM 61 | 6 |

Chapter 3  CPU Instruction Set Summary
3.2 Computational Instructions
Computational instructions can be either in register (R-type) format, in which both
operands are registers, or in immediate (I-type) format, in which one operand is a 16-
bit immediate.
Computationalinstructions perform the following operations on register values:
• arithmetic
• logical
• shift
• multiply
• divide
These operations fit in the following four categories of computational instructions:
• ALU Immediateinstructions
• three-Operand Register-Typeinstructions
• shiftinstructions
• multiply and divide instructions
3.2.1 64-bit Operations
The V 5000 microprocessor is a 64-bit architecture which supports 32-bit operands.
R
These operands must be sign extended. Thirty-two bit operand opcodes include all
non-doubleword operations, such as: ADD, ADDU, SUB, SUBU, ADDI, SLL, SRA,
SLLV, etc.  The result of operations that use incorrect sign-extended 32-bit values is
unpredictable. In addition, 32-bit data is stored sign-extended in a 64-bit register.
3.2.2 Cycle Timing for Multiply and Divide Instructions
MFHI and MFLO instructions are interlocked so that any attempt to read them before
prior instructions complete delays the execution of these instructions until the prior
instructions finish.
Table 3-2 gives the number of processor cycles (PCycles) required to resolve an
interlock or stall between various multiply or divide instructions, and a subsequent
MFHI or MFLO instruction.
62 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
Table 3-2    Multiply/Divide Instruction Latency and Repeat Rates
| Instruction | Latency | Repeat Rate |
| --- | --- | --- |
| MULT (32-bit×16-bit) | 4 | 3 |
| MULT (32-bit×32-bit) | 5 | 4 |
| MULTU | 5 | 4 |
| DIV | 36 | 36 |
| DIVU | 36 | 36 |
| DMULT | 9 | 8 |
| DMULTU | 9 | 8 |
| DDIV | 68 | 68 |
| DDIVU | 68 3.2.3 Jump and Branch Instructions Jump and branchinstructions change the control flow of a program.  All jump and branch instructions occur with a delay of one instruction: that is, the instruction immediately following the jump or branch (this is known as the instruction in thedelay slot) always executes while the target instruction is being fetched from storage. (1) Overview of Jump Instructions Subroutine calls in high-level languages are usually implemented with Jump or Jump and Link instructions, both of which are J-type instructions.  In J-type format, the 26- bit target address shifts left 2 bits and combines with the high-order 4 bits of the current program counter to form an absolute address. Returns, dispatches, and large cross-page jumps are usually implemented with the Jump Register or Jump and Link Register instructions.  Both are R-type instructions that take the 64-bit byte address contained in one of the general purpose registers. (2) Overview of Branch Instructions All branch instruction target addresses are computed by adding the address of the instruction in the delay slot to the 16-bitoffset(shifts left 2 bits and is sign-extended to 64 bits).  All branches occur with a delay of one instruction. If a conditional branch is not taken, the instruction in the delay slot is nullified. User’s Manual  U11761EJ6V0UM 63 | 68 |

Chapter 3  CPU Instruction Set Summary
3.2.4 Special Instructions
Specialinstructions allow the software to initiate traps; they are always R-type.
Exception instructions are extensions to the MIPS ISA.
3.2.5 Coprocessor Instructions
Coprocessorinstructions perform operations in their respective coprocessors.
Coprocessor loads and stores are I-type, and coprocessor computational instructions
have coprocessor-dependent formats.
CP0instructions perform operations specifically on the System Control Coprocessor
registers to manipulate the memory management and exception handling facilities of
the processor.
3.3 MIPS IV Instruction Set Additions
The V 5000 Microprocessor runs the MIPS IV instruction set, which is a superset of
R
the MIPS III instruction set and is backward compatible. The additions of these new
instructions enables the MIPS architecture to compete in the high-end numeric
processing market which has traditionally been dominated by vector architectures.
A set of compound multiply-add instructions has been added, taking advantage of the
fact that the majority of floating point computations use the chained multiply-add
paradigm. The intermediate multiply result is rounded before the addition is
performed.
A register + register addressing mode for floating point loads and stores has been
added which eliminates the extra integer add required in many array accesses.
However, issuing of a Register + Register load causes a one cycle stall in the pipeline,
which makes it useful only for compatibility with other MIPS IV implementations.
Register + register addressing for integer memory operations is not supported.
64 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
A set of four conditional move operators allows floating point arithmetic ‘IF’
statements to be represented without branches. ‘THEN’ and ‘ELSE’ clauses are
computed unconditionally and the results placed in a temporary register. Conditional
move operators then transfer the temporary results to their true register. Conditional
moves must be able to test both integer and floating point conditions in order to supply
the full range of IF statements. Integer tests are performed by comparing a general
register against a zero value.
Floating point tests are performed by examining the floating point condition codes.
Since floating point conditional moves test the floating point condition code, the
V 5000 microprocessor provides 8 condition codes to give the compiler increased
R
flexibility in scheduling the comparison and the conditional moves. Table 3-3 lists in
alphabetical order the new instructions which comprise the MIPS IV instruction set.
Table 3-3    MIPS IV Instruction Set Additions and Extensions
Instruction Definition
BC1F Branch on FP Condition Code False
BC1T Branch on FP Condition Code True
BC1FL Branch on FP Condition Code False Likely
BC1TL Branch on FP Condition Code True Likely
C.cond.fmt (cc) Floating Point Compare
LDXC1 Load Double Word indexed to COP1
LWXC1 Load Word indexed to COP1
MADD.fmt Floating Point Multiply-Add
MOVF Move conditional on FP Condition Code False
MOVN Move on Register Not Equal to Zero
MOVT Move conditional on FP Condition Code True
MOVZ Move on Register Equal to Zero
MOVF.fmt FP Move conditional on Condition Code False
MOVN.fmt FP Move on Register Not Equal to Zero
MOVT.fmt FP Move conditional on Condition Code True
User’s Manual  U11761EJ6V0UM 65

Chapter 3  CPU Instruction Set Summary
Table 3-3    MIPS IV Instruction Set Additions and Extensions  (Continued)
Instruction Definition
MOVZ.fmt FP Move conditional on Register Equal to Zero
MSUB.fmt Floating Point Multiply-Subtract
NMADD.fmt Floating Point Negative Multipy-Add
NMSUB.fmt Floating Point Negative Multiply-Subtract
a
PREFX Prefetch Indexed --- Register + Register
a
PREF Prefetch --- Register + Offset
RECIP.fmt Reciprocal Approximation
RSQRT.fmt Reciprocal Square Root Approximation
SDXC1 Store Double Word indexed to COP1
SWXC1 Store Word indexed to COP1
a.  Prefetch is not implemented in the V 5000 microprocessor and these instruc-
R
tions are treated as no-ops.
Table 3-4 lists the COP0 instructions for the V 5000 processor. COP0 instructions are
R
those which are not architecturally visible and are used by the kernel.
Table 3-4    V5000 COP0 Instrucitons
R
COP0 Instruction Definition
ERET Return from Exception
TLBP Probe for TLB Entry
TLBR Read Indexed TLB Entry
TLBWI Write Indexed TLB Entry
TLBWR Write Random TLB Entry
WAIT Enter Standby Mode
66 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
3.3.1 Summary of Instruction Set Additions
The following is a brief description of the additions to the MIPS III instruction set.
These additions comprise the MIPS IV instruction set.
(1) Indexed Floating Point Load
LWXC1- Load word indexed to Coprocessor 1.
LDXC1- Load doubleword indexed to Coprocessor 1.
The two Index Floating Point Load instructions are exclusive to the MIPS IV
instruction set and transfer floating-point data types from memory to the floating point
registers using register + register addressing mode. There are no indexed loads to
general registers. The contents of the general register specified by the base is added to
the contents of the general register specified by the index to form a virtual address. The
contents of the word or doubleword specified by the effective address are loaded into
the floating point register specified in the instruction.
The region bits (63:62) of the effective address must be supplied by the base. If the
addition alters these bits an address exception occurs. Also, if the address is not
aligned, an address exception occurs.
(2) Indexed Floating Point Store
SWXC1- Store word indexed to Coprocessor 1.
SDXC1- Store doubleword indexed to Coprocessor 1.
The two Index Floating Point Store instructions are exclusive to the MIPS IV
instruction set and transfer floating-point data types from the floating point registers to
memory using register + register addressing mode. There are no indexed loads to
general registers. The contents of the general register specified by the base is added to
the contents of the general register specified by the index to form a virtual address. The
contents of the floating point register specified in the instruction is stored to the
memory location specified by the effective address.
The region bits (63:62) of the effective address must be supplied by the base. If the
addition alters these bits an address exception occurs. Also, if the address is not
aligned, an address exception occurs.
User’s Manual  U11761EJ6V0UM 67

Chapter 3  CPU Instruction Set Summary
(3) Prefetch
PREF- Register + offset format
PREFX- Register + register format
The two prefetch instructions are exclusive to the MIPS IV instruction set and allow
the compiler to issue instructions early so the corresponding data can be fetched and
placed as close as possible to the CPU. Each instruction contains a 5-bit ‘hint’ field
which gives the coherency status of the line being prefetched. The line can be either
shared, exclusive clean, or exclusive dirty. The contents of the general register
specified by the base is added either to the 16 bit sign-extended offset or to the contents
of the general register specified by the index to form a virtual address. This address
together with the ‘hint’ field is sent to the cache controller and a memory access is
initiated.
The region bits (63:62) of the effective address must be supplied by the base. If the
addition alters these bits an address exception occurs. The prefetch instruction never
generates TLB-related exceptions. The PREF instruction is considered a standard
processor instruction while the PREFX instruction is considered a standard
Coprocessor 1 instruction. The V 5000 microprocessor does not implement prefetch
R
and these instruction are executed as no-ops.
(4) Branch on Floating Point Coprocessor
BC1T- Branch on FP condition True
BC1F- Branch on FP condition False
BC1TL- Branch on FP condition True Likely
BC1FL- Branch on FP condition False Likely
The four branch instructions are upward compatible extensions of the Branch on
Floating point Coprocessor instructions of the MIPS instruction set. The BC1T and
BC1F instructions are extensions of MIPS I. BC1TL and BC1FL are extensions of
MIPS III. These instructions test one of eight floating point condition codes.  This
encoding is downward compatible with previous MIPS architectures.
The branch target address is computed from the sum of the address of the instruction
in the delay slot and the 16-bit offset, shifted left two bits and sign-extended to 64 bits.
If the contents of the floating point condition code specified in the instruction are equal
to the test value, the target address is branched to with a delay of one instruction. If the
conditional branch is not taken and the nullify delay bit in the instruction is set, the
instruction in the branch delay slot is nullified.
68 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
(5) Integer Conditional Moves
MOVT- Move conditional on condition code true
MOVF- Move conditional on condition code false
MOVN- Move conditional on register not equal to zero
MOVZ- Move conditional on register equal to zero
The four integer move instructions are exclusive to the MIPS IV instruction set and are
used to test a condition code or a general register and then conditionally perform an
integer move. The value of the floating point condition code specified in the instruction
by the 3-bit condition code specifier, or the value of the register indicated by the 5-bit
general register specifier, is compared to zero. If the result indicates that the move
should be performed, the contents of the specified source register is copied into the
specified destination register.
(6) Floating Point Multiply-Add
MADD- Floating Point Multiply-Add
MSUB- Floating Point Multiply-Subtract
NMADD- Floating Point Negative Multiply-Add
NMSUB- Floating Point Negative Multiply-Subtract
These four instructions are exclusive to the MIPS IV instruction set and accomplish
two floating point operations with one instruction. Each of these four instrucitons
performs intermediate rounding.
(7) Floating Point Compare
C.cond.fmt- Compare the contents of two FPU registers
The contents of the two FPU source registers specified in the instruction are interpreted
and arithmetically compared. A result is determined based on the comparison and the
conditions specified in the instruction.
User’s Manual  U11761EJ6V0UM 69

Chapter 3  CPU Instruction Set Summary
(8) Floating Point Conditional Moves
MOVT.fmt- Floating Point Conditional Move on condition code true
MOVF.fmt- Floating Point Conditional Move on condition code false
MOVN.fmt- Floating Point Conditional Move on register not equal to zero
MOVZ.fmt- Floating Point Conditional Move on register equal to zero
The four floating point conditional move instructions are exclusive to the MIPS IV
instruction set and are used to test a condition code or a general register and then
conditionally perform a floating point move. The value of the floating point condition
code specified by the 3-bit condition code specifier, or the value of the register
indicated by the 5-bit general register specifier, is compared to zero. If the result
indicates that the move should be performed, the contents of the specified source
register is copied into the specified destination register. All of these conditional
floating point move operations are non-arithmetic. Consequently, no IEEE 754
exceptions occur as a result of these instructions.
(9) Reciprocal’s
RECIP.fmt- Reciprocal
RSQRT.fmt- Reciprocal Square Root
The reciprocal instruction performs a reciprocal on a floating point value. The
reciprocal of the value in the floating point source register is placed in a destination
register.
The reciprocal square root instruction performs a reciprocal square root on a floating
point value. The reciprocal of the positive square root of a value in the floating point
source register is placed in a destination register.
The V 5000 meets full IEEE accuracy for the RECIP and RSQRT instructions.
R
On the V 5000 microprocessor, the RECIP instruction has the same latency as a DIV
R
instruction, but a RSQRT is faster than a SQRT followed by a RECIP.
70 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
3.3.2 Cycle Timing for Floating Point Instrucitons
Table 3-5    Floating Point Operations
| Opcode | Latency | Repeat |
| --- | --- | --- |
| ADD  (sngl/dbl) | 4 | 1 |
| SUB  (sngl/dbl) | 4 | 1 |
| MULT  (sngl/dbl) | 4/5 | 1/2 |
| MADD  (sngl/dbl) | 4/5 | 1/2 |
| MSUB  (sngl/dbl) | 4/5 | 1/2 |
| NMADD (sngl/dbl) | 4/5 | 1/2 |
| NMSUB (sngl/dbl) | 4/5 | 1/2 |
| DIV  (sngl/dbl) | 21/36 | 19/34 |
| SQRT  (sngl/dbl) | 21/36 | 19/34 |
| RECIP  (sngl/dbl) | 21/36 | 19/34 |
| RSQRT  (sngl/dbl) | 38/68 | 36/66 |
| ROUND.W (sngl/dbl) | 4/4 | 1/1 |
| ROUND.L (sngl/dbl) | 4/4 | 1/1 |
| TRUNC.W (sngl/dbl) | 4/4 | 1/1 |
| TRUNC.L (sngl/dbl) | 4/4 | 1/1 |
| CEIL.W (sngl/dbl) | 4/4 | 1/1 |
| CEIL.L (sngl/dbl) | 4/4 | 1/1 |
| FLOOR.W (sngl/dbl) | 4/4 | 1/1 |
| FLOOR.L (sngl/dbl) | 4/4 | 1/1 |
| CVT.S.D | 4 | 1 |
| CVT.S.W | 6 | 3 |
| CVT.S.L | 6 | 3 |
| CVT.D.S | 4 | 1 |
| CVT.D.W | 4 | 1 |
| CVT.D.L | 4 | 1 |
| CVT.W (sngl/dbl) | 4 | 1 |
| CVT.L (sngl/dbl) | 4 | 1 |
| CMP  (sngl/dbl) | 1 | 1 |
| MOV  (sngl/dbl) | 1 | 1 |
| MOVC  (sngl/dbl) | 1 | 1 |
| ABS  (sngl/dbl) | 1 | 1 |
| NEG  (sngl/dbl) | 1 | 1 |
| LWC1,  LWXC1 | 2 User’s Manual  U11761EJ6V0UM 71 | 1 |

Chapter 3  CPU Instruction Set Summary
Table 3-5    Floating Point Operations (Continued)
| Opcode | Latency | Repeat |
| --- | --- | --- |
| LDC1,  LDXC1 | 2 | 1 |
| SWC1,  SWXC1 | 2 | 1 |
| SDC1,  SDXC1 | 2 | 1 |
| MTC1,  DMTC1 | 2 | 1 |
| MFC1,  DMFC1 | 2 | 1 |
| CTC1 | 3 | 3 |
| CFC1 | 2 | 2 |
| BC1T, BC1TL | 1 | 1 |
| BC1F, BC1FL | 1 3.4 The Cache Instruction The CACHE instruction in the V 5000 microprocessor is implemented as follows: | 1 |
R
31	2625	2120	1615	0
CACHE	base	op	offset
1 0 1 1 1 1
655 16
Figure  3-2   V5000 CACHE Instruction Format
R
Format:
CACHE op, offset(base)
Description:
The 16-bitoffsetis sign-extended and added to the contents of general registerbaseto
form a virtual address.  The virtual address is translated to a physical address using the
TLB, and the 5-bit sub-opcode specifies a cache operation for that address.
If CP0 is not usable (User or Supervisor mode) the CP0 enable bit in theStatusregister
is clear, and a coprocessor unusable exception is taken.  The operation of this
instruction on any operation/cache combination not listed below, or on a secondary
cache when none is present, is undefined. The operation of this instruction on
uncached addresses is also undefined.
72 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
The Index operation uses part of the virtual address to specify a cache block.
For a primary cache of  32 KB with 32 bytes per tag, vAddr specifies the block.  In
13:5
addition, vAddr specifies which cache set to operate on.
14
CACHEBITS LINEBITS
| For a secondary cache of 2 | bytes with 2 | bytes per tag, pAddr specifies the block. CACHEBITS ... LINEBITS Index Load Tag also uses vAddr to select the doubleword for reading LINEBITS... 3 parity.  When theCEbit of theStatusregister is set, Hit WriteBack, Hit WriteBack Invalidate, Index WriteBack Invalidate, and Fill also use vAddr to select LINEBITS ... 3 the doubleword that has its parity modified. This operation is performed unconditionally. The Hit operation accesses the specified cache as normal data references, and performs the specified operation if the cache block contains valid data with the specified physical address (a hit).  If the cache block is invalid or contains a different address (a miss), no operation is performed. Write back from a primary cache goes to the secondary cache and to memory. If no secondary cache is present, the data goes to memory. Data comes from the primary data cache, if present, and is modified (it is marked Dirty).  Otherwise the data comes from the secondary cache.  The address to be written is specified by the cache tag and not the translated physical address. TLB Refill and TLB Invalid exceptions can occur on any operation.  For Index operations (where the physical address is used to index the cache but need not match the cache tag) unmapped addresses may be used to avoid TLB exceptions.  This operation never causes TLB Modified or Virtual Coherency exceptions. Bits 17...16 of the instruction specify the cache as follows: |
| --- | --- | --- |
| Code | Name | Cache |
| 0 | I | primary instruction |
| 1 | D | primary data |
| 2 | -- | Reserved |
| 3 | SD | secondary cache User’s Manual  U11761EJ6V0UM 73 |

Chapter 3  CPU Instruction Set Summary
Bits 20...18 (this value is listed under theCodecolumn) of the instruction specify the
operation as follows:
Code	Caches	Name	Operation
Index
0I Set the cache state of the cache block to Invalid.
Invalidate
Examine the cache state of the primary data cache block at the index
Index specified by the virtual address.  If the state is Dirty, write the block back
0DWriteback to the secondary cache (if present) and to memory.  The address to write
Invalidate is taken from the primary cache tag.  Set the cache state of primary
cache block to Invalid.
Flash Flash Invalidate the entire secondary cache in one operation for tag
0S
Invalidate RAMs which support this function.
Index Load Read the tag for the cache block at the specified index and place it iinto
1 All
Tag theTagLoandTagHiCP0 registers, ignoring any parity errors.
Index Store Write the tag for the cache block at the specified index from theTagLo
2 I, D
Tag andTagHiCP0 registers.
Write the tag for the cache block at the specified index with the tag value
Index Store
2S from the effective address generated by the CACHE instruction and the
Tag
valid bit from the TagLo CP0 register.
This operation is used to avoid loading data needlessly from secondary
cache or memory when writing new contents into an entire cache block.
Create Dirty If the cache block does not contain the specified address, and the block
3D
Exclusive is dirty, write it back to the secondary cache (if present) and to memory.
In all cases, set the cache block tag to the specified physical address,
set the cache state to Dirty Exclusive.
If the cache block contains the specified address, mark the cache block
4	I,D	Hit Invalidate
invalid.
Hit Writeback If the cache block contains the specified address, write the data back if
5D
Invalidate it is dirty, and mark the cache block invalid.
The processor will generate a page invalidate by doing a burst of 128
Page line invalidates to the secondary cache at the page specified by the
5S
Invalidate effective address generated by the CACHE instruction, which must be
page-aligned. Interrupts are deferred during page invalidates.
Fill the primary instruction cache block from secondary cache or
| 5 | I | Fill memory. If the cache block contains the specified address, and its state is Dirty, |
| --- | --- | --- |
| 6 | D | Hit Writeback write back the data and clear the state to not Dirty. If the cache block contains the specified address, data is written back |
| 6 | I | Hit Writeback unconditionally. 74 User’s Manual  U11761EJ6V0UM |

Chapter 3  CPU Instruction Set Summary
Operation:
48
32, 64	T:	vAddr←((offset	)	|| offset	) + GPR[base]
15 15...0
(pAddr, uncached)←AddressTranslation (vAddr, DATA)
CacheOp (op, vAddr, pAddr)
Exceptions:
Coprocessor unusable exception
3.5 Implementation Specific Instructions
Some of the V 5000 instructions are implementation specific and therefore are not
R
part of the MIPS IV Instruction Set.  These are coprocessor instructions that perform
operations in their respective coprocessors.  Coprocessor loads and stores are I-type,
and coprocessor computational instructions have coprocessor-dependent formats.
User’s Manual  U11761EJ6V0UM 75

Chapter 3  CPU Instruction Set Summary
3.5.1 Implementation Specific CP0 Instructions
ERET Exception Return
| 31 | 26   25   24 | 6    5 | 0 |
| --- | --- | --- | --- |
| COP0 | CO | 0 | ERET |
| 0 1 0 0 0 0 | 1 | 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0    0 1 1 0 0 0 |  |
| 6 | 1 | 19 Format: | 6 |
ERET
Description:
ERET is the V 5000 instruction for returning from an interrupt, exception, or error
R
trap.  Unlike a branch or jump instruction, ERET does not execute the next instruction.
ERET must not itself be placed in a branch delay slot.
If the processor is servicing an error trap (SR = 1), then load the PC from the
2
ErrorEPC and clear the ERL bit of the Status register (SR).  Otherwise (SR =0), load
2 2
the PC from theEPC, and clear theEXLbit of the Status register (SR).
1
An ERET executed between a LL and AC also causes the SC to fail.
Operation:
T:    if SR = 1 then
2
PC←ErrorEPC
SR←SR ||0||SR
31..3 1..0
else
PC←EPC
SR←SR 0    SR
31..2 0
endif
LLbit←0
Exceptions:
Coprocessor unusable exception.
76 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
TLBR Read Indexed TLB Entry
| 31 | 26   25   24 | 6    5 | 0 |
| --- | --- | --- | --- |
| COP0 | CO | 0 | TLBR |
| 0 1 0 0 0 0 | 1 | 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0    0 0 0 0 0 1 |  |
| 6 | 1 | 19 Format: | 6 |
TLBR
Description:
TheEntryHiandEntryLoregisters are loaded with the contents of the TLB entry
pointed at by the contents of the TLBIndexregister.  The operation is invalid (and the
results are unspecified) if the contents of the TLBIndexregister are greater than the
number of TLB entries in the processor.
TheGbit (which controls ASID matching) read from the TLB is written into both of
theEntryLo0andEntryLo1registers.
Operation:
T:   PageMask←TLB[Index ]
5..0255..192
| EntryHi←TLB[Index | ] | and not TLB[Index 5..0191..128 5..0255..192 | ] |
| --- | --- | --- | --- |
| EntryLo1←TLB[Index | ] | \|\|TLB[Index 5..0127..65 5..0140 | ] |
| EntryLo0←TLB[Index | ] | \|\|TLB[Index 5..063..1 5..0140 Exceptions: Coprocessor unusable exception. User’s Manual  U11761EJ6V0UM 77 | ] |

Chapter 3  CPU Instruction Set Summary
TLBP Probe TLB For Matching Entry
| 31 | 26   25   24 | 6    5 | 0 |
| --- | --- | --- | --- |
| COP0 | CO | 0 | TLBP |
| 0 1 0 0 0 0 | 1 | 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0    0 0 1 0 0 0 |  |
| 6 | 1 | 19 Format: | 6 |
TLBP
Description:
TheIndexregister is loaded with the address of the TLB entry whose contents match
the contents of theEntryHiregister.  If no TLB entry matches, the high-order bit of the
Indexregister is set.
The architecture does not specify the operation of memory references associated with
the instruction immediately after a TLBP instruction, nor is the operation specified if
more than one TLB entry matches.
Operation:
31
T:    Index←1||0
For i in 0..TLBEntries - 1
15
if (TLB[i]	and not (0	||TLB[i]	))
167..141 216..205
15
=(EntryHi	and not (0	||TLB[i]	)) and
39..13 216..205
(TLB[i]	or(TLB[i]	= EntryHi7..0)) then
140 135..128
26
Index←0 ||i
5..0
endif
endfor
Exceptions:
Coprocessor unusable exception.
78 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
TLBWI Write Indexed TLB Entry
| 31 | 26   25   24 | 6    5 | 0 |
| --- | --- | --- | --- |
| COP0 | CO | 0 | TLBWI |
| 0 1 0 0 0 0 | 1 | 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0    0 0 0 0 1 0 |  |
| 6 | 1 | 19 Format: | 6 |
TLBWI
Description:
The TLB entry pointed at by the contents of the TLB Index register is loaded with the
contents of the EntryHi and EntryLo registers.
TheGbit of the selected TLB entry is written with the logical AND of theGbits in the
EntryLo0 and EntryLo1 registers.
The operation is invalid (and the results are unspecified) if the contents of theTLB
Index register are greater than the number of TLB entries in the processor.
Operation:
T:    TLB[Index ]←
5..0
EntryHi[39:25]||(EntryHi[24:13] and not PageMask)||EntryLo1
||EntryLo0
Exceptions:
Coprocessor unusable exception.
User’s Manual  U11761EJ6V0UM 79

Chapter 3  CPU Instruction Set Summary
TLBWR Write Random TLB Entry
| 31 | 26   25   24 | 6    5 | 0 |
| --- | --- | --- | --- |
| COP0 | CO | 0 | TLBWR |
| 0 1 0 0 0 0 | 1 | 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0    0 0 0 1 1 0 |  |
| 6 | 1 | 19 Format: | 6 |
TLBWR
Description:
The TLB entry pointed to by the contents of the TLBRandomregister is loaded with
the contents of theEntryHiandEntryLoregisters.
TheGbit of the selected TLB entry is written with the logical AND of theGbits in the
EntryLo0andEntryLo1registers.
Operation:
T:    TLB[Random ]←
5..0
EntryHi[39:25]||(EntryHi[25:13] and not PageMask)||EntryLo1
||EntryLo0
Exceptions:
Coprocessor unsuable exception.
80 User’s Manual  U11761EJ6V0UM

Chapter 3  CPU Instruction Set Summary
DMTC0 Doubleword Move To System Control
Coprocessor
| 31 | 26   25 | 21   20 | 16 | 15 | 11   10 | 0 |
| --- | --- | --- | --- | --- | --- | --- |
| COP0 | DMT | rt | rd | 0 |  |  |
| 0 1 0 0 0 0 | 0 0 1 0 1 | 0 0 1 0 1 | 0 0 1 0 1   0 0 0 0 0 0 0 0 0 0 0 |  |  |  |
| 6 | 5 | 5 | 5 | 11 Format: DMTC0  rt,  rd Description: The contents of general registerrtare loaded into coprocessor registerrdof  CP0. This operation is defined in kernel mode regardless of the setting of the Status.KX bit. Execution of this instruction in supervisor mode with Status.SX = 0 or in user mode with UX = 0, causes a reserved instruction exception. All 64-bits of the coprocessor 0 register are written from the general register source. The operation of DMTC0 on a 32-bit coprocessor 0 register is undefined. Because the state of the virtual address translation system may be altered by this instruction, the operation of load instructions, store instructions, and TLB operations immediately prior to and after this instruction are undefined. Operation: T:        data←GPR[rt] T+1:    CPR[0,rd]←data Exceptions: Coprocessor unusable exception. Reserved instruction exception for supervisor mode with Status.SX = 0 or user mode with Status.UX = 0. User’s Manual  U11761EJ6V0UM 81 |  |  |

Chapter 3  CPU Instruction Set Summary
MTC0                         Move To System Control
Coprocessor
| 31 | 26   25 | 21   20 | 16 | 15 | 11   10 | 0 |
| --- | --- | --- | --- | --- | --- | --- |
| COP0 | MT | rt | rd | 0 |  |  |
| 0 1 0 0 0 0 | 0 0 1 0 0 | 0 0 1 0 1 | 0 0 1 0 1   0 0 0 0 0 0 0 0 0 0 0 |  |  |  |
| 6 | 5 | 5 | 5 | 11 Format: MTC0  rt,  rd Description: The contents of general registerrtare loaded into coprocessor registerrdof CP0. Because the state of the virtual address translation system may be altered by this instruction, the operation of load instructions, store instructions, and TLB operations immediately prior to and after this instruction are undefined. Operation: T:        data←GPR[rt] T+1:    CPR[0,rd]←data Exceptions: Coprocessor unusable exception. 82 User’s Manual  U11761EJ6V0UM |  |  |

Chapter 3  CPU Instruction Set Summary
DMFC0 Doubleword Move From System Control
Coprocessor
| 31 | 26   25 | 21   20 | 16 | 15 | 11   10 | 0 |
| --- | --- | --- | --- | --- | --- | --- |
| COP0 | DMF | rt | rd | 0 |  |  |
| 0 1 0 0 0 0 | 0 0 0 0 1 | 0 0 1 0 1 | 0 0 1 0 1   0 0 0 0 0 0 0 0 0 0 0 |  |  |  |
| 6 | 5 | 5 | 5 | 11 Format: DMFC0  rt,  rd Description: The contents of coprocessor registerrdof the CP0 are loaded into general registerrt. This operation is defined in kernel mode regardless of the setting of the Status.KX bit. Execution of this instruction in supervisor mode with Status.SX = 0 or in user mode with UX = 0, causes a reserved instruction exception. All 64-bits of the general register destination are written from the coprocessor register source.  The operation of DMFC0 on a 32-bit coprocessor 0 register is undefined. Operation: T:        data←GPR[0,rd] T+1:    CPR[rt]←data Exceptions: Coprocessor unusable exception. Reserved instruction exception for supervisor mode with Status.SX = 0 or user mode with Status.UX = 0. User’s Manual  U11761EJ6V0UM 83 |  |  |

Chapter 3  CPU Instruction Set Summary
WAIT Enter Standby Mode
| 31 | 26   25   24 | 6    5 | 0 |
| --- | --- | --- | --- |
| COP0 | CO | 0 | WAIT |
| 0 1 0 0 0 0 | 1 | 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0    1 0 0 0 0 0 |  |
| 6 | 1 | 19 Format: | 6 |
WAIT
Description:
The WAIT instruction is used to put the CPU into Standby Mode. In Standby Mode,
most of the internal clocks are shut down which freezes the pipeline and reduces power
consumption. SeeChapter 18 Standby Mode Operationfor more details.
Operation:
T:        if SysAD bus is idle then
Enter Standby Mode
endif
Exceptions:
Coprocessor unusable exception.
84 User’s Manual  U11761EJ6V0UM

Chapter 4  V 5000 Processor Pipeline
R
The V 5000 processor has a five-stage instruction pipeline. Each stage takes one
R
PCycle (one cycle of PClock, which runs at a multiple of the frequency of SysClock).
Thus, the execution of each instruction takes at least five PCycles.  An instruction can
take longer—for example, if the required data is not in the cache, the data must be
retrieved from main memory.
Once the pipeline has been filled, five instructions can be executed simultaneously.
Figure 4-1 shows the five stages of the instruction pipeline.
User’s Manual   U11761EJ6V0UM 85

Chapter 4  V5000 Processor Pipeline
R
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
One
Cycle
Figure  4-1   Instruction Pipeline Stages
4.1 Instruction Pipeline Stages
• 1I - Instruction Fetch, Phase One
• 2I - Instruction Fetch, Phase Two
• 1R - Register Fetch, Phase One
• 2R - Register Fetch, Phase Two
• 1A - Execution, Phase One
• 2A - Execution, Phase Two
• 1D - Data Fetch, Phase One
• 2D - Data Fetch, Phase Two
• 1W - Write Back, Phase One
• 2W - Write Back, Phase Two
86 User’s Manual   U11761EJ6V0UM

Chapter 4  V5000 Processor Pipeline
R
1I - Instruction Fetch, Phase One
During the 1I phase, the following occurs:
• Branch logic selects an instruction address and the instruction cache fetch
begins.
• The instruction translation lookaside buffer (ITLB) begins the virtual-to-
physical address translation.
2I - Instruction Fetch, Phase Two
The instruction cache fetch and the virtual-to-physical address translation continues.
1R - Register Fetch, Phase One
During the 1R phase, the following occurs:
• The instruction cache fetch is completed.
• The instruction cache tag is checked against the page frame number
obtained from the ITLB
2R - Register Fetch, Phase Two
During the 2R phase, one of the following occurs:
• The instruction decoder decodes the instruction.
• Any required operands are fetched from the register file.
• Determine whether instruction is issued or delayed depending on
interlock conditions.
1A - Execution - Phase One
During the 1A phase, one of the following occurs:
• Calculate branch address (if applicable).
• Any result from the A or D stages are bypassed
• The ALU starts an integer operation.
• The ALU calculates the data virtual address for load and store
instructions.
• The ALU determines whether the branch condition is true.
2A - Execution - Phase Two
During the 2A phase, one of the following occurs:
• The integer operation begun in the 1A phase completes.
User’s Manual   U11761EJ6V0UM 87

Chapter 4  V5000 Processor Pipeline
R
• Data cache address decode.
• Store data is shifted to the specified byte positions.
• The DTLB begins the data virtual to physical address translation.
1D - Data Fetch - Phase One
During the 1D phase, one of the following occurs:
• The DTLB data address translation completes.
• The JTLB virtual to physical address translation begins.
• Data cache access begins
2D - Data Fetch - Phase Two
• The data cache access completes. Data is shifted down and extended.
• The JTLB address translation completes.
• The data cache tag is checked against the PFN from the DTLB or JTLB
for any data cache access.
1W - Write Back, Phase One
• This phase is used internally by the procesor to resolve all exceptions in
preperation for the register write.
2W - Write Back, Phase Two
• For register-to-register and load instructions, the result is written back to
the register file.
WB - Write Back
For register-to-register instructions, the instruction result is written back to the register
file during the WB stage.  Branch instructions perform no operation during this stage.
Figure 4-2 shows the activities occurring during each ALU pipeline stage, for load,
store, and branch instructions.
88 User’s Manual   U11761EJ6V0UM

Chapter 4  V5000 Processor Pipeline
R
Clock
Phase
1I	2I	1R	2R	1A	2A	1D	2D	1W	2W
ICD ICA
IFetch
ITLBM ITLBR ITC
and RF
Decode IDEC
| ALU | EX1 | EX2 | WB |
| --- | --- | --- | --- |
| DVA | DCAD Load/Store JTLB1 JTLB2 | DCAA | DCLA |
| DTLBMDTLBR | DTC SA DCW Branch BAC | WB |  |
| ICD | Instruction cache address decode | ICA | Instruction cache array access |
| ITLBM | Instruction address translation match | ITLBR | Instruction address translation read |
| ITC | Instruction tag check | RF | Register operand fetch |
| IDEC | Instruction address translation stage 2 | EX1 | Execute operation - phase 1 |
| EX2 | Execute operation - phase two | WB | Write back to register file |
| DVA | Data virtual address calculation | DCAD | Data cache address decode |
| DCAA | Data cache array access | DCLA | Data cache load align |
| JTLB1 | JTLB address translation - phase 1 DTLBM Data address translation match DTLBR Data address translation read | JTLB2 | JTLB address translation - phase 2 |
| DTC | Data tag check | SA | Store align |
| DCW | Data cache write | BAC | Branch address calculation Figure  4-2   CPU Pipeline Activities User’s Manual   U11761EJ6V0UM 89 |

Chapter 4  V5000 Processor Pipeline
R
4.2 Branch Delay
The CPU pipeline has a branch delay of one cycle and a load delay of one cycles.   The
one-cycle branch delay is a result of the branch comparison logic operating during the
1A pipeline stage of the branch. This allows the branch target address calculated in the
previous stage to be used for the instruction access in the following 1I phase.
Figure 4-3 illustrates the branch delay.
One	One	One	One	One
Cycle	Cycle	Cycle	Cycle	Cycle
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
* **
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
Branch
Delay
*    Branch and fall-through address calculated
**   Address selection made
Figure  4-3   CPU Pipeline Branch Delay
4.3 Load Delay
The completion of a load at the end of the 2D pipeline stage produces an operand that
is available for the 1A pipeline phase of the subsequent instruction following the load
delay slot.
Figure 4-4 shows the load delay of two pipeline stages.
90 User’s Manual   U11761EJ6V0UM

Chapter 4  V5000 Processor Pipeline
R
One	One	One	One	One
Cycle	Cycle	Cycle	Cycle	Cycle
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
Load
Delay
Figure  4-4   CPU Pipeline Load Delay
4.4 Interlock and Exception Handling
Smooth pipeline flow is interrupted when cache misses or exceptions occur, or when
data dependencies are detected.  Interruptions handled using hardware, such as cache
misses, are referred to asinterlocks, while those that are handled using software are
called exceptions.
There are two types of interlocks:
• Stalls, which are resolved by halting the pipeline.
• Slips, which require one part of the pipeline to advance while another part
of the pipeline is held static.
At each cycle, exception and interlock conditions are checked for all active
instructions.
Because each exception or interlock condition corresponds to a particular pipeline
stage, a condition can be traced back to the particular instruction in the exception/
interlock stage.  For instance, a Reserved Instruction (RI) exception is raised in the
execution (A) stage.
User’s Manual   U11761EJ6V0UM 91

Chapter 4  V5000 Processor Pipeline
R
Table 4-1   Relationship of Pipeline Stage to Interlock Condition
Pipeline Stage
State
IRADW
Stall	ITM	ICM	DCM
CPE
Slip LDI
MDSt
FCBusy
Exceptions	ITLB	IBE	RI	DBE
IPErr	CUn	NMI
BP Reset
SC DPErr
DTLB OVF
TLBMod FPE
Intr
92 User’s Manual   U11761EJ6V0UM

Chapter 4  V5000 Processor Pipeline
R
Table 4-2   Pipeline Exceptions
Exception Description
ITLB Instruction Translation or Address Exception
Intr External Interrupt
IBE IBus Error
RI Reserved Instruction
BP Breakpoint
SC System Call
CUn Coprocessor Unusable
IPErr Instruction Parity Error
OVF Integer Overflow
FPE             FP             Interrupt
DTLB Data Translation or Address Exception
TLBMod TLB Modified
DBE Data Bus Error
DPErr Data Parity Error
NMI             Non-maskable             Interrupt
Reset            Reset
Table 4-3   Pipeline Interlocks
Interlock Description
ITM Instruction TLB Miss
ICM Instruction Cache Miss
CPE Coprocessor Possible Exception
DCM Data Cache Miss
LDI Load Interlock
MDSt Multiply/Divide Start
FCBsy          FP          Busy
User’s Manual   U11761EJ6V0UM 93

Chapter 4  V5000 Processor Pipeline
R
4.4.1 Exception Conditions
When an exception condition occurs, the relevant instruction and all those that follow
it in the pipeline are cancelled.  Accordingly, any stall conditions and any later
exception conditions that may have referenced this instruction are inhibited; there is no
benefit in servicing stalls for a cancelled instruction. When this instruction reaches the
W stage, three events occur;
• The exception flag causes the instruction to write various CP0 registers
with the exception state,
• The current PC is changed to the appropriate exception vector address,
• The exception bits of earlier pipeline stages are cleared.
This implementation allows all instructions which occurred before the exception to
complete, and all instructions which occurred after the instruction to be aborted. Hence
the value of the EPC is such that execution can be restarted. In addition, all exceptions
are guaranteed to be taken in order. Figure 4-5 illustrates the exception detection
mechanism for a Reserved Instruction (RI) exception.
One	One	One	One	One
Cycle	Cycle	Cycle	Cycle	Cycle
Exception
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
Instructions
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
Aborted
1I 2I   1R  2R  1A  2A  1D  2D  1W 2W
Exception
Vector Address 1I    2I   1R  2R  1A  2A  1D  2D  1W
Figure  4-5   Exception Detection Mechanism
94 User’s Manual   U11761EJ6V0UM

Chapter 4  V5000 Processor Pipeline
R
4.4.2 Stall Conditions
A  stall condition is used to suspend the pipline for conditions detected after the R
pipeline stage. When a stall occurs, the processor resolves the condition and then
restarts the pipeline. Once the interlock is removed, the restart sequence begins two
cycles before the pipeline resumes execution.  The restart sequence reverses the
pipeline overrun by inserting the correct information into the pipeline. Figure 4-6
shows a data cache miss stall.
1	2	3	4
I  R A D WW WWW
I RADD DDDW
IRAA AAADW
IRR RRRADW
1 - Detect cache miss
2 - Start moving dirty cache line data to write buffer
3 - Fetch first doubleword into cache and restart pipeline
4 - Begin loading remainder of cache line into cache when Dcache is idle
Figure  4-6   Servicing a Data Cache Miss
The data cache miss is detected in the D stage of the pipeline. If the cache line to be
replaced is dirty, the W bit is set and data is moved to the internal write buffer in the
next cycle. The squiggly line in Figure 4-6 indicates the memory access. Once the
memory is accessed and the first doubleword of data is returned, the pipeline is
restarted. The remainder of the cache line is returned in subsequent cycles. The dirty
data in the write buffer is written out to memory after the cache line fill operations is
completed.
User’s Manual   U11761EJ6V0UM 95

Chapter 4  V5000 Processor Pipeline
R
4.4.3 Slip Conditions
During the 2R and 1A pipeline stages, internal logic determines whether it is possible
to start the current instruction in this cycle. If all required source operands are
available, as well as all hardware resources needed to complete the operation, then the
instruction is issued. Otherwise, the instruction “slips”. Slipped instructions are retried
on subsequent cycles until they are issued. Pipeline stages D and W advance normally
during slips in an attempt to resolve the conflict. NOP’s are inserted into the bubbles
which are created in the pipeline. Branch -likely instructions, ERET, nor exceptions do
not cause slips.
Figure 4-7 shows how instructions can slip during an instruction cache miss.
Complete
W
Complete
DW
Complete
ADW
Complete
RADW
| IRRRR | RRR | R | A | DW |
| --- | --- | --- | --- | --- |
| 1 | 2 | 2 | 2 | 2 3 |
| IIII | I | I | I | I R A D W 1 - Detect cache miss 2 - Load cache line (4 doublewords) into Icache 3 - Restart pipeline Figure  4-7   Slips During an Instruction Cache Miss 96 User’s Manual   U11761EJ6V0UM |

Chapter 4  V5000 Processor Pipeline
R
Instruction cache misses are detected in the R-stage of the pipeline. Slips are detected
in the A stage. Instruction cache misses never require a writeback operation as writes
are not allowed to the instruction cache. Unlike the data cache, early restart, where the
pipeline is restarted after only a portion of the cache line fill has occurred, is not
implemented for the instruction cache. The requested cache line is loaded into the
instruction cache in its entirety before the pipeline is restarted.
4.5 Write Buffer
The V 5000 processor contains a write buffer which improves the performance of
R
write operations to external memory. All write cycles use the write buffer. The write
buffer holds up to four 64-bit address and data pairs.
On a cache miss requiring a write-back, the entire buffer is used for the write-back data
and allows the processor to proceed in parallel with the memory update. For uncached
and write-through stores, the write buffer decouples the CPU from the write to
memory. If the write buffer is full, additional stores are stalled until there is room for
them in the write buffer.
User’s Manual   U11761EJ6V0UM 97

Chapter 5  Superscalar Issue Mechanism
The V 5000 processor incorporates a simple dual-issue mechanism which allows two
R
instructions to be dispatched per cycle under certain conditions. A FPU ALU operation
can be dispatched along with any other type of instruction, as long as the other
instruction is not another FP ALU operation.
Figure 5-1 shows a simplfied diagram of the dual issue mechanism.
98 User’s Manual   U11761EJ6V0UM

Chapter 5  Superscalar Issue Mechanism
2-deep
Read Integer
buffer
Register File
2
Instr
Cache
instr
Read FP
Register File
I Stage R Stage
| Integer Reg | Integer | Integer ALU |
| --- | --- | --- |
| File Write | Load/Store | Execution |
| FP Register | FP | FP ALU |
| File Write | Load/Store | Execution |
| W Stage | D Stage Figure  5-1   Dual Issue Mechanism I - Stage Two instructions are fetched from the instruction cache and placed in a 2-deep instruction buffer. Issue logic determines the type of instruction and which pipeline the instruction is routed to. Also, the instruction cache tag is checked against the page frame number (PFN) obtained from the ITLB. R - Stage Any required operands are fetched from the appropriate register file, and the decision is made to either proceed or slip the instruction based on any interlock conditions. For branch instruction, the branch address is calculated. A - Stage The appropriate ALU begins the arithmetic, logical, or shift operation. The data virtual address is calculated for any load or store instructions. The appropriate ALU determines whether the branch condition is true. The data cache access is started. User’s Manual   U11761EJ6V0UM 99 | A Stage |

Chapter 5  Superscalar Issue Mechanism
D - Stage
The data cache access is completed. Data is shifted down and extended. Data address
translation in the DTLB completes. The virtual to physical address translation in the
JTLB is performed. The data cache tag is checked against the PFN from the DTLB or
JTLB for any data cache access.
W - Stage
The processor resolves all exceptions. For register-to-register and load instructions, the
result is written back to the appropriate register file.
100 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
The V 5000 processor provides a full-featured memory management unit (MMU)
R
which uses an on-chip translation lookaside buffer (TLB) to translate virtual addresses
into physical addresses.
This chapter describes the processor virtual and physical address spaces, the virtual-
to-physical address translation, the operation of the TLB in making these translations,
and those System Control Coprocessor (CP0) registers that provide the software
interface to the TLB.
User’s Manual   U11761EJ6V0UM 101

Chapter 6  Memory Management Unit
6.1 Translation Lookaside Buffer (TLB)
Mapped virtual addresses are translated into physical addresses using an on-chip
†
TLB.The TLB is a fully associative memory that holds 48 entries, which provide
mapping to 48 odd/even page pairs (96 pages).  When address mapping is indicated,
each TLB entry is checked simultaneously for a match with the virtual address that is
extended with an ASID stored in theEntryHiregister.
The address mapped to a page ranges in size from 4 KB to 16 MB, in multiples of 4—
that is, 4K, 16K, 64K, 256K, 1M, 4M, 16M.
6.1.1 Hits and Misses
If there is a virtual address match, or hit, in the TLB, the physical page number is
extracted from the TLB and concatenated with the offset to form the physical address
(see Figure 6-1).
If no match occurs (TLB miss), an exception is taken and software refills the TLB from
the page table resident in memory.  Software can write over a selected TLB entry or
use a hardware mechanism to write into a random entry.
6.1.2 Multiple Matches
The V 5000 processor does not provide any detection or shutdown mechanism for
R
multiple matches in the TLB.  Unlike earlier designs, multiple matches do not
physically damage the TLB.  Therefore, multiple match detection is not needed. The
result of this condition is undefined, and software is expected to never allow this to
occur.
6.2 Processor Modes
The V 5000 has three processor operating modes, an instruction set mode, and an
R
addressing mode.  All are described in this section.
† There  are  virtual-to-physical  address  translations  that  occur  outside  of  the  TLB.    For  example,
addresses inthe kseg0andkseg1spaces are unmapped translations.  In these spaces the physical
address is 0x000 0000 0 11 VA[28:0].
102 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
6.2.1 Processor Operating Modes
The three operating modes are listed in order of decreasing system privilege:
• Kernel Mode(Highest system privilege):  can access and change any
register.  The innermost core of the operating system runs in kernel mode.
• Supervisor Mode:has fewer privileges and is used for less critical
sections of the operating system.
• User Mode(lowest system privilege):  prevents users from interfering
with one another.
User mode is the processor’s base operating mode.  The processor is forced to Kernel
mode when the processor is handling an error (ERL bit is set) or an exception (EXL
bit is set).
The processor’s operating mode is set by theStatusregister’sKSUfield, together with
theERL, EXL, KX, SX, UXandXXbits.  Table 6-1 lists theStatusregister settings for
the three operating modes, as well as error and exception level settings; the blanks in
the table indicatedon’t cares.
Table 6-1   Processor Modes
Addressing
| XX | KX | SX | UX | KSU | ERL EXL Description Mode | IE | ISA ISA |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 31 | 7 | 6 | 5 | 2 | 2 | 1 | 0 III IV 32-Bit/64-Bit |
| 0 | 10 | 0 | 0 | 0 | 0 | 32 |  |
| 0 | 1 | 10 | 0 | 0 | User mode | 1 | 0 64 |
| 1 | 1 | 10 | 0 | 0 | 1 | 1 | 64 |
| 0 | 01 Supervisor mode | 0 | 0 | 0 | 1 | 32 |  |
| 1 | 01 | 0 | 0 | 1 | 1 | 64 |  |
| 0 | 00 Kernel mode | 0 | 0 | 1 | 1 | 32 |  |
| 1 | 00 | 0 | 0 | 1 | 1 | 64 |  |
| 0 | 0 | 1 | 1 | 1 | 32 Exception level |  |  |
| 1 | 0 | 1 | 1 | 1 | 64 |  |  |
| 0 | 1 | 1 | 1 | 32 Error level |  |  |  |
| 1 | 1 | 1 | 1 | 64 |  |  |  |
| 0 | 0 | 1    Interrupts are enabled User’s Manual   U11761EJ6V0UM 103 |  |  |  |  |  |

Chapter 6  Memory Management Unit
6.2.2 Instruction Set Mode
The processor’sinstruction set modedetermines which instruction set is enabled.  By
default, the processor implements the MIPS IV Instruction Set Architecture (ISA).  For
compatibility with earlier machines, however, it can be limited to the MIPS III ISA or
the MIPS I/II ISAs.
6.2.3 Addressing Modes
The processor’saddressing modedetermines whether it generates 32-bit or 64-bit
memory addresses.
Refer to Table 6-1 for the following addressing mode encodings:
• In Kernel mode theKXbit enables 64-bit addressing; all instructions are
always valid.
• In Supervsor mode, theSXbit enables 64-bit addressing and the MIPS III
instructions.
• In User mode, theUXbit enables 64-bit addressing and the MIPS III
instructions; theXXbit enables the new MIPS IV instructions.
6.3 Address Spaces
This section describes the virtual and physical address spaces and the manner in which
virtual addresses are converted or “translated” into physical addresses in the TLB.
6.3.1 Virtual Address Space
The processor has three address spaces:kernel, supervisor, and user. Each space can
be independently configured to be a 32-bit or 64-bit space by the KX, SX, and UX bits
in the Status register.
• If UX=0 (extended address bit = 0), user addresses are 32 bits wide.  The
31
maximum user process size is 2 GB (2 ).
• If UX=1 (extended address bit = 1), user addresses are 64 bits wide.  The
40
maximum user process size is 1 TB (2 ).
Figure 6-1 shows the translation of a virtual address into a physical address.
104 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
Virtual address
1.  Virtual  address  (VA)  represented  by  the
virtual page number (VPN) is compared
ASID	VPN	Offset
with tag in TLB. The ASID portion of the
VA is held in EnHI Register.
G ASID
2.  If  there  is  a  match,  the  page  frame VPN
number (PFN) representing the upper
TLB
bits  of  the  physical  address  (PA)  is
output from the TLB. Entry
PFN
TLB
3.  The  Offset,  which  does  not  pass  through
the TLB, is then concatenated to the PFN.
PFN Offset
Physical address
Figure  6-1   Overview of a Virtual-to-Physical Address Translation
As shown in Figure 6-1, the virtual address is extended with an 8-bit address space
identifier (ASID), which reduces the frequency of TLB flushing when switching
contexts.  This 8-bit ASID is in the CP0EntryHiregister.  TheGlobalbit (G) is in each
TLB entry.
6.3.2 Physical Address Space
Using a 36-bit address, the processor physical address space encompasses 64 GB.
6.3.3 Virtual-to-Physical Address Translation
Converting a virtual address to a physical address begins by comparing the virtual
address from the processor with the virtual addresses in the TLB; there is a match when
the virtual page number (VPN) of the address is the same as the VPN field of the entry,
and either:
• the Global (G) bit of the TLB entry is set, or
• the ASID field of the virtual address is the same as the ASID field of the
TLB entry.
User’s Manual   U11761EJ6V0UM 105

Chapter 6  Memory Management Unit
This match is referred to as aTLB hit.   If there is no match, a TLB Miss exception is
taken by the processor and software is allowed to refill the TLB from a page table of
virtual/physical addresses in memory.
If there is a virtual address match in the TLB, the physical address is output from the
TLB and concatenated with theOffset, which represents an address within the page
frame space. TheOffsetdoes not pass through the TLB.
The next sections describe the 32-bit and 64-bit address translations.
6.3.4 32-bit Mode Virtual Address Translation
Figure 6-2 shows the virtual-to-physical-address translation of a 32-bit mode address.
• The top portion of Figure 6-2 shows a virtual address with a 12-bit, or 4-
KB, page size, labelledOffset. The remaining 20 bits of the address
represent the VPN, and index the 1M-entry page table.
• The bottom portion of Figure 6-2 shows a virtual address with a 24-bit, or
16-MB, page size, labelledOffset. The remaining 8 bits of the address
represent the VPN, and index the 256-entry page table.
20
Virtual Address with 1M (2 ) 4-KB pages
39	32 31 29 28	20 bits = 1M pages	12 11	0
ASID	VPN	Offset
82012
Virtual-to-physical Offset  passed  unchanged
translation in TLB to physical memory
Bits 31, 30 and 29 of the
TLB
virtual address select
36-bit Physical Address
user, supervisor, or kernel
35 0
address spaces.
PFN Offset
Virtual-to-physical Offset  passed  unchanged
translation in TLB to physical memory
TLB
39	32 31 29 28	24 23	0
ASID	VPN	Offset
88 24
8 bits = 256 pages
8
Virtual Address with 256 (2) 16-MB pages
Figure  6-2   32-bit Mode Virtual Address Translation
106 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
6.3.5 64-bit Mode Virtual Address Translation
Figure 6-3 shows the virtual-to-physical-address translation.  This figure illustrates the
two extremes in the range of possible page sizes: a 4-KB page (12 bits) and a 16-MB
page (24 bits).
• The top portion of Figure 6-3 shows a virtual address with a
12-bit, or 4-KB, page size, labelledOffset.  The remaining 28 bits of the
address represent the VPN, and index the 256M-entry page table.
• The bottom portion of Figure 6-3 shows a virtual address with a 24-bit, or
16-MB, page size, labelledOffset.  The remaining 16 bits of the address
represent the VPN, and index the 64K-entry page table.
28
Virtual Address with 256M (2 ) 4-KB pages
| 71 | 64636261 | 40 39 | 28 bits  = 256M pages | 1211 | 0 |
| --- | --- | --- | --- | --- | --- |
| ASID | 0 or -1 | VPN | Offset |  |  |
| 8 | 24 Offset passed Virtual-to-physical TLB unchanged to translation in TLB physical Bits 62 and 63 of the virtual memory 36-bit Physical Address address select user, supervisor, 35 0 or kernel address spaces. PFN Offset Offset passed Virtual-to-physical unchanged to translation in TLB physical TLB memory | 28 | 12 |  |  |
| 71 | 64636261 | 4039 | 2423 | 0 |  |
| ASID | 0 or -1 | VPN | Offset |  |  |
| 8 | 24 16 bits = 64K pages | 16 | 24 |  |  |
16
Virtual Address with 64K (2 )16-MB pages
Figure  6-3   64-bit Mode Virtual Address Translation
User’s Manual   U11761EJ6V0UM 107

Chapter 6  Memory Management Unit
6.3.6 Address Spaces
The processor has three address spaces.
• User address space
• Supervisor address space
• Kernel address space
Each space can be independently configured as either 32- or 64-bit.
6.3.7 User Address Space
In User address space, a single, uniform virtual address space—labelled User segment
(useg), is available; its size is:
31
•	2 GB (2	bytes) if UX = 0 (useg)
40
•	1 TB (2	bytes) if UX = 1 (xuseg)
Figure 6-4 shows the range of User virtual address space.
32-bit 64-bit
0x  FFFF  FFFF 0x   FFFF  FFFF  FFFF  FFFF
Address Address
Error Error
0x  8000  0000
0x  0000  0100  0000  0000
2 GB 1 TB
useg xuseg
Mapped Mapped
0x  0000  0000 0x  0000  0000  0000  0000
Figure  6-4   UserVirtual Address Space as Viewed from User Mode
User space can be accessed from user, supervisor, and kernel modes.
The User segment starts at address 0 and the current active user process resides in
either useg (in 32-bit mode) or xuseg (in 64-bit mode). The TLB identically maps all
references to useg/xuseg from all modes, and controls cache accessibility.
108 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
The processor operates in User mode when theStatusregister contains the following
bit-values:
• KSUbits = 10
2
• EXL= 0
• ERL= 0
TheUXbit in theStatusregister selects between 32- or 64-bit User address spaces as
follows:
• whenUX= 0, 32-bitusegspace is selected.
• whenUX= 1, 64-bitxusegspace is selected.
Table 6-2 lists the characteristics of the two user address spaces,usegandxuseg.
Table 6-2   32-bit and 64-bit User Address Space Segments
Status Register
Address Bit Segment
| Bit Values | Address Range Values Name KSU  EXL  ERL   UX 0x0000 0000 32-bit 2 GB | Segment Size |
| --- | --- | --- |
| 00useg | through | 31 |
| A(31) = 0 | (2 | bytes) 0x7FFF FFFF any 0x0000 0000 0000 0000 64-bit 1 TB |
| 01xuseg | through A(63:40) = 0 (2 bytes) 0x0000 00FF FFFF FFFF (1) 32-bit User Space (useg) In 32-bit User space, whenUX= 0 in theStatusregister, all valid addresses have their most-significant bit cleared to 0; any attempt to reference an address with the most- significant bit set while in User mode causes an Address Error exception. The system maps all references tousegthrough the TLB, and bit settings within the TLB entry for the page determine the cacheability of a reference. TLB misses on addresses in 32-bit User space (useg) use the TLB refill vector. User’s Manual   U11761EJ6V0UM 109 | 40 |

Chapter 6  Memory Management Unit
(2) 64-bit User Space (xuseg)
In 64-bit User space, whenUX=1 in theStatusregister, addressing is extended to 64-
40
bits.  When UX=1, the processor provides a single, uniform address space of 2 bytes,
labelledxuseg.
All valid User mode virtual addresses have bits 63:40 equal to 0; an attempt to
reference an address with bits 63:40 not equal to 0 causes an Address Error exception.
TLB misses on addresses in 64-bit User (xuseg) space use the XTLB refill vector.
6.3.8 Supervisor Space
Supervisor address space is designed for layered operating systems in which a true
kernel runs in Kernel mode, and the rest of the operating system runs in Supervisor
mode.  The Supervisor address space provides code and data addresses for supervisor
mode.
Supervisor space can be accessed from supervisor mode and kernel mode.
The processor operates in Supervisor mode when theStatusregister contains the
following bit-values:
• KSU= 01
2
• EXL= 0
• ERL= 0
TheSXbit in theStatusregister select between 32- or 64-bit Supervisor space
addressing:
• whenSX= 0, 32-bit supervisor space is selected and TLB misses on
supervisor space addresses are handled by the 32-bit TLB refill exception
handler
• whenSX= 1, 64-bit supervisor space is selected and TLB misses  on
supervisor space addresses are handled by the 64-bit XTLB refill
exception handler. Figure 6-5 shows Supervisor address mapping.  Table
6-3 lists the characteristics of the supervisor space segments; descriptions
of the address spaces follow.
110 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
32-bit 64-bit
0x  FFFF  FFFF
0x   FFFF  FFFF  FFFF  FFFF
Address Address
| 0x  E000  0000 | error 0x   FFFF  FFFF  E000   0000 0.5 GB sseg 0.5 GB Mapped csseg 0x  C000  0000 Mapped 0x   FFFF  FFFF  C000   0000 Address Address error 0x  A000  0000 error 0x  4000  0100  0000  0000 Address error 1 TB 0x  8000  0000 xsseg Mapped 0x  4000  0000  0000  0000 Address error 2 GB 0x  0000  0100  0000  0000 suseg Mapped 1 TB xsuseg Mapped 0x  0000  0000 0x  0000  0000  0000  0000 Figure  6-5   User and Supervisor Address Spaces as Viewed from Supervisor Mode Table 6-3   Supervisor Mode Addressing Segment Segment A(63:62) Address Range Name Size SX  UX 0x0000 0000 0000 0000 2 GB | error |
| --- | --- | --- |
| 00 | X0suseg | through 31 |
2
(2 bytes)
0x0000 0000 7FFF FFFF
0x0000 0000 0000 0000
1 TB
00	X1xsuseg	through	40
2
(2 bytes)
0x0000 00FF FFFF FFFF
0x4000 0000 0000 0000
1 TB
01	1Xxsseg	through	40
2
(2 bytes)
0x4000 00FF FFFF FFFF
sseg 0xFFFF FFFF C000 0000
512 MB
11	XXor	through	29
2
(2 bytes)
csseg 0xFFFF FFFF DFFF FFFF
User’s Manual   U11761EJ6V0UM 111

Chapter 6  Memory Management Unit
(1) 32-bit Supervisor, User Space (suseg)
In Supervisor space, whenSX= 0 in theStatusregister and the most-significant bit of
the 32-bit virtual address is set to 0, thesusegvirtual address space is selected; it covers
31
the full 2 bytes (2 GB) of the current user address space.  The virtual address is
extended with the contents of the 8-bit ASID field to form a unique virtual address.
This mapped space starts at virtual address 0x0000 0000 and runs through 0x7FFF
FFFF.
(2) 32-bit Supervisor, Supervisor Space (sseg)
In Supervisor space, whenSX= 0 in theStatusregister and the three most-significant
bits of the 32-bit virtual address are 110, thessegvirtual address space is selected; it
2
29
covers 2 -bytes (512 MB) of the current supervisor address space.The virtual address
is extended with the contents of the 8-bit ASID field to form a unique virtual address.
This mapped space begins at virtual address 0xC000 0000 and runs through 0xDFFF
FFFF.
(3) 64-bit Supervisor, User Space (xsuseg)
In Supervisor space, whenSX= 1 in theStatusregister and bits 63:62 of the virtual
40
address are set to 00, thexsusegvirtual address space is selected; it covers the full 2
2
bytes (1 TB) of the current user address space.  The virtual address is extended with
the contents of the 8-bit ASID field to form a unique virtual address.
This mapped space starts at virtual address 0x0000 0000 0000 0000 and runs through
0x0000 00FF FFFF FFFF.
(4) 64-bit Supervisor, Current Supervisor Space (xsseg)
In Supervisor space, whenSX= 1 in theStatusregister and bits 63:62 of the virtual
address are set to 01, thexssegcurrent supervisor virtual address space is selected.
2
The virtual address is extended with the contents of the 8-bit ASID field to form a
unique virtual address.
This mapped space begins at virtual address 0x4000 0000 0000 0000 and runs through
0x4000 00FF FFFF FFFF.
112 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
(5) 64-bit Supervisor, Separate Supervisor Space (csseg)
In Supervisor space, whenSX= 1 in theStatusregister and bits 63:62 of the virtual
address are set to 11, thecssegseparate supervisor virtual address space is selected.
2
Addressing of thecssegis compatible with addressingssegin 32-bit mode.The virtual
address is extended with the contents of the 8-bit ASID field to form a unique virtual
address.
This mapped space begins at virtual address 0xFFFF FFFF C000 0000 and runs
through 0xFFFF FFFF DFFF FFFF.
6.3.9 Kernel Space
The processor operates in Kernel mode when theStatusregister contains one of the
following values:
• KSU= 00
2
• EXL= 1
• ERL= 1
TheKXbit in theStatusregister selects between 32- or 64-bit Kernel space addressing:
• whenKX= 0, 32-bit kernel space is selected.
• whenKX= 1, 64-bit kernel space is selected.
The processor enters Kernel mode whenever an exception is detected and it remains
there until an Exception Return (ERET) instruction is executed or EXL is cleared.  The
ERET instruction restores the processor to the address space existing prior to the
exception.
Kernel virtual address space is divided into regions differentiated by the high-order
bits of the virtual address, as shown in Figure 6-6.  Table 6-4 lists the characteristics
of the  kernel mode segments.
User’s Manual   U11761EJ6V0UM 113

Chapter 6  Memory Management Unit
64-bit
32-bit
0x   FFFF  FFFF  FFFF  FFFF
0.5 GB
0x FFFF FFFF
ckseg3
Mapped
0.5 GB 0x   FFFF  FFFF  E0000000
kseg3
Mapped 0.5 GB
0x E000 0000 cksseg
Mapped
0x   FFFF  FFFF  C0000000
0.5 GB 0.5 GB
ksseg
Unmapped ckseg1
Mapped
Uncached
0x   FFFF  FFFF  A000  0000
0x C000 0000
0.5 GB
0.5 GB
Unmapped ckseg0
Unmapped	0x   FFFF  FFFF  80000000	Cached
kseg1
Uncached
Address
0x A000 0000
0x  C000  00FF  8000  0000 error
0.5 GB
Unmapped	kseg0	xkseg
Mapped
Cached 0x  C000  0000  0000  0000
0x 8000 0000
Unmapped xkphys
0x  8000  0000  0000  0000
Address
0x  4000  0100  0000  0000 error
2 GB 1 TB
xksseg
kuseg Mapped
Mapped 0x  4000  0000  0000  0000
Address
error
0x  0000  0100  0000  0000
1 TB
xkuseg
Mapped
0x  0000  0000  0000  0000
0x 0000 0000
Figure  6-6   User, Supervisor, and Kernel Address Spaces as Viewed from Kernel Mode
114 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
Table 6-4   Kernel Mode Addressing
Segment Segment
A(63:62) Address Range
Name Size
KX	SX	UX
0x0000 0000 0000 0000
2 GB
00	XX 0kuseg	through	31
2
(2 bytes)
0x0000 0000 7FFF FFFF
0x0000 0000 0000 0000
1 TB
00	XX 1xkuseg	through	40
2
(2 bytes)
0x0000 00FF FFFF FFFF
0x4000 0000 0000 0000
1 TB
01	X1Xxksseg	through	40
2
(2 bytes)
0x4000 00FF FFFF FFFF
0x8000 0000 0000 0000
8×
through
10	1XXxkphys	64 GB
2
0x8000 000F FFFF FFFF
36
(2 bytes)
etc.
0xC000 0000 0000 0000	40	31
(2 –2 )
11	1XXxkseg	through
2
bytes
0xC000 00FF 7FFF FFFF
0xFFFF FFFF 8000 0000
512 MB
11	XXXkseg0	through	29
2
(2 bytes)
0xFFFF FFFF 9FFF FFFF
0xFFFF FFFF A000 0000
512 MB
11	XXXkseg1	through	29
2
(2 bytes)
0xFFFF FFFF BFFF FFFF
0xFFFF FFFF C000 0000
512 MB
11	XXXksseg	through	29
2
(2 bytes)
0xFFFF FFFF DFFF FFFF
0xFFFF FFFF E000 0000
512 MB
11	XXXkseg3	through	29
2
(2 bytes)
0xFFFF FFFF FFFF FFFF
(1) 32-bit Kernel, User Space (kuseg)
In Kernel space, whenKX= 0 in theStatusregister, and the most-significant bit of the
virtual address, A31, is cleared, the 32-bitkusegvirtual address space is selected; it
31
covers the full 2 bytes (2 GB) of the current user address space.The virtual address
is extended with the contents of the 8-bit ASID field to form a unique virtual address.
User’s Manual   U11761EJ6V0UM 115

Chapter 6  Memory Management Unit
(2) 32-bit Kernel, Kernel Space 0 (kseg0)
In Kernel space, whenKX= 0 in theStatusregister and the most-significant three bits
of the virtual address are 100, 32-bitkseg0virtual address space is selected; it is the
2
29
2 -byte (512-MB) kernel physical space.  References tokseg0are not mapped
through the TLB; the physical address selected is defined by subtracting 0x8000 0000
from the virtual address.   TheK0field of theConfigregister, described in this chapter,
controls cacheability and coherency.
(3) 32-bit Kernel, Kernel Space 1 (kseg1)
In Kernel mode, whenKX= 0 in theStatusregister and the most-significant three bits
of the 32-bit virtual address are 101, 32-bitkseg1virtual address space is selected; it
2
29
is the 2 -byte (512-MB) kernel physical space.
References tokseg1are not mapped through the TLB; the physical address selected is
defined by subtracting 0xA000 0000 from the virtual address.
Caches are disabled for accesses to these addresses, and physical memory (or memory-
mapped I/O device registers) are accessed directly.
(4) 32-bit Kernel, Supervisor Space (ksseg)
In Kernel space, whenKX= 0 in theStatusregister and the most-significant three bits
of the 32-bit virtual address are 110, thekssegvirtual address space is selected; it is
2
29
the current 2 -byte (512-MB) supervisor virtual space.The virtual address is
extended with the contents of the 8-bit ASID field to form a unique virtual address.
(5) 32-bit Kernel, Kernel Space 3 (kseg3)
In Kernel space, whenKX= 0 in theStatusregister and the most-significant three bits
of the 32-bit virtual address are 111, thekseg3virtual address space is selected; it is
2
29
the current 2 -byte (512-MB) kernel virtual space.The virtual address is extended
with the contents of the 8-bit ASID field to form a unique virtual address.
116 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
(6) 64-bit Kernel, User Space (xkuseg)
In Kernel space, whenKX= 1 in theStatusregister and bits 63:62 of the 64-bit virtual
address are 00, thexkusegvirtual address space is selected; it covers the current user
2
address space.The virtual address is extended with the contents of the 8-bit ASID field
to form a unique virtual address.
31
When ERL = 1 in theStatusregister, the user address region becomes a 2 -byte
unmapped (that is, mapped directly to physical addresses) uncached address space.
(7) 64-bit Kernel, Current Supervisor Space (xksseg)
In Kernel space, whenKX= 1 in theStatusregister and bits 63:62 of the 64-bit virtual
address are 01, thexkssegvirtual address space is selected; it is the current supervisor
2
virtual space.The virtual address is extended with the contents of the 8-bit ASID field
to form a unique virtual address.
(8) 64-bit Kernel, Physical Spaces (xkphys)
In Kernel space, whenKX= 1 in theStatusregister and bits 63:62 of the 64-bit virtual
36
address are 10, thexkphysvirtual address space is selected; it is a set of eight 2 -byte
2
kernel physical spaces.Accesses with address bits 58:36 not equal to 0 cause an
address error.
References to this space are not mapped; the physical address selected is taken from
bits 35:0 of the virtual address.  Bits 61:59 of the virtual address specify the
cacheability and coherency attributes, as shown in Table 6-5.
Table 6-5   Cacheability and Coherency Attributes
| Value (61:59) | Cacheability and Coherency Attributes Cacheable, noncoherent, write-through, no 0 0x8000  0000 0000 0000 write allocate Cacheable, noncoherent, write-through, write 1 0x8800  0000 0000 0000 allocate | Starting Address |
| --- | --- | --- |
| 2 | Uncached | 0x9000  0000 0000 0000 |
| 3 | Cacheable, noncoherent | 0x9800  0000 0000 0000 |
| 4-7 | Reserved | 0xA000 0000 0000 0000 User’s Manual   U11761EJ6V0UM 117 |

Chapter 6  Memory Management Unit
(9) 64-bit Kernel, Kernel Space (xkseg)
In Kernel space, whenKX= 1 in theStatusregister and bits 63:62 of the 64-bit virtual
address are 11, the address space selected is one of the following:
2
• kernel virtual space,xkseg, the current kernel virtual space;the virtual
address is extended with the contents of the 8-bit ASID field to form a
unique virtual address
• one of the four 32-bit kernel compatibility spaces, as described in the next
section.
(10)    64-bit Kernel, Compatibility Spaces
In Kernel space, whenKX= 1 in theStatusregister, bits 63:62 of the 64-bit virtual
address are 11, and bits 61:31 of the virtual address equal –1.  The lower two
2
bytes of address, as shown in Figure 6-6, select one of the following 512-MB
compatibility spaces.
• ckseg0.  This 64-bit virtual address space is an unmapped region,
compatible with the 32-bit address modelkseg0.  TheK0field of the
Configregister controls cacheability and coherency.
• ckseg1.  This 64-bit virtual address space is an unmapped and uncached
region, compatible with the 32-bit address modelkseg1.
• cksseg.  This 64-bit virtual address space is the current supervisor virtual
space, compatible with the 32-bit address modelksseg.
• ckseg3.  This 64-bit virtual address space is kernel virtual space,
compatible with the 32-bit address modelkseg3.
6.4 System Control Coprocessor
The System Control Coprocessor (CP0) is implemented as an integral part of the CPU,
and supports memory management, address translation, exception handling, and other
privileged operations.  CP0 contains the registers shown in Figure 6-7 plus a 48-entry
TLB.  The sections that follow describe how the processor uses the memory
management-related registers.
Each CP0 register has a unique number that identifies it; this number is referred to as
theregister number.  For instance, thePage Maskregister is register number 5.
118 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
EntryLo0 Context
Index
BadVAddr
EntryLo0
2* 0*
EntryHi	2*	Index	4*	8*
EntryHi
10* EntryLo1
3*	Random	Count	Compare
Random
1* 9*
11*
47
Page Mask
Status Cause
Page Mask
| 5* | 12* | 13* |
| --- | --- | --- |
| TLB | Wired | EPC XContext Wired 6* 14* 20* PRId ECC CacheErr |
| 15* | 26* (“Safe” entries) (See Random Register, Config ErrorEPC contents of TLB Wired) 16* 30* 127 0 | 27* |
0
TagLo TagHi
LLAddr
17*	28*	29*
Used with exception
Used with memory
processing. See
management system.
Chapter 7 for details.
*Register number
Figure  6-7   CP0 Registers and the TLB
6.4.1 Format of a TLB Entry
Figure 6-8 shows the TLB entry formats for both 32- and 64-bit modes. Each field of
an entry has a corresponding field in theEntryHi,EntryLo0,EntryLo1, orPageMask
registers.
User’s Manual   U11761EJ6V0UM 119

Chapter 6  Memory Management Unit
32-bit Mode
| 127 | 121120 | 109108 | 96 |
| --- | --- | --- | --- |
| 0 | MASK | 0 |  |
| 7 | 12 | 13 |  |
| 95 | 777675 7271 | 64 |  |
| VPN2 | G | 0 | ASID 128-bit TLB entry |
| 19 | 1 in 32-bit mode of | 4 | 8 |
| VR5000 processor | 6362 61 | 3837 | 35343332 |
| 0 | PFN | C | DV0 |
| 2 | 24 | 3111 3130 29 65 3210 |  |
| 0 | PFN | C | DV0 |
| 2 | 24 | 3111 64-bit Mode |  |
| 255 | 217 216 | 205204 | 192 |
| 0 | MASK | 0 |  |
| 39 | 12 | 13 |  |
| 191190 189 | 168167 | 141140139136 135 | 128 |
| R | 0 | VPN2 | G 0 ASID 256-bit TLB entry |
| 2 | 22 | 27 | 14 8 in 64-bit mode of |
| VR5000 processor | 127 | 94  93 | 7069 67666564 |
| 0 | PFN | C | DV0 |
| 34 | 24 | 3111 |  |
| 63 | 30   29 | 653210 |  |
| 0 | PFN | C | DV0 |
| 34 | 24 | 3111 Figure  6-8   Format of a TLB Entry The format of theEntryHi,EntryLo0,EntryLo1, andPageMaskregisters are nearly the same as the TLB entry.  The one exception is theGlobalfield (Gbit), which is used in the TLB, but is reserved in theEntryHiregister.  Figure 6-9 and Figure 6-10 describe the TLB entry fields shown in Figure 6-8. 120 User’s Manual   U11761EJ6V0UM |  |

Chapter 6  Memory Management Unit
PageMask Register
31	25  24	13  12	0
00MASK
| 7 | 12 Mask..... Page comparison mask. 0........... Reserved. Must be written as zeroes, and returns zeroes when read. EntryHi Register | 13 |
| --- | --- | --- |
| 31 | 13 12 32-bit | 87 0 |
| VPN2 | 0 | ASID Mode |
| 19 | 5 | 8 |
| 63 62  61 | 40   39 | 13 12 87 0 64-bit |
| R | FILL | VPN2 0 ASID Mode |
| 2 | 22 | 27 5 8 VPN2... Virtual page number divided by two (maps to two pages). ASID.... Address space ID field.  An 8-bit field that lets multiple processes share the TLB; each process has a distinct mapping of otherwise identical virtual page numbers. R.......... Region. (00→user, 01→supervisor, 11→kernel) used to match vAddr 63...62 Fill........ Reserved.  0 on read; ignored on write. 0........... Reserved. Must be written as zeroes, and returns zeroes when read. Figure  6-9   Fields of the PageMask and EntryHi Registers User’s Manual   U11761EJ6V0UM 121 |

Chapter 6  Memory Management Unit
EntryLo0 and EntryLo1 Registers
| 31 | 30  29 32-bit | 65 | 3 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- |
| 0 | PFN | CVDG Mode |  |  |  |
| 2 | 24 | 3111 |  |  |  |
| 31 | 30  29 32-bit | 653210 |  |  |  |
| Mode | 0 | PFN | CVD | G |  |
| 2 | 24 | 3111 |  |  |  |
| 63 | 30  29 64-bit | 65 | 3 2 | 1 | 0 |
| 0 | PFN | CVDG Mode |  |  |  |
| 34 | 24 | 3111 |  |  |  |
| 63 | 30  29 64-bit | 653210 |  |  |  |
| 0 | PFN Mode | CVD | G |  |  |
| 34 | 24 | 3111 PFN...... Page frame number; the upper bits of the physical address. C.......... Specifies the TLB page coherency attribute; see Table 6-6. D.......... Dirty.  If this bit is set, the page is marked as dirty and, therefore, writable.  This bit is actually a write-protect bit that software can use to prevent alteration of data. V.......... Valid.  If this bit is set, it indicates that the TLB entry is valid; otherwise, a TLBL or TLBS miss occurs. G.......... Global. If this bit is set in both Lo0 and Lo1, then the processor ignores the ASID during TLB lookup. 0........... Reserved. Must be written as zeroes, and returns zeroes when read. Figure  6-10   Fields of the EntryLo0 and EntryLo1 Registers 122 User’s Manual   U11761EJ6V0UM |  |  |  |

Chapter 6  Memory Management Unit
The TLB page coherency attribute (C) bits specify whether references to the page
should be cached; if cached, the algorithm selects between several coherency
attributes.  Table 6-6 shows the coherency attributes selected by theCbits.
Table 6-6   TLB Page Coherency (C) Bit Values
C(5:3) Value Page Coherency Attribute
0 Cacheable, noncoherent, write-through, no write allocate
1 Cacheable, noncoherent, write-through, write allocate
2 Uncached
3 Cacheable noncoherent (noncoherent)
4 Reserved
5 Reserved
6 Reserved
7 Reserved
6.5 CP0 Registers
The following sections describe the CP0 registers that are assigned specifically as a
software interface with memory management (each register is followed by its register
number in parentheses).
• Indexregister (CP0 register number 0)
• Randomregister (1)
• EntryLo0(2) andEntryLo1(3) registers
• PageMaskregister (5)
• Wiredregister (6)
• EntryHiregister (10)
• PRIdregister (15)
• Configregister (16)
• LLAddrregister (17)
• TagLo(28) andTagHi(29) registers
User’s Manual   U11761EJ6V0UM 123

Chapter 6  Memory Management Unit
6.5.1 Index Register (0)
TheIndexregister is a 32-bit, read/write register containing six bits to index an entry
in the TLB.  The high-order bit of the register shows the success or failure of a TLB
Probe (TLBP)instruction.
TheIndexregister also specifies the TLB entry affected by TLB Read (TLBR)or TLB
Write Index (TLBWI)instructions.
Figure 6-11 shows the format of theIndexregister; Table 6-7 describes theIndex
register fields.
Index Register
31 30	6   5	0
0
P Index
1	25	6
Figure  6-11   Index Register
Table 6-7   Index Register Field Descriptions
Field Description
Probe failure.  Set to 1 when the previous TLBProbe (TLBP)
P
instruction was unsuccessful.
Index to the TLB entry affected by the TLBRead and
Index
TLBWrite instructions
Reserved.   Must be written as zeroes, and returns zeroes when
0
read.
124 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
6.5.2 Random Register (1)
TheRandomregister is a read-only register of which six bits index an entry in the TLB.
This register decrements as each instruction executes, and its values range between an
upper and a lower bound, as follows:
• A lower bound is set by the number of TLB entries reserved for exclusive
use by the operating system (the contents of theWiredregister).
• An upper bound is set by the total number of TLB entries (47 maximum).
TheRandomregister specifies the entry in the TLB that is affected by the TLB Write
Random instruction.  The register does not need to be read for this purpose; however,
the register is readable to verify proper operation of the processor.
To simplify testing, theRandomregister is set to the value of the upper bound upon
system reset.  This register is also set to the upper bound when theWiredregister is
written.
Figure 6-12 shows the format of theRandomregister.  Table 6-8 describes theRandom
register fields.
Random Register
31	65	0
0
Random
26 6
Figure  6-12   Random Register
Table 6-8   Random Register Field Descriptions
Field Description
Random TLB Random index
Reserved.  Must be written as zeroes, and returns zeroes when
0
read.
User’s Manual   U11761EJ6V0UM 125

Chapter 6  Memory Management Unit
6.5.3 EntryLo0 (2), and EntryLo1 (3) Registers
TheEntryLoregister consists of two registers that have identical formats:
• EntryLo0is used for even virtual pages.
• EntryLo1is used for odd virtual pages.
TheEntryLo0andEntryLo1registers are read/write registers.   They hold the physical
page frame number (PFN) of the TLB entry for even and odd pages, respectively, when
performing TLB read and write operations. Figure 6-10 shows the format of these
registers.
6.5.4 PageMask Register (5)
ThePageMaskregister is a read/write register used for reading from or writing to the
TLB; it holds a comparison mask that sets the variable page size for each TLB entry.
TLB read and write operations use this register as either a source or a destination; when
virtual addresses are presented for translation into physical address, the corresponding
bits in the TLB identify which virtual address bits among bits 24:13 are used in the
comparison.  When theMaskfield is not one of the values shown in Table 6-9, the
operation of the TLB is undefined.
Table 6-9   Mask Field Values for Page Sizes
Bit
Page Size
24	23	22	21	20	19	18	17	16	15	14	13
4 KB 000000000000
16 KB 000000000011
64 KB 000000001111
256 KB 000000111111
1 MB 000011111111
4 MB 001111111111
16 MB 111111111111
126 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
6.5.5 Wired Register (6)
TheWiredregister is a read/write register that specifies the boundary between the
wiredandrandomentries of the TLB as shown in Figure 6-13.  Wired entries are fixed,
nonreplaceable entries, which cannot be overwritten by a TLB write operation.
Random entries can be overwritten.
TLB
47
Range of Random entries
Wired
Register
Range of Wired entries
0
Figure  6-13   Wired Register Boundary
TheWiredregister is set to 0 upon system reset.  Writing this register also sets the
Randomregister to the value of its upper bound (seeRandomregister, above).  Figure
6-14 shows the format of theWiredregister;  Table 6-10 describes the register fields.
Wired Register
31	65	0
0
Wired
26 6
Figure  6-14   Wired Register
Table 6-10   Wired Register Field Descriptions
Field Description
Wired TLB Wired boundary
Reserved.  Must be written as zeroes, and returns zeroes
0
when read.
User’s Manual   U11761EJ6V0UM 127

Chapter 6  Memory Management Unit
6.5.6 EntryHi Register (10)
TheEntryHiregister holds the high-order bits of a TLB entry for TLB read and write
operations.
TheEntryHiregister is accessed by the TLB Probe, TLB Write Random, TLB Write
Indexed, and TLB Read Indexed instructions.
When either a TLB refill, TLB invalid, or TLB modified exception occurs, theEntryHi
register is loaded with the virtual page number (VPN2) and the ASID of the virtual
address that did not have a matching TLB entry.
6.5.7 Processor Revision Identifier (PRId) Register (15)
The 32-bit, read-onlyProcessor Revision Identifier(PRId) register contains
information identifying the implementation and revision level of the CPU and CP0.
Figure 6-15 shows the format of thePRIdregister; Table 6-11 describes thePRId
register fields.
PRId Register
31                                                                                                                 016 15 87
0	Imp	Rev
16 88
Figure  6-15   Processor Revision Identifier Register Format
Table 6-11   PRId Register Fields
Field Description
Imp Implementation number
Rev Revision number
Reserved.  Must be written as zeroes, and returns zeroes when
0
read.
128 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
The low-order byte (bits 7:0) of thePRIdregister is interpreted as a revision number,
and the high-order byte (bits 15:8) is interpreted as an implementation number. The
implementation number of the V 5000 processor is 0x23.  The content of the high-
R
order halfword (bits 31:16) of the register are reserved.
The revision number is stored as a value in the formy.x, whereyis a major revision
number in bits 7:4 andxis a minor revision number in bits 3:0.
The revision number can distinguish some chip revisions, however there is no
guarantee that changes to the chip will necessarily be reflected in thePRIdregister, or
that changes to the revision number necessarily reflect real chip changes.  For this
reason, these values are not listed and software should not rely on the revision number
in thePRIdregister to characterize the chip.
6.5.8 Config Register (16)
TheConfigregister specifies various configuration options which can be selected.
Some configuration options, as defined byConfigbits 31:13,11:3 are set by the
hardware during reset and are included in theConfigregister as read-only status bits
for the software to access.  Other configuration options are read/write (as indicated by
Configregister bits 12 and 3:0) and controlled by software; on reset these fields are
undefined.
Certain configurations have restrictions.  TheConfigregister should be initialized by
software before caches are used.  Caches should be written back to memory before line
sizes are changed, and caches should be reinitialized after any change is made.
Figure 6-16 shows the format of theConfigregister; Table 6-12 describes theConfig
register fields.
User’s Manual   U11761EJ6V0UM 129

Chapter 6  Memory Management Unit
Config Register
| 31 30   28  27242322 212019 1817161514131211 | 968 | 5342  0 |
| --- | --- | --- |
| 0 | EC | EP SB SS EW SC1 BEEMEBSE IC DC IBDB0 K0 |
| 13 | 4 | 211 211 1 1131 3 1 1 1 3 Figure  6-16   Config Register Format Table 6-12   Config Register Fields Field Description System clock ratio: 0→processor clock frequency divided by 2 1→processor clock frequency divided by 3 2→processor clock frequency divided by 4 EC 3→processor clock frequency divided by 5 4→processor clock frequency divided by 6 5→processor clock frequency divided by 7 6→processor clock frequency divided by 8 7→Reserved Transmit data pattern (pattern for write-back data): 0→D Doubleword every cycle 1→DDxDDx 2 Doublewords every 3 cycles 2→DDxxDDxx 2 Doublewords every 4 cycles 3→DxDxDxDx 2 Doublewords every 4 cycles |
EP
4→DDxxxDDxxx 2 Doublewords every 5 cycles
5→DDxxxxDDxxxx 2 Doublewords every 6 cycles
6→DxxDxxDxxDxx 2 Doublewords every 6 cycles
7→DDxxxxxxDDxxxxxx 2 Doublewords every 8 cycles
8→DxxxDxxxDxxxDxxx 2 Doublewords every 8 cycles
Secondary Cache block size.  On the V 5000 this is set to 8 words.
R
SB 1→8 words
00, 10, 11→Reserved
Secondary Cache Size
00→512 KB
SS 01→1 MB
10→2 MB
11→None
SysAD bus width.  On the V 5000 this is set to 64-bit.
R
EW 00→64-bit
01, 10, 11→Reserved
130 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
Field Description
Secondary Cache present.
SC 0→Secondary cache present
1→Secondary cache not present
Big Endian Mode:
BE 0→Little Endian
1→Big Endian
ECC mode enable.  On the V 5000 this must be set to parity.
R
EM 0→ECC mode
1→Parity mode
Block ordering.   On the V 5000 this must be set to sub-block.
R
EB 0→Sequential
1→Sub-block
Secondary Cache Enable (software writeable)
SE 0→Disabled
1→Enabled
12+IC
Primary I-cache Size (I-cache size = 2 bytes).  In the V 5000 processor,
R
IC
this must be set to 32 KB.
12+DC
Primary D-cache Size (D-cache size = 2 bytes).  In the V 5000 processor,
R
DC
this must be set to 32 KB.
Primary I-cache line size. In the V 5000 processor, this must be set to 32 bytes.
R
IB 0→16 bytes
1→32 bytes
Primary D-cache line size.  In the V 5000 processor, this must be set to 32 bytes.
R
DB 0→16 bytes
1→32 bytes
kseg0coherency algorithm (seeEntryLo0andEntryLo1registers and theCfield
K0
of Table 6-6) (software writeable)
User’s Manual   U11761EJ6V0UM 131

Chapter 6  Memory Management Unit
6.5.9 Load Linked Address (LLAddr) Register (17)
The read/writeLoad Linked Address(LLAddr)register contains the physical address
read by the most recent Load Linked instruction.
This register is for diagnostic purposes only, and serves no function during normal
operation.
Figure 6-17 shows the format of theLLAddrregister;PAddrrepresents bits of the
physical address, PA(35:4).
LLAddr Register
31 0
PAddr(35:4)
32
Figure  6-17   LLAddr Register Format
6.5.10 Cache Tag Registers [TagLo (28) and TagHi (29)]
TheTagLoandTagHiregisters are 32-bit read/write registers that hold either the
primary cache tag and parity, or the secondary cache tag and ECC during cache
initialization, cache diagnostics, or cache error processing.  TheTagregisters are
written by the CACHE and MTC0 instructions.
ThePandECCfields of these registers are ignored on Index Store Tag operations.
Parity and ECC are computed by the store operation.
Figure 6-18 shows the format of these registers for primary cache operations.  Figure
6-19 shows the format of these registers for secondary cache operations.
Table 6-13 lists the field definitions of theTagLoandTagHiregisters.
132 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
| 31 | 87 | 65 | 1 | 0 |
| --- | --- | --- | --- | --- |
| TagLo | PTagLo | PState | Undefined | P |
| 24 | 2 31 0 TagHi Undefined | 5 | 1 |  |
32
Figure  6-18   TagLo and TagHi Register (P-cache) Formats
| 31 | 151413 12 | 10  9 | 0 |
| --- | --- | --- | --- |
| TagLo | STagLo | 0 | SState 0 |
| 17 | 2 | 3 | 10 31 0 TagHi Undefined |
32
Figure  6-19   TagLo and TagHi Register (S-cache) Formats
User’s Manual   U11761EJ6V0UM 133

Chapter 6  Memory Management Unit
Table 6-13   Cache Tag Register Fields
Field Description
PTagLo Specifies the physical address bits 35:12
Specifies the primary cache state
0→Invalid
PState 1→Reserved
2→Reserved
3→Valid
P Specifies the primary tag even parity bit
STagLo Specifies the physical address bits 35:19
Specifies the secondary cache state
0→Invalid
1→Reserved
2→Reserved
SState 3→Reserved
4→Valid
5→Reserved
6→Reserved
7→Reserved
0 Reserved.  Must be written as zeroes, and returns zeroes when read.
Undefined These fields should not be used.
134 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
6.6 Virtual-to-Physical Address Translation Process
During virtual-to-physical address translation, the CPU compares the
8-bit ASID (if the Global bit,G, is not set) of the virtual address to the ASID of the
TLB entry to see if there is a match.  One of the following comparisons are also made:
• In 32-bit mode, the highest 7-to-19 bits (depending upon the page size) of
the virtual address are compared to the contents of the TLB virtual page
number.
• In 64-bit mode, the highest 15-to-27 bits (depending upon the page size)
of the virtual address are compared to the contents of the TLB virtual
page number.
If a TLB entry matches, the physical address and access control bits (C,D, andV) are
retrieved from the matching TLB entry.  While theVbit of the entry must be set for a
valid translation to take place, it is not involved in the determination of a matching
TLB entry.
Figure 6-20 illustrates the TLB address translation process.
User’s Manual   U11761EJ6V0UM 135

Chapter 6  Memory Management Unit
Virtual Address (Input)
For valid VPN
address space, see and
the section describing ASID
Operating Modes
in this chapter.
| Valid | Yes | No | Valid |
| --- | --- | --- | --- |
| No | User | No | Sup No Address Address Address? Address? |
| Error | Mode? Exception Exception | Mode? | Error |
| Yes | Yes No Yes Address Valid Unmapped | Yes |  |
| Error | Address? Access Exception Yes No VPN No Match? Yes Global | MSBs=10? |  |
| G | No | ASID Match? = 1? Yes Yes 32-bit No Valid V address? = 1? No Yes Yes Dirty | No |
| Yes | No Write? = 1? Yes No Non- | D |  |
| cacheable | TLB | TLB | XTLB |
TLB
C =
Mod	Invalid	Refill	Refill
010?
Yes No
Exception Exception
Access
Access
Main
Cache
Memory
Physical Address (Output)
Figure  6-20   TLB Address Translation
136 User’s Manual   U11761EJ6V0UM

Chapter 6  Memory Management Unit
6.7 TLB Exceptions
If there is no TLB entry that matches the virtual address, a TLB miss exception occurs.
If the access control bits (DandV) indicate that the access is not valid, a TLB
modification or TLB invalid exception occurs.  If theCbits equal 010, the physical
2
address that is retrieved accesses main memory, bypassing the cache.
6.8 TLB Instructions
Table 6-14 lists the instructions that the CPU provides for working with the TLB.
Table 6-14   TLB Instructions
Op Code Description of Instruction
TLBP Translation Lookaside Buffer Probe
TLBR Translation Lookaside Buffer Read
TLBWI Translation Lookaside Buffer Write Index
TLBWR Translation Lookaside Buffer Write Random
User’s Manual   U11761EJ6V0UM 137

Chapter 7  CPU Exception Processing
This chapter describes the CPU exception processing, including an explanation of
exception processing, followed by the format and use of each CPU exception register.
7.1 Overview of Exception Processing
The processor receives exceptions from a number of sources, including translation
lookaside buffer (TLB) misses, arithmetic overflows, I/O interrupts, and system calls.
When the CPU detects one of these exceptions, the normal sequence of instruction
execution is suspended and the processor enters Kernel mode.
The processor then disables interrupts and forces execution of a software exception
processor (called ahandler) located at a fixed address.  The handler saves the context
of the processor, including the contents of the program counter, the current operating
mode (User or Supervisor), and the status of the interrupts (enabled or disabled).  This
context is saved so it can be restored when the exception has been serviced.
When an exception occurs, the CPU loads theException Program Counter(EPC)
register with a location where execution can restart after the exception has been
serviced.  The restart location in theEPCregister is the address of the instruction that
caused the exception or, if the instruction was executing in a branch delay slot, the
address of the branch instruction immediately preceding the delay slot.
The registers described later in the section assist in this exception processing by
retaining address, cause and status information.
138 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
7.2 Exception Processing Registers
This section describes the CP0 registers that are used in exception processing.  Table
7-1 lists these registers, along with their number—each register has a unique
identification number that is referred to as itsregister number.  For instance, theECC
register is register number 26.  The remaining CP0 registers are used in memory
management.
Software examines the CP0 registers during exception processing to determine the
cause of the exception and the state of the CPU at the time the exception occurred.  The
registers in Table 7-1 are used in exception processing, and are described in the
sections that follow.
Table 7-1    CP0 Exception Processing Registers
Register Name Reg.  No.
Context 4
BadVAddr (Bad Virtual Address) 8
Count 9
Compare register 11
Status 12
Cause 13
EPC (Exception Program Counter) 14
XContext                                                                                                 20
ECC 26
CacheErr (Cache Error and Status) 27
ErrorEPC (Error Exception Program Counter) 30
CPU general registers are interlocked and the result of an instruction can normally be
used by the next instruction; if the result is not available right away, the processor stalls
until it is available.  CP0 registers and the TLB are not interlocked, however; there may
be some delay before a value written by one instruction is available to following
instructions.
User’s Manual  U11761EJ6V0UM 139

Chapter 7  CPU Exception Processing
7.2.1 Context Register (4)
TheContextregister is a read/write register containing the pointer to an entry in the
page table entry (PTE) array; this array is an operating system data structure that stores
virtual-to-physical address translations.  When there is a TLB miss, the operating
system loads the TLB with the missing translation from the PTE array.  Normally, the
operating system uses theContextregister to address the current page map which
resides in the kernel-mapped segment,kseg3.  TheContextregister duplicates some of
the information provided in theBadVAddrregister, but the information is arranged in
a form that is more useful for a software TLB exception handler.  Figure 7-1 shows the
format of theContextregister; Table7-2 describes theContextregister fields.
Context Register
31                                                                                                                  023  22 4   3
32-bit
| PTEBase | BadVPN2 Mode | 0 |
| --- | --- | --- |
| 9 | 19 63                                                                                                                  023  22 4   3 64-bit | 4 |
| PTEBase | BadVPN2 Mode | 0 |
| 41 | 19 Figure  7-1   Context Register Format Table 7-2    Context Register Fields Field Description This field is written by hardware on a miss.  It contains the BadVPN2 virtual page number (VPN) of the most recent virtual address that did not have a valid translation. This field is a read/write field for use by the operating system. It is normally written with a value that allows the operating PTEBase system to use theContextregister as a pointer into the current PTE array in memory. The 19-bitBadVPN2field contains bits 31:13 of the virtual address that caused the TLB miss; bit 12 is excluded because a single TLB entry maps to an even-odd page pair.  For a 4-KB page size, this format can directly address the pair-table of 8-byte PTEs.  For other page and PTE sizes, shifting and masking this value produces the appropriate address. 140 User’s Manual  U11761EJ6V0UM | 4 |

Chapter 7  CPU Exception Processing
7.2.2 Bad Virtual Address Register (BadVAddr) (8)
The Bad Virtual Address register (BadVAddr) is a read-only register that displays the
most recent virtual address that caused one of the following exceptions: TLB Invalid,
TLB Modified, TLB Refill, or Address Error.
Figure 7-2 shows the format of theBadVAddrregister.
BadVAddr Register
31                                                                                                                  0
32-bit
Bad Virtual Address
Mode
32
63                                                                                                                  0
64-bit
Bad Virtual Address
Mode
64
Figure  7-2   BadVAddr Register Format
Note:TheBadVAddrregister does not save any information for bus errors, since bus
errors are not addressing errors.
7.2.3 Count Register (9)
TheCountregister acts as a timer incrementing at a constant rate whether or not an
instruction is executed, retired, or any forward progress is made through the pipeline.
On the V 5000 the count register can be configured at reset time to count either half
R
the maximum issue rate or at the maximum issue rate.  The default behavior is to count
at half the maximum issue rate.
This register can be read or written.  It can be written for diagnostic purposes or system
initialization; for example, to synchronize processors.
Figure 7-3 shows the format of theCountregister.
Count Register
31 0
Count
32
Figure  7-3   Count Register Format
User’s Manual  U11761EJ6V0UM 141

Chapter 7  CPU Exception Processing
7.2.4 Compare Register (11)
TheCompareregister acts as a timer (see also theCountregister); it maintains a stable
value that does not change on its own.
When the value of theCountregister equals the value of theCompareregister,
interrupt bitIP(7)in theCauseregister is set.  This causes an interrupt as soon as the
interrupt is enabled.
Writing a value to theCompareregister, as a side effect, clears the timer interrupt.
For diagnostic purposes, theCompareregister is a read/write register.   In normal use
however, theCompareregister is write-only.  Figure 7-4 shows the format of the
Compareregister.
Compare Register
31                                                                                                                  0
Compare
32
Figure  7-4   Compare Register Format
7.2.5 Status Register (12)
TheStatusregister (SR) is a read/write register that contains the operating mode,
interrupt enabling, and the diagnostic states of the processor.  The following list
describes the more importantStatusregister fields.
• The 8-bitInterrupt Mask(IM) field controls the enabling of eight
interrupt conditions.  Interrupts must be enabled before they can be
asserted, and the corresponding bits are set in both theInterrupt Mask
field of theStatusregister and theInterrupt Pendingfield of theCause
register. IM[1:0] are software interrupt masks, while IM[7:2] correspond
to Int[5:0].
• The 3-bitCoprocessorUsability(CU) field controls the usability of 3
possible coprocessors.  Regardless of theCU0bit setting, CP0 is always
usable in Kernel mode. For all other cases, an access to an unusable
coprocessor causes an exception.
• The 9-bitDiagnosticStatus(DS) field is used for self-testing, and checks
the cache and virtual memory system.
142 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
• TheReverse-Endian (RE)bit, bit 25, reverses the endianness of the
machine.  The processor can be configured as either little-endian or big-
endian at system reset; reverse-endian selection is used in Kernel and
Supervisor modes, and in the User mode when theREbit is 0.  Setting the
REbit to 1 inverts the User mode endianness.
(1) Status Register Format
Figure 7-5 shows the format of theStatusregister.  Table 7-3 describes theStatus
register fields.  Figure 7-6 and Table 7-4 provide additional information on the
Diagnostic Status(DS) field.  All bits in theDSfield are readable and writable.
Status Register
31                                                                   1530	28  27 2625  24	16	876	5 4 3 2  1   0
CU
XX	0FRRE	DS	IM7 - IM0	KXSXUXKSU  ERL EXL  IE
(Cu2:Cu0)
1	3	111	9	82111111
Figure  7-5   Status Register
User’s Manual  U11761EJ6V0UM 143

Chapter 7  CPU Exception Processing
Table 7-3    Status Register Fields
Field Description
Enables execution of MIPS IV instructions in user-mode
XX 1→MIPS IV instructions usable
0→MIPS IV instructions unusable
Controls the usability of each of the four coprocessor unit
numbers.  CP0 is always usable when in Kernel mode, regardless
of the setting of theCUbit. SettingCUenables the MIPS IV
0 3
CU
instruction set,
1→usable
0→unusable
0 Reserved. Set to 0.
Enables additional floating-point registers
FR 0→16 registers
1→32 registers
RE Reverse-Endianbit, valid in User mode.
DS Diagnostic Statusfield (see Figure 7-6).
Interrupt Mask: controls the enabling of each of the external,
internal, and software interrupts.  An interrupt is taken if interrupts
are enabled, and the corresponding bits are set in both theInterrupt
IM Maskfield of theStatusregister and theInterrupt Pendingfield of
theCauseregister.
0→disabled
1→enabled
Enables 64-bit addressing in Kernel mode.  The extended-
addressing TLB refill exception is used for TLB misses on kernel
KX addresses.
0→32−bit
1→64−bit
Enables 64-bit addressing and operations in Supervisor mode.  The
extended-addressing TLB refill exception is used for TLB misses
SX on supervisor addresses.
0→32−bit
1→64−bit
Enables 64-bit addressing and operations in User mode.  The
extended-addressing TLB refill exception is used for TLB misses
UX on user addresses.
0→32−bit
1→64−bit
144 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
Field Description
Mode bits
10 →User
2
KSU
01 →Supervisor
2
00 →Kernel
2
Error Level; set by the processor when Reset, Soft Reset, NMI, or
Cache Error exception are taken.
0→normal
1→error
When ERL is set:
ERL Interrupts are disabled.
The ERET instruction will use the return address held in
ErrorEPC instead of EPC.
Kuseg andxkuseg are treated as unmapped and uncached
regions.This allows main memory to be accessed in the presence
of cache errors.
Exception Level; set by the processor when any exception other
than Reset, Soft Reset, NMI, or Cache Error exception are taken.
0→normal
1→exception
When EXL is set:
EXL
Interrupts are disabled.
TLB refill exceptions will use the general exception vector
instead of the TLB refill vector.
EPC will not be updated if another exception is taken.
Interrupt Enable
IE 0→disable interrupts
1→enables interrupts
User’s Manual  U11761EJ6V0UM 145

Chapter 7  CPU Exception Processing
Diagnostic Status Field
24	23	22	21	20	19	18	17	16
00BEV	0	SR	0	CE	DE
21111111
Figure  7-6   Status Register DS Field
Table 7-4    Status Register Diagnostic Status Bits
Bit Description
Controls the location of TLB refill and general exception vectors.
BEV 0→normal
1→bootstrap
0 Reserved. Must be written as zeroes. Returns zeroes when read.
SR 1→Indicates that a Soft Reset or NMI has occurred.
Contents of the ECC register set or modify the check bits of the
CE
caches when CE = 1; see description of theECCregister.
Specifies that cache parity or ECC errors cannot cause exceptions.
DE 0→parity/ECC remain enabled
1→disables parity/ECC
0 Reserved.   Must be written as zeroes, and returns zeroes when read.
(2) Status Register Modes and Access States
Fields of theStatusregister set the modes and access states described in the sections
that follow.
Interrupt Enable: Interrupts are enabled when all of the following conditions are true:
• IE= 1
• EXL= 0
• ERL= 0
If these conditions are met, the settings of theIMbits enable the interrupt.
Operating Modes: The following CPUStatusregister bit settings are required for
User, Kernel, and Supervisor modes.
• The processor is in User mode whenKSU= 10,EXL= 0, andERL= 0.
2
• The processor is in Supervisor mode whenKSU= 01,EXL= 0, andERL
2
= 0.
146 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
• The processor is in Kernel mode whenKSU= 00, orEXL= 1, orERL=
2
1.
32- and 64-bit Modes: The following CPUStatusregister bit settings select 32- or 64-
bit operation for User, Kernel, and Supervisor operating modes.  Enabling 64-bit
operation permits the execution of 64-bit opcodes and translation of 64-bit addresses.
64-bit operation for User, Kernel and Supervisor modes can be set independently.
• 64-bit addressing for Kernel mode is enabled whenKX= 1.  64-bit
operations are always valid in Kernel mode.
• 64-bit addressing and operations are enabled for Supervisor mode when
SX= 1.
• 64-bit addressing and operations are enabled for User mode whenUX= 1.
Kernel Address Space Accesses: Access to the kernel address space is allowed when
the processor is in Kernel mode.
Supervisor Address Space Accesses: Access to the supervisor address space is
allowed when the processor is in Kernel or Supervisor mode, as described above in the
section titled, Operating Modes.
User Address Space Accesses: Access to the user address space is allowed in any of
the three operating modes.
(3) Status Register Reset
The contents of theStatusregister are undefined at reset, except for the following bits
in theDiagnostic Statusfield:
• ERLandBEV= 1
TheSRbit distinguishes between the Reset exception and the Soft Reset exception
(caused either byReset* or Nonmaskable Interrupt [NMI]).
7.2.6 Cause Register (13)
The 32-bit read/writeCauseregister describes the cause of the most recent exception.
Figure 7-7 shows the fields of this register. Table 7-5 describes theCauseregister
fields.
All bits in the Causeregister, with the exception of theIP(1:0)bits, are read-only;
IP(1:0)are used for software interrupts.
User’s Manual  U11761EJ6V0UM 147

Chapter 7  CPU Exception Processing
Table 7-5   Cause Register Fields
Field Description
Indicates whether the last exception taken occurred in a branch delay slot.
BD 1→delay slot
0→normal
Coprocessor unit number referenced when a Coprocessor Unusable exception is
CE
taken.
Indicates an interrupt is pending.
IP 1→interrupt pending
0→no interrupt
ExcCode Exception code field (see Table 7-6)
0 Reserved.  Must be written as zeroes, and returns zeroes when read.
148 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
Cause Register
| 31                                                                153029 2827 | 16 | 876 Exc | 21 | 0 |
| --- | --- | --- | --- | --- |
| BD | 0 | CE | 0 | IP7 IP0 0 0 Code |
| 1 | 1212 Figure  7-7   Cause Register Format Table 7-6   Cause Register ExcCode Field Exception Mnemonic Description Code Value | 8125 |  |  |
| 0 | Int | Interrupt |  |  |
| 1 | Mod | TLB modification exception |  |  |
| 2 | TLBL | TLB exception (load or instruction fetch) |  |  |
| 3 | TLBS | TLB exception (store) |  |  |
| 4 | AdEL | Address error exception (load or instruction fetch) |  |  |
| 5 | AdES | Address error exception (store) |  |  |
| 6 | IBE | Bus error exception (instruction fetch) |  |  |
| 7 | DBE | Bus error exception (data reference: load or store) |  |  |
| 8 | Sys | Syscall exception |  |  |
| 9 | Bp | Breakpoint exception |  |  |
| 10 | RI | Reserved instruction exception |  |  |
| 11 | CpU | Coprocessor Unusable exception |  |  |
| 12 | Ov | Arithmetic Overflow exception |  |  |
| 13 | Tr | Trap exception |  |  |
| 14 | ---- | Reserved |  |  |
| 15 | FPE | Floating-Point exception |  |  |
| 16–31 | –-- | Reserved 7.2.7 Exception Program Counter (EPC) Register (14) The Exception Program Counter (EPC) is a read/writeregister that contains the address at which processing resumes after an exception has been serviced. For synchronous exceptions, theEPCregister contains either: User’s Manual  U11761EJ6V0UM 149 |  |  |

Chapter 7  CPU Exception Processing
• the virtual address of the instruction that was the direct cause of the
exception, or
• the virtual address of the immediately preceding branch or jump
instruction (when the instruction is in a branch delay slot, and theBranch
Delaybit in theCauseregister is set).
The processor does not write to theEPCregister when theEXLbit in theStatusregister
is set to a 1.
Figure 7-8 shows the format of theEPCregister.
EPC Register
31 0
32-bit
EPC
Mode
32
63 0
64-bit
EPC
Mode
64
Figure  7-8   EPC Register Format
7.2.8 XContext Register (20)
The read/writeXContextregister contains a pointer to an entry in the page table entry
(PTE) array, an operating system data structure that stores virtual-to-physical address
translations.  When there is a TLB miss, the operating system software loads the TLB
with the missing translation from the PTE array.  TheXContextregister duplicates
some of the information provided in theBadVAddrregister, and puts it in a form useful
for a software TLB exception handler.  TheXContextregister is for use with the XTLB
refill handler, which loads TLB entries for references to a 64-bit address space, and is
included solely for operating system use.  The operating system sets the PTE base field
in the register, as needed.  Normally, the operating system uses theContextregister to
address the current page map, which resides in the kernel-mapped segmentkseg3.
Figure 7-9 shows the format of theXContextregister; Table 7-7 describes theXContext
register fields.
150 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
XContext Register
63                                                                                                                  033 323130 4   3
PTEBase	R	BadVPN2	0
31	2	27	4
Figure  7-9   XContext Register Format
The 27-bitBadVPN2field has bits 39:13 of the virtual address that caused the TLB
miss; bit 12 is excluded because a single TLB entry maps to an even-odd page pair.
For a 4-KB page size, this format may be used directly to address the pair-table of 8-
byte PTEs.  For other page and PTE sizes, shifting and masking this value produces
the appropriate address.
Table 7-7   XContext Register Fields
Field Description
TheBad Virtual Page Number/2 field is written by hardware on a miss.  It contains
BadVPN2
the VPN of the most recent invalidly translated virtual address.
TheRegionfield contains bits 63:62 of the virtual address.
00 = user
2
R
01=supervisor
2
11=kernel.
2
ThePage Table Entry Baseread/write field is normally written with a value that
PTEBase allows the operating system to use theContextregister as a pointer into the current
PTE array in memory.
7.2.9 Error Checking and Correcting (ECC) Register (26)
The 8-bitError Checking and Correcting(ECC) register reads or writes primary-
cache data parity bits for cache initialization, cache diagnostics, or cache error
processing.  (Tag ECC and parity are loaded from and stored to theTagLoregister.)
TheECCregister is loaded by the Index Load Tag CACHE operation. Content of the
ECC register is:
• written into the primary data cache on store instructions (instead of the
computed parity) when theCEbit of theStatusregister is set.
• substituted for the computed instruction parity for the CACHE operation
Fill.
Figure 7-10 shows the format of theECCregister; Table 7-8 describes the register
fields.
User’s Manual  U11761EJ6V0UM 151

Chapter 7  CPU Exception Processing
ECC Register
31 807
0 ECC
24 8
Figure  7-10   ECC Register Format
Table 7-8   ECC Register Fields
Field Description
An 8-bit field specifying the parity bits read from or written to a primary
cache.
ECC field values for Index_Store_Tag_D, Index_Load_Tag_D cache
operations:
ECC[0]  Even parity for least significant byte of requested doubleword
ECC[1]  Even parity for 2nd least significant byte
ECC[2]  Even parity for 3rd least significant byte
ECC[3]  Even parity for 4th least significant byte
ECC
ECC[4]  Even parity for 4th most significant byte
ECC[5]  Even parity for 3rd most significant byte
ECC[6]  Even parity for 2nd most signficant byte
ECC[7]  Even parity for most significant byte of requested doubleword
ECC field values for Index_Store_Tag_I, Index_Load_Tag_I cache
operations:
ECC[0]  Even parity for least significant word of requested doubleword
ECC[1]  Even parity for most significant word of requested doubleword
0 Reserved.  Must be written as zeroes, and returns zeroes when read.
7.2.10 Cache Error (CacheErr) Register (27)
The 32-bit read-onlyCacheErrregister processes ECC errors in the secondary cache
and parity errors in the primary cache.  Parity errors cannot be corrected.
TheCacheErrregister holds cache index and status bits that indicate the source and
nature of the error; it is loaded when a Cache Error exception is asserted.
Figure 7-11 shows the format of theCacheErrregister and Table 7-9 describes the
CacheErrregister fields.
152 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
CacheErr Register
| 313029282726252423  22 21 | 3 | 201 |
| --- | --- | --- |
| ERECEDET 0 EEEBEI | 0 | 0 SIDX 0 PIDX |
| 1 | 111 | 1 1 1 111 19 1 2 Figure  7-11   CacheErr Register Format Table 7-9   CacheErr Register Fields Field Description Type of reference ER 0→instruction 1→data Cache level of the error EC 0→primary 1→reserved Indicates if a data field error occurred ED 0→no error 1→error Indicates if a tag field error occurred ET 0→no error 1→error EE This bit is set if the error occurred on the SysAD bus. This bit is set if a data error occurred in addition to the instruction error (indicated by the remainder of |
EB
the bits).  If so, this requires flushing the data cache
after fixing the instruction error.
This bit is set if the error occured on filling primary
EI
on store miss.
Physical address [21:3] of the reference that
SIDX
encountered the error
Virtual address [13:12] of the double word in error.
PIDX (used with SIDX to construct a virtual index for the
primary caches)
Reserved.  Must be written as zeroes, and returns
0
zeroes when read.
User’s Manual  U11761EJ6V0UM 153

Chapter 7  CPU Exception Processing
7.2.11 Error Exception Program Counter (Error EPC)
Register (30)
TheErrorEPCregister is similar to theEPCregister, except thatErrorEPCis used on
parity error exceptions.  It is also used to store the program counter (PC) on Reset, Soft
Reset, and nonmaskable interrupt (NMI) exceptions.
The read/writeErrorEPCregister contains the virtual address at which instruction
processing can resume after servicing an error.  This address can be:
• the virtual address of the instruction that caused the exception
• the virtual address of the immediately preceding branch or jump
instruction, when this address is in a branch delay slot.
There is no branch delay slot indication for theErrorEPCregister.
Figure 7-12 shows the format of theErrorEPCregister.
ErrorEPC Register
31 0
32-bit
ErrorEPC
Mode
32
63 0
64-bit
ErrorEPC
Mode
64
Figure  7-12   ErrorEPC Register Format
7.3 Processor Exceptions
This section describes the processor exceptions—it describes the cause of each
exception, its processing by the hardware, and servicing by a handler (software).  The
types of exception, with exception processing operations, are described in the next
section.
154 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
7.3.1 Exception Types
This section gives sample exception handler operations for the following exception
types:
• reset
• soft reset
• nonmaskable interrupt (NMI)
• cache error
• remaining processor exceptions
When theEXLbit in theStatusregister is 0, either User, Supervisor, or Kernel
operating mode is specified by theKSUbits in theStatusregister.  When theEXLbit
is a 1, the processor is in Kernel mode.
When the processor takes an exception, theEXLbit is set to 1, which means the system
is in Kernel mode.  After saving the appropriate state, the exception handler typically
changesKSUto Kernel mode and resets theEXLbit back to 0.  When restoring the
state and restarting, the handler restores the previous value of theKSUfield and sets
theEXLbit back to 1.
Returning from an exception, also resets theEXLbit to 0.
In the following sections, sample hardware processes for various exceptions are
shown, together with the servicing required by the handler (software).
(1) Reset Exception Process
Figure 7-13 shows the Reset exception process.
T:  undefined
Random←TLBENTRIES–1
Wired←0
Config←0 || EC || EP || 00000000 || BE || 110 || 010 || 1 || 1 || 0 || undefined
6
|| DC || undefined
ErrorEPC←PC
SR←SR	|| 1 || 0 || 0 || SR	|| 1 || SR
31:23	19:3	1:0
PC←0xFFFF FFFF BFC0 0000
Figure  7-13   Reset Exception Processing
User’s Manual  U11761EJ6V0UM 155

Chapter 7  CPU Exception Processing
(2) Cache Error Exception Process
Figure 7-14 shows the Cache Error exception process.
T:  ErrorEPC←PC
25
CacheErr←ER || EC || ED || ET || ES || EE || ED || 0
SR←SR || 1 ||SR
31:3 1:0
if SR = 1 then      /*What is the BEV bit setting*/
22
PC←0xFFFF FFFF BFC0 0200 + 0x100  /*Access boot-PROM area*/
else
PC←0xFFFF FFFF A000 0000 + 0x100  /*Access main memory area*/
endif
Figure  7-14   Cache Error Exception Processing
(3) Soft Reset and NMI Exception Process
Figure 7-15 shows the Soft Reset and NMI exception process.
T:  ErrorEPC←PC
SR←SR	|| 1 || 0 || 1 || SR	|| 1 || SR
31:23	19:3	1:0
PC←0xFFFF FFFF BFC0 0000
Figure  7-15   Soft Reset and NMI Exception Processing
156 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
(4) General Exception Process
Figure 7-16 shows the process used for exceptions other than Reset, Soft Reset, NMI,
and Cache Error.
12 2
T:   Cause←BD || 0 || CE || 0	|| Cause	|| ExcCode || 0
15:8
if SR= 0 then/* System is in User or Supervisor mode with no current exception */
1
EPC←PC
endif
SR←SR || 1 || SR
31:2 0
if SR = 1 then
22
PC←0xFFFF FFFF BFC0 0200 + vector  /*access to uncached space*/
else
PC←0xFFFF FFFF 8000 0000 + vector  /*access to cached space*/
endif
Figure  7-16   General Exception Processing
7.3.2 Exception Vector Locations
The Reset, Soft Reset, and NMI exceptions are always vectored to location 0xFFFF
FFFF BFC0 0000.  Addresses for all other exceptions are a combination of avector
offsetand abase address.
The base addres is determined by the BEV bit of theStatusregister.
Table 7-10 shows the 64-bit-mode vector base address for all exceptions; the 32-bit
mode address is the low-order 32 bits (for instance, the base address for NMI in 32-bit
mode is 0xBFC0 0000).
Table 7-11 shows the vector offset added to the base address to create the exception
address.
Table 7-10   Exception Vector Base Addresses
BEV Bit V 5000 Processor Vector Base Address
R
0 0xFFFF FFFF 8000 0000
1 0xFFFF FFFF BFC0 0200
User’s Manual  U11761EJ6V0UM 157

Chapter 7  CPU Exception Processing
Table 7-11   Exception Vector Offsets
Exception V 5000 Processor Vector Offset
R
TLB refill, EXL = 0 0x000
XTLB refill, EXL = 0
0x080
(X = 64-bit TLB)
Cache Error 0x100
Others 0x180
WhenBEV = 0, the vector base address for the cache error exception changes from
kseg0(0xFFFF FFFF 8000 0000) tokseg1(0xFFFF FFFF A000 0000). This change
indicates that the caches are initialized and that the vector can be cached. WhenBEV
= 1, the vector base for the cache error exception is 0xFFFF FFFF BFC0 0200. This is
an uncached and unmapped space, allowing the exception to bypass the cache and the
TLB.
(1) TLB Refill Vector Selection
In all present implementations of the MIPS III ISA, there are two TLB refill exception
vectors:
• one for references to 32-bit address space (TLB Refill)
• one for references to 64-bit address space (XTLB Refill)
The TLB refill vector selection is based on the address space of the address (user,
supervisor,orkernel) that caused the TLB miss, and the value of the corresponding
extended addressing bit in theStatusregister (UX, SX,orKX).  The current operating
mode of the processor is not important except that it plays a part in specifying in which
address space an address resides.  TheContextandXContextregisters are entirely
separate page-table-pointer registers that point to and refill from two separate page
tables.  For all TLB exceptions (Refill, Invalid, TLBL or TLBS), theBadVPN2fields
of both registers are loaded as they were in the V 4000.
R
In contrast to the V 5000, the V 4000 processor selects the vector based on the current
R R
operating mode of the processor (user, supervisor,orkernel) and the value of the
corresponding extended addressing bit in theStatusregister (UX, SXorKX).  In
addition, theContextandXContextregisters are not implemented as entirely separate
registers; thePTEbasefields are shared.  A miss to a particular address goes through
either TLB Refill or XTLB Refill, depending on the source of the reference.  There can
be only a single page table unless the refill handlers execute address-deciphering and
page table selection in software.
158 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
Note:Refills for the 0.5 GB supervisor mapped region,sseg/ksseg, are controlled by
the value ofKXrather thanSX.  This simplifies control of the procesor when supervisor
mode is not being used.
Table 7-12 lists the TLB refill vector locations, based on the adress that caused the
TLB miss and its correspoinding mode bit.
Table 7-12   TLB Refill Vectors
| Space | Address Range | Regions | Exception Vector 0xFFFF FFFF E000 0000 Refill (KX=0) |
| --- | --- | --- | --- |
| Kernel | to | kseg3 0xFFFF FFFF FFFF FFFF XRefill (KX=1) 0xFFFF FFFF C000 0000 Refill (SX=0) | or |
| Supervisor | to | sseg, ksseg 0xFFFF FFFF DFFF FFFF XRefill (SX=1) 0xC000 0000 0000 0000 | or |
| Kernel | to | xkseg | XRefill (KX=1) 0xC000 0FFE FFFF FFFF 0x4000 0000 0000 0000 |
| Supervisor | to | xsseg, xksseg | XRefill (SX=1) 0x4000 0FFF FFFF FFFF 0x0000 0000 8000 0000 |
| User | to | xsuseg, xuseg, xkuseg 0x0000  0FFF FFFF FFFF 0x0000 0000 0000 0000 Refill (UX=0) useg, xuseg, suseg, | XRefill (UX=1) |
| User | to xsuseg, kuseg, xkuseg 0x0000 0000 7FFF FFFF XRefill (UX=1) User’s Manual  U11761EJ6V0UM 159 | or |  |

Chapter 7  CPU Exception Processing
7.3.3 Priority of Exceptions
Table 7-13 describes exceptions in the order of highest to lowest priority.   While more
than one exception can occur for a single instruction, only the exception with the
highest priority is reported.
Table 7-13    Exception Priority Order
Reset(highest priority)
Soft Reset
Nonmaskable Interrupt (NMI)
Address error –– Instruction fetch
TLB refill –– Instruction fetch
TLB invalid –– Instruction fetch
Cache error –– Instruction fetch
Bus error –– Instruction fetch
Integer overflow, Trap, System Call, Breakpoint, Reserved Instruction,
Coprocessor Unusable, or Floating-Point Exception
Address error –– Data access
TLB refill –– Data access
TLB invalid –– Data access
TLB modified –– Data write
Cache error –– Data access
Bus error –– Data access
Interrupt(lowest priority)
Generally speaking, the exceptions described in the following sections are handled
(“processed”) by hardware; these exceptions are then serviced by software.
160 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
7.3.4 Reset Exception
Cause
The Reset exception occurs when theColdReset* signal is asserted and then
deasserted.  This exception is not maskable.
Processing
The CPU provides a special interrupt vector for this exception:
• location 0xFFFF FFFF BFC0 0000 in 64-bit mode
The Reset vector resides in unmapped and uncached CPU address space, so the
hardware need not initialize the TLB or the cache to process this exception.  It also
means the processor can fetch and execute instructions while the caches and virtual
memory are in an undefined state.
The contents of all registers in the CPU are undefined when this exception occurs,
except for the following register fields:
• In theStatusregister,SRis cleared to 0, andERLandBEVare set to 1.
All other bits are undefined.
• SomeConfigregister are initialized from the boot-time mode stream.
• TheRandomregister is initialized to the value of its upper bound.
• TheWiredregister is initialized to 0.
Servicing
The Reset exception is serviced by:
• initializing all processor registers, coprocessor registers, caches, and the
memory system
• performing diagnostic tests
• bootstrapping the operating system
7.3.5 Soft Reset Exception
Cause
The Soft Reset exception occurs in response to assertion of theReset* input Execution
begins at the Reset vector when theReset*signal is negated.
The Soft Reset exception is not maskable.
User’s Manual  U11761EJ6V0UM 161

Chapter 7  CPU Exception Processing
Processing
The Reset vector is used for this exception. The Reset vector is located within
uncached and unmapped address space. Hence the cache and TLB need not be
initialized in order to process the exception. Regardless of the cause, when this
exception occurs theSRbit of theStatusregister is set, distinguishing this exception
from a Reset exception.
The primary purpose of the Soft Reset exception is to reinitialize the processor after a
fatal error during normal operation. Unlike an NMI, all cache and bus state machines
are reset by this exception.
When the Soft Reset exception occurs, all register contents are preserved with the
following exceptions:
• ErrorEPCregister, which contains the restart PC.
• ERL, BEV,andSRbits of the Status Register, each of which is set to 1.
Because the Soft Reset can abort cache and bus operations, the cache and memory
states are undefined when the Soft Reset exception occurs.
Servicing
The Soft Reset exception is serviced by saving the current processor state for
diagnostic purposes,  and reinitializing for the Reset exception.
7.3.6 Non Maskable Interrupt (NMI) Exception
Cause
The Non Maskable Interrupt exception occurs in response to falling edge of the NMI
signal, or an external write to theInt*[6]bit of theInterruptRegister. The NMI
interrupt is not maskable and occurs regardless of the settings of theEXL, ERL, andIE
bits in theStatusRegister.
Processing
The Reset vector is used for this exception. The Reset vector is located within
uncached and unmapped address space. Hence the cache and TLB need not be
initialized in order to process the exception. Regardless of the cause, when this
exception occurs theSRbit of theStatusregister is set, distinguishing this exception
from a Reset exception.
162 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
Because the NMI can occur in the midst of another exception, it is typically not
possible to continue program execution after servicing an NMI. An NMI exception is
taken only at instruction boundaries. The state of the caches and memory system are
preserved.
When the NMI exception occurs, all register contents are preserved with the following
exceptions:
• ErrorEPC register, which contains the restart PC.
• ERL, BEV, and SR bits of the Status Register, each of which is set to 1.
Servicing
The NMI exception is serviced by saving the current processor state for diagnostic
purposes, and reinitializing for the Reset exception.
Caution If a pipeline cancelling logic (e.g. cache error, bus error) occurs after
the V 5000 detects an NMI by the V 5000 starts the NMI handling,
R R
the NMI will be cancelled and only the pipeline cancelling logic will be
handled.
If an NMI cancellation occurred, make NMI* inactive once and then
make it active again after the NMI cancellation.
7.3.7 Address Error Exception
Cause
The Address Error exception occurs when an attempt is made to execute one of the
following:
• load or store a doubleword that is not aligned on a doubleword boundary
• load, fetch, or store a word that is not aligned on a word boundary
• load or store a halfword that is not aligned on a halfword boundary
• reference the kernel address space from User or Supervisor mode
• reference the supervisor address space from User mode
This exception is not maskable.
User’s Manual  U11761EJ6V0UM 163

Chapter 7  CPU Exception Processing
Processing
The common exception vector is used for this exception.  TheAdELorAdEScode in
theCauseregister is set, indicating whether the instruction caused the exception with
an instruction reference, load operation, or store operation shown by theEPCregister
andBDbit in theCauseregister.
When this exception occurs, theBadVAddrregister retains the virtual address that was
not properly aligned or that referenced protected address space.  The contents of the
VPNfield of theContextandEntryHiregisters are undefined, as are the contents of the
EntryLoregister.
TheEPCregister contains the address of the instruction that caused the exception,
unless this instruction is in a branch delay slot.  If it is in a branch delay slot, theEPC
register contains the address of the preceding branch instruction and theBDbit of the
Causeregister is set as indication.
Servicing
The process executing at the time is handed a segmentation violation signal. This error
is usually fatal to the process incurring the exception.
Restriction
An address error exception will erroneously occur on a branch instruction that is the
second to last instruction of a segment (e.g., USEG0).
7.3.8 TLB Exceptions
Three types of TLB exceptions can occur:
• TLB Refilloccurs when there is no TLB entry that matches an attempted
reference to a mapped address space.
• TLB Invalid occurs when a virtual address reference matches a TLB entry
that is marked invalid.
• TLB Modified occurs when a store operation virtual address reference to
memory matches a TLB entry which is marked valid but is not dirty (the
entry is not writable).
The following three sections describe these TLB exceptions.
164 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
TLB Refill Exception
Cause
The TLB refill exception occurs when there is no TLB entry to match a reference to a
mapped address space.  This exception is not maskable.
Processing
There are two special exception vectors for this exception; one for references to 32-bit
address spaces, and one for references to 64-bit address spaces.  TheUX, SX,andKX
bits of theStatusregister determine whether the user, supervisor or kernel address
spaces referenced are 32-bit or 64-bit spaces.  All references use these vectors when
theEXLbit is set to 0 in theStatusregister.  This exception sets theTLBLorTLBScode
in theExcCodefield of theCauseregister.  This code indicates whether the instruction,
as shown by theEPCregister and theBDbit in theCauseregister, caused the miss by
an instruction reference, load operation, or store operation.
When this exception occurs, theBadVAddr,Context,XContextandEntryHiregisters
hold the virtual address that failed address translation. TheEntryHiregister also
contains the ASID from which the translation fault occurred.  TheRandomregister
normally contains a valid location in which to place the replacement TLB entry.  The
contents of theEntryLoregister are undefined.  TheEPCregister contains the address
of the instruction that caused the exception, unless this instruction is in a branch delay
slot, in which case theEPCregister contains the address of the preceding branch
instruction and theBDbit of theCauseregister is set.
Servicing
To service this exception, the contents of theContextorXContextregister are used as
a virtual address to fetch memory locations containing the physical page frame and
access control bits for a pair of TLB entries.  The two entries are placed into the
EntryLo0/EntryLo1register; theEntryHiandEntryLoregisters are written into the
TLB.
It is possible that the virtual address used to obtain the physical address and access
control information is on a page that is not resident in the TLB. This condition is
processed by allowing a TLB refill exception in the TLB refill handler.  This second
exception goes to the common exception vector because theEXLbit of theStatus
register is set.
User’s Manual  U11761EJ6V0UM 165

Chapter 7  CPU Exception Processing
TLB Invalid Exception
Cause
The TLB invalid exception occurs when a virtual address reference matches a TLB
entry that is marked invalid (TLB valid bit cleared).  This exception is not maskable.
Processing
The common exception vector is used for this exception.  TheTLBLorTLBScode in
theExcCodefield of theCauseregister is set.  This indicates whether the instruction,
as shown by theEPCregister andBDbit in theCauseregister, caused the miss by an
instruction reference, load operation, or store operation.
When this exception occurs, theBadVAddr,Context,XContextandEntryHiregisters
contain the virtual address that failed address translation.  TheEntryHiregister also
contains the ASID from which the translation fault occurred.  TheRandomregister
normally contains a valid location in which to put the replacement TLB entry.  The
contents of theEntryLoregister is undefined.
TheEPCregister contains the address of the instruction that caused the exception
unless this instruction is in a branch delay slot, in which case theEPCregister contains
the address of the preceding branch instruction and theBDbit of theCauseregister is
set.
Servicing
A TLB entry is typically marked invalid when one of the following is true:
• a virtual address does not exist
• the virtual address exists, but is not in main memory (a page fault)
• a trap is desired on any reference to the page (for example, to maintain a
reference bit)
After servicing the cause of a TLB Invalid exception, the TLB entry is located with
TLBP (TLB Probe), and replaced by an entry with that entry’sValidbit set.
TLB Modified Exception
Cause
The TLB modified exception occurs when a store operation virtual address reference
to memory matches a TLB entry that is marked valid but is not dirty and therefore is
not writable.  This exception is not maskable.
166 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
Processing
The common exception vector is used for this exception, and theModcode in the
Causeregister is set.
When this exception occurs, theBadVAddr,Context,XContextandEntryHiregisters
contain the virtual address that failed address translation.  TheEntryHiregister also
contains the ASID from which the translation fault occurred.  The contents of the
EntryLoregister is undefined.
TheEPCregister contains the address of the instruction that caused the exception
unless that instruction is in a branch delay slot, in which case theEPCregister contains
the address of the preceding branch instruction and theBDbit of theCauseregister is
set.
Servicing
The kernel uses the failed virtual address or virtual page number to identify the
corresponding access control information.  The page identified may or may not permit
write accesses; if writes are not permitted, a write protection violation occurs.
If write accesses are permitted, the page frame is marked dirty/writable by the kernel
in its own data structures. The TLBP instruction places the index of the TLB entry that
must be altered into theIndexregister. TheEntryLoregister is loaded with a word
containing the physical page frame and access control bits (with theDbit set), and the
EntryHiandEntryLoregisters are written into the TLB.
7.3.9 Cache Error Exception
Cause
The Cache Error exception occurs when either a primary or secondary cache parity
error is detected. This exception is maskable by theDEbit in the Status Register.
Processing
The processor sets theERLbit in theStatusregister, saves the exception restart address
in theErrorEPCregister, and then transfers the information to a special vector in
uncached space;
If BEV = 0, the vector is 0xFFFF FFFF A000 0100.
If BEV = 1, the vector is 0xFFFF FFFF BFC0 0300.
User’s Manual  U11761EJ6V0UM 167

Chapter 7  CPU Exception Processing
Servicing
All errors should be logged.  To correct parity errors the system uses the CACHE
instruction to invalidate the cache block, overwrite the old data through a cache miss,
and resumes execution with an ERET. Other errors are not correctable and are likely
to be fatal to the current process.
7.3.10 Bus Error Exception
Cause
A Bus Error exception is raised by board-level circuitry for events such as bus time-
out, backplane bus parity errors, and invalid physical memory addresses or access
types.  This exception is not maskable.
A Bus Error exception occurs when a cache miss refill, uncached reference, or an
unbuffered write occurs synchronously; a Bus Error exception resulting from a
buffered write transaction must be reported using the general interrupt mechanism.
Processing
The common interrupt vector is used for a Bus Error exception.  TheIBEorDBEcode
in theExcCodefield of theCauseregister is set, signifying whether the instruction (as
indicated by theEPCregister andBDbit in theCauseregister) caused the exception
by an instruction reference, load operation, or store operation.
TheEPCregister contains the address of the instruction that caused the exception,
unless it is in a branch delay slot, in which case theEPCregister contains the address
of the preceding branch instruction and theBDbit of theCauseregister is set.
Servicing
The physical address at which the fault occurred can be computed from information
available in the CP0 registers.
• If theIBEcode in theCauseregister is set (indicating an instruction fetch
reference), the virtual address is contained in theEPCregister.
• If theDBEcode is set (indicating a load or store reference), the
instruction that caused the exception is located at the virtual address
contained in theEPCregister (or 4+ the contents of theEPCregister if
theBDbit of theCauseregister is set).
The virtual address of the load and store reference can then be obtained by interpreting
the instruction.  The physical address can be obtained by using the TLBP instruction
and reading theEntryLoregister to compute the physical page number.  The process
executing at the time of this exception is handed a bus error signal, which is usually
fatal.
168 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
7.3.11 Integer Overflow Exception
Cause
An Integer Overflow exception occurs when an ADD, ADDI, SUB, DADD, DADDI
or DSUB instruction results in a 2’s complement overflow.  This exception is not
maskable.
Processing
The common exception vector is used for this exception, and theOVcode in theCause
register is set.
TheEPCregister contains the address of the instruction that caused the exception
unless the instruction is in a branch delay slot, in which case theEPCregister contains
the address of the preceding branch instruction and theBDbit of theCauseregister is
set.
Servicing
The process executing at the time of the exception is handed a floating-point
exception/integer overflow signal. This error is usually fatal to the current process.
7.3.12 Trap Exception
Cause
The Trap exception occurs when a TGE, TGEU, TLT, TLTU, TEQ, TNE, TGEI,
TGEUI, TLTI, TLTUI, TEQI, or TNEI instruction results in a TRUE condition. This
exception is not maskable.
Processing
The common exception vector is used for this exception, and theTrcode in theCause
register is set.
TheEPCregister contains the address of the instruction causing the exception unless
the instruction is in a branch delay slot, in which case theEPCregister contains the
address of the preceding branch instruction and theBDbit of theCauseregister is set.
Servicing
The process executing at the time of a Trap exception is handed a floating-point
exception/integer overflow signal. This error is usually fatal.
User’s Manual  U11761EJ6V0UM 169

Chapter 7  CPU Exception Processing
7.3.13 System Call Exception
Cause
A System Call exception occurs during an attempt to execute the SYSCALL
instruction.  This exception is not maskable.
Processing
The common exception vector is used for this exception, and theSyscode in theCause
register is set.
TheEPCregister contains the address of the SYSCALL instruction unless it is in a
branch delay slot, in which case theEPCregister contains the address of the preceding
branch instruction.
If the SYSCALL instruction is in a branch delay slot, theBDbit of theStatusregister
is set; otherwise this bit is cleared.
Servicing
When this exception occurs, control is transferred to the applicable system routine.
To resume execution, theEPCregister must be altered so that the SYSCALL
instruction does not re-execute; this is accomplished by adding a value of 4 to theEPC
register (EPCregister + 4) before returning.
If a SYSCALL instruction is in a branch delay slot, a more complicated algorithm,
beyond the scope of this description, may be required.
7.3.14 Breakpoint Exception
Cause
A Breakpoint exception occurs when an attempt is made to execute the BREAK
instruction.  This exception is not maskable.
Processing
The common exception vector is used for this exception, and theBPcode in theCause
register is set.
TheEPCregister contains the address of the BREAK instruction unless it is in a branch
delay slot, in which case theEPCregister contains the address of the preceding branch
instruction.
170 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
If the BREAK instruction is in a branch delay slot, theBDbit of theStatusregister is
set, otherwise the bit is cleared.
Servicing
When the Breakpoint exception occurs, control is transferred to the applicable system
routine.  Additional distinctions can be made by analyzing the unused bits of the
BREAK instruction (bits 25:6), and loading the contents of the instruction whose
address theEPCregister contains.  A value of 4 must be added to the contents of the
EPCregister(EPCregister + 4) to locate the instruction if it resides in a branch delay
slot.
To resume execution, theEPCregister must be altered so that the BREAK instruction
does not re-execute; this is accomplished by adding a value of 4 to theEPCregister
(EPCregister + 4) before returning.
If a BREAK instruction is in a branch delay slot, interpretation of the branch
instruction is required to resume execution.
7.3.15 Reserved Instruction Exception
Cause
The Reserved Instruction exception occurs when one of the following conditions
occurs:
• an attempt is made to execute an instruction with an undefined major
opcode (bits 31:26)
• an attempt is made to execute a SPECIAL instruction with an undefined
minor opcode (bits 5:0)
• an attempt is made to execute a REGIMM instruction with an undefined
minor opcode (bits 20:16)
• an attempt is made to execute 64-bit operations in 32-bit mode when in
User or Supervisor modes
64-bit operations are always valid in Kernel mode regardless of the value of theKXbit
in theStatusregister.
This exception is not maskable.
Processing
The common exception vector is used for this exception, and theRIcode in theCause
register is set.
User’s Manual  U11761EJ6V0UM 171

Chapter 7  CPU Exception Processing
TheEPCregister contains the address of the reserved instruction unless it is in a branch
delay slot, in which case theEPCregister contains the address of the preceding branch
instruction.
Servicing
No instructions in the MIPS ISA are currently interpreted.  The process executing at
the time of this exception is handed an illegal instruction/reserved operand fault signal.
This error is usually fatal.
7.3.16 Coprocessor Unusable Exception
Cause
The Coprocessor Unusable exception occurs when an attempt is made to execute a
coprocessor instruction for either:
• a corresponding coprocessor unit that has not been marked usable, or
• CP0 instructions, when the unit has not been marked usable and the
process executes in either User or Supervisor mode.
This exception is not maskable.
Processing
The common exception vector is used for this exception, and theCPUcode in the
Causeregister is set.  The contents of theCoprocessor Usage Errorfield of the
coprocessorControlregister indicate which of the four coprocessors was referenced.
TheEPCregister contains the address of the unusable coprocessor instruction unless
it is in a branch delay slot, in which case theEPCregister contains the address of the
preceding branch instruction.
Servicing
The coprocessor unit to which an attempted reference was made is identified by the
Coprocessor Usage Error field, which results in one of the following situations:
• If the process is entitled access to the coprocessor, the coprocessor is
marked usable and the corresponding user state is restored to the
coprocessor.
• If the process is entitled access to the coprocessor, but the coprocessor
does not exist or has failed, interpretation of the coprocessor instruction is
possible.
172 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
• If theBDbit is set in theCauseregister, the branch instruction must be
interpreted; then the coprocessor instruction can be emulated and
execution resumed with theEPCregister advanced past the coprocessor
instruction.
• If the process is not entitled access to the coprocessor, the process
executing at the time is handed an illegal instruction/privileged instruction
fault signal. This error is usually fatal.
7.3.17 Floating-Point Exception
Cause
The Floating-Point exception is used by the floating-point coprocessor.  This exception
is not maskable.
Processing
The common exception vector is used for this exception, and theFPEcode in the
Causeregister is set.
The contents of theFloating-Point Control/Statusregister indicate the cause of this
exception.
Servicing
This exception is cleared by clearing the appropriate bit in theFloating-Point Control/
Statusregister.
For an unimplemented instruction exception, the kernel should emulate the instruction;
for other exceptions, the kernel should pass the exception to the user program that
caused the exception.
7.3.18 Interrupt Exception
Cause
The Interrupt exception occurs when one of the eight interrupt conditions is asserted.
The significance of these interrupts is dependent upon the specific system
implementation.
Each of the eight interrupts can be masked by clearing the corresponding bit in theInt-
Maskfield of theStatusregister, and all of the eight interrupts can be masked at once
by clearing theIEbit of theStatusregister.
User’s Manual  U11761EJ6V0UM 173

Chapter 7  CPU Exception Processing
Processing
The common exception vector is used for this exception, and theIntcode in theCause
register is set.
TheIPfield of theCauseregister indicates current interrupt requests.  It is possible that
more than one of the bits can be simultaneously set (or evennobits may be set) if the
interrupt is asserted and then deasserted before this register is read.
Servicing
If the interrupt is caused by one of the two software-generated exceptions (SW1or
SW0), the interrupt condition is cleared by setting the correspondingCauseregister bit
to 0.
If the interrupt is hardware-generated, the interrupt condition is cleared by correcting
the condition causing the interrupt pin to be asserted.
Due to the on-chip write buffer, a store to an external device may not occur until after
other instructions in the pipeline finish. Hence, the user must ensure that the store will
occur before thereturn from exceptioninstruction (ERET) is executed. Otherwise the
interrupt may be serviced again even though there is no actual interrupt pending.
7.4 Exception Handling and Servicing Flowcharts
The remainder of this section contains flowcharts for the following exceptions and
guidelines for their handlers:
• general exceptions and their exception handler
• TLB/XTLB miss exception and their exception handler
• cache error exception and its handler
• reset, soft reset and NMI exceptions, and a guideline to their handler.
Generally speaking, the exceptions are handled by hardware (HW); the exceptions are
then serviced by software (SW).
174 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
Exceptions other than Reset, Soft Reset, NMI, CacheError or first-level TLB miss
Note: Interrupts can be masked by IE or IMs
Comments
*FP Control Status Register
Set FP Control Status Register
is only set if the respective exception
EnHi <- VPN2, ASID
occurs.
Context <- VPN2 *EnHi, X/Context are set only for
Set Cause Register TLB- Invalid, Modified,
& Refill exceptions
EXCCode, CE
*BadVA is set for TLB-Refill,
TLB-invalid, TLB-Modified, Address
Error exceptions
Yes	Instr. in	No
Br.Dly. Slot?
Cause 31 (BD) <- 1 Cause 31 (BD) <- 0
EXL	= 1	= 1	EXL
(SR1) (SR1)
= 0 = 0
Set Bad VA Set Bad VA
EPC <-- (PC - 4) EPC <-- PC
Processor forced to kernel mode
EXL <- 1 and interrupts disabled
=0(normal) =1 (bootstrap)
BEV
PC <- 0xFFFF FFFF 8000 0000 + 180
PC <- 0xFFFF FFFF BFC0 0200 + 180
(unmapped, cached)
(unmapped, uncached)
To General Exception Servicing Guidelines
Figure  7-17   General Exception Handler (HW)
User’s Manual  U11761EJ6V0UM 175

Chapter 7  CPU Exception Processing
Comments
MFC0 - * Unmapped vector so TLBMod, TLBInv,
X/Context TLB Refill exceptions not possible
EPC
Status * EXL=1 so Interrupt exceptions disabled
Cause
* OS/System to avoid all other exceptions
*Only CacheError, Reset, Soft Reset, NMI
exceptions possible.
MTC0 -
(Set Status Bits:)
KSU<- 00
EXL <- 0 (optional - only to enable Interrupts while keeping Kernel Mode)
IE = 1
* After EXL=0, all exceptions allowed.
Check CAUSE REG. & Jump to (except interrupt if masked by IE or IM
appropriate Service Code and CacheError if masked by DE)
Service Code
EXL = 1
MTC0 -
EPC
STATUS
* ERET is not allowed in the branch delay slot of
another Jump Instruction
* Processor does not execute the instruction which is
ERET
in the ERET’s branch delay slot
* PC <- EPC; EXL <- 0
* LLbit <- 0
Figure  7-18   General Exception Servicing Guidelines (SW)
176 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
Yes Instr. in
Br.Dly. Slot?
No
EnHi <- VPN2, ASID EnHi <- VPN2, ASID
Context <- VPN2 Context <- VPN2
Set Cause Reg. Set Cause Reg.
EXCCode, CE and EXCCode, CE and
Cause bit 31 (BD) <- 1
Cause bit 31 (BD) <- 0
Check if exception within
another exception
EXL	=1	EXL	=1
(SR bit 1) (SR bit 1)
=0 =0
Set BadVA Set BadVA
EPC <-- (PC -4) EPC <-- PC
XTLB
Y N
Instruction?
Set BadVA
| Vec. Off. = 0x080 | Vec. Off. = 0x000 Points to Refill Exception Points to General Exception Processor forced to Kernel Mode & EXL <- 1 interrupt disabled | Vec. Off. = 0x180 |
| --- | --- | --- |
| =0 (normal) | BEV | =1 (bootstrap) (SR bit 22) PC <- 0xFFFF FFFF 8000 0000 + Vec.Off. PC <- 0xFFFF FFFF BFC0 0200 + Vec.Off. (unmapped, cached) (unmapped, uncached) To TLB/XTLB Exception Servicing Guidelines Figure  7-19   TLB/XTLB Miss Exception Handler (HW) User’s Manual  U11761EJ6V0UM 177 |

Chapter 7  CPU Exception Processing
Comments
* Unmapped vector so TLBMod, TLBInv,
TLB Refill or VCEP exceptions
not possible
MFC0 -
* EXL=1 so Interrupt exceptions disabled
CONTEXT
* OS/System to avoid all other exceptions
*Only CacheError, Reset, Soft Reset, NMI
exceptions possible.
* Load the mapping of the virtual address in Context Reg.
Move it to ENLO and Write into the TLB
* There could be a TLB miss again during the mapping
Service Code
of the data or instruction address.  The processor will
jump to the general exception vector since the EXL is 1.
(Option to complete the first level refill in the general
exception handler or ERET to the original instruction
and take the exception again)
* ERET is not allowed in the branch delay slot of
another Jump Instruction
* Processor does not execute the instruction which is
ERET in the ERET’s branch delay slot
* PC <- EPC; EXL <- 0
* LLbit <- 0
Figure  7-20   TLB/XTLB Exception Servicing Guidelines (SW)
178 User’s Manual  U11761EJ6V0UM

Chapter 7  CPU Exception Processing
Note: Can be masked/disabled by DE (SR16) bit = 1
Set CacheErr Reg.
Yes Instr. in
Br. Dly. Slot?
No
ErrEPC <- (PC - 4) ErrEPC <- PC
ERL <- 1
=0	(normal)	=1	(bootstrap)
BEV
Cache Error Exception Handling (HW)
PC <- 0xFFFF FFFF A000 0000 + 100 PC <- 0xFFFF FFFF BFC0 0200 + 100
(unmapped, uncached) (unmapped, uncached)
Comments
* Unmapped Uncached vector so
TLB related & Cache Error Exception not possible
* ERL=1 so Interrupt exceptions disabled
* OS/System to avoid all other exceptions
Service Code
*Only Reset, Soft Reset, NMI
exceptions possible.
* ERET is not allowed in the branch delay slot of
another Jump Instruction
* Processor does not execute the instruction which is
Servicing Guidelines (SW) in the ERET’s branch delay slot
ERET
* PC <- ErrorEPC; ERL <- 0
* LLbit <- 0
Figure  7-21   Cache Error Exception Handling (HW) and Servicing Guidelines
User’s Manual  U11761EJ6V0UM 179

Chapter 7  CPU Exception Processing
Soft Reset or NMI Exception Reset Exception
Random <- TLBENTRIES - 1
Status:
BEV <- 1 Wired <- 0
Config <- Update(31:6)|| Undef(5:0)
SR<- 1
ERL <- 1 Status:
BEV <- 1
SR<- 0
ERL <- 1
ErrorEPC <- PC
PC <- 0xFFFF FFFF BFC0 0000
Reset, Soft Reset & NMI Exception Handling (HW)
Yes
NMI?
Note: There is no indication from the
processor to differentiate between
No NMI & Soft Reset;
there must be a system level indication.
=0
NMI Service Code Status bit 20
(SR)
= 1
Reset, Soft Reset & NMI
Servicing Guidelines (SW)
Soft Reset Service Code Reset Service Code
(Optional) ERET
Figure  7-22   Reset, Soft Reset & NMI Exception Handling
180 User’s Manual  U11761EJ6V0UM

Chapter 8  Floating Point Unit
This chapter describes the floating-point unit (FPU) of the V 5000 processor,
R
including the programming model, instruction set and formats, and the pipeline.
The FPU, with associated system software, fully conforms to the requirements of
ANSI/IEEE Standard 754–1985,IEEE Standard for Binary Floating-Point
Arithmetic.  In addition, the MIPS architecture fully supports the recommendations of
the standard and precise exceptions.
User’s Manual  U11761EJ6V0UM 181

Chapter 8  Floating Point Unit
8.1 Overview
The FPU operates as a coprocessor for the CPU (it is assigned coprocessor labelCP1),
and extends the CPU instruction set to perform arithmetic operations on floating-point
values.
Figure 8-1 illustrates the functional organization of the FPU.
Data Cache
FCU
64 Control
64
FP Bypass
Pipeline Chain
FP Mul/ FP
FP
Add
Ld/St Div/Sqrt
64	64	64
64 6464 64 64 64
FP Reg File
Figure  8-1   FPU Functional Block Diagram
182 User’s Manual  U11761EJ6V0UM

Chapter 8  Floating Point Unit
8.2 FPU Features
This section briefly describes the operating model, the load/store instruction set, and
the coprocessor interface in the FPU.  A more detailed description is given in the
sections that follow.
• Full 64-bit Operation. When theFRbit in the CPUStatusregister equals
0, the FPU is in 32-bit mode and contains thirty-two 32-bit registers that
hold single- or, when used in pairs, double-precision values.  When the
FRbit in the CPUStatusregister equals 1, the FPU is in 64-bit mode and
the registers are expanded to 64 bits wide.  Each register can hold single-
or double-precision values. The FPU also includes a 32-bitControl/Status
register that provides access to all IEEE-Standard exception handling
capabilities.
• Load and Store Instruction Set. Like the CPU, the FPU uses a load- and
store-oriented instruction set, with single-cycle load and store operations.
• Tightly Coupled Coprocessor Interface. The FPU resides on-chip to
form a tightly coupled unit with a seamless integration of floating-point
and fixed-point instruction sets.  Since each unit receives and executes
instructions in parallel, some floating-point instructions can execute at the
same single-cycle-per-instruction rate as fixed-point instructions.
8.3 FPU Programming Model
This section describes the set of FPU registers and their data organization.  The FPU
registers includeFloating-Point General Purposeregisters(FGRs) and two control
registers:Control/StatusandImplementation/Revision.
8.4 Floating-Point General Registers (FGRs)
The FPU has a set ofFloating-Point General Purposeregisters(FGRs) that can be
accessed in the following ways:
User’s Manual  U11761EJ6V0UM 183

Chapter 8  Floating Point Unit
• As 32 general purpose registers (32 FGRs), each of which is 32 bits wide
when theFRbit in the CPUStatusregister equals 0; or as 32 general
purpose registers (32 FGRs), each of which is 64-bits wide whenFR
equals 1.  The CPU accesses these registers through move, load, and store
instructions.
• As 16 floating-point registers (see the next section for a description of
FPRs), each of which is 64-bits wide, when theFRbit in the CPUStatus
register equals 0.  The FPRs hold values in either single- or double-
precision floating-point format.  Each FPR corresponds to adjacently
numbered FGRs as shown in Figure 8-2.
• As 32 floating-point registers (see the next section for a description of
FPRs), each of which is 64-bits wide, when theFRbit in the CPUStatus
register equals 1.  The FPRs hold values in either single- or double-
precision floating-point format.  Each FPR corresponds to an FGR as
shown in Figure 8-2.
Floating-Point	Floating-Point	Floating-Point	Floating-Point
Registers (FPR)General Purpose Registers Registers (FPR)General Purpose Registers
(FR = 0) (FR = 1)
(FGR) (FGR)
31	0	63	0
FPR0 FGR0
(least) FGR0
FPR0
(most)	FGR1	FPR1	FGR1
FPR2 FGR2
(least) FGR2
FPR2
| (most) | FGR3 | FPR3 | FGR3 |
| --- | --- | --- | --- |
| • | • • | • |  |
| • | • • | • |  |
| • | • • FPR28 FGR28 (least) FGR28 | • |  |
FPR28
FGR29
(most)	FGR29	FPR29
FGR30	FPR30	FGR30
(least)
FPR30
(most)	FPR31	FGR31
FGR31
Floating-Point
Control Registers
(FCR)
Control/Status Register Implementation/Revision Register
31	FCR31	0	0
31 FCR0
Figure  8-2   FPU Registers
184 User’s Manual  U11761EJ6V0UM

Chapter 8  Floating Point Unit
8.5 Floating-Point Registers
The FPU provides:
• 16Floating-Pointregisters (FPRs) when theFRbit in theStatusregister
equals 0, or
• 32Floating-Pointregisters (FPRs) when theFRbit in theStatusregister
equals 1.
These 64-bit registers hold floating-point values during floating-point operations and
are physically formed from theGeneral Purposeregisters (FGRs).  When theFRbit
in theStatusregister equals 1, theFPRreferences a single 64-bitFGR.
TheFPRs hold values in either single- or double-precision floating-point format.  If
theFRbit equals 0, only even numbers (theleastregister, as shown in Figure 8-2) can
be used to addressFPRs.  When theFRbit is set to a 1, allFPRregister numbers are
valid.
If theFRbit equals 0 during a double-precision floating-point operation, the general
registers are accessed in double pairs.  Thus, in a double-precision operation, selecting
Floating-Point Register 0(FPR0) actually addresses adjacentFloating-Point General
PurposeregistersFGR0andFGR1.
User’s Manual  U11761EJ6V0UM 185

Chapter 8  Floating Point Unit
8.6 Floating-Point Control Registers
The FPU has 32 control registers (FCRs) that can only be accessed by move
operations. TheFCRs are described below:
• TheImplementation/Revisionregister(FCR0)holds revision information
about the FPU.
• TheControl/Statusregister(FCR31)controls and monitors exceptions,
holds the result of compare operations, and establishes rounding modes.
• FCR1toFCR30are reserved.
Table 8-1 lists the assignments of theFCRs.
Table 8-1   Floating-Point Control Register Assignments
FCR Number Use
FCR0 Coprocessor implementation and revision register
FCR1 to FCR30 Reserved
FCR31 Rounding mode, cause, trap enables, and flags
186 User’s Manual  U11761EJ6V0UM

Chapter 8  Floating Point Unit
8.6.1 Implementation and Revision Register (FCR0)
The read-onlyImplementation and Revisionregister (FCR0) specifies the
implementation and revision number of the FPU.  This information can determine the
coprocessor revision and performance level, and can also be used by diagnostic
software.
Figure 8-3 shows the layout of the register; Table 8-2 describes theImplementation
and Revisionregister (FCR0) fields.
Implementation/Revision Register (FCR0)
31	16 15	87	0
0	Imp	Rev
16 88
Figure  8-3   Implementation/Revision Register
Table 8-2   FCR0 Fields
Field Description
Imp Implementation number (0x23)
Rev Revision number in the form ofy.x
Reserved.  Must be written as zeroes, and returns zeroes when
0
read.
The revision number is a value of the formy.x, where:
• yis a major revision number held in bits 7:4.
• xis a minor revision number held in bits 3:0.
The revision number distinguishes some chip revisions; however, MIPS does not
guarantee that changes to its chips are necessarily reflected by the revision number, or
that changes to the revision number necessarily reflect real chip changes.  For this
reason revision number values are not listed, and software should not rely on the
revision number to characterize the chip.
User’s Manual  U11761EJ6V0UM 187

Chapter 8  Floating Point Unit
8.6.2 Control/Status Register (FCR31)
TheControl/Statusregister(FCR31) contains control and status information that can
be accessed by instructions in either Kernel or User mode.FCR31also controls the
arithmetic rounding mode and enables User mode traps, as well as identifying any
exceptions that may have occurred in the most recently executed instruction, along
with any exceptions that may have occurred without being trapped.
Figure 8-4 shows the format of theControl/Statusregister, and Table 8-3 describes the
Control/Statusregister fields.  Figure 8-5 shows theControl/StatusregisterCause,
Flag,andEnablefields.
Control/Status Register (FCR31)
31	25 24   23  22	18   17	12   11	7   6	2   1	0
Cause	Enables	Flags
RM
CC7-CC1	FSCC0	0
E V Z O U I	V Z O U I	V Z O U I
71565521
Legend:
E = Unimplemented Operation	Z = Division by zero	U = Underflow
V = Invalid Operation	O = Overflow	I = Inexact Operation
Figure  8-4   FP Control/Status Register Bit Assignments
Table 8-3   Control/Status Register Fields
Field Description
CC7-CC1 Condition bits 7-1. See description ofControl/StatusregisterConditionbit.
TheFSbit enables a value that cannot be normalized (denormarlized number) to be
flushed. When theFSbit is set and the enable bit is not set for the underflow exception
and illegal exception, the result of the denormalized number does not cause the
unimplemented operation exception, but is flushed. Whether the flushed result is 0 or
FS
the minimum normalized value is determined depending on the rounding mode (refer
toTable 8-4).  On the V 5000, even if the FS bit is set, if a madd, msub, nmadd or
R
nmsub instruction encounters a denormalized result during the multiply portion of the
calculation, an unimplemented operation exception is always taken.
CC0 Condition bit 0.  See description ofControl/StatusregisterConditionbit.
Cause Cause bits. See description ofControl/StatusregisterCause, Flag,andEnablebits.
Enables Enable bits.  See description ofControl/StatusregisterCause, Flag,andEnablebits.
Flags Flag bits.  See description ofControl/StatusregisterCause, Flag,andEnablebits.
Rounding mode bits.  See description ofControl/StatusregisterRounding Mode
RM
Controlbits.
188 User’s Manual  U11761EJ6V0UM

Chapter 8  Floating Point Unit
Bit #17	16	15	14	13	12
Cause
EZOUIV
Bits
Bit #11	10	9	8	7
Enable
VZO U  I
Bits
Bit #6543 2
Flag
VZO U  I
Bits
Inexact Operation
Underflow
Overflow
Division by Zero
Invalid Operation
Unimplemented Operation
Figure  8-5   Control/Status Register Cause, Flag, and Enable Fields
(1) Accessing the Control/Status Register
When theControl/Statusregister is read by a Move Control From Coprocessor 1
(CFC1) instruction, all unfinished instructions in the pipeline are completed before the
contents of the register are moved to the main processor.  If a floating-point exception
occurs as the pipeline empties, the FP exception is taken and the CFC1 instruction is
re-executed after the exception is serviced.
The bits in theControl/Statusregister can be set or cleared by writing to the register
using a Move Control To Coprocessor 1(CTC1) instruction.FCR31must only be
written to when the FPU is not actively executing floating-point operations; this can be
ensured by reading the contents of the register to empty the pipeline.
(2) IEEE Standard 754
IEEE Standard 754 specifies that floating-point operations detect certain exceptional
cases, raise flags, and can invoke an exception handler when an exception occurs.
These features are implemented in the MIPS architecture with theCause,Enable, and
Flagfields of theControl/Statusregister.  TheFlagbits implement IEEE 754
exception status flags, and theCauseandEnablebits implement exception handling.
User’s Manual  U11761EJ6V0UM 189

Chapter 8  Floating Point Unit
(3) Control/Status Register FS Bit
TheFSbit enables a value that cannot be normalized (denormarlized number) to be
flushed. When theFSbit is set and the enable bit is not set for the underflow exception
and illegal exception, the result of the denormalized number does not cause the
unimplemented operation exception, but is flushed. Whether the flushed result is 0 or
the minimum normalized value is determined depending on the rounding mode (refer
toTable 8-4).
However, for MADD.fmt, NMADD.fmt, MSUB.fmt, and NMSUB.fmt instructions,
the V 5000 will always take an unimplemented operation exception if the intermediate
R
multiply result is a denormalized value regardless of the value of theFSbit.
Table 8-4   Flush Values of Denormalized Number Results
Flushed Result
Denormalized
Rounding Mode
Number Result
| RN | RZ Emin | RP | RM |
| --- | --- | --- | --- |
| Positive | +0 | +0 | +2 +0 Emin |
| Negative | –0 | –0 | –0 –2 (4) Control/Status Register Condition Bit When a floating-point Compareoperation takes place, the result is stored at bit 23 and bits 31:25, theConditionbits, to save or restore the state of the condition line.  TheCC bit is set to 1 if the condition is true; the bit is cleared to 0 if the condition is false.  Bit 23 and bits 31:25 are affected only by compareand Move Control To FPUinstructions. (5) Control/Status Register Cause, Flag, and Enable Fields Figure 8-5 illustrates theCause,Flag, andEnablefields of theControl/Statusregister. Cause Bits Bits 17:12 in theControl/Statusregister containCausebits, as shown in Figure 8-5, which reflect the results of the most recently executed instruction. TheCausebits are a logical extension of the CP0Causeregister; they identify the exceptions raised by the last floating-point operation and raise an interrupt or exception if the corresponding enable bit is set.  If more than one exception occurs on a single instruction, each appropriate bit is set. 190 User’s Manual  U11761EJ6V0UM |

Chapter 8  Floating Point Unit
TheCausebits are written by each floating-point operation (but not by load, store, or
move operations).  The Unimplemented Operation (E) bit is set to a 1 if software
emulation is required, otherwise it remains 0.  The other bits are set to 0 or 1 to indicate
the occurrence or non-occurrence (respectively) of an IEEE 754 exception.
When a floating-point exception is taken, no results are stored, and the only state
affected is theCausebit.
Enable Bits
A floating-point exception is generated any time aCausebit and the corresponding
Enablebit are set.  A floating-point operation that sets an enabledCausebit forces an
immediate exception, as does setting bothCauseandEnablebits with CTC1.
There is no enable for Unimplemented Operation (E).  Setting Unimplemented
Operation always generates a floating-point exception.
Before returning from a floating-point exception, software must first clear the enabled
Causebits with a CTC1 instruction to prevent a repeat of the interrupt.  Thus, User
mode programs can never observe enabledCausebits set; if this information is
required in a User mode handler, it must be passed somewhere other than theStatus
register.
For a floating-point operation that sets only unenabledCausebits, no exception occurs
and the default result defined by IEEE 754 is stored.  In this case, the exceptions that
were caused by the immediately previous floating-point operation can be determined
by reading theCausefield.
Flag Bits
TheFlagbits are cumulative and indicate that an exception was raised by an operation
that was executed since they were explicitly reset.Flagbits are set to 1 if an IEEE 754
exception is raised, otherwise they remain unchanged.  TheFlagbits are never cleared
as a side effect of floating-point operations; however, they can be set or cleared by
writing a new value into theStatusregister, using a Move To Coprocessor Control
instruction.
When a floating-point exception is taken, the flag bits are not set by the hardware;
floating-point exception software is responsible for setting these bits before invoking
a user handler.
User’s Manual  U11761EJ6V0UM 191

Chapter 8  Floating Point Unit
(6) Control/Status Register Rounding Mode Control Bits
Bits 1 and 0 in theControl/Statusregister constitute theRounding Mode(RM) field.
As shown in Table 8-5 these bits specify the rounding mode that the FPU uses for all
floating-point operations.
Table 8-5   Rounding Mode Bit Decoding
Rounding
Mode	Mnemonic	Description
RM(1:0)
Round result to nearest representable value; round to
0RNvalue with least-significant bit 0 when the two nearest
representable values are equally near.
Round toward 0: round to value closest to and not
1RZ
greater in magnitude than the infinitely precise result.
Round toward +∞:round to value closest to and not
2RP
less than the infinitely precise result.
Round toward –∞: round to value closest to and not
3RM
greater than the infinitely precise result.
8.7 Floating-Point Formats
The FPU performs both 32-bit (single-precision) and 64-bit (double-precision) IEEE
standard floating-point operations.  The 32-bit single-precision format has a 24-bit
signed-magnitude fraction field (f+s) and an 8-bit exponent (e), as shown in Figure 8-
6.
31	30	23	22	0
se f
Sign	Exponent	Fraction
18 23
Figure  8-6   Single-Precision Floating-Point Format
The 64-bit double-precision format has a 53-bit signed-magnitude fraction field (f+s)
and an 11-bit exponent, as shown in Figure 8-7.
192 User’s Manual  U11761EJ6V0UM

Chapter 8  Floating Point Unit
| 63 | 62 se f | 52 | 51 | 0 |
| --- | --- | --- | --- | --- |
| Sign | Exponent 111 52 Figure  8-7   Double-Precision Floating-Point Format As shown in the above figures, numbers in floating-point format are composed of three fields: • sign field,s • biased exponent,e = E + bias • fraction,f = .bb....b 1 2 p–1 The range of the unbiased exponentEincludes every integer between the two values | Fraction |  |  |
| E | and E | inclusive, together with two other reserved values: min max •E-1 (to encode±0 and denormalized numbers) min ∞ •E+1 (to encode± and NaNs [Not a Number]) max For single- and double-precision formats, each representable nonzero numerical value has just one encoding. For single- and double-precision formats, the value of a number,v, is determined by the equations shown in Table 8-6. Table 8-6   Calculating Values in Single and Double-Precision Formats No. Equation |  |  |
| (1) | if E = E | +1 andf≠0, thenvis NaN, regardless ofs max s |  |  |
| (2) | if E = E | +1 and f = 0, thenv= (–1) ∞ max s E |  |  |
| (3) | if E | ≤E≤E | , thenv= (–1)2 (1.f) min max s Emin |  |
| (4) | if E = E | –1and f≠0, thenv= (–1)2 min s | (0.f) |  |
| (5) | if E = E | –1 and f = 0, thenv= (–1)0 min For all floating-point formats, ifvis NaN, the most-significant bit offdetermines whether the value is a signaling or quiet NaN:vis a signaling NaN if the most- significant bit offis set, otherwise,vis a quiet NaN. User’s Manual  U11761EJ6V0UM 193 |  |  |

Chapter 8  Floating Point Unit
Table 8-7 defines the values for the format parameters; minimum and maximum
floating-point values are given in Table 8-8.
Table 8-7   Floating-Point Format Parameter Values
Format
Parameter
Single Double
| E | +127 | +1023 max |
| --- | --- | --- |
| E | –126 | –1022 min |
| Exponentbias | +127 | +1023 |
| Exponent width in bits | 8 | 11 |
| Integer bit | hidden | hidden |
| f  (Fraction width in bits) | 24 | 53 |
| Format width in bits | 32 Table 8-8   Minimum and Maximum Floating-Point Values Type Value Float Minimum 1.40129846e–45 Float Minimum Norm 1.17549435e–38 Float Maximum 3.40282347e+38 Double Minimum 4.9406564584124654e–324 Double Minimum Norm 2.2250738585072014e–308 Double Maximum 1.7976931348623157e+308 8.8 Binary Fixed-Point Format Binary fixed-point values are held in 2’s complement format.  Unsigned fixed-point values are not directly provided by the floating-point instruction set.  Figure 8-8 illustrates binary fixed-point format; Table 8-9 lists the binary fixed-point format fields. 194 User’s Manual  U11761EJ6V0UM | 64 |

Chapter 8  Floating Point Unit
31	30	0
Sign Integer
1 31
Figure  8-8   Binary Fixed-Point Format
Field assignments of the binary fixed-point format are:
Table 8-9   Binary Fixed-Point Format Fields
Field Description
sign sign bit
integer integer value
8.9 Floating-Point Instruction Set Overview
All FPU instructions are 32 bits long, aligned on a word boundary.  They can be
divided into the following groups:
• Load, Store, and Moveinstructions move data between memory, the
main processor, and theFPU General Purposeregisters.
• Conversioninstructions perform conversion operations between the
various data formats.
• Computationalinstructions perform arithmetic operations on floating-
point values in the FPU registers.
• Compareinstructions perform comparisons of the contents of registers
and set a conditional bit based on the results.
• Branch on FPU Conditioninstructions perform a branch to the specified
target if the specified coprocessor condition is met.
In the instruction formats shown in Table 8-10 through Table 8-13, thefmtappended
to the instruction opcode specifies the data format:Sspecifies single-precision binary
floating-point,Dspecifies double-precision binary floating-point,Wspecifies 32-bit
binary fixed-point,andLspecifies 64-bit (long) binary fixed-point.
User’s Manual  U11761EJ6V0UM 195

Chapter 8  Floating Point Unit
Table 8-10   FPU Instruction Summary: Load, Move and Store Instructions
OpCode                                                Description
LWC1 Load Word to FPU
LWXC1 Load Word Indexed to FPU
SWC1 Store Word from FPU
SWXC1 Store Word Indexed from FPU
LDC1 Load Doubleword to FPU
LDXC1 Load Doubleword Indexed to FPU
SDC1 Store Doubleword From FPU
SDXC1 Store Doubleword Indexed From FPU
MTC1 Move Word To FPU
MFC1 Move Word From FPU
CTC1 Move Control Word To FPU
CFC1 Move Control Word From FPU
DMTC1 Doubleword Move To FPU
DMFC1 Doubleword Move From FPU
PREFX Prefetch Indexed - Register + Register
Table 8-11   FPU Instruction Summary: Conversion Instructions
OpCode                                                Description
CVT.S.fmt Floating-point Convert to Single FP
CVT.D.fmt Floating-point Convert to Double FP
CVT.W.fmt Floating-point Convert to 32-bit Fixed Point
CVT.L.fmt Floating-point Convert to 64-bit Fixed Point
ROUND.W.fmt Floating-point Round to 32-bit Fixed Point
ROUND.L.fmt Floating-point Round to 64-bit Fixed Point
TRUNC.W.fmt Floating-point Truncate to 32-bit Fixed Point
TRUNC.L.fmt Floating-point Truncate to 64-bit Fixed Point
CEIL.W.fmt Floating-point Ceiling to 32-bit Fixed Point
CEIL.L.fmt Floating-point Ceiling to 64-bit Fixed Point
FLOOR.W.fmt Floating-point Floor to 32-bit Fixed Point
FLOOR.L.fmt Floating-point Floor to 64-bit Fixed Point
196 User’s Manual  U11761EJ6V0UM

Chapter 8  Floating Point Unit
Table 8-12   FPU Instruction Summary: Computational Instructions
OpCode                                                Description
ADD.fmt Floating-point Add
SUB.fmt Floating-point Subtract
MADD Floating-point Multiply-Add
MSUB Floating-point Multiply-Subtract
NMADD Floating-point Negative Multiply-Add
NMSUB Floating-point Negative Multiply-Subtract
MUL.fmt Floating-point Multiply
DIV.fmt Floating-point Divide
ABS.fmt Floating-point Absolute Value
MOV.fmt Floating-point Move
NEG.fmt Floating-point Negate
SQRT.fmt Floating-point Square Root
RECIP Floating-point Reciprocal
RSQRT Floating-point Reciprocal Square Root
Table 8-13   FPU Instruction Summary: Compare and Branch Instructions
OpCode                                                Description
C.cond.fmt Floating-point Compare
BC1T Branch on FPU True
BC1F Branch on FPU False
BC1TL Branch on FPU True Likely
BC1FL Branch on FPU False Likely
8.9.1 Floating-Point Load, Store, and Move Instructions
This section discusses the manner in which the FPU uses the load, store and move
instructions listed in Table 8-10.
(1) Transfers Between FPU and Memory
All data movement between the FPU and memory is accomplished by using one of the
following instructions:
User’s Manual  U11761EJ6V0UM 197

Chapter 8  Floating Point Unit
• Load Word To Coprocessor 1 (LWC1) or Store Word From
Coprocessor 1 (SWC1) instructions, which reference a single 32-bit
word of the FPU general registers
• Load Doubleword (LDC1) or Store Doubleword (SDC1) instructions,
which reference a 64-bit doubleword.
These load and store operations are unformatted; no format conversions are performed
and therefore no floating-point exceptions can occur due to these operations.
(2) Transfers Between FPU and CPU
Data can also be moved directly between the FPU and the CPU by using one of the
following instructions:
• Move To Coprocessor 1(MTC1)
• Move From Coprocessor 1(MFC1)
• Doubleword Move To Coprocessor 1(DMTC1)
• Doubleword Move From Coprocessor 1(DMFC1)
Like the floating-point load and store operations, these operations perform no format
conversions and never cause floating-point exceptions.
(3) Load Delay and Hardware Interlocks
The instruction immediately following a load can use the contents of the loaded
register.  In such cases the hardware interlocks, requiring additional real cycles; for this
reason, scheduling load delay slots is desirable, although it is not required for
functional code.
(4) Data Alignment
All coprocessor loads and stores reference the following aligned data items:
• For word loads and stores, the access type is always WORD, and the low-
order 2 bits of the address must always be 0.
• For doubleword loads and stores, the access type is always
DOUBLEWORD, and the low-order 3 bits of the address must always be
0.
198 User’s Manual  U11761EJ6V0UM

Chapter 8  Floating Point Unit
(5) Endianness
Regardless of byte-numbering order (endianness) of the data, the address specifies the
byte that has the smallest byte address in the addressed field. For a big-endian system,
it is the leftmost byte; for a little-endian system, it is the rightmost byte.
8.9.2 Floating-Point Conversion Instructions
Conversion instructions perform conversions between the various data formats such as
single- or double-precision, fixed- or floating-point formats.
8.9.3 Floating-Point Computational Instructions
Computational instructions perform arithmetic operations on floating-point values, in
registers.  There are two categories of computational instructions:
• 3-Operand Register-Typeinstructions, which perform floating-point
addition, subtraction, multiplication, and division
• 2-Operand Register-Typeinstructions, which perform floating-point
absolute value, move, negate, and square root operations
For a detailed description of each instruction, refer to the MIPS IV instruction set
manual.
(1) Branch on FPU Condition Instructions
The Branch on FPU (coprocessor unit 1) condition instructions that can test the result
of the FPU compare (C.cond) instructions.  For a detailed description of each
instruction, refer to the MIPS IV instruction set manual.
(2) Floating-Point Compare Operations
The floating-point compare (C.fmt.cond) instructions interpret the contents of two
FPU registers (fs, ft) in the specified format (fmt) and arithmetically compare them.  A
result is determined based on the comparison and conditions (cond) specified in the
instruction.
Table 8-14 lists the mnemonics for the compare instruction conditions.
User’s Manual  U11761EJ6V0UM 199

Chapter 8  Floating Point Unit
Table 8-14   Mnemonics and Definitions of Compare Instruction Conditions
| Mnemonic | Definition | Mnemonic | Definition |
| --- | --- | --- | --- |
| T | True | F | False |
| OR | Ordered | UN | Unordered |
| NEQ | Not Equal Ordered or Less Than or Greater | EQ | Equal |
| OLG | UEQ | Unordered or Equal Than Unordered or Greater Than or |  |
| UGE | OLT | Ordered Less Than Equal |  |
| OGE | Ordered Greater Than | ULT | Unordered or Less Than |
| UGT | Unordered or Greater Than | OLE | Ordered Less Than or Equal Unordered or Less Than or |
| OGT | Ordered Greater Than Equal | ULE |  |
| ST | Signaling True | SF | Signaling False Greater Than, or Less Than or Not Greater Than or Less Than GLE NGLE Equal or Equal |
| SNE | Signaling Not Equal | SEQ | Signaling Equal |
| GL | Greater Than or Less Than | NGL | Not Greater Than or Less Than |
| NLT | Not Less Than | LT | Less Than |
| GE | Greater Than or Equal | NGE | Not Greater Than or Equal |
| NLE | Not Less Than or Equal | LE | Less Than or Equal |
| GT | Greater Than | NGT | Not Greater Than 8.10 FPU Instruction Pipeline Overview The FPU provides an instruction pipeline that parallels the CPU instruction pipeline. It shares the same five-stage pipeline architecture with the CPU. 8.10.1 Instruction Execution Figure 8-9 illustrates the 5-instruction overlap in the FPU pipeline. 200 User’s Manual  U11761EJ6V0UM |

Chapter 8  Floating Point Unit
One	One	One	One	One
Cycle	Cycle	Cycle	Cycle	Cycle
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
1I    2I   1R  2R  1A  2A  1D  2D  1W 2W
Figure  8-9   FPU Instruction Pipeline
Figure 8-9 assumes that one instruction is completed every PCycle.  Most FPU
instructions, however, require more than one cycle in the EX stage. This means the
FPU must stall the pipeline if an instruction execution cannot proceed because of
register or resource conflicts.
8.10.2 Instruction Execution Cycle Time
Unlike the CPU, which executes almost all instructions in a single cycle, more time
may be required to execute FPU instructions.
Table 8-15 gives the minimum latency, in processor pipeline cycles, of each floating-
point operation for the currently implemented configurations. These latency
calculations assume the result of the operation is immediately used in a succeeding
operation.
User’s Manual  U11761EJ6V0UM 201

Chapter 8  Floating Point Unit
Table 8-15   Floating-Point Operation Latencies
Pipeline Cycles Pipeline Cycles
| Operation | Latency/Repeat SDWL SD | Operation | Latency/Repeat |
| --- | --- | --- | --- |
| ADD.fmt | 4/1 | 4/1 | BC1T 1/1 |
| SUB.fmt | 4/1 | 4/1 | BC1F 1/1 |
| MUL.fmt | 4/1 | 5/2 | BC1TL 1/1 |
| DIV.fmt | 21/19 | 36/34 | BC1FL 1/1 SWC1, |
| SQRT.fmt | 21/19 | 36/34 | 2/1 |
SDC1
LDC1,
RECIP	21/19	36/34	2/1
LWC1
LWXC1,
RSQRT	38/36	68/66	2/1
LDXC1
SWXC1,
ABS.fmt	1/1	1/1	2/1
SDXC1
MTC1,
MOV.fmt	1/1	1/1	2/1
DMTC1
MFC1,
NEG.fmt	1/1	1/1	2/1
DMFC1
ROUND.W/
| 4/1 | 4/1 | CTC1 TRUNC.W | 3/3 |
| --- | --- | --- | --- |
| ROUND.L/ | ** | ** |  |
| 4/1 | 4/1 | CFC1 TRUNC.L CEIL.W/ | 2/2 |
| 4/1 | 4/1 | MADD | 4/1 5/2 FLOOR.W |
| CEIL.L/ | ** | ** |  |
| 4/1 | 4/1 | MSUB | 4/1 5/2 FLOOR.L |
| CVT.D.fmt | 4/1 | (a) | 4/1 4/1* NMADD 4/1 5/2 |
| CVT.S.fmt | (a) | 4/1 | 6/3 6/3* NMSUB 4/1 5/2 |
| CVT.[W,L] | 4/1 | 4/1 |  |
| C.cond.fmt | 1/1 (a) .........These operations are illegal. * ..........Trap on greater than 52 bits of significance. ** ........Trap on greater than 53 bits of significance. 202 User’s Manual  U11761EJ6V0UM | 1/1 |  |

Chapter 8  Floating Point Unit
8.10.3 Instruction Scheduling Constraints
The FPU resource scheduler is kept from issuing instructions to the FPU op units
(adder, multiplier, and divider) by the limitations in their micro-architectures.  An FPU
ALU instruction can be issued at the same time as any other non-FP-ALU instructions.
This includes all integer instructions as well as floating-point loads and stores.
User’s Manual  U11761EJ6V0UM 203

Chapter 9  Floating Point Exceptions
This chapter describes FPU floating-point exceptions, including FPU exception types,
exception trap processing, exception flags, saving and restoring state when handling an
exception, and trap handlers for IEEE Standard 754 exceptions.
A floating-point exception occurs whenever the FPU cannot handle either the operands
or the results of a floating-point operation in its normal way.   The FPU responds by
generating an exception to initiate a software trap or by setting a status flag.
9.1 Exception Types
The FPControl/Statusregister described in Chapter 8 contains anEnablebit for each
exception type; exceptionEnablebits determine whether an exception will cause the
FPU to initiate a trap or set a status flag.
• If a trap is taken, the FPU remains in the state found at the beginning of
the operation and a software exception handling routine executes.
• If no trap is taken, an appropriate value is written into the FPU
destination register and execution continues.
The FPU supports the five IEEE Standard 754 exceptions:
• Inexact (I)
• Underflow (U)
• Overflow (O)
204 User’s Manual  U11761EJ6V0UM

Chapter 9  Floating Point Exceptions
• Division by Zero (Z)
• Invalid Operation (V)
Causebits,Enables, andFlagbits (status flags) are used.
The FPU adds a sixth exception type, Unimplemented Operation (E), to use when the
FPU cannot implement the standard MIPS floating-point architecture, including cases
in which the FPU cannot determine the correct exception behavior.  This exception
indicates the use of a software implementation. The Unimplemented Operation
exception has noEnableorFlagbit; whenever this exception occurs, an
unimplemented exception trap is taken (if the FPU interrupt input to the CPU is
enabled).
Figure 9-1 illustrates theControl/Statusregister bits that support exceptions.
Bit #17	16	15	14	13	12
Cause
EZOUIV
Bits
Bit #11	10	9	8	7
Enable
VZO U  I
Bits
Bit #654 3 2
Flag
VZO U  I
Bits
Inexact Operation
Underflow
Overflow
Division by Zero
Invalid Operation
Unimplemented Operation
Figure  9-1   Control/Status Register Exception/Flag/Trap/Enable Bits
Each of the five IEEE Standard 754 exceptions (V, Z, O, U, I) is associated with a trap
under user control, and is enabled by setting one of the fiveEnablebits.  When an
exception occurs, the correspondingCausebit is set.  If the correspondingEnablebit
is not set, theFlagbit is also set.  If the correspondingEnablebit is set, theFlagbit is
not set and the FPU generates an interrupt to the CPU.  Subsequent exception
processing allows a trap to be taken.
User’s Manual  U11761EJ6V0UM 205

Chapter 9  Floating Point Exceptions
9.2 Exception Trap Processing
When a floating-point exception trap is taken, theCauseregister indicates the floating-
point coprocessor is the cause of the exception trap.  The Floating-Point Exception
(FPE) code is used, and theCausebits of the floating-pointControl/Statusregister
indicate the reason for the floating-point exception.  These bits are, in effect, an
extension of the system coprocessorCauseregister.
9.3 Flags
AFlagbit is provided for each IEEE exception.  ThisFlagbit is set to a 1 on the
assertion of its corresponding exception, with no corresponding exception trap
signaled.
TheFlagbit is reset by writing a new value into theStatusregister; flags can be saved
and restored by software either individually or as a group.
When no exception trap is signaled, floating-point coprocessor takes a default action,
providing a substitute value for the exception-causing result of the floating-point
operation.  The particular default action taken depends upon the type of exception.
Table 9-1 lists the default action taken by the FPU for each of the IEEE exceptions.
206 User’s Manual  U11761EJ6V0UM

Chapter 9  Floating Point Exceptions
Table 9-1   Default FPU Exception Actions
Rounding
Field	Description	Default action
Mode
Inexact
I	Any	Supply a rounded result
exception
Modify underflow values to 0 with the sign of the intermediate
RN
result
Modify underflow values to 0 with the sign of the intermediate
RZ
Underflow result
U
exception
Modify positive underflows to the format’s smallest positive
RP
finite number; modify negative underflows to -0
Modify negative underflows to the format’s smallest negative
RM
finite number; modify positive underflows to 0
Modify overflow values to∞with the sign of the intermediate
RN
result
Modify overflow values to the format’s largest finite number
RZ
with the sign of the intermediate result
Overflow
O
exception
Modify negative overflows to the format’s most negative
RP
finite number; modify positive overflows to +∞
Modify positive overflows to the format’s largest finite
RM
number; modify negative overflows to –∞
Division by
| Z | Any | Supply a properly signed∞ zero Invalid |
| --- | --- | --- |
| V | Any | Supply a quiet Not a Number (NaN) operation Table 9-2 lists the exception-causing situations and contrasts the behavior of the FPU with the requirements of the IEEE Standard 754. User’s Manual  U11761EJ6V0UM 207 |

Chapter 9  Floating Point Exceptions
Table 9-2   FPU Exception-Causing Conditions
IEEE
FPA Internal	Trap	Trap
Standard Notes
Result	Enable	Disable
754
| Inexact result | I | I | I | Loss of accuracy a |
| --- | --- | --- | --- | --- |
| Exponent overflow | O,I | O,I | O,I | Normalized exponent > E max Zero is (exponent = E -1, min |
| Division by zero | Z mantissa = 0) | Z | Z |  |
| Overflow on convert | V | E | E | Source out of integer range |
| Signaling NaN source | V | V | V |  |
| Invalid operation | V | V | V | 0/0, etc. |
| Exponent underflow | U | E | E | Normalized exponent < E min |
| Denormalized or | Denormalized is (exponent = E min | -1 |  |  |
| None | E QNaN and mantissa <> 0) a. The IEEE Standard 754 specifies an inexact exception on overflow only if the overflow trap is disabled. 9.4 FPU Exceptions The following sections describe the conditions that cause the FPU to generate each of its exceptions, and details the FPU response to each exception-causing condition. 9.4.1 Inexact Exception (I) The FPU generates the Inexact exception if one of the following occurs: • the rounded result of an operation is not exact, or • the rounded result of an operation overflows, or • the rounded result of an operation underflows and both the Underflow and InexactEnablebits are not set and theFSbit is set. The FPU usually examines the operands of floating-point operations before execution actually begins, to determine (based on the exponent values of the operands) if the operation canpossiblycause an exception.  If there is a possibility of an instruction causing an exception trap, the FPU uses a coprocessor stall to execute the instruction. 208 User’s Manual  U11761EJ6V0UM | E |  |  |

Chapter 9  Floating Point Exceptions
It is impossible, however, for the FPU to predetermine if an instruction will produce an
inexact result.  If Inexact exception traps are enabled, the FPU uses the coprocessor
stall mechanism to execute allfloating-point operations that require more than one
cycle.  Since this mode of execution can impact performance, Inexact exception traps
should be enabled only when necessary.
Trap Enabled Results:If Inexact exception traps are enabled, the result register is not
modified and the source registers are preserved.
Trap Disabled Results:The rounded or overflowed result is delivered to the
destination register if no other software trap occurs.
9.4.2 Invalid Operation Exception (V)
The Invalid Operation exception is signaled if one or both of the operands are invalid
for an implemented operation.  When the exception occurs without a trap, the MIPS
ISA defines the result as a quiet Not a Number (NaN). The invalid operations are:
• Addition or subtraction: magnitude subtraction of infinities, such as:
( +∞) + ( –∞) or ( –∞) – ( –∞)
• Multiplication: 0 times∞, with any signs
• Division: 0/0, or∞/∞, with any signs
• Comparison of predicates involving<or>without?, when the operands
are unordered
• Comparison or a Convert From Floating-point Operation on a signaling
NaN.
• Any arithmetic operation on a signaling NaN.  A move (MOV) operation
is not considered to be an arithmetic operation, but absolute value (ABS)
and negate (NEG) are considered to be arithmetic operations and cause
this exception if one or both operands is a signaling NaN.
• Square root:√x, where x is less than zero
Software can simulate the Invalid Operation exception for other operations that are
invalid for the given source operands.  Examples of these operations include IEEE
Standard 754-specified functions implemented in software, such as Remainder:xREM
y, whereyis 0 orxis infinite; conversion of a floating-point number to a decimal format
whose value causes an overflow, is infinity, or is NaN; and transcendental functions,
such as ln (–5) or cos–1(3).
Trap Enabled Results:The original operand values are undisturbed.
Trap Disabled Results:A quiet NaN is delivered to the destination register if no other
software trap occurs.
User’s Manual  U11761EJ6V0UM 209

Chapter 9  Floating Point Exceptions
9.4.3 Division-by-Zero Exception (Z)
The Division-by-Zero exception is signaled on an implemented divide operation if the
divisor is zero and the dividend is a finite nonzero number.  Software can simulate this
exception for other operations that produce a signed infinity, such as ln(0), sec(π/2),
–1.
csc(0), or 0
Trap Enabled Results:The result register is not modified, and the source registers are
preserved.
Trap Disabled Results:The result, when no trap occurs, is a correctly signed infinity.
9.4.4 Overflow Exception (O)
The Overflow exception is signaled when the magnitude of the rounded floating-point
result, with an unbounded exponent range, is larger than the largest finite number of
the destination format.  (This exception also sets the Inexact exception andFlagbits.)
Trap Enabled Results:The result register is not modified, and the source registers are
preserved.
Trap Disabled Results:The result, when no trap occurs, is determined by the
rounding mode and the sign of the intermediate result (as listed in Table 9-1).
9.4.5 Underflow Exception (U)
Two related events contribute to the Underflow exception:
Emin
•	creation of a tiny nonzero result between±2	which can cause some
later exception because it is so tiny
• extraordinary loss of accuracy during the approximation of such tiny
numbers by denormalized numbers.
IEEE Standard 754 allows a variety of ways to detect these events, but requires they be
detected the same way for all operations.
Tininess can be detected by one of the following methods:
• after rounding (when a nonzero result, computed as though the exponent
Emin
range were unbounded, would lie strictly between±2 )
• before rounding (when a nonzero result, computed as though the exponent
range and the precision were unbounded, would lie strictly between
Emin
±2 ).
The MIPS architecture requires that tininess be detected after rounding.
Loss of accuracy can be detected by one of the following methods:
210 User’s Manual  U11761EJ6V0UM

Chapter 9  Floating Point Exceptions
• denormalization loss (when the delivered result differs from what would
have been computed if the exponent range were unbounded)
• inexact result (when the delivered result differs from what would have
been computed if the exponent range and precision were both
unbounded).
The MIPS architecture requires that loss of accuracy be detected as an inexact result.
Trap Enabled Results:If Underflow or Inexact traps are enabled, or if theFSbit is
not set, then an Unimplemented exception (E) is generated, and the result register is
not modified.
Trap Disabled Results:If Underflow and Inexact traps are not enabled and theFSbit
is set, the result is determined by the rounding mode and the sign of the intermediate
result (as listed in Table 9-1).
9.4.6 Unimplemented Instruction Exception (E)
Any attempt to execute an instruction with an operation code or format code that has
been reserved for future definition sets theUnimplementedbit in theCausefield in the
FPUControl/Statusregister and traps.  The operand and destination registers remain
undisturbed and the instruction is emulated in software.  Any of the IEEE Standard 754
exceptions can arise from the emulated operation, and these exceptions in turn are
simulated.
The Unimplemented Instruction exception can also be signaled when unusual
operands or result conditions are detected that the implemented hardware cannot
handle properly.  These include:
• Denormalized operand, except for Compare instruction
• Quiet Not a Number operand, except for Compare instruction
• Denormalized result or Underflow, when either Underflow or Inexact
Enablebits are set or theFSbit is not set.
• Reserved opcodes
• Unimplemented formats
• Operations which are invalid for their format (for instance, CVT.S.S)
NOTE:Denormalized and NaN operands are only trapped if the instruction
is a convert or computational operation. Moves do not trap if their operands
are either denormalized or NaNs.
On the V 5000 additional causes of the unimplemented exception include:
R
• If the multiply portion of the madd, msub, nmadd, nmsub instruction
would produce an overflow, underflow or denormal output
User’s Manual  U11761EJ6V0UM 211

Chapter 9  Floating Point Exceptions
• A floating-point to 64-bit fixed-point conversion with an output that
53 53
would be greater than 2 –1 (0×001F FFFF FFFF FFFF) or less than –2
(0×FFE0 0000 0000 0000)
Concerned instructions: CEIL.L.fmt, CVT.L.fmt, FLOOR.L.fmt,
ROUND.L.fmt, TRUNC.L.fmt
• A floating-point to 32-bit fixed-point conversion with an output that
31 31
would be greater than 2	–1 (0×7FFF FFFF) or less than –2	(0×8000
0000)
Concerned instructions: CEIL.W.fmt, CVT.W.fmt, FLOOR.W.fmt,
ROUND.W.fmt, TRUNC.W.fmt
• A 64-bit fixed-point to floating-point conversion with a source operand
52
that would be greater than 2 –1 (0×000F FFFF FFFF FFFF) or less than
52
–2 (0×FFF0 0000 0000 0000)
Concerned instructions: CVT.D.fmt, CVT.S.fmt
• Attempting to execute a MIPS IV floating-point instruction if the MIPS
IV instruction set has not been enabled
The use of this exception for such conditions is optional; most of these conditions are
newly developed and are not expected to be widely used in early implementations.
Loopholes are provided in the architecture so that these conditions can be implemented
with assistance provided by software, maintaining full compatibility with the IEEE
Standard 754.
Trap Enabled Results:The original operand values are undisturbed.
Trap Disabled Results:This trap cannot be disabled.
9.5 Saving and Restoring State
Sixteen or thirty-two doubleword coprocessor load or store operations save or restore
the coprocessor floating-point register state in memory.  The remainder of control and
status information can be saved or restored through Move To/From Coprocessor
Control Register instructions, and saving and restoring the processor registers.
Normally, theControl/Statusregister is saved first and restored last.
When the coprocessorControl/Statusregister (FCR31) is read, and the coprocessor is
executing one or more floating-point instructions, the instruction(s) in progress are
either completed or reported as exceptions. The architecture requires that no more than
one of these pending instructions can cause an exception.  If the pending instruction
cannot be completed, this instruction is placed in theExceptionregister, if present.
212 User’s Manual  U11761EJ6V0UM

Chapter 9  Floating Point Exceptions
Information indicating the type of exception is placed in theControl/Statusregister.
When state is restored, state information in the status word indicates that exceptions
are pending.
Writing a zero value to theCausefield ofControl/Statusregister clears all pending
exceptions, permitting normal processing to restart after the floating-point register
state is restored.
TheCausefield of theControl/Statusregister holds the results of only one instruction;
the FPU examines source operands before an operation is initiated to determine if this
instruction can possibly cause an exception. If an exception is possible, the FPU
executes the instruction in stall mode to ensure that no more than one instruction (that
might cause an exception) is executed at a time.
9.6 Trap Handlers for IEEE Standard 754 Exceptions
The IEEE Standard 754 strongly recommends that users be allowed to specify a trap
handler for any of the five standard exceptions that can compute; the trap handler can
either compute or specify a substitute result to be placed in the destination register of
the operation.
By retrieving an instruction using the processorException Program Counter (EPC)
register, the trap handler determines:
• exceptions occurring during the operation
• the operation being performed
• the destination format
On Overflow or Underflow exceptions (except for conversions), and on Inexact
exceptions, the trap handler gains access to the correctly rounded result by examining
source registers and simulating the operation in software.
On Overflow or Underflow exceptions encountered on floating-point conversions, and
on Invalid Operation and Divide-by-Zero exceptions, the trap handler gains access to
the operand values by examining the source registers of the instruction.
The IEEE Standard 754 recommends that, if enabled, the overflow and underflow traps
take precedence over a separate inexact trap. This prioritization is accomplished in
software; hardware sets both bits.
User’s Manual  U11761EJ6V0UM 213

Chapter 10   Initialization Interface
The V 5000 processor has the following three types of resets; they use theVccOk,
R
ColdReset*,andReset*input signals.
• Power-on reset: starts when the power supply is turned on and completely
reinitializes the internal state machines of the processor without saving any
state information.
• Cold reset: restarts all clocks, but the power supply remains stable.  A
cold reset completely reinitializes the internal state machines of the
processor without saving any state information.
• Warm reset: restarts the processor, but does not affect clocks.  A warm
reset preserves the processor internal state.
The Initialization interface is a serial interface that operates at the frequency of the
SysClockdivided by 256: (SysClock/256). This low-frequency operation allows the
initialization information to be stored in a low-cost ROM device.
10.1 Processor Reset Signals
This section describes the three reset signals,VccOk, ColdReset*,andReset*.
214 User’s Manual   U11761EJ6V0UM

Chapter 10  Initialization Interface
†
| V | Ok:When asserted,V | Okindicates to the processor that the power supply CC CC (Vcc) has been within the specific range for more than 100 milliseconds (ms) and is expected to remain stable.  The assertion ofVccOkinitiates the reading of the boot- time mode control serial stream (described in Initialization Sequence, in this chapter). ColdReset*:TheColdReset*signal must be asserted (low) for either a power-on reset or a cold reset.ColdReset*must be deasserted synchronously withSysClock. Reset*:theReset*signal must be asserted for any reset sequence.  It can be asserted synchronously or asynchronously for a cold reset, or synchronously to initiate a warm reset.Reset*must be deasserted synchronously withSysClock. ModeIn: Serial boot mode data in. ModeClock: Serial boot mode data clock, at theSysClockfrequency divided by 256 (SysClock/256). 10.1.1 Power-on Reset The sequence for a power-on reset is listed below. Note |
| --- | --- | --- |
| 1. | Power-on reset applies stable V | and V IO within the specific range from CC CC the power supply to the processor.  It also supplies a stable, continuous system clock at the processor operational frequency. Note |
| 2. | After at least 100 ms of stable V CC, CC CC is asserted to the processor.  The assertion ofV Okinitializes the processor | V IO andSysClock, theV Oksignal |
CC
operating parameters.  After the mode bits have been read in, the processor allows
its internal phase locked loops to lock, stabilizing the processor internal clock,
PClock.
16
3. ColdReset*is asserted for at least 64K (2 )SysClockcycles after the assertion
ofV Ok.   Once the processor reads the boot-time mode control serial data
CC
stream,ColdReset*can be deasserted.ColdReset*must be deasserted
synchronously withSysClock.
4. AfterColdReset*is deasserted synchronously,Reset*is deasserted to allow the
processor to begin running.  (Reset*must be held asserted for at least 64
SysClockcycles after the deassertion ofColdReset*.)Reset*must be deasserted
synchronously withSysClock.
NOTE:  ColdReset*must be asserted whenV Okasserts.  The behavior of the
CC
processor is undefined ifV Okasserts whileColdReset*is deasserted.
CC
Note	V	IO is only for V 5000A.
CC R
†Assertedmeans the signal is true, or in its valid state.  For example, the low-activeReset* signal is
said to be asserted when it is in a low (true) state; the high-activeV Oksignal is true when it is
CC
asserted high.
User’s Manual   U11761EJ6V0UM 215

Chapter 10  Initialization Interface
Figure 10-1 shows the power-on system reset timing diagram.
Vcc Note1
Note 2 3.135V
VccIO
SysClock
≥100 ms
VccOK
256 SysClock
ModeClock
tMDSt
MDH
.  .
ModeIn	Bit0	Bit1	Bit255
tDS
ColdReset*
≥64
≥64K SysClock
SysClock
Reset*
tDS
Notes 1. 3.135V (V 5000), 2.3V (V 5000A, 100 to 235MHz),
R R
2.375V (V 5000A, 236 to 250MHz),
R
2.5V (V 5000A, 251 to 266MHz)
R
2. V 5000A only
R
Figure  10-1   Power-on Reset Timing Diagram
10.1.2 Cold Reset
A cold reset can begin anytime after the processor has read the initialization data
stream, causing the processor to start with the Reset exception.  A cold reset requires
the same sequence as a power-on reset except that the power is presumed to be stable
before the assertion of the reset inputs and the deassertion ofV Ok.
CC
To begin the reset sequence,V Okmust be deasserted for a minimum of at least 64
CC
MasterClock cycles before reassertion.
Figure 10-2 shows the cold reset timing diagram.
216 User’s Manual   U11761EJ6V0UM

Chapter 10  Initialization Interface
V H
CC
Note
V IO
CC H
SysClock
≥64
SysClock
V OK
CC
256SysClock
ModeClock
tMDSt
MDH
.  .
ModeIn	Bit0	Bit1	Bit255
tDS
ColdReset*
≥64
≥64K SysClock
SysClock
Reset*
tDS
Note V 5000A only
R
Figure  10-2   Cold Reset Timing Diagram
10.1.3 Warm Reset
To execute a warm reset, theReset*input is asserted synchronously withSysClock.
It is then held asserted for at least 64SysClockcycles before being deasserted
synchronously withSysClock.  The boot-time mode control serial data stream is not
read by the processor on a warm reset.   A warm reset forces the processor to start with
a Soft Reset exception.
Figure 10-3 shows the warm reset timing diagram.
User’s Manual   U11761EJ6V0UM 217

Chapter 10  Initialization Interface
V
CC H
Note
V	IO	H
CC
SysClock
V	OK	H
CC
ColdReset* H
t tDS
DS
Reset*
≥64 SysClock
Note V 5000A only
R
Figure  10-3   Warm Reset Timing Diagram
10.1.4 Processor Reset State
After a power-on reset, cold reset, or warm reset, all processor internal state machines
are reset, and the processor begins execution at the reset vector.  All processor internal
states are preserved during a warm reset, although the precise state of the caches
depends on whether or not a cache miss sequence has been interrupted by resetting the
processor state machines.
10.2 Initialization Sequence
The boot-mode initialization sequence begins immediately afterV Okis asserted.
CC
As the processor reads the serial stream of 256 bits through theModeInpin, the boot-
mode bits initialize all fundamental processor modes.
The initialization sequence is listed below.
1.	The system deasserts theV	Oksignal.  TheModeClockoutput is held asserted.
CC
2.	The processor synchronizes theModeClockoutput at the timeV	Okis
CC
asserted.  The first rising edge ofModeClockoccurs 256SysClockcycles after
V Okis asserted.
CC
218 User’s Manual   U11761EJ6V0UM

Chapter 10  Initialization Interface
3. Each bit of the initialization stream is presented at theModeInpin after each
rising edge of theModeClock.  The processor samples 256 initialization bits from
theModeIninput.
10.3 Boot-Mode Settings
The following rules apply to the boot-mode settings:
•	Bit 0 of the stream is presented to the processor whenV	Okis first
CC
asserted.
• Selecting a reserved value results in undefined processor behavior.
• Zeros must be scanned in for all reserved bits.
User’s Manual   U11761EJ6V0UM 219

Chapter 10  Initialization Interface
Table 10-1 shows the boot mode settings.
Table 10-1   Boot Mode Settings
Bit	Value	Mode Setting
0 Reserved: must be zero
XmitDatPat: System interface data rate for block writes
only
0 DDDD
1 DDxDDx
2 DDxxDDxx
3 DxDxDxDx
1:4
4 DDxxxDDxxx
5 DDxxxxDDxxxx
6 DxxDxxDxxDxx
7 DDxxxxxxDDxxxxxx
8 DxxxDxxxDxxxDxxx
9:15 Reserved
SysCkRatio: PClock to SysClock Multiplier.
0 Multiply by 2
1 Multiply by 3
2 Multiply by 4
5:7	3	Multiply by 5
4 Multiply by 6
5 Multiply by 7
6 Multiply by 8
7 Reserved
EndBit: Specifies byte ordering. Logically ORed with the
BigEndian signal.
8
0 Little-Endian
1 Big Endian
Non-Block Write: Determines how non-block writes are
handled.
0V4x00 compatible
R
9:10
1 Reserved
2 Pipelined writes
3 Write-reissue
TmrIntEn: Disables Timer Interrupt on Int*[5]
11	0	Timer Interrupt Enabled
1 Timer Interrupt Disabled
220 User’s Manual   U11761EJ6V0UM

Chapter 10  Initialization Interface
| Bit | Value | Mode Setting Secondary Cache Enable |
| --- | --- | --- |
| 12 | 0 | Secondary Cache Disabled 1 Secondary Cache Enabled DrvOut: Output driver slew rate control 10 100% (fastest) |
| 13:14 | 11 | 83% 00 67% 01 50% (slowest) Secondary cache SRAM protocol |
| 15 | 0 | Pipelined 1 Burst Secondary cache size 0 512 KB secondary cache |
| 16:17 | 1 | 1 MB secondary cache 2 2 MB secondary cache 3 Reserved CP0 Count Register Update Rate |
| 18 | 0 | 1/2 x PClocK 1 1 x PClocK 19 Reserved: Must be zero Reserved: Must be zero |
20
However, must be set for Rev. 2.41 or lower of V 5000
R
21:32 Reserved: Must be zero
Reserved: Must be zero
33
However, must be set for Rev. 2.41 or lower of V 5000
R
34:36 Reserved: Must be zero
Reserved: Must be zero
37
However, must be set for Rev. 2.x or lower of V 5000
R
Note 1, Note 2
Enable 2.5PClock to SysClock Multiplier
38	0	Disable
1 Enable
39:255 Reserved: Must be zero
Notes 1. This is for V 5000A. This bit must be zero for V 5000.
R R
2. In case bit38 is set, the SysCkRatio (bit5-7) is ignored.
User’s Manual   U11761EJ6V0UM 221

Chapter 11   Clock Interface
11.1 Basic System Clocks
The various clock signals used in the V 5000 processor are described below, starting
R
withSysClock, upon which the processor bases all internal and external clocking.
11.1.1 SysClock
The processor bases all internal and external clocking on the singleSysClockinput
signal.
11.1.2 PClock
The processor generates an internal clock, PClock, at the initialization-interface-
specified frequency multiplier ofSysClockand phase-aligned toSysClock. All
internal registers and latches usePClock.
222 User’s Manual  U11761EJ6V0UM

Chapter 11  Clock Interface
11.1.3 Alignment to SysClock
•	Processor output data changes a minimum of t	ns and becomes stable
DM
a maximum of t ns after the rising edge ofSysClock.  This drive-time
DO
is the sum of the maximum delay through the processor output drivers
together with the maximum clock-to-Q delay of the processor output
registers.
•	Processor input data must be stable for a maximum of t	ns before the
DS
rising edge ofSysClockand must remain stable a minimum of t ns
DH
after the rising edge ofSysClock.
11.1.4 Phase-Locked Loop (PLL)
The processor alignsPClockandSysClockwith internal phase-locked loop (PLL)
circuits that generate aligned clocks. By their nature, PLL circuits are only capable of
generating aligned clocks forSysClockfrequencies within a limited range.
Clocks generated using PLL circuits contain some inherent inaccuracy, or jitter; a
clock aligned withSysClockby the PLL can lead or trailSysClockby as much as the
related maximum jitter tallowed by the individual vendor. The tparameter must be
ji ji
| added to the t | , t | , and t | parameters, and subtracted from the t | parameters to |
| --- | --- | --- | --- | --- |
| DS DH | DO get the total input and output timing parameters. Figure 11-1 shows theSysClocktiming parameters. SysClock t t CH CL | DM |  |  |
| t | tCF | ±tji |  |  |
CR
Figure  11-1   SysClock Timing
User’s Manual  U11761EJ6V0UM 223

Chapter 11  Clock Interface
11.2 Connecting Clocks to a Phase-Locked System
When the processor is used in a phase-locked system, the external agent must phase
lock its operation to a commonSysClock.  In such a system, the transmission of data
and data sampling have common characteristics, even if the components have different
delay values.  For example,transmission time(the amount of time a signal takes to
move from one component to another along a trace on the board) between any two
components A and B of a phase-locked system can be calculated from the following
equation:
Transmission Time = (SClock period) –  (t	for A) – (t	for B) –
DO DS
(Clock Jitter for A Max) – (Clock Jitter for B Max)
Figure 11-2 shows a block-level diagram of a phase-locked system using the V 5000
R
processor.
SysClock
External Agent
V 5000
R
SysClock SysClock
SysCmd(8:0) SysCmd(8:0)
SysAD(63:0) SysAD(63:0)
Figure  11-2   Phase-Locked System
224 User’s Manual  U11761EJ6V0UM

Chapter 12  Cache Organization and Operation
This chapter describes in detail the cache memory: its place in the V 5000 memory
R
organization, and individual organization of the caches.
This chapter uses the following terminology:
• The data cache may also be referred to as the D-cache.
• The instruction cache may also be referred to as the I-cache.
These terms are used interchangeably throughout this book.
User’s Manual   U11761EJ6V0UM 225

Chapter 12  Cache Organization and Operation
12.1 Memory Organization
Figure 12-1 shows the V 5000 system memory hierarchy. In the logical memory
R
hierarchy, the caches lie between the CPU and main memory. They are designed to
make the speedup of memory accesses transparent to the user.
Each functional block in Figure 12-1 has the capacity to hold more data than the block
above it. For instance, physical main memory has a larger capacity than the caches. At
the same time, each functional block takes longer to access than any block above it.
For instance, it takes longer to access data in main memory than in the CPU on-chip
registers.
VR5000 CPU
Registers Registers
Registers
I-cache D-cache
Primary Cache
Caches
Secondary Cache Faster Access Increasing Data
Time Capacity
Main Memory
Memory
Disk, CD-ROM,
Tape, etc.
Peripherals
Figure  12-1   Logical Hierarchy of Memory
The V 5000 processor has two on-chip caches: one holds instructions (the instruction
R
cache), the other holds data (the data cache). The instruction and data caches can be
read in one PClock cycle.
226 User’s Manual   U11761EJ6V0UM

Chapter 12  Cache Organization and Operation
Data writes are pipelined and can complete at a rate of one per PClock cycle. In the
first stage of the cycle, the store address is translated and the tag is checked; in the
second stage, the data is written into the data RAM.
Figure 12-2 provides a block diagram of the V 5000 cache and memory model.
R
VR5000
Cache Controller Main Memory
I-cache
Caches Secondary Cache
D-cache
I-cache Instruction cache
D-cacheData cache
Figure  12-2   V5000 Cache Support
R
12.2 Primary Cache Organization
This section describes the organization of the on-chip data and instructio caches.
12.2.1 Cache Line Lengths
A cache line is the smallest unit of information that can be fetched from main memory
for the cache, and that is represented by a single tag.
The line size fot the instruciton/data cache is 32 bytes.
12.2.2 Cache Sizes
The V 5000 instruciton cache is 32 KB; the data cache is 32 KB.
R
User’s Manual   U11761EJ6V0UM 227

Chapter 12  Cache Organization and Operation
12.2.3 Organization of the Instruction Cache (I-Cache)
The V 5000 procesosr I-cache has the following characteristics:
R
• 2-way set associative
• indexed with a virtual address
• checked with a physical tag
organized with a 32-byte cache line.
| 26 | 25 | 24 | 23 | 0 |
| --- | --- | --- | --- | --- |
| P | PState | PTag |  |  |
| 1 | 2 | 24 |  |  |
| 71 | 64  63 DataP Data DataP Data DataP Data DataP Data | 0 |  |  |
864
P: Even parity for the PTag
PState: Primary cache state
PTag: Primary cache tag (bits 35:12 of the physical address)
DataP: Even parity for the data
Data: I-cache data
Figure  12-3   Primary Instruction Cache Line Format
228 User’s Manual   U11761EJ6V0UM

Chapter 12  Cache Organization and Operation
12.2.4 Organization of the Data Cache (D-Cache)
The V 5000 processor D-cache has the following characteristics:
R
• write-back or write-through
• 2-way set associative
• indexed with a virtual address
• checked with a physical tag
organized with a 32-byte cache line.
| 26 | 25 | 24 23 | 0 |
| --- | --- | --- | --- |
| P | PState | PTag |  |
| 1 | 2 | 24 |  |
| 71 | 64  63 DataP Data DataP Data DataP Data DataP Data | 0 |  |
864
P: Even parity for the PTag
PState: Primary cache state
PTag: Primary cache tag (bits 35:12 of the physical address)
DataP: Even parity for the data
Data: D-cache data
Figure  12-4   Primary Data Cache Line Format
User’s Manual   U11761EJ6V0UM 229

Chapter 12  Cache Organization and Operation
12.3 Secondary Cache Organization
The V 5000 has a secondary cache interface and can operate with an external
R
secondary cache.
The secondary cache is:
• direct-mapped
• indexed with a virtual address
• checked with a physical tag
• organized with an 8-word (32-byte) cache line
• either 512 KB, 1 MB, or 2 MB in size.
| 37 | 35 34 | 32  31 | 0 |
| --- | --- | --- | --- |
| VIdx | SState | STag |  |
| 3 | 3 | 32 |  |
| 71 | 64  63 DataP Data DataP Data DataP Data DataP Data | 0 |  |
864
VIdx: Virtual index of the associated primary cache line (bits 14:12 of the virtual address)
SState: Secondary cache state
STag: Secondary cache tag (bits 35:17 of the physical address)
DataP: Even parity for the data
Data: Secondary cache data
Figure  12-5   Secondary Cache Line Format
230 User’s Manual   U11761EJ6V0UM

Chapter 13   V 5000 Processor Bus Interface
R
The System interface allows the processor to access external resources needed to
satisfy cache misses and uncached operations, while permitting an external agent
access to some of the processor internal resources.
The clock portion of the V 5000 system interface has been simplified and many of the
R
external clock signals have been deleted from the system interface of the V 4000
R
Series.
The V 5000 processor supports up to a 100 MHz pipelinedSysADbus. V 5000 also
R R
implements a unified, write-through secondary cache which has the same 32-byte line
size as the primary caches. Secondary cache index and control signals are supplied by
the processor. Secondary cache sizes of 512 KB, 1 MB, and 2 MB are supported.
This chapter describes the System interface from the point of view of both the
processor and the external agent.
User’s Manual  U11761EJ6V0UM 231

Chapter 13  V5000 Processor Bus Interface
R
13.1 Terms Used
The following terms are used in this document:
• Anexternal agentis any logic device connected to the processor, over the
System interface, that allows the processor to issue requests.
•Asystem eventis an event that occurs within the processor and requires
access to external system resources.
• Sequencerefers to the precise series of requests that a processor generates
to service a system event.
• Protocolrefers to the cycle-by-cycle signal transitions that occur on the
System interface pins to assert a processor or external request.
• Syntaxrefers to the precise definition of bit patterns on encoded buses,
such as the command bus.
13.2 Interface Buses
Figure 13-1 shows the primary communication paths for the System interface: a 64-bit
address and data bus,SysAD[63:0], and a 9-bit command bus,SysCmd[8:0].  The
SysADand theSysCmdbuses are bidirectional; that is, they are driven by the
processor to issue a processor request, and by the external agent to issue an external
request.
A request through the System interface consists of:
• an address
• a System interface command that specifies the precise nature of the
request
• a series of data elements if the request is for a write or read response.
232 User’s Manual  U11761EJ6V0UM

Chapter 13  V5000 Processor Bus Interface
R
VR5000 External Agent
SysCmd[8:0]
SysAD[63:0]
Figure  13-1   System Interface Buses
Figure 13-2 shows the primary communication paths for a secondary cache
configuration. The secondary cache shares theSysADandSysADCbuses between the
processor and the external agent. The processor implements theScLineandScWord
address buses to the secondary cache to access a cache line within the secondary cache
and 64-bit cache doublewords within the cache line, respectively.
V5000 External
R
Agent
SysCmd[8:0]
SysAD[63:0]
SysADC[7:0]
ScLine[15:0]
ScWord[1:0]
Secondary
Cache
Figure  13-2   Secondary Cache Interface
User’s Manual  U11761EJ6V0UM 233

Chapter 14  System Interface Transactions
There are two broad categories of transactions:processor requestsandexternal
requests.  This chapter describes them.
14.1 Processor Requests
The processor issues either a single request or a series of requests—calledprocessor
requests—through the System interface, to access an external resource.  For this to
work, the processor System interface must be connected to an external agent that is
compatible with the System interface protocol, and can coordinate access to system
resources.
234 User’s Manual  U11761EJ6V0UM

Chapter 14  System Interface Transactions
An external agent requesting access to a processor internal resource generates an
external request.  This access request passes through the System interface.  System
events and request cycles are shown in Figure 14-1.
VR5000 External Agent
Processor Requests
•  Read
•  Write External Requests
•  Write
•  Null
System Events
•  Load Miss
•  Store Miss
•  Write Back
•  Write Through
•  Store Hit
•  Uncached Load/Store
Figure  14-1   Requests and System Events
14.1.1 Rules for Processor Requests
A processor request is a request or a series of requests, through the System interface,
to access some external resource.  As shown in Figure 14-2, processor requests include
read and write.
VR5000 External Agent
Processor Requests
•  Read
•  Write
Figure  14-2   Processor Requests to External Agent
Read request asks for a block, doubleword, partial doubleword, word, or partial word
of data either from main memory or from another system resource.
User’s Manual  U11761EJ6V0UM 235

Chapter 14  System Interface Transactions
Writerequestprovides a block, doubleword, partial doubleword, word, or partial word
of data to be written either to main memory or to another system resource.
The processor is only allowed to have one request pending at any time.  For example,
the processor issues a read request and waits for a read response before issuing any
subsequent requests.  The processor submits a write request only if there are no read
requests pending.
The processor has the input signalsRdRdy*andWrRdy*to allow an external agent
to manage the flow of processor requests.RdRdy*controls the flow of processor read
requests, whileWrRdy*controls the flow of processor write requests.  The processor
request cycle sequence is shown in Figure 14-3.
V5000 External Agent
R
1.  Processor issues read or write
2.  External system controls
acceptance of requests by
asserting RdRdy* or WrRdy*
Figure  14-3   Processor Request Flow Control
14.1.2 Processor Read Request
When a processor issues a read request, the external agent must access the specified
resource and return the requested data.
A processor read request can be split from the external agent’s return of the requested
data; in other words, the external agent can initiate an unrelated external request before
it returns the response data for a processor read.  A processor read request is completed
after the last word of response data has been received from the external agent.
Note that the data identifier associated with the response data can signal that the
returned data is erroneous, causing the processor to take a bus error.
Processor read requests that have been issued, but for which data has not yet been
returned, are said to bepending.  A read remains pending until the requested read data
is returned.
The external agent must be capable of accepting a processor read request any time the
following two conditions are met:
236 User’s Manual  U11761EJ6V0UM

Chapter 14  System Interface Transactions
• There is no processor read request pending.
• The signalRdRdy*has been asserted for two or more cycles before the
issue cycle.
14.1.3 Processor Write Request
When a processor issues a write request, the specified resource is accessed and the data
is written to it.  A processor write request is complete after the last word of data has
been transmitted to the external agent. The V 5000 processor supportsV4000
R R
compatible,write-reissueandpipelined writeoperations as defined in Chapter 15.
The external agent must be capable of accepting a processor write request any time the
following two conditions are met:
• No processor read request is pending.
• The signalWrRdy*has been asserted for two or more cycles.
14.2 External Requests
External requests include write, and null requests, as shown in Figure 14-4. This
section also includes a description of read response, a special case of an external
request.
VR5000 External Agent
External Requests
•  Write
•  Null
Figure  14-4   External Requests to Processor
Writerequest provides a word of data to be written to the processor’s internal resource.
User’s Manual  U11761EJ6V0UM 237

Chapter 14  System Interface Transactions
Nullrequest requires no action by the processor; it provides a mechanism for the
external agent to return the System interface to the master state without affecting the
processor.
The processor controls the flow of external requests through the arbitration signals
ExtRqst*andRelease*, as shown in Figure 14-5.  The external agent must acquire
mastership of the System interface before it is allowed to issue an external request; the
external agent arbitrates for mastership of the System interface by assertingExtRqst*
and then waiting for the processor to assertRelease*for one cycle.  IfRelease*is
asserted as part of an uncompelled change to slave state during a processor read
request, and the secondary cache is enabled, the secondary cache access must be
resolved and be a miss. Otherwise the system interface returns to the master state.
VR5000 External Agent
1. External system requests bus
mastership by asserting ExtRqst*
2. Processor grants mastership by
asserting Release*
3. External system issues an
External Request
4. Processor regains bus mastership
Figure  14-5   External Request Arbitration
Mastership of the System interface always returns to the processor after an external
request is issued.  The processor does not accept a subsequent external request until it
has completed the current request.
If there are no processor requests pending, the processor decides, based on its internal
state, whether to accept the external request, or to issue a new processor request. The
processor can issue a new processor request even if the external agent is requesting
access to the System interface.
The external agent assertsExtRqst* indicating that it wishes to begin an external
request.  The external agent then waits for the processor to signal that it is ready to
accept this request by assertingRelease*.  The processor signals that it is ready to
accept an external request based on the criteria listed below.
• The processor completes any request in progress.
238 User’s Manual  U11761EJ6V0UM

Chapter 14  System Interface Transactions
• While waiting for the assertion ofRdRdy*to issue a processor read
request, the processor can accept an external request if the external
request is delivered to the processor one or more cycles beforeRdRdy*is
asserted.
• While waiting for the assertion ofWrRdy* to issue a processor write
request, the processor can accept an external request provided the external
request is delivered to the processor one or more cycles beforeWrRdy*
is asserted.
• If waiting for the response to a read request after the processor has made
an uncompelled change to a slave state, the external agent can issue an
external request before providing the read response data.
14.2.1 External Write Request
When an external agent issues a write request, the specified resource is accessed and
the data is written to it.  An external write request is complete after the word of data
has been transmitted to the processor.
The only processor resource available to an external write request is the Interrupt
register. Refer to Chapter 17 for more information.
14.2.2 Read Response
Aread responsereturns data in response to a processor read request, as shown in
Figure 14-6.  While a read response is technically an external request, it has one
characteristic that differentiates it from all other external requests—it does not perform
System interface arbitration.  For this reason, read responses are handled separately
from all other external requests, and are simply called read responses.
The data identifier associated with the response data can signal that the returned data
is erroneous, causing the processor to take a bus error.
User’s Manual  U11761EJ6V0UM 239

Chapter 14  System Interface Transactions
VR5000 External Agent
1.  Read request
2.  Read response
Figure  14-6   External Agent Read Response to Processor
14.3 Handling Requests
This section details thesequence,protocol, andsyntaxof both processor and external
requests.  The following system events are discussed:
• load miss
• store miss
• store hit
• uncached loads/stores
• uncached instruction fetch
• load linked store conditional
14.3.1 Load Miss
When a processor load misses in the primary cache, before the processor can proceed
it must obtain the cache line that contains the data element to be loaded from the
external agent.
If the new cache line replaces a current dirty exclusive or dirty shared cache line, the
current cache line must be written back before the new line can be loaded in the
primary cache.
240 User’s Manual  U11761EJ6V0UM

Chapter 14  System Interface Transactions
The processor examines the coherency attribute in the TLB entry for the page that
contains the requested cache line, and executes one of the following request:
• The coherency attribute isnoncoherent, the processor issues a
noncoherent read request.
Table 14-1 shows the actions taken on a load miss to primary cache.
Table 14-1   Load Miss to Primary Caches
State of Data Cache Line Being Replaced
Page Attribute
Clean/Invalid Dirty (W=1)
Noncoherent	NCBR	NCBR/W
NCBR ................. Processor noncoherent block read request
NCBR/W ............ Processor noncoherent block read request followed by processor
block write request
The processor takes the following steps:
1. The processor issues a noncoherent block read request for the cache line that
contains the data element to be loaded. If the secondary cache is enabled and the
page coherency attribute is write-back, the response data will also be written into
the secondary cache.
2. The processor then waits for an external agent to provide the read response.
3. The processor restarts the pipeline after the first doubleword of the data cache
miss is received. The remaining three doublewords are placed in the cache after
all three doublewords have been received and the dcache is otherwise idle.
If the current cache line must be written back, the processor issues a block write
request to save the dirty cache line in memory. If the secondary cache is enabled and
the page attribute is write-back, the write back data will also be written into the
secondary cache.
14.3.2 Store Miss
When a processor store misses in the primary cache, the processor may request, from
the external agent, the cache line that contains the target location of the store for pages
that are either write-back or write-through with write-allocate only.  The processor
examines the coherency attribute in the TLB entry for the page that contains the
requested cache line to see if the cache line is being maintained with either a write-
allocate or no-write-allocate policy.
User’s Manual  U11761EJ6V0UM 241

Chapter 14  System Interface Transactions
The processor then executes one of the following requests:
• If the coherency attribute isnoncoherentwrite-back, or write-through
with write-allocate, a noncoherent block read request is issued.
• If the coherency attribute isnoncoherentwrite-through with no write-
allocate, a non-block write request is issued.
Table 14-2 shows the actions taken on a store miss to the primary cache.
Table 14-2   Store Miss to Primary and Secondary Caches
State of Data Cache Line Being
Page Attribute Replaced
Clean/Invalid Dirty (W=1)
Noncoherent-write-back or noncoherent-write-
NCBR NCBR/W
through with write-allocate
Noncoherent-write-through with no-write-
NCW NA
allocate
NCBR................. Processor noncoherent block read request
NCBR/W............ Processor noncoherent block read request followed by processor block
write request
NCW .................. Processor noncoherent write request
If the coherency attribute is write-back, or write-through with write-allocate, the
processor issues a non-coherent block read request for the cache line that contains the
data element to be loaded, then waits for the external agent to provide read data in
response to the read request. If the secondary cache is enabled and the page coherency
attribute is write-back, the response data will also be written into the secondary cache.
If the current cache line must be written back, the processor issues a write request for
the current cache line.
If the page coherency attribute is write-through, the processor issues a non-block write
request.
For a write-through, no-write-allocate store miss, the processor issues a non-block
write request only.
242 User’s Manual  U11761EJ6V0UM

Chapter 14  System Interface Transactions
14.3.3 Store Hit
The action on the system bus is determined by whether the line is write-back or write-
through. For lines with a write-back policy, a store hit does not cause any processor
request on the bus.  For lines with a write-through policy, the store generates a
processor non-block write request for the store data.
14.3.4 Uncached Loads or Stores
When the processor performs an uncached load, it issues a noncoherent doubleword,
partial doubleword, word, or partial word read request.  When the processor performs
an uncached store, it issues a doubleword, partial doubleword, word, or partial word
write request. All writes by the processor are buffered from the system interface by a
4-entry write buffer. The write requests are sent to the system bus only when no other
requests are in progress. However, once the emptying of the write buffer has begun, it
is allowed to complete. Therefore, if the write buffer contains any entries when a block
read is requested, the write buffer is allowed to empty before the block read request is
serviced. Uncached loads and stores do not affect the secondary cache.
14.3.5 Uncached Instruction Fetch
The processor issues doubleword reads for instruction fetches to uncached addresses.
Thus any system ROM address space accessed during a processor boot-restart must
support 64-bit reads.
14.3.6 Load Linked Store Conditional Operation
The execution of a Load-Linked/Store-Conditional instruction sequence is not visible
at the System interface; that is, no special requests are generated due to the execution
of this instruction sequence.
User’s Manual  U11761EJ6V0UM 243

Chapter 15   System Interface Protocols
The following sections contain a cycle-by-cycle description of the system interface
protocols for each type of processor and external request.
15.1 Address and Data Cycles
Cycles in which theSysADbus contains a valid address are calledaddress cycles.
Cycles in which theSysADbus contains valid data are calleddata cycles.  Validity of
addresses and data from the processor is determined by the state of theValidOut*
signal. Validity of addreses and data from the external agent is determined by the state
of theValidIn*signal. Validity of data from the secondary cache is determined by
the state of the pipelinedScDCE*andScCWE*signals from the processor and the
ScDOE*signal from the external agent.
TheSysCmdbus identifies the contents of theSysADbus during any cycle in which
it is valid from the processor or the external agent.  The most significant bit of the
SysCmdbus is always used to indicate whether the current cycle is an address cycle
or a data cycle.
• During address cyclesSysCmd(8)= 0. The remainder of theSysCmd
bus,SysCmd(7:0), contains the encoded system interface command.
244 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
• During data cycles [SysCmd(8)= 1], the remainder of theSysCmdbus,
SysCmd(7:0), contains an encoded data identifier.  There is noSysCmd
associated with a secondary cache read response.
15.2 Issue Cycles
There are two types of processor issue cycles:
• processor read request.
• processor write request.
The processor samples the signalRdRdy*to determine the issue cycle for a processor
read; the processor samples the signalWrRdy*to determine the issue cycle of a
processor write request.
As shown in Figure 15-1,RdRdy*must be asserted two cycles prior to the address
cycle of the processor read request in order to define the address cycle as the issue
cycle.
SysCycle	1	2	3	4	5	6
SysClock
SysAD Bus Addr
RdRdy*
Figure  15-1   State of RdRdy* Signal for Read Requests
As shown in Figure 15-2,WrRdy*must be asserted two cycles prior to the first
address cycle of the processor write request in order to define the address cycle as the
issue cycle.
User’s Manual  U11761EJ6V0UM 245

Chapter 15  System Interface Protocols
SysCycle	1	2	3	4	5	6
SysClock
SysAD Bus Addr
WrRdy*
Figure  15-2   State of WrRdy* Signal for Write Requests
The processor repeats the address cycle for the request until the conditions for a valid
issue cycle are met.  After the issue cycle, if the processor request requires data to be
sent, the data transmission begins.  There is only one issue cycle for any processor
request.
The processor accepts external requests, even while attempting to issue a processor
request, by releasing the System interface to slave state in response to an assertion of
ExtRqst*by the external agent.
Note that the rules governing the issue cycle of a processor request are strictly applied
to determine which action the processor takes.  The processor can either:
• complete the issuance of the processor request in its entirety before the
external request is accepted, or
• release the System interface to slave state without completing the issuance
of the processor request.
In the latter case, the processor issues the processor request (provided the processor
request is still necessary) after the external request is complete.  The rules governing
an issue cycle again apply to the processor request.
15.3 Handshake Signals
The V 5000 processor manages the flow of requests through the following six control
R
signals:
• RdRdy*,WrRdy* are used by the external agent to indicate when it can
accept a new read (RdRdy*) or write (WrRdy*) transaction.
246 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
• ExtRqst*,Release* are used to transfer control of theSysADand
SysCmdbuses.ExtRqst* is used by an external agent to indicate a need
to control the interface.Release* is asserted by the processor when it
transfers the mastership of the System interface to the external agent.  For
secondary cache reads, assertion ofRelease* to the external agent is
speculative, and is aborted if there is a hit in the secondary cache.
• The V 5000 processor usesValidOut* and the external agent uses
R
ValidIn* to indicate valid command/data on theSysCmd/SysADbuses.
• The secondary cache uses theScDCE*,ScCWE*andScDOE*signals
to control validation on theSysADandSysADCbuses.
15.4 System Interface Operation
Figure 15-3 shows how the system interface operates from register to register.  That is,
processor outputs come directly from output registers and begin to change with the
rising edge ofSysClock.
Processor inputs are fed directly to input registers that latch these input signals with the
rising edge ofSysClock.  This allows the System interface to run at the highest
possible clock frequency.
V 5000
R
OUTPUT
LATCH Output data
D63:0
INPUT
LATCH Input data
SysClock
Figure  15-3   System Interface Register-to-Register Operation
User’s Manual  U11761EJ6V0UM 247

Chapter 15  System Interface Protocols
15.4.1 Master and Slave States
When the V 5000 processor is driving theSysADandSysCmdbuses, the System
R
interface is inmaster state. When the external agent is driving theSysADandSysCmd
buses, the System interface is inslave state.  When the secondary cache is driving the
SysADandSysADCbuses, the System interface is in slave state.
In master state, the processor asserts the signalValidOut*whenever theSysADand
SysCmdbuses are valid.
In slave state, the external agent asserts the signalValidIn*whenever theSysADand
SysCmdbuses are valid and the secondary cache drives theSysADandSysADC
buses in response to theScDCE*,ScCWE*, andScDOE* signals.
The System interface remains in master state unless one of the following occurs:
• The external agent requests and is granted the System interface (external
arbitration).
• The processor issues a read request.
15.4.2 External Arbitration
The System interface must be in slave state for the external agent to issue an external
request through the System interface.  The transition from master state to slave state is
arbitrated by the processor using the System interface handshake signalsExtRqst*
andRelease*.  This transition is described by the following procedure:
1. An external agent signals that it wishes to issue an external request by asserting
ExtRqst*.
2. When the processor is ready to accept an external request, it releases the System
interface from master to slave state by assertingRelease*for one cycle.
3. The System interface returns to master state as soon as the issue of the external
request is complete.
15.4.3 Uncompelled Change to Slave State
Anuncompelledchange to slave state is the transition of the System interface from
master state to slave state, initiated by the processor when a processor read request is
pending.Release* is asserted automatically at the same time a read request is issued
and an uncompelled change to slave state then occurs. This transition to slave state
allows the external agent to return read response data without arbitrating for bus
ownership.
If the secondary cache is enabled and a secondary cache hit occurs, then the bus is
returned to master state.
248 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
After an uncompelled change to slave state, the processor returns to master state at the
end of the next external request.  This can be a read response, or some other type of
external request. If the external agent issues some other type of external request while
there is a pending read request, the processor performs another uncompelled change to
slave state by assertingRelease* for one cycle.
An external agent must note that the processor has performed an uncompelled change
to slave state and begin driving theSysADbus along with theSysCmdbus.  As long
as the System interface is in slave state, the external agent can begin an external request
without arbitrating for the System interface; that is, without assertingExtRqst*.
Table 15-1 lists the abbreviations and definitions for each of the buses that are used in
the timing diagrams that follow.
Table 15-1   System Interface Requests
Scope	Abbreviation	Meaning
Global	Unsd	Unused
Addr Physical address
SysAD bus
Data<n> Data element number n of a block of data
Cmd An unspecified System interface command
Read A processor read request command
Write A processor or external write request command
A System interface release external null request
SINull
SysCmd bus command
A noncoherent data identifier for a data element other
NData
than the last data element
NEOD A noncoherent data identifier for the last data element
15.5 Processor Request Protocols
Processor request protocols described in this section include:
• read
• write
NOTE:In the timing diagrams, the two closely spaced, wavy vertical lines, such
as those shown in Figure 15-4,  indicate one or more identical cycles which are not
illustrated due to space constraints.
User’s Manual  U11761EJ6V0UM 249

Chapter 15  System Interface Protocols
Figure  15-4   Symbol for Undocumented Cycles
15.5.1 Processor Read Request Protocol
The following sequence describes the protocol for doubleword, partial doubleword,
word, partial word, and non-secondary cache mode processor read requests. The
secondary cache block read request protocol is described later in this section. The
numbered steps below correspond to Figure 15-5.
1. RdRdy* is asserted low, indicating the external agent is ready to accept a read
request.
2. With the System interface in master state, a processor read request is issued by
driving a read command on theSysCmdbus and a read address on theSysADbus.
The physical address is driven ontoSysAD[35:0], and virtual address bits [13:12]
are driven ontoSysAD[57:56]. All other bits are driven to zero.
3. At the same time, the processor assertsValidOut*for one cycle, indicating valid
data is present on theSysCmdand theSysADbuses.
NOTE:Only one processor read request can be pending at a time.
4. The processor makes an uncompelled change to slave state during the issue cycle
of the read request. The external agent must not assert the signalExtRqst*for the
purposes of returning a read response, but rather must wait for the uncompelled
change to slave state.  The signalExtRqst*can be asserted before or during a read
response to perform an external request other than a read response.
5. The processor releases theSysCmdand theSysADbuses oneSysClockafter the
assertion ofRelease*.
6. The external agent drives theSysCmdand theSysADbuses within two cycles
after the assertion ofRelease*.
Once in slave state the external agent can return the requested data through a read
response.  The read response can return the requested data or, if the requested data
could not be successfully retrieved, an indication that the returned data is erroneous.
If the returned data is erroneous, the processor takes a bus error exception.
250 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
Figure 15-5 illustrates a processor read request, coupled with an uncompelled change
to slave state, that occurs as the read request is issued.
Timings for theSysADCandSysCmdPbuses are the same as those of theSysADand
SysCmdbuses, respectively.
Processor External Agent
Master
SysCycle	1	2	3	4	5	6	7	8	9	10	11	12
SysClock
SysAD Bus Addr
5 6
SysCmd Bus Read
ValidOut* 3
2
RdRdy* 1
4
Release*
Figure  15-5   Processor Read Request Protocol
Any time a read request has been issued (indicating a read request is pending), the
processor will assertRelease*to perform an uncompelled change to slave state.  Once
in the slave state the processor will always accept either a read response or an
ExtRqst*(if a read is pending).
15.5.2 Processor Write Request Protocol
Processor write requests are issued using one of three protocols.
• Doubleword, partial doubleword, word, or partial word writes use a non-
block write request protocol.
• Non-secondary cache block writes use a block write request protocol.
• Secondary cache block write request protocol.
Processor non-block write requests are issued with the System interface in master
state, as described below in the steps below; Figure 15-6 shows a processor
noncoherent non-block write request cycle.
User’s Manual  U11761EJ6V0UM 251

Chapter 15  System Interface Protocols
1. WrRdy* is asserted low, indicating the external agent is ready to accept a write
request.
2. A processor single non-block write request is issued by driving a write command
on theSysCmdbus and a write address on theSysADbus. The physical address
is driven ontoSysAD[35:0], and virtual address bits [13:12] are driven onto
SysAD[57:56]. All other bits are driven to zero.
3. The processor assertsValidOut*.
4. The processor drives a data identifier on theSysCmdbus and data on theSysAD
bus.
5. The data identifier associated with the data cycle must contain a last data cycle
indication.  At the end of the cycle,ValidOut*is deasserted.
NOTE:Timings for theSysADCandSysCmdPbuses are the same as those of
theSysADandSysCmdbuses, respectively.
Processor
Master
SysCycle	1	2	3	4	5	6	7	8	9	10	11	12
SysClock
SysAD Bus Addr Data0
SysCmd Bus WriteNEOD
3 5
ValidOut*
2
4
WrRdy* 1
Figure  15-6   Processor Non-Coherent Non-Block Write Request Protocol
252 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
Figure 15-7 illustrates a non-secondary cache block write request.
Processor
Master
SysCycle	1	2	3	4	5	6	7	8	9	10	11	12
SysClock
SysAD Addr Data0Data1Data2Data3
SysCmd WriteNData NDataNDataNEOD
3 5
ValidOut*
2
4
WrRdy* 1
Figure  15-7   Processor Non-Coherent, Non-Secondary Cache Block Write Request
User’s Manual  U11761EJ6V0UM 253

Chapter 15  System Interface Protocols
15.5.3 Processor Request Flow Control
The external agent usesRdRdy*to control the flow of processor read requests.
Figure 15-8 illustrates this flow control, as described in the steps below.
1. The processor samples theRdRdy*signal to determine if the external agent is
capable of accepting a read request.
2. Read request is issued to the external agent.
3. The external agent deassertsRdRdy*, indicating it cannot accept additional read
requests.
4. The read request issue is stalled becauseRdRdy* was negated two cycles earlier.
5. Read request is again issued to the external agent.
External External
| Processor | Agent | Processor Master | Agent |
| --- | --- | --- | --- |
| SysCycle | 1 | 2 | 3 4 5 6 7 8 9 10 SysClock |
| SysAD | Addr0 | D0 | Addr1 D1 |
| SysCmd | Read | NEOD | Read NEOD ValidOut* ValidIn* |
| RdRdy* | 1 | 2 | 3 4 5 Release* Figure  15-8   Processor Request Flow Control Figure 15-9 illustrates two processor write requests in which the issue of the second is delayed for the state ofWrRdy*. 1. WrRdy*is state low, indicating the external agent is ready to accept a write request. 2. The processor assertsValidOut*, a write command on theSysCmdbus, and a write address on theSysADbus. 3. The second write request is delayed until theWrRdy* signal is again asserted. 254 User’s Manual  U11761EJ6V0UM |

Chapter 15  System Interface Protocols
4. The processor does not complete the issue of a write request until it issues an
address cycle in response to the write request for which the signalWrRdy* was
asserted two cycles earlier.
NOTE:Timings for theSysADCandSysCmdPbuses are the same as those of
theSysADandSysCmdbuses, respectively.
Master Processor
SysCycle	1	2	3	4	5	6	7	8	9	10	11	12
SysClock
SysAD Bus	Addr Data0	Addr	Data0
SysCmd Bus	Write NEOD	Write	NEOD
2
ValidOut*
WrRdy*	1	3	4
Figure  15-9   Two Processor Write Requests with Second Write Delayed
The V 5000 processor interface requires thatWrRdy* be asserted two system cycles
R
prior to the issue of a write cycle. An external agent that negatesWrRdy* immediately
upon receiving the write that fills its buffer will suspend any subsequent writes for four
system cycles in V 4000 non-block write-compatible mode. The processor always
R
inserts at least two unused  system cycles after a write address/data pair in order to give
the external agent time to suspend the next write.
Figure 15-10 shows back-to-back write cycles in V 4000-compatible mode.
R
1. WrRdy* is asserted, indicating the processor can issue a write request.
2. WrRdy* remains asserted, indicating the external agent can accept another write
request.
3. WrRdy* deasserts, indicating the external agent cannot accept another write
request, stalling the issue of the next write request.
User’s Manual  U11761EJ6V0UM 255

Chapter 15  System Interface Protocols
Master Processor
SysCycle	1	2	3	4	5	6	7	8	9	10	11	12	13	14
SysClock
Cycles 1234
SysAD Bus	Addr DataUnusedUnused Addr Data UnusedUnused	Addr	Data
Write #1	Write #2	Write #3
ValidOut*
1 2
WrRdy* 3
Figure  15-10   V4000-Compatible Back-to-Back Write Cycle Timing
R
An address/data pair  every four system cycles is not sufficiently high performance for
all applications. For this reason, the V 5000 processor provides two protocol options
R
that modify the V 4000 back-to-back write protocol to allow an address/data pair
R
every two system cycles. These two protocols are as follows:
Write ReissueallowsWrRdy* to be negated during the address cycle and forces
the write cycle to be re-issued.
Pipelined Writesleave the sample point ofWrRdy* unchanged and require that
the external agent accept one more write than dictated by the V 4000 protocol.
R
256 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
The write re-issue protocol is shown in Figure 15-11. Writes issue whenWrRdy* is
asserted both two cycles prior to the address cycle and during the address cycle.
1. WrRdy* is asserted, indicating the external agent can accept a write request.
2. WrRdy* remains asserted as the write is issued, and the external agent is ready to
accept another write request.
3. WrRdy* deasserts during the address cycle.  This write request is aborted and
reissued.
4. WrRdy* is asserted, indicating the external agent can accept a write request.
5. WrRdy* remains asserted as the write is issued, and the external agent is able to
accept another write request.
Master Processor
| No | No | No | No |
| --- | --- | --- | --- |
| Issue | Issue | Issue Issue Issue Issue SysCycle 1 2 345 6789 1011 SysClock |  |
| SysAD | Addr0Data0Addr1Data1 | Addr1 | Data1 |
| SysCmd[8:0] | WriteNEODWriteNEOD ValidOut* | Write | NEOD |
| WrRdy* | 1 | 2 | 3 4 5 Figure  15-11   Write Reissue User’s Manual  U11761EJ6V0UM 257 |

Chapter 15  System Interface Protocols
The pipelined write protocol is shown in Figure 15-2.  Writes issue whenWrRdy* is
asserted two cycles before the address cycle and the external agent is required to accept
one more write afterWrRdy* is negated.
1. WrRdy* is asserted, indicating the external agent can accept a write request.
2. WrRdy* remains asserted as the write is issued, and the external agent is able to
accept another write request.
3. WrRdy* is deasserted, indicating the external agent cannot accept another write
request; it does, however, accept this write.
4. WrRdy* is asserted, indicating the external agent can accept a write request.
Master Processor
| No | No | No |
| --- | --- | --- |
| Issue | Issue | Issue Issue IssueIssue SysCycle 1 2 345 6789 1011 SysClock |
| SysAD | Addr0Data0Addr1Data1 | Addr2 Data2 |
| SysCmd[8:0] | WriteNEODWriteNEOD ValidOut* | Write NEOD |
| WrRdy* | 1 | 2 3 4 Figure  15-12   Pipelined Writes 15.6 External Request Protocols External requests can only be issued with the System interface in slave state.  An external agent assertsExtRqst*to arbitrate for the System interface, then waits for the processor to release the System interface to slave state by assertingRelease* before the external agent issues an external request.  If the System interface is already in slave state—that is, the processor has previously performed an uncompelled change to slave state—the external agent can begin an external request immediately. After issuing an external request, the external agent must return the System interface to master state.  If the external agent does not have any additional external requests to perform,ExtRqst*must be deasserted two cycles after the cycle in whichRelease* 258 User’s Manual  U11761EJ6V0UM |

Chapter 15  System Interface Protocols
was asserted.  For a string of external requests, theExtRqst* signal is asserted until
the last request cycle, whereupon it is deasserted two cycles after the cycle in which
Release*was asserted.
The processor continues to handle external requests as long asExtRqst*is asserted;
however, the processor cannot release the System interface to slave state for a
subsequent external request until it has completed the current request.  As long as
ExtRqst*is asserted, the string of external requests is not interrupted by a processor
request.
This section describes the following external request protocols:
• null
• write
• read response
15.6.1 External Arbitration Protocol
System interface arbitration uses the signalsExtRqst*andRelease*as described
above.  Figure 15-13 is a timing diagram of the arbitration protocol, in which slave and
master states are shown.
The arbitration cycle consists of the following steps:
1. The external agent assertsExtRqst*when it wishes to submit an external request.
2. The processor waits until it is ready to handle an external request, whereupon it
assertsRelease*for one cycle.
3. The processor sets theSysADandSysCmdbuses to tristate.
4. The external agent must wait at least two cycles after the assertion ofRelease*
before it drives theSysADandSysCmdbuses.
5. The external agent negatesExtRqst*two cycles after the assertion ofRelease*,
unless the external agent wishes to perform an additional external request.
6. The external agent sets theSysADand theSysCmdbuses to tristate at the
completion of an external request.
The processor can start issuing a processor request one cycle after the external agent
sets the bus to tristate.
NOTE:Timings for theSysADCandSysCmdPbuses are the same as those of the
SysADandSysCmdbuses, respectively.
User’s Manual  U11761EJ6V0UM 259

Chapter 15  System Interface Protocols
External
| Master | Processor | Agent | Processor |
| --- | --- | --- | --- |
| SysCycle | 1 | 2 | 3 4 5 6 7 8 9 10 11 12 SysClock Addr Data0 SysAD Bus |
| 3 | 4 Cmd NEOD SysCmd Bus ValidIn* | 6 |  |
| ExtRqst* | 1 | 5 |  |
2
Release*
Figure  15-13   Arbitration Protocol for External Requests
15.6.2 External Null Request Protocol
The processor supports a system interface external null request, which returns the
System interface to master state from slave state without otherwise affecting the
processor.
External null requests require no action from the processor other than to return the
System interface to master state.
Figure 15-14 shows a timing diagram of an external null request, which consist of the
following steps:
1. The external agent drives a system interface release external null request
command on theSysCmdbus, and assertsValidIn*for one cycle to return system
interface ownership to the processor.
2. TheSysADbus is unused (does not contain valid data) during the address cycle
associated with an external null request.
3. After the address cycle is issued, the null request is complete.
For aSystem interface release external null request, the external agent releases the
SysCmdandSysADbuses, and expects the System interface to return to the master
state.
260 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
External Agent Processor
Master
SysCycle	1	2	3	4	5	6	7	8	9	10	11	12
SysClock
2
SysAD Bus Unsd
3
SysCmd Bus SINull
1
ValidOut*
ValidIn*
ExtRqst*
Release*
Figure  15-14   System Interface Release External Null Request
15.6.3 External Write Request Protocol
External write requests use a protocol identical to the processor single word write
protocol except theValidIn*signal is asserted instead ofValidOut*.  Figure 15-15
shows a timing diagram of an external write request, which consists of the following
steps:
1. The external agent assertsExtRqst*to arbitrate for the System interface.
2. The processor releases the System interface to slave state by assertingRelease*.
3. The external agent drives a write command on theSysCmdbus, a write address
on theSysADbus, and assertsValidIn*.
4. The external agent drives a data identifier on theSysCmdbus, data on theSysAD
bus, and assertsValidIn*.
5. The data identifier associated with the data cycle must contain a coherent or
noncoherent last data cycle indication.
6. After the data cycle is issued, the write request is complete and the external agent
sets theSysCmdandSysADbuses to a tristate, allowing the System interface to
return to master state.  Timings for theSysADCandSysCmdPbuses are the same
as those of theSysADandSysCmdbuses, respectively.
External write requests are only allowed to write a word of data to the processor.
Processor behavior in response to an external write request for any data element other
than a word is undefined.
User’s Manual  U11761EJ6V0UM 261

Chapter 15  System Interface Protocols
Processor	External Agent	Processor
Master
SysCycle	1	2	3	4	5	6	7	8	9	10	11	12
SysClock
SysAD Bus Addr Data0
6
SysCmd Bus Write NEOD
5
ValidOut* 3
4
ValidIn*
1
ExtRqst*
2
Release*
Figure  15-15   External Write Request, with System Interface Initially a Bus Master
15.6.4 Read Response Protocol
An external agent must return data to the processor in response to a processor read
request by using a read response protocol.  A read response protocol consists of the
following steps:
1. The external agent waits for the processor to perform an uncompelled change to
slave state.
2. The processor returns the data through a single data cycle or a series of data cycles.
3. After the last data cycle is issued, the read response is complete and the external
agent sets theSysCmdandSysADbuses to a tristate.
4. The System interface returns to master state.
NOTE:The processor always performs an uncompelled change to slave state
after issuing a read request.
5. The data identifier for data cycles must indicate the fact that this data isresponse
data.
6. The data identifier associated with the last data cycle must contain alast data cycle
indication.
For read responses to non-coherent block read requests, the response data does not
need to identify the initial cache state. The cache state is automatically assigned as
dirty exclusive by the processor.
262 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
The data identifier associated with a data cycle can indicate that the data transmitted
during that cycle is erroneous; however, an external agent must return a data block of
the correct size regardless of the fact that the data may be in error.
The processor only checks the error bit for the first doubleword of the block. The
remaining error bits for the block are ignored.
Read response data must only be delivered to the processor when a processor read
request is pending.  The behavior of the processor is undefined when a read response
is presented to it and there is no processor read pending.
Figure 15-16 illustrates a processor word read request followed by a word read
response. Figure 15-17 illustrates a read response for a processor block read with the
System interface already in slave state.
NOTE:Timings for theSysADCandSysCmdPbuses are the same as those of
theSysADandSysCmdbuses, respectively.
| Master | Processor | External Agent | Processor |
| --- | --- | --- | --- |
| SysCycle | 1 | 2 | 3 4 5 6 7 8 9 10 11 12 SysClock |
| SysAD Bus | Addr | Data0 3 4 Read NEOD SysCmd Bus ValidOut* 2 6 ValidIn* ExtRqst* |  |
1
Release*
Figure  15-16   Processor Word Read Request, Followed by a Word Read Response
User’s Manual  U11761EJ6V0UM 263

Chapter 15  System Interface Protocols
External Agent Processor
SysCycle	1	2	3	4	5	6	7	8	9	10	11	12
SysClock
SysAD Bus Data0Data1Data2Data3
3 4
SysCmd Bus NDataNDataNDataNEOD
ValidOut* 2
6
5
ValidIn*
ExtRqst*
Release*
Figure  15-17   Block Read Response, System Interface already in Slave State
15.7 SysADC[7:0] Protocol
The following rules apply to the use ofSysADC[7:0]during a block read response.
• Data is checked on only the first doubleword of the transfer. If data is
erroneous (SysCmd[5]=1), the primary and secondary cache lines are
invalidated and a bus error exception is generated.
• A parity error on the first doubleword will be detected as it issused and
will cause a cache parity error exception.  The cache line will be valid.
Parity errors in subsequent doubles will be detected if they are used.
• On the following three doublewords; The data erroneous bit is ignored.
Parity for each of the three doublewords is written into the cache, but is
not checked until the data is referenced.
• Any read that will fill the secondary cache must receive correct parity for
all 4 doublewords (SysCmd[4]=0) for data going to the secondary cache.
• For a secondary cache mode read hit cycle; Data erroneous is implicitly
OFF. Check parity is implicitly ON, indicating that the secondary cache
must implement theSysADCbits.
264 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
• If a memory error occurs during a block read operation, theSysADCbits
should be forced to bad parity for all bytes affected by the memory error
during the read response. Since the processor performs an early-restart on
data cache line fills, setting theSysCmd[5]bit on any transfer other than
the first doubleword does not cause a bus error. Forcing bad parity will
generate a cache error if any of the remaining three doublewords of the
transfer are referenced.
15.8 Data Rate Control
The System interface supports a maximum data rate of one doubleword per cycle.  The
rate at which data is delivered to the processor can be determined by the external
agent—for example, the external agent can drive data and assertValidIn*everyn
cycles, instead of every cycle.  An external agent can deliver data at any rate it chooses.
The processor only accepts cycles as valid whenValidIn*is asserted and theSysCmd
bus contains a data identifier; thereafter, the processor continues to accept data until it
receives the data word tagged as the last one.
Figure 15-18 shows a read response in which data is provided to the processor at a rate
of two doublewords every three cycles using the data patternDDx.
External Agent Processor
Master
SysCycle	1	2	3	4	5	6	7	8	9	10	11	12
SysClock
SysAD Bus	Data0Data1	Data2Data3
SysCmd Bus	NDataNData	NDataNEOD
ValidOut*
ValidIn*
ExtRqst*
Release*
Figure  15-18   Read Response, Reduced Data Rate, System Interface in Slave State
User’s Manual  U11761EJ6V0UM 265

Chapter 15  System Interface Protocols
15.9 Data Transfer Patterns
A data pattern is a sequence of letters indicating thedataandunusedcycles that repeat
to provide the appropriate data rate.  For example, the data patternDDxxspecifies a
repeatable data rate of two doublewords every four cycles, with the last two cycles
unused.  Table 15-2 lists the maximum processor data rate for each of the possible
block write modes that may be specified at boot time.
Table 15-2   Transmit Data Rates and Patterns
Maximum Data Rate Data Pattern
1 Double/1 SysClock Cycle DDDD
2 Doubles/3 SysClock Cycles DDxDDx
1 Double/2 SysClock Cycles DDxxDDxx
1 Double/2 SysClock Cycles DxDxDxDx
2 Doubles/5 SysClock Cycles DDxxxDDxxx
1 Double/3 SysClock Cycles DDxxxxDDxxxx
1 Double/3 SysClock Cycles DxxDxxDxxDxx
1 Double/4 SysClock Cycles DDxxxxxxDDxxxxxx
1 Double/4 SysClock Cycles DxxxDxxxDxxxDxxx
In Table 15-2, data patterns are specified using the lettersDandx;Dindicates a data
cycle andxindicates an unused cycle.
266 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
15.10 Independent Transmissions on the SysAD Bus
In most applications, theSysADbus is a point-to-point connection, running from the
processor to a bidirectional registered transceiver residing in an external agent.  For
these applications, theSysADbus has only two possible drivers, the processor or the
external agent.
Certain applications may require connection of additional drivers and receivers to the
SysADbus, to allow transmissions over theSysADbus that the processor is not
involved in.  These are calledindependenttransmissions.  To effect an independent
transmission, the external agent must coordinate control of theSysADbus by using
arbitration handshake signals and external null requests.
An independent transmission on theSysADbus follows this procedure:
1. The external agent requests mastership of theSysADbus, to issue an external
request.
2. The processor releases the System interface to slave state.
3. The external agent then allows the independent transmission to take place on the
SysADbus, making sure thatValidIn*is not asserted while the transmission is
occurring.
4. When the transmission is complete, the external agent must issue aSystem
interface release external null requestto return the System interface to master
state.
15.11 System Interface Endianness
The endianness of the System interface is programmed at boot time through the boot-
time mode control interface and theBigEndianpin. TheBigEndianpin allows the
system to change the processor addressing mode without rewriting the mode ROM. If
endianness is to be specified via theBigEndianpin, program mode ROM bit 8 to zero.
If endianness is to be specified by the mode ROM, ground theBigEndianpin.
Software cannot change the endianness of the System interface and the external
system; software can set the reverse endian bit to reverse the interpretation of
endianness inside the processor, but the endianness of the System interface remains
unchanged.
User’s Manual  U11761EJ6V0UM 267

Chapter 15  System Interface Protocols
15.12 System Interface Cycle Time
The processor specifies minimum and maximum cycle counts for various processor
transactions and for the processor response time to external requests.  Processor
requests themselves are constrained by the System interface request protocol, and
request cycle counts can be determined by examining the protocol.  The following
System interface interactions can vary within minimum and maximum cycle counts:
• waiting period for the processor to release the System interface to slave
state in response to an external request (release latency)
• response time for an external request that requires a response (external
response latency).
The remainder of this section describes and tabulates the minimum and maximum
cycle counts for these System interface interactions.
15.13 Release Latency
Release latencyis generally defined as the number of cycles the processor can wait to
release the System interface to slave state for an external request.  When no processor
requests are in progress, internal activity can cause the processor to wait some number
of cycles before releasing the System interface.  Release latency is therefore more
specifically defined as the number of cycles that occur between the assertion of
ExtRqst* and the assertion ofRelease*.
There are three categories of release latency:
• Category 1: when the external request signal is asserted two cycles before
the last cycle of a processor request.
• Category 2: when the external request signal is not asserted during a
processor request or is asserted during the last cycle of a processor
request.
• Category 3: when the processor makes an uncompelled change to slave
state.
268 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
Table 15-3 summarizes the minimum and maximum release latencies for requests that
fall into categories 1, 2, and 3.  Note that the maximum and minimum cycle count
values are subject to change.
Table 15-3   Release Latency for External Requests
Category	Minimum PCycles	Maximum PCycles
14 6
24 24
30 0
15.14 System Interface Commands/Data Identifiers
System interface commands specify the nature and attributes of any System interface
request; this specification is made during the address cycle for the request.  System
interface data identifiers specify the attributes of data transmitted during a System
interface data cycle.
The following sections describe the syntax, that is, the bitwise encoding of System
interface commands and data identifiers.
Reserved bits and reserved fields in the command or data identifier should be set to 1
for System interface commands and data identifiers associated with external requests.
For System interface commands and data identifiers associated with processor
requests, reserved bits and reserved fields in the command and data identifier are
undefined.
15.14.1   Command and Data Identifier Syntax
System interface commands and data identifiers are encoded in 9 bits and are
transmitted on theSysCmdbus from the processor to an external agent, or from an
external agent to the processor, during address and data cycles.  Bit 8 (the most-
significant bit) of theSysCmdbus determines whether the current content of the
SysCmdbus is a command or a data identifier and, therefore, whether the current cycle
is an address cycle or a data cycle.  For System interface commands,SysCmd(8)must
be set to 0. For System interface data identifiers,SysCmd(8)must be set to 1.
User’s Manual  U11761EJ6V0UM 269

Chapter 15  System Interface Protocols
15.14.2   System Interface Command Syntax
This section describes theSysCmdbus encoding for System interface commands.
Figure 15-19 shows a common encoding used for all System interface commands.
| 8 | 7 | 5 | 4 | 0 |
| --- | --- | --- | --- | --- |
| 0 | Request Type | Request Specific Figure  15-19   System Interface Command Syntax Bit Definition SysCmd(8)must be set to 0 for all System interface commands. SysCmd(7:5)specify the System interface request type which may be read, write, or null. Table 15-4 shows the types of requests encoded by theSysCmd(7:5)bits. Table 15-4   Encoding ofSysCmd(7:5)for System Interface Commands SysCmd(7:5) Command 0 Read Request 1 Reserved 2 Write Request 3 Null Request 4-7 Reserved SysCmd(4:0)are specific to each type of request and are defined in each of the following sections. (1) Read Requests Figure 15-20 shows the format of aSysCmdread request. |  |  |
| 8 | 7 | 5 | 4 | 3 2 1 0 Read Request Specific 0 000 (see tables) Figure  15-20   Read RequestSysCmdBus Bit Definition Tables 15-5 through 15-7 list the encodings ofSysCmd(4:0)for read requests. 270 User’s Manual  U11761EJ6V0UM |

Chapter 15  System Interface Protocols
Table 15-5   Encoding ofSysCmd(4:3)for Read Requests
SysCmd(4:3) Read Attributes
0-1 Reserved
2 Noncoherent block read
3 Doubleword, partial doubleword, word, or partial word
Table 15-6   Encoding ofSysCmd(1:0)for Block Read Request
SysCmd(1:0) Read Block Size
0 Reserved
1 8 words
2-3 Reserved
Table 15-7   Read Request Data Size Encoding ofSysCmd(2:0)
SysCmd(2:0) Read Data Size
0 1 byte valid (Byte)
1 2 bytes valid (Halfword)
2 3 bytes valid (Tribyte)
3 4 bytes valid (Word)
4 5 bytes valid (Quintibyte)
5 6 bytes valid (Sextibyte)
6 7 bytes valid (Septibyte)
7 8 bytes valid (Doubleword)
(2) Write Requests
Figure 15-21 shows the format of aSysCmdwrite request.
Table 15-8 lists the write attributes encoded in bitsSysCmd(4:3). Table 15-9 lists the
block write replacement attributes encoded in bitsSysCmd(2:0). Table 15-10 lists the
write request bit encodings inSysCmd(2:0).
8	7	5	4	3	2	1	0
0	010	Write Request Specific
(see tables)
Figure  15-21   Write RequestSysCmdBus Bit Definition
User’s Manual  U11761EJ6V0UM 271

Chapter 15  System Interface Protocols
Table 15-8   Write Request Encoding ofSysCmd(4:3)
SysCmd(4:3) Write Attributes
0 Reserved
1 Reserved
2 Block write
Doubleword, partial doubleword, word, or
3
partial word
Table 15-9   Block Write Request Encoding ofSysCmd(2:0)
SysCmd(2) Reserved
SysCmd(1:0) Write Block Size
0 Reserved
1 8 words
2-3 Reserved
Table 15-10   Write Request Data Size Encoding ofSysCmd(2:0)
SysCmd(2:0) Write Data Size
0 1 byte valid (Byte)
1 2 bytes valid (Halfword)
2 3 bytes valid (Tribyte)
3 4 bytes valid (Word)
4 5 bytes valid (Quintibyte)
5 6 bytes valid (Sextibyte)
6 7 bytes valid (Septibyte)
7 8 bytes valid (Doubleword)
(3) Null Requests
Figure 15-22 shows the format of aSysCmdnull request.
8	7	5	4	3	2	1	0
0	011	Null Request Specific
(see tables)
Figure  15-22   Null RequestSysCmdBus Bit Definition
272 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
System interface release external null requests use the null request command.  Table
15-11 lists the encodings ofSysCmd(4:3)for external null requests.
SysCmd(2:0)are reserved for null requests.
Table 15-11   External Null Request Encoding ofSysCmd(4:3)
SysCmd(4:3) Null Attributes
0 System Interface release
1-3 Reserved
15.14.3   System Interface Data Identifier Syntax
This section defines the encoding of theSysCmdbus for System interface data
identifiers.  Figure 15-23 shows a common encoding used for all System interface data
identifiers.
| 8 | 7 See | 6 | 5 | 4 | 3 | 2 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 1 | Last | Resp | Err | Note | Cache Reserved |  |  |
| Data | Data | Data | below Figure  15-23   Data IdentifierSysCmdBus Bit Definition SysCmd(8)must be set to 1 for all System interface data identifiers. NOTE:  SysCmd(4)is reserved for processor data identifier.   In an external data identifier,SysCmd(4)indicates whether or not to check the data and check bits for error. (1) Noncoherent Data Noncoherent data is defined as follows: • data that is associated with processor block write requests and processor doubleword, partial doubleword, word, or partial word write requests • data that is returned in response to a processor noncoherent block read request or a processor doubleword, partial doubleword, word, or partial word read request • data that is associated with external write requests • data that is returned in response to an external read request User’s Manual  U11761EJ6V0UM 273 | State |  |  |  |

Chapter 15  System Interface Protocols
(2) Data Identifier Bit Definitions
SysCmd(7)marks the last data element andSysCmd(6)indicates whether or not the
data is response data, for both processor and external coherent and noncoherent data
identifiers.  Response data is data returned in response to a read request.
SysCmd(5)indicates whether or not the data element is error free. Erroneous data
contains an uncorrectable error and is returned to the processor, forcing a bus error.  In
the case of a block response, the entire line must be delivered to the processor no matter
how minimal the error. Note that the processor only checksSysCmd[5]during the first
doubleword of a block read response.
SysCmd(4)indicates to the processor whether to check the data and check bits for this
data element, for both coherent and noncoherent external data identifiers.
SysCmd(3)is reserved for external data identifiers.
SysCmd(4:3)are reserved for noncoherent processor data identifiers.
SysCmd(2:0)are reserved for non-coherent data identifiers.
Table 15-12 lists the encodings ofSysCmd(7:3)for processor data identifiers. Table
15-13 lists the encodings ofSysCmd(7:3)for external data identifiers.
Table 15-12   Processor Data Identifier Encoding ofSysCmd(7:3)
SysCmd(7) Last Data Element Indication
0 Last data element
1 Not the last data element
SysCmd(6) Response Data Indication
0 Data is response data
1 Data is not response data
SysCmd(5) Good Data Indication
0 Data is error free
1 Data is erroneous
SysCmd(4) Data Parity Checking Enable
0 Check data parity
1 Ignore data parity
SysCmd(3) Reserved
274 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
Table 15-13   External Data Identifier Encoding ofSysCmd(7:3)
SysCmd(7) Last Data Element Indication
0 Last data element
1 Not the last data element
SysCmd(6) Response Data Indication
0 Data is response data
1 Data is not response data
SysCmd(5) Good Data Indication
0 Data is error free
1 Data is erroneous
SysCmd(4) Data Checking Enable
0 Check the data and check bits
1 Do not check the data and check bits
SysCmd(3) Reserved
15.15 System Interface Addresses
System interface addresses are full 36-bit physical addresses presented on the least-
significant 36 bits (bits 35 through 0) of theSysADbus during address cycles. Virtual
address bitsVA[13:12]appear onSysAD[57:56]. The remaining bits of theSysAD
bus are unused during address cycles.
15.15.1   Addressing Conventions
Addresses associated with doubleword, partial doubleword, word, or partial word
transactions and update requests, are aligned for the size of the data element.  The
system uses the following address conventions:
• Addresses associated with block requests are aligned to double-word
boundaries; that is, the low-order 3 bits of address are 0.
However, when the Branch instruction is used to jump to a word
boundary (SysAD[2:0]=100) which is not a double-word boundary
(SysAD[2:0]=000) of the non-cache area, LOW is not output for the low-
order 3rd bit of the address that is output toSysADfor instruction
fetching; instead,SysAD[2:0]=100 is output.
User’s Manual  U11761EJ6V0UM 275

Chapter 15  System Interface Protocols
In other words, when a jump to the non-cache area with a low-order byte
address of 0x4 and 0xC has occurred, double-word access occurs but the
low-order bytes of the output address remain as 0x4 and 0xC.
Immediately after such a branch, the CPU uses the word data whose byte
addresses are indicated by 0x4 and 0xC.
• Doubleword requests set the low-order 3 bits of address to 0.
• Word requests set the low-order 2 bits of address to 0.
• Halfword requests set the low-order bit of address to 0.
• Byte, tribyte, quintibyte, sextibyte, and septibyte requests use the byte
address.
15.15.2   Subblock Ordering
The order in which data is returned in response to a processor block read request is
subblock ordering.  In subblock ordering, the processor delivers the address of the
requested doubleword within the block.  An external agent must return the block of
data using subblock ordering, starting with the addressed doubleword.
For block write requests, the processor always delivers the address of the doubleword
at the beginning of the block; the processor delivers data beginning with the
doubleword at the beginning of the block and progresses sequentially through the
doublewords that form the block.
During data cycles, the valid byte lines depend upon the position of the data with
respect to the aligned doubleword (this may be a byte, halfword, tribyte, quadbyte/
word, quintibyte, sextibyte, septibyte, or an octalbyte/doubleword).  For example, in
little-endian mode, on a byte request where the address modulo 8 is 0,SysAD(7:0)are
valid during the data cycles. Table 15-14 lists the byte lanes used for partial word
transfers for both big and little endian.
276 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
Table 15-14   Partial Word Transfer Byte Lane Usage
SysAD byte lanes used (Big Endian)
# Bytes Address
SysCmd[2:0] Mod 8
63:56  55:48 47:40 39:32 31:24 23:16  15:8 7:0
0X
1X
2X
1 3X
(000) 4X
5X
6X
7X
0XX
2XX
2
(001)
4XX
6XX
0XXX
1 XXX
3
4 XXX
(010)
5 XXX
4 0    XXXX
(011)	4	XXXX
0    XXXXX
5
(100)
3 XXXXX
0    XXXXXX
6
(101)
2 XXXXXX
0    XXXXXXX
7
(110)
1 XXXXXXX
8 (111)	0	X	XXXXXXX
7:0	15:8	23:16	31:24	39:32	47:40	55:48	63:56
SysAD byte lanes used (Little Endian)
User’s Manual  U11761EJ6V0UM 277

Chapter 15  System Interface Protocols
15.15.3   Processor Internal Address Map
External reads and writes provide access to processor internal resources that may be of
interest to an external agent.  The processor decodes bitsSysAD(6:4)of the address
associated with an external read or write request to determine which processor internal
resource is the target.  However, the processor does not contain any resources that are
readablethrough an external read request.  Therefore, in response to an external read
request the processor returns undefined data and a data identifier with itsErroneous
Databit,SysCmd(5), set.  TheInterruptregister is the only processor internal resource
available forwriteaccess by an external request.  TheInterruptregister is accessed by
an external write request with an address of 000on bits 6:4 of theSysADbus.
2
15.16 Error Checking
15.16.1   Parity Error Checking
The V 5000 processor uses only parity (error detection only).
R
Parity is the simplest error detection scheme.  By appending a bit to the end of an item
of data—called aparity bit—single bit errors can be detected; however, these errors
cannot be corrected.
278 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
There are two types of parity:
• Odd Parityadds 1 to any even number of 1s in the data, making the total
number of 1s odd (including the parity bit).
• Even Parityadds 1 to any odd number of 1s in the data, making the total
number of 1s even (including the parity bit).
Odd and even parity are shown in the example below:
| Data(3:0) | Odd Parity Bit | Even Parity Bit |
| --- | --- | --- |
| 0  0  1  0 | 0 The example above shows a single bit inData(3:0)with a value of 1; this bit is Data(1). • In even parity, the parity bit is set to 1.  This makes 2 (an even number) the total number of bits with a value of 1. • Odd parity makes the parity bit a 0 to keep the total number of 1-value bits an odd number—in the case shown above, the single bitData(1). The example below shows odd and even parity bits for various data values: | 1 |
| Data(3:0) | Odd Parity Bit | Even Parity Bit |
| 0   1   1   0 | 1 | 0 |
| 0   0   0   0 | 1 | 0 |
| 1   1   1   1 | 1 | 0 |
| 1   1   0   1 | 0 Parity allows single-bit error detection, but it does not indicate which bit is in error— for example, suppose an odd-parity value of 00011 arrives.  The last bit is the parity bit, and since odd parity demands an odd number (1,3,5) of 1s, this data is in error: it has an even number of 1s.  However it is impossible to tellwhichbit is in error. 15.16.2   Error Checking Operation The processor verifies data correctness by using parity as it passes data from the System interface to/from the primary caches. User’s Manual  U11761EJ6V0UM 279 | 1 |

Chapter 15  System Interface Protocols
(1) System Interface
The processor generates correct check bits for doubleword, word, or partial-word data
transmitted to the System interface.  As it checks for data correctness, the processor
passes data check bits from the primary cache, directly without changing the bits, to
the System interface.
The processor does not check data received from the System interface for external
writes.  By setting theSysCmd[4]bit in the data identifier, it is possible to prevent the
processor from checking read response data from the System interface.
The processor does not check addresses received from the System interface and does
not generate check bits for addresses transmitted to the System interface.
The processor does not contain a data corrector; instead, the processor takes a cache
error exception when it detects an error based on data check bits.  Software is
responsible for error handling.
(2) System Interface Command Bus
In the V 5000 processor, the System interface command bus has a single parity bit,
R
SysCmdP, that provides even parity over the 9 bits of this bus.  TheSysCmdPparity
bit is not generated when the system interface is in master state and is not checked
when the System interface is in slave state. This signal is defined to maintain V 4000
R
compatibility and is not functional in the V 5000.
R
280 User’s Manual  U11761EJ6V0UM

Chapter 15  System Interface Protocols
(3) Summary of Error Checking Operations
Error checking operations are summarized in Table 15-15 and 15-16.
Table 15-15   Error Checking Operation for Internal Transactions
Primary Primary
| Uncached | Uncached | Cache Load | Cache Write to Bus | Cache |
| --- | --- | --- | --- | --- |
| Load | Store | from System Interface Interface | System | Instruction |
| Processor Data | From system | Not checked | From system | Checked; Trap Check on |
| interface | on error | cache write- unchanged back; Trap on error |  |  |
| System Address, | Not | Not | Not | Not Not |
| Command, and | Generated | Generated | Generated | Generated Generated Check bits; Transmit |
| System Address, | Not Checked | Not Checked | Not Checked | Not Checked Not Checked Command, and Check Bits; Receive |
| System | Checked, | From | Checked on | From primary From primary |
| Interface Data | Trap on error doubleword, Trap on error | Processor | requested | cache cache |
| System | Checked, | Generated | Checked on | From primary From primary |
| Interface Data | Trap on error Check Bits doubleword, Trap on error User’s Manual  U11761EJ6V0UM 281 | requested | cache | cache |

Chapter 15  System Interface Protocols
Table 15-16   Error Checking Operation for External Transactions
Bus External Write
Processor Data NA
System Address, Command, and Check NA
bits; Transmit
System Address, Command, and Check Not Checked
Bits;  Receive
System Interface Data Not Checked
System Interface Data Check Bits Not  Checked
282 User’s Manual  U11761EJ6V0UM

Chapter 16  Secondary Cache Interface
The V 5000 processor supports an external secondary cache by providing an internal
R
secondary cache controller with a dedicated secondary cache port.
16.1 Secondary Cache Transactions
For processors configured with a secondary cache, the secondary cache is a special
form of external agent that is jointly controlled by both the processor and the external
agent. Figure Figure 16-1 illustrates a processor request to the secondary cache and
external agent.
User’s Manual   U11761EJ6V0UM 283

Chapter 16  Secondary Cache Interface
V 5000
R
External Agent
Processor Requests
•  Read
•  Write
Secondary Cache
Figure  16-1   Processor Requests to Secondary Cache and External Agent
16.1.1 Secondary Cache Probe, Invalidate, and Clear
For secondary cache invalidate, clear, and probe operations, the secondary cache is
controlled by the processor and the external agent is not involved in these operations.
Issuance of secondary cache invalidate, clear, and probe operations is not flow-
controlled and proceeds at the maximum data rate. Figures 16-2 and 16-3 shows the
secondary cache invalidate and tag probe operations.
V 5000
R
Secondary Cache
1.  Invalidate/Clear Request
Figure  16-2   Secondary Cache Invalidate and Clear
284 User’s Manual   U11761EJ6V0UM

Chapter 16  Secondary Cache Interface
V 5000
R
Secondary Cache
1.  Probe Request
2.  Tag Response
Figure  16-3   Secondary Cache Tag Probe
16.1.2 Secondary Cache Write
For secondary cache write-through, the processor issues a block write operation that is
directed to both the secondary cache and the external agent.  Issuance of secondary
cache writes is controlled by the normalWrRdy* flow control mechanism.  Secondary
cache write data transfers proceed at the data transfer rate specified in the Mode ROM
for block writes. Figure 16-4 illustrates a secondary cache write operation.
V 5000
R
External Agent
1. Block Write Request
2. Write Response
Secondary Cache
Figure  16-4   Secondary Cache Write Through
User’s Manual   U11761EJ6V0UM 285

Chapter 16  Secondary Cache Interface
16.1.3 Secondary Cache Read
For secondary cache reads, the processor issues a block read speculatively to both the
secondary cache and the external agent.
- If the block is present in the secondary cache, the secondary cache
provides the read response and the block read to the external agent
is aborted.
- If the block is not present in the secondary cache, the secondary
cache read is aborted and the external agent provides the read
response to both the secondary cache and the processor.
Figures 16-5 and 16-6 shows a secondary cache read hit and miss respectively.
V 5000
R
External Agent
1.  Block Read Request
3. Memory Read Abort
Secondary Cache
2.  Tag Compare
3.  Read Response
Figure  16-5   Secondary Cache Read Hit
286 User’s Manual   U11761EJ6V0UM

Chapter 16  Secondary Cache Interface
V 5000
R
External Agent
1.  Block Read Request
3.  Read Response
Secondary Cache
2.  Tag Compare
3.  Fill Cache Line
Figure  16-6   Secondary Cache Read Miss
Issuance of the secondary cache read is controlled by the normalRdRdy* flow control
mechanism.  Secondary cache read responses always proceed at the maximum data
transfer rate.  External agent read responses to the secondary cache proceed at the data
transfer rate generated by the external agent.
16.2 Secondary Cache Read Protocol
There are three possible scenarios which can occur on a secondary cache access.
1) Secondary cache read hit
2) Secondary cache miss
3) Secondary cache miss with bus error
User’s Manual   U11761EJ6V0UM 287

Chapter 16  Secondary Cache Interface
16.2.1 Secondary Cache Read Hit
Figure 16-7 shows the secondary cache read hit protocol. When a block read request
is speculatively issued to both the secondary cache and the external agent, but
completed by the secondary cache:
1. The processor issues a block read request and also asserts theScTCE*,
ScTDE*, andScDCE*secondary cache control signals. In addition the
processor drives the cache index ontoScLine[15:0]and the sub-block order
doubleword ontoScWord[1:0]. Assertion ofScTCE*, along withValidOut*
andSysCmd,  indicates to the external agent that this is a secondary cache read
request. In addition, the assertion ofScTCE*initiates a tag RAM probe. The
assertion ofScTDE*loads the tag portion of theSysADbus into the tag RAM.
TheScValidsignal is asserted to probe for a valid cache tag. The assertion of
ScDCE*initiates a speculative read of the secondary cache data RAMs.
2. TheScMatchsignal from the tag RAM is sampled by both the processor and the
external agent. Assertion ofScMatchindicates a secondary cache tag hit, causing
the external agent to abort the memory read. Hence there is no uncompelled
change to slave state. The data RAMs now ownSysADand supply the first of a
4 doubleword burst in response to the 4-cycleScDCE*burst. TheSysCmdbus
is not driven during the secondary cache read.
3. Ownership of theSysADbus is returned to the processor.
288 User’s Manual   U11761EJ6V0UM

Chapter 16  Secondary Cache Interface
Master	Processor	Secondary Cache	Processor
SysCycle 1  2 34 5 6 789 10
SysClock
3
SysAD	Addr	Data0	Data1	Data2	Data3
SysCmd[8:0] Read
ScLine[15:0] Index
ScWord[1:0]	I0	I1	I2	I3
1
ScTCE*
ScTDE*
ScValid
2
ScMatch
ScDCE*
ScSWE*
ScDOE*
ValidOut*
Release*
Figure  16-7   Secondary Cache Read Hit
16.2.2 Secondary Cache Read Miss
Figure 16-8 shows the secondary cache read miss protocol when a block read request
is speculatively issued to both the secondary cache and the external agent, but is
completed by the external agent with a response to both the secondary cache and the
processor.
1. The processor issues a block read request and also asserts theScTCE*,
ScTDE*,ScDCE*, andScValidsignals and drives the cache index onto
ScLine[15:0]andScWord[1:0].
2. TheScMatchsignal from the tag RAM is sampled by the processor and external
agent. Since the signal is negated, indicating a secondary cache miss, the SysAD
data from the secondary cache is invalid.
User’s Manual   U11761EJ6V0UM 289

Chapter 16  Secondary Cache Interface
3. The external agent negatesScDOE*to tri-state the data RAM outputs,
indicating that it will be supplying the read response.  The processor tri-states its
ScWord[1:0]outputs to allow the external agent to drive them during the read
response.
4. The processor assertsScCWE*to prepare the data RAMs for a write of the
response data.
5. The external agent supplies the first doubleword of the read response and asserts
ValidIn*. The data is both written into the secondary cache and accepted by the
processor.SysCmdindicates that data is not erroneous. Note that this response
may be delayed additional cycles.
6. The processor assertsScTCE*to write the tag value stored in the tag RAM data
input register two cycles afterValidIn*is asserted.
7. The external agent assertsScDOE*to indicate that it will supply the last
doubleword of the read response in the next cycle.
8. The processor negatesScDCE*two cycles after the next assertion ofScDOE*
in order to complete the secondary cache line fill.
290 User’s Manual   U11761EJ6V0UM

Chapter 16  Secondary Cache Interface
| Processor | Secondary Cache Master SysCycle 1  2 34 5 6 789 10 SysClock | External Agent |
| --- | --- | --- |
| SysAD | Addr | Data0 Data1 Data0 Data1 Data2 Data3 |
| SysCmd[8:0] | Read | NData NData NData NEOD ScLine[15:0] Index |
| ScWord[1:0] | I0 | I1 I2 I3 I0 I1 I2 I3 1 6 ScTCE* ScTDE* ScTOE* ScValid |
2
ScMatch
8
ScDCE*
4
ScCWE*
ScDOE*	3	7
ValidOut*
Release*
5
ValidIn*
Figure  16-8   Secondary Cache Read Miss
16.2.3 Secondary Cache Read Miss with Bus Error
Figure 16-9 shows a secondary cache read miss with bus error protocol. This protocol
is the same as the secondary cache read miss except:
1. The external agent supplies the first doubleword of the read response data with the
data error bit set (SysCmd[5]=1). Note that the data error bit ofSysCmdis only
checked during the first coubleword of a read response.
2. The processor assertsScTCE*andSCTDE*to write the new tag value into the
secondary cache tag RAM withScValidnegated to invalidate this line.
User’s Manual   U11761EJ6V0UM 291

Chapter 16  Secondary Cache Interface
Processor	Secondary Cache	External Agent
Master
SysCycle 1  2 34 5 6 789 10
SysClock
SysAD	Addr	Data0	Data1	Data0	Data1	Data2	Data3
1
SysCmd[8:0]	Read	NData	NData	NData	NEOD
ScLine[15:0] Index
ScWord[1:0]	I0	I1	I2	I3	I0	I1	I2	I3
ScTCE*
2
ScTDE*
ScTOE*
ScValid
ScMatch
ScDCE*
ScCWE*
ScDOE*
ValidOut*
Release*
ValidIn*
Figure  16-9   Secondary Cache Read Miss with Bus Error
16.3 Secondary Cache Write
Figure 16-10 shows a secondary cache write protocol. For the external agent, this
protocol is the same as a non-secondary cache mode block write to the external agent,
but the data is also written into the secondary cache.
292 User’s Manual   U11761EJ6V0UM

Chapter 16  Secondary Cache Interface
1. The processor issues a block write and also assertsScTCE*,ScTDE*, and
ScCWE*in order to write the tag portion of the address onSysADinto the
secondary cache tag RAM. The processor assertsScValidto set the secondary
cache tag to valid.
2. The processor assertsScDCE*to write the block into the secondary cache data
RAMs.
Processor
Master
SysCycle 1  2 34 5 6 78910
SysClock
| SysAD | Address Data0 | Data1 | Data2 | Data3 |
| --- | --- | --- | --- | --- |
| SysCmd[8:0] | Write | NData | NData | NData NEOD ScLine[15:0] Index |
| ScWord[1:0] | I0 | I1 | I2 | I3 |
1
ScTCE*
ScTDE*
ScTOE*
ScValid
2
ScDCE*
ScDOE*
ScCWE*
ValidOut*
Figure  16-10   Secondary Cache Write Operation
User’s Manual   U11761EJ6V0UM 293

Chapter 16  Secondary Cache Interface
16.4 Secondary Cache Line Invalidate
The V 5000 processor has the ability to invalidate either a single line or 128
R
consecutive lines (address aligned) of the secondary cache. The invalidate operation is
analogous to writing to the Tag RAM and invalidating the line in question. The
ScTCE*,ScTDE*, andScCWE*signals are driven active in the same clock as the
SysADandScLinebusses withScValidnegated. Invalidates are the only cache
operations which may occur back-to-back. Note thatValidOut*is not asserted during
secondary cache invalidate operations as the external agent does not participate in
secondary cache invalidates.
Figure 16-11 shows the secondary cache invalidate protocol.
Master Processor
SysCycle 12345
SysClock
SysAD Tag
SysCmd[8:0] Write
ScLine[15:0] Index
ScTCE*
ScTDE*
ScTOE*
ScValid
ScDCE*
ScCWE*
ValidOut*
Figure  16-11   Secondary Cache Line Invalidate
The repeat rate for cache line invalidate instructions is twoSysClocks. The repeat
rate for cache page invalidate is oneSysClockper line for 128 consecutive
SysClockcycles.
294 User’s Manual   U11761EJ6V0UM

Chapter 16  Secondary Cache Interface
16.5 Secondary Cache Probe Protocol
The secondary cache probe operation is analogous to a Tag RAM read operation. The
ScTCE* andScTDE* signals are asserted in the same clock as system address and
the secondary cache line index. The processor then tri-states theSysADbus.ScTOE*
is asserted one clock later and the tag information is driven onto theSysADbus.
ValidOut*is not asserted during a secondary cache probe operation as the external
agent does not participate in secondary cache probes. The Tag RAM bits are driven
ontoSysAD [35:19]andScValid, which are the onlySysADsignals valid during a
probe operation. Figure 16-12 shows a timing diagram of a secondary cache probe
protocol.
Secondary
Processor Cache
Master
SysCycle 12345
SysClock
SysAD[36:19]	Addr	Tag
SysCmd[8:0] Read
ScLine[15:0] Index
ScTCE*
ScTDE*
ScTOE*
Valid
ScValid
ScDCE*
ScCWE*
ValidOut*
Figure  16-12   Secondary Cache Probe (Tag RAM Read)
User’s Manual   U11761EJ6V0UM 295

Chapter 16  Secondary Cache Interface
16.6 Secondary Cache Flash Clear Protocol
In addition to the line invalidate operation, the V 5000 processor also has the ability
R
to invalidate the entire secondary cache in one operation. This operation allows the
processor to clear the entire column of Tag RAM valid bits. In order to execute this
operation the Tag RAM must support a flash clear of the valid bit column. As with the
line invalidate operation,ValidOut*is not asserted during the flash clear operation as
the external agent does not participate in flash clear operations. In addition, the
ScTCE*,ScTDE*, andScCWE*signals need not be asserted. The assertion of
ScCLR*is all that is necessary for the Tag RAM to perform the requested operation.
Figure 16-13 illustrates the secondary cache flash clear protocol.
Processor
Master
SysCycle 12345
SysClock
ScCLR*
Figure  16-13   Secondary Cache Flash Clear
16.7 Secondary Cache Mode Configuration
The secondary cache configuration is specified by the processor ROM mode serial bit
[15]. The state of this bit is indicated by the Secondary Cache (SC) bit in the CP0
config register (bit 17). If bit [17] is zero, a secondary cache is present in the system.
If no secondary cache is present, or the secondary cache is disabled, the processor
drives all secondary cache signals to their inactive state.
If no secondary cache is present and the mode ROM is configured for no secondary
cache, theScMatchandScDOE*signals become don’t-care inputs and must be
terminated to valid logic levels. If the secondary cache is present and enabled, then the
SysADCsignals must implement valid parity during block read responses.
The doublewords transferred onSysADduring secondary cache block read
transactions are in sub-block order. The doublewords transferred onSysADduring
secondary cache block write transactions are in sequential order.
296 User’s Manual   U11761EJ6V0UM

Chapter 16  Secondary Cache Interface
The size of the secondary cache is indicated by the processor mode ROM serial bits
[17:16], and are encoded as follows:
[17:16] = 00 - 512 KB
[17:16] = 01 - 1 MB
[17:16] = 10 - 2 MB
[17:16] = 11 - Reserved
The state of these bits appear as CP0 config register bits [21:20].
User’s Manual   U11761EJ6V0UM 297

Chapter 17  Interrupts
The V 5000 processor supports the following interrupts: six hardware interrupts, one
R
internal “timer interrupt,” two software interrupts, and one nonmaskable interrupt.
The processor takes an exception on any interrupt. This chapter describes the six
hardware and single nonmaskable interrupts.
17.1 Hardware Interrupts
The six CPU hardware interrupts can be caused by either an external write request to
the V 5000, or through dedicated interrupt pins.  These pins are latched into an
R
internal register by the rising edge ofSysClock.
298 User’s Manual   U11761EJ6V0UM

Chapter 17  Interrupts
17.2 Nonmaskable Interrupt (NMI)
The nonmaskable interrupt is caused either by an external write request to the V 5000
R
or by a dedicated pin in the V 5000.  This pin is latched into an internal register by the
R
rising edge ofSysClock.
Caution If a pipeline cancelling logic (e.g. cache error, bus error) occurs after
the V 5000 detects an NMI by the V 5000 starts the NMI handling,
R R
the NMI will be cancelled and only the pipeline cancelling logic will be
handled.
If an NMI cancellation occurred, make NMI* inactive once and then
make it active again after the NMI cancellation.
17.3 Asserting Interrupts
External writes to the CPU are directed to various internal resources, based on an
internal address map of the processor.  WhenSysAD[6:4]= 0, an external write to any
address writes to an architecturally transparent register called theInterruptregister;
this register is available for external write cycles, but not for external reads.
During a data cycle,SysAD[22:16]are the write enables for the seven individual
Interruptregister bits andSysAD[6:0]are the values to be written into these bits.  This
allows any subset of theInterruptregister to be set or cleared with a single write
request. Figure 17-1 shows the mechanics of an external write to theInterruptregister.
Interrupt register
0
SysAD(6:0)
Interrupt Value
1
6543210
2 See Figures 17-2
and 17-3.
3
4
22	21	20	19	18	17	16
5
SysAD(22:16)
6
Write Enables
Figure  17-1   Interrupt Register Bits and Enables
User’s Manual   U11761EJ6V0UM 299

Chapter 17  Interrupts
Figure 17-2 shows how the V 5000 interrupts are readable through the Cause register.
R
• Bit 5 of theInterruptregister is OR’ed with theInt*[5]pin and then
multiplexed with theTimerInterruptsignal. The result is directly
readable as bit 15 of theCauseregister.
• Bits 4:0 of theInterruptregister are bit-wise OR’ed with the current value
of interupt pinsInt*[4:0]. The result is directly readable as bits 14:10 of
theCauseregister.
543210Interrupt register (5:0)
IP2 10
IP3 11
See
IP4 12
Figure 17-4.
IP5
13
IP6
14
IP7
15
Cause
Timer register
Interrupt
(Internal OR gate
| SysClock | 5 | 43210 register) multiplexer |
| --- | --- | --- |
| Int*(5) | Int*(3) | Int*(1) |
| Int*(4) | Int*(2) Figure  17-2   V5000 Interrupt Signals | Int*(0) |
R
300 User’s Manual   U11761EJ6V0UM

Chapter 17  Interrupts
Figure 17-3 shows the internal derivation of theNMIsignal for the V 5000 processor.
R
TheNMI* pin is latched by the rising edge ofSysClock. Bit 6 of theInterruptregister
is then OR’ed with the inverted value ofNMI*to form the nonmaskable interrupt.
Only the falling edge of the latched signal will cause the NMI.
6 Interrupt register (6)
(Internal
register) NMI
(Internal)
NMI*
Edge-
SysClock
triggered
Flip-flop	Inverter	OR gate
Figure  17-3   V5000 Nonmaskable Interrupt Signal
R
Figure 17-4 shows the masking of the V 5000 interrupt signal.
R
• Causeregister bits 15:8 (IP7-IP0) are AND-ORed withStatusregister
interrupt mask bits 15:8 (IM7-IM0) to mask individual interrupts.
• Statusregister bit 0 is a global Interrupt Enable (IE).  It is ANDed with
the output of the AND-OR logic to produce the V 5000 interrupt signal.
R
User’s Manual   U11761EJ6V0UM 301

Chapter 17  Interrupts
Status register
SR(0)
IE
Status register
SR(15:8)
IM0
IM1
IM2
IM3 8
IM4
IM5
IM6
IM7
1 VR5000 Interrupt
1
IP0
IP1
IP2
AND
8
IP3
function
IP4
IP5
AND-OR
IP6
function
IP7
Cause register
(15:8)
Figure  17-4   Masking of the V5000 Interrupt
R
302 User’s Manual   U11761EJ6V0UM

Chapter 18  Standby Mode Operation
The Standby Mode operation is a means of reducing the internal core’s power
consumption when the CPU is in a “standby” state.  In this chapter, the Standby Mode
operation is discussed.
18.1 Entering Standby Mode
To enter Standby Mode, first execute the WAIT instruction.  When the WAIT
instruction finishes the W pipe-stage, if the SysAD bus is currently idle, the internal
clocks will shut down, thus freezing the pipeline.  The PLL, internal timer, some of the
input pin clocks (Int[5:0]*,NMI*,ExtRqst*,Reset*andColdReset*), and the
output clock (ModeClock) will continue to run.  If these conditions are not correct
when the WAIT instruction finishes the W pipe-stage (i.e., theSysADbus is not idle),
the WAIT is treated as a NOP.
When the processor enters Standby Mode, the system interface signals are in their idle
state and the processor is the master of theSysADbus. TheInt*,NMI*,ExtReq*,
Reset*, andColdReset*signals are monitored for an interrupt or reset condition that
signals the end of Standby Mode.
Once the CPU is in Standby Mode, any interrupt, includingExtRqst*orReset*, will
cause the CPU to exit Standby Mode.  Figure 18-1 illustrates the Standby Mode
Operation.
User’s Manual  U11761EJ6V0UM 303

Chapter 18  Standby Mode Operation
V 5000 I/F
R
V 5000 samples the SysAD/SysCmd/Control pins on each rising edge of
R
MasterClock.
SysAD
IfBus Activity
When “Wait” instruction finishes the W-stage, the Detected
SysCmd
V 5000 will check for BUS ACTIVITY.
R
IfBus Activity
“Wait” instruction is treated
ExtRqst*
Not Detected
as a “NOP” instruction.
Int[5:0]*
NMI*
Reset*
Once in Standby Mode, PClock will shutdown, freezing
ColdReset*
the pipeline; however, these signals and internal blocks
will remain active:
Release*
PLL                                  ExtRqst*           ModeClock
Internal Timer                  Int[5:0]             MasterOut
WrRdy*
NMI*
Reset*
RdRdy*
ColdReset*
ValidIn*
If any of Int[5:0]*, NMI*, Reset* are asserted, or an internal
timer interrupt occurs, V 5000 will exit Standby Mode.
R
ValidOut*
After exiting Standby Mode, V 5000 does not sample any Control/
R
SysAD/SysCmd bus signals on the first rising edge of SysClock.  Also,
bus activity and other internal processes will resume by using the latched
information that existed before entering Standby Mode.
Note:During Standby Mode, all control signals for the CPU must be deasserted or put into
the appropriate state, and all input signals, exceptInt[5:0]*,Reset*,ColdReset*and
ExtRqst*, must remain unchanged.
Figure  18-1   Standby Mode Operation
304 User’s Manual  U11761EJ6V0UM

Chapter 19    PLL Analog Power Filtering
For noisy module environments a filter circuit of the following form is
recommended as shown in Figure 19-1.
10 ohm
Vcc VccP
10 uF	0.1 uF	100 pF
Vss VssP
Figure  19-1   PLL Filter Circuit (1)
Because the optimum values of filter elements differ depending on the application
and noise environment of the system, the above values are given for reference
only. Find the optimum values for users’ application through trial and error. A
choke element (inductor) may be used instead of the resistor used as a power filter.
In the case that the processor’s behavior is unstable with the above filter circuit,
as shown in Figure 19-1, please insert a resistor (e.g. 10 ohm) between V and
SS
V P, as shown in Figure 19-2. Please make a full evaluation on your board to
SS
insert the resistor.
User’s Manual   U11761EJ6V0UM 305

Chapter 19      PLL Analog Power Filtering
10 ohm
Vcc VccP
10 uF	0.1 uF	100 pF
Vss VssP
10 ohm
Figure  19-2   PLL Filter Circuit (2)
306 User’s Manual   U11761EJ6V0UM

Chapter 20  V 5000 Instruction Hazards
R
20.1 Introduction
This chapter identifies the V 5000 Instruction Hazards.  Certain combinations of
R
instructions are not permitted because the results of executing such combinations
are unpredictable in combination with some events, such as pipeline delays, cache
misses, interrupts, and exceptions.
Most hazards result from instructions modifying and reading state in different
pipeline stages.  Such hazards are defined between pairs of instructions, not on a
single instruction in isolation.  Other hazards are associated with restartability of
instructions in the presence of exceptions.
For the following code hazards, the behavior is undefined and unpredictable.
User’s Manual  U11761EJ6V0UM 307

Chapter 20  V5000 Instruction Hazards
R
20.2 List of Instruction Hazards
• Any instruction that would modify PageMask or EntryHi or EntryLo0
or EntryLo1 or Random CP0 Registers should not be followed by a
TLBWR instruction.  There should be at least two integer instructions
between the register modification and the TLBWR instruction.
• Any instruction that would modify PageMask or EntryHi or EntryLo0
or EntryLo1 or Index CP0 Registers should not be followed by a
TLBWI instruction.  There should be at least two integer instructions
between the register modification and the TLBWI instruction.
• Any instruction that would modify the Index CP0 Register or the
contents of the JTLB should not be followed by a TLBR instruction.
There should be at least two integer instructions between the register
modification and the TLBR instruction.
• Any instruction that would modify the PageMask or EntryHi or CPO
Registers or the contents of the JTLB should not be followed by a
TLBP instruction.  There should be at least two integer instructions
between the register modification and the TLBPinstruction.
• Any instruction that would modify the EPC or ErrorEPC or Status
CPO Registers should not be followed by an ERET instruction.
There should be at least two integer instructions between the register
modification and the ERET instruction.
• A Branch or Jump instruction is not allowed to be in the delay-slot of
another Branch/Jump instruction.  This sequence is illegal in the
MIPs architecture.
• The two instructions preceding any DIV, DIVU, DDIV, DDIVU,
MULT, MULTU, DMULT or DMULTU instructions  should not read
the HI or LO registers. There should be at least two integer
instructions between the register read and the register modification.
• Any instruction that would modify Count Register should not be
followed by any instruction that would read Count Register when the
Boot Mode Serial bit 18 is 0.  There should be at least two integer
instructions between the register modification and the register read.
308 User’s Manual  U11761EJ6V0UM

Appendix A  Cycle Counts for V 5000 Cache Operations
R
A.1	Cycle Counts for V	5000 Cache Misses
R
A.1.1 Mnemonics
To describe processor sequences that inlude a memory access, the number of cycles
must be calculated based on the system response to a memory access.  Such sequences
will be described with equations based on the following mnemonics:
• SYSDIV:   The number of processor cycles per system cycle, ranges from
2 - 8.
• ML:    Number of system cycles of memory latency defined as the
number of cycles theSysADbus is driven by the external agent before the
first doubleword of data appears.
• DD:     Number of system cycles required to return the block of data,
defined to be the number of cycles beginning when the first doubleword
of data appears on theSysADbus and ending when the last double word
of data appears on theSysADbus inclusive.
• {0 to (SYSDIV - 1)}:     In many equations this term is used.  It has a
value (number of cycles) between 0 and (SYSDIV - 1) depending on the
alignment of the execution of the cache miss or cache op with the system
clock.
User’s Manual  U11761EJ6V0UM 309

Appendix A  Cycle Counts for V5000 Cache Operations
R
A.1.2 DCache Misses
Caveats to DCache Misses:
1)  All Cycle counts are in processor cycles.
2)  DCache misses have lower priority than write backs, external requests, and ICache
misses.  If the write back buffer contains unwritten data when a dcache miss occurs,
the write back buffer will be retired before the handling of the dcache miss is begun.
Instruction cache misses are given priority over data cache misses.  If an icache miss
occurs at the same time as a dcache miss, the icache miss will be handled first.
External requests will be completed before beginning the handling of a dcache miss.
3)  For all data cache misses handling of the returning cache miss data must wait for
the store buffer and response buffer to empty (if they are filled) and for dirty data (if
present) to be moved from the dcache to the write back buffer.  It is possible that if all
of the above occur, and the dcache miss hits in the secondary cache, the first
doubleword of data will return before the data cache is available.  In this case the first
doubleword of data will hold in the response buffer for one or two cycles which will
add to the latency of the dcache miss.
4)  In handling a dcache miss a write back may be required which will fill the write
back buffer.  Write backs can affect subsequent cache misses since they will stall until
the write back buffer is written back to memory.
5)  All cycle counts are best case assuming no interference from the mechanisms
described above.
The following equations yield the number of stall cycles for data cache misses under
the specified circumstances.
Secondary cache hit:
Number_Of_Cycles_For_DCache_Miss_Secondary_Cache_Hit   =
1 + {0 to (SYSDIV - 1)} + (3 x SYSDIV) + 2
Secondary cache miss:
Number_Of_Cycles_For DCache_Miss_Secondary _Cache_Miss  =
1 + {0 to (SYSDIV - 1)} + (2 x SYSDIV) + (ML x SYSDIV) + (1 x SYSDIV) + 2
Note:Memory Latency (ML) has a minimum of 3 to allow for the secondary cache
check.
310 User’s Manual  U11761EJ6V0UM

Appendix A  Cycle Counts for V5000 Cache Operations
R
A.1.3 ICache Misses
Caveats to ICache Misses
1)  All cycle counts are in processor cycles.
2)  ICache misses have lower priority than write backs and external requests.  If the
write back buffer contains unwritten data when an icache miss occurs, the write back
buffer will be retired before the handling of the icache miss is begun.  External requests
will be completed before beginning the handling of an icache miss.
3)  All cycle counts are best case assuming no interference from the mechanisms
described above.
The following equations yield the number of stall cycles for instruction cache misses
under the specified circumstances.
Secondary cache hit:
Number _Of_Cycles_For_ICache_Miss_Secondary_Cache_Hit  =
1 + {0 to (SYSDIV - 1)} + (6 x SYSDIV) + 3
Secondary cache miss:
Number_Of_Cycles_For_ICache_Miss_Secondary_Cache_Miss   =
1 + {0 to (SYSDIV - 1)} + (2 x SYSDIV) + (ML x SYSDIV) + (DD x SYSDIV) + 3
Note:Memory Latency (ML) has a minimum of 3 to allow for the secondary cache
check.
A.2	Cycle Counts for V	5000 Cache Operations
R
Caveats to Cache Operations
1)  All cycle counts are in processor cycles.
2)  All cache ops have lower priority than cache misses, write backs and external
requests.  If the write back buffer contains unwritten data when a cache op is executed,
the write back buffer will be retired before the cache op is begun.  If an instruction
User’s Manual  U11761EJ6V0UM 311

Appendix A  Cycle Counts for V5000 Cache Operations
R
cache miss occurs at the same time as a cache op is executed, the instruction cache miss
will be handled first.  Cache ops are mutually exclusive with respect to data cache
misses.  External requests will be completed before beginning a cache op.
3)  For all data cache ops the cache op machine waits for the store buffer and response
buffer to empty before beginning the cache op.  This can add 3 cycles to any data cache
op if there is data in the response buffer or store buffer.  The response buffer contains
data from the last data cache miss that has not yet been written to the data cache.  The
store buffer contains delayed store data waiting to be written to the data cache.
4)  Cache ops of the form xxxx_Writeback_xxxx may perform a write back which will
fill the write back buffer.  Write backs can affect subsequent cache ops since they will
stall until the write back buffer is written back to memory.  Cache ops which fill the
write back buffer are noted in the following tables.
5)  All cycle counts are best case assuming no interference from the mechanisms
described above.
Table A-1   Primary Data Cache Operations
| Code | Name | Number of Cycles 10 Cycles if the cache line is clean. 0 Index_Writeback_Invalidate_D 12 Cycles if the cache line is dirty.  (Write back) |
| --- | --- | --- |
| 1 | Index_Load_Tag_D | 7 Cycles |
| 2 | Index_Store_Tag_D 10 Cycles for a cache hit. 13 Cycles for a cache miss if the cache line is clean. 3 Create_Dirty_Exclusive_D 15 Cycles for a cache miss if the cache line is dirty. (Writeback) 7 Cycles for a cache miss. 4 Hit_Invalidate_D 9 Cycles for a cache hit. 7  Cycles for a cache miss. 12  Cycles for a cache hit if the cache line is clean. 5 Hit_Writeback_Invalidate_D 14 Cycles for a cache hit if the cache line is dirty. (Writeback) 7  Cycles for a cache miss. 10  Cycles for a cache hit if the cache line is clean. 6 Hit_Writeback_D 14 Cycles for a cache hit if the cache line is dirty. (Writeback) 312 User’s Manual  U11761EJ6V0UM | 8 Cycles |

Appendix A  Cycle Counts for V5000 Cache Operations
R
Table A-2   Primary Instruction Cache Operations
| Code | Name | Number of Cycles 0 Index_Invalidate_I     7 Cycles. 1 Index_Load_Tag_I    7 Cycles. 2 Index_Store_Tag_I    8 Cycles. 3 NA 7 Cycles for a cache miss. 4 Hit_Invalidate_I 9 Cycles for a cache hit. This  equation  yields  the  number  of  processor  cycles  for  a  Fill_I cache op: |
| --- | --- | --- |
| 5 | Fill_I | Number_Of_Cycles_For_A_Fill_I_Cacheop  = 10 + {0 to (SYSDIV -1)} + (2 x SYSDIV) + (ML x SYSDIV) + (DD x SYSDIV). 7  Cycles for a cache miss. 6 Hit_Writeback_I 20 Cycles for a cache hit.  (Writeback) Table A-3   Secondary Cache Operations |
| Code | Name | Number of Cycles This   equation   yields   the   number   of   processor   cycles   for   a Flash_Invalidate_S cache op: 0 Flash_Invalidate_S Number_Of_Cycles_For_Flash_Invalidate_S_Cacheop  = 3 + {0 to (SYSDIV - 1)} + (1 x SYSDIV) + 3 This   equation   yields   the   number   of   processor   cycles   for   an Index_Load_Tag_S cache op: 1 Index_Load_Tag_S Number_Of_Cycles_For_Index_Load_Tag_S   = 3 + {0 to (SYSDIV -1)} + (4 x SYSDIV) + 3 This   equation   yields   the   number   of   processor   cycles   for   an Index_Store_Tag_ Index_Store_Tag_S cache op: |
2
S Number_Of_Cycles_For_Index_Store_Tag_S   =
3 + {0 to (SYSDIV - 1)} + (1 x SYSDIV) + 3
3 NA
4 NA
This   equation   yields   the   number   of   processor   cycles   for   a
Page_Invalidate_S cache op:
5 Page_Invalidate_S
Number_Of_Cycles_For_Page_Invalidate_S   =
3 + {0 to (SYSDIV -1)} + (128 x SYSDIV) + 3
6 NA
User’s Manual  U11761EJ6V0UM 313

Appendix B  Subblock Order
A block of data elements (whether bytes, halfwords, words, or doublewords) can be
retrieved from storage in two ways: in sequential order, or using a subblock order.  This
appendix describes these retrieval methods, with an emphasis on subblock ordering.
Sequential ordering retrieves the data elements of a block in serial, or sequential, order.
Figure B-1 shows a sequential order in which doubleword 0 is taken first and
doubleword 3 is taken last.
DW 0	DW 1	DW 2	DW 3
Doubleword 0 Doubleword 3
taken first taken fourth
Doubleword 1 Doubleword 2
taken second taken third
Figure  B-1   Retrieving a Data Block in Sequential Order
Subblock ordering allows the system to define the order in which the data elements are
retrieved.  The smallest data element of a block transfer for the V 5000 is a
R
doubleword, and Figure B-2 shows the retrieval of a block of data that consists of 4
doublewords, in which DW2 is taken first.
314 User’s Manual  U11761EJ6V0UM

Appendix B  Subblock Order
octalword
quadword
Order of retrieval	2	3	0	1
DW0	DW1	DW2	DW3
DW0 DW 3
taken third taken second
DW1 DW2
taken fourth taken first
Figure  B-2   Retrieving a Data in a Subblock Order
Using the subblock ordering shown in Figure B-2, the doubleword at the target address
is retrieved first (DW2), followed by the remaining doubleword (DW3) in this
quadword.
It may be easier way to understand subblock ordering by taking a look at the method
used for generating the address of each doubleword as it is retrieved.  The subblock
ordering logic generates this address by executing a bit-wise exclusive-OR (XOR) of
the starting block address with the output of a binary counter that increments with each
doubleword, starting at doubleword zero (00).
2
Using this scheme, Table B-1 through Table B-3 list the subblock ordering of
doublewords for an 8-word block, based on three different starting-block addresses:
10, 11, and 01.  The subblock ordering is generated by an XOR of the subblock
2	2	2
address (either 10, 11, and 01) with the binary count of the doubleword (00through
2	2	2	2
11).  Thus, the third doubleword retrieved from a block of data with a starting address
2
of 10is found by taking the XOR of address 10with the binary count of DW2, 10.
2	2	2
The result is 00, or DW0.
2
The remaining tables illustrate this method of subblock ordering, using various address
permutations.
User’s Manual  U11761EJ6V0UM 315

Appendix B  Subblock Order
Table B-1   Subblock Ordering Sequence: Address 10
2
Starting Block Double Word
Cycle Binary Count
Address Retrieved
| 1 | 10 | 00 | 10 |
| --- | --- | --- | --- |
| 2 | 10 | 01 | 11 |
| 3 | 10 | 10 | 00 |
| 4 | 10 Table B-2   Subblock Ordering Sequence: Address 11 | 11 | 01 |
2
Starting Block Double Word
Cycle Binary Count
Address Retrieved
| 1 | 11 | 00 | 11 |
| --- | --- | --- | --- |
| 2 | 11 | 01 | 10 |
| 3 | 11 | 10 | 01 |
| 4 | 11 Table B-3   Subblock Ordering Sequence: Address 01 | 11 | 00 |
2
Starting Block Double Word
Cycle Binary Count
Address Retrieved
| 1 | 01 | 00 | 01 |
| --- | --- | --- | --- |
| 2 | 01 | 01 | 00 |
| 3 | 01 | 10 | 11 |
| 4 | 01 316 User’s Manual  U11761EJ6V0UM | 11 | 10 |

Appendix C  Driver Strength Control
The speed of the V 5000 output drivers is statically controlled at boot time. This
R
appendix discusses the output buffer strength control mechanism in the V 5000
R
processor.
Two of the boot time mode bits are used to control the strength of the output buffer.
These are boot mode bit 13 and 14.
The output driver strength can be from 100% (fastest) to 50% (slowest), based on the
value of boot mode bits 13 and 14. Table C-1 shows the encoding for these boot mode
bits and the selected driver strength.
Table C-1   Output Driver Strength
Boot Mode
Driver
Bits
Strength
14  13
1   0 100%
1   1 83%
0   0 67%
0   1 50%
User’s Manual  U11761EJ6V0UM 317

| Appendix D  Differences between V | 5000 and V R R | 5000A |
| --- | --- | --- |
| Parameter | V5000 | V5000A R R |
| Maximum internal operat- | 150/180/200 MHz ing frequency Note | 250/266 MHz |
| Multiplication ratio for | 2, 3, 4, 5, 6, 7, 8 | 2, 2.5 , 3, 4, 5, 6, 7, 8 clock interface (input vs. internal) |
| Supply voltage | 3.3V±5% | Core: 2.4V±0.1V (100 to 235 MHz) 2.5V±5% (236 to 250 MHz) 2.6V±0.1V (251 to 266 MHz) I/O   : 3.3V±5% |
| Package | •223-pin ceramic PGA •272-pin plastic BGA (cavity down advanced type) (cavity down advanced type) Note Selectable only when SysClock = 100MHz 318 User’s Manual  U11761EJ6V0UM | 272-pin plastic BGA |

| Appendix E  Differences between V | 5000 and V R R | 4310 |
| --- | --- | --- |
| Item | V5000 R R | V4310 |
| Operation Frequency    Internal | 200 MHz MAX. | 167 MHz MAX. |
| External | 100 MHz MAX. | 83.3 MHz MAX. |
| Pipeline | 2-way superscalar 5-stage pipeline | 5-stage pipeline |
| Cache | On-chip Primary | 32 KB (2-way set) 16 KB (direct map) Instruction Cache |
| On-chip Primary Data Cache | 32 KB (2-way set) | 8 KB (direct map) |
| Secondary Cache Interface | Incorporated (direct map) | N/A |
| Data Protection | Byte parity | N/A |
| System Bus | Write Data Transfer Rate (DD, DDxDDx, (DD, DxxDxx) DDxxDDxx, DxDx, DDxxxDDxxx, DDxxxxDDxxxx, DxxDxx, DDxxxxxxDDxxxxxx, DxxxDxxx) | 9 types 2 types |
| SysAD Bus Used after Last | Unused for trailing x | Maintains last D cycle |
| D Cycle | cycles User’s Manual   U11761EJ6V0UM 319 | value |

Appendix E  Differences between V5000 and V4310
R R
| Item | V5000 R R | V4310 |
| --- | --- | --- |
| Boot Mode Setting | Serial data input from ModeIn pin (2:0) | Specific by DivMode |
| Integer Operating Unit | MIPS I, II, III, IV | MIPS I, II, III instruction instruction set set |
| JTAG Interface | N/A | Incorporated |
| SyncIn - SyncOut Path | N/A | Available |
| Clock Interface | PClock Divisor | 2, 3, 4, 5, 6, 7, or 8 1.5, 2, 2.5, 3, 4, 5, or 6 |
| System Bus Clock Divisor | 2, 3, 4, 5, 6, 7, or 8 | 1.5, 2, 2.5, 3, 4, 5, or 6 |
| Clock Output | N/A | TClock |
| Power Control Mode | Standby mode (freezing pipeline) | N/A |
| PRId Register | Imp = 0x23 320 User’s Manual   U11761EJ6V0UM | Imp = 0x0B |

Appendix F  V 5000 Restrictions
R
• Any load-linked memory reference that hits in the DTLB will cause
the LLAddr register to hold the virtual address of that reference
instead of the physical address.
• C0_CacheErr[2] does not report Virtual Address [14] of the parity
error location. This bit is always read as zero.
• If a pipeline cancelling logic (e.g. cache error, bus error) occurs after
the V 5000 detects a non-maskable interrupt (NMI) by the V 5000
R R
starts the NMI handling, the NMI will be cancelled and only the
pipeline cancelling logic will be handled.
If an NMI cancellation occurred, make NMI* inactive once and then
make it active again after the NMI cancellation.
• An LL or LLD instruction targeting 64-bit Kernel xkphys address
space issues a 4-byte uncached read request or 8-byte uncached read
request respectively. If the targeted primary data cache line for an LL/
LLD instruction is dirty, the cache data is ignored and an uncached
load from memory is executed, and consequently the consistency of
data is not guaranteed.
Therefore, write back the line from the primary data cache to
memory before the execution of an LL/LLD instruction targeting
xkphys address space.
Example of a program is as follows.
User’s Manual  U11761EJ6V0UM 321

Appendix F  V5000 Restrictions
R
example:
cache Hit_writeback_d, offset(base)
ll rt, offset(base)
:
sc rt, offset(base)
322 User’s Manual  U11761EJ6V0UM

Appendix G  Index
Numerics B
223-pin ceramic PGA...see PGA Bad Virtual Address (BadVAddr)
272-pin plastic BGA...see BGA register...141
BadVAddr register...see Bad Virtual Address
A register
basic system clocks...222
access type...60
BGA...53
address space...108
branch delay...90
kernel...113
bus interface...231
32-bit...115
terms used...232
64-bit...117
physical...105
C
supervisor...110
32-bit...112 cache
64-bit...112 operation...225
user...108 organization...227
32-bit...109 sizes...227
64-bit...110 Cache Error (CacheErr) register...152
virtual...104 CACHE instruction...72
address translation cache line
32-bit virtual...106 length...227
64-bit virtual...107 cache tag registers...see TagLo or TagHi
virtual-to-physical...105 register
process...135 CacheErr register...see Cache Error register
User’s Manual   U11761EJ6V0UM 323

Appendix G  Index
Cause register...147 error checking operation...279
clock generator...29 system interface...280
clock interface...222 system interface command bus...280
Cold Reset...216 parity error checking...278
Compare register...142 types of...279
Config register...129 Error Exception Program Counter (ErrorEPC)
Context register...140 register...154
Control/Status register (FCR31)...188 ErrorEPC register...see Error Exception
coprocessor 0...see CP0 Program Counter register
Count register...141 ExcCode field...149
CP0...29, 37, 118 exception handler
registers...123 Cache Error...179
CPU registers...30 general...175
TLB/XTLB miss...177
D exception handling
NMI...180
D-cache...see data cache
Reset...180
data addressing...34
Soft Reset...180
data cache (D-cache)...29
exception processing...138
organization...229
registers...139
data formats...34
Exception Program Counter (EPC)
data rate control...265
register...149
data transfer patterns...266
exception servicing guidelines
independent transmission on the SysAD
Cache Error...179
bus...267
general...176
Diagnostic Status (DS) field...146
TLB/XTLB...178
driver strength control...317
exception types...155
FPU...204
E
exceptions...154
ECC register...see Error Checking and Address Error...163
Correcting register Breakpoint...170
EntryHi register...121, 128 Bus Error...168
EntryLo0 register...122, 126 Cache Error...167
EntryLo1 register...122, 126 conditions...94
EPC register...see Exception Program Coprocessor Unusable...172
Counter register detection mechanism...94
error checking...278 Divide-by-Zero...210
Error Checking and Correcting (ECC) Floating-point...173
register...151 handling...174
Inexact...208
Integer Overflow...169
324 User’s Manual   U11761EJ6V0UM

Appendix G  Index
Interrupt...173 floating-point exceptions...204
Invalid Operation...209 actions...207
Non Maskable Interrupt (NMI)...162 conditions...208
Overflow...210 flags...206
priority...160 trap...206
Reserved Instruciton...171 floating-point formats...192
Reset...161 floating-point general registers (FGRs)...183
servicing...174 floating-point registers...185
Soft Reset...161 floating-point unit...181
System Call...170 features...183
TLB...164 programming model...183
TLB, Invalid...166 FPU...see floating-point unit
TLB, Modified...166
TLB, Refill...165 I
Trap...169
I-cache...see instruciton cache
types...155, 204
IEEE standard 754...189
Underflow...210
Implementation and Revision register
Unimplemented Instruciton...211
(FCR0)...187
vector locations...157
Index register...124
extrnal arbitration protocol...259
initialization interface...214
external request protocols...258
boot-mode settings...219
null...260
reset state...218
read response...262
sequence...218
write...261
instruction cache (I-cache)...29
external requests...237
organization...227
read response...239
instruction execution
write...239
cycle time...201
instruction hazards...308
F
instruction latencies
FCR...see floating-point control registers floating point...202
FGR...see floating-point general registers integer...63
fixed-point format instruction pipeline
binary...194 FPU...200
floating-point control registers (FCRs)...186 instruciton scheduling
floating-point exception FPU...203
saving and restoring state...212 instruction set...58, 195
trap handlers...213 instruction set additions
branch on floating point coprocessor...68
floating point compare...69
floating point conditional moves...70
floating point multiply-add...69
User’s Manual   U11761EJ6V0UM 325

Appendix G  Index
indexed floating point load...67 L
indexed floating point store...67
LLAddr register...see Load Linked Address
integer conditional moves...69
register
prefetch...68
load delay...90
reciprocal’s...70
load delay slot...60
instruction set
scheduling...60
CPU...58
Load Linked Address (LLAddr)
floating-point...195
register...132
MIPS IV...64
additions and extensions...65
M
instructions
branch...63 memory management system (MMU)...see
computational...62 memory management unit
64-bit operation...62 memory management unit...101
cycle timing...62 memory organization...226
divide...62 MMU...see memory management unit
floating-point...199
multiply...62 N
conversion
NMI...see interrupt, nonmaskable
FPU...199
coprocessor...64
P
jump...63
load...59 PageMask register...121, 126
FPU...197 PClock...222
special...64 PGA...51
store...59 phase-locked loop (PLL)...223
FPU...197 phase-locked system...224
interface buses...232 pin configuration...51
interlock...91 pipeline...85, 200
condition...92 activities...89
interrupts...298 pipeline stages...86
asserting...299 PLL...see phase-locked loop
hardware...298 PLL analog power filtering...305
nonmaskable (NMI)...299 power-on reset...215
PRId register...see Processor Revision
J Identifier register
processor internal address map...278
joint TLB (JTLB)...41
processor modess...102
operating...103
instruction set...104
addressing...104
326 User’s Manual   U11761EJ6V0UM

Appendix G  Index
processor request protocols...249 signals
flow control...254 clock interface...46
read...250 initialization interface...48
write...251 interrupt interface...48
processor requests...234 secondary cache interface...46
read...236 system interface...44
rules...235 slip
write...237 instruciton cache miss...96
Processor Revision Identifier (PRId) slip conditions...96
register...128 stall conditions...95
Status regsiter...142
R subblock order...314
superscalar
Random register...125
issue mechanism...98
requests
dual...99
handling...240
SysClock...222
reset signal...214
alignment to...223
system control coprocessor...37
S
system event
secondary cache interface...283 load linked store conditional
secondary cache operations operation...243
clear...284 load miss...240
invalidate...284 store hit...243
probe...284 store miss...241
secondary cache uncached instruction fetch...243
mode configuration...296 uncached load...243
protocol uncached store...243
flash clear...296 system interface...234
line invalidate...294 addresses...275
probe...295 addressing conventions...275
write...292 subblock ordering...276
read...286 command...269
read protocol...287 syntax...270
hit...288 null requests...272
miss...289 read requests...270
miss with bus error...291 write requests...271
transactions...283 cycle time...268
write...285 release latency...268
signal...43 data identifiers...269
syntax...273
bit definitions...274
User’s Manual   U11761EJ6V0UM 327

Appendix G  Index
noncoherent data...273
endianness...267
handshake signals...246
protocols...244
address cycle...244
data cycle...244
external arbitration...248
issue cycle...245
master state...248
slave state...248
SysADC[7:0]...264
uncompelled change to
slave state...248
transactions...234
T
TagHi register...132
TagLo register...132
TLB...see translation lookaside buffer
TLB entry
format of...119
TLB exceptions...137
TLB instructions...137
translation lookaside buffer (TLB)...41, 102
hit...102
miss...102
multiple matches...102
V
V 5000 restrictions...321
R
W
Warm Reset...217
Wired register...127
write buffer...97
X
XContext register...150
328 User’s Manual   U11761EJ6V0UM

Although NEC has taken all possible steps
to ensure that the documentation supplied
Facsimile Message
to  our  customers  is  complete,  bug  free
and  up-to-date,  we  readily  accept  that
From:
errors may occur.  Despite all the care and
precautions  we’ve  taken,  you  may
Name encounter problems in the documentation.
Please  complete  this  form  whenever
you’d  like  to  report  errors  or  suggest
Company
improvements to us.
Tel. FAX
Address
Thank you for your kind support.
| North America | Hong Kong, Philippines, Oceania | Asian Nations except Philippines |
| --- | --- | --- |
| NEC Electronics Inc. | NEC Electronics Hong Kong Ltd. | NEC Electronics Singapore Pte. Ltd. |
| Corporate Communications Dept. | Fax:  +852-2886-9022/9044 Fax:  +1-800-729-9288 +1-408-588-6130 Korea Japan Europe NEC Electronics Hong Kong Ltd. NEC Semiconductor Technical Hotline NEC Electronics (Europe) GmbH Seoul Branch Fax:  +81- 44-435-9608 Technical Documentation Dept. Fax:  +82-2-528-4411 Fax:  +49-211-6503-274 South America Taiwan NEC do Brasil S.A. NEC Electronics Taiwan Ltd. Fax:  +55-11-6462-6829 Fax:  +886-2-2719-5951 I would like to report the following error/make the following suggestion: Document title: Document number: Page number: If possible, please fax the referenced page or drawing. | Fax:  +65-250-3583 |
| Document Rating | Excellent | Good Acceptable Poor Clarity Technical Accuracy Organization CS  01.2 |
