# am33c93a-scanned

.
I
Advanced
Am33C93A
Micro
EnhancedSCSI-BusInterfaceController Devices
DISTINCTIVECHARACTERISTICS
WimplementsfullSCSIbusteatures:arbitration, WIncludes48-mAdriversfordirectconnectiontothe
disconnect,reconnect,paritygeneration/checking SCS!bus
onbothdataports,softreset,andsynchronous 24bittransfercounter
datatransfers Programmabletimeoutforselectionandreselection
BSynchronousoffsetselectablefrom1to12bytes, “Combination”commandsgreatlyreduceinterrupt-
withselectabletransferperiodupto5Mbytes/s handlingresponsibilities
WCompatiblewithmostmicroprocessorsthroughan WSpecial“TranslateAddress”commandperformsthe
8-bitdatabus;supportsbothmultiplexedandnon-
Logical-to-Physicaladdresstranslation
multiplexedaddress/databussystems.Hostbus
|Single+5Vsupply
dataparitycheckingandgenerationisanoptional
WAvailablein44-pinchipcarrieror40-pinDIP
feature
BLowpowerCMOSdesign
WCanbeusedasahostadapter(SCSIInitiator)or
peripheraladapter(SCSITarget)
WDatatransferoptionsincludeprogrammed/O,
single-byteDMA,burst(multibyte)DMA,ordirect
busaccess(DBABus)transfers
GENERALDESCRIPTION
TheAm33C93AisaMOS/VLSIdeviceimplementedin “TransferInfo”commandandsupplyingSCSIcom-
AdvancedMicroDevices'CMOSprocess.Itoperates mandbytestotheAm33C93A.TheAm33C93Atrans-
fromasingle5-Voltsupplyandisavailableineithera ferstheSCSIcommandtotheperipheral,andthen
44-pinchipcarrierora40-pindual-in-linepackage.All waitsforthenextbusphaserequest.Thisprocess
inputsandoutputsareTTLcompatible. continuesuntilallSCSIinformationincludingdata,
status,andmessageshavebeentransferred.
TheAm33C93Aisintendedforuseinsystemswhich
interfacetotheSmallComputerSystemInterface TheAm33C93Aalsooffershigh-levelSelect-and-
(SCSI)Bus.TheAm33C93Acanoperateinboththe Transfercommandswhicheliminatetheinterrupthan-
initiator(typically,ahostcomputersystem)andthe dlingotherwiserequiredbetweeneachSCSIbus
target(typically,aperipheraldevice)SCSIbusroles. phase.
Whenusedinthehostsystem,theAm33C93Ainter- WhentheAm33C93Aisusedinaperipheralsystem,
facestoboththehostbusandtheSCSIbus.Toperform theAm33C93AwilloperateprimarilyinaTargetrole.It
aSCSIoperation,thehostprocessorissuesacom- interfaceswithalocalprocessorandtheSCSIbusin
mandtotheAm33C93AtoselectthedesiredTarget. thisenvironmentjustasitdoeswhenusedasahost
TheAm33C93AthenarbitratesfortheSCSIbusand adapter.TheTarget-rolecommandsetenablesthe
selectstheperipheralunit.Ifitfailstogetthebus AmM33C93AtorequesteachSCSIbusphaseindividu-
becauseofadevicewithhigherpriority,itcontinues allyortosequencetheSCSIbusphasesautomatically
tryingandnotifiesthehostwhenithassucceededby throughtheuseofcombinationcommands.
generatinganinterrupt.Atthispoint,theAm33C93Ais
TheAM33C93Ahasaninternalmicrocontrolier,aregis-
operatingintheinitiatorrole.Whentheperipheralre-
tertaskfile,andSCSIinterfacelogic.Thisarchitecture
questsaSCSIcommandfromthehost,theAm33C93A
supportsbotbtightcontroloftheprotocolfornon-
receivestherequestandgeneratesanotherinterruptto
standardSCS!implementations,aswellasahands-
thehost.Thehostrespondstothisinterruptbyissuinga
freemodeforstandardSCS|applications.
Publication#11853	Aov.B	Amandment
ssuoDate:November1991

aAMD
BLOCKDIAGRAM
scsi
Internal
Bus
Bus
scsl Register
File [[ADDR|,\oae
ArbitrationPLA	andStack	Catrl.
HostInterface [+C8
scs
DataBuffers
ParityGen/Checker ParityGen/Checker
RE,WE,D7-D0,DP
SCSIREQ/ACK
HController
HandshakeLogic
[¢——DRQ
DataBuffer/
TransferCounter
12ByteFIFO
[¢———————»DACK
ROM
Program
Controller 11853.003A
Am33C93A

AMDa
CONNECTIONDIAGRAMS
44-PINCHIPCARRIER
>	Q9	-Q	X|z
3 4
Eg3Eies8lBlEEE
OO anmr]r
6 5 4 3 2 1 4443424140
SEL[]7	°	30[]GND
cik)8 38f]507
bRa]9 37[]sbe
DACK[]10 36[(HALT)
op]11 35[7)sDs
INTRQ[]12 34[7]spa
Do[]13 a3[]sp3
D1[}14 327sp2
p2[}1s 31[]GND
b3[]16 30[7]sD1
D4[]17 207500
\_1819202122232425262728J
|ONR
2QRogORI Y
8 3
838<65|o|g|cza-“%
o 118538001
Note:Pinsinparenthesesarefortestpurposesonly,andshouldbeleftunconnectedfornormalchipoperation.
40-PINDIP
0]1e 4o0[]vce
MSG(]2 39[]REQ
GND(|3 38[]AcK
[y 37[]ATN
BSYs 36[]MR
SEL[]6 35[]GND
cik 7 34[]sD7
| bRa\|8 | 337 | SD6 |
| --- | --- | --- |
| DAcK(]9 | 32\| | SD5 |
| INTRQ[]10 | 31[] | SD4 |
| oo] | 30\| | sD3 |
| b1[]12 | 29 | \|<]o |
| D2[]13 | 28] | GND |
| D3[}14 | 27[] | D1@g |
| Da[]1s | 26\| Ds[]16 SDP | SDo |
| D6(]17 | 247 D7(]18 ®ZO3 (HE 2ROOoOoOoOo000000ETd9\|al 118538.002 Am33C93A 15 | ALE |

nAMD
ORDERINGINFORMATION
StandardProducts
AMDstandardproductsareavailableinseveralpackagesandoperatingranges.Theordernumber(Valid
combination)
sformedbyacombinationof:
AM33C93A -20
TopmionaLPROCESSING
Blank=Standardprocessing
TEMPERATURERANGE
C=Commerciat{0to+70°C)
PACKAGETYPE
P=40-PinPlasticDIP(PD040)
J=44-PinPlasticLeadedChipCarrier
{PL044)
'SPEEDOPTION
DEVICENUMBER/DESCRIPTION
Am33C93A
ValidCombinations
ValidCombinations
ValidCombinationslistconfigurationsplannedtobesupportedinvolumeforthis
AM33C93A-16 device.ConsultthelocalAMDsalesofficetoconfirmavailabiltyofspecificvalid
Jc,PC combinations,tocheckonnewlyreleasedcombinations.
AM33C93A-20
1-6 Am33C93A

AMDu
PINDESCRIPTIONS
Processor/DMAInterface
| Name | Vo | Function CLK 820MHzsquarewaveclock. MR Resetisanactive-lowinputwhichforcestheAm33C93Aintoanidlestate.AlSCSsignalsare forcedtothenegatedstate. |
| --- | --- | --- |
| INTRQ | o | InterruptRequesttoexternalmicroprocessorindicatesacommandcompletion/terminationora needtoservicetheSCSinterface.ReadingtheSCSISTATUSregisterclearsthisbit. o ReadEnableisanactive-lowinputwhichisusedwithTStoreadaregisterorwithDACKtoaccess theDATAregisterinDMAmode.InDBABusmode,itisusedasanoutputtoreaddatafroma sectorbuffer.(TRI-STATE) o WriteEnableisanactive-lowinputwhichisusedwithStowritearegisterorwithDACKtoaccess theDATAregisterinDMAmode.InDBABusmode,Itisusedasanoutputtowritedatatoasector buffer.(TRI-STATE) ChipSefectisanactive-lowinputwhichqualifiesREandWEwhenaccessingaregister.Thissig- nalmustbeinactiveduringaDMAcycle(DACKactiveinDMAandBurstDMAmode,orDRQ activeinDBABusmode). Ao AddresspinA0isusedoaccessthinternalregistersfornon-multiplexedaddress/databusses (i.e.theALEpinisgrounded).TheaddressofthedesiredregisterisloadedintotheADDRESS registerduringawritecyclewithA0=0.TheselectedregisteristhenaccessedwhenAO=1. ALE AddressLatchEnableisusedformultiplexedaddress/databussestoloadtheaddressofthe desiredAM33C93Aragisterfromthedatabus.Hfindirectaddressingistobeused,theALEpin shouldbegrounded.SeethedescriptionoftheADDRESSregisterforacompletediscussionof directandindirectaddressing. o DMAacknowledgeinputusedforinterfacingtoanexternalDMAcontraller(e.g.8237).When DACKislow,allbustransfersaretofromtheDATAregisterregardiessofthecontentsofthe (RCS) ADDRESSregister.InDBABusmode,thispinfunctionsasaRAMchipselectoutputtoallowthe Am33CA3A10accessasectorbuffer.REandWEareoutputswhenRCS(RAMChipSelect)is active.Sincethispincanbeanopendrainoutput,apullupresistormayberequiredwhen operatinginDBABusmode. 1) DatarequestisanoutputwheninterfacingtoanexternalDMAcontroller,andaninputwhenin DBABusmode.WhenusedwithanexternalDMAcontroller,DRQandDACKformthehandshake (DRQ) forthedata-bytetransfers.InBurstmode,DRQremainslowaslongasthereisdatatotransfer.In DBABusmode,theAm33C93A performsbursttransterswhileDRQishigh,andwhenDRQislow, datatransfersareinhibited,RCSisfalse,andtheREandWEoutputsaredisabled.Sincethispin canbeanopendrainoutput,apullupresistormayberequiredwhenoperatinginOMAorBurst mode. |
| D7-DO | ] | Processordatabus. |
| DP | ] | DataParity,usedonlyforcheckingigeneratingparityduringdatatransfers. SCSilInterface |
| Name | Vo | Function |
| ATN | vo | ATNisanoutputintheinitiatorroleandaninputinthetargetrole.Itisusedtoindicatethe ATTENTIONcondition. |
| ACK | Vo | ACKisanoutputintheinitiatorrofeandaninputinthetargetrole.Itisusedtoindicatean acknowledgementforaREQ/ACKdatatransferhandshake. |
| MSG | [e] | MSGisaninputintheinitiatorroleandanoutputinthetargetrole.Itisassertedduringa MESSAGEphase. |
| [} | o | T/Disaninputintheinitiatorroleandanoutputinthetargetrole.Itisusedtoindicatewhether CONTROLorDATAinformationisontheSCSIdatabus. |
| REQ | vo | REQisaninputintheinitiatorroleandanoutputinthetargetrole.ItindicatesarequestforaREQ/ ACKdatatransfer. Am33C93A 17 |

