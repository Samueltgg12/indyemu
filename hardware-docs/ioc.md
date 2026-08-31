# ioc

IOC2 CHIP
Vic Alessi, 93/05/28
| 1.0 | INTRODUCTION | 2 |
| --- | --- | --- |
| 2.0 | GENERAL DESCRIPTION | 3 |
| 2.1 | 85CX30 SERIAL DUART | 3 |
| 2.2 | PI1 PARALLEL INTERFACE | 3 |
| 2.3 | 8042 KEYBOARD/MOUSE CONTROLLER | 3 |
| 2.4 | 8254 PROGRAMMABLE TIMER | 3 |
| 2.5 | INT3 INTERRUPT MULTIPLEXOR | 4 |
| 2.6 | MISCELLANEOUS LOGIC | 5 |
| 2.6.1 | POWER CONTROL | 5 |
| 2.6.2 | VOLUME CONTROL | 7 |
| 2.6.3 | ISDN GLUE | 7 |
| 2.6.4 | OTHER CONTROL | 7 |
| 3.0 | PIN DESCRIPTION | 8 |
| 4.0 | REGISTER DESCRIPTION | 13 |
| 4.1 | SERIAL REGISTERS | 14 |
| 4.2 | PARALLEL REGISTERS | 14 |
| 4.3 | KEYBOARD/MOUSE REGISTERS | 14 |
| 4.4 | TIMER REGISTERS | 14 |
| 4.5 | INT3 REGISTERS | 14 |
| 4.6 | MISCELLANEOUS REGISTERS | 16 |
| 5.0 | AC TIMING | 19 |
| 5.1 | P Bus Timing | 20 |
| 5.2 | Power Control | 21 |
| 6.0 | GUINNESS/FULL HOUSE DIFFERENCES A. VTI 85C30 SPECIFICATION B. PI1 SPECIFICATION C.VTI KEYBOARD CONTROLLER EXCERPT D. VTI 8254 SPECIFICATION E. IOC SCHEMATICS Page 1 of 22 | 22 |

IOC2 CHIP
1.0 INTRODUCTION
The I/O Controller (IOC) Chip is a single ASIC that contains 2 serial ports, a parallel port, a keyboard and mouse
controller, programmable timer, interrupt multiplexor, and some miscellaneous logic. The miscellaneous logic
includes control/status for a number of functions throughout the system, including power control, volume control,
ISDN glue, and other control.
The IOC2 will be used in Guinness, and will hopefully be used in a cost reduced version of Full House. This cost
reduction will require a board spin to replace the current discrete implementation with the IOC, but should be trans-
parent to Software, except for a few minor differences. These Differences will be mentioned in their relevant sections.
The IOC2 will be turn-keyed by VLSI Technology Inc. VTI has existing macrocells for the Zilog Z85C30, Intel 8042
Keyboard/Mouse controller, and Intel 8254 Programmable Interval Timer. The rest of the circuitry will be provided
by SGI, including the Parallel Interface (PI1), and an updated version of the INT2 interrupt multiplexor. VTI will also
be required to add enhancements to the 85C30 to provide ‘85CX30’ functionality. This added functionality is dis-
cussed in further detail in Section 2.1
The IOC2 chip contains 70 inputs, 40 outputs, 35 bidirectionals, 6 JTAG test pins, and 21 power and ground pins for
a total of 172 pins. Power is estimated at 659 mW.
The chip can be broken into six sections:
(1) VTI 85CX30 Serial DUART,
(2) SGI PI1 Parallel Interface
(3) VTI 8042 Keyboard/Mouse Controller
(4) VTI 8254 Programmable Timer
(5) SGI INT3 Interrupt Multiplexor
(6) Miscellaneous Control
The six sections are described in more detail in the next section. This is followed by a section on pin descriptions and
a section describing the register set. The last section covers AC timing parameters. As a final note, an attempt was
made to not duplicate information that already existed in the various macrocell specifications. These specifications
should be attached at the end of this document, and include the following macrocells: VTI 85C30, SGI PI1, VTI
8042, and VTI 8254. Also included in accompanying documentation should be the IOC2 schematics, dated 92/11/16.
PI1	INT3	8254	85CX30
PBUS
VOLUME
8042
&	OTHER	ISDN
POWER
Page 2 of 22

IOC2 CHIP
2.0 GENERAL DESCRIPTION
2.1 85CX30 SERIAL DUART
This macrocell provides the same functionality at the Zilog Z85C30 Enhanced Serial Communication
Controller (ESCC), plus several enhancements. The ESCC is a dual-channel, full-duplex data com-
munications controller capable of supporting several protocols. Each channel is capable of RS232
(ARC) or RS422 (Mac) transmission. Each channel is also capable of supporting MIDI. In addition,
the ‘X’ version contains several enhancements found in the Z85C230. These include:
(1) 4-Byte Deep Transmit FIFO
(2) 8-Byte Deep Receive FIFO
(3) Write Register 7’ (prime)
(4) Modified Databus Timing
(5) RR0 Status Latched During Read
Full House differs from Guinness in that it uses a full blown Zilog 85C230 with some additional fea-
tures. These features include any of the 230 enhancements that relate to SDLC or Synchronous proto-
cols. None of these features should be needed, so Guinness and Full House serial port drivers should
be functionaly equivalent. It is believed that the 85C30 has enough SLDC capability to drive Apple
Talk, since this is the orginal DUART used in the Mac.
See the VTI 85C30 excerpt at the end of this specification for more details.
2.2 PI1 PARALLEL INTERFACE
The parallel interface functionality is derived from the Parallel Interface (PI1) Chip, developed by
Scott Sellers and John Lin of SGI. Is has four modes of operation: standard parallel port (SPP), SGI
parallel port (SGIPP), HP BOISE high speed parallel port (HPBPP), and a Ricoh scanner mode. To
support the different specifications, there are two basic modes of operation: register mode and DMA
mode. In register mode, used primarily for SPP operations, all the control necessary to transfer data is
performed by reads/writes to internal registers. For support of higher transfer rates, DMA mode is
used. DMA mode provides automatic handshaking with the parallel device, reducing software over-
head, and also contains an internal FIFO to reduce CPU intervention. The DMA channel can be
tristated through the DMA_SEL Register, so that this channel may be shared with another device.
More on this in Section 4.6. Functionality between Guinness and Full House are identical.
See the PI1 specification at the end of this document for more information.
2.3 8042 KEYBOARD/MOUSE CONTROLLER
This macro provides the same functionality as an Intel 80C42 controller loaded with a standard PC
BIOS. The mouse and keyboard should be configured for PS/2 mode. Full House uses a discrete
implementation of the Intel 8042 loaded with an Award BIOS. It is unknown at this time how the
Award and VTI BIOS differ.
See the VTI excerpt at the end of this documentation for further details.
2.4 8254 PROGRAMMABLE TIMER
This macro provides the same functionality as an Intel 82C54 Programmable Interval Timer. This
macro contains 3 programmable timers. A divide-by-20 state machine provides a 1MHz clock to
Counter 2 for 1uS timer resolution. It is easy to derive any other source using the three counters.
Counter 2 output clocks the other two counters. The terminal counts of Counter 0 and Counter 1 trig-
ger interrupts to the INT3. This functionality is identical to that of the INT2 timer circuitry. The only
difference between Full House (which uses INT2) and Guinness is that INT3 and the 8254 registers
are located at different addresses.
Page 3 of 22

