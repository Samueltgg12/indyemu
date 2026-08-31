# Dallas 1386 Indy

DS1386
DS1386
RAMified Watchdog Timekeeper
FEATURES PIN ASSIGNMENT
•8K or 32K bytes of user NV RAM
| INTA | 1 | 32 VCC INTA | 1 | 32 VCC |
| --- | --- | --- | --- | --- |
| •Real time quartz clock/calendar keeps track of hun- | INTB | 2 | 31 SQW INTB | 2 31 SQW |
| NC | 3 | 30 VCC | A14 | 3 30 VCC dredths of seconds, seconds, minutes, hours, days, |
| A12 | 4 | 29 | WE | A12 4 29 WE date of the month, months, and years; valid up to 2100 |
| A7 | 5 | 28 NC | A7 | 5 28 A13 |
| A6 | 6 | 27 A8 | A6 | 6 27 A8 •Will operate in 28–pin JEDEC footprint when lower |
| A5 | 7 | 26 A9 | A5 | 7 26 A9 justified |
| A4 | 8 | 25 A11 | A4 | 8 25 A11 |
| •Watchdog timer restarts an out–of–control processor | A3 | 9 | 24 | OE A3 9 24 OE |
| A2 | 10 | 23 A10 | A2 | 10 23 A10 |
| •Alarm function schedules  real-time related activities | A1 | 11 | 22 | CE A1 11 22 CE |
| A0 | 12 | 21 DQ7 | A0 | 12 21 DQ7 such as system wakeup |
| DQ0 | 13 | 20 DQ6 | DQ0 | 13 20 DQ6 |
| •Embedded lithium energy cell maintains time, watch- | DQ1 | 14 | 19 DQ5 | DQ1 14 19 DQ5 |
| DQ2 | 15 | 18 DQ4 | DQ2 | 15 18 DQ4 dog, user RAM, and alarm information |
| GND | 16 | 17 DQ3 | GND | 16 17 DQ3 |
| •Programmable interrupts and square wave output | DS1386 8K x 8 | DS1386 32K x 8 32–PIN ENCAPSULATED 32–PIN ENCAPSULATED |  |  |
| •All registers are individually addressable via the ad- | PACKAGE dress and data bus PIN DESCRIPTION •Accuracy is better than±1 minute/month at 25°C INTA –   Interrupt Output A (open drain) | PACKAGE |  |  |
| •Greater than 10 years of timekeeping in the absence | INTB(INTB) | –   Interrupt Output B (open drain) |  |  |
| of VCC | A0–A14 | –   Address Inputs DQ0–DQ7 –   Data Input/Output •Interrupt signals are active in power–down mode CE –   Chip Enable OE –   Output Enable ORDERING INFORMATION WE –   Write Enable |  |  |
| DS1386 | XX–XXX | RTC and NVSRAM; 32 pin DIP VCC –   +5 Volts |  |  |
| –150   150 ns access | GND | –   Ground –120 120 ns access SQW –   Square Wave Output |  |  |
| 08   8K x 8 NVSRAM | NC | –   No Connection 32 32K x 8 NVSRAM |  |  |
DESCRIPTION
The DS1386 RAMified Watchdog Timekeeper is a self– read or written in the same manner as bytewide static
contained real time clock (RTC), alarm, watchdog timer, RAM.  The timekeeping registers are located in the first
and interval timer in a 32–pin JEDEC DIP package.  The 14 bytes of memory space.  Data is maintained in the
DS1386 contains an embedded lithium energy source RAMified    Timekeeper  by  intelligent  control  circuitry
and a quartz crystal which eliminates the need for any which  detects  the  status  of  VCCand  write  protects
external circuitry.  Data contained within 8K or 32K by memory when VCCis out of tolerance.  The lithium ener-
8–bit  memory  and  the  timekeeping  registers  can  be gy source can maintain data and real time for over ten
Copyright 1995 by Dallas Semiconductor Corporation. 041697 1/12
All Rights Reserved.  For important information regarding
patents and other intellectual property rights, please refer to
Dallas Semiconductor data books.