aAMD
SCSIInterface(Cont.)
| Name | Vo | Function |
| --- | --- | --- |
| ) | 1o | TOisaninputintheinitiatorroleandanoutputinthetarget role.Itcontrolsthedirectionofdata movementontheSCS\|databuswithrespecttoanInitiator. |
| SDo-SD7 | WO | SCSIdatabus. |
| S | o | SCSIdatabuspartysignal. |
| BSY | 1o | BSYisassertedwhentheAm33C93Aisattemptingtoarbitrate fortheSCSIbusorwhen connectedasaTarget. |
| SEL | o | BELisassertedwhentheAm33C93Aisattemptingtoselectorreselectanother SCSIdevice. Note:Allpinshaveopen-drainoutputdrivers. Am33C93AREGISTERS RegisterMap Address |
| Ao | AW | RegisterAccessed (HEX) |
| 4 | R | AUXILIARYSTATUSREGISTER XX |
| o | w | ADDRESSREGISTER XX |
| 1 | RW | OWNIDREGISTER /CDBSIZE 00 |
| 1 | RW | CONTROLREGISTER 01 |
| 1 | RW | TIMEOUTPERIODREGISTER 02 |
| 1 | RW | TOTALSECTORSREGISTER /CDB18T 03 |
| 1 | RW | TOTALHEADSREGISTER /CDB2ND 04 |
| 1 | RW | TOTALCYLINDERSREGISTER(MSB) /CDB3RD 05 |
| 1 | RW | TOTALCYLINDERSREGISTER(LSB) /CDB4TH 06 |
| 1 | RIW | LOGICALADDRESS(MSB) /CDB5TH o7 |
| 1 | RW | LOGICALADDRESS(2ND) /CDB6TH 08 |
| 1 | RW | LOGICALADDRESS(3RD) /CDB7TH 09 |
| 1 | RW | LOGICALADDRESS(LSB) /CDB8TH oA |
| 1 | RW | SECTORNUMBERREGISTER /CDB9TH o8 |
| 1 | RW | HEADNUMBERREGISTER /CDB10TH oc |
| 1 | RW | CYLINDERNUMBER(MSB)REGISTER /CDB11TH [ |
| 1 | RW | CYLINDERNUMBER(LSB)REGISTER /CDB12TH OE |
| 1 | RW | TARGETLUNREGISTER oF |
| 1 | RW | COMMANDPHASEREGISTER 10 |
| 1 | RW | SYNCHRONOUSTRANSFERREGISTER 1" |
| 1 | RW | TRANSFERCOUNTREGISTER(MSB) 12 |
| 1 | RW | TRANSFERCOUNTREGISTER(2NDBYTE) 13 |
| 1 | RW | TRANSFERCOUNTREGISTER(LSB) 14 |
| 1 | RW | DESTINATIONIDREGISTER 15 |
| 1 | RW | SOURCEIDREGISTER 16 |
| 1 | R | SCSISTATUS 17 |
| 1 | RW | COMMANDREGISTER 18 |
| 1 | RW | DATAREGISTER 19 |
| 1 | R | AUXILIARYSTATUS(DIRECTADDRESSINGMODE) 1F Notes: 1.Allunusedbitsofadefinedregisterarereservedandmustbezero. .Readinganundefinedorunavailableregisterresultsinanall-onesdatabusoutput. [N.RegisteraddressesaredeterminedbytheADDRESSregisterbitsAR7throughARO. N. Whenusingamultiplexedaddress/databuswithALE,theA0pinisignoredandtheADDRESSregisterisloaded withALE.Inthismode,theAUXILIARYSTATUSregisterismappedathex1F. 5.SeePage14foradescriptionofhowresetaffectstheinternalregisters. 18 Am33C93A |

AMDn
RegisterDescriptions
AUXILIARYSTATUSREGISTER
(AddressHex1F)
TheAUXILIARYSTATUSregisterisaread-onlyregister STATUSregistermaybeaccessedatanytime,except
whichcontainsgeneralstatusinformationnotdirectly duringDMAaccesses(DACKasserted
inDMA/Burst
associatedwiththeinterruptcondition.TheAUXILIARY modeorDRQassertedinDBAbusmode).
’ o
[INTJLoi[esycie]oT o[Pe[pBR]
DATABUFFERREADY
L——PARITYERROR
t————————NotUsed
NotUsed
COMMANDINPROGRESSBUSY
LASTCOMMAND
IGNORED
INTERRUPTPENDING
11852.004A
| Bit | Name | Description |
| --- | --- | --- |
| 0 | DBR | DATABUFFERREADYisusedduringprogrammedI/0toindicatetotheprocessorwhether ornottheDATAregisterisavailableforreadingorwriting.DuringSendorTransfer commandswhichtransmitdataovertheSCSIbus,theDBRbitissetwhentheAm33C93A isreadytotakeabytefromthehost;thebitisresetwhentheprocessorwritesthebytetothe DATAregister.DuringReceiveorTransfercommandswhichreceivedataovertheSCSI bus,theDBRissetwhenabyteisreceived;itisresetwhentheprocessorreadsthebyte fromtheDATAregister. PARITYERRORstatusindicatesthatevenparitywasdetectedonadatabytereceived duringaninformationtransfer.Parityischeckedondatareceivedfromthehostbusduring transfersouttotheSCSIbusandischeckedondatareceivedfromtheSCSIbusduring transfersouttothehostbus.DetectionofaparityerrorwillsetthePEstatusbitregardiessof thestateoftheHHPorHSPbitsintheCONTROLregister.ThePEbitisclearedwhenanew commandisissued |
| 4 | ciP | COMMANDINPROGRESS,whenset,indicatesthattheAmM33C93Aisinterpretingthelast commandenteredintotheCOMMANDregisterandthereforethisregisterisunavailable. Whenthisbitisreset,acommandmaybewrittentotheCOMMANDregister. |
| 5 | BSY | BUSYindicatesthataLevelIlcommandiscurrentlyexecutingandthereforeonlythe COMMANDregister(whenCIP=0),theDATAregister,andtheAUXILIARYSTATUS registerareaccessiblebythehost.ALevelIlcommandmaynotbewrittentothe COMMANDregisterwhenthisbitisone. |
| 6 | Lct | LASTCOMMANDIGNOREDindicatesthatacommandwasissuedbythehostjustpriorto orconcurrentwithapendinginterrupt,andthereforethecommandwillbeignored. |
| 7 | INT | INTERRUPTPENDINGindicatesthattheINTRQpinisasserted.Thehostshouldreadthe SCSISTATUSregistertoclearINTRQpriortoissuinganycommands. Am33C93A 19 |

aAMD
ADDRESSREGISTER OWNID/CDBSIZEREGISTER
(AddressXXHex) (Address00Hex)
TheADDRESSregisterisawrite-onlyregisterwhich TheOWNID/CDBSIZEregister,initsfirstmode,con-
containstheaddressoftheregistertobeaccessed. tainsboththeencodedIDoftheAm33C93Aonthe
RegistersintheAm33C93Amaybeaccessedinoneof SCSIbusandseveralcontrolbitsthatareusedto
twoways: initiallyconfigurethedeviceduringthe“Reset”
command.Thesebitscontrot‘advancedfeature’
-Directaddressing(multiplexedaddress/databus- selection,hostbusparityenable,andselectionofthe
ses).Indirectaddressing,thefallingedgeofthe divisorfortheinputclock.Initssecondmode(when
ALEsignalisusedtolatchtheaddressintothe advancedfeaturesareenabled,seep.16),thisregister
ADDRESSregister.TheA0pinshouldbecon- isusedduringthecombinationcommandstospecify
nectedtogroundwhenusingthismethod.TheALE theSCSICDBsizeifthecommandgroupisunknownto
istypicallythenfollowedbytheTSandWEorRE theAm33C93A.
signalsthataccesstheselectedregister.Also,in
directaddressing,theAUXILIARYSTATUSregis- inthefirstmode,thisregister(asdefinedbelow)is
terislocatedataddress1Fhex. sampledandbecomeseffectiveonlyaftera“Reset”
commandisissuedtothedevice.Thisregistermustbe
Indirectaddressing(separateaddress/dalabus-
initialized,anda“Reset”commandmustthenbeis-
ses).Inindirectaddressing,theregisteraccessis
sued,followingahardwareresettosettheSCSIbusID,
performedintwoseparatecycles.Thismethodis theclockdivisor,andtheoperatingmodesbeforeany
enabledbyattachingALEtoground.First,the othercommandsareissued.
ADDRESSregisterisloadedbyperformingawrite
ofthedesiredaddresstotheAm33C93A(WEand Inthesecondmode,bits3-0ofthisregisterareused
TSasserted)withA0=0.Thentheregisterisac- duringtheSelect-and-TransferandWait-for-Select
cessedbyassertingCSandWEorRE,withA0=1. commandstospecifytheSCSICommandDescriptor
Also,followingeveryaccesswithAO=1,theAD- Blocksizeifitisnotagroup0,group1,orgroup5
DRESSregisterwillautomaticallyincrementto command.Thismodeisenabledonlywhenadvanced
pointatthenextregister,withtheexceptionofthe featuresareenabled(seep.16).
followinglocations:AUXILIARYSTATUSregister,
DATAregister,andtheCOMMANDregister.In
indirectaddressing,theAUXILIARYSTATUS
registerisaccessedbyperformingaread(CSand
REasserted)withA0=0.
OwnID/CDBSizeRegister
7 [
[Fsi]Fso]o[enp[EAF[1D2D1[Do|
1Dbit0
IDbit1
IDbit2
EnableAdvancedFeatures
EnableHostParity
NotUsed
FREQUENCYSELECT¢
FREQUENCYSELECT1 118530054
| Bit | Name | Description |
| --- | --- | --- |
| 0-2 | Dn | SCSIDBits0-2settheSCSIbus1DnumberthattheAm33C93Awilluseduringarbitration andselection. EAF ENABLEADVANCEDFEATURE!S,whensettoone,causestheAm33C93Atoenable certainadvancedfeatures(seePage16).Whenthisbitiszero,thosefeaturesaredisabled. EHP ENABLEHOSTPARITY,whensetttoone,enablesoddparitycheckingonthehostbus;the PEbitintheAUXILIARYSTATU!Sregisterwillindicateparityerrorsdetectedonthehost bus,andtheHHPbitintheCONTROLregisterwillbeused.Whenthisbitiszero,no checkingisperformedonthehostbus;thePEbitisnotsetwhenaparityerrorisdetectedon thehostbus,andtheHHPbitmustbesettozero.NOTE:Parityisalwaysgeneratedonthe hostdataparitybit(DP),regardlessofthestateofthisbit. 1-10 Am33C83A |

AMDn
| Bit | Name | Description |
| --- | --- | --- |
| 67 | FSn | FREQUENCYSELECT0-1selectthedivisorthatisappliedtotheinputclock.Theresulting clockisusedfordatatransfertimingandforSCSIbusarbitrationtiming.Thetablebelow showsinputclockfrequencyrangesandthecorrespondingdivisors.Thecorrectdivisorfor theinputclockmustbeused,orSCStbustimingspecificationsmaynotbemet. |
INPUTCLOCK
FREQUENCY RESULTING
| (MH2) | Fst | FS0 | DIVISOR |
| --- | --- | --- | --- |
| 8-10 | 0 | o | 2 |
| 12-15 | 0 | 1 | 3 |
| 16-20 | 1 | o | 4 |
| XX | 1 | 1 | Undefined Notethatan11MHZclockrateshouldnotbeused,asthe resuttingSCS!buscleardelaymayviolateSCS!specifications. TheformulaforcomputingthemaximumSCSdatatransferrate is: InputClockFequency MaximumSCS\|TransferRate= [Mbyte/sec] ClockDivisior |
CONTROLREGISTER
(Address01Hex)
TheCONTROLregisterisusedtoenable/disablecertainfunctions,suchasresponsetoparityerrorsandtheSCSI
attentioncondition,interrupthandling,anddatatransfermodes.
7 o
[Dm2]om1[oMo[HHP]EDI|IDI|HA[HSP]
HALTonSCSIPARITYERROR
HALTonATTENTION
INTERMEDIATEDISCONNECTINT
ENDINGDISCONNECTINTERRUPT
HALTonHOSTPARITYERROR
DMAModeSelectbit0
DMAModeSelectbit1
DMAModeSelectbit2 11853-006A
Description
Bt Name
| 0 | HSP | TheHALTonSCSIPARITYERRORbitenablestheAm33C93Atoimmediatelyterminatea ReceiveorTransfercommandifaparityerrorisdetectedonanincoming SCS\|databyte.In theInitiatorrole,terminationduetoaSCSIparityerrorcausestheACK pintobeleftinthe activestateinordertoinhibitanyadditionaldatatransfers(REQs)bytheTarget;this facilitateserrorhandlingwiththeTarget.Synchronousdatatransferscheckparityevery 4096byles,orattheendoftheremainingtransfercount,whicheverisless.Asynchronous transferscheckparityoneverybyte. |
| --- | --- | --- |
| 1 | HA | TheHALTonATTENTIONbit(inTg%lmodeonly)enablestheAm33C93Atoterminatea SendorReceivecommandiftheATN inputisasserted.Thisnormallyindicatesthatthe InitiatordetectedaparityerrorwhilereceivingdatafromtheAm33C93A.TheATNinputis testedbeforethestartofadatatransfer,every4096bytesifthetransfercountisgreaterthan 4096,andaftertheendofthetransfer.Theserulesapplytobothsynchronousand asynchronoustransfers. |
| 2 | DI | TheINTERMEDIATEDISCONNECTINTERRUPTbit,whenset,enablestheAm33C93Ato generatean85HinterruptandcompleteaSelect-and-TransfercommandiftheTarget disconnectsaccordingtothedefinedSCSIprotocol.Whenthisbitisreset,nointerruptis generatedbyavaliddisconnect.Thisfeature,whenusedwiththeResumeSelect-and- Transfercommand,providessupportforoverlappedSCS!operations.1Dlisalsousedto selectexecutionoptionsinTargetmodeCombinationcommandsthatservetoreducehost systemoverhead.(RefertoCOMMANDS,p.15formoredetails.) |
| 3 | Am33C33A | 111 |

Bit_Name Description
| 3 | EDI | WhentheENDINGDISCONNECTINTERRUPTbitisset,the 16Hinterruptwhichnormally followstheCOMMANDCOMPLETEmessageduringtheexecutionofaSelect-and-Transfer commandwillbesuppresseduntiltheTargetdisconnectsfromtheSCSIbus. EDIisalso usedintheTargetmodeCombinationcommandstoenablechainingbetween those commands,resultinginreducedhostsystemoverhead.RefertoCOMMANDS p.15formore details. |
| --- | --- | --- |
| 4 | HHP | TheHALTonHOSTPARITYERRORbitenablestheAmM33C93A toimmediatelyterminate aSendorTranstercommandifaparityerrorisdetectedonanincominghostdata byte.Host parityerrorsarecheckedaccordingtotherulesforcheckingSCS!parityerrors. However,a haltonahostparityerrorwillnotholdtheACKsignalassertedwhenanerror occurs.Host paritycheckingisperformedatthesameintervalsasSCSIparitychecking. |
| 57 | DMx | DMAMODESELECTbits2-0areusedtoselecttheDMA modeofoperation,which describesthehostbustransfermodeusedduringDataInorDataOutphases. Thefollowing tabledescribesthedifferentDMAmodes,andthestateofthesebitsto selectthem: |
| DM2 | DM1 | DMO DMAModeSelected |
| 0 | 0 | 0 POLLEDMODE,ornoDMAenabled.Alldataphase transfersare performedbypoliingforDBRintheAUXILIARYSTATUSregister,and thenwriting(reading)thedatato(from)theDATAregister. |
| o | 0 | 1 BURSTMODEselectsademand-modeDMAinterface. Inthismode, theDRQsignalwillbeactiveaslongasthereisdata/spaceinthe internalFIFOtoallow_thetransfertocontinue.TheDMAcontrolier respondsbyassertingDACKandRE/WEaslongasDRQisactive. |
| 0 | 1 | 0 DBABUSMODEisselectedwhentheAm33C93Aisconnected toa DBABus.ThismodealsocanbecalledDirectBufferAccess(DBA) mode.Inthismode,theAm33C93Aactsasabusmaster,andalldata accesssignalsreversetheirdirection:TheDRQoutputsignalbecomes theDRQinput,whichenablestheAm33C93Atodrivethebufferbus controlsignals.TheDACKoutputsignalbecomestheRCSinput,which isassertedasachipselectforthebuffer.TheREandWEinputsbecome outputswhichdrivethereadandwritefunctionsoftheRAMbutfer.As longastheDRQsignalisasserted,transferswillcontinueinaburst manner,untilthetransferiscompleteoritdecidestopausethetransfer bynegatingtheDRQsignal;onemoretransfermayoccurafterthis transition,andthentheDACK,RE,andWEsignalsarenegated. |
| 1 | 0 | 0 DMAMODEisselectedwhentheAm33C93AisobeusedwithaDMA controllerinsingle-bytetransfermode.Inthismode,DRQisasserted andthen negated,andtheDMAcontrollerrespondsbyasserting andWEorRE,foreachdatabytetransferredtoffromtheAm33C93A. TIMEOUTPERIODREGISTER Theconstant‘80scalestheunitsofthe equation,asis (Address02Hex) basedontheintemnaltimeoutcycle time.Theuser TheTIMEOUTPERIODregisterisan8-bitregister shouldroundtheresulting‘registervalue’uptothenext containingapresetvaluewhichdeterminesthetimeout integralvaluetoensurethattheuser’sminimumtimeout periodforSelectandReselectcommands.Thisvalue requirementismet. maybecalculatedasafunctionoftheinputclockfre- ThetimeoutperiodspecifieshowlongtheAm33C93A quencyandthedesiredtimeoutperiod,asshowninthe willwaitforaresponse(indicatedbyassertionofthe followingequation: BSY.§g_al)afterithasbeguntheselectionphase(as- |
| Tper-Ficlk | sert | SELandnegateBSY)beforeterminatingthecom- istervalue= mand.Thetimeoutfunctioncanbedisabledbyloading theTIMEOUTPERIQDregisterwithzero. Where: NOTE:Thefollowingtwelveregistersareusedexclusivelyby Tper=Thedesiredtimeoutperiodinmilliseconds; theTransiateAddressand/or“combination”com- Fickk=TheinputclockfrequencyattheCLKpinin mands.Thefunctionofeachregisterisdeterminedby MHz(withnodivisorapplied). thetypeofcommandissued. 112 Am33C93A |

AMDn
TOTALSECTORSREGISTER/CDB1STBYTE resultingsectornumberfollowingaTranslateAddress
(Address03Hex) command.
TranslateAddress:TheTOTALSECTORSregister
Select-and-Transfer:Thisregistershouldbefoaded
shouldbesettothetotalnumberofsectorspertrack
withtheninthbyteofatenortwelvebyteCDBbefore
priortoissuingaTranslateAddresscommand.
issuingaSelect-and-Transfercommand.
Select-and-Transfer:Thisregistershouldbeloaded
Wait-for-Select-and-Receive:TheAm33C93Awillstore
withthefirstbyteoftheCOMMANDDESCRIPTOR
theninthbyteofatenortwelvebytereceivedCDBin
BLOCKbeforeissuingaSelect-and-Transfercom-
thisregister.
mand.
Wait-for-Select-and-Receive:TheAm33C93Awillstore HEADNUMBERREGISTER/CDB10THBYTE
thefirstbyteofthereceivedCDBinthisregister. (Address0CHex)
TranslateAddress:TheHEADNUMBERregistercon-
TOTALHEADSREGISTER/CDB2NDBYTE tainstheresultingheadnumberfollowingaTranslate
(Address04Hex) Addresscommand.Ifautomaticcompensationfor
TranslateAddress:Thisregisterholdsthetotalnumber sparesectorsonadiskistobeperformedbythe
ofheadsduringaTranslateAddresscommand. AmM33C93A,thenthenumberofsparesectorspercylin-
dermustbewrittenintothisregisterbeforeissuingthe
Select-and-Transfer:Thisregistershouldbeloaded TranslateAddresscommand.Itshouldbenotedthat
withthesecondbyteoftheCDBbeforeissuinga whencompensationisused,themaximumnumberof
Select-and-Transfercommand.
cylindersallowedis4096,andthemaximumnumberof
headsis15.Aninitialvalueofzerointhisregister
Wait-for-Select-and-Receive:TheAm33C93Awillstore
indicatesthatnocompensationistobeperformed.
thesecondbyteofthereceivedCDBinthisregister.
Select-and-Transfer:Thisregistershouldbeloaded
TOTALCYLINDERSREGISTER/CDB3RDAND4TH withthetenthbyteofatenortwelvebyteCDBbefore
BYTES issuingaSelect-and-Transfercommand.
(Address05,06Hex)
Wait-for-Select-and-Receive:TheAm33C93Awillstore
TranslateAddress:Thisisa16-bitregisterwhichholds
thetenthbyteofatenortwelvebytereceivedCDBin
thetotalnumberofcylinders.
thisregister.
Select-and-Transfer:Thisregistershouldbeloaded
withthethirdandfourthbytesoftheCDBbeforeissuing
CYLINDERNUMBERREGISTER/CDB11THAND
aSelect-and-Transfercommand.
12THBYTES
(Address0D,OEHex)
Wait-for-Select-and-Receive:TheAm33C93Awillstore
TranslateAddress:TheCYLINDERNUMBERregister
thethirdandfourthbytesofthereceivedCDBinthis
isa16-bitregisterwhichcontainstheresultingcylinder
register.
numberfollowingexecutionoftheTranslateAddress
command.WhenaTranslateAddresscommand involv-
LOGICALADDRESSREGISTER/CDB5TH-8TH
ingautomaticcompensationforsparesectorsisissued
BYTES
(i.e.theHEADNUMBERregisterinitiallycontainsa
(Address06,07,08,09,OAHex)
nonzerovalue),thenthisregistermustbeloadedwith
TranslateAddress:TheLOGICALADDRESSregister
totalnumberofsectorspercylinder(totalsectorsftrack
isa32-bitregisterwhichshouldbeloadedwiththe
totalheads—totalsparesectors/cyl)beforeissuingthe
logicaladdresstobefranslatedpriortoissuingthe
command.
TranslateAddresscommand.
Select-and-Transfer:Thisregistershouldbeloaded
Select-and-Transfer:ForsixbyteCDBs,onlythefirst
withtheeleventhandtwelfthbytesofatwelvebyteCDB.
twobytesofthisregisterareloadedwiththefifthand
beforeissuingaSelect-and-Transfercommand.
sixthbytesoftheCDB.FortenandtwelvebyteCDBs,
thisregisterisloadedwiththefifth,sixth,seventh,and Wait-for-Select-and-Receive:TheAm33C93Awillstore
eighthbytesoftheCDB. theeleventhandtwelfthbytesofatwelvebytereceived
CDBinthisregister.
Wait-for-Select-and-Receive:TheAm33C93Awillstore
thefifth,sixth,seventh(ifany),andeighth(ifany)bytes Send-Status-and-Command-Complete:TheCDB11
ofthereceivedCDBinthisregister. registerisusedtospecifythereturnedstatusbytetobe
sentduringaSend-Status-and-Command-Complete
SECTORNUMBERREGISTER/CDB9THBYTE command.TheCDB12registerisusedtodeterminethe
(Address0BHex) typeofCommand-Completemessagesentbythe
TransiateAddress:Thisregisterwillcontainthe Am33C93A.Ifbit0oftheCDB12registerissettoone,
Am33C93A 1-13

aAMD
7 o0
thenalinkedCommandCompletemessagewillbesent
o[cpe[cpPs[cra]cpa]cPz]crPt]cPo
duringcommandexecution.Inthiscase,bit1ofthe
CDB12registerisusedasaFLAGbittodetermine
whethera0Ahex(FLAG=0)ora0Bhex(FLAG=1)
CommandPhasebit0
LinkedCommandCompletemessageissent.Ifbit0is CommandPhasebit1
zero,thenasimpleCommandCompletemessage(00 CommandPhasebit2
CommandPhasebit3
hex)issent.
CommandPhasebit4
CommandPhasebit§
CommandPhasebit6
TARGETLUNREGISTER
NotUsed
(AddressOFHex)
11853008
TheTARGETLUNregisterisusedtoholdboththe
LogicalUnitNumber(LUN)andTargetstatusinforma-
multi-phasecommandshavebeencompleted.Thus,if
tionduringvariousAm33C93Acommandsand
thecommandhasterminatedabnormally,theproces-
sequences.DuringaSelect-and-TransferorReselect-
sorcanreadthisregistertodeterminethecauseofthe
and-Transfercommand,thecontentsofthisregister
terminationandhowtorespondtoit.Thisregisteris
(alongwiththeSOURCEIDregister)areusedto
alsousedtoresumecombinationcommandsbyloading
generateandchecktheIDENTIFYmessagestrans-
thisregisterwithavaluethatindicatesthenextdesired
ferredacrosstheSCSIbus.Inaddition,theTARGET
orexpectedbusphase,andreissuingthecommand.
LUNregisterisusedtoholdtheTargetStatusbyte
Refertothedescriptionofthespecificcommandsfor
receivedduringaSelect-and-Transfercommand.
detailsregardingthevariouscommandphasesand
resumevalues.
DuringWait-for-Select-and-Receivecommands,this
registermayholdtheimageoftheIdentifymessage
receivedfromtheInitiator.IftheTLVbitiszero,there SYNCHRONOUSTRANSFERREGISTER
(Address11Hex)
wasnoIdentifymessagereceived.IftheTLVbitisone,
TheSYNCHRONOUSTRANSFERregisterisusedto
thenavalidIdentifymessagewasreceived.TheDOK
bitwillthenindicatewhetherofnottheInitiatorhas selectbetweensynchronousandasynchronoustrans-
enableddisconnects. fers,andisalsousedtodefinethemaximumtransfer
rate.Forinformationphasesotherthana“data”transfer
DuringReselect-and-Transfercommands,thisregister phase,orwhentheselectedoffsetiszero
isused1osettheLUNtobeusedintheIdentifymes- (OF3=0F2=0F1=0F0=0),asynchronoustransferswill
sagesenttotheInitiatorafterSelectionphase.TheTLV occur.Valuesgreaterthanzerodefineasynchronous
andDOKbitsarenotused. transfermodeandtheoffsetisdeterminedasshown
below.ThisoffsetdeterminestheeffectiveFIFOdepth
7 o
forsynchronousdatatransfers,andistypicallydeter-
TLV|DOK]|ofojofTL2|TL1|TLO
minedbynegotiationwiththeotherSCSIdevice(as
definedintheSCSIstandard).TheTransferPeriod
controlbitsselecttheminimumtransferperiodforboth
TARGETLUNbit0
TARGETLUNbit1 synchronousandasynchronousSCSItransfersand,it
TARGETLUNbit2 DBABusmodeisused,thetransferperiodandthe
NotUsed
widthoftheRE/WEstrobesforhosttransfers.Thepe-
NotUsed
NotUsed riodisdefinedintermsoftheinternalclockcycletime;
DisconnectsOK thefrequencyofthisclockisdeterminedbythedivisor
TARGETLUNValid
selectedintheOWNIDregister.
11853.907A
7 o
o[TP2]TP1]TP0[OF3]OF2]OF1]|OF0
Inadvancedmode,duringSelect-and-Transfercom-
mands,thisregisterisusedtohandlereselectionbyan
unexpectedTarget.Inthiscase,thisregisterwillhold
OFFSETbit0
thelogicalunitnumberofthereselectingtarget.The LOFFSETbit1
TLVandDOKbitswillbezero. OFFSETbit2
OFFSETbit3
TRANSFERPER.bit0
COMMANDPHASEREGISTER TRANSFERPER.bit1
(Address10Hex) TRANSFERPER.bit2
TheCOMMANDPHASEregisterisusedduringcombi-
118530008
nationcommandstoindicatewhichphasesofthese
1-14 Am33C93A

AMDa
| Bit | Name | Description |
| --- | --- | --- |
| 0-3 | OFx | TheOFFSETbitsareusedtoselectthedesiredoffsetaccordingtothefollowing: |
| 3 | 2 | 1 0 SelectedOffset |
| o | o | o0 o 0(=Asynchronousdataphasetransfers) |
| o | 0 | 0 1 1 |
| o | 0 | 1 0 2 |
| o | 0 | 1 1 3 |
| o | 1 | 0 o0 4 |
| o | 1 | o0 1 5 |
| o | 1 | 1 0 6 |
| o | 1 | 1 1 7 |
| 100 | 0O | 8 |
| 100 | 1 | 9 |
| 101 | 0 | 10 1011 1 |
| 11 0 | 0 | 12 |
| 11 0 | 1 | Undefined 111X Undefined |
| 4-6 | TPx | TheTRANSFERPERIODbitsareusedtoselectthedesiredtransferperiodaccordingtothe followingtable: |
| scsl | DBABus | (SCSIREQVACKSynchronousPulseWidth |
| 6 | 5 | 4 TransferPerlod andDBABusRE/WEPulseWidth) |
| o | o0 | X 8cycles (4cycles) |
| 0 | 1 | 0 2" a |
| o | 1 | 1 3" a ) |
| 100 | 4" | @") |
| 101 | 5" | @") |
| 11 0 | 6 " | “") |
| 111 | 7" | “") The‘cycle’referredtoaboveistheperiodoftheinternaldatatransferclockafterthedivisorchosenintheOWNIDregisteris applied.Thisperiodiscalculatedbythefollowingformula: DIVISOR(fromOWND) CYCLE=T(useq) 2+INPUTCLOCKFREQUENGY(MHz) TRANSFERCOUNTREGISTER Send,Receive,orTransfercommandwillbecompleted (Address12,13,14Hex) whenasinglebytehasbeentransferred. TheTRANSFERCOUNTregisterisa24-bitregister Afterthecompletionofanysuccessfultransfer,the containingapresetvaluefortheinternaltransfer TRANSFERCOUNTregisterwillbezero.Thisincludes counter.Thispresetvalueisloadedintotheinternal commandsissuedinSingleByteTransfermode. transfercounterwhenaSend,Receive,orTransfer commandisissued.Thiscounterisusedtodefine Whenatransferisinterruptedbyahaltonerrorcondi- commandcompletionbydecrementingaseachdata tion,aSCSIbusphasechange,oranabort,the byteistransferredovertheSCSIbusandcausinga TRANSFERCOUNTregisterwillcontainthenumberof “successtulcompletion”interruptwhenthecounter bytesNOTsuccessfullytransferredtoffromtheSCSI reacheszero.InCombinationcommands,thisregister bus,includinganybytesleftintheFIFO(seeDATA specifiesthenumberofbytestobetransferredduringa register).ThisFIFOclearingprocessmaycausethe Dataphase. TRANSFERCOUNTregistertodifferwiththeuser's DMAcontrollercount,becausesomebytesmayhave Thecounterfunctioncanbedisabledbyloadingthe beentransferredintotheFIFO,butnottotheSCSIbus; TRANSFERCOUNTregisterwithzerospriorto therefore,theTRANSFERCOUNTshouldbeusedto issuingacommandorbysettingtheSINGLE-BYTE determinetheactualnumberofbytestransferredto/ TRANSFERbitintheCOMMANDregisterconcurrent tromtheSCSIbus. withissuingthecommand.Ifthecounterisdisabled,the Am33C93A 115 |

