# WD33C93A_Data_Sheet_and_Application_Notes_Nov1990

WESTERNDIGITALCORPORATION
WD33C93A
DATASHEETANDAPPLICATIONNOTES
WESTERNDIGITALCORPORATION
NOVEMBER,1990

IiWESIERNDIGITAL StorageLSIApplicationsNote
WDRegionalOffices
| WDLiterature(800)832-4778USA | U.S.A | California | (415)'335-2501 |
| --- | --- | --- | --- |
| (800)448-8470Canada | Georgia | (404)394-1480 |  |
| (714)932-4900lntemational | Illinois | (708)882-8731 Massachusetts (508)535-5914 |  |
| WDBBS: | (714)756-8176 Texas (214)991-6800 | NewJefSey | (201)285-1112 |
| Canada: | Ontario | (416)566-4702 Quebec (514)697-1532 PRODUCT:WD33C93A Sept15,1990 Number071-A WD33C93AApplicationNoteList |  |
| Number | A(fected | DescriPtion |  |
| E062-B | WD33C93.JAIB | VersionDifferences:Allchanges,additions,deletions,and pannumbersforeachofthereleasedversionsofthe WD33C93SCSIBusInterface Controller(SBIC)chip. |  |
| E031-A | WD33C93A | DataSheet:ContainsthedatasheetfortheWD33C93ASCSI BusInterfaceController(SBIC)chip. |  |
| E02S-A | WD33C93.JA | ConversiontotheAversion:Listofdesignconsiderations forconvertingtotheWD33C93Afromthenon-Aversion. |  |
| E018-A | WD33C93A | BugList:AllknownproblemsintheWD33C93A. |  |
| E022-A | WD33C93A | DRQBug,RevC,Donly:TheDRQsignalmayerroneously deassertforashorttimeundersomeconditions |  |
| E024-A | WD33C93.JA | DRQ/DACKinPolled1/0mode:DuringpolledI/Omode, theselinesshouldbeheldtoafalsestate. |  |
| E033-A | WD33C9x | SCSIsystemdesignissuesconcerningbusnoise:Apaperon thesourcesofnoiseontheSCSIbusandwhattodoabout them. |  |
| E039-A | WD33C93.JA | ACKassertiontiming:ACK\maybedeassertedpriorto REQ\ |  |
| E040-A | WD33C92/93.JA | ParityErrorsduringSelect-and-Transfer:Aparityerror maybemaskedbyotherinterruptconditions. |  |
| E042-A | WD33C92!3.JA | Synchronous/AsynchronousTransfers:Descriptionsandis- suesconcerningSBICchiptransfers. InternationalOffices: HongKong852-736-5123;Korea822-554-0508;Munich498-9922-0060;Ontario416-566-4702;Paris331-6985-5757; Quebec514-697-1532;Singapore65-448-4700;Taiwan886-2717-4775;Tokyo813-791-2001;U.K.443-7274-2955. COpyrightWestern0lglt811990 page'of2 |  |

StorageLSIApplicationsNote#071-A
| E043-A | WD33C93A | AuxiliaryStatusRegisterNotes:Mscnotesonuseandfunc- tionoftheAuxiliaryStatusregisteroftheSBICchip. |
| --- | --- | --- |
| E044-A | WD33C92/93.JA | AbortingaWait-for-Select-and-Transfer:Howtodoit... |
| E04S-A | WD33C92/93.JA | AddressTranslationTimes: |
| E046-A | WD33C92/93.JA | UnexpectedDisconnectaffectstransfercount:Internaland externaltransfercountsmaydifferinthiscircumstance. |
| E047-A | WD33C92/93.JA | Select-and-Transfercommandflowchart: |
| E048-A | WD33C92/93.JA | TargetModeVendorUniqueCDBs:HowtheSBIGchip handlesvarioussizesofCommandDescriptorBlocks.. |
| E049-A | WD33C92/93.JA | ALETimingrequirements:Maximumtimelengthspecifica- tion. |
| EOSO-A | WD33C92/93.JA | InitiatorModeVendorUniqueCDBs:HowtheSBICchip handlesvarioussizesofCommandDescriptorBlocks. |
| EOSI-A | WD33C92/93.JA | TargetMode-DelayofATNInterrupt:Timingirregularity. |
| E06S-A | WD33C92/93-all | HostTransfermodes:Descriptionsofthe4modesofdata transferbetweentheSBICchipandthehost. |
| E066-A | WD33C93A | Command/InterruptGuide:Amatrixofinterruptsandcom- mandsfortheWD33C93A. |
| E067-A | WD33C93A | SCSIStatusRegister:Descriptionoflogicorientationof SCSIphasebitsinthestatusregister. ---.--•.•.•..•..........--.•............_......._--....--...----.--..-..--.--..--.-........_--_....---.........._------ |
| E029-A | All | WDSalesOfficesbyRegion:ListofWDworldwidesales officeslistedbyregionofresponsibility. |
| E030-A | All | NorthAmericanDistributorsandResellers:Listofalldis- tributorsinNorthAmericabystate/province,listofallre- sellers. |
| E032-A | all | DecodingWDLSIpartnumbers:Top/bottomsidepart numberbrandingexplainedforLSIparts. |
| E070-A | All | ReservedRegisterBits:Defaultprogrammingofthesebits shouldalwaysbewithavalueofzero(0). NumberE071-A copyrightWesternDigital1990 page2o'~ |

e:IWESIERNDIGITAL StorageLSIApplicationsNote
WDRegionalOffices
| WDLiterature(800)832-4778USA | U.S.A | CalHomia | (415)335-2501 |
| --- | --- | --- | --- |
| (800)448-8470Canada | Georgia | (404)394-1480 |  |
| (714)932-4900lntemational | Illinois | (708)882-8731 Massachusetts (508)535-5914 |  |
| WDBBS: | (714)753-1234 Texas (214)991-6800 | NewJeTSey | (201)285-1112 |
| Canada: | Ontario | (416)566-4702 Quebec (514)697-1532 |  |
| PRODUCT: | Model#:WD33C93JAlB | August17,1990 |  |
| Manf#: | 3393,4393,5393,7393 WD33C93 VersionDifferences CurrentSales:WD33C93ArevF | NumberE062·B |  |
| FutureSales: | WD33C93B | Samplesin10/90,ProductionQuantityin1/91 Note:ThispartwillbesoldinadditiontotheWD33C93A WD33C93B (differencesfromWD33C93A) TheWD33C93BisfunctionalandperformanceimprovementovertheWD33C93A.Theadditions totheWD33C93BareforSCSI2supportandforimprovedsystemperformance.TheBpartis completelybackwardscompatible withtheApartandmayreplaceitinmostapplicationswithno hardwareorfirmwaremodifications(seenotefor#5).Someminorchangesarerequiredtomake useoftheadditionalfunctionsoftheBpart. 1.Addition:FastSCSI·TheWD33C93BsupportsfastSCSItransferratesofupto10MB/s. Bit7oftheSynchronousTransferregisterenablesfastSCSItransfers.Clockfrequenciesof between16and20Mhzarerequiredforthismode. 2. Addition:TagMessageSupport· a)MessageType:Bits3,4intheDestinationIDregisternowindicatethetypeoftagged messagesentorreceived: a0 NoMessage o1 SimpleQueuetag 10 HeadofQueuetag 1 1 OrderedQueuetag b)QueueTag:AQueueTagregisterhasbeenaddedtoholdthevalueofthesecondbyteof the tagmessagesassociatedwiththeSelect-and-Transfer,Reselect-and-Transfer,andWait- for-Select-and-Receivecommands 3.Addition:FIFOStatusBit- Bit3oftheAuxiliaryStatusregister(FFE)nowindicates FIFOfulloremptydependingonthedirectionoftransfer.ThebitindicatesFIFOempty (FFE=1)whentheJ.lpistransferringdataintothe12byteFIFO.ThebitindicatesFIFOfull whentheJ.lpisreadingfromtheFIFO.TheseenabletheJ.lptotransferupto12byteswith- IntematlonalOffices: HongKong852-736-5123;Korea822-554-0508;Munich498-9922-0060;Ontario416-566-4702;Paris331-6985-5757; Quebec514-697-1532;Singapore65-448-4700;Taiwan886-2717-4n5;Tokyo813-791·2001;U.K. 443-7274-2955. CopyrightWestemDigital1990 page'of9 |  |

StorageLSIApplicationsNote#E062-S
outtheneedtopolltheDBRoutputpriortoeachtransfer.
4.Addition:ReselectionInformation:Bit5oftheTargetLUNregisternowindicateswhat
typeofinfonnationisin thelowerbitsoftheTargetLUNregister: ..
oLogicalUnitNumber
1 TargetRoutineNumber
5.Addition:IncreasedTargetModeFaultSCSIBusTolerance- Thefollowingfeaturesaf-
fectonlytheTargetmodeofoperation.TheyareenabledbytheRAFbit(fonnerlytheErn
bit)intheOwnIDregister.ApplicationswhichusethisbitwiththeWD33C93Awillhave
tomodifyF/Waccordingly:
a)TransferErrorDetection:Whenenabled,theWD33C93BwillabortaSendorReceive
commandwitha25hinterruptifitdetectsapossibletransfercorruptioncausedby-noiseon
theREQandACKsignals.
b)UnexpectedBusFreeDetection(newtoTargetmode,alreadyexistsinInitiatormode):
Whenenabled,theWD33C93Bwillgenerateeithera85hor41hinterruptintheeventof
unexpecteddisconnection.ThisisintendedtocatchnoiseontheSELlinewhichcausesthe
devicetoerroneouslydisconnectfromtheSCSIbus.
Note:IfapplicationsmadeuseoftheEIHbitintheWD33C93A,theF/Wwillhavetobe
modifiedtoeitherdisablethebitoraccommodatethe additionaltypesofinterrupts.
6. WD33C93BNumberReference:
| Model# | Manr# | Description |
| --- | --- | --- |
| WD33C93BPL0002 | 7393KBIIPL | 40pinPlasticDIP |
| WD33C93B1M0002 | 7393KBI11M WD33C93BDifferencesfroWD33C93A NumberE062-S copyrightWesternDigital1990 page2of9 | 44pinPLCC |

StorageLSIApplicationsNote#E062-B
WD33C93A (differencesfromWD33C93)
1. HIWAddition:FasterTransferRate-
a)TheWD33C93Acannowtransferdataatupto5MB/s.
b)AburstDMAmodeontheIlPsidehasbeenaddedtohelpaccommodatehigherdata
bandwidths.Bit5oftheControlregisterhasbeenaddedtoenabletheDMAburstmode.
c)Themaximumclockfrequencyhasbeenincreasedto20Mhz
d)Selectabledividerscontrolledbybits7,6intheOwnIDregisterhavebeen addedto
managetransferrateandarbitrationtiming.
2. HIWAddition:HostParity- ThePLCCversionoftheWD33C93Anowsupportshost
paritygeneratingandchecking.
a)Bit5(EHP)oftheOwnIDregisterhasbeenaddedtoenabletheHostParityfeature.
b)Bit4(HHP)oftheControlregisterhasbeenaddedtoenableHaltonHostParityerror.
c)Pin11ofthePLCCis theJ.1pdataparitypin.Thispinwas"Test"andwasnotused
undernormaloperations.
3. HIWAddition:ExtendedFIFO- TheWD33C93AinternaldataFIFOhasbeenexpanded
to12bytesfrom5bytesfortheWD33C93.Bit3hasbeenaddedtotheoffsetcounterin
,theSynchronousTransferregistertoaccommodatetheincreasedFIFOsize.
4. HIWChange:FasterExecutionTimes- Thecommanddecodeandalgorithmsofmany
commandshavebeenmodifiedtogreatlyreducecontrolleroverheadinbothTargetandIni-
tiatormodes.
5. CmdAddition:Send-Status-and-Command-Complete(ODh)- Thistargetmodecom-
mandhasbeenaddedtotheWD33C93A.Thiscommandfirstsendsthestatusbyte,as
specifiedintheCDBbyte11.Thiscommandwillsendalinkedcommandcomplete
message.Linkedcommandcompletewithflagissentwhenbit1ofCDB12isset.The
commandwillalsochaintothecommandfetchportionofWAIT-for-Select-and-receive.
6. CmdAddition:Send-Disconnect-Message(OE)- Thistargetmodecommandisusedto
disconnectfromtheSCSIbuswhenthetargetexpectstoseek,findthefIrStblock,dealwith
longtapeoperations,fillabuffer,etc..Thecommandsendsthedisconnectmessage,fol-
lowedbyadisconnectfromthebus.IftheID!bitissettoone,aSave-Data-Pointermes-
sageissentpriortothedisconnectmessage.
7. CmdAddition:SetIDIbit(OF)- ThiscommandisusedtosettheIDIbitwhenalevelII
commandisinprogress.Thisisneededsincethe registerfileisnotaccessibletotheIlPat
thattime.
WD33C93ADifferencesfromWD33C93
NumberE062-B
copyrightWesternDigital1990 page30f9

StorageLSIApplicationsNote#E062-B
8. CmdDeletion:TransferPadCommand:TheTransferPadcommandisnolongersup-
portedintheWD33C93A.
9. CmdDeletion:AbortCommand:TheAbortcommandisnolongersupportedintheIni-
tiatormode.
10. FeatureAddition:AdvancedFeatureControl- Bit3(EAF)oftheOwnIDregisterhas
beenaddedtoenablethefollowingfeatures:
a)UnexpectedReselectionhandling:Followingareselectionbyanunexpectedtargetdur-
ingaSelect-andTransfercommand,byanunexpectedtargetduringaSelect-and-Transfer
command,orwhenidleandtheEnableReselectionbitis1,theWD33C93Awillcontinue
andgofetchtheidentifymessagebeforeinterruptingthehost.
b)UnknownCommandGroupsize:IntheTargetmode,ifthefIrstbyteoftheCOBisan
opcodeforanunknowncommandgroup(groups2,3,4,6,or7),thedevicewillinterrupt
thehostandaskforthetotalcommandlengthtobeloadedintotheOwnIDregister.This
featureisforWait-for-Select-and-ReceiveforSelect-and-Transferonly.
c)DataPhaseDirectioncheck:Bit6(DPD)hasbeenaddedtotheDestinationIDregister
tospecifytheexpecteddirectionoftheSCSIdataphase.Thisallowsanerrorconditionto
begeneratedifanincorrectdataphasehasbeengenerated.Thisfunctionisonlyapplicable
totheoperationofSelect-and-Transfercommands.
d)DataPhaseDirectionCheckDisable:Bit5(DF)hasbeenaddedtotheDestinationID
registertoenableordisableboththeDataPhaseDirectioncheckfeatureandthelinkfrom
Send-Status-and-Command-CompletetoWait-for-Select-and-Transfer.Note:Thisfeature
is isonlyintherevisionEandFparts.
11. FeatureAddition:NewStatusCodes- Thefollowingstatuscodeshavebeenadded:
a)WD33C93AAdvancedFeaturesEnabled-code00000001:Thiscodeisreturnedaftera
"SoftReset"iftheEnableAdvancedFeatures(EAF)bitisset(bit4,OwnID).Thecode
providesameansofverifyingthepresenceoftheApart.
b)UnexpectedReselection-code00100111:Thiscodeisreturnedwhenanunexpected
reselectionoccursduringaSelect-and-Transfercommand,andindicatesthattheTarget
LUNregistercontainsavalididentifymessage.
c)Reselection-code10000001:Thiscodeisreturnedwhenareselectionoccurswhenthe
deviceisidlingwithAdvancedfeaturesModeenabled.ThecodeindicatesthattheData
registercontainsavalididentifymessage.
d)DevicePause-code10000111:Thiscodeisreturnedwhen thedevicehaspausedtoget
thecommandlengthintheOwnIDregister. .
12. FeatureAddition:Reselect-and-TransferCmdEnhancement:Thesecommandsmay
nowberesumedinthesamemannerastheinitiatorSelect-and-Transfercommands.Also,
WD33C93ADifferencesfromWD33C93
NumberE062-B
copyrightWesternDlglta11990 page4of9

StorageLSIApplicationsNote#E062-B
thesecommandsmaybechainedtothenewSend-Status-andCommand-Completeand
Send-Disconnect-MessagecommandsusingtheED!bitinthecontrol register,andthe
commandlinkselectbitinthedestinationIDregister.
13.FeatureAddition:Wait-for-Select-and-ReceiveCmdEnhancement:Thiscommand
maynowberesumedinthesamemannerastheinitiatorSelect-and-Transfercommands.
Also,thiscommandmaybechainedtofromthenewSend-Status-and-Command-Complete
command.WhenED!isset,thiscommandwillchaintotheSend-Disconnect-Message
commandifCDBbyte1indicatesareadcommandhasbeenreceived.
14.FeatureAddition:20MHzclockrate:TheinputclocktimingsfortheWD33C93Ahave
beenchangedfromthoselistedintheWD33C93Adatasheet,whichspecifiedamaximum
frequencyof16Mhz.TheWD33C93Aisnowguaranteedtooperatewithamaximum
inputclockfrequencyof20MHz,andtherevisedtimingsarelistedbelow:
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| Tcp | ClockPeriod | 50 | 125 | os |
| ClockHigh | 20 Teh | os |  |  |
| ClockLow | 20 Tel . · . · Tep :~ ..: · · Clk I( \ \ I · · | os |  |  |
| ~~ | .~~ | .~ |  |  |
| · | · | Tel Teh · |  |  |
| · | · | 14. 15.FunctionChange-SinglebyteTransfers:TheWD33C93didnotcorrupttheTransfer CountregisterduringaSingle-Byte-Transfer.This allowedapreviousmulti-byte operation toberesumedwithoutreloadingtheTransferCountregisterafteraSingle-Byte-Transfer command.Thiswasan"undocumentedfeature"that,nolongerexistsintheWD33C93A. TheTransferRegisteriscorruptedduringaSingle-Byte-Transferandmustbereloaded afterexecutionofthatcommand. 16.FunctionChange-PhaseInterrupts: TheWD33C93generatesaPhaseChangeinterrupt followinganInvalidCommandinterrupt.Thisisanunnecessaryinterruptandbasicallyan unplanned"feature"oftheWD33C93.TheWD33C93Adoesnotprovide aPhaseChange interruptfollowingaInvalidCommandinterrupt WD33C93ADifferencesfrom WD33C93 NumberE062-B copyrightWesternDigital1990 page50f9 |  |  |

StorageLSIApplicationsNote/IE062-B
17.MscChanges!Additions:
a)COBbyte11register:Thisregisterisnowalsousedtospecifythestatusbytefor~end­
Status-and-Command-Completecommands
b)COBByte12register:WhentheFlagbit(Bit1)is0and101isI,LinkedCommand
Complete(messagecode=OAh)issentduringaSend-Status-and-Command-Complete
command.Whenthisbitis1and101isI,LinkedCommandCompletewithFlag(message
code=OBh)issentduringaSend-Status-and-Command-Completecommand.
c)TargetLUNregister:Thisregistercanalsocontaintheidentifymessag,ereceiveddur-
inganunexpectedreselectionifadvancedfeaturesareenabled.
d)SelectCommandChainControl:Bit7(SCC)intheDestination10registerhasbeen
addedtocontrolwhichcommandischainedtowhenthedatatransferiscompleted:
oChaintoSend-Status-and-Command-Complete
1ChaintoSend-Disconnect-Message
18.RevEandFChangesonly:ThefollowingchangeswereincorporatedintorevisionsE
andFonlyoftheWD33C93Apart.RevisionFisthecurrentproductionpart.
a)EnableImmediateHalt:Bit5(EIH)hasbeenaddedtotheOwn10register.This
TargetmodefeatureallowsanimmediatehalttooccuronSCSIparityerrororifATNand
HAare bothtrueinsteadofwaitingfora4kdataboundarytooccur.
b)Bit5(OF)hasbeenaddedtotheDestination10registertoinhibitboththeDataPhase
DirectioncheckintheAdvancedFeaturesmodeandthelinkfromSend-Status-and-Com-
mand-CompletetoWait-for-Select-and-Transfer.
19.RegisterDifferenceSummary:
| Register | Bit | WD33C93 | WD33C93A |
| --- | --- | --- | --- |
| a)Own10register: | 3 | EAF-EnableAdvancedFeatures 4 HHP-HaltonHostParityerror 5 EIH-EnableImmediateHalt 6,7 Xfrratecontrol |  |
| b)Controlregister: | 5 | DBA-DMABurstEnable |  |
| c)Destination10register: | 5 | DF-DataPhaseDirChkEnable 6 DPD-DataPhaseDircheck 7 SCC-SelectCommandChain |  |
| d)COBByte12register: | 1 | LCC-LinkedCommandControl |  |
| e)SynchXfrregister | 3 | extrabitfor12byteFIFO WD33C93ADifferencesfromWD33C93 NumberE062-B copyrightWesternDigital1990 page6of9 |  |

StorageLSIApplicationsNote#E062-8
20.WD33C93AIncompatibilitieswhenbeingusedwithaWD33C93alsoontheSCSI
bus:
PerformanceoptimizationofboththeinternalmicrocodeandtheLSIdesignhaveresulted
inthefollowingincompatibilitiesbetweentheWD33C93AandtheWD33C93: .
a) WD33C93offsetvalues:Duetotimingdifferencesbetweenthetwoparts,the
WD33C93offsetmustnotbesettoits maximumvalueoffiveduringsynchronous
transfersfromtheWD33C93AtotheWD33C93.Anyotheroffsetvalue(0through4)may
beused.
b) TheWD33C93AchecksforATN\assertionbeforethestartofadatatransfer.ARe-
ceiveorSendcommandwillhaltifHAissetpriortothetransferofanydata.The
WD33C93allowsadatatransfertooccurbeforelookingforATN\
21.FunctionChange-47hinterruptdifference:The47hinterruptintheWD33C93isgen-
eratedforaparityerrorinthestatus,message,orcommandbytesaswellasforanincorrect
message.The47hinterruptintheWD33C93Aisonlygeneratedforaparityerrorinthe
statusbyte.A4Fhinterruptisnowgeneratedforaparityerrorinthemessageorcommand
bytesaswellasforanincorrectmessage.The43hinterruptisgeneratedforallotherparity
errors(data/commandbytes).
Todeterminethecauseofa4Fhinterrupt,issueaTransferInformationcommand.Eithera
messagebyte(ifanincorrectmessage)ora43hinterrupt(ifaparityerror)willresult.
22.FunctionChange-InterruptDifference:A13hinterruptisgeneratedafterSelectionhas
occurredandanAbortcommandhasbeenissued.TheWD33C93versionissueda23hin-
terrupt.
23.FunctionChange-MR(MasterReset)Input:Ahardreset(MRpininput)resetsonly
theOwnIDregister.TheWD33C93hardresetclearsallregisters.Allotherfunctionsof
thehardresetareunchanged.
24.SynchronousTransferPeriodchange:TheprogrammingoftheSynchronousTransfer
PeriodregisterhaschangedfromtheWD33C93.Previouslyitwasnecessarytoprogram
thedesiredvalue+1.IntheWD33C93A,thedesiredvalueisdirectlyprogrammed(aperi-
odof3clocksisnowprogrammedas"3"ratherthan"4"asintheWD33C93).
25.RCSpulseinWD-Busmode:TheWD33C93AnolongertheRCSlinetoindicate a .
ReadytoTransferstate.AfterthemicroprocessorissuesacommandtotheSBICchip,the
microprocessorshouldthenassertDRQwhenitisreadyfordatatransfer.TheSBICwill
sampletheDRQlineandbegindatatransferwhenready.
WD33C93A DifferencesfromWD33C93
NumberE062-8
copyrightWesternDigital1990 page70t9

StorageLSIApplicationsNote#E062·B
26.TimingDifferences:
| Mode | WDJJC2J | WDJJC2JA Simal | MaxLMiD |
| --- | --- | --- | --- |
| PIO | 10 | 5 | nsmin |
TRHDI
DMA	40-90	nomin-75	nsmin-max
TDI.QH
30	0	nsmin
TOHQL
TSHWI	WD·Bus	0	nominspec	nsmin
0	nominspec	nsmin
TSHRI
T	20	30	nsmax
SLWV
T	20	30	nsmax
SLRV
30	20	nsmin
TWHDI
10	20	nsmin
TOVRH
10	0	nsmin
TRHDI
Async-Target	5	0	nsmin
TOVAL
0	replacedbyTALDI	nsmin
TRHDI
0 nsmin
TALDI
-Initiator	0	replacedbyTRHDI	nsmin
TAHDI
0 nsmin
TRHDI
Sync-Target
TRHDI
TRHOI -Initiator
27.ICCSpecifcationchange:Themaximumspecificationforthesupplycurrenthasbeenin-
creasedfrom20mato36ma.
28.WD33C93ANumberReference:
| Modell | Manfl | Description |
| --- | --- | --- |
| WD33C93APL0008 | 5393KF09PL | 40pinPlasticDIP |
| WD33C93A1M0008 | 5393KF09JM WD33C93ADifferencesfromWD33C93 NumberE062·B copyrightWesternDlglta11990 pageBof9 | 44pinPLCC |

