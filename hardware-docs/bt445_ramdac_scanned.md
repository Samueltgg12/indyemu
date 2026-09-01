# bt445_ramdac_scanned

Advance
Thisdocumentcontainsinformationonaproductunderdevelopment.The
parametricinformationcontainstargetparametersthataresubjecttochange.
DistinguishingFeatures Bt445
¢PLLPixelClockGeneration ¢JTAGSupport
| (M/N) | * 160-pinPOFPPackage °veroeeBiInputPixelPort MonolithicCMOS | 150MHz |
| --- | --- | --- |
| » 150.135.and110MHz | Applications | Triple256x8RAMDAC™ Operation ¢High-ResolutionColorGraphics |
| *High-ResolutionTrue-Color | *CAE/CAD/ICAM | ProductDescription Support *ImageProcessing |
| * 1:1to64:1MultiplexedPixel | ¢Instrumentation | TheBt445isdesignedspecificallyforhigh- |
| Port | *DesktopPublishing | performance,high-resolutioncolorgraphics applications.Thewideinputpixelportand *Bt458SoftwareCompatible ColorFlatPanelDisplays internalmultiplexingmodesenableTTL- *ProgrammablePixelFormat compatibleinterfacingtotheframebuffer, |
| *Three256x8ColorPalette | RelatedProducts | whilemaintainingPLL-generated135MHz, |
| RAMs | ternal | ided150MHz video dat |
| * 16x24OverlayPalette | >Bra3l | vtexternaYtoshigh fresh‘ hichata |
| »4x24CursorPalette | ° Bt4ss | ratesrequired forhigh refreshrate, high-res- * Bt858 olutioncolorgraphics. ¢DigitalPixelOutputPort TheBt445supportsPLLpixelclockgen- *Oor7.5IREBlanking eration,supportingavarietyoffrequencies *VRAMShiftClockGeneration usinganM/Ndivisorscheme.Thisdecreases ¢ SystemClockGeneration systemcostduetotheeliminationofmulti- plecrystaloscillatorsthatareusedtosupport FunctionalBlockDiagram avarietyofmonitorandrefreshrates.In addition,the Bt445providestheserial MCLK20 VRAMclock,videoclock,andvarious VAAGNDRANGEXTALIXTAL?S110)cpycuKgMCLK2sREFFSADJUST multi-purposesystemclocks. Usingapatentedpixelportarchitecture, |
| CLOCK —J | PIXE | CPU : . |
| cooel | “wex” | cockY ciock\|pfGRyCADOK Lecome Flexport™,theinputpixelportcanbecon- figuredinanalmostunlimitedvarietyof |
| VIDCLK"“¢ | PIXEL | MEME pixeldepths,multiplexmodes,andinputport |
| SCLK* | LOAD | EXTRACT ptBypass : : |
| VIDCLKE | CONTROLLoGi¢ | . DA——-—>OR widths.Forexample,thesemodesinclude1-, |
| LDISCLK!—1 | ¥ | EXTRACT. FP)3x256X8 2-,4-,8-,12-,16-,and24-bit/pixelpseudo PIXELHeePteewe\|COLOR DAC i106 . |
| a] | Pa] | -feacking [erence] BLINK.&myPALETTE colorandtruecolorwithoverlayandcursor |
| v3.0 | EbalEpptoc | voce\|}36x24 T bAC—-4-108 palettesupport.TheBt445runs24-bittrue |
| s\|sl | Isdé | BYPASS Reo prox color, withi cursor,rover!erlay,@andpalettepal |
| BLANK’tleFY¢ | CURSOR | CURSO 3PSYNC* bypasssupport,atpixelratesfor1280x1024 |
| VSYNC*—4 R | Ra | EXTRACT. DIGITAL >PBLANK’ 7 1 |
| syncvnevnce—4 | oureut | >Pvsynt: monitors.TheBt445isalsoBt458software |
| Tels | >eresPHSYNC* | compatible. |
| RESET’-+>]susconrran\| | [tac | \| >06/30) Otherfeatures includeprogrammable |
| 4 | 4hal | >083-0) setupanddigitalpixeloutputs,asrequired |
| TT] | rT¥ | i i |
| ceRWC120) | TMSTCKT011D0 | 70) foractivematrixTFTsupportorNTSC encoding. BrooktreeCorporation*9950BarnesCanyonRd.«SanDiego,CA92121 (619)452-7580¢(800)VIDEOIC*TLX:383596*FAX:(619)452-1249 & 1445001eC Brooktree’:..; |

Bt445
CircuitDescription
Introduction
TheBt445isaflexible150-MHzRAMDAC,which Pseudo-colormodesaresupportedbysourcing-the
providesmultiplemultiplexoperatingmodeswithmul- red,green,andbluefieldsfromthesamebitsinthe
tipleplanedepthresolutions,whilestillmaintaining sourcepixel.Infact,anyfieldsofaninputpixelmay
Bt458registercompatibility. appearinanyorderorbecoincidentoroverlappedwith
Twophaselockloopsareprovidedtoeliminate otherfields.
high-speedsignalsonthePCBandexpensiveECL Thecolorpalettebypassbitcontrolstheselection
crystaloscillators.Oneisprogrammable((M/N)/L), betweencolorpaletteusageorbypass.Userscanuse
whereMis6bits,Nis4bits,andLcanbe1,2,4,or8) thelookuptableforgammacorrectionortheycan
andisusedtogeneratethepixelclockfrequency.The bypasstheLUTonapixel-by-pixelbasis.Thisallows
secondPLLoperatesfromthesamecrystaloroscillator userstocustomizefeatureswithASICs,whileprovid-
inputasthepixelPLL,andisnotprogrammable.Itmay ingcapabilitiesforcost-efficienthigh-resolution1280x
beusedtoprovideadditionalclockoutputsthatmaybe 1024true-colorgraphics.Colorpalettebypassisavail-
usedfortheCPUsystemclocks,and/orSCSIorEther- ableinallpixelmodes,allowingnumerousmono-
netclocks,forexample. chrome/gray-scaleoptionsontheBt445.
TheBt445’sinputpixelportcanbesoftware-config- TheBt445alsoprovidesadigitalpixeloutputport
uredtobeanywidthfrom1-64pins.Thisallowsmaxi- fromtheDACinputstosupportdrivinganactive
mum.versatilityforframebufferconfiguration.For matrixTFTLCDoranNTSCencodersuchasthe
example,theBt445cansupportaframebufferarchitec- Bt858.TheBt445providesaclock,andthered,green,
turehavinga6:1multiplexed8-bitpseudo-colorframe andbluepixeldatapriortothedecoderoftheDACs.In
buffer(48signals)with2-bitoverlay(12signals).The addition,thepipelinedsyncandblankoutputsarepro-
inputportwidthinthiscasemaybesetto60pins.A videdsothatuserscansynchronizetheirtimingtovalid
pixeldisplayordercanbeselectedtostartfromthe pixeldata.Twomodesofoperationareprovided:4-4-4
lower-numberedbitsoftheinputpixelport(LSB truecolorwherethehigh-ordernibbleofred,green,
unpacking)orfromthehigher-numberedbits(i.e.,the andblueareprovided,andan8-8-8true-colormode
pixelportwidth,MSBunpacking). wherealibitsofred,green,andblueareprovidedata
TheBt445alsoprovidesfullyprogrammablemulti- reducedpixelrate.Whenusingthedigitaloutputport
plexrates(1:1to64:1,anyintegervalue)andfullypro- (i.e.,outputbitsOR3-ORO,OG3-OG0,orOB3-OB0),
grammablepixelwidths(1to32bitsperpixel,any theDACoutputqualityisnotguaranteed.
integervalue).Theonlyrestrictionsarethatthepixel Forbattery-poweredapplications,variouspower-
portstartposition,multiplexrate,andpixelwidthbe downmodesareavailable.Inonemode,theRAMand
consistent.Thismeansthatthenumberofbitsperpixel DACsareturnedoff.TheRAMretainsdataandmaybe
multipliedbythemultiplexratemustbelessthanor accessedforreadorwriteoperationsbytheMPU.
equaltothenumberofinputportbitsconfigured.Also, Anothermodepowersdownthepixelclock,RAM,and
whenconfiguredfor1:1multiplexed,themaximum DACs.AvideoRAMshiftclock(SCLK*)isprovided
pixelrateislimitedbytheinputpixelportrate,asindi- bytheBt445,changingthecyclefrequencyincorre-
catedintheACCharacteristicssection. spondencewiththemultiplexfactor.Thissimplifies
Afterpixelserializationhasoccurred,theBt445 timingrequirementstodevelopexternallogicfor
allowsfullconfigurabilityforsourceandwidthselec- VRAMtiminggeneration.Inaddition,theBt445pro-
tionofthered,green,blue,overlay,cursor,andpalette videsanotheroutputclock(VIDCLK*)whichshould
bypassfieldsofthesourcepixel.Forexample,ina16- beusedforthegenerationoftheCRTtimingsignals.
bitwidepixel,theredfieldmaycomefrombits4—0,
greenmaycomefrombits9-5,bluemaycomefrom
bits14-10,andpalettebypasscontrolmaycomefrom
bit15ofthepixel.
5-4 SECTION5

Brooktree* Bt445
CircuitDescription(continued)
MPUInterface
Asillustratedinthefunctionalblockdiagram,the readcycle,theaddressregisterincrementstothenext
Bt445supportsastandardMPUbusinterface,allowing location,whichtheMPUmayreadbysimplyreading
theMPUtoaccesstheinternalcontrolregistersand anothersequenceofred,green,andbluedata.
colorpalettes.Thedual-portcolorpaletteRAM,over- WhenaccessingthecolorpaletteRAM,theaddress
laypalette,andcursorcolorregistersallowcolorupdat- registerresetsto$00afterabluereadorwritecycleto
ingwithoutcontentionwiththedisplayrefreshprocess. location$FF.Tokeeptrackofthered,green,andblue
Table1illustrateshowtheC(2-0)controlinputs read/writecycles,theaddressregisterhas2additional
workinconjunctionwiththeinternaladdressregisterto bitsthatcountmodulothree.Theyareresettozero
specifywhichcontrolregister,colorpaletteRAMentry, whentheMPUreadsorwritestotheaddressregister.
overlayregister,orcursorcolorregisterwillbe TheMPUdoesnothaveaccesstothesebits.Theother
accessedbytheMPU. 8bitsoftheaddressregister(ADDR(7-0))areaccessi-
Theresetpinpresetstheinternalregisters,default- bletotheMPU.
ingallinternalregisterstobecompatiblewiththe4:1
multiplexconfigurationoftheBt458.Featuressuchas
AdditionalInformation
alternatepixeldepthmodesandmultiplexfactorsare
AlthoughthecolorandoverlaypaletteRAMsandcur-
availablethroughtheuseoftheC(2)controlpin,which
sorcolorregistersaredualported,ifthepixel!datais
providesaccesstotheextrafeatures.
The8-bitaddressregister(ADDR(7-0))isusedto addressingthesamepaletteentrybeingwrittentoby
theMPUduringthewritecycle,itispossibleforoneor
addresstheinternalcolorandcontrolregisters,elimi-
moreofthepixelsonthedisplayscreentobedisturbed.
natingtherequirementforexternaladdressmultiplex-
ers.ADDR(O)correspondstoD(O)andistheleast Amaximumofonepixelisdisturbedifthewritedata
fromtheMPUisvalidduringtheentirechipenable
significantbit.
time.
Thecontrol]registerscanalsobeaccessedthrough
Reading/WritingColorData
theaddressregisterinconjynctionwiththeC(2-0)
TowritecolordatatheMPUloadstheaddressregister inputs,asshowninTable1.Allcontrolregistersmay
withtheaddressofthecolorpaletteRAMlocation, bewrittentoorreadbytheMPUatanytime.The
overlaypalette,orcursorcolorregistertobemodified. addressregisterdoesnotincrementfollowingreador
TheMPUperformsthreesuccessivewritecycles(red, writecyclestothecontrolregisters,facilitatingread-
green,andblue),usingC(2-0)toselectthecolorregis- modify-writeoperations.
ter.Duringthebluewritecycle,the3bytesofcolor Topreventpixelsfrombeingdisturbedduringwrites
informationareconcatenatedintoa24-bitwordand tothecontrolregisters,theMPUdatamustbevalid
writtentothelocationspecifiedbytheaddressregister. duringtheentirechipenabletime,ortheaccesses
Theaddressregisterthenincrementstothenextloca- shouldbelimitedtoblankingtime.Thesetuptime
tion,whichtheMPUmaymodifybysimplywriting shownintheACCharacteristicssectionarethemini-
anothersequenceofred,green,andbluedata. mumrequiredtointernallycapturethedata.
Toreadcolordata,theMPUloadstheaddressregis- Notethatifaninvalidaddressisloadedintothe
terwiththeaddressofthecolorpaletteRAMlocation addressregister,datawrittentothedevicewillbe
oroverlayregistertoberead.TheMPUperformsthree ignoredandinvaliddatawillbereadbytheMPU.This
successivereadcycles(red,green,andblue),using isnotrecommended,asthismaycauseproblemsin
C(2-0)toselecteitherthecolorpaletteRAM,overlay Bt445code-compatibleproducts.
palette,orcursorcolorregisters.Followingtheblue
WORKSTATIONGRAPHICS 5—5

Bt445
CircuitDescription(continued)
Reset
| C(2-0) | ADDR(7-0)\|Value[Hex] | AddressedbyMPU |
| --- | --- | --- |
| 0 | 0 | 0 $xx AddressRegister |
| 0 | 0 | 1 $00-$FF PrimaryColorPaletteRAM* |
| 0 | 1 | 0 $00 3A IDRegister($3A) |
| $01 | AO | RevisionRegister($A0) $02 Reserved $03 Reserved |
| $04 | FF | ReadEnableRegister |
| $05 | 0 | BlinkEnableRegister |
| $06 | 43 | CommandRegister0 |
| $07 | 0 | TestRegister0 $08-$FF Reserved |
| 0 | 1 | 1 $00-$0F OverlayColorPaletteRAM(Note1) $10-$FF Reserved |
| 1 | 0 | 0 $xx Reserved |
| 1 | 0 | 1 $00 07 RedMSBPosition |
| $01 | 08 | RedWidthControl |
| $02 | FF | RedDisplayEnableControl |
| $03 | 0 | RedRegisterBlinkEnable $04-$07 Reserved($00) |
| $08 | 07 | GreenMSBPosition |
| $09 | 08 | GreenWidthControl |
| $0A | FF | GreenDisplayEnableControl |
| $0B | 0 | GreenBlinkEnableRegister $0C-$OF Reserved($00) |
| $10 | 07 | BlueMSBPosition |
| $11 | 08 | BlueWidthControl |
| $12 | FF | BlueDisplayEnableControl |
| $13 | 0 | BlueBlinkEnableRegister $14-$17 Reserved($00) |
| $18 | 09 | OverlayMSBPosition |
| $19 | 02 | OverlayWidthControl |
| SIA | 03 | OverlayDisplayEnableControl |
| $1B | 0 | OverlayBlinkEnableRegister $1C~IF Reserved($00) |
| $20 | 0 | CursorMSBPosition |
| $21 | 02 | CursorWidthControl |
| $22 | 03 | CursorDisplayEnableControl |
| $23 | 0 | CursorBlinkRegister $24—-$FF Reserved($00) Table1.AddressRegister(ADDR)Operation. 5-6 SECTION5 |

Brooktree’ Bt445
CircuitDescription(continued)
Reset
| C(2-0) | ADDR(7-0)\|Value[Hex} | AddressedbyMPU |
| --- | --- | --- |
| 1 | 1 | 0 $00 Ox TestRegister1 |
| $01 | 40 | CommandRegister1 |
| $02 | 0 | DigitalOutputControlRegister |
| $03 | 03 | VIDCLK*CycleControlRegister $04 Reserved |
| $05 | 19 | PixelPLLRateRegister0 |
| $06 | 04 | PixelPLLRateRegister1 |
| $07 | XX | PLLControlRegister |
| $08 | 04 | PixelLoadControlRegister |
| $09 | 28 | PixelPortStartPositionRegister |
| $0A | 08 | PixelFormatControlRegister |
| $0B | 03 | MPXRateRegister |
| $0C | XX | SignatureAnalysisRegisters(Note1) |
| $0D | 0A | PixelDepthControlRegister |
| $0E | 0 | PaletteBypassPosition |
| $OF | 01 | PaletteBypassWidthControl $10-$FF Reserved($00) |
| 1 | 1 | 1 $00 CursorColor0(Note1) $01 CursorColor1(Note1) $02 CursorColor2(Note1) $03 CursorColor3(Note1) $04-$FF Reserved Note1:Requiresmodulo3loading/reading. Table1.(continued).AddressRegister(ADDR)Operation. WORKSTATIONGRAPHICS 5-7 |

Bt445 Brooktree*
CircuitDescription(continued)
ClockGeneration
TheBt445hastwophaselockloopsforgeneratingthe usedbycapacitivelycouplingtheoscillator’soutputto
pixelclockandthreesystemclocks.(SeetheFunc- theXTAL]input,asshowninFigure2.Forthisconfig-
tionalBlockDiagramandFigure1).Thepixelclockis uration,leavetheXTAL2pindisconnectedasshown.
fullyprogrammable,abletogenerateover500unique BothPLLscanbedisabledseparatelytoprovide
pixelclockfrequenciesusingasinglecrystal. maximumflexibilityinconfiguringtheBt445tomatch
Theadvancedphaselockloops(PLLs)containan thesystemrequirements.Inordertominimizenoise,all
internalloopfiltertoprovidemaximumnoiseimmunity unusedoutputsshouldbedisabledviathecommand
andreducejitter.Exceptforthereferencecrystalor registers.Additionally,inordertoprovideminimal
oscillator,noexternalcomponentsoradjustmentsare noiseeffectstotheRAMDAC,alloftheclockgener-
necessary. atedoutputsarelowdriveandmustberedrivenbya
ThepixelclockgeneratorusesanMover(LxN) bufferbeforedistribution.
schemetoprovideprecisefrequencies.TheM,N,and WiththeassertionofRESET*,thevideoclock
Lvaluescanbeprogrammedthroughthecommand defaultsintoamodewherebyaone-fourthpixelrate
registerswithavarietyofvalues,whichgenerallypro- videoclockisautomaticallygenerated.Thisrateiscon-
videfrequencygranularitythataverageslessthan| sistentwiththeLDrateneededtouseaBt458in4:1
MHz.Misabinary6-bitvalue,Nisabinary4-bit multiplexmode.ThePLLsarealsoinitiatedwith
value,andLisselectabletobe1,2,4,or8.Serialclock RESET*togeneratethesystemclocks.
andvideoclocksaregeneratedfromthederivedpixel AsanalternativetousingthePLLforpixelclock
clock. generation,theBt445isalsodesignedtoacceptdiffer-
AsecondPLLgeneratesanumberofvariousclocks entialclocksignals(CLOCKandCLOCK*inFigure
(MCLK20,MCLK25,CPUCLK),whichmaybeused 2).TheseclockinputscanbegeneratedbyECLlogic
fortheCPUclockandothersystemclocks.Usinga20 operatingat+5V.NotethattheCLOCKandCLOCK*
MHzcrystal,aconstant20MHzand25MHzclockis inputsrequireterminationresistors(220QtoGND)
availableforEthernetandSCSIclockgeneration,while thatshouldbelocatedasclosetothedrivingsourceas
theCPUclockoutputisselectablebetween25,33,40, possible.A150-2chipresistorneartheRAMDAC
or50MHz.ThereferencecrystalusedmustbeanAT pinsisalsoneededtoensurepropertermination.(See
cut,withseriesconfiguration,andoperatedinthefun- Figure3).
damentalmode.Anoscillatorreferencecanalsobe
5-8 SECTION5

Brooktree’ Bt445
CircuitDescription(continued)
CLOCK a"
| : | ;>SCLK | >SCLK* |
| --- | --- | --- |
| CLOCK | MPX | Divider |
| VIDCLK* | a | * |
| r | Divider Pixel ClockPLL Internal M RAMDAC NxL PixelClock | >VIDCLK |
| Oscillator\|XTAL1\| | \| or Crystal | ‘ |
| Crystal\|XTAL2 | Amplifier 6-25MHz]— 7 x5/2 > cpu[x88 MPX\|\|»CPUCLK Clock\|x2 > PLL > xS/Are >MCLK25 x1 ™MCLK20 Figure1.PLLClockGenerationBlockDiagram. WORKSTATIONGRAPHICS 5-9 | Select |

Bt445 Brooktree’
CircuitDescription(continued)
+5
f	1000pF	Bt445
Oscillator	1€	XTAL1
ANXTAL2
r]LOCK
CLOCK"
Figure2.OscillatorClockInterface.
Bt438ORBt440 Bt445
CLOCK	[-f	$P)CLOCK
220
150
CLOCK*F-¢ #p1CLOCK’
VAA
220 t
0.1WF
VREF| AAddVREF
1k
—|LD/SCLK!
—P|VIDCLK! VIDCLK*
“
Figure3.DifferentialECLCLockInterface.
5-10 SECTION5