DS1386
years in the absence of VCC.  Timekeeper information DATA RETENTION
includes  hundredths  of  seconds,  seconds,  minutes, The RAMified Timekeeper provides full functional capa-
hours,  day, date, month, and year.  The date at the end bility when VCCis greater than 4.5 volts and write-pro-
of the month is automatically adjusted for months with tects the register contents at 4.25 volts typical.  Data is
less  than  31  days,  including  correction  for  leap  year. maintained in the absence of VCCwithout any additional
The RAMified Timekeeper operates in either 24 hour or support circuitry.  The DS1386 constantly monitors VCC.
12 hour format with an AM/PM indicator.  The watchdog Should the supply voltage decay, the RAMified Time-
timer provides alarm interrupts and interval timing be- keeper will automatically write–protect itself and all in-
tween 0.01 seconds and 99.99 seconds.  The real time puts to the registers become “don’t care”.  The two inter-
alarm provides for preset times of up to one week. Inter- rupts INTAand INTB(INTB) and the internal clock and
rupts for both watchdog and RTC will operate when sys- timers continue to run regardless of the level of VCC.
tem  is  powered  down.  Either  can  provide  system However, it is important to insure that the pull–up resis-
“wake-up” signals. tors used with the interrupt pins are never pulled up to a
value that is greater than VCC+ 0.3V.  As VCCfalls below
approximately 3.0 volts, a power switching circuit turns
OPERATION – READ REGISTERS
the  internal  lithium  energy  source  on  to  maintain  the
The  DS1386  executes  a  read  cycle  whenever  WE
clock and timer data and functionality.  It is also required
(Write Enable) is inactive (High) and CE(Chip Enable)
to insure that during this time (battery backup mode),
and OE(Output Enable) are active (Low).  The unique
the voltage present at INTAand INTB(INTB) does never
address specified by the address inputs (A0–A14) de-
exceed 3.0V.  At all times the current on each should not
fines which of the  registers is to be  accessed.  Valid
exceed +2.1 mA or –1.0 mA.  During power–up, when
data  will  be  available  to  the  eight  data  output  drivers
VCCrises  above  approximately  3.0  volts,  the  power
within tACC(Access Time) after the last address input
switching  circuit  connects  external  VCCand  discon-
signal is stable, providing that CEand OEaccess times
nects the internal lithium energy source.  Normal opera-
are also satisfied.  If OEand CEaccess times are not
tion can resume after VCCexceeds 4.5 volts for a period
satisfied, then data access must be measured from the
of 200 ms.
latter occurring signal (CEor OE) and the limiting pa-
rameter is either tCOfor CEor tOEfor OErather than ad-
dress access. RAMIFIED TIMEKEEPER REGISTERS
The RAMified Timekeeper has 14 registers which are
eight bits wide that contain all of the timekeeping, alarm,
OPERATION – WRITE REGISTERS
watchdog and control information.  The clock, calendar,
The  DS1386  is  in  the  write  mode  whenever  the  WE
alarm,  and  watchdog  registers  are  memory  locations
(Write Enable) and CE(Chip Enable) signals are in the
which contain external (user–accessible) copies of the
active (Low) state after the address inputs are stable.
timekeeping data. The external copies are independent
The latter occurring falling edge of CEor WEwill deter-
of internal functions except that they are updated peri-
mine the start of the write cycle.  The write cycle is termi-
odically by the simultaneous transfer of the incremented
nated by the earlier rising edge of CEor WE.  All address
internal copy (see Figure 1). The Command Register
inputs must be kept valid  throughout the write cycle.
bits are  affected by both internal and external functions.
WEmust return to the high state for a minimum recovery
This register will be discussed later.  The 8K or 32K by-
state (tWR) before another cycle can be initiated.  Data
tes of RAM and the 14 external timekeeping registers
must  be  valid  on  the  data  bus  with  sufficient  Data
are accessed from the external address and data bus.
Set–Up (tDS) and Data Hold Time (tDH) with respect to
Register 0, 1, 2, 4, 6, 8, 9, and A contain time of day and
the earlier rising edge of CEor WE.  The OEcontrol sig-
date information (see Figure 2).  Time of day information
nal should be kept inactive (High) during write cycles to
is stored in BCD.  Registers 3, 5, and 7 contain the Time
avoid bus contention.  However, if the output bus has
of Day Alarm information.  Time of Day Alarm informa-
been enabled (CEand OEactive), then WEwill disable
tion is stored in BCD.  Register B is the Command Reg-
the outputs in tODWfrom its falling edge.
ister and information in this register is binary.  Registers
C and D are the Watchdog Alarm Registers and infor-
mation which is stored in these two registers is in BCD.
Registers E through 1FFF or 7FFF are user bytes and
can be used to maintain data at the user’s discretion.
041697 2/12