StorageLSIApplicationsNote#E062·B
WD33C93NumberReference:
| ~odel# | ~anf# | Description |
| --- | --- | --- |
| WD33C93PL00bb | 3393AB09PL | 40pinPlasticDIP |
| WD33C93JM00bb | 3393AB09JM ChangesfromApplicationsNoteE035revA: - Items21through27whereaddedtothedifferenceslistforWD33C93A. WD33C93ADifferencesfromWD33C93 NumberE062-B copyrightWesternDigital1990 page90f9 | 44pinPLCC |

seeWESIERNDIGITAL StorageLSIApplicationsNote
WDReglonslOffices
| WDLiterature(800)832-4778USA | U.S.A | Califomia | (415)335-2501 |
| --- | --- | --- | --- |
| (800)448-8470Canada | Georgia | (404)394-1480 |  |
| (714)932-4900International | Illinois | (708)882-8731 Massachusetts (508)535-5914 |  |
| WDBBS: | (714)753-1234 Texas (214)991-6800 | NewJersey | (201)285-1112 |
| Canada: | Ontario | (416)566-4702 Quebec (514)697-1532 |  |
| PRODUCT: | Model# WD33C93A | August17,1990 |  |
| Manf# | 5393 | NumberE031-A WD33C93ADataSheet Contents: DataSheet WD33C93A: AMOSNLSI40/44pinchipprovidinghighandlowlevelinterfacefunctionsto theSCSIbus.FullSCSIbusfeaturesincludearbitration,disconnect,reconnect,paritygeneration andchecking,synchronousandasynchronoustransfersupto4Mbytes/s,DMA,andbuiltin48ma driversfordirectconnectiontoasingleendedSCSIbus.Themaindifferencesbetweenthe WD33C93Aandthepreviousversion(WD33C93) arefastertransferrates,hostparitygeneration andchecking,anextendedFIFO,fastercommandexecutiontimesandanumberofnewcom- mands.FormoreinformationonthesechangesandadditionsrefertoWDStorageLSI ApplicationsNote#E062. SourceDocument#:79-000199, WD162786/88 PanNumbers: |  |
| Model# | Manr# | Description |  |
| WD33C93APL0008 | 5393KF09PL | 40pinPlasticDIP |  |
| WD33C93A1M0008 | 5393KF09JM InternationalOffices: HongKong852-736-5123;Korea 822-554-0508;Munich498-9922-0060;Ontario416-566-4702;Paris331-6985-5757; Quebec514-697-1532;Singapore65-448-4700;Taiwan886-2717-4n5;Tokyo813-791-2001;U.K.443-7274-2955. CopyrightWestemDigital1990 | 44pinPLCC |  |

WD33C93ASCSIBus
InterfaceController
FEATURES TheWD33C93Aisintendedforuseinsystemswhich
interfacetotheSCSI(SmallComputerSystemInter-
•ImplementsfullSCSIbusfeatures:arbitration,
face)Bus.TheWD33C93Acanoperateinboththe
disconnect,reconnect,paritygeneration/checking
Initiator(typically,ahostcomputersystem)andthe
onboth dataports,softreset,andsynchronous
Target(typically,aperipheraldevice)SCSIbusroles.
datatransfers.
Whenusedinthehostsystem,theWD33C93Ainter-
•AsynchronousDatatransfersupto2.5Mb/sec
facestoboththehostbusandtotheSCSIbus.To
•SynchronousDatatransfersupto5.0Mb/sec
performaSCSIoperation,thehostprocessormust
•Synchronousoffsetselectablefrom1to12bytes. issueacommandtotheWD33C93Atoselectthe
desiredTarget.TheWD33C93Athenarbitratesforthe
•Compatiblewithmostmicroprocessorsthroughan
SCSIbusandselectstheperipheralunit.Ifitfailstoget
8-bitdatabus;supportsbothmultiplexedandnon-
thebusbecauseofahigherprioritybusdevice,it
multiplexedaddress/databussystems.Hostbus
continuestrying,notifyingthehostwhenithassuc-
dataparitycheckingandgenerationisanoptional
ceededbygeneratinganinterrupt.AtthispOint,the
feature.
WD33C93Aisoperatingintheinitiatorrole.Whenthe
•Canbeusedashostadapter(SCSIInitiator)or
peripheralrequestsaSCSIcommandfromthehost,the
peripheraladapter(SCSITarget).
WD33C93Areceivestherequestandgenerates
•Localhostdatatransferoptionsinclude anotherinterrupttothehost.Thehostrespondstothis
programmedI/O,singlebyteDMA.burst(multibyte) interruptbyissuing  a"TransferInfo"commandand
DMA,ordirectbusaccess(WDbus)transfers. supplyingSCSIcommandbytestotheWD33C93A.
TheWD33C93AtransferstheSCSIcommandtothe
•Includes48-madriversfordirect connectionto
peripheral,andthenwaitsforthenextbusphase
theSCSIbus.
request.ThisprocesscontinuesuntilallSCSIinforma-
•24bittransfercounter.
tionincludingdata,status,andmessageshavebeen
•Programmabletimeoutforselectionandreselection. transferred.
•InternalMicrocontroller TheWD33C93AalsooffershighlevelSelect-And-
Transfercommands,whichmaybeusedtoeliminate
•"Combination"commandsgreatlyreduceinterrupt-
theinterrupt-handlingwhichisotherwisetypically
handlingresponsibilities.
requiredbetweeneachSCSIbusphase.
•Special"TranslateAddress"commandperforms
WhentheWD33C93Aisusedinaperipheralsystem,it
theLogical-to-Physicaladdressedtranslation.
interfaceswithalocalprocessorandtheSCSIbusjust
•Single+5Vsupply.
asitdoeswhenusedasahostadapter.Inthisenviron-
•Availablein44-pinchipcarrieror40-pinDIP. ment,theWD33C93AwilloperateprimarilyinaTarget
role.TheTarget-rolecommandsetenablesthe
•LowpowerCMOSdesign.
WD33C93Atoreql:festeachSCSIbusphaseindividu-
ally,orthespecialcombinationcommandsmaybeused
DESCRIPTION forautomaticSCSIbusphasesequencing.
TheWD33C93AisaMOSNLSIdevicewhichisimple- TheWD33C93Ahasaninternalmicrocontroller,areg-
mentedinWesternDigital'sCMOSprocess.Itoperates istertaskfile,andSCSIinterfacelogic.Thisarchitec-
fromasingle5voltsupplyandisavailableineithera44- turesupportsbothtightcontroloftheprotocolfornon-
pinchipcarrierora40-pindual-in-linepackage.All standardSCSIimplementations,aswellasahands-
inputsandoutputsareTIL-compatible. freemodeforstandardSCSIapplications.
.,ESTERNDIGITAl.

1/0
| 1 | 40 | vee |
| --- | --- | --- |
| ~ | 2 | 39 REO |
| GNO | 3 | 38 ACR |
| CIO | 4 | 37 ATI\l |
| SSY | 5 | 36 ~ |
| SEE | 6 | 35 GNO |
| elK | 7 | 34 SOi |
| ORO | 8 | 33 S06 |
| OACR | 9 | 32 S05 |
| INTRa | 10 | 31 S04 |
| DO | 11 | 40-PIN 30 S03 |
| 01 | 12 | 29 ~ |
| 02 | 13 | DIP 28 GNO |
| 03 | 14 | 27 SOl |
| 04 | 15 | 26 SOC |
| 05 | 16 | 25 SOP |
| 06 | 17 | 24 ALE |
| 07 | 18 | 23 RE |
| AO | 19 | 22 WE |
| GNO | 20 | 21 CS |
| G S | S | S S S S G S S |
| N 0 | o(N.C.)O | 0 0 0 N 0 0 |
| D° 7 | 6 | 5 4 3 2 0 1 0 |
| -  -  - | - | - - - 39   383736   35 34   3332 31 3029 28 SOP ~ 40 |
| 41 | 27 | ALE ATI\l 26 RE ACR 42 25 WE REO 43 24 CS vee 44 |
| (N.C.) | 23 | GNO --. 22 (N.C.) i/o 2 |
| 3 | 21 ~ | AO |
| GNO | 4 | 20 07 |
| C/O | 5 | 19 |
OS
18 05
SSY 6
| 7 | 8 | 9 | 10 11 12 13 14 15 16 17 |
| --- | --- | --- | --- |
| S | e 0 | 0 | 0 I 0 0 0 0 0 |
| E | l | R A P | N 0 1 2    3 4 |
| l   Ka | e K R a NOTE: PinlabeledN.C.shouldbeleftnotconnected. | T |  |
2

4. PINDESCRIPTIONS
4.1 PROCESSOR/DMAINTERFACE
DIP PLCC
| (40PIN) | (44PIN) | NAME | 1/0 | FUNCTION |
| --- | --- | --- | --- | --- |
| 7 | 8 | ClK | I | 8-16MHzsquarewaveclock. |
| 36 | 40 | MR | I | Resetisanactivelowinputwhichforcesthe WD33C93Aintoanidlestate.AllSCSIsignalsare forcedtothenegatedstate. |
| 10 | 12 | INTRa | 0 | InterruptRequesttoexternalmicroprocessor. Usedtoindicatecommandcompletion/termination oraneedtoservicetheSCSIinterface.Thisbitis resetwhentheSCSIStatusregisterisread. |
| 23 | 26 | RE | 1/0 | Readenableisanactivelowinputwhichisused withCS-toreadaWD33C93Aregister.InWDBus mode,itisusedasanoutputtoreaddatafroma sectorbuffer.(Tri-State) |
| 22 | 25 | WE | 1/0 | Writeenableisanactivelowinputwhichisused withCS-towriteaWD33C93Aregister.InWD Busmode,itisusedasanoutputtowritedatato asectorbuffer.(Tri-State) |
| 21 | 24 | CS | I | ChipSelectisanactivelowinputwhichisusedto qualifyRE-andWE-whenaccessingaregister. ThissignalmustbeinactiveduringaDMAcycle (DACK-activeinDMAlburstmode,orOROactive inWDBusmode). |
| 19 | 21 | AO | I | Addresspinusedtoaccesstheinternalregisters fornon-multiplexedaddress/databusses(Le.,the ALEpinisgrounded).Theaddressofthedesired registerisloadedintotheAddressregisterduring awritecyclewithAO=O.Theselectedregisteris thenaccessedwhenAO=1. |
| 24 | 27 | ALE | I | AddresslatchEnableisusedformultiplexed address/databussestoloadtheaddressofthe desiredWD33C93Aregisterfromthedatabus. Ifindirectaddressingistobeused,theALEpin shouldbegrounded.Seethedescriptionofthe Addressregisterforacompletediscussionof directandindirectaddressing. |
| 9 | 10 | DACKI(RCS) | 110 | DMAacknowledgeinputusedfor interfacingtoan externalDMAcontroller.WhenDACK islow,allbustransfersareto/fromtheDataregis- terregardlessofthecontentsoftheADDRESS register.InWDBusmode,thispinfunctionsasa RAMchipselectoutputtoallowtheWD33C93A toaccessasectorbuffer.RE-andWE-areoutputs whenRCS-isactive.Sincethispincanbe anopendrainoutput,apullupresistorisrequired whenoperatinginWDBusmode. |
| S | 9 | ORO/(ORO) | 110 | Datarequestisanoutputwheninterfacingtoan externalOMAcontroller,andaninputwhenin. WOBusmode.WhenusedwithanexternalDMA controller,ORO-andOACK-formthehandshake forthedata-bytetransfers.InBurstmode,ORO- remainslowaslongasthereisdatatotransfer.In WOBusmode,theWD33C93Aperformsburst transferswhileOROishigh,andwhenOROislow, datatransfersareinhibited,RCS-isfalse,and'the RE-andWE-outputsaredisabled.Sincethispin canbeanopendrainoutput,apullupresistoris requiredwhenoperatinginDMAorBurstmode. |
| 18-11 | 17-13 | 07-00 | 110 | Hostprocessordatabus. |
| 11 | OP | 110 | DataParity,usedonlyforchecking/generating hostdatabusparityduringdatatransfers.(odd) |  |
3

4.2 SCSIINTERFACE
Note: Allpinshaveopen-drainoutputdrivers.
DIP PLCC
| (40PIN) | (44PIN) | NAME | 110 | FUNCTION |
| --- | --- | --- | --- | --- |
| 39 | 43 | REO | I/O | REO-isaninputintheinitiatorroleandanoutput inthetargetrole.ItindicatesarequestforaREO/ ACKdatatransfer. |
| 38 | 42 | ACK | I/O | ACK-isanoutputintheinitiatorroleandaninput inthetargetrole.Itisusedtoindicatean acknowledgementforaREO/ACKdatatransfer, handshake. |
| 37 | 41 | ATN | 1/0 | ATN-isanoutputintheinitiatorroleandaninput inthetargetrole.ItisusedtoindicatetheSCSI Attentioncondition. |
| 2 | 3 | MSG | I/O | MSG-isaninputintheinitiatorroleandanoutput inthetargetrole.ItisassertedduringaMessage phase. |
| 4 | S | C/O | 110 | C/O-isaninputintheinitiatorroleandanoutputin thetargetrole.Itisusedtoindicatewhether ControlorDatainformationisontheSCSIdata bus. |
| 1 | 2 | 1/0 | 110 | 110-isaninputintheinitiatorroleandanoutputin thetargetrole.Itcontrolsthedirectionofdata movementontheSCSIdatabuswithrespecttoan Initiator. |
| S | 6 | BSY | 1/0 | BSY-isassertedwhentheW033C93Ais attemptingtoarbitratefortheSCSIbusorwhen connectedasaTarget. |
| 6 | 7 | SEL | 110 | SEL-isassertedwhentheW033C93Ais attemptingtoselectorreselectanotherSCSI device. |
| N/A | 28 | SOP | 110 | SCSIdatabusparitysignal.(odd) |
| 34-26 | 38-29 | S07-S00 | 1/0 | SCSIdatabus. |

5. WD33C93ABLOCKDIAGRAM
SCSI. INTERNAL
BUS BUS
: ~...--
| SCSI | ... | REGISTER :+-~......-AO/ALE |
| --- | --- | --- |
| ARBITRATION | • | FILE PLA ANDSTACK ... CS- SCSI HOSTINTERFAC= ~ ~ |
| PARITY | • | DATABUFFERS • ... • RE- GEN/CHECKER PARITYGEN/CHEC<ER |
WE-
07
I
DO
DP
SCSIREO/ACK ...
~
HANDSHAKE	•	•	MICROCONTROLLE=
LOGIC
.......t---..~DRO-
DATABUFFERI TRANSFER
... ......t----....,~~DACK
12BYTEFIFO COUNTER
•
~
"'" ROM
PROGRAMCNT=·
5

6. WD33C93AREGISTERS
6.1 REGISTERMAP
ADDRESS
| AO | RIW | REGISTERACCESSED | (Hex) |
| --- | --- | --- | --- |
| 0 | R | AUXILIARYSTATUS | XX· |
| 0 | W | ADDRESSREGISTER | XX |
| 1 | RIW | OWN10REGISTER | ICDBSIZE 00 |
| 1 | RIW | CONTROLREGISTER | 01 |
| 1 | RIW | TIMEOUTPERIODREGISTER | 02 |
| 1 | RIW | TOTALSECTORSREGISTER | ICDB1ST 03 |
| 1 | RIW | TOTALHEADSREGISTER | ICDB2ND 04 |
| 1 | RIW | TOTALCYLINDERSREGISTER(MSB) | ICDB3RD 05 |
| 1 | RIW | TOTALCYLINDERSREGISTER(LSB) | ICDB4TH 06 |
| 1 | RIW | LOGICALADDRESS(MSB) | ICDB5TH 07 |
| 1 | RIW | LOGICALADDRESS(2ND) | ICDB6TH 08 |
| 1 | RIW | LOGICALADDRESS(3RD) | .ICDB7TH 09 |
| 1 | RIW | LOGICALADDRESS(LSB) | ICDB8TH OA |
| 1 | RIW | SECTORNUMBERREGISTER | /CDB9TH OB |
| 1 | RIW | HEADNUMBERREGISTER | ICDB10TH OC |
| 1 | RIW | CYLINDERNUMBERREGISTER(MSB) | ICDB11TH 00 |
| 1 | RIW | CYLINDERNUMBERREGISTER(LSB) | ICDB12TH OE |
| 1 | RIW | TARGETLUNREGISTER | OF |
| 1 | RIW | COMMANDPHASEREGISTER | 10 |
| 1 | RIW | SYNCHRONOUSTRANSFERREGISTER | 11 |
| 1 | RIW | TRANSFERCOUNTREGISTER(MSB) | 12 |
| 1 | , | RIW | TRANSFERCOUNTREGISTER(2NDBYTE) 13 |
| 1 | RIW | TRANSFERCOUNTREGISTER(LSB) | 14 |
| 1 | RIW | DESTINATION10REGISTER | 15 |
| 1 | RIW | SOURCE10REGISTER | 16 |
| 1 | R | SCSISTATUS | 17 |
| 1 | RIW | COMMANDREGISTER | 18 |
| 1 | RIW | DATAREGISTER | 19 |
| 1 | R | AUXILIARYSTATUS | (DIRECTADC;:::SSINGMODE) 1F NOTES: 1.Allunusedbitsofadefinedregisterarereservedandmustbezer: 2.Readinganundefinedorunavailableregisterresultsinanall-ones:latabusoutput. 3.RegisteraddressesaredeterminedbytheAddressregisterbitsA=OthruAR7. 4.Whenusingamultiplexedaddress/databuswithALE.theAOpin5ignoredandtheAddress registerisloadedwithALE.Inthismode.theAuxiliaryStatusregls:erismappedatHex1F. 5.Seesection6.3foradescriptionofhowresetaffectstheinternal~sgisters. |
6

6.2 REGISTERDESCRIPTIONS
6.2.1 AUXILIARYSTATUSREGISTER
(AddressHexIF)
TheAuxiliaryStatusregisterisaread-onlyregister
whichcontainsgeneralstatusinformationnotdirectly
associatedwiththeinterruptcondition.TheAuxiliary
Statusregistermaybeaccessedatanytime,except
duringDMAaccesses(DACK-assertedinDMAlBurst
mode,orOROassertedinWDbusmode).
| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| INT | LCI | BSY | CIP | 0 | 0 | PE | DBR |
| Bit0 | DBR DataBufferReadyisusedduringpro- grammed110toindicatetothepro- | Bit3 | Notused,willbezero. |  |  |  |  |
| Bit4 | CIP | COMMANDINPROGRESS,when cessorwhetherornottheDataregister set,indicatesthattheWD33C93Ais isavailableforreadingorwriting.Dur- interpretingthelastcommandentered ingSendorTransfercommandswhich intotheCommandregisterandthere- transmitdataovertheSCSIbus,the forethisregisterisunavailable.When DBRbitissetwhentheWD33C93Ais thisbitisreset,acommandmaybe readytotakeabytefromthehost; the writtentotheCommandregister. bitisresetwhentheprocessorwrites Bit5 BSY BUSYindicatesthataLevelIIcom- thebytetotheDATAregister.During mandiscurrentlyexecutingandthere- ReceiveorTransfercommandswhich foreonlytheCommandregister(when receivedataovertheSCSIbus,the CIP=0),theDATAregister,andthe DBRissetwhenabyteisreceived;itis AuxiliaryStatusregisterareaccess- resetwhentheprocessorreadsthe iblebythehost.ALevelIIcommand bytefromtheDATAregister. maynotbewrittentotheCommand |  |  |  |  |  |
| Bit1 | PE | ParityErrorstatusindicatesthateven registerwhenthisbitisone. paritywasdetectedonadatabyte |  |  |  |  |  |
| Bit6 | LCI | LASTCOMMANDIGNOREDindi- receivedduringaninformationtrans- catesthatacommandwasissuedby fer.Parityischeckedondatareceived thehostjustpriortoorconcurrentwith fromthehostbusduringtransfersout apendinginterrupt,andthereforethe totheSCSIbus,andischeckedon commandwillbeignoredandthissta- datareceivedfromtheSCSIbus dur- tusset. ingtransfersouttothehostbus. |  |  |  |  |  |
| Detectionofaparityerrorwillsetthe | Bit7 | INT | INTERRUPTPENDINGindicatesthat PEstatusbitregardlessofthestateof theIntrqpinisasserted.Thehost theHHPorHSPbitsintheControl shouldreadtheSCSIStatusregister register.ThePEbitisclearedwhena toclearIntrqpriortoissuingany newcommandisissued. commands. Bit2 Notused,willbezero. |  |  |  |  |
7

| 6.2.2 ADDRESSREGISTER | 6.2.3 | OWNID/CDBSIZEREGISTER [AddressXXHex] [Address00Hex] TheAddressregisterisawrite-onlyregisterwhich TheOwn10/COBSizeregister,initsfirstmode,con- containstheaddressoftheregistertobeaccessed. tainsboththeencoded10oftheW033C93Aonthe RegistersintheWD33C93Amaybeaccessedinoneof SCSIbusandseveralcontrolbitsthatareusedto twoways: initiallyconfigurethedeviceduringthe"Reset"com- mand.Thesebitscontrol'advancedfeature'selection, eDirectaddressing(multiplexedaddress/databusses). hostbusparityenable,andselectionoftheinputclock Indirectaddressing,thefallingedgeoftheALEsignal division.Initssecondmode(whenadvancedfeatures isusedtolatchtheaddressintotheADDRESSregis- areenabled,see7.3),thisregisterisusedduringthe ter.TheALEistypicallythenfollowedbytheCS-and combinationcommandstospecifytheSCSICOBsizeif WE-orRE-signalsthataccesstheselectedregister. thecommandgroupisunknowntotheWD33C93A. Also,indirectaddressing,theAUXILIARYSTATUS registerislocatedataddress1 FHex., Inthefirstmode,thisregister(asdefinedbelow)is sampledandbecomeseffectiveonlyaftera"Reset" elndirectaddressing(separateaddress/databusses). commandisissuedtothedevice.Thisregistermustbe Inindirectaddressing,theregisteraccessisper- initialized,andthena"Reset"commandissued,toset formedintwoseparatecycles.Thismethodis theSCSIbus10.theclockdivisor.andtheoperating enabledbyattachingALEtoground.First,the modesbeforeanyothercommandsareissued. Addressregisterisloadedbyperformingawriteofthe desiredaddresstotheWD33C93A(WE- andCS- Inthesecondmode.bits3-0ofthisregisterareused asserted)withAO=O.Thentheregisterisaccessed duringtheSelect-and-TransferandWait-for-Select byassertingCS-andWE-orRE-,withAO=1.Also. commandstospecifytheSCSICommandDescriptor followingeveryaccesswithAO=1,theAddressregis- BlocksizeifitisnotagroupO.group1.orgroup5 terwillautomaticallyincrementtopointatthenext command.Thismodeisenabledonlywhenadvanced register,withtheexceptionofthefollowinglocations: featuresareenabled(see7.3). AuxiliaryStatusregister,Dataregister,andtheCom- mandregister.Inindirectaddressing,theAuxiliary Statusregisterisaccessedbyperformingaread(CS- andRE-asserted)withAO=O. OWNID/CDBSIZEREGISTER |
| --- | --- | --- |
| 7 | 6 | 5 4 3 2 1 0 |
| FS1 | FSO | 0 EHP EAF 102 101 100 |
| Bit0-2 | IOn | SCSI10Bits0-2settheSCSIbus10 Statusregisterwillindicateparity numberthattheW033C93Awilluse errorsdetectedonthehostbus,and duringarbitrationandselection. theHHPbitintheControlregisterwill beused.Whenthisbitiszero,no Bit3 EAF ENABLEADVANCEDFEATURES, checkingisperformedonthehostbus; whensettoone,causesthe thePEbitisnotsetwhenaparityerror W033C93Atoenablecertain isdetectedonthehostbus.andthe advancedfeatures(seesection7.3). HHPbitmustbesettozero. Whenthisbitiszero,thosefeatures aredisabled. NOTE:Parityisalwaysgeneratedon thehostdataparitybit(DP).regard- Bit4 EHP ENABLEHOSTPARITY.whensetto lessofthestateofthisbit. one,enablesoddparitycheckingon |
| thehostbus;thePEbitintheAuxiliary | Bit5 | Notused.willbezero. |
8

