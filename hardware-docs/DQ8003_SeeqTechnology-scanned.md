# DQ8003_SeeqTechnology-scanned

8003
SEEQ xS2
Technology,Incorporated	EDLC?®Ethernet	sz
z5
&
mgg
DataLinkController
ESE
L3z
May1991 a
Features Description
WOptimizedforBurstModeDMAApplications
TheSEEQEthernetDataLinkController(EDLC)isde-
W100%EthernetIEEE802.3(10BASES)and signedtosupportDataLinkLayer(layer2)oftheEthernet
IEEE802.3/CHEAPERNET (10BASE2) specificationforLocalAreaNetworks(LAN).Thesystem
interfaceisoptimizedforeaseofconnectiontocommonly
W10MHzSerial/ParallelConversion
availableDMAControllersandspecificallyforBURST
PreambleGenerationandRemoval
MODEOPERATION.The8003interfacesdirectlytothe
WAutomatic32-BitFCS(CRC)Generationand 8023Aand8020ManchesterCodeConverters(MCC™)
Checking tocompletethestationresidentEthernetfunctions.The
protocolusedisCarrierSense,MultipleAccesswith
CollisionHandling,TransmisslonDeferraland
CollisionDetection(CSMA/CD).The8003EDLCchipis
RetransmissionwithAutomaticJamand
asingleVLS|devicewhichreplacesapproximately60MS!
BackoffFunctions
andS8ldevices.Itisdesignedtogreatlysimplifythede-
ErrorInterruptandStatusGeneration velopmentofEthernetcommunicationincomputerbased
systems.The8003providesaneconomicsolutionforthe
40PinDIPPackage,44PinPLCC
constructionofanEthernetnode,providinghighspeed
Single5V+10%PowerSupply
datacommunicationat10Megabits/secondandseesap-
StandardCPUandPeripheralInterface plicationsinterminals,workstations,personalcomputers,
ControlSignals smallbusinesssystems,andlargecomputersystems,in
boththeofficeandindustrialenvironment. The8003
LoopbackCapabilityforDiagnostics
EDLCchiphasauniversalsysteminterfacecompatible
SinglePhaseClock
withalmostanymicroprocessor,microcomputer,orsys-
BInputsandOutputsTTLCompatible tembus,allowingthesystemdesignertomaketheprice/
performancetradeoffsforeachapplication.Thetransmit
andreceivesectionsoftheEDLCchipareindependent
FunctionalBlockDiagram
™0
TRANSMIT
BYTE
COUNTER
encooen| [T
INTERFACE CO.NA““‘
TROLLER
ATTEMPT
| A | CONTROL | INTERRUPT [ | COMMAND/ |
| --- | --- | --- | --- |
| pom | RFILE | PconTRoL[[Tx Re] e ~—DEN 1evme | [ |
| contROL | [N | RC | Costio-7 ceneraton[w u PARALLEL x |
| 1 | [ | [SERIAL i |  |
| B | REGEWVEBIT | RESE |  |
| oata | \| | Hro | = conTROL o |
| INTERFACE | 1 | oECOOER |  |
CHECKER
A0 INTERFACE
168vTE
cho
RECENE SERAL
Fro	STRIPPER	PARALLEL
Ao0RESS
cHECKER
Recee|oo}R
BvTE e
s e|[oavers|.T
COUNTER
EDLCisaregisteredtrademarkofSEEQTechnologyInc.
MCCisatrademarkofSEEQTechnologyInc.
1-1
MD400024/C

8003
andcanoperatesimultaneouslytoallowreceptionofa SourceAddress:TheSourceAddressisa6-bytefield
transmittedframeforuseinloopbackdiagnosticsmodes. containingthespecificStationAddressfromwhichthis
frameoriginated.
FunctionalDescription
Byte-CountFleid:TheByte-CountFieldconsistsoftwo
FrameFormat
bytesprovidingthenumberofvaliddatabytesintheData
OnanEthernetcommunicationnetwork,informationis
Field,46to1500.ThisfieldisuninterpretedattheData
transmittedandreceivedinpacketsorframes.AnEth-
LinkLayer,andispassedthroughtheEDLCchiptobe
ernetframeconsistsofapreamble,twoaddressfields,a
handledattheClientLayer.
byte-countfield,adatafieldandaframechecksequence
(FCS).Eachfieldhasaspecificformatwhichisdescribed
DataField:TheDataFieldconsistsof46to1500bytesof
indetailbelow.AnEthernetframehasaminimumlength
informationwhicharefullytransparentinthesensethat
of64bytesandamaximumlengthof1518bytesexclusive
anyarbitrarysequenceofbytesmayoccur.
ofthepreamble. TheEthernetframeformatisshown
below.
FrameCheckSequence:TheFrameCheckSequence
| i— | ETHERNETFRAME | i | (FCS)fieldisa32-bitcyclicredundancycheck(CRC} valuecomputedasafunctionoftheDestinationAddress Field,SourceAddressField,TypeFieldandDataField. TheFCSisappendedtoeachtransmittedframe,andused T T |
| --- | --- | --- | --- |
| PREAMBLE | \| | SOURCE l | oaTA atreceptiontodetermineifthereceivedframeisvalid. |
| ® | ADORESS DESTINATION ) ADDRESS couNT | iy | @ |
| ) | @ | Transmitting NOTE: ThetransmitdatastreamconsistsofthePreamble,four Fieldlengthinbytesinparentheses. informationfields,andtheFCSwhichiscomputedinreal timebytheEDLCchipandautomaticallyappendedtothe Preamble:Thepreambleisa64-bitfieldconsistingof62 frameattheendoftheserialdata.ThePreambleisalso alternating“1"sand“0"sfollowedbya“11”End-of-Pre- ambleindicator. generatedbytheEDLCchipandtransmittedimmediately priortotheDestinationAddress.DestinationAddress, SourceAddress,TypeFieldandDataFieldareprepared DestinationAddress:TheDestinationAddressis a6-byte inthebuffermemorypriortoinitiatingtransmission.The fieldcontainingeitheraspecificStationAddress,aBroad- EDLCchipencapsulatesthesefieldsintoanEthernet castAddress,oraMulticastAddresstowhichthisframeis directed. |  |
00
AxtxrerervTxEN20Avee wr
[5)5]@[3]7] 4I3ok3%I
ol
Figure1.Dual-In-Line Figure2.PlasticLeadedChipCarrier
TopView Topview
—SEEQ
MD400024/C

8003 n
- 3
jm)x4
EE|]
epr¥e)
w
framebyinsertingapreamblepriortotheseinformation 2z
eestome[	m	T
=b
fieldsandappendingaCRCaftertheinformationfields. o
- eg
53
e||pesmumon
TransmissionInitlatior/Deferral
...	A2%	{($BYTES)
TheEthernetnodeinitiatesatransmissionbystoringthe
o
entireinformationcontentoftheframetobetransmittedin
M ke
anexternalbuffermemory,andthentransferringinitial
v w
framebytestotheEDLCTransmitFIFO.“Transmit-buffer
v w
toFIFO"transfersarecoordinatedviatheTXWRand
||o
TxRDYhandshakeinterface,i.e.,bytesarewrittentothe
o |[feaves
FIFOviaTXWRonlywhenTxRDYisHIGH.Actualtrans-
YR
missionofthedataontothenetworkwillonlyoccurifthe
W se
networkhasnotbeenbusyfortheminimumdefertime(9.6
L)}mm
Hs)andanyBackofftimerequirementshavebeensatis-
| s | b | anTEy fied.Whentransmissionbegins,theEDLCchipactivates o7 0o thetransmitenable(TXEN)lineconcurrentlywiththe |
| --- | --- | --- |
| A | 2\| transmissionofthefirstbitofthePreambleandkeepsit = AL@i activeforthedurationofthetransmission. BYTES} usteve Collision WhenconcurrenttransmissionsfromtwoormoreEthernet Figure3.TypicalFrameBufferFormatfor nodesoccur(collision),theEDLCchiphaltsthetransmis- Byte-OrganizedMemory sionofthedatabytesintheTransmitFIFOandtransmits aJampatternconsistingof55555555hex.Attheendof beforeattemptingretransmission,where“K"isthecurrent theJamtransmission,theEDLCchipissuesaTxRET transmissionattemptnumber(nottoexceed10). signaltotheCPUandbeginstheBackoffwaitperiod. When16consecutiveattemptshavebeenmadeattrans- Toreinitiatetransmission,theinitialbytesof theframe missionandallhavebeenterminatedduetocollision,the informationfieldsmustbereloadedintotheEDLCTrans- EDLCTransmitControlsetsanerrorstatusbitandissues mitFIFO.TheTxRETisusedtoindicatetothebuffer aninterrupttotheCPUifenabled. managertheneedforframereinitialization.The reloading oftheTransmitFIFOmaybedonepriortotheBackoff TerminatingTransmission intervalelapsing,sothatnoadditionaldelay needbe TransmissionTerminatesunderthefollowingconditions: incurredtoretransmission. Normal:Theframehasbeentransmittedsuccessfully Schedulingofretransmissionisdeterminedbyacon- withoutcontention.Loadingofthelastdatabyteintothe trolledrandomizationprocesscalledTruncatedBinary TransmitFIFOissignaledtotheEDLCchipbyactivation ExponentialBackoff. TheEDLCchipwaitsarandom oftheRxTXEOFsignalconcurrentlywiththeiastbyteof intervalbetween0and2Xslottimes(51.2usperslottime) dataloadedintotheTransmitFIFO.Thislineactsasa RATx00 RaTxD1 RaTx02 AxTxD3 RaTx04 AxTxDs RxTxD6 RaTxD7 | on |
| FIRSTBYTE | ya_ | SIXTHBYTE |
| ozJro_w | [re | ] Jamo aer\|sounceaooress |
T
DESTINATIONADDRESS
BITSWITHINABYTETRANSMITTED/RECEIVEDBITNO.“0"FIRSTTHROUGHBITNO.7"LAST.
Figure4. BItSerialization/Deserialization
Tochrmiagy,orpes 1-3
MD400024/C

8003
ninthbitintheTransmitFIFO. Whenthislastbyteis frameisnotreceived,andtheEDLCchipbeginsmonitor-
serialized,theCRCisappendedandtransmittedconclud- ingthenetworkforacarrieragain.
ingframetransmission.TheTransmissionSuccessfulbit
oftheTransmitStatusRegisterwillbesetbyanormal AddressMatching
termination. Ethernetaddressesconsistoftwo6-bytefields.Thefirst
bitoftheaddresssignifieswhetheritisaStationAddress
Collislon:TransmissionattemptedbytwoormoreEth- oraMulticast/BroadcastAddress.
emnstnodes.TheJamsequenceistransmitted,theColli-
sionstatusbitisset,theTxRETsignalisgenerated,and
FirstBit Address
theBackoffintervalbegun.
4 StationAddress(Physical)
1 Multicast/BroadcastAddress
Underflow:Transmitdataisnotreadywhenneededfor
transmission.Oncetransmissionhasbegun,theEDLC (logical)
chiponaveragerequiresonetransmitbyteevery800ns
Addressmatchingoccursasfollows:
inordertoavoidTransmitFIFOunderflow(starvation).If
thisconditionoccurs,theEDLCchipterminatesthetrans-
StationAddress:Alldestinationaddressbytesmust
mission,issuesaTxRETsignal,andsetstheTransmit-
matchthecorrespondingbytesfoundintheStationAd-
Underflowstatusbit.
dressRegister.
16TransmissionAttempts:IfaCollisionoccursforthe
MuiticastAddress:Ifthefirstbitoftheincomingaddress
sixteenthconsecutivetime,the16-Transmission-At-
isa1andtheEDLCchipisprogrammedtoaccept
temptsstatusbitisset,theCollisionstatusbitisset,the
MulticastAddresses,theframeisreceived.
TxRETsignalisgenerated,andtheBackoffintervalbe-
gun. Thecounterthatkeepstrackofthenumberof
BroadcastAddress:Thesixincomingdestinationad-
collisionsismodulo16andthereforerolisoveronthe17th
dressbytesmustallbeFFhex.IftheEDLCchipis
collision.
programmedtoacceptbroadcastorMulticastAdoresses
theframewillbereceived.
Atthecompletionofeverytransmissionorretransmission,
newstatusinformationisloadedintotheTransmitStatus
IftheincomingframeisaddressedtotheEDLCchip
Register.DependentuponthebitsenabledintheTrans-
specifically(DestinationAddressmatchesthecontentsof
mitCommandRegister,aninterruptwillbegeneratedfor
theStationAddressRegister),orisofgeneralorgroup
thejustcompletedtransmission.Inbothcollisionand
interest(BroadcastorMulticastAddress),theEDLCchip
underflowtheTxRETsignalisactivated.
willpasstheframeexclusiveofPreambleandFCStothe
CPUbutferandindicateanyerrorconditionsattheendof
Recelving
theframe.If,however,theaddressdoesnotmatch,as
TheEDLCchipiscontinuouslymonitoringthenetwork.
soonasthemismatchsrecognizedtheEDLCchipwillter-
WhenactivityisrecognizedviatheCarrierSense(CSN)
minatereceptionandissueanRxDC.
linegoingactive,theEDLCchipsynchronizesitselftothe
incomingdatastreamduringthePreamble,andthen
TheEDLCchipmaybeprogrammedviatheMatchMode
examinesthedestinationaddressfieldoftheframe.
bitsoftheReceiveCommandRegistertoignoreallframes
DependingontheAddressMatchModespecified,the
(DisableReceiver),acceptallframes(Promiscuous
EDLCchipwilleitherrecognizetheframeasbeingad-
modej,acceptframeswiththeproperStationAddressor
dressedtoitselfinageneralorspecificfashionorabortthe
theBroadcastAddress(StatiorvBroadcast),oracceptall
framereception.
frameswiththeproperStationAddress,theBroadcast
Address,orallMulticastAddresses(StatiorvBroadcast/
PreambleProcessing
Multicast).
TheEDLCchiprecognizesactivityontheEthernetviathe
CarrierSenseline.ThePreambleisnormally64bits(8
TerminatingReception
bytes)long.ThePreambleconsistsofasequenceof62
Receptionisterminatedwheneitherofthefollowingcon-
alternating“1"sand“0'sfollowedby“11”,withtheframe
ditionsoccur:
informationfieldsimmediatelyfollowing.Inorderforthe
decoderphase-locktooccur,theEDLCchipwaits16 bit
CarrierSenseInactive:Indicatesthattrafficisnolonger
timesbeforelookingforthe“11"endofpreambleindicator.
presentontheEthernetcable.
IftheEDLCchipreceivesa“00"beforereceivingthe“11"
inthePreamble,anerrorconditionhasoccurred.The
—SEEQ
Techoongy,oorperaind
1-4
MD400024/C

8003
2
=
wzl
£5
TRANSMIT [
| RECEIVE | hraed ~ab BUFFER uco o | pE2 |
| --- | --- | --- |
| BUS | s003 | 8020or8023 |
| rRANSCEVER\| | E0LC | MANCHESTER |
CODE
K—)
CONVERTER(MCC)
comslon]mmsun‘RECEIVE
SYSTEM
TO83CE2
cPu MEMORY
ETHERNET
TRANSCENER
Figure5.TypicalEthernetNodeConfiguration
Overtlow:Thehostnodseforsomereasonisnot
ableto commandandstatusregistersmaybeaccessedatany
emplytheReceiveFIFOasrapidlyasitisfilled,andan time. However,itisrecommendedthatwritingtothe
erroroccursasframedataislost.OnaveragetheReceive commandregisterbedoneonlyduringinterframegaps.
FIFOmustbeservicedevery800nstoavoidthiscondition.
WiththeexceptionofthetwoMatchModebitsinthe
FrameReceptionConditions ReceiveCommandRegister,allbitsinbothcommand
Uponterminatingreception,theEDLCchipwilldetermine registersareinterruptenablebits.Changingtheinterrupt
thestatusofthereceivedframeandconditionallyloadit enablebitsduringframetransmissiondoesnotaffectthe
intotheReceiveStatusRegister.Aninterrupt frameintegrity.Asynchronouserrorevents,howsver,
willbe
issuediftheappropriateconditionsasspecifiedinthe e.g.,overflow,underflow,etc.,maycausechipoperation
ReceiveCommandRegisterarepresent.TheEDLCchip tovary,iftheircorrespondingenablebitsarebeingaltered
mayreportthefollowingconditionsattheendofframe atthesametime.
reception:
Readingthestatusregistersmayalsooccuratanytime
Overflow:TheEDLCinternalReceiveFIFOoverflows. duringtransmissionorreception.
DribbleError:CarrierSensedidnotgoinactive
ona
InternalRegisterAddressing
receivedatabyteboundary.
Register
CRCError:The32-bitCRCtransmittedwiththeframe
Address RegisterDescription
doesnotmatchthatcalculateduponreception.
| A2\|A1 \|AO | Read | Write ShortFrame:Aframecontaininglessthan64bytesof |
| --- | --- | --- |
| oclo]o}o | — | StationAddr0 informationwasreceived(includingFCS). |
| 110]o0 | \|1 | — StationAddr1 |
| 2101 \|0 | — | StationAddr2 GoodFrame:Aframeisreceivedthatdoesnot havea |
| 3o}t \|1 | — | StationAddr3 CRCerror,ShortframeorOverflowCondition. |
| 411(0]0 | - | StationAddr4 |
| SystemInterface | S5(1]0]1 | - StationAddr5 |
| TheEDLCchipsysteminterfaceconsistsoftwoindepend- | 86 | (1 ]\|1]0 [RxStatus RxCommand |
| entbussesandrespectivecontrolsignals.Data | 70111 | TxStatus TxCommand isread andwrittenovertheReceive/TransmitDataBusRxTxD (0-7)._ThesetransfersarecontrolledbytheTxRDY and StatusRegistersarereadonlyregisters.Commandand TXWHsignalsfortransmitteddataandRxRDYand AxAD StationAddressregistersarewriteonlyregisters.Access forreceiveddata.AllCommandsandStationAddresses totheseregistersisviatheCPUinterface:Controlsignals arewritten,andallstatusreadoveraseparateCommand/ CS, RD, WR,andtheCommand/StatusDataBus StatusBusCdSt(0-7).Thesetransfersarecontrolled Cdst(0-7). by theCS,AD,WRandA0-A2signals.TheEDLC chip's Technetegy,nenrporaisd |
1-5
MD400024/C

8003
StationAddressRegister TransmitStatusRegisterFormat
TheStationAddressRegisteris6bytesinlength.The
76543210BT
contentsmaybewritteninanyorder,withbit“0"ofbyte“0”
correspondingtothefirstbitreceivedinthedatastream,
andindicatingwhethertheaddressisphysicalorlogical. l_TransmitUnderfiow
Bit7ofstationaddressbyte5iscomparedtothelastbitof L——TransmitCollision
thereceiveddestinationaddress.TheStationAddress 16TransmissionAttempts
shouldbeprogrammedpriortoenablingthereceiver.
TransmissionSuccesstul
Old/NewStetus.
TransmitCommandRegister
TheTransmitCommandRegisterisaninterruptmask
register,whichprovidesforcontroloftheconditionsal- ReceiveCommandRegister
lowedtogeneratetransmitinterrupts. Eachofthefour TheReceiveCommandRegisterhastwoprimaryfunc-
leastsignificantbitsoftheregistermaybeindividuallyset tions,itspecifiestheAddressMatchMode,anditspecifies
orcleared.Whenset,theoccurrenceoftheassociated Frames-ofInterest.i.e.frameswhosearrivalmustbe
conditionwillcauseaninterrupttobegenerated.Thefour communicatedtotheCPUviainterruptsandstatusregis-
spacificconditionsforwhichinterruptsmaybegenerated terupdates.Frames-of-Interestareframeswhosestatus
are. nmustbesavedforinspection,evenattheexpenseoflosing
*Underflow subsequentframes.
+Collision
RecelveCommandReglsterFormat
*16Collisions
+TransmissionSuccessful 765432108
TheinterruptsignalINTwillbesetwhenoneormorsofthe
specifiedtransmissionterminationconditionsoccursand
theassociatedcommandbithasbeenset.Theinterrupt LInterruptonOverfiowEror
L——interruptonCRCError
signalINTwillbeclearedwhentheTransmitStatus
LIntemuptonDribbieEror
Registerisread.
InterruptonShortFrame
InterruptonEndofFrame
AllbitsoftheTransmitCommandRegisterarecleared InterruptonGoodFrames
uponchipreset. MaichMode0
MatchMode1
TransmitCommandRegisterFormat
Bits0-5specifyInterruptandFrame-of-Interestwhenset.
76543210BIT
Bit4,EndofFrame,specifiesanytypeofframeexcept
ofojofo
overfiow.
LInterruptonTransmitUnderfiow
MatchModeDefinition
InterruptonTransmitCollision
Interrupton16Transmission
Match|Match
Allempts
Mode[Mode
InterruptonTransmission
| Successtul | 1 | 1) | Function |
| --- | --- | --- | --- |
| 0 | 0 | 0 | RecsiverDisable TransmissionSuccessfulissetonlyonthesuccessful |
| transmissionorretransmissionofaframe. | 1 | 0 | 1 ReceiveAllFrames |
| 2 | 1 | o | ReceiveStationorBroadcast TransmitStatusRegister Frames TheTransmitStatusRegisterisloadedattheconclusion |
| 3 | 1 | 1 | ReceiveStation, ofeachframetransmissionorretransmissionattempt.It Broadcast/MulticastFrames providesforthereportingofboththenormalanderror terminationconditionsofeachtransmission. ChangingthereceiveMatchModebitsduringframere- TheOLD/NEWstatusbitisseteachtimetheTransmit ceptionmaychangechipoperationandgiveunpredictable StatusRegisterisread,andreseteachtimenewstatusis results. loadedintotheTransmitStatusRegister.TheOLD/NEW statusbitisSET,andallotherbitsCLEAREDuponchip reset. Techrwiogy,bcarpersisd MD400024/C |

8003
- 2
LEy
224
&
InterruptEnableandFrames-of-Interest
Theseconditionsensurethatamaximumnumberofgood gze
Exb
Bits0-5whensetspecifyinterruptgenerationonoccur-	framesarereceivedandretained.	M]Qo
renceofthecorrespondingframereceptioncondition. S
Theyalsospecifythecorrespondingtypesofframestobe
PinDescription
Frames-of-InterestforusebytheReceiveStatus
Register
TheEDLCchiphasfourgroupsofinterfacesignals:
tocontrolstatusloading.
»PowerSupply *DataBuffer
»Encoder/Decoder »Command/Status
RecelveStatusRegister
TheRecsiveStatusRegisterisnormallyloadedwiththe
PowerSupply
statusofeachreceivedframewhentheframehasbeen
cc
receivedorframereceptionhasbeenterminatedduetoan
ss
errorcondition.Inaddition,thisregistercontainstheOid/
NewStatusbitwhichissetwhentheReceive
Status
Encoder/DecoderInterface
Registerisreadorthechipisreset,andclearedonlywhen
TXCTransmitClock(Input):10MHz,50%dutycycle
statusisloadedforaFrame-of-Interest(asdefined
bybits
transmitclockusedtosynchronizethetransmitdatafrom
0-5oftheReceiveCommandRegister).Allotherbitsare
theEDLCchiptotheencoder.Thisclockrunscontinu-
cleareduponchipreset,
ously,andisasynchronoustoRxC.
ReceiveStatusRegisterFormat
TxDTransmitData(Output):SerialDataoutputtothe
76543210 BT encoder.ActiveHIGH.
X
TxENTransmitEnable(Output):Thissignalisusedto
T_ReceivedFramewithOvarllowEror
activatetheencoder.Itbecomesactivewhenthefirstbit
L——ReceivedFramewithCRCEfror
ofthePreambleistransmittedandinactivewhenthelast
ReceivadFramewithDribbleError
bitoftheframeistransmitted.ActiveHIGHandclearedby
ReceivedShortFrame
RecaivedEndofFrama Reset.
ReceivadGoodFrame
RxCReceiveData(Input):10MHz,50%dutycyclenomi-
Old/NewStatus
nal. Thereceiveclockisusedtosynchronizeincoming
datatotheEDLCchipfromthedecoder.Thisclockruns
TheOld/NewStatusbitwrite-protectstheReceiveStatus
RegisterwhileitcontainsunreadstatusforaFrame-of- continuously,andisasynchronoustoTxC.
Interest. Whenthisbitiszero,theregister
iswrite-
RxDReceiveData(Input):SerialinputdatatotheEDLC
protected.TheOld/NewStatusbitisclearedwheneverthe
chipfromthedecoder.ActiveHIGH.
statusofanewFrame-of-interestisloadedintotheRe-
ceiveStatusRegisterandissetafterthatstatus
isread.
Whenzero,itindicates‘newstatusforaFrame-of- CSNCarrierSense(Input):Indicatestrafficonthecoax-
Interest”. ialcabletotheEDLCchip.Becomesactivewiththefirst
bitofthePreamblereceived,andinactiveonebittimeafter
thelastbitoftheframeisreceived.ActiveHIGH.
Thusthestatusofanyframereceivedfollowingtherecep-
tionofaFrame-of-Interestwillnotbeloadedintothe
ReceiveStatusRegisterunlessthepreviousstatus COLLCoitision(Input):Indicatestransmissionconten-
has
tionoftheEthernetcable.theCollisioninputislatched
beenread.Ifanyfollowingframeisreceivedbeforethe
internally.Sampledduringtransmission,Collisionissetby
statusofthepreviousFrame-of-Interesthasbeenread,
anactivehighpulseontheCOLLinputandautomatically
thenewstatuswillnotbeloaded,theReceiveDiscard
resetattheendoftransmissionoftheJAMsequence.
(RxDC)signalwillbeissuedandtheReceiveFIFOwillbe
cleared.
DataBufferInterface
RxTxD(0-7)Receive/TransmitDataBus(I/0):Carries
Withthisoneexceptioncausedbyawrite-protectcondi-
Receive/Transmitdatabytefrom/totheEDLCchipRe-
tion,thestatusofeachframeisalwaysloadedintothe
ceive/TransmitFIFOs.
ReceiveStatusRegisteroncompletionofreception.
Anyframereceivedwillcauseaninterrupttobe RxTxEOFReceive/TransmitEndofFrame(1/0):Indi-
generated
ifthecorrespondingInterruptEnablebitis cateslastbyteofdataontheReceive/TransmitDataBus.
set. This
EffectivelyaninthbitintheFIFOswithidenticaltimingto
interruptisresetuponreadingtheReceiveStatusRegis-
RxTxD(0-7).ActiveHIGH.
ter.
SEEQ
Technaioqy,hoarperated
MD400024/C