IOC2 CHIP
See the VTI 82C5 Megacell Specification at the end of this document.
2.5 INT3 INTERRUPT MULTIPLEXOR
The Interrupt Multiplexor macrocell will be supplied by SGI and will be an updated version of the
INT2 chip (hereafter referred to as INT3). INT3 is functionally identical to INT2, with the following
exceptions:
- R3000 reset support has been removed.
- LED (general output) Register has been removed.
- FPU Interrupt support has been removed.
- Register set base address has changed.
- The 8254 system timer is now discussed as a separate entity in Section 2.4.
- There is now a ERROR STATUS register, which allows S/W to identify the source of a Bus Error.
- VME Interrupt inputs were replaced by mappable, polarity-selectable interrupt inputs.
- Vertical Status was removed. The same functionality can be obtained by using a mappable interrupt
and setting the corresponding mask bit low.
- The special latching property of FIFO_FULL_N was removed. Future graphics systems (such as
Newport) should latch this interrupt before sending it to the IOC. Existing graphics (such as Express)
should solve this problem locally. This is also true for VERT_RETRACE_N, which needs some glue
logic in current systems.
- Local1 bits 2 and 0, which were reserved in INT2, are now being used.
INT3 operation is pretty basic. Interrupts throughout the system are input to INT3 where they are
multiplexed out onto 5 different priority level interrupt outputs. INT3 expects to see a latched, level-
triggered interrupt. It does no internal latching, with the exception of the timer interrupts. The 5 inter-
rupt output levels are as follows:
- Level 4, Bus Error
There are 3 bus error interrupts. These interrupts are not maskable. Their status can be read at IOC
address 29\h.
- Level 3, Timer 1
There is a single TIMER1 interrupt that comes from the 8254 Timer. This interrupt is latched by
INT3, and is cleared by writing a ‘1’ to bit 1 of the Timer Clear Reg, or by a system reset. See
attached VTI specification for more information on the Timer.
- Level 2, Timer 0
There is also a single TIMER0 interrupt that comes from the 8254 Timer. This interrupt is latched by
INT3, and is cleared by writing a ‘1’ to bit 0 of the Timer Clear Reg, or by a system reset. See Section
2.4 for more information on the Timer.
- Level 1, Local 1
There are 8 local1 interrupts, including MAP_INT1. Each interrupt is masked by its respective bit in
the Local1 Mask Reg. The interrupts’ status can be read through the Local1 Status Reg. Status can
always be read regardless of the state of the mask bit.
- Level 0, Local 0
There are 8 local0 interrupts, including MAP_INT0. Each interrupt is masked by its respective bit in
the Local0 Mask Reg. The interrupts’ status can be read through the Local0 Status Reg. Status can
always be read regardless of the state of the mask bit.
Page 4 of 22

IOC2 CHIP
In addition, there are also 8 mappable polarity-selectable, interrupts. The polarities for each interrupt
are set through their respective bit in the Map Pol Reg. These interrupts can be masked separately by
two separate registers, Map Mask1 and Map Mask0, to produce MAP_INT1 and MAP_INT0, respec-
tively. MAP_INT1becomes a Local1 interrupt, and MAP_INT0 is a Local0 interrupt. The status of
the mappable interrupts can be read from the Map Status Reg. Note that a ‘1’ is always an active inter-
rupt, regardless of how its polarity is set
Full House uses INT2, so see the beginning of this section for Full House/Guinness differences (note
that the biggest difference is that the location of the INT3/8254 registers has changed).
See Section 4.5 for more details on the INT3 registers.
2.6 MISCELLANEOUS LOGIC
The miscellaneous ‘glue’ logic that remains can be divided into four subsections: power control, vol-
ume control, ISDN glue, and other control. they are discussed in more detail below:
2.6.1 POWER CONTROL
The power control circuitry provides software with the ability of controlling the power sup-
ply, more frequently known as soft power up/down. In this arrangement, the machine will
have a single on/off button that is not connected directly to the supply. Instead, when the but-
ton is pressed, it will signal the IOC to turn the supply on. Below is a detailed explanation of
how the power control functions. Refer to the IOC schematics at the back of this specifica-
tion for a better understanding.
There are 8 important power control signals:
+5V AUX comes from the power supply and is always active as long as the supply is
plugged in.
+5VCC comes from the power supply and is only active when INHIBIT_N is not asserted.
DC_GOOD comes from the power supply and is asserted when +5VCC is above 4.7V. It
should remain below 0.8V when it is not asserted.
PWR_CLR_N clears bit 0 (Power State Bit) of the Panel Register when low. It should be
connected to an RC circuit with a long enough time constant to effectively clear the Power
State Bit when +5V AUX is first active. It has been estimated that 4.7K x 47uF = 220 mS is
sufficient. In addition, a 56K resistor should be connected in parallel to the Cap to ensure a
rapid discharge when +5V AUX is removed.
INHIBIT_N is an input to the supply, and inhibits the +5VCC line of the supply when
asserted.
PWR_INT_N interrupts S/W when power-down has been requested. This interrupt is com-
bined with UP and DOWN interrupts to produce PANEL_INT_N.
SW_PWR_N is asserted when the on/off button is pressed. Pull up through a 4.7K resistor to
+5V AUX.
Page 5 of 22