Bit6-7	FSn	FREQUENCYSELECT0-1selectthe	showsinputclockfrequencyranges
divisorthatisappliedtotheinput andthecorrespondingdivisors.The,
clock.Theresultingclockisusedfor correctdivisorfortheinputclockmust
datatransfertimingandforSCSIbus beused,orSCSIbustimingspecifica-
arbitrationtiming.Thetablebelow tionsmaynotbemet.
INPUTCLOCK
RESULTING
FREQUENCY	FS1	FSO
DIVISOR
(MHZ)
| 8-10 | 0 | 0 | 2 |
| --- | --- | --- | --- |
| 12-15 | 0 | 1 | 3 |
| 16 | 1 | 0 | 4 |
| xx | 1 | 1 | undefined Notethatan11MHZclockrateshouldnotbeused,astheresultingSCSIbusclear delaymayviolateSCSI specifications.TheformulaforcomputingthemaximumSCSIdatatransferrateis: MAXIMUMSCSITRANSFERRATE= INPUTCLOCKFREQUENCY [MByte/sec] |
CLOCKDIVISOR
6.2.4 CONTROLREGISTER
[Address01Hex]
TheCONTROLregisterisusedtoenable/disablecer-
tainfunctions,suchasresponsetoparityerrorsandthe
SCSIattentioncondition,interrupthandling,anddata
transfermodes.
BIT	7	6	5	4	3	2	1	0
oM2 oM1	oMO	HHP	Eol	101	HA	HSP
Bit0	HSP TheHALTonSCSIPARITYERROR	Bit1	HA	TheHALTonATTENTIONbit(inTar-
bitenablestheW033C93Atotermi- getmodeonly)enablesthe
nateaReceiveorTransfercommandif W033C93AtoterminateaSendor
aparityerrorisdetectedonanincom- ReceivecommandiftheATN-inputis
ingSCSIdatabyte.IntheInitiatorrole, asserted.Thisnormallyindicatesthat
terminationduetoaSCSIparityerror theInitiatordetectedaparityerror
causestheACK-pintobeleftinthe whilereceivingdatafromthe
activestateinordertoinhibitanyaddi- W033C93A.TheATN-inputistested
tionaldatatransfers(REQs)bythe beforethestartofadatatransfer,
Target;thisfacilitateserrorhandling every4096bytesifthetransfercount
withtheTarget.Synchronousdata isgreaterthan4096,andaftertheend
transferscheckparityevery4096 ofthetransfer.These··ulesapplyto
bytes,orattheendoftheremaining bothsynchronousandasynchronous
transfercount,whicheverisless. transfers.
Asynchronoustransferscheckparity
oneverybyte.
a

| Bit2 | 101 | TheIntermediateDisconnectInterrupt bit.whenset.enablestheW033C93A reducedhostsystemoverhead.Refer togenerateana5Hdisconnectinter- toSection7formoredetails. ruptandsuspendsaSelect-and- Bit4 HHP TheHaltonHostParityErrorbit TransfercommandiftheTargetdis- enablestheWD33C93Atoimme- connectsaccordingtothedefined diatelyterminateaSend'orTransfer SCSIprotocol.Whenthisbitisreset. commandifaparityerrorisdetected nointerruptisgeneratedbyavalid onanincominghostdatabyte.Host disconnect.Thisfeature.whenused parityerrorsarecheckedaccordingto withtheResumeSATcommand. therulesforcheckingSCSIparity providessupportforoverlappedSCSI errors.However.ahaltonahostparity operations.101isalsousedtoselect errorwillnotholdtheACK- signal executionoptionsinTargetmodecom- assertedwhenanerroroccurs.Host binationcommandsthatserveto paritycheckingisperformedatthe reducehostsystemoverhead.Referto sameintervalsasSCSIparity Section7formoredetails. checking. | betweenthosecommands.resultingin |
| --- | --- | --- | --- |
| Bit3 | EOI | WhentheEndingDisconnectInterrupt Bit5-7 DMx DMAModeSelectbits2-0areusedto bitisset.the16Hinterruptwhichnor- selecttheDMAmodeofoperation. mallyfollowstheCommandComplete whichdescribesthehostbustransfer messageduringtheexecutionofa modeusedduringDataInorDataOut Select-And-Transfercommandwillbe phases.Thefollowingtabledescribes suppresseduntiltheTargetdiscon- thedifferentDMAmodes.andthe nectsfromtheSCSIbus.EOIisalso stateofthesebitstoselectthem: usedintheTargetmodecombination commandstoenablechaining |  |
| DM2 | DM1 | DMO | DMAMODESELECTED |
| 0 | 0 | 0 | Polled110Mode,ornoDMAenabled.Alldataphasetransfersare performedbypollingforDBRintheAuxiliaryStatusregister,aridthen writing(reading)thedatato(from)theDataregister. |
| 0 | 0 | 1 | BurstModeselectsademand-modeDMAinterface.Inthismode, the ORO..signalwillbeactiveaslongasthereisdata/spaceintheinternal FIFOtoallowthetransfertocontinue.TheDMAcontrollerrespondsby assertingDACK-andRE-IWE-aslongasDRO-isactive. |
| 0 | 1 | 0 | WDBusModeshouldbeselectedwhentheWD33C93Aisconnectedtoa WDBus.ThismodeisalsoreferredtoasDirectBufferAccess(DBA) mode. Inthismode,theWD33C93Aactsasabusmaster,andalldataaccess signalsreversetheirdirection:TheORO-signalbecometheOROinput, whichenablestheW033C93Atodrivethebufferbuscontrolsignals. TheOACK-signalbecomestheRCS-output,whichisassertedasachip selectforthebuffer.RE-andWE-becomeoutputswhichdrivetheread andwritefunctionsoftheexternalFIFO/RAMbuffer.AslongastheORO signalisasserted,transferswillcontinuein.aburstmanner,untilthe transfer iscompleteorthehost/localupdecidestopausethetransferby negatingtheOROsignal;afternegatingORO,onemoretransfer may occurbeforetheRCS-.RE-,andWE-signalsarenegated. |
| 1 | 0 | 0 | OMAModeisselectedwhentheW033C93AistobeusedwithaOMA controllerinsingle-typetransfermode.Inthismode,ORO-isasserted andthennegated,andtheOMAcontroller respondsbyassertingOACK- andWE-orRE-,foreachdatabytetransferredto/fromtheW033C93A. |

