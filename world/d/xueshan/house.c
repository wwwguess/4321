//by dwolf
//97.118

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"ѩ�����"NOR);
	set("long", @LONG
	  �������һ�����أ������ǰ�ѩ��Զ����������Ԩ��һͷȫ���׵�С��
�������Ƕ��򶴣���������ʱ����������ֻԲ������������´����㡣������һ�ú�
���ѩ�ɣ���������һ��С�ݣ��㾺����������������ֻ������ѩ�У�����Ҳ��ѩ��
�и��������Ա߿�����һ�С�
LONG	
);
	set("objects", ([
		__DIR__"npc/hufei.c" : 1,
		__DIR__"npc/feihu.c" : 1,
	]));  
	set("exits", ([
		"south" : __DIR__"halfhole.c",
	]));
	setup();
}