IOC2 CHIP
RTC_TMR_N is asserted when the RTC watchdog timer is active. It is used to turn the
machine back on after a power failure. Pull up through a 4.7K resistor to +5V AUX.
The system has 3 valid states, based on the power supply outputs:
OFF
In this state, the supply is unplugged or there has been an AC power-failure. All supply out-
puts are at high impedance. All soft power control signals are at high impedance.
AUX
In this state, the supply is plugged in, and the +5V AUX line is active. the main power,
+5VCC is inhibited, so the system remains powered off.
MAIN
In this state, both +5V AUX and +5VCC are active, and the system is now powered up.
There are 4 valid events that can change the state of the power supply. The events are based
on the following state machine:
POWERFAIL
POWERFAIL POWERDOWN
OFF	AUX	MAIN
STANDBY POWERUP
STANDBY occurs when the power supply cord is plugged in or power returns after an AC
power-failure. First, this causes the +5V AUX circuitry to become active. The Power State
Bit (bit 0 of the Panel Reg) should get cleared through PWR_CLR_N, ensuring that
INHIBIT_N will be asserted and the system will remain off. After a given time, the Cap will
charge up and the clear input of the Power State flop will de-assert. DC_GOOD will remain
low since the +5V supply is still off at this point. PWR_INT_N goes to an unknown state. S/
W does nothing during standby.
POWERUP occurs when INHIBIT_N is de-asserted and +5VCC becomes active, powering
up the system. This is caused in one of two ways: the user can press the ON/OFF button, or
the RTC_TMR_N output may be asserted. In either case, the Power State Bit is preset, and
INHIBIT_N is deasserted. If ON/OFF is pressed, PWR_INT_N is also asserted. This inter-
rupt should be masked at power up and cleared during initialization. 20nS after +5VCC
reaches 4.7V, DC_GOOD will get asserted by the power supply. This signal masks out any
floating signals until main power is at a normal level. Any PBUS signals should now be at a
stable level. During this transaction, S/W must do the following: (1) Mask and clear
PWR_INT_N during initialization. This bit is masked by clearing bit 1 of the INT3 Local1
Mask Register. The interrupt can be cleared by writing 0x03 to the Power Control Register.
(2) Activate the RTC watchdog timer. This will assert RTC_TMR_N, which will restart the
Page 6 of 22 machine in the event of a power failure.

IOC2 CHIP
POWERDOWN occurs when several things happen. First, the ON/OFF button is pressed,
which asserts PWR_INT_N. Software now has the opportunity to check to make sure it is
safe to power down. If it is not, power down is aborted by clearing the interrupt and returning
to normal operation. If it is all right to power down, S/W can gracefully shutdown the sys-
tem, and as a last step, assert INHIBIT_N to the power supply. This causes +5VCC to turn
off and DC_GOOD de-asserts. S/W steps for powerdown: (1) deactivate the RTC watchdog
timer. This deasserts RTC_TMR_N. (2) Turn the machine off. This is done by writing 0x20
to the Power Control Register. As a last note, Power-down can also be achieved by a pull-
down menu option.
POWERFAIL occurs whenever the power cord is unplugged or there is an AC power-failure.
The power supply returns to the OFF state, and all signals go to high impedance, except
RTC_TMR_N. This signal retains its state, because it is powered by the RTC battery. S/W
needs to do nothing, since it set the watchdog timer when it first powered on.
Full House and Guinness have the same power control functionality.
2.6.2 VOLUME CONTROL
The volume control circuit takes as input an up and down volume button. It asserts an
UP_INT_N if the ‘UP’ button is pressed, and DOWN_INT_N if the ‘DOWN’ button is
pressed. These interrupts are combined with the PWR_INT_N power interrupt mentioned in
the last section to produce PANEL_INT_N. This interrupt can be masked/read through
INT3. The Panel Register provides the ability to read both the interrupt status and the button
status (whether button is still depressed) via the Volume Register. This register should be
monitored while either button is held, and the volume setting should get updated accord-
ingly.
If both buttons are pressed simultaneously, a muting function occurs. The volume setting
should get stored in non-volatile RAM during power down.
Full House does not have any support for Volume Control.
2.6.3 ISDN GLUE
The IOC2 contains glue for the DMA signals. This glue is necessary because of polarity dif-
ferences and the fact that the Siemans ISDN chip only has a single DMA Acknowledge for
both Trasmit/Receive DMA Requests. These DMA channels can be tristated internally,
through the DMA_SEL Register. See section 4.6 for more details.
2.6.4 OTHER CONTROL
This group contains the left-over input and output control signals for Guinness and Full
House. There is also eight general control lines that can be individually programmed as
inputs or outputs for any unforseen, last minute control. See the register descriptions for
GENERAL CONTROL, GC SELECT, READ, WRITE, RESET, DMA_SEL, and SYS ID in
section 4 for a detailed overview.
Page 7 of 22

IOC2 CHIP
3.0 PIN DESCRIPTION
| Signal | Type | Drive | Pin | P_BUS INTERFACE PINS |
| --- | --- | --- | --- | --- |
| ADDR<5:0> | Input | <5> 141 | P-bus address lines. <4> 142 <3> 143 <2> 144 <1> 145 <0> 146 |  |
| DATA<7:0> | Bidir | 8 mA | <7> 155 | P-bus data lines. <6> 157 <5> 158 <4> 159 <3> 160 <2> 161 <1> 162 <0> 164 |
| RD_N | Input | 152 | P-bus read strobe, active low. |  |
| WR_N | Input | 154 | P-bus write strobe, active low. |  |
| IOC_CS_N | Input | 150 | IOC chip select. |  |
| DRQ_N | Output | 2 mA | 119 | P-bus DMA request from parallel port, active low. |
| DACK_N | Input | 139 | HPC3 P-bus DMA acknowledge to parallel port, active low. |  |
| TC | Input | 140 | P-bus DMA terminal count. |  |
| Signal | Type | Drive | Pin | SERIAL PORT PINS |
| RXDx_N | Input | (1) 104 | Receive Data. There is an input for each UART. (2) 94 |  |
| RTCx_N | Input | (1) 102 | Receive/Transmit Clock input to 85C30. There is an input for each (2) 101 UART. |  |
| TRCx_N | Bidir | (1) 105 | Transmit/Receive Clock input to 85C30. There is an input for each (2) 95 UART. |  |
| CTSx_N | Input | (1) 106 | Clear to Send, active low. There is an input for each UART. (2) 96 |  |
| SYNCx_N | Bidir | (1) 103 | SYNC input to 85C30. . There is an input for each UART. (2) 93 |  |
| DCDx_N | Input | (1) 112 | Data Carrier Detect, active low. There is an input for each UART. (2) 100 |  |
| TXDx | Output | 2 mA | (1) 108 | Transmit Data. There is an output for each UART. (2) 97 |
| DTRx_N | Output | 2 mA | (1) 110 | Data Terminal Ready, active low. There is an output for each UART. (2) 98 |
| RTSx_N | Output | 2 mA | (1) 111 | Request to send, active low. There is an output for each UART. (2) 99 Page 8 of 22 |