| 6.2.5 | TIMEOUTPERIODREGISTER | Select-And-Transfer:Thisregistershouldbeloaded withthethirdandfourthbytesoftheCOBbeforeissuing [Address02Hex] aSelect-And-Transfercommand. TheTimeoutPeriodregisterisanS-bltregistercontain- Wait-For-Select-And-Receive:TheW033C93Awill ingapresetvaluewhichdeterminesthetimeoutperiod forSelectandReselectcommands.Thisvaluemaybe storethethirdandfourthbytesofthereceivedCOBin thisregister. calculatedasafunctionoftheinputclockfrequencyand thedesiredtimeoutperiod,asshowninthefollowing 6.2.9 LOGICALADDRESSREGISTERI equation: COB5TH-8THBYTES[Address07, registervalue=Tper*Ficlk 08,09,OAHex] BOd Where: TranslateAddress:ThelogicalAddressregisterisa 32-bitregisterwhichshouldbeloadedwiththelogical Tper =thedesiredtimeoutperiodinmilliseconds; addresstobetranslatedpriortoissuingtheTranslate Ficlk =theinputclo(;kfrequencyattheClKpinin Addresscommand. Megahertz(withnodivisorapplied). |
| --- | --- | --- |
| d | =decimal | Select-And-Transfer:ForsixbyteCOBs.onlythefirst twobytesofthisregisterareloadedwiththefifthand Theconstant'SO'scalestheunitsoftheequation,asis sixthbytesoftheCOB.FortenandtwelvebyteCOBs. basedontheinternaltimeoutcycletime.Theuser thisregisterisloadedwiththefifth.sixth,seventh,and shouldroundtheresulting'registervalue'uptothenext eighthbytesoftheCOB. integralvaluetoensurethattheuser'sminimumtimeout requirementismet. Wait-For-Select-And-Receive:TheW033C93Awill storethefifth,sixth,seventh(ifany).andeighth(ifany) ThetimeoutperiodspecifieshowlongtheW033C93A bytesofthereceivedCOBinthisregister. willwaitforaresponse(indicatedbyassertionofthe BSY- signal)afterithasbeguntheselectionphase 6.2.10 SECTORNUMBER (assertSEl-andnegateBSY-)beforeterminatingthe REGISTER/COB9THBYTE[AddressOBHex] command.Thetimeoutfunctioncanbedisabledby loadingtheTimeoutPeriodregisterwithzero. TranslateAddress:Thisregisterwillcontaintheresult- ingsectornumberfollowingaTranslateAddress NOTE:Thefollowingtwelveregistersareused command. exclusivelybytheTranslateAddressandlor"com- bination"commands.Thefunctionofeachregister Select-And-Transfer:Thisregistershouldbeloaded isdeterminedbythetypeofcommandIssued. withtheninthbyteofatenortwelvebyteCOBbefore issuing  aSelect-and-Transfercommand. 6.2.6 TOTALSECTORSREGISTERI Wait-For-Select-And-Receive:TheW033C93Awill COB1STBYTE[Address03Hex] storetheninthbyteofatenortwelvebytereceivedCOB TranslateAddress:TheTotalSectorsregistershould inthisregister. besettothetotalnumberofsectorspertrackpriorto |
| issuingaTranslateAddresscommand. | 6.2.11 | HEADNUMBERREGISTER COB10THBYTE[AddressOCHex] Select-and-Transfer:Thisregistershouldbeloaded withthefirstbyteoftheCommandDescriptorBlock TranslateAddress:TheHeadNumberregistercon- beforeissuingaSelect-And-Transfercommand. tainstheresultingheadnumberfollowingaTranslate Addresscommand.Ifautomaticcompensationfor Wait-For-Select-And-Receive:TheW033C93Awill sparesectorsonadiskistobeperformedbythe storethefirstbyteofthereceivedCOBinthisregister. W033C93A.thenthenumberofsparesectorsper cylindermustbewrittenintothisregisterbeforeissuing 6.2.7 TOTALHEADSREGISTERI theTranslateAddresscommand.Itshouldbenotedthat COB2NDBYTE[Address04Hex] whencompensationisused,themaximumnumberof TranslateAddress:Thisregisterholdsthetotalnumber cylindersallowedis4096,andthemaximumnumberof ofheads duringaTranslateAddresscommand. headsis15.Aninitialvalueofzerointhisregister Select-And-Transfer:Thisregistershouldbeloaded indicatesthatnocompensationistobeperformed. withthesecondbyteoftheCOBbeforeissuingaSelect- Select-And-Transfer:Thisregistershouldbeloaded And-Transfercommand. withthetenthbyteofatenortwelvebyteCOBbefore Wait-For-Select-And-Receive:TheW033C93Awill issuingaSelect-And-Transfercommand. storethesecondbyteofthereceivedCOBinthis Wait-For-Select-And-Receive:TheW033C93Awill register. storethetenthbyteofatenortwelvebytereceivedCOB inthisregister. 6.2.8 TOTALCYLINDERSREGISTER/ |
COB3RDAND4THBYTES
6.2.12 CYLINDERNUMBERREGISTER/COB
[Address05,06Hex]
11THAND12THBYTES[Address00,OE,Hex]
TranslateAddress:Thisisa16-bitregisterwhichholds
TranslateAddress:TheCylinderNumberregisterisa
thetotalnumberofcylinders.

.16-bitregisterwhichcontainstheresultingcylinder DuringWait-For-Select-And-Receivecommands,this
numberfollowingexecutionoftheTranslateAddress registermayholdtheimageoftheIdentifymessage
command.WhenaTranslateAddresscommandinvolv- receivedfromtheInitiator.IftheTLVbitiszero,there
ingautomaticcompensationforsparesectorsisissued wasnoIdentifymessagereceived.IftheTLVbitisone.
(Le.theHeadNumberregisterinitiallycontainsanon- thenavalidIdentifymessagewasrec;:eived.TheDOK
zer.ovalue),thenthisregistermustbeloadedwithtotal bitwillthenindicatewhetherornottheInitiatorhas
numberofsectorspercylinder(totalsectors/track.. enableddisconnects.
totalheads- totalsparesectors/cyl)beforeissuingthe
DuringReselect-And-Transfercommands.thisregister
command.
isusedtosettheLUNtobeusedintheIdentifymes-
Select-And-Transfer:Thisregistershouldbeloaded sagesenttotheInitiatorafterSelectionphase.TheTLV
withtheeleventhandtwelfthbytesofatwelvebyteCOB andOOKbitsarenotused.
beforeissuingaSelect-and-Transfercommand.
Inadvancedmode,duringSelect-And-Transfercom-
Walt-For-Select-And-Receive:TheWD33C93Awill mands,thisregisterisusedtohandlereselectionbyan
storetheeleventhandtwelfthbytesofatwelvebyte unexpectedTarget.Inthismode,thisregisterwillhold
receivedCOBinthisregister. theimageof  theIdentifymessagereceivedfromthe
Target.Inthiscase,theTLVbitisone,sincetheTarget
Send-Status-And-Command-Complete:TheCDB11
alwayssendstheIdentifymessage.
registerisusedtospecifythereturnedstatusbytetobe
sentduringaSend-Status-And-Command-Complete
6.2.14 COMMANDPHASEREGISTER
command.TheCDB12registerisusedtodeterminethe
[Address10Hex]
typeofCommand-Completemessagesentbythe
WD33C93A.Ifbit0oftheCDB12registerissettoone, TheCommandPhaseregisterisusedduringcombina-
thenalinkedCommandCompletemessagewillbesent tioncommandstoindicatewhichphasesofthesemUlti-
duringcommandexecution.Inthiscase,bit1ofthe phasecommandshavebeencompleted.Thus,ifthe
CDB12registerisusedasaFLAGbittodetermine commandhasterminatedabnormally,theprocessor
whetheraOAHex(FLAG=O)oraOBHex(FLAG=1) canreadthisregistertodeterminethecauseofthe
LinkedCommandCompletemessageissent.Ifbit0is terminationandhowtorespondtoit.Thisregisteris
zero,thenasimpleCommandCompletemessage(00 alsousedtoresumecombinationcommandsbyloading
Hex)issent. thisregisterwithavaluethatindicatesthenextdesired
orexpectedbusphase.andreissuingthecommand.
| 6.2.13 | TARGETLUNREGISTER | Refertothedescriptionof thespecificcommandsfor [AddressOFHex] detailsregardingthevariouscommandphasesand resumevalues. TheTargetLUNregisterisusedtoholdboththeLogical UnitNumber(LUN)andTargetstatusinformationdur- ingvariousWD33C93Acommandsandsequences. DuringaSelect-And-TransferorReselect-And-Transfer command,thecontentsofthisregister(alongwiththe Source10register)areusedtogenerateandcheckthe Identifymessageswhicharetransferredacrossthe SCSIbus.Inaddition,theTargetLUNregisterisusedto holdtheTargetStatusbytereceivedduringaSelect- And-Transfercommand. |
| --- | --- | --- |
| BIT | 7 | 6 5 4 3 2 1 0 |
| TLV DOK | 0 | 0 0 TL2 TL1 TLO |

| 6.2.15 | SYNCHRONOUSTRANSFER | chronousdatatransfers,andistypicallydeterminedby negotiationwiththeotherSCSIdevice(asdefinedin REGISTER[Address11Hex] theSCSIstandard).TheTransferPeriodcontrolbits TheSynchronousTransferregisterisusedtoselect selecttheminimumtransferperiodforbothsyn- betweensynchronousandasynchronoustransfers, chronousandasynchronousSCSItransfersand,ifWO- andisalsousedtodefinethemaximumtransferrate. Busmodeisused,thetransferperiodand.thewidthof Forinformationphasesotherthana"data"transfer theRE-IWE-strobesforhosttransfers.Theperiodis phase,orwhentheselectedoffsetiszero definedintermsoftheinternalclockcycletime;the (OF3- OFO=0),asynchronoustransferswilloccur. frequencyofthisclockisdeterminedbythedivisor Valuesgreaterthanzerodefineasynchronoustransf~r selectedintheOWN10register. modeandtheoffsetisdeterminedasshownbelow.This offset  determinestheeffectiveFIFOdepthforsyn- |
| --- | --- | --- |
| BIT | 7 | 6 5 4 3 2 1 0 |
| 0 | TP2 TP1 | TPO OF3 OF2 OF1 OFO |
| Bit0-3 | OFx | TheOFFSETbitsareusedtoselectthedesiredoffsetaccordingtothefollowing: |
| OF3 | OF2 | OF1 OFO SELECTEDOFFSET |
| 0 | 0 | 0 0 Note1 |
| 0 | 0 | 0 1 1 |
| 0 | 0 | 1 0 2 |
| 0 | 0 | 1 1 3 |
| 0 | 1 | 0 0 4 |
| 0 | 1 | 0 0 5 |
| 0 | 1 | 1 0 6 |
| 0 | 1 | 1 1 7 |
| 1 | 0 | 0 0 8 |
| 1 | 0 | 0 1 9 |
| 1 | 0 | 1 0 10 |
| 1 | 0 | 1 1 11 |
| 1 | 1 | 0 0 12 |
| 1 | 1 | 0 1 12 |
| 1 | 1 | 1 X 12 Note1*  - Asynchronousdata phasetransfers |
13

| Bit4-6 | TPx | TheTRANSFERPERIODbitsareusedtoselectthe  desiredtransferperiodaccordingtothe followingtable: SCSIIWD-BUS (SCSIREQ/ACKsynchronouspulsewidth |
| --- | --- | --- |
| T.P2 | TP1 | TPO TRANSFERPERIOD andWD-BUSRE-IWE-pulsewidth) |
| 0 | 0 | X 8cycles (4cycles) |
| 0 | 1 | 0 2cycles (1cycle) |
| 0 | 1 | 1 3cycles (1cycle) |
| 1 | 0 | 0 4cycles (2cycles) |
| 1 | 0 | 1 5cycles (3cycles) |
| 1 | 1 | 0 6cycles (4cycles) |
| 1 | 1 | 1 7cycles (4cycles) The'cycle'referredtoaboveistheperiodoftheinternaldatatransferclockafterthedivisor chosenintheOWN10 registerisapplied.Thisperiodiscalculatedbythefollowingformula: DIVISOR(fromOWN10) CYCLE(~s)= 2*INPUTCLOCKFREQUENCY(MHZ) |
| 6.2.16 | TRANSFERCOUNTREGISTER | Transfercommandwillbecompletedwhenasinglebyte [Address12, 13,14Hex] hasbeentransferred. TheTransferCountregisterisa24-bitregistercontain- Afterthecompletionofanysuccessfultransfer,the ingapresetvaluefortheinternaltransfercounter.This TransferCountregisterwillbezero.Thisincludescom- presetvalueisloadedintotheinternaltransfercounter mandsissuedinSingleByteTransfermode. whenaSend,Receive,orTransfercommandisissued. Whenatransfer isinterruptedbyahaltonerrorcondi- Thiscounterisusedtodefinecommandcompletionby tion,aSCSIbusphasechange,oranabort,theTransfer decrementingaseachdatabyteistransferredoverthe CountregisterwillcontainthenumberofbytesNOT SCSIbusandcausingasuccessfulcompletioninter- successfullytransferredto/fromtheSCSIbus.includ- ruptwhenthecounterreacheszero.Incombination ingclearingtheinternalFIFOofanybytesleftinthe commands,thisregisterspecifiesthenumberofbytes FIFO(seeDATAregister).ThisFIFOclearingprocess tobetransferredduringaDataphase. maycausetheTransferCountregistertodifferwiththe Thecounterfunctioncanbedisabledbyloadingthe user'sDMAcontrollercount.becausesomebytesmay TransferCountregisterwithzeroespriortoissuinga havebeentransferredintotheFIFO.butnottotheSCSI commandorbysettingtheSingle-ByteTransferbitin bus;therefore.theTransferCountshouldbeusedto theCommandregisterconcurrentwith issuingthecom- determinetheactualnumberofbytestransferredto/ mand.Ifthecounterisdisabled,theSend,Receive,or fromtheSCSIbus. |

| 6.2.17 | DESTINATION10REGISTER | Bit6 | DPD DATAPHASEDIRECTION,when [Address15Hex] advancedfeaturesareenabled(see 7.3),isusedtospecifytheexpected TheDestination10registercontainstheencodedSCSI directionoftheSCSIdataphase.This bus10ofthedevicewhichistobeselectedor allowstheWD33C93Atoverifythe reselectedwhenaReselectorSelectcommandis directionduringSelect-And-Transfer issued.Thisregisteralsocontainscontrolbitsthat commandsbeforebeginningthe affecttheoperationofcertaincombinationcommands. transfer.Whenthisbitiszero,the expecteddirectionisout(totheTar- get).When thisbitisone,theexpected |
| --- | --- | --- | --- |
| BIT | 7 | 6 | 5 4 3 2 1 0 directionisin(fromtheTarget).An unexpectedinformationphaseerror |
| SCCDPD | 0 | 0 | 0 012 011 010 willoccurifthedirectiondoesnot matchthesettingofthisbit. |
| Bit0-2 | Destination10bits010-012contains theencodedSCSIbus10ofthedevice onlywhentheReselect-And-Transfer whichistobeselectedorreselected commandisissuedwithEDI=1.This whenaReselectoraSelectcommand bitselectswhichcommandischained isissued. towhenthedatatransferiscompleted. Whenthisbitiszero,aSend-Status- and-Command-Completecommand beginsexecuting.Whenthisbitisone. aSend-Disconnect-Messagecom- mandbeginsexecuting. 6.2.18 SOURCE10REGISTER [Address16Hex] TheSOURCE10registerisusedtoreporttheSCSIbus 10ofthedevicethathasselectedorreselectedthe WD33C93A.Italsocontainsbitsthatenableandcon- trolresponsetoselectionandreselection. | Bit7 | SCC SELECTCOMMANDCHAINisused |
| BIT | 7 | 6 | 5 4 3 2 1 0 |
| ER | ES | DSP | 0 SIV SI2 SI1 SIO |
| Bit0-2 | Six | Source10Bits2-0arevalidonlyifthe SIVbitissettoone. Thesebitsindicate busparitywhenrespondingtoselec- theSCSIbus10ofthedevicethat tionorreselection.Whenthisbitis selected or reselected the zero,anyselectionorreselectionwith WD33C93A. aparityerrorisignored. | causestheWD33C93Atoignorethe |
| Bit3 | SIV | Source10Validissettooneafterthe | Bit6 ES EnableSelection,whensettoone. WD33C93Aisselectedorreselectedif enablestheWD33C93Atorespondto theotherSCSIbusdeviceassertedits aselectionbyanotherdeviceonthe ownbus10bit(inadditiontothebus10 SCSIbus.Whenthisbitiszero.any bitoftheWD33C93A)duringthe selectionisignored. select/reselectphase.Thisbitiszeroif |
| Bit7 | ER | EnableReselection,whensettoone, onlythebus10bitoftheWD33C93A enablestheWD33C93Atorespondto wasasserted. areselectionbyanotherdeviceonthe |  |
| Bit4 | Notused.willbezero. | SCSIbus.Whenthisbitiszero,any reselectionisignored. Bit5 DSP DisableSelectParity.whensettoone, |  |
15

6.2.19 SCSISTATUSREGISTER
BIT	7	6	5	4	3	2	1	0
[Address17Hex]
| TheSCSIStatusregisterisaread-onlyregisterwhich | SS7 SS6 SS5 SS3 SS2 indicatesthecauseofthemostrecentinterruptrequest assertion.Interruptrequestisassertedwhenevera conditionoccurswithintheWD33C93Athatrequires | SS4 | SS1 | SSO |
| --- | --- | --- | --- | --- |
| Bit0-3 | SSx | SCSIStatusbits0-3,arestatu~ interventionbythehost;forexample: qualifierswhosemeaningdepend~ •theWD33C93Ahasbeenreset; uponwhichupper(4-7)statusbitil set. •thecommandcompletedsuccessfully; |  |  |
| •thebusphasechanged; | Bit4-7 | SSx | SCSIStatusbits4-7definethetype0 •anerroroccurred. interruptthatoccurred.ThepossiblE codesaredefinedinthefollowin~ Onceinterruptrequesthasbeenasserted,thecontents table: ofthisregisterwillnotchangeuntilaftertheSCSI STATUSregisterhasbeenreadoruntiltheWD33C93A hasbeenreset. |  |
| STATUS | CODE | GROUPMEANING |  |  |
| 0000 | xxxx | TheWD33C93Aisinaresetstate. |  |  |
| 0001 | xxxx | AWD33C93Acommandhascompletedsuccessfully. |  |  |
| 0010 | xxxx | AWD33C93Acommandhaspausedorwasabortedby anAbortcommand. |  |  |
| 0100 | xxxx | AWD33C93Acommandhasbeenterminatedprematurely duetoanerrororotherunexpectedcondition. |  |  |
| 1000 | xxxx | AneventontheSCSIbusrequiresservice. |  |  |
16

AllotherStatusCodegroupsarecurrentlynotusedand
| MCICODE | MEANING arereserved forfutureuse. Inthefollowingtables,the'State'columnindicatesthe 000 DataOutphase currentstatefromwhichtheStatusCodecanoccur. 001 DataInphase Also,theMCIfieldreferstothesignalsthatdefinea | I |
| --- | --- | --- |
| SCSIbusinformationtransferphase:MSG,C/D,and | 010 | Commandphase 1/0.Abitsettooneindicatesthatthesignalisasserted 011 Statusphase ontheSCSIbus.Azeroindicatesnegation.Whenever I 100 UnspecifiedInfoOutphase oneoftheseStatusCodesoccurs,theREOsignalis |
| assertedontheSCSIbus.Thetablebelowsummarizes | 101 | UnspecifiedInfoInphase themeaningoftheMCIfield: 110 MessageOutphase 111 MessageInphase |
RESETSTATEINTERRUPTS
| STATUS | CODE | STATE* | SPECIFICMEANING |
| --- | --- | --- | --- |
| 0000 | 0000 | D,T.I | WD33C93Reset.Thedevicehasbeenreset,oraReset commandhasexecutedsuccessfullywithnoadvancedfeatures enabled.ThenewstateoftheWD33C93Aisdisconnected. |
| 0000 | 0001 | D,T,I | WD33C93AReset.Thedevicehassuccessfullycompleteda Resetcommandwithadvancedfeaturesenabled.Thenewstate oftheWD33C93Aisdisconnected. *D =Disconnected T =ConnectedasaTarget I =ConnectedasanInitiator |
17

SUCCESSFULCOMPLETIONINTERRUPTS
| STATUS, | CODE | STATE* | SPECIFICMEANING |
| --- | --- | --- | --- |
| 0001 | 0000 | 0 | AReselectcommandcompletedsuccessfully.Thenewstateof theWD33C93AisconnectedasaTarget. |
| 0001 | 0001 | 0 | ASelectcommandcompletedsuccessfully.Thenewstateofthe WD33C93AisconnectedasanInitiator. |
| 0001 | 0010 | Reservedforfutureuse. |  |
| 0001 | 0011 | 0,T | AReceive,Send,Reselect-And-Transfer,Wait-For-Select-And- Receive,Send-Status-And-Command-Complete,oraSend- Disconnect-Messagecommandcompletedsuccessfully (ATN-isnotasserted). |
| 0001 | 0100 | D.T | AReceive,Send,Reselect-And-Transfer,Wait-For-Select-And- Receive,Send-Status-And-Command-Complete,oraSend- Disconnect-Messagecommandcompletedsuccessfully (ATN-isasserted). |
| 0001 | 0101 | 0,T | ATranslateAddresscommandcompletedsuccessfully. |
| 0001 | 0110 | 0.1 | ASelect-And-Transfercommandcompletedsuccessfully. |
| 0001 | 0111 | Reservedforfutureuse. |  |
| 0001 | 1MCI | I | ATransfer(non-MessageINphase)commandcompleted successfully.MCIdefinesthenewinformationtype(SCSIbus phase)beingrequested. |
PAUSEDORABORTEDINTERRUPTS
| STATUS | CODE | STATE* | SPECIFICMEANING |
| --- | --- | --- | --- |
| 0010 | 0000 | I | ATransferInfo(Message-Inphase)commandhaspausedwith ; ACK-asserted.Thisallowsthehosttoexaminethemessage beforeacceptingit. |
| 0010 | 0001 | I | ASaveDataPointersmessagewasreceivedduringaSelect- And-Transfercommand.Thehostshouldsaveitscurrentdata bufferpOinter. |
| 0010 | 0010 | 0 | ASelectorReselectcommandwasaborted. |
| 0010 | 0011 | T | AReceiveorSendcommandhashaltedbyanerrororwas aborted(ATN-isnotasserted). |
| 0010 | 0100 | T | AReceiveorSendcommandhashaltedbyanerrororATN- asserted,orwasaborted(ATN-isasserted). |
| 0010 | 0101 | 0 | AnAbortwasissuedwhiletheWD33C93Awasinthe processofbeingselectedorreselected. |
| 0010 | 0110 | Reservedforfutureuse. |  |
| 0010 | 0111 | 0 | TheWD33C93AhasbeenreselectedduringaSelect-And- Transfer(with101=0)byaTargetthatdoesnotmatchtheSCSI bus10loadedintotheDestination10register;orthefollowing IdentifymessagedidnotmatchtheLUNloadedintotheTarget LUNregister.ACK-hasbeenleftassertedfollowingtheIdentify message,andthebus10andLUNofthereselectingTarget areavailableintheSource10andTargetLUNregisters. (AdvancedModeonly) |
| 0010 | 1MCI | I | ATransfercommandwasaborted.MCIdefinethenew informationtype(SCSIbusphase)beingrequested. *0 =Disconnected T =ConnectedasaTarget I =ConnectedasanInitiator |
18

TERMINATEDINTERRUPTS
| STATUS | CODE | STATE* | SPECIFICMEANING |
| --- | --- | --- | --- |
| 0100 | 0000 | D.T.I | Aninvalidcommandwasissued. |
| 0100 | 0001 | I | Anunexpecteddisconnect(SCSIbusfree)bytheTargetcaused acommandtoterminate.ThenewstateoftheWD33C93Ais disconnected. |
| 0100 | 0010 | 0 | AtimeoutoccurredduringaSelectorReselectcommand.The stateoftheWD33C93Aisdisconnected. |
| 0100 | 0011 | T.I | Aparityerrorcausedacommandtoterminate(ATN-isnot asserted).ThetransferdirectiondetermineswhetheritisaSCSI orhostparityerror. |
| 0100 | 0100 | T.I | Aparityerrorcausedacommandtoterminate(ATN-is asserted).ThetransferdirectiondetermineswhetheritisaSCSI orhostparityerror. |
| 0100 | 0101 | 0,T | TheLogicalAddressexceededthediskboundaries. |
| 0100 | 0110 | 0 | ATargetwhoseSCSIbusdevice10doesnot matchthebus10 setintheDestination10registerhasreselectedtheWD33C93A duringaSelect-And-Transfercommand(with101=0).This interruptoccurswhentheWD33C93Aisnot inAdvancedMode. ThenewstateoftheWD33C93AisconnectedasanInitiator. |
| 0100 | 0111 | 1 | Anincorrectstatusbyte(i.e.thestatusbytehasaparityerror) wasreceivedduringaSelect-And-Transfercommand.TheData Registercanbereadtoobservethestatusbyteinerror. |
| 0100 | 1MCI | I | Anunexpectedinformationphasewasrequested.MCIdefine theSCSIbusphasewhichisrequested.Thisistypicallycaused byaphasechangebeforetheTransferCounthasreachedzero, oranunexpectedphasesequenceoccurredduringaSelect- And-Transfercommand. •0 Disconnected T =ConnectedasaTarget I =ConnectedasanInitiator |
19

SERVICEREQUIREDINTERRUPTS
| STATUS | CODE | STATE* | SPECIFICMEANING |
| --- | --- | --- | --- |
| 1000 | 0000 | 0 | TheW033C93Ahasbeenreselected.Thenewstateofthe W033C93Aisconnectedas anInitiator.NoIdentifymessage transferhasyetoccurred. |
| 1000 | 0001 | 0 | TheW033C93AhasbeenreselectedinAdvancedMode. TheSCSIbus10oftheTargetmaybereadfromtheSource10 register.TheIdentifymessagefromtheTargetmaybereadfrom theDataregister.TheACK-signalisleftasserted.Thenew stateoftheW033C93AisconnectedasanInitiator. |
| 1000 | 0010 | 0 | TheW033C93Ahasbeenselected(noATN-assertion). ThenewstateoftheW033C93AisconnectedasaTarget. |
| 1000 | 0011 | 0 | TheW033C93Ahasbeenselected(ATN-wasasserted). ThenewstateoftheW033C93AisconnectedasaTarget. |
| 1000 | 0100 | T | TheATN-signalhasbeenasserted. |
| 1000 | 0101 | I | Adisconnecthasoccurred.ThenewstateoftheW033C93Ais disconnected. |
| 1000 | 0110 | Reservedforfutureuse. |  |
| 1000 | 0111 | T | TheWait-For-Select-And-Receivecommandhaspaused becausethefirstbyteoftheincomingCOSisnotaknown commandgroup.TheOwn10registermustbeloadedwiththe CDSlength,andthecommandresumed.TheCOBlregister maybeexaminedtodeterminetheSCSIcommandgroupfrom theopcode.ThenewstateoftheW033C93Aisconnectedasa Target.(AdvancedModeonly) |
| 1000 | lMCI | I | TheREOsignalhasbeenassertedfollowingconnectionor whentheW033C93AisintheInitiatorstateandnocommandis executing.Theinformationphasetypeshouldbeexamined. MCIdefinetheinformationphase(SCSIbusphase)whichis beingrequested. •0 =Disconnected T =Connectedas aTarget I =ConnectedasanInitiator |
20

TheSingle-ByteTransfer(SBT)bitintheCommand
6.2.20 COMMANDREGISTER
registerisonlyusedduringinformationtransfertype
[Address18Hex]
commands.Whenthisbitissetinconjunctionwithone
TheCommandregisterisusedtoissuetheWD33C93A
ofthesecommands,thetransfer  counterisdisabled
commands.SincetheWD33C93AexpectstheSCSI
andexactlyonebyteistobetransferred,regardlessof
Statustohavebeenreadbeforethehostcanissuea
thevalueintheTransferCountregister.
validcommand.acommandshouldnotbeloadedinto
RefertotheCommandssectionforadescriptionofthe
theCommandregisterwithinsevenmicroseconds
commandsandtheircorrespondingcommandcodes.
(independentofinputclockfrequency)fromthelast
~C~IStatusreadto avoidthecommandbeingignored
(indIcatedbytheLCIbitintheAuxiliaryStatusregister).
Also.thisregistershouldneverbeloadedwhentheCIP
BIT	7	6	5	4	3	2	1	a
orINTbits(inAuxiliaryStatus)aresettoone,anda
LevelIIcommandshouldneverbeloadedwhenthe
SBTCC6CC5CC4CC3CC2CC1 cco
BSYbitissettoone.

•TheOwn10registerisresettozero.
6.2.21 DATAREGISTER[Address19Hex)
•Advancedmodeisdisabled.
TheDATAregisterisusedtotransferdatabytes
betweenthe'hostandtheSCSIbusduringtheSCSI •TheES,ER,andDSPbitsintheSource10register
informationtransferphases(command,data,status,or areresettozero.
messagephase).Itmaybeaccessedbytheprocessor
•TheSCSIStatusregisterisresettozero.
duringanytypeofinformationphase(simpleLevelII
•TheinternalFIFO,internaltransfercounter(notthe
commands)orviatheDMAIWDBUSinterfaceduringa
hostaccessibleregister).offsets.andstatemachines
SCSIDataInphaseorDataOutphase(simpleand
arecleared.
combinationLevelIIcommands).
•Theinternalclockdividercircuitissettodividebytwo.
TheDATAregisterisactuallyaportforthehostinterface
intotheintervaltwelvebyteFIFOoftheWD33C93A. •ThefollowinghostaccessibleregistersareNOT
TheFIFOisusedforalltransfers(synchronousand affectedbytheMR-signal:
asynchronous)betweentheSCSIbusandthehostbus,
•Registers01Hexthrough15Hex;
forbothDMAandprocessoraccesstransfers.Ifthe
•Source10(16Hex)registerbits0-3;
WD33C93Aistobehaltedforanyreason(through
ABORT,forexample),thendatatransferswiththisFIFO •Commandregister(18Hex).
mustcontinueuntilaninterruptoccurs.Thismustbe
NOTE:TheSCSISoftResetmaybeimplementedby
donesothattheFIFOisreturnedtoareadystatefor
usingtheSCSIbusresetsignaltocausearesetofthe
subsequenttransfers,andtoflushincomingdatatothe
WD33C93A(forexample,ORthehostpoweronreset
hostbus.
signalwiththereceivedSCSIbusreset(RST)signal).
TheDATAregisterisaccessedbythehostprocessor Thehostmayexaminetheregistersthatarenot
duringadataphasewhentheCONTROLregisterDMA affectedbytheMR-signaltorecoverfromtheSCSI
modeselectbitsareallreset(=0),andwhentheDBR resetcondition.
bitintheAuxiliaryStatusregisteristrue.Theprocessor
writes(reads)theDATAregisterbyloadingtheAddress	6.3.2	SOFTWARERESET
registerwithaHexvalueof19andassertingtheWE-
ThefollowingresultsoccurwhentheWD33C93A
(RE-)andCS- pins.Thisaccessalsooccursduring
executestheResetcommand:
non-dataphases.
•TheDBRbitintheAuxiliaryStatus registerisresetto
WhentheControlregisterDMAmodeselectsbitsare
zero.TheINTbit(andINTRapin)issettoonewhen
setforDMAmodeorBurstmode,theDMAinterfaceis
theResetcommandiscomplete.
enabled.Inthiscase,theDATAregisteriswritten(read)
•AllSCSIbussignalsareresettothenegatedstate.
whentheDACK-andWE-pinsareassertedinresponse
totheassertionbytheWD33C93AoftheDRa-pin. •TheinternalFIFO.internaltransfercounter,offsets,
andstatemachinesarecleared.
WhentheWD-BUS isselectedbytheDMAmodeselect
bits.theRCS-pinfunctionsasanexternalbufferchip •TheOwn10registerisinterpretedandtheclock
selectandtheWE- andRE- pinsbecomeoutputs, divisor,hostparity,andadvancedmodeare
allowingtheWD33C93Atoautomaticallytransferdata configured.
betweenitsDATAregisterandtheexternalbuffer.Inthis
•Registers01Hexthrough16Hexareresettozero.
mode,buscontrolcanbereturnedtotheexternal
TheCommandregister(18Hex)isalsoresettozero.
processororanydevicebynegatingtheORapin.
•TheSCSIStatusregisterissetascommandedbythe
EAFbitintheOwn10register.
6.3 RESETCONDITIONS
6.3.1 HARDWARERESET
ThefollowingresultsoccurwhentheWD33C93Ais
resetbytheassertionoftheMR-signal:
•TheLCIandPEbitsintheAuxiliaryStatusregisterare
resettozero.TheDBRbitintheAuxiliaryStatus
Registerisresettozero.TheBSYandCIPareresetto
zero,andtheINTbit(andINTRapin)issettoone
whenthehardwareresetiscomplete.

7. COMMANDS
7.1 COMMANDLISTS
COMMAND
VALID
CODE	COMMAND	LEVEL
STATES
(Hex)
| 00 | Reset | D,T,I |
| --- | --- | --- |
| 01 | Abort | D,T,I |
| 02 | AssertATN | I |
| 03 | NegateACK | I |
| 04 | Disconnect | T,I |
| 05 | Reselect | 0 |
| 06 | Select-With-ATN | 0 |
| 07 | Select-Without-ATN | 0 |
| 08 | Selw/ATN-And-Transfer | 0,1 |
| 09 | SelwloATN-And-Transfer | 0,1 |
| OA | Reselect-And-ReceiveData | 0 |
| 08 | Reselect-And-SendData | 0 |
| OC | Wait-For-Select-And-Receive | 0 |
| 00 | Send-Status-And-Command-Complete | T |
| OE | Send-Disconnect-Message | T |
| OF | Set101 | D,T,I |
| 10 | ReceiveCommand | T |
| 11 | ReceiveData 12 T ReceiveMessageOut | T |
| 13 | ReceiveUnspecifiedInfoOut 14 T SendStatus | T |
| 15 | T | II SendData |
| 16 | T | II SendMessag~In |
| 17 | SendUnspecifiedInfoIn | T II |
| 18 | TranslateAddress | D,T II |
| 20 | TransferInfo WD33C93Avalidstates: | I II |
| o | = | Disconnected |
| T | = | Connected asaTarget |
| I | = | ConnectedasanInitiator CommandLevels: |
| I | = | LevelIcommand |
| II | = | LevelIIcommand |
23

7.2	WD33C93ACOMMANDTYPES	WD33C93Awasidle,theSCSIstatusregisterwillbe
setto81Hex,andtheIdentifymessagewillbeinthe
TherearetwobasictypesofWD33C93Acommands:
Dataregister.IftheWD33C93AwasexecutingaSelect-
LevellandLevelII.Levellcommandsmaybeissued
And-Transfercommand,theSCSIstatusregisterwillbe
whileaLevelIIcommandisinprogress(indicatedbyan
setto27Hex,andtheIdentifymessagewillbeinthe
AuxiliaryStatusofBSY=1,CIP=O)and,exceptforthe
TargetLUNregister.Ineithercase,theSource10regis-
"Abort"and"Reset"commands,donotgeneratean
terwillcontaintheSCSIbus10ofthereselectingTarget,
interruptupontheircompletion.LevelIIcommand
andtheACKsignalremainsassertedsothattheIden-
executionwillalwaysresultinaninterrupt.IfaLevelII
tifymessagemayberejected.
commandisissued whileanotherLevelIIcommandis
executing,unpredictableresultsmayoccur.
7.3.2 UNKNOWNSCSICOMMANDGROUPS
TherearetwotypesofLevelIIcommands.'Simple'
WhenaSCSICommandDescriptorBlockistransferred
LevelIIcommandsareassociatedwithasingleopera-
ontheSCSIbus,thecommandlengthinbytesis
tionorphase(forexample,selectionorinformat~on
determinedbythegroupcode,whichisfoundinbits7-5
transfer).'Combination'LevelIIcommandscombine
ofthefirstcommandbyte,oropcode.Group0(opcodes
multiplephasesintoasingleWD33C93Acommandto
00to1 FHex),group1(opcodes20to3FHex),and
minimizeinterruptoverhead.TheInitiatorcombinati~n
group5(opcodesAOtoBFHex)commandsaredefined
commands'expect'certainSCSIbusphasesatcertain
bytheSCSIstandard(X3.131-1986)assix,ten,and
timesduringasequence.Theseexpectedphasesare
twelvebytecommands,respectively.Allothercom-
basedoncommonsequencesperformedbyaTargeton
mandgroupsareundefinedbythatstandard.Innormal
theSCSIbus;anydeviationcausesaninterrupt.Target
mode,theWD33C93Awillassumethatthese
combinationcommandscanalsobechainedtogether
undefinedgroupsaresixbytecommandswhenexecut-
tominimizeinterruptoverheadbycreatinglonger
ingSelect-And-TransferorWait-For-Select-A~d­
phasesequences.
Receivecommands.InAdvancedMode,thefollOWing
NOTE:Whenusingcommandchaining,caremustbe eventswilloccur:
takentoensurethatallcommandsinthechainare
•Select-And-Transfer:WhenloadingtheCOBinto
initializedpriortoissuingthecommand.
theCOBregisterspriortoissuingthecommand,the
TheWD33C93Awillbeinoneofthree"states"during hostalsoloadstheexpectedcommandlengthinto
operation:Disconnected,ConnectedasaTarget,~r theOWN10register.TheWD33C93Ausesthisvalue
ConnectedasanInitiator.Certaincommandsarevalid tomakesurethecorrectnumberofbytesarethen
onlyinparticularstatesasindicatedintheComr:na~d transferredinthecommandphase.
List.AnattempttoissueaLevelIIcommandwhichIS
•Walt-For-Select-And-Recelve:Whenreceivingthe
invalidforthepresentWD33C93Astatewillcausean
CDSfromtheInitiator,theWD33C93Awillcheckthe
"invalidcommand"interrupt.LevelIcommandsissued
firstCOBbyteassoonasitisreceived.Ifthegroupis
ininvalidstateswillbeignored.
undefined,aninterruptwilloccursothatthehost
processorcanexaminethefirstcommandbyteinthe
7.3 ADVANCEDMODEFEATURES
CDS1STregister,andthenloadtheTotalcommand
TheWD33C93Ahasseveralnewfeaturesincluded
lengthintotheOwn10register.TheSCSIstatus
whichaddnewfunctionstotheoriginalWD33C93
registerissetto87Hex,andtheCommandPhase
design.SomeofthesefeaturescausetheW033C93A
registerissetto31Hex,whenthisinterruptoccurs.
tobeincompatiblewiththeWD33C93.Thesefeatures
Aftertheinterrupt,theWD33C93Awillonlyaccepta
havebeengroupedtogetherundertheheadingof
ResumeWait-For-Select-And-Receivecommand,
~dvancedMode'features.Thesefeaturesaredisabled
Abort,Disconnect,orResetcommand.Allothercom-
whentheWD33C93AisresetbytheMR-signal(hard-
mandsareinvalid;duringtheinterruptprucessing,the
warereset).Theymustbeenabledbythehost  by
WD33C93Awillcontinuetotransferthefirstsixbytesof
issuingthe'Reset'commandwiththe'Enable
thecommandintoitsinternalFIFO.
AdvancedFeatures'(EAR)bitsetintheOwn10register.
Thehostcandetermineifadvancedfeatureshavebeen
7.3.3 DATEPHASEDIRECTION
enabled(therebyimplyingthataWD33C93Ais
installed)byexaminingtheSCSIstatusregisterafter DuringaSelect-And-Transfercommandinnormal
issuingthe'Reset'command. mode,theDataphasedirectionisdeterminedsolelyby
theTarget;ifthisdirectiondoesnotmatchthedirection
Thefeaturesenabledbythisbitaredescribedbelow.
expectedbythehost,theWD33C93Awillnotdetectthis
errorbutexpectsthatthetransferwillcontinue.In
7.3.1 UNEXPECTEDRESELECTION:
AdvancedMode,theDPDbitintheDestination10
Wheninnormalmode,areselectionwhenidle(ER=1)
registeriscomparedwiththestateoftheI/OsIgnalon
orwhendisconnectedduringaSelect-And-Transfer
theSCSIbus.Iftheexpectedandactualdirectionsdo
command(andtheTargetbus10doesnotmatchthe
notmatch,aninterruptwilloccurwith'unexpected
Destination10register)causesanimmediateinterrupt
phase'statusintheSCSIstatusregister.
afterthereselectionhandshakeiscomplete.In
AdvancedMode,theWD33C93Awillcontinuetothe
MessageInphasetofetchtheIdentifymessage.Ifthe
24

I~
7.4 LEVELICOMMANDS processorhasreceivedtheinterruptindicatingthis,the
TRANSFERCOUNTregistercontainsthenumberof
| 7.4.1 | RESET | (00HEX) bytesthatwerenotsuccessfullytransferredwiththeSCSI TheResetcommandperformsasimilarfunctiontothe bus.TheWD33C93Aremainsintheconnectedasa hardwareresetcausedbyassertingtheMR-pinexcept Targetstate.TheWD33C93Aisnowreadytoreceiveany thattheOwn10registerissampledforinformationcon- appropriateTargetmodecommand,includingaresume cerningtheoperatingconfigurationoftheWD33C93A. ofthecommandthatwasaborted. TheWD33C93Aisalsoinitializedasdescribedinthe InitiatorState:WhentheWD33C93Aisinaconnectedas RESETCONDITIONSsection.TheResetcommandmay anInitiatorstate,theAbortcommandmaybeusedto beexecutedinanyWD33C93Astateandwillforcethe abortTRANSFERINFO,TRANSFERPAD,Select,or WD33C93AintotheDisconnectedstate,abortingany Select-and-TRANSFERcommand.Whenissuingan previouslyissuedcommandinprogress.Uponcomple- AbortintheconnectedasanInitiatorstate,thelocal tionoftheResetcommand,aninterruptisgeneratedthe processormustcontinuetoserviceanydatarequest SCSISTATUSwillbe00Hexor01Hex,dependingonthe (DBR,ORO,etc.)fromtheWD33C93Auntilaninterrupt contentsoftheOWN10register. fromtheWD33C93Aoccurs.Thisisrequiredtoallowthe FIFOtoclear;theAbortprocessingwillnotcompleteuntil 7.4.2 ABORT (01HEX) theFIFOcontentsareflushedtothedatadestination. TheAbortcommandisvalidinanyWD33C93Astate: AftertheAbortcommandisprocessedandthelocal Disconnected,Target,orInitiator.TheAbortcommand processorhasreceivedtheinterruptindicatingthis,the hasdifferenteffectsdependingonthestateandthe TRANSFERCOUNTregistercontainsthenumberof commandthatiscurrentlyexecuting,asdescribedbelow: bytesthatwerenotsuccessfullytransferredwiththeSCSI DisconnectedState:IntheDisconnectedstate,theAbort bus.TheWD33C93Aremainsintheconnectedasan commandmaybeusedtohaltanattemptedSelect, Initiatorstate.TheWD33C93Aisnowreadytoreceive Select-and-Transfer,Reselect,orReselect-and-Transfer anyappropriateInitiatormodecommand,includinga command.IftheAbortcommandisissuedfollowinga resumeofthecommandthatwasaborted. SelectorReselectcommandandtheWD33C93Ahas |
| --- | --- | --- |
| wonarbitration,theWD33C93AreleasestheSCSIbusby | 7.4.3 | DISCONNECT (04HEX) removingtheBus10bitswhileSEL- isassertedand TheDisconnectcommandmaybeusedineitherthe checkingforanegatedBSY-signal.If.afteratleast200 TargetortheInitiatorconnectedstates.IntheTargetrole, J.LS,thereisnoBSY-response,theWD33C93Agoestoa theDisconnectcommandisthenormalprocedurefor BusFreecondition,anda"paused/aborted"interruptis disconnectingfromtheSCSIbusfollowingtheinforma- generated.Ifthereisaresponsewithinthistimeperiod, tiontransferphase.IntheInitiatorrole,Disconnectcanbe thena"successfulcompletion"interruptwillresult usedtoreleasethebusfollowingatimeoutcondition.The instead.IftheWD33C93Ahasnotyetwonarbitration,it Disconnectcommandcausestheimmediatereleaseof willimmediatelyaborttheSelectorReselectcommand. allbussignalsand,inTargetmode,returnstheSCSIbus TargetState:WhentheWD33C93AisinaConnectedas totheBusFreephase.IftheDisconnectcommandis aTargetstate,theAbortcommandmaybeusedtoabort issuedduringanactiveLevelIIcommand,theLevelII RECEIVE,SEND,orthedataphaseportionofaTarget commandisimmediatelyterminatedandtheWD33C93A combinationcommand.WhenissuinganAbortinthe transitionstotheDisconnectedstate. ConnectedasaTargetstate,thefollowingrulesapply: |
| 7.4.4 | ASSERTATN 1. WhenanAbortcommandisissuedtoabortaSEND orReselect-and-SENDcommand,thelocalprocessor TheAssertATNcommandisonlyvalidwhenConnected mustnotserviceanydatarequest(DBR,ORO,etc.)from asanInitiator.ItisnormallyusedtoallowtheInitiatorto theWD33C93AuntilaninterruptfromtheWD33C93A informaTargetthatithasamessagepending(theTarget occurs.ThisisrequiredtoallowtheFIFOtoclear;the isexpectedtorespondbyperformingaMessageOut AbortprocessingwillnotcompleteuntiltheFIFOcontents Phase). areflushedtotheSCSIbus.TheWD33C93Aremoves thedatarequestatanarbitrarytimeduringtheAbort ATN-isautomaticallynegated: commandprocessingandthedatarequestisnotvalid •beforethelastbyteofaTransferInfocommandissued oncetheAbortcommandiswrittentotheCOMMAND inresponsetotheMessageOutphase; register. •whentheIdentifymessageoutistransferredtothe 2. WhenanAbortcommandisissuedtoaborta TargetduringaSelect-and-Transfercommand; RECEIVEorReselect-and-RECEIVEcommand,the •whenaSCSIBusFreephaseoccurs. localprocessormustCONTINUEtoserviceanydata request(DBR,ORO,etc.)fromtheWD33C93Auntilan TheSelect-with-ATNandSelect-with-ATN-and-Transfer interruptfromtheWD33C93Aoccurs.Thisisrequiredto commandswillcausetheWD33C93Atoautomatically' allowtheFIFOtoclear;theAbortprocessingwillnot assertATN-priortothereleaseofSEL-providingthebus completeuntiltheFIFOcontentsareflushedtothelocal arbitrationiswon. processor. AftertheAbortcommandisprocessedandthelocal | (02HEX) |

| 7.4.5 | NEGATEACK (03HEX) | deasserted.Atthistime,  atimeoutsequencewhose lengthisdeterminedbythevalueintheTimeoutPeriod TheNegateAckcommandcausesACK-tobenegated.It registerbegins.IfBSY-isnot  assertedbytheTarget isusedwhenConnectedasanInitiatorfollowingMes- beforeatimeoutoccurs,theWD33C93Abeginsits sage-IntypeTransferInfocommands,orwhenthe selectionabortsequence(asdes~ribedintheAbort WD33C93Ahasdetectedaparityerroronanyreceived commanddescription),andifthereisnoTarget informationandtheHaltonSCSIParityError(HSP)bitis responsetheSelect-with-ATNcommandisterminated set.HostparityerrorsdonotaffecttheACK-signal.Forall anda"terminated"interruptisgenerated.IftheTarget otherInitiatortransfers,ACK-negationisautomatic. respondsbeforethetimeoutperiodhaselapsedor InthecaseofaMessage-Intransfer,incomingmessages beforetheselectionabortsequenceiscomplete,the mayberejectedandtheInitiatormayindicateitsintentto WD33C93AnegatestheSel- signal,puttingthe sendeithera"MessageReject"ora"MessageParity WD33C93AinaConnected-as-an-Initiatorstate.A Error"MessagebyissuingtheAssertATNcommandprior "successfulcompletion"interruptindicatesthatthe toissuingtheNegateAckcommand.Iftheincoming Select-with-ATNcommandhasbeencompleted messageistobeaccepted,onlytheNegateAckcom- successfully. mandshouldbeissued. IftheWD33C93Adoesnotwinthearbitrationorthereis Duringnon-Message-Intransfers,iftheTransfercom- noresponsefromtheTargetandthetimeoutfeatureis mandisterminatedbyparityerror,theAssertATNcom- disabled,theSelect-with-ATNcommandcanbe mandcanagainbeissuedpriortoNegateACK,thistime abortedwithanAbortcommand.WhentheAbortcom- indicatingtheInitiator'sintenttosendan"Initiator mandissuccessfullyexecutedunderthesecircum- DetectedError"Message. stances.theWD33C93Aisdisconnectedfromthebus anda"paused/aborted"interruptisgenerated. |
| --- | --- | --- |
| 7.4.6 | SET101 | (OFHEX) TheSet101commandisusedintheInitiatorroleto 7.5.2 SELECT-WITHOUT-ATN (07HEX) supportoverlappedSCSIoperations.IfaSCSIcommand TheSelect-without-ATN  commandisidenticaltothe isexecutingviaaSelect-and-Transfercommand,thenthe Select-with-ATNcommandexceptthatATN·isnotset Set101commandmaybeusedtosetthe101bitinthe duringtheSelectionPhase. Controlregister,whichthencausesaninterrupttooccur uponaTargetdisconnection.Thisabilityallowsthe101bit 7.5.3 RESELECT (05HEX) tobeleftresetwhenthefirstSCSIoperationisstarted, TheReselectcommandisidenticaltotheSelect-with- whichmayreducethenumberofWD33C93Ainterrupts, out-ATNcommandexceptthatthe1/0signalisasserted yetalsoallowsasecondoperationtobestartedwhen uponcompletionof theArbitrationPhase.Successful neededwithoutwaitingforthefirstoperationtobe completionoftheReselectcommandresultsinthe completed. WD33C93AbeingConnectedasaTarget. 7.5 SIMPLELEVELIICOMMANDS 7.5.4 RECEIVE (10-13HEX) |
| 7.5.1 | SELECT-WITH-ATN (06HEX) | TherearefourRECEIVEcommandswhicharedis- tinguishedfromeachotheronlybythestateofthree Select-with-ATNisvalidonlyintheDisconnectedstat6 SCSIinterfacesignalsandthetypeofdatathatis andwhenissuedwillcausetheWD33C93Atoselecta transferred.Thesecommands,conSistingofthe Target.Beforeissuingthiscommand,theSCSIBus10 ReceiveCommand,ReceiveData,ReceiveMessage oftheTargetdeviceshouldbewrittenintotheDestina- Out,andReceiveUnspecifiedInfoOutcommandsare tion10register.WhentheSelect-with-ATNcommandis validonlyintheConnected-as-a-Targetstate.Thetype issued,theWD33C93Abeginsbusarbitration.Ifthe ofReceivecommandselecteddeterminesthestateof WD33C93Aisselectedorreselectedbyanotherdevice the110-,C/D-,andMSG-outputs duringthecommand duringthearbitration,theSelect-with-ATNcommandis accordingtothefollowingchartbelow(1=asserted). abortedanda"servicerequired"interrupt(exHex)is generated. TheReceivecommandsareinformationtransferrring ShouldtheWD33C93Awinthearbitration,SEL-and commandsandarethereforedependentontheSBTbit ATN-areasserted,theTargetandInitiatorBusIDsare intheCommandregisterfordeterminationofasuc· placedontheSCSIdatabus,andthenBSY·is cessfulcompletion.Inaddition toaterminationcaused |
| RECEIVECOMMANDTYPE | OPCODE | MSG CID 1/0 |
| ReceiveCommand | 10 | 0 1 0 |
| ReceiveData | 11 | 0 0 0 |
| ReceiveMessageOut | 12 | 1 1 0 |
| ReceiveUnspecifiedInfoOut | 13 | 1 0 0 |
26

byreset(viaeitheraResetcommandbeingissuedor theSendStatus.SendData.SendMessageIn.and
assertionoftheMR-pin).aReceivecommandcomple- SendUnspecifiedInfoIncommands.TheSCSIpin
tionorterminationwilloccurunderanyofthesecondi- statesduringtheSendcommandsaredeterminedby
tions:(1)Theinternaltransfercounterisdisabled theparticularcommandsasfollowsshowninthechart
(SBT=1ortheTransferCountregisterisloadedwith below(asserted=1).
zero)andasinglebytehasbeenreadfromtheData
TheSendcommandsarealsoinformationtransferring
register;(2)Thecounterhasdecrementedtozero(with
commandsandassucharealsodependentuponthe
SBT=0)indicatingthatthespecifiednumberofbytes
SBTbitintheCommandregisterforcommandcomple-
havebeentransferred;(3)Aparityerrorhasbeen
tion.Inadditiontothatcausedbyreset(viaeithera
detectedononeofthereceiveddatabytes(and
ResetcommandbeingissuedorassertionoftheMR-
HSP=1);(4)TheATN-pinisasserted(andHA=1);(5)
pin),aSendcommandcompletionorterminationwill
TheAbortcommandisissued;or(6)ADisconnect
occurunderanyoftheseconditions:(1)Theinternal
commandisissued.
transfercounterisdisabled(SBT= 1ortheTransfer
WhentheReceivecommandiscompletedasaresultof Countregisterisloadedwithzero)andasinglebytehas
receivingthecorrect  numberofbytes,a"successful beenreadfromtheDataregister;(2)Thecounterhas
completion"interruptwillbegenerated.Ifaparityerror decrementedtozero(withSBT=0)indicatingthatthe
hascausedtermination,a"terminated"interruptwill specifiednumberofbyteshavebeentransferred;(3)A
insteadbegenerated.Inthiscase,theTransferCount parityerrorhasbeendetectedononeofthedatabytes
registerwillcontainthenumberofbytesyettobe fromthehost(andHHP=1);(4)TheATN- pinis
transferred.Afteranycompletionorterminationofthe asserted(andHA=1);(5)TheAbortcommandisis-
Receivecommandsexceptthoseduetoasubsequent sued;or(6)ADisconnectcommandisissued.The
Disconnectcommandorreset,theWD33C93Aisinthe WD33C93AremainsConnected-As-A-Targetfollowing
Connected-as-a-Targetstate. theSendcommandcompletion/terminationunlessthe
Disconnectcommandorresetwasusedtoforcea
Asdatatransfercommands,theReceivecommands
termination.
aredependentontheDMAmodeselectbitsinthe
ControlregisterfortheDataregisteraccessingmode.
DuringaSendcommand.Dataregisteraccessingis
ThesebitsdeterminewhethertheDataregister
controlledbytheDMAmodeselectbitsintheControl
accesseswillbehandledbytheprocessororthrougha
register.Whenthesebitsaresettotheappropriate
DMAIWDinterface.Whentheprocessorisrequiredto
mode,loadingoftheDataregisterisaccomplishedbya
readtheDataregister(Le.DMAmodeselectbits=0),it
DMAcontrollerorthroughtheWD-Businterface.Ifthe
mustmonitortheDBRstatusbit(inAuxiliaryStatus)to
DMAmodeselectbitsarezero,theprocessormustpoll
determinewhenabyteisavailableforreading.During
theAuxiliaryStatusregisterandcanwritetotheData
Receivecommands,thisstatusbitwillberesetwhena
registeronlywhentheDataBufferReadybitisset
byteisreadfromtheDataregisterandsetwhenabyte
(DBR=1).SendcommandscausetheDBRbittobe
isloadedintotheDataregisterviatheSCSIinterface.
reseteverytimetheprocessorloadsabyteintothe
DBRisalsoresetwhenaReceivecommandisissued.
Dataregisterandsetwhenabyteistransferredfrom
Allinformationtransfersinvolvingotherthandatainfor- theDataregisterontotheSCSIdatabus.TheDBRbil
mationareasynchronous.However.iftheinformation willalsobesetuponissuingaSendcommand.
phaseinvolvesdatatransfers,theSynchronousTrans-
AsinthecaseofReceivecommands,synchronous
ferregisterwillbeevaluated.Inthiscase,anyselected
transferswilloccuronlywhendatatransfersare
offsetotherthanzeroresultsinsynchronoustransfers.
involvedandanoffsetotherthanzeroisselected.
TheminimumTransferPeriodforbothtypesoftransfers
isdeterminedbythetransferperiodbitsinthissame
| 7.5.6 | TRANSFER register. TransferInfoisusedtosendandreceivedata,com | (20HEX) |
| --- | --- | --- |
| 7.5.5 | SEND | (14-17HEX) mand,status,andmessageinformation. AsinthecaseoftheRECEIVEcommands.thereare fourSendcommandswhicharedistinguishedonlyby the stateofthe1/0-,C/D-,andMSG-pinsandthetype of datathatistransferred.ThefourSendcommands, alsovalidintheConnected-as-a-Targetstateonly,are |
| SEND | COMMANDTYPE | OPCODE MSG CID 1/0 |
| Send | Status | 14 0 1 1 |
| Send | Data | 15 a a 1 II ! |
| Send | MessageIn | 16 1 1 1 |
| Send | UnspecifiedInfoIn | 17 1 a 1 |
27

ThefirstReq- assertionfollowingconnectionasan Ifaparityerrorisdetectedonadatabytereceivedfrom
Initiator,resultsina"servicerequired"interrupt.The theSCSIbus(andHSP=1).oron adatabytereceived
processorshouldexaminetheSCSIStatusregisterto fromthehost(andHHP=1).thentheWD33C93Awill
determinethetypeanddirectionofinformationtransfer terminatethecommandand.forSCSIparityerrors.will
requestedbytheTarget.andthenissueaTransferInfo leaveACK-asserted(toalsohalttheTarget).Inthis
commandinresponse.WhileanInitiator.the casea"terminated"interruptisgenerated.Finally.
WD33C93Awillalsogenerateaninterrupteachtime negationoftheBSY- signal(Le.theTargetsuddenly
theTargetdevicerequestsanewtypeofinformation disconnects)oratransitioninthe1/0-.C/D-.and/or
transferphase. MSG-pinsduringaTransfercommandwillalsotermi-
natethecommandandgeneratea"terminated"
AsinthecaseoftheSendandReceivecommands.
interrupt.
whentheTransferInfocommandcompletionistobe
dependentupontheinternaltransfercounter.thepro- Ifaparityerrorisdetectedonareceivedbytebutparity
cessorshouldloadtheTransferCountregisterpriorto errorcommandterminationisdisabled(HSP=0or
issuingthiscommand.TheDMAmodeselectbitsinthe HHP=O,asappropriate).theWD33C93Awillstillset
Controlregister.theoffsetandtransferperiodbitsinthe theParityErrorstatusbitintheAuxiliaryStatusregister
SynchronousTransferregister.andtheSBTbitinthe butwillnotterminatethecommandasaresultofthis
CommandregisterareusedduringTransferInfocom- error.
mandsjustastheyareduringtheSend-And-Receive
| commands.However.forprocessoraccessoftheData | 7.5.7 TRANSLATEADDRESS registerduringTransferInfocommands(whentheDMA TheTranslateAddressCommandisusedtoperforma modeselectbitsarezero.orthebusphaseisotherthan logical-tophysical-addresstranslation.CertainSCSI Dataphase).behavioroftheDataBufferReady(DBR) commandsinvolvealogicaladdresswhichmaybeupto statusbitisdeterminedbythedirectionofinformation 32bitsinlength.Whenacommandisdetectedwhich transferasdefinedbythe1/0-pin.Whenthetransferis requires addresstranslation.theprocessorcanreload fromInitiatortoTarget.theDBRbitisresetbywritingto thelogicaladdressintotheWD33C93ALogical theDataregisterandissetwhenthebyteistransferred AddressregisterandthenissuetheTranslateAddress fromtheDataregisterontotheSCSIdatabus.When commandtohavetheWD33C93Adotheconversion. thetransferisfromTargettoInitiator.DBRissetwhena Uponreceivinga"successfulcompletion"interrupt.the byteisreceivedovertheSCSIdatabusandtransferred processorcanreadthreeWD33C93Aregistersto intotheDataregisterandisresetbyreadingtheData extracttheCylinderNumber.HeadNumber.andSector register.DBRisalsoresetwheneveraTransferInfo Numbercorrespondingtothelogicaladdress.Thedisk commandisissued. parameterscontainedintheTotalSectors.TotalHeads. andTotalCylindersregistersmustalsobevalidbefore ThereareseveralcausesofaTransferInfocommand issuingaTranslateAddresscommand. completion/terminationinadditiontoareset.Justasfor aSendorReceivecommand,theTransferInfocom- Ifautomaticcompensationforsparesectorsistobe mandcanbeterminatedbyissuingasubsequentDis- performedbytheWD33C93A,thenthenumberof connectorAbortcommand.TheAbortcommandwill sparesectorspercylinderandtotalnumberofsectors causea"paused/aborted"interrupttobegenerated percylindermustalsobeloadedintheHeadNumber afterexecutiOn(leavingtheWD33C93Ainaconnected andCylinderNumberregistersrespectively.A"termi- state).whiletheDisconnectcommandcausesanimme- nated"interruptwilloccurifanydivisionoperation diatedisconnectanddoesnotgenerateaninterrupt. performedduringthiscommandresultsinanoverflow. ATransferInfocommandwillbeeithercompletedor pausedwhenthespecifiednumberofbytes(eithera 7.6 COMBINATIONLEVELIICOMMANDS singlebyteormultiplebytesasdefinedbytheSingle- | (18HEX) |
| --- | --- | --- |
| ByteTransferbitintheCommandregister)havebeen | 7.6.1 | SELECT-AND-TRANSFER sentorreceived.TheWD33C93Ageneratesa"suc- (08AND09HEX) cessfulcompletion"interruptonlyafterreceiving TheSelect-And-Transfercommandsarecapableof anotherREO-fromtheTargetduringnon-MessageIn greatlyreducingthehostorlocalprocessorinterrupt- informationphases.butgeneratesa"paused/aborted" handlingburdenbyenablingtheWD33C93A'sinternal interruptforMessage-Inphaseswithoutwaitingforan microprocessortomanagethelow-levelSCSIprotocol. additionalREO-(NotethatwhenthecompletedTrans- ferInfocommandwasaMessage-Intransferphase.the ACK-pinwillbeleftassertedbytheWD33C93Ainthe lastREO-ACKcycleofthecommand.andthepro- cessorisrequiredtoissueanegateACKoranAssert ATNfollowedbyaNegateACKcommandtoacceptor rejectthemessagerespectively). |
28

ThisresultsinasfewasoneinterruptperSCSIopera- throughouttheentireSelect-And-Transfercommand
tion.Select-And-Transfercommandsareusedwhenin execution,iftheTargetrequestsanunexpectedinfor-
anInitiatorrole.andtypicallyconsistofatleastthe mationphasetype,theWD33C93Aterminatesthe
followingSCSIphases:(1)SelectionofaTargetdevice; commandandgeneratesa"terminated"interrupt.If
(2)Sendingofacommand;(3)Receptionofstatus theCommandphaseisrequ~stedin.thissituation,the
information;and(4)ReceptionofaCommandCom- WD33C93AwillextracttheSCSIcommandfromthe
pleteMessage.Thesecommandsoptionallyconsistof internalCommandDescriptorBlockregistersandsend
aDataTransferphaseandadditionalMessageTransfer 6,10,or12bytesofcommandinformationasdeter-
phases.DuringexecutionofaSelect-And-Transfer minedbyitsevaluationoftheSCSIcommandcodein
command,theCommandPhaseregisterwillbe theCDB1register.TheCommandPhaseregisterisset
updatedtoindicatewhichbusphasesoftheSCSI toHex30beforethefirstCommandbyteissentand
operationhavebeencompleted,sothatuponcomple- thenincrementswitheachbytetransferred,so thatfora
tionorterminationofthecommand,theWD33C93A 12-byteCDBcommandtheCommandPhaseregister
maybeinterrogatedtofindoutwheretheSCSIopera- willcontainHex3CwhenallbytesoftheCDBhavebeen
tionwasstopped. transferred.
ThetwoSelect-And-Transfercommandsaredis- AftertheCommandphase.theWD33C93Aexpects
tinguishedfromeachotheronlybywhetherornotthe eitheraDataInphase.DataOutphase.Statusphase.
ATN-pinisassertedduringtheSelectionphase.Select- orMessageInphase.IftheTargetisrequestinga
And-TransfercommandsdirectlysupportGroup0(6- MessageInphase.apendingdisconnectionis
byteCDB).Group1(10-byteCDB),andGroup5(12- assumed.TheWD33C93Athereforeexpectstoreceive
byte)SCSIcommands.Inaddition.theabilitytohave eitheraSaveDataPointerMessage(Hex02)ora
ATN- assertedduringSelectionsupportstheSCSI DisconnectMessage(Hex04).Ifeithermessageis
MessageProtocolwhichcallsforanIdentifyMessage incorrect.orifadifferentmessageisreceived.a"termi-
OutphasefollowingtheSelection.WhentheSelect nated"interruptwillbegeneratedtoalerttheprocessor
w/Atn-And-Transfercommandsisissued,the ofthatfactandtoallowthemessagetobereadfromthe
WD33C93Aexpectsthefirstinformationphaserequest Dataregister.A"terminated"interruptwillalsobegen-
fromtheTargettobeaMessageOutphase,whereasfor eratediftheTargetdisconnectsbeforesendingthe
aSelectwloAtn-and-Transfercommand,thefirstinfor- Disconnectmessage.WhenacorrectSaveData
mationphaserequestisexpectedtobeaCommand Pointermessageisreceived,a"paused/aborted"inter-
Outphase. ruptisgeneratedandtheSelect-And-Transfercom-
mandterminatedtoallowtheprocessortosavethe
WhenaSelect-And-Transfercommandisissued.the
SCSIdatapointers.However.ifaDisconnectmessage
WD33C93AarbitratesforthebusandselectsaTarget
isreceived.theCommandPhaseregisterwillbe
justasduringaSelectcommand.IftheTargetdoesnot
updatedtoHex42andcommandexecutioncontinues.
respondbeforeatimeoutoccurs,theSelect-And-Trans-
fercommandisterminatedanda"terminated"interrupt
WhentheactualTarget-disconnectiondoesoccur.the
isgenerated.FailuretocompletetheSelectionphaseis
CommandPhaseregisteris·updatedtoHex43andif
alsoindicatedbythefactthattheCommandPhase
theIDIbitisset.theWD33C93AterminatestheSelect-
registercontainsall zeroes.IftheSelectionissuccess-
And-Transfercommandbygeneratingan85Hinterrupt.
ful.no interruptisgenerated.buttheCommandPhase
However.iftheIDIbitisreset.theninsteadthe
registerwillbesettoaHex10.
WD33C93Asitsinanidlestate.waiting fortheTargetto
reconnect.IfadifferentTargetdeviceReselectsthe
AftercompletingtheSelectionphase.theWD33C93A
WD33C93A.a"terminated"interruptisgenerated.
beginsaninformationtransferphase.IfATN-hasbeen
However.iftheoriginalTargetReselectsthe
asserted(Le.aSelectw/Atn-And-Transfercommand
WD33C93A.nointerruptisgeneratedandtheCom-
wasissued),theWD33C93AexpectstheTargetto
mandPhaseregisterissettoHex44.
respondwithaMessageOutphase.Ifthefirstinforma-
tionphaserequestisotherthanaMessageOut FollowingtheoriginalTargetReselection.the
request,theWD33C93Awillterminatethecommand WD33C93AexpectsaMessageInphasewhichshould
andgeneratea"terminated"interrupt.However,when consistoftheTargetsendinganIdentifyMessage.This
theTargetdoesrequestaMessageOutphase.the Single-bytemessageshouldbeofthebinaryform:
WD33C93Awillrespondbyautomaticallysendingan 10000ttt.wheretttistheTargetLun.Ifthedatareceived
IdentifyMessage.Thissinglebytemessageisofthe bytheWD33C93AisdifferentortheTargetLunspec-
binaryform:1rOOOttt,wherer=1iftheEnableReselect ifiedinthisbytedoesnotmatchthecontentsofthe
bitintheSourceIDregisterisequalto1,andtttisthe TargetLunregister,a"terminated"interruptisgener-
encodedTargetLogicalUnitNumbercontainedinthe atedandtheMessagebytemaybeexaminedby
TargetLUNregister.OncetheIdentifyMessagehas theprocessor.AcorrectIdentifyMessageInphasere-
beensent,theWD33C93AwillsettheCommandPhase sultsintheCommandPhaseregisterbeingupdated
registertoHex20. toHex45.
FollowingtheMessageOutphase(orSelectionphase AftertheIdentifyMessageisreceivedfromtheTargetor
whenATN-wasnotassertedduringSelection),aCom- immediatelyaftertheCommandOutphase(whenthere
mandphaseisexpectedbytheWD33C93A.Again,and isnodisconnection).aDataInphase.DataOutphase.

orStatusphaseshouldoccur.IftheTransferCount statusbyteisstoredintheTargetLunregisterwhereit
registercontainsanynon-zerovalue.thenthe canbereaduponcompletionof thecommand.
WD33C93AwillexpectaDataTransferphase.If
Followingcompletionofthe status-bytetransfer.aMes-
AdvancedFeaturesareenabled.thentheDPDbitwill
sageInphaseisexpected.TheWD33C93Aexpectsthe
beexaminedtoverifythecorrectdatadirection.Ifthe
TargettosendaCommandCompleteMessage(Hex
datadirectionisincorrect.thena"terminated"interrupt
00)toindicatethattheSCSIcommandoperationhas
isgenerated.Inthisphase.theWD33C93Awillusethe
beencompleted.AftertheWD33C93Areceivesthis
TransferCountregistertodeterminethenumberof
CommandCompleteMessage.theCommandPhase
bytestobetransferred.andallhost-sideDataregister
registeradvancestoHex60.andiftheEDIbitisreset.a
accesseswillbeaccomplishedviathemethodselected
"successfulcompletion"interruptisgenerated.The
bytheDMAmodeselectbitsintheControlregister.
processorshouldthenreadtheTargetLunregisterto
Whentheinternalcounterreacheszero.theData
examinetheTargetstatus.Anadditionalinterruptwill
TransferphaseiscompleteandtheCommandPhase
thenoccurwhentheSCSIbusgoestotheBusFree
registerissettoHex46.
state.orwhenanotherREO-isassertedtobeginan
Notethatanynumberofdisconnection/reconnection informationtransferphase(asinSCSIlinkedcom-
cyclesmayoccurduringtheDataTransferphaseso mands).IftheEDIbitisset.the"successfulcompletion;
longastheyareaccomplishedaccording tothedefined interruptwillbesuppressedLintiltheTargetdisconnects
messageprotocol.TheCommandPhaseregisterwill fromtheSCSIbus.
cyclethroughthedisconnectphases(41-45)witheach
AtanytimeduringexecutionoftheSelect-And-Transfer
disconnectionandsubsequentreconnectionuntilallof
commands.anabnormalorunexpectedconditionwill
thedatahasbeentransferredandtheDataTransfer
causetheWD33C93Atoterminatethecommand.set
phaseiscomplete.
theappropriatestatusqualifiers.andgeneratea"termi-
AStatusphaseisexpectedbytheWD33C93Afollowing nated"interrupt.Iftheterminationoccurredduringan
theDataTransferphase(orinsteadoftheDataTransfer informationtransfer phase.theWD33C93Awillbeleft
phasewhentheTransferCountregistercontainsa inaConnected-as-an-Initiatorstate(unlesstermination
valueofzero).Atthestartof  theStatusphase.the wasduetoasuddenTargetdisconnection).Command
CommandPhaseregisterisloadedwithHex47.Upon terminationduringanyotherphasewillresultinthe
completionoftheStatusphase.theCommandPhase WD33C93AbeinginaDisconnectedstate.Transfer
registerwillbeupdatedtoHex50.andthereceived
COMMAND
MEANING
PHASE
00 NoSCSIbusdevicehasbeenselected.TheWD33C93Aisinthedisconnectedstate.
TheTargethasbeenselected.TheWD33C93AisnowintheconnectedasanInitiator
10
state.
20 AnIdentifymessagehasbeensenttotheTarget.
30 Commandphasehasstarted.nobytestransferred.
3x Commandphase,xbyteshavebeentransferred.
41 SaveDataPointermessagereceived.
42 Disconnectmessagereceived,busnotfree.
Targethasdisconnected(SCSIbusfree)followingasuccessfultransferofa
43
Disconnectmessage.TheWD33C93Aisnowinthedisconnectedstate.
TheWD33C93AhasbeenreselectedbytheTargetwhoseSCSIbus10matchesthe
44 valueintheDESTINATION10register.TheWD33C93Aisnowintheconnectedasan
Initiatorstate.
TheWD33C93AhasreceivedanIdentifymessagefromtheTargetwhoseLogicalUnit
45
NumbermatchesthevalueintheTARGETLUNregister.
ThenumberofbytesspecifiedintheTRANSFERCOUNTregisterhavebeen
46
transferredto/fromtheTargetduringaDataOutllnphase.
47 TheTargethasbegunaReceiveStatusphase.
TheWD33C93AhassuccessfullyreceivedaStatusbytefromtheTargetandstoredit
50
intheTARGETLUNregister.
TheWD33C93AhassuccessfullyreceivedaCommandCompletemessagefromthe
60
Target.

COMMAND
MEANING
PHASE
ResumeafterTargetselectioniscomplete.
10
ResumeafterIdentifymessageout.Commandphaseisexpected;animplie«;lNegate
20
ACKoccurs.
ResumewhenCommandphasehasbegun(REO-asserted).
30
ResumeafterCommandphaseorafterSaveDataPointermessage.Data,Status,or
41
MessageInphasesareexpected.AnimpliedNegateACKoccurs.
ResumetocompleteDisconnectMessageIn;animpliedNegateACKoccurs.
42
44 ResumeafterreselectionbyaTarget.
Resumetotransfermoredatainadatatransfer phase.MayexpectStatusor
45
MessageInaswell.AnimpliedNegateACKoccurs.
Resumeafterthedataphasehasbeencompleted,expectingStatusphaseoraSave
46
DataPointer/DisconnectMessageInphase.AnimpliedNegateACKdoesnotoccur.
ResumetocompleteaStatusphase;animpliedNegateACKoccurs.
50
ResumetocompleteaCommandCompletemessagefromtheTarget;animplied
60
NegateACKoccurs.
commandsmaybeusedtohandletheexceptionby (1)Reselect-and-Receivecommand,EDI=0,
transferringmessageswiththeTarget. andSCC=don'tcare:
Thefollowingtablesummarizesthepossiblevalues •Reselectionphase;
thattheCommandPhaseregistercantakeduringthe •SendIdentifyMessageIn;
Select·And·Transfercommands,andtheirmeanings •ReceiveDataOutphase;
relativetocommandtermination: •Completioninterrupt.
A"ResumeSelect-And-Transfer"commandis
(2)Reselect-and-Sendcommand,EDI=0,
assumedwheneveranormal"Select-And-Transfer"
andSCC=don'tcare:
commandisissuedwhiletheWD33C93Aisinthe
•Reselectionphase;
Connected-Initiatorstate.Whenthe"Resume"isiss-
•SendIdentifyMessageIn;
ued,theWD33C93AexaminestheCommandPhase
•ReceiveDataInphase;
RegistertodeterminewheretorestarttheSelect-And-
•Completioninterrupt.
Transfercommandexecution.Thisfeature,inconjunc-
tionwiththeIntermediateDisconnectInterrupt (3)Reselect-and-Receivecommand,EDI=1,
enabled,allowssupportofmulti-threadedorover- andSCC=O:
lappedI/OontheSCSIbus.
•Reselectionphase;
Thetableabovebrieflydescribesthevalidsettingsof •SendIdentifyMessageIn;
theCommandPhaseregisterwhenresumingaSelect- •ReceiveData Outphase;
And-Transfercommand: •ChaintoSe.nd-Status-and-CommandComplete.
(4)Reselect-and-Sendcommand,EDI=1,
7.6.2	RESELECT-AND-TRANSFER	andSCC=O:
(OAANDOBHEX)
•Reselectionphase;
TheReselect-And-Transfercommandsincludethe •SendIdentifyMessageIn;
Reselect-and-ReceiveDataandtheReselect-and- •ReceiveDataInphase;
SendDatacommands.Thesecommandscausethe •ChaintoSend-Status-And-CommandComplete.
WD33C93AtoexecutecertaincommonSCSIbus
(5)Reselect-and-RCVcommand,EDI=1,
phasesequencesasaTargetfollowingaReselection
andSCC=1:
phase.Thesephasesaredeterminedbywhichcom-
•Reselectionphase;
mandissent,andthesettingoftwobits:theEDIbitin
•SendIdentifyMessageIn;
theControlRegister;andtheSCCbitintheDestination
•RCVDataOutphase;
10register.TheSCSIbusphasesequencesaresum-
•ChaintoSend-Disconnect-Message.
marizedbelow.Refertothecommanddescriptionsof
theSend-Status-And-Command-CompleteandSend-
Disconnect-Messagecommandsfordetailsonthose
sequences.

(6)Reselect-and-Sendcommand.EDI=1. orifaparityerrorisdetectedonanincoming databyte
andSCC=1: (andHSP= 1orHHP=1,dependingondatadirection).
thecommandwillbeterminatedandJheappropriate
•ReselectiQJ1phase;
statuswillbeset.Inthiscase.theCommandPhase
•SendIdentifyMessageIn;
registershouldbeevaluated todeterminethelastsuc-
•SendDataInphase;
cessfullycompletedphase.Ifnoneoftheseconditions
•ChaintoSend-Disconnect-Message.
occurs.allphasescompletenormally.andifEDI=O.
IfthereselectionattempttimesoutduringaReselect- thena"successfulcompletion"interruptwouldbegen-
And-Transfercommand.ATN-isassertedandHA=1. eratedatthispoint.However.ifEDI=1.nointerruptis
COMMAND
MEANING
PHASE
NoSCSIbusdevicehasbeenreselected.TheWD33C93Aisinthedisconnected
00
state.
!
TheWD33C93AhassuccessfullyreselectedtheInitiator.TheWD33C93Aisnowin
10
theconnectedasaTargetstate.
TheIdentifymessagehasbeensuccessfullysenttotheInitiator.
20
46 Therequesteddatatransferhasbeencompleted.
generatedandcommandchainoccurs(asdescribed ConnectedasaTargetstate.Whenthe"Resume"is
above). issued.theWD33C93AexaminestheCommandPhase
RegistertodeterminewheretorestarttheReselect-
Thefollowingtablesummarizesthepossiblevalues
And-Transfercommandexecution.Thisfeature.incon-
thattheCommandPhaseregistercantakeduringthe
junctionwiththecapabilitytochaintoothercombina-
Reselect-And-Transfercommands.andtheirmeanings
tioncommands.allowslongerSCSIbussequencesto
relativetocommandtermination.Seeothercommand
beexecutedbyasinglecommand.
descriptionsforadditionalvaluesthatcanoccurwhen
commandchainingisused. Thefollowingtablebrieflydescribesthemeaningofthe
CommandPhaseregisterwhenresumingaReselect-
A"ResumeReselect-And-Transfer"commandis
And-Transfercommand:
assumedwheneveranormal"Reselect-And-Transfer"
commandisissuedwhiletheWD33C93Aisinthe
COMMAND
MEANING
PHASE
10 ResumeafterInitiatorreselectioniscomplete;startwithIdentifyMessageOut.
ResumeafterIdentifyMessageOut;startwithdatatransferphase.IfTransferCount
20 iszero.nodatatransferphaseoccurs.Ineithercase.achaintoanothercombination
commandcanoccurifenabled.
7.6.3 WAIT·FOR·SELECT·AND·RECEIVE messagefromtheInitiator,beforecontinuingonwith
theimplied"ReceiveCommand"toreceivetheSCSI
(OCHEX)
commandinformation.TheSCSIcommandinformation
TheWait-For-Select-And-Receivecausesthe
(COB)willbestoredintheCOBregisters(Hex
WD33C93AtoidleuntilitisselectedbyanInitiator,at
addresses03toOE),andifavalidIdentifymessageis
whichtimetheWD33C93AwillentertheTargetmode
received,itwillbesavedintheTargetLunregister(Hex
andmessageandcommandinformationwillautomat-
addressOF).Thenumberofcommandbytesrequested
icallyberequested.Asanoption,theWD33C93Amay
bytheWD33C93AisdeterminedbytheSCSIgroup
beprogrammedtodisconnectwhenaSCSIreadcom-
codeinthefirstbyteofthe.COB.
mandisreceivedwhileexecutingaWait-For-Select-
And-Receivecommand.Useofthiscommandtherefore
AftertheWD33C93Aisselectedandreceivesallvalid
eliminatestheinterruptswhichnormallyoccurafter
commandandmessageinformation,a"successful
selectionandafter eachsubsequentSCSIbusphase,
completion"interruptwillnormallybegeneratedto
andresultsinveryshortbus-connecttimeduringSCSI
allowthelocalprocessortoreadoutandinterpretthe
readcommands.
SCSICOB.However,bysettingtheEDIbitpriorto
IfATN-wasassertedbytheInitiatorduringtheselection issuingaWait-For-Select-And-Receivecommand,the
phase.theWD33C93Awillfirstexecuteanimplied WD33C93Aisenabledtoperformanautomaticdiscon-
"ReceiveMessageOut"commandtogettheIdentify nectwhenaSCSIreadcommandisreceived.There-
32

fore,whenEDI=1andthe1stCDSbytereceived pletedbeforetheerrorconditionoccurred.ACommand
containsa6,10or12bytereadcommandcode,then PhaseHexvaiueofHex10indicatesthatthe
theWD33C93Awilltemporarilysuppresstheinterrupt WD33C93Awass..ccessfullyselected.AHexvalueof
andchaintobeginexecutionofaSend-Disconnect- 20indicatesthatamessagewasreceivedfromthe
Messagecommand.Aninterruptwillthenbegenerated Initiator.andwhentheWD33C93Abegmsreceiving
.aftercompletionofthiscommand,whichnormally commandbytes.treCommandPhaseissettoHex30
wouldindicateatransitiontothebusfreecondition. andincrementswit~eachbytereceived(toamaximum
RefertotheSend-Disconnect-Messagecommand of3Cfora12-byteCDScommand).
descriptionformoredetails.
Thefollowingtablesummarizesthepossiblevalues
Ifduringexecutionthemessageorcommandinforma- thattheCommanc?haseregistercantakeduringthe
tionreceivedfromtheInitiatorisinvalid.theimplied Wait-For-Select-A!1d-Receivecommand.andtheir
receivecommandwillbeterminatedandtheappropri- meaningsrelative:0commandtermination.Seeother
atestatusreported.Inthiscase.theCommandPhase commanddescrio:onsforadditonalvaluesthatcan
registershouldbereadtodeterminewhichphaseofthe occurwhencomma:1dchainingisused.
Wait-For-Select-And-Receivecommandwaslastcom-
COMMAND
MEANING
PHASE
TheWD33C93Ahasnotbeenselected.T11eWD33Cg3Aisinthedisconnectedstate.
00
TheWD33C93Ahasbeensuccessfullyselectedbyt~eInitiator.TheWD33C93Ais
10
nowintheconnectedasaTargetstate.
TheIdentifymessagehasbeensuccessfullyreceivecfromtheInitiator.
20
TheWD33C93Ahasbeguncommandphasebysen:~gtheSCSIbusphasesignals
30
andassertingREO-.
TheWD33C93Ahastransferred1commandbytefre.,theInitiator.TheSCSIStatus
31
mayindicatetheneedforthehosttoloadthecomma1dsizeintotheOWN10register.
3x TheWD33C93Ahastransferredxcommandbytesfr:mtheInitiator.
A"ResumeWait-For-Select-And-Receive"commandis inconjunctionw~thecapabilitytochaintoother
assumedwheneveranormal"Wait-For-Select-And- combinationcOrT':-nands.allowslongerSCSIbus
Receive"commandisissuedwhiletheWD33C93Aisin sequencestobeexecutedbyasinglecommand.
theConnectedasaTargetstate.Whenthe"Resume"is
Thefollowingtable:lrieflydescribesthemeaningofthe
issued.theWD33C93AexaminestheCommandPhase
CommandPhase-egisterwhenresumingaWait-For-
RegistertodeterminewheretorestarttheWait-For-
Select-And-Recervecommand:
Select-And-Receivecommandexecution. Thisfeature.
COMMAND
MEANING
PHASE
ResumeafterselectionbytheInitiatoriscomplete:s:artwithIdentifyMessageOutif
10
ATNisasserted,otherwise.startwithcommandphase.
Resumeafteramessageout:checkthereceivedmessageintheTargetLunregister
20
foravalidIdentifymessage.
ResumeafterIdentifymessageout.Startwithcomr:-andphase.
30
ResumeaftertheWD33C93Ahastransferred1cor.-."'!"IandbytefromtheInitiator.This
31 resumepointisusedonlywhenanunknowngroupc:dehasbeendetectedin
AdvancedMode.andthecommandsizehasbeenIcaaedintotheOwn10register.
33

7.6.4 SEND-STATUS-AND-COMMAND- CDB11issent,followedbyaCommandComplete
message(00Hex).A"successfulcompletion"inter-
COMPLETE (00HEX)
rupnowoccurs.
TheSend-Status-And-Command-Completecommand
(2)CDB12bitO=1,bit1=0:ThestatusbyteinCDB11is
isvalidintheTargetrole,andisusedtocompletea
sent,followedbyaLinkedCommandComplete
SCSIoperationbytransferringtheappropriatestatus
message(OAHex).Achaintothecommandfetch
informationtotheInitiatorpriortodisconnectionfrom
portionofWait-for-Select-and-Receivethenoccurs
theSCSIbus.ThiscommandalsosupportslinkedSCSI
tofetchthenextCDBfromtheInitiator.WD33C93A
operationsbyoptionallyallowingalinkedcommand-
commandexecutionproceedsasdescribedforthat
completemessagetobesentafterlhestatusistrans-
command.
ferred.Linkedcommandcompletemessagesare
controlledbytheCDB12registerwithbitsthat  corre- (3)CDB12bitO=1,bit1= 1 :ThestatusbyteinCDB11is
spondtothestandardlinkedcommandcontrolbitsin sent,followedbyaLinkedCommandCompletewith
theCDB. Flagmessage(OBHex).Achaintothecommand
fetchportionofWait-for-Select-and-Receivethen
BeforeaSend-Status-And-Command-Completecom-
occurstofetchthenextCDBfromtheInitiator.
mandisissued,theCDB11registermustbeloadedwith
WD33C93Acommandexecutionproceedsas
astatusbytewhichwillthenbetransferredacrossthe
describedforthatcommand.
SCSIbus.Also,thelinkcontrolbitsfromthecurrent
CDBmustbeloadedintotheCDB12registertoensure ASend-Status-And-Command-Completecommand
thatthecorrectsequenceoccurs.Notethatthebits maybeterminatedbyATN-assertedwhenHA=1,or
usedbytheWD33C93Aareidenticalinmeaningtothe whenaDisconnectorResetcommandisissued.In
SCSIstandardlinkcontrolbits.Thehostprocessormay addition,itmaybeabortedonaSCSIbus-phase
simplyloadthecontrolbytefromthecurrentSCSI boundarybyissuinganAbortcommand.
commandintoCDB12togetthecorrectfunction.Asthe
Thefollowingtablesummarizesthepossiblevalues
commandexecutionprogresses,theCommandPhase
thattheCommandPhaseregistercantakeduringthe
registerwillbeupdatedtoindicatethelastphase
Send-Status-and-Command-Completecommand.and
completed.
theirmeaningsrelativetocommandtermination.See
Thepossiblesequencescausedbythiscommandare othercommanddescriptionsforadditionalvaluesthat
asfollows: canoccurwhencommandchainingisused.
(1)CDB12bitO=O,bit1=don'tcare:Thestatusbytein
COMMAND
MEANING
PHASE
00 Nooperationoccurred;typically,ATN-wasfoundtobeasserted.
50 Statusphasetransfercompleted.
60 CommandCompletemessagetransfercompleted.
61 LinkedCommandCompletemessagetransfercompleted.
pletecommandexecution.Thisfeature.in
A"ResumeSend-Status-And-Command-Complete"
conjunctionwiththecapabilitytochaintoothercom-
commandisassumedwheneveanormal"Send-Sta-
binationcommands,allowslongerSCSIbus
tus-And-Command-Complete"commandisissued
sequencestobeexecutedbyasinglecommand.
whiletheWD33C93AisintheConnectedasaTarget
state.Whenthe"Resume"isissued.theWD33C93A Thefollowingtablebrieflydescribesthemeaningofthe
examinestheCommandPhaseRegistertodetermine CommandPhaseregisterwhenresumingaSend-Sta-
wheretorestarttheSend-Status-And-Command-Com- tus-And-Command-Completecommand:
COMMAND
MEANING
PHASE
Resumeafterstatusphase.Startwithcommandcompletemessage.Maychainto
50
commandfetchifcommandedtodoso.
34

7.6.5 SEND-DISCONNECT-MESSAGE messageissent.theCommandPhasewillbesetto
(OEHEX) 41H.AftertheDisconnectmessagetransfer.thisregis-
terwillbeupdatedto42H.andafterdisconnectionthe
TheSend-Disconnect-MessagecommandisaTarget-
CommandPhaseregisterwillcontaina43H.
rolecommandwhichmaybeusedtodisconnectfrom
theSCSIbusatanytimeduringaSCSIcommand ASend-Disconnect-Messagecommandmaybetermi-
sequence.ThiscommandconsistsofsendingaDiscon- natedbyATN-assertedwhenHA=1.orwhenaDiscon-
nectmessagebyte.followedbyphysicaldisconnection nectorResetcommandisissued.Inaddition.itmaybe
fromthebus(SCSIbusfree).Aninterruptisgenerated abortedon  aSCSIbus-phaseboundarybyissuingan
onlyaftertransitiontobusfreeoccurs.Asanoption.a Abortcommand.
SaveDataPointersmessagewillautomaticallybesent
Thefollowingtablesummarizesthepossiblevalues
beforetheDisconnectmessagewheneverthe101bitis
thattheCommandPhaseRegistercantakeduringthe
setpriortoissuingthiscommand.
Send-Disconnect-Message.andtheirmeaningsrela-
.TheCommandPhaseregisterisupdatedduringexecu- tivetocommandtermination.Seeothercommand
tionoftheSend-Disconnect-Messagecommandto descriptionsforadditionalvaluesthatcanoccurwben
indicatebusphasestatus.AfteraSaveDataPointers commandchainingisused.
COMMAND
MEANING
PHASE
Nooperationoccurred;typically.ATN-wasfoundtobeasserted.
00
TheSaveDataPointermessagewastransferred.
41
TheDisconnectmessag~wastransferred.
42
ThebusfreestateoccurredaftertheDisconnectmessagewastransferred.The
43
WD33C93Aisnowinthedisconnectedstate.
8. ELECTRICALCHARACTERISTICS
ABSOLUTEMAXIMUMRATINGS
VoltageonanypinwithrespecttoGND - 0.5Vto+7.0V
Operatingtemperature oto70degreesC
Storagetemperature - 55to+125degreesC
Powerdissipation 500mW
InputStaticDischargeProtection 1200Vpintopin
DCOPERATINGCHARACTERISTICS
Ta=0to70deg.C
VCC=+5V+/-.25V,GND=OV
| SYMBOL | CHARACTERISTICS | MIN | ~AX | UNITS | CONDITIONS |
| --- | --- | --- | --- | --- | --- |
| IlL | INPUTLEAKAGE | 10 | uA | VIN=.4TOVCC |  |
| 10L1 | SCSIOUTPUTLEAKAGE (INACTIVE) VCC | 50 | uA | VOUT=.5TO |  |
| 10L2 | OUTPUTLEAKAGE (TRI-STATE) VCC | 10 | uA | VOUT=.4TO |  |
| VIH | INPUTHIGHVOLTAGE | 2.0 | V |  |  |
| VIL | INPUTLOWVOLTAGE | 0.8 | V |  |  |
| VIHYS | SCHMITTTRIGGERINPUT HYSTERISIS(ALLSCSIPINS) | 0.2 | V |  |  |
| VOH | OUTPUTHIGHVOLTAGE | 2.4 | V | 10=-400uA |  |
| VOL1 | SCSIOUTPUTLOWVOLTAGE | 0.5 | V | 10=48.0rnA |  |
| VOL2 | OUTPUTLOWVOLTAGE (ALLOTHERS) | 0.4 | V | 10=4.0mA |  |
| ICC | SUPPLYCURRENT | 20 | mA | Ta=+25deg.C |  |
35

9.	TIMINGCHARACTERISTICS	Where:
Timingcharacteristicsarevalidovertheentireoperat- Tcycistheinternalclockcycletime;
ingtemperature(0to70deg.C)andvoltage(4.75to
Ticlkistheperiodoftheclock attheMCKinput;
5.25Volts)ranges,andarereferencedtoandfromalow
DIVISORistheclockdivisorselectedintheOWN10
voltageof0.8voltsandahighvoltageof2.0volts.All
register.
outputsareassumedtohavealoadcapacitanceof50
picofarads. Forexample,witha16MHzclockinputtothe
WD33C93A,theclockdivisorselectedwouldbe4.
ManyoftheSCSIbustimingparametersthatfolloware
Therefore,thevalueofTcycwouldbe:
definedintermsofaninternalclockcycletimethatis
determinedbytheinputclockandtheclockdivisor
___6_2_.5_n_s_ec_*4___=125nsec
Tcyc =
selectedintheOWN10register.Thiscycletimeis
2
calculatedasfollows:
Ticlk*DIVISOR
Tcyc =
2
9.1 PROCESSOR/DMAINTERFACE
9.1.1 CLK
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| lcp | CLOCKPERIOD | 62.5 | 125 | ns |
| teh | CLOCKHIGH | 28 | ns |  |
| tel | CLOCKLOW tep--------------~~~ f\)--_____~ MCK~-_--/J - .. tel 9.1.2 MR | 28 | ns |  |
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
I
tmr	MRPULSEWIDTH	1	us
I
MR-----\
-_.(
1.....- tmr
36

| 9.1.3 | PROCESSORWRITE- | INDIRECTADDRESSINGMODE |
| --- | --- | --- |
| SYMBOL | CHARACTERISTIC | MIN MAX UNITS |
| tavwl | ADDRVALIDTOWELOW | 0 ns |
| CSLOWTOWELOW | 0 | ns. tclwl |
| WEPULSEWIDTH | 120 twa | ns |
| ~VWh | DATAVALIDTOWEHIGH | 70 ns |
| WEHIGHTOADDR.INVALID | 0 | ns twhai |
| twhCh | WEHIGHTOCSHIGH | 0 ns |
| twhdi | WEHIGHTODATAINVALID | 0 ns |
| twhwl | WEHIGHTOWEORRELOW tAvWL ~ ~tWHA1"'1 | 100 ns |
14
AO
I..-tCLWL.. 1-4-tWHCH--....
\
~	tWE	...	tWHWL
• •
\ /
\-
tOVWH ~~tWHOI1
I~
00-07
37

| 9.1.4 | PROCESSORREAD- | INDIRECTADDRESSINGMODE |
| --- | --- | --- |
| SYMBOL | CHARACTERISTIC | MIN MAX UNITS |
| tavrl | ADDRVALIDTORELOW | 0 ns |
| CSLOWTORELOW | 0 | ns telrl |
| tre | RELOWTODATAVALID | 180 10000 ns |
| t.ldv | REPULSEWIDTHLOWTODATAVALID | 180 180 ns |
| trhCh | REHIGHTO.CSHIGH | 0 ns |
| trhd; | REHIGHTODATAINVALID | 10 40 ns |
| tmrl | REHIGHTOREORWELOW | 100 ns |
| tmB; | REHIGHTOAOINVALID | 0 ns |
| ~ | t,WRL -. I~ | ~ tRHAI |
AO
....tCLRL~ .-tRHCH--+-
\
| lit | ~ ... tRE | tRHRL | ~ |
| --- | --- | --- | --- |
| \ | / | \~ |  |
| .... | tRLDV ~I I.... | ... | tRHDI |
00-07
38

| 9.1.5 | PROCESSORWRITE- | DIRECTADDRESSINGMODE |
| --- | --- | --- |
| SYMBOL | CHARACTERISTIC | MIN MAX UNITS |
| taval | ADDRVALIDTOALELOW | 40 ns |
| talai | ALELOWTOADDRINVALID | 0 ns |
| talwl | ALELOWTOWELOW | 90 ns |
| tclwi | CSLOWTOWELOW | 0 ns |
| WEPULSETOWEHIGH | 120 twe | ns |
| !c,VWh | DATAVALIDTOWEHIGH | 70 ns |
| twhch | WEHIGHTOCSHIGH ns | 0 |
| twhdi | WEHIGHTODATAINVALID | 0 ns |
| twhwl | WEHIGHTOWEORRELOW | 100 Ins |
ALE
-.tCLWL	...	~	tWHCH
14
\
~tALWL-'...	tWE	~...	tWHWL
~
\
\-
~tAVAL~ ,~tovWH-"...twHo,"1
ALAI
.-t .'
00-07=><'--_____---.JXXXXXXXXXXXXXXX\.._____.-JX"---_____
39

/
| 9.1.6 | PROCESSORREAD- | DIRECTADDRESSINGMODE |
| --- | --- | --- |
| SYMBOL | CHARACTERISTIC | MIN MAX UNITS |
| taval | ADDRVALIDTOALELOW | 40 'ns |
| ta1ai | ALELOWTOADDRINVALID | 0 ns |
| talrl | ALELOWTORELOW | 30 ns |
| tclrl | CSLOWTORELOW | 0 n$ |
| REPULSEWIDTH | 180 | 10000ns tnt |
| trldv | RELOWTODATAVALID | 180 ns |
| tmch | REHIGHTOCSHIGH | 0 ns |
| trhdi | REHIGHTODATAINVALID | 10 40 ns |
| tmrl | REHIGHTOREORWELOW | 100 ns |
ALE
| ~tCLRL | ... | ~ | tRHCH • \ \. |
| --- | --- | --- | --- |
| ~ | tALRL.-..... | tRE | ~.. tRHRL .. |
| \ | / | \..... |  |
| r---tAvAL--. | .. | .-.. | tRHOI tRLOV--'1 |
1--
-~'1
x______
00-07X___a_d_d_re_ss__---'XXXXXXXXXXXXX
40

9.1.7 DMAWRITE
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| 1cI1wl | DACKLOWTOWELOW | 0 | ns |  |
| DACK,WRLOWTOOROHIGH | 40 | 90 | ns. 1cI1Qh |  |
| twr | WEPULSEWIDTH | 50 | ns |  |
| twhwl | WEHIGHTOWELOW | 100 | ns |  |
| ~vwh | DATAVALIDTOWEHIGH | 25 | ns |  |
| twhdh | WEHIGHTODACKHIGH | 0 | ns |  |
| twhdi | WEHIGHTODATAINVALID | 0 | ns |  |
| ~hQI | DACKHIGHTOOROLOW ~tOLOH ... ORO(OUT) \ | 30 | ns |  |
| ~tOLWL | ....-tWR~tWHOH DACK(IN) \ ... t.·.'"!WL \ tOVWH tWHOI --1 r- | 4 | tOI-:'- |  |
00-07
xx=xxx_____--'xxxxX/xxxxxxxxxxxxxx
NOTE:ExternalloadonORO&DACKisassumedtobe1KO.
011

9.1.8 DMAREAD
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| tqlrf | OACKLOWTORELOW | 0 | ns |  |
| OACK,RELOWTOOROHIGH | 40 fctlQh | 90 | ns |  |
| REPULSEWIDTH | 80 tro | ns |  |  |
| tmrl | REHIGHTORELOW | 100 | ns |  |
| tndv | RELOWTODATAVALID | 70 | ns |  |
| tmdh | REHIGHTOOACKHIGH | 0 | ns |  |
| trhdi | REHIGHTODATAINVALID | 5 | 40 | ns |
| tmdl | OROHIGHTOOROLOW | 100 | ns |  |
| fcthQI | OACKHIGHTOOROLOW tOLOH .. • ORO(OUT) r-,. | 30 | ns |  |
| ~tOLRL | .. | tRHOH | ~tOHOL DACK(IN) \ |  |
| ... | tRO | .. | tRHRL • \ / |  |
| ~tRLOV | tRHOI I I __________~XXXX~~X~XX~---------XXXXX-.~~XXXX~~XX~X~XX~XXXXXXXXX~~~~~ | .. |  |  |
00-07
NOTE:ExternalloadonORO&DACKisassumedtobe1KO.

9.1.9 WO-BUSBUFFERWRITE
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| tqhSI | OROHIGHTOResLOW | 0 | .ns |  |
| tSIWV | ResLOWTOWEVALID | 0 | 20 | ns |
| two | WEPULSEWIDTH | Tcyc-20 | ns |  |
| tw1dv | WELOWTODATAVALID | 50 | ns |  |
| tWhdi | WEHIGHTOWELOW | 30 | ns |  |
| twhWI | WEHIGHTOWELOW | Tcyc-20 | ns |  |
| OROLOWTOResHIGH | 8*Tcyc | 10*Tcyc tq'Sh | ns |  |
| !shW; | ResHIGHTOWEINVALID | 100 | ns |  |
0
| ~I 04 | taHSL | ~tOLSH----. \ ORO(IN) |
| --- | --- | --- |
| ---.. tSLWV ~ | tSHWI--.. Res(OUT) | ..-- |
| ... | two | ... tWHWL-----. |
| WE(OUT) | \ | / \ ...-twLDV 1-04tWHDI -1 1 -----------------------------------------------~x~______~x~---------------------------------------- |
00-07
..,

9.1.10 WD-BUSBUFFERREAD
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| iqhsi | OROHIGHTORCSLOW | 0 | ns |  |
| RCSLOWTOREVALID | 0 | 20 tallY | ns |  |
| t,.o | REPULSEWIDTH | Tcyc-20 | ns |  |
| tcsVrh | DATAVALIDTOREHIGH | 10 | ns |  |
| trhdi | REHIGHTODATAINVALID | 10 | ns |  |
| trhrl | REHIGHTORELOW | TCYC-20 | ns |  |
| lqlsh | OROLOWTORCSHIGH | 8*Tcyc | 10*Tcyc | ns |
| tShri | RCSHIGHTOREINVALID 0 100 ~ToLsH~ ~taHSL --'1 \ DRW(IN) | ns |  |  |
| ... | TsLRv .- | tSHRI ---. RCS(OUT) | ..- |  |
| .- | tRO | ~.-. tRHRL ~ | ---. |  |
| RE(OUT) | \ \ ..- tOVRH ---.. tRHOI r- ______________~x~________________~x~____________----------- | J |  |  |
00-07

9.1.11 BURSTDMAWRITE
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| letlWI | DACKLOWTOWELOW | 0 | ns |  |
| twlQh | WELOWTOOROHIGH | 75 | ns |  |
| twr | WEPULSEWIDTH | 50 | ns |  |
| twhWI | WEHIGHTOWELOW | 80 | ns |  |
| letvwh | DATAVALIDTOWEHIGH | 25 | ns |  |
| twhdh | WEHIGHTODACKHIGH | 0 | ns |  |
| twhdi | WEHIGHTODATAINVALID .. ORO(OUT) tWHDH DACK(IN) tWHDI | 0 | ns |  |
00-07

9.1.12 BURSTDMAREAD
SYMBOL	CHARACTERISTIC	MIN	MAX	UNITS
I
DACKLOWTORELOW	0	ns
letlrl
tr1qh	RELOWTOOROHIGH	75	ns
I
| trd | REPULSEWIDTH | 80 | ns |
| --- | --- | --- | --- |
| trhrl | REHIGHTORELOW | 80 | ns |
| tr1dv | RELOWTODATAVALID | 50 | ns |
| trhdh | REHIGHTODACKHIGH | 0 | ns |
| trndi | REHIGHTODATAINVALID .. tRLOH ~I ORO(OUT) I | 5 | 40 ns |
| ~ | ~tRO~ tOLRL RHOH t I~ DACK(IN) \ / "- ~tRHRL--. | --... |  |
| \. | I | \. ~t t RLOV RH01 1"- ~ 00-07 ________________~x~____~~x~________~x~______~x______ |  |

9.1.13 INTRQ
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| tihrl | INTRaHIGHTORELOW | 0 | ns |  |
| REPULSEWIDTH | 180 t" | ns· |  |  |
| trhil | REHIGHTOINTRaLOW | 0 | 100 | ns |
| tilih | INTRaLOWTOINTRaHIGH | 100 | ns |  |
| ..tIHRL.. | ... | tRI-'_ | ~~tILIH--.. / \ INTRa ~ ~ tRI \ V |  |

9.2 SCSIINTERFACE
9.2.1 ARBITRATION
..
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| BSY,SELINHIGHTOBSYOUTLOW | 12*Tcyc ~hbl | 16*Tcyc | ns |  |
| ~liO | BSYOUTLOWTOBUS10OUT | -50 | 50 | ns |
| ~ISI | BSYOUTLOWTOSELOUTLOW | 2.2 | us |  |
| .... | tBHBL | ....... \ .... tBllO----... " -----------------------------<~---------------- Igroup --------------------------------------------- Tgroup -----------------------~--------------------- NOTE:Tgroup=signalsdrivenbyaTarget=1/0,CIO,MSG,REO Igroup=signalsdrivenbyanInitiator=ATN,ACK | tSLSL |  |

9.2.2 SELECTINGATARGET(ASANINITIATOR)
| SYMBOL | .CHARACTERISTIC | .MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| SELOUTLOWTO"OR-ED"10OUT | 1.2 taloo | us |  |  |
| "OR-ED"10OUTVALIDTOACK,ATNOUT | 100 tovao | ns |  |  |
| taobh | ACK,ATNOUTVALIDTOBSYOUTHIGH | 100 | ns |  |
| BSYOUTHIGHTOBSYINLOWVALID | 400 ~hbv | ns |  |  |
| ~ISh | BSYINLOWTOSELOUTHIGH _____________________________________________________________________________-JJJ.---\~_ _ ---~..tBHBV....4-- ~_------~----------r_-------------J/ | 100 | ns |  |
I
tSLOO .-,
.---------------(~--------+---------------------
~,..tovAO.~tAOBH...
--------------------
~----------------------------------------
Tgroup
NOTE:Tgroup=signalsdrivenbyaTarget=110,CIO,MSG,REO
49

9.2.3 RESPONSETOSELECTION(ASATARGET)
| SYMBOL | CHARACTERISTIC | .MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| tS1bh | SELINLOWTOBSYINHIGH | 0 | ns |  |
| tivbh | "OR-ED"10VALIDINTOBSYINHIGH | 0 | ns |  |
| tbhbl | SELLOW,10VALID,BSYHIGHTOBSYLOW | 0.4 | 200 | us |
| tblOi | BSY OUTLOWTO"OR-ED"10INVALIDIN | 0 | ns |  |
| tblSh | BSYOUTLOWTOSELINHIGH | 0 | ns |  |
| tavsh | ATNVALIDINTOSELINHIGH | 0 | ns |  |
| tshio | SELINHIGHTOTgroupOUT -----tSLBH / | 100 | ns |  |
| ~tBHBL | ~ | tBLSH c / " t 1vBH ~tBL01--" ------ ----- ---- ------ ~t ~ | ---.. |  |
AVSH
-------------------------(
----------------------------------------------
tSH10
•
Tgroup
---------------------------------------~
NOTE:Tgroup=signalsdrivenbyaTarget=110,C/O,MSG,REO
50

9.2.4 RESELECTINGANINITIATOR(ASATARGET)
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| SELOUTLOWTO"OR-ED"10OUT | 1.2 tsloo | us |  |  |
| "OR-ED"10VALIDTOI/OandTgroupOUT | 100 loviO | ns |  |  |
VALID
| t;Obh | I/OandTgroupOUTVALIDTOBSYOUTHIGH | 100 | us |
| --- | --- | --- | --- |
| tbhbv | BSY OUTHIGHTOBSYINLOWVALID | 400 | ns |
| ~ISh | BSYINLOWTOSELOUTHIGH ...tBHBV~..-- tBLSH / \ --. 41( tSLOO \ | 100 | ns |
I
I
--  -  - -----  -  -  - - - --(
~toVIO~~tIOBH""
I/O -   -   -   -   -   -   -   -  -   -   -   -   -   -   -   -   -   -   - -\'i-I________________
I
group ___________________I
I rl-------------------------------
Tgroup________________________________________________
NOTE:Tgroup=signalsdrivenbyaTarget=C/O,MSG,REO
Igroup=signalsdrivenbyanInitiator=ATN,ACK

9.2.5 RESPONSETORESELECTION(ASANINITIATOR)
| SYMBOL | CHARACTERISTIC | MIN | MAX | 'UNITS |
| --- | --- | --- | --- | --- |
| SELINLOWTOBSYINHIGH | a | ns ts'bh |  |  |
| ~h | "OR-ED"10VALIDINTOBSYINHIGH | a | ns |  |
| 110INLOWTOBSYINHIGH | a | ns ~'bh |  |  |
| !t,hao | SELLOW,10VALID,BSYHIGHTOIgroupOUT | 100 | ns |  |
| taWI | IgroupVALIDOUTTOBSYOUTLOW | 100 | ns |  |
| !t,l'Ibl | BSYINHIGHTOBSYOUTLOW | 0.4 | 200 | us |
| BSYOUTLOWTO"OR-ED"INVALIDIN | a | ns !t,'Oi |  |  |
| BSYOUTLOWTOSELINHIGH | a | ns !t,'Sh |  |  |
| tshbh | SELINHIGHTOBSYOUTHIGH tSLBH BSY----+-----',......_--- tSHBL OBx------- Igroup-  -  - -=:j-- - - - --1--  -  -  -  -  -  -  -.1....'x~a...""';J~---------------- | a | ns |  |
| _ | t,,,,,," | ,,"AO | .. |  |
| 110 | -, ~ro~---------------------------_____- _________- ___- NOTE:Tgroup=signalsdrivenbyaTarget=C/O,MSG,REO Igroup=signalsdrivenbyanInitiator=ATN,ACK *** BSYwillstillbedrivenlowbythereselectingtarget. | . |  |  |
52

9.2.6 RECEIVEASYNCHRONOUSINFORMATIONTRANSFERIN(ACTINGASANINITIATOR),
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| SELINHIGHTOPHASECHANGEIN | 0 | ns lshPC |  |  |
| tildt | 110INLOWTODATABUSTRISTATE | 0 | 125 | ns |
| tpcrt | PHASECHANGEINTOREOINLOW | 400 | ns |  |
| ~vrt | DATAVALIDINTOREOINLOW | 0 | ns |  |
| tnal | REOINLOWTOACKOUTLOW | 0 | 175 | ns |
| tald; | ACKOUTLOWTODATAINVALIDIN | 0 | ns |  |
| talrh | ACKOUTLOWTOREOINHIGH | 0 | ns |  |
| tmah | REOINHIGHTOACKOUTHIGH | 0 | 175 | ns |
| tahPC | ACKOUTHIGHTOPHASECHANGEIN / ------- | 0 | ns |  |
| -...tSHPC | tlLOT | tovRL | ~~tALOI r- \. / |  |
I
Phase
tpCRL
I...
\ /
~tAHPC"
RLAL	ALRH	.....tRHAH•
.t	• -.t	•
\
ATN----------------------------------------------------------------------
NOTE:Phase=signalsthatdefinethebusphaseC/O.MSG
53

9.2.7 SENDASYNCHRONOUSINFORMATIONTRANSFERIN(ACTINGASATARGET)
| SYMBOL | CHARACTERISTIC | MIN | MAX | .UNITS |
| --- | --- | --- | --- | --- |
| SELINHIGHTOPHASECHANGEOUT | 100 tshPC | ns· |  |  |
| tildO | I/OOUTLOWTODATAOUT | 800 | ns |  |
| ~vrl | DATAOUTVALIDTOREOOUTLOW | 55 | ns |  |
| tpcrl | PHASECHANGEOUTTOREOOUTLOW | 500 | ns |  |
| trial | REOOUTLOWTOACKINLOW | 0 | ns |  |
| talm | ACKINLOWTOREOOUTHIGH | 0 | 175 | ns |
| tmdi | REOOUTHIGHTODATAOUTINVALID | 0 | ns |  |
| tmah | REOOUTHIGHTOACKINHIGH | 0 | ns |  |
| tahPC | ACKINHIGHTOPHASECHANGEOUT | 100 | ns |  |
| taM | ACKINHIGHTOREOOUTLOW ..J .-tRHOlr / ~tSHPC" ~tll•OO I tOVRl'" \ .. (PCRl Phase \ / "- _tRlAl• I4-tAL=-"~tRHAH.~tAHPC~ \. J f-4-- tAHRl--. | 0 | 175 | ns |
ATN-------------------------------------------------------------------
NOTE:Phase=signalsthatdefinethebusphaseC/O.MSG

9.2.8 SENDASYNCHRONOUSINFORMATIONTRANSFEROUT(ACTINGASANINITIATOR)
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| SELINHIGHTOPHASECHANGEIN | 0 | ns tshPC |  |  |
| tihdo | I/OINHIGHTODATAOUT | 0 | ns |  |
| tpcrl | PHASECHANGEINTOREOINLOW | 400 | ns |  |
| trtal | REOINLOWTOACKOUTLOW | 0 | 175 | ns |
| ~val | DATAOUTVALIDTOACKOUTLOW | 55 | ns |  |
| talrh | ACKOUTLOWTOREOINHIGH | 0 | ns |  |
| trhah | REOINHIGHTOACKOUTHIGH | 0 | 175 | ns |
| tahdi | ACKOUTHIGHTODATAOUTINVALID | 0 | ns |  |
| tahPC | ACKOUTHIGHTOPHASECHANGEIN / | 0 | ns |  |
| tSHF"C | t'HDO | tDvAL | . | -+ tAHDI |
I-
I"
-----
/
I
Phase
X
I..	tF"CRL	.
\
1
-.tRLAL.....~tALRH~tRHAH~......tAHF"C
-
\
NOTE:Phase=signalsthatdefinethebusphaseC/O.MSG

9.2.9 RECEIVEASYNCHRONOUSINFORMATIONTRANSFEROUT(ACTINGASANTARGET)
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| SELINHIGHTOPHASECHANGEOUT | 100 lshPC | ns |  |  |
| ~hdl | 1/0OUTHIGHTODATABUSTRISTATE | 0 | ns |  |
| lpcrl | PHASECHANGETOREOOUTLOW | 500 | ns |  |
| trial | REOOUTLOWTOACKINLOW | 0 | ns |  |
| ~val | DATAINVALIDTOACKINLOW | 5 | ns |  |
| talrh | ACKINLOWTOREOOUTHIGH | 0 | 175 | ns |
| trtldi | REOOUTHIGHTODATAININVALID | 0 | ns |  |
| trhah | REOOUTHIGHTOACKINHIGH | 0 | ns |  |
| tahPC | ACKINHIGHTOPHASECHANGEOUT | 0 | ns |  |
| tahrl | ACKINHIGHTOREOOUTLOW | 0 | 175 | ns |
J
X--------,-X
| --.tSHPC | tOVAL | tRHOI |
| --- | --- | --- |
| - | tlHOT / '\X | I~ |
| ... | tpCRL | ~ |
I
Phase X
\ J
i'--
--+tRLAL........tALRH..~tRHAH"f4-tAHPC f4-
J
--.	tAHRL	f4-
ATN---------------------------------------------------------------------
NOTE:Phase=signalsthatdefinethebusphaseCID,MSG

9.2.10 RECEIVESYNCHRONOUSINFORMATIONTRANSFERIN(ACTINGASANINITIATOR)
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| ~vrl | DATAVALIDINTOREOINLOW | 0 | .ns |  |
| t~di | REOINLOWTODATAINVALID | 45 | ns |  |
| trlrh | REOINLOWTOREOINHIGH | 50 | ns |  |
| tmrl | REOINHIGHTOREOINLOW | 50 | ns |  |
| talah | ACKOUTLOWTOACKOUTHIGH | Tcyc-10 | ns |  |
| tahal | ACKOUTHIGHTOACKOUTLOW | Tcyc-2S | ns |  |
| tahpc | ACKOUTHIGHTOPHASECHANGE PARAMETERStshpc,tildt,andtpcrlAREALSOAPPLICABLEANDAREIDENTICALTOTHOSEIN9.2.6. -x ...- tRLOI tovRL ~I /XXXX | 0 | ns |  |
I
Phase
~
tRLRH ----1 tRHRL
\ \
tAHPC ~
•
ACK------------------~
ATN--------------------------------------------------------------------.....
NOTE:Phase=signalsthatdefinethebusphaseC/O,MSG
57

9.2.11 SENDSYNCHRONOUSINFORMATIONTRANSFERIN(ACTINGASATARGET)
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| ~Vrl | DATAVALIDOUTTOREOOUTLOW | 55 | ns |  |
| trldi | REOOUTLOWTODATAINVALIDOUT | 100 | ns |  |
| trlrh | REOOUTLOWTOREOOUTHIGH | Tcyc-10 | ns |  |
| trhrl | REOOUTHIGHTOREOOUTLOW | Tcyc-25 | ns |  |
| talah | ACKINLOWTOACKINHIGH | 50 | ns |  |
| tahal | ACKINHIGHTOACKINLOW | 50 | ns |  |
| tahpc | ACKINHIGHTOPHASECHANGEOUT PARAMETERStshpc,tildt,andtpcrlAREALSOAPPLICABLEANDAREIDENTICALTOTHOSEIN SUBSECTION9.2.7. - | a | ns |  |
| ... tOVAl | ... | tRlDI ~I /XX)( |  |  |
I
Phase
....
tRlRH--.. tRHRl
\ \
tAHPC .-.-
•
/
tAlAH--..~tAHAl-.1
ATN--------------------------------------------------------------------
NOTE:Phase=signals thatdefinethebusphaseCID,MSG
58

9.2.12 SENDSYNCHRONOUSINFORMATIONTRANSFEROUT(ACTINGASANINITIATOR)
| SYMBOL | CHARACTERISTIC | .MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| ~val | DATAVALIDOUTTOACKOUTLOW | 55 | ns |  |
| taldi | ACKOUTLOWTODATAINVALIDOUT | 100 | ns |  |
| trlrh | REOINLOWTOREOINHIGH | 50 | ns |  |
| trhrl | REOINHIGHTOREOINLOW | 50 | ns |  |
| talah | ACKOUTLOWTOACKOUTHIGH | Tcyc-10 | ns |  |
| tahal | ACKOUTHIGHTOACKOUTLOW | Tcyc-25 | ns |  |
| tahpc | ACKOUTHIGHTOPHASECHANGE PARAMETERStshpc.tildt.andtpcrlAREALSOAPPLICABLEANDAREIDENTICALTOTHOSEIN9.2.8. DBx_ r-------------~,.------------.,.r------- lro----------------------+----------r--- Phase ~I .. ... tRLRH tRHRL | 0 | ns |  |
I
\ \
----. tAHPC
---
.ACK
J
I~tALAH---. tAHAL
~
ATN-----------------------------------------
NOTE:Phase=signalsthatdefinethebusphaseC/O.MSG
9.2.13 RECEIVESYNCHRONOUSINFORMATIONTRANSFEROUT(ACTINGASATARGET)
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| DATAVALIDINTOACKINLOW | 0 | ns ~val |  |  |
| taldi | ACKINLOWTODATAINVALID | 45 | ns |  |
| REOOUTLOWTOREOOUTHIGH | Tcyc-10 trlrh | ns |  |  |
| REOOUTHIGHTOREOOUTLOW | Tcyc-25 tmrl | ns |  |  |
| talah | ACKINLOWTOACKINHIGH | 50 | ns |  |
| tahal | ACKINHIGHTOACKINLOW | 50 | ns |  |
| tahpc | ACKINHIGHTOPHASECHANGEOUT PARAMETERStshpc•~ldI.andlpcrlAREALSOAPPLICABLEANDAREIDENTICALTOTHOSEINSUBSECTION 9.2.9. | 0 | ns |  |
59

9.2.14 ARBITRATIONTOBUSFREE
| SYMBOL | CHARACTERISTIC | MIN | MAX | ..UNITS |
| --- | --- | --- | --- | --- |
| SELINLOWTOBSYHIGH,DATATRI-STATE | 8*Teye talbh +75 BSY------------------------------~ ~tSlBH---. SEL------------------------------------~\ DBx--~----~(~__________________________________~)~-·-------- 9.2.15 SELECTION(ASANINITIATOR)ORRESELECTION(ASATARGET)TOBUSFREE (SELECTIONTIMEOUT) | ns |  |  |
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| ~adc | TIMEOUTORABORTTODATABUSCLEARED | 0 | ns |  |
| lcICSh | DATABUSCLEAREDTOSELOUTHIGH | 200 | us |  |
| tshdt | SELOUTHIGHTODATABUSTRISTATE | 800 | ns |  |
| tahih | SELOUTHIGHTOentlTRISTATE BSY------------~I SEL--------------------------------~ I~ DBx --------------- --------------------------~----_r------~ | 800 | ns |  |
1--
~roupor----------------------------------------~
Igroup )-------- ------
NOTE:Tgroup=signalsdrivenbyaTarget=110.C/O.MSG,REO
Igroup=signalsdrivenbyanInitiator=ATN,ACK
60

9.2.16 CONNECTEO-AS-AN-INITIATORTOBUSFREE
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| --- | --- | --- | --- | --- |
| tbhdt | BSYINHIGHTODATABUSTRISTATE +75ns | 8.Tcyc | ns |  |
| ~hgt | BSYINHIGHTOIgroupTRISTATE +75ns BSY------------------------~I tBHDT DBx )---------------- Igroup )  -  -  -  -  -  -   -  -   -  -   -  -   -  - NOTE:Igroup=signalsdrivenbyanInitiator=ATN,ACK 9.2.17 CONNECTEO-AS-A-TARGETTOBUSFREE | 8.Tcyc | ns |  |
| SYMBOL | CHARACTERISTIC | MIN | MAX | UNITS |
| ~hdt | BSYOUTHIGHTODATABUSTRISTATE +75ns | 8.Tcyc | ns |  |
| ~hgt | BSYOUTHIGHTOTgroupTRISTATE +75ns | 8.Tcyc | ns |  |
BSY---------------------------J
teHDT 1--
---------------------~------~
DBx ----------------
-----------------------------4---------/
tBHGT
Tgroup_____________________________________)  -  -   -  -   -  -  -   -   -   -  -  -   -  -
NOTE:Tgroup=signalsdrivenbyaTarget=110,C/O,MSG,REO
61

PACKAGEDIAGRAMS
2060!020------~
381! 38
~-------5232!51 ~O"1
I
-r
t
| r | I | I |
| --- | --- | --- |
| 540±015 | 610:!: | 645:!: 030 1372±38 '638:!:76 , ~~~~~~~~~ 020•015 _O~!003~ - 000 3D!08 ~______________________~__________~ -00 [-:~:Js-- ~rn~~rrr~rrT~~~~rrI,"lIrrT, -r 075±025 I 150:!:020 |
| 190±641, | 100±010 38~:!: 51 254±64 152:!:51 018:!:003 46!08 40LEADPLASTIC"PL" | 060±020 |
WD33C93A
,,::':'~----:-004-
~..__.076,!!!!!~
, __:l1O~00'l
f""II ...,'"
;1
t
·4) ~A
j	-0//	'l	i c:;,	-	177mm
ie:::
e:::
c;: ;~".,es
e:::-
O!IO 001T"rP
..'
I '
44LEADPLASTIC"JM"
WD33C93A
62

095±.010
PINllD-
241±25
.--
•
.610±.015 600±015
( 1524±3S
15.49±3S D
,
-1-
| 200±025 | ._______ .25±os 50S0±64 . 050±015 .!S9±3S | 010±003 |
| --- | --- | --- |
| I | ' | , |
| I~1 I | I~ | -.- 185±015 |
| ' , | i'.. | 470±64 |
| II | , | I~ J |
| 050:!:025 | ' | ;  , II |
| 127±64-:roo- ; | --..;~055:!:010 | -i~01S:!:003 |
| --l | _ | 100:!:010 140:!:25 46±OS 2.54:!:25 40LEADCERAMIC"AL" |
WD33C93A
63

COPYRIGHT@'1988WESTERNDIGITALCORPORATION.
•ALLRIGHTSRESERVED.
InformationfurnishedbyWesternDigitalCorporationisbelievedtobeaccurateandreliable.However,noresponsibilityis
assumedbyWesternDigitalCorporationforitsuse;norforanyinfringementsofpatentsorotherrightsofthirdpartieswhichmay
resultfromitsuse.NolicenseisgrantedbyimplicationorotherwiseunderanypatentorpatentrightsofWesternDigital
Corporation.WesternDigitalCorporationreservestherighttochangespecificationsatanytimewithoutnotice.
DOCUMENT#79·000199
WesternDigital
2445McCabeWay
Irvine,California92714
(714)863·0102 (714)474·2033
FAX(714)660·4909 Telex910·595·1139
WD162756i8S7M

IEWESTERNDIGITAL StorageLSIApplications Note
WDReglonalOffiess
| WDLiterature(800)832-4778USA | U.S.A | Califomia | (415)335-2501 |
| --- | --- | --- | --- |
| (SOO)448-8470Canada | Georgia | (404)394-1480 |  |
| (714)932-4900Intemational | Illinois | (708)882-8731 Massachusetts (508)535-5914 |  |
| WDBBS: | (714)753-1234 Texas (214)991-6800 | NewJersey | (201)285-1112 |
| Canada: | Ontario | (416)566-4702 Ouebec (514)697-1532 |  |
| PRODUCT: | Model#:WD33C93A Mant#: 5393 NumberE025-A Convertinl:fromtheWD33C93totheWD33C93A TheWD33C93SCSIBusInterlaceController(SBIC)chiphasbeensupersededby the WD33C93A.Ingeneralthereshouldbenoproblemsinconvertingfromthenon-AtotheApart. Theareasofdifferencesbetweenthetwochipsarelistedinthefollowing pagesunder3sections: I ChangesintheWD33C93Athatcouldcauseconversionissues..................pg2 ThesearedesignchangesintheWD33C93Athatarenotcompatible withnormalhardware/fmnwaredesignpracticesfortheWD33C93. IT ChangesintheWD33C93Athatshouldnotcauseproblems.......................pg3 ThesearedesignchangesintheWD33C93Athatwillnotcauseproblems withnormalhardware/fmnwaredesignpracticesintheWD33C93but shouldbechecked. m ChangesintheWD33C93Athatwillnotcauseproblems.............................pg5 ThesearechangesintheWD33C93Awhichwillcausenoconversionissues. WD33C93ANumberReference: | August17.1990 |  |
| ~odel# | ~anf# | Description |  |
| WD33C93APL0008 | 5393KF09PL | 40pinPlasticDIP |  |
| WD33C93A1M0008 | 5393KF091M WD33C93NumberReference: | 44pinPLCC |  |
| ~odel# | ~anf# | Description |  |
| WD33C93PL00bb | 3393AB09PL | 40pinPlasticDIP |  |
| WD33C931M00bb | 3393AB09IM InternationalOffices: HongKong852-736-5123;Korea822-554-0508;Munich498-9922-0060;Ontario416-566-4702;Paris331-6985-5757; Quebec514-697-1532;Singapore65-448-4700;Taiwan886-2717-4n5;Tokyo813-791-2001;U.K. 443-7274-2955. CopyrightWestemDigital1990 page1of7 | 44pinPLCC |  |

StorageLSIApplicationsNote#E025-A
Changesthatcouldcauseconversionissues;
ThesearedesignchangesintheWD33C93Athatarenotcompatiblewithnormal
hardware/fumwaredesignpracticesfortheWD33C93.
1. CmdDeletion:TransferPadCommand:TheTransferPadcommandisnolongersupport-
edintheWD33C93A.
2. CmdDeletion:AbortCommand:TheAbortcommandisnolongersupportedintheInitia-
tormode.
3. FunctionChange-SinglebyteTransfers:TheWD33C93didnotcorrupttheTransfer
CountregisterduringaSingle-Byte-Transfer.Thisallowedapreviousmulti-byteoperationto
beresumedwithoutreloadingtheTransferCountregisterafteraSingle-Byte-Transfercom-
mand.Thiswasan"undocumentedfeature"thatnolongerexistsin theWD33C93A.The
TransferRegisteriscorruptedduringaSingle-Byte-Transferandmustbereloadedafterexe-
cutionofthatcommand.
4. FunctionChange-PhaseInterrupts: TheWD33C93generatesaPhaseChangeinterrupt
followinganInvalidCommandinterrupt.Thisisanunnecessaryinterruptandbasicallyan
unplanned"feature"oftheWD33C93.TheWD33C93A doesnotprovideaPhaseChangein-
terruptfollowingaInvalidCommandinterrupt.
NumberE025-A
copyrightWesternDigital1990 page2of7

StorageLSIApplicationsNote#E025-A
Chan&esthatshouldn'tmakeadifferenceundernormaluse
ThesearedesignchangesintheWD33C93Athatwillnotcauseproblemswithnonna!hard-
ware/fIrmwaredesignpracticesintheWD33C93butshouldbechecked.
RegisterDifferenceSummary:
Undernormaldesignpractices,thesebitsshouldnotbewrittentonorshouldtheirstateupon
beingreadmakeanydifference.Itissometimesfoundthatpreviouslynon-functionalbitsare
writtentoordecodeduponreadasamatterofprogrammingefficiencyandthereforecause
problemswhenanewversionofapartissubstitutedfortheoriginal.Belowisalistofall
registerchanges(bitsnotpreviouslyactive)thatshouldbecheckedifIrmwareforproper
handling.Formoreinformationonthefunctionofthesebits,pleaserefertoWDStorageLSI
ApplicationNote#E062onVersionDifferencesintheWD33C93chipfamily.
| Register | Bit | WD33C93 | WD33C93A |
| --- | --- | --- | --- |
| a)Own10register: | 3 | EAF-EnableAdvancedFeatures 4 HHP-HaltonHostParityerror 5 EIH-EnableImmediateHalt 6,7 Xfrratecontrol |  |
| b)Controlregister: | 5 | DBA-DMABurstEnable |  |
| c)Destination10register: | 5 | .DF-DataPhaseDirChkEnable 6 DPD-DataPhaseDircheck 7 SCC-SelectCommandChain |  |
| d)CDBByte12register: | 1 | LCC-LinkedCommandControl |  |
| e)SynchXfrregister | 3 | extrabitfor12byteFIFO 2. HIWChange:FasterExecutionTimes- Thecommanddecodeandalgorithmsofmany commandshavebeenmodifie4togreatlyreducecontrolleroverheadinbothTargetandIni- tiatormodes.- Increasesinhostresponsetimingingeneralshouldnotcauseaproblemundernormalde- sign practices,butundersomecircumstancesshouldbechecked. 3. FeatureAddition:NewStatusCodes- Thefollowingstatuscodeshavebeenadded: a)WD33C93AAdvancedFeaturesEnabled-code00000001:Thiscodeisreturnedaftera "SoftReset"iftheEnableAdvancedFeatures(EAp)bitisset(bit4,Own10).Thecode providesa meansofverifyingthepresenceoftheApart. b)UnexpectedReselection-code00100111:Thiscodeisreturnedwhenanunexpected NumberE025-A copyrightWesternDigital1990 page30f7 |  |

