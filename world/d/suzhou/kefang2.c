//ROOM:/d/suzhou/kefang2.c
//by dwolf
//97.11.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG "�͵귿" NOR);
	set("long", @LONG
	���ǿ�ջ�Ŀͷ��������м��Ŵ���һЩ������˯���㣬��������ŵ��߽�ȥ��
�ҵ�һ�����̣�׼��˯����
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 0);
        set("sleep_room",0);

	set("exits", ([
		"north" : __DIR__"kezhan2",
	]));

	setup();
}       
  