8003
RxRDYReceiveReady(Output):Indicatesthatatleast Command/StatusInterface
onebyteofreceiveddataisavailableintheReceiveFIFO. CdSt(0-7)Command/StatusDataBus(V/0):Theselines
Thissignalwillremainactivehighaslongasonebyteof carrycommandsandstatusaswellasstationaddress
dataremainsintheReceiveFIFO.Whenthisconditionno initializationinformationbetweentheEDLCchipandCPU.
longerexists,RxRDYwillbedeassertedwithrespecttothe Theselinesarenominallyhighimpedanceuntilactivated
leadingedgeoftheAxADstrobethatremovesthelastbyte byCSandRDbeingsimultaneouslyactive.
ofdatafromtheReceiveFIFO.RxRDshouldnotbe
activatedifAXRDYislow.ActiveHIGHandclearedby A0-A2Address(0-2)(Input):Addresslinestoselectthe
Reset. properEDLCinternalregistersforreadingorwriting.
RxRDReceiveReadStrobe(Input):Enablestransferof CSChipSelect(Input):ChipSelectinput,mustbeactive
receiveddatafromtheEDLCReceiveFIFOtotheRxTxD inconjunctionwithRDorWRtosuccessfullyaccessthe
Bus.DataisvalidfromtheEDLCReceiveFIFOatthe EDLCinternalregisters.ActiveLOW.
RxTxDpinsontherisingedgeofthissignal.Thissignal
shouldnotbeactivatedunlessRxRdyshigh.ActiveLOW. ADRead(Input):EnablesreadingoftheEDLCinternal
registersinconjunctionwithCS.Datafromtheinternal
RxDCReceiveDiscard(Output):Assertedwhenoneofthe registersisenabledviathefallingedgeofRDandisvalid
followingconditionsoccurs,andtheassociatedInterrupt ontherisingedgeofthesignal.ActiveLOW.
EnablebitintheReceiveCommandRegisterisreset.(1)
ReceiveFIFOoverflow.(2)CRCError.{3)ShortFrame WRWrite(Input):EnableswritingoftheEDLCinternal
Error.(4)Receiveframeaddressnonmatchor(5)current registersinconjunctionwithCS.WritedataontheCdst
framestatuslostbecausepreviousstatuswasnotread. {0-7)datalinesmustbesetuprelativetotherisingedge
RxDCdoesnotactivateonerrorswhentheassociated ofthesignal.ActiveLOW.
InterruptEnablebitisset. Inthiscase,EOFwillbe
generatedinsteadwhentheReceiveFIFOisreadout. INTinterrupt(Output):Enabledasoutlinedabovebya
Thisallowsreceptionofframeswitherrors.RxDCacts varietyoftransmitandreceiveconditions.Remainsactive
internallytocleartheReceiveFIFO. untilthestatusregistercontainingthereasonforthe
interruptisread.ActiveHIGH.
TxRDYTransmitReady(Output):indicatesthatthe
TransmitFIFOhasspaceavailableforatleastonedata RESET(Inpu):Initializescontrollogic,clearscommand
byte.Thissignalwillremainactivehighaslongasonebyte registers,clearstheTransmitStatusRegister,clearsbits
ofspaceexistsfortransmitteddatatobewritteninto. 0-5oftheReceiveStatusRegister,setstheOld/New
Whenthisconditionnolongerexists,TxRDYwillbe Statusbit(bit7oftheReceiveStatusRegister),asserts
deassertedwithrespecttotheleadingedgeoftheTXWR RxDCandTxRETandclearstheReceiveandTransmit
strobethatfilistheTransmitFIFO. TxRDYisforced FIFOs.Inaddition,TxRDYisforcedlowduringareset.
inactiveduringReset,andwhenTxRETisactive.Active TxRDYgoeshighwhenRESETgoeshigh,indicatingthe
HIGH.GoeshighafterReset. EDLCchipisreadytotransmit.RESETisactiveLOW.
TxWRTransmitWrite(Input):Synchronizesdatatrans-
ferfromtheRxTxDBustotheTransmitFIFO.Datais
writtentotheFIFOontherisingedgeofthissignal.This
signalshouldnotbeactiveunlessTxRDYishigh.Active
Low.
TxRetTransmitRetransmit(Output):Assertedwhen-
evereithertransmitunderflowortransmitcollisioncondi-
tionsoccur.Itisnominally800nsinwidth.ActiveHIGH.
AssertedbyReset.TxRETclearstheinternalTransmit
FiFO.
—SEEQ
Techeiagy,oerperstsd
MD400024/C

