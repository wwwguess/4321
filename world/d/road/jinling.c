//jinling   hhumud
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "����" NOR);
	set("long", @LONG
������������Ŷ�����������⡣
���꣬�г�ʯͷ�ǵġ��о仰�������������"����ع��ʯͷ��"��
�����ǵ���ɽ��������������򵽡��������ã������պ���
�����ݳ��ˡ��������ǽ���ǵ���վ����ʱ���Կ����в���
���Ƕ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"jldukoun",
	"southeast" : __DIR__"rjltosz0",
	"southwest" :"/d/hhu/yizhan",
//	"east" : "/d/hhu/out-hohai",
	"west"     : __DIR__"rcstoyt4",
]));
	set("outdoors","road");
	setup();
	replace_program(ROOM);
}