DS1386
BLOCK DIAGRAMFigure 1
INTA INTB(INTB)
SQW
1024HZ
SWAPPINS
DIVIDEBY 4
100HZ“AVG”
TD INTWD INT
(VBAT)
CC
V POWERSWITCH
HUNDREDTHSOF SECONDS
INTERNAL COUNTERS
EXTERNAL REGISTERS
PF DELAY
DIVIDE BY 10
YEARS AND CHECK
TIME OF DAY ALARM
UPDATE SECONDS THRU
INTERNAL COUNTERS
WATCHDOG ALARM
DIVIDE EXTERNAL REGISTERS
JITTER BY 40.96
GENERATOR 100HZ“AVG”
DQ0–DQ7
DATA I/0 BUFFERS
JITTER DIVIDEBY 40.96
GENERATOR
4096HZ
8K X 8NVRAM
INTERNAL REGISTERS
32K X 8 OR
DIVIDEBY 8
EXTERNAL REGISTERS,CLOCK, CALENDAR,TIME OF DAY ALARMCOMMAND REGISTER
32.788HZ
PRESCALER
OSCILLATOR &
ADN COUNTROL
ADDRESS DECODE
OSCILLATOR
(X1) (X2)
CE OEWE
A0–A14A0–A12
QUARTZCRYSTAL
041697 3/12

DS1386
TIME OF DAY REGISTERS update is to do read verifies and re–execute the write
Registers 0, 1, 2, 4, 6, 8, 9, and A contain Time of Day cycle if data is not correct.  While the possibility of erro-
data in BCD.  Ten bits within these eight registers are not neous  results  from  reads  and  write  cycles  has  been
used and will always read zero regardless of how they stated, it is worth noting that the probability of an incor-
are written.  Bits 6 and 7 in the Months Register (9) are rect result is kept to a minimum due to the redundant
binary bits.  When set to logic 0, EOSC(Bit 7) enables structure of the RAMified Timekeeper.
the Real Time Clock oscillator.  This bit is set to logic 1 as
shipped from Dallas Semiconductor to prevent lithium
TIME OF DAY ALARM REGISTERS
energy consumption during storage and shipment.  This
Registers  3,  5,  and  7  contain  the  Time  of  Day  Alarm
bit will normally be turned on by the  user during device
Registers.   Bits 3, 4, 5, and 6 of Register 7 will always
initialization.  However, the oscillator can be turned on
read zero regardless of how they are written.  Bit 7 of
and off as necessary by setting this bit to the appropriate
Registers 3, 5, and 7 are mask bits (Figure 3).  When all
level.  Bit 6 of this same byte controls the Square Wave
of the mask bits are  logic 0, a Time of Day Alarm will only
Output (pin 31).  When set to logic 0, the Square Wave
occur  when  Registers  2,  4,  and  6  match  the  values
Output Pin will output a 1024 Hz Square Wave Signal.
stored in Registers 3, 5, and 7.  An alarm will be gener-
When set to logic 1 the Square Wave Output Pin is in a
ated every day when bit 7 of Register 7 is set to a logic 1.
high impedance state.  Bit 6 of the Hours Register is de-
Similarly, an alarm is generated every hour when bit 7 of
fined as the 12 or 24 Hour  Select Bit.  When set to logic
Registers 7 and 5 is set to a logic 1.  When bit 7 of Regis-
1, the 12 Hour Format is selected.  In the 12 Hour For-
ters 7, 5, and 3  is set  to a logic 1, an alarm will occur
mat, bit 5 is the AM/PM  bit with logic 1 being PM.  In the
every minute when Register 1 (seconds) rolls from 59 to
24 Hour Mode, bit 5 is the Second 10 Hour bit (20–23
00.
hours).  The Time of Day Registers are updated  every
0.01 seconds from the Real Time Clock, except when
Time of Day Alarm Registers are written and read in the
the TE bit  (bit 7 of Register B) is set low or the clock os-
same format as the Time of Day Registers.  The Time of
cillator is not running. The preferred method of synchro-
Day Alarm Flag and Interrupt is always cleared when
nizing data access to and from the RAMified  Timekeep-
Alarm Registers are read or written.
er is to access the Command Register by doing a write
cycle  to  address  location  0B  and  setting  the  TE  bit
(Transfer Enable bit) to a logic 0.  This will freeze the Ex-
WATCHDOG ALARM REGISTERS
ternal Time of Day Registers at the present recorded
Registers C and D contain the time for the Watchdog
time, allowing access to occur without danger of simul-
Alarm.    The  two  registers  contain  a  time  count  from
taneous update.  When the watch registers have been
00.01 to 99.99 seconds in BCD.  The value written into
read or  written, a second write cycle to location 0B, set-
the Watchdog Alarm Registers can be written or read in
ting the TE bit to a logic 1, will put the Time of Day Regis-
any order.  Any access to Register C or D will cause the
ters back to being updated every .01 second.  No time is
Watchdog Alarm to reinitialize and clears the Watchdog
lost in the Real Time Clock because the internal copy of
Flag Bit and the Watchdog Interrupt Output.  When a
the Time of Day Register buffers is continually increm-
new  value  is  entered  or  the  Watchdog  Registers  are
ented  while the external memory registers are frozen.
read, the Watchdog Timer will start counting down from
An alternate method of reading and writing the Time of
the entered value to zero.  When zero is reached, the
Day Registers is to ignore synchronization.  However,
Watchdog  Interrupt  Output  will  go  to  the  active  state.
any single read may give erroneous data as the Real
The Watchdog Timer Countdown is interrupted and re-
Time Clock may be in the process of updating the exter-
initialized back to the entered value every time either of
nal memory registers as data is being read. The internal
the registers are accessed.  In this manner, controlled
copies of seconds through years are incremented, and
periodic accesses to the Watchdog Timer can prevent
the  Time of Day Alarm is checked during the period that
the Watchdog Alarm from going to an active level.  If ac-
hundreds of seconds reads 99 and are transferred to the
cess does not occur, countdown alarm will be repetitive.
external register when hundredths of seconds roll from
The  Watchdog  Alarm  Registers  always  read  the  en-
99 to 00.  A way of making sure data is valid is to do mul-
tered value.  The actual count- down  register is internal
tiple reads and compare.  Writing the registers can also
and is not readable. Writing registers C and D to zero will
produce erroneous results for the same reasons.  A way
disable the Watchdog Alarm feature.
of making sure that the write cycle has caused proper
041697 4/12

