//lanzhou 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "����" NOR);
	set("long", @LONG
���������ݳǵĶ����š�ͨ�����ſ�ȥ��һ����·ֱͨ��������·�ϵ����˺ܶ࣬
�ܶ������������գ����Ŵ����Ļ���ڴҴҵظ�·��������˿��֮·�ıؾ�֮�أ�
�����Ҫ�������У������������������������ݵ�ɳ��Ͱ����ϻ�����󱥿ڸ���

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/lzdukoun",
	"southeast" : "/d/road/rcatolz3",
//	"west" : "/d/road/rqhhtolz2",
]));

	setup();
	replace_program(ROOM);
}
