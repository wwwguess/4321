// Room: /d/new_taohua/shitang.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ɲ���Ƥ����ľ��ɡ������������٣����ݺ�ٸ�һ��������
������Щ�������������ϲ���������ɫ���̣�����ѩˮ�����������Ƣ��  
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "east" : __DIR__"houting",
  "west" : __DIR__"chufang",
]));
	

	setup();
}

void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{
    this_player()->start_busy(2);
        write(YEL "�������������ش����һ��\n" NOR);
        write(YEL "ֱ�ԵöǷʳ��������������վ������\n" NOR);
  this_player()->set("food",400);
  this_player()->set("water",400);
        return 1;
}
