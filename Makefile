# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 18:12:38 by tkhemniw          #+#    #+#              #
#    Updated: 2022/10/16 23:44:56 by tkhemniw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Defaults
NAME				= push_swap
CHECKER_NAME		= checker
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
RM					= /bin/rm -f

#Directories
INCS_DIR			= ./includes
PRINTF_DIR			= ./libs/ft_printf
SRC_DIR				= ./srcs
PUSH_SWAP_DIR		= $(SRC_DIR)/push_swap
UTIL_DIR			= $(SRC_DIR)/utils
INSTR_DIR			= $(SRC_DIR)/instrs
SORTING_DIR			= $(SRC_DIR)/sorting
CHECKER_DIR			= $(SRC_DIR)/checker

#Includes
INCLUDES 			= -I $(INCS_DIR)									\
					  -I $(PRINTF_DIR)/includes

#Libraries
LIBS				= -L $(PRINTF_DIR) -lftprintf

#Source files
SRCS				= $(PUSH_SWAP_DIR)/push_swap.c						\
					  $(UTIL_SRCS)										\
					  $(INSTR_SRCS)										\
					  $(SORTING_SRCS)									\
					  $(CHECKER_SRCS)
UTIL_SRCS			= $(UTIL_DIR)/initiation.c							\
					  $(UTIL_DIR)/dlst_instrs.c							\
					  $(UTIL_DIR)/dlst_utils.c							\
					  $(UTIL_DIR)/utils1.c								\
					  $(UTIL_DIR)/utils2.c								\
					  $(UTIL_DIR)/utils3.c
INSTR_SRCS			= $(INSTR_DIR)/swap.c								\
					  $(INSTR_DIR)/push.c								\
					  $(INSTR_DIR)/rotate.c								\
					  $(INSTR_DIR)/rrotate.c
SORTING_SRCS		= $(SORTING_DIR)/selection_sort.c					\
					  $(SORTING_DIR)/lazy_sort1.c						\
					  $(SORTING_DIR)/lazy_sort2.c						\
					  $(SORTING_DIR)/partition.c						\
					  $(SORTING_DIR)/3val_sort.c						\
					  $(SORTING_DIR)/2val_sort.c						\
					  $(SORTING_DIR)/4val_sort.c						\
					  $(SORTING_DIR)/5val_sort.c
CHECKER_SRCS		= $(CHECKER_DIR)/checker.c

#Object files 
OBJS 				= $(SRCS:%.c=%.o)
CHECKER_OBJS 		= $(CHECKER_SRCS:%.c=%.o)

#Build Directories
BUILD_DIR			= build
CHECKER_BUILD_DIR	= checker_build

#Command

#Make defaults
all:				$(NAME)

#Make ./Push_swap
$(NAME):			$(OBJS) libs
						$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

#Bonus
bonus: 				checker

#Make ./checker
checker:			$(CHECKER_NAME)

$(CHECKER_NAME): 		$(CHECKER_OBJS) libs
						$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBS) -o $(CHECKER_NAME)

#Make .a
libs:
					make -C $(PRINTF_DIR)

#.c to .o
.c.o:
					$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ -c

#Cleaner
clean:
					make clean -C $(PRINTF_DIR)
					$(RM) -r $(OBJS) $(CHECKER_OBJS)

fclean:				clean
					make fclean -C $(PRINTF_DIR)
					$(RM) $(NAME)

#Restart
re:					fclean all

code:				
					code $(SRCS)

