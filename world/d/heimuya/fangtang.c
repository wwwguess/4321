// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
	һ������,�м�һ���泤�ޱȵĳԷ���������������̲�
һ��������ͨ���ڳԷ�(chifan)�ĵط�.�
LONG
	);

	set("exits", ([
		"east"  :__DIR__"dingfeng5.c",
	]));

	setup();
}

void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{
	this_player()->start_busy(5);
	write(YEL "�������������ش����һ��\n" NOR);
	write(YEL "ֱ�ԵöǷʳ��������������վ������\n" NOR);	
	this_player()->set("food",350);
	this_player()->set("water",350);
	return 1;
}
