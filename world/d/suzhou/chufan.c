// Room: /d/suzhou/chufan.c
//by dwolf 
//97.11.5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",MAG"����"NOR);
	set("long", @LONG
�����ھֵĳ���,�м�һ���泤�ޱȵĳԷ���������������̲�һ�������ھֵ��ӳԷ�
(chifan)�ĵط���
LONG
	);

	set("exits", ([
		"west"  :__DIR__"bjhyuan.c",
	]));

	setup();
}

void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{
	object me;
	me = this_player();

	if( !me->query("mark/�ھ�") ) 
		return notify_fail("�㲻���ھ����ˣ���׳԰���\n");
	
	me->start_busy(5);
	write(YEL "�������������ش����һ��\n" NOR);
	write(YEL "ֱ�ԵöǷʳ��������������վ������\n" NOR);	
	me->set("food",350);
	me->set("water",350);
		return 1;
}