IOC2 CHIP
| Signal | Type | Drive | Pin | SERIAL PORT PINS |
| --- | --- | --- | --- | --- |
| PC_MODEx_N | Output | 2 mA | (1) 68 | ARC Mode select, active low. There is an output for each UART. (2) 65 |
| MAC_MODEx_N | Output | 2 mA | (1) 71 | Mac Mode select, active low. RTSx_N must be low for this signal to be (2) 70 active. There is an output for each UART. |
| Signal | Type | Drive | Pin | PARALLEL PORT PINS |
| PD<7:0> | Bidir | 12 mA | <7> 123 | Parallel Port Address/Data Bus. <6> 124 <5> 125 <4> 126 <3> 127 <2> 128 <1> 129 <0> 130 |
| ACK_N | Input | 134 | Used as a data transfer acknowledge, active low. |  |
| BUSY | Bidir | 12 mA | 116 | In SPP, SGIPP, and HPBPP write mode this pin is an output data strobe. In Ricoh this is output when pr/sc is low. |
| PE | Input | 135 | Signals paper end status. In HPBPP mode the peripheral uses this to acknowledge direction. If it is asserted it indicates forward, otherwise reverse is assumed. |  |
| SLCT | Input | 114 | Selects the on/off line status of the printer. |  |
| ERR_N | Bidir | 12 mA | 115 | Active low. Monitors error/fault status of the printer, but in Ricoh mode this is an output pr/sc denoting DMA direction. |
| STB_N | Bidir | 12 mA | 120 | Active low. In SPP, SGIPP, and HPBPP write mode this pin is an output data strobe. In Ricoh this is output when pr/sc is low. |
| AFD_N | Output | 12 mA | 121 | Active low. Signals autofeed. In HPBPP read mode, this indicates host ready for data, and handshakes with ACK_N. In HPBPP write mode, this is driven high. |
| INIT_N | Output | 12 mA | 136 | Active low. Reset output to the printer. In HPBPP mode, this indicates transfer direction (1=write, 0=read). |
| SLIN_N | Output | 12 mA | 137 | Active low. In SPP mode this active low output denotes that data transfer direction is from printer to host. In SGIPP it is an input denoting a no ink status from the printer. This is always de-asserted in HPBPP. |
| ERR_DIR | Output | 2 mA | 117 | Direction control error signal. |
| ADO_EN | Output | 2 mA | 118 | Direction control for PD<7:0>. |
| Signal | Type | Drive | Pin | KEYBOARD/MOUSE PINS |
| KBD_DATA | Bidir | 12 mA | 3 | Keyboard Data, open drain output. |
| KBD_CLK | Bidir | 12 mA | 2 | Keyboard Clock, open drain output. |
| MSE_DATA | Bidir | 12 mA | 4 | Mouse Data, open drain output. |
| MSE_CLK | Bidir | 12 mA | 6 | Mouse Clock, open drain output. Page 9 of 22 |

IOC2 CHIP
| Signal | Type | Drive | Pin | INTERRUPT CONTROLLER PINS |
| --- | --- | --- | --- | --- |
| HPC_BUS_ERROR | Input | 14 | HPC3 bus error. |  |
| MC_BUS_ERROR | Input | 13 | MC bus error. |  |
| EISA_ERROR_N | Input | 15 | EISA error, active low. |  |
| VERT_RETRACE_N | Input | 16 | Vertical Retrace, active low. |  |
| VIDEO_VSYNC_N | Input | 17 | Video Vsync, active low. |  |
| AC_FAIL_N | Input | 18 | AC Fail, active low. |  |
| HPC_DMA_DONE | Input | 19 | HPC DMA done. |  |
| LOCAL1_N<2> | Input | 30 | General purpose interrupt, reserved in INT2. |  |
| LOCAL1_N<0> | Input | 31 | General purpose interrupt, reserved in INT2. |  |
| GRX_INT_N | Input | 27 | Graphics interrupt, active low. |  |
| MC_DMA_DONE | Input | 20 | MC DMA done. |  |
| ENET_INT | Input | 22 | Ethernet interrupt. |  |
| SCSI1_INT | Input | 24 | SCSI channel 1 interrupt. |  |
| SCSI0_INT | Input | 25 | SCSI channel 0 interrupt. |  |
| FIFO_FULL_N | Input | 26 | FIFO full interrupt, active low. |  |
| MAP_INT_N<7:6,3:0> | Input | <7> 28 | Mappable interrupts for general use. Polarity selectable, default is active <6> 29 low. <3> 32 <2> 33 <1> 34 <0> 35 |  |
| CPU_INT_N<4:0> | Output | 4 mA | <4> 8 | CPU interrupt outputs. <3> 9 <2> 10 <1> 11 <0> 12 |
| Signal | Type | Drive | Pin | POWER/VOLUME CONTROL PINS |
| SW_PWR_N | Input | 165 | On/Off Power Button, active low. |  |
| SW_UP_N | Input | 37 | Up Button input, active low. |  |
| SW_DOWN_N | Input | 38 | Down Button input, active low. |  |
| RTC_TMR_N | Input | 166 | RTC Watchdog Timer, active low. Used to turn the machine back on after a power failure. Active low. |  |
| DC_GOOD | Input | 167 | Power supply signal indicating that the system has power. |  |
| +5V AUX | Input | 170 | Auxiliary +5V from the power supply, continuously on as long as supply is plugged in. |  |
| PWR_CLR_N | Input | 168 | When AUX supply goes away, the Power State Register is cleared through an external RC circuit connected to this line. Active low. Page 10 of 22 |  |