StorageLSIApplicationsNote#E025-A
reselectionoccursduringaSelect-and-Transfercommand,andindicatesthattheTarget
LUNregistercontainsavalididentifymessage.
c)Reselection-code10000001:Thiscodeisreturned whenareselectionoccurswhenthe
deviceisidlingwithAdvancedfeaturesModeenabled.ThecodeindicatesthattheData
registercontainsavalididentifymessage.
d)DevicePause-code10000111:Thiscodeisreturnedwhenthedevicehaspausedtoget
thecommandlengthintheOwnIDregister.
NewStatusCodesmaycauseerroneouserrorsintheStatusCodedecodesectionofsome
typesoffmnwarealgorithmsandshouldbechecked.
NumberE025-A
copyrightWesternDigital1990 page4of7

StorageLSIApplicationsNote#E025-A
ChangesintheWD33C93Athatwincausenoconversionissues;
1. HIWAddition:FasterTransferRate-
a)TheWD33C93Acannowtransferdataatupto5MB/s.
b)AburstDMAmodeontheJ.1psidehasbeenaddedtohelpaccommodatehigherdata
bandwidths.Bit5oftheControlregisterhasbeenaddedtoenabletheDMAburstmode.
c)Themaximumclockfrequencyhasbeenincreasedto20Mhz
d)Selectabledividerscontrolledbybits7,6intheOwnIDregisterhavebeenaddedto
managetransferrateandarbitrationtiming.
2. HIWAddition:ExtendedFIFO- TheWD33C93AinternaldataFIFOhasbeenexpanded
to12bytesfrom5bytesforthe WD33C93.Bit3hasbeenaddedtotheoffsetcounterin
theSynchronousTransferregistertoaccommodatetheincreasedFIFOsize.
3. CmdAddition:Send-Status-and-Command-Complete(ODh)- Thistargetmodecom-
mandhasbeenaddedtotheWD33C93A.Thiscommandfirstsendsthestatusbyte,as
specifiedintheCDBbyte11.Thiscommandwillsendalinkedcommandcomplete
message.Linkedcommandcompletewithflagissentwhenbit1ofCOB12isset.The
commandwillalsochaintothecommandfetchportionofWAIT-for-Select-and-receive.
4. CmdAddition:Send-Disconnect-Message(OE)- Thistargetmodecommandisusedto
disconnectfromtheSCSIbuswhenthetargetexpectstoseek, fmdthefirstblock,dealwith
longtapeoperations,fillabuffer,etc..Thecommandsendsthedisconnectmessage,fol-
lowedbyadisconnectfromthebus.IftheIDIbitissettoone,aSave-Data-Pointermes-
sageissentpriortothedisconnectmessage.
S. CmdAddition:SetIDIbit(OF)- ThiscommandisusedtosettheIDIbitwhen alevelIT
commandisinprogress.ThisisneededsincetheregisterfileisnotaccessibletotheJ.1pat
thattime.
6. FeatureAddition:Reselect-and-TransferCmdEnhancement:Thesecommandsmay
nowberesumedinthesamemannerastheinitiatorSelect-and-Transfercommands.Also,
thesecommandsmaybechainedtothenewSend-Status-andCommand-Completeand
Send-Disconnect-MessagecommandsusingtheEDIbitinthecontrolregister,andthe
commandlinkselectbitinthedestinationIDregister.
7. FeatureAddition:Wait-for-Select-and-ReceiveCmdEnhancement:Thiscommand
maynowberesumedinthesamemannerastheinitiatorSelect-and-Transfercommands.
Also,thiscommandmaybechainedtofromthenewSend-Status-and-Command-Complete
command.WhenEDIisset,thiscommandwillchaintotheSend-Disconnect-Message
commandifCDBbyte1indicatesa readcommandhasbeenreceived.
NumberE025-A
copyrightWesternDigital1990 page50f7