8003
4
LES
. =g
AbsoluteMaximumRatings <
£2E
AmbientTemperature
wesg
UnderBias
=10°Cto+80°C
StorageTemperature
~65°Cto+150°C
AllInputorOutputVoltages
withRespecttoGround......
.+6V100.3V
PackageMaximumPowerDissipat
...1.5Watts
OperatingConditions
AmbientTemperatureRange
..0°Cto70°C
V..PowerSupply
.50Vto5.50V
DCCharacteristicsT,=0°Cto
70°C,V,,=5V105%
Limits™
Symbol|Parameter
| Min. | Typ. Units Condition ™ InputLeakageCurrent | Max. |
| --- | --- | --- |
| 10 | HA | Vy=045V105.25V lo OutputLeakageCurrent |
| 10 | HA | Vour=045V |
10525V
loc VeCurrent
150	200	mA
Ve, ClockInputHighVoltage
35 3
v
Ve, ClockInputLowVoltage
0.8 v
Vi InputLowVoltage
0.8 \
Vi InputHighVoltage
2.0 6
Vv ExceptTRWRandRXRD
Vi, InputHighVoltage
3.0 3
v TXWRandRxRD
Vo QOutputLowVoltage
0.4	A	I=2.1
mA
Vo OutputHighVoltage
2.4
v o=~400A
NOTE:
1.TypicalvaluesareforT,=25°C
andnominalsupplyvoltages.
—SEER@
Tecmalogy.naerpersid
1-9
MD400024/C

