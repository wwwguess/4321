//ROOM:/d/suzhou/kefang3.c
//by dwolf
//97.11.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG "�͵귿" NOR);
	set("long", @LONG
	���ǿ�ջ�Ŀͷ��������м������䣬��ϡ���������ǵ�˵Ц����������Գ��
���㲻�ɼӿ��˽Ų����ҵ�һ��յĵ��䣬׼��˯����
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 0);
        set("sleep_room",1);

	set("exits", ([
		"west" : __DIR__"kezhan2",
	]));

	setup();
}       
  