Brooktree’ Bt445
CircuitDescription(continued)
FrameBufferClocking
PixeldatamaybeclockedintotheBt445inoneoftwo SCLK*/SCLKIsignalsforpixelloading.Alsoreferto
modes:withVIDCLKinputandoutputsignals,orwith theACtimingspecificationsforthemaximumratesat
theSCLKinputandoutputsignals. whichtheSCLK*maybeoperated.
ThebufferedversionofSCLK*,referredtointhis
PixelLoadingUsingSCLK specificationasSCLK,isreturnedtotheBt445tobe
usedtoloadtheinputpixe]data.Thisallowsforfaster
SystemdesignsthatinterfaceVRAMframebuffer
serialpathoperation,asthebufferdelaydoesnotaddto
serialdatadirectlytotheBt445canusetheSCLK*and
theserialportdelayindeterminingtheminimum
LD/SCLKIsignalpairstoloadpixeldata.Inthismode,
SCLKcycletimeatwhichthesystemmayoperate
theBt445facilitatesthegenerationoftheVRAMshift
(refertoFigures4and5).
clockbyprovidingVRAMserialshiftclock,SCLK*.
TheVIDCLKIsignalisstillusedtoloadthe
SCLK*shouldbeusedtoclocktheVRAMshiftregis-
VSYNC*,HSYNC*,SYNC*,andBLANK*®signals.
tersthatprovidepixeldatatotheBt445.Theratioof
TheVIDCLKrateisindependentofthepixeldepth;the
SCLK*tothepixelclockequalsthevaluesetintothe
VIDCLKrateisselectedbytheVIDCLKrateselect
MPXrateregister.
register.
SCLK*isstoppedGinalogical“1”state)during
blankingtoallowthesystemtoreloadtheVRAMserial
PixelLoadingUsingVIDCLK
shiftregisters.Systemimplementationsusing“mid-
line”transfermaynecessitateinsertingaVRAMshift SystemarchitecturesthatprecludeusingtheSCLK
clockpulseduringblankingtimetoloadtheshiftregis- signalsforloadingpixeldatamayinsteadusetheVID-
tertapaddress.Thesystemmayinsertthisadditional CLK*signaltoloadpixeldata.Inthismodeofopera-
clockwithoutincurringadditionalgatedelaysbyusing tion, the LD/SCLKIand VIDCLKIshouldbe
aNANDdriverforgeneratingSCLKtotheVRAMs. connectedtogether.
TheunusedinputontheNANDdrivermaybeusedto Inthismode,theVIDCLKrateselectfieldshouldbe
inserttheadditionalSCLKtoloadthetapaddress.The writtenasthesamevalueastheMPXRateRegister.
SCLK*(activelowtime)pulsewidthisnominallytwo TheSCLK*outputisdisabled(high-z)whentheBt445
pixelclockcycles;asaresult,architecturesusingless isconfiguredinthismode.
than4:1 multiplexingwillnotnormallyusethe
Memory >RAS"
DataTransfer	peCAS	PixelMemoryArray
Control |DT*/OE*
pm)SCLK
74F1804
| >\|D/SCLKI | Btags >)VIDCLKI | — |
| --- | --- | --- |
| em} | CATTiming | >\|SYNC*/HSYNC* Generator . >)BLANK* VIDCLK* |
XTAL
20MHz
Oscillator
74F1804}
Figure4,FrameBufferClockingInterface,UsingSCLK.
WORKSTATIONGRAPHICS 5~11

Bt445 Brooktree’
CircuitDescription(continued)
wootf \ff\_f\_S\NLY
BLANK*
\
\ /
SCLK*
r~.TranslNonmicli
Sf\aN
LD/SCLKI
' ode
'
P(63-0)
Midline
LD/SCLKI	|	/ —\_ Transter
Mode
P(63—o)[	Group0	!	€
XNPixelDataValidFrom
System-insertedShiftClock
Figure5.FrameBufferInterfaceTimingDiagramUsingSCLKI.
5-12 SECTION5

Brooktree’ Bt445
CircuitDescription(continued)
VIDCLKGeneration WhentheBt445isconfiguredforusingVIDCLK
forloadingpixeldata,SYNC*andBLANK*corre-
Atresettime,theBt445isconfiguredtoloadpixels
spondtothepixeldatabeingloadedonthesameclock
usingVIDCLK.Themultiplexrateissetto4:1(Bt458
edge.
compatible).WhenchangingtheVIDCLKrate,the
Everyclockcycle,theselectedcolorinformation
VIDCLK*outputisguaranteednottoglitchwhen
fromthecolorpaletteRAMsoroverlayregistersare
changingfromoneratetoanother.Duringthetransi-
presentedtotheD/Aconverters.
tion,theminimumloworhighpulsewidthwillbeat
TheSYNC*andBLANK*inputs,pipelinedto
leasttheloworhighwidthofthefasteroftheoldor
maintainsynchronizationwiththepixeldata,add
newVIDCLKrate.For1:1and2:1VIDCLK*rates,
appropriatelyweightedcurrentstotheanalogoutputs,
theVIDCLK*outputwillhavea50/50dutycycle;for
producingthespecificoutputlevelsrequiredforvideo
3:1to64:1VIDCLK*rates,theVIDCLK*activedow)
applications,asillustratedinFigures6and7.
pulsewidthis2pixelclocks.
ThevaryingoutputcurrentfromeachoftheD/A
convertersproducesacorrespondingvoltagelevel,
VideoGeneration
whichisusedtodrivethecolorCRTmonitor.Notethat
onlythegreenoutput(IOG)maycontainsyncinforma-
TheVIDCLK*outputisafree-runningclocktypically
tion.Tables2and3detailhowtheSYNC*and
usedforclockingthedisplaytiminggenerator.The
BLANK?inputsmodifytheoutputlevels.
periodofVIDCLK*isindependentofSCLK*andis
TheD/AconvertersonthetheBt445useaseg-
controlledbytheMPUbytheVIDCLK*rateregister.
mentedarchitectureinwhichbitcurrentsareroutedto
VIDCLKmaybethepixelclockdividedbyanyinteger
eitherthecurrentoutputorGNDbyasophisticated
from1-64.SYNC*andBLANK*informationarereg-
decodingscheme.Thisarchitectureeliminatestheneed
isteredwitheachrisingedgeofVIDCLKIandinserted
forprecisioncomponentratiosandgreatlyreducesthe
intothepipelinedpixelstreamattheappropriatetime.
switchingtransientsassociatedwithturningcurrent
WhenusingSCLK*toclockpixels,SYNC*and
sourcesonoroff.Monotonicityandlowglitchare
BLANK*areregisteredbyadifferentclockfromthe
guaranteedbyusingidenticalcurrentsourcesandcur-
pixeldata;therefore,theydonotcorrespondtothe
rentsteeringtheiroutputs.Anon-chipoperational
pixe]inputsthatarepresentatthesametime.The
amplifierstabilizestheD/Aconverter’sfullscaleout-
SYNC*andBLANK*inputsareusedtoprovidethe
putcurrentagainsttemperatureandpowersupplyvari-
RAMDACwithtiminginformation.
ations.
WORKSTATIONGRAPHICS 5-13

Bt445 Brooktree’
CircuitDescription(continued)
RED,BLUE GREEN
| MA | v | MA | v |
| --- | --- | --- | --- |
| 19.05 | 0.714\|26.67 92.5IRE | 1.000 | WHITELEVEL |
| 1.44 | 0.054\|9.05 7.5IRE | 0.340 | BLACKLEVEL |
| 0.00: | 0.000\|7.62 | 0.286 | BLANKLEVEL |
40IRE
| 0.00 | 0.000 | SYNCLEVEL Figure6.CompositeVideoOutputWaveform(SETUP=7.5IRE). |
| --- | --- | --- |
| age | Syne | NoSync * * DAC |
| Description | Jout(mA) | lout(mA) SYNC BLANK InputData |
| WHITE | 26.67 | 19.05 1 1 $FF |
| DATA | data+9.05 | data+1.44 1 1 data |
| DATA-SYNC | data+1.44 | data+1.44 0 1 data |
| BLACK | 9.05 | 1.44 1 1 $00 |
| BLACK-SYNC | 1,44 | 1.44 0 i $00 |
| BLANK | 7,62 | 0 1 0 $xx |
| SYNC | 0 | 0 0 0 $xx Note:TypicalwithRSET=523Q,VREF=1.235V.Blankpedestal=7.5JRE. Table2.VideoOutputTruthTable(SETUP=7.5IRE). 5-14 SECTION5 |

Brooktree’ Bt445
CircuitDescription(continued)
RED,BLUE GREEN
MA	Vv	MA	Vv
18.6	0.698|26.67	1.00	WHITELEVEL
100IRE
0.00	0.000|8.05	0.302	BLACK/BLANKLEVEL
43IRE
| 0.00 | 0.000 0.00 Figure7.CompositeVideoOutputWaveformSETUP=0IRE). | 0.000 | SYNCLEVEL |
| --- | --- | --- | --- |
| a | Sync | NoSync | * . DAC Description\|iout(ma)\|tout(ma)\| SYNC BLANK"\|inputData |
| WHITE | 26.67 | 18.60 | 1 ] SFF |
| DATA | data+8.5 | data | 1 ] data |
| DATA-SYNC | data | data | 0 1 data |
| BLACK | 8.05 | 0 | 1 1 $00 |
| BLACK-SYNC | 0 | 0 | 0 1 $00 |
| BLANK | 8.05 | 0 | 1 0 Sxx |
| SYNC | 0 | 0 | 0 0 $xx Note:TypicalwithRSET=495©,VREF=1.235V.Blankpedestal=0IRE. Table3.VideoOutputTruthTable(SETUP=0IRE). WORKSTATIONGRAPHICS 5-15 |

Bt445 Brooktree’
CircuitDescription(continued)
FrameBufferInterface InternallogicmaintainsaninternalLOADsignal,
synchronoustoCLOCK,andisguaranteedtofollow
theLD/SCLKIsignalbyatleastone,butnotmorethan
SystemsUsingVIDCLK*forLoadingPixel
TBD,clockcycles.ThisLOADsignaltransfersthereg-
Data
isteredpixelandoverlaydataintoasecondsetofregis-
Toenablepixeldatatobetransferredfromtheframe ters,whicharetheninternallymultiplexedatthepixel
bufferatTTLdatarates,theBt445incorporatesinter- clockrate.
nalregistersandmultiplexers.AsillustratedinFigure
8,ontherisingedgeofLD/SCLKIandVIDCLKT,sync
ColorSelection
andblankinformation,color,overlay,cursor,andpal-
ettebypassinformationareallregistered.Thenumber Ateachpixelportloadcycle,oneormorepixelscon-
ofpixelssuppliedforeachinputcycledependsonthe sistingofcolor,overlay,cursor,and/orpalettebypass
multiplexrateasdeterminedbythecurrentmode.Note informationareprocessedbythemultiplexingand
thatwiththisconfiguration,thesyncandblanktiming unpackinglogic,readmasks,blinkmask,andcom-
willberecognizedonlywithloadpixelrateresolution, mandregisters.Throughtheuseofthecontrolregisters,
setbythemultiplexmode.Typically,theLD/SCLKI individualbitplanesmaybeenabledordisabledfor
signalisgeneratedfromtheinvertedsignaloftheVID- display,and/orblinkedatoneoffourblinkratesand
CLK*outputoftheBt445. dutycycles.
Pixelportbitsusedasoverlayinputshavepixeltim- Thecolorselectionprocessmaybebrokendown
ing,facilitatingtheuseofadditionalbitplanesinthe intothefollowingsteps:
framebuffertocontroloverlayselectiononapixel
basis,ortheymaybecontrolledbyexternalcharacter
1.Multiplextheinputpixelsfromthepixelportload
orcursorgenerationlogic.
cycletothepixelclockrateusingtheappropriate
LD/SCLKImaybephaseshiftedinanyamountrel-
pixelportstartposition,pixelunpackingmode,
ativetoCLOCKorVIDCLK*.Asaresult,thepixel
andpixelmultiplexmode.
andoverlaydataareregisteredontherisingedgeof
2.Expandtheresulting1:)pixeldatato8bitseach
LD/SCLKI,independentoftheclockphase.
ofred,green,andblue;4bitsofoverlay;2bitsof
PCLK HULU
VIDCLKI,
LD/SCLKI
:
BLANK*
‘Seasseercnataseetats00,0,%
P(63-0)PRRRRR‘
LX 6%
Figure8.FrameBufferandPixelPortTimingDiagram,UsingVIDCLK*Output.
5-16 SECTION5

Brooktree’* Bt445
CircuitDescription(continued)
cursor;and1 bitofpalettebypasscontrol. sizefrom1~32bitsperpixel.Notallbitsofapixelwill
Pseudo-colormodeswillsupplythesame8-bit necessarilybeused.Thepixeldepthmustbeconsistent
resulttoeachofthered,green,andbluecolorsat withthepixelportstartpositionandmultiplexrate.
thispoint.
3.Applytheappropriatereadmaskstothepixel MultiplexRateSelection
data.
TheMultiplexRateisselectableindependentfrom
4.Applytheappropriateblinkmaskstothepixel thepixeldepthandpixelportstartposition.Validmul-
data. tiplexratesare1:1to64:1(anyintegeramount).Again,
5.Ifthepaletteisbypassedapplytheresultingpixel theonlyrestrictionisthatthemultiplexratemustbe
datadirectlytotheDACinputs;otherwise,apply consistentwiththepixeldepthandpixelportstartposi-
thepixeldatatotheaddressesofeachofthe tion.WhenusingVIDCLKtoloadpixels,themultiplex
respectivelyred,green,andbluecolorpalettes. rateshouldbeprogrammedatthesamerateastheVID-
UsetheresultstodrivetheDACsinputs. CLK*ratetoselectthecycletimeofVIDCLK*.
PixelPortStartPositionSelection StartPosition/PixelDepth/Multiplex
RateRestrictions
TheBt445’spixelpatharchitectureallowsthecon-
figurabilityofthestartingpositionforpixelunpacking.
TheBt445isspecifiedtooperateatthepixeldepths,
Thisprovidesthesystemdesignerwithgreateroptions
pixelportstartpositions,andmultiplexratesthatsat-
totailortheBt445tothedesiredframebufferorganiza-
isfythefollowingrelationship:
tion.ThestartingpositionisconfiguredviathePixel
PortStartPositionRegisterandmaybespecifiedtobe
ForMSBunpacking:
anypositionfromP(63)toP(0).
StartPosition—(PixelDepthxMultiplexRate)20
Oneusecouldbeinsystemsutilizingdoubleframe
bufferdesigns.Forexample,inanMSBunpacking,8-
ForLSBunpacking:
bitpixel,4:1multiplexconfiguration,framebufferA
(PixelDepthxMultiplexRate)—StartPosition<64
couldbeattachedtoinputpixelportbitsP(31—-0)and
framebufferBcouldbeattachedtoinputpixelportbits
ProgrammingtheBt445toconfigurationsnotcon-
P(63-32).Assumingtheotherregistershavebeen
sistentwiththisrelationshipwillyieldunspecified
appropriatelyprogrammed,theBt445wouldallow
resultsthatwillnotbetestedorguaranteed.
switchingbetweentheframebuffersbysimplypro-
gramminga$20(forframebufferA)ora$40(forframe
PixelProcessing
bufferB)intothePixelPortStartPositionRegister.
Thepixelunpackingprocess,whichusesthepixelport
PixelUnpackingSelection startposition,pixeldepth,andmultiplexrate,internally
yieldsaserializedpixelstream.Eachpixelinthisserial
TheBt445supportspixelunpackingstartingfrom
streammaybeupto32bitswide,asspecifiedbythe
eitherthelow-ordersideoftheinputpixelport(LSB
PixelDepthRegister.Atthispoint,theindividualfields
unpacking)orthehigh-ordersideoftheinputpixelport
areextractedfromeachpixel.Thefieldsextractedare:
(MSBunpacking).Thestartingbitforeitherunpacking
Red,Green,Blue,Overlay,Cursor,andPaletteBypass
directionisspecifiedbyusingthePixelPortStartPosi-
Control.Thered,green,andbluefieldsmayeachbeup
tionRegister.Forfurtherinformation,seethePixelPort
to8bitswide,theoverlayfieldmaybeupto4bits
StartPositionRegisterintheInternalRegistersection.
wide,andthepalettebypasscontrolmaybe|bitwide.
Withineachpixel,theMSBisthehighestnumbered
TheMSBpositionandwidthofeachofthesefields
bit.
withinthepixelisindependentlyspecifiedbythecorre-
spondingsourceandwidthregisters.Thefieldsmay
PixelDepthSelection
overlaporbenoncontiguous.Forexample,for8-bit
pseudocolormode,thered,green,andblueposition
TheBt445providesextremelyflexibleoptionsfor
andwidthregisterswouldspecifythesamefieldofthe
variouspixeldepthsonaframe-by-framebasis.The
pixel.
selectionofthepixeldepthissetviathePixelDepth
Register.Thepixeldepthmaybespecifiedtobeany
WORKSTATIONGRAPHICS 5-17

Bt445
CircuitDescription(continued)
High-orderBitsofInput Resulting8-bit
| 5-BitInputPixelField | PixeltobeLow-Order ExpandedField Appended Hex Binary | ; |
| --- | --- | --- |
| $00 | 00000 | 000 $00 |
| $01 | 00001 | 000 $08 |
| $02 | 0.0010 | 000 $10 |
| $03 | 00011 | 000 $18 |
| $04 | 0.0100 | 001 $21 |
| $05 | 00101 | 001 $29 |
| $06 | 00110 | 001 $31 |
| $07 | 00111 | 001 $39 |
| $08 | 01000 | 010 $42 |
| $09 | 01001 | 010 S4A |
| $0A | 01010 | 010 $52 |
| $0B | 01011 | 010 $5A |
| $0C | 01100 | 011 $63 |
| $0D | 01101 | 011 $6B |
| $0E | 01110 | O11 $73 |
| $OF | 01111 | O11 $7B |
| $10 | 10000 | 100 $84 |
| $11 | 10001 | 100 $8C |
| $12 | 10010 | 100 $94 |
| $13 | 10011 | 100 $9C |
| $14 | 10100 | 101 $A5 |
| $15 | 10101 | 101 $AD |
| $16 | 10110 | 101 $BS5 |
| $17 | 10111 | 101 $BD |
| $18 | 11000 | 110 $C6 |
| $19 | 11001 | 110 $CE |
| SIA | 11010 | 110 $D6 |
| $1B | 11011 | 110 $DE |
| $1C | 11100 | 111 $E7 |
| $1D | 11101 | 11 SEF |
| SIE | 11110 | i111 $F7 |
| $1F | 11111 | 111 S$FF Ifthiseffectisnotdesired,thereadmaskregistersmaybeusedtoforcetheappendedLSBstozero. Table4.ExpansionofPixelColorFieldsLessThan8Bitstoan8-bitField.Five-bitPixelColor FieldExample. GenerationofUnspecifiedPixelData LSBs Whentrue-colorsourcepixeldatacontainslessthan8 tiontableforthevariouspixelmodes.Table4illus- bitspercolorchannel,itisexpandedto8bitsbyleft tratesthiseffectbyindicatingtheactualvaluesapplied justifyingandaddingtheappropriateLSBstoallowfor totheredDACinputwheninthe16-bit-per-pixel5-5-5 full-scaleandbest-fitlinearityovertheDACoutput mode,withpalettebypass. range.Thisallowstheuseofthesamegammacorrec- 5-18 SECTION5 |

Brooktree’ Bt445
CircuitDescription(continued)
ColorPaletteBypassMode PixelOutputInterface
Thecolorpalettebypasscontrolisusedtocontrolthe Thedigitalpixeloutputinterfacecanbeoperatedin
accesstothecolorpaletteRAMbythepixeldata.The eitheroftwotrue-colormodes:4-4-4or8-8-8.This
overlayandcursorcolorpalettearenotaffected;they interfacealsoprovidesthepixeloutputclock(PCLK),
arealwaysusedifoverlayorcursordataispresent. pipelined sync (PSYNC*)andpipelined blank
Bypassingthecolorpalettedeliverswhatwouldhave (PBLANK*)outputs,and12bitsofdata.Thepixelout-
beenthepaletteaddressdirectlytotheDACinputs. putinterfacesignalsOR(3-0),OG(3-0),OB(3-0),and
PCLKarespecifiedtorunatamaximumpixelrateof
55MHzwhenin4-4-4mode,or27.5MHzwhenin8-
Blinking
8-8mode(seeFigure9).
Toensurethatacolorchangeduetoblinkingdoesnot
occurduringtheactivedisplaytime(ie.,inthemiddle
4-4-4True-ColorMode
ofthescreen),theBt445monitorstheBLANK*input
todetermineverticalretraceintervals.Averticalretrace Whenoperatedin4-4-4true-colormode,thepixel
intervalisrecognizedbydeterminingthenumberof outputinterfaceprovides12bitsofpixeldata,(one
syncsperblankingtime.TheBt445assumesthataver- pixel)oneachrisingorfallingedgeofthepixelclock
ticalretraceoccurswhenevermorethanonesync output,whereeachgroupof4bitscorrespondstothe
occursduringablankinterval. mostsignificantnibbleofthe3bytesbeingprovidedat
Systemsthatdonotrequireseparatesyncforthe thered,green,andblueDACinputs.OR(G-0)carries
digitaloutputsectionmayprovideacompositesync theR(7-4),OG@G-0)carriesG(7-4),andOB(3-0)car-
inputontheSYNC*/HSYNC*inputpin;theVSYNC* riesB(7-4).
inputshouldbealogicalone.TheBt445generates
compositeSYNC*bylogicallyORingtheSYNC*/ 8-8-8True-ColorMode
HSYNC*inputwiththeVSYNC*input.
Whenoperatedin8-8-8true-colormode,thepixel
Theprocessedpixeldataisthenusedtoselectwhich
outputinterfaceprovides24bitsofpixeldataeach
colorpaletteentryoroverlayregisteristoprovidecolor
PCLKcycle.Eachedgeofthepixeldatacarries12bits
information.NotethatPOistheLSBwhenaddressing
ofthepixeldata,firstthehighordernibblesofred,
thecolorpaletteRAM.
PCLK
PBLANK*	:	/
4-4-4
Pixei0	Pixel1=Pixel2	Pitel3—Pikel4	Pikel5
True
OR(3-0)
Color
OG(3-0)
Mode
0B(3-0)EEE
Pixel0	Pixel1	Pixel2
|
—_
8-8-8
True
OR(3-0)
Color
OG(3-0) Mode
OB(3-0)
Figure9.PixelOutputInterfaceModesRepresentativeTimingDiagram.
WORKSTATIONGRAPHICS 5-19