nAMD
DESTINATIONIDREGISTER
(Address15Hex)
TheDESTINATIONIDregistercontainstheencoded issued.Thisregisteralsocontainscontrolbitsthataffect
SCSIbusIDofthedevicewhichistobeselectedor theoperationofcertaincombinationcommands.
reselectedwhenaReselectorSelectcommandis
7 3
[sccloro]o[ o[ o[Diz[Dn[Dio]
DESTINATIONIDbit0
LDESTINATIONIDbit1
DESTINATIONIDbit2
NotUsed
NotUsed
NotUsed
DATAPHASEDIRECTION
SELECTCOMMANDCHAIN 118530104
| Bit | Name | Description |
| --- | --- | --- |
| 6 | DPD | DATAPHASEDIRECTION,whenadvancedfeaturesareenabled(seep.14),isusedto specifytheexpecteddirectionoftheSCSIdataphase,whenitoccurs.Thisallowsthe Am33C93AtoverifythedirectionduringSelect-and-Transfercommandsbeforebeginning thetransfer.Whenthisbitiszero,theexpecteddirectionisout(totheTarget).Whenthisbit isone,theexpecteddirectionisin(fromtheTarget).Anunexpectedinformationphaseerror willoccurifthedirectiondoesnotmatchthesettingofthisbit. |
| 7 | Scc | SELECTCOMMANDCHAINisusedonlywhentheReselect-and-Transfercommandis issuedwithEDI=1.Thisbitselectswhichcommandischainedtowhenthedatatransferis completed.Whenthisbitiszero,aSend-Status-and-Command-Completecommandbegins executing.Whenthisbitisone,aSend-Disconnect-Messagecommandbeginsexecuting. |
SOURCEIDREGISTER
(Address16Hex)
TheSOURGEIDregisterisusedtoreporttheSCSIbus1Dofthedevicethathasselectedorreselectedthe
Am33C93A.Italsocontainsbitsthatenableandcontrolresponsetoselectionandreselection.
7 o
[ERTEs[osP]o[siv]si2]si[sio]
SOURGEIDbit0(readonly)
SOURCEIDbit1geadonly
SOURCEIDbit2(readonly)
SOURCE1DVALI(readonly)
NotUsed
DESABLESEL/RESEL.PARITY
ENABLESELECTION
ENABLERESELECTION 118530114
| Bit | Name | Description |
| --- | --- | --- |
| 7 | ER | ENABLERESELECTION,whensettoone,enablestheAm33C93Atorespondtoa reselectionbyanotherdeviceontheSCSIbus.Whenthisbitiszero,anyreselectionis ignored. |
| 6 | ES | ENABLESELECTION,whensettoone,enablestheAm33C93Atorespondtoaselection byanotherdeviceontheSCSIbus.Whenthisbitiszero,anyselectionisignored. |
| 5 | bspP | DISABLESELECTPARITY,whensettoone,causestheAm33C93Atoignorethebus paritywhenrespondingtoselectionorreselection.Whenthisbitiszero,anyselectionor reselectionwithaparityerrorisignored. |
| 3 | Siv | SOURGCEIDVALIDissettooneaftertheAm33C93Aisselectedorreselectediftheother SCSIbusdeviceasserteditsownbusIDbit(inadditiontothebusIDbitoftheAm33C93A) duringtheselect/reselectphase.ThisbitiszeroifonlythebusIDbitoftheAm33C33Awas asserled. |
| 2-0 | Six | SOURCEIDBits2-0arevalidonlyiftheSIVbitissettoone.ThesebitsindicatetheSCSI busIDofthedevicethatselectedorreselectedtheAmM33C93A. 1-16 Am33C93A |

AMDn
SCSISTATUSREGISTER «TheAm33C93Ahasbeenreset;
(Address17Hex) «Thecommandcompletedsuccessfully;
TheSCSISTATUSregisterisaread-onlyregister «Thebusphasechanged;
whichindicatedthecauseofthemostrecentINTRQ «Anerroroccurred.
assertion.INTRQisassertedwheneveracondition
OnceINTRQhasbeenasserted,thecontentsofthis
occurswithintheAm33C93Athatrequiresintervention
registerwillnotchangeuntilaftertheSCS!STATUS
bythehost;forexample:
registerhasbeenreadoruntiltheAm33C93Ahasbeen
reset.
7 o
[ss7]ss6]ss5[ss4]ss3]ss2[ss1]ss0]
SCSISTATUSbit0
SCSISTATUSbit;
3o@4>2c@itg
SCSISTATUSbit3
SCSISTATUSbit4
SCSISTATUSbit5
SCSISTATUSbit6
SCSISTATUSbit7118530124
| Bit | Name | Description |
| --- | --- | --- |
| 0-3 | 8Sx | SCS1STATUSbits0-3arestatusqualifierswhosemeaningdependsupon whichupper (4-7)statusbitisset. |
| 4-7 | SSx | SCSISTATUSbits4-7definethetypeofinterruptthatoccurred. Thepossiblecodesare definedinthefollowingtable: |
| Status | I | GroupMeaning |
| 0000 | XXXX | TheAm33C93Aisinaresetstate. |
| 0001 | xooc | AAm33C93Acommandhascompletedsuccessfully. |
| 0010 | xxxx | AAm33C93AcommandhaspausedorwasabortedbyanAbortcommand. |
| 0100 | XXXX | AAm33C93Acommandhasbeenterminatedprematurelydue toanerroror otherunexpectedcondition. |
| 1000 | xox | AneventontheSCSIbusrequiresservice. |
| AllotherStatusCodegroupsarecurrentlynotusedand | MCICODE arereservedforfutureuse. 000 DataOutphase | MEANING |
| Inthefollowingtables,the‘STATE’columnindicates | 001 | DataInphase 010 Commandphase thecurrentstateinwhichtheStatusCodecanoccur. o1t Statusphase Also,theMCIfieldreferstothesignalsthat_definea 100 UnspecifiedInfoOutphase SCSIbusinformationtransferphase:MSG,T/D,and 101 UnspecttiedInfoInphase 1/0.Abitsettooneindicatesthatthesignalisasserted 110 MessageOutphase ontheSCSIbus.Azeroindicatesnegation.Whenever 11 MessageInphase oneoftheseStatusCodesoccurs,theREQsignalis assertedontheSCS\|bus.Thetablebelowsummarizes themeaningoftheMCifield: Am33C93A 117 |

aAMD
ResetStateInterrupts
| Status | Code | State* | SpecificMeaning |
| --- | --- | --- | --- |
| 0000 | 0000 | oTl | Am33C9A3Reset.Thedevicehasbeenreset,oraResetcommandhasexecuted successfullywithnoadvancedfeaturesenabled.ThenewstateoftheAm33C93Ais disconnected. |
| 0000 | 0001 | DTI | Am33C93AReset.ThedevicehassuccessfullycompletedaResetcommandwith advancedfeaturesenabled.ThenewstateoftheAm33C93Aisdisconnected. SuccessfulCompletionInterrupts |
| Status | Code | State* | SpecificMeaning |
| 0001 | 0000 | D | AReselectcommandcompletedsuccessfully.ThenewstateoftheAm33C93Ais connectedasaTarget. |
| 0001 | 0001 | D | ASelectcommandcompletedsuccessfully.ThenewstateoftheAm33C93Ais connectedasanInitiator. |
| 0001 | 0010 | — | Reservedforfutureuse. |
| 0001 | 0011 | DT | AReceive,Send,Reselect-and-Transfer,Wait-for-Select-and-Receive,Send-Status- and-Command-Complete,oraSend-Disconnect-Messagecommandcompletedsuc- cesstully(ATNisnotasserted). |
| 0001 | 0100 | oT | AReceive,Send,Reselect-and-Transfer,Wait-for-Select-and-Receive,Send-Status- and-Command-Complete,oraSend-Disconnect-Messagecommandcompleted successtully(ATNisasserted). |
| 0001 | o101 | DT | ATranslateAddresscommandcompletedsuccessfully. |
| 0001 | 0110 | DI | ASelect-and-Transfercommandcompletedsuccessfully |
| 0001 | 0111 | - | Reservedforfutureuse. |
| 0001 | mcl | 1 | ATransler(non-MESSAGEINphase)commandcompletedsuccessfully.MCIdefinesthe newinformationtype(SCS!busphase)beingrequested. PausedorAbortedInterrupts |
| Status | Code | State* | SpecificMeaning |
| 0010 | 0000 | ] | ATransferInfo(MESSAGE-INphase)commandhaspausedwithACKasserted.This allowsthehosttoexaminethemessagebeforeacceptingit. |
| 0010 | 0007 | 1 | ASave-Data-PointermessagewasreceivedduringaSelect-and-Transtercommand.The hostshouldsaveitscurrentdatabuferpointer. |
| 0010 | 0010 | D | ASelectorReselectcommandwasaborted. |
| 0010 | 0011 | T | AReceiveorSendcommandhashaltedbyanerrororwasaborted(ATNisnotasserted). |
| 0010 | 0100 | T | AReceiveorSendcommandhashaltedbyanerrororbyassertionofATNorwasaborted (ATNisasserted). |
| o010 | oot | - | Reservedforfutureuse. |
| 0010 | o110 | — | Reservedforfutureuse. |
| 0010 | o111 | D | TheAm33C93AhasbeenreselectedduringaSelect-and-Transfer(withIDI=0)bya TargetthatdoesnotmatchtheSCSIbusIDloadedintotheDESTINATIONIDregisteror thefollowingIdentifymessagedidnotmatchtheLUNloadedintotheTARGETLUN register.ACKhasbeenleftassertedfollowingtheIdentifymessage,andthebusIDand LUNofthereselectingTargetareavailableintheSOURCEIDandTARGETLUN registers. |
| o010 | 1MCI | 1 | ATransfercommandwasaborted.MCIdefinethenewinformationtype(SCS1busphase) beingrequested. *D=Disconnected T=ConnectedasaTarget 1=ConnectedasanInitiator 1-18 Am33C93A |

AMDa
TerminatedInterrupts
| Code | State* | SpecificMeaning Status |
| --- | --- | --- |
| 0100 | 0000 | DTl Aninvalidcommandwasissued. (SCSIbusfree)bytheTargetcausedacommandtoterminate. |
| o100 | 0001 | \| Anunexpecteddisconnect ThenewstateoftheAm33C93Asdisconnected. |
| o100 | 0010 | D Atimeoutoccurredduring aSelectorReselectcommand.ThestateoftheAm33C93A is disconnected. |
| 0100 | 0011 | Tl Aparityerrorcausedacommand toterminate(ATNisnotasserted).Thetransferdirection determineswhetheritisaSCS!orhostparityerror. |
| 0100 | 0100 | T Aparityerrorcausedacommand toterminate(ATNisasserted).Thetransferdirection determineswhetheritisaSCSIorhostparityerror. |
| 0100 | 0101 | DT TheLogicalAddressexceeded thediskboundaries. |
| o100 | o110 | D ATargetwhoseSCSIbus deviceIDdoesnotmatchthebusIDsetintheDESTINATION |
ID
registerhasreselectedtheAm33C93AduringaSelect-and-Transfer
command(withIDI<0).
ThisinterruptoccurswhentheAm33C3AsnotinAdvancedMode.
Thenewstateofthe
AmM33C93AisconnectedasanInitiator.
| 0100 | 0111 | \| | Anincorrectstatusbytewas receivedduringaSelect-and-Transfercommand. |
| --- | --- | --- | --- |
| 0100 | 1MCI | 1 | Anunexpectedinformationphase wasrequested.MCIdefinetheSCS\|busphasewhichis requested.Thisistypicallycausedbyaphasechange beforetheTransferCounthas reachedzeroorbyanunexpectedphasesequenceoccurringduring aSelect-and-Transfer command. ServiceRequiredInterrupts Code_State* SpecificMeaning Status |
| 1000 | 0000 | D | TheAm33C93Ahasbeenreselected. ThenewstateoftheAm33C93Aisconnectedasan nitiator.NoIdentifymessagetransferhasyetoccurred. |
| 1000 | 0001 | D | TheAm33C93Ahasbeenreselected inAdvancedMode.TheSCSIbusIDoftheTarget maybereadfromtheSOURCEIDvngtRev.TheIdentifymessage fromtheTargetmaybe readfromtheDATAregister.The signalisleftasserted.Thenew stateofthe AmM33C93AisconnectedasanInitiator. |
| 1000 | 0010 | D | TheAm33C33Ahasbeenselected (ATNwasnotasserted).Thenewstateofthe Am33C93AisconnectedasaTarget. |
| 1000 | 0011 | D | TheAm33C93Ahasbeenselected (ATNwasasserted).ThenewstateoftheAm33C93Ais connectedasaTarget. |
| 1000 | 0100 | T | TheATNsignalhasbeenasserted. |
| 1000 | 0101 | \| | Adisconnecthasoccurred.Thenew stateoftheAm33C93Asdisconnected. |
| 1000 | 0110 | Reservadforfutureuse. |  |
| 1000 | 0111 | TheWait-for-Select-and-Receive commandhaspausedbecausethefirstbyteofthe incomingCDBisnotaknowncommandgroup.TheOWNIDregister mustbeloadedwith theCDBlength,andthecommandresumed.TheCDB1register maybeexaminedto determinetheSCSIcommandgroupfromtheopcode.Thenew stateoftheAm33C93Ais connectedasaTarget.(AdvancedModeonly) |  |
| 1000 | 1MCI | ! | TheREQsignalhasbeenasserted followingconnectionorwhentheAm33C93Aisinthe Initiatorstateandnocommandisexecuting.Theinformationphasetypeshould beexam- ined.MC!definetheinformationphase(SCS\|busphase)whichisbeing requested. *D=Disconnected T=ConnecledasaTarget 1=ConnectedasanInitiator Am33C93A 1-19 |