8003
ACTestConditions Capacitance®71,=25°C,F=1MHz
OutputLoad:1SchottkyTTLGate+CL=100pF
| (AllpinsexceptTXEN,TxD) | Symbol{Parameter | Maximum\|Conditlon |
| --- | --- | --- |
| ;I’xEl;l;’TTDIiam:;;fcxorflg‘T;’LGate+CL=35pF | Cy | InputCapacitance\| 15pF Vy=0V ACCharacteristicsT,=0°Cto70°C,V,,=5Vt5% Limits Units |
| Symbol®*l\|Parameter | Min. | Typ. I Max, (ns) Condition DATAANDCOMMAND/STATUSINTERFACETIMING |
| TDBD | RxTx/CdStBusDataDelay | 150 ns |
| TDBR | RxTx/CdStBusReleaseDelay | 10 ns |
| TDBS | RxTx/CdStBusSiezureDelay | 10 150 ns |
| TDRY | RxRDY/TxRDYClearDelay | 100 ns |
| THAR | A,/CSHold | 10 ns |
| THDA | RxTx/CdStBusHold | 0 ns |
| THRW | RXRD/TXWRHold | 0 ns |
| TSAR | A,/CSSetup | 0 ns |
| 78CS | CdStBusSetup | 90 ns |
| TSRT | RxTxBusSetup | 90 ns |
| TWCH | "RXRD/TXWR/RD/WHHighWidth | 100 ns |
| TWCL | 'RXRD/TWR/RD/WRLowWidth | 200 10,000 ns |
SERIALTRANSMITANDRECEIVEINTEFACETIMING
| TDDC | RxDCSetDelay | 800 | ns | NOTE1 |
| --- | --- | --- | --- | --- |
| TDIC | INTClearDelay | 150 | ns |  |
| TDRE | TxRETSetDelay | 2400 | 3400 | ns NOTE3 |
| TORI | ReceiveINTDelay | 1000 | ns | NOTE2 |
| TOTD | TxD/TXENDelay | 20 | 60 | ns Cl=35pF |
| TOTI | TransmitINTDelay | 1200 | ns | NOTE4 |
| THRD | RxDHold | 20 | ns |  |
| TPCK | RxC/TxCClockPeriod | 95 | 1000 | ns |
| TSRD | RxDSetup | 30 | ns |  |
| TWDC | RxDCHighWidth | 600 | ns |  |
| TWRC | RxCHigh/LowWidth | 45 | ns |  |
| TWRE | TxRETHighWidth | 600 | ns |  |
| TWRS | RESETLowWidth | 10,000 | ns |  |
| TWTC | TxCHigh/LowWidth | 45 | ns |  |
| TWCO | COLLWidth NOTES: 1.ForframereceptionwithShortframeorCRCError.IfframereceptionisterminatedduetoOverflow,RXDCwillbeissuedwithin1.2psofOverflow.Ifframe. receptionisterminatedduetonon-malchofaddress,RxDCwilbeissuedwithin2.4psoftherecaiptofthelastaddressbil. 2.NormalframerecaptionwithoutOverflow.HfframereceptionisterminatedduetoOverflow,INTwillbeissuedwithin1.2ofOverfiow. 3.ForTXRETcausedbyCollisionor16Collisioncondition.IftransmissionisterminatedduetoUnderfiowTxRETwillbeissuedwithin1.2usoftheUnderflow. 4.ForINTcausedbyColiisionor16Collisioncondition,1fcausedbyUnderfiow,INTwillbeissuedwithin1.2ps.Ifcausedbynormaltermination,INTwill baissuedwithin200nsofTXENgoingLOW. 5.ltalicsindicateinputrequirement,non-italicsindicateoutputtiming. 6Characterized.Nottested. | 50 | ns |  |
SEEQ
Tecnnaiagy,Icorpersted
MD400024/C

8003
&
LEw
gag
RECEIVE &
DATAINTERFACETIMING
E5E
RxFIFO(BOTTOM)EMPTY waoS
TORY—#» THRW
RxRDY
RxRD
TD8D
[+—Toe0—]
T
TDBS: TOBS1
RXTX0(0-7)
RXTAECF I
NOTE1 NOTE1
TRANSMITDATAINTERFACETIMING
TxFIFO(TOP)FULL
TxRDY
7
F:TwoL—-]
TowR
/
TWCH	re—W	—
THAW
ReTXD(0-7)
RaTxEOF
TSRT—w|	THOA	TsAT—m|
THDA
COMMAND/STATUSINTERFACETIMING
LJf
w	X	/	/
TWEH	|,_toe0	|	Y0BR
Cast(0-7)
)_ >—_
Tscs NOTE+
THDA TDBS—=-f
NOTE1:Busisdrivenatthistime.However,
novalidinformationpresent.
Srrt——
1-11
MD400024/C

8003
SERIALTRANSMITINTERFACETIMING SERIALRECEIVEINTERFACETIMING
TPCK-
ARAR
TOTD, THAD
s	o	[==-TDOC-
-	£X	e	fi
TDRE_ TWRE-
ta—TDRI
TARET
oK,
L
[ 2l
IO
)
OrderingInformation
DQ8003
PACKAGE	TEMPERATURE	PARTTYPE
TYPE RANGE
D-CERAMICDIP	Q-0°Cto+70°C	EDLC
P-PLASTICDIP
N-PLCC
—SEEQ
Tecimetegy,neormorsins 1-12
MD400024/C