DS1386
DS1386 RAMIFIED  WATCHDOG TIMEKEEPER REGISTERSFigure 2
| ADDRESS | BIT 7 00–99 | BIT 0 | RANGE |
| --- | --- | --- | --- |
| 0 | 0.1 SECONDS | 0.01 SECONDS 1 00–59 |  |
| 0 | 10 SECONDS 00–59 | SECONDS |  |
| 2 | 0 | 10 MINUTES | MINUTES |
| 3 | M | 10 MIN ALARM | MIN ALARM 00–59 10 01–12+A/P 12/24 10 |
| 4 | 0 | HOURS |  |
| A/P | HR | 00–23 CLOCK, CALENDAR, |  |
| TIME OF DAY ALARM | 10 | 10 | 01–12+A/P |
| 5 | M | 12/24 | HR ALARM |
| REGISTERS | A/P | HR | 00–23 |
| 6 | 00000 01–07 | DAYS | 01–07 |
| 7 | M | 0000DAY ALARM 01–31 |  |
| 0 | 0 | 10 DATE | DATE |
8
| 9 | EOSCESQW | 01–12 |
| --- | --- | --- |
| 0 | 10MO | MONTHS |
| A | 10 YEARS | YEARS 00–99 COMMAND IBH B PU |
| REGISTERS | TE | IPSW WAM TDM WAF TDF LO LVL |
| C | 0.1 SECONDS | 0.01 SECONDS 00–99 |
WATCHDOG
ALARM
REGISTERS
D	SECONDS	00–99
10 SECONDS
E
USER
REGISTERS
(1FFF)
7FFF
041697 5/12