IOC2 CHIP
| Signal | Type | Drive | Pin | POWER/VOLUME CONTROL PINS |
| --- | --- | --- | --- | --- |
| INHIBIT_N | Output | 12 mA | 169 | Controls the state of the power supply. A low inhibits the supply, high turns the supply on. |
| Signal | Type | Drive | Pin | ISDN GLUE PINS |
| ISDN_DACKTx_N | Input | (A) 39 | Transmit DMA acknowledge from HPC3, active low. There is an input (B) 47 for each ISDN B channel. |  |
| ISDN_DACKRx_N | Input | (A) 40 | Receive DMA acknowledge from HPC3, active low. There is an input (B) 48 for each ISDN B channel. |  |
| ISDN_DRQTx | Input | (A) 42 | Transmit DMA request from Siemans HSCX. There is an input for each (B) 50 ISDN B channel. |  |
| ISDN_DRQRx | Input | (A) 45 | Receive DMA request from Siemans HSCX. There is an input for each (B) 52 ISDN B channel. |  |
| ISDN_DACKx_N | Output | 4 mA | (A) 41 | Transmit/Receive DMA acknowledge to Siemans HSCX, active low. (B) 49 There is an input for each ISDN B channel. |
| ISDN_DRQTx_N | Output | 4 mA | (A) 43 | Transmit DMA request to HPC3, active low. There is an input for each (B) 51 ISDN B channel. |
| ISDN_DRQRx_N | Output | 4 mA | (A) 46 | Receive DMA request to HPC3, active low. There is an input for each (B) 53 ISDN B channel. |
| ISDN_RST | Output | 4 mA | 56 | ISDN reset, settable through the Reset Register. |
| Signal | Type | Drive | Pin | MISCELLANEOUS PINS |
| SYS_ID<4:0> | Input | <4> 72 | System ID bits, used to read board revision and system type. <3> 73 <2> 74 <1> 75 <0> 76 |  |
| ENET_LI_N | Input | 77 | Ethernet link indicator, active low. Indicates a TP link. |  |
| ENET_PSTAT | Input | 78 | Ethernet power status. A high indicates normal +12V power. |  |
| SCSI1_PSTAT | Input | 79 | SCSI1 power status. A high indicates normal +5V power. |  |
| SCSI0_PSTAT | Input | 80 | SCSI0 power status. A high indicates normal +5V power. |  |
| LED<2:1> | Output | 12 mA | <2> 54 | Sets the LED color. Low is orange, high is green. <1> 55 |
| EISA_RST_N | Output | 4 mA | 57 | Resets EISA for Full House, active low. |
| DC_MARGIN_HI | Output | 12 mA | 58 | Set high to step voltage from +5V to +5.5V. |
| DC_MARGIN_LO | Output | 12 mA | 59 | Set high to step voltage from +5V down to +4.5V. |
| ENET_AUTOSEL | Output | 2 mA | 60 | Ethernet auto select. Set low for manual, high for auto-select via TP LI. |
| ENET_PORTSEL | Output | 2 mA | 62 | Ethernet port select. Set low for TP, high for AUI. |
| ENET_UTP | Output | 2 mA | 63 | Ethernet UTP select. Set high for 100 ohm unshielded TP, low for 150 ohm shielded TP. Page 11 of 22 |

IOC2 CHIP
| Signal | Type | Drive | Pin | MISCELLANEOUS PINS |
| --- | --- | --- | --- | --- |
| ENET_NTH | Output | 2 mA | 64 | Ethernet NTH select. Set high for normal TP squelch threshold, set low to reduce by 4.5dB. |
| CLK_20MHz | Input | 148 | 20 MHz system clock. |  |
| CLK_SER | Input | 91 | 85CX30 Clock Input, selected through an internal mux. This clock should only be used if 85C30 data loss problem exists. |  |
| RST_N | Input | 81 | Chip reset, active low. |  |
| GEN_CNTL<7:0> | Bidir | 4mA | <7> 82 | General Control lines, programmable as either inputs or outputs. <6> 83 <5> 84 <4> 83 <3> 86 <2> 87 <1> 89 <0> 90 |
| Signal | Type | Drive | TEST PINS |  |
| ENTEI | Input | 138 |  |  |
| JTRST_N | Input | 173 | JTAG Reset |  |
| JTDI | Input | 1 | JTAG Data In |  |
| JTMS | Input | 171 | JTAG Master Select |  |
| JTCK | Input | 172 | JTAG Clock |  |
| JTDO | Output | 4 mA | 174 | JTAG Data Out Page 12 of 22 |

IOC2 CHIP
4.0 REGISTER DESCRIPTION
| 0x1FBD9800 | Parallel Port Data Register | 0x1FBD9880 | INT3 Local0 Status Register |
| --- | --- | --- | --- |
| 0x1FBD9804 | Parallel Port Control Register | 0x1FBD9884 | INT3 Local0 Mask Register |
| 0x1FBD9808 | Parallel Port Status Register | 0x1FBD9888 | INT3 Local1 Status Register |
| 0x1FBD980C | Parallel Port DMA Control Register | 0x1FBD988C | INT3 Local1 Mask Register |
| 0x1FBD9810 | Parallel Port Interrupt Status Register | 0x1FBD9890 | INT3 Map Status Register |
| 0x1FBD9814 | Parallel Port Interrupt Mask Register | 0x1FBD9894 | INT3 Map Mask0 Register |
| 0x1FBD9818 | Parallel Port Timer 1 Register | 0x1FBD9898 | INT3 Map Mask1 Register |
| 0x1FBD981C | Parallel Port Timer 2 Register | 0x1FBD989C | INT3 Map Pol Register |
| 0x1FBD9820 | Parallel Port Timer 3 Register | 0x1FBD98A0 | INT3 Timer Clear Register |
| 0x1FBD9824 | Parallel Port Timer 4 Register | 0x1FBD98A4 | INT3 Error Status Register |
| 0x1FBD9828 | Not Used | 0x1FBD98A8 | Not Used |
| 0x1FBD982C | Not Used | 0x1FBD98AC | Not Used |
| 0x1FBD9830 | Serial Port1 Command Transfer | 0x1FBD98B0 | Timer Counter 0 Register |
| 0x1FBD9834 | Serial Port1 Data Transfer | 0x1FBD98B4 | Timer Counter 1 Register |
| 0x1FBD9838 | Serial Port2 Command Transfer | 0x1FBD98B8 | Timer Counter 2 Register |
| 0x1FBD983C | Serial Port2 Data Transfer | 0x1FBD98BC | Timer Control Word Register |
| 0x1FBD9840 | Keyboard/Mouse Registers | 0x1FBD98C0 | Reserved |
| 0x1FBD9844 | Keyboard/Mouse Registers | 0x1FBD98C4 | “ |
| 0x1FBD9848 | GC Select Register | 0x1FBD98C8 | “ |
| 0x1FBD984C | General Control Register | 0x1FBD98CC | “ |
| 0x1FBD9850 | Panel Register | 0x1FBD98D0 | “ |
| 0x1FBD9854 | Not Used | 0x1FBD98D4 | “ |
| 0x1FBD9858 | System ID Register | 0x1FBD98D8 | “ |
| 0x1FBD985C | Not Used | 0x1FBD98DC | “ |
| 0x1FBD9860 | Read Register | 0x1FBD98E0 | “ |
| 0x1FBD9864 | Not Used | 0x1FBD98E4 | “ |
| 0x1FBD9868 | DMA Select Register | 0x1FBD98E8 | “ |
| 0x1FBD986C | Not Used | 0x1FBD98EC | “ |
| 0x1FBD9870 | Reset Register | 0x1FBD98F0 | “ |
| 0x1FBD9874 | Not Used | 0x1FBD98F4 | “ |
| 0x1FBD9878 | Write Register | 0x1FBD98F8 | “ |
| 0x1FBD987C | Not Used | 0x1FBD98FC Page 13 of 22 | “ |

