// chengdu 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "�ɶ�" NOR);
	set("long", @LONG
��������츮֮���ĳɶ����������ط��֣������ڿҡ�
��ҹ��û��������Ϸ����Ǵ�������ʵ�������ţ�
��������ȥ���ݡ�����������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"southeast" : "/d/road/rcdtodk0",
	"southwest" : "/d/road/rcdtojs0",
	"northeast" : "/d/road/rjmtocd2",
]));

	setup();
	replace_program(ROOM);
}