DS1386
TIME OF DAY ALARM MASK BITSFigure 3
REGISTER
| (3)MINUTES | (5)HOURS | (7)DAYS |
| --- | --- | --- |
| 1 | 1 | 1 ALARM ONCE PER MINUTE |
| 0 | 1 | 1 ALARM WHEN MINUTES MATCH |
| 0 | 0 ALARM WHEN HOURS AND MINUTES MATCH ALARM WHEN HOURS, MINUTES, | 1 |
000
AND DAYS MATCH
NOTE: ANY OTHER BIT COMBINATIONS OF MASK BIT SETTINGS PRODUCE ILLOGICAL OPERATION.
COMMAND REGISTER vated.  The activated state is determined by bits 1,4,5,
Address location 0Bh is the Command Register where and 6 of the COMMAND REGISTER.  When this bit is
mask bits, control bits and flag bits reside.  The opera- set to a logic 1, the Watchdog interrupt output is deacti-
tion of each bit is as follows: vated.
TE –Bit 7 Transfer enable – This bit when set to a logic 0 TDM –Bit 2 Time of Day Alarm Mask – When this bit is
will disable the transfer of data between internal and ex- set to a logic 0, the Time of Day Alarm Interrupt output
ternal clock registers. The contents in the external clock will be activated.  The activated state is determined by
registers are now frozen and reads or writes will not be bits 0,4,5, and 6 of the COMMAND REGISTER.  When
affected with updates.   This bit must be set to a logic 1 to this bit is set to a logic 1 , the Time of Day Alarm interrupt
allow updates. output is deactivated.
IPSW –Bit 6 Interrupt switch – When set to a logic 1, WAF –Bit 1 Watchdog Alarm Flag – This bit is set to a
INTAis the Time of Day Alarm and INTB/(INTB) is the logic 1 when a watchdog alarm interrupt occurs.  This bit
Watchdog Alarm.  When set to logic 0, this bit reverses is read only.
the output pins. INTAis now the Watchdog Alarm output
and INTB/(INTB) is the Time of Day Alarm output. The bit is reset when any of the Watchdog Alarm regis-
ters are accessed.
IBH/LO  –Bit  5  Interrupt  B  Sink  or  Source  Current  –
When  this  bit  is  set  to  a  logic  1  and  VCCis  applied, When the interrupt is in the pulse mode (see bit 4 defini-
INTB/(INTB) will source current (see DC characteristics tion), this flag will be in the logic 1 state only during the
IOH).  When this bit is set to a logic 0, INTB will sink cur- time the interrupt is active.
rent (see DC characteristics IOL).
TDF –Bit 0 Time of Day Flag – This is a read only bit.
PU/LVL –Bit 4 Interrupt pulse mode or level mode – This bit is set to a logic 1 when a Time of Day alarm has
This bit determines whether both interrupts will output a occurred.  The time the alarm occurred can be deter-
pulse or level signal.  When set to a logic 0, INTAand mined by reading the Time of Day Alarm registers.  This
INTB/(INTB) will be in the level mode.  When this bit is bit is reset to a logic 0 state when any of the Time of Day
set to a logic 1, the pulse mode is selected and INTAwill Alarm registers are accessed.
sink current for a minimum of 3 ms and then release.
INTB/(INTB) will either sink or source current, depend- When the interrupt is in the pulse mode (see bit 4 defini-
ing on the condition of Bit 5, for a minimum of 3 ms and tion), this flag will be in the logic 1 state only during the
then release. time the interrupt is active.
WAM –Bit 3 Watchdog Alarm Mask – When this bit is set
to a logic 0, the Watchdog Interrupt output will be acti-
041697 6/12

