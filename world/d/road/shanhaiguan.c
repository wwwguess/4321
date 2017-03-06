
inherit ROOM;

void create()
{
	set("short", "山海关");
	set("long", @LONG
这就是号称“天下第一关”的山海关了。山海关是万里长城的最东端，
这里依山傍海，地势险要，是进出东北的门户。因此山海关自古以来就是
兵家必争之地� 东面就是扼守山海关的兵营，由镇北大将军吴四贵把守。�
北面就通往东北地区了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rshgtoft0",
	"southwest" : "/d/road/rjdtoshg4",
	"east" 		: "/d/shhg/camp1",
]));

	setup();
	replace_program(ROOM);
}