IOC2 CHIP
The IOC2 registers are selected through IOC_CS_N. There are 64 internal registers, which start at the base address of
0x1fbd9800 (PBUS_CS_N<6> only. If a different chip select is used, refer to the HPC3 Specification for the appro-
priate starting address). The following is a more detailed description of each register.
4.1 SERIAL REGISTERS, addresses 0x1FBD9830-0x1FBD983C
The 85CX30 DUART uses an indirect method of addressing, and requires two operations to read or
write a register. The first operation sets the index of the desired register. The second operation actually
reads/writes the desired register. In addition, the desired channel and transfer type must be selected
through two address lines. Address bit 1 selects the channel in which the read or write operation
occurs. A high selects channel 2 and a low selects channel 1. Address bit 0 defines the type of infor-
mation transferred. A high means data is being transferred and a low indicates a command. See the
VTI 85C30 Specification for further information on the register set.
4.2 PARALLEL REGISTERS, addresses 0x1FBD9800-0x1FBD982C
The Parallel Port Macro is identical to the Parallel Interface Chip designed internally by Scott Sellers
and John Lin of Silicon Graphics. Section 3 of their specification defines the register set in detail.
4.3 KEYBOARD/MOUSE REGISTERS, addresses 0x1FBD9840-0x1FBD9844
The Keyboard and Mouse Controller is identical to a hard-coded Intel 82C42. The operation of this
part, including the individual register descriptions, can be found in the VTI Keyboard Controller
excerpt at the end of this specification.
4.4 TIMER REGISTERS, addresses 0x1FBD98B0-0x1FBD98BC
The Timer Macro is a standard Intel 8254 Programmable Interval Timer. The VTI 8254 specification
is included at the end, and contains information on the timer registers.
4.5 INT3 REGISTERS, addresses 0x1FBD9880-0x1FBD98AC
| Bit | Oper | LOCAL0 STATUS REGISTER, address 0x1FBD9880 |
| --- | --- | --- |
| 7 | R | Mappable Interrupt 0 Status. (masked by MAP MASK0). A high indicates an active interrupt (not affected by LOCAL0 MASK setting). |
| 6 | R | Graphics Interrupt Status. A high indicates an active interrupt (not affected by LOCAL0 MASK setting). |
| 5 | R | Parallel Port Interrupt Status. A high indicates an active interrupt (not affected by LOCAL0 MASK setting). |
| 4 | R | MC DMA Done Status. A high indicates an active interrupt (not affected by LOCAL0 MASK setting). |
| 3 | R | Ethernet Interrupt Status. A high indicates an active interrupt (not affected by LOCAL0 MASK setting). |
| 2 | R | SCSI Channel 1 Interrupt Status. A high indicates an active interrupt (not affected by LOCAL0 MASK setting). |
| 1 | R | SCSI Channel 0 Interrupt Status. A high indicates an active interrupt (not affected by LOCAL0 MASK setting). |
| 0 | R | FIFO Full Interrupt Status. A high indicates an active interrupt (not affected by LOCAL0 MASK setting). |
| Bit | Oper | LOCAL0 MASK REGISTER, address 0x1FBD9884 |
| 7:0 | RW | Mappable Interrupt 0 Mask. A low masks the interrupt, which is the default after reset. |
| 6 | RW | Graphics Interrupt Mask. A low masks the interrupt, which is the default after reset. |
| 5 | RW | Parallel Port Interrupt Mask.A low masks the interrupt, which is the default after reset. |
| 4 | RW | MC DMA Done Mask. A low masks the interrupt, which is the default after reset. |
| 3 | RW | Ethernet Interrupt Mask. A low masks the interrupt, which is the default after reset. Page 14 of 22 |

