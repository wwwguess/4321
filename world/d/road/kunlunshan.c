#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY "����ɽ����" NOR);
	set("long", @LONG
�����������ɽ���£�̧ͷһ��������ɽֱ��������
���ϲ�ʱ�ɹ���ֻͺӥ���������������������е㷢ë��
������һ��С��,��ʱ��һЩ�����˳���.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rqhhtokl4",
	"northeast" : "/d/mingjiao/xiaozhen",
	"south" : "/d/road/rkltotgl0",
]));

	setup();
	replace_program(ROOM);
}