vis500:
					python3 pyviz.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`

vis100:
					python3 pyviz.py `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`

vis10:
					python3 pyviz.py `ruby -e "puts (-5..4).to_a.shuffle.join(' ')"`

vis20:
					python3 pyviz.py `ruby -e "puts (-10..9).to_a.shuffle.join(' ')"`

vis30:
					python3 pyviz.py `ruby -e "puts (-15..14).to_a.shuffle.join(' ')"`

visdebug:
					python3 pyviz.py -240706169 -375137015 805987519 1230381172 -439605799 617240476 -681414670 -1229217619 1083942226 -643012666 708022593 -230283810 1823162325 -1659658210 630491275\
					-272168747 -374662753 210748721 -745655012 1055996491 2064933147 -1770231811 1392662442 -1313846408\
					-1279887578 -1136399861 1489938715 585185906 -1345217944 -2026664509

visdebug.1:
					python3 pyviz.py 15 12 22 25 11 19 9 6 24 10 21 16 28 2 20 14 13 17 8 23 29 1 26 4 5 7 27 18 3 0

debug:				
					./push_swap -240706169 -375137015 805987519 1230381172 -439605799 617240476 -681414670 -1229217619 1083942226 -643012666 708022593 -230283810 1823162325 -1659658210 630491275\
					-272168747 -374662753 210748721 -745655012 1055996491 2064933147 -1770231811 1392662442 -1313846408\
					-1279887578 -1136399861 1489938715 585185906 -1345217944 -2026664509

debug.1:			
					./push_swap 15 12 22 25 11 19 9 6 24 10 21 16 28 2 20 14 13 17 8 23 29 1 26 4 5 7 27 18 3 0

visdebug1:	
					python3 pyviz.py -910375298 817741925 2138566939 -556486725 -1431765026 -1659009032 -1849024900 1612425369 855082774 -1102445910 1252863585 1910913755 -1723960613 -1742448880 -568129393 -330302341 -902663281 1675445994 205112379 2100070334 -1183564024 -1815555903 172942756 89281669 1929994194 -2044232193 1110013756 -1222266199 81293019 -1151812011 463299215 1230506501 659366188 -1479808451 1402839318 -369327809 1207211640 -1314210719 -1176725813 -762556368 1718909099 1306635606 -858096035 -552700770 408715114 265837516 499846213 212223875 1899348118 -478571857 -1318880376 -674234968 690589317 1845376411 -1827665966 -1084027822 -420727890 1767894662 -894200694 -547760915 721738370 20128935 1719266153 1379811391 -1434373349 119751763 -1265240078 -393146814 -508044336 -1126642440 713642340 1957245859 486800162 -602433034 -842410464 -661474919 1322222416 -2133371247 -1613914643 -1219125354 941931974 -97887622 -1344022421 -1600766673 353101970 -195578026 -1902571143 -1992294524 122770073 -1250263208 152881397 2032399324 1069157474 -1793337789 903271942 1949217292 -89204480 1368073101 -1154709238 1388324425 -1030381480 -294626667 782263101 -1722537657 -1222722800 183924905 -1018305655 1929125858 -1951412621 494786090 785940262 -1341435866 576889629 -379135156 260292089 -1991955257 1965534835 -1796101894 1274319034 -773012777 -492325328 202012054 -805051048 -741708603 -723054448 1933291100 -241383319 1282630365 1778066326 -2024320738 -1294611817 1685111091 1403914723 1207450817 -1476651064 -313985770 1196575841 474063612 -950427362 -744710182 1297401393 -1795195804 -234926377 -2025207398 -1994900439 -1173604642 -1624989364 -654413589 2008649062 -550844617 1319168150 -204025871 1055046867 -628797067 -1583215331 637902316 1976789189 -873451030 -956847622 2039589602 -1560631757 -725449350 -1565461524 1688657356 1929050969 -521736476 1879750435 32278796 -459816390 440166800 -1954442443 631428921 2081168293 -383194801 -1767243049 2032210574 482825685 -1668831301 1355429765 53808509 1611876996 -81862298 -1821248505 -1748797475 543253160 -1660646090 761056482 -210535911 -1490081226 -1442365030 371391323 -1310211447 275293196 863842505 -465160302 -861731329 -1370864081 -843396013 981029824 -1581744665 -776941878 -2007226171 198742674 1862294493 2129073448 517116702 872852968 -1938020195 606128978 460679446 1426897192 -1956906605 -688575794 51590918 904473687 660452502 2107558323 1805717677 -598373670 1315443956 -1953886492 1640537844 -1393744571 1726588026 493276984 1251879133 1316561521 -2128286077 52925544 380698351 1095277581 -1360322150 1256402300 -1395641467 -816073944 1617050426 -1981139428 318862754 1519994384 1892618244 417751276 -1511578005 268080039 1447145511 273853260 -2096876178 -1784699594 1340566971 1573937652 1530964491 458640890 972675675 2015874536 1418585200 1144498956 136306358 1202323161 1997445801 1618298649 -1653628316 1556944468 -1229474883 -1631012975 1123043008 -396805671 -1712533967 -494448559 783823002 800628254 365203168 -570792470 1852322453 81496247 756832338 -386312904 -1679162158 -413584526 558168715 -1820188401 -1965555008 882424834 1399541540 -1206359811 1198334108 -19648586 -1720244564 1837422792 -1754869697 477263911 -241332608 109721293 2070734521 543695314 -1851775333 1055138073 -1913487025 756989435 -2075961617 1964909636 -495805913 204686751 384035586 1924091092 153292411 -2105503639 1711024068 963391503 -1573388653 1807199721 -764130605 -1276926550 692157157 978875456 -337806927 482436530 613196717 746441666 -993554833 -1521182583 1274033606 1855298363 45971394 824196646 -1950431276 -1352518372 -1881820590 -1345768341 -1651491348 -1408577137 -426550128 1875114391 -1343488597 817336006 -599007813 -2119403544 -400488094 -1301860925 -368387586 478523574 878865384 -752551931 -475355200 -681872738 -1832452560 -1883341823 819441210 -119977445 -319613770 -1100422062 -330557026 1956107682 485703740 -1868763974 1439870799 1873987588 753987232 1624082339 -602852276 -681172595 -212068803 -1278077381 -967718658 -83839074 1200241635 1674917538 -1477918334 655416689 2051301853 -1805019722 -1085047669 1719468270 1981386203 1529739008 1978391766 -982898447 88965346 -58445097 -406748962 -514481807 872868665 -1540356687 97771246 2079070200 1410688034 2079703332 -908189247 2095325908 -455872971 1716766118 732676820 1032717418 383179127 -522233905 251856248 -2119823098 556211910 -818382993 -325709815 -1398365242 -2080739238 -1147064420 967369218 -358594846 -1457603603 -1033173204 -710495435 444398321 -1138271424 -484371222 801688409 1923147016 660020755 -254182271 2116183288 377198138 -614319474 -1750795409 -582487784 -981206469 -874775971 -1094011391 -1303142716 -1309265540 -824053144 -361386002 -606126381 655191804 -1410081317 1563230572 2075971393 542389571 1084711713 250127066 2044279583 -1124255883 1836471432 1577340160 -1539174171 1719942274 100757672 69939886 -170344954 1690925361 1382671580 -1319986475 1919381805 1318456552 -852587728 1383719422 -396525320 1793755838 1259851258 -1391937162 -889797768 -1649291217 1924789473 1812020937 446009687 -1223846330 2091840831 -1322551606 1950439968 1467127505 1680509799 1878228186 -1011461046 -948799553 49182094 559323837 1334674623 -117740296 -297287523 1438847925 -1689694806 1225108502 -94638077 600485936 -1058111803 -512257335 -795782936 -1637710010 -1466471672 -721661712 1460944973 1064021434 101734178 -977420604 1173356677 161711757 -810227597 1801818153 -707241340 -81097745 -1109376814 1347383281 2049057623 -297907388 1844986477 663703713 977933881 
					
visdebug1.1:
					python3 pyviz.py 140 344 499 186 79 53 29 423 347 122 382 461 45 44 185 221 142 429 274 495 112 34 269 258 468 8 369 109 255 116 298 380 324 72 405 215 377 96 113 161 436 389 148 187 291 279 308 275 460 199 95 173 328 451 31 126 205 441 143 189 331 247 437 400 78 263 104 211 194 119 330 473 305 180 151 174 394 0 60 110 355 239 90 61 284 235 24 13 264 105 266 483 366 38 353 470 241 399 115 403 129 227 338 46 108 270 130 467 20 307 340 92 316 214 278 14 475 36 386 159 197 272 156 164 166 469 229 387 442 10 101 431 406 378 74 224 373 299 138 163 388 37 231 9 12 114 59 175 480 188 393 234 363 176 62 321 476 146 137 484 66 165 65 432 466 191 458 248 202 293 18 320 492 213 40 482 303 51 398 253 422 243 32 43 311 52 337 233 71 77 286 97 282 348 201 147 86 150 361 63 158 11 271 454 498 309 349 22 318 297 409 17 170 251 354 326 496 445 182 390 19 427 84 440 306 381 391 1 252 288 368 87 383 83 154 424 15 283 415 459 292 70 280 412 281 5 39 396 420 417 296 358 481 408 371 265 376 479 425 54 418 106 58 370 209 48 196 339 341 285 184 452 256 335 212 50 206 314 33 16 352 404 111 374 246 47 449 41 300 230 262 488 312 28 364 23 336 7 474 195 273 290 464 267 4 434 356 64 446 160 103 329 360 219 302 319 333 132 69 385 453 249 346 21 88 26 89 55 81 204 456 91 343 181 3 208 100 216 301 351 162 200 171 30 25 345 237 223 123 220 472 304 27 411 455 334 426 179 172 232 102 136 242 375 428 73 323 487 35 125 438 478 416 477 133 257 245 207 192 350 67 259 490 407 491 141 494 203 435 332 362 289 190 277 2 313 153 222 82 6 117 357 218 76 128 168 294 118 198 342 463 325 228 497 287 177 42 183 134 145 124 99 98 152 217 178 322 80 419 489 310 367 276 485 120 448 421 68 439 260 254 236 433 401 94 462 392 149 402 210 443 384 85 144 56 465 447 295 107 493 93 471 414 430 457 131 139 250 315 395 238 226 410 49 379 240 317 127 193 157 57 75 167 413 365 261 135 372 268 155 444 169 244 121 397 486 225 450 327 359

debug1:
					./push_swap -910375298 817741925 2138566939 -556486725 -1431765026 -1659009032 -1849024900 1612425369 855082774 -1102445910 1252863585 1910913755 -1723960613 -1742448880 -568129393 -330302341 -902663281 1675445994 205112379 2100070334 -1183564024 -1815555903 172942756 89281669 1929994194 -2044232193 1110013756 -1222266199 81293019 -1151812011 463299215 1230506501 659366188 -1479808451 1402839318 -369327809 1207211640 -1314210719 -1176725813 -762556368 1718909099 1306635606 -858096035 -552700770 408715114 265837516 499846213 212223875 1899348118 -478571857 -1318880376 -674234968 690589317 1845376411 -1827665966 -1084027822 -420727890 1767894662 -894200694 -547760915 721738370 20128935 1719266153 1379811391 -1434373349 119751763 -1265240078 -393146814 -508044336 -1126642440 713642340 1957245859 486800162 -602433034 -842410464 -661474919 1322222416 -2133371247 -1613914643 -1219125354 941931974 -97887622 -1344022421 -1600766673 353101970 -195578026 -1902571143 -1992294524 122770073 -1250263208 152881397 2032399324 1069157474 -1793337789 903271942 1949217292 -89204480 1368073101 -1154709238 1388324425 -1030381480 -294626667 782263101 -1722537657 -1222722800 183924905 -1018305655 1929125858 -1951412621 494786090 785940262 -1341435866 576889629 -379135156 260292089 -1991955257 1965534835 -1796101894 1274319034 -773012777 -492325328 202012054 -805051048 -741708603 -723054448 1933291100 -241383319 1282630365 1778066326 -2024320738 -1294611817 1685111091 1403914723 1207450817 -1476651064 -313985770 1196575841 474063612 -950427362 -744710182 1297401393 -1795195804 -234926377 -2025207398 -1994900439 -1173604642 -1624989364 -654413589 2008649062 -550844617 1319168150 -204025871 1055046867 -628797067 -1583215331 637902316 1976789189 -873451030 -956847622 2039589602 -1560631757 -725449350 -1565461524 1688657356 1929050969 -521736476 1879750435 32278796 -459816390 440166800 -1954442443 631428921 2081168293 -383194801 -1767243049 2032210574 482825685 -1668831301 1355429765 53808509 1611876996 -81862298 -1821248505 -1748797475 543253160 -1660646090 761056482 -210535911 -1490081226 -1442365030 371391323 -1310211447 275293196 863842505 -465160302 -861731329 -1370864081 -843396013 981029824 -1581744665 -776941878 -2007226171 198742674 1862294493 2129073448 517116702 872852968 -1938020195 606128978 460679446 1426897192 -1956906605 -688575794 51590918 904473687 660452502 2107558323 1805717677 -598373670 1315443956 -1953886492 1640537844 -1393744571 1726588026 493276984 1251879133 1316561521 -2128286077 52925544 380698351 1095277581 -1360322150 1256402300 -1395641467 -816073944 1617050426 -1981139428 318862754 1519994384 1892618244 417751276 -1511578005 268080039 1447145511 273853260 -2096876178 -1784699594 1340566971 1573937652 1530964491 458640890 972675675 2015874536 1418585200 1144498956 136306358 1202323161 1997445801 1618298649 -1653628316 1556944468 -1229474883 -1631012975 1123043008 -396805671 -1712533967 -494448559 783823002 800628254 365203168 -570792470 1852322453 81496247 756832338 -386312904 -1679162158 -413584526 558168715 -1820188401 -1965555008 882424834 1399541540 -1206359811 1198334108 -19648586 -1720244564 1837422792 -1754869697 477263911 -241332608 109721293 2070734521 543695314 -1851775333 1055138073 -1913487025 756989435 -2075961617 1964909636 -495805913 204686751 384035586 1924091092 153292411 -2105503639 1711024068 963391503 -1573388653 1807199721 -764130605 -1276926550 692157157 978875456 -337806927 482436530 613196717 746441666 -993554833 -1521182583 1274033606 1855298363 45971394 824196646 -1950431276 -1352518372 -1881820590 -1345768341 -1651491348 -1408577137 -426550128 1875114391 -1343488597 817336006 -599007813 -2119403544 -400488094 -1301860925 -368387586 478523574 878865384 -752551931 -475355200 -681872738 -1832452560 -1883341823 819441210 -119977445 -319613770 -1100422062 -330557026 1956107682 485703740 -1868763974 1439870799 1873987588 753987232 1624082339 -602852276 -681172595 -212068803 -1278077381 -967718658 -83839074 1200241635 1674917538 -1477918334 655416689 2051301853 -1805019722 -1085047669 1719468270 1981386203 1529739008 1978391766 -982898447 88965346 -58445097 -406748962 -514481807 872868665 -1540356687 97771246 2079070200 1410688034 2079703332 -908189247 2095325908 -455872971 1716766118 732676820 1032717418 383179127 -522233905 251856248 -2119823098 556211910 -818382993 -325709815 -1398365242 -2080739238 -1147064420 967369218 -358594846 -1457603603 -1033173204 -710495435 444398321 -1138271424 -484371222 801688409 1923147016 660020755 -254182271 2116183288 377198138 -614319474 -1750795409 -582487784 -981206469 -874775971 -1094011391 -1303142716 -1309265540 -824053144 -361386002 -606126381 655191804 -1410081317 1563230572 2075971393 542389571 1084711713 250127066 2044279583 -1124255883 1836471432 1577340160 -1539174171 1719942274 100757672 69939886 -170344954 1690925361 1382671580 -1319986475 1919381805 1318456552 -852587728 1383719422 -396525320 1793755838 1259851258 -1391937162 -889797768 -1649291217 1924789473 1812020937 446009687 -1223846330 2091840831 -1322551606 1950439968 1467127505 1680509799 1878228186 -1011461046 -948799553 49182094 559323837 1334674623 -117740296 -297287523 1438847925 -1689694806 1225108502 -94638077 600485936 -1058111803 -512257335 -795782936 -1637710010 -1466471672 -721661712 1460944973 1064021434 101734178 -977420604 1173356677 161711757 -810227597 1801818153 -707241340 -81097745 -1109376814 1347383281 2049057623 -297907388 1844986477 663703713 977933881 

debug1.1:
					./push_swap 140 344 499 186 79 53 29 423 347 122 382 461 45 44 185 221 142 429 274 495 112 34 269 258 468 8 369 109 255 116 298 380 324 72 405 215 377 96 113 161 436 389 148 187 291 279 308 275 460 199 95 173 328 451 31 126 205 441 143 189 331 247 437 400 78 263 104 211 194 119 330 473 305 180 151 174 394 0 60 110 355 239 90 61 284 235 24 13 264 105 266 483 366 38 353 470 241 399 115 403 129 227 338 46 108 270 130 467 20 307 340 92 316 214 278 14 475 36 386 159 197 272 156 164 166 469 229 387 442 10 101 431 406 378 74 224 373 299 138 163 388 37 231 9 12 114 59 175 480 188 393 234 363 176 62 321 476 146 137 484 66 165 65 432 466 191 458 248 202 293 18 320 492 213 40 482 303 51 398 253 422 243 32 43 311 52 337 233 71 77 286 97 282 348 201 147 86 150 361 63 158 11 271 454 498 309 349 22 318 297 409 17 170 251 354 326 496 445 182 390 19 427 84 440 306 381 391 1 252 288 368 87 383 83 154 424 15 283 415 459 292 70 280 412 281 5 39 396 420 417 296 358 481 408 371 265 376 479 425 54 418 106 58 370 209 48 196 339 341 285 184 452 256 335 212 50 206 314 33 16 352 404 111 374 246 47 449 41 300 230 262 488 312 28 364 23 336 7 474 195 273 290 464 267 4 434 356 64 446 160 103 329 360 219 302 319 333 132 69 385 453 249 346 21 88 26 89 55 81 204 456 91 343 181 3 208 100 216 301 351 162 200 171 30 25 345 237 223 123 220 472 304 27 411 455 334 426 179 172 232 102 136 242 375 428 73 323 487 35 125 438 478 416 477 133 257 245 207 192 350 67 259 490 407 491 141 494 203 435 332 362 289 190 277 2 313 153 222 82 6 117 357 218 76 128 168 294 118 198 342 463 325 228 497 287 177 42 183 134 145 124 99 98 152 217 178 322 80 419 489 310 367 276 485 120 448 421 68 439 260 254 236 433 401 94 462 392 149 402 210 443 384 85 144 56 465 447 295 107 493 93 471 414 430 457 131 139 250 315 395 238 226 410 49 379 240 317 127 193 157 57 75 167 413 365 261 135 372 268 155 444 169 244 121 397 486 225 450 327 359

visdebug2:			
					python3 pyviz.py -253858469 -231380886 1497751697 234251573 -696118429 1411264043 1196490653 -337126243 -341894462 -408501523 1463491033 599379189 -2003470113 -2092384667 1500950401 1917097378 -585481415 419976727 -1572063303 674346043 1050133430 1300434368 -496735446 447479903 -1516132880 -647959862 -710080946 82880707 272357882 1296015669

visdebug2.1:		
					python3 pyviz.py 12 13 27 15 5 25 22 11 10 9 26 19 1 0 28 29 7 17 2 20 21 24 8 18 3 6 4 14 16 23

debug2:				
					./push_swap -253858469 -231380886 1497751697 234251573 -696118429 1411264043 1196490653 -337126243 -341894462 -408501523 1463491033 599379189 -2003470113 -2092384667 1500950401 1917097378 -585481415 419976727 -1572063303 674346043 1050133430 1300434368 -496735446 447479903 -1516132880 -647959862 -710080946 82880707 272357882 1296015669

debug2.1:			
					./push_swap 12 13 27 15 5 25 22 11 10 9 26 19 1 0 28 29 7 17 2 20 21 24 8 18 3 6 4 14 16 23
#ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG
#.PHONY
.PHONY:				all bonus checker libs clean checker_clean fclean re code


#-1 -2 -3 1 0 9 4 -12 6 18 5 -5 2 3 -4
#-99 -300 -1234 10000 50 100000 55555 -987988 88888 181818 55556 -12345 19999 20000 -11223
#-987988 -12345 -11223 -1234 -300| -99 50 10000 19999 20000| 55555 55556 88888 100000 181818