Bt445 Brooktree’
CircuitDescription(continued)
green,andbluearepresentedontherisingedgeofthe AccessPortandBoundaryScanArchitecture,the
pixelclock,thenthelow-ordernibblesarepresentedon Bt445hasdedicatedpinswhichareusedfortestpur-
thefallingedgeoftheclock.Notethatdecreasedhori- posesonly.
zontalspacialresolutionistradedforincreasedcolor JTAGusesboundary-scancellsplacedateachdigi-
resolution. talpin,bothinputsandoutputs.Allscancellsareinter-
connectedintoaBoundary-ScanRegister(BSR),
whichappliesorcapturestestdatausedforfunctional
ResetInitialization
verificationoftheRAMDAC.JTAGisparticularlyuse-
TheSOandS1inputsareusedatresettimetoloadthe fulforboardtestersusingfunctionaltestingmethods.
PLLControlRegisterwiththeproperCPUoutput JTAGconsistsoffourdedicatedpinscomprisingthe
clockmultiplexrate.Thisallowsforimmediateproper TestAccessPort(TAP).ThesepinsareTMS(Test
selectionoftheCPUclockrate.WhileRESET*isa ModeSelect)TCK(TestClock),TDI(TestDataInput)
logicalzero,theSOandS1inputsflowthroughandare andTDO(TestDataOut).Completeverificationofthe
latchedasRESET*rises.TheCPUoutputclocksare RAMDACcanbeachievedthroughthesefourTAP
alsoglitchlessduringtransitionsasdefinedforVID- pins.Withboundary-scancellsateachdigitalpin,the
CLKratetransitions. Bt445isabletoapplyandcapturethelogiclevel.Since
allofthedigita]pinsareinterconnectedasalongshift
Power-DownMode register,theTAPlogichasaccessandcontrolofallthe
necessarypinstoverifyfunctionality.TheTAPcontrol-
TheBt445incorporatesapower-downcapability,con-
lercanshiftinanynumberoftestvectorsthroughthe
trolledbycommandbitsCR13andCR14.Whileboth
TDIinputandapplythemtotheinternalcircuitry.The
commandbitsarealogicalzero,theBt445functionsin
outputresultisscannedoutontheTDOpinandexter-
thenormaloperatingmode.
nallychecked.WhileisolatingtheBt445fromtheother
ThecommandbitscanbesetsothattheDACsand
componentsontheboard,theuserhaseasyaccesstoall
powertotheRAMareturnedoff.NotethattheRAM
Bt445digitalpinsthroughtheTAPandcanperform
stillretainsthedata.TheRAMmaybereadbyorwrit-
completefunctionalitytestingwithoutusingexpensive
tenthroughtheMPU.TheRAMautomaticallypowers
bed-of-nailstesters. °
upduringMPUread/writecyclesandshutsdownwhen
ThebidirectionalMPUportandalldigitaloutputs
theMPUaccessiscompleted.TheDACsoutputno
requireextraattentionwithrespecttoJTAG.Because
current,andthecommandregistersmaystillbewritten
JTAGrequiresfullcontrolovereachdigitalpin,addi-
toorreadbytheMPU.NotethattheoutputDACs
tionaloutputenable(OE)cellsareincludedintheBSR
requireabout1secondtoturnoff(sleepmode)orturn
fortheMPUI/Oportandvariousdigitaloutputs.When
ondependingonthecompensationcapacitor.
loadedbytheJTAGinstructions,theseOEcellscontrol
InordertoconservepowerduringTFT-onlyopera-
thedrivingstrengthoftheirrespectivepins.
tion,theDACscanbeturnedoff,shuntingvalidpixel
WiththeJTAGbus,usersalsohaveaccesstoavital
datatotheTTLoutputs.Duringthisoperation,the
portionoftheBt445,theSignatureAnalysisRegister
RAMisstillactive,indexingpixeldatatoRGBvalues.
(seeFigure10).Withaccesstothisregister,userscan
easilyverifyexpectedvideodataseriallythroughthe
BoundaryScanTestabilityStructures JTAGport.TheSARislocatedbetweenthelookup
tableandtheinputstotheDACs.
AsthecomplexityofRAMDACsincreases,theneedto
Withthepower-onreset(POR)circuitry,theBt445
easilyaccesstheRAMDACforfunctionalverification
willinitializeeachpintooperateinaRAMDACmode
isbecomingvital.TheBt445hasincorporatedspecial
insteadofaJTAGtestmodeduringpower-up
circuitrythatallowsittobeaccessedinfullcompliance
sequence.
withstandardssetbytheJointTestActionGroup
GTAG).ConformingtoIEEEP1149.1,StandardTest
5-20 SECTION5

Brooktree’ Bt445
CircuitDescription(continued)
Signature
Analysis
Register
L
OEL4 JTAG
Controller
Lo LL_
VO	ie)	vO	TCK	TDO	TDI	TMS
Figure10.JTAGBlockDiagram.
WORKSTATIONGRAPHICS 5-21

Bt445 Broolxtree’
InternalRegisters
Thefollowingareimportantprogrammingnotes beANDedoffpriortomakingcomparisons.
regardingfuturecodecompatibility: Althoughitshouldnotbeassumedthatthese
reservedbitswillalwaysreturnzeroswhenread,the
Internalreservedaddresslocationsshouldnotbe resetvalueswillalwaysbeasshown.
accessed. Itisrecommendedthatthelower2bitsofoverlay
ToensurecompatibilitywithfutureBt445code- blink-and-readmaskvaluesbereadand/orwritten
compatibledevices,reservedvaluesforfieldsshould fromtheextendedregisterspace(i.e.,C(2)=1).
neverbewritten. Althoughfunctionallyequivalenttoaccessesfrom
ToensurecompatibilitywithfutureBt445code- theBt458-compatibleaddressspace,newcodewill
compatibledevices,reservedbitsshouldbemain- beeasiertomodifyforfutureBt445code-compati-
tainedwithread-modify-writes,whichonlyupdate bledevicesiftheseaccessesaremadeinthe
theunreservedbits.Furthermore,whentestingthe extendedregisterspace.
contentsofinternalregisters,reservedfieldsshould
5-22 SECTION5

Brooktree’ Bt445
InternalRegisters(continued)
CommandRegister0
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
| Bit(s) | FieldName | rene | FieldDescription |
| --- | --- | --- | --- |
| 7 | Reserved(logicalzero) | 0 | IntheBt458,thisbitspecifies4:1multiplexmode.Inthe Bt445,thisbitisignored.ToconfiguretheBt445forBt458- compatible5:1,theextendedBt445registersetmustbe used. |
| 6 | Overlaycolor0disable | 1 | Whentheoverlayselectbitsare0000,thisbitspecifies whethertousethecolorpaletteRAMoroverlaycolor0to (0)Useoverlaycolor0 providecolorinformation. (1)Usecolorpalette |
RAM
| 5,4 | Blinkrateselection | 00 | These2bitscontroltheblinkratecycletimeanddutycycle, andarespecifiedasthenumberofverticalretraceintervals. (00)16on,48off(25/75) Thenumbersinparenthesesspecifythedutycycle(percent (01)16on,16off(50/50) on/off). (10)32on,32off(50/50) (11)64on,64off(50/50) |
| --- | --- | --- | --- |
| 3 | OverlayPlane1blinkenable | 0 | Ifalogicalone,thisbitforcestheoverlaybit1inputs,ifany, totogglebetweenalogicalzeroandtheinputvalueatthe (0)Disableblinking selectedblinkratepriortoselectingthepalettes.Avalueof (1)Enableblinking logicalzerodoesnotaffectthevalueoftheoverlaybit1 inputs.ThisbitisalsomappedintotheOverlayBlinkEnable Registerbit1. |
| 2 | OverlayPlane0blinkenable | 0 | Ifalogicalone,thisbitforcestheoverlaybit0inputstotog- glebetweenalogicalzeroandtheinputvalueattheselected (0)Disableblinking blinkratepriortoselectingthepalettes.Avalueoflogical (1)Enableblinking zerodoesnotaffectthevalueoftheoverlaybit0inputs.This bitisalsomappedintotheOverlayBlinkEnableRegisterbit 0. |
| 1 | Overlayplane\|display | ] | Ifalogicalzero,thisbitforcestheoverlayplane1inputs,if enable any,toalogicalzeropriortoselectingthepalettes.Avalue ofalogicalonedoesnotaffectthevalueoftheoverlayplane (0)Disable 1input.ThisbitisalsomappedintotheOverlayDisplay (1)Enable EnableRegisterbit1. |
| 0 | Overlayplane0display | 1 | Ifalogicalzero,thisbitforcestheoverlayplane0inputs,if enable any,toalogicalzeropriortoselectingthepalettes.Avalue ofalogicalonedoesnotaffectthevalueoftheoverlayplane (0)Disable Oinput.ThisbitisalsomappedintotheOverlayDisplay (1)Enable EnableRegisterbit0. WORKSTATIONGRAPHICS 5-23 |

Bt445
InternalRegisters(continued)
CommandRegister1
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
Reset
| Bit(s) | FieldName | Value | FieldDescription |
| --- | --- | --- | --- |
| Greensyncenable | 0 | Thisbitenablesordisablessyncinformationfrombeinggener- atedontheIOGoutput. (0)DisablesynconIOG (1)EnablesynconIOG |  |
| PedestalEnable | 1 | Thisbitspecifieswhethera0or7.5IREblankingpedestalisto begeneratedonthevideooutputs.A0IREspecifiesthatthe (0)OIRE blackandblanklevelsarethesame. (1)7.5IRE |  |
| Reserved | 0 | Reservedforfutureexpansion. |  |
| 4,3 | PowerDownEnable | 00 | Whilethesebitsare00,thedeviceoperatesnormally.Withthe DACsoffstandardoperationoccurs,buttheoutputoftheLUT (00)NormalOperation isrouteddirectlytotheTTLoutputs.Iftheseregisterbitsare (01)DACsoff setfortheDACsandpowertotheRAMisturedoff,func- (10)DACsandRAMoff tionaloperationisdiscontinued.Inbothpower-downmodes, (11)DisableInternal theRAMstillretainsthedata,andCPUreadsandwritescan Clocking occurwithnolossofdata.Whilethedeviceisinthedisable internalclockingmode,theinternalclockandotheroutput clockmodesarecompletelydisabledtofurtherconservepower wheninpower-downmode.TheRAMstillretainsthedataand MPUreadsandwritescanoccurwithnolossofdata. |
| PaletteAddressingMode | 0 | Thisbitcontrolsthefieldexpansionmode.Whenthisbitisa logicalzero,pixelfieldscontainingfewerthanthenormal (0)Sparse widthofthefieldwillbeexpandedbyleftjustifyingthespeci- (1)Contiguous fiedbitsandusinggroupreplicationontotheunspecifiedlower bits.Whenthisbitisalogicalone,thespecifiedbitswillbe rightjustifiedwithzerosplacedontotheunspecifiedMSBs. |  |
| SignatureAnalysisEnable | 0 | Thisbitenablesoperationofallsignatureanalysisregister (SAR)clocking.Alogicalzeroisthenormalmode,theSAR (0)DisableSAR disabled.WritingalogicaloneenablestheSARforoperation (1)EnableSAR oneverypixel.Asslightlymorepowerisconsumedwhenthe SARisenabled,itisrecommendedthattheSARbedisabled whennotactuallybeingused. |  |
| ResetPipelinedDepth | 0 | Transitioningthisbitfromalogicalzerotoalogicalonecauses thepixelpipelinedepthtobeinitialized.Forfurtherinforma- tion,see“PipelineDelayInitialization”intheApplications section. 5-24 SECTION5 |  |

Brooktree* Bt445
InternalRegisters(continued)
RedMSBPosition
Reset
| Bit(s) | FieldName | FieldDescription Value |
| --- | --- | --- |
| 10 | MSBPosition | $07 PositionoftheMSBoftheredfieldwithintheinputpixel. ($00)—PixelBit0 Thisfield,inconjunctionwiththesize,determineswhich ($01)—-PixelBit1 bitsoftheinputpixelareusedtoaccesstheredcolorpalette orredDACoutput.Thevaluespecifiedshouldbelessthan ($1F)-PixelBit31 thepixelsize. ($20)-Reserved (S$FF)-Reserved RedWidthControl Reset |
| Bit(s) | FieldName | FieldDescription Value |
| 7-0 | Size | $08 Numberofbitstobeusedfortheredfieldinapixel.Thesize ($00)—Reserved andpositionoftheredfieldmustliewithinthedefinedpixel] ($01)-1Bit size. ($02)-2Bits ($08)-8Bits ($09)-Reserved ($FF)—Reserved RedBlinkEnableRegister Reset |
| Bit(s) | FieldName | FieldDescription Value |
| 7-0 | BlinkEnable | $00 Bits7-0,correspondingtotheexpanded(i.e.,eitherright justifiedandzeropadded,orleftjustifiedandMSBrepli- cated)pixelplanes7-0,respectively,enableblinkingofindi- vidualplanes.Alogicaloneinanybitpositioncausesthe correspondingpixelplanetobeturnedoffinaccordance withtheblinkratecounteranddutycycle.Alogicalzero causesthecorrespondingpixelplanetobeunaffectedbythe blinklogic.TheregisterisalsowrittenwithMPUdata whenevertheBt458-compatibleblinkregisteriswritten. WORKSTATIONGRAPHICS 5-25 |

Bt445
InternalRegisters(continued)
RedDisplayEnableControl
ThisregisterisalsowrittenwhentheBt458-compatiblereadmaskregisteriswritten.
Reset
| Bit(s) | FieldName | FieldDescription Value |
| --- | --- | --- |
| EnableBitPlane7 | 1 | Thisbitcontrolstheenablingofredbitplane7.Alogical (0)Disable zerocausesbit7oftheredfieldofthepixeltobeforcedto (1)Enable zero.Alogicalonecausesbit7oftheredfieldtopasstothe colorpaletteorDAC. EnableBitPlane6 Thisbitcontrolstheenablingofredbitplane6.Alogical (0)Disable zerocausesbit6oftheredfieldofthepixeltobeforcedto (1)Enable zero.Alogicalonecausesbit6oftheredfieldtopasstothe colorpaletteorDAC. EnableBitPlane5 Thisbitcontrolstheenablingofredbitplane5.Alogical (0)Disable zerocausesbit5oftheredfieldofthepixeltobeforcedto (1)Enable zero.Alogicalonecausesbit5oftheredfieldtopasstothe colorpaletteorDAC. EnableBitPlane4 Thisbitcontrolstheenablingofredbitplane4.Alogical (0)Disable zerocausesbit4oftheredfieldofthepixeltobeforcedto (1)Enable zero.Alogicalonecausesbit4oftheredfieldtopasstothe colorpaletteorDAC. : EnableBitPlane3 Thisbitcontrolstheenablingofredbitplane3.Alogical (0)Disable zerocausesbit3oftheredfieldofthepixeltobeforcedto (1)Enable zero.Alogicalonecausesbit3oftheredfieldtopasstothe colorpaletteorDAC. EnableBitPlane2 Thisbitcontrolstheenablingofredbitplane2.Alogical (0)Disable zerocausesbit2oftheredfieldofthepixeltobeforcedto (1)Enable zero.Alogicalonecausesbit2oftheredfieldtopasstothe colorpaletteorDAC. EnableBitPlane1 Thisbitcontrolstheenablingofredbitplane1.Alogical (0)Disable zerocausesbit1oftheredfieldofthepixeltobeforcedto (1)Enable zero.Alogicalonecausesbit1oftheredfieldtopasstothe colorpaletteorDAC. EnableBitPlane0 Thisbitcontrolstheenablingofredbitplane0.Alogical (0)Disable zerocausesbit0oftheredfieldofthepixeltobeforcedto (1)Enable zero.Alogicalonecausesbit0oftheredfieldtopasstothe colorpaletteorDAC. 5-26 SECTION5 |

Brooktree* Bt445
InternalRegisters(continued)
GreenMSBPosition
Reset
| Bit(s) | FieldName | FieldDescription Value |
| --- | --- | --- |
| 7-0 | MSBPosition | $07 PositionoftheMSBofthegreenfieldwithintheinputpixel. ($00)-PixelBit0 Thisfield,inconjunctionwiththesize,determineswhich ($01)—PixelBitt bitsoftheinputpixelareusedtoaccessthegreencolorpal- etteorgreenDACoutput.Thevaluespecifiedshouldbeless ($1F)-PixelBit31 thanthepixelsize. ($20)-Reserved ($FF)—-Reserved GreenWidthControl Reset |
| Bit(s) | FieldName | FieldDescription Value |
| 7-0 | Size | $08 Numberofbitstobeusedforthegreenfieldinapixel.The ($00)—Reserved sizeandpositionofthegreenfieldmustliewithinthe ($01)-1Bit definedpixelsize. ($02)-2Bits ($08)-8Bits ($09)-Reserved ($FF)--Reserved GreenBlinkEnableRegister Reset |
| Bit(s) | FieldName | FieldDescription Value |
| 7-0 | GreenBlinkEnable | $00 Bits7-0,correspondingtotheexpanded(ie.,eitherright justifiedandzeropadded,orleftjustifiedandMSBrepli- cated)greenpixelplanes7-0,respectively,enableblinking ofindividualplanes.Alogicaloneinanybitpositioncauses thecorrespondingpixelplanetobeturnedoffinaccordance withtheblinkratecounteranddutycycle.Alogicalzero causesthecorrespondingpixelplanetobeunaffectedbythe blinklogic.TheregisterisalsowrittenwithMPUdata whenevertheBt458-compatibleblinkregisteriswritten. WORKSTATIONGRAPHICS 5-27 |

Bt445 Brookiree’
InternalRegisters(continued)
GreenDisplayEnableControl
ThisregisterisalsowrittenmappedtotheBt458-compatiblereadmask.
Reset
Bit(s)	FieldName	FieldDescription
Value
EnableBitPlane7 Thisbitcontrolstheenablingofgreenbitplane7.Alogical
(0)Disable zerocausesbit7ofthegreenfieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit7ofthegreenfieldtopassto
thecolorpaletteorDAC.
EnableBitPlane6 Thisbitcontrolstheenablingofgreenbitplane6.Alogical
(0)Disable zerocausesbit6ofthegreenfieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit6ofthegreenfieldtopassto
thecolorpaletteorDAC.
EnableBitPlane5 Thisbitcontrolstheenablingofgreenbitplane5.Alogical
(0)Disable zerocausesbit5ofthegreenfieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit5ofthegreenfieldtopassto
thecolorpaletteorDAC.
EnableBitPlane4 Thisbitcontrolstheenablingofgreenbitplane4.Alogical
(0)Disable zerocausesbit4ofthegreenfieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit4ofthegreenfieldtopassto
thecolorpaletteorDAC. :
EnableBitPlane3 Thisbitcontrolstheenablingofgreenbitplane3.Alogical
(0)Disable zerocausesbit3ofthegreenfieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit3ofthegreenfieldtopassto
thecolorpaletteorDAC.
EnableBitPlane2 Thisbitcontrolstheenablingofgreenbitplane2.Alogical
(0)Disable zerocausesbit2ofthegreenfieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit2ofthegreenfieldtopassto
thecolorpaletteorDAC.
EnableBitPlanet Thisbitcontrolstheenablingofgreenbitplane1.Alogical
(0)Disable zerocausesbit1ofthegreenfieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit1ofthegreenfieldtopassto
thecolorpaletteorDAC.
EnableBitPlane0 Thisbitcontrolstheenablingofgreenbitplane0.Alogical
(0)Disable zerocausesbit0ofthegreenfieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit0ofthegreenfieldtopassto
thecolorpaletteorDAC.
5-28 SECTION5

Brooktree* Bt445
InternalRegisters(continued)
BlueMSBPosition
Reset
| Bit(s) | FieldName | FieldDescription Value |
| --- | --- | --- |
| 7-0 | MSBPosition | $07 PositionoftheMSBofthebluefieldwithintheinputpixel. ($00)-PixelBit0 Thisfield,inconjunctionwiththesize,determineswhich ($01)—PixelBit1 bitsoftheinputpixelareusedtoaccessthebluecolorpal- etteorblueDACoutput.Thevaluespecifiedshouldbeless ($1F)-PixelBit31 thanthepixelsize. ($20)—Reserved ($FF)—Reserved BlueWidthControl Reset |
| Bit(s) | FieldName | FieldDescription Value |
| 7-0 | Size | $08 Numberofbitstobeusedforthebluefieldinapixel.The ($00)-Reserved sizeandpositionofthebluefieldmustliewithinthedefined ($01)-1Bit pixelsize. ($02)-2Bits ($08)-8Bits ($09)—Reserved ($FF)—Reserved BlueBlinkEnableRegister Reset |
| Bit(s) | FieldName | FieldDescription Value |
| 70 | BlueBlinkEnable | $00 Bits7-0,correspondingtotheexpanded(i-e.,eitherright justifiedandzeropadded,orleftjustifiedandMSBrepli- cated)bluepixelplanes7-0,respectively,enableblinkingof individualplanes.Alogicaloneinanybitpositioncausesthe correspondingpixelplanetobeturnedoffinaccordance withtheblinkratecounteranddutycycle.Alogicalzero causesthecorrespondingpixelplanetobeunaffectedbythe blinklogic.TheregisterisalsowrittenwithMPUdata whenevertheBt458-compatibleblinkregisteriswritten. WORKSTATIONGRAPHICS 5-29 |

Bt445
InternalRegisters(continued)
BlueDisplayEnableControl
ThisregisterisalsowrittenwhentheBt458-compatiblereadmaskregisteriswritten.
Reset
Bit(s)	FieldName	FieldDescription
Value
EnableBitPlane7 Thisbitcontrolstheenablingofbluebitplane7.Alogical
(0)Disable zerocausesbit7ofthebluefieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit7ofthebluefieldtopasstothe
colorpaletteorDAC.
EnableBitPlane6 Thisbitcontrolstheenablingofbluebitplane6.Alogical
(0)Disable zerocausesbit6ofthebluefieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit6ofthebluefieldtopasstothe
colorpaletteorDAC.
EnableBitPlane5 Thisbitcontrolstheenablingofbluebitplane5.Alogical
(0)Disable zerocausesbit5ofthebluefieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit5ofthebluefieldtopasstothe
colorpaletteorDAC.
EnableBitPlane4 Thisbitcontrolstheenablingofbluebitplane4.Alogical
(0)Disable zerocausesbit4ofthebluefieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit4ofthebluefieldtopasstothe
colorpaletteorDAC. ,
EnableBitPlane3 Thisbitcontrolstheenablingofbluebitplane3.Alogical
(0)Disable zerocausesbit3ofthebluefieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit3ofthebluefieldtopasstothe
colorpaletteorDAC.
EnableBitPlane2 Thisbitcontrolstheenablingofbluebitplane2.Alogical
(0)Disable zerocausesbit2ofthebluefieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit2ofthebluefieldtopasstothe
colorpaletteorDAC.
EnableBitPlane| Thisbitcontrolstheenablingofbluebitplane1.Alogical
(0)Disable zerocausesbit1ofthebluefieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit1ofthebluefieldtopasstothe
colorpaletteorDAC.
EnableBitPlane0 Thisbitcontrolstheenablingofbluebitplane0.Alogical
(0)Disable zerocausesbit0ofthebluefieldofthepixeltobeforcedto
(1)Enable zero.Alogicalonecausesbit0ofthebluefieldtopasstothe
colorpaletteorDAC.
5-30 SECTION5