StorageLSIApplicationsNote#E025-A
8. FeatureAddition:20MHzclockrate:TheinputclocktimingsfortheWD33C93Ahave
beenchangedfromthoselistedintheWD33C93Adatasheet,whichspecifiedamaximum
frequencyof16Mhz.TheWD33C93Aisnowguaranteedtooperatewithamaximum·
inputclockfrequencyof20MHz,andtherevisedtimingsarelistedbelow:
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| Tcp | ClockPeriod | 50 | 125 | ns |
| ClockHigh | 20 Teh | ns |  |  |
| ClockLow | 20 Tel Tcp ~~ · · Clk | ns |  |  |
| I | \"'-----....,.,/ · · · | \ |  |  |
| :~ | .:~ · | .: |  |  |
| Teh | · | Tel · 14. 9. MscChanges!Additions: a)CDBbyte11register:Thisregisterisnowalsousedtospecify thestatusbyteforSend- Status-and-Command-Completecommands b)COBByte12register:WhentheFlagbit(Bit1)is0and101is1,LinkedCommand Complete(messagecode=OAh)issentduringaSend-Status-and-Command-Complete .command.Whenthisbitis1and101is1,LinkedCommandCompletewith Flag(message code=OBh)issentduringaSend-Status-and-Command-Completecommand. c)TargetLUNregister:Thisregistercanalsocontaintheidentifymessagereceiveddur- inganunexpectedreselectionifadvancedfeaturesareenabled. d)SelectCommandChainControl:Bit7(SCC)intheDestination10registerhasbeen addedtocontrolwhichcommandischainedtowhenthedatatransferiscompleted: oChaintoSend-Status-and-Command-Complete 1ChaintoSend-Disconnect-Message NumberE025·A copyrightWestern Digital1990 page6of7 |  |  |