nAMD
COMMANDREGISTER
(Address18Hex)
TheCOMMANDregisterisusedtoissuethe conjunctionwithoneofthesecommands,thetransfer
AM33C93Acommands.Thisregistershouldneverbe counterisdisabledandexactlyonebyteistobe
loaded when the CIP or INT bits	(in	transferred,regardlessofthevalueintheTRANSFER
AUXILIARYSTATUS)aresettoone,andaLevelIl COUNTregister.Thepreviouscontentsofthe
commandshouldneverbeloadedwhentheBSYbitis TRANSFERCOUNTregisterarenotpreserved.
settoone.
RefertotheCOMMANDSsectionforadescriptionof
TheSINGLE-BYTETRANSFER(SBT)bitinthe thecommandsandtheircorrespondingcommand
COMMANDregisterisonlyusedduringinformation codes.
transfertypecommands.Whenthisbitissetin
7 o
[seT]cce]ccs]cea]cea]ccz[ccifcco]
‘COMMANDCODEBit0
‘COMMANDCODE
‘COMMANDCODE
COMMANDCODEBit6
SINGLE-BYTETRANSFER118530138
DATAREGISTER butferchipselectandtheWEandREpinsbecomeout-
(Address19Hex) puts,allowingtheAm33C93Atoautomaticallytranster
TheDATAregisterisusedtotransferdatabytesbe- databetweenitsDATAregisterandtheexternalbuffer.
tweenthehostandtheSCSIbusduringtheSCSI Inthismode,buscontrolcanberetunedtotheexternal
informationtransferphases(command,data,status,or processororanyotherdevicebynegatingtheDRQpin.
messagephase).Itmaybeaccessedbytheprocessor
ResetConditions
duringanytypeofinformationphase(simpleLeve!1l
ccommands)orviatheDMA/DBABusinterfaceduringa HARDWARERESET
SCSIDataInphaseorDataOutphase(simpleand Thefollowingresultsoccur_whentheAm33C93Ais
combinationLevelIlcommands). resetbytheassertionoftheMRsignal:
TheDATAregisterisactuallyaportforthehostinter- +TheAUXILIARYSTATUSregisterisresettozero.
faceintotheinternaltwelvebyteFIFOofthe TheINTbit(andtheINTRQpin)issettoonewhen
Am33C93A.TheFIFOisusedforalltransfers thehardwareresetcompletes.
(synchronousandasynchronous)betweentheSCSI
TheOWNIDregisterisresettozero.
busandthehostbus,forbothDMAandprocessor
Advancedmodeisdisabled.
accesstransfers.IftheAm33C93Aistobehaltedfor
TheES,ER,andDSPbitsintheSOURCEID
anyreason(throughABORT,forexample),thendata
registerareresettozero.
transferswiththisFIFOmustcontinueuntilaninterrupt
TheSCSISTATUSregisterisresettozero.
occurs.ThismustbedonesothattheFIFOisreturned
TheinternalFIFO,internaltransfercounter(not
toareadystateforsubsequenttransfers,andtoflush
thehostaccessibleregister),offsets,andstate
incomingdatatothehostbus.
machinesarecleared.
TheDATAregisterisaccessedbytheprocessorduring Theinternalclockdividercircuitissettodivideby
two.
adataphasewhentheCONTROLregisterDMAmode
selectbitsareallreset(=0),andwhentheDBRbitinthe ThefollowinghostaccessibleregistersareNOT
AUXILIARYSTATUSregisteristrue.Theprocessor affectedbytheMRsignal:
writes(reads)theDATAregisterbyloadingthe Registers01hexthrough15hex;
ADDRESSregisterwithahexvalueof19andasserting SOURCEID(16hex)registerbits0-3;
theWE(RE)andTSpins.Thisaccessalsooccursdur- COMMANDregister{18hex);
ingnon-dataphases.
Note:TheSCS!SoftResetmaybeimplementedbyusingthe
SCSIbusresetsignaltocausearesetofthe
WhentheCONTROLregisterDMAmodeselectbitsare
Am33C93A(forexample,ORthehostpoweronreset
setforDMAmodeorBURSTmode,theDMAinterface
signalwiththereceivedSCSIbusreset(RST)signal).
isenabled.Inthiscase,theDATAregisteriswritten
Thehostmeysxaminetheregistersthatarenotaf-
(read)whentheDACKandWE(RE)pinsareasserted
fectedbytheMRsignaltorecoverfromtheSCSIreset
inresponsetotheassertionbytheAm33C93Aofthe
DRQpin.WhentheDBABusisselectedbytheDMA
modeselectbits,theRCSpinfunctionsasanexternal
1-20 Am33C93A