Brooktree* Bt445
InternalRegisters(continued)
OverlayMSBPosition
| : | ‘ | Reset |
| --- | --- | --- |
| Bit(s) | FieldName | Value FieldDescription |
| 7-0 | MSBPosition | $09 PositionoftheMSBoftheoverlayfieldwithintheinput ($00)-PixelBit0 pixel.Thisfield,inconjunctionwiththesize,determines ($01)-PixelBit1 whichbitsoftheinputpixelareusedtoaccesstheoverlay paletteorallDACoutputs.Thevaluespecifiedshouldbe ($1F)-PixelBit31 lessthanthepixelsize. ($20)—Reserved ($FF)-Reserved OverlayWidthControl |
| . | . | Reset |
| Bit(s) | FieldName | Value FieldDescription |
| JO | Size | $02 Numberofbitstobeusedfortheoverlayfieldinapixel,The ($00)—Reserved sizeandpositionoftheoverlayfieldmustliewithinthe ($01)-1Bit definedpixelsize. ($02)—2Bits ($03)—-3Bits ($04)-4Bits ($05)—Reserved ($FF)-Reserved OverlayBlinkEnableRegister |
| : | ‘ | Reset |
| Bit(s) | FieldName | Value FieldDescription |
| 74 | Reserved | $0 Reservedforfutureexpansion. |
| 3-0 | OverlayBlinkEnable | $0 Bits3-0,correspondingtotheexpanded(i.e.,eitherright justifiedandzeropadded,orleftjustifiedandMSBrepli- cated)overlaypixelplanes3-0,respectively,enableblinking ofindividualplanes.Alogicaloneinanybitpositioncauses thecorrespondingpixelplanetobeturnedoffinaccordance withtheblinkratecounteranddutycycle.Alogicalzero causesthecorrespondingpixelplanetobeunaffectedbythe blinklogic.Bits0and1ofthisfieldarealsoreadandwritten byaccessingtheBt458-compatibleoverlayblinkcontrolsin CommandRegister0. WORKSTATIONGRAPHICS 5-31 |

Bt445
InternalRegisters(continued)
OverlayDisplayEnableControl
Bits1and0ofthisregisterarealsomappedtotheBt458-compatiblecommandregister0bits1and0.
Reset
| Bit(s) | FieldName | FieldDescription Value |
| --- | --- | --- |
| 7-4 | Reserved | Reservedforfutureexpansion. EnableBitPiane3 Thisbitcontrolstheenablingofoverlaybitplane3.Alogi- (0)Disable calzerocausesbit3oftheoverlayfieldofthepixeltobe (1)Enable forcedtozero.Alogicalonecausesbit3oftheoverlayfield topasstotheoverlaypalette. EnableBitPlane2 Thisbitcontrolstheenablingofoverlaybitplane2.Alogi- (0)Disable calzerocausesbit2oftheoverlayfieldofthepixeltobe (1)Enable forcedtozero.Alogicalonecausesbit2oftheoverlayfield topasstotheoverlaypalette. EnableBitPlane1 Thisbitcontrolstheenablingofoverlaybitplane1.Alogi- (0)Disable calzerocausesbit1oftheoverlayfieldofthepixeltobe (1)Enable forcedtozero.Alogicalonecausesbit1oftheoverlayfield topasstotheoverlaypalette. EnableBitPlane0 Thisbitcontrolstheenablingofoverlaybitplane0.Alogi- (0)Disable calzerocausesbit0oftheoverlayfieldofthepixeltobe (1)Enable forcedtozero.Alogicalonecausesbit0oftheoverlayfield topasstotheoverlaypalette. 5-32 SECTION5 |

Brooktree’ Bt445
InternalRegisters(continued)
CursorMSBPosition
Reset
| Bit(s) | FieldName | FieldDescription Value |
| --- | --- | --- |
| 7-0 | MSBPosition | $00 PositionoftheMSBofthecursorfieldwithintheinput ($00)—-PixelBit0 pixel.Thisfield,inconjunctionwiththesize,determines ($01)—PixelBit\| whichbitsoftheinputpixelareusedtoaccessthecursor paletteorallDACinputs.Thevaluespecifiedshouldbeless ($1F)-PixelBit31 thanthepixelsize. ($20)-Reserved ($FF)—Reserved CursorWidthControl Reset |
| Bit(s) | FieldName | FieldDescription Value |
| 7-0 | Size | $02 Numberofbitstobeusedforthecursorfieldinapixel.The ($00)-Reserved sizeandpositionofthecursorfieldmustliewithinthe ($01)-1Bit definedpixelsize. ($02)—2Bits ($03)—Reserved ($FF)—Reserved CursorBlinkRegister Reset |
| Bit(s) | FieldName | FieldDescription Value |
| J-2 | Reserved | 000000 Reservedforfutureexpansion. |
| 1,0 | CursorBlinkEnable | 00 Bits1and0,correspondingtotheexpanded(i.e.,eitherright justifiedandzeropadded,orleftjustifiedandMSBrepli- cated)cursorpixelplanes1and0,respectively,enableblink- ingofindividualplanes.Alogicaloneinanybitposition causesthecorrespondingpixelplanetobeturnedoffin accordancewiththeblinkratecounteranddutycycle.Alog- ica]zerocausesthecorrespondingpixelplanetobeunaf- fectedbytheblinklogic. WORKSTATIONGRAPHICS 5-33 |

Bt445 Brooktree’
InternalRegisters(continued)
CursorDisplayEnableControl
| . | . | Reset |
| --- | --- | --- |
| Bit(s) | FieldName | Value FieldDescription |
| 7-2 | Reserved | 0000000 Reservedforfutureexpansion. |
| 1 | EnableBitPlane1 | 1 Thisbitcontrolstheenablingofcursorbitplane1.Alogi- (0)Disable calzerocausesbit1ofthecursorfieldofthepixeltobe (1)Enable forcedtozero.Alogicalonecausesbit1ofthecursorfield topasstothecursorpalette. |
| 0 | EnableBitPlane0 | 1 Thisbitcontrolstheenablingofcursorbitplane0.Alogi- (0)Disable calzerocausesbit0ofthecursorfieldofthepixeltobe (1)Enable forcedtozero.Alogicalonecausesbit0ofthecursorfield topasstothecursorpalette. PaletteBypassPosition |
| . | . | Reset |
| Bit(s) | FieldName | Value FieldDescription |
| 7-0 | LSBPosition | $00 PositionoftheLSBofthepalettebypassfieldwithinthe ($00)-PixelBit0 inputpixel.Thisfield,inconjunctionwiththesize,deter- ($01)—PixelBit1 mineswhichbitsoftheinputpixelareusedtocontrolpalette bypass.Thevaluespecifiedshouldbelessthanthepixel ($1F)—PixelBit31 size. ($20)—-Reserved ($FF)-Reserved PaletteBypassWidthControl |
| . | . | Reset |
| Bit(s) | FieldName | Value FieldDescription |
| 7-0 | Size | $01 Numberofbitstobeusedforthepalettebypassfieldina ($00)—-Reserved pixel.Thesizeandpositionofthepalettebypassfieldmust ($01)-1Bit liewithinthedefinedpixelsize. ($02)—Reserved ($FF)-Reserved 5-34 SECTION5 |

Brooktree’ Bt445
InternalRegisters(continued)
PixelPortStartPositionRegister
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
Bit(s)	FieldDefinition	Preset	Description
7-0	PixelPortStartPosition	$28	WhenMSBunpacked,thisregistershouldbeloadedwith
theMSB+1 ofthepixelinputbitstobeused.WhenLSB
($00)Bit0 unpacked,ThisregistercontainstheLSBnumberofthe
($01)Bit1 pixelbitstobeused.Forexample,ifMSBunpackingis
: desiredusingbits31-0oftheinputpixelport,thenthisreg-
($3F)Bit63 istershouldbeloadedwith$20.Thisregisterselectsthe
($40)Bit64 startingbitpositionforthepixelunpackinglogic.
($41)Reserved
($FF)Reserved
WORKSTATIONGRAPHICS 5-35

Bt445
InternalRegisters(continued)
PixelFormatControlRegister
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
Reset
Bit(s)	FieldDefinition	Description
Value
PixelUnpackingOrder Thisbitselectsthepixelunpackingordering.Whenpixels
areMSBunpacked,thefirstpixeloutputwillcomefromthe
(0)MSBUnpacking higher-orderbitsoftheinputpixelport.WhenLSBis
(1)LSBUnpacking unpacked,thefirstpixeloutputwillcomefromthelower-
orderbitsoftheinputpixelport.
Reserved Reservedforfutureexpansion.
CursorEnable Thisbitenablestheinputpixelcursorfieldtoselectthecur-
sorpalette.Whenthis‘bitisalogicalzero,theinputpixel
(0)Disable cursorfieldisignored.
(1)Enable
CursorColor0Enable Thisbitenablestheuseofcursorcolor0.Whenthisbitisa
logicalzero,acursorfieldvalueofzerocausesthecursorto
(0)Disable betransparent.Whenthisbitisalogicalone,acursorfield
(1)Enable valueofzerocausescursorcolor0tobeused.
OverlayEnable Thisbitenablestheinputpixeloverlayfieldtoselectthe
overlaypalette.Whenthisbitisalogicalzero,theinput
(0)Disable pixeloverlayfieldisignored.
(1)Enable
Reserved Reservedforfutureexpansion.
1,0	PaletteBypassControl	Thisfieldspecifieshowthepixeldatashouldaddressthe
colorpalette,orbypassit.Ifthecolorpaletteisused,apixel
(00)AlwaysuseColor willaddressthecolorpalettes,anditscontentswouldthenbe
Palette usedastheinputstotheDACsortodrivethepixeloutput
(01)Alwaysbypass port.Cursorandoverlaysalwaysusethecolorpalette.
ColorPalette
(10)Useinputpixelfield
(11)Reserved
5-36 SECTION5

Brooktree’ Bt445
InternalRegisters(continued)
PixelDepthControlRegister
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
| Bit(s) | FieldName | Reset | FieldDescription Value |
| --- | --- | --- | --- |
| 7-0 | PixelDepthSelect | $0A | Thesebitsselectthepixeldepth.Thetotalnumberofbitsper pixel,includingoverlay,cursor,andunusedbitsineach ($00)Reserved pixel,mustbespecified.Theresetvalueisconsistentwith ($01)1BivPixet theBt458(10bitsperpixel,8pseudocolorplus2overlay). ($02)2Bits/Pixel ($03)3Bits/Pixel ($1E)30Bits/Pixel ($1F)31Bits/Pixel ($20)32Bits/Pixel ($21)Reserved ($FF)Reserved PixelPLLRateRegister0 ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO. |
| Bit(s) | FieldName | Frese | FieldDescription |
| 7,6 | Reserved(logicalzero) | 00 | Reserved. |
| 5-0 | MultiplierSelection(M) | 011001 | Determinesthemultiplierfactorfortheinputoscillatorfre- quency(M)usedindeterminingthefinalpixelclockfre- ($00)Reserved quency. ($17)Reserved ($18)Multiplyby24 ($19)Multiplyby25 ($3E)Multiplyby62 ($3F)Multiplyby63 WORKSTATIONGRAPHICS 5-37 |

Bt445
InternalRegisters(continued)
PixelPLLRateRegister1
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
Reset
| Bit(s) | FieldName | FieldDescription Value |
| --- | --- | --- |
| 7,6 | PixelClockDivider(L) | ThisbitcontrolsthePixelPLLdividerL. (00)Divideby1 (01)Divideby2 (10)Divideby4 (11)Divideby8 |
| 5,4 | Reserved | Reserved. |
| 3-0 | PixelClockDivisor | 0100 Determinesthedivisorfactorfortheinputoscillatorfre- Selection(N) quency(N)usedindeterminingthefinalpixelclockfre- quency. (0000)Reserved (0001)Reserved (0011)Divideby4 (0100)Divideby5 (1110)Divideby15 (1111)Reserved 5-38 SECTION5 |

Brooktree’ Bt445
InternalRegisters(continued)
PLLControlRegister
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
Reset
| Bit(s) | FieldName | Value | FieldDescription |
| --- | --- | --- | --- |
| PixelClockPLLEnable | 1 | ThisbitdetermineswhetherthePLLusedtogeneratethe pixelclockshouldbeenabledordisabled.Shouldthe (0)PLLDisable PLLbedisabled,thepixelclockmustbeinputviathe (1)PLLEnable CLOCKandCLOCK*. |  |
| MCLKEnable | 1 | ThisbitdisablesthePLLusedtosynthesizethemaster clockwhicheventuallygeneratestheCPUclock,20MHz (0)MCLKsDisabled and25MHzclock.Alogicalzerowrittentothisbitdis- (1)MCLKsEnabled ables(i.e.,three-states)PLLoperationfortheseclocks only. |  |
| 54 | CPUClockSelection | Sd,0) | ThesebitsselecttheCPUfrequencyforCPUCLKoutput. WhenRESET*isactive,SJandSOselecttheinitialval- (00)50MHz uesofthesetwobits;whenRESET™rises,thesebitsare (01)40MHz latched. (10)33MHz (11)25MHz |
| 3-0 | VCOGainControl | 1000 | PLLVCOGainControl. (0000)—Range0 (0001)-Range1 (0010)-Range2 (0111)—Range7 (1000)-Range8 (1111)-Range15 WORKSTATIONGRAPHICS 5-39 |

Bt445
InternalRegisters(continued)
VIDCLK*CycleControlRegister
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
| Bit(s) | FieldName | Preset | FieldDescription |
| --- | --- | --- | --- |
| 7,6 | Reserved | 00 | Reservedforfutureexpansion. |
| 5-0 | VIDCLKCycleTime | 000011 | ThesebitsselecttheVIDCLK*cycletimeinpixelclock Select units. (000000)CLOCK (000001)CLOCK/2 (000010)CLOCK/3 (000011)CLOCK/4 (111101)CLOCK/62 (111110)CLOCK/63 (111111)CLOCK/64 5-40 SECTION5 |

Brooktree* Bt445
InternalRegisters(continued)
PixelLoadControlRegister
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
| Bit(s) | FieldName | Reset | FieldDescription Value |
| --- | --- | --- | --- |
| 7-5 | Reserved | 000 | Reserved |
| SCLK*Control | 0 | ThisbitspecifieswhetherthefirstSCLK*pulseaftera blankedtimeisneeded(logicalone)toreadthefirstpixel (0)Extrapulsenot item.Alogicalzeroindicatesthatthesystemhasexternally needed providedthefirstVRAMshiftclock,andtheBt445mayreg- (1)Extrapulseneeded istervalidpixeldatawiththefirstSCLK*. |  |
| SCLK*Enable | 0 | AlogicalonemustbewrittentothisbittoenableSCLK*to beoutput.Alogicalzerowrittentothisbitthree-statesthe (0)SCLK*Disabled SCLK*outputandthesystemshoulduseVIDCLK*togen- (1)SCLK*Enabled erateLD/SCLKI. |  |
| VIDCLK*Enable | 1 | AlogicalonemustbewrittentothisbittoenableVIDCLK tobeoutput.Alogicalzerowrittentothisbitthree-statesthe (0)VIDCLK*Disabled VIDCLK*output. (1)VIDCLK*Enabled |  |
| 1,0 | Reserved(logicalzero) WORKSTATIONGRAPHICS 5-41 | 00 | Reserved. |

Bt445
InternalRegisters(continued)
DigitalOutputControlRegister
ThecommandregistermaybewrittentoorreadbytheMPUatanytime.Bit0correspondstodatabusbitDO.
Reset
Bit(s)	FieldName	FieldDescription
Value
7
OperatingMode	0	Thisbitselectsthe4-4-4or8-8-8true-colormode.Whenthisbitis
alogicalzero,the4-4-4modeofoperationisselected.Inthismode
(0)4-4-4TrueColor
theappropriatePCLKedgedeliversthehigh-ordernibbleofthe
(1)8-8-8TrueColor
databeingdeliveredtotheDACinputs.Whenthisbitisalogical
one,the8-8-8modeofoperationisselected.Inthismodethehigh-
ordernibbleofeachpixelisdeliveredoneachPCLKrisingedge,
andthelow-ordernibbleofeachpixelisdeliveredonthefalling
edgeofPCLK.In8-8-8mode,thePCLKedgeselectcontrolisnot
used.
Reserved Reserved.
OR,OG,OB(3-0)Output Thisbitenablesthered,green,andbluedigitaloutputs.Thisoutput
Enable shouldnotbeenabledwhenthepixelrateexceedsthatspecifiedby
theACtimingparametersforthisoutput.Alogicalzerointhisbit
(0)Disable
disables(i.e.,three-states)thered,green,andbluedigitaloutputs.
(1)Enable
Whenthree-stated,theseoutputswillfloattovalidTTLlevelssince
internalpullupresistorsareprovided.
PVSYNC*,PHSYNC* Thisbitenablestheseparatepipelinedsyncoutputs.Alogicalone
OutputEnable enablestheoutputs;alogicalzerocausestheseoutputstobethree-
stated.Whenthree-stated,aninternalpullupresistormaintainsthis
(0)Disable
outputatalogicalone,providedthatitislightlyloaded.
(1)Enable
PSYNC#*OutputEnable Thisbitenablesthepixel-synchronized,pipelinedsyncoutputsig-
nal.ItmaybeusedtogeneratetheTTLsyncsignalrequiredby
(0)Disable
monitorshavingseparatesync.Alogicaloneenablestheoutput;a
(1)Enable
logicalzerocausesthisoutputtobethree-stated.Whenthree-stated,
aninternalpullupresistormaintainsthisoutputatalogicalone,
providedthatitislightlyloaded.
PBLANK*OutputEnable Thisbitenablesthepixel-synchronized,pipelinedblankoutputsig-
nal.Alogicaloneenablestheoutput;alogicalzerocausesthisoutput
(0)Disable
tobethree-stated.Whenthree-stated,aninternalpullupresistor
(1)Enable
maintainsthisoutputatalogicalone,providedthatitislightlyloaded.
PCLKEdgeSelect ThisbitselectstheedgeofPCLKtowhichthedigitaloutputchanges
willbesynchronized.AlogicalzerocausestheACtimingparame-
(0)Risingedge
tersforthedigitalpixeloutputstobereferencedtotherisingedgeof
(1)Fallingedge
PCLK.AlogicalonecausestheACtimingparametersforthedigital
pixeloutputstobereferencedtothefallingedgeofPCLK.Thisbit
isnotusedwhenthe8-8-8modeofoperationisselected.
PCLKOutputEnable ThisbitenablesthePCLKoutputofthedigitalpixeloutputport.
Thisoutputshouldnotbeenabledwhenthepixelrateexceedsthat
(0)Disable
specifiedbytheACtimingparametersforthisoutput.Alogicalone
(1)Enable
enablestheoutputs;alogicalzerocausesthisoutputtobethree-
stated.Whenthree-stated,aninternalpullupresistormaintainsthis
outputatalogicalone,providedthatitislightlyloaded.
5~42 SECTION5

Brooktree’ Bt445
InternalRegisters(continued)
MPXRateRegister
| Bit(s) | FieldName | eset | FieldDescription |
| --- | --- | --- | --- |
| 7,6 | Reserved | 00 | Reservedforfutureexpansion |
| 5-0 | MPXRate | $03 | Numberofpixelsloadedperinputpixelloadcycle.The valuespecifiedshouldbeconsistentwiththepixeldepth;i.e. ($00)1:1 thenumberofpixelsmultipliedbythepixe)depthlessthan ($01)2:1 orequaltothenumberofbitsforwhichtheinputportiscon- ($02)3:1 figured. ($03)4:1 ($3E)63:1 ($3F)64:1 WORKSTATIONGRAPHICS 5-43 |