IOC2 CHIP
| Bit | Oper | LOCAL0 MASK REGISTER, address 0x1FBD9884 |
| --- | --- | --- |
| 2 | RW | SCSI Channel 1 Interrupt Mask. A low masks the interrupt, which is the default after reset. |
| 1 | RW | SCSI Channel 0 Interrupt Mask. A low masks the interrupt, which is the default after reset. |
| 0 | RW | FIFO Full Interrupt Mask. A low masks the interrupt, which is the default after reset. |
| Bit | Oper | LOCAL1 STATUS REGISTER, address 0x1FBD9888 |
| 7 | R | Vertical Retrace Status. A high indicates an active interrupt (not affected by LOCAL1 MASK setting). |
| 6 | R | Video Vsync Interrupt Status. A high indicates an active interrupt (not affected by LOCAL1 MASK setting). |
| 5 | R | AC Fail Interrupt Status. A high indicates an active interrupt (not affected by LOCAL1 MASK setting). |
| 4 | R | HPC DMA Done Status. A high indicates an active interrupt (not affected by LOCAL1 MASK setting). |
| 3 | R | Mappable Interrupt 1 Status (masked by MAP MASK1). A high indicates an active interrupt (not affected by LOCAL1 MASK setting). |
| 2 | R | General Purpose LOCAL1_N<2> Interrupt, active low. This interrupt was unused in INT2. |
| 1 | R | Panel Interrupt Status. This interrupt asserts when either PWR_INT_N, UP_INT_N, or DOWN_INT_N activates. A high indicates an active interrupt (not affected by LOCAL1 MASK setting). |
| 0 | R | General Purpose LOCAL1_N<0> Interrupt, active low. This interrupt was unused in INT2. |
| Bit | Oper | LOCAL1 MASK REGISTER, address 0x1FBD988C |
| 7 | RW | Vertical Retrace Mask. A low masks the interrupt, which is the default after reset. |
| 6 | RW | Video Vsync Interrupt Mask. A low masks the interrupt, which is the default after reset. |
| 5 | RW | AC Fail Interrupt Mask. A low masks the interrupt, which is the default after reset. |
| 4 | RW | HPC DMA Done Mask. A low masks the interrupt, which is the default after reset. |
| 3 | RW | Mappable Interrupt 1 Mask. A low masks the interrupt, which is the default after reset. |
| 2 | RW | General Purpose LOCAL1_N<2> Interrupt Mask. A low masks the interrupt, which is the default after reset. |
| 1 | RW | Panel Interrupt Mask. A low masks the interrupt, which is the default after reset. |
| 0 | RW | General Purpose LOCAL1_N<0> Interrupt Mask. A low masks the interrupt, which is the default after reset. |
| Bit | Oper | MAP STATUS REGISTER, address 0x1FBD9890 |
| 7:6 | R | Mappable Interrupt<7:6> Status. A high bit indicates that the respective interrupt is active. The status not affected by either of the MAP MASK registers, or the polarity setting in the MAP POL register. |
| 5 | R | Serial DUART Interrupt Status. A high indicates an active interrupt (not affected by LOCAL1 MASK setting). |
| 4 | R | Keyboard/Mouse Interrupt Status. A high indicates an active interrupt (not affected by LOCAL1 MASK |
| 3:0 | R | Mappable Interrupt<3:0> Status. A high bit indicates that the respective interrupt is active. The status not affected by either of the MAP MASK registers, or the polarity setting in the MAP POL register. Page 15 of 22 |

IOC2 CHIP
| Bit | Oper | MAP MASK0 REGISTER, address 0x1FBD9894 |
| --- | --- | --- |
| 7:0 | RW | Mappable Interrupt<7:0> Mask 0. This mask arbitrates which mappable interrupts cause Mappable Interrupt 0 to activate. A low bit masks the respective interrupt, which is the default after reset. Note that bit <5> is reserved for the Serial DUART, and bit <4> is reserved for the Keyboard/Mouse Controller. |
| Bit | Oper | MAP MASK1 REGISTER, address 0x1FBD9898 |
| 7:0 | RW | Mappable Interrupt<7:0> Mask 1. This mask arbitrates which mappable interrupts cause Mappable Interrupt1 to activate. A low bit masks the respective interrupt, which is the default after reset.Note that bit <5> is reserved for the Serial DUART, and bit <4> is reserved for the Keyboard/Mouse Controller. |
| Bit | Oper | MAP POL REGISTER, address 0x1FBD989C |
| 7:0 | RW | Mappable Polarity Select<7:0>. A high bit selects ‘active high’ polarity on the respective Mappable Interrupt<7:0> input, a low bit select ‘active low’ polarity, which is the default.Note that bit <5> is reserved for the Serial DUART, and bit <4> is reserved for the Keyboard/Mouse Controller. Since these are both active low interrupts, their polarity bits should always be set low. |
| Bit | Oper | TIMER CLEAR REGISTER, address 0x1FBD98A0 7:2 Not Used |
| 1 | W | Timer1 Clear. Writing a ‘1’ to this location resets the Timer1 Interrupt. |
| 0 | W | Timer0 Clear. Writing a ‘1’ to this location resets the Timer0 Interrupt. |
| Bit | Oper | ERROR STAT REGISTER, address 0x1FBD98A4 7:3 Not Used |
| 2 | R | HPC Bus Error Status. A high indicates an active interrupt. |
| 1 | R | MC Bus Error Status. A high indicates an active interrupt. |
| 0 | R | EISA Error Status. A high indicates an active interrupt. 4.6 MISCELLANEOUS REGISTERS, addresses 0x1FBD9848-0x1FBD987C |
| Bit | Oper | GENERAL CONTROL SELECT REGISTER, address 0x1FBD9848 |
| 7:0 | RW | Configures GEN_CNTL<7:0> as either input, if respective bit is low, or an output, if the bit is high. |
| Bit | Oper | GENERAL CONTROL REGISTER, address 0x1FBD984C |
| 7:0 | RW | Control Bits<7:0>, can be configured as either an input or output by setting the respective bit of the GC Select Reg. |
| Bit | Oper | FRONT PANEL REGISTER, address 0x1FBD9850 |
| 7 | R | Volume Up Hold Status. This bit is low when the ‘UP’ button is being depressed. Page 16 of 22 |

IOC2 CHIP
| Bit | Oper | FRONT PANEL REGISTER, address 0x1FBD9850 |
| --- | --- | --- |
| 6 | RW | Volume Up Interrupt Status. This interrupt gets latched when the ‘UP’ button has been pressed, and is active low. Write a ‘1’ to this bit to clear the interrupt. |
| 5 | R | Volume Down Hold Status. This bit is low when the ‘DOWN’ button is being depressed. |
| 4 | RW | Volume Down Interrupt Status. This interrupt gets latched when the ‘DOWN’ button has been pressed, and is active low. Write a ‘1’ to this bit to clear the interrupt. 3:2 Not Used |
| 1 | R/W | Power Interrupt Status. The interrupt is asserted and latched when the power button is pressed The Interrupt is active low. Write a ‘1’ to this bit to clear the interrupt. |
| 0 | R/W | Power State (active low). When low, the supply is off. When high, the supply is on. |
| Bit | Oper | SYSTEM ID REGISTER, address 0x1FBD9858 |
| 7:5 | R | Chip Revision. 00\h means a discrete implementation of the IOC. |
| 4:1 | R | Board Revision. |
| 0 | R | System Type.’0’ is Sapphire,’1’ is Full House. |
| Bit | Oper | READ REGISTER, address 0x1FBD9860 |
| 7 | R | Ethernet Link Indicator (active low). A low bit indicates a TP link, a high indicates no link, default to AUI. |
| 6 | R | Ethernet Power Status. A low indicates no power (open PTC), high indicates +12V power. |
| 5 | R | SCSI1 Power Status. A low indicates no power (open PTC), high indicates +5V power. (Full House only) |
| 4 | R | SCSI0 Power Status. A low indicates no power (open PTC), high indicates +5V power. |
| 3:0 | R | Not Used., |
| Bit | Oper | DMA_SEL Register, address 0x1FBD9868 7:6 Not Used. |
| 5:4 | RW | Serial Port Clock Select. 00\h selects a 10MHz internal clock (default), 01\h selects a 6.67MHz internal clock, and 02\h or 03\h selects the external clock input. 3 Not Used. |
| 2 | RW | Parallel Port DMA Select. A high bit selects the Parallel Port DMA channel. 0\h is the default after reset. |
| 1 | RW | ISDN Channel B DMA Select. A high bit selects the Parallel Port DMA channel. 0\h is the default after reset |
| 0 | RW | ISDN Channel B DMA Select. A high bit selects the Parallel Port DMA channel. 0\h is the default after reset |
| Bit | Oper | RESET REGISTER, address 0x1FBD9870 7:6 Not Used. |
| 5:4 | RW | LED bits, cleared after reset. 3 ISDN Reset. Set low to reset ISDN, high for normal operation. Cleared after reset. (Guinness only) Page 17 of 22 |

IOC2 CHIP
| Bit | Oper | RESET REGISTER, address 0x1FBD9870 |
| --- | --- | --- |
| 2 | RW | EISA Reset. Set low to reset EISA, high for normal operation. Cleared after reset. (Full House only). |
| 1 | RW | Keyboard/Mouse Reset. Set low to reset Keyboard/Mouse Controller, high for normal operation. Cleared after reset. |
| 0 | RW | Parallel Port Reset. Set low to reset the Parallel Port, high for normal operation. Cleared after reset. |
| Bit | Oper | WRITE REGISTER, address 0x1FBD9878 |
| 7 | RW | Margin High. Set low for normal +5V operation, high to step supply up to +5.5V. Cleared at reset. |
| 6 | RW | Margin Low. Set low for normal +5V operation, high to step supply down to +4.5V. Cleared at reset. |
| 5 | RW | UART1 PC Mode. Set low to configure Port1 for RS422 Mac mode, high to select RS232 PC mode. Cleared at reset. |
| 4 | RW | UART2 PC Mode. Set low to configure Port 2 for RS422 Mac mode, high to select RS232 PC mode. Cleared at reset. |
| 3 | RW | Ethernet Auto Select (active high). Set low for manual mode, high to have LXT901 automatically select TP or AUI based on link integrity. Cleared at reset. |
| 2 | RW | Ethernet Port Select. Set low for TP, high for AUI. This setting is only used when Auto Select is in manual mode. Cleared at reset. |
| 1 | RW | Ethernet UTP/STP select. Set low to select 150 ohm termination for shielded TP (default), set high to select 100 ohm termination for unshielded TP. Cleared at reset. |
| 0 | RW | Ethernet Normal Threshold (NTH) select. Set low to select the normal TP squelch threshold (default), high to reduce the threshold by 4.5 dB (set low when reset). Page 18 of 22 |

IOC2 CHIP
5.0 AC TIMING
5.1 P Bus Timing
The Pbus timing was based around the V85CX30, since it had the most stringent requirements. By
meeting the 85CX30 timing requirements, the timing requirements are met for all other macros.
TsA(wr) > 35ns, currently 56ns
ThA(wr) > 0ns
TsA(rd) > 50ns, currently 56ns
ThA(rd) > 0ns
Tl(rd) > 125ns, currently 180ns
Tl(wr) > 180ns, currently 180ns
TsD(wr) > 22ns, currently 32ns
ThD(wr) > 0ns
Based on the above data and the diagram on the following page, P2 should be 2 cycles, or 60ns. P3
should be 180ns or 6 cycles. P4 should be 30ns, or 1 cycle. P1, which is the time between chip selects,
should be greater than 500ns. All of these times are based on a 33MHz GIO bus speed.
Below are some important delays internal to IOC2:
Thd from P_DATA after RD_N : 4.5ns
Tpd from RD_N to P_DATA : 53.5ns
Tpd from RD_N to internal read stobes : 5.88ns
Tpd from IOC_CS_N to internal chip selects : 10.5ns
Tpd from P_ADDR to internal address lines : 5.8ns
Tpd from IOC_CS to 85CX30 chip select : min 22ns, max 95ns
Tsu from P_DATA to WR_N : min 21ns, max 98ns
(note: the above delays are needed to meet the 85CX30 timing requirements.
See the VTI C8530 and the Zilog Z85230 specifications for more detail.)
5.2 Power Control
The power control functionality was described in section 2.6.1. The accompanying timing diagram
follows.
Page 19 of 22

P1
VALID ADDRESS
P4
VALID
P3
VALID DATA
P2
VALID ADDRESS
P1
CS_N
ADDR	RDn/WRn wrDATA	rdDATA

AUX
POWERDOWN Z
0x02
S/W CLEARS TIMER
ON/OFF PRESSED
WRITES TO POWER CONTROL REGISTER
MAIN
0x03
POWERUP S/W CLEARS INT
S/W SETS TIMER
STANDBYAUX X
Z
ON/OFFPRESSED
Z	Z	Z	Z	Z
OFF
+5V AUX
+5VCC DC_GOODPWR_CLR_NINHIBIT_NPWR_INT_NSW_PWR_NRTC_TMR_NPWR_WR_N

GUINNESS/FULL HOUSE DIFFERENCES
Guinness uses an IOC2 ASIC that replaces several components used in Full House. These include the
INT2, Z85230, Intel 8242, PI1, and some miscellaneous registers.
* The serial port inside IOC2 is now a VTI 85CX30 instead of a Zilog Z85230. It is missing any of
the SDLC/Synchronous enhancements added to the 230. Since these are not used, it should be trans-
parent to S/W.
* The Keyboard/mouse controller inside IOC2 is now a VTI 8042 instead of an Intel 8242 with Award
BIOS. It is unkown whether this will require any S/W changes.
IOC2 has General Control Registers located at 0x1FBD9848 and 0x!FBD984C. These control some
programmable control lines and should both get initialized to 0xFF.
* The IOC2 has General Control Registers located at 0x1FBD9848 and 0x!FBD984C. These control
some programmable control lines and should both get initialized to 0xFF.
* The Panel Register is called Power Control by Full House. Only the lowest 2 bits are used. Guinness
uses the upper for bits for volume control.
* The System ID Register at 0x1FBD9858 reads 001 for IOC bits 7:5 and 0 for bit 0 (Guinness).
* The IOC2 contains the DMA Select Register located at 0x1FBD9800 with should get initialized to
0x00 after reset. Bit 2 of this register must get set high to enable parallel port DMA channel. Bits 1
and 0 must get high before ISDN DMA is performed.
* Some register names changed: Read Register in IOC2 is the same as Read1 in Full House, Reset
Register is Write1, and Write Register is Write2. Functionalilty is the same.
* Full House has an Aux Register at 0x1FBD9900 which does not exist in Guinness.
* Since the interrupt controller (INT3) is now located inside IOC2, the base address will change from
0x1FBD9000 to 0x1FBD9880. There are 2 new registers in INT3 that did not exist in INT2. These are
the Map Pol Register and the Error Status Register. The Map Pol Register’s location on the address
map matches the LED Register in INT2, which gets used by Full House, so any writes to this register
should be removed for Guinness. The Map Pol Register should contain a value of 0xFF after initial-
ization. This configures all general purpose control lines at outputs. The Error Status Register is read
only and allows S/W to determine the source of a bus error.
Other differences include:
* Guinness only has 2 banks of memory. Full House has 3.
* Guinness has non-pipelined option slots, Full House has pipelined.
* Guinness has no EISA capability.
* Guinness has only 1 SCSI port, Full House has 2.
* Guinness has built-in ISDN. Registers are located at 0x1FBD9000-0x1FBD97BB. Since no S/W
has been written for ISDN, these registers should not get written to.
* Guinness has built-in video located in the EISA address space. For exact addresses, see a VINO
designer.
* Guinness has Flash located at 0x1FE00000 through 0x1FFFFFFF
* Full House uses a serial EEPROM for HPC3 configuration.
Page 22 of 22
