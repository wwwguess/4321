//jinan  hhumud
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY "����" NOR);
	set("long", @LONG
�����Ǽ��ϵ������ţ��ſ�վ���������سǵ�������
������һ���������ĳ��У�����Ȫ�ǵ����ƣ������Ȫˮ��������
���洦�ɼ��Ĵ�����΢�������ҡҷ�����������������ѡ����ϵ�
ǧ��ɽ����һ�����ܲ�ȥ�ĵط�����ɽ�±���ǧ��ǧ�棬������̾Ϊ��ֹ��

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rdktojn0",
	"south" : "/d/road/rjntoxz0",
	"east" : "/d/road/rjntopl0",
]));

	setup();
	replace_program(ROOM);
}