Bt445 Brooktree’
InternalRegisters(continued)
IDRegister
This8-bitregistermaybereadbytheMPUtodeter- logicalone,thesignaturesarebeingacquired.The
minethetypeofRAMDACbeingusedinthesystem. MPUmaywritetotheoutputSARswhileBLANK*is
ThevalueisdifferentforeachRAMDAC.Forthe alogicalzerotoloadtheseedvalue.TheoutputSARs
Bt445,thevaluereadbytheMPUwillbe$3A.Data usedatabeingloadedintotheoutputDACstocalculate
writtentothisregisterisignored. thesignatures.JTAGlogiccanaccesstheoutputSAR
independentlyoftheMPUoperation.MPUaccessesto
theSARsrequireoneaddressregisterloadfollowedby
RevisionRegister
threereadsorwritestothered,green,andbluesigna-
This8-bitregisterisaread-onlyregister,specifyingthe tureregisters,respectively.DOcorrespondstoRO,GO,
revisionoftheBt445.The4mostsignificantbitssig- andBO.
nifytherevisionletter,A,inhexadecimalform.The4 Byloadingatestdisplayintotheframebuffer,a
leastsignificantbitsdonotrepresentanyvalueand givenvalueforthered,green,andbluesignatureregis-
shouldbeignored. terswillbereturnedifallcircuitryisworkingproperly.
ItisimperativethattheMPUadheretoconditions
ReadEnableRegister requiredtopreventthedisruptionofpixeldataduring
signatureacquisitiontoensureconsistentresults.See
WritingthisBt458-compatibleregisterlocationcauses
theACCharacteristicssectionforfurtherinformation.
thered,green,andbluereadenableregisterstobe
simultaneouslywrittenwiththeMPUdata.Eachread
TestRegister0
enableregisterisusedtoenable(logicalone)ordisable
(logicalzero)red,green,andblueplanesfromaddress- ThetestregisterprovidesBt458-compatiblediag-
ingthecolorpaletteRAM.D(7-0)correspondtobits nosticcapabilitybyenablingtheMPUtoreadthe
7-0ofthered,green,andbluefieldsofeachpixel, inputstotheD/Aconverters.Itmaybewrittentoor
respectively.EachregisterbitislogicallyANDedwith readbytheMPUatanytime,andisinitializedtoDAC-
thecorrespondingfieldbitinput.Theseregistersmay selectequalsnone.Whenwritingtotheregister,the
bewrittentoorreadbytheMPUatanytimeandare upper4bits(D4—D7)areignored.Thecontentsofthe
initializedto$FF.AnMPUreadofthisregisterreads testregisteraredefinedinTable5.
thecontentsofthegreenreadenableregister. Tousetestregister0,the.hostMPUwritestoit,
selectingthenibbleandtheDACinputtoberead.This
specifieswhich4bitsofcolorinformationtheMPU
BlinkEnableRegister
wishestoread(R(3-0),G(3-0),B(3-0),R(7-4),G(7-
WritingthisBt458-compatibleregisterlocationcauses
4),orB(7-4)).WhentheMPUreadstestregister0,the
thered,green,andbluereadblinkregisterstobesimul- 4bitsofcolorinformationfromtheDACinputsare
taneouslywrittenwiththeMPUdata.Theblinkenable containedintheupper4bitsoftheMPUdatabus,and
registerisusedtoenable(logicalone)ordisable(logi- thelower4bitscontainthered,green,blue,low,or
calzero)individualbitsinthered,green,andbluecolor
highnibbleselectioninformationpreviouslywritten.
fieldsfromblinkingattheblinkrateanddutycycle Notethateitherthepixelclockmustbeasslowasthe
specifiedbythecommandregister.D(7-0)correspond MPUcycletime,orthesamepixelandoverlaydata
tofieldbits7-0,respectively.Inorderforabitplaneto mustbepresentedtothedeviceduringtheentireMPU
blink,thecorrespondingbitinthereadenableregister readcycle.
mustbealogicalone.Thisregistermaybewrittentoor
Forexample,toreadtheupper4bitsofredcolor
readbytheMPUatanytimeandisinitializedto$00. informationbeingpresentedtotheD/Aconverters,the
AnMPUreadofthisregisterreadsthecontentsofthe MPUwritestotestregister0,settingtheDACselect
GreenBlinkEnableRegister. fieldto001andthelownibbleselectto0.TheMPU
thenreadstestregister0,keepingthepixeldatastable,
SignatureAnalysisRegisters(SAR) whichresultsinD(7-4)containingtheR(7-4)DAC
inputbits,andD(3—-0)containingthered,green,blue,
low,orhighnibbleenableinformation,asillustratedin
SignatureAnalysisOperation
Table6.
Thesethree8-bitSARsmaybereadbytheMPU
whileBLANK*isalogicalzero.WhileBLANK*isa
5-44 SECTION5

Brooktree* Bt445
InternalRegisters(continued)
| Bits) | FieldName | Rese" | Description |
| --- | --- | --- | --- |
| 74 | DACInputData | N/A | ColorinformationatDACinput(4bitsofred,green,or blue).Datawrittentothisfieldisignored. |
| 3 | LowNibbleSelect | 0 | Writingalogicalonetothisfieldenablesthelownibble (0)HighNibble (i.e.,bits3-0)oftheselectedDACinputtobereadfrom (1)LowNibble bits7-4ofthistestregister.Writingalogicalzerotothis fieldenablesthehighnibble(i.e.,bits7-4)oftheselected DACinputstobereadfrombits7—4ofthistestregister. |
| 2-0 | DACSelect | 000 | Blueenable (000)None Greenenable (001)Red Redenable (010)Green (100)Blue Allotherdecodesare reserved. Table5.TestRegister0. MPUBusBits ValueRead 7A R(7-4) 3-0 0001 Table6.TestRegister0Example. WORKSTATIONGRAPHICS 5-45 |

Bt445 Brooktree*
InternalRegisters(continued)
Thecomparator,whichmaybeaccessedinTest analogcablesconnectingthemonitorisopen(i.e.,bro-
Register1(seeTable7),enablestheMPUtodetermine ken),thevoltagepresentatthecorrespondingDAC
whethertheCRTmonitorisconnectedtotheanalog outputwouldbehigherthanpredicted,asoneofthe
RGBoutputsornot,andwhethertheDACsarefunc- terminationresistorswouldnotbepresent.
tional,Whenthemonitorisnotconnectedoroneofthe
| Bit(s) | FieldName | reset | Description |
| --- | --- | --- | --- |
| 7,6 | Operand1Select | 00 | ThisfieldselectsOperand1ofthecomparator.Fornormal operation,theoperand\|and2fieldsshouldbothcontain00. (00)NormalOperation (01)SelectGreenDAC Output (10)SelectRedDAC Output (11)Reserved |
| 5,4 | Operand2Select | 00 | ThisfieldselectsOperand2ofthecomparator.Fornormal operation,theoperand1and2fieldsshouldbothcontain00. (00)NormalOperation (01)Select145mV Reference (10)SelectBlueDAC Output (11)Reserved |
| 3 | ComparisonResult | N/A | ThisfieldyieldstheresultofthecomparisonoftheDAC and/orreferenceoutput.Comparingoperandswhosevalues (0)Operand1<Operand2 liewithinafewLSBswillyieldunpredictableresults.Data (1)Operand1>Operand2 writtentothisbitisignored,asthisfieldisreadonly.This resultisvalidonlyaftertherequiredcomparisonsettling timeisreached(i.e.,5Usaftertheoperandbecomescon- stant). |
| 2-0 | Reserved | 000 | Reserved. Table7.TestRegister1. 5—46 SECTION5 |

Brooktree’ Bt445
PinDescriptions
Pin Pin
Description
Count Name
BLANK* Compositeblankcontrolinput(TTLcompatible).Alogicalzerodrivestheanalogoutputs
totheblankinglevel,asillustratedinTables2and3.Itisregisteredontherisingedgeof
LD.WhenBLANK*isalogicalzero,thepixelandoverlayinputsareignored.
SYNC*/ Compositesync/Hsynccontrolinput(TTLcompatible).Alogicalzeroonthisinput
HSYNC* switchesoffanIREcurrentsourceontheIOGoutput(seeFigures6and7).SYNC*/
HSYNC*doesnotoverrideanyothercontro!ordatainput,asshowninTables2and3;
therefore,itshouldbeassertedonlyduringtheblankinginterval.Itisregisteredontheris-
ingedgeofVIDCLKI.IfsyncinformationisnottobegeneratedontheJOGoutput,this
pinshouldbeconnectedtoGND.
VSYNC* Separatesynccontrolinputs(TTLcompatible).Thissignalisregisteredwitheachrising
edgeofVIDCLKIandispipelinedtothepixeldatarate,thenoutputwithpixeltimingto
thePVSYNC*outputs.ThissignalisnotinternallyusedbytheBt445.
VIDCLKI VideoClockinput(TTL-compatibleSchmittTrigger).Therisingedgeofthisinputis
usedtoloadtheSYNC*andBLANK*controlinputs.Also,ifSCLK*isnotusedtocon-
troltheVRAMframebuffer,pixelinputs(PO-P47)arealsoloadedwiththerisingedgeof
thissignal.Thisinputisusuallydrivenwithasystem-buffered/skewedversionofthe
VIDCLK*output.
LD/SCLKI LoadSerialClockInput(TTL-compatibleSchmittTrigger).Thissignalisusedonlywhen
theBt445isconfiguredtoprovidetheVRAMserialclock(SCLK*)output.Pixeldatais
loadedontherisingedgeofthissignal,exceptforthefirstrisingedge,whichoccursdur-
ingblanking.Thisinputisusuallydrivenwithasystem-buffered/skewedversionofeither
theSCLK*outputorVIDCLK*.
64	P(63-0)	PixelInputsPort(TTLcompatible).Theseinputsareusedtospecify,onapixelbasis,
whichoneofthe256entriesinthecolorpaletteRAM,16entriesoftheoverlaypalette,or
4entriesofcursorpaletteistobeusedtoprovidecolorinformation.Dependingonthe
pixelconfiguration,upto64consecutivepixelsperloadcycleareinputthroughthisport.
TheyareregisteredontherisingedgeofVIDCLKIorLD/SCLKI.Theseinputshave
internalpullupresistors;therefore,unusedpinsdonotrequireconnection.However,ifthe
systemconfigurationallows,theunusedpinsshouldbeconnectedtoGND.
Sc,0) CPUClockRateSelectSwitch(TTLcompatible).Theseinputsareusedtosettheinitial
CPUclockrateatresettime.
IOR,IOG, Red,green,andbluevideocurrentoutputs.Thesehigh-impedancecurrentsourcesare
IOB capableofdirectlydrivingadoubly-terminated75-Qcoaxialcable(Figure12).
SCLK* VRAMshiftclockoutput(TTL-voltage-levelcompatible,lowdrive).Thesignalonthis
pinisequaltotheselectedpixelclockdividedby1,2,4,8,or32dependingonthepixel
depthselected.Thisclockmustberedriventhroughaninvertingbufferpriortothecon-
nectiontotheserialclockoftheVRAMs,
VIDCLK* VideoClockOutput(TTL-voltage-levelcompatible,lowdrive).Thisoutputisadivided
pixelasprogrammedintheVIDCLK*CycleControlregister.Thisclockmustbe
redriventhroughaninvertingbufferpriortotheconnectiontotheCRTtiminggeneration
logic.
WORKSTATIONGRAPHICS 5-47

Bt445
PinDescriptions(continued)
| Pin | Pin | . |
| --- | --- | --- |
| Count | Name | Description |
| 1 | PCLK | PixelClock(TTL-voltage-levelcompatible,lowdrive).Thisclockisusedtosynchro- nizethenextstagewiththedigitaloutputs.Itmustberedriventhroughanoninverting bufferpriortotheconnectiontothenextstage.Thispixelclockhasamaximumoutput clockspeedof55MHzdrivinga20pFload. |
| 1 | PSYNC* | CompositeSYNCcontroloutput(TTL-voltage-levelcompatible,lowdrive).Thissignal issynchronizedwiththepixeloutputs. |
| 2 | PHSYNC*, | SeparateSYNCcontroloutputs(TTL-voltage-levelcompatible,lowdrive).Thesesig- PVSYNC* nalsaresynchronizedwiththepixeloutputs. |
| 1 | PBLANK* | CompositeBLANKcontroloutput(TTL-voltage-levelcompatible,lowdrive).Thissig- nalissynchronizedwiththepixeloutputs. |
| 12 | OR(3-0) | DigitalOutputs(TTL-voltage-levelcompatible,lowdrive).Theselow-driveoutputs OGG-0) representthe4MSBsofthered,green,andblueDACdecoderandcanbeusedtodrive OB(3-0) anactivematrixTFTdirectly.Theseoutputsmustberedriventhroughanoninverting bufferpriortotheconnectiontothenextstage. |
| 1 | CPUCLK | CPUClock(TTL-voltage-levelcompatible,lowdrive).Thisclockisusedtoderivethe CPUclockandisselectablebetween50,40,33,and25MHz(whenusinga20MHz crystal).Thisclockmustberedriventhroughabufferpriortotheconnectiontothenext stage.Thispixelclockhasamaximumoutputclockspeedof50MHzdrivinga20pF load. |
| ] | MCLK20 | 20MHzMasterClock(TTL-voltage-levelcompatible,lowdrive).Thismasterclock generatesaconstant20MHzclock.Thisclockmustberedriventhroughabufferprior totheconnectiontothenextstage.Thispixelclockhasamaximumoutputclockspeed of50MHzdrivinga20pFload. |
| 1 | MCLK25 | 25MHzMasterClock(TTL-voltage-levelcompatible,lowdrive).Thismasterclock generatesaconstant25MHzclock.Thisclockmustberedriventhroughabufferprior totheconnectiontothenextstage.Thispixelclockhasamaximumoutputclockspeed of50MHzdrivinga20pFload. |
| 1 | TMS | TestModeSelect(TTLcompatible).JTAGinputpinwhosetransitionsdrivetheJTAG statemachinethroughitssequences.WhennotperformingJTAGoperations,thispin shouldbedriventoalogichigh. |
| 1 | TCK | TestClock(TTLcompatible).UsedtosynchronizeallJTAGteststructures.Maximum clockrateforthispinis50MHz.WhennotperformingJTAGoperations,thispinshould bedriventoalogichigh. |
| 1 | TDI | TestDataIn(TTLcompatible).JTAGinputpinusedforloadinginstructionstotheTAP controllerorforloadingtestvectordataforboundaryscanoperation.Whennotper- formingJTAGoperations,thispinshouldbedriventoalogichigh. |
| 1 | TDO | TestDataOut(TTLcompatible).JTAGoutputusedforverifyingtestresultsofallJTAG samplingoperations.ThisoutputpinisactiveforcertainJTAGsequences,andwillbe three-statedatallothertimes.WhennotperformingJTAGoperations,thispinshouldbe leftfloating. 5—48 SECTION5 |

Brooktree’ Bt445
PinDescriptions(continued)
Pin
| Count | PinName | Description COMP, Compensationpins.Thesepinsprovidecompensationfortheinternalreferenceampli- COMP2 fier.A0.1pFceramiccapacitormustbeconnectedbetweenthesetwopins(Figure13). FSADJUST Full-scaleadjustcontrol.Aresistor(RSET)connectedbetweenthispinandGNDcon- trolsthemagnitudeofthefull-scalevideosignal(Figure13).NotethattheIRErelation- shipsinFigures6and7aremaintained,regardlessofthefull-scaleoutputcurrent. TherelationshipbetweenRSETandthefull-scaleoutputcurrentonIOGis: RSET(Q)=KI*VREF(V)/IOG(mA) Thefull-scaleoutputcurrentonIORandIOBforagivenRSETis: IOR,IOB(mA)=K2*VREF(V)/RSET(Q) whereK1andK2aredefinedas: |
| --- | --- | --- |
| Setup | 1OG | IOR,OB |
| 7.5TIRE | K1]=11,294 | K2=8,067 |
| OIRE | K1=10,684 VREF Voltagereferenceinput.Anexternalvoltagereferencecircuit,suchastheoneshownin Figure13,mustsupplythisinputwitha1.235V(typical)reference.Theuseofaresistor networktogeneratethereferenceisnotrecommended,asanylow-frequencypower supplynoiseonVREFwillbedirectlycoupledontotheanalogoutputs.A0.1LF ceramiccapacitormustbeusedtodecouplethisinputtoVAA,asshowninFigure13. ThedecouplingcapacitormustbeascloseaspossibletothedevicetokeepJeadlengths toanabsoluteminimum. CLOCK, Clockinputs.ThesedifferentialclockinputsaredesignedtobedrivenbyECLlogic CLOCK* configuredforsinglesupply(+5V)operation.Theclockrateistypicallythepixelclock rateofthesystem. XTAL1 Crystalinput.ThisinputiseitherconnectedtoacrystalordrivenbyaCMOSoscillator. TheinternalphaselockloopsgeneratethepixelandCPUclocksusingthisinput. XTAL2 Crystalamplifieroutput.Thisoutputisconnectedtothesecondterminalofthecrystal whenused. CE* Chipenablecontrolinput(TTL-compatibleSchmittTrigger).Thisinputmustbealogi- calzerotoenabledatatobewrittentoorreadfromthedevice.Duringwriteoperations, dataisinternallyregisteredontherisingedgeofCE*.Careshouldbetakentoavoid glitchesonthisedge-triggeredinput. Read/writecontrolinput(TTLcompatible).Towritedatatothedevice,bothCE*andR/ Wmustbealogicalzero.Toreaddatafromthedevice,CE*mustbealogicalzeroand R/Wmustbealogicalone.R/WisregisteredonthefallingedgeofCE*. C(Q-0) Commandcontrolinputs(TTLcompatible),C2,C1,andCOspecifythetypeofreador writeoperationbeingperformed,asillustratedinTable1.Theyareregisteredwiththe fallingedgeofCE*. WORKSTATIONGRAPHICS 5—49 | K2=7,457 |

Bt445 Brooktree’
PinDescriptions(continued)
| 8 | DQ-0) | Databus(TTLcompatible).Dataistransferredintoandoutofthedeviceoverthis8-bit bidirectionaldatabus.DOistheleastsignificantbit. |
| --- | --- | --- |
| 1 | RANGE | CompensationforVCO.A0.01HFceramicchipcapacitormustbeconnectedbetween thispinandVAA(Figure13). |
| 1 | RESET* | Resetinput(TTLcompatible).Whenthissignalisasserted,alltheCommandRegister BitsaresettobeinaBt458-compatiblemode. |
| 7 | NC | NoConnect.Reservedforfutureexpansion.Thesepinsshouldbeleftopen. |
| 19 | VAA | Analogpower.AllVAApinsmustbeconnected. |
| ll | GND | Analogground.AllGNDpinsmustbeconnected. g ZSasaagesaseedeSSsRsERRRELLERRELTZELEEREE |
S28
VAT	merttrrreeeeeeReRRR	eeeweeROfhvaa
[]VAA
fj)P12
[)Pit
)P10
pPs
)Pe
)P?
Ps
NPs
Pa
bs
P2
-
Po
be
NC
rien	Bt445	bc
ome
160PinPlastic
xm
FlatPack [}PBLANK®
GND Quad
Vaa	.	DSci:
pcx
TopView
comes
GND
OR}
bon
GND ORO
10G 063
GND 0G2
VAA oat
JOR poGo
VAA f)083
GND Dope
VREF nc
Fsans(38 GND
vaaQJ39 VAA
VAA(J40 ;VAA
HESESESRLEZFLPESLFRLRSERERELEEL22EE22
Figure11.160-pinPQFPPinAssignments.
5-50 SECTION5

Brooktree* Bt445
PinDescriptions(continued)
| Signal | PinNumber | Signal | PinNumber\|Signal | PinNumber | Signal | PinNumber |
| --- | --- | --- | --- | --- | --- | --- |
| BLANK* | 148 | P25 | 135 | VAA | 39 | OBO 76 |
| SYNC*/HSYNC* | 147 | P26 | 136 | VAA | 40 | OB] 77 |
| VSYNC* | 150 | P27 | 137 | VAA | 4] | OB2 85 |
| NC | 149 | P28 | 138 | VAA | D | OB3 |
| P29 | 139 | VAA | 8 |  |  |  |
| CLOCK* | 18 | P30 | 140 | VAA | 81 | IOR |
| CLOCK | 17 | P31 | 141 | VAA | 82 | I0G 31 |
| XTAL1 | 20 | VAA | 119 | IOB |  |  |
| XTAL2 | 21 | P32 | 42 | VAA | 120 |  |
| RANGE | 24 | P33 | 43 | VAA | 121 | COMP |
| P34 | 44 | VAA | 122 | COMP2 | 25 |  |
| SO | 11 | P35 | 45 | VAA | 160 | FSADJUST 38 |
| Sl | 12 | P36 | 46 | VREF | 37 |  |
| RESET* | 10 | P37 | 47 | GND | 3 |  |
| CPUCLK | 142 | P38 | 48 | GND | 19 | CE* 5 |
| MCLK20 | 144 | P39 | 49 | GND | 22 | R/W 6 |
| MCLK25 | 143 | P40 | 50 | GND | XD | C2 9 |
| P41 | 31 | GND | 32 | Cl | 8 |  |
| SCLK* | 98 | P42 | 52 | GND | 36 | CO |
| VIDCLK* | 97 | P43 | 53 | GND | 38 | D7 159 |
| VIDCLKI | 146 | P44 | 54 | GND | B | D6 158 |
| LD/SCLKI | 145 | P45 | 35 | GND | 36) | D5 157 |
| P46 | 56 | GND | 95 | D4 | 156 |  |
| PO | 106 | P47 | 57 | GND | 151 | D3 155 |
| Pl | 107 | D2 | 154 |  |  |  |
| P2 | 108 | P48 | 59 | NC | 4 | D1 153 |
| P3 | 109 | P49 | 60 | NC | DB | DO 152 |
| P4 | 110 | P50 | 61 | NC | & |  |
| P5 | 111 | P5 | 62 | NC | 103 | TMS 16 |
| P6 | 112 | P52 | 63 | NC | 104 | TCK 13 |
| P7 | 113 | P53 | 64 | NC | 105 | TDI 15 |
| P8 | 114 | P54 | 65 | TDO | 14 |  |
| P9 | 115 | P55 | 66 | PCLK | % |  |
| P10 | 116 | P56 | 67 | PBLANK* | 9 |  |
| Pil | 7 | P57 | 68 | PSYNC* | 100 |  |
| P12 | 118 | P58 | 69 | PVSYNC* | 10] |  |
| P13 | 123 | P59 | 70 | PHSYNC* | 102 |  |
| P14 | 124 | P60 | 7] |  |  |  |
| PI5 | 125 | P61 | 72 | ORO | 9] |  |
| P62 | 73 | ORI | 92 |  |  |  |
| P16 | 126 | P63 | 74 | OR2 | B |  |
| P17 | 127 | OR3 | se |  |  |  |
| P18 | 128 | VAA | 1 | OGO0 | 87 |  |
| P19 | 129 | VAA | 2 | OG! | 88 |  |
| P20 | 130 | VAA | 23 | OG2 | 89 |  |
| P21 | 131 | VAA | 27 | OG3 | 9 |  |
| P22 | 132 | VAA | 29 |  |  |  |
| P23 | 133 | VAA | 33 |  |  |  |
| P24 | 134 WORKSTATIONGRAPHICS 5-51 | VAA | 35 |  |  |  |