DS1386
ABSOLUTE MAXIMUM RATINGS*
Voltage on any Pin Relative to Ground –0.3V to +7.0V
Operating Temperature 0°C to 70°C
Storage Temperature –40°C to +70°C
Soldering Temperature 260°C for 10 seconds (See Note 14)
*  This is a stress rating only and functional operation of the device at these or any other conditions above those
indicated in the operation sections of this specification is not implied.  Exposure to absolute maximum rating
conditions for extended periods of time may affect reliability.
RECOMMENDED DC OPERATING  CONDITIONS (0°C to 70°C)
| PARAMETER | SYMBOL | MIN | TYP | MAX | UNITS | NOTES |
| --- | --- | --- | --- | --- | --- | --- |
| Supply Voltage | VCC | 4.5 | 5.0 | 5.5 | V | 10 |
| Input Logic 1 | VIH | 2.2 | VCC+ 0.3 | V | 10 |  |
| Input Logic 0 | VIL | –0.3 DC ELECTRICAL CHARACTERISTICS (0°C to 70°C; VCC= 5V +10%) | +0.8 | V | 10 |  |
| PARAMETER | SYMBOL | MIN | TYP | MAX | UNITS | NOTES |
| Input Leakage Current | IIL | –1.0 | +1.0 | μA |  |  |
| Output Leakage Current | ILO | –1.0 | +1.0 | μA |  |  |
| I/O Leakage Current | ILIO | –1.0 | +1.0 | μA |  |  |
| Output Current @ 2.4V | IOH | –1.0 | mA |  |  |  |
| Output Current @ 0.4V | IOL | 2.1 | mA | 13 |  |  |
| Standby Current CE= 2.2V | ICCS1 | 3.0 | 7.0 | mA |  |  |
| Standby Current CE= VCC-0.5 | ICCS2 | 2.0 | 4.0 | mA |  |  |
| Active Current | ICC | 85 | mA |  |  |  |
| Write Protection Voltage | VTP | 4.0 | 4.25 CAPACITANCE (tA= 25°C) | 4.5 | V |  |
| PARAMETER | SYMBOL | MIN | TYP | MAX | UNITS | NOTES |
| Input Capacitance | CIN | 7 | 15 | pF |  |  |
| Output Capacitance | COUT | 7 | 15 | pF |  |  |
| Input/Output Capacitance | CI/O 041697 7/12 | 7 | 15 | pF |  |  |

DS1386
AC ELECTRICAL CHARACTERISTICS (0°C to 70°C; VCC= 5.0V +10%)
DS1386XX–120 DS1386XX–150
| PARAMETERPARAMETER | SYMBOLSYMBOL | UNITSUNITS | NOTESNOTES |
| --- | --- | --- | --- |
| MIN | MAX | MIN | MAX |
| Read Cycle Time | tRC | 120 | 150 ns 1 |
| Address Access Time | tACC | 120 | 150 ns |
| CEAccess Time | tCO | 120 | 150 ns |
| OEAccess Time | tOE | 100 | 120 ns |
| OEor CEto Output Active | tCOE | 10 | 10 ns |
| Output High Z from Deselect | tOD | 40 | 50 ns |
| Output Hold from Address | tOH | 10 | 10 ns Change |
| Write Cycle Time | tWC | 120 | 150 ns |
| Write Pulse Width | tWP | 110 | 140 ns 3 |
| Address Setup Time | tAW | 0 | 0 ns |
| Write Recovery Time | tWR | 10 | 15 ns |
| Output High Z from WE | tODW | 40 | 50 ns |
| Output Active from WE | tOEW | 10 | 10 ns |
| Data Setup Time | tDS | 85 | 110 ns 4 |
| Data Hold Time | tDH | 10 | 15 ns 4,5 |
| INTA, INTBPulse Width | tIPW | 3 | 3 ms 11,12 041697 8/12 |

DS1386
READ CYCLE (Note1)
tRC
| VIH | VIH | VIH |
| --- | --- | --- |
| Addresses | V | V V |
| IL | IL tACC tOH | IL |
VIH
tCO V
IH
CE VIL
t tOD
AW
tOE
VIH V
IH
OE VIL
tOD
tCOE	V	V
OH	OUTPUT	OH
DOUT
| VOL | DATA VALID WRITE CYCLE 1 (Notes 2, 6, 7) tWC | VOL |
| --- | --- | --- |
| VIH | VIH | VIH |
| Addresses | V | V |
| VIL | IL tAW CE VIL tWR tWP | IL |
WE
VIH	V	VIH
VIL IL
tODW
High Impedance tOEW
DOUT
tDS tDH
| VIH | Data in | VIH |
| --- | --- | --- |
| DIN | V | V |
| IL | Stable WRITE CYCLE 2 (Notes 2, 8) tWC | IL |
| VIH | V | VIH Addresses IH |
| VIL | V | VIL |
IL
tWR
tWP
tAW
CE V
VIH	VIL	VIL	IH
VIL
VIH
WE
tCOE tODW
DOUT t
DS t
DH
VIH	Data in	VIH
DIN
VIL	Stable	VIL
041697 9/12

DS1386
TIMING DIAGRAM:  INTERRUPT OUTPUTS PULSE MODE (SEE NOTES 11 AND 12)
tIPW
INTA, INTB
INTB
POWER–UP CONDITION
CE
VIH
tREC
4.5V
4.25V
4.0V
VCC
tR
POWER–DOWN CONDITION
CE
VIH
tPF
tF
VCC
4.5V
4.25V
4.0V
VBAT
tFB
041697 10/12

