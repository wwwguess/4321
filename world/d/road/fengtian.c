
inherit ROOM;

void create()
{
	set("short", "奉天");
	set("long", @LONG
这里就是关外名城奉天。奉天是关外最大的城市，这里会集了很多来自关外
各地的商人，游客。可是现在这里的城门紧闭着，不知发生了什么事。
北面是到长白山的唯一通路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rfttocbs0",
	"southwest" : "/d/road/rshgtoft4",
	"west" : "/d/road/rfttocy0",
	"east" : "/d/road/rfttogl0",
]));

	setup();
	replace_program(ROOM);
}