Bt445
PCBoardLayoutConsiderations
PCBoardConsiderations
TheBt445layoutshouldbeoptimizedforlowestnoise capacitorsareforhigh-frequencypowersupplynoise
ontheBt445powerandgroundlinesbyshieldingthe rejection.Thedecouplingcapacitorsshouldbecon-
digitalinputsandprovidinggooddecoupling.Thetrace nectedattheVAAandGNDpins,usingshort,wide
lengthbetweengroupsofVAAandGNDpinsshould traces.
beasshortaspossibletominimizeinductiveringing. Whenusingalinearregulator,thepower-up
Awell-designedpowerdistributionnetworkiscriti- sequencemustbeverifiedtopreventlatchup.Alinear
caltoeliminatingdigitalswitchingnoise.Theground regulatorisrecommendedtofiltertheanalogpower
planesmustprovidealow-impedancereturnpathfor supplyifthepowersupplynoiseislessthan200mV.
thedigitalcircuits.APCboardwithaminimumofsix Thisisespeciallyimportantwhenaswitchingpower
layersisrecommended.Thegroundlayershouldbe supplyisusedandtheswitchingfrequencyiscloseto
usedasashieldtoisolatenoisefromtheanalogtraces therasterscanfrequency.Notethatabout10percentof
withlayer1(top)theanalogtraces,layer2theground powersupplyhumandripplenoiselessthan1MHz
plane(preferableanaloggroundplane),layer3theana- willcoupleontotheanalogoutputs.
logpowerplane,andtheremaininglayersusedfordig-
italtracesanddigitalpowersupplies.
COMPDecoupling
TheoptimumlayoutenablestheBt445tobelocated
ascloseaspossibletothepowersupplyconnectorand TheCOMPpinmustbedecoupledtoVAA,typically
thevideooutputconnector. usinga0.1WFceramiccapacitor.Low-frequencysup-
plynoisewillrequirealargervalue.TheCOMPcapac-
itormustbeascloseasphysicallypossibletothe
PowerandGroundPlanes
COMPandVAApins.Asurface-mountceramicchip
Thepowerandgroundplanesneedisolationgapsto capacitorispreferredforminimalleadinductance,
minimizedigitalswitchingnoiseeffectsontheanalog whichdegradesthenoiserejectionofthecircuit.Short,
signalsandcomponents.Thesegapsneedtobeatleast widetraceswillalsoreduceleadinductance.
1/8"wide.Theyareplacedsothatdigitalcurrentscan- Ifthedisplayhasaghostingproblem,additional
notflowthroughapeninsulathatcontainstheanalog capacitanceinparallelwiththeCOMPcapacitormay
components,signals,andvideoconnector.Asample helpfixtheproblem.
layoutisshowninFigure12.
DigitalSignalInterconnect
DeviceDecoupling
ThedigitalinputstotheBt445shouldbeisolatedas
Foroptimumperformance,allcapacitorsshouldbe muchaspossiblefromtheanalogoutputsandother
locatedasclosetothedeviceaspossible,usingthe analogcircuitry.Also,theseinputsignalsshouldnot
shortestleadspossible(consistentwithreliableopera- overlaytheanalogpowerandoutputsignals.
tion)toreducetheleadinductance.Chipcapacitorsare Mostnoiseontheanalogoutputswillbecausedby
recommendedforleadinductance.Radialleadceramic excessiveedgerates(lessthan3ns),overshoot,under-
capacitorsmaybesubstitutedforchipcapacitorsand shoot,andringingonthedigitalinputs.
arebetterthanaxialleadcapacitorsforself-resonance. Thedigitaledgeratesshouldbenofasterthannec-
Valuesarechosentohaveself-resonanceabovethe essary,asfeedthroughnoiseisproportionaltothedigi-
pixelclock. taledgerates.Lowerspeedapplicationswillbenefit
usinglowerspeedlogic(3-5nsedgerates)toreduce
data-relatednoiseontheanalogoutputs.
PowerSupplyDecoupling
Transmissionlineswillmismatchifthelinesdonot
Bestpowersupplydecouplingperformanceisobtained
matchthesourceanddestinationimpedance.Thiswill
byprovidinga0.1WFceramiccapacitorinparallelwith
degradesignalfidelityifthelinelengthreflectiontime
a0.01uFchipcapacitortodecoupleeachgroupof isgreaterthanonefourththesignaledgetime.Lineter-
VAApinstoGND.Thecapacitorsshouldbeplacedas minationorlinelengthreductionisthesolution.For
closeaspossibletothedeviceVAAandGNDpins.
example,logicedgeratesof2nsrequirelinelengthsof
The33uFcapacitorshowninFigure13isforlow-
lessthan4incheswithoutusingtermination.Ringing
frequencypowersupplyripple;the0.1(dFand0.01uF maybereducedbydampingthelinewithaseriesresis-
tor30-3002).
§-52 SECTION5

Brooktree’ Bt445
PCBoardLayoutConsiderations(continued)
DigitalArea
rTTTT4
eS
l
®© nalog
ge	Area |	RAMDAC
oO |
LowLL
EdgeofPCB DigitalArea
Figure12.RepresentativePower/GroundAnalogAreaLayout
Radiationofdigitalsignalscanalsobepickedupby AnalogoutputvideoedgesexceedingtheCRTmon-
theanalogcircuitry.Thisispreventedbyreducingthe itorbandwidthcanbereflected,producingcable-length
digitaledgerates(rise/falltime),minimizingringingby dependentghosts.Simplepulsefilterscanreducehigh-
usingdampingresistors,andminimizingcoupling frequencyenergy,reducingEMIandnoise.Thefilter
throughPCboardcapacitancebyrouting90degreesto impedancemustmatchthelineimpedance.
anyanalogsignals.
Theclockdriverandallotherdigitaldevicesonthe
AnalogOutputProtection
circuitboardmusthaveadequatedecouplingtoprevent
thenoisegeneratedbythedigitaldevicesfromcou- TheBt445analogoutputsshouldbeprotectedagainst
plingintotheanalogcircuitry. high-energydischarges,suchasthosefrommonitor
arc-overorfrom“hot-switching"AC-coupledmonitors.
ThediodeprotectioncircuitshowninFigure13can
AnalogSignalInterconnect
preventlatchupunderseveredischargeconditions
TheBt445shouldbelocatedascloseaspossibletothe withoutadverselydegradinganalogtransitiontimes.
outputconnectorstominimizenoisepickupandreflec- The1N4148/9arelow-capacitance,fast-switching
tionsduetoimpedancemismatch. diodes,whicharealsoavailableinmultiple-device
Thevideooutputsignalsshouldnotoverlaytheana- packages(FSA250XorFSA270X)orsurface-mount-
logpowerplane,tomaximizethehigh-frequency ablepairs(BAV99orMMBD7001).
powersupplyrejection.
Formaximumperformance,theanalogvideooutput
impedance,cableimpedance,andloadimpedance
shouldbethesame.
WORKSTATIONGRAPHICS 5-53

Bt445
PCBoardLayoutConsiderations(continued)
Bt445 ‘Locateascloseas
possibletoBt445
VAA	VAA	+5(VEC)
(@pin23) il
:	R4	cg
RANGE +
C10 C1
VREF 02-04
ral
GND GROUND
iXTALI
"T RSET
XTAL2
COMP FSADJUST
wees
eae IoR
COMP2	108	—	Jaa
VAA
1N4148/
DAC
9 TOMONITOR
OUTPUT 1N4148/
9
GND
DiodeProtectionCircuit
| Location | Description | VendorPartNumber |
| --- | --- | --- |
| C1-C4,C8,C9 | 0.1fFceramiccapacitor | ErieRPE112Z75U104M50V |
| CS-C7,C11 | 0.01uFceramicchipcapacitor | AVX12102T103QA1018 |
| C10 | 33UFtantalumcapacitor | MalloryCSR13F336KM |
| C12 | 4.7UFtantalumcapacitor | tbd |
| Ll | ferritebead | Fair-Rite2743001111 |
| R1,R2,R3 | 75Q1%metalfilmresistor | DaleCMF-55C |
| R4 | 1000Q1%metalfilmresistor | DaleCMF-55C |
| RSET | 523©1%metalfilmresistor | DaleCMF-55C |
| X1 | 20MHzcrystal | thd |
| ZI | 1.2Vvoltagereference | NationalSemiconductorLM385Z-1.2 Note:Thevendornumbersabovearelistedonlyasaguide.Substitutionofdeviceswithsimilarcharac- teristicswillnotaffecttheperformanceoftheBt445. Figure13.TypicalConnectionDiagramandPartsList. 5-54 SECTION5 |

Brookiree’ Bt445
ApplicationsInformation
TestFeaturesoftheBt445
TheBt445containsadedicatedtestregisterandanana- Experiencedusershavedevelopedtablesofspecific
logoutputcomparatorthatassisttheuserinevaluating seedsandpixelstreams,andrecordedthesignatures
theperformanceandfunctionalityofthepart.Thissec- thatresultfromthoseinputsappliedtoknown-good
tionisintendedtoexplaintheoperatingusageofthese parts.Notethatagoodsignaturefromonegivenpixel
testfeatures. streamcanbeusedastheseedforthesucceeding
streamtobetested.Anysignatureisdeterministically
createdfromastartingseed,andthesucceedingpixel
SignatureRegister
streamfedtotheSARs.
Whenenabled,theoutputsignatureregistersoperate Whenperformingsystemteststhatusethesignature
withthe24bitsofdatathatarepresentedtotheDAC analysisregisters,itisrecommendedthatthepipeline
inputs.These24-bitvectorsrepresentasinglepixel- delayberesetpriortothetesttoprovideoptimalallow-
color,andarepresentedasinputssimultaneouslytothe anceforinputclockdrift.Thispreventsthedisruption
red,green,andblueSARs,aswellasthethreeon-chip ofpixeldatabecauseofpipelineauto-reset,whichmay
DACs. occurasthephaserelationoftheinputclockdrifts,
TheSARsactasawidelinearfeedbackshiftregister withrespecttotheoutputclocks.Excessiveinputclock
oneachsucceedingDACinput.Itisimportanttonote driftmayrequirethatsignaturesbeacquiredover
thatinallthemultiplexedmodestheSARsregister shorterperiodswhenthemaximumdriftmaybemore
everypixel. tightlycontrolled.Thisisespeciallyrecommendeddur-
TheBt445willonlygeneratesignatureswhilein ingenvironmentalandpowersupplyvariationtesting.
active-display(BLANK*negated).TheSARsare
availableforreadingandwritingviatheMPUport
AnalogComparator
whentheBt445isinablankingstate(BLANK*
asserted).Specifically,itissafetoaccesstheSARs TheotherdedicatedteststructureintheBt445isthe
aftertheDACoutputsareintheblankingstate(upto analogcomparator.Itallowstheusertomeasurethe
24pixelclockperiodsafterBLANK*isasserted). DACsagainsteachother,aswellasagainstaspecific
Typically,theuserwillwriteaspecific24-bitseed referencevoltage.
valueintotheSARs.Then,aknownpixelstreamwill FourcombinationsoftestsareselectedviatheTest
beinputtothechip,forexample,onescan-lineorone Register.Withagivensetting,therespectivesignals
framebufferofpixels.Then,atthesucceedingblank (DACoutputsorthe145mVreference)willbecontin-
state,theresultant24-bitsignaturecanbereadbythe uouslyinputtothecomparator.Theresultofthecom-
MPU.The24-bitsignatureregisterdataisaresultof paratorislatchedintotheTestRegister.Thecapture
thesamecaptureddatathatisfedtotheDACs.Thus, occursoveroneLD/SCLKIperiodsetbyalogicalone
overlay,cursor,andpalettebypassdatavalidityisalso atpinP31.
testedusingthesignatureregisters. Duetothesimpledesignofthecomparator,itisrec-
Itisnotsimpletodescribealgorithmicallythespe- ommendedthattheDACoutputsbestablefor5Us
cificlinearfeedbackshiftoperationusedintheBt445. beforecapture.Atadisplayrateof100MHz,5uscor-
ThelinearfeedbackconfigurationareshowninFigure respondsto500pixels.Furthermore,eitherthecolor
14. paletteRAMorthepixelinputs(orboth)shouldbe
configuredtoguaranteeasinglecontinuousoutput
fromtheDACsundertest,untilcapture.
WORKSTATIONGRAPHICS 5-55

Bt445 Brooktree’
ApplicationsInformation(continued)
| RO—R7 | G0-G7 | BO-B7 |
| --- | --- | --- |
| +8 | +8 | +8 |
| RED | GREEN | BLUE |
| IN | IN | IN |
| 0123 4 5 6 7 | 0123 45 67 | 0 123 4 5 6 7 Figure14.SignatureAnalysisRegisterCircuit. 5-56 SECTION5 |

Brooktree’ Bt445
ApplicationsInformation(continued)
InitializingtheBt445
Followingtheassertionoftheresetsignal,theBt445pixelunpackinglogicandpixelformattinglogicareinitialized
totheBt4584:1MPXmodeofoperation.SeeTable8.
| ControlRegister | Value | Description |
| --- | --- | --- |
| PixelPortStartPosition | 40 | 4pixels,eachwith8-bitpseudocolorand2-bitoverlay. |
| PixelDepth | 10 | 8-bitpseudocolorand2-bitoverlay. |
| PixelMultiplexRate | 4 | 4:1Multiplexed. |
| Red,Green,BlueShift | $00 | 8-bitpseudo-colorsourcesRed,Green,andBluefromsame fieldstartingfromlow-orderbitofpixel. Red,Green,BlueWidth $08 |
| Red,Green,BlueEnable | $FF | Allplanesused. |
| Red,Green,BlueBlink | $00 | Pixelblinkingdisabled. |
| OverlayShift | $08 | Overlaycomesinonnexthigh-orderpixelsabove8-bit pseudo-colorbits. |
| OverlayWidth | 2 | 2-bitoverlaysupportedinBt458. |
| OverlayEnable | $03 | Bitplanes0and1enabled. |
| OverlayBlink | $00 | Overlayblinkingdisabled. Table8.ResetInitialization. WORKSTATIONGRAPHICS 5-57 |

Bt445
ApplicationsInformation(continued)
ColorPaletteInitialization
Table9showsthesequenceofMPUwritesrequiredtoloadthecolorpaletteentries:
Internal
Address
| Operation | Description | C(2-0) | Register\|MPUData |
| --- | --- | --- | --- |
| ColorPaletteRAMInitialization | Write$00toaddressregister | 000 | - $00 |
| WritereddatatoRAM(location$00) | 001 | $00 | $rr |
| WritegreendatatoRAM(location$00) | 001 | $00 | $gg |
| WritebluedatatoRAM(location$00) | 001 | $00 | $bb |
| WritereddatatoRAM(location$01) | 001 | $01 | $rr |
| WritegreendatatoRAM(location$01) | 001 | $01 | $gg |
| WritebluedatatoRAM(location$01) | 010 | $01 | $bb |
| WritereddatatoRAM(location$FF) | 001 | $FF | Sir |
| WritegreendatatoRAM(location$FF) | 001 | $FF | $gg |
| WritebluedatatoRAM(location$FF) | 001 | $FF | $bb |
| OverlayColorPaletteInitializa- | Write$00toaddressregister | 000 | - $00 |
| tion | WritereddatatooverlayQocation$0) | 011 | $00 Sir |
| Writegreendatatooverlay(location$0) | 011 | $00 | $gg |
| Writebluedatatooverlay(location$0) | 011 | $00 | $bb |
| Writereddatatooverlay(location$1) | 011 | $01 | $ur |
| Writegreendatatooverlay(location$1) | 011 | $01 | Seg |
| Writebluedatatooverlay(location$1) | 011 | $01 | $bb |
| Writereddatatooverlay(location$F) | O11 | SOF | Ser |
| Writegreendatatooverlay(location$F) | 011 | $0F | $gg |
| Writebluedatatooverlay(location$F) | 011 | $OF | $bb |
| CursorPaletteInitialization | Write$00toaddressregister | 000 | - $00 |
| Writereddatatocursor(location$0) | 111 | $00 | $rr |
| Writegreendatatocursor(location$0) | 111 | $00 | $gg |
| Writebluedatatocursor(location$0) | 111 | $00 | $bb |
| Writereddatatocursor(location$1) | 111 | $01 | Ser |
| Writegreendatatocursor(location$1) | 111 | $01 | $gg |
| Writebluedatatocursor(location$1) | iil | $01 | $bb |
| Writereddatatocursor(location$3) | 111 | $03 | $rr |
| Writegreendatatocursor(location$3) | 111 | $03 | $gg |
| Writebluedatatocursor(location$3) | 111 Table9.ColorPaletteInitialization. 5-58 SECTION5 | $03 | $bb |

Brookiree* Bt445
ApplicationsInformation(continued)
PipelineDelayInitialization PLLInitialization
TheBt445employsavariablepipelinedelaytoallow CrystalFrequencySelection
foreasiersystemimplementation.Thisschemeallows
Thecrystalfrequencyshouldbeselectedbasedon
theLD/SCLKIandVIDCLKIsignalstodriftrelativeto
therequiredpixelrate(s),thedisplaypixelratetoler-
thepixelclock(aswouldoccurwithvaryingenviron-
ance,andtherequiredsystemclockoutputs.When
mentalconditionssuchaswarm-upandpowersupply
usingtheBt445-generatedsystemclocks,becausethe
fluctuations)withoutcorruptingtheoutputpixeldata
systemclockratiosarefixed,thecrystalreferencefre-
stream.Theamountofallowabledriftdependsonthe
quencyisusuallydictatedbyrequiredsystemclock
MPXRate;forexample,ina4:1MPXmode,thedrift
rates.ThedesiredratioforthePLLcanthenbecom-
windowisslightlylessthan4pixelclockcycles.This
putedbydividingrequiredthepixelratebythecrystal
comparesfavorablywithfixed-pipelinedelaydevices
frequency,lookinguptheMandNvaluesintheratio
wherethedriftisnecessarilylessthanonepixelclock
tablefortheclosestratio,andensuringthatthedisplay
tothepointofpixellossorduplication.
canstillsatisfactorilyoperatewithinthebest-fitpixel
Foroptimumperformance,thepipelinedepthshould
rateandassociatedCRTtimings.
beinitializedawayfromtheextremesofthedriftwin-
dowtoallowforsubsequentdrift.Thisisaccomplished
RatioSelection
bythetransitionoftheRESET*signalfrom0to1or
undertheMPU’scontrolbythetransitionofthe ThePLLclockratioissetbyprogrammingtheM
RESETPIPELINEfieldinthePixelFormatControl andNvaluesthroughtheMPUport.ResetMandN
Registerfrom0to1.TheMPUshouldresetthepipe- valuesare$18and$04,respectively,yieldingapixel
linewheneveranyofthefollowingregistersorfields rateof5timesthecrystalreference.
arechanged:thePixelPortStartPositionRegister,the Table11showsthecompleterangeofM/Nratiosfor
PixelUnpackingOrderField,theMPXRateRegister, Mrangesfrom25-64andNrangesfrom4-15and L=
thePixelDepthControlRegister,thePLLRateRegis- 1,for20.0and14.318MHzcrystals.
ters,thePixelClockPLLEnableField,TheVCOGain
ControlField,ortheSCLK*Enablefield.
Additionally,whenchanginganycontrolsaffecting
thepixelPLLrateorVCOgain,sufficienttimeshould
beallowedforthePLLtostabilizetothenewrateprior
totheMPUissuingthepipelinedelayinitialization.
Table10illustratestheallowabledriftwindowsfor
LD/SCLKIrelativetothepipelinedepthinitialization
timeforthevariousMPXmodes.
| MPXRate(s) | Minimum | Maximum | Units |
| --- | --- | --- | --- |
| 1:1 | 0 | 0 |  |
| 2:1 | -] | +1 |  |
| 3:1 | -1 | +2 |  |
| 4:1 | -2 PixelClocks | +2 |  |
| 5:1 | 2 | +3 |  |
| 63:1 | -2 | +61 |  |
| 64:1 | -2 | +62 ExternalstoppingoftheCLOCKandCLOCK*signalsisnotrequiredfor pipelinedelayinitialization. Table10.AllowableLD/SCLKIDrift. WORKSTATIONGRAPHICS 5-59 |  |

