//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��Ҵ���");
	set("long", @LONG
	���������Ĵ󻧣� һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ
�������˴������࣬���������������������Ϲ�������������д�š����֡� ��˵
��ҵ���������򳴵�һ�ֺ��Ǵ��㡣��֪������û�����������
�����Ҷ�վ���ſڡ�   
LONG
	);
	set("exits", ([
		"north" : __DIR__"wroad1",
		"west" : __DIR__"zuojia2",
]));                                      
	set("objects", ([
		__DIR__"npc/jiading" : 2,
]));
	setup();
	replace_program(ROOM);
}