StorageLSIApplicationsNote#E025-A
WD33C93AIncompatibilitieswhenbeingusedwithaWD33C93alsoontheSCSIbus:.
Perfonnanceoptimizationofboth theinternalmicrocodeandtheLSIdesignhaveresulted
inthefollowingincompatibilitiesbetweentheWD33C93AandtheWD33C93:
a) WD33C93offsetvalues:Duetotimingdifferencesbetweenthetwoparts,the
WD33C93offsetmustnotbesettoitsmaximumvalueoffiveduringsynchronous
transfersfromtheWD33C93AtotheWD33C93.Anyotheroffsetvalue(0through4)may
beused.
b) TheWD33C93AchecksforATN\assertionbeforethestartofadatatransfer.ARe-
ceiveorSendcommandwillhaltifHAissetpriortothetransferofanydata.The
WD33C93allowsadata transfertooccurbeforelookingforATN\
NumberE025-A
copyrightWesternDigital1990 page70f7

~WESIERNDIGITAL StorageLSIApplicationsNote
WDRegionalOffices
| WDLiterature(800)832-4778USA | U.S.A | California | (415)335-2501 |
| --- | --- | --- | --- |
| (SOO)448-8470Canada | Georgia | (404)394-1480 |  |
| (714)932-4900Intemational | Illinois | (708)882-8731 Massachusetts (508)535-5914 |  |
| WD88S: | (714)753-1234 Texas (214)991-6800 | NewJersey | (201)285-1112 |
| Canada: | Ontario | (416)566-4702 Quebec (514)697-1532 |  |
| PRODUCT: | Model#:WD33C93A | August17.1990 |  |
| Manf#: | 5393 | NumberE018-A WD33C93ABU2List KnownProblems: |  |
| PI) | UnexpectedDataInPhase: InitiatormodebugwhichgeneratesaDataInphasefollowingaIdentifymessage | pg2 |  |
| P2) | Assert-ATNbug: UnpredictablebehaviorwhenAssert-ATNcommandusedundersomecircumstances | pg2 |  |
| P3) | FIFOdataloss: FIFOdatalostinphasechangeduringDataOutphase. | pg2 |  |
| P4) | REQ\assertiontimingerror: SCSItimingviolationforphaselinesetuptimespriortoREQ\assertionundersomeconditions | pg2 |  |
| PS) | FalseBusFreedetection: BSY\andSEL\falseglitchesof~200nsmaybeincorrectlyinterpretedasaBusFreecondition | pg3 |  |
| P6) | TwhdiTimingViolation: TimingviolationforTwhdi(WE\hightodatainvalid)intheWDbusinterfacemode. | pg3 |  |
| P7) | Tslrv'TslrvTimingViolation: WD33C93AdoesnotmeetthetimingrequirementsforTslrvorTslwv ----------------_._._------------------------------_.---------------------------_._._--------------- AdditionsandChanges: | pg4 |  |
| 1) | lOMHzclockrate: Maximumclockratechangedto20MHz InternationalOffices: HongKong852-736-5123;Korea822-554-0508;Munich498-9922-0060;Ontario416-566-4702;Paris331-6985-5757; Quebec514-697-1532;Singapore65-448-4700;Taiwan886-2717-4n5;Tokyo813-791-2001;U.K.443-7274-2955. CopyrightWestemDigital1990 page1of4 | pgS |  |