Bt445 Brooktree’
ApplicationsInformation(continued)
| ReferenceFrequency:20.0 | 14.31818 | ReferenceFrequency:20.0 | 14.31818 |
| --- | --- | --- | --- |
| MIN | M | N | PCLK PCLK VCO MIN M N PCLK PCLK VCO |
| 3.250 | 26 | 8 | 65.00 N/A tbd 3.909 43 1178.18 N/A tbd |
| 3.267 | 49 | 15 | 65.33 N/A tbd 3.917 47 12 78.33 N/A tbd |
| 3.273 | 36 | 11 | 65.45 N/A tbd 3.923 51 13. 78.46 N/A tbd |
| 3.286 | 46 | 14 | 65.71 N/A tbd 3.929 55 1478.57 N/A tbd |
| 3.300 | 33 | 10 | 66.00 N/A tbd 3.933 59 1578.67 N/A tbd |
| 3.308 | 43 | 13 | 66.15 N/A tbd 4.000 28 7~~80.00 N/A tbd |
| 3,333 | 30 | 9 | 66.67 N/A tbd 4.067 61 15 81.33 N/A tbd |
| 3.357 | 47 | 14 | 67.14 N/A tbd 4.071 57 1481.43 N/A tbd |
| 3.364 | 37 | 1 | 67.27 N/A tbd 4.077 53 13. 81.54 N/A tbd |
| 3.375 | 27 | 8 =67.50 | N/A tbd 4.083 49 12 81.67 N/A tbd |
| 3.385 | 44 | 13. | 67.69 N/A tbd 4.091 45 11 81.82 N/A tbd |
| 3.400 | 34 | 10 | 68.00 N/A tbd 4.100 41 10 =82.00 N/A tbd |
| 3.417 | 41 | 12 | 68.33 N/A tbd 4.111 37 9 82.22 N/A tbd |
| 3.429 | 48 | 14.68.57 | N/A thd 4.125 33 8 =82.50 N/A tbd |
| 3.444 | 31 | 9 | 68.89 N/A tbd 4.133 62 15 82.67 N/A tbd |
| 3.455 | 38 | 11 | 69.09 N/A tbd 4.143 29 7 82.86 N/A tbd |
| 3.462 | 45 | 13, | 69.23 N/A tbd 4.154 54 13.83.08 N/A tbd |
| 3.467 | 52 | 15 | 69.33 N/A tbd 4.167 25 6 83.33 N/A tbd |
| 3.500 | 28 | 8 | 70.00 N/A tbd 4.182 46 ll =83.64 N/A tbd |
| 3.533 | 53 | 15 | 70.67 N/A tbd 4.200 42 10 84.00 N/A tbd |
| 3.538 | 46 | 13. | 70.77 N/A tbd 4.214 59 14 84.29 N/A tbd |
| 3.545 | 39 | 11 =70.91 | N/A tbd 4,222 38 9 =84.44 N/A tbd |
| 3.556 | 32 | 9 | 71.11 N/A tbd 4.231 55 13 84.62 N/A tbd |
| 3.571 | 25 | 7 | 71.43 N/A tbd 4.250 34 8 85.00 N/A tbd |
| 3.583 | 43 | 12. | 71.67 N/A tbd 4.267 64 1585.33 N/A tbd |
| 3.600 | 36 | 10=72.00 | N/A tbd 4.273 47 1k 85.45 N/A tbd |
| 3.615 | 47 | 13, | (72.31 N/A tbd 4.286 30 7 85.71 N/A tbd |
| 3.625 | 29 | 8 | 72.50 N/A tbd 4.300 43 10 86.00 N/A tbd |
| 3.636 | 40 | 1100 | 72.73 N/A tbd 4,308 56 13. 86.15 N/A tbd |
| 3.643 | 51 | 14.72.86 | N/A tbd 4.333 26 6 86.67 N/A tbd |
| 3.667 | 33 | 9 =73.33 | N/A tbd 4,357 61 14 87.14 N/A tbd |
| 3.692 | 48 | 13.73.85 | N/A tbd 4.364 48 1187.27 N/A tbd |
| 3.700 | 37 | 10 | =74.00 N/A tbd 4,375 35 8 =87.50 N/A tbd |
| 3.714 | 26 | 7 | 74.29 N/A tbd 4.385 57 13 87.69 N/A tbd |
| 3.727 | 41 | 1174.55 | N/A tbd 4.400 44 10 =88.00 N/A tbd |
| 3.733 | 56 | 1S | (74.67 N/A tbd 4.417 53 12 88.33 N/A tbd |
| 3.750 | 30 | 8 | 75.00 N/A tbd 4.429 31 7~~88.57 N/A tbd |
| 3.769 | 49 | 1375.38 | N/A tbd 4.444 40 9 88.89 N/A tbd |
| 3.778 | 34 | 9 | 75.56 N/A tbd 4.455 49 11 89.09 N/A tbd |
| 3.786 | 53 | 14 | 75.71 N/A tbd 4.462 58 13 89.23 N/A tbd |
| 3.800 | 38 | 10=76.00 | N/A tbd 4.500 27 6 90.00 N/A tbd |
| 3.818 | 42 | il =76.36 | N/A tbd 4.538 59 13 90.77 N/A tbd |
| 3.833 | 46 | 12 | 76.67 N/A tbd 4.545 50 li 90.91 65.08—tbd |
| 3.846 | 50 | 13, | 76.92 N/A tbd 4.556 41 9 O11 65.23 tbd |
| 3.857 | 27 | 7 | 77.14 N/A tbd 4.571 32 7 91.43 65.45—tbd |
| 3.867 | 58 | 15 | 77.33 N/A tbd 4.583 55 12. 91.67 65.62—tbd |
| 3.875 | 31 | 8 =77.50 | N/A tbd 4.600 46 10 92.00 65.86 thd |
| 3.889 | 35 | 9 | 77.78 N/A tbd 4.615 60 130 92.31 66.08 thd |
| 3.900 | 39 | 10=78.00 | N/A tbd 4.625 37 8 92.50 66.22 tbd Table11.SamplePixelClockRates. 5-60 SECTION5 |

Brooktree’ Bt445
ApplicationsInformation(continued)
| ReferenceFrequence:20.0 | 14.31818 | ReferenceFrequency:20.0 | 14.31818 |
| --- | --- | --- | --- |
| MIN | M | N | PCLK PCLK VCO MIN M N PCLK PCLK VCO |
| 4.636 | 31 | Il | 92.73 66.38 thd 5.667 34 6 113.33 81.14 thd |
| 4.667 | 28 | 6 | 93.33 66.82 tbd 5.700 57 10 114.00 81.61 thd |
| 4.692 | 61 | 13.93.85 | 67.19 thd 5.714 40 7 114.29 81.82—tbd |
| 4,700 | 47 | 10 | 94.00 67.30 thd 5.727 63 11 114.55 82.00 thd |
| 4.714 | 33 | T | 94.29 67.50—tbd 5.750 46 8 115.00 82.33 tbd |
| 4,727 | 52 | 11 | 94.55 67.69 thd 5.778 $2 9 115.56 82.73 thd |
| 4.750 | 38 | 8 | 95.00 68.01—tbd 5.800 29 5 116.00 83.05 thd |
| 4.769 | 62 | 13 | 95.38 68.29 thd 5.818 64 11 116.36 83.31 tbd |
| 4.778 | 43 | 9 | 95.56 68.41—tbd 5.833 35 6 116.67 83.52 thd |
| 4.800 | 48 | 10 | 96.00 68.73 tbd 5.857 41 7 117.14 83.86 thd |
| 4.818 | 53 | 11 | 96.36 68.99 thd 5.875 47 8 117.50 84.12 thd |
| 4.833 | 29 | 6 | 96.67 69.20—tbd 5.889 53 9 117.78 84.32 thd |
| 4.846 | 63 | 13 | 96.92 69.39 thd 5.900 59 10 118.00 84.48 thd |
| 4.857 | 34 | 7 | 97.14 69.55 thd 6.000 30 5 120.00 85.91—tbd |
| 4.875 | 39 | 8 | 97.50 69.80 thd 6.100 61 10 122.00 87.34 thd |
| 4.889 | 44 | 9 | 97.78 70.00 =tbd 6.111 55 9 122.22 87.50 thd |
| 4.900 | 49 | 10 | 98.00 70.16—tbd 6.125 49 8 122.50 87.70 tbd |
| 4,909 | 54 | 11 | 98.18 70.29 thd 6.143 43 7 122.86 87.95 tbd |
| 4.917 | 59 | 12 | 98.33 70.40—tbd 6.167 37 6 123.33 88.30 thd |
| 4.923 | 64 | 13 | 98.46 70.49—tbd 6.200 31 5 124.00 88.77—tbd |
| 5.000 | 25 | 5 | 100.00 71.59 tbd 6.222 56 9 124.44 89.09 thd |
| 5.083 | 61 | 12 | 101.67 72.78—tbd 6.250 25 4 125.00 89.49 thd |
| 3.091 | 56 | il | 101.82 72.89 tbd 6.286 44 7 125.71 90.00 thd |
| 5.100 | 51 | 10 | 102.00 73.02 thd 6.300 63 10 126.00 90.20 thd |
| 5.111 | 46 | 9 | 102.22 73.18 thd 6.333 38 6 126.67 90.68 tbd |
| 5.125 | 41 | 8 | 102.50 73.38 tbd 6.375 51 8 127.50 91.28 tbd |
| 5.143 | 36 | 7 | 102.86 73.64 thd 6.400 32 5 128.00 91.64 tbd |
| 5.167 | 31 | 6 | 103.33 73.98 tbd 6.429 45 7 128.57 92.05_tbd |
| 5.182 | 57 | 11 | 103.64 74.19—thd 6.444 58 9 128.89 92.27 thd |
| 3.200 | 26 | 5 | 104.00 74.45 tbd 6.500 26 4 130.00 93.07 tbd |
| 5.222 | 47 | 9 | 104.44 74.77~~thd 6.556 59 9 131.11 93.86 tbd |
| 5.250 | 42 | 8 | 105.00 75.17 thd 6.571 46 7 131.43 94.09 thd |
| 5.273 | 58 | 11 | 105.45 75.50 thd 6.600 33 5 132.00 94.50 thd |
| 5.286 | 37 | 7 | 105.71 75.68—thd 6.625 53 8 132.50 94.86 tbd |
| 5.300 | 53 | 10 | 106.00 75.89 thd 6.667 40 6 133.33 95.45—thd |
| 5.333 | 32 | 6 | 106.67 76.36 thd 6.714 47 7 134.29 96.14 tbd |
| 35.364 | 59 | 11 | 107.27 76.80 thd 6.750 27 4 NIA 96.65 thd |
| 35.375 | 43 | 8 | 107.50 76.96 tbd 6.778 61 9 NIA 97.05 thd |
| 5.400 | 27 | 5 | 108.00 77.32—thd 6.800 34 5 N/A 97.36 thd |
| 5.429 | 38 | 7 | 108.57. 77.73 thd 6.833 4] 6 N/A 97.84 thd |
| 5.444 | 49 | 9 | 108.89 77.95 tbd 6.857 48 7 N/A 98.18—thd |
| 5.455 | 60 | 11 | 109.09 =78.10 thd 6.875 55 8 N/A 98.44 thd |
| 3.500 | 33 | 6 | 110.00 78.75 tbd 6.889 62 9 N/A 98.64 thd |
| 5.545 | 61 | 11 | 110.91 79.40—thd 7.000 28 4 N/A 100.23 thd |
| 5.556 | 50 | 9 | 111.11 79.55 thd 7AM 64 9 N/A 101.82 tbd |
| 3.571 | 39 | 7 | 111.43 79.77 thd 7.125 57 8 N/A 102.02 tbd |
| 5.600 | 28 | 5 | 112.00 80.18—thd 7.143 50 7 N/A 102.27 tbd |
| 5.625 | 45 | 8 | 112.50 80.54 thd 7.167 43 6 N/A 102.61 tbd |
| 3.636 | 62 | 1! | 112.73 80.70 thd 7.200 36 5S NA 103.09 thd Table11(continued).SamplePixelClockRates. WORKSTATIONGRAPHICS 5-61 |

Bt445 Brooktree’*
ApplicationsInformation(continued)
| ReferenceFrequency:20.0 | 14.31818 | ReferenceFrequency:20.0 | 14.31818 |
| --- | --- | --- | --- |
| MIN | M | N | PCLK PCLK VCO MIN M N PCLK PCLK VCO |
| 7.250 | 29 | 4. | NIA 103.81 tbd 8.250 33 4 NIA 118.12 thd |
| 7.286 | 51 | 7 | N/A 104.32 tbd 8.286 58 7 NIA 118.64 thd |
| 7.333 | 44 | 6 | N/A 105.00 tbd 8.333 50 6 NIA 119.32 tbd |
| 7.375 | 59 | 8 | N/A 105.60 tbd 8400 42 5 N/A 120.27 thd |
| 7.400 | 37 | 5 | NIA 105.95 tbd 8.429 59 7 NIA 120.68 thd |
| 7.429 | 52 | 7 | NA 106.36 tbd 8.500 34 4 NA 121.70 thd |
| 7.500 | 30 | 4 | NA 107.39 thd 8.571 60 7 NIA 122.73 thd |
| 7.571 | 53 | 7 | NIA 108.41 tbd 8.600 43 5 NIA 123.14 thd |
| 7.600 | 38 | 5 | N/A 108.82 tbd 8.667 52 6 NA 124.09 thd |
| 7.625 | 61 | 8 | N/A 109.18 thd 8.714 61 7 NA 124.77 thd |
| 7.667 | 46 | 6 | NA 109.77 tbd 8.750 35 4 N/A 125.28 thd |
| 7.714 | 54 | 7 | NA 110.45 tbd 8.800 44 5 NIA 126.00 thd |
| 7.750 | 31 | 4 | N/A 110.97 tbd 8.833 53 6 N/A 126.48 thd |
| 7.800 | 39 | 5 | NA 111.68 thd 8.857 62 7 N/A 126.82 thd |
| 7.833 | 47 | 6 | NA 112.16 tbd 9.000 36 4 NIA 128.86 tbd |
| 7.857 | 55 | 7 | NA 112.50 tbd 9.143 64 7 N/A 130.91 tbd |
| 7.875 | 63 | 8 | N/A 112.76 tbd 9.167 55 6 N/A 131.25 tbd |
| 8.000 | 32 | 4 | NIA 114.55 tbd 9.200 46 5 NIA 131.73 tbd |
| 8.143 | 57 | 7 | NA 116.59 thd 9.250 37 4. NIA 132.44 thd |
| 8.167 | 49 | 6 | NA 116.93 tbd 9.333 56 6 N/A 133.64 thd |
| 8.200 | 41 | 5 | N/A 117.41 thd 9400 47 5 NIA 134.59 tbd Table11(continued).SamplePixelClockRates. Note:AllPixelClockfrequenciesshownarepriortothe“L”dividersection.Allofthelistedfrequenciesmaybe dividedby1,2,4,or8toprovidelowerpixelclockrates. 5-62 SECTION5 |

Brooktree’ Bt445
ApplicationsInformation(continued)
FrameBufferInterfaceConfigurations pixelclock,loadclock,andVRAMserialshiftclock
areexternallygeneratedbyadevicesuchastheBt438
TheBt445maybeoperatedwithaninternalPLLoran
orBt440.Figure15illustratesthisconfiguration.
externalclockgenerator.Additionally,theBt445may
Themultiplexratessupportedarelimitedbythe
beusedtogeneratetheVRAMserialshiftclocksignal,
modesforwhichtheexternalclockdivider(i.e.,the
orthissignalmaybegeneratedexternally.Thefollow-
Bt440inthiscase)canbeconfigured.TheSYNC*and
ingfiguresshowexamplesoftheframebufferinterface
BLANK*informationloadedcorrespondtothepixel
whenusingtheBt445invariousmodes.
dataloadedonthesameLDclockrisingedge.The
maximumpixelclockrateis150MHz.
ExternallyGeneratedPixelClockwithExter-
nallyGeneratedVRAMSerialShiftClock
Inthisconfiguration,neithertheSCLK*norVID-
CLK*outputsoftheBt445areused,andthusthey
shouldbedisabledviathecommandregisters.The
Crystal/
Oscillator
Memory	osc]	{osc	Bt445
Controller	i	t
. >CLK
LOA LDC \0G
108CS
LDbe —p}VIDCLK!
SystemBus
or	—>	Serial
GraphicsPipeline	Controls	Ota	ath!(63-0)
Address
___ Data
p>)SYNC*
—p|BLANK*
Figure15.FrameBufferInterface,ExternalPixelClock,andSerialClockGeneration.
WORKSTATIONGRAPHICS 5-63

Bt445 Brooktree*
ApplicationsInformation(continued)
PLL-GeneratedPixelClockwithExternally referencethatisphaserelatedtothepixelclock.The
GeneratedVRAMShiftClock memorycontrollerproducesaclockgatesignalfor
generatingtheVRAMshiftclockfromVIDCLK*.Fig-
Inthisconfiguration,theBt445generatesthepixel
ure16illustratesthisconfiguration.
clockinternallyfromtheMandNvaluescontainedin
TheinvertingdriversusedtogenerateLD/SCLKI
thecontrolregisters.TheWRAMshiftclockisstill
andtheVRAMshiftclockshouldideallyhavecorre-
externallygenerated,butthesystemmustusethe
lateddelaysandhigh-impedance,lowcapacitance
Bt445'sVIDCLK*output,asthereisnoothersystem
inputs.
Crystal|
4
XTALI XTAL2
y
>LD/SCLKI
|VIDCLK! 1OR—>|}
OG-/—»>
| LDhe | o<} | vipcike SCLKEnable soup Memory I | (OB |
| --- | --- | --- | --- |
| SystemBus | Controller | Bt445 |  |
| or | —, | Serial |  |
| GraphicsPipeline | Controls | Data»!(63-0) hee "\| VRAM ——»\|Frame |  |
| 2 | 2'* | \|Buffer p>!SYNC’ —p\|BLANK* Figure16.FrameBufferInterface,withPLLPixelClockandnoBt445-ProvidedShiftClock. 5-64 SECTION5 |  |

Brooktree* Bt445
ApplicationsInformation(continued)
Bt445-GeneratedVRAMShiftClock,Exter- sameastheMPXrate.Asaresult,thelastgroupofpix-
nally-GeneratedPixelClock elsloadedwithLD/SCLKIattheendofanactivescan
line,maynotallbedisplayed.Itshouldbenotedthatin
Inthisconfiguration,thepixelclockisgeneratedin
thisconfiguration,theSYNC*andBLANK*informa-
anexternaloscillator.TheBt445providestwoclocksto
tiondoesnotcorrelatetothedataontheBt445’spixel
thesystem:VIDCLK*andSCLK*.VIDCLK*is
inputport;however,theBt445internallyalignsthe
alwaysfreerunningandisusedtocontroltheCRTtim-
CRTtimingcontrolswiththepixeldataforoutput.
inggenerator,usuallypartofthecontroller.VIDCLKI
Also,thebufferdelaysforVIDCLK*andSCLK*need
isusedtoregistertheSYNC*,andBLANK*signals.
notbecorrelated.
LD/SCLKIisusedtoregisterthepixeldata.Figure17
TheSCLKcontrolsignalsuppliedbythememory
illustratesthisconfiguration.
controllerisusedonlytoinsertshiftclocksforthepur-
SCLK*isassertedasneededtoshiftoutpixeldata
poseofloadingtheshiftregistertapaddressrequired
fromtheVRAMs,accordingtotheMPXratespecified
byVRAMssupportingsplit-shiftregisteroperations.
byacontrolregister.Generally,VIDCLK*andSCLK*
Thepixelrateinthisconfigurationmaybeupto150
donotrunatthesamerate;hence,thegranularitywith
MHz.
whichSYNC*andBLANK*arespecifiedisnotthe
PixelRate
Oscillator
CLOCK] |CLOCK*
ry
Mid-linexferControl
jtIsc ES
Memory p|LD/SCLKI =[0B-—»
Controller	SCLKi	Bt445
SystemBus
or	+>	Controls	perl
GraphicsPipeline Address "| VRAM
mp(63-0)
=>Frame
ett Buffer
oeVIDCLKI
VIDCLKkq— <<}VIDCLK*
SYNC*
BLANK*
Figure17.FrameBufferInterfacewithExternallyGeneratedPixelClockandBt445-GeneratedSCLK.
WORKSTATIONGRAPHICS 5-65

Bt445 Brooktree’
ApplicationsInformation(continued)
TheBt445-GeneratedVRAMShiftClockand Inthisconfiguration,themaximumpixelrateislim-
PLL-GeneratedPixelClock itedbythePLLmaximumoperationalfrequencyof135
Thisconfigurationisverysimiliartotheprevious MHz.SeeFigure18.
onewithoutthePLLgeneratedpixelclock.Here,arel-
ativelylowfrequencycrystalisconnectedtotheOSC,
OSC*inputs,insteadofusinganECLoscillatoroper-
atedonapseudo-ECLsupply(i.e.,+5andGND)con-
nectedtotheCLOCKandCLOCK*inputsofthe
Bt445.
Crystal|
XTAL1 XTAL2
VY
SCLKControl
| ; | . | IOR +SCLK 1OG |
| --- | --- | --- |
| Memory | LO/SCLKI Ad Controller SCLK SystemBus Bt445 Serial | [OB WH |
| or | —> | Controls Vv Data vP(63-0) GraphicsPipeline VRAM Address VvFrame qe _y\| Buffer VIDCLK! VIDCLKA VIDCLK* SYNC* flBLANK* Figure18.FrameBufferInterfaceforBt445-GeneratedVRAMSerialClockandPixelClock. 5-66 SECTION5 |

Brooktree’ Bt445
ApplicationsInformation(continued)
DigitalOutputPort sentedonthePVSYNC*andPHSYNC*outputs,
respectively.ThisallowsforvariationsbetweenCRT
Figure19showsasimplifiedtypicalconnection
andflat-panelSYNCsignaltimingsanddurations.
betweentheBt445,aCRTdisplay,andatypicalVGA
However,thehorizontallineratesandpixelratesmust
resolutionTFTflat-paneldisplay.TheVSYNC*and
beidenticalifbothdisplaysaretobedrivensimulta-
HSYNC*inputstotheBt445arenotinternallyused;
| : | : | . | neously. theyareonlysynchronizedwiththepixeldataandpre- Generic AnalogMonitor Analog Interface Signals OR oe |
| --- | --- | --- | --- |
| io | id y VIDCLK ¢- 1OB < VRAM Bt445 Memory Controller Array | » |  |
| PCLK | . | vitach a P(63-0) * itachi v ~ Paty TM26D50VC2AA |  |
| CONTROLS4 | < | PVSYNC* | Flat-Panel » TFT |
SCLK
PHSYNC* <
VSYNG*,HSYNC*	OR(3-0)	pe
SYNC’,BLANK*,
OG(3-0) i
v|
OB(3-0) <
. Digital
j Interface
Signals
Crystal
Figure19.TypicalConnectionDiagramforDigitalOutputPortto640x480TFTFlat-PanelDisplay.
WORKSTATIONGRAPHICS 5-67

Bt445 Brooktree’
ApplicationsInformation(continued)
InterfacingtoHigh-ResolutionFlat- matrixpanel.However,toprovide2pixelsathalfthe
clockrate,someinterveninglogicmaybeused.Refer
PanelDisplays
toFigure20.
Preliminaryinformationsuggeststhathigh-resolution Forproperoperation,thecontrolsignalsPBLANK*,
flat-paneldisplayswillachievetherequiredpixelrates PVSYNC*,andPHSYNC*shouldonlychangeonan
withoutusingexcessiveclockspeedsifmorethan1 evenpixel.Thesamplefogicshownresetsthegener-
pixelperclockcycleisprovided,inthesamefashion atedclockandpixeldataoneachedgeofPBLANK*.
thathigh-resolutionBrooktreeRAMDACsacceptpix- Alsonotethattheclock-to-Qdelayontheflip-fiop,
elsattheinputpixelport.TheBt445'sdigitaloutput whichgeneratesLDClocktothepanel,shouldbe
portmayoperateupto55MHz,providingtheband- fasterthantheclock-to-Qdelayofthepixeldataregis-
widthrequired,forexample,fora1024x768active ters.
Bt445
| PCLK | PBLANK* | PVSYNC*PHSYNC* | OR | OG | OB |
| --- | --- | --- | --- | --- | --- |
| 3210 | 3210 | 3210 |  |  |  |
| RED’ | GREEN | BLUE |  |  |  |
| RED | GREEN 321032103210 321032103210 FETTTtTttttti PETtTttTrrtttil o0DDDDODDODODDD DDDODOODDDODDDB | BLUE | RED | GREEN | BLUE |
| > | EvenPixelRegister [Teseeaceacacceas eaacaaaaacaae | 6h | > | OddPixetRegister | 6 |
321032103210
| RED | GREEN | BLUE |
| --- | --- | --- |
| ED | GREEN D @d D Qa | BLUE |
| a12 | GREEN | @LUE RED GREEN BLUE |
| 3 | or)032103 10 | 321032103210 |
| _— | \| LN—LITTLITTY Ba\| \| | TTITITTTTitt |
| LOClock | BLANK’VSYNC*HSYNC* | PA(RGB)(3-0) PB(RGB)(3-0) 1024x768TFTActiveMatrix Figure20.InterfacingtheBt445witha1024x768TFTActiveMatrixFlatPanel. 5-68 SECTION5 |

Brooktree’ Bt445
ApplicationsInformation(continued)
DigitalOutputConnectionin8-8-8
True-ColorMode
Figure21showsasimplifiedtypicalconnectiondia- level.Theconfigurationshownassumesthattheexter-
gramusing8-8-8true-colormode,toaBt858video nalCRTtiminggeneratorprovidestheappropriate
encoder. SYNC*andBLANK*signalsattheinputoftheBt445
Theregistersareusedtoholdthedatapresentedin forrunningtheBt858inmastermode0.ThePCLK
thefirsthalfofthePCLKcycle;datapresentedduring mayneedtobere-drivenand/ordelayedtominimize
thesecondhalfofthePCLKcycleisheldinthetrans- PCLKloadingandtomeetholdtimerequirementsof
parentlatches,whichareopenduringtheclockhigh theBt858.
| PCLKPBLANK*PVSYNC*PHSYNC* | OR I LLL | 0G | 08 | \| |
| --- | --- | --- | --- | --- |
| 3210 | 3210 | bererers\| 3210 3.2140 3210 32140 iy=o n ° oboDOoOODBDBODD ic] OctalLatch aaaacagag DDDDOODDD DDDDDDODD >OctalRegister [>OctalRegister eaqagaaaaa eaaacaaacaa Lt] LIit |  |  |
| 7654 | 9210 | 7654 | 3210 |  |
| 7 | TESHeS21 | 76543270 |  |  |
| CLOCK_IN SLANK*VSYNC*HSYNC* | Red | Green Bt858 Figure21.InterfacingtheBt445totheBt858. WORKSTATIONGRAPHICS 5-69 | Biue | \| |

