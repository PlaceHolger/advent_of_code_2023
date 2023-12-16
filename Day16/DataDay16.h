#pragma once

//#define USE_TEST_DATA

#ifdef USE_TEST_DATA

constexpr int NUM_COLUMNS = 10;
constexpr const char s_FieldData[][NUM_COLUMNS+1] =
{
   R"(.|...\....)",
   R"(|.-.\.....)",
   R"(.....|-...)",
   R"(........|.)",
   R"(..........)",
   R"(.........\)",
   R"(..../.\\..)",
   R"(.-.-/..|..)",
   R"(.|....-|.\)",
   R"(..//.|....)",
};

#else

constexpr int NUM_COLUMNS = 110;
constexpr const char s_FieldData[][NUM_COLUMNS+1] =
{
R"(\-....|\......|...............................\......-../......./...\........|......|.........................)",
R"(.........-.....-............|.................-......|.\\......-...................-..|...\...................)",
R"(......./.|.............-.....-......................................./................\........\..............)",
R"(....|.-.........\..........|.......--.........../....|\....-.........|................./..-.................|.)",
R"(...-......./...../....\...................-......../\.../...............\.............-.......................)",
R"(...|............\.-......./...........|......-....................-..-.../....../......\...\.../..............)",
R"(..|..|..\.....................\..........|...\.|......................\......|....|....|.\.-......-...|....-..)",
R"(......../........................-......-.............\\.-............................/|........|../..........)",
R"(-..........................|.......-.../..............|...................\................|........-...../...)",
R"(.|............\.//.....-..........-....\......./...........................|........................|.........)",
R"(.............................................-................................\..-.\................/........\)",
R"(........|........................-....\..........-.........-..../....\../....\.\........\.....\.|.............)",
R"(.................\..|...........-...|......../................|.-..........-./...........|.--.................)",
R"(.......................-................\............\..|.....\....\....|\.....\.....-...\.....-.|............)",
R"(..........................\....|.../........../..........//........\\.........................................)",
R"(........................\.|..\........./.........../...||.............../................../.........-........)",
R"(/...........................|.....-..../../........./.\.....................|....../.|.....|..................)",
R"(....................\.../-|..../..................../.....|..............\./.....-.........../.--......../|.|.)",
R"(...-........\.....|......|....|.-............................-.....|./.......-.....-.....|-.....|.............)",
R"(....../............................................./..|....-..................\.....-.................//.....)",
R"(\.........................|....................................................../...../...\.........-..-.....)",
R"(....-../..\\.......-......../...\.................................\....-.............\.........\.....-........)",
R"(............/.........../...........\....................\......../.....\.................................|../)",
R"(.......\.........-....|..-|..|..............\............/.................................\......./..........)",
R"(................./..........................................\...........-|......................./.........\..)",
R"(|.......................-..../-/.......-........\.........................................../..../.......-....)",
R"(.\.............|.........|...--....-..|..-..............................................................|\.-|.)",
R"(.\....\...-\.....|./..........................\..............-......................\.....|...................)",
R"(.....|......./.|......................|.................................\........./..../..........\...........)",
R"(/..-...................|.......|.....-..........|...........\...-............-......|.|...................../.)",
R"(....................\..../.............|............|...............................-....|.-.........\....|...)",
R"(...|\.\.......\......\.....|..|.......|...\........................|.................-..-...........-.........)",
R"(............../\-.|.......-...\..........-............\.../...../..|......\................./............|....)",
R"(..........|............\..../........-.............\./....../.........................../.-...................)",
R"(.-.\/............................./......|....\........|....../............\......-....../.........\..........)",
R"(........./......../../.................\...-.\.........\............./../.....-............\..................)",
R"(\.\.......-..................-........-\.....|....\-............/...\............../................./........)",
R"(.........|.................-......\....\......./....|/................-.....\...........|\......|.............)",
R"(.......|........\...\......................-...--........../......-...........\|...............|..\......|....)",
R"(........\.................\...../....|.|..................\.....................\...........\.....-.-.........)",
R"(.....\/................/...-.-...............\...................................\....|.|.-|................/.)",
R"(.......\............\............\-............/......\....../.........|......-......\..-....-...-.........\..)",
R"(.............../......................................|....\.............../..|................../...-...|....)",
R"(.........\.../../.........................../..-........./.-...\.......-..........|.-...../..../........../...)",
R"(...|.......................|./..................-................\...|.....\.-................\./......\......)",
R"(|..../........|...../...................-./.....-...........|.....................-.......-..-................)",
R"(.../..-.......-...........|..-...............--..............||.../...........................................)",
R"(....|../...\.................../..../-..-...|.-.............\......................-....\.......-.....-.......)",
R"(.\.........-....-.....|........-..............................|.........................................\....|)",
R"(..|......................./.........\.......................\...............-.....././...\..|....-....././....)",
R"(...--.|.......................\..|......\|........-....||../....-........|.........\.......-..../..\....-.....)",
R"(-.\.........\...................-../....|............-.............../.............\......-....\..............)",
R"(............\....-.....\.|...............-.......-.|..............\...........................|..-.../........)",
R"(................................................\.........-....................-.......\......................)",
R"(.\.....\........................|....|......-...........-\...|/...................../.........................)",
R"(///.-..\.........\......./....|..........................\.|/.....................-...........-\....|..|......)",
R"(-...........|.....-/...............................|.....|....................................\......-......\/)",
R"(................\/............................................/.......................-........./.............)",
R"(........\.....-..\..............|....................|.....\........-../....../...........\-.........-........)",
R"(...../......../.........|.\........../.............\.............../......-.........................-\.../.-..)",
R"(.......................\..\......../|...|.....-..........................-.|.......\....................-.....)",
R"(..\......-/........./....|..\.................|...-..../|.................................-...................)",
R"(.............-..........-....../............................................../..........|....................)",
R"(.././.../.........\..\....|....||...............|./....-...-...............|/.......................-.........)",
R"(...............-...../.\.....\............\...............................-.-...........\.............-|......)",
R"(....\..............-............/..\................................\-.....-...........................\......)",
R"(.....-.....|.-.........../.........|...................../..................\..../.......\.-./.............../)",
R"(..\-..-....|................\...../................................|....|.|........./...........|....|........)",
R"(.............|..............................-.\........../....../......\.|.......-.......-....................)",
R"(........................./.............|.|........|..-............-../........-../....|.......|............-..)",
R"(......./.........\.\..\..../.-.-..|./........-.|.............../......./......|....-.-...../...........\......)",
R"(................./.....-....|........-\..\....\...................../....................................../..)",
R"(.|.......|./.../.......|.-..........-................-...........\.......-./......./..........................)",
R"(.......-..............................\.....\..-\/.|.-....................../.............|..........-...-....)",
R"(............/..-..........\..\/.\.../...........-................-..........\.|....|../-....................-.)",
R"(.....\......|.......|................|..\.|......\..-|-..../...........................................\...\..)",
R"(........../-.|........-..-........\......|...\.......\...|................................|......-............)",
R"(..|.......\....../......................||......\........-....\......|............-............/.....\.../....)",
R"(..................../...\.-............\......-........\...............-..\.....|.............................)",
R"(..........|.-....|....|./-.....|................../.......\......-...........././...|-...........|....-.......)",
R"(....../...\................./.....-...................|-................/.-...................|.........|.../.)",
R"(...........................-.................|../..|....../..........-....................../.................)",
R"(......../..\...../.\...\|...../.........\..........................-...\.......\...........\................./)",
R"(......-......|........./.../..|.....................|.......|...-..............-.\.....-./...\.......-..|.\...)",
R"(....|...-....................|....|....|..............\..|-......|...|...........................-............)",
R"(.......................|........-......\-...........-../..................../................./...............)",
R"(.......|....-\.\...|...\..............--...-.......-..|...\........|\.........................-......../....\.)",
R"(...\..........................-.................-......................-......\........-......................)",
R"(..|.....................|.-../-....\....-................|....................../...............|.|.........|.)",
R"(.\/.........-.....\............................|.............|....................\...........................)",
R"(....-....................\....-....-..\.......\....................././......|.......................\........)",
R"(./.......-...............-..............-...-...........................-........|...............\-.......|..|)",
R"(.....-................................/.|....-/...\..-.......-..........|.....-...|..........|................)",
R"(.....-..........................|...-.......|...../.\...-.........-........-\............-....-...../.../.....)",
R"(......./|\...........-...............\......./.........\...................\.....\............../.|.\........\)",
R"(.\/.............|...........................\-|........|..-.....................|.......................|.....)",
R"(/....|..................................|......................\..-\.....|..|......................|....|.....)",
R"(..................................-....../-..............\.........................................-../....\..)",
R"(.......................||......./....................../.../....\.................................\.../.......)",
R"(...............-..........--........\............................../...-/............/..........-.............)",
R"(......../...........|....................-................|..../.............../......./..................\.\.)",
R"(....\.../|..\..........|...........-.......................................................................\..)",
R"(......\...|/..\...............|......\.................../................../....\........../......-..........)",
R"(..............-....\............/.....|../...\....|.|..........\..........|................/..........|.......)",
R"(..../\.......................-................\......-............\./......................|....|..........|..)",
R"(..............|................|\.......\..-.../................/............................|................)",
R"(...................-..................................................-.......|.\.........|...................)",
R"(.................\....|.....\/......-........................\..................|.............................)",
R"(......................................|...........\...-.....|.....|.............../.....|..\.../..............)",
R"(.........../............................/...............|.....................-....\..................-.......)"};

#endif

constexpr int NUM_ROWS = std::size(s_FieldData);