StorageLSIApplicationsNote#E018-A
DETAILEDPROBLEMDESCRIPTIONSandWORK-AROUNDS
PI). UnexpectedDataInPhase:
Affects: Initiatormode,DataInphase,IdentifyMessage
Instructions: Select-and-Transfer
Description: AnunexpectedDataInPhasefollowstheIdentifymessageoutofSelect-and-Trans-
fer.Thismaycausespuriousnewphaseinterrupts.
Work-Around:ResumetheSelect-and-TransfercommandwiththeCommandphaseregistersetto4lh
P2) Assert-ATNbug:
Affects: Initiatormode,IdentifyMessageOut,Commandphase
Instructions: Select-and-Transfer
Description: IssuingtheAssert-A1N\commandduringtheIdentify MessageOutorCommand
phasesoftheSelect-and-TransfercommandwillcausetheWD33C93Atobehaveunpredictably
Work-Around:DonotissuetheAssert-A1N\commanduntiltheCommandphasehascompletedwhen
usingSelect-and-TransferorustheseparateSelectandTransferInfocommandstoimplementtheSelect-
and-Transfer sequenceuptotheendoftheCommandphase.
P3) FIFOdataloss:
Affects: Initiatormode,DataOutphase,Disconnectmessage
Instructions: Select-and-Transfer
Description: TheWD33C93AwillloseanybytesstoredintheFIFOduringtheDataOutphaseof
theSelect-and-TransfercommandwhentheTargetchangesphasetosenda Disconnectmessage.IftheIDI
bitisnotset,thehostwillneverknowthattheFIFObyteswerelost
Work-Around:SettheIDIbitbeforeissuingtheSelect-and-TiansfercommandwhenTargetdisconnects
areenabledandaDataOutphaseisexpected.
P4) REQ\assertiontimingerror:
Affects: Targetmode,timingfromphaselinechangetoREO'assertion
Instructions: Wait-for-Select-and-Receive
Description: Undersomecircumstances,theWD33C93Awillviolatetheminimumtime required
NumberE018-A
copyrightWesternDigital1990 page2of4

StorageLSIApplicationsNote#E018-A
bytheSCSIspecificationbetweenchangingthephaselinesandassertingREQ/Theseviolationsoccurdur-
ingtheWait-for-Select-and-ReceivecommandwhentheWD33C93Asetsthephaselinesforamessageout
phaseandassertsREQ\toobtaintheIdentifymessagebyteandtherustbyteofaTagmessage.
Work-Around:SettheEnableSelection(ES)bitintheSourceIDregistertoallowselectionbyanother
SCSIdevice.UsetheReceive-Messagecommandtorequestanymessagebytesandthenresume
theWait-for-Select-and-Receivecommandstartingwiththecommandphase.
P5) FalseBusFreedetection:
Affects: Busfreedetection
Instructions:
Description: TheWD33C93AmaydetectafalseBusFreecondition.BusFreeisdermedinthe
SCSIspecificationasbothBSY\andSEL\beingfalsefor~400ns.TheWD33C93AmaysignalaBusFree
conditionforBSY\andSEL\beingnegatedfor~s.
Work-Around:Nospecificwork-aroundisavailable.TrytoensureascleanaSCSIbusaspossibleto
minimizereflections.Normalconditionsshouldnotproduceglitchesinthe200nsto400nsrange.
P6) TwhdiTimingViolation:
Affects: Hostbusinterface.WDBusinterfacemode
Instructions:
Description: TheWD33C93AdoesnotmeetthetimingrequirementsforTwhdi(WE\highto
datainvalid)intheWDbusinterfacemode.ThedataholdtimeafterWE\goesfalseisspecifiedas~3Oos.
Theactualholdtimewillperfonnas~IOns
Work-Around:ThespecificationwillbechangedtoTwhdi~IOos.
P7) Tslrv'TslrvTimingViolation:
Affects: Hostbusinterface,WDBusinterfacemode
Instructions:
Description: TheWD33C93AdoesnotmeetthetimingrequirementsforTslrv(RCS\lowtoRr.\
valid)orTslwv(RCS\lowtoWE\valid)intheWDbusinterfacemode.ThesetuptimeforRcs\out
goingtrueuntilRr.\orWE\goestrueisspecifiedas~os.Theinternaltimingfortheseoutputsissuchthat
theactualperfonnanceis~-5nsforRCS\truetoWE\orRr.\true.
Work-Around:ThespecificationwillbechangedtoTslrv,Tslwv~-5ns.
NumberE018-A
copyrightWestern0lgllal1990 page30f4

StorageLSIApplicationsNote#E018-A
AdditionsandChanges
1) 20MHzclockrate:
Afi'eets: maximumClockinputfrequency
Instructions:
Description: TheinputclocktimingsfortheWD33C93Ahavebeentightenedfromthoselistedin
theWD33C93Adatasheet,whichspecifiedamaximumfrequencyof16Mhz.TheWD33C93Aisnow
guaranteedtooperatewithamaximuminputclockfrequencyof20MHz,andtherevisedtimingsarelisted
below:
| Symbol | Characteristic | Min | Max | Units |
| --- | --- | --- | --- | --- |
| ClockPeriod | 50 | 125 Tcp | ns |  |
| ClockHigh | 20 Tch | ns |  |  |
| ClockLow | 20 Tcl | ns |  |  |
| · | Tcp ~.. .~ | · |  |  |
| · | : · · Clk | · |  |  |
| \ | I | \ |  |  |
I
·	·	·
:.. .:..
••
· ·
:	Tch	·	Tcl
·
· ·
· ·
NumberE018-A
copyrightWesternDigital1990 page4of4