Bt445
Brooktree’
RecommendedOperatingConditions
| Parameter | Symbol | Min | Typ | Max | Units |
| --- | --- | --- | --- | --- | --- |
| PowerSupply | VAA | 4.75 | 5.00 | 5.25 | v |
| AmbientOperatingTemperature | TA | 0 | +70 | °C |  |
| OutputLoad | RL | 37.5 | Q |  |  |
| ReferenceVoltage | VREF | 1.20 | 1.235 | 1,26 | Vv |
| FSADJUSTResistor | RSET | 523 | Q |  |  |
| JunctionTemperature | Tjmax AbsoluteMaximumRatings | +125 | cc |  |  |
| Parameter | Symbol | Min | Typ | Max | Units |
| VAA(measuredtoGND) | 7.0 | Vv |  |  |  |
| VoltageonanySignalPin(Note1) | GND-O.5 0.5 AnalogOutputShortCircuit DurationtoanyPowerSupply | VAA+ | v |  |  |
| orCommon | ISC | indefinite |  |  |  |
| AmbientOperatingTemperature | TA | -55 | : | °C |  |
| StorageTemperature | TS | -65 | +125 | °C |  |
| JunctionTemperature | TJ | +150 CeramicPackage Cc |  |  |  |
| PlasticPackage | +175 +150 | °C |  |  |  |
| SolderingTemperature | TSOL (5seconds,1/4"frompin) 260 | °C |  |  |  |
| VaporPhaseSoldering(1minute) | TVSOL Stressesabovethoselistedunder“AbsoluteMaximumRatings”maycausepermanentdamagetothedevice.Thisisastressrating onlyandfunctionaloperationofthedeviceattheseoranyotherconditionsabovethoselistedintheoperationalsectionsofthis specificationisnotimplied.Exposuretoabsolutemaximumratingconditionsforextendedperiodsmayaffectdevicereliability. Note1:Thisdeviceemployshigh-impedanceCMOSdeviceonallsignalpins.ItshouldbehandledasanESD-sensitivedevice. Voltageonanysigna]pinthatexceedsthepowersupplyvoltagebymorethan+0.5Vcaninducedestructivelatchup. 5-70 SECTION5 | Cc |  |  |  |

Brooktree’ Bt445
DCCharacteristics
| Parameter | Symbol AnalogOutputs | Min | Typ | Max | Units |
| --- | --- | --- | --- | --- | --- |
| Resolution(eachDAC) | 8 | 8 | 8 | Bits Accuracy(eachDAC) |  |
| IntegralLinearityError | IL | +1 | LSB |  |  |
| DifferentialLinearityError | DL | +1 | LSB |  |  |
| Gray-ScaleError | +5 | %Gray |  |  |  |
| Monotonicity | guaranteed Coding Binary DigitalInputs(exceptCLOCK,CLOCK*,VIDCLKI,and LD/SCLK]) | Scale |  |  |  |
| InputHighVoltage | VIH | 2.0 | VAA+0.5 | Vv |  |
| InputLowVoltage | VIL | GND-0.5 | 0.8 | Vv |  |
| InputHighCurrent(Vin=2.4V) | TlH | 1 | pA |  |  |
| InputLowCurrent(Vin=0.4V) | TL | -l | HA |  |  |
| InputCapacitance | CIN (f=1MHz,Vin=2.4V) DigitalInputswithInternalPullups(PixelInputsand JTAGPins) | 4 | 10 | pF |  |
| InputHighVoltage | VIH | 2.0 | VAA+0.5 | Vv |  |
| InputLowVoltage | VIL | GND-O.5 | 0.8 | Vv |  |
| InputHighCurrent(Vin=2.4V) | TlH | 60 | pA |  |  |
| InputLowCurrent(Vin=0.4V) | HL | -60 | HA |  |  |
| InputCapacitance | CIN (f=1MHz,Vin=2.4V) . PixelClockInputs(CLOCK,CLOCK*) | 4 | 10 | pF |  |
| InputHighVoltage | VKIH | VAA-1.0 | VAA+0.5 | Vv |  |
| InputLowVoltage | VKIL | GND-0.5 | VAA-1.6 | Vv |  |
| InputHighCurrent(Vin=4.0V) | IKIH | 1 | pA |  |  |
| InputLowCurrent(Vin=0.4V) | IKIL | -l | pA |  |  |
| InputCapacitance | CKIN (f=1MHz,Vin=4.0V) ClockInputs(VIDCLKI,LD/SCLKI) | 4 | 10 | pF |  |
| Positivegoingthreshold | VT+ | 1.7 | Vv |  |  |
| Negativegoingthreshold | VT- | 0.9 | Vv |  |  |
| Hysteresis | Wry-VT-) | 0.8 | Vv |  |  |
| InputHighCurrent(Vin=2.4V) | Tih | 1 | pA |  |  |
| InputLowCurrent(Vin=0.4V) | lil | -l | pA |  |  |
| InputCapacitance | Cin (f=1MHz,Vin=4.0V) DigitalOutputs(exceptD(7-0),PCLK,VIDCLK*, SCLK*) | 4 | 10 | pF |  |
| OutputHighCurrent(Voh=2.4V) | Toh | 1 | mA |  |  |
| OutputLowCurrent(Vol=0.4V) | Tol | 1 | mA |  |  |
| Three-stateCurrent | loz | 10 | pA |  |  |
| LoadCapacitance(includesboardwiring | cl andcapacitanceatbufferinput) Seetestconditionsonthenextpage. WORKSTATIONGRAPHICS 5-71 | 10 | pF |  |  |

Bt445 Brooktree’
DCCharacteristics(continued)
| Parameter | Symbol DigitalOutputswithInternalPullups(exceptD(7-0), VIDCLK*,SCLK*) | Min | Typ | Max | Units |
| --- | --- | --- | --- | --- | --- |
| OutputHighCurrent(Voh=2.4V) | Ioh | 1 | mA |  |  |
| OutputLowCurrent(Vol=0.4V) | Tol | 1 | mA |  |  |
| Three-stateCurrent | loz | 60 | pA |  |  |
| LoadCapacitance(includesboardwiring | cl andcapacitanceatbufferinput) DigitalOutputs(VIDCLK*,SCLK*) | 10 | pF |  |  |
| OutputHighCurrent(Voh=2.4V) | Toh | I | mA |  |  |
| OutputLowCurrent(Vol=0.4V) | Tol | 1 | mA |  |  |
| Three-stateCurrent | loz | 10 | pA |  |  |
| LoadCapacitance(includesboardwiring | Ci andcapacitanceatbufferinput) DigitalOutputs(PCLK) | 20 | pF |  |  |
| OutputHighCurrent(Voh=2.4V) | Toh | 1 | mA |  |  |
| OutputLowCurrent(Vol=0.4V) | Tol | 1 | mA |  |  |
| Three-stateCurrent | loz | 60 | pA |  |  |
| LoadCapacitance(includesboardwiring | Cl andcapacitanceatbufferinput) DigitalOutputs(D(7-0)) | 20 | pF |  |  |
| OutputHighVoltage | VOH (IOH=-800pA) | 2.4 | v |  |  |
| OutputLowVoltage | VOL | r =0.4 (IOL=6.4mA) | Vv |  |  |
| Three-stateCurrent | 10Z | 10 | pA |  |  |
| OutputCapacitance | CDOUT AnalogOutputs OutputCurrent | 10 | pF |  |  |
| WhiteLevelRelativetoBlank | 17.69 | 19.05 | 20.40 | mA |  |
| WhiteLevelRelativetoBlack | 16.74 | 17.62 | 18.50 | mA |  |
| BlackLevelRelativetoBlank | 0.95 | 1.44 | 1,90 | mA |  |
| BlankLevelonIOR,IOB | 0 | 5 | 50 | pA |  |
| BlankLevelonIOG | 6.29 | 7.62 | 8.96 | mA |  |
| SyncLevelonIOG | 0 | 5 | 50 | pA |  |
| LSBSize | 69.1 | pA |  |  |  |
| DAC-to-DACMatching | 2 | 5 | % |  |  |
| OutputCompliance | VOC | -1.0 | +12 | Vv |  |
| OutputImpedance | RAOUT | 50 | kQ |  |  |
| OutputCapacitance | CAOUT (f=1MHz,IOUT=0mA) | 13 | 20 | pF |  |
| VoltageReferenceInputCurrent | TREF | 10 | pA |  |  |
| PowerSupplyRejectionRatio | PSRR (COMP=0.1pF,f=1kHz) VAA Testconditions(unlessotherwisespecified):“RecommendedOperatingConditions”withRSET=523Q,VREF=1.235V.Asthe aboveparametersareguaranteedoverthefulltemperaturerange,temperaturecoefficientsarenotspecifiedorrequired. 5-72 SECTION5 | 0.5 | Fol% |  |  |

Brooktree’ Bt445
ACCharacteristics
InputClock
| 150MHzDevices | 135MHzDevices Parameter Symbol\|Min\|Typ\|Max\|Min\|Typ\|Max\|Min\|Typ\|Max\|Units | 110MHzDevices |
| --- | --- | --- |
| ClockRate | Fmax | 150 135 110 MHz |
| ClockCycleTime | 12 | 6.7 74 9.09 ns |
| ClockPulseWidthHigh | 13 | 2.7 3 4 ns |
| ClockPulseWidthLow | 14 | 2.7 3 4 ns MPUPort |
| 150MHzDevices | 135MHzDevices Parameter Symbol\|Min\|Typ\|Max\|Min\|Typ\|Max\|Min\|Typ\|Max\|Units | 110MHzDevices |
| R/W,CO,C1Setup | 1 | 0 0 0 ns |
| R/W,CO,C1Hold | 2 | 15 15 15 ns |
| CE*LowTime | 3 | 50 50 50 ns |
| CE*HighTime | 4 | 25 25 25 ns |
| CE*JtoDataDriven | 5 | 7 7 7 ns |
| CE*JtoDataValid | 6 | 75 75 75 ns |
| CE*TtoDataThree-Stated | 7 | 15 15 15 ns |
| WriteDataSetupTime | 8(Note1) | 35 35 35 ns |
| WriteDataHoldTime | 9 | 3 3 3. ns Note/:Theparametershownguaranteeswritedatacapture.Topreventunnecessarypixeldisturbanceswhenwritingcontrolregis- ters,thewritedatashouldbevalidthroughouttheCE*activeduration. InputPixel |
| 150MHzDevices | 135MHzDevices Parameter Symbol\|Min\|Typ\|Max;Min\|Typ\|Max\|Min\|Typ\|Max\|Units | 110MHzDevices |
| LD/SCLKI | LDmax | 75 75 75 MHz |
| PixelandControlSetup | 10 | 3 3 3 ns |
| PixelandControlHold | 11 | 2 2 2 ns WORKSTATIONGRAPHICS 5-73 |

Bt445 Brooktree’
ACCharacteristics(continued)
VIDCLKI
| 150MHzDevices | 135MHzDevices Parameter Symbol\|Min\|Typ\|Max\|Min\|Typ\|Max\|Min\|Typ\|Max\|Units | 110MHzDevices |
| --- | --- | --- |
| VIDCLKICycleTime | 15 | 13.3 13.3 13.3 ns |
| VIDCLKIPulseWidthHigh | 16 | 5.32 5.32 5.32 ns |
| VIDCLKIPulseWidthLow | 17 | 5.32 5.32 5.32 ns BLANK*,HSYNC*/SYNC*, VSYNC*Setup BLANK*,HSYNC*/SYNC*, VSYNC*Hold AnalogOutput |
| 150MHzDevices | 135MHzDevices Parameter Symbol\|Min\|Typ\|Max\|Min\|Typ\|Max\|Min\|Typ\|Max\|Units | 110MHzDevices |
| AnalogOutputDelay | 18 | TBD TBD 20 ns |
| AnalogOutputRise/Fall | 19 | 2 2 2 ns |
| AnalogOutputSettling(Note1) | 20 | 8 8 8 ns |
| TTLOutputSkew | 21 | TBD TBD TBD ns |
| Clock/DataFeedthrough(Note2) | 35 | 35 1 35 pY-sec |
| GlitchImpulse(Note3) | 50 | 50 50 pV-sec |
| AnalogOutputSkew(Note4) | 0 | 2 0 2 0 2 ns |
| PipelineDelay | TBD | TBD\|TBD TBD 6 10 Clocks |
| VAASupplyCurrent(Note5) | IAA | TBD TBD TBD mA Testconditions(unlessotherwisespecified):“RecommendedOperatingConditions"withRSET=523Q,VREF=1.235V.TTL inputvaluesare0-3V,withinputrise/falltimes<3ns,measuredbetweenthe10percentand90percentpoints.ECLinputvalues areVAA~0.8toVAA—1.8V,withinputrise/falltimes<2ns,measuredbetweenthe20percentand80percentpoints.Timing referencepointsat50percentforinputsandoutputs.Analogoutputload<10pF,DO-D7outputload<40pF.Seetimingnotesin Figures22-26.Astheaboveparametersareguaranteedoverthefulltemperaturerange,temperaturecoefficientsarenotspecified orrequired. Note1:Outputsettlingtimemeasuredfrom50percentpointoffull-scaletransitiontooutputsettlingwithin+1LSB. Note2:Clockanddatafeedthroughisafunctionoftheamountofedgerates,overshoot,andundershootonthedigitalinputs.For thistest,theTTLdigitalinputshavea1kQresistortoGNDandaredrivenby74HClogic.Settlingtimedoesnotinclude clockanddatafeedthrough. Note3:Glitchimpulseincludesclockanddatafeedthrough,—3dBtestbandwidth=2xclockrate. Note4:Outputdelaytimemeasuredfrom50percentpointoftherisingclockedgeto50percentpointoffull-scaletransition. Note5:AtFmax.IAA(typ)atVAA=5.0V,TA=20°C.IAA(max)atVAA=5.25V,TA=0°C. 5-74 SECTION5 |

Brooktree’ Bt445
ACCharacteristics(continued)
SystemClockGenerationACTimingParameters
| Parameter | Symbol | Min | Typ | Max | Units |
| --- | --- | --- | --- | --- | --- |
| VAAvalidtoVIDCLKstable | tbd | ns |  |  |  |
| VAAvalidtoCPUCLKstable | tbd | ns |  |  |  |
| VAAvalidtoMCLKstable | tbd | ns |  |  |  |
| RESET*activepulsewidth | 33 | tbd | ns |  |  |
| SO,$1toRESET*setuptime | 34 | tbd | ns |  |  |
| SO,S1toRESET*holdtime | 35 | tbd | ns |  |  |
| CE*risetonewVIDCLKrate | 36 | tbd | tbd | ns |  |
| CE?risetonewCPUCLKrate | 37 | thd | thd | ns |  |
| SO,S1tonewCPUCLKrate | 38 | tbd | ns |  |  |
| RESET*tonewCPUCLKrate | 39 | tbd | ns |  |  |
| CPUCLK | Fmax | 50 | MHz |  |  |
| MCLK20 | Fmax | 20 | MHz |  |  |
| MCLK25 | Fmax | 25 | MHz |  |  |
| CPUCLK,MCLK20,MCLK25rise/falltime | 5 | ns |  |  |  |
| CPUCLK,MCLK20,MCLK25dutycycle | 40 | 50 - CPUCLK,MCLK20,MCLK25Jitter tbd PLLClockGenerationTimingParameters | 60 | % |  |
| Parameter | Symbol | Min | Typ | Max | Units |
| Crystal/OscillatorFrequency | 6 | 20 | 25 | MHz |  |
| PLLClockGeneratorMultiplicand | M | 25 | 63 |  |  |
| PLLClockGeneratorDivisor | N | 4 | 15 |  |  |
| PLLM/NRatio | tbd | tbd |  |  |  |
| PLLM/NGeneratedPixelClockRate | 65 | 135 | MHz |  |  |
| PLLM/NGeneratedPixelClockAccuracy | tbd PLLM/NGeneratedPixelClockJitter tbd Aboveparametersapplytopredivided(i.e.,beforeapplying1/L)pixelclockgeneration. WORKSTATIONGRAPHICS 5—75 | tbd | % |  |  |

Bt44s Brooktree’
ACCharacteristics(continued)
LD/SCLKI
foneN\	fo}	Vib,min
P(63-0)	\ccetvetesttttteteteneteeey/Rs	ceeetteees	Vi,max
Figure22.InputPixelTiming.
10> ¢—_—17—_»-—-16—_»
VIDCLKI
tip
BLANK*,VSYNC’, Vih,min
HSYNC*/SYNC* Vil,max
Figure23.InputControlTiming.
5-76 SECTION5

Brooktree’ Bt4d45
ACCharacteristics(continued)
18 20
TOR,10G,IOB
—| 19
v2
CLOCK
Figure24.VideoOutputTiming.
RD,C(2-0)
CE*
D(7-0),WRITE
D(7-0),READ
Figure25.MPURead/WriteTiming.
WORKSTATIONGRAPHICS 5-77

Bt445 Brooktree*
ACCharacteristics(continued)
37
Vv
CE*	\	_/
VIDCLK* \___/
CPUCLK
$1,0
33
RESET*	\	/
Figure26.Reset,CPUClock,andVIDCLK*OutputTiming.
5-78 SECTION5

Brooktree’ Bt445
ACCharacteristics(continued)
DigitalPixelOutputPortACTimingParameters
| Parameter | Symbol | Min | Typ | Max | Units |
| --- | --- | --- | --- | --- | --- |
| PCLKCycleTime(Note1) | 40 4-4-4Mode 18.2 8-8-8Mode 36.4 | ns |  |  |  |
| PCLKEdgetoData,ControlDelay | 41 | 15 | ns |  |  |
| PCLKEdgetoData,ControlHold | 42 | 10 | ns |  |  |
| PCLKPulseHighDutyCycle | 43 | 40 | 60 | % |  |
| PCLKVIDCLK*,SCLK*rise/falltime | 3 | ns |  |  |  |
| PSYNC*,PBLANK*,PVSYNC*,PHSYNC*rise/falltime | 7 | ns |  |  |  |
| O(R,G,B)3—0)cycletime | 36.4 | ns |  |  |  |
| O(R,G,B)(3-)rise/falltime | 5 | ns Note1:ThecycletimeparametersapplyonlywhenthePCLKoutputisenabled.SeeFigure27. 43 40 A A <>4 |  |  |  |
| OR(3-0), | . OB(3-0) \| . 4200 42 > PSYNC*,PBLANK’*, PHSYNC’*,PVSYNC* Figure27.PixelOutputPortTimings. WORKSTATIONGRAPHICS 5-79 | — |  |  |  |

Bt445
OrderingInformation
Speed Ambient
| ModelNumber | pee | Package | Temperature (MHz) R ange |
| --- | --- | --- | --- |
| Bt44SKPF150 | 150 | 160-pinPlastic QuadFlatpack | 0°to+70°C |
| Bt445KPF135 | 135 | 160-pinPlastic QuadFlatpack | 0°to+70°C |
| Bt44SKPF110 | 110 | 160-pinPlastic QuadFlatpack 5-80 SECTION5 | 0°to+70°C |
