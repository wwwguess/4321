//by dwolf
//lou.c /
   
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"��ѩ¥"NOR);
	set("long", @LONG
	   "������ѩΪ�����������˶మ��ѩ������ѩ����߾���Ϊ��ѩ��ѩ����
�죬����ѩ�У�˼��ǧ�أ���ͨ�����һ˿�������������ѩ�����Ը�����һ�ּ�
į���Լ���һ�ֶ����������д�����ѩ¥�����⣬��ž����ڴ˰ɡ�"���Ǵ�ѩɽׯ
����һ ��¥���羰�ǳ�������
LONG
	); 
	set("exits", ([
		"up" : __DIR__"lou2.c",
		"east" : __DIR__"guarden2",
]));
	setup();
	replace_program(ROOM);
}
