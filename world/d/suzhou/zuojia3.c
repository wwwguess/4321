//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"��Һ�Ժ"NOR);
	set("long", @LONG
���߽���Ժ��ӭ����һ�ڴ����һ���Ҷ���������һ���Ҷ�������Ū�㣬����ͷ����
��������׼�����Ǵ��㡣��û��ʼ������ŵ�һ������������������˰���
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"zuojia2",
	]));                                      
	set("objects", ([
		__DIR__"npc/jiading" : 2,
		__DIR__"npc/zuoqh" : 1,
]));
	setup();
	replace_program(ROOM);
}