AMDn
SOFTWARERESET
ThefollowingresultsoccurwhentheAm33C93A «TheOWNIDregisterisinterpretedandtheclock
executestheSoftwareResetcommand: divisor,hostparity,andadvancedmodearecon-
«TheDBRbitintheAUXILIARYSTATUSregisteris figured.
resettozero.TheINTbit(andINTRQpin)issetto *Registers01hexthrough16hexareresettozero.
onewhentheResetcommandiscomplete. TheCOMMANDregister(18hex)isalsoresetto
«AllSCSIbussignalsareresettothenegatedstate. zero.
«TheSCSISTATUSregisterissetascommanded
«TheinternalFIFO,internaltransfercounter(notthe
bytheEAFbitintheOWN1Dregister.
hostaccessibleregister),offsets,andstate
machinesarecleared.
COMMANDS
CommandList
Command
Code Valid
| (HEX) | Command | States | Level |
| --- | --- | --- | --- |
| 00 | Reset | AN | i |
| 01 | Abort | DTl | i |
| 02 | AssertATN | i | ! |
| 03 | NegateACK | I | I |
| 04 | Disconnect | T | 1 |
| 05 | Reselect | o] | I |
| 06 | Select-with-ATN | D | n |
| 07 | Select-without-ATN | 3] | n |
| 08 | Select-with-ATNand-Transfer | D! | ] |
| 09 | Select-without-ATNand-Transfer | D/} | I |
| 0A | Reselect-and-Receive-Data | DT | n |
| 0B | Reselect-and-Send-Data | DT | [ |
| oc | Wait-for-Select-and-Receive | DT | " |
| oD | Send-Status-and-Command-Complete | T | \| |
| 0E | Send-Disconnect-Message | T | n |
| OF | SetIDI | D,TI | 1 |
| 10 | ReceiveCommand | T | i |
| 1 | ReceiveData | T | n |
| 12 | ReceiveMessageOut | T | 1 |
| 13 | ReceiveUnspecifiedInfoOut | T | 1 |
| 14 | SendStatus | T | I |
| 15 | SendData | T | I |
| 16 | SendMessageIn | T | il |
| 17 | SendUnspecifiedInfoIn | T | I |
| 18 | TranslateAddress | oT | n |
| 20 | TransferInfo Am33C93Astates: CommandLevels: D=Disconnected \|=Level{command T=ConnectedasaTarget It=LevelIlcommand 1=ConnectedasanInitiator Am33C93A 1-21 | I | n |

amn
Am33C93ACommandTypes diateinterruptafterthereselectionhandshakeis
TherearetwobasictypesofAm33C93Acommands: complete.InAdvancedMode,theAm33C93Awill
Level|andLevelII.Level|commandsmaybeissued continuetotheMessageInphasetofetchtheIdentify
whileaLevelIlcommandisinprogress(indicatedbyan message.IftheAm33C93Awasidle,theSCSI
AUXILIARYSTATUSofBSY=1,CIP=0)and,exceptfor STATUSregisterwillbesetto81hex,andtheIdentify
the“Abort”and“Reset”commands,donotgeneratean messagewillbeintheDATAregister.IftheAm33C93A
interruptupontheircompletion.LevelIlcommandexe- wasexecutingaSelect-and-Transfercommand,the
cutionwillaiwaysresultinaninterrupt.IfaLevelIl SCSISTATUSregisterwillbesetto27hex,andthe
commandisissuedwhileanotherLevelIlcommandis IdentifymessagewillbeintheTARGETLUNregister.
executing,unpredictableresultsmayoccur. Ineithercase,theSOURCEIDregisterwillcontainthe
SCSIbusIDofthereselectingTarget,andtheACK
TherearetwotypesofLevelIlcommands.‘Simple’ signalremainsassertedsothattheIdentifymessage
LevelIlcommandsareassociatedwithasingleopera- mayberejected.
tionorphase(forexample,selectionorinformation
transfer).‘Combination’LevelIlcommandscombine
UNKNOWNSCSICOMMANDGROUPS
multiplephasesintoasingleAmM33C93Acommandto
WhenaSCSICommandDescriptorBlockistransferred
minimizeinterruptoverhead.TheInitiatorcombination
ontheSCSIbus,thecommandlengthinbytesisdeter-
commands‘expect’certainSCS|busphasesatcertain
minedbythegroupcode,whichisfoundinbits7-5of
timesduringasequence.Theseexpectedphasesare
thefirstcommandbyte,oropcode.Group0(opcodes
basedoncommonsequencesperformedbyaTarget
00to1Fhex),group1(opcodes20to3Fhex),and
ontheSCSIbus;anydeviationcausesaninterrupt.
group5(opcodesAQtoBFhex)commandsaredefined
Targetcombinationcommandscanbechainedto-
bytheSCSIstandard(X3.131-1986)assix,ten,and
gethertofurtherminimizeinterruptoverheadby
twelvebytecommands,respectively.Allothercom-
creatinglongerphasesequences.
mandgroupsareundefinedbythatstandard.Innormal
NOTE:Whenusingcommandchaining,caremustbetaken mode,theAm33C93Awillassumethattheseundefined
toensurethatallcommandsinthechainareinitial- groupsaresixbytecommandswhenexecutingSelect-
izedpriortoissuingthecommand. and-TransferorWait-for-Select-and-Receivecom-
mands.InAdvancedMode,thefollowingeventswill
TheAm33C93Awillbeinoneofthree“states”during
occur:
operation:Disconnected,ConnectedasaTarget,or
ConnectedasanInitiator.Certaincommandsarevalid Select-and-Transfer:WhenloadingtheCDBintothe
onlyinparticularstatesasindicatedintheCOMMAND CDBregisterspriortoissuingthecommand,thehost
LIST.AnattempttoissueaLevelIfcommandwhichis alsoloadstheexpectedcommandlengthintotheOWN
invalidforthepresentAm33C93Astatewillcausean 1Dregister.TheAm33C93Ausesthisvaluetomake
“invalidcommand"interrupt.Level|commandsissued surethecorrectnumberofbytesarethentransferredin
ininvalidstateswillbeignored. thecommandphase.
AdvancedModeFeatures Wait-for-Select-and-Receive:WhenreceivingtheCDB
fromtheInitiator,theAm33C93Awillcheckthefirst
TheAm33C93Ahasseveralnewfeaturesincluded
CDBbyteassoonasitisreceived.Ifthegroupis
whichaddnewfunctionstotheoriginal33C93design.
undefined,aninterruptwilloccursothatthehostcan
SomeofthesefeaturescausetheAm33C93Atobe
‘examinethefirstcommandbyteintheCDB1STregis-
incompatiblewiththe33C93.Thesefeatureshavebeen
ter,andthenloadtheTOTALcommandlengthintothe
groupedtogetherundertheheadingof‘Advanced
OWNIDregister.TheSCSISTATUSregisterissetto
Mode’features.Thesefealuresaredisabledwhenthe
87hex,andtheCOMMANDPHASEregisterissetto31
Am33C93AisresetbytheMRsignal(hardwarereset).
hex,whenthisinterruptoccurs.
Theymustbeenabledbythehostbyissuingthe‘Reset’
commandwiththe‘EnableAdvancedFeatures'(EAR)
Aftertheinterrupt,theAm33C93Awillonlyaccepta
bitsetintheOWN1Dregister.Thehostcandetermineif
ResumeWait-for-Select-and-Receivecommand,Abort,
advancedfeatureshavebeenenabled(thereby
Disconnect,orResetcommand.Allothercommands
implyingthataAm33C93Aisinstalled)byexamining
areinvalid;duringtheinterruptprocessing,the
theSCSISTATUSregisterafterissuingthe‘Reset’
Am33Ca3Awillcontinuetotransferthefirstsixbytesof
command.
thecommandintoitsinternalFIFO.
Thefeaturesenabledbythisbitaredescribedbelow.
DATAPHASEDIRECTION
DuringaSelect-and-Transfercommandinnormal
UNEXPECTEDRESELECTION
mode,theDataphasedirectionisdeterminedsolelyby
Wheninnormal(33C93)mode,areselectionwhenidle
theTarget;ifthisdirectiondoesnotmatchthedirection
(ER=1)orwhendisconnectedduringaSelect-and-
expectedbythehost,theAm33C93Awillnotdetectthis
Transfercommand(andtheTargetbusIDdoesnot
errorbutexpectsthatthetransferwillcontinue.In
matchtheDESTINATIONIDregister)causesanimme-
1-22 Am33C93A

AMD
AdvancedMode,theDPDbitintheDESTINATION1D arbitrarytimeduringtheAbortcommandprocessing
registeriscomparedwiththestateoftheI/Osignalon andthedatarequestisnotvalidoncetheAbort
theSCSIbus.Iftheexpectedandactualdirectionsdo commandiswrittentotheCOMMANDregister.
notmatch,aninterruptwilloccurwith‘unexpected
2.WhenaAbortcommandisissuedtoabortaReceive
phase’statusintheSCSISTATUSregister.
orReselect-and-Receivecommand,thelocalproc-
essormustCONTINUEtoserviceanydatarequest
Level|Commands
(DBR,DRQ,etc.)fromtheAm33C93Auntilaninter-
RESET(00HEX) ruptfromtheAm33C93Aoccurs.Thisisrequiredto
TheResetcommandperformsasimilarfunctiontothe allowtheFIFOtoclear;theAbortprocessingwillnot
hardwareresetcausedbyasseringtheMRpinexcept completeuntiltheFIFOcontentsareflushedtothe
thattheOWNDregisterissampledforinformation localprocessor.
concerningtheoperatingconfigurationofthe
Am33C93A.TheAM33CI3Aisalsoinitializedasde- AftertheAbortcommandisprocessedandthelocal
scribedintheRESETCONDITIONSsection.TheReset processorhasreceivedtheinterruptindicatingthis,the
commandmaybeexecutedinanyAm33C93Astate TRANSFERCOUNTregistercontainsthenumberof
andwillforcetheAm33C93AintotheDisconnected bytesthatwerenotsuccessfullytransferredwiththe
state,abortinganypreviouslyissuedcommandin SCSIbus.TheAm33C93AremainsintheConnected-
progress.UponcompletionoftheResetcommand,an as-a-Targetstate.TheAm33C93Aisnowreadytore-
imerruptisgeneratedtheSCSISTATUSwillbe00hex ceiveanyappropriateTargetmodecommand,including
or01hex,dependingonthecontentsoftheOWN1D aresumeofthecommandthatwasaborted.
register.
DISCONNECT(04HEX)
ABORT(01HEX) TheDisconnectcommandmaybeusedineitherthe
TheAbortcommandisvalidintheDisconnectedand TargetortheInitiatorconnectedstates.IntheTarget
Connected-as-a-Targetstates.TheAbortcommandhas role,theDisconnectcommandisthenormalprocedure
differenteffectsdependingonthestateandthecom- fordisconnectingfromtheSCSIbusfollowingtheinfor-
mandthatiscurrentlyexecuting,asdescribedbelow: mationtransferphase.IntheInitiatorrole,Disconnect
canbeusedtoreleasethebusfollowingatimeout
DisconnectedState:IntheDisconnectedstate,the condition.TheDisconnectcommandcausestheimme-
Abortcommandmaybeusedtohaltanattempted diatereleaseofallbussignalsand,inTargetmode,
Select,Select-and-Transfer,Reselect,orReselect-and- returnstheSCSIbustotheBusFreephase.Ifthe
Transtercommand.IftheAbortcommandisissued DisconnectcommandisissuedduringanactiveLevelIl
followingaSelectorReselectcommandandthe command,theLevelIlcommandisimmediatelytermi-
Am33C93Ahaswonarbitration,theAm33C93A natedandtheAm33C93AtransitionstotheDiscon-
releasestheSCSIbusbyremovingtheBusIDbils
nectedstate.
whileSELisassertedandcheckingforanegatedBSY
signal.Ifafteratleast200ps,thereisnoBSYresponse,
ASSERTATN(02HEX)
theAm33C93AgoestoaBusFreeconditionandgener-
TheAssertATNcommandisonlyvalidwhenCon-
atesa"paused/aborted”interrupt.Ifthereisaresponse
nectedasanInitiator.Itisnormallyusedtoaflowthe
withinthistimeperiod,thena“successfulcompletion”
InitiatortoinformaTargetthatithasamessagepend-
interruptwillresultinstead.IftheAm33C93Ahasnotyet
ing(TheTargetisexpectedtorespondbyperforminga
wonarbitration,itimmediatelyabortstheSelector
MessageOutPhase).
Reselectcommand.
ATNisautomaticallynegated:
TargetState:WhentheAm33C93AisinaConnected-
«BeforethelastbyteofaTransferInfocommand
as-a-Targetstate,theAbortcommandmaybeusedto
issuedinresponsetotheMessageOutphase;
abortReceive,Send,orthedataphaseportionofa
Targetcombinationcommand.WhenissuinganAbort +WhentheIdentifymessageoutistransferredtothe
intheConnected-as-a-Targetstate,thefollowingrules TargetduringaSelect-and-Transfercommand;
apply:
«WhenaSCSIBusFreephaseoccurs.
1.WhenaAbortcommandisissuedtoabortaSendor
TheSelect-with-ATNandSelect-with-ATN-and-
Reselect-and-Sendcommand,thelocalprocessor
TransfercommandswillcausetheAm33C93Atoauto-
mustnotserviceanydatarequest(DBR,DRQ,eic.)
maticallyassertATNpriortothereleaseofSELprovid-
fromtheAm33C93Auntilaninterruptfromthe
ingthebusarbitrationiswon.
Am33C93Aoccurs.Thisisrequired1oallowthe
FIFOtoclear;theAbortprocessingwillnotcomplete
untiltheFIFOcontentsareflushedtotheSCSIbus.
TheAm33C93Aremovesthedatarequestatan
Am33C93A 1-23

nAMD
NEGATEACK(03HEX) thistime,atimeoutsequencewhoselengthisdeter-
TheNegateACKcommandcausesACKtobenegated. minedbythevalueintheTIMEOUTPERIODregister
Itmaybeusedinthefollowingsituations: begins.IBSYisnotassertedbytheTargetbeforea
timeoutoccurs,theAm33C93Abeginsitsselection
-aftersuccessfulcompletionofaMessage-In
abortsequence(asdescribedintheAbortcommand
TransierInfocommands;
description),andifthereisnoTargetresponsethe
-aftertheAm33C93Ahasdetectedaparityerroron
Select-with-ATNcommandisterminatedanda“ter-
anyreceivedSCSIinformationandtheHALTon
minated”interruptisgenerated.IftheTargetresponds
SCSIPARITYERROR(HSP)bitisset;
beforethetimeoutperiodhaselapsedorbeforethe
«afterunexpectedreselectioninadvancedmode; selectionabortsequenceiscomplete,theAm33C93A
and negatestheSELsignal,puttingtheAm33C93Aina
Connected-as-an-Initiatorstate.A“successfulcomple-
«afterasave-data-pointermessageisreceived
tion”interruptindicatesthattheSelect-with-ATNcom-
duringaselect-and-transtercommand.
mandhasbeencompletedsuccessfully.
HostparityerrorsdonotaffecttheACKsignal.Forall
IftheAm33C93Adoesnotwinthearbitrationorthereis
otherInitiatortransfers,ACKnegationisautomatic.
noresponsefromtheTargetandthetimeoutfeatureis
InthecaseofaMessage-Intransfer,incomingmes- disabled,theSelect-with-ATNcommandcanbe
sagesmayberejectedandtheInitiatormayindicateits abortedwithanAbortcommand.WhentheAbort
intenttosendeithera“MESSAGEREJECT"ora commandissuccessfullyexecutedunderthesecircum-
“MESSAGEPARITYERROR"Messagebyissuingthe stances,theAm33C93Aisdisconnectedfromthebus
AssertATNcommandpriortoissuingtheNegateAck anda“paused/aborted”interruptisgenerated.
command.Iftheincomingmessageistobeaccepted,
onlytheNegateAckcommandshouldbeissued.
SELECT-WITHOUT-ATN(07HEX)
TheSelect-without-ATNcommandisidenticaltothe
Duringnon-Message-Intransfers,iftheTransfercom-
Select-with-ATNcommandexceptthatATNisnotset
mandisterminatedbyaparityerror,theAssertATN
duringtheSelectionPhase.
ccommandcanagainbeissuedpriortoNegateACK,this
timeindicatingtheInitiator'sintenttosendan
“INITIATORDETECTEDERROR"Message. RESELECT(05HEX)
TheReselectcommandisidenticaltotheSelect-
without-ATNcommandexceptthattheVOsignalis
SETIDI(OFHEX)
asserteduponcompletionoftheArbitrationPhase.
TheSetIDIcommandisusedintheInitiatorroleto
SuccessfulcompletionoftheReselectcommand
supportoverlappedSCSIoperations.IfaSCSIcom-
resultsintheAm33C93AbeingConnectedasaTarget.
mandisexecutingviaaSelect-and-Transfercommand,
thentheSetIDIcommandmaybeusedtosettheIDIbit
RECEIVE(10-13HEX)
intheCONTROLregister,whichthencausesaninter-
rupttooccuruponaTargetdisconnection.Thisability TherearefourReceivecommandswhicharedistin-
allowstheIDIbittobeleftresetwhenthefirstSCSI qguishedfromeachotheronlybythestateofthreeSCSI
operationisstarted,whichmayreducethenumberof interfacesignalsandthetypeofdatathatistransferred.
Thesecommands,consistingoftheReceive
Am33C93Ainterrupts,yetalsoallowsasecond
operationtobestartedwhenneededwithoutwaitingfor Command,ReceiveData,ReceiveMessageOut,and
thefirstoperationtobecompleted. ReceiveUnspecifiedInfoOutcommandsarevalidonly
intheConnected-as-a-Targetstate.Thetypeofthe
SimpleLevelIlCommands Receivecommandselecteddeterminesthestateofthe
VO,C/D,andMSGoutputsduringthecommand ac-
SELECT-WITH-ATN(06HEX)
cordingtothefollowingchart(1=asserted):
Select-with-ATNisvalidonlyintheDisconnectedstate
andwhenissuedwillcausetheAm33C93Atoselecta TheReceivecommandsareinformationtransferring
Target.Beforeissuingthiscommand,theSCSiBus1D commandsandarethereforedependentontheSBTbit
oftheTargetdeviceshouldbewrittenintothe intheCOMMANDregisterfordeterminationofasuc-
DESTINATIONIDregister.WhentheSelect-with-ATN
| commandisissued,theAm33C93Abeginsbus | ReceiveCommandType arbitration.IftheAm33C93Aisselectedorreselected | OPCODEMSGCD1O |
| --- | --- | --- |
| ReceiveCommand | 10 | o 1 o byanotherdeviceduringthearbitration,theSelect-with- |
| ReceiveData | 11 | 0 o o ATNcommandisabortedanda“servicerequired” |
| ReceiveMessageOut | 12 interrupt(8xhex)isgenerated. | 10 |
| ReceiveUnspecifiedInfoOut | 13 | 10o ShouildtheAM33C93Awinthearbitration,SELandATN areasserted,theTargetandInitiatorBusIDsareplaced ontheSCSIdatabus,andthenBSYisdeasserted.At 1-24 Am33C93A |

AMDn
SendCommandType~OPCODEMSGC/D 1O
cessfulcompletion.Inadditiontoaterminationcaused
byreset(viaeitheraResetcommandbeingissuedor
| SendStatus. | 14 | o | 1 | 1 |
| --- | --- | --- | --- | --- |
| assertionoftheMRpin),aReceivecommandcomple- | SendData | 15 | o | o ot |
| tionorterminationwilloccurunderanyofthesecondi- | SendMessageIn | 16 | 1 |  |
| tions:(1)Theinternaltransfercounterisdisabled | SendUnspecifiedInfoIn (SBT=1ortheTRANSFERCOUNTregisterisloaded withzero)andasinglebytehasbeenreadfromthe DATAregister;(2)Thecounterhasdecrementedto TheSendcommandsarealsoinformationtransferring commandsandassucharealsodependentuponthe zero(withSBT=0)indicatingthatthespecifiednumber ofbyteshavebeentransferred;(3)Aparityerrorhas SBTbitintheCOMMANDregisterforcommandcom- pletion.Inadditiontothatcausedbyreset(viaeithera beendetectedononeofthereceiveddatabytes(and ResetcommandbeingissuedorassertionoftheMR HSP=1);(4)TheATNpinisasserted(andHA=1);(5) pin),aSendcommandcompletionorterminationwill TheAbortcommandisissued;or(6)ADisconnect occurunderanyoftheseconditions:(1)Theinternal commandisissued. transfercounterisdisabled(SBT=1ortheTRANSFER WhentheReceivecommandiscompletedasaresultof COUNTregisterisloadedwithzero)andasinglebyte receivingthecorrectnumberofbytes,a“successful hasbeenreadfromtheDATAregister;(2)Thecounter completion”interruptwillbegenerated.Ifaparityerror hasdecrementedtozero(withSBT=0)indicatingthat hascausedtermination,a“terminated”interruptwill thespecifiednumberofbyteshavebeentransferred; insteadbegenerated.Inthiscase,theTRANSFER (3)Aparityerrorhasbeendetectedononeofthedata COUNTregisterwillcontainthenumberofbytesyetto bytesfromthehost(andHHP=1);(4)TheATNpinis betransferred.Afteranycompletionorterminationof asserted(andHA=1);(5)TheAbortcommandisissued; theReceivecommandsexceptthoseduetoasubse- or(6)ADisconnectcommandisissued.The quentDisconnectcommandorreset,theAm33C93Ais Am33C93AremainsConnected-as-a-Targetfollowing intheConnected-as-a-Targetstate. theSendcommandcompletion/terminationunlessthe Disconnectcommandorresetwasusedtoforcea Asdatatransfercommands,theReceivecommands termination. aredependentontheDMAmodeselectbitsinthe CONTROLregisterfortheDATAregisteraccessing DuringaSendcommand,DATAregisteraccessingis mode.ThesebitsdeterminewhethertheDATAregister controliedbytheDMAmodeselectbitsinthe accesseswillbehandledbytheprocessororthrougha CONTROLregister.Whenthesebitsaresettothe DMA/Aminterface.Whentheprocessorisrequired1o appropriatemode,loadingoftheDATAregisterisac- readtheDATAregister(i.e.DMAmodeselectbits=0),it complishedbyaDMAcontrollerorthroughtheDBA mustmonitortheDBRstatusbit(inAUXILIARY Businterface.IftheDMAmodeselectbitsarezero,the STATUS)todeterminewhenabyteisavailablefor processormustpolltheAUXILIARYSTATUSregister reading.DuringReceivecommands,thisstatusbitwill andcanwritetotheDATAregisteronlywhentheDATA beresetwhenabyteisreadfromtheDATAregisterand BUFFERREADYbitisset(DBR=1).Sendcommands setwhenabyteisloadedintotheDATAregisterviathe causetheDBRbittobereseteverytimetheprocessor SCSIinterface.DBRisalsoresetwhenaReceive loadsabyteintotheDATAregisterandsetwhenabyte commandisissued. istransferredfromtheDATAregisterontotheSCSi databus.TheDBRbitwillalsobesetuponissuinga Alinformationtranstersinvolvingotherthandatainfor- Sendcommand. mationareasynchronous.However,iftheinformation phaseinvolvesdatatransfers,theSYNCHRONOUS AsinthecaseofReceivecommands,synchronous TRANSFERregisterwillbeevaluated.Inthiscase,any transferswilloccuronlywhendatatransfersarein- selectedoffsetotherthanzeroresultsinsynchronous volvedandanoffsetotherthanzeroisselected. transfers.TheminimumTransferPeriodforbothtypes oftransfersisdeterminedbythetransferperiodbitsin TRANSFERINFO(20HEX) thissameregister. TheTransferInfocommandisvalidonlywhenCon- nectedasanInitiatorandisusedtosendandreceive SEND(14-17HEX) data,command,status,andmessageinformation. AsinthecaseoftheReceivecommands,therearefour ThefirstREQassertionfollowingconnectionasanIni- Sendcommandswhicharedistinguishedonlybythe tiatorresultsina“servicerequired”interrupt.Thepro- stateofthe/0,T/D,andMSGpinsandthetypeofdata thatistransferred.ThefourSendcommands,alsovalid cessorshouldexaminetheSCSISTATUSregisterto determinethetypeanddirectionofinformationtransfer intheConnected-as-a-Targetstateonly,aretheSend Status,SendData,SendMessageIn,andSend requestedbytheTarget,andthenissueaTransferInfo commandinresponse.WhileanInitiator,the UnspecifiedInfoIncommands.TheSCSIpinstates duringtheSendcommandsaredeterminedbythepar- Am33C93Awillalsogenerateaninterrupteachtimethe ticularcommandasfollows(asserted=1): Targetdevicerequestsanewtypeofinformationtrans- ferphase. Am33C93A 125 | 17 | 101 |  |

nAMD
AsinthecaseoftheSendandReceivecommands, and/orMSGpinsduringaTransfercommandwillalso
whencompletionoftheTransferInfocommandde- terminatethecommandandgeneratea‘terminated”
pendsupontheinternaltransfercounter,theprocessor interrupt.
shouldloadtheTRANSFERCOUNTregisterpriorto
Iaparityerrorisdetectedonareceivedbytebutparity
issuingthiscommand.TheDMAmodeselectbitsinthe
errorcommandterminationisdisabled(HSP=0or
CONTROLregister,theoffsetandtransferperiodbitsin
HHP=0,asappropriate),theAm33C93Awillstillsetthe
theSYNCHRONOUSTRANSFERregister,andthe
PARITYERRORstatusbitintheAUXILIARYSTATUS
SBTbitintheCOMMANDregisterareusedduring
registerbutwillnotterminatethecommandasaresult
TransferInfocommandsjustastheyareduringthe
ofthiserror.
SendandReceivecommands.However,forprocessor
accessoftheDATAregisterduringTransferInfocom-
TRANSLATEADDRESS(18HEX)
mands{(whentheDMAmodeselectbitsarezeroorthe
TheTranslateAddressCommandperformsalogical-
busphaseisotherthanDataphase),behaviorofthe
DATABUFFERREADY(DBR)statusbitisdetermined addresstophysical-addresstranslation.CertainSCSI
bythedirectionofinformationtransferasdefinedbythe commandsinvolvealogicaladdresswhichmaybeup
170 pin.WhenthetransferisfromInitiatortoTarget,the 1032bitsinlength.Whenacommandisdetectedwhich
requiresaddresstranslation,theprocessorcanreload
DBRbitisresetbywritingtotheDATAregisterandis
setwhenthebyteistransferredfromtheDATAregister thelogicaladdressintotheAm33C93ALOGICAL
ontotheSCSIdatabus.Whenthetransferisfrom ADDRESSregisterandthenissuetheTranslate
TargettoInitiator,DBRissetwhenabyteisreceived AddresscommandtohavetheAm33C93Adothecon-
overtheSCSIdatabusandtransferredintotheDATA version.Uponreceivinga“successfulcompletion”inter-
registerandisresetbyreadingtheDATAregister.DBR rupt,theprocessorcanreadtheCYLINDERNUMBER,
isalsoresetwheneveraTransferInfocommandis HEADNUMBER,andSECTORNUMBERregistersto
extractthelogicaladdress.Thediskparameterscon-
issued.
tainedintheTOTALSECTORS,TOTALHEADS,and
ThereareseveralcausesofaTransferInfocommand TOTALCYLINDERSregistersmustalsobevalidbefore
compietion/terminationinadditiontoareset.Justasfor issuingaTranslateAddresscommand.
aSendorReceivecommand,theTransferInfocom-
Ifautomaticcompensationforsparesectorsistobe
mandcanbeterminatedbyissuingasubsequentDis-
connectorAbortcommand.TheAbortcommandwill performedbytheAm33C93A,thenthenumberofspare
sectorspercylinderandtotalnumberofsectorsper
causea“paused/aborted”interrupttobegeneratedaf-
cylindermustalsobeloaded,respectively,intothe
terexecution(leavingtheAm33C93Ainaconnected
state),whiletheDisconnectcommandcausesanimme- HEADNUMBERandCYLINDERNUMBERregisters.A
“terminated”interruptwiloccurifanydivisionoperation
diatedisconnectanddoesnotgenerateaninterrupt.
performedduringthiscommandresultsinanoverflow.
ATransferInfocommandwilleithercompleteorpause
whenthespecifiednumberofbytes(eitherasinglebyte CombinationLevelIlCommands
ormultiplebytesasdefinedbytheSINGLE-BYTE
SELECT-AND-TRANSFER(08AND09HEX)
TRANSFERbitintheCOMMANDregister)hasbeen
TheSelect-and-Transfercommandsgreatlyreducethe
sentorreceived.TheAm33C93Ageneratesa
hostorlocalprocessorinterrupt-handlingburdenby
“successful_completion”interruptonlyafterreceiving
enablingtheAm33C93A’sinternalmicroprocessorto
anotherREQfromtheTargetduringnon-Message-in
managethelow-levelSCSIprotocol,resultinginasfew
informationphasesbutgeneratesa“paused/aborted”
asoneinterruptperSCSIoperation.Select-and-
interruptforMessage-Inphaseswithoutwaitingforan
TranstercommandsareusedwheninanInitiatorrole,
additionalREQ(NotethatwhenthecompletedTransfer
andtypicallyconsistofatleastthefollowingSCSI
InfocommandwasaMessage-Intransferphase,the
phases:(1)SelectionofaTargetdevice;(2)Sendingof
ACKpinwillbeleftassertedbytheAm33C93Ainthe
acommand;(3)Receptionofstatusinformation;and(4)
lastREQ-ACKcycleofthecommand,andthe
ReceptionofaCOMMANDCOMPLETEMessage.
processorisrequiredtoissueaNegateACKoran
ThesecommandsoptionallyconsistofaDataTransfer
AssertATNfollowedbyaNegateACKcommandto
phaseandadditionalMessageTransferphases.
acceptorrejectthemessage).
TheAm33C93AwillupdatetheCOMMANDPHASE
Itaparityerrorisdetectedonadatabytereceivedfrom
registerastheSelect-and-Transfercommand
theSCSIbus(andHSP=1)oronadatabytebyte
executes.Uponcompletionorterminationofthe
receivedfromthehost(andHHP=1),thenthe
command,thelocalprocessorcanreadthisregisterto
Am33C93Awillterminatethecommandand,forSCSI
determinewheretheSCSIoperationstopped.
parityerrors,willleaveACKasserted(toalsohaltthe
Target).Inthiscasea“terminated”interruptisgener- ThetwoSelect-and-Transfercommands_differfrom
ated.Finally,anegationoftheBSYsignal(i.e.theTar- eachotheronlybywhetherornottheATNpinisas-
getsuddenlydisconnects)oratransitioninthe70,T/D, sertedduringtheSelectionphase.Theabilitytoassert
126 Am33C93A

AMDn
ATNduringSelectionsupportstheSCSIMessage AftertheCommandphase,theAm33C93Aexpects
ProtocolwhichcallsforanIDENTIFYMessageOut eitheraDataInphase,DataOutphase,Statusphase,
phasefollowingtheSelection.WhenexecutingaSelect orMessageInphase.IftheTargetisrequestinga
W/ATN-and-Transfercommands,theAm33C93A MessageInphase,apendingdisconnectionis
expectstheTargettorequestaMessageOutphase assumed.TheAm33C93Athereforeexpectstoreceive
immediatelyfollowingselection,whereasforaSelect eitheraSave-Data-Pointermessage(hex02)oraDis-
'W/OATN-and-Transfercommand,itexpectstheTarget connectmessage(hex04).Ifeithermessageisincor-
todirectlyenterCommandphase.TheSelect-and- rect,orifadifferentmessageisreceived,a‘terminated”
Transfercommands,moreover,supportGroup0 interruptwillbegeneratedtoalerttheprocessorofthat
(6-byteCDB),Group1(10-byteCDB),andGroup5 factandtoallowthemessagetobereadfromtheDATA
(12-byteCDB)SCSIcommands. register.A“terminated”interruptwillalsobegenerated
iftheTargetdisconnectsbeforesendingtheDisconnect
WhenaSelect-and-Transfercommandisissued,the message.WhenacorrectSave-Data-Pointermessage
Am33C93AarbitratesforthebusandselectsaTarget isreceived,a‘paused/aborted”interruptisgenerated
justasduringaSelectcommand.IftheTargetdoesnot
andtheSelect-and-Transfercommandterminatedto
respondbeforeatimeoutoccurs,theSelect-and- allowtheprocessortosavetheSCSIdatapointer.
Transtercommandhaltsanda“terminated”interruptis However,itaDisconnectmessageisreceived,the
generated.FailuretocompletetheSelectionphaseis COMMANDPHASEregisterwillbeupdatedtohex42
alsoindicatedbythefactthattheCOMMANDPHASE
andcommandexecutioncontinues.
registercontainsallzeros.IftheSelectionissuccessful,
nointerruptisgenerated,buttheCOMMANDPHASE WhentheactualTarget-disconnectiondoesoccur,the
registerwillbesettoahex10. COMMANDPHASEregisterisupdatedtohex43andif
theIDIbitisset,theAm33C93AterminatestheSelect-
AftercompletingtheSelectionphase,theAm33C93A
and-Transfercommandbygeneratingan85Hinterrupt.
beginsaninformationtransferphase.IfATNhasbeen
However,iftheIDIbitisreset,theninsteadthe
asserted(i.e.aSelectW/ATN-and-Transfercommand
'Am33C93Asitsinanidlestate,waitingfortheTargetto
wasissued),theAm33C93AexpectstheTargetto
reconnect.IfadifferentTargetdeviceReselectsthe
respondwithaMessageOutphase.Ifthefirst
'Am33C93A,a“terminated”interruptisgenerated.How-
informationphaserequestisotherthanaMessageOut
ever,iftheoriginalTargetReselectstheAm33C93A,no
request,theAm33C93Awillterminatethecommand
interruptisgeneratedandtheCOMMANDPHASE
andgeneratea“terminated”interrupt.However,when
registerissettohex44.
theTargetdoesrequestaMessageOulphase,the
Am33C93Awillrespondbyautomaticallysendingan FollowingtheoriginalTargetReselection,the
IDENTIFYMessage.Thissinglebytemessageisofthe AmM33C93AexpectsaMessageInphasewhichshould
binaryform:1r000ttt,wherer=1iftheENABLE consistoftheTargetsendinganIDENTIFYMessage.
RESELECTIONbitintheSOURCE1Dregisterisequal Thissingle-bytemessageshouldbeofthebinaryform:
to1,andtttistheencodedTargetLOGICALUNIT 10000ttt,wherefitistheTargetLUN.Ifthedata
NUMBERcontainedintheTARGETLUNregister. receivedbytheAm33C93AisdifferentortheTarget
OncetheIDENTIFYMessagehasbeensent,the LUNspecifiedinthisbytedoesnotmatchthecontents
Am33C93AwillsettheCOMMANDPHASEregisterto oftheTARGETLUNregister,a“terminated”interruptis
hex20. generatedandtheMessagebytemaybeexaminedby
theprocessor.AcorrectIDENTIFYMessageInphase
FollowingtheMessageOutphase(orSelectionphase
resultsintheCOMMANDPHASEregisterbeing
whenATNwasnotassertedduringSelection),aCom-
updatedtohex45.
mandphaseisexpectedbytheAm33C93A.Again,and
throughouttheentireSelect-and-Transfercommand AftertheIDENTIFYMessageisreceivedfromthe
execution,iftheTargetrequestsanunexpectedinfor- TargetorimmediatelyaftertheCommandOutphase
mationphasetype,theAm33C93Aterminatesthecom- (whenthereisnodisconnection),aDataInphase,Data
mandandgeneratesa‘terminated”interrupt.Ifthe Outphase,orStatusphaseshouldoccur.Ifthe
Commandphaseisrequestedinthissituation,the TRANSFERCOUNTregistercontainsanynon-zero
Am33C93AwillextracttheSCSIcommandfromthe value,thentheAm33C93AwillexpectaDataTransfer
internalCOMMANDDESCRIPTORBLOCKregisters phase.IfAdvancedFeaturesareenabled,thenthe
andsendthe6-,10-,or12-bytesofcommand DPDbitwillbeexaminedtoverifythecorrectdata
informationasdeterminedbyitsevaluationoftheSCS! direction.Ifthedatadirectionisincomect,thena“termi-
commandcodeintheCDB1register.TheCOMMAND nated”interruptisgenerated.Inthisphase,the
PHASEregisterisset1ohex30beforethefirst AM33C93AwillusetheTRANSFERCOUNTregisterto
Commandbyteissentandthenincrementswitheach determinethenumberofbytestobetransferred,andall
bytetransferred,sothatfora12-byteCDBcommand host-sideDATAregisteraccesseswillbeaccomplished
theCOMMANDPHASEregisterwillcontainhex3C viathemethodselectedbytheDMAmodeselectbitsin
whenalibytesoftheCDBhavebeentransferred. theCONTROLregister.Whentheinternalcounter
Am33C93A 1-27

nAMD
Command
reacheszero,theDataTransferphaseiscompleteand
Phase Meaning
theCOMMANDPHASEregisterissettohex46.
00 NoSCSIbusdevicehasbeenselected.The
Notethatanynumberofdisconnection/reconnection
Am33C93Aisinthedisconnectedstate.
cyclesmayoccurduringtheDataTransferphaseso
10 TheTargethasbeenselected.The
longastheyareaccomplishedaccordingtothedefined
Am33C93Aisnowintheconnectedasan
messageprotocol.TheCOMMANDPHASEregisterwill
Iniiatorstate.
cyclethroughthedisconnectphases(41-45)witheach
20 AnIdentitymessagehasbeensenttothe
disconnectionandsubsequentreconnectionuntilallof
Target.
thedatahasbeentransferredandtheDataTransfer
| phaseiscomplete. | 30 | Commandphasehasstarted,nobytes transferred. AStatusphaseisexpectedbytheAm33C93Afollowing 3x Commandphase,xbyteshavebeen theDataTransferphase(orinsteadoftheData transferred. TransferphasewhentheTRANSFERCOUNTregister 41 Save-Data-Pointermessagereceived. containsavalueofzero).AtthestartoftheStatus 42 Disconnectmessagerecaived,busnotfree. phase,theCOMMANDPHASEregisterisloadedwith |
| --- | --- | --- |
| hex47.UponcompletionoftheStatusphase,the | 43 | Targethasdisconnected(SCSIbusfree) COMMANDPHASEregisterwillbeupdatedtohex50, followingasuccessfultransferofaDisconnect message.TheAm33C93Aisnowinthe andthereceivedstatusbyteisstoredintheTARGET disconnectedstate. LUNregisterwhereitcanbereaduponcompletionof |
| thecommand. | 44 | TheAm33C93Ahasbeenreselectedbythe TargetwhoseSCSIbusIDmatchesthevalue Followingcompletionofthestatus-bytetransfer,aMes- intheDESTINATIONIDregister.The sageInphaseisexpected.TheAm33C93Aexpectsthe Am33C93Aisnowintheconnectedasan TargettosendaCOMMANDCOMPLETEMessage Initiatorstate. |
| {hex00)toindicatethattheSCSIcommandoperation | 45 | TheAm33C93Ahasreceivedanidentifymes- hasbeencompleted.AftertheAm33C93Areceivesthis sagefromtheTargetwhoseLogicalUnit COMMANDCOMPLETEMessage,theCOMMAND NumbermatchesthevalueintheTARGET PHASEregisteradvancestohex60,andittheEDIbitis LUNregister. |
| reset,a“successfulcompletion”interruptisgenerated. | 46 | Thenumberofbytesspecifiedinthe TheprocessorshouldthenreadtheTARGETLUN TRANSFERCOUNTregisterhavebeentrans- registertoexaminetheTargetstatus.Anadditional ferredtoffromtheTargetduringaDataOut/in interruptwillthenoccurwhentheSCSIbusgoestothe phase. |
| BusFreestate,orwhenanotherREQisassertedto | 47 | TheTargethasbegunaReceiveStatusphase. beginaninformationtransferphase(asinSCSIlinked 50 TheAm33C93Ahassuccessfullyreceiveda ccommands).IftheEDIbitisset,the“successfulcom- StatusbytefromtheTargetandstoreditinthe pletion”interruptwillbesuppresseduntiltheTarget TARGETLUNregister. disconnectsfromtheSCSIbus. 60 TheAm33C93Ahassuccesstullyreceiveda CommandCompletemessagefromtheTar- AtanytimeduringexecutionoftheSelect-and-Transfer get. commands,anabnormalorunexpectedconditionwill causetheAm33C93Atoterminatethecommand,set theappropriatestatusqualifiers,andgeneratea“termi- A“ResumeSelect-and-Transfer’commandisassumed wheneveranormal“Select-and-Transfer”commandis nated”interrupt.Iftheterminationoccurredduringan informationtransferphase,theAm33C93Awillbeleftin issuedwhiletheAm33C93AisintheConnected- Initiatorstate.Whenthe“Resume”isissued,the aConnected-as-an-Initiatorstate(unlesstermination Am33C93AexaminestheCOMMANDPHASEregister wasduetoasuddenTargetdisconnection).Command 1odeterminewheretorestarttheSelect-and-Transfer terminationduringanyotherphasewillresultinthe commandexecution.Thisfeature,inconjunctionwith Am33C93AbeinginaDisconnectedstate.Transfer theINTERMEDIATEDISCONNECTINTERRUPT commandsmaybeusedtohandletheexceptionby enabled,allowssupportofmulti-threadedoroverlapped transferringmessageswiththeTarget. 1/0ontheSCSIbus. Thefollowingtablesummarizesthepossiblevaluesthat Thefollowingtablebrieflydescribesthevalidsettingsof theCOMMANDPHASEregistercantakeduringthe theCOMMANDPHASEregisterwhenresumingaSe- Select-and-Transfercommands,andtheirmeanings relativetocommandtermination: lect-and-Transfercommand: 128 Am33C93A |

AMDa
3.Reselect-and-Receivecommand,EDI=1,and
Command
| Phase | Meaning »Reselectionphase; 10 ResumeafterTargetselectioniscomplete. +SendIdentifyMessageIn; 20 ResumeafterIdentifymessageout.Gommand phaseisexpected;animpliedNegateACK »ReceiveDataOutphase; oceurs. =ChaintoSend-Status-and-CommandComplete; 30 ResumewhenCommandphasehasbegun 4.Reselect-and-Sendcommand,EDI=1,andSCC=0: (REQasserted). +Reselectionphase; 41 ResumeafterCommandphaseorafterSave- Data-Pointermessage.Data,Status,or »SendIdentifyMessageIn; MessageInphasesareexpected.Animplied »SendDataInphase; NegateACKoccurs. »ChaintoSend-Status-and-Command-Complete; 42 ResumetocompleteDisconnectMessageIn; animpliedNegataACKoccurs. 5.Reselect-and-Receivecommand,EDI=1,and ResumeafterreselectionbyaTarget. SCC=1: &RResumetotransfermoredatainadatatrans- +Reselectionphase; ferphase.MayexpectStatusorMessageInas »SendIdentifyMessageIn; well.AnimpliedNegateACKoccurs. +ReceiveDataOutphase; 46 Resumeafterthedataphasehasbeen completed,expectingStatusphaseoraSave- »ChaintoSend-Disconnect-Message; Data-Pointer/DisconnectMessageInphase. 6.Reselect-and-Sendcommand,EDI=1,andSCC=1: AnimpliedNegateACKdoesNOToccur. +Reselectionphase; 50 ResumetocompleteaStatusphase;an «SendIdentityMessageIn; impliedNegateACKoccurs. | SCC= |
| --- | --- | --- |
| 60 | ResumetocompleteaCommandComplete messagefromtheTarget;animpliedNegate «ChaintoSend-Disconnect-Message. ACKoccurs. IfthereselectionattempttimesoutduringaReselect- and-Transfercommand,ATNisassertedandHA=1,or RESELECT-AND-TRANSFER(0AAND0BHEX) ifaparityerrorisdetectedonaincomingdatabyte(and TheReselect-and-Transfercommandsincludethe HSP=1orHHP=1,dependingondatadirection),the Reselect-and-Receive-DataandtheReselect-and- commandwillbeterminatedandtheappropriatestatus Send-Datacommands.Thesecommandscausethe willbeset.Inthiscase,theCOMMANDPHASEregister Am33C93AtoexecutecertaincommonSCSIbus shouldbeevaluatedtodeterminethelastsuccessfully phasesequencesasaTargetfollowingaReselection completedphase.Ifnoneoftheseconditionsoccurs,all phase.Thesephasesaredeterminedbywhich phasescompletenormally,andifEDI=0,thena“suc- commandissent,andthesettingoftwobits:theEDIbit cessfulcompletion”interruptwouldbegeneratedatthis intheCONTROLregister;andtheSCCbitinthe point.However,ifEDI=1,nointerruptisgeneratedand DESTINATIONDregister.TheSCSIbusphase commandchainoccurs(asdescribedabove). sequencesaresummarizedbelow.Refertothecom- manddescriptionsoftheSend-Status-and-Command- Thefollowingtablesummarizesthepossiblevaluesthat CompleteandSend-Disconnect-Messagecommands theCOMMANDPHASEregistercantakeduringthe fordetailsonthosesequences. Reselect-and-Transfercommands,andtheirmeanings relativetocommandtermination.Seeothercommand 1.Reselect-and-Receivecommand,EDI=0,and descriptionsforadditionalvaluesthatcanoccurwhen SCC=dontcare: commandchainingisused. «Reselectionphase; Command »SendIdentifyMessageIn; Phase Meaning +ReceiveDataOutphase; 00 NoSCSIbusdevicehasbeenreselected.The +Completioninterrupt. Am33C93Asinthedisconnectedstate. | +SendDataInphase; |
| 2.Reselect-and-Sendcommand,EDI=0,and | 10 | TheAm33C93Ahassuccessfullyreselected SCC=don'tcare: theInitiator.TheAm33C93Aisnowinthe connectedasaTargetstate. +Reselectionphase; 20 TheIdentifymessagehasbeensuccessfully «SendIdentifyMessageIn; senttotheInitiator. |
| +SendDataInphase; | 46 | :lr:e;equesleddatatransferhasbeencom- +Completioninterrupt. : Am33C33A 1-29 |

nAMD
A"ResumeReselect-and-Transfer'commandisas- containsa6-,10-,or12-bytereadcommandcode,then
sumedwheneveranormal“Reselect-and-Transfer” theAm33C93Awilltemporarilysuppresstheinterrupt
commandisissuedwhiletheAm33C93Aisinthe andchain1obeginexecutionofaSend-Disconnect-
Connected-as-a-Targetstate.Whenthe“Resume”is Messagecommand.Aninterruptwillthenbegenerated
issued,theAm33C93AexaminestheCOMMAND aftercompletionofthiscommand,whichnormallywould
PHASEregistertodeterminewheretorestartthe indicateatransitiontothebusfreecondition.Referto
Reselect-and-Transfercommandexecution.This theSend-Disconnect-Messagecommanddescription
feature,inconjunctionwiththecapabilitytochainto formoredetails.
othercombinationcommands,allowslongerSCSIbus
Ifduringexecutionthemessageorcommandinforma-
sequencestobeexecutedbyasinglecommand.
tionreceivedfromtheInitiatorisinvalid,theimplied
Thefollowingtablebrieflydescribesthemeaningofthe receivecommandwillbeterminatedandtheappropri-
COMMANDPHASEregisterwhenresuminga atestatusreported.Inthiscase,theCOMMAND
Reselect-and-Transfercommand: PHASEregistershouldbereadtodeterminewhich
phaseoftheWait-for-Select-and-Receivecommand
Command
waslastcompletedbeforetheerrorconditionoccurred.
Phase Meaning
ACOMMANDPHASEhexvalueofhex10indicates
thattheAm33C93Awassuccessfullyselected.Ahex
10 ResumeafterInitiatorreselectioniscomplete;
startwithIdentityMessageOut. valueof20indicatesthatamessagewasreceivedfrom
| 20 | ResumeatterIdentifymessageout;startwith | theInitiator,andwhentheAm33C93Abeginsreceiving datatransferphase.fTRANSFERCOUNTis commandbytes,theCOMMANDPHASEissettohex zero,nodatatransferphaseoccurs.Ineither 30andincrementswitheachbytereceived(toa case,achaintoanothercombinationcom- maximumof3Cfora12-byteCDBcommand). mandcanoccurifenabled. Thefollowingtablesummarizesthepossiblevaluesthat theCOMMANDPHASEregistercantakeduringthe WAIT-FOR-SELECT-AND-RECEIVE(0CHEX) Wait-for-Select-and-Receivecommand,andtheir TheWait-for-Select-and-Receivecausesthe meaningsrelativetocommandtermination.Seeother Am33C93AtoidieuntititisselectedbyanInitiator,at commanddescriptionsforadditionalvaluesthatcan whichtimetheAm33C93AwillentertheTargetmode occurwhencommandchainingisused. andmessageandcommandinformationwill “automaticallyberequested.Asanoption,the Command |
| --- | --- | --- |
| Am33C93Amaybeprogrammedtodisconnectwhena | Phase | Meaning SCSIreadcommandisreceivedwhileexecutinga |
| Wait-for-Select-and-Receivecommand.Useofthis | 00 | TheAm33C3Ahasnotbeenselected.The Am33C93Asinthedisconnectedstate. commandthereforeeliminatestheinterruptswhich 10 TheAm33C93Ahasbeensuccessfully normatlyoccurafterselectionandaftereach selectedbytheInitiator.TheAm33C93Ais subsequentSCSIbusphase,andresultsinveryshort nowintheconnectedasaTargetstate. bus-connecttimeduringSCSIreadcommands. 20 TheIdentitymessagehasbeensuccessfully receivedfromtheInitiator. IfATNwasassertedbytheInitiatorduringtheselection 30 TheAm33C93Ahasbeguncommandphase phase,theAm33C93Awillfirstexecuteanimplied bysettingtheSCS!busphasesignalsand “ReceiveMessageOut"commandtogettheIdentify assertingREQ. messagefromtheInitiator,beforecontinuingonwith 31 TheAm33C93Ahastransferredone theimplied“ReceiveCommand”toreceivetheSCSI commandbytefromtheInitiator.TheSCSI commandinformation.TheSCSIcommandinformation STATUSmayindicatetheneedforthehostto (CDB)willbestoredintheCDBregisters(hex loadthecommandsizeintotheOWNID addresses03toOF),andifavalidIDENTIFYmessage register. |
| isreceived,itwillbesavedintheTARGETLUNregister | 3x | TheAm33C93Ahastransferredxcommand bytesfromtheInitiator (hexaddressOF). Thenumberofcommandbytes requestedbytheAm33C93AisdeterminedbytheSCSI groupcodeinthefirstbyteoftheCDB. A“ResumeWait-for-Select-and-Receive”commandis assumedwheneveranormal“Wait-for-Select-and- AftertheAm33C93Aisselectedandreceivesallvalid Receive”commandisissuedwhiletheAm33C93Aisin commandandmessageinformation,a“successful theConnected-as-a-Targetstate.Whenthe“Resume” completion”interruptwillnormallybegeneratedtoallow isissued,theAm33C93AexaminestheCOMMAND thelocalprocessortoreadoutandinterprettheSCSt PHASEregistertodeterminewheretorestarttheWait- CDB.However,bysettingtheEDIbitpriortoissuinga for-Select-and-Receivecommandexecution.This |
| Wait-for-Select-and-Receive | command, feature,inconjunctionwiththecapabilitytochainto Am33C93Aisenabledtoperformanautomatic othercombinationcommands,allowslongerSCSIbus disconnectwhenaSCSIreadcommandisreceived. sequences1obeexecutedbyasinglecommand. Therefore,whenEDI=1andthe1stCDBbytereceived 1-30 Am33C93A | the |

AMDn
Thefoliowingtablebrieflydescribesthemeaningofthe portionofWait-for-Select-and-Receivethenoccurs
COMMANDPHASEregisterwhenresumingaWait-for- 1ofetchthenextCDBfromtheinitiator.Am33C93A
Select-and-Receivecommand: commandexecutionproceedsasdescribedforthat
command.
‘Command
Phase	Meaning	3.CDB12bit0=1,bit1=1:ThestatusbyteinCDB11is.
sent,followedbyaLinkedCommandCompletewith
10 ResumeafterselectionbytheInitiatoriscom-
Flagmessage(OBhex).Achaintothecommand
plete;startwithIdentifyMessageOutifATNis
fetchportionofWait-for-Select-and-Receivethen
asserted,otherwise,startwithcommand
occurstofetchthenextCDBfromtheInitiator.
phase.
Am33C93Acommandexecutionproceedsasde-
20 Resumeafteramessageout;checkthere-
caivedmessageintheTARGETLUNregister scribedforthatcommand.
foravalidIdentifymessage.
ASend-Status-and-Command-Completecommand
30 ResumeafterIdentifymessageout.Startwith
maybeterminatedbyATNassertedwhenHA=1,or
commandphase.
whenaDisconnectorResetcommandisissued.
3 ResumeaftertheAm33C93Ahastransferred1
commandbytefromtheInitiator.Thisresume
Thefollowingtablesummarizesthepossiblevaluesthat
pointisusedonlywhenanunknowngroup
theCOMMANDPHASEregistercantakeduringthe
codehasbeendetectedinAdvancedMode,
Send-Status-and-Command-Completecommand,and
andthecommandsizehasbeenloadedinto
theOWNIDregister. theirmeaningsrelativetocommandtermination.See
othercommanddescriptionsforadditionalvaluesthat
canoccurwhencommandchainingisused.
SEND-STATUS-AND-COMMAND-COMPLETE
(0DHEX) Command
Phase Meaning
TheSend-Status-and-Command-Completecommand
isvalidintheTargetrole,andisusedtocompletea
00 Nooperationoccurred;typically,ATNwas
SCSIoperationbytransferringtheappropriatestatus
foundtobeasserted.
informationtotheInitiatorpriortodisconnectionfrom
50 Statusphasetransfercompleted.
| theSCSIbus.ThiscommandalsosupportslinkedSCSI | 60 | CommandCompletemessagetransfercom- operationsbyoptionallyallowingalinkedcommand- pleted. |
| --- | --- | --- |
| completemessagetobesentafterthestatusis | 61 | LinkedCommandCompletemessagetransfer transferred.Linkedcommandcompletemessagesare completed. controlledbytheCDB12registerwithbitsthatcorre- spondtothestandardlinkedcommandcontrolbitsin A"ResumeSend-Status-and-Command-Complete” theCDB. commandisassumedwheneveranormal“Send- Status-and-Command-Complete”commandisissued BeforeaSend-Status-and-Command-Completecom- whiletheAm33C93AisintheConnected-as-a-Target mandisissued,theCDB11registermustbeloadedwith state.Whenthe“Resume”isissued,theAm33C93A astatusbytewhichwillthenbetransferredacrossthe examinestheCOMMANDPHASEregistertodetermine SCSIbus.Also,thelinkcontrolbitsfromthecurrent wheretorestarttheSend-Status-and-Command- CDBmustbeloadedintotheCDB12registertoensure Completecommandexecution.Thisfeature,in thatthecorrectsequenceoccurs.Notethatthebits conjunctionwiththecapabilitytochaintoothercombi- usedbytheAm33C93Aareidenticalinmeaningtothe nationcommands,allowslongerSCSIbussequences SCSIstandardlinkcontrolbits.Thehostprocessormay 10beexecutedbyasinglecommand. simplyloadthecontrolbytefromthecurrentSCSIcom- mandintoCDB12togetthecorrectfunction.Asthe Thefollowingtablebrieflydescribesthemeaningofthe commandexecutionprogresses,theCOMMAND COMMANDPHASEregisterwhenresumingaSend- PHASEregisterwillbeupdatedtoindicatethelast Status-and-Command-Completecommand: phasecompleted. Command Phase Meaning Thepossiblesequencescausedbythiscommandare |
| asfollows: | 50 | Resumeafterstatusphase.Startwith commandcompletemessage.Maychainto 1.CDB12bit0=0,bitt=don'tcare:Thestatusbytein commandfetchifcommandedtodoso. CDB11issent,followedbyaCommandComplete message(00hex).A“successfulcompletion” SEND-DISCONNECT-MESSAGE(0EHEX) interruptnowoccurs. TheSend-Disconnect-MessagecommandisaTarget- 2.CDB12bit0=1,bit1=0:ThestatusbyteinCDB11is rolecommandwhichmaybeusedtodisconnectfrom sent,followedbyaLinkedCommandComplete theSCSIbusatanytimeduringaSCSIcommand message(OAhex).Achaintothecommandfetch Am33C93A 1-31 |

nAMD
sequence.ThiscommandconsistsofsendingaDiscon- Thefollowingtablesummarizesthepossiblevaluesthat
nectmessagebyte,followedbyphysicaldisconnection theCOMMANDPHASEregistercantakeduringthe
fromthebus(SCSIbusfree).Aninterruptisgenerated Send-Disconnect-Message,andtheirmeaningsrelative
onlyaftertransitiontobusfreeoccurs.Asanoption,a tocommandtermination.Seeothercommanddescrip-
Save-Data-Pointermessagewillautomaticallybesent tionsforadditionalvaluesthatcanoccurwhen
beforetheDisconnectmessagewheneverthe1Dlbitis. commandchainingisused.
setpriortoissuingthiscommand.
Command
Phase Meaning
TheCOMMANDPHASEregisterisupdatedduring
executionoftheSend-Disconnect-Messagecommand
00 Nooperationoccurred;typically,ATNwas
toindicatebusphasestatus.AfteraSave-Data-Pointer
foundtobeasserted.
| messageissent,theCOMMANDPHASEwillbesetto | 41 | TheSave-Data-PointermessagewasIrans- 41H.AftertheDisconnectmessagetransfer,thisregis- ferred. |
| --- | --- | --- |
| terwillbeupdatedto42H,andafterdisconnectionthe | 42 | TheDisconnectmessagewastransferred. |
| COMMANDPHASEregisterwillcontaina43H. | 43 | ThebusfreestateoocurredaftertheDiscon- nectmessagewastransferred.The ASend-Disconnect-Messagecommandmaybetermi- Am33C93Aisnowinthedisconnectedstate. natedbyATNassertedwhenHA=1,orwhenaDiscon- nectorResetcommandisissued. |
ELECTRICALCHARACTERISTICS
ABSOLUTEMAXIMUMRATINGS
VoltageonanypinwithrespecttoGND~~0.5V10+7.0V
Operatingtemperature 01070deg.C
Storagetemperature 5510+125deg.C
Powerdissipation 400MW
InputStaticDischargeProtection 2KV
StressesabovethosefistedunderABSOLUTEMAXIMUM
RATINGSmaycausepermanentdevicefailure.Functionality
atorabovetheselimitsisnotimplied.Exposuretoabsolutely
maximumratingsforextendedperiodsmayaffectdevice
reliability.
DCOPERATINGCHARACTERISTICS
Ta=01070°C,VCC=45V+0.25V,GND=0V
| Symbol | Characteristic | Min | Max | Units. | Conditions |
| --- | --- | --- | --- | --- | --- |
| nw | InputLeakage | 10 | nA | VIN=.410VCC |  |
| oLt | SCSIOutputLeakage(Inactive) | 50 | RA | VOUT=.510VCC |  |
| o2 | OutputLeakage(Tri-State) | 10 | kA | VOUT=.4toVCC |  |
| VIH | InputHighVoltage | 20 | v |  |  |
| VIL | InputLowVoltage | 08 | v |  |  |
| VIHYS | SchmittTriggerInput Hysteresis(AllSCSIPins) | 0.2 | v |  |  |
| VOH | OutputHighVoltage | 24 | v | 10=~400pA |  |
| voLt | SCSIOutputLowVoltage | 05 | v | 10=48.0mA |  |
| voL2 | OutputLowVoltage(AllOthers) | 0.4 | v | 0=40mA |  |
| icc | SupplyCurrent 1-32 Am33C93A | 20 | mA | Ta=+25°C |  |

AMDn
SWITCHINGTESTCIRCUIT
Fromoutput V-
inciortost T
| PinsoftheDevice | e, | I, | I, |
| --- | --- | --- | --- |
| INTRQ,RE,WE | 100pF | 4mA | 400uA |
| D0-D7,DP | 100pF | 4mA | 400uA |
| DACK,DRQ | 100pF SD0-SD7,SDP | 4mA | - |
| BSY,SEL.10,C/D | 100pF MSG,ATN,REQ,ACK *Actualcapacitancemayvary£20%. | 20mA | - |
SWITCHINGTESTWAVEFORM
AltheOpenDrains
TSSV
AllOtherPins
1svX Xisv
Am33C93A

‘b.lAMD
TIMINGCHARACTERISTICS Where:
Timingcharacteristicsarevalidovertheentireoperat-
Teycistheinternalclockcycletime;
ingtemperature(0to70°C)andvoltage(4.75t05.25V)
ranges,andarereferencedtoandfromalowvoltageof
TekinistheperiodoftheclockattheCLKinput;
0.8voltsandahighvoltageof2.0Volts.Alloutputsare
assumedtohavealoadcapacitanceof50picofarads. DIVISORistheclockdivisorselectedintheOWN1D
register.
Manyofthetimingparametersthatfollowaredefinedin
1ermsofaninternalclockcycletimethatisdetermined Forexample,witha16MHzclockinputtotheAm33C93A,
bytheinputclockandtheclockdivisorselectedinthe theclockdivisorselectedwouldbe4.Therefore,thevalue
OWNIDregister.ThiscycletimeiscalculatedasofTeyewouldbe:
follows:
62.5ns4
Tekin«DIVISOR Teyo=—"
—=125ns
Teye=——
2
Processor/DMAInterface
CLK
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tep | ClockPeriod ns | 16MHz | 625 | 125 |
| 20MHz | 50.0 | ns |  |  |
| ton | ClockHigh ns | 16MHz | 280 |  |
| 20MHz | 20.0 | ns |  |  |
| oL | ClockLow ns | 16MHz | 28.0 |  |
| 20MHz | 200 top | ns |  |  |
| CLK | 24V4V | )\ | /—__JX tcH je——tcL 1ess01A |  |
MR
| Symbol | Characteristic Units | Min | Max |
| --- | --- | --- | --- |
| [, | MRPulseWidth | 1 | us |
| MR | \ | £ |  |
MR
ssaorer
1-34 Am33C93A

AMDn
PROCESSORWRITE—INDIRECTADDRESSINGMODE
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tawwt | A0ValidtoWELow | 0 | ns |  |
| terwt | TSLowtoWELow | 0 | ns |  |
| tye | WEPulseWidth | 120 | ns |  |
| tovw | DataValidtoWEHigh | 70 | ns |  |
| [ | WEHightoA0Invalid | 0 | ns |  |
| [ | WEHigh1oTSHigh | 0 | ns |  |
| tror | WEHigh1oDataInvalid | 0 | ns |  |
| [ | WEHightoWEorRELow tAVWL—>\| ‘_¥'WHAI Ao —toLwL etWHCH; cs Twe TWHWL weT\ S— tDVWH—>1 tWHDI o007XOQQOQOUOOCOORK_—————RAXA000O000 | 100 | ns |  |
118530154
PROCESSORREAD—INDIRECTADDRESSINGMODE
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tavaL | A0ValidtoRELow | 0 | ns |  |
| ton | TSLowtoRELow | 0 | ns |  |
| tae | REPulseWidth | 180 | 10000 | ns |
| taov | RELowtoDataValid | 180 | ns |  |
| tacn | TEHightoTSHigh | 0 | ns |  |
| taor | TEHightoDataInvalid | 10 | 40 | ns |
| temnL | REHightoREorWELow | 100 | ns |  |
| 1 | REHightoA0Invalid TAVRL—> -———%tRHAI Ao 7=1CLRL [tRHCHj cs | 0 | ns |  |
| tRE | tRHRL RE \ | \| |  |  |
SL
tRLDV— tRHDI
oo-070000000000RACA0000OCN00
118530168
Am33C93A

aAMD
PROCESSORWRITE—DIRECTADDRESSINGMODE
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| [ | ADDRValidtoALELow ns | 40 |  |  |
| ALELowtoADDRInvalid | [ | ns [ |  |  |
| twl | ALELowtoWELow | 90 | ns |  |
| o | bELowtoWELow ns | 0 |  |  |
| WEPulseWidth | 120 twe | ns |  |  |
| tovwn | DataValidtoWEHigh ns | 70 |  |  |
| [ | WEHightoTSHigh ns | 0 |  |  |
| ot | WEHightoDataInvalid ns | 0 |  |  |
| [ | WEHightoWEorRELow ns | 100 |  |  |
ALE
_\f—’—toLwL 1WHCH
[ALWL	tWE	‘WHWL:q
|S
TAVAL tALAI
tDVWH tWHDI
D0-D7
KOOISR0000KXXX
X
18830178
PROCESSORREAD—DIRECTADDRESSINGMODE
| Symbol | Characteristic Units | Min | Max |
| --- | --- | --- | --- |
| ta | ADDRValidtoALELow | 40 | ns |
| taa | ALELowtoADDRInvalid | 0 | ns |
| tan | ALELowtoRELow | 30 | ns |
| [ | TSLowtoRELow ns | 0 |  |
| toe | REPulseWidth | 180 | 10000 ns |
| taov | RELowtoDataValid | 180 | ns |
| tarch | REHightoTSHigh ns | 0 |  |
| [ | REHightoDataInvalid | 10 | 40 ns |
| [ | REHightoREorWELow T\ _{_—’—tCLRL tRHCH | 100 | ns |
| —tALRL | tRE | tRHRL )S\| tAvAL\|talal tRLOV—>\| Do-D7 | f |
11853058
1-36 Am33C93A

AMDa
DMAWRITE
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| o | DATKLowtoWELow | 0 | ns |  |
| toan | DACK,WELowtoDRQHigh | 7% | ns |  |
| twa | WEPulseWidth | 50 | ns |  |
| [ | WEHightoWELow | 100 | ns |  |
| [— | DataValidtoWEHigh | 25 | ns |  |
| Yo | WEHightoDACKHigh | 0 | ns |  |
| Yol | WEHightoDATAInvalid | 5 | ns |  |
| toraL | DACKHightoDRQLow tDLOH | 0 | ns |  |
| praoun~\ | £ | \ |  |  |
| _7 | tWHDH !DLWL 1DHAL: | —e |  |  |
11853019
NOTE:ExternalloadonDRQ&DACKisassumedtobe1KQ.
DMAREAD
| ‘Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| [ | DACKLowtoRELow | 0 | ns |  |
| touan | DACK,RELowtoDRQHigh | 75 | ns |  |
| ta | REPulseWidth | 80 | ns |  |
| taaL | REHightoRELow | 100 | ns |  |
| taov | RELowtoDataValid | 70 | ns |  |
| tamon | REHightoDACKHigh | 0 | ns |  |
| oo | REHightoDATAInvalid | 5 | 40 | ns |
| tonaL | DACKHightoDRQLow | 0 | ns |  |
| taoL | DRQHightoDRALow !DLoH | 100 | ns |  |
| DRa©UD | \ | J——tRupL% |  |  |
| !DLRL | tRHDH DACK(IN) | !DHaL |  |  |
VA
'RD !RHRL
RE &t——‘
|
tRLOV-
tRHD}
Do-D7
@ROOOXOUHXRHKNNXK
NOTE:ExternalloadonDRQ&DACKisassumedtobe1K.
18530208
Am33C93A 1-37

aAMD
DIRECTBUFFERACCESSWRITE
| Symbol | Characteristic Max Units | Min |
| --- | --- | --- |
| tonsy | DRQHightoRCSLow ns | 0 |
| towy | RCSLowtoWEValid ns | 0 20 |
| two | WEPulseWidth ns [ WELowtoDataValid 50 ns | Teyc-20 |
| tmor | WEHightoDataInvalid ns | 20 |
| [y | WEHightoWELow ns | Teyc-20 |
| tausn | DRQLowtoACSHigh 10°Teye ns | 8'Teye |
| e | RCSHightoWEInvalid ns | 0 100 |
| o | RCSLowtoWELow ns | 60 |
| towe | DRQLowtoWELow(1) ns taLSH— tQHSL | [ |
| DRQ(IN) | tsLwL | { |
| tsLwy | tawL™ \ Y2 TGS(ouT) two LWHWL—\| | tshwi |
| oun———\ | 7 | \ /S we tWLDV tWHDI 0o-07XXXXXXOOONN RORRRRRHAXRNONNR) |
118830214
DIRECTBUFFERACCESSREAD
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| DRQHightoACSLow | 0 | ns tons |  |  |
| tshy | RCSLowtoREValid | 0 | 20 | ns |
| Width | Teyc-20 tao BEPulse | ns |  |  |
| tovan | DataValidtoREHigh | 10 | ns |  |
| ool | REHightoDataInvalid ns | 10 |  |  |
| [, | REHightoRELow ns | Teyc-20 |  |  |
| tous | DRQLowtoRCSHigh ns | 8'Teye | 10°Teye |  |
| tsuml | RCSHightoREInvalid | 100 | ns |  |
| o | RCSLowtoRELow | 60 | ns |  |
| oL | DRQLowtoRELow(1) taLsH tQHSL: | 0 | ns |  |
| oRO(N)] | tSLRL | \ |  |  |
| tsLRY | QLR> | tSHRI 5 ] RCS(OUT) tRO 1RHAL |  |  |
| REoun——I\ | 7 | /S tDVRH >tRHDI | — |  |
VYVVYVYYYYYYYYYYYY
po-07XRXXROUK_—————ROCUCCOCHKHKKXAXCAR)
118530224
1-38 Am33C93A

AMDn
BURSTDMAWRITE
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| toowe | DACKLowtoWELow | [ | ns |  |
| twon | WELowtoDRQHigh | 75 | ns |  |
| twn | WEPulseWidth | 50 | ns |  |
| e | WEHightoWELow | 80 | ns |  |
| tovwn | DataValidtoWEHigh | 25 | ns |  |
| twrion | WEHightoDACKHigh | 0 | ns |  |
| [ | WEHightoDataInvalig [—twLoH TRoun)\ ;‘ | 5 | ns |  |
| 1DLWL | twR | tWHDH |  |  |
| DACK(IN) | \ | /\ etwHWL—>] tDVWH tWHDI oo-07QOQOOOOOOQRRK_——RXC0000KCXXXXXXX BURSTDMAREAD et | Y |  |
| Symbol | Characteristic | Min | Max | Units |
| touaL | DACKLowtoRELow | 0 | ns |  |
| [ | TRELowtoDRQHigh | 7 | ns |  |
| tap | REPulseWidth | 80 | ns |  |
| taumL | REHightoRELow | 80 | ns |  |
| taoy | RELowtoDataValid | 50 | ns |  |
| tavon | REHightoDACKHigh | 4 | ns |  |
| tanor | REHightoDataInvalid [*—tRLQH DRA(OUT)_\ 4}_ | 5 | 40 | ns |
| 1DLRL | tRD | RHDH— [*—'RHRL—> \ ] 11853.024A Am33C93A 1-39 |  |  |

nAMD
INTRQ
| Characteristic | Min | Max | Units Symbol |
| --- | --- | --- | --- |
| HightoRELow | 0 | ns [, INTRQ |  |
| Width | 180 ta REPulse | ns |  |
| TEHightoINTRQLow | 0 | 100 tau | ns |
| [ | INTRQLowtoINTRQHigh ns HIHRL [+tRHIL tILH | 100 |  |
INTRQ
tRI
RE \
¥
118530250
SCSlInterface
ARBITRATION
| Characteristic | Min | ‘Max | Units Symbol |
| --- | --- | --- | --- |
| BSY,5ELInHightoBSYOutLow 12'Teyc | 6'Teye toaL | ns |  |
| tao | BSYOutLowtoBUSIDOut 50 ns | -50 |  |
| tas | BSYOutLowtoSELOutLow ps | 22 |  |
| BHBL | tBLsL e— \ | ‘l |  |
A
«—1BLIO'_’1
s
BB————————
—————
NOTE:Tgroup=signalsdrivenbyaTarget=VO,C/D,MSG,REQ
Igroup=signalsdrivenbyanInitiator=ATN,ACK
118530288
1-40 Am33C93A

AMDa
SELECTINGATARGET(ASANINITIATOR)
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tsi00 | SELOutLowto“OR-ED"IDOut | 12 | us |  |
| tovao | “OR-ED"IDOutValidtoACK,ATNOut | 100 | ns |  |
| taomH | ACK,ATNOutValidtoBSYOutHigh | 100 | ns |  |
| taay | BSYOutHightoBSYInLowValid | 400 | ns |  |
| tasu | BSYInLowtoSELOutHigh &Y ViR tBHBY tBLSH s\ 7 tsLoO L C | 100 | ns |  |
| tovao | } | tAOBH AN—=—————= AR— —— — ————— TGOUP=——————o ———=————————- NOTE:Tgroup=signalsdrivenbyaTarget=0,/D,MSG,REQ RESPONSETOSELECTION(ASATARGET) |  |  |
| Symbol | Characteristic | Min | Max | Units |
| [ | SELInLowtoBSYInHigh | 0 | ns |  |
| tyen | “OR-ED"IDValidIntoBSYInHigh | 0 | ns |  |
| tauaL | SELLow,IDValid,BSYHightoBSVLow | 0.4 | 200 | us |
| taon | BSYOutLowto“OR-ED"IDInvalidIn | 0 | ns |  |
| 1, | BSYOutLowtoSELInHigh | 0 | ns |  |
BLSH
1,	ATNValidIntoSELInHigh	0	ns
AVSH
tsmo	SELInHightoTgroupOut	100	ns
[tSLBH
1BHBL 1BLSH
— ———
HIVBH—f——»] 1BLOI—+——»]
[tAVSH—>
fe——>}—tSHIO
NOTE:Tgroup=signalsdrivenbyaTarget=VO,C/D,MSG,REQ
11853.020A
Am33C93A 1-41

nAMD
RESELECTINGANINITIATOR(ASATARGET)
Characteristic Min MaxUnits
Symbol
| to“OR-ED”IDOut | 12 [ SELOutLow | us |
| --- | --- | --- |
| tovio | “OR-ED"”IDQutValidto/O&TgroupOutValid100 | ns |
| tom | 1/O&TgroupOutValidtoBSYOutHigh ns Yoy BSYOutHightoBSYInLowValid 400 ns toen BSYInLowtoSELOutHigh 100 ns | 100 |
1BHBV
BSY f
tsLoo fe—tBLSH—*]
s\
B———————
tovio	t	tiogH
moT4
|
Igoup——————
——7F
Tgop—————-————————
———————
NOTE:Tgroup=signalsdrivenbyaTarget=C/D,MSG,& REQ
Igroup=signalsdrivenbyanInitiator=ATN,ACK
nassoasn
RESPONSETORESELECTION(ASANINITIATOR)
| Characteristic | Min | Max | Units ‘Symbol |
| --- | --- | --- | --- |
| toipn | SELInLowtoBSYInHigh | 0 | ns |
| tyan | “OR-ED"IDValidIntoBSYInHigh | [ | ns |
| tuan | 770InLowtoBSYInHigh tamo SELLow,IDValid,BSYHightoIgroupOut 100 ns | [ | ns |
| [y | IgroupValidOuttoBSYOutLow ns | 100 |  |
| [ | BSYInHightoBSYOutLow 200 ps | 04 |  |
| taior | BSVOutLowto“OR-ED"IDInvalidIn | 0 | ns |
| tarsn | BSYOutLowtoSELInHigh ns | 0 |  |
| touan | SELInHightoBSYOutHigh ns IsBH—> | 0 |  |
| 1BHBL | TBLSH | »— !SHBH * |  |
SEL
‘IVBH—'Q——’ 1BLOI—
=-- ----
TIVBH
wor— ———]o
NLBH tgAHO—
=)
——————— o—————————
TgOUp
ignalsdivenbyaTarget=C/D.MSG,REQ
11850908
Igroup=signalsdrivenbyanInitiator=ATN, ACK
+++BSYwillilbedrivenbythereselectingfarget
1-42 Am33C93A

AMD“
RECEIVEASYNCHRONOUSINFORMATIONTRANSFERIN(ACTINGASANINITIATOR)
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tepe | SELInHightoPhaseChangeIn | 0 | ns |  |
| ot | OInLowtoDataBusTRISTATE | 0 | 125 | ns |
| tocaL | PhaseChangeIntoREQInLow | 400 | ns |  |
| tovar | DataValidIntoREQInLow | 0 | ns |  |
| taiaL | REQInLowtoACKOutLow | 0 | 175 | ns |
| L | ACKOutLowtoDataInvalidIn | 0 | ns |  |
| [ | ACKOutLowtoREQInHigh | 0 | ns |  |
| [ | REQInHightoACKOutHigh | 0 | 175 | ns |
| Yo | ACKOutHightoPhaseChangeIn o]m tSHPC je—>'DVAL g | [ | ns |  |
| -—2[:tipt | UALDI | taHPC |  |  |
| \ | tPCRL | y— |  |  |
3
Phase
TRLAL: 1ALRH
REQ
\ y
\ TRHAH/—
ACK
ATN
NOTE:Phase=signalsthatdefinethebusphaseC/D,MSG
11853031
Am33C33A 1-43

nAMD
SENDASYNCHRONOUSINFORMATIONTRANSFERIN(ACTINGAS
ATARGET)
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| teupe | SELInHightoPhaseChangeOut | 100 | ns |  |
| oo | 770OutLowtoDataOut | 800 | ns |  |
| tovaL | DataOutValidtoREQOutLow | 55 | ns |  |
| tocaL | PhaseChangeOuttoREQOutLow500 | ns |  |  |
| [ | REQOutLowtoACKInLow | 0 | ns |  |
| [P | ACTKInLowtoREQOutHigh | 0 | 175 | ns |
| tao | ACKInLowtoDataOutinvalid | 0 | ns |  |
| taan | REQOutHightoACKInHigh | [ | ns |  |
| tanpe | ACKInHightoPhaseChangeOut | 100 | ns |  |
| tanL | ACKInHightoREQOutLow fsre -——itALDI tILDO | 0 | 175 | ns |
| \ | 1DVAL 3l tPCRL Phase | / |  |  |
REQ
UALRH tAHPC
tRLAL N
\ RHAH
ACK
r+—tAHRL
ATN NOTE:Phase=signalsthatdefinethebusphaseC/D,MSG
11es3a2A
1-44 Am33C93A

AMDfl
SENDASYNCHRONOUSINFORMATIONTRANSFEROUT(ACTINGASANINITIATOR)
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| teupe | SELInHightoPhaseChangeIn | ] | ns |  |
| o | OInHightoDataOut | 0 | ns |  |
| tocaL | PhaseChangeIntoREQInLow | 400 | ns |  |
| taia | REQInLowtoACKOutLow | 0 | 175 | ns |
| tova | DataOutValidtoACKOutLow | 55 | ns |  |
| tarn | ATKOutLowtoREQInHigh | 0 | ns |  |
| taan | REQInHightoACKOutHigh | [ | 175 | ns |
| ool | ACKInHightoDataOutInvalid | 0 | ns |  |
| tape | ACKOutHightoPhaseChangeIn | 0 | ns |  |
| SHPC\| | TDVAL -7 \| fe———tpPcR— B \ Phase \ / TALRH taHPC LALAL TRHAH | tAHDI |  |  |
| ACK | \ NOTE:Phase=signalsthatdefinethebusphaseC/D,MSG esacan Am33C93A 1-45 | i |  |  |

aAMD
RECEIVEASYNCHRONOUSINFORMATIONTRANSFEROUT(ACTINGASATARGET)
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| toupc | SELInHightoPhaseChangeOut | 100 | ns |  |
| tor | 770OutHightoDataBusTRISTATE 0 | ns |  |  |
| tocaL | PhaseChangetoREQOutLow | 500 | ns |  |
| taia | REQOutLowtoACKInLow | 0 | ns |  |
| tovar | DataInValidtoACKInLow | 5 | ns |  |
| T | ACKInLowtoREQOutHigh | [ | 175 | ns |
| [ | ‘REQOutHightoDataInInvalid | 0 | ns |  |
| [ | REQOutHightoACKInHigh | 0 | ns |  |
| tape | ACKInHightoPhaseChangeOut | 0 | ns |  |
| L | ACKInHightoREQOutLow =7 [——>—tIHDT [——>tDVAL | 0 | 175 | ns |
| o5QR | —--3 1SHPC 1RHDI | YRR |  |  |
| o | f | \|- tPCRL: Phaso |  |  |
X
fEG	\	/	{AHPG	\"s_
TALRH
tRLAL	]	|
[e—tAHRL
ATN
NOTE:Phase=signalsthatdefinethebusphaseC/D,MSG
Tres3034A
1-46 Am33C93A

AMDn
RECEIVESYNCHRONOUSINFORMATIONTRANSFERIN(ACTINGASANINITIATOR)
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tovaL | DataValidIntoREQInLow | 0 | ns |  |
| taor | REQInLowtoDATAInvalid | 45 | ns |  |
| [ | REQInLowtoREQInHigh | 50 | ns |  |
| taunL | REQInHightoREQInLow | 50 | ns |  |
| taan | ACKOutLowtoACKOutHigh | Teye-10 | ns |  |
| tanar | ACKOutHightoACKOutLow | Teyc-25 | ns |  |
| tape | ACKOutHightoPhaseChange Parameterstgoc,b,o@ndtooparealsoapplicableandareidenticaltothoseinReceive AsynchronousInformationTransferIn(ActingasanInitiator),topofpage37. o X tDVAL Phase %( URLRH tRHRL | 0 | ns |  |
| REG | \ | / | \ | / —LAHPC |
| ACK | \ | g | S‘ le—taLAH—te——>UanAL |  |
ATN
NOTE:Phase=signalsthatdefinethebusphaseC/D,MSG
11850025
Am33C93A 1-47

uAMD
SENDSYNCHRONOUSINFORMATIONTRANSFERIN(ACTINGASATARGET)
| Symbol | ___Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tovhe | DataValidOuttoREQOutLow | 55 | ns |  |
| tap | REQOutLowtoDataInvalid | 100 | ns |  |
| tacu | REQOutLowtoREQOutHigh | Teyc-10 | ns |  |
| L | REQOutHightoREGOutLow~Toye-25 | ns |  |  |
| tacan | ACKInLowtoACKInHigh | 50 | ns |  |
| tapiaL | ACKInHightoACKInLow | 50 | ns |  |
| e | ACKInHightoPhaseChangeOut Parameterstg,o0,byoandtosparealsoapplicableandareidenticaltothoseinReceive AsynchronousInformationTransferin(ActingasaTarget),bottomofpage37. o= X fe——1tovaL Phase | 0 | ns |  |
X
1RLRH tRHRL
REQ	X	7	i	/
tAHPC
A
AcK 7
tALAH tAHAL
ATN
NOTE:Phase=signalsthatdefinethebusphaseC/D,MSG
nssacon
1-48 Am33C93A

AMDn
SENDSYNCHRONOUSINFORMATIONTRANSFEROUT(ACTINGASANINITIATOR)
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tova | DataValidOuttoACKOutLow ALDI ACKOutLowtoData Invalid 100 ns | 55 | ns |  |
| taumn | REQInLow1oREQInHigh | 50 | ns |  |
| taaL | REQInHightoREQInLow | 50 | ns |  |
| tacan | ACKOutLowtoACKOutHigh~Teyc-10 | ns |  |  |
| oL | ACKOutHightoACKOutLow | Tcyc-25 | ns |  |
| tape | ACKOutHightoPhaseChangeIn Parameterstg,pe,typoy@8N0tocpyarealsoapplicableandareidenticaltothoseinSend AsynchronousInformationTransferIn(ActingasaTarget),bottomofpage39and40. | 0 | ns |  |
| =X | - 1DVAL—4—tALDI i X Phase [*—RLRH tALAL | X |  |  |
| AEQ | \ | / | / | H—tAHPC le—taLan—>te——>—tanaL |
ATN
NOTE:Phase=signalsthatdefinethebusphaseC/D,MSG.
esacara
RECEIVESYNCHRONOUSINFORMATIONTRANSFEROUT(ACTINGASATARGET)
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tova | DataValidIntoACKInLow | 0 | ns |  |
| tuor | ACKInLowtoDataInvalid | 45 | ns |  |
| tomn | REQOutLowtoREQOutHigh | Teyc-10 | ns |  |
| tauaL | REQOutHightoREQOutLow | Teyc-25 | ns |  |
| s | ACKInLowtoACKinHigh | 50 | ns |  |
| taaL | ACKInHightoACKInLow | 50 | ns |  |
| e | ACKInHightoPhaseChangeOut Parameterst,,,,,t,,andt,,arealsoapplicableandareidenticaltothoseinSend SynchronousInformationTransferOut(ActingasanInitiator),topofthispage. | 0 | ns |  |
| w5X | )f‘ 1DVAL 14—1ALDI i " Phase [ALRH—>}¢——*—tRLAL | j( |  |  |
| REQ | v | X | / | AHPC |
| e | \ | VAR Je—tALAH—e———>1—1AHAL ATN e NOTE:Phase=signaisthatdefinethebusphase/D,MSG Am33C93A 1-49 | 7 |  |

AMD
ARBITRATIONTOBUSFREE
| Symbol | Characteristic [ SELInLow | Min | Max | Units |
| --- | --- | --- | --- | --- |
| toBSYHigh,DataTRI-STATE | 8'Teyc+75 j— — | ns |  |  |
| BSY | \ 1SLBH—™ | 7 |  |  |
SEL
o8 —— )S
11853.099A
SELECTION(ASANINITIATOR)ORRESELECTION(ASATARGET)TOBUSFREE
(SELECTIONTIMEOUT)
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tranc | TimeoutorAborttoDataBusCleared0 | ns |  |  |
| toosw | DataBusClearedtoSELOutHigh | 200 | us |  |
| 5ot | SELOutHightoDataBusTRISTATE | 800 | ns |  |
| 1, | SELOutHightoCNTLTRISTATE | 800 | ns |  |
SEL
4 tSHDT
8%	\	tDCSH/2
. tSHIH
groupor
v	-	—-- -
NOTE:Tgroup=signalsdrivenbyaTarget=O,C/D,MSG,REQ
Igroup=signalsdrivenbyanInitiator=ATN,ACK
rasaouon
1-50 Am33C93A

AMDa
CONNECTED-AS-AN-INITIATORTOBUSFREE
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tauor | BSYInHightoDataBusTRISTATE | 8'Tcyc+75ns | ns. |  |
| taner | BSYInHightoIgroupTRISTATE BSY 7/ -tBHOT - . ns3on | 8'Teyc+750s | ns |  |
CONNECTED-AS-A-TARGETTOBUSFREE
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| tauor | BSYOutHightoDataBusTRISTATE | 8'Tcyc+75ns | ns |  |
| tgar | BSYOutHightoTgroupTRISTATE BSY 7 [+tBHDT 8% ;I_________ [tBHGT —m 4 =—==—== Tgoop wisssoih Am33C93A 1-51 | 8'Tcyc+75ns | ns. |  |