DS1386
AC ELECTRICAL CHARACTERISTICS POWER–UP POWER–DOWN TIMING (0°C to 70°C)
| PARAMETER | SYMBOL | MIN | MAX | UNITS | NOTES |
| --- | --- | --- | --- | --- | --- |
| CEHigh to Power Fail | tPF | 0 | ns |  |  |
| Recovery at Power Up | tREC | 200 | ms |  |  |
| VCCSlew Rate | tF | 300 Power Down 4.0<VCC<4.5V | μs |  |  |
| VCCSlew Rate | tFB Power Down 3.0<VCC<4.25V | 10 | μs |  |  |
| VCCSlew Rate | tR Power Up 4.5V>VCC>4.0V | 0 | μs |  |  |
| Expected Data Retention | tDR | 10 | years WARNING: Under no circumstances are negative undershoots, of any amplitude, allowed when device is in battery backup mode. NOTES: 1.   WEis high for a read cycle. 2.   OE= VIHor VIL. If OE= VIHduring write cycle, the output buffers remain in a high impedance state. 3.   tWPis specified as the logical AND of the CEand WE.  tWPis measured from the latter of CEor WEgoing low to the earlier of CEor WEgoing high. 4.   tDSor tDHare measured from the earlier of CEor WEgoing high. 5.   tDHis measured from WEgoing high.  If CEis used to terminate the write cycle, then tDH= 20 ns for –120 parts and tDH= 25 ns for –150 parts. 6.   If the CElow transition occurs simultaneously with or later than the WElow transition in Write Cycle 1, the output buffers remain in a high impedance state during this period. 7.   If the CEhigh transition occurs prior to or simultaneously with the WEhigh transition, the output buffers remain in a high impedance state during this period. 8.   If WEis low or the WElow transition occurs prior to or simultaneously with the CElow transition, the output buffers remain in a high impedance state during this period. 9.   Each DS1386 is marked with a four digit date code AABB. AA designates the year of manufacture.  BB designates the week of manufacture.  The expected tDRis defined as starting at the date of manufacture. 10. All voltages are referenced to ground. 11. Applies to both interrupt pins when the alarms are set to pulse. 12. Interrupt output occurs within 100 ns on the alarm condition existing. 13. Both INTAand INTB(INTB) are open drain outputs. 14. Real–Time Clock Modules can be successfully processed through conventional wave–soldering techniques as long as temperature exposure to the lithium energy source contained within does not exceed +85°C.  Post solder cleaning with water washing techniques is acceptable, provided that ultrasonic vibration is not used. 041697 11/12 | 9 |  |

DS1386
AC TEST CONDITIONS AC TEST CONDITIONS
| Input Levels: | 0V to 3V | Output Load: 50 pF + 1TTL Gate |
| --- | --- | --- |
| Transition Times: | 5 ns | Input Pulse Levels: 0–3.0V Timing Measurement Reference Levels Input: 1.5V Output: 1.5V Input Pulse Rise and Fall Times: 5 ns. DS1386 32–PIN 740 MIL MODULE PKG 32–PIN |
| DIM | MIN | MAX |
| A   IN. | 1.720 | 1.740 |
| MM | 43.69 | 44.20 |
| B   IN. | 0.720 | 0.740 |
| MM | 18.29 | 18.80 |
1
C   IN.	0.395	0.415
A
| MM | 10.03 | 10.54 |
| --- | --- | --- |
| D   IN. | 0.090 | 0.120 |
| MM | 2.29 | 3.05 |
| E   IN. | 0.017 | 0.030 |
| MM | 0.43 | 0.76 |
| C | F    IN. | 0.120 0.160 |
| MM | 3.05 | 4.06 |
| G   IN. | 0.090 | 0.110 |
F
| MM | 2.29 | 2.79 |
| --- | --- | --- |
| H   IN. | 0.590 | 0.630 |
| D | K | G |
| MM | 14.99 | 16.00 |
| J IN. | 0.008 | 0.012 |
| MM | 0.20 | 0.30 |
| K   IN. | 0.015 | 0.021 |
| MM | 0.38 | 0.53 |
J
E
H
B
041697 12/12
