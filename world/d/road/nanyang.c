
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ഫ�����������������ϵ�¡�н�®���ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rlytoxy0",
	"south" : "/d/road/rlytoxy1",
]));

	setup();
	replace_program(ROOM);
}